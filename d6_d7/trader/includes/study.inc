<?php


/**
 * Determines price action
 * @param unknown $ks
 * @param unknown $ds
 * @param unknown $ticks
 */
function trader_stoch_cycles($ks, $ds, $ticks) {
  $k = reset($k);
  $d = reset($d);
  $cur_trend = $d > $k ? 'down' : 'up';
  $tick = reset($ticks);
  $prev_high = $tick->high;
  $prev_low = $tick->low;
  $cur_high = $tick->high;
  $cur_low = $tick->low;
  $cycle_high = $tick->high;
  $cycle_low = $tick->low;
  $prev_cycle_high = $tick->high;
  $prev_cycle_low = $tick->low;

  foreach ($ticks as $key => $tick) {

  }
}

/**
 * Finds trend and support/resistance based on stochastics
 * @param unknown $highs
 * @param unknown $lows
 * @param unknown $closes
 * @param unknown $k
 * @param unknown $d
 * @param unknown $s
 * @param string $type
 */
function trader_stoch_sr($highs, $lows, $closes, $k_period, $d_period, $s_period, $buffer, $type = TRADER_MA_SMA) {
  $stoch - trader_stoch($highs, $lows, $closes, $k_period, $d_period, $type, $s_period, $type);
  $ks = $stoch[0];
  $ds = $stoch[1];
  $side = FALSE;
  $cursup = FALSE;
  $curres = FALSE;
  $newsup = FALSE;
  $newres = FALSE;
  $prevres = FALSE;
  $prevsup = FALSE;

  foreach ($ds as $key => $d) {
    $k = $ds[$key];
    $high = $highs[$key];
    $low = $lows[$low];

    // Initialize
    if (!$cursup) {
      $cursup = $low;
      $newsup = $low;
      $prevsup = $low;
    }
    if (!$curres) {
      $curres = $high;
      $newres = $high;
      $prevres = $high;
    }
    if (!$side) {
      $side = $d < 50 ? 'sell' : 'buy';
    }

    // Calc new support

    // QUESTION: should high/low be
  }
}

/**
 * Returns array of values for divergence found, FALSE if not. Options $d parameter will use cross of k and d as reference
 */
function trader_divergence($k, $d = FALSE, $ticks, $source = 'k') {
  if ($source == 'k') {
    $k = $k;
  } elseif ($source == 'd') {
    $k = $d;
  }

  $pk = reset($k);
  $pd = reset($d);

  $ck = next($k);
  $cd = next($d);

  if ($ck > $pk) {
    $cur_dir = 'up';
    $prev_dir = 'up';
  } else {
    $cur_dir = 'down';
    $prev_dir = 'down';
  }

  $prev_k_high = FALSE;
  $prev_k_low  = FALSE;
  $prev_k = $ck;

  $max_k = $ck;
  $min_k = $ck;

  $pt = reset($ticks);
  $ct = next($ticks);
  $prev_tick_high = FALSE;
  $prev_tick_low = FALSE;


  $tick_low = $pt->low;
  $tick_high = $pt->high;

  $return = array();

  reset($ticks);
  reset($k);
  reset($d);

  $side = FALSE;
  $prev_action = FALSE;
  foreach ($ticks as $key => $tick) {
    $action = FALSE;
    $k_reverse = FALSE;
    if (empty($k[$key]) || empty($d[$key])) {
      $return['action'][$key] = FALSE;
      $return['side'][$key] = FALSE;
      continue;
    }


    $ck = $k[$key];
    $cd = $d[$key];

    //$cur_dir = $ck > $cd ? 'up' : 'down';


    if ($ck >= $max_k) {
      $max_k = $ck;
      $tick_high = $tick->high > $tick_high ? $tick->high : $tick_high;
      if ($tick->low < $tick_low) {
        $prev_tick_low = $tick->low;
      }
    }

    if ($ck <= $min_k) {
      $min_k = $ck;
      $tick_low = $tick->low < $tick_low ? $tick->low : $tick_low;
      if ($tick->high > $tick_high) {
        $prev_tick_high = $tick->high;
      }
    }

    if ($ck > $pk) {
      $cur_dir = 'up';
      if ($tick_low < $prev_tick_low) {
         
      }
    } elseif ($ck < $pk) {
      $cur_dir = 'down';
      if ($tick_high > $prev_tick_high) {
         
      }
    }

    $side = FALSE;

    // check against prev high and low
    if ($cur_dir <> $prev_dir) {
      if ($cur_dir == 'down') {
        if (!$prev_tick_high) {
          $prev_tick_high = $tick_high;
          $prev_k_high = $max_k;
          $prev_prev_tick_high = $tick_high;
          $prev_prev_k_high = $max_k;
        } else {
          if ($tick->high > $tick_high) {
            $tick_high = $tick->high;
          }
          if (!$action) {
            //Lower highs in price and higher highs in the oscillator which indicate a confirmation of the price trend which is down.
            if (($tick_high < $prev_tick_high && $max_k > $prev_k_high)) {
              $action = 'confirm down';
            }

            //Higher highs in price and lower highs in the oscillator which indicate a trend reversal from up to down.
            if (($tick_high > $prev_tick_high && $max_k < $prev_k_high)) {
              $action = 'reverse down';
            }
            $side = 'sell';
          }
          $prev_prev_tick_high = $prev_tick_high;
          $prev_prev_k_high = $prev_k_high;


          $prev_tick_high = $tick_high;
          $prev_k_high = $max_k;
          //$max_k = $ck;
          $min_k = $ck;

          $tick_low = $tick->low;
          //testing below
          //$tick_high = $tick->high > $tick_high ? $tick->high : $tick_high;
          //$prev_tick_high = $tick_high;
        }
      } elseif ($cur_dir == 'up') {
        if (!$prev_tick_low) {
          $prev_tick_low = $tick_low;
          $prev_k_low = $min_k;
          $prev_prev_tick_low = $tick_low;
          $prev_prev_k_low = $min_k;
        } else {
          if ($tick->low < $tick_low) {
            $tick_low = $tick->low;
          }
          if (!$action) {
            //Higher lows in price and lower lows in the oscillator which indicate a confirmation of the price trend which is up.
            if (($tick_low > $prev_tick_low && $min_k < $prev_k_low)) {
              $action = 'confirm up';
            }

            //Lower lows in price and higher lows in the oscillator which indicate a trend reversal from down to up.
            if (($tick_low < $prev_tick_low && $min_k > $prev_k_low)) {
              $action = 'reverse up';
            }

            $side = 'buy';
          }
          $prev_prev_tick_low = $prev_tick_low;
          $prev_prev_k_low = $prev_k_low;

          $prev_tick_low = $tick_low;
          $prev_k_low = $min_k;
          $max_k = $ck;
          $tick_high = $tick->high;
          //$min_k = $ck;
          //testing beloe //remove if it doesn't work
          //$tick_low = $tick->low < $tick_low ? $tick->low : $tick_low;
          //$prev_tick_low = $tick_low;

        }
      }
    } else {
      // Check if stoch falling but price higher than prev
      if ($cur_dir == 'down' && $tick->high > $tick_high) {
        $action = $side ='sell';
      }
      if ($cur_dir == 'up' && $tick->low < $tick_low) {
        $action = $side ='buy';
      }

    }

    if ($cur_dir <> $prev_dir) {
      $k_reverse = TRUE;
    }


    if ($action) {
      $prev_action = $action;
    }

    $prev_dir = $cur_dir;
    $pk = $ck;
    $pd = $cd;

    $return['action'][$key] = $action;
    $return['side'][$key] = $side;

    /*
     $return[$key] = array(
     'action' => $action,
     'direction' => $cur_dir,
     'tick_high' => $tick_high,
     'tick_low' => $tick_low,
     'prev_tick_high' => $prev_tick_high,
     'prev_tick_low' => $prev_tick_low,
     'k_reverse' => $k_reverse,
     'prev_action' => $prev_action,
     'side' => $side,
     );
     */
  }

  return $return;
}

