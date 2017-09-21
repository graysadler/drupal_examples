<?php

function trader_clear_setup_criteria($setup, $type) {
  $setup_update = &drupal_static('trader_setup_save');

  $field = 'field_' . $type . '_criteria';
  $criterias = $setup->{$field}->value();
  foreach ($criterias as $fck => $fci) {
    //$fcv = $strat->field_entry_criteria[$fck]->value();
    //$fcv =
    //$entry = entity_metadata_wrapper('field_collection_item', $fci->item_id);
    $entry = $setup->{$field}[$fck];
    $entry->field_criteria_met->set(FALSE);
    $entry->field_candle_time->set(NULL);
    //$entry->save(TRUE);
  }

  $setup_update[$setup->nid->value()] = $setup;
}

function trader_save_setup_criteria($setup, $type) {
  $field = 'field_' . $type . '_criteria_triggered';
  $criterias = $setup->{$field}->value();
  foreach ($criterias as $fck => $fci) {
    //$entry = $setup->{$field}[$fck];
    $entry = entity_metadata_wrapper('field_collection_item', $fci);
    $entry->save(TRUE);
  }
}

function trader_setup_check($strat, $studies_all, $type, $setup = FALSE, $backtest = FALSE) {
  $setup_update = &drupal_static('trader_setup_update');
  $update = FALSE;
  $new_setup = FALSE;
  $field = 'field_' . $type . '_criteria';
  $field_triggered = 'field_' . $type . '_criteria_triggered';
  // Wrap with entity api
  if (!$setup) {
    //$setup_base = &drupal_static('trader_setup_base', NULL);
    //if (!$setup_base) {
    //$setup_base = trader_prepare_setup_from_strat($strat, $backtest);
    //}
    $setup = trader_prepare_setup_from_strat($strat, $backtest);
    //$setup = clone $setup_base;
    //$setup->{$field}->set($strat->{$field}->value());
    //$new_setup = TRUE;
  }
  $strat_wrapper = entity_metadata_wrapper('node', $strat);
  $criterias = $strat_wrapper->{$field}->value();

  // Save all met criteria in an array
  $triggered = array();
  if ($setup->field_entry_criteria_triggered) {
    foreach ($setup->field_entry_criteria_triggered as $ref) {
      $triggered[$ref->value()->item_id] = $ref->value()->item_id;
    }
  }

  // Loop through each entry criteria
  $total = count($criterias);
  $count = 0;
  foreach ($criterias as $fck => $fci) {
    //$fcv = $strat->field_entry_criteria[$fck]->value();
    //$fcv =
    //$entry = entity_metadata_wrapper('field_collection_item', $fci);
    $entry = $strat_wrapper->{$field}[$fck];
    $frac = $entry->field_fractal->value();
    $entry_id = $fci->item_id;
    $prev_met = FALSE;
    if (in_array($entry_id, $triggered)) {
      // If criteria already met, make sure it's not always required
      if ($entry->field_always_required->value() == FALSE) {
        $count++;
        continue;
      } else {
        // Remove from triggered array and check entry criteria once again
        unset($triggered[$entry_id]);
        $prev_met = TRUE;
      }
    }

    if (empty($studies_all[$frac])) {
      continue;
    }

    $studies = $studies_all[$frac];

    $candle_time = $studies['ticks'][0]->timestamp;
    $study = $entry->field_variable->value();
    $value = NULL;
    $value_comp = NULL;

    if ($study == 'callback') {
      $callback = $entry->field_value->value();
      $return = call_user_func($callback, $strat, $setup, $studies_all, $type);
      if ($return) {
        $met = TRUE;
      }
    } else {
      if (!empty($studies[$study])) {
        if (isset($studies[$study][$entry->field_value->value()])) {
          $value = $studies[$study][$entry->field_value->value()];
        }
      }

      $study_comp = $entry->field_variable_comp->value();

      if ($study_comp == 'value') {
        $value_comp = $entry->field_value_comp->value();
      } else {
        if (!empty($studies[$study_comp])) {
          if (isset($studies[$study_comp][$entry->field_value_comp->value()])) {
            $value_comp = $studies[$study_comp][$entry->field_value_comp->value()];
          }
        }
      }

      // TODO, make sure === NULL is correct
      if ($value === NULL || $value_comp === NULL) {
        // Shouldn't be here
        break;
      }

      $op = $entry->field_op->value();

      switch ($op) {
        case '=':
          $met = $value == $value_comp;
          break;
        case '<':
          $met = $value < $value_comp;
          break;
        case '>':
          $met = $value > $value_comp;
          break;
        case '<=':
          $met = $value <= $value_comp;
          break;
        case '>=':
          $met = $value >= $value_comp;
          break;
        default:
          $met = FALSE;
      }
    }
    if ($type == 'entry') {
      if ($met) {
        $count++;
        // Don't update if this was already previously met
        if (!$prev_met) {
          $setup->field_entry_criteria_triggered[] = $entry_id;
          if ($setup->field_setup_status->value() == 'closed') {
            $setup->field_setup_status->set('pending');
          }
          $update = TRUE;
        }
      } else {
        // Only update when this required field was previously met to reduce db queries
        if ($entry->field_always_required->value() && $prev_met) {
          $setup->field_entry_criteria_triggered->set(NULL);
          $update = TRUE;
          $count = 0;          
        }
        // Skip checking the rest if not met
        break;
      }
    } else {
      // Type = close
      if ($met) {
        $entry->field_criteria_met->set(TRUE);
        $entry->field_candle_time->set($candle_time);
        $setup_update[$setup->nid->value()] = $setup;

        return $setup;
      }
    }
  }

  if ($update && $type == 'entry') {
    // Make sure this is not a duplicate setup node
    /* commenting out as this may be redundant. will try to tweak logic in trader_process_setups instead
    if (trader_setup_get_by_candletime($strat, $candle_time)) {
      watchdog('trader', 'Duplicate setup creation prevented.', NULL, WATCHDOG_WARNING);
      return FALSE;
    }
    */
    
    $setup->field_criteria_total->set($total);
    $setup->field_criteria_count->set($count);
    $ratio = round($count/$total, 2);
    $setup->field_criteria_ratio->set($ratio);
    $setup->field_candle_time->set($candle_time);
    return $setup;
  }

  return FALSE;
}

