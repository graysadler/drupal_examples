<?php

function trader_form_order($form, &$form_state, $object = NULL, $type = NULL) {
  global $user;
  global $oanda;
  $form = array();
  $wrapper = FALSE;
  $expiry = time() + (60 * 60 * 5); // 5 hour
  
  
  if ($object) {
    $account = user_load($object->uid);
    $user_wrapper = entity_metadata_wrapper('user', $account);
    $wrapper = entity_metadata_wrapper('node', $object);
    $side = $wrapper->field_side->value();
    $price = $wrapper->field_price->value();
    $instrument = $wrapper->field_instrument;
    $prices = trader_get_current_prices($instrument->name->value());
    
    if ($type == 'setup') {
      $strategy = $wrapper->field_strategy;
      $criteria_met = $wrapper->field_criteria_count->value() / $wrapper->field_criteria_total->value();
      if ($criteria_met === 1) {
      
        // Setup so will be a new order
        // Get current price
        if ($side == 'sell') {
          if ($price > $prices->bid) {
            $order_type = 'marketIfTouched';
          } else {
            $order_type = 'limit';
          }
        } else {
          if ($price > $prices->ask) {
            $order_type = 'limit';
          } else {
            $order_type = 'marketIfTouched';
          }
        }
        $pips = abs($wrapper->field_stop_loss->value() - $wrapper->field_price->value());
        $pips = substr_count($instrument->name->value(), 'JPY') > 1 ? $pips * 10000 : $pips * 100;
        
        $units = trader_calc_position($instrument->name->value(), $wrapper->field_strategy->field_max_trade_risk->value(), $oanda->account->account->marginAvailable, $pips);
      }
    } else {
      // Existing order
      $units = $wrapper->field_units->value();
      $expiry = $wrapper->field_expiry->value();
      $order_type = $wrapper->field_order_type->value();
      $strategy = $wrapper->field_setup->field_strategy;
    }
    
  } else {
    $account = user_load($user->uid);
    $user_wrapper = entity_metadata_wrapper('user', $account);
    $units = trader_get_default_units($user);
    $order_type = 'limit';
  }
  

  $form['#node'] = $object;

  $form['account_id'] = array(
    '#type' => 'select',
    '#title' => 'Account',
    '#options' => _trader_user_account_options(),  
    '#default_value' => $wrapper ? $wrapper->field_account->value() : '',
  );
  
  $form['field_order_type'] = array(
      '#type' => 'select',
      '#title' => t('Order Type'),
      '#options' => array('limit' => 'Limit', 'market' => 'Market', 'marketIfTouched' => 'MIT'), // TODO add these to the setup?
      '#default_value' => $order_type,
      '#required' => TRUE,
  );

  $form['field_side'] = array(
      '#type' => 'select',
      '#title' => t('Side'),
      '#options' => array('buy' => 'Buy', 'sell' => 'Sell'),
      '#default_value' => $wrapper ? $wrapper->field_side->value() : '',
      '#required' => TRUE,
  );

  $form['#instrument'] = $wrapper ? $wrapper->field_instrument : '';

  $form['instrument'] = array(
      '#type' => 'textfield',
      '#title' => t('Instrument'),
      '#default_value' => $wrapper ? $wrapper->field_instrument->name->value() : '',
      '#required' => TRUE,
  );

  $form['field_price'] = array(
      '#type' => 'textfield',
      '#title' => t('Price'),
      '#default_value' => $wrapper ? $wrapper->field_price->value() : '',
      '#required' => TRUE,
  );

  $form['field_units'] = array(
      '#type' => 'textfield',
      '#title' => t('Units'),
      '#default_value' => $units,
      '#required' => TRUE,
  );

  $form['field_stop_loss'] = array(
      '#type' => 'textfield',
      '#title' => t('Stop'),
      '#default_value' => $wrapper ? $wrapper->field_stop_loss->value() : '',
      '#required' => FALSE,
  );

  $form['field_take_profit'] = array(
      '#type' => 'textfield',
      '#title' => t('TP'),
      '#default_value' => $wrapper ? $wrapper->field_tp1->value() : '',
      '#required' => FALSE,
  );

  // TODO finish trail selection
  $form['field_trail_mode'] = array(
      '#type' => 'select',
      '#title' => t('Trail Mode'),
      '#options' => array('' => 'None'),
      '#default_value' => '',
      '#required' => FALSE,
  );
  $expiry = '';
  if (isset($wrapper)) {
    if (isset($wrapper->field_expiry)) {
      $expiry = $wrapper->field_expiry->value();
    }
  }
  $expiry = $expiry ? format_date($expiry, 'custom', "Y-m-d H:i:s") : $expiry;
  $form['field_expiry'] = array(
      '#title' => t('Expiry'),
      '#type' => 'date_text',
      '#default_value' => $expiry,
      '#date_type' => DATE_UNIX,
      '#date_timezone' => date_default_timezone(),
      '#date_format' => 'Y-m-d H:i:s',
      '#date_increment' => 1,
      '#date_year_range' => '-3:+3',
      //'#required' => TRUE,
  );


  if ($type == 'setup') {
    $form['order'] = array(
        '#type' => 'submit',
        '#value' => t('Order'),
        '#submit' => array('trader_form_order_submit_order'),
    );

    $form['close'] = array(
        '#type' => 'submit',
        '#value' => t('Close'),
        '#submit' => array('trader_form_order_submit_close'),
    );
  }

  if ($type == 'order') {
    $form['update'] = array(
        '#type' => 'submit',
        '#value' => t('Update Order'),
        '#submit' => array('trader_form_order_submit_update'),
    );

    $form['cancel'] = array(
        '#type' => 'submit',
        '#value' => t('Cancel Order'),
        '#submit' => array('trader_form_order_submit_cancel'),
    );
  }

  return $form;
}

