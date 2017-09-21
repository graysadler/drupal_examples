<?php
/**
 * @file
 * IIN extra panels pane attribute panels style.
 */

// Plugin definition.
$plugin = array(
  'title'              => t('Custom Pane Styles'),
  'description'        => t('Add custom attributes per pane.'),
  'render pane'        => 'pane_class_panels_pane_class',
  'pane settings form' => 'pane_class_panels_pane_class_settings_form',
);

/**
 * Form constructor for the pane settings form.
 *
 * You see this when you click on the gear in the top-left of a pane, click
 * "Change" under "Style" and choose "Custom pane classes"; or when you click
 * "Display settings" on the panel itself, click "Change" under "Style" and
 * choose "Custom pane classes".
 */
function pane_class_panels_pane_class_settings_form($settings) {
  $form = array();
  $new = count($settings) ? FALSE : TRUE;
  
  $form['align'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content Alignment'),  
  );
  $form['align']['text_align_center'] = array(
    '#type' => 'checkbox',
    '#default_value' => $new ? FALSE : $settings['align']['text_align_center'],
    '#title' => t('Center Content (text-align)'),    
  );
  $form['align']['vertical_align'] = array(
    '#type' => 'checkbox',
    '#default_value' => $new ? TRUE : $settings['align']['vertical_align'],
    '#title' => t('Vertically Align Content'),    
  );
  $form['align']['vertical_align_min'] = array(
      '#type' => 'fieldset',
      '#title' => t('Pane Height'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
  );
  
  // Grab breakpoints from variable in case we want to change in the future
  $breakpoints = variable_get('pane_class_breakpoints', 
      array(
          'Mobile' => '@media only screen and (max-width: 767px)', 
          'Tablet' => '@media only screen and (min-width: 768px)', 
          'Desktop' => '@media only screen and (min-width: 1200px)')
      );
  
  foreach ($breakpoints as $key => $breakpoint) {
    $default = $new ? ($key == 'Mobile' ? 250 : 350) : $settings['align']['vertical_align_min'][$key];
    $form['align']['vertical_align_min'][$key] = array(
        '#type' => 'textfield',
        '#size' => 10,      
        '#element_validate' => array('element_validate_number'),
        '#default_value' => $default,
        '#title' => $key . ' Minimum Height (in pixels)',
        '#description' => 'Enter a numerical value for the minimum acceptable height of this pane as viewed on ' . $key . '. This is typically left blank except for header region page title components. Mobile headers are typically 250 and desktop and tablet are 350.',
    );  
  }
  
  return $form;
}

/**
 * Preprocesses a pane-class pane before sending through normal pane theme rendering.
 */
function theme_pane_class_panels_pane_class($vars) {
  $settings = $vars['settings'];

  // If pane is in head and we want to vertically align, check the min height
  if ($vars['pane']->panel == 'head' && $settings['align']['vertical_align']) {
    // Apply some min heights in case the user doesn't
    if (empty($settings['align']['vertical_align_min']['Mobile'])) {
      $settings['align']['vertical_align_min']['Mobile'] = 250;
    }
    if (empty($settings['align']['vertical_align_min']['Tablet'])) {
      $settings['align']['vertical_align_min']['Tablet'] = 350;
    }
    if (empty($settings['align']['vertical_align_min']['Desktop'])) {
      $settings['align']['vertical_align_min']['Desktop'] = 350;
    }
  }
  // Assign an ID if we need to apply some styles
  $id = !empty($vars['content']->css_id) ? $vars['content']->css_id : 'pane-class-' . $vars['pane']->pid;
  $vars['content']->css_id = $id;
  
  // Initialize the css classes if empty
  $vars['content']->css_class = empty($vars['content']->css_class) ? '' : $vars['content']->css_class;

  // Add text-center class if needed
  if (!empty($settings['align']['text_align_center'])) {
    $vars['content']->css_class .= 'text-center';    
  }
  
  // Add vertical-alignment structure if needed
  if (!empty($settings['align']['vertical_align'])) {    
    $vars['content']->content = '<div class="flex-va"><div class="flex-va-item">' . $vars['content']->content . '</div></div>';
    
    $breakpoints = variable_get('pane_class_breakpoints', array('Mobile' => '@media only screen and (max-width: 767px)', 'Tablet' => '@media only screen and (min-width: 768px)', 'Desktop' => '@media only screen and (min-width: 1200px)'));
    $css = '';
    // Apply min heights to each breakpoint
    foreach ($settings['align']['vertical_align_min'] as $key => $value) {
      if ($value) {
        $css .= $breakpoints[$key] . ' { #' . $id . ' .flex-va {min-height:' . $value . 'px;}}';
        $px = !empty($settings['align']['vertical_align_min']) ? $settings['align']['vertical_align_min'] : '';
        $style = $px . ' style="min-height:' . $px . 'px;"';
      }
    }
    // Add css
    if ($css) {
      $vars['content']->content = '<style>' . $css . '</style>' . $vars['content']->content;
    }    
  }

  // Render pane through normal channels
  return theme('panels_pane', $vars);
}