/**
 * Returns a setup if matching strat and candle_time are found
 */
function trader_setup_get_by_candletime($strat, $candle_time) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'setup')
  ->fieldCondition('field_strategy', 'target_id', $strat->nid, '=')
  ->fieldCondition('field_candle_time', 'value', $candle_time, '=')
  ->range(0, 10)
  // Run the query as user 1.
  ->addMetaData('account', user_load(1));
  
  $result = $query->execute();
  $nids = FALSE;
  if (isset($result['node'])) {
    $nids = array_keys($result['node']);
  }  
  
  return $nids;
}

/**
 * Insert setups for a given strategy
 */
function trader_process_setups($strat = FALSE, $start = FALSE, $end = FALSE, $db = FALSE, $reset = FALSE, $backtest = FALSE, $kill = FALSE) {
  global $user;
  global $oanda;
  
  $trader_enabled = variable_get('trader_status', FALSE);
  
  if (!$trader_enabled) {
    trader_set_message('Trader is NOT enabled.');
    return;
  }
  
  $time = time();
  trader_order_update_units();
  $now = time();
  
  if ($now - $time > 3) {
    trader_set_message('Updating orders took ' . ($now - $time) . ' seconds.');
  }  
  
  $time = time();
  // Check held orders
  trader_order_check_held_orders();  
  $now = time();
  
  if ($now - $time > 3) {
    trader_set_message('Checking held orders took ' . ($now - $time) . ' seconds.');
  }
  
  // Load setup process variable to check whether or not we're currently running
  $in_progress = variable_get('trader_setup_processor', FALSE);
  if ($in_progress && $kill) {
    $in_progress = FALSE;
  }
  $time = time();
  if ($in_progress) {
    // Check if processor is stuck
    $max = 60 * 2; // 2 minutes
    if ($in_progress > ($time - $max)) {
      watchdog('trader', 'Setup processor cancelled - currently running', NULL, WATCHDOG_WARNING);
      return;
    }
  } 
  variable_set('trader_setup_processor', $time);
  
  $candles = &drupal_static('trader_candles', array());
   
  $setup_studies = &drupal_static('trader_setup_studies', array());

  if (!$setup_update = &drupal_static('setup_update')) {
    $setup_update = array();
  }

  if ($reset) {
    $results = db_query("SELECT n.nid FROM node n WHERE n.type = 'setup'");
    $delete_nids = array();
    foreach ($results as $result) {
      $delete_nids[$result->nid] = $result->nid;
    }

    node_delete_multiple($delete_nids);
  }

  if (!$backtest) {
    // Load all existing and ACTIVE setups
    $results = db_query("SELECT n.nid FROM node n INNER JOIN field_data_field_setup_status s ON n.nid = s.entity_id WHERE n.type = 'setup' AND n.status = 1 AND (s.field_setup_status_value = 'pending')");
    $setup_nids = array();
    foreach ($results as $result) {
      $setup_nids[$result->nid] = $result->nid;
    }
    unset($results);
    $setups_tmp = node_load_multiple($setup_nids);
    $setups = array();
    foreach ($setups_tmp as $nid => $setup) {
      $setup = entity_metadata_wrapper('node', $setup);
      if (!$reset) {
        $strat_nid = $setup->field_strategy->value()->nid;
        $instrument = $setup->field_instrument->value();
        $setups[$strat_nid][$instrument->tid] = $setup;
      } else {
        $setup->delete();
      }
    }
    unset($setups_tmp);
  }

  // Load all existing strats if none is provided
  if (!$strat) {
    $strats = trader_get_strats(TRUE);
    unset($results);
  } else {
    $strats = array($strat);
  }

  // LOOP through each STRATEGY
  $now = new DateTime('NOW', new DateTimeZone('GMT'));
  $timestamp = $now->format('U');
  $timestamp = $timestamp - ($timestamp % 60);

  $curtime = time();
  if ($start && !is_numeric($start)) {
    $start = new DateTime($start, new DateTimeZone('America/New_York'));
    $start->setTimezone(new DateTimeZone('GMT'));
    $start = $start->format('U');
  }
  if ($end && !is_numeric($end)) {
    $end = new DateTime($end, new DateTimeZone('America/New_York'));
    $end->setTimezone(new DateTimeZone('GMT'));    
    $end = $end->format('U');
  }
  
  $setup_complete_dates = variable_get('trader_setup_complete_dates', array());
  
  // $limit is the max number of candles to return
  $limit = 3000;
  if (!$start) {
    if ($reset) {
      // Reset so start will be 24 hours ago
      $start = $timestamp - (60 * 60 * 24);
      $end = $end_data = $timestamp;
    } else {
      // Will be handled in next loop of strats
      // Start will be end of previous completion time
      //$start = $setup_complete_dates[$strat->nid];
    }
    // $start_data will be FALSE so will pick up last x candles
    $start_data = FALSE;
  } else {
    // Give 24 hours prior for indicators
    $start_data = $start - (60 * 60 * 24);
    $end_data = $end;
  }  
  
  // Load candles for each strat
  foreach ($strats as $strat) {
    $strat_wrapper = entity_metadata_wrapper('node', $strat);
    $instrument = $strat_wrapper->field_instrument->value();
    
    // Determine if start and end needs to be updated
    if (!$start) {
      if (!$reset) {
        // Start will be end of previous completion time
        // If not set, make 24 hours ago
        if (empty($setup_complete_dates[$strat->nid])) {
          $start = $timestamp - (60 * 60 * 24);
          $setup_complete_dates[$strat->nid] = $start - 1; // Add -1 to cover initial start in seconds
          trader_set_message('TRADER processing setups - NO START DATE FOUND');
        } else {
          $start = $setup_complete_dates[$strat->nid];
          $start = $start - ($start % 30); // make sure it's rounded down to closes 30 seconds                    
        }
      }
      
      // To prevent a weird gap, only limit to 60 hours
      $end = $start + (60 * 60 * 60);
      if ($end > $timestamp) {
        $end = $timestamp;
      }
      $end_data = $end;      
    }

    // Load applicable fracs
    $fracs = trader_strat_load_fracs($strat_wrapper);
        
    if (empty($fracs)) {
      watchdog('trader', 'No fracs found for strategy ' . $strat_wrapper->title->value(), NULL, WATCHDOG_ERROR);
      continue;
    }
    
    // Load candles
    $now = time();
    foreach ($fracs as $gran) {
      /* Commenting out because this may not be needed anymore
      if ($reset && $db) {
        oanda_update_prices_bidask($instrument->name, $gran, 86400, $start_data, $end_data, $db);
      }
      */
      
      if (empty($candles[$instrument->name][$gran])) {
        $candles[$instrument->name][$gran] = oanda_get_bidask_ticks($instrument->name, $start_data, $end_data, $gran, FALSE, $limit);
      }
      if (empty($candles[$instrument->name][$gran])) {
        watchdog('trader', 'No candles were loaded for ' . $strat->title . '.', NULL, WATCHDOG_ERROR);
        //$continue = TRUE;
        //break;
      }
    }
    
    //if ($continue) {
      //continue;
    //}
    
    $time = time();
    if ($time - $now > 3) {    
      trader_set_message('Loading candles took ' . ($time - $now) . ' seconds.');
    }
    $now = time();    
  }
  
  foreach ($strats as $strat) {
    $continue = FALSE;
    $strat_wrapper = entity_metadata_wrapper('node', $strat);
    $instrument = $strat_wrapper->field_instrument->value();
    
    // Get last complete candle
    $last_candle = end($candles[$instrument->name][$strat_wrapper->field_fractal->value()]);
    
    // If strat should only use completed candles, make sure we're not storing an incomplete candle times
    if ($strat_wrapper->field_completed_candles->value()) {      
      while ($last_candle->complete == FALSE) {
        $last_candle = prev($candles[$instrument->name][$strat_wrapper->field_fractal->value()]);
        trader_set_message('moving candle');
      }
    }
        
    // Storing the last candle time so we know when to search for setups next time
    $last_candle_time = $last_candle->timestamp;

    // Skip if we're still on the candle when last checked
    // Also skip if last candle is less than previous setup candle time
    if ($setup_complete_dates[$strat->nid] >= $last_candle_time) {
      static $messaged;
      if (!$messaged) {
        trader_set_message('Skipping strat setup check due to no new candles.');
        $messaged = TRUE;
      }
      continue;
    }
    
    // Close all positions and orders if this is a reset
    if ($reset) {
      $account_id = $strat_wrapper->field_account->value();
      $result = $oanda->position_close_all($account_id);
      $result = $oanda->order_close_all($instrument->name, $account_id);
    }
    
    // Loop through and store studies
    foreach ($strat_wrapper->field_studies as $fc) {
      $study = $fc->field_study->value();
      $study_load[$study] = $fc->field_study_value->value();
    }
    
    if (empty($study_load)) {
      // If the strat has an entry criteria then skip
      if ($strat_wrapper->field_entry_type->value() == 'criteria') {
        trader_set_message('Setup search cancelled for strat - no studies loaded.');
        continue;        
      }
    }
    
    $time = time();
    if ($time - $now > 3) {
      trader_set_message('Loading study variables took ' . ($time - $now) . ' seconds.');
    }
    $now = time();

    // LOAD studies
    $studies_all = trader_get_studies($candles, $instrument->name, $study_load);
    $time = time();
    if ($time - $now > 3) {
      trader_set_message('Loading study data took ' . ($time - $now) . ' seconds.');
    }
    $now = time();

    // Saving to static variable so it can be used in backtest
    $setup_studies[$strat->nid] = $studies_all;

    // Loop from start to end and check setups on each new candle
    // Incrementing by 1 second as some candles which are completed are sometimes 31, 32, etc.
    for ($i = $start; $i < $end; $i += 1) {
      // Make sure we don't duplicate a candle
      if ($i <= $setup_complete_dates[$strat->nid]) {
        continue;
      }
      $setup = FALSE;
      if (!empty($setups[$strat->nid][$instrument->tid])) {
        $setup = $setups[$strat->nid][$instrument->tid];
      }

      $studies = array();
      $result = FALSE;
      foreach ($fracs as $frac) {
        if (!empty($studies_all[$instrument->name][$frac][$i])) {
          // Load studies for this candle
          $studies[$frac] = $studies_all[$instrument->name][$frac][$i];
        }
      }
      if (empty($studies)) {
        continue;
      }

      // Skip if the prev candle isn't complete and the strat tells it so
      // TODO: May need to move this somewhere else and may need to improve this
      // logic so it's node candle 1.
      if ($strat_wrapper->field_completed_candles->value()) {
        if (!$studies[$strat_wrapper->field_fractal->value()]['ticks'][1]->complete) {       
          trader_set_message('Skip setup check as this candle is incomplete.');
          continue;
        }
      }
      
      $close = FALSE;
      if ($setup) {
        // Check to see if it should be closed
        if ($setup->field_criteria_count->value()) {
          if ($close = trader_setup_check($strat, $studies, 'close', $setup, $backtest)) {
            $setup->field_setup_status->set('closed');
            $setup->field_criteria_count->set(0);
            $setup->field_entry_criteria_triggered->set(NULL);
            $setups[$strat->nid][$instrument->tid] = $setup;

            if (!$backtest) {
              $setup_update[$setup->nid->value()] = $setup;
            }
            $setup = FALSE;
          }
        }
      }
      
      if (!$close) {
        if ($strat_wrapper->field_entry_type->value() == 'callback') {
          $callback = $strat_wrapper->field_entry_callback->value();
          if ($callback && function_exists($callback)) {
            $setup = call_user_func($callback, $studies, $setup, $strat_wrapper);
          } else {
            trader_set_message('Strategy using entry callback but no callback function found.');
            // Break out of this for loop
            break;
          }
        } else {          
          $setup = trader_setup_check($strat, $studies, 'entry', $setup, $backtest);
        } 
      }

      if ($setup) {
        $setup->field_current_price->set($studies[$setup->field_fractal->value()]['ticks'][0]->close);

        $setups[$strat->nid][$instrument->tid] = $setup;

        // Check if all criteria met
        $criteria_total = $setup->field_criteria_total->value();
        $criteria_count = $setup->field_criteria_count->value();
        if ($criteria_total == $criteria_count) {    
          trader_set_message('Setup complete ' . $strat->title . ' current candle:' . $i . ' current time:' . $timestamp);
          unset($setups[$strat->nid][$instrument->tid]);
          
          // EXEC setup function when setup completes all criteria to pass in entry/exits
          $callback = !empty($strat_wrapper->field_callback->value()) ? $strat_wrapper->field_callback->value() : FALSE;
          if ($callback && function_exists($callback)) {
            $setup = call_user_func($callback, $studies[$setup->field_fractal->value()], $setup, $strat_wrapper);
          } else {
            $setup = trader_setup_add_prices($studies[$setup->field_fractal->value()], $setup, $strat_wrapper);
          }
          $setup->field_setup_status->set('completed');
          
          // Check min pips
          if ($min_pips = $strat_wrapper->field_min_pips->value()) {
            $reward = trader_pip_from_decimal($setup->field_reward->value(), $setup->field_instrument->field_pip->value());
            if ($reward < $min_pips) {
              $setup->field_setup_status->set('closed');
            }
          }
          
          if ($setup->field_setup_status->value() == 'completed') {
            trader_set_message('Setup created at ' . format_date($i));
            
            // If automating the ordering, do that now
            if (!$backtest) {
              // If this is a new setup, save it
              if ($setup->is_new->value()) {
                $setup->save();
              }
              if ($order = trader_prepare_order_from_setup($setup)) {
                $order->save();                
              } else {
                trader_set_message('Order not created');
                continue;
              }              
            }            
          }          

          if ($backtest) {
            // Only storing these in the setup_update array when it's complete
            $setup_update[$setup->field_candle_time->value()] = $setup;
            $setup = FALSE;
          }
        }

        if (!$backtest) {
          // If this is a new setup, save it
          if ($setup->is_new->value()) {
            $setup->save();
          }
          $setup_update[$setup->nid->value()] = $setup;
        }
      }
    }

    $time = time();
    if ($time - $now > 3) {
      trader_set_message('Checking for setups took ' . ($time - $now) . ' seconds.');
    }
    $now = time();

    if (!$backtest) {
      $setup_complete_dates[$strat->nid] = $last_candle_time;
      variable_set('trader_setup_complete_dates', $setup_complete_dates);
    }
  }

  if (!$backtest) {
    foreach ($setup_update as $nid => $setup) {
      trader_set_message('Setup ' . $nid . ' saved');
      $setup->save();
      //trader_save_setup_criteria($setup, 'entry');
      //trader_save_setup_criteria($setup, 'close');
    }
  } else {
    return $setup_update;
  }
  $secs = time() - $curtime;
  trader_set_message('setup processing total seconds: ' . $secs);
  //watchdog('trader_setup', 'Setups processed');
  variable_set('trader_setup_processor', FALSE);
}


