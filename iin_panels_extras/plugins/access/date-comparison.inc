<?php

/**
 * Plugins are described by creating a $plugin array which will
 * be used by the system that includes the file.
 */
$plugin = array(
  'title' => t('Date: Compare to Moment'),
  'description' => t('allows someone to bypass protection with url in link'),
  'callback' => 'iin_panels_extras_date_comparison_ctools_access_check',
  'summary' => 'iin_panels_extras_date_comparison_ctools_summary',
  'settings form' => 'iin_panels_extras_date_comparison_ctools_settings',
	//'required context' => new ctools_context_required(t('URL Data'), 'url_data'),
);

/**
 * Custom callback defined by 'callback' in the $plugin array.
 *
 * Check for access.
 */
function iin_panels_extras_date_comparison_ctools_access_check($conf, $context) {
  // Grab the setting for this given date and compare it to today's date
  $date = $conf['date'];
  $moment = $conf['moment'];
  $comparison = $conf['comparison'];

  if (strtotime($moment) < strtotime($date) && $comparison == 'before') {
    return TRUE;
  }
  if (strtotime($moment) <= strtotime($date) && $comparison == 'on_before') {
    return TRUE;
  }
  if (strtotime($date) === strtotime($moment) && $comparison == 'on') {
    return TRUE;
  }
  if (strtotime($moment) >= strtotime($date) && $comparison == 'on_after') {
    return TRUE;
  }
  if (strtotime($moment) > strtotime($date) && $comparison == 'after') {
    return TRUE;
  }
  return FALSE;
}

/**
 * Settings form for the 'date' access plugin.
 */
function iin_panels_extras_date_comparison_ctools_settings($form, &$form_state, $conf) {
  $form['settings']['date'] =  array(
    '#type' => 'date_popup',
    '#title' => 'Date',
    '#description' => t('Choose a date to compare to today\'s date or current time.'),
        '#default_value' => !empty($conf['date']) ? $conf['date'] : date("Y-m-d H:i:s"),
        '#date_type' => DATE_DATETIME,
        '#date_timezone' => date_default_timezone(),
        '#date_format' => 'm/d/Y h:i a',
        '#date_increment' => 1,
        '#date_year_range' => '-3:+3',
  );
  $form['settings']['comparison'] =  array(
    '#type' => 'select',
    '#title' => 'Comparison Type',
    '#description' => t('Choose how the date you chose compares to the chosen moment ("right now" or "today.")'),
    '#default_value' => !empty($conf['comparison']) ? $conf['comparison'] : 'on',
    '#options' => array(
      'before' => 'Before',
      'on_before' => 'On or Before',
      'on' => 'On',
      'on_after' => 'On or After',
      'after' => 'After'
    ),
  );
  $form['settings']['moment'] =  array(
    '#type' => 'select',
    '#title' => 'Moment',
    '#description' => t('Choose the moment to compare the date to. "Now" will look at the current minute, "Today" will match any time during today\'s date.'),
    '#default_value' => !empty($conf['moment']) ? $conf['moment'] : 'today',
    '#options' => array(
      'now' => 'Right Now',
      'today' => 'Today',
    ),
  );
  return $form;
}

/**
 * Provide a summary description showing what you choose as a param.
 */
function iin_panels_extras_date_comparison_ctools_summary($conf, $context) {
  return t('Date: ' . $conf['date']);
}
