<?php
 
// Plugin definition
$plugin = array(
  // Title and description of the plugin
  'title' => t('Custom Background'),
  'description' => t('Background color and/or image'),
  // Define a theme function for this plugin
  'render pane' => 'background_render_pane',
  'render region' => 'background_render_region',
    //
  // We'll be using a template for rendering
  /*
  'hook theme' => array(
    'pane_bg_background' => array(
      'variables' => array(
        'content' => NULL,
        'style_attributes' => array(),
        'title' => NULL,
      ),
      'path' => drupal_get_path('module', 'pane_bg') . '/plugins/styles',
      'template' => 'pane-background',
    ),
  ),*/
  // This defines the settings form for the plugin
  'pane settings form' => 'background_settings_form',
  'settings form' => 'background_settings_form',
    
    //'render region' => 'panels_extra_styles_wrapper_render_region',
    //'render pane' => 'panels_extra_styles_wrapper_render_pane',
    //'settings form' => 'panels_extra_styles_wrapper_element_region_settings_form',
    //'pane settings form' => 'panels_extra_styles_wrapper_element_pane_settings_form',    
);

/**
 * Settings form callback.
 */
function background_settings_form($settings) {
  /*
  $form['image'] = array(
      '#type' => 'textfield',
      '#title' => t('Image field'),
      '#description' => t('Enter the image field for the background image. You may use substitutions in this field. E.g. for the default image field attached to articles use "%node:field_image"'),
      '#required' => TRUE,
      '#default_value' => (isset($form['image'])) ? $form['image'] : '',
  );
  */
  
  if (!empty($settings['image'])) {
    if (is_array($settings['image'])) {
      $fid = $settings['image']['fid'];
    } else {
      $fid = $settings['image'];
    }
  }
  
  $form['image'] = array(
    '#type' => 'media',
    '#tree' => TRUE, // Required
    '#title' => t('Background Image'),
    '#description' => t('Allowed formats: PNG, JPG'),
    '#required' => FALSE,
    //'#input' => TRUE,
    '#extended' => TRUE,
    '#media_options' => array(
        'global' => array(
            //'schemes' => array('http'),
            //'types' => array('image'),
            //'file_extensions' => 'png jpg', // File extensions
            'enabledPlugins' => array(
                'upload',
                'media_default--media_browser_my_files',
                'media_default--media_browser_1',
                'media_browser_plus--media_browser_my_files',
                'media_browser_plus--media_browser_thumbnails',                
            ),
        ),
    ),
    '#default_value' => array('fid' => $fid),
  );
  /*
  $form['image_style'] = array(
      '#type' => 'select',
      '#title' => t('Image Style'),
      '#description' => t('Choose the appropriate image style for the background image.'),
      '#options' => image_style_options(),
      '#default_value' => (isset($form['image_style'])) ? $form['image_style'] : '',
  );
  */
  
  $form['id'] = array(
      '#type' => 'textfield',
      '#title' => t('ID/Anchor (#)'),
      '#description' => t('Enter an ID/Anchor for this block.'),
      '#default_value' => (isset($settings['id'])) ? $settings['id'] : '',
  );
    
  $form['class'] = array(
      '#type' => 'textfield',
      '#title' => t('CSS Classes'),
      '#description' => t('Enter CSS classes for this style. Separate multiple classes by spaces.'),
      '#default_value' => (isset($settings['class'])) ? $settings['class'] : '',
  );
  
  $form['bg_color'] = array(
      '#type' => 'jquery_colorpicker',
      '#title' => t('Background Color'),
      '#default_value' => isset($settings['bg_color']) ? $settings['bg_color'] : 'FFFFFF',
  );
  
  $form['min_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Minimum Height'),
    '#description' => t('Enter the minimum height (in px) that this section should be.'),
    '#default_value' => isset($settings['min_height']) ? $settings['min_height'] : '200',
    '#element_validate' => array('element_validate_number'),
  );

  $form['fore_color'] = array(
      '#type' => 'select',
      '#title' => t('Foreground Color'),
      '#default_value' => isset($settings['fore_color']) ? $settings['fore_color'] : 'white',
      '#options' => array('white'=>t('White'), 'gray'=>t('Gray'))
  );  

  $form['border_style'] = array(
      '#type' => 'select',
      '#title' => t('Border Style'),
      '#options' => array('' => t('None'), 'shadow' => t('Shadow')),
      '#default_value' => isset($settings['border_style']) ? $settings['border_style'] : '',
  );  
    
  $form['#attached']['css'] = array(
      drupal_get_path('module', 'pane_bg') . '/plugisn/styles/background.css',
  );

  $form['#submit'][] = 'background_settings_form_submit';
  return $form;
}

