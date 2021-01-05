<?php

/**
 * @file
 * Plugin to provide access control/visibility if persona is active
 */

$plugin = array(
  'title' => t("Persona active"),
  'description' => t('Control access by whether or not a persona is active'),
  'callback' => 'sevone_persona_persona_active_ctools_access_check',
  'settings form' => 'sevone_persona_persona_active_ctools_access_settings',
  'summary' => 'sevone_persona_persona_active_ctools_access_summary',
  'defaults' => array('active' => array()),
);

/**
 * Settings form
 */
function sevone_persona_persona_active_ctools_access_settings($form, &$form_state, $conf) {
  // Load the terms
  $vocab = taxonomy_vocabulary_machine_name_load('persona');
  $results = db_select('taxonomy_term_data', 't')
    ->fields('t', array('tid', 'name'))
    ->condition('vid', $vocab->vid)
    ->execute();  
  
  $options = array();
  foreach ($results as $item) {
    $options[$item->tid] = $item->name;
  }
  
  $form['settings']['active'] = array(
    '#type' => 'select',
    '#description' => t("Will only be visible for the selected persona"),
    '#options' => $options,
    '#default_value' => !empty($conf['active']) ? $conf['active'] : '',
    '#multiple' => TRUE,
    '#required' => TRUE,
  );
  return $form;
}

/**
 * Check for access. Does the user's persona match the visibility rule?
 */
function sevone_persona_persona_active_ctools_access_check($conf, $context) {
  $tids = $conf['active'];
  
  // This happens after a persona is cleared
  if (empty($tids) || !is_array($tids)) {
    return TRUE;
  }
  
  if (!$filters = global_filter_get_session_value()) {
    return FALSE;
  }
  
  // No filters show block by default
  if (empty($filters['field_persona'])) {
    return FALSE;
  }

  // global filter supports mutliple filters
  foreach ($filters['field_persona'] as $persona) {
    if (in_array($persona, $tids)) {
      return TRUE;
    }
  }
  
  return FALSE;
}

/**
 * Provide a summary description based upon the specified context
 */
function sevone_persona_persona_active_ctools_access_summary($conf, $context) {
 if (!empty($conf['active']) && $terms = taxonomy_term_load_multiple($conf['active'])) {
    $personas = array();
    foreach ($terms as $term) {
      $personas[] = $term->name;
    }
  
    return t('Persona(s) active: @personas', array('@personas' => implode(', ', $personas)));
  }
}
