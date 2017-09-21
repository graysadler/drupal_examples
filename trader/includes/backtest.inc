<?php

function trader_backtest($strat, $start, $end, $backtest = NULL, $create = TRUE) {
  $start_time = time();

  $setups = trader_process_setups($strat, $start, $end, TRUE, FALSE, TRUE);
  drupal_set_message('Setups took ' . (time() - $start_time) . ' seconds.');
  $strat = entity_metadata_wrapper('node', $strat);

  // Studies are keyed by strat=>frac=>timestamp
  $setup_studies = &drupal_static('trader_setup_studies', array());
  $setup_studies = $setup_studies[$strat->nid->value()];

  // Simulate live market with M1 candles
  // Setups are in array keyed by timestamp
  // Timestamp is when to start from
  // Use first timestamp to know which candles to start from
  $instrument = $strat->field_instrument;
  $pair = $instrument->name->value();

  $trades = &drupal_static('trader_backtest_trades', array());
  $orders = &drupal_static('trader_backtest_orders', array());
  $results = &drupal_static('trader_backtest_results', array());

  // Convert setups to orders
  $now = time();
  foreach ($setups as $key => $setup) {
    $orders[$key] = trader_prepare_order_from_setup($setup);
  }
  drupal_set_message('Order creation took ' . (time() - $now) . ' seconds.');

  if (empty($orders)) {
    drupal_set_message('BACKTEST: No setups created during backtest.');
    return;
  }
  $now = time();
  // Load candles for simulation - 1M
  reset($orders);
  $data_start = key($orders); // Only need to start with the first order
  end($orders);
  $data_end = key($orders) + (60 * 60 * 24); // Add 24 hours in case a trade carries over
  $gran = 'M1';
  $candles = oanda_get_bidask_ticks($pair, $data_start, $data_end, $gran, FALSE); // TODO really limit to 5000? - removed limit but should there be?
  drupal_set_message('M1 candles loaded for simulation took ' . (time() - $now) . ' seconds.');

  $now = time();
  // Loop through orders - check for fill or expire
  foreach ($orders as $okey => &$order) {
    // Loop through candles
    foreach ($candles as $ckey => $candle) {
      // Skip if candle is before ordered
      if ($candle->timestamp < $order->field_candle_time->value()) {
        continue;
      }
      // Check if order fills or expires
      $side = $order->field_side->value();
      $range_high = $side == 'buy' ? $candle->high_ask : $candle->high_bid;
      $range_low = $side == 'buy' ? $candle->low_ask : $candle->low_bid;
      $price = $order->field_price->value();
      // Check expiration
      if ($order->field_expiry->value()) {
        if ($candle->timestamp >= $order->field_expiry->value()) {
          $update = array('field_order_status' => 'closed', 'field_updated' => $candle->timestamp);
          trader_update_fields($order, $update);
          break;
        }
      }
      // Check fill
      if ($price >= $range_low && $price <= $range_high) {
        $update = array('field_order_status' => 'filled', 'field_updated' => $candle->timestamp);
        trader_update_fields($order, $update);
        $trade = trader_backtest_create_trade_object_from_order($order);
        $update = array('field_updated' => $candle->timestamp, 'field_trade_open_date' => $candle->timestamp);
        trader_update_fields($trade, $update);
        $trades[$okey] = $trade;
        break;
      }
    }
  }
  drupal_set_message('Order fills took ' . (time() - $now) . ' seconds.');
  $now = time();
  // Loop through trades - run trade management, check SL and TP
  // Check drawdowns
  foreach ($trades as $tkey => $trade) {
    $price = $trade->field_price->value();
    $side = $trade->field_side->value();
    // Loop through candles
    $studies = FALSE;
    foreach ($candles as $ckey => $candle) {
      // Skip if candle is before filled
      if ($candle->timestamp < $trade->field_updated->value()) {
        continue;
      }

      $stop = $trade->field_stop_loss->value();
      $stopped = $side == 'buy' ? $candle->low_bid <= $stop : $candle->high_ask >= $stop;

      // Check SL
      if ($stopped) {
        $profit = $side == 'buy' ? $stop - $price: $price - $stop;
        $profit = trader_pip_format($instrument, $profit);
        $update = array(
            'field_trade_result' => 'stop',
            'field_updated' => $candle->timestamp,
            'field_close_price' => $stop,
            'field_trade_close_date' => $candle->timestamp,
            'field_trade_profit' => $profit,
            'field_trade_drawdown' => $profit,
        );

        trader_update_fields($trade, $update);
        $results[$tkey] = $trade;
        break;
      }

      // Check TP
      if ($trade->field_take_profit->value()) {
        $tp = $trade->field_take_profit->value();
        $profit_taken = $side == 'buy' ? $candle->high_bid >= $tp : $candle->low_ask <= $tp;
        if ($profit_taken) {
          $profit = $side == 'buy' ? $tp - $price : $price - $tp;
          trader_pip_format($instrument, $profit);
          $update = array(
              'field_trade_result' => 'tp',
              'field_updated' => $candle->timestamp,
              'field_close_price' => $tp,
              'field_trade_close_date' => $candle->timestamp,
              'field_trade_profit' => $profit,
          );
          trader_update_fields($trade, $update);
          $results[$tkey] = $trade;
          break;
        }
      }

      // Record drawdown
      $drawdown = $side == 'buy' ? $price - $candle->low_bid : $candle->high_ask - $price;
      if ($drawdown > $trade->field_trade_drawdown->value()) {
        $update = array('field_trade_drawdown' => $drawdown);
        trader_update_fields($trade, $update);
      }

      // Manage trade
      // TODO not sure if this is best way with range bars
      if (!empty($setup_studies[$strat->field_fractal->value()][$candle->timestamp])) {
        $studies = $setup_studies[$strat->field_fractal->value()][$candle->timestamp];
      }
      if ($studies) {
        if ($update = trader_manage_trade($trade, $candle, $studies)) {
          trader_update_fields($trade, $update);
        }
      }

      $prev_candle = $candle;
    }



    //    $drawdown = trader_pip_format($instrument, $drawdown);

    $results[$tkey] = $trade;
  }
  drupal_set_message('Trade simulation took ' . (time() - $now) . ' seconds.');
  $now = time();

  if (!$backtest) {
    global $user;
    $backtest = new stdClass;
    $backtest->is_new = TRUE;
    //unset($backtest->field_entry_criteria);
    $backtest->type = 'backtest';
    $backtest->language = LANGUAGE_NONE;
    $backtest->status = 1;
    $backtest->comment = 0;
    $backtest->promote = 0;
    $backtest->uid = $user->uid;
    $backtest->title = 'BACKTEST: ' . $strat->title->value();
    $backtest->field_backtest_start[0]['value'] = $start;
    $backtest->field_backtest_end[0]['value'] = $end;
    $backtest->field_strategy['und'][0]['target_id'] = $strat->nid->value();
    $backtest = entity_metadata_wrapper('node', $backtest);
  }

  // Format the results to save in backtest body field
  $wins = 0;
  $losses = 0;
  $ntrades = 0;
  $largest_w = 0;
  $largest_l = 0;
  $total_pips = 0;
  foreach ($results as $result) {
    $side = $result->field_side->value();
    $pips = $side == 'buy' ? $result->field_close_price->value() - $result->field_price->value() : $result->field_price->value() - $result->field_close_price->value();
    $total_pips += $pips;
    $ntrades++;

    if ($pips > 0) {
      $wins++;
      if ($pips > $largest_w) {
        $largest_w = $pips;
      }
    }

    if ($pips < 0) {
      $losses++;
      if ($pips < $largest_l) {
        $largest_l = $pips;
      }
    }
  }

  $backtest->field_backtest_wins->set($wins);
  $backtest->field_backtest_losses->set($losses);
  $backtest->field_backtest_trades->set($ntrades);
  $backtest->field_backtest_pips->set($total_pips);
  $backtest->field_largest_win->set($largest_w);
  $backtest->field_largest_loss->set($largest_l);

  $date_start = new DateTime($start, new DateTimeZone('America/New_York'));
  $date_end = new DateTime($end, new DateTimeZone('America/New_York'));
  $backtest->field_backtest_start->set($date_start->format('U'));
  $backtest->field_backtest_end->set($date_end->format('U'));
  $backtest->field_backtest_type->set('manual');
  $body = trader_backtest_display_results($orders, $results);
  $backtest->body->set(array('value'=>$body, 'format'=>'full_html'));

  $end_time = time();
  $total_seconds = $end_time - $start_time;
  $total_minutes = round($total_seconds / 60, 2);
  $total_minutes = $total_minutes < 1 ? $total_seconds . ' seconds' : $total_minutes . ' minutes';
  drupal_set_message('Backtest result rendering took ' . (time() - $now) . ' seconds.');

  if ($create) {
    $backtest->save();
    $msg = "Backtest took $total_minutes. " . l('View it here', 'node/' . $backtest->nid->value());
  } else {
    $msg = "Backtest took $total_minutes. ";
  }

  drupal_set_message($msg);
  return $backtest->value();
}

