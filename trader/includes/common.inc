<?php

function _trader_get_study_value($var, $value, $studies) {
  if (array_key_exists($var, $studies)) {
    return $studies[$var][$value];
  }

  return FALSE;
}

function trader_pip_from_decimal($value, $pips) {
  $exp = _trader_pip_precision($pips);
  
  return $value * pow(10, $exp);
}
function _trader_pip_precision($value) {
  $split = explode('.', $value);
  return strlen($split[1]);
}

function _trader_pip_format($value, $precision) {
  return number_format($value, $precision);
}

function trader_pip_format($instrument, $value) {
  if (is_array($instrument) || is_array($instrument->field_pip_precision)) {
    $test = 'test';
  }
  $precision = _trader_pip_precision($instrument->field_pip_precision->value());
  return _trader_pip_format($value, $precision);
}

function trader_calc_position($pair, $risk, $balance, $pips) {
  global $oanda;
  $curs = explode('_', $pair);
  $factor = $curs[0] == 'JPY' || $curs[1] == 'JPY' ? 100 : 10000;

  if ($curs[1] == 'USD') {
    $price = 1;
  } else {
    // Find USD_cur[1]
    $priceObj = $oanda->price('USD_' . $curs[1]);
    $price = ($priceObj->bids[0]->price + $priceObj->asks[0]->price) / 2;
  }

  $amount_to_risk = $balance * $risk;
  $r = $price * $amount_to_risk;
  $c = $r / $pips;
  $units = $c * ($factor/1);
  $units = round($units);
  return $units;
}

function trader_load_instrument($pair) {
  $terms = taxonomy_get_term_by_name($pair);
  $term = array_shift($terms);
  $wrapper = entity_metadata_wrapper('taxonomy_term', $term);
  return $wrapper;
}