/**
 * Returns trend
 * @param unknown $ds
 * @param unknown $ticks
 */
function trader_stoch_trend($ks, $ds, $top = 80, $bottom = 20, $source = 'k') {
  $side = FALSE;
  $prev_dir = FALSE;
  $potential_buy = FALSE;
  $potential_sell = FALSE;
  $max_reached = FALSE;
  $sideways = FALSE;
  $value_comp = FALSE;
  $prev_side = FALSE;

  $return = array();

  $ds = $source == 'k' ? $ks : $ds;

  foreach ($ds as $key => $d) {
    /*
     * Rules:
     * If D reverses before top(80), we're shorting
     * If D reverses before bottom(20), we buying
     */

    if (!$side) {
      $side = $d < 50 ? 'sell' : 'buy';
      $prev_side = $side;
      $dir = $d < 50 ? 'down' : 'up';
      $prev_d = $d;
    }

    // What's the current direction?
    if ($d < $prev_d) {
      $dir = 'down';
    } elseif ($d > $prev_d) {
      $dir = 'up';
    } else {
      // Leave dir as is
    }

    if (!$prev_dir) {
      $prev_dir = $dir;
    }

    $enter_top = $prev_d < $top && $d >= $top;
    $enter_bottom = $prev_d > $bottom && $d <= $bottom;
    $inside_top = $prev_d >= $top && $d >= $top;
    $inside_bottom = $prev_d <= $bottom && $d <= $bottom;
    $exit_top = $prev_d >= $top && $d < $top;
    $exit_bottom = $prev_d <= $bottom && $d > $bottom;
    $inside_middle = !$inside_top && !$inside_bottom;

    if (($enter_top && $side == 'buy') || ($enter_bottom && $side == 'sell')) {
      $value_comp = FALSE;
    }

    if (($exit_top && $side == 'buy') || ($exit_bottom && $side == 'sell')) {
      $value_comp = FALSE;
    }

    if ($dir <> $prev_dir) {
      if ($inside_top && $dir == 'up' && $side == 'sell') {
        $side = 'buy';
        $value_comp = FALSE;
      } elseif ($inside_bottom && $dir == 'down' && $side == 'buy') {
        $value_comp = FALSE;
        $side = 'sell';
      } else {
        if ($side == 'buy' && $dir == 'up' && !$inside_top) {
          if ($value_comp) {
            if ($prev_d == $value_comp) {
              $side = 'sell';
            } else {
              $side = $prev_d >= $value_comp ? 'buy' : 'sell';
            }
          }
          $value_comp = $prev_d;
        }
        if ($side == 'sell' && $dir == 'down' && !$inside_bottom) {
          if ($value_comp) {
            if ($prev_d == $value_comp) {
              $side = 'buy';
            } else {
              $side = $prev_d <= $value_comp ? 'sell' : 'buy';
            }
          }
          $value_comp = $prev_d;
        }
      }
    } else {
      if ($side == 'buy' && $dir == 'down') {
        if ($value_comp) {
          if ($d == $value_comp) {
            $side = 'sell';
          } else {
            $side = $d >= $value_comp ? 'buy' : 'sell';
          }
        }
      }
      if ($side == 'sell' && $dir == 'up') {
        if ($value_comp) {
          if ($d == $value_comp) {
            $side = 'buy';
          } else {
            $side = $d <= $value_comp ? 'sell' : 'buy';
          }
        }
      }
    }



    if ($side <> $prev_side) {
      $value_comp = FALSE;
    }

    /*
     if ($dir <> $prev_dir) {
     if ($dir == 'down') {
     $prev_d_high = $prev_d;
     if ($prev_d >= $top) {
     // side changes if no switches between
     $max_reached = TRUE;
     //$side = 'sell';
     } else { // prev_d < top
     if ($prev_d > 50) {
     if ($side == 'buy') {
     $potential_sell = TRUE;
     // Only change if d is lower prev low
     //$side = 'sell';
     if (!$max_reached) {
     $side = 'sell';
     } else {
     $sideways = TRUE;
     }
     }
     } else {
     $side = 'sell';
     }
     }
     $potential_buy = FALSE;
     } else { // up
     $prev_d_low = $prev_d;
     if ($prev_d <= $bottom) {
     // Side remains
     //$side = 'buy';
     $max_reached = TRUE;
     } else { // prev_d < top
     if ($prev_d < 50) {
     if ($side == 'sell') {
     $potential_buy = TRUE;
     //$side = 'buy';
     if (!$max_reached) {
     $side = 'buy';
     } else {
     $sideways = TRUE;
     }
     }
     } else {
     $side = 'buy';
     }
     }
     $potential_sell = FALSE;
     }
     } else {

     }

     if (($prev_d < 50 && $d > 50) || ($prev_d > 50 && $d < 50)) {
     $max_reached = FALSE;
     $sideways = FALSE;
     }
     if ($potential_buy && $d > $prev_d_high) {
     $side = 'buy';
     $potential_buy = FALSE;
     }
     if ($potential_sell && $d < $prev_d_low) {
     $side = 'sell';
     $potential_sell = FALSE;
     }*/

    $return[$key] = $side;
    $prev_d = $d;
    $prev_dir = $dir;
    $prev_side = $side;
  }

  return $return;
}

