<?php
/**
 * @file
 * IIN extra panels region attribute panels style.
 */

// Plugin definition.
$plugin = array(
  'title'              => t('Custom Region Styles'),
  'description'        => t('Add custom attributes per region.'),

  'render region'      => 'region_class_panels_region_class_region',
  'settings form'      => 'region_class_panels_region_class_region_settings_form',

  'hook theme' => array(
    'region_class_panels_clean_region' => array(
      'variables' => array(
        'region_classes' => '',
      ),
      'path' => drupal_get_path('module', 'iin_panels_extras') . '/plugins/styles/region_class',
      'template' => 'region_class_panels_clean_region',
    ),
  ),
);

/**
 * Form constructor for the region settings form.
 *
 * You see this when you click on the gear in the top-left of a region, click
 * "Change" under "Style" and choose "Custom region classes"; or when you click
 * "Display settings" on the panel itself, click "Change" under "Style" and
 * choose "Custom region classes".
 *
 * @ingroup forms
 */
function region_class_panels_region_class_region_settings_form($style_settings) {
  $form = array();
  
  $form['region_class'] = array(
    '#type' => 'fieldset',
    '#title' => t('Custom Region Styles'),
    '#weight' => 0,
  );

  $form['region_class']['region_bg_images'] = array(
    '#type' => 'radios',
    '#weight' => -1,
    '#required' => TRUE,
    '#default_value' => !empty($style_settings['region_class']['region_bg_images']) ? $style_settings['region_class']['region_bg_images'] : 'class',
    '#options' => array(
      'class' => t('Apply an existing style.'),
      'image' => t('Set an image.'),
    ),
  );
  $form['region_class']['image_bg'] = array(
    '#type' => 'fieldset',
    '#title' => t('Custom Background Image'),
    '#weight' => 0,
    '#description' => t('Set up to 3 background images to be used as a background for this region. The image needs to be enabled in its edit form to show up in the list of possible selections. Go to admin/content/files to browse the current list.'),
    '#states' => array(
      'visible' => array(
        ':input[name="settings[region_class][region_bg_images]"]' => array('value' => 'image'),
      ),
    ),
  );

  // background position
  $positions = array(
      'top left' => t('Top Left'),
      'top center' => t('Top Center'),
      'top right' => t('Top Right'),
      'center left' => t('Middle Left'),
      'center center' => t('Middle Center'),
      'center right' => t('Middle Right'),
      'bottom left' => t('Bottom Left'),
      'bottom center' => t('Bottom Center'),
      'bottom right' => t('Bottom Right'),
  );
  $pos_default = variable_get('region_class_bg_image_position_default', 'top center');

  $prefix = '<fieldset style="padding:1em;">';
  $suffix = '</fieldset>';
  
  $size_default = variable_get('region_class_bg_size_default', 'cover');
  
  //legacy images are not in an array, so make sure they are compatible with current structure
  if (is_array($style_settings['region_class']['image_bg'])) {
    foreach ($style_settings['region_class']['image_bg'] as $key => $tmp_settings) {
      if (!is_array($tmp_settings)) {
        $image_settings[$key] = array('image' => $tmp_settings, 'position' => $pos_default, 'size' => $size_default);
      } else {
        $image_settings[$key] = $tmp_settings;
      }
    }
  }
  
  $media_element = array(
      '#type'          => 'media',
      '#theme'         => 'media_widget', // Without that, you only get text input
      '#media_options' => array(
          'global' => array(
              'file_directory'  => 'headers',
              'enabledPlugins'  => array( // Not needed if you want to enable all the plugins
                  'upload',
                  'media_default--media_browser_my_files'
              ),
              'file_extensions' => 'png gif jpg jpeg',
              'max_filesize'    => '100 MB',
              'uri_scheme'      => 'public',
              'types'           => array('image'),
              'schemes'         => array(
                  'public' => 'public',
              ),
          ),
      ),
  );
  
  // Desktop
  $form['region_class']['image_bg']['region_bg_desktop']['#prefix'] = $prefix;
  $form['region_class']['image_bg']['region_bg_desktop']['#suffix'] = $suffix;
  
  $form['region_class']['image_bg']['region_bg_desktop']['image'] = $media_element;
  $form['region_class']['image_bg']['region_bg_desktop']['image']['#title'] = t('Desktop');  
  $form['region_class']['image_bg']['region_bg_desktop']['image']['#description'] = t('Add this image as the background for this region, desktop width (>1300px).');
  $default = $image_settings['region_bg_desktop']['image'];
  
  // Legacy filename needs to be replaced with fid
  if ($default && !is_numeric($default)) {
    if ($files = _file_load_by_name($default)) {
      $file = array_shift($files);
      $default = $file->fid;
    }
  }
      
  $form['region_class']['image_bg']['region_bg_desktop']['image']['#default_value'] = $default;
                      
  // Desktop Position
  $form['region_class']['image_bg']['region_bg_desktop']['position'] = array(
    '#type' => 'select',
    '#title' => t('Image Position'),
    '#options' => $positions,
    '#description' => t('Image positioning for Desktop Background image'),
    '#default_value' => !empty($image_settings['region_bg_desktop']['position']) ? $image_settings['region_bg_desktop']['position'] : $pos_default,
  );

  
  $form['region_class']['image_bg']['region_bg_desktop']['size'] = array(
      '#type' => 'radios',
      '#title' => t('Contain Image'),
      '#options' => array('contain' => t('Yes'), 'cover' => t('No')),
      '#description' => t('If selected, the image will not stretch to the width of it\'s container.'),
      '#default_value' => !empty($image_settings['region_bg_desktop']['size']) ? $image_settings['region_bg_desktop']['size'] : $size_default,
  );  
  
  // Tablet  
  $form['region_class']['image_bg']['region_bg_tablet']['#prefix'] = $prefix;
  $form['region_class']['image_bg']['region_bg_tablet']['#suffix'] = $suffix;
  
  $form['region_class']['image_bg']['region_bg_tablet']['image'] = $media_element;
  $form['region_class']['image_bg']['region_bg_tablet']['image']['#title'] = t('Tablet');
  $form['region_class']['image_bg']['region_bg_tablet']['image']['#description'] = t('Add this image as the background for this region, desktop width (>768 and <1300px).');
  $default = $image_settings['region_bg_tablet']['image'];
  
  // Legacy filename needs to be replaced with fid
  if ($default && !is_numeric($default)) {
    if ($files = _file_load_by_name($default)) {
      $file = array_shift($files);
      $default = $file->fid;
    }
  }
  $form['region_class']['image_bg']['region_bg_tablet']['image']['#default_value'] = $default;        
        
  // Tablet position
  $form['region_class']['image_bg']['region_bg_tablet']['position'] = array(
    '#type' => 'select',
    '#title' => t('Image Position'),
    '#options' => $positions,
    '#description' => t('Image positioning for Tablet Background image'),
    '#default_value' => !empty($image_settings['region_bg_tablet']['position']) ? $image_settings['region_bg_tablet']['position'] : $default,
  );
  $form['region_class']['image_bg']['region_bg_tablet']['size'] = array(
      '#type' => 'radios',
      '#title' => t('Contain Image'),
      '#options' => array('contain' => t('Yes'), 'cover' => t('No')),
      '#description' => t('If selected, the image will not stretch to the width of it\'s container.'),
      '#default_value' => !empty($image_settings['region_bg_tablet']['size']) ? $image_settings['region_bg_tablet']['size'] : $size_default,
  );
  
  
  // Mobile
  $form['region_class']['image_bg']['region_bg_mobile']['#prefix'] = $prefix;
  $form['region_class']['image_bg']['region_bg_mobile']['#suffix'] = $suffix;
  
  $form['region_class']['image_bg']['region_bg_mobile']['image'] = $media_element;
  $form['region_class']['image_bg']['region_bg_mobile']['image']['#title'] = t('Mobile');
  $form['region_class']['image_bg']['region_bg_mobile']['image']['#description'] = t('Add this image as the background for this region, desktop width (>479 and <768px).');
  $default = $image_settings['region_bg_mobile']['image'];
  
  // Legacy filename needs to be replaced with fid
  if ($default && !is_numeric($default)) {
    if ($files = _file_load_by_name($default)) {
      $file = array_shift($files);
      $default = $file->fid;
    }
  }
  $form['region_class']['image_bg']['region_bg_mobile']['image']['#default_value'] = $default;  

  // Mobile position
  $form['region_class']['image_bg']['region_bg_mobile']['position'] = array(
    '#type' => 'select',
    '#title' => t('Image Position'),
    '#options' => $positions,
    '#description' => t('Image positioning for Mobile Background image'),
    '#default_value' => !empty($image_settings['region_bg_mobile']['position']) ? $image_settings['region_bg_mobile']['position'] : $default,
  );
  
  $form['region_class']['image_bg']['region_bg_mobile']['size'] = array(
      '#type' => 'radios',
      '#title' => t('Contain Image'),
      '#options' => array('contain' => t('Yes'), 'cover' => t('No')),
      '#description' => t('If selected, the image will not stretch to the width of it\'s container.'),
      '#default_value' => !empty($image_settings['region_bg_mobile']['size']) ? $image_settings['region_bg_mobile']['size'] : $size_default,
  );
  
  
  // general classes to be added to provide styles and/or images as backgrounds for the full-width regions
  $options = array(
    '' => t('None'),
    'background-gray' => t('Gray'),
    'background-about-header' => t('About Header (image)'),
    'background-about-video' => t('About Video (image)'),
    'background-aboutus-corevalues' => t('About Core Values (image)'),
    'background-contact-header' => t('Contact Header (image)'),
    'background-curric-crowd' => t('Curriculum Crowd (image)'),
    'background-curric-header' => t('Curriculum Header (image)'),
    'background-curric-pc' => t('Curriculum PC (image)'),
    'background-green-hills' => t('Green Hills (image)'),
    'background-hc-header' => t('Health Coaching Header (image)'),
    'background-hc1' => t('Health Coaching 1 (image)'),
    'background-hc2' => t('Health Coaching 2 (image)'),
    'background-heart-apple' => t('Heart Apple (image)'),
    'background-home-sky' => t('Home Sky (image)'),
    'background-info-header' => t('Info Header (image)'),
    'background-plg-apple' => t('Paid Lead Gen Apple (image)'),
    'background-search-header' => t('Search Header (image)'),
    'background-world-map' => t('World Map (image)'),
    'video-modal-box-3-up'  => t('Video Modal Boxes 3-up (style)'), //TODO! this needs to just be broken out into its own custom pane
    'container-fluid'  => t('Full Width Region'),
  );
  $form['region_class']['region_classes'] = array(
    '#type' => 'select',
    '#title' => t('Existing Region Classes'),
    '#weight' => 1,
    '#options' => $options,
    '#description' => t('Styles as classes to set on the region wrapper that appear on some of pages already.'),
    '#default_value' => $style_settings['region_class']['region_classes'],
    '#states' => array(
      'visible' => array(
        ':input[name="settings[region_class][region_bg_images]"]' => array('value' => 'class'),
      ),
    ),
  );
  $form['region_class']['region_anchor'] = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#weight' => 2,
    '#maxlength' => 128,
    '#title' => t('Region Anchor Link'),
    '#description' => t('Optional anchor link name. If a menu item needs to #hash link to this section of the page, enter a link name here.'),
    '#default_value' => $style_settings['region_class']['region_anchor'],
  );
  $form['region_class']['region_full_width'] = array(
    '#type' => 'checkbox',
    '#weight' => 3,
    '#title' => t('Full Width Container'),
    '#description' => t('Make the container within this region stretch full-width.'),
    '#default_value' => $style_settings['region_class']['region_full_width'],
  );
  // Color picker

  // Set some defaults
  $color_form = array();
  $color_form_state = array();
  $field['field_name'] = 'region_color_bg';
  $field['settings']['default_colors'] = variable_get('iin_default_colors', '');
  $instance['widget']['type'] = 'color_field_default_widget';
  $instance['label'] = t('Background Color');
  $delta = 0;
  $element['#delta'] = $delta;
  $element['#description'] = '';
  $items = array();
  //$items[$delta]['rgb'] = $settings['region_color_bg']['rgb'] ? $settings['region_color_bg']['rgb'] : '';
  $form['region_class']['region_color_bg'] = color_field_field_widget_form($color_form, $color_form_state, $field, $instance, LANGUAGE_NONE, $items, $delta, $element);

  // Vertical alignment
  $form['region_class']['vertical_align'] = array(
      '#type' => 'checkbox',
      '#default_value' => $new ? TRUE : $style_settings['region_class']['vertical_align'],
      '#title' => t('Vertically Align Region Content'),
  );
  return $form;
}