function trader_chart_generate_settings($studies) {
  $ticks = $studies['ticks'];
  $highs = $studies['highs'];
  $lows = $studies['lows'];
  $closes = $studies['closes'];
  $opens = $studies['opens'];

  $color = '#8c8c8c';

  $trend = 0;
  foreach($ticks as $key => $tick) {
    $time = $tick->timestamp * 1000;

    $stoch_fast = $studies['k'][$key];
    $stoch_slow = $studies['d'][$key];

    $rsi = $studies['rsis'][$key];
    $slope = $studies['lr_slope'][$key];
    $rev = $studies['lr_rev'][$key];
    $lr = $studies['sma_short'][$key];
    $dev_high = $studies['sadler_high'][$key];
    $dev_low = $studies['sadler_low'][$key];
    $dev_mid = ($dev_high + $dev_low) / 2;
    //$dev_low = $lr - $devs[$key];
    //$dev_high = $lr + $devs[$key];
    //$dist = $max[$key];
    //$dev_high = $lr + $dist;
    //$dev_low = $lr - $dist;
    $action = $studies['divergence_action'][$key];
    $sma = $studies['sma_long'][$key];

    //$slope = $lr > $prev_lr ? 1 : -1;
    //$slope = $lr > $dev_mid ? 1 : -1;
    //$trend = $lr > $sma ? 1 : -1;
    //$trend = $trends[$key] == 'buy' ? 1 : -1;

    //$trend = $trends[$key];

    /* THIS WORKS GREAT!!! */
    if ($tick->high > $lr && $tick->low > $lr && $tick->close > $tick->open) {
      $trend = 1;
    }
    if ($tick->high < $lr && $tick->low < $lr && $tick->close < $tick->open) {
      $trend = -1;
    }
    /*
     if ($sma > $prev_sma) {
     $trend = 1;
     }
     if ($sma < $prev_sma) {
     $trend = -1;
     }
     */
    /*
     if ($stoch_fast > $stoch_slow) {
     $trend = 1;
     }
     if ($stoch_fast < $stoch_slow) {
     $trend = -1;
     }
     */
    /*
     if ($stoch_fast > 50) {
     $trend = 1;
     }
     if ($stoch_fast < 50) {
     $trend = -1;
     }*/
    /*
     if ($stoch_slow >= $prev_ss) {
     $trend = 1;
     }
     if ($stoch_slow <= $prev_ss) {
     $trend = -1;
     }*/
    /*
     if ($stoch_fast >= $prev_sf) {
     $trend = 1;
     }
     if ($stoch_fast <= $prev_sf) {
     $trend = -1;
     }
     */
    /* THIS IS A BIT TOO SLOW
     if ($rsis_avg[$key] > 55) {
     $trend = 1;
     }
     if ($rsis_avg[$key] < 45) {
     $trend = -1;
     } */


    /*
     if ($lr > $prev_lr && $tick->close > $tick->open) {
     $trend = 1;
     }
     if ($lr < $prev_lr) {
     $trend = -1;
     }*/




    //$trend = $lr_trend[$key];
    //$trend = $trend == 'up' ? 1 : -1;

    /*
     if ($sma > $prev_sma) {
     $color = '#00ff00';
     }
     if ($sma < $prev_sma) {
     $color = '#ff0000';
     }
     */

    if ($trend > 0) {
      $color = '#13a300';
    }
    if ($trend < 0) {
      $color = '#930000';
    }
    if ($action) {
      if ($action == 'reverse down') {
        //if ($action == 'confirm down') {
        //if ($action == 'reverse down' || $action == 'confirm down') {
        $color = '#ff2df1';
      }
      if ($action == 'reverse up') {
        //if ($action == 'confirm up') {
        //if ($action == 'reverse up' || $action == 'confirm up') {
        $color = '#c7ff00';
      }
    }

    $prev_sma = $sma;
    $prev_lr = $lr;
    $prev_ss = $stoch_slow;
    $prev_sf = $stoch_fast;

    $data['sma'][] = array('x' => (int)$time, 'y' => (float)$sma, 'color' => $color);
    //$data['sma_short'][] = array('x' => (int)$time, 'y' => (float)$sma_short, 'color' => $color);

    //$data['sar'][] = array('x' => (int)$time, 'y' => (float)$sar, 'color' => '#F033FF');
    $data['rsi'][] = array((int)$time, (float)$rsi, 'RSI');
    $data['lr_rev'][] = array((int)$time, (float)$rev, 'LRRev');
    $data['lr_slope'][] = array((int)$time, (float)$slope, 'LRSlope');
    $data['lr'][] = array((int)$time, (float)$lr, 'LR');
    $data['dev_high'][] = array((int)$time, (float)$dev_high, 'LRH');
    $data['dev_low'][] = array((int)$time, (float)$dev_low, 'LRL');
    $data['stoch_k'][] = array((int)$time, (float)$stoch_fast, 'Stoch F');
    $data['stoch_d'][] = array((int)$time, (float)$stoch_slow, 'Stoch S S');

    $data['tick'][] = array((int)$time, (float)$opens[$key], (float)$highs[$key], (float)$lows[$key], (float)$closes[$key]);
    $prev_time = $time;
    //}
  }

  //$tick = end($data['tick']);
  //watchdog('trader','TRADER: Last tick close is ' . $tick[4]);

  return $data;

  $settings['oanda']['chart']['data'] = $data;
  $commands[] =  ajax_command_settings($settings, TRUE);
  return array('#type' => 'ajax', '#commands' => $commands);
}

function trader_get_current_prices($instruments) {
  global $oanda;

  if (!is_array($instruments)) {
    $instruments = array($instruments);
  }

  $prices = $oanda->prices($instruments);

  if (empty($prices->prices)) {
    return;
  }

  $return = array();

  foreach ($prices->prices as $key => $price) {
    $return[$price->instrument] = $price;
  }

  return $return;
}

function trader_get_default_units($account) {
  global $user;
  $wrapper = entity_metadata_wrapper('user', $account);
  $account = user_load($user->uid);
  return $wrapper->field_default_units->value();
}

function trader_get_price_history($instrument, $start, $end, $gran) {
  $candles = oanda_get_ticks($instrument, $start, $end, $gran);

  foreach ($candles as $key => $candle) {
    $highs[$key] = $candle->high;
    $lows[$key] = $candle->low;
    $closes[$key] = $candle->close;
  }

  return array(
      'candles' => $candles,
      'highs' => $highs,
      'lows' => $lows,
      'closes' => $closes,
  );
}