function trader_prepare_setup_from_strat($strat, $backtest) {
  $setup = entity_create('node', array('type' => 'setup'));
  
  $setup->uid = $strat->uid;
  
  $wrapper = entity_metadata_wrapper('node', $setup);

  $strat_wrapper = entity_metadata_wrapper('node', $strat);

  $side = $strat_wrapper->field_side->value();
  $wrapper->field_side->set($strat_wrapper->field_side->value());
  $wrapper->field_setup_status->set('pending');
  $instrument = $strat_wrapper->field_instrument->value();
  $pair = $instrument->name;
  $title = 'SETUP ' . strtoupper($side) . ' ' . $pair;
  $wrapper->title->set($title);
  $wrapper->field_instrument->set($instrument->tid);
  $wrapper->field_fractal->set($strat_wrapper->field_fractal->value());
  $wrapper->field_strategy->set($strat_wrapper->nid->value());
  return $wrapper;
}
/**
 * Prepares an order object
 * @param unknown $setup
 * @param string $order_type
 * @return EntityMetadataWrapper
 */
function trader_prepare_order_from_setup($setup, $order_type = FALSE) {
  global $oanda;
  $order = new stdClass;
  $order->type = 'order';
  $order->uid = $setup->author->uid->value();
  $order->status = 1;
  $order->comment = 0;
  $order->promote = 0;
  $order->language = LANGUAGE_NONE;

  $strat = $setup->field_strategy;
  
  $wrapper = entity_metadata_wrapper('node', $order);

  $side = $setup->field_side->value();
  $instrument = $setup->field_instrument;
  $pair = $instrument->name->value();
  $price = $setup->field_price->value();
  $title = strtoupper($side) . ' ' . $pair . ' ' . $price;
  $wrapper->title->set($title);

  // Order type
  if (!$order_type) {
    // For now assume as orders are LIMIT
    $order_type = 'LIMIT';
    // TODO in the future, perhaps make mit or stop based on current price?
  }
  
  // Account
  $wrapper->field_side->set($side);
  $wrapper->field_instrument->set($instrument->tid->value());
  $wrapper->field_price->set($price);
  //$pips = _trader
  $pips = $setup->field_risk->value() / $instrument->field_pip->value();
  $sub = $oanda->account($strat->field_account->value());
  $wrapper->field_account->set($strat->field_account->value());
  $balance = $sub->account->marginAvailable;
  //$balance = $oanda->account->account->marginAvailable;
  
  $units = 0;
  
  $unit_type = $strat->field_unit_type->value();
  if ($unit_type == 'percent') {
    $units = trader_calc_position($instrument->name->value(), $setup->field_strategy->field_max_trade_risk->value(), $balance, $pips);
  } elseif ($unit_type == 'specific') {
    $units = $strat->field_specific_units->value();
  }
  
  if (!$units) {
    trader_set_message('Cannot order as # units has not been set.');
    return false;
  }
  
  $wrapper->field_units->set($units); 
  $wrapper->field_stop_loss->set($setup->field_stop_loss->value());
  $wrapper->field_take_profit->set($setup->field_tp1->value());
  //TODO FINISH BELOW
  //$wrapper->field_expiry->set() TODO: finish this
  //$wrapper->field_lower_bound->set()
  //$wrapper->field_upper_bound->set()
  $wrapper->field_order_type->set($order_type);
  $wrapper->field_order_status->set('pending');
  $wrapper->field_setup->set($setup->nid->value());

  $wrapper->field_candle_time->set($setup->field_candle_time->value());
  return $wrapper;
}

