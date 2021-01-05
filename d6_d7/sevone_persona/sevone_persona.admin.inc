<?php

/**
 * @file
 * sevone_persona.admin.inc
 */

/**
 * Menu callback for admin settings.
 */
function sevone_persona_admin_config() {
  // Load all global filters
  $filters = variable_get('global_filters', array());
  
  // Load analytics
  $analytics = variable_get('sevone_persona_analytics', array());
  
  $form['global_filters']['analytics'] = array(
    '#tree' => TRUE,
    '#type' => 'fieldset',
    '#title' => t('Google UA Dimension Keys'),
    '#description' => 'Dimension keys are needed from Google in order to properly report on user personas. For information on where to get this, please read <a href="https://support.google.com/analytics/answer/2709829?hl=en&topic=2709827&ctx=topic" target="_blank">this</a>',
  );
  
  foreach ($filters as $filter) {
    if (empty($filter['name'])) {
      continue;
    }
    $default_value = isset($analytics[$filter['name']]) ? $analytics[$filter['name']] : ''; 
    
    $form['global_filters']['analytics'][$filter['name']] = array(
      '#type' => 'textfield',
      '#title' => $filter['name'],
      '#default_value' => $default_value,
    );
  }
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),  
  );
  return $form;
}

/**
 * Submit callback for sevone_persona_admin_config()
 * @param $form
 * @param $form_state
 */
function sevone_persona_admin_config_submit(&$form, &$form_state) {
  $values = $form_state['values'];
  
  foreach ($values['analytics'] as $name => $value) {
    $analytics[$name] = $value;
  }
  
  variable_set('sevone_persona_analytics', $analytics);  
  
  drupal_set_message('Configuration saved.');
}