function trader_get_strats($active_only = FALSE, $load = TRUE) {
  $items = array();

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'strategy')
  ->propertyCondition('status', NODE_PUBLISHED);

  if ($active_only) {
    $query->fieldCondition('field_strat_live', 'value', 1, '=');
  }

  //->fieldOrderBy('field_photo', 'fid', 'DESC')
  //->range(0, 10)
  // Run the query as user 1.
  $query->addMetaData('account', user_load(1));

  $result = $query->execute();
  if (isset($result['node'])) {
    $items_nids = array_keys($result['node']);
    $items = entity_load('node', $items_nids);
  }

  return $items;
}

/**
 * Load users with API credentials
 */
function trader_get_users() {
  $items = array();

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'user')
  ->entityCondition('bundle', 'user')
  ->propertyCondition('status', 1)
  ->fieldCondition('field_oanda_api', 'value', 'NULL', '!=')
  ->fieldCondition('field_account_id', 'value', 'NULL', '!=');
  
  //->fieldOrderBy('field_photo', 'fid', 'DESC')
  //->range(0, 10)
  // Run the query as user 1.
  $query->addMetaData('account', user_load(1));

  $result = $query->execute();
  if (isset($result['user'])) {
    $uids = array_keys($result['user']);
  }

  $users = user_load_multiple($uids);
  return $users;
}

function trader_load_trade_by_id($account_id, $trade_id) {
  $items = array();
  
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'trade')
  ->propertyCondition('status', NODE_PUBLISHED)
  ->fieldCondition('field_trade_id', 'value', $trade_id, '=')
  ->fieldCondition('field_account', 'value', $account_id, '=');
  
    
  //->fieldOrderBy('field_photo', 'fid', 'DESC')
  //->range(0, 10)
  // Run the query as user 1.
  $query->addMetaData('account', user_load(1));
  
  $result = $query->execute();
  if (isset($result['node'])) {
    $items_nids = array_keys($result['node']);
    $items = entity_load('node', $items_nids);
  }
  
  return array_shift($items);
}

