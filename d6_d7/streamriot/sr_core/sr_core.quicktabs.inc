<?php
/**
 * @file
 * sr_core.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function sr_core_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'help_center';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = TRUE;
  $quicktabs->default_tab = 999999;
  $quicktabs->title = 'HELP CENTER';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'help_and_faq_block',
      'display' => 'block',
      'args' => '',
      'title' => 'Help CENTER and Guide',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'help_and_faq_block',
      'display' => 'block_1',
      'args' => '',
      'title' => 'FAQ’S',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'accordion';
  $quicktabs->style = 'default';
  $quicktabs->options = array(
    'history' => 0,
    'jquery_ui' => array(
      'autoHeight' => 0,
      'collapsible' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('FAQ’S');
  t('HELP CENTER');
  t('Help CENTER and Guide');

  $export['help_center'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'popular_blog';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Popular blog';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'blog_right_side_block',
      'display' => 'block_1',
      'args' => '',
      'title' => 'Popular',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'blog_right_side_block',
      'display' => 'block_2',
      'args' => '',
      'title' => 'Recent',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'bid' => 'tagclouds_delta_1',
      'hide_title' => 1,
      'title' => 'Tags',
      'weight' => '-98',
      'type' => 'block',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'Sky';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Popular');
  t('Popular blog');
  t('Recent');
  t('Tags');

  $export['popular_blog'] = $quicktabs;

  return $export;
}
