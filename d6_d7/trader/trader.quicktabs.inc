<?php
/**
 * @file
 * trader.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function trader_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'portfolio';
  $quicktabs->ajax = 1;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Portfolio';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'portfolio',
      'display' => 'trades',
      'args' => '',
      'use_title' => 0,
      'title' => 'Trades',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'portfolio',
      'display' => 'orders',
      'args' => '',
      'use_title' => 0,
      'title' => 'Orders',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Orders');
  t('Portfolio');
  t('Trades');

  $export['portfolio'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'setups';
  $quicktabs->ajax = 1;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Setups';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'trade_setups',
      'display' => 'all',
      'args' => '',
      'use_title' => 0,
      'title' => 'All',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'trade_setups',
      'display' => 'completed',
      'args' => '',
      'use_title' => 0,
      'title' => 'Completed',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('All');
  t('Completed');
  t('Setups');

  $export['setups'] = $quicktabs;

  return $export;
}