function trader_get_studies($frac_candles, $pair, $study_load, $organize = TRUE) {
  $studies_all = &drupal_static('trader_studies_all');
  $studies = &drupal_static('trader_studies');

  if (isset($studies) && $organize) {
    //return $studies;
  }

  if (isset($studies_all) && !$organize) {
    //return $studies_all;
  }

  $studies = array();

  $key = 0;
  foreach ($frac_candles[$pair] as $frac => $candles) {
    foreach ($candles as $candle) {
      $closes[$key] = $candle->close;
      $highs[$key] = $candle->high;
      $lows[$key] = $candle->low;
      $opens[$key] = $candle->open;
      $ticks[$key] = $candle;
      $key++;
    }

    $studies[$pair][$frac]['closes'] = $closes;
    $studies[$pair][$frac]['highs'] = $highs;
    $studies[$pair][$frac]['lows'] = $lows;
    $studies[$pair][$frac]['opens'] = $opens;
    $studies[$pair][$frac]['ticks'] = $ticks;

    if (!empty($study_load['rsi'])) {
      $studies[$pair][$frac]['rsi'] = trader_rsi($closes, $study_load['rsi']);
    }

    if (!empty($study_load['stoch'])) {
      $stoch_ops = $study_load['stoch'];
      $stoch_ops = explode('/', $stoch_ops);
      $ma = TRADER_MA_TYPE_SMA;
      if (!empty($stoch_ops[3])) {
        $ma = constant($stoch_ops[3]);
      }
      $stoch = trader_stoch($highs, $lows, $closes, $stoch_ops[0], $stoch_ops[1], $ma, $stoch_ops[2], $ma);
      $studies[$pair][$frac]['k'] = $stoch[0];
      $studies[$pair][$frac]['d'] = $stoch[1];
    }

    if (!empty($study_load['sma'])) {
      $studies[$pair][$frac]['sma'] = trader_sma($closes, $study_load['sma']);
    }

    if (!empty($study_load['sma_short'])) {
      $studies[$pair][$frac]['sma_short'] = trader_sma($closes, $study_load['sma_short']);
    }

    if (!empty($study_load['sma_long'])) {
      $studies[$pair][$frac]['sma_long'] = trader_sma($closes, $study_load['sma_long']);
    }

    if (!empty($study_load['divergence'])) {
      $stoch_ops = $study_load['divergence'];
      $stoch_ops = explode('/', $stoch_ops);
      $ma = TRADER_MA_TYPE_SMA;
      if (!empty($stoch_ops[3])) {
        $ma = constant($stoch_ops[3]);
      }
      $stoch = trader_stoch($highs, $lows, $closes, $stoch_ops[0], $stoch_ops[1], $ma, $stoch_ops[2], $ma);
      $divergence = trader_divergence($stoch[0], $stoch[1], $ticks, $stoch_ops[4]);
      $studies[$pair][$frac]['divergence_side'] = $divergence['side'];
      $studies[$pair][$frac]['divergence_action'] = $divergence['action'];
    }

    if (!empty($study_load['lr'])) {
      $linreg = trader_linearreg($closes, $study_load['lr']);
      $studies[$pair][$frac]['lr'] = $linreg;
      $devs = trader_stddev($linreg, $study_load['lr'], 2);
      $count = count($candles);
      while ($count - count($devs) > 0) {
        array_unshift($devs, NULL);
      }
      foreach ($linreg as $lrk => $lr) {
        $studies[$pair][$frac]['lr_high'][$lrk] = $lr + $devs[$lrk];
        $studies[$pair][$frac]['lr_low'][$lrk] = $lr - $devs[$lrk];
      }
    }

    if (!empty($study_load['lr_slope'])) {
      $studies[$pair][$frac]['lr_slope'] = trader_linearreg_slope($closes, $study_load['lr_slope']);
    }


    if (!empty($study_load['lr_trend'])) {
      $sma = trader_sma($closes, $study_load['lr_trend']);
      //$linreg = trader_linearreg($closes, $study_load['lr_trend']);
      $studies[$pair][$frac]['lr_trend'] = trader_lr_trend($sma, $candles);
    }
    
    if (!empty($study_load['slope_trend'])) {
      $slopes = $studies[$pair][$frac]['lr_slope'];
      $studies[$pair][$frac]['slope_trend'] = trader_trend_slope($slopes, $highs, $lows);
    }

    if (!empty($study_load['lr_rev'])) {
      $linreg = trader_linearreg($closes, $study_load['lr_rev']);
      $revs = trader_linearreg_reverse($linreg);
      $studies[$pair][$frac]['lr_rev'] = $revs;
    }

    if (!empty($study_load['sadler'])) {
      $sadler_highs = trader_max($highs, $study_load['sadler']);
      $sadler_lows = trader_min($lows, $study_load['sadler']);
      $studies[$pair][$frac]['sadler_high'] = $sadler_highs;
      $studies[$pair][$frac]['sadler_low'] = $sadler_lows;
    }

    if (!empty($study_load['bb'])) {
      $bb = trader_bbands($closes, $study_load['bb'], 2, 2, TRADER_MA_TYPE_SMA);
      $test = 'yesy';
    }

    if (array_key_exists('wave', $study_load)) {
      if (!isset($stoch)) {
        $stoch = trader_stoch($highs, $lows, $closes, 5, 2, TRADER_MA_TYPE_SMA, 3, TRADER_MA_TYPE_SMA);
        $studies[$pair][$frac]['stoch_k'] = $stoch[0];
        $studies[$pair][$frac]['stoch_d'] = $stoch[1];
      }
      $waves = trader_waves($candles, $stoch[0], $stoch[1]);
      $test = 'yesy';
      $studies[$pair][$frac]['wave_high'] = $waves['wave_high'];
      $studies[$pair][$frac]['wave_low'] = $waves['wave_low'];
      $studies[$pair][$frac]['wave_prevhigh'] = $waves['wave_prevhigh'];
      $studies[$pair][$frac]['wave_prevlow'] = $waves['wave_prevlow'];
      $studies[$pair][$frac]['wave_trend'] = $waves['wave_trend'];
    }

    $studies_all = $studies;

    // Organize studies
    if ($organize) {
      $ticks_rev = array_reverse($candles, TRUE);
      $study_ticks = array();
      foreach ($studies[$pair][$frac] as $study => $values) {
        $values_rev = array_reverse($values, TRUE);
        $offset = 0;
        foreach($ticks_rev as $tick_key => $tick) {
          // Get last n items of the values
          $study_values = array_slice($values_rev, $offset, 10);
          $study_ticks[$tick_key][$study] = $study_values;
          $offset++;
        }
      }

      $study_ticks = array_reverse($study_ticks, TRUE);
      $studies[$pair][$frac] = $study_ticks;
    }
  }

  return $studies;
}