function trader_setup_add_prices($studies, $setup, $strat) {
  $tick = $studies['ticks'][0];
  $spread = trader_pip_format($strat->field_instrument, ($tick->close_ask - $tick->close_bid));
  $pip_value = $setup->field_instrument->field_pip->value();
  $side = $strat->field_side->value();
  $stop = FALSE;
  $risk = FALSE;
  
  // Price
  $price = trader_setup_get_price($strat, $studies);
  /*
  $price = _trader_get_study_value($strat->field_entry_var->value(), $strat->field_entry_var_value->value(), $studies);
  if ($strat->field_entry_buffer->value()) {
    $buffer = $strat->field_entry_buffer->value() * $pip_value;
    $price = $side == 'buy' ? $price + $buffer : $price - $buffer;
  }

  if ($strat->field_entry_spread->value()) {
    $price = $side == 'buy' ? $price - $spread : $price + $spread;
  }

  $price = trader_pip_format($strat->field_instrument, $price);
  */
  $setup->field_price->set($price);

  // TP1
  $tp1 = trader_setup_get_take_profit($strat, $studies, $price);
  /*
  $tp1 = $strat->field_fc_take_profit[0];
  if ($tp1->field_take_profit_var->value() == 'pips') {
    $pips = $tp1->field_take_profit_value->value();
    $pips = $pips * $pip_value;
    $tp1 = $side == 'buy' ? $price + $pips : $price - $pips;
  } else {
    $tp1 = _trader_get_study_value($tp1->field_take_profit_var->value(), $tp1->field_take_profit_value->value(), $studies);
  }
  $tp1 = trader_pip_format($strat->field_instrument, $tp1);
  */
  $setup->field_tp1->set($tp1);
  
  // Stop loss
  if ($strat->field_stop_var->value() == 'pips') {
    $pips = $strat->field_stop_var_value->value();
    $pips = $pips * $pip_value;
    $stop = 'buy' ? $price - $pips : $price + $pips;
  } else {
    // Use studies to find value
    $stop = _trader_get_study_value($strat->field_stop_var->value(), $strat->field_stop_var_value->value(), $studies);
  }

  $reward = $side == 'buy' ? $tp1 - $price : $price - $tp1;
  $setup->field_reward->set($reward);
  
  if ($stop) {
    $risk = $side == 'buy' ? $price - $stop : $stop - $price;
    $setup->field_risk->set($risk);
    
    // Make sure SL is even to TP if required 1:1
    if ($strat->field_stop_even_rr->value()) {
      if ($risk < $reward) {
        $stop = $side == 'buy' ? $price - $reward : $price + $reward;
        $setup->field_stop_loss->set($stop);
      }
    }
    
    // If buffer wanted, add it
    if ($strat->field_stop_buffer->value()) {
      $buffer = $strat->field_stop_buffer->value() * $pip_value;
      $stop = $side == 'buy' ? $stop - $buffer : $stop + $buffer;
    }
    
    // If spread wanted, add it
    if ($strat->field_stop_spread->value()) {
      $stop = $side == 'buy' ? $stop - $spread : $stop + $spread;
    }
    
    $stop = trader_pip_format($setup->field_instrument, $stop);
    $setup->field_stop_loss->set($stop);
  }
  
  return $setup;
}

