<?php

/**
 * @file
 * Model editing UI.
 *
 * We make very little use of the EntityAPI interface for this - preferring instead to use
 * views. That offers more flexibility to change a UI that will, more often than not,
 * be end-user facing.
 */

/**
 * UI controller.
 */
class StreamUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults. Main reason for doing this is that
   * parent class hook_menu() is optimized for entity type administration.
   */
  public function hook_menu() {
    
    $items = array();
    $id_count = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%' . $this->entityType;

    $items[$this->path] = array(
      'title' => 'Streams',
      'description' => 'Add edit and update streams.',
      'page callback' => 'system_admin_menu_block_page',
      'access arguments' => array('access administration pages'),
      'file path' => drupal_get_path('module', 'system'),
      'file' => 'system.admin.inc',
    );
    
    // Change the overview menu type for the list of models.
    $items[$this->path]['type'] = MENU_LOCAL_TASK;
    
    // Change the add page menu to multiple types of entities
    $items[$this->path . '/add'] = array(
      'title' => 'Add a stream',
      'description' => 'Add a new stream',
      'page callback'  => 'stream_add_page',
      'access callback'  => 'stream_access',
      'access arguments' => array('edit'),
      'type' => MENU_NORMAL_ITEM,
      'weight' => 20,
      'file' => 'stream.admin.inc',
      'file path' => drupal_get_path('module', 'stream')

    );
    
    // Add menu items to add each different type of entity.
    /*
    foreach (stream_get_providers() as $type) {
      $items[$this->path . '/add/' . $type->type] = array(
        'title' => 'Add ' . $type->label,
        'page callback' => 'stream_form_wrapper',
        'page arguments' => array(stream_create(array('type' => $type->type))),
        'access callback' => 'stream_access',
        'access arguments' => array('edit', 'edit ' . $type->type),
        'file' => 'stream.admin.inc',
        'file path' => drupal_get_path('module', $this->entityInfo['module'])
      );
    }
		*/
    // Loading and editing model entities
    $items[$this->path . '/stream/' . $wildcard] = array(
      'page callback' => 'stream_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'stream_access',
      'access arguments' => array('edit', $id_count + 1),
      'weight' => 0,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
      'file' => 'stream.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
    $items[$this->path . '/stream/' . $wildcard . '/edit'] = array(
      'title' => 'Edit',
      'type' => MENU_DEFAULT_LOCAL_TASK,
      'weight' => -10,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
    );
    
    $items[$this->path . '/stream/' . $wildcard . '/delete'] = array(
      'title' => 'Delete',
      'page callback' => 'stream_delete_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'stream_access',
      'access arguments' => array('edit', $id_count + 1),
      'type' => MENU_LOCAL_TASK,
      'context' => MENU_CONTEXT_INLINE,
      'weight' => 10,
      'file' => 'stream.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
    
    // Menu item for viewing models
    $items['stream/' . $wildcard] = array(
      //'title' => 'Title',
      'title callback' => 'stream_page_title',
      'title arguments' => array(1),
      'page callback' => 'stream_page_view',
      'page arguments' => array(1),
      'access callback' => 'stream_access',
      'access arguments' => array('view', 1),
      'type' => MENU_CALLBACK,
    );
    return $items;
  }
  
  
  /**
   * Create the markup for the add Model Entities page within the class
   * so it can easily be extended/overriden.
   */ 
  public function addPage() {
    $item = menu_get_item();
    $content = system_admin_menu_block($item);

    if (count($content) == 1) {
      $item = array_shift($content);
      drupal_goto($item['href']);
    }    
        
    return theme('stream_add_list', array('content' => $content));
  }
  
}


/**
 * Form callback wrapper: create or edit a model.
 *
 * @param $model
 *   The model object being edited by this form.
 *
 * @see model_edit_form()
 */
function stream_form_wrapper($stream) {
  // Add the breadcrumb for the form's location.
  stream_set_breadcrumb();
  return drupal_get_form('stream_edit_form', $stream);
}


/**
 * Form callback wrapper: delete a model.
 *
 * @param $model
 *   The model object being edited by this form.
 *
 * @see model_edit_form()
 */
function stream_delete_form_wrapper($stream) {
  // Add the breadcrumb for the form's location.
  //model_set_breadcrumb();
  return drupal_get_form('stream_delete_form', $stream);
}


/**
 * Form callback: create or edit a model.
 *
 * @param $model
 *   The model object to edit or for a create form an empty model object
 *     with only a model type defined.
 */
function stream_edit_form($form, &$form_state, $stream) {
  // Add the default field elements.
  $form['channel'] = array(
    '#type' => 'textfield',
    '#title' => t('Stream Channel'),
    '#default_value' => isset($stream->channel) ? $stream->channel : '',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -5,
  );
  
  // Add the field related form elements.
  $form_state['stream'] = $stream;
  field_attach_form('stream', $stream, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 400,
  );

  // We add the form's #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save stream'),
    '#submit' => $submit + array('stream_edit_form_submit'),
  );
  
  if (!empty($stream->channel)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete stream'),
      '#suffix' => l(t('Cancel'), 'admin/content/streams'),
      '#submit' => $submit + array('stream_form_submit_delete'),
      '#weight' => 45,
    );
  }

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'stream_edit_form_validate';
  return $form;
}