function trader_update_fields($entity, $fields = array()) {
  foreach ($fields as $field => $value) {
    if (isset($entity->{$field})) {
      $entity->{$field}->set($value);
    }
  }
}

/**
 * Updates instruments from Oanda
 */
function trader_update_instruments() {
  // Load all existing instruments
  $vocabulary = taxonomy_vocabulary_machine_name_load('instrument');
  $terms = entity_load('taxonomy_term', FALSE, array('vid' => $vocabulary->vid));

  foreach ($terms as $i) {
    $current[$i->name] = $i;
  }

  $fields = 'pip,maxTradeUnits,precision,maxTrailingStop,minTrailingStop,marginRate,halted,interestRate';
  $options = array('fields' => $fields);
  $response = OandaWrap::instruments($options);

  if (!empty($response->instruments)) {
    foreach ($response->instruments as $instrument) {
      if (empty($current[$instrument->instrument])) {
        $term = new stdClass();
        $term->vid = $vocabulary->vid;
        $term->language = LANGUAGE_NONE;
        $term->name = $instrument->instrument;
      } else {
        $term = $current[$instrument->instrument];
      }

      $term->field_pip[LANGUAGE_NONE][0]['value'] = $instrument->pip;
      $term->field_max_trade_units[LANGUAGE_NONE][0]['value'] = $instrument->maxTradeUnits;
      $term->field_pip_precision[LANGUAGE_NONE][0]['value'] = $instrument->precision;
      $term->field_max_trailing_stop[LANGUAGE_NONE][0]['value'] = $instrument->maxTrailingStop;
      $term->field_min_trailing_stop[LANGUAGE_NONE][0]['value'] = $instrument->minTrailingStop;
      $term->field_margin_rate[LANGUAGE_NONE][0]['value'] = $instrument->marginRate;
      $term->field_halted[LANGUAGE_NONE][0]['value'] = $instrument->halted;

      taxonomy_term_save($term);
    }
  }
}

function trader_strat_load_fracs($strat) {
  // Loop through entry and close criteria to store fracs
  $fracs = array();
  //$frac_candles = array();
  foreach ($strat->field_entry_criteria as $fck => $fc) {
    //$criteria = field_collection_item_load($fc['value']);
    //$criterias[$fck] = $criteria;
    //if (empty($criteria->field_fractal)) {
    //continue;
    //}
    $frac = $fc->field_fractal->value();
    $fracs[$frac] = $frac;
    //$frac_candles[$frac] = $start + (60 * $frac);
  }

  return $fracs;
}

/**
 * Checks trade targets for potential stop loss move. Returns array if trade should be updated, otherwise FALSE.
 */