/**
 * Generates an html table of backtest results
 * @param unknown $orders
 * @param unknown $results
 * @return An
 */
function trader_backtest_display_results($orders, $results) {
  // Trades table
  $rows = array();
  $date = new DateTime('now', new DateTimeZone('America/New_York'));

  foreach ($results as $result) {
    $side = $result->field_side->value();
    $price = $result->field_price->value();
    $drawdown = $result->field_trade_drawdown->value();

    $row = array();
    $row[] = $result->field_trade_result->value();
    $date->setTimestamp($result->field_trade_open_date->value());
    $row[] = $date->format('m/d/y H:i');
    $date->setTimestamp($result->field_trade_close_date->value());
    $row[] = $date->format('m/d/y H:i');
    $row[] = $side;
    $row[] = $price;
    $row[] = $result->field_units->value();
    $row[] = $result->field_stop_loss->value();
    $row[] = $result->field_take_profit->value();
    $row[] = $result->field_close_price->value();
    $row[] = $drawdown;

    $reward = $result->field_side->value() == 'buy' ? $result->field_take_profit->value() - $result->field_price->value() : $result->field_price->value() - $result->field_take_profit->value();
    $reward = trader_pip_format($result->field_instrument, $reward);
    $risk = $result->field_side->value() == 'buy' ? $result->field_price->value() - $result->field_stop_loss->value() : $result->field_stop_loss->value() - $result->field_price->value();
    $risk = trader_pip_format($result->field_instrument, $risk);
    $rr = $risk . ':' . $reward;
    $row[] = $rr;
    $row[] = $result->field_trade_profit->value();
    $rows[] = $row;
  }

  $header = array('Result', 'Opened', 'Closed', 'Side', 'Price', 'Units', 'SL', 'TP', 'Close Price', 'Drawdown', 'R:R', 'Profit');
  $output = theme('table', array('header' => $header, 'rows' => $rows));

  // Orders table
  $rows = array();
  foreach ($orders as $order) {
    $row = array();
    $date->setTimestamp($order->field_candle_time->value());
    $row[] = $date->format('m/d/y H:i');
    $row[] = $order->field_order_status->value();
    $row[] = $order->field_side->value();
    $row[] = $order->field_price->value();
    $row[] = $order->field_units->value();
    $row[] = $order->field_stop_loss->value();
    $row[] = $order->field_take_profit->value();
    $rows[] = $row;
  }

  $header = array('Ordered', 'Status', 'Side', 'Price', 'Units', 'SL', 'TP');
  $output .= theme('table', array('header' => $header, 'rows' => $rows));
  return $output;
}