/**
 * This is really moving avg
 * @param unknown $lrs
 * @param unknown $ticks
 * @return multitype:boolean number
 */
function trader_lr_trend($lrs, $ticks) {
  $trend = FALSE;
  $return = array();

  $ticks = array_values($ticks);

  foreach ($ticks as $key => $tick) {
    if (empty($lrs[$key])) {
      $return[$key] = FALSE;
      continue;
    }

    $lr = $lrs[$key];

    if ($tick->high > $lr && $tick->low > $lr && $tick->close > $tick->open) {
      $trend = 1;
    }
    if ($tick->high < $lr && $tick->low < $lr && $tick->close < $tick->open) {
      $trend = 0;
    }

    $return[$key] = $trend;
  }

  return $return;
}

function trader_lr_trend_structure($lrs, $ticks, $pass = 1) {
  $prev_low = FALSE;
  $prev_high = FALSE;
  $cur_low = FALSE;
  $cur_high = FALSE;
  $trend = FALSE;
  $prev_dir = FALSE;
  $dir = FALSE;
  $return = array();
  $pass_count = 0;

  foreach ($lrs as $key => $lr) {
    $tick = $ticks[$key];

    // Init
    if (!$dir) {
      $trend = $lr ? 'up' : 'down';
      $prev_high = $tick->high;
      $cur_high = $tick->high;
      $prev_low = $tick->low;
      $cur_low = $tick->low;
      $prev_dir = $trend;
      $dir = $trend;
    }

    $cur_high = $tick->high > $cur_high ? $tick->high : $cur_high;
    $cur_low = $tick->low < $cur_low ? $tick->low : $cur_low;

    $dir = $lr ? 'up' : 'down';

    if ($dir <> $prev_dir) {
      if ($dir == 'up') {
        // If in down trend, check if we made new lows
        if ($trend == 'down') {
          if ($cur_low >= $prev_low) {
            $pass_count++;
            if ($pass_count >= $pass || $cur_high > $prev_high) {
              $trend = 'up';
              $prev_high = $tick->high;
              $prev_low = $cur_low;
            }
          } else {
            $pass_count = 0;
            $prev_low = $cur_low < $prev_low ? $cur_low : $prev_low;
          }

        }

        //$prev_low = $cur_low;
      }
      if ($dir == 'down') {
        // If in up trend, check if we made new highs
        if ($trend == 'up') {
          if ($cur_high <= $prev_high) {
            $pass_count++;
            if ($pass_count >= $pass || $cur_low < $prev_low) {
              $trend = 'down';
              $prev_low = $tick->low;
              $prev_high = $cur_high;
            }
          } else {
            $pass_count = 0;
            $prev_high = $cur_high  > $prev_high ? $cur_high : $prev_high;
          }

        }

        //$prev_high = $cur_high;
      }

      $cur_high = $tick->high;
      $cur_low = $tick->low;
    } else {
      if ($trend == 'up' && $tick->close < $prev_low) {
        $trend = 'down';
      }
      if ($trend == 'down' && $tick->close > $prev_high) {
        $trend = 'up';
      }
    }

    if ($trend <> $prev_trend) {
      $pass_count = 0;
    }

    $return[$key] = $trend;
    $prev_dir = $dir;
    $prev_trend = $trend;
  }

  return $return;
}


