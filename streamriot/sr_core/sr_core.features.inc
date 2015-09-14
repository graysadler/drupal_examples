<?php
/**
 * @file
 * sr_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sr_core_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function sr_core_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function sr_core_image_default_styles() {
  $styles = array();

  // Exported image style: about-us_staff.
  $styles['about-us_staff'] = array(
    'name' => 'about-us_staff',
    'label' => 'about-us staff',
    'effects' => array(
      12 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 280,
          'height' => 200,
        ),
        'weight' => -10,
      ),
    ),
  );

  // Exported image style: blog_popular.
  $styles['blog_popular'] = array(
    'name' => 'blog_popular',
    'label' => 'blog popular',
    'effects' => array(
      4 => array(
        'label' => 'Resize',
        'help' => 'Resizing will make images an exact set of dimensions. This may cause images to be stretched or shrunk disproportionately.',
        'effect callback' => 'image_resize_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_resize',
        'data' => array(
          'width' => 65,
          'height' => 45,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: bloglist.
  $styles['bloglist'] = array(
    'name' => 'bloglist',
    'label' => 'bloglist',
    'effects' => array(
      2 => array(
        'label' => 'Resize',
        'help' => 'Resizing will make images an exact set of dimensions. This may cause images to be stretched or shrunk disproportionately.',
        'effect callback' => 'image_resize_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_resize',
        'data' => array(
          'width' => 791,
          'height' => 322,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: blogside.
  $styles['blogside'] = array(
    'name' => 'blogside',
    'label' => 'blogside',
    'effects' => array(
      3 => array(
        'label' => 'Resize',
        'help' => 'Resizing will make images an exact set of dimensions. This may cause images to be stretched or shrunk disproportionately.',
        'effect callback' => 'image_resize_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_resize',
        'data' => array(
          'width' => 300,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: featured_blog.
  $styles['featured_blog'] = array(
    'name' => 'featured_blog',
    'label' => 'Featured Blog (278x158)',
    'effects' => array(
      10 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 278,
          'height' => 158,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: full-page-inner.
  $styles['full-page-inner'] = array(
    'name' => 'full-page-inner',
    'label' => 'Full-page-inner',
    'effects' => array(
      9 => array(
        'label' => 'Resize',
        'help' => 'Resizing will make images an exact set of dimensions. This may cause images to be stretched or shrunk disproportionately.',
        'effect callback' => 'image_resize_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_resize',
        'data' => array(
          'width' => 791,
          'height' => 322,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: home_staff.
  $styles['home_staff'] = array(
    'name' => 'home_staff',
    'label' => 'Home staff',
    'effects' => array(
      7 => array(
        'label' => 'Resize',
        'help' => 'Resizing will make images an exact set of dimensions. This may cause images to be stretched or shrunk disproportionately.',
        'effect callback' => 'image_resize_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_resize',
        'data' => array(
          'width' => 350,
          'height' => 360,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: multistream-term.
  $styles['multistream-term'] = array(
    'name' => 'multistream-term',
    'label' => 'multistream-term',
    'effects' => array(
      5 => array(
        'label' => 'Resize',
        'help' => 'Resizing will make images an exact set of dimensions. This may cause images to be stretched or shrunk disproportionately.',
        'effect callback' => 'image_resize_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_resize',
        'data' => array(
          'width' => 300,
          'height' => 166,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: stream-slider.
  $styles['stream-slider'] = array(
    'name' => 'stream-slider',
    'label' => 'stream-slider',
    'effects' => array(
      6 => array(
        'label' => 'Resize',
        'help' => 'Resizing will make images an exact set of dimensions. This may cause images to be stretched or shrunk disproportionately.',
        'effect callback' => 'image_resize_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_resize',
        'data' => array(
          'width' => 701,
          'height' => 385,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: userprofile12.
  $styles['userprofile12'] = array(
    'name' => 'userprofile12',
    'label' => 'userprofile12',
    'effects' => array(
      1 => array(
        'label' => 'Resize',
        'help' => 'Resizing will make images an exact set of dimensions. This may cause images to be stretched or shrunk disproportionately.',
        'effect callback' => 'image_resize_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_resize',
        'data' => array(
          'width' => 50,
          'height' => 50,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function sr_core_node_info() {
  $items = array(
    'help' => array(
      'name' => t('Help'),
      'base' => 'node_content',
      'description' => t('This content type contains the help and Frequently Asked question pages.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'staff' => array(
      'name' => t('Staff'),
      'base' => 'node_content',
      'description' => t('Enter the our staff and related information.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