function trader_backtest_create_trade_object_from_order($order) {
  global $user;

  $trade = new stdClass;
  $trade->type = 'trade';
  $trade->uid = $user->uid;
  $trade->status = 1;
  $trade->comments = 0;
  $trade->promote = 0;
  $trade->language = LANGUAGE_NONE;

  $wrapper = entity_metadata_wrapper('node', $trade);

  $side = $order->field_side->value();
  $wrapper->field_side->set($side);
  $instrument = $order->field_instrument->value();
  $pair = $instrument->name;
  $price = $order->field_price->value();
  $title = strtoupper($side) . ' ' . $pair . ' ' . $price;
  $wrapper->title->set($title);

  // Account

  $wrapper->field_instrument->set($instrument->tid);
  $wrapper->field_price->set($price);
  $wrapper->field_units->set(10000); // TODO make this dynamic
  $wrapper->field_stop_loss->set($order->field_stop_loss->value());
  $wrapper->field_tp1->set($order->field_take_profit->value());
  $wrapper->field_take_profit->set($order->field_take_profit->value());
  $wrapper->field_tp2->set($order->field_tp2->value());
  //$wrapper->field_setup->set($order->nid->value());

  //$wrapper->field_candle_time->set($order->field_candle_time->value());
  return $wrapper;
}