function trader_setup_get_price($strat, $studies) {
  $tick = $studies['ticks'][0];
  $side = $strat->field_side->value();  
  $spread = trader_pip_format($strat->field_instrument, ($tick->close_ask - $tick->close_bid));  
  $pip_value = $strat->field_instrument->field_pip->value();
  $price = _trader_get_study_value($strat->field_entry_var->value(), $strat->field_entry_var_value->value(), $studies);
  if ($strat->field_entry_buffer->value()) {
    $buffer = $strat->field_entry_buffer->value() * $pip_value;
    $price = $side == 'buy' ? $price + $buffer : $price - $buffer;
  }
  
  if ($strat->field_entry_spread->value()) {
    $price = $side == 'buy' ? $price - $spread : $price + $spread;
  }
  
  $price = trader_pip_format($strat->field_instrument, $price);
  return $price;  
}
function trader_setup_get_take_profit($strat, $studies, $price) {
  $tp = FALSE;
  
  $tp1 = $strat->field_fc_take_profit[0];
  if ($tp1->field_take_profit_var->value() == 'pips') {
    $pips = $tp1->field_take_profit_value->value();
    $pips = $pips * $pip_value;
    $tp = $side == 'buy' ? $price + $pips : $price - $pips;
  } else {
    $tp = _trader_get_study_value($tp1->field_take_profit_var->value(), $tp1->field_take_profit_value->value(), $studies);
  }
  
  if ($tp) {    
    $tp = trader_pip_format($strat->field_instrument, $tp);
  }  
  
  return $tp;
}

