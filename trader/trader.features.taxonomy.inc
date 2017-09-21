<?php
/**
 * @file
 * trader.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function trader_taxonomy_default_vocabularies() {
  return array(
    'account' => array(
      'name' => 'Account',
      'machine_name' => 'account',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'broker' => array(
      'name' => 'Broker',
      'machine_name' => 'broker',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'candle_gran' => array(
      'name' => 'Candle Gran',
      'machine_name' => 'candle_gran',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'instrument' => array(
      'name' => 'Instrument',
      'machine_name' => 'instrument',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'order_status' => array(
      'name' => 'Order Status',
      'machine_name' => 'order_status',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'strategy' => array(
      'name' => 'Strategy',
      'machine_name' => 'strategy',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'trade_status' => array(
      'name' => 'Trade Status',
      'machine_name' => 'trade_status',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'trading_days' => array(
      'name' => 'Trading Days',
      'machine_name' => 'trading_days',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'trading_hours' => array(
      'name' => 'Trading Hours',
      'machine_name' => 'trading_hours',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
