<?php

/**
 * @file
 * Model type editing UI.
 */

/**
 * UI controller.
 */
class StreamProviderUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
		$items[$this->path]['description'] = 'Manage stream providers, including adding
		and removing fields and the display of fields.';
    return $items;
  }
}

/**
 * Generates the model type editing form.
 */
function stream_provider_form($form, &$form_state, $provider, $op = 'edit') {

  if ($op == 'clone') {
    $provider->label .= ' (cloned)';
    $provider->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $provider->label,
    '#description' => t('The human-readable name of this model type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  // Machine-readable type name.
  $form['provider'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($provider->provider) ? $provider->provider : '',
    '#maxlength' => 32,
//    '#disabled' => $provider->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'stream_get_providers',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this model type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Provider'),
    '#weight' => 40,
  );

  //Locking not supported yet
  /*if (!$provider->isLocked() && $op != 'add') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete model type'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('stream_provider_form_submit_delete')
    );
  }*/
  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function stream_provider_form_submit(&$form, &$form_state) {
  $provider = entity_ui_form_submit_build_entity($form, $form_state);
  $provider->save();
  $form_state['redirect'] = 'admin/structure/stream_providers';
}

/**
 * Form API submit callback for the delete button.
 */
function stream_provider_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/stream_providers/manage/' . $form_state['stream_provider']->type . '/delete';
}
