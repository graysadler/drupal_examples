<?php
/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Confirmation Message'),
  'description' => t('Prints a Webform Confirmation Message.'),
  'category' => t('Miscellaneous'),
  'single' => TRUE,
  'content type' => 'confirmation_message',
);

/**
* Output function for the confirmation_message content type.
*/
function iin_panels_extras_confirmation_message_content_type_render($subtype, $conf, $panel_args, $context) {

  $pane = new stdClass();
  $pane->content = '';
  // similar data grab to the preprocess function in m7_webinar
  if (isset($_GET['sid'])) {
    $sid = check_plain($_GET['sid']);
    module_load_include('inc', 'webform', 'includes/webform.submissions');
    $subs = webform_get_submissions(array('sid' => $sid));
    $nid = $subs[$sid]->nid;
    $node = node_load($nid);
    $pane->content = token_replace($node->webform['confirmation']);
    $time = (_webform_get_component_key($node, 'StealthTime__c')) ? $subs[$sid]->data[_webform_get_component_key($node, 'StealthTime__c')]['value'][0] : '';
    $pane->content = str_replace('[global:stealth-time]', $time, $pane->content);
  }
  else {
    $pane->content = "No Submission Data Available";
  }

  $pane->content = '<div class="webform-confirmation">' . $pane->content . '</div>';
  return $pane;
}


/**
* Returns an edit form for the custom type.
*/

//function iin_panels_extras_confirmation_message_content_type_edit_form($form, &$form_state) {
//}

/**
* Returns an edit form for the custom type.
*/
//function iin_panels_extras_confirmation_message_content_type_edit_form_submit($form, &$form_state) {
//}

function iin_panels_extras_confirmation_message_content_type_admin_title($subtype, $conf, $context) {

	return t('Webform Confirmation Message.');

}
