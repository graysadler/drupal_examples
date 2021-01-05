<?php
/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Copyright Notice'),
  'description' => t('Simple Copyright Notice Pane.'),
  'category' => t('Miscellaneous'),
  'single' => TRUE,
  'content type' => 'copyright_widget',
);
 
/**
* Output function for the '[content_type]' content type.
*/
function iin_panels_extras_copyright_widget_content_type_render($subtype, $conf, $panel_args, $context) {
	
  //kpr($conf);	
  $block = new stdClass();
	$block->content = '<p class="obj-center">&copy ' . $conf['custom_year'] . ' Integrative Nutrition Inc.</p>'; 
        
  return $block;
}

 
/**
* Returns an edit form for the custom type.
*/

function iin_panels_extras_copyright_widget_content_type_edit_form($form, &$form_state) {
	
	$conf = $form_state['conf'];
	
	//set an initial default
	if($conf['custom_year']) { $year = $conf['custom_year']; }
	else {$year = date("Y"); }
	
	
	$form['custom_year'] = array(
    '#title' => t('Custom Copyright Year'),
    '#description' => t('Add a custom copyright year string (such as 2008-2012). Use the token [current:year] to place the current year in your string.'),
    '#type' => 'textfield',
    '#default_value' => $year,
    '#required' => FALSE,
  );

	return $form;
}
 
/**
* Returns an edit form for the custom type.
*/
function iin_panels_extras_copyright_widget_content_type_edit_form_submit($form, &$form_state) {

		$form_state['conf']['custom_year'] = str_replace('[current:year]', date("Y"), $form_state['values']['custom_year']);

}

function iin_panels_extras_copyright_widget_content_type_admin_title($subtype, $conf, $context) {
	
	return t('Custom copyright pane');

}