function background_settings_form_submit(&$form, &$form_state) {
  
}

/**
 * Render callback.
 */
function theme_background_render_pane($vars) {
 
  $attr = array('style'=>'', 'classes_array'=>array());
  
  if (!empty($vars['settings']['image'])) {
    if (is_array($vars['settings']['image'])) {
      $fid = $vars['settings']['image']['fid'];
    } else {
      $fid = $vars['settings']['image'];      
    }
    if ($file = file_load($fid)) {
      $image_url = file_create_url($file->uri);
      $attr['style'] = 'background-image: url(' . $image_url . ');background-size: cover;';
    }
  }  

  // Add our classes to the attrubutes array, if any defined
  if ($vars['settings']['class']) {
    $attr['classes_array'] = explode(' ', $vars['settings']['class']);
  }
  
  // Add our id to the attrubutes array, if any defined
  if ($vars['settings']['id']) {
    $id = explode(' ', $vars['settings']['id']);
    $attr['id'] = $id[0];
  }  
  
  //$style_attributes['class'][] = 'panel-pane';
  $attr['classes_array'][] = 'pane-bg';
  
  if (!empty($vars['settings']['min_height'])) {
    $attr['style'] .= ' min-height:' . $vars['settings']['min_height'] . 'px;';
  }

  $title = '';
  
  if (!empty($vars['content']->subject)) {
    $title =  $vars['content']->subject;
  } elseif (!empty($vars['content']->title)) {
    $title = $vars['content']->title;
  }
  
  if (!empty($vars['settings']['bg_color'])) {
    $attr['style'] .= ' background-color: #' . $vars['settings']['bg_color'] . ';';
    $attr['classes_array'][] = 'has-color-bg';
  }
  
  if (!empty($vars['settings']['fore_color'])) {
    $attr['classes_array'][] = 'fore-color-' . $vars['settings']['fore_color'];
  }  
  
  if (!empty($vars['settings']['border_style'])) {
    $attr['classes_array'][] = 'pane-shadow';
  }
    
  $vars['pane_bg'] = $attr;
  
  $vars['title'] = $title;
  
  return theme('panels_pane', $vars);  
}

/**
 * Render callback.
 */
function theme_background_render_region($vars) {
  $attr = array('style'=>'', 'class'=>array());
  
  if (!empty($vars['settings']['image'])) {
    if (is_array($vars['settings']['image'])) {
      $fid = $vars['settings']['image']['fid'];
    } else {
      $fid = $vars['settings']['image'];      
    }
    if ($file = file_load($fid)) {
      $image_url = file_create_url($file->uri);
      $attr['style'] = 'background-image: url(' . $image_url . ');background-size: cover;';
    }
  }  

  // Add our classes to the attrubutes array, if any defined
  if ($vars['settings']['class']) {
    $attr['class'] = explode(' ', $vars['settings']['class']);
  }
  
  // Add our id to the attrubutes array, if any defined
  if ($vars['settings']['id']) {
    $id = explode(' ', $vars['settings']['id']);
    $attr['id'] = $id[0];
  }  
  
  //$style_attributes['class'][] = 'panel-pane';
  $attr['class'][] = 'pane-bg';
  
  if (!empty($vars['settings']['min_height'])) {
    $attr['style'] .= 'min-height:' . $vars['settings']['min_height'] . 'px;';
  }
  
  if (!empty($vars['settings']['bg_color'])) {
    $attr['style'] .= 'background-color: #' . $vars['settings']['bg_color'] . ';';
    $attr['class'][] = 'has-color-bg';
  }
  
  if (!empty($vars['settings']['fore_color'])) {
    $attr['style'] .= 'color: #' . $vars['settings']['fore_color'].';';
    $attr['class'][] = 'has-color-fore';
  }  
  
  $output = theme('panels_default_style_render_region', $vars);  

  if (!empty($vars['settings']['border_style'])) {
    $attr['class'][] = 'region-shadow';    
    $attr['class'][] = 'container';    
    $output = '<div class="container">' . $output . '</div>';
  }
    
  $output = '<div'. drupal_attributes($attr)  . '>' . $output . '</div>';
 
  return $output;
}