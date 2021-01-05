<?php
/**
 * @file
 * trader.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function trader_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_automation|node|strategy|form';
  $field_group->group_name = 'group_automation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'strategy';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Automation',
    'weight' => '3',
    'children' => array(
      0 => 'field_ping_backtest',
      1 => 'field_ping_setup',
      2 => 'field_backtest_complete_date',
      3 => 'field_setup_complete_date',
      4 => 'field_automate',
      5 => 'field_sms_alert',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_automation|node|strategy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_delete|node|order|form';
  $field_group->group_name = 'group_delete';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'order';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'To Delete',
    'weight' => '19',
    'children' => array(
      0 => 'field_tp1',
      1 => 'field_tp2',
      2 => 'field_risk',
      3 => 'field_reward',
      4 => 'field_candle_gran',
      5 => 'field_candle_time',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'To Delete',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-delete field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_delete|node|order|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_entry_price|node|strategy|form';
  $field_group->group_name = 'group_entry_price';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'strategy';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_order_mgmt';
  $field_group->data = array(
    'label' => 'Entry Price',
    'weight' => '64',
    'children' => array(
      0 => 'field_entry_var',
      1 => 'field_entry_var_value',
      2 => 'field_entry_buffer',
      3 => 'field_entry_spread',
      4 => 'field_entry_frac',
      5 => 'field_entry_fractal',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-entry-price field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_entry_price|node|strategy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_entry|node|strategy|form';
  $field_group->group_name = 'group_entry';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'strategy';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Entry Settings',
    'weight' => '5',
    'children' => array(
      0 => 'field_entry_criteria',
      1 => 'field_entry_type',
      2 => 'field_entry_callback',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_entry|node|strategy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_oanda|user|user|form';
  $field_group->group_name = 'group_oanda';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Oanda',
    'weight' => '3',
    'children' => array(
      0 => 'field_api_key',
      1 => 'field_account_id',
      2 => 'field_default_units',
      3 => 'field_max_trade_risk',
      4 => 'field_max_account_risk',
      5 => 'field_default_bounds',
      6 => 'field_oanda_api',
      7 => 'field_account_buy',
      8 => 'field_account_sell',
      9 => 'field_last_trans_id',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-oanda field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_oanda|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_order_mgmt|node|strategy|form';
  $field_group->group_name = 'group_order_mgmt';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'strategy';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Order Management',
    'weight' => '7',
    'children' => array(
      0 => 'field_callback',
      1 => 'field_close_order_on_tp',
      2 => 'group_entry_price',
      3 => 'group_stop',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_order_mgmt|node|strategy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_risk_mgmt|node|strategy|form';
  $field_group->group_name = 'group_risk_mgmt';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'strategy';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Risk Management',
    'weight' => '6',
    'children' => array(
      0 => 'field_min_pips',
      1 => 'field_max_trade_risk',
      2 => 'field_unit_type',
      3 => 'field_specific_units',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_risk_mgmt|node|strategy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_setup|node|strategy|form';
  $field_group->group_name = 'group_setup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'strategy';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Setup Settings',
    'weight' => '2',
    'children' => array(
      0 => 'field_instrument',
      1 => 'field_close_criteria',
      2 => 'field_trading_days',
      3 => 'field_trading_hours',
      4 => 'field_side',
      5 => 'field_strat_live',
      6 => 'field_fractal',
      7 => 'field_account',
      8 => 'field_completed_candles',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_setup|node|strategy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_stop|node|strategy|form';
  $field_group->group_name = 'group_stop';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'strategy';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_order_mgmt';
  $field_group->data = array(
    'label' => 'Stop Loss',
    'weight' => '65',
    'children' => array(
      0 => 'field_stop_frac',
      1 => 'field_stop_var',
      2 => 'field_stop_buffer',
      3 => 'field_stop_spread',
      4 => 'field_stop_var_value',
      5 => 'field_stop_fractal',
      6 => 'field_stop_even_rr',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-stop field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_stop|node|strategy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_studies|node|strategy|form';
  $field_group->group_name = 'group_studies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'strategy';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Studies',
    'weight' => '4',
    'children' => array(
      0 => 'field_studies',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_studies|node|strategy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_targets|node|strategy|form';
  $field_group->group_name = 'group_targets';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'strategy';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_trade_mgmt';
  $field_group->data = array(
    'label' => 'Targets',
    'weight' => '60',
    'children' => array(
      0 => 'field_fc_take_profit',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-targets field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_targets|node|strategy|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_trade_mgmt|node|strategy|form';
  $field_group->group_name = 'group_trade_mgmt';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'strategy';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Trade Management',
    'weight' => '8',
    'children' => array(
      0 => 'field_break_even_criteria',
      1 => 'field_max_trades',
      2 => 'group_targets',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_trade_mgmt|node|strategy|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Automation');
  t('Entry Price');
  t('Entry Settings');
  t('Oanda');
  t('Order Management');
  t('Risk Management');
  t('Setup Settings');
  t('Stop Loss');
  t('Studies');
  t('Targets');
  t('To Delete');
  t('Trade Management');

  return $field_groups;
}
