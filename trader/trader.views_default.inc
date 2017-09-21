<?php
/**
 * @file
 * trader.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function trader_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'orders';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Orders';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Orders';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_setup_target_id']['id'] = 'field_setup_target_id';
  $handler->display->display_options['relationships']['field_setup_target_id']['table'] = 'field_data_field_setup';
  $handler->display->display_options['relationships']['field_setup_target_id']['field'] = 'field_setup_target_id';
  $handler->display->display_options['relationships']['field_setup_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_strategy_target_id']['id'] = 'field_strategy_target_id';
  $handler->display->display_options['relationships']['field_strategy_target_id']['table'] = 'field_data_field_strategy';
  $handler->display->display_options['relationships']['field_strategy_target_id']['field'] = 'field_strategy_target_id';
  $handler->display->display_options['relationships']['field_strategy_target_id']['relationship'] = 'field_setup_target_id';
  $handler->display->display_options['relationships']['field_strategy_target_id']['required'] = TRUE;
  /* Field: Field: Candle Time */
  $handler->display->display_options['fields']['field_candle_time']['id'] = 'field_candle_time';
  $handler->display->display_options['fields']['field_candle_time']['table'] = 'field_data_field_candle_time';
  $handler->display->display_options['fields']['field_candle_time']['field'] = 'field_candle_time';
  $handler->display->display_options['fields']['field_candle_time']['settings'] = array(
    'format_type' => 'candle_time',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Account */
  $handler->display->display_options['fields']['field_account']['id'] = 'field_account';
  $handler->display->display_options['fields']['field_account']['table'] = 'field_data_field_account';
  $handler->display->display_options['fields']['field_account']['field'] = 'field_account';
  /* Field: Content: Order Status */
  $handler->display->display_options['fields']['field_order_status']['id'] = 'field_order_status';
  $handler->display->display_options['fields']['field_order_status']['table'] = 'field_data_field_order_status';
  $handler->display->display_options['fields']['field_order_status']['field'] = 'field_order_status';
  /* Field: Field: Instrument */
  $handler->display->display_options['fields']['field_instrument']['id'] = 'field_instrument';
  $handler->display->display_options['fields']['field_instrument']['table'] = 'field_data_field_instrument';
  $handler->display->display_options['fields']['field_instrument']['field'] = 'field_instrument';
  /* Field: Content: Order Type */
  $handler->display->display_options['fields']['field_order_type']['id'] = 'field_order_type';
  $handler->display->display_options['fields']['field_order_type']['table'] = 'field_data_field_order_type';
  $handler->display->display_options['fields']['field_order_type']['field'] = 'field_order_type';
  /* Field: Content: Price */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '5',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Units */
  $handler->display->display_options['fields']['field_units']['id'] = 'field_units';
  $handler->display->display_options['fields']['field_units']['table'] = 'field_data_field_units';
  $handler->display->display_options['fields']['field_units']['field'] = 'field_units';
  $handler->display->display_options['fields']['field_units']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Side */
  $handler->display->display_options['fields']['field_side']['id'] = 'field_side';
  $handler->display->display_options['fields']['field_side']['table'] = 'field_data_field_side';
  $handler->display->display_options['fields']['field_side']['field'] = 'field_side';
  /* Field: Content: Stop Loss */
  $handler->display->display_options['fields']['field_stop_loss']['id'] = 'field_stop_loss';
  $handler->display->display_options['fields']['field_stop_loss']['table'] = 'field_data_field_stop_loss';
  $handler->display->display_options['fields']['field_stop_loss']['field'] = 'field_stop_loss';
  $handler->display->display_options['fields']['field_stop_loss']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '5',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Take Profit */
  $handler->display->display_options['fields']['field_take_profit']['id'] = 'field_take_profit';
  $handler->display->display_options['fields']['field_take_profit']['table'] = 'field_data_field_take_profit';
  $handler->display->display_options['fields']['field_take_profit']['field'] = 'field_take_profit';
  $handler->display->display_options['fields']['field_take_profit']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '5',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Setup */
  $handler->display->display_options['fields']['field_setup']['id'] = 'field_setup';
  $handler->display->display_options['fields']['field_setup']['table'] = 'field_data_field_setup';
  $handler->display->display_options['fields']['field_setup']['field'] = 'field_setup';
  $handler->display->display_options['fields']['field_setup']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Trade */
  $handler->display->display_options['fields']['field_trade']['id'] = 'field_trade';
  $handler->display->display_options['fields']['field_trade']['table'] = 'field_data_field_trade';
  $handler->display->display_options['fields']['field_trade']['field'] = 'field_trade';
  $handler->display->display_options['fields']['field_trade']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_strategy_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Strategy';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'order' => 'order',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['orders'] = $view;

  $view = new view();
  $view->name = 'portfolio';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Portfolio';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Portfolio';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Trades */
  $handler = $view->new_display('block', 'Trades', 'trades');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'You currently have no open trades';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'trade' => 'trade',
  );

  /* Display: Orders */
  $handler = $view->new_display('block', 'Orders', 'orders');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'You currently have no open orders.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'order' => 'order',
  );
  /* Filter criterion: Content: Order Status (field_order_status) */
  $handler->display->display_options['filters']['field_order_status_value']['id'] = 'field_order_status_value';
  $handler->display->display_options['filters']['field_order_status_value']['table'] = 'field_data_field_order_status';
  $handler->display->display_options['filters']['field_order_status_value']['field'] = 'field_order_status_value';
  $handler->display->display_options['filters']['field_order_status_value']['value'] = array(
    'pending' => 'pending',
  );
  $export['portfolio'] = $view;

  $view = new view();
  $view->name = 'trade_setups';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Trade Setups';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'field_setup_status' => 'field_setup_status',
    'field_candle_time' => 'field_candle_time',
    'field_criteria_ratio' => 'field_criteria_ratio',
    'field_reward' => 'field_reward',
    'field_risk' => 'field_risk',
    'field_price' => 'field_price',
    'field_stop_loss' => 'field_stop_loss',
    'field_take_profit' => 'field_take_profit',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = 'field_candle_time';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_setup_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_candle_time' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_criteria_ratio' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_reward' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_risk' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_stop_loss' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_take_profit' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_strategy_target_id']['id'] = 'field_strategy_target_id';
  $handler->display->display_options['relationships']['field_strategy_target_id']['table'] = 'field_data_field_strategy';
  $handler->display->display_options['relationships']['field_strategy_target_id']['field'] = 'field_strategy_target_id';
  $handler->display->display_options['relationships']['field_strategy_target_id']['required'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'candle_time';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_strategy_target_id';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_setup_status']['id'] = 'field_setup_status';
  $handler->display->display_options['fields']['field_setup_status']['table'] = 'field_data_field_setup_status';
  $handler->display->display_options['fields']['field_setup_status']['field'] = 'field_setup_status';
  /* Field: Field: Candle Time */
  $handler->display->display_options['fields']['field_candle_time']['id'] = 'field_candle_time';
  $handler->display->display_options['fields']['field_candle_time']['table'] = 'field_data_field_candle_time';
  $handler->display->display_options['fields']['field_candle_time']['field'] = 'field_candle_time';
  $handler->display->display_options['fields']['field_candle_time']['settings'] = array(
    'format_type' => 'candle_time',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Criteria Ratio */
  $handler->display->display_options['fields']['field_criteria_ratio']['id'] = 'field_criteria_ratio';
  $handler->display->display_options['fields']['field_criteria_ratio']['table'] = 'field_data_field_criteria_ratio';
  $handler->display->display_options['fields']['field_criteria_ratio']['field'] = 'field_criteria_ratio';
  $handler->display->display_options['fields']['field_criteria_ratio']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Reward */
  $handler->display->display_options['fields']['field_reward']['id'] = 'field_reward';
  $handler->display->display_options['fields']['field_reward']['table'] = 'field_data_field_reward';
  $handler->display->display_options['fields']['field_reward']['field'] = 'field_reward';
  $handler->display->display_options['fields']['field_reward']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '5',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Risk */
  $handler->display->display_options['fields']['field_risk']['id'] = 'field_risk';
  $handler->display->display_options['fields']['field_risk']['table'] = 'field_data_field_risk';
  $handler->display->display_options['fields']['field_risk']['field'] = 'field_risk';
  $handler->display->display_options['fields']['field_risk']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '5',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Price */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '5',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Stop Loss */
  $handler->display->display_options['fields']['field_stop_loss']['id'] = 'field_stop_loss';
  $handler->display->display_options['fields']['field_stop_loss']['table'] = 'field_data_field_stop_loss';
  $handler->display->display_options['fields']['field_stop_loss']['field'] = 'field_stop_loss';
  $handler->display->display_options['fields']['field_stop_loss']['label'] = 'SL';
  $handler->display->display_options['fields']['field_stop_loss']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '5',
    'prefix_suffix' => 1,
  );
  /* Field: Content: TP1 */
  $handler->display->display_options['fields']['field_tp1']['id'] = 'field_tp1';
  $handler->display->display_options['fields']['field_tp1']['table'] = 'field_data_field_tp1';
  $handler->display->display_options['fields']['field_tp1']['field'] = 'field_tp1';
  $handler->display->display_options['fields']['field_tp1']['label'] = 'TP';
  $handler->display->display_options['fields']['field_tp1']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '5',
    'prefix_suffix' => 1,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Action';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="/node/[nid]">View</a> <a href="/node/[nid]/edit">Edit</a>';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'setup' => 'setup',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';

  /* Display: All */
  $handler = $view->new_display('block', 'All', 'all');
  $handler->display->display_options['block_description'] = 'Setups';

  /* Display: Completed */
  $handler = $view->new_display('block', 'Completed', 'completed');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'setup' => 'setup',
  );
  /* Filter criterion: Content: Status (field_setup_status) */
  $handler->display->display_options['filters']['field_setup_status_value']['id'] = 'field_setup_status_value';
  $handler->display->display_options['filters']['field_setup_status_value']['table'] = 'field_data_field_setup_status';
  $handler->display->display_options['filters']['field_setup_status_value']['field'] = 'field_setup_status_value';
  $handler->display->display_options['filters']['field_setup_status_value']['value'] = array(
    'completed' => 'completed',
  );
  $export['trade_setups'] = $view;

  $view = new view();
  $view->name = 'trades';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Trades';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Trades';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_trade_open_date' => 'field_trade_open_date',
    'field_updated' => 'field_updated',
    'title' => 'title',
    'field_account' => 'field_account',
    'field_trade_id' => 'field_trade_id',
    'field_instrument' => 'field_instrument',
    'field_side' => 'field_side',
    'field_units' => 'field_units',
    'field_price' => 'field_price',
    'field_stop_loss' => 'field_stop_loss',
    'field_take_profit' => 'field_take_profit',
    'field_break_even_price' => 'field_break_even_price',
    'field_trade_close_date' => 'field_trade_close_date',
    'field_close_price' => 'field_close_price',
    'field_trade_drawdown' => 'field_trade_drawdown',
    'field_trade_profit' => 'field_trade_profit',
    'field_trade_result' => 'field_trade_result',
    'field_margin_used' => 'field_margin_used',
    'field_financing' => 'field_financing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_trade_open_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_updated' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_account' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trade_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_instrument' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_side' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_units' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_stop_loss' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_take_profit' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_break_even_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trade_close_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_close_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trade_drawdown' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trade_profit' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trade_result' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_margin_used' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_financing' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Field: Content: Open Date/Time */
  $handler->display->display_options['fields']['field_trade_open_date']['id'] = 'field_trade_open_date';
  $handler->display->display_options['fields']['field_trade_open_date']['table'] = 'field_data_field_trade_open_date';
  $handler->display->display_options['fields']['field_trade_open_date']['field'] = 'field_trade_open_date';
  $handler->display->display_options['fields']['field_trade_open_date']['settings'] = array(
    'format_type' => 'candle_time',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Updated */
  $handler->display->display_options['fields']['field_updated']['id'] = 'field_updated';
  $handler->display->display_options['fields']['field_updated']['table'] = 'field_data_field_updated';
  $handler->display->display_options['fields']['field_updated']['field'] = 'field_updated';
  $handler->display->display_options['fields']['field_updated']['settings'] = array(
    'format_type' => 'candle_time',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Account */
  $handler->display->display_options['fields']['field_account']['id'] = 'field_account';
  $handler->display->display_options['fields']['field_account']['table'] = 'field_data_field_account';
  $handler->display->display_options['fields']['field_account']['field'] = 'field_account';
  /* Field: Content: Trade ID */
  $handler->display->display_options['fields']['field_trade_id']['id'] = 'field_trade_id';
  $handler->display->display_options['fields']['field_trade_id']['table'] = 'field_data_field_trade_id';
  $handler->display->display_options['fields']['field_trade_id']['field'] = 'field_trade_id';
  /* Field: Field: Instrument */
  $handler->display->display_options['fields']['field_instrument']['id'] = 'field_instrument';
  $handler->display->display_options['fields']['field_instrument']['table'] = 'field_data_field_instrument';
  $handler->display->display_options['fields']['field_instrument']['field'] = 'field_instrument';
  /* Field: Content: Side */
  $handler->display->display_options['fields']['field_side']['id'] = 'field_side';
  $handler->display->display_options['fields']['field_side']['table'] = 'field_data_field_side';
  $handler->display->display_options['fields']['field_side']['field'] = 'field_side';
  /* Field: Content: Units */
  $handler->display->display_options['fields']['field_units']['id'] = 'field_units';
  $handler->display->display_options['fields']['field_units']['table'] = 'field_data_field_units';
  $handler->display->display_options['fields']['field_units']['field'] = 'field_units';
  $handler->display->display_options['fields']['field_units']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Price */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '5',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Stop Loss */
  $handler->display->display_options['fields']['field_stop_loss']['id'] = 'field_stop_loss';
  $handler->display->display_options['fields']['field_stop_loss']['table'] = 'field_data_field_stop_loss';
  $handler->display->display_options['fields']['field_stop_loss']['field'] = 'field_stop_loss';
  $handler->display->display_options['fields']['field_stop_loss']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '5',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Take Profit */
  $handler->display->display_options['fields']['field_take_profit']['id'] = 'field_take_profit';
  $handler->display->display_options['fields']['field_take_profit']['table'] = 'field_data_field_take_profit';
  $handler->display->display_options['fields']['field_take_profit']['field'] = 'field_take_profit';
  $handler->display->display_options['fields']['field_take_profit']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '5',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Break Even Price */
  $handler->display->display_options['fields']['field_break_even_price']['id'] = 'field_break_even_price';
  $handler->display->display_options['fields']['field_break_even_price']['table'] = 'field_data_field_break_even_price';
  $handler->display->display_options['fields']['field_break_even_price']['field'] = 'field_break_even_price';
  $handler->display->display_options['fields']['field_break_even_price']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '5',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Close Date/Time */
  $handler->display->display_options['fields']['field_trade_close_date']['id'] = 'field_trade_close_date';
  $handler->display->display_options['fields']['field_trade_close_date']['table'] = 'field_data_field_trade_close_date';
  $handler->display->display_options['fields']['field_trade_close_date']['field'] = 'field_trade_close_date';
  $handler->display->display_options['fields']['field_trade_close_date']['settings'] = array(
    'format_type' => 'candle_time',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Close Price */
  $handler->display->display_options['fields']['field_close_price']['id'] = 'field_close_price';
  $handler->display->display_options['fields']['field_close_price']['table'] = 'field_data_field_close_price';
  $handler->display->display_options['fields']['field_close_price']['field'] = 'field_close_price';
  $handler->display->display_options['fields']['field_close_price']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '5',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Drawdown */
  $handler->display->display_options['fields']['field_trade_drawdown']['id'] = 'field_trade_drawdown';
  $handler->display->display_options['fields']['field_trade_drawdown']['table'] = 'field_data_field_trade_drawdown';
  $handler->display->display_options['fields']['field_trade_drawdown']['field'] = 'field_trade_drawdown';
  $handler->display->display_options['fields']['field_trade_drawdown']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '5',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Trade Profit */
  $handler->display->display_options['fields']['field_trade_profit']['id'] = 'field_trade_profit';
  $handler->display->display_options['fields']['field_trade_profit']['table'] = 'field_data_field_trade_profit';
  $handler->display->display_options['fields']['field_trade_profit']['field'] = 'field_trade_profit';
  $handler->display->display_options['fields']['field_trade_profit']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '5',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Trade Result */
  $handler->display->display_options['fields']['field_trade_result']['id'] = 'field_trade_result';
  $handler->display->display_options['fields']['field_trade_result']['table'] = 'field_data_field_trade_result';
  $handler->display->display_options['fields']['field_trade_result']['field'] = 'field_trade_result';
  /* Field: Content: Margin Used */
  $handler->display->display_options['fields']['field_margin_used']['id'] = 'field_margin_used';
  $handler->display->display_options['fields']['field_margin_used']['table'] = 'field_data_field_margin_used';
  $handler->display->display_options['fields']['field_margin_used']['field'] = 'field_margin_used';
  $handler->display->display_options['fields']['field_margin_used']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Financing */
  $handler->display->display_options['fields']['field_financing']['id'] = 'field_financing';
  $handler->display->display_options['fields']['field_financing']['table'] = 'field_data_field_financing';
  $handler->display->display_options['fields']['field_financing']['field'] = 'field_financing';
  $handler->display->display_options['fields']['field_financing']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '5',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'trade' => 'trade',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['trades'] = $view;

  return $export;
}