function trader_manage_trade($trade, $candle, $studies) {
  //TODO finish this
  return;
  $ticks = $studies['ticks'];
  $prev_tick = $ticks[1];

  $side = $trade->field_side->value();
  $stop = $trade->field_stop_loss->value();
  $price = $trade->field_price->value();
  $update = FALSE;

  if ($side == 'buy') {
    // Move SL to BE if price closes above entry
    if ($stop < $price && $prev_tick->close_bid > $price) {
      $update['field_stop_loss'] = $price;
    }
    if ($prev_tick->close_bid > $prev_tick->open_bid && $stop < $prev_tick->low_bid) {
      $update['field_stop_loss'] = $prev_tick->low_bid;
    }
  }
  if ($side == 'sell') {
    // Move SL to BE if price closes above entry
    if ($stop > $price && $prev_tick->close_ask < $price) {
      $update['field_stop_loss'] = $price;
    }
    if ($prev_tick->close_ask < $prev_tick->open_ask && $stop > $prev_tick->high_ask) {
      $update['field_stop_loss'] = $prev_tick->high_ask;
    }
  }
  return $update;
  $update_stop = FALSE;
  $spread = trader_pip_format($trade->field_instrument, ($candle->close_ask - $candle->close_bid));
  $pip_value = $trade->field_instrument->field_pip->value();
  $side = $trade->field_side->value();
  $strat = $trade->field_strategy;
  $actions = FALSE;

  // Is trade in trailing mode?
  if ($trade->field_is_trailing->value()) {
    // If trailing, check if stop can be moved
    if ($strat->field_trail_var->value() == 'pips') {
      $pips = $strat->field_trail_var_value->value();
      $pips = $pips * $pip_value;
      $stop == 'buy' ? $candle->close_bid - $pips : $candle->close_ask + $pips;
    } else {
      // Use studies to find value
      $stop = _trader_get_study_value($strat->field_trail_var->value(), $strat->field_trail_var_value->value(), $studies);
    }

    $update_stop = $side == 'buy' ? $stop > $trade->field_stop_loss->value() : $stop < $trade->field_stop_loss->value();
  } else {
    // If not trailing, check if stop can move to break even
    if ($trade->field_break_even_price->value()) {
      $stop = $trade->field_price->value();
      $break_even = $side == 'buy' ? $candle->close_bid >= $trade->field_break_even_price->value() : $candle->close_ask <= $trade->field_break_even_price->value();
      if ($break_even) {
        $update_stop = $side == 'buy' ? $stop > $trade->field_stop_loss->value() : $stop < $trade->field_stop_loss->value();
      }
    }

    // If not trailing, check if trailing wanted
    // If trailing wanted, check if can start trailing

  }

  // If we can move SL, return array with new stop
  if ($update_stop) {
    $actions[] = array('action' => 'update stop', 'value' => $stop);
  }
  // If we want to take profits, return array of some kind
  return $actions;
}

function trader_calc_risk($side, $price, $stop) {
  return $side == 'buy' ? $price - $stop : $stop - $price;
}

function trader_tx_sync_all() {
  global $oanda_accounts;
  
  foreach ($oanda_accounts as $oanda) {
    foreach ($oanda->accounts as $account_id => $account) {
      $last_tx = trader_tx_last($account);
      if ($last_tx != $account->lastTransactionID) {
        trader_tx_sync($oanda, $account);
      }
    }
  }
}

function trader_tx_sync($oanda, $account) {
  $in_progress = variable_get('trader_tx_sync', FALSE);
  $now = time();
  // Bail if we're currently syncing
  if ($in_progress && $in_progress >= ($now - 60 * 1)) {    
    return;
  }
  
  variable_set('trader_tx_sync', $now);
    
  $last_tx = trader_tx_last($account);

  if ($last_tx == $account->lastTransactionID) {
    return;
  }
  
  if (!$last_tx) {
    $last_tx = $account->lastTransactionID - 1000;
    if ($last_tx <= 0) {
      $last_tx = 1;
    }  
  }
  
  // Get transactions from the last tx id
  $txs = $oanda->transactions_sinceid($last_tx, $account->id);
  
  if (empty($txs->transactions)) {
    return;
  }
  
  $trader_txs = variable_get('trader_txs', array());
  
  foreach ($txs->transactions as $tx) {
    trader_tx_update($tx);
    $trader_txs[$account->id] = $tx->id;
    variable_set('trader_txs', $trader_txs);
  }
  
  $trader_txs[$account->id] = $txs->lastTransactionID;
  variable_set('trader_tx_sync', FALSE);
}