function trader_form_backtest_strat($form, $form_state, $node = FALSE) {

  if ($node) {
    $form['strat'] = array(
        '#type' => 'hidden',
        '#value' => $node->nid,
    );
  } else {
    $options = trader_get_strats(FALSE, FALSE);
    $form['strat'] = array(
        '#type' => 'select',
        '#title' => t('Strategy'),
        '#options' => $options,
    );
  }
  $default = time();
  $format = 'm/d/Y h:i a';

  $form['start'] = array(
      '#type' => 'date_select',
      '#title' => t('Start'),
      '#date_type' => DATE_UNIX,
      '#date_format' => $format,
      '#default_value' => $default,
      '#date_increment' => 1,
      '#date_year_range' => '-10:+0',
  );
  $form['end'] = array(
      '#type' => 'date_select',
      '#title' => t('End'),
      '#date_type' => DATE_UNIX,
      '#date_format' => $format,
      '#default_value' => $default,
      '#date_increment' => 1,
      '#date_year_range' => '-10:+0',
  );
  $form['create'] = array(
      '#type' => 'checkbox',
      '#title' => t('Create Record'),
      '#default_value' => TRUE,
  );
  $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Backtest'),
  );
  $form['update'] = array(
      '#type' => 'button',
      '#executes_submit_callback' => TRUE,
      '#value' => t('Update DB'),
      '#submit' => array('trader_form_backtest_update_submit'),
  );

  if (!empty($form_state['storage']['results'])) {
    $form['results']['#markup'] = $form_state['storage']['results'];
  }

  return $form;
}

function trader_form_backtest_update_submit($form, $form_state) {
  $values = $form_state['values'];
  $strat = $values['strat'];
  $strat = node_load($strat);
  $strat = entity_metadata_wrapper('node', $strat);

  $start = strtotime($values['start']) - (60 * 60 * 24 * 7);
  $end = strtotime($values['end']);

  $fracs = trader_strat_load_fracs($strat);
  $instrument = $strat->field_instrument->value();
  foreach ($fracs as $frac) {
    oanda_update_prices_bidask($instrument->name, $frac, 86400, $start, $end, TRUE);
  }
  $form_state['rebuild'] = TRUE;
}

function trader_form_backtest_strat_submit($form, &$form_state) {
  $values = $form_state['values'];
  $strat = $values['strat'];
  $start = $values['start'];
  $end = $values['end'];
  $form_state['rebuild'] = TRUE;
  if (is_numeric($strat)) {
    $strat = node_load($strat);
  }
  $create = $values['create'];
  if ($backtest = trader_backtest($strat, $start, $end, NULL, $create)) {
    $results = node_view($backtest);
  } else {
    $results = array('#markup' => 'no backtest generated');
  }
  $form_state['storage']['results'] = drupal_render($results);
}