function trader_trend_slope($slopes, $highs, $lows, $middle = 0, $use_divergence = FALSE) {
  $return = array();

  $prev_high = FALSE;
  $prev_low = FALSE;
  $cur_high = FALSE;
  $cur_low = FALSE;
  $trend = FALSE;
  $prev_slope = FALSE;

  $dir = 1;
  $prev_dir = 1;
  
  $slope_low = FALSE;
  $slope_high = FALSE;
  $prev_slope_low = FALSE;
  $prev_slope_high = FALSE;
  
  foreach ($slopes as $key => $slope) {
    $high = $highs[$key];
    $low = $lows[$key];

    if (!$cur_high) {
      $prev_high = $high;
      $prev_low = $low;
      $cur_high = $prev_high;
      $cur_low = $prev_low;
      $prev_slope = $slope;
      
      $prev_slope_high = $slope;
      $prev_slope_low = $slope;
      $slope_high = $slope;
      $slope_low = $slope;
    }

    if ($slope > $prev_slope) {
      $dir = 1;
    } elseif ($slope < $prev_slope) {
      $dir = -1;
    }
    
    // Save current and previous high/lows
    if ($slope > $middle) {
      // Check if prev slope was neg
      if ($prev_slope < $middle) {
        //$prev_low = $cur_low;
        $prev_high = $cur_high;
        $cur_high = $high;
        $slope_high = $slope;
        $prev_slope_low = $slope_low;
      }
      
      $slope_high = $slope > $slope_high ? $slope : $slope_high;
      // Check if higher high
      if ($high > $cur_high) {
        $cur_high = $high;
      }
    } elseif ($slope < $middle) {
      // Check if prev slope was pos
      if ($prev_slope > $middle) {
        //$prev_high = $cur_high;
        $prev_low = $cur_low;
        $cur_low = $low;
        $slope_low = $slope;
        $prev_slope_high = $slope_high;        
      }
      $slope_low = $slope < $slope_low ? $slope : $slope_low;
      
      if ($low < $cur_low) {
        $cur_low = $low;
      }
    }

    if ($trend === FALSE && $prev_high == $cur_high) {
      $trend = 1;
      $return[$key] = $trend;
      $prev_slope = $slope;
      continue;
    }

    // If trend is high and we've now exited top of cycle, check high vs prev_high
    if ($trend === 1 && $slope < $middle && $prev_slope > $middle) {
      if ($cur_high > $prev_high) {
        $trend = 1;
      } else {
        //$trend = -1;
      }
    }
    if ($trend === -1 && $slope > $middle && $prev_slope < $middle) {
      if ($cur_low < $prev_low) {
        $trend = -1;
      } else {
        //$trend = 1;
      }
    }
    
    // If trend is high and low is lower than prev low, we're now going down
    if ($trend === 1 && $slope < $middle && $cur_low < $prev_low){
      $trend = -1;
    }
    if ($trend === -1 && $slope > $middle && $cur_high > $prev_high){
      $trend = 1;
    }
    
    // Check for slope divergence
    if ($use_divergence) {
      if ($slope > $middle && $dir == -1 && $prev_dir == 1) {
        if ($slope_high < $prev_slope_high) {
          $trend = -1;
        }
      }
      if ($slope < $middle && $dir == 1 && $prev_dir == -1) {
        $trend = 1;
      }
    }
    

    $prev_dir = $dir;
    $prev_slope = $slope;

    $return[$key] = $trend;
  }

  return $return;
}

function trader_trend_sadler($highs, $lows) {
  $return = array();
  $prev_high = FALSE;
  $prev_low = FALSE;
  $prev_trend = FALSE;
  $trend = FALSE;
  foreach ($highs as $key => $high) {
    $low = $lows[$key];

    if ($prev_high === FALSE) {
      $prev_high = $high;
      $prev_low = $low;
    }

    if ($high > $prev_high) {
      $trend = 1;
    }

    if ($low < $prev_low) {
      $trend = -1;
    }

    if ($high > $prev_high && $low < $prev_low) {
      $trend = $prev_trend;
    }

    $prev_high = $high;
    $prev_low = $low;
    $prev_trend = $trend;
    $return[$key] = $trend;
  }

  return $return;
}

