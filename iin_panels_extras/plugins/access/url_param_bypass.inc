<?php

/**
 * Plugins are described by creating a $plugin array which will
 * be used by the system that includes the file.
 */
$plugin = array(
  'title' => t('URL: Url Paramter Bypass'),
  'description' => t('allows someone to bypass protection with url in link'),
  'callback' => 'iin_panels_extras_url_param_bypass_ctools_access_check',
  'summary' => 'iin_panels_extras_url_param_bypass_ctools_summary',
  'settings form' => 'iin_panels_extras_url_param_bypass_ctools_settings',
	//'required context' => new ctools_context_required(t('URL Data'), 'url_data'),
);

/**
 * Custom callback defined by 'callback' in the $plugin array.
 *
 * Check for access.
 */
function iin_panels_extras_url_param_bypass_ctools_access_check($conf, $context) {
  // If for some unknown reason that $context isn't set, we just want to be sure.
  //if (empty($context) || empty($context->data)) {
  //  return FALSE;
  //}

  // Grab the setting for this instance and compare it to the url parameters from the context
  $param = $conf['url_param'];
  
  //grab the indexed version of $_GET
  //$url_params = $context->data['query_index'];
  
  //foreach($url_params as $key => $val) {
  if (!empty($_GET)) {
	  
	  foreach ($_GET as $key => $val) {
		  if (!empty($val)) {
			  if (strpos($param, $val) !== FALSE) {
				  return TRUE;
			  }
		  }
		  
	  }
  }
  
}

/**
 * Settings form for the 'url_param' access plugin.
 */
function iin_panels_extras_url_param_bypass_ctools_settings($form, &$form_state, $conf) {
  $form['settings']['url_param'] = array(
    '#type' => 'textfield',
    '#title' => t('URL Parameter'),
    '#description' => t('Enter a value or list of values (comma or space-separated) to be passed via url parameter (ie www.site.com?parameter=value)'),
    '#default_value' => $conf['url_param'],
  );
  return $form;
}

/**
 * Provide a summary description showing what you choose as a param.
 */
function iin_panels_extras_url_param_bypass_ctools_summary($conf, $context) {
  return t('Param: ' . $conf['url_param']);
}