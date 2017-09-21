<?php

/**
 * Plugins are described by creating a $plugin array which will
 * be used by the system that includes the file.
 */
$plugin = array(
  'title'         => t('URL Parameters: Key|Value'),
  'description'   => t('Allows visibility of pane with param keys and values in link'),
  'summary'       => 'iin_panels_extras_url_parameters_ctools_summary',
  'callback'      => 'iin_panels_extras_url_parameters_ctools_access_check',
  'settings form' => 'iin_panels_extras_url_parameters_ctools_settings',
);

/**
 * Custom callback defined by 'callback' in the $plugin array.
 *
 * Check for access.
 */
function iin_panels_extras_url_parameters_ctools_access_check($conf, $context) {
  // Grab the setting for this instance and compare it to the url parameters from the context
  $param_key = $conf['param_key'];
  $param_value = $conf['param_value'];
	if (!empty($param_key) && !empty($param_value)) {
    if(!empty($_GET) && !empty($_GET[$param_key]) && $_GET[$param_key] == $param_value) {
      return TRUE;
    } 
	}
	else if (!empty($param_key) && empty($param_value)) {
  	if(!empty($_GET) && !empty($_GET[$param_key])) {
      return TRUE;
    } 
	}
	// look for the value in any url parameter
	else if (!empty($_GET) && in_array($param_value, $_GET) == TRUE) {
		return TRUE;
  }
  return FALSE;
}

/**
 * Settings form for the 'url_parameters' access plugin.
 */
function iin_panels_extras_url_parameters_ctools_settings($form, &$form_state, $conf) {
  $form['settings']['param_key'] = array(
    '#type' => 'textfield',
    '#title' => t('URL Parameter Key'),
    '#description' => t('If you don\'t specify a key value, the pane will appear when any key in the query has the value specified. For example, http://www.integrativenutrition.com/?color=blue, "color" is the key.'),
    '#default_value' => $conf['param_key'],
  );
  $form['settings']['param_value'] = array(
    '#type' => 'textfield',
    '#title' => t('URL Parameter Value. '),
    '#description' => t('For example, http://www.integrativenutrition.com/?color=blue, "blue" is the value. If you specify a key, but no value, it will check to see if there is a key anywhere in the URL string.'),
    '#default_value' => $conf['param_value'],
  );  
  $form['#validate'][] = 'iin_panels_extras_url_parameters_ctools_settings_validate';
  return $form;
}

/**
 * Provide a summary description showing what you choose as a param key|value.
 */
function iin_panels_extras_url_parameters_ctools_summary($conf, $context) {
  $text = '';
  $text = !empty($conf['param_key']) ? 'Key: ' . $conf['param_key'] . ' ': "";
  $text .= (!empty($conf['param_value'])) ? 'Value: '. $conf['param_value'] . ' ': "";
  return $text;
}

function iin_panels_extras_url_parameters_ctools_settings_validate(&$form, &$form_state) {
  if (empty($form_state['values']['settings']['param_value']) && empty($form_state['values']['settings']['param_key'])) {
    form_set_error('param_key', t('You should probably have something saved in a field at this point.'));
  }
}
