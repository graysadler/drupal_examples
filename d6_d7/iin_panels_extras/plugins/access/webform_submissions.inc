<?php

/**
 * Plugins are described by creating a $plugin array which will
 * be used by the system that includes the file.
 */
$plugin = array(
  'title' => t('Webform Submissions: Component Key|Value'),
  'description' => t('allows someone to access pane with key/value in webform submissions'),
  'callback' => 'iin_panels_extras_webform_submissions_ctools_access_check',
  'summary' => 'iin_panels_extras_webform_submissions_ctools_summary',
  'settings form' => 'iin_panels_extras_webform_submissions_ctools_settings',
);

/**
 * Custom callback defined by 'callback' in the $plugin array.
 *
 * Check for access.
 */
function iin_panels_extras_webform_submissions_ctools_access_check($conf, $context) {
  // If for some unknown reason that $context isn't set, we just want to be sure.
  //if (empty($context) || empty($context->data)) {
  //  return FALSE;
  //}
  if (!empty($_SESSION['iin_quizzes_last_data']['sid'])) {
    $sid = $_SESSION['iin_quizzes_last_data']['sid'];
  }
  if (!empty($_GET['sid'])) {
    $sid = $_GET['sid'];
  }
  // if we are on a confirmation page
  if(isset($sid) && !empty($node)){
    // set $submission to submitted data array
    include_once drupal_get_path('module','webform') . '/includes/webform.submissions.inc';
    $submission = webform_get_submission($node->nid, $sid);
    // set $components to submitted webform components details (key, value, CID etc).
    $webform = node_load($submission->nid);
    $components = $webform->webform['components'];
    // set variables to validation settings configuration
    $component_key = $conf['webform_component_key'];
    $component_value = $conf['webform_component_value'];
    // if both component KEY AND VALUE are filled out - check that both settings match submitted data:
    if (!empty($conf['webform_component_key']) && !empty($conf['webform_component_value'])) {
      foreach ($components as $component_index => $component_data) {
        if ($component_data['form_key'] == $component_key) {
          $component_id = $component_data['cid'];
          if (array_key_exists($component_id, $submission->data) == TRUE) {
            $submitted_value = $submission->data[$component_id][0];
            if (!empty($submitted_value) && $submitted_value == $component_value) {
              return TRUE;
            }
          }
        }
      }
    }
    // if only component KEY is filled out - check that webform field had been filled out with ANY value:
    if (!empty($conf['webform_component_key']) && empty($conf['webform_component_value'])) {
      foreach ($components as $component_index => $component_data) {
        if ($component_data['form_key'] == $component_key) {
          $component_id = $component_data['cid'];
          if (array_key_exists($component_id, $submission->data) == TRUE) {
            if (!empty($submission->data[$component_id][0])) {
              return TRUE;
            }
          }
        }
      }
    }
    // if only component VALUE is filled out - check that specified value had been filled out in ANY webform field:
    if (!empty($conf['webform_component_value']) && empty($conf['webform_component_key'])) {
      foreach ($submission->data as $component_index => $component_data) {
        if ($component_data[0] == $conf['webform_component_value']) {
          return TRUE;
        }
      }
    }
  }
}

/**
 * Settings form for the 'webform_submissions' access plugin.
 */
function iin_panels_extras_webform_submissions_ctools_settings($form, &$form_state, $conf) {
  $form['settings']['webform_component_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Webform Component Key'),
    '#description' => t('Specify a webform component \'Field Key\', to check whether or not that field was filled out by the user. <b>For example, \'Email\' field, "email" is the Field Key.</b> If you specify a \'Webform Component Value\', but no \'Webform Component Key\', the pane will appear when any Field in the webform has the value specified.'),
    '#default_value' => $conf['webform_component_key'],
  );
  $form['settings']['webform_component_value'] = array(
    '#type' => 'textfield',
    '#title' => t('Webform Component Value'),
    '#description' => t('Specify a webform component value, to check whether or not that specific value had been inserted by the user. <b>For example, \'Email\' field, "example@email.com" is the value.</b> If you specify a \'Webform Component Key\', but no \'Webform Component Value\', the pane will appear when that Field is filled out with ANY value.'),
    '#default_value' => $conf['webform_component_value'],
  );
  $form['#validate'][] = 'iin_panels_extras_webform_submissions_ctools_settings_validate';
  return $form;
}

/**
 * Provide a summary description showing what you choose as a validation rule.
 */
function iin_panels_extras_webform_submissions_ctools_summary($conf, $context) {
  $text = '';
  $text = !empty($conf['webform_component_key']) ? 'Key: ' . $conf['webform_component_key'] . ' ': "";
  $text .= (!empty($conf['webform_component_value'])) ? 'Value: '. $conf['webform_component_value'] . ' ': "";
  return $text;
}

function iin_panels_extras_webform_submissions_ctools_settings_validate(&$form, &$form_state) {
  if (empty($form_state['values']['settings']['webform_component_value']) && empty($form_state['values']['settings']['webform_component_key'])) {
    form_set_error('webform_component_key', t('You should probably have something saved in a field at this point.'));
  }
}