function trader_trend_stoch($stochs, $highs, $lows, $high_stoch = 80, $low_stoch = 20) {
  $return = array();

  $prev_high = FALSE;
  $prev_low = FALSE;
  $cur_high = FALSE;
  $cur_low = FALSE;
  $trend = FALSE;
  $prev_stoch = FALSE;

  foreach ($stochs as $key => $stoch) {
    $high = $highs[$key];
    $low = $lows[$key];

    if (!$cur_high) {
      $prev_high = $high;
      $prev_low = $low;
      $cur_high = $prev_high;
      $cur_low = $prev_low;
      $prev_stoch = $stoch;
    }

    // Save current and previous high/lows
    if ($stoch >= $high_stoch) {
      // Check if prev stoch was neg
      if ($prev_stoch < $high_stoch) {
        //$prev_low = $cur_low;
        $prev_high = $cur_high;
        $cur_high = $high;
      }
      // Check if higher high
      if ($high > $cur_high) {
        $cur_high = $high;
      }
    } elseif ($stoch <= $low_stoch) {
      // Check if prev stoch was pos
      if ($prev_stoch > $low_stoch) {
        //$prev_high = $cur_high;
        $prev_low = $cur_low;
        $cur_low = $low;
      }
      if ($low < $cur_low) {
        $cur_low = $low;
      }
    }

    if ($trend === FALSE && $prev_high == $cur_high) {
      $trend = 1;
      $return[$key] = $trend;
      $prev_stoch = $stoch;
      continue;
    }

    // If trend is high and we've now exited top of cycle, check high vs prev_high
    if ($stoch < $high_stoch && $prev_stoch > $high_stoch) {
      if ($cur_high > $prev_high) {
        $trend = 1;
      } else {
        $trend = -1;
        //$cur_low = $low;
      }
    }
    if ($stoch > $low_stoch && $prev_stoch < $low_stoch) {
      if ($cur_low < $prev_low) {
        $trend = -1;
      } else {
        $trend = 1;
        //$cur_high = $high;
      }
    }

    // Make sure we're not caught in an opposite trend
    if ($trend === 1 && $cur_low < $prev_low) {
      //$trend = -1;
      //$prev_low = $low;
    }
    if ($trend === -1 && $cur_high > $prev_high) {
      //$trend = 1;
      //$prev_high = $high;
    }

    $prev_stoch = $stoch;

    $return[$key] = $trend;
  }

  return $return;
}


function trader_waves($ticks, $ks, $ds) {
  $n = -1;
  $return = array();

  $prev_wave_side = FALSE;
  $wave_side = FALSE;

  foreach ($ticks as $key => $tick) {
    $n++;
    if (empty($ks[$n])) {
      continue;
    }
    $k = $ks[$n];
    $d = $ds[$n];

    // First visible wave
    if (!isset($curwave)) {
      $curwave['high'] = $tick->high;
      $curwave['low'] = $tick->low;
    }

    if ($d >= 45) {
      $wave_side = 'high';
    }
    if ($d <= 55) {
      $wave_side = 'low';
    }

    $curwave['high'] = $tick->high > $curwave['high'] ? $tick->high : $curwave['high'];
    $curwave['low'] = $tick->low < $curwave['low'] ? $tick->low : $curwave['low'];

    if ($wave_side != $prev_wave_side) {
      $curwave['wave_side'] = $wave_side;
      if ($wave_side == 'high') {
        $curwave['prev_high'] = $curwave['high'];
        $curwave['prev_low'] = $curwave['low'];
        $curwave['high'] = $tick->high;
      }
      if ($wave_side == 'low') {
        $curwave['prev_high'] = $curwave['high'];
        $curwave['prev_low'] = $curwave['low'];
        $curwave['low'] = $tick->low;
      }
    }

    if ($wave_side == 'high') {
      if ($curwave['low'] > $curwave['prev_low']) {
        $curwave['trend'] = 'up';
      } else {
        $curwave['trend'] = 'down';
      }
    } elseif ($wave_side == 'low') {
      if ($curwave['high'] > $curwave['prev_high']) {
        $curwave['trend'] = 'up';
      } else {
        $curwave['trend'] = 'down';
      }
    }

    $prev_wave_side = $wave_side;
    $return['wave_high'][$key] = $curwave['high'];
    $return['wave_prevhigh'][$key] = $curwave['prev_high'];
    $return['wave_low'][$key] = $curwave['low'];
    $return['wave_prevlow'][$key] = $curwave['prev_low'];
    $return['wave_trend'][$key] = $curwave['trend'];
  }

  return $return;
}