/**
 * Returns HTML for a region-class-style-classes region.
 *
 * @ingroup themeable
 */
function theme_region_class_panels_region_class_region(&$vars) {
  if (!$node = menu_get_object()) {
    // Panels IPE may be at play, if so menu_get_object() does not return correct node
    // Let's see if we can grab the right node, other wise bail
    if (substr($_GET['q'], 0 , 11) == 'panels/ajax') {
      if (!empty($_REQUEST['destination'])) {
        $dest = $_REQUEST['destination'];
        if (arg(0, $dest) == 'node' && is_numeric(arg(1, $dest))) {
          $node = node_load(arg(1, $dest));
        }
      }
    }
    
    if ($node) {
      $node_wrapper = entity_metadata_wrapper('node', $node);
    }
  }
  
  $region_classes = array();
  if (!empty($vars['settings']['region_class']['region_bg_images']) && $vars['settings']['region_class']['region_bg_images'] == 'image') {
    $region_classes[] = 'region-bg-img';
    foreach ($vars['settings'] as $row => $data) {
      if (!empty($data['image_bg'])) {
        // look for each of the widths
        $filename_d  = '';
        $filename_t  = '';
        $filename_m  = '';
        $filename_xl = '';

        foreach ($data['image_bg'] as $media_query => $image_settings) {
          if (!is_array($image_settings)) {
            $filename = $image_settings;
            $image_settings = array();
            $image_settings['image'] = $filename;
            $image_settings['position'] = variable_get('region_class_bg_image_position_default', 'top center');
          }
          
          $filename = $image_settings['image'];
          
          // New way is to save the fid
          if (is_numeric($filename)) {
            //$files = _file_load_by_name($filename);
            //$file = array_shift($files);
            $file = file_load($filename);
            $filename = $file->uri;
          }
          
          if ($media_query == 'region_bg_desktop' && $filename != 'none') {
            $image_bg_settings['desktop']['position'] = $image_settings['position'];
            $image_bg_settings['desktop']['size'] = $image_settings['size'];
            
            if ($node && $filename == 'node_header_desktop') {
              if ($node_wrapper->field_header_img_desktop->value()) {
                $fid = $node_wrapper->field_header_img_desktop->value()->fid;
                $file = file_load($fid);
                $filename_d = $file->filename;
              }
            } else {
              $filename_d = $filename;
            }
            
          }
          if ($media_query == 'region_bg_tablet' && $filename != 'none') {
            $image_bg_settings['tablet']['position'] = $image_settings['position'];
            $image_bg_settings['tablet']['size'] = $image_settings['size'];
            
            if ($node && $filename == 'node_header_tablet') {
              if ($node_wrapper->field_header_img_tablet->value()) {
                $fid = $node->field_header_img_tablet->value()->fid;
                $file = file_load($fid);
                $filename_t = $file->filename;
              }
            } else {
              $filename_t = $filename;
            }
          }
          if ($media_query == 'region_bg_mobile' && $filename != 'none') {
            $image_bg_settings['mobile']['position'] = $image_settings['position'];
            $image_bg_settings['mobile']['size'] = $image_settings['size'];
            
            if ($node && $filename == 'node_header_mobile') {
              if ($node_wrapper->field_header_img_mobile->value()) {
                $fid = $node->field_header_img_mobile->value()->fid;
                $file = file_load($fid);
                $filename_m = $file->filename;
              }
            } else {
              $filename_m = $filename;
            }
          }
        }
      }
    }
  }
  $region_id = $vars['region_id'];
  // if we have at least one of these set, go for it, assuming it's our newer custom theme and the function exists...
  if (function_exists('region_custom_bg_style') && (!empty($filename_d) || !empty($filename_m) || !empty($filename_t) || !empty($filename_xl)) && !empty($region_id)) {
    drupal_add_css(region_custom_bg_style($vars['region_id'], $filename_d, $filename_m, $filename_t, $filename_xl, $image_bg_settings), 'inline');
  }

  $panes = "";
  // Gather the content
  foreach ($vars['panes'] as $pane) {
    $panes .= $pane;
  }
  // Don't output anything if there is nothing in the region.
  if (empty($vars['display']->panels[$region_id])) {
    return theme('region_class_panels_clean_region', array(
      'region_classes' => 'hidden',
      'panes' => $panes,
    ));
  }
  
  return theme('region_class_panels_clean_region', array(
    //'region_classes' => $region_classes,  
    'panes' => $panes
  ));
}