function trader_tx_update($tx) {
  $type = $tx->type;
  $order = NULL;
  $order_wrapper = NULL;
  
  if (!empty($tx->clientOrderID)) {
    $order_id = $tx->clientOrderID;
    if (!is_numeric($order_id)) {
      $order_id = str_replace('order_', '', $order_id);
    }
    $order = node_load($order_id);
    if ($order->type != 'order') {
      return;
    }
    $order_wrapper = entity_metadata_wrapper('node', $order);
  } 

  // Order rejected
  if (strpos($type, '_ORDER_REJECT') !== FALSE) {
    if (!empty($tx->clientExtensions->id)) {
      $order_id = $tx->clientExtensions->id;
      if (!is_numeric($order_id)) {
        $order_id = str_replace('order_', '', $order_id);
      }
      $status = 'rejected';
      $order = node_load($order_id);
      if ($order->type != 'order') {
        return;
      }
      
      $order_wrapper = entity_metadata_wrapper('node', $order);
      
      $order_wrapper->field_order_status->set($status);
      $order_wrapper->save();      
    }    
    return;
  }
  
  // A trade has been opened or closed
  if ($type == 'ORDER_FILL') {
    switch ($tx->reason) {
      case 'STOP_LOSS_ORDER':
      case 'TAKE_PROFIT_ORDER':
        if ($tx->reason == 'STOP_LOSS_ORDER') {
          $status = 'stop';
        }
        if ($tx->reason == 'TAKE_PROFIT_ORDER') {
          $status = 'tp';
        }
        foreach ($tx->tradesClosed as $t) {
          if (!empty($t->clientTradeID)) {
            $trade_id = $t->clientTradeID;
            if (strpos($trade_id, 'order_') !== FALSE) {
              break;
            }
            
            if ($trade = node_load($trade_id)) {
              if ($trade->type != 'trade') {
                return;
              }
              $trade_wrapper = entity_metadata_wrapper('node', $trade);
              $trade_wrapper->field_trade_close_date->set(floor($tx->time));
              $trade_wrapper->field_updated->set(floor($tx->time));              
              $trade_wrapper->field_trade_result->set($status);
              $trade_wrapper->field_close_price->set($tx->price);
              $trade_wrapper->field_trade_profit->set($tx->pl);
              $trade_wrapper->field_financing->set($tx->financing);
              $trade_wrapper->save();
            }
          }
        }
        break;        
      case 'LIMIT_ORDER':
      case 'MARKET_ORDER':
      case 'STOP_ORDER':
        $status = 'filled';
        if (!$order_wrapper) {
          return;
        }

        if ($order) {
          if ($order->type != 'order') {
            return;
          }
          $trade_id = $tx->tradeOpened->tradeID;

          //Create a trade
          $trade_wrapper = trader_prepare_trade_from_order($order_wrapper); 
          $trade_wrapper->field_trade_open_date->set(floor($tx->time));
          $trade_wrapper->field_updated->set(floor($tx->time));
          $trade_wrapper->field_trade_id->set($trade_id);
          $trade_wrapper->field_price->set($tx->price);
          $trade_wrapper->save();

          $trade = node_load($trade_wrapper->nid->value());
          oanda_trade_update_extensions($trade, $tx->accountID, $trade_id);
          
          // Update order
          $order_wrapper->field_order_status->set($status);
          $order_wrapper->field_trade_id->set($trade_id);
          $order_wrapper->field_trade->set($trade_wrapper->nid->value());
          $order_wrapper->save();
          
        }
        break;
    }
  }
  
  // Order cancelled
  if ($ype == 'ORDER_CANCEL') {
    if ($order) {
      $order_wrapper->field_order_status->set('cancelled');
      //$body = $order_wrapper->body->value();
      
      $order_wrapper->save();
    }
  }
}

function trader_set_message($message) {
  $date = new DateTime('now', new DateTimeZone('America/New_York'));
  $format = $date->format('m/d/y G:i:s');
  drupal_set_message('TRADER ' . $format . ' ' . $message);
}
function trader_tx_last($account) {
  $txs = variable_get('trader_txs', array());

  if (!empty($txs[$account->id])) {
    return $txs[$account->id];
  }
  
  return;
}

function trader_form_tx($form, &$form_state) {
  global $user;
  global $oanda_accounts;
  
  $oanda = $oanda_accounts[$user->uid];
  
  foreach ($oanda->accounts as $id => $account) {
    $options[$id] = $id;
  }
  
  $form = array();
  
  $form['account'] = array(
    '#type' => 'select',
    '#options' => $options,
    '#title' => t('Account')    
  );
  
  $form['tx'] = array(
    '#type' => 'textfield',
    '#title' => t('Transaction #'),      
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),  
  );
  
  return $form;
}

function trader_form_tx_submit($form, &$form_state) {
  global $user;
  global $oanda_accounts;
  
  $oanda = $oanda_accounts[$user->uid];
  
  $values = $form_state['values'];
  $account_id = $values['account'];
  $tx_id = $values['tx'];
  
  $tx = $oanda->transaction($tx_id, $account_id);
  
  dpm($tx);
  
}