function trader_waves_new($ticks, $cycles, $high_start, $high_exit, $low_start, $low_exit, $trends) {
  $prev_trend = FALSE;
  $return = array();

  $fast = NULL;
  $slow = NULL;

  foreach($trends as $key => $trend) {
    if (!isset($cycles['slow'][$key]) || !isset($cycles['fast'][$key])) {
      // Not sure, so skip until we are
      $return[$key] = array('current_wave' => FALSE, 'waves' => array());
      continue;
    }
    $lower_low = $trend == 'down' ? TRUE : FALSE;
    $higher_high = $trend == 'up' ? TRUE : FALSE;

    $prev_fast = $fast;
    $prev_slow = $slow;

    $slow = $cycles['slow'][$key];
    $fast = $cycles['fast'][$key];

    $tick = $ticks[$key];

    if ($prev_trend != $trend) {
      $wave_count = 0;
      $cycle_count = 0;
      $first_wave = TRUE;
      $second_wave = TRUE;
      $in_wave = FALSE;
      $in_cycle = FALSE;
      $hook_k_count = 0;
      $hook_d_count = 0;
      $waves = array();
      $prev_trend = $trend;
      $trend_high = $tick->high;
      $trend_low = $tick->low;
      $prev_fast = $fast;
      $prev_slow = $slow;
      $cycle = FALSE;
      $tick_count = 0;
    } else {
      $trend_high = $tick->high > $trend_high ? $tick->high : $trend_high;
      $trend_low = $tick->low < $trend_low ? $tick->low : $trend_low;
    }

    if ($in_cycle) {
      if ($tick->complete && ($cycle_type == 'high' && $slow < $high_exit) || ($cycle_type == 'low' && $slow > $low_exit)) {
        $in_cycle = FALSE;
        $cycle = FALSE;
        $tick_count = 0;
        $in_wave = FALSE;
        $hook_k_count = 0;
        $hook_d_count = 0;
      }
    }

    if (!$in_cycle) {
      // We weren't previously in a cycle, check if we're in a wave now
      if (($slow > $high_start) || ($slow < $low_start)) {
        $in_cycle = TRUE;
        $cycle_count++;
        $tick_count++;
        $hook_k_count = 0;
        $hook_d_count = 0;
        $cycle_high = $tick->high;
        $cycle_low = $tick->low;
        $cycle_type = $slow > $high_start ? 'high' : 'low';
        $cycle = array('max_d' => $slow, 'max_k' => $fast, 'hook_k' => FALSE, 'hook_d' => FALSE);
        $prev_fast = $fast;
        $prev_slow = $slow;
      } else {
        // hmm why here?
        $test = 'test';
      }
    }

    if ($in_cycle) {
      $tick_count++;
      // We're in a cycle, updates highs/lows
      $cycle_high = $cycle_high > $tick->high ? $cycle_high : $tick->high;
      $cycle_low = $cycle_low < $tick->low ? $cycle_low : $tick->low;

      // Save fast and slow for cycles!
      if ($cycle_type == 'high') {
        $cycle['max_k'] = $fast > $cycle['max_k'] ? $fast : $cycle['max_k'];
        $cycle['max_d'] = $slow > $cycle['max_d'] ? $slow : $cycle['max_d'];
        if ($fast <= $prev_fast) {
          if (!$cycle['hook_k']) {
            $hook_k_count++;
            $cycle['hook_k_count'] = $hook_k_count;
            $cycle['hook_k_tick'] = $tick;
          }
          $cycle['hook_k'] = TRUE;
        } else {
          $cycle['hook_k'] = FALSE;
          $cycle['hook_k_tick'] = FALSE;
        }
        if ($slow <= $prev_slow) {
          if (!$cycle['hook_d']) {
            $hook_d_count++;
            $cycle['hook_d_count'] = $hook_d_count;
            $cycle['hook_d_tick'] = $tick;
          }
          $cycle['hook_d'] = TRUE;
        } else {
          $cycle['hook_d'] = FALSE;
          $cycle['hook_d_tick'] = FALSE;
        }
      } else {
        $cycle['max_k'] = $fast < $cycle['max_k'] ? $fast : $cycle['max_k'];
        $cycle['max_d'] = $slow < $cycle['max_d'] ? $slow : $cycle['max_d'];

        if ($fast >= $prev_fast) {
          if (!$cycle['hook_k']) {
            $hook_k_count++;
            $cycle['hook_k_count'] = $hook_k_count;
            $cycle['hook_k_tick'] = $tick;
          }
          $cycle['hook_k'] = TRUE;
        } else {
          $cycle['hook_k'] = FALSE;
          $cycle['hook_k_tick'] = FALSE;
        }
        if ($slow >= $prev_slow) {
          if (!$cycle['hook_d']) {
            $hook_d_count++;
            $cycle['hook_d_count'] = $hook_d_count;
            $cycle['hook_d_tick'] = $tick;
          }
          $cycle['hook_d'] = TRUE;
        } else {
          $cycle['hook_d'] = FALSE;
          $cycle['hook_d_tick'] = FALSE;
        }
      }

      // See if we potentially reached a high/low for this cycle
      $cycle['peak'] = 0;
      if ($cycle['hook_d'] || $cycle['hook_k']) {
        if ($cycle_type == 'high') {
          if ($cycle['hook_d'] && $tick->low < $cycle['hook_d_tick']->low) {
            $cycle['peak']++;
          }
          if ($cycle['hook_k'] && $tick->low < $cycle['hook_k_tick']->low) {
            $cycle['peak']++;
          }
        } else {
          if ($cycle['hook_d'] && $tick->high > $cycle['hook_d_tick']->high) {
            $cycle['peak']++;
          }
          if ($cycle['hook_k'] && $tick->high > $cycle['hook_k_tick']->high) {
            $cycle['peak']++;
          }
        }
      }

      // In cycle, are we also in a wave?
      // First cycle is always a wave
      if ($first_wave && $tick->complete) {
        if (($trend == 'up' && $cycle_type == 'high') || ($trend == 'down' && $cycle_type == 'low')) {
          $first_wave = FALSE;
          $wave_count++;
          $in_wave = TRUE;
        }
      } elseif ($second_wave && $tick->complete) {
        if (($trend == 'up' && $cycle_type == 'low') || ($trend == 'down' && $cycle_type == 'high')) {
          $second_wave = FALSE;
          $wave_count++;
          $in_wave = TRUE;
        }
      }

      // Only count waves that make higher/lower bodies compared to previous wave
      if ($wave_count && !$in_wave && !$first_wave && !$second_wave) {
        $save_wave = FALSE;
        $prev_wave = $waves[$wave_count];

        // If prev wave matches our current cycle type, then most likely had a failed wave
        // Update the prev wave with new data and continue on
        if ($prev_wave['type'] == $cycle_type) {
          $in_wave = TRUE;
          $waves[$wave_count]['high'] = $cycle_high > $waves[$wave_count]['high'] ? $cycle_high : $waves[$wave_count]['high'];
          $waves[$wave_count]['low'] = $cycle_low > $waves[$wave_count]['low'] ? $cycle_low : $waves[$wave_count]['low'];
        } else {
          if ($cycle_type == 'high') {
            if ($higher_high && $tick->close > $waves[$wave_count-1]['high']) {
              $save_wave = TRUE;
              //} elseif (!$higher_high && $tick->high > $waves[$wave_count-1]['high']) {
            } elseif (!$higher_high) {
              $save_wave = TRUE;
            }
          }
          if ($cycle_type == 'low') {
            if ($lower_low && $tick->close < $waves[$wave_count-1]['low']) {
              $save_wave = TRUE;
              //} elseif (!$lower_low && $tick->low < $waves[$wave_count-1]['low']) {
            } elseif (!$lower_low) {
              $save_wave = TRUE;
            }
          }

          if ($save_wave && $tick->complete) {
            $wave_count++;
            $in_wave = TRUE;
            $waves[$wave_count] = array('high' => $cycle_high, 'low' => $cycle_low, 'type' => $cycle_type);
          }
        }
      }

      if ($in_wave) {
        // Still in the cycle, if also in a wave, update the high/low values
        $waves[$wave_count]['high'] = $cycle_high;
        $waves[$wave_count]['low'] = $cycle_low;
        $waves[$wave_count]['type'] = $cycle_type;
        $waves[$wave_count]['wave_num'] = $wave_count;

        // Save K crossover
        $waves[$wave_count]['fast'] = $fast;
        $waves[$wave_count]['slow'] = $slow;
        $waves[$wave_count]['trend_high'] = $trend_high;
        $waves[$wave_count]['trend_low'] = $trend_low;

        $waves[$wave_count]['hook_k'] = $cycle['hook_k'];
        $waves[$wave_count]['hook_d'] = $cycle['hook_d'];
        $waves[$wave_count]['max_k'] = $cycle['max_k'];
        $waves[$wave_count]['max_d'] = $cycle['max_d'];
      }
    }

    $current_wave = $in_wave ? $waves[$wave_count] : FALSE;
    $current_cycle = FALSE;
    if ($cycle) {
      $current_cycle = array(
          'type' => $cycle_type,
          'high' => $cycle_high,
          'low' => $cycle_low,
          'count' => $cycle_count,
          'wave_count' => $wave_count,
          'tick_count' => $tick_count,
          'max_k' => $cycle['max_k'],
          'max_d' => $cycle['max_d'],
          'hook_k' => $cycle['hook_k'],
          'hook_d' => $cycle['hook_d'],
          'hook_k_count' => $cycle['hook_k_count'],
          'hook_d_count' => $cycle['hook_d_count'],
          'cycle' => $cycle
      );
    }
    $trend = array('high' => $trend_high, 'low' => $trend_low);
    $return[$key] = array('current_wave' => $current_wave, 'waves' => $waves, 'current_cycle' => $current_cycle, 'trend' => $trend);
  }

  return $return;
}

