<?php
/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Expanding List'),
  'description' => t('Bring in a List that can expand and contract.'),
  'category' => t('Atomic Elements'),
  'single' => TRUE,
  'content type' => 'atom_expanding_list',
  'settings form' => 'iin_panels_extras_atom_expanding_list_content_type_edit_form',
);

/**
 * Output function for the '[content_type]' content type.
 */
function iin_panels_extras_atom_expanding_list_content_type_render($subtype, $conf, $panel_args, $context) {
  $output = '<h1>nope</h1>';
  if (!empty($conf['list_node'])) {
    $node = node_load(intval($conf['list_node']));
    $output = node_view($node, 'full content');
  }
  $block = new stdClass();
  $block->content = $output;
  return $block;
}


/**
 * Returns an edit form for the custom type.
 */

function iin_panels_extras_atom_expanding_list_content_type_edit_form($form, &$form_state) {

  $list_nid = !empty($form_state['conf']['list_node']) ? $form_state['conf']['list_node'] : '';
  $form['settings']['list_node'] = array(
    '#title' => t('Expanding List'),
    '#markup'=> '<h2>markup?</h2>',
    '#description' => t('Find Your List Node by typing its title, or just enter its node id. You must first create a list node.'),
    '#type' => 'textfield',
    '#autocomplete_path' => 'iin-panels-extras/atom-expanding-list-autocomplete',
    '#default_value' => $list_nid,
  );

  return $form;
}

/**
 * Validation Callback
 */
function iin_panels_extras_atom_expanding_list_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf']['list_node'] = $form_state['values']['list_node'];

}

/**
 * Validation Callback
 */
function iin_panels_extras_atom_expanding_list_content_type_edit_form_validate($form, &$form_state) {

  if (!is_int($form_state['values']['list_node'])) {
    $node = node_load($form_state['values']['list_node']);
    if (empty($node->nid)) {
      form_set_error('list_node', t('Enter a Node ID, Please.'));
    }
  }

}

function iin_panels_extras_atom_expanding_list_content_type_admin_title($subtype, $conf, $context) {
  return t('Expanding List');
}
