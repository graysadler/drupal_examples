<?php

/**
 * @file query_string.inc
 * Context plugin that can extract arbitrary values from the query string.
 */

/**
 * $plugin array which will be used by the system that includes this file.
 */
$plugin = array(
  'title' => t('URL Data'),
  'description' => t('A context that passes some useful URL tidbits.'),
  'context' => 'iin_panels_extras_url_data_create_query_string',
  'context name' => 'url_data',
  'keyword' => 'url_data',
  'edit form' => 'iin_panels_extras_url_data_settings_form',
  //'convert list' => array(
  //  'raw' => t('Raw string'),
  //  'html_safe' => t('HTML-safe string'),
  //),
  //'convert' => 'iin_panels_extras_url_data_convert',
);

/**
 * Create a context from manual configuration.
 */
function iin_panels_extras_url_data_create_query_string($empty, $data = NULL, $conf = FALSE) {
  $context = new ctools_context('url_data');
  $context->plugin = 'url_data';

	$url_data = array();
	$url_data['host'] = $_SERVER['HTTP_HOST'];
	$url_data['querystring'] = $_SERVER['QUERY_STRING'];
	$url_data['uri'] = $_SERVER['REQUEST_URI'];
	$url_data['queries'] = $_GET;
	$url_data['query_index'] = array_values($_GET);

	$context->data = $url_data;
  
  return $context;
}

/**
 * Form builder; settings for the context.
 */
function iin_panels_extras_url_data_settings_form($form, &$form_state) {
  $form['nothing'] = array(
    '#title' => t('Nothing Really'),
    '#description' => t('Enter the nothing.'),
    '#type' => 'textfield',
    '#required' => FALSE
  );

  return $form;
}

/**
 * Submit handler; settings form for the context.
 */
function iin_panels_extras_url_data_settings_form_submit($form, &$form_state) {
  $form_state['conf']['key'] = $form_state['values']['key'];
  $form_state['conf']['fallback_value'] = $form_state['values']['fallback_value'];
}

/**
 * Convert a context into a string.
 */
//function iin_panels_extras_url_data_convert($context, $type) {
//  switch ($type) {
//    case 'raw':
//      return $context->data;
//    case 'html_safe':
//      return check_plain($context->data);
//  }
//}