function trader_high_low_divergence($highs, $lows, $reals, $reset_on_change = TRUE) {
  $prev_high = FALSE;
  $prev_low = FALSE;
  $check_low = FALSE;
  $check_high = FALSE;
  $cur_value_low = FALSE;
  $cur_value_high = FALSE;
  $prev_value_low = FALSE;
  $prev_value_high = FALSE;
  $prev_value = FALSE;
  $dir = FALSE;
  $prev_dir = FALSE;
  
  $return = array();
  
  foreach ($reals as $key => $value) {
    $return[$key]['divergence'] = FALSE;
    $return[$key]['trend'] = FALSE;
    
    if (!isset($highs[$key]) || !isset($lows[$key]) || !$value) {
      continue;
    }
        
    $high = $highs[$key];
    $low = $lows[$key];
    
    if (!$prev_high) {
      $prev_high = $high;
      $prev_low = $low;
    }
    
    /* This was added to prevent bad signals */
    if ($reset_on_change) {
      if ($low > $prev_low) {
        $prev_value_low = FALSE;
        $cur_value_low = FALSE;
        $check_low = FALSE;
      }
      if ($high < $prev_high) {
        $prev_value_high = FALSE;
        $cur_value_high = FALSE;
        $check_high = FALSE;
      } 
    }
    
    if (!$dir) {
      $dir = 1;
    }
    
    if ($value > $prev_value) {
      $dir = 1;
    } elseif ($value < $prev_value) {
      $dir = -1;
    }
    
    
    if ($low <= $prev_low) {
      if (!$check_low && $dir == 1) {
        $check_low = TRUE;
      }
      
      if ($low < $prev_low) {
        $cur_value_low = $value;        
      }
     
      $cur_value_low = $value < $cur_value_low ? $value : $cur_value_low;

      if ($check_low) {
        if ($low == $prev_low) {
          if (!$prev_value_low) {
            $prev_value_low = $cur_value_low;
            $check_low = FALSE;
          }
          
          // What is current value compared to prev low's value?
          if ($cur_value_low > $prev_value_low) {
            // There is divergence
            $return[$key]['divergence'] = 1;
          } else {
            $return[$key]['trend'] = -1;
          }
          
          $prev_value_low = $cur_value_low;
          $check_low = FALSE;        
        }            
      }
    }
    
    if ($high >= $prev_high) {
      if (!$check_high && $dir == -1) {
        $check_high = TRUE;
      }
      
      if ($high > $prev_high) {
        $cur_value_high = $value;
      }
       
      $cur_value_high = $value > $cur_value_high ? $value : $cur_value_high;
    
      if ($check_high) {
        if ($high == $prev_high) {
          if (!$prev_value_high) {
            $prev_value_high = $cur_value_high;
            $check_high = FALSE;
          }
          
          // What is current value compared to prev low's value?
          if ($cur_value_high < $prev_value_high) {
            // There is divergence
            $return[$key]['divergence'] = -1;
          } else {
            $return[$key]['trend'] = 1;
          }
      
          $prev_value_high = $cur_value_high;
          $check_high = FALSE;
        }
      }
    }
    $prev_dir = $dir;
    $prev_value = $value;
    $prev_high = $high;
    $prev_low = $low;
  }
  
  return $return;
}