function trader_order_update($oanda, $account_id, $order) {
  $options = (array) $order;
  return $oanda->order_set($account_id, $order->id, $options);
}

function trader_order_close_all($pair) {
  OandaWrap::order_close_all($pair);
}
/**
 * @param node $order
 * @return boolean
 */
function trader_order_close($order, $message = 'No Reason provided') {
  global $oanda_accounts;
   
  if (!$oanda = $oanda_accounts[$order->uid]) {
    return FALSE;
  }
  
  $wrapper = entity_metadata_wrapper('node', $order);
  
  $account_id = $wrapper->field_account->value();
  
  $result = $oanda->order_close($account_id, $wrapper->field_order_id->value());

  if (isset($result->code)) {
    // error
    trader_set_message('Order ' . $order->nid . ' was attempted to close but an Oanda refused:' . $message);
    return FALSE;
  } else {
    $wrapper->field_order_status->set('closed');
    $wrapper->field_updated->set(time());
    $wrapper->save();
    trader_set_message('Order ' . $order->nid . ' closed: ' . $message);
    return TRUE;
  }
}

function trader_form_order_submit_update($form, &$form_state) {
  $node = $form['#node'];
  $wrapper = entity_metadata_wrapper('node', $node);

}

function trader_form_order_submit_cancel($form, &$form_state) {
  $node = $form['#node'];
  $wrapper = entity_metadata_wrapper('node', $node);
  $result = trader_order_close($node);
}

function trader_form_order_submit_order($form, &$form_state) {
  $values = $form_state['values'];
  $values['instrument'] = $form['#instrument'];
  $values['node'] = $form['#node'];

  if ($result = trader_order_submit($values)) {
    // Update the setup status
    $node = $form['#node'];
    if ($node->type == 'setup') {
      $wrapper = entity_metadata_wrapper('node', $node);
      $wrapper->field_setup_status->set('ordered');
      $wrapper->save();
    }

    if ($node->type == 'order') {
      // TODO Update the order fields
    }
  }
}

function trader_order_submit($values) {
  global $oanda;
  global $user;
  $account_wrapper = entity_metadata_wrapper('user', $user);
  
  $order = new stdClass;
  $order->type = 'order';
  $order->uid = $user->uid;
  $order->status = 1;
  $order->comment = 0;
  $order->promote = 0;
  $order->language = LANGUAGE_NONE;

  $wrapper = entity_metadata_wrapper('node', $order);
  
  $side = $values['field_side'];
  $pair = $values['instrument'];
  $stop = $values['field_stop_loss'];
  $take_profit = $values['field_take_profit'];
  $instrument = trader_load_instrument($pair);
  $units = $values['field_units'];
  $price = $values['field_price'];
  $title = strtoupper($side) . ' ' . $pair . ' ' . $price;
  $wrapper->title->set($title);
  
  $order_type = $values['field_order_type'];
  
  // Account
  $wrapper->field_side->set($side);
  $wrapper->field_instrument->set($instrument->tid->value());
  $wrapper->field_price->set($price);
  //$pips = _trader
  $risk = trader_calc_risk($side, $price, $stop);
  $pips = $risk / $instrument->field_pip->value();
  $account_id = $values['account_id'];
  $sub = $oanda->account($account_id);
  $balance = $sub->account->marginAvailable;
  
  //$units = trader_calc_position($instrument->name->value(), $account_wrapper->field_max_trade_risk->value(), $balance, $pips);
  $wrapper->field_units->set($units); // TODO make this dynamic
  $wrapper->field_stop_loss->set($stop);
  $wrapper->field_take_profit->set($take_profit);
  $expiry_date = new DateTime($values['field_expiry'], new DateTimeZone(date_default_timezone()));
  $wrapper->field_expiry->set($expiry_date->format('U'));// TODO: finish this
  //$wrapper->field_lower_bound->set()
  //$wrapper->field_upper_bound->set()
  $wrapper->field_order_type->set($order_type);
  $wrapper->field_order_status->set('pending');
  $wrapper->field_account->set($account_id);
  
  if (!empty($values['field_setup'])) {
    $wrapper->field_setup->set($setup->nid->value());    
    $wrapper->field_candle_time->set($setup->field_candle_time->value());
  }
  
  $wrapper->save();
}