/**
 * Form API validate callback for the model form
 */
function stream_edit_form_validate(&$form, &$form_state) {
  $stream = $form_state['stream'];
  
  // Notify field widgets to validate their data.
  field_attach_form_validate('stream', $stream, $form, $form_state);
}


/**
 * Form API submit callback for the model form.
 * 
 * @todo remove hard-coded link
 */
function stream_edit_form_submit(&$form, &$form_state) {
  
  $stream = entity_ui_controller('stream')->entityFormSubmitBuildEntity($form, $form_state);
  // Save the model and go back to the list of models
  
  // Add in created and changed times.
  if ($stream->is_new = isset($stream->is_new) ? $stream->is_new : 0){
    $stream->created = time();
  }

  $stream->changed = time();
  
  $stream->save();
  $form_state['redirect'] = 'admin/content/streams';
}

/**
 * Form API submit callback for the delete button.
 * 
 * @todo Remove hard-coded path
 */
function stream_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/content/streams/stream/' . $form_state['stream']->stream_id . '/delete';
}


/**
 * Form callback: confirmation form for deleting a model.
 *
 * @param $model
 *   The model to delete
 *
 * @see confirm_form()
 */
function stream_delete_form($form, &$form_state, $stream) {
  $form_state['stream'] = $stream;

  $form['#submit'][] = 'streaml_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete stream %channel?', array('%channel' => $stream->channel)),
    'admin/content/streams/stream',
    '<p>' . t('This action cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );
  
  return $form;
}

/**
 * Submit callback for model_delete_form
 */
function stream_delete_form_submit($form, &$form_state) {
  $stream = $form_state['stream'];

  stream_delete($stream);

  drupal_set_message(t('The stream %channel has been deleted.', array('%channel' => $stream->channel)));
  watchdog('stream', 'Deleted stream %channel.', array('%channel' => $stream->channel));

  $form_state['redirect'] = 'admin/content/streams';
}



/**
 * Page to add Model Entities.
 *
 * @todo Pass this through a proper theme function
 */
function stream_add_page() {
  $controller = entity_ui_controller('stream');
  return $controller->addPage();
}


/**
 * Displays the list of available model types for model creation.
 *
 * @ingroup themeable
 */
function theme_stream_add_list($variables) {
  $content = $variables['content'];
  $output = '';
  if ($content) {
    $output = '<dl class="stream-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    if (user_access('administer streams')) {
      $output = '<p>' . t('Stream Entities cannot be added because you have not created any stream types yet. Go to the <a href="@create-stream">stream creation page</a> to add a new stream.', array('@create-stream' => url('admin/structure/stream/add'))) . '</p>';
    }
    else {
      $output = '<p>' . t('No streams have been created yet for you to use.') . '</p>';
    }
  }

  return $output;
}

/**
 * Sets the breadcrumb for administrative model pages.
 */
function stream_set_breadcrumb() {
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('Content'), 'admin/content'),
    l(t('Streams'), 'admin/content/streams'),
  );

  drupal_set_breadcrumb($breadcrumb);
}