function trader_setup_insert_results() {
  db_query('DELETE FROM field_data_field_result WHERE 1');
  // Load all setups that have completed but don't have a result
  // Load all existing and ACTIVE setups
  $results = db_query("SELECT n.nid FROM node n
	LEFT JOIN field_data_field_result r ON n.nid = r.entity_id
	INNER JOIN field_data_field_setup_status s ON n.nid = s.entity_id
	INNER JOIN field_data_field_candle_time c ON n.nid = c.entity_id
	WHERE n.type = 'setup' AND s.field_setup_status_value = 'completed' AND r.field_result_value IS NULL
	ORDER BY c.field_candle_time_value ASC");

  foreach ($results as $result) {
    $setup_nids[$result->nid] = $result->nid;
  }
  $setups_tmp = node_load_multiple($setup_nids);
  $setups = array();
  foreach ($setups_tmp as $nid => $setup) {
    $setup = entity_metadata_wrapper('node', $setup);
    $instrument = $setup->field_instrument[0];
    $data[$instrument->name->value()][$setup->nid->value()] = $setup;
  }

  $update = array();

  foreach ($data as $instrument => $setups) {
    $setup = reset($setups);
    $start = $setup->field_candle_time->value();
    $setup = end($setups);
    $time = $setup->field_candle_time->value() + (60 * 60 * 6); // Give it 4 hours after triggered
    $end = $time;

    oanda_update_prices_bidask($instrument, 'M5', 86400, $start, $end, TRUE);

    $candles = oanda_get_bidask_ticks($instrument, $start, $end, 'M5', TRUE);
    foreach ($setups as $setup) {
      foreach ($candles as $timestamp => $candle) {
        if ($setup->field_candle_time->value() > $timestamp) {
          continue;
        }
        $tp = $setup->field_tp1->value();
        $sl = $setup->field_stop_loss->value();
        $side = $setup->field_side->value();
        $risk = $setup->field_risk->value();
        $reward = $setup->field_reward->value();

        // check stop loss
        if (($side == 'sell' && $candle->high_ask >= $sl) || ($side == 'buy' && $candle->low_bid <= $sl)) {
          $setup->field_result->set(-($risk));
          $setup->field_result_candle_time->set($timestamp);
          $update[] = $setup;
          break;
        }

        // check take profit
        if (($side == 'buy' && $candle->high_bid >= $tp) || ($side == 'sell' && $candle->low_ask <= $tp)) {
          $setup->field_result->set(($reward));
          $setup->field_result_candle_time->set($timestamp);
          $update[] = $setup;
          break;
        }

      }
    }
  }

  if (!empty($update)) {
    foreach ($update as $setup) {
      $setup->save();
    }
  }
}