/**
 * Submit handler that closes a setup and prevents an order
 */
function trader_form_order_submit_close($form, &$form_state) {
  $node = $form['#node'];

  $wrapper = entity_metadata_wrapper('node', $node);
  $wrapper->field_setup_status->set('closed');
  $wrapper->save();
}

/**
 * Testing order form
 */
function trader_form_test_orders($form, &$form_state) {
  //$form = drupal_get_form('trader_form_order');
  $form = trader_form_order($form, $form_state);
  //dpm($form);
  $form['field_expiry']['#required'] = FALSE;
  $form['order'] = array(
      '#type' => 'submit',
      '#value' => t('Order'),
      '#submit' => array('trader_form_test_orders_submit'),
  );
  return $form;
}

function trader_form_test_orders_submit(&$form, &$form_state) {
  trader_order_submit($form_state['values']);
}

/**
 * Prepares a trade object and returns it's entitymetadata wrapper ready to save.
 * @param  EntityMetadataWrapper $order
 * @return EntityMetadataWrapper
 */
function trader_prepare_trade_from_order($order) {
  $trade = new stdClass;
  $trade->type = 'trade';
  $trade->uid = $order->author->uid->value();

  // Make sure that this isn't an anonymous uid
  if ($trade->uid === 0) {
    $trade->uid = 1;
  }
  $trade->status = 1;
  $trade->comment = 0;
  $trade->promote = 0;
  $trade->language = LANGUAGE_NONE;
  
  $wrapper = entity_metadata_wrapper('node', $trade);

  $side = $order->field_side->value();
  $instrument = $order->field_instrument;
  $pair = $instrument->name->value();
  $price = $order->field_price->value();
  $units = $order->field_units->value();

  $wrapper->title->set('TRADE ' . $order->title->value());
  $wrapper->field_side->set($side);
  $wrapper->field_instrument->set($instrument->tid->value());
  $wrapper->field_price->set($price);
  $wrapper->field_account->set($order->field_account->value());
  $wrapper->field_units->set($units); 
  $wrapper->field_stop_loss->set($order->field_stop_loss->value());
  $wrapper->field_take_profit->set($order->field_take_profit->value());
  
  return $wrapper;
}

/**
 * Update units based on margin available and any additional orders. 
 * Cancel orders if TP for that order has already hit
 * @param unknown $accounts
 */
