<?php

/**
 * Plugins are described by creating a $plugin array which will
 * be used by the system that includes the file.
 */
$plugin = array(
  'title' => t('URL: Url Paramter Has-Keys'),
  'description' => t('allows someone to access pane with param key in link'),
  'callback' => 'iin_panels_extras_url_param_has_key_ctools_access_check',
  'summary' => 'iin_panels_extras_url_param_has_key_ctools_summary',
  'settings form' => 'iin_panels_extras_url_param_has_key_ctools_settings',
	//'required context' => new ctools_context_required(t('URL Data'), 'url_data'),
);

/**
 * Custom callback defined by 'callback' in the $plugin array.
 *
 * Check for access.
 */
function iin_panels_extras_url_param_has_key_ctools_access_check($conf, $context) {
  // If for some unknown reason that $context isn't set, we just want to be sure.
  //if (empty($context) || empty($context->data)) {
  //  return FALSE;
  //}

  // Grab the setting for this instance and compare it to the url parameters from the context
  $param_key = $conf['url_param_has_key'];
      
	if (!empty($_GET)) {
	  if (array_key_exists($param_key, $_GET) == TRUE) {
		  return TRUE;
	  }  
	}
 
  
}

/**
 * Settings form for the 'url_param_has_key' access plugin.
 */
function iin_panels_extras_url_param_has_key_ctools_settings($form, &$form_state, $conf) {
  $form['settings']['url_param_has_key'] = array(
    '#type' => 'textfield',
    '#title' => t('URL Parameter Has-Key'),
    '#description' => t('Enter a value or list of keys (comma or space-separated) to be passed via url parameter (ie www.site.com?key=value)'),
    '#default_value' => $conf['url_param_has_key'],
  );
  return $form;
}

/**
 * Provide a summary description showing what you choose as a param key.
 */
function iin_panels_extras_url_param_has_key_ctools_summary($conf, $context) {
  return t('Key: ' . $conf['url_param_has_key']);
}