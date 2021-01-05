<?php
/**
 * @file
 * trader.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function trader_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'AUD_CAD',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '032e2a0c-013a-4bbb-8f97-883e7082a455',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.03,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 1,
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '05ac05f6-2685-4399-8426-b9101a562b96',
    'vocabulary_machine_name' => 'trading_hours',
  );
  $terms[] = array(
    'name' => 'H4',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '07203f2c-4202-4ec3-a7e4-c9d20b523860',
    'vocabulary_machine_name' => 'candle_gran',
  );
  $terms[] = array(
    'name' => 20,
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 20,
    'uuid' => '07b8b243-8adb-4f61-a014-31cd61c27bd8',
    'vocabulary_machine_name' => 'trading_hours',
  );
  $terms[] = array(
    'name' => 'Wednesday',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => '0a9143ab-e5d2-47c4-bb10-62f9d35c297f',
    'vocabulary_machine_name' => 'trading_days',
  );
  $terms[] = array(
    'name' => 'USD_CAD',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '0b5f7c66-3214-45f8-800b-2e6ab8667829',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.02,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'Sadler',
    'description' => 'This description',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '0cf0a2bb-5c9a-463c-817b-d02283424de4',
    'vocabulary_machine_name' => 'strategy',
    'field_frac_s' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_frac_m' => array(
      'und' => array(
        0 => array(
          'value' => 30,
        ),
      ),
    ),
    'field_frac_l' => array(
      'und' => array(
        0 => array(
          'value' => 60,
        ),
      ),
    ),
    'field_stochastic' => array(
      'und' => array(
        0 => array(
          'value' => '5/3/2',
          'format' => NULL,
        ),
      ),
    ),
    'field_sma' => array(
      'und' => array(
        0 => array(
          'value' => 50,
        ),
      ),
    ),
    'field_sma_long' => array(
      'und' => array(
        0 => array(
          'value' => 100,
        ),
      ),
    ),
    'field_sadler_range' => array(
      'und' => array(
        0 => array(
          'value' => 24,
        ),
      ),
    ),
    'field_rsi' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_macd' => array(),
    'field_instrument' => array(
      'und' => array(
        0 => array(
          'tid' => 'f02dd394-f806-43d3-bce3-a0fd65f3435b',
          'uuid' => 'f02dd394-f806-43d3-bce3-a0fd65f3435b',
        ),
      ),
    ),
    'field_trading_hours' => array(
      'und' => array(
        0 => array(
          'tid' => 'b0efdc8f-9a12-428e-a2c1-c1525596869f',
          'uuid' => 'b0efdc8f-9a12-428e-a2c1-c1525596869f',
        ),
        1 => array(
          'tid' => '1c1befcd-5bdc-47f6-be47-1fdef8fa6e2f',
          'uuid' => '1c1befcd-5bdc-47f6-be47-1fdef8fa6e2f',
        ),
        2 => array(
          'tid' => '86d5b678-7b36-4e1f-83d7-63b4cbe72dea',
          'uuid' => '86d5b678-7b36-4e1f-83d7-63b4cbe72dea',
        ),
        3 => array(
          'tid' => '74ba23c7-8050-428e-a2c7-11220ee8e266',
          'uuid' => '74ba23c7-8050-428e-a2c7-11220ee8e266',
        ),
        4 => array(
          'tid' => 'f9a599e4-cf31-44e5-8403-f9760e5de84c',
          'uuid' => 'f9a599e4-cf31-44e5-8403-f9760e5de84c',
        ),
        5 => array(
          'tid' => 'b9cfd79c-3443-4ad7-b0af-fc02292df8e3',
          'uuid' => 'b9cfd79c-3443-4ad7-b0af-fc02292df8e3',
        ),
        6 => array(
          'tid' => 'e2a4f0d2-6240-49b6-95a8-526898c9b22f',
          'uuid' => 'e2a4f0d2-6240-49b6-95a8-526898c9b22f',
        ),
        7 => array(
          'tid' => 'c13cffea-6af8-4fca-bdd1-f8345bf426db',
          'uuid' => 'c13cffea-6af8-4fca-bdd1-f8345bf426db',
        ),
        8 => array(
          'tid' => '18f16284-3ac3-4a15-9c91-583b714637f7',
          'uuid' => '18f16284-3ac3-4a15-9c91-583b714637f7',
        ),
      ),
    ),
    'field_trading_days' => array(
      'und' => array(
        0 => array(
          'tid' => '6654d660-4d18-45f1-9e59-fec604d84705',
          'uuid' => '6654d660-4d18-45f1-9e59-fec604d84705',
        ),
        1 => array(
          'tid' => '74d7e5e3-7725-495c-a2fe-f4f16387686b',
          'uuid' => '74d7e5e3-7725-495c-a2fe-f4f16387686b',
        ),
        2 => array(
          'tid' => '0a9143ab-e5d2-47c4-bb10-62f9d35c297f',
          'uuid' => '0a9143ab-e5d2-47c4-bb10-62f9d35c297f',
        ),
        3 => array(
          'tid' => 'fd11bf82-0bd9-4df7-b4e0-90af225ea579',
          'uuid' => 'fd11bf82-0bd9-4df7-b4e0-90af225ea579',
        ),
        4 => array(
          'tid' => '96d0af5b-c24b-4f9c-b5ab-d2abba23887c',
          'uuid' => '96d0af5b-c24b-4f9c-b5ab-d2abba23887c',
        ),
      ),
    ),
    'field_max_trade_risk' => array(
      'und' => array(
        0 => array(
          'value' => '0.0200',
        ),
      ),
    ),
    'field_min_pips' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_min_risk_reward' => array(
      'und' => array(
        0 => array(
          'value' => '1:1',
          'format' => NULL,
        ),
      ),
    ),
    'field_callback' => array(
      'und' => array(
        0 => array(
          'value' => 'trader_setup_sadler',
          'format' => NULL,
        ),
      ),
    ),
    'field_entry_criteria' => array(),
    'field_close_criteria' => array(),
  );
  $terms[] = array(
    'name' => 'GBP_HKD',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '13a704cf-289b-43ce-a4fb-8309516799c1',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'EUR_DKK',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '16f10aa2-1bca-48ef-b337-95c393dfddc7',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.02,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'M30',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '1806d17a-97eb-42e2-b6e4-8aed3e2c1b5b',
    'vocabulary_machine_name' => 'candle_gran',
  );
  $terms[] = array(
    'name' => 11,
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 11,
    'uuid' => '18f16284-3ac3-4a15-9c91-583b714637f7',
    'vocabulary_machine_name' => 'trading_hours',
  );
  $terms[] = array(
    'name' => 4,
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => '1c1befcd-5bdc-47f6-be47-1fdef8fa6e2f',
    'vocabulary_machine_name' => 'trading_hours',
  );
  $terms[] = array(
    'name' => 'CHF_HKD',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '1d8db0d1-b20d-4f38-bff8-d33150b5c902',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'EUR_NOK',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '1dece71a-1f95-4f52-8004-0e614a77f2df',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.03,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'USD_HUF',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '1fdc0210-fbab-4ead-aee4-1401b93e1a7d',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.01,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => 0.001,
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'USD_CHF',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '21cac4a9-4b2c-4727-8553-e525e7c40ee5',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'EUR_CZK',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '21ee7748-ad75-4260-9358-863813675d6d',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 14,
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 14,
    'uuid' => '2566f443-34d6-432f-acd1-696a0b471279',
    'vocabulary_machine_name' => 'trading_hours',
  );
  $terms[] = array(
    'name' => 'EUR_HUF',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '26e62749-c06d-48a3-ad33-6a5bf5fe7703',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.01,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => 0.001,
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'AUD_HKD',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '27d1905c-7c65-4a8b-bb1d-badbf00dbc7c',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'USD_SGD',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '29286971-c0ce-4bdd-83b6-339cbb92972b',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'EUR_TRY',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '2b7df9d4-89e8-484e-a472-0f4af5990974',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'AUD_JPY',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '2c701d91-00f4-4e02-bcaa-be62d68edb6c',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.01,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => 0.001,
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.03,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'AUD_USD',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '2c9a07a5-0720-4b36-b46c-861acd96fe71',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.03,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'Pending',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '309d2879-423d-4ba9-9f44-c0b207019c1a',
    'vocabulary_machine_name' => 'order_status',
  );
  $terms[] = array(
    'name' => 'Oanda',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3261de86-b1ab-4f41-97e2-61268403f190',
    'vocabulary_machine_name' => 'broker',
  );
  $terms[] = array(
    'name' => 'AUD_SGD',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '32a0c285-006e-41e1-9814-e5fbdd016277',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'GBP_CHF',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '36b07ed4-f180-4147-903d-41339eaa54e0',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 0,
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3a5a2c88-b214-4581-b3cb-39cb0eb015bc',
    'vocabulary_machine_name' => 'trading_hours',
  );
  $terms[] = array(
    'name' => 'SGD_HKD',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '3c0124d4-b08f-4e04-b590-cd31d4363091',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'CAD_JPY',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '4423639d-2436-486c-8d17-324dba3c64fc',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.01,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => 0.001,
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.03,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'USD_HKD',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '44e61669-c9cf-4c4b-99f0-e5bd74a4591a',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'GBP_ZAR',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '4666e8c6-77ae-4261-8276-b3635f2d129a',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 15,
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 15,
    'uuid' => '476257c8-3baf-412c-a2d0-b426a1f6cfff',
    'vocabulary_machine_name' => 'trading_hours',
  );
  $terms[] = array(
    'name' => 'HKD_JPY',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '4ac565d7-e699-4345-9bbf-108b482174b1',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 22,
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 22,
    'uuid' => '4c21a976-f579-47c1-a305-54c15f0aec4e',
    'vocabulary_machine_name' => 'trading_hours',
  );
  $terms[] = array(
    'name' => 'GBP_CAD',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '4df88773-0b20-4b37-9f05-a6a7af5b2d88',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.02,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'S15',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '4fc94c4a-73f6-4706-bc49-73089cdf1cce',
    'vocabulary_machine_name' => 'candle_gran',
  );
  $terms[] = array(
    'name' => 'Filled',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => '52996189-ba45-4fd1-8cda-85b23e10720a',
    'vocabulary_machine_name' => 'order_status',
  );
  $terms[] = array(
    'name' => 'D1',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '531f5e9f-f623-445b-92a3-95b9e1b00371',
    'vocabulary_machine_name' => 'candle_gran',
  );
  $terms[] = array(
    'name' => 'SGD_CHF',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '53c090be-42d3-4ee9-9d04-a6f020371de1',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'S10',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '58ed0ffe-5b0a-4cb4-b86b-5bf399347a2f',
    'vocabulary_machine_name' => 'candle_gran',
  );
  $terms[] = array(
    'name' => 'EUR_ZAR',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '5e33f081-ebc0-4877-af75-dd9e8731dccf',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'USD_ZAR',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '5e695a34-d7e7-43f7-a602-3c4718fc465e',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'USD_CZK',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '5eb4e580-2763-413c-896f-18b5030ca127',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'EUR_CAD',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '64b1f1b0-70f7-4cbb-99f1-f8bbf6977f96',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.02,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'Monday',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '6654d660-4d18-45f1-9e59-fec604d84705',
    'vocabulary_machine_name' => 'trading_days',
  );
  $terms[] = array(
    'name' => 'EUR_AUD',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '67389132-6595-4940-b88a-a955db86a551',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.03,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'EUR_PLN',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '7294780f-ea52-4943-8607-e1e98e6e518a',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'EUR_NZD',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '73949c91-f54a-4d13-9031-b7ac39de6d49',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.02,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 6,
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 6,
    'uuid' => '74ba23c7-8050-428e-a2c7-11220ee8e266',
    'vocabulary_machine_name' => 'trading_hours',
  );
  $terms[] = array(
    'name' => 'Tuesday',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => '74d7e5e3-7725-495c-a2fe-f4f16387686b',
    'vocabulary_machine_name' => 'trading_days',
  );
  $terms[] = array(
    'name' => 'CAD_CHF',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '759278e1-18ff-4c95-9d14-e24ee7895d2b',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'USD_NOK',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '77ba18f0-8e38-4ac5-81b1-3fc36502c645',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.03,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 12,
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 12,
    'uuid' => '7c92a234-5583-4405-b23f-bd24eb3b839e',
    'vocabulary_machine_name' => 'trading_hours',
  );
  $terms[] = array(
    'name' => 'NZD_JPY',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '7d4eb440-8c40-4a50-9291-4c3525596292',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.01,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => 0.001,
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.03,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'EUR_HKD',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '7dec34bd-893b-424c-8d0e-b75e2a224745',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 17,
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 17,
    'uuid' => '7f5078f7-ad41-4ec5-a268-2182d5b714c3',
    'vocabulary_machine_name' => 'trading_hours',
  );
  $terms[] = array(
    'name' => 16,
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 16,
    'uuid' => '83f057e5-c806-45d5-bd20-e2daeb4afefd',
    'vocabulary_machine_name' => 'trading_hours',
  );
  $terms[] = array(
    'name' => 5,
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 5,
    'uuid' => '86d5b678-7b36-4e1f-83d7-63b4cbe72dea',
    'vocabulary_machine_name' => 'trading_hours',
  );
  $terms[] = array(
    'name' => 'USD_SEK',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '88b12526-a05c-43b8-a86d-16c902c81385',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.03,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 21,
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 21,
    'uuid' => '89094444-3d24-4d26-bce4-c1ec0dca295f',
    'vocabulary_machine_name' => 'trading_hours',
  );
  $terms[] = array(
    'name' => 'USD_PLN',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '8c19120d-56e8-4d84-b45d-d8f3e009274f',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'CHF_JPY',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '8f703f74-fd37-4394-8805-d1a19b372de4',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.01,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => 0.001,
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 13,
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 13,
    'uuid' => '9017d708-4757-49e1-890d-1861684704b8',
    'vocabulary_machine_name' => 'trading_hours',
  );
  $terms[] = array(
    'name' => 'M5',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '912c7308-88f4-4525-8d80-e86a1bab01cb',
    'vocabulary_machine_name' => 'candle_gran',
  );
  $terms[] = array(
    'name' => 23,
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 23,
    'uuid' => '92117607-f80c-4979-8cf8-52f8a2e3ee58',
    'vocabulary_machine_name' => 'trading_hours',
  );
  $terms[] = array(
    'name' => 'Denied',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '93fa9d96-17a6-4636-9347-abe017edda82',
    'vocabulary_machine_name' => 'order_status',
  );
  $terms[] = array(
    'name' => 'Sunday',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '948fa02d-8766-4e5e-8d81-324593f0a4c6',
    'vocabulary_machine_name' => 'trading_days',
  );
  $terms[] = array(
    'name' => 'USD_CNH',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '94ee25fd-cb1a-41e2-8d24-5c821219af05',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'EUR_SEK',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '957a6b48-40ee-4c3e-9c89-52b3b96c42dc',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.03,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'NZD_HKD',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '95b89e30-f181-433d-820c-e4184e02654c',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'AUD_CHF',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '96a66bf2-a1c6-4ac0-b993-dfd8e6af5309',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'Friday',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 5,
    'uuid' => '96d0af5b-c24b-4f9c-b5ab-d2abba23887c',
    'vocabulary_machine_name' => 'trading_days',
  );
  $terms[] = array(
    'name' => 'CHF_ZAR',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '98b5d78d-7d6a-4586-bf7e-cc7d93d9a3aa',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'M1',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '9ac65289-72b5-4565-aae0-22f188943431',
    'vocabulary_machine_name' => 'candle_gran',
  );
  $terms[] = array(
    'name' => 18,
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 18,
    'uuid' => '9c2fd9e2-7337-41c1-9807-b336a2f91130',
    'vocabulary_machine_name' => 'trading_hours',
  );
  $terms[] = array(
    'name' => 'GBP_USD',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '9e9bcce8-2cf1-4d11-b89b-5882f92c21c0',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.02,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'NZD_SGD',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'a7e409fa-f1c2-4974-b43d-87c3cc34ba91',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'EUR_SGD',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'a88aa509-a1c5-45c2-98ee-175a41d73d7f',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'GBP_SGD',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'acd65d04-3953-40c7-9b6b-a3d8b4a736db',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'TRY_JPY',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'acf17979-fd90-41ed-8751-7c10d191a4a5',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.01,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => 0.001,
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 19,
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 19,
    'uuid' => 'ad336b9e-c16d-4ec1-a63d-c8443db62730',
    'vocabulary_machine_name' => 'trading_hours',
  );
  $terms[] = array(
    'name' => 3,
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => 'b0efdc8f-9a12-428e-a2c1-c1525596869f',
    'vocabulary_machine_name' => 'trading_hours',
  );
  $terms[] = array(
    'name' => 'CAD_SGD',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'b11281bc-e0b9-4ef6-9d17-7b283e488c78',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'USD_SAR',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'b3473541-7a61-4e9a-8248-fff09f7d144c',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'EUR_USD',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'b48ad7b1-63a3-4e01-b3e9-097d2edca9b2',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.02,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'EUR_CHF',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'b8da1841-8f3a-409d-a321-902b7f99daed',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'S1',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b8f17f87-8ca1-4a06-910e-8a54d65157be',
    'vocabulary_machine_name' => 'candle_gran',
  );
  $terms[] = array(
    'name' => 8,
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 8,
    'uuid' => 'b9cfd79c-3443-4ad7-b0af-fc02292df8e3',
    'vocabulary_machine_name' => 'trading_hours',
  );
  $terms[] = array(
    'name' => 'USD_THB',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'bb52525c-3a8c-47b6-b086-b13a6cde057c',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.01,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => 0.001,
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'M1',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'bc20c875-e818-4721-a7ad-46b1d9a92a31',
    'vocabulary_machine_name' => 'candle_gran',
  );
  $terms[] = array(
    'name' => 'USD_TRY',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'be3e6efe-ada6-4e03-9d65-bbbc6683a03a',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 10,
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 10,
    'uuid' => 'c13cffea-6af8-4fca-bdd1-f8345bf426db',
    'vocabulary_machine_name' => 'trading_hours',
  );
  $terms[] = array(
    'name' => 'M3',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'c1e28a80-fe73-4f5b-94a6-c832aeafc38d',
    'vocabulary_machine_name' => 'candle_gran',
  );
  $terms[] = array(
    'name' => 'NZD_CAD',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'c3eaa539-0756-4194-b022-01ca7980e944',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.02,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'NZD_CHF',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'c3f6ecae-c916-4b1c-8eae-92e50259448b',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 2,
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => 'c552a8f0-f354-4c4b-903a-ba34180657bb',
    'vocabulary_machine_name' => 'trading_hours',
  );
  $terms[] = array(
    'name' => 'AUD_NZD',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'c65e4c98-5f70-47e0-a87a-e1231cada78f',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.03,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'S30',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'c7f354cd-f7ea-41bd-9d42-d6bfc5bd9fb0',
    'vocabulary_machine_name' => 'candle_gran',
  );
  $terms[] = array(
    'name' => 'USD_JPY',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'cbeb0149-94ef-4a09-99eb-5f5df8254323',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.01,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => 0.001,
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.03,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'EUR_GBP',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'd105a183-1880-4bc5-a040-008633605a2e',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.02,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'EUR_JPY',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'd2315898-cde4-4350-a6d0-9cd5430ab781',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.01,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => 0.001,
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.03,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'SGD_JPY',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'd6506e83-70b5-4016-9167-351a111e6350',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.01,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => 0.001,
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'GBP_PLN',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'e0c9aaa2-206b-4659-acb2-7292290826ed',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 9,
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 9,
    'uuid' => 'e2a4f0d2-6240-49b6-95a8-526898c9b22f',
    'vocabulary_machine_name' => 'trading_hours',
  );
  $terms[] = array(
    'name' => 'GBP_NZD',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'ec9bd2e7-4734-442d-84c4-aefaf12eb17b',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.02,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'GBP_AUD',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'edd827d3-1951-465c-a58c-577c38aa8209',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.03,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'USD_MXN',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'eef6915d-7c74-4ec5-9104-bca921d489c7',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.06,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'Ordered',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => 'efdfb067-ff00-42a5-8e7b-f2ae4f57ae08',
    'vocabulary_machine_name' => 'order_status',
  );
  $terms[] = array(
    'name' => 'W1',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'f000658f-8bfe-476f-b3fc-b913828a3146',
    'vocabulary_machine_name' => 'candle_gran',
  );
  $terms[] = array(
    'name' => 'GBP_JPY',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'f02dd394-f806-43d3-bce3-a0fd65f3435b',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.01,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => 0.001,
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.03,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'NZD_USD',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'f04e4b99-e220-491e-ac1b-3ceed194b83a',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.02,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'USD_DKK',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'f0f51108-e3c7-4874-8fde-14da54881987',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.02,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'CAD_HKD',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'f31fccab-ae35-4e69-99ec-15a606eefde1',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.0001,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => '0.00001',
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 'S5',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'f446ca8f-2efe-47f4-8b39-ebb3b7e1e300',
    'vocabulary_machine_name' => 'candle_gran',
  );
  $terms[] = array(
    'name' => 'ZAR_JPY',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'f85d7ed0-788c-4ec5-a4e8-fa98738abc8e',
    'vocabulary_machine_name' => 'instrument',
    'field_pip' => array(
      'und' => array(
        0 => array(
          'value' => 0.01,
        ),
      ),
    ),
    'field_max_trade_units' => array(
      'und' => array(
        0 => array(
          'value' => 10000000,
        ),
      ),
    ),
    'field_pip_precision' => array(
      'und' => array(
        0 => array(
          'value' => 0.001,
        ),
      ),
    ),
    'field_max_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 10000,
        ),
      ),
    ),
    'field_min_trailing_stop' => array(
      'und' => array(
        0 => array(
          'value' => 5,
        ),
      ),
    ),
    'field_margin_rate' => array(
      'und' => array(
        0 => array(
          'value' => 0.05,
        ),
      ),
    ),
    'field_halted' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_bid' => array(),
    'field_ask' => array(),
  );
  $terms[] = array(
    'name' => 7,
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 7,
    'uuid' => 'f9a599e4-cf31-44e5-8403-f9760e5de84c',
    'vocabulary_machine_name' => 'trading_hours',
  );
  $terms[] = array(
    'name' => 'M15',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'fa7c2a00-b2fc-4955-b944-0b8225dacdbd',
    'vocabulary_machine_name' => 'candle_gran',
  );
  $terms[] = array(
    'name' => 'H1',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'fc93f433-0025-4d85-a9a2-b0061b60fc41',
    'vocabulary_machine_name' => 'candle_gran',
  );
  $terms[] = array(
    'name' => 'Thursday',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => 'fd11bf82-0bd9-4df7-b4e0-90af225ea579',
    'vocabulary_machine_name' => 'trading_days',
  );
  return $terms;
}