/**
 * When price hits cci high/low, check for divergence next time breaks that high/low
 * @param unknown $highs
 * @param unknown $lows
 * @param unknown $ccis
 */
function trader_cci_divergence($highs, $lows, $ccis, $max = 200, $min = -200) {
  $prev_high = FALSE;
  $prev_low = FALSE;
  $check_low = FALSE;
  $check_high = FALSE;
  $cur_value_low = FALSE;
  $cur_value_high = FALSE;
  $prev_value_low = FALSE;
  $prev_value_high = FALSE;
  $prev_value = FALSE;
  $dir = FALSE;
  $prev_dir = FALSE;
  $prev_max_high = FALSE;
  $prev_max_low = FALSE;
  $trigger_max_check = FALSE;
  $in_max = FALSE;
  
  $return = array();
  
  foreach ($ccis as $key => $value) {
    $return[$key] = FALSE;
  
    if (!isset($highs[$key]) || !isset($lows[$key]) || !$value) {
      continue;
    }
  
    $high = $highs[$key];
    $low = $lows[$key];
  
    if (!$prev_high) {
      $prev_high = $high;
      $prev_low = $low;
    }

    if (!$dir) {
      $dir = 1;
    }
  
    if ($value > $prev_value) {
      $dir = 1;
    } elseif ($value < $prev_value) {
      $dir = -1;
    }
        
    if ($in_max || $trigger_max_check) {
      $cur_max_high = $high > $cur_max_high ? $high : $cur_max_high;
      $cur_value_high = $value > $cur_value_high ? $value : $cur_value_high;
    }
        
    // Entering max
    // Save max cci and high while above max
    if ($value > $max && $prev_value < $max) {
      $in_max = TRUE;
      $cur_max_high = $high;
      $cur_value_high = $value;
    } elseif ($value < $max && $prev_value > $max) {
      $in_max = FALSE;
      $prev_value_high = $cur_value_high;
      $prev_max_high = $cur_max_high;
      $cur_max_high = $high;
      $cur_value_high = $value;
    }
    
    if ($in_max && $cur_max_high > $prev_max_high && $cur_value_high > $prev_value_high) {
      $trigger_max_check = FALSE;
    }
    
    if ($high > $prev_max_high && $prev_high <= $prev_max_high) {
      $trigger_max_check = TRUE;
      $cur_value_high = $value;
      $cur_max_high = $high;
    } elseif ($high < $prev_max_high && $prev_high > $prev_max_high) {
      $trigger_max_check = FALSE;
      $cur_max_high = $high;
      $cur_value_high = $value;
    }
    
    if ($trigger_max_check) {
      // We have started to decend, so compare highs
      if ($dir == -1 && $prev_dir == 1) {
        if ($cur_value_high < $prev_value_high) {
          $return[$key] = -1;
        }
      }
    }
    
    $prev_dir = $dir;
    $prev_value = $value;
    $prev_high = $high;
    $prev_low = $low;
  }
  
  return $return;  
}

function trader_stoch_trend_sma($ss, $smas, $closes, $high_s = 50, $low_s = 50) {
  $prev_s = reset($ss);
  $first_sma = reset($smas);
  $first_close = reset($closes);  
  $trend = $first_close >= $first_sma ? 1 : -1;
  $return = array();
  $prev_dir = $trend == 1 ? 1 : -1;
  
  foreach ($closes as $key => $close) {     
    if (empty($smas[$key]) || empty($ss[$key])) {
      $return[$key] = FALSE;
      continue;
    }
    
    $s = $ss[$key];
    $sma = $smas[$key];    
    if ($s > $prev_s) {
      $dir = 1;
    } elseif ($s < $prev_s) {
      $dir = -1;
    }
    
    if ($dir <> $prev_dir) {
      if ($trend == 1) { // Up
        if ($s < $prev_s) {
        //if ($prev_s >= $high_s && $s < $high_s) {
          if ($close < $sma) {
            $trend = -1;
          }
        }
      } else { // Down
        if ($s > $prev_s) {
        //if ($prev_s <= $low_s && $s > $low_s) {
          if ($close > $sma) {
            $trend = 1;
          }
        }      
      }
    }
        
    $prev_dir = $dir;
    $prev_s = $s;
    $return[$key] = $trend; 
  }
  
  return $return;
}