function trader_order_update_units($accounts = array()) {
  global $oanda_accounts;
  $order_nids = array();
  $candles = array();
  $hl = array();
  
  $now = time();
  if (!$since = variable_get('trader_order_update', NULL)) {    
    $since = $now - 60 * 24; // 6 hours ago
  }
  foreach ($oanda_accounts as $oanda) {
    foreach ($oanda->accounts as $account) {
      $orders = $account->orders;
      
      foreach ($orders as $order) {
        if ($order->type == 'TAKE_PROFIT' || $order->type == 'STOP_LOSS') {
          continue;
        }
        if (isset($order->clientExtensions)) {
          $order_nid = $order->clientExtensions->id;
          //$order_nid = str_replace('order_', '', $order_nid);
          if (!$node = node_load($order_nid)) {
            watchdog('trader', 'Attempting to update order with no node', NULL, WATCHDOG_ALERT);
            continue;
          }
          if ($node->type != 'order') {
            watchdog('trader', 'Attempting to update order that is not an order node', NULL, WATCHDOG_ALERT);
            continue;
          }
          
          $wrapper = entity_metadata_wrapper('node', $node);
          $setup = $wrapper->field_setup;
          $strategy = $setup->field_strategy->value();
          if (!$strategy) {
            watchdog('trader', 'Order exists without a strategy NID: ' . $node->nid, NULL, WATCHDOG_ALERT);
            continue;
          }
          
          $strategy_wrapper = $wrapper->field_setup->field_strategy;
          
          // Close orders if TP hit already
          if ($strategy_wrapper->field_close_order_on_tp->value()) {
            $pair = $wrapper->field_instrument->name->value();
            $account_id = $wrapper->field_account->value();
            
            if (empty($candles[$pair])) {
              $candles[$pair] = oanda_get_bidask_ticks($pair, $since, $now, 'M1');
            }
            $high = NULL;
            $low = NULL;          
            foreach ($candles[$pair] as $candle) {
              if ($candle->timestamp < $wrapper->field_candle_time->value()) {
                continue;
              }
              if (!$high) {
                $high = $candle->high_bid;
                $low = $candle->low_ask;
              } 
              
              $high = $candle->high_bid > $high ? $candle->high_bid : $high;
              $low = $candle->low_ask < $low ? $candle->low_ask : $low;
            }
            
            $side = $wrapper->field_side->value();
            
            if ($side == 'buy' && $high >= $wrapper->field_take_profit->value()) {
              // Close the order
              trader_order_close($node, 'Take profit price hit');
              continue;
            }
            if ($side == 'sell' && $low <= $wrapper->field_take_profit->value()) {
              // Close the trade
              trader_order_close($node, 'Take profit price hit');
              continue;
            }
          } else {
            // Keep Order open
            $test = 'test';
          }

          // Update order units based on margin/units

          $pips = $setup->field_risk->value() / $wrapper->field_instrument->field_pip->value();
          $balance = $account->marginAvailable;
          //$balance = $oanda->account->account->marginAvailable;
          $units = trader_calc_position($wrapper->field_instrument->name->value(), $wrapper->field_setup->field_strategy->field_max_trade_risk->value(), $balance, $pips);
          $wrapper->field_units->set($units); 
          $order->units = $units;
          $result = trader_order_update($oanda, $account_id, $order);
          $wrapper->save();
        }
      }
    }
  }
  
  variable_set('trader_order_update', $now);
  
  $time = time();
  if ($time - $now > 3) {
    trader_set_message('Updating orders took ' . $time - $now . ' seconds.');
  }
}

/**
 * Loops through orders being held due to max_trade.
 * Closes orders where TP hit if applicable
 * Saves orders so that max_trade will be checked in hook_node_update().
 * 
 * TODO: This function has some duplicate code that's in trader_order_update_units. See about merging
 * the code into a single function somehow.
 */
function trader_order_check_held_orders() {
  global $oanda_accounts;

  // Return all orders being held
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node', '=');
  $query->propertyCondition('type', 'order');
  $query->fieldCondition('field_order_status', 'value', 'holding');
  $query->propertyOrderBy('created', 'ASC');
  
  $query_result = $query->execute();
  $nodes = array();
  if (isset($query_result['node'])) {
    // EFQ query results are keyed by entity ID
    $node_ids = array_keys($query_result['node']);
    $nodes = node_load_multiple($node_ids);
  }
  
  if (empty($nodes)) {
    return;
  }
  
  foreach ($nodes as $nid => $node) {
    // Check if order is still valid
    $wrapper = entity_metadata_wrapper('node', $node);
    $setup = $wrapper->field_setup;
    $strategy = $setup->field_strategy->value();
    if (!$strategy) {
      watchdog('trader', 'Order exists without a strategy NID: ' . $node->nid, NULL, WATCHDOG_ALERT);
      continue;
    }
    
    $strategy_wrapper = $wrapper->field_setup->field_strategy;
    
    // Close orders if TP hit already
    if ($strategy_wrapper->field_close_order_on_tp->value()) {
      $account_id = $wrapper->field_account->value();
      $pair = $wrapper->field_instrument->name->value();
      $since = $wrapper->field_candle_time->value();
      $now = time();
      if (empty($candles[$pair])) {
        $candles[$pair] = oanda_get_bidask_ticks($pair, $since, $now, 'M1');
      }
      $high = NULL;
      $low = NULL;
      foreach ($candles[$pair] as $candle) {
        if ($candle->timestamp < $since) {
          continue;
        }
        
        if (!$high) {
          $high = $candle->high_bid;
          $low = $candle->low_ask;
        }
    
        $high = $candle->high_bid > $high ? $candle->high_bid : $high;
        $low = $candle->low_ask < $low ? $candle->low_ask : $low;
      }
    
      $side = $wrapper->field_side->value();
    
      if (($side == 'buy' && $high >= $wrapper->field_take_profit->value()) ||
         ($side == 'sell' && $low <= $wrapper->field_take_profit->value())) {
        // Close the order
        $wrapper->field_order_status->set('closed');
      }
    } else {
      // Keep Order - will check any open trades on hook_node_update().
      $wrapper->field_order_status->set('pending');
    }

    // Save the order
    $wrapper->save();    
  }
}