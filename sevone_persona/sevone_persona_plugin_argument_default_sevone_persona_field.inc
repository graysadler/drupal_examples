<?php
/**
 * @file
 * Contains the SevOne Persona/Identity default argument plugin (field).
 */

/**
 * Default argument plugin to extract the global filter value set for this
 * contextual filter.
 */
class sevone_persona_plugin_argument_default_sevone_persona_field extends global_filter_plugin_argument_default_global_filter_field {

  /**
   * Define the one option we offer.
   */
  public function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  /**
   * Build the option form.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }
  
  /**
   * Provide the default form form for submitting options
   */
  function options_submit(&$form, &$form_state, &$options = array()) { 
    parent::options_submit($form, $form_state, $options);
  }  

  /**
   * Get argument.
   * Overrides global_filter's version in order to create global filter on the fly
   * TODO: possibly move this to options_submit even though this is called during preview after submit
   */
  public function get_argument() {
    $field_name = $views_field_name = $this->argument->field;
    // Where $views_field_name refers to a field it equals one of:
    // '<field_name>_value', '<field_name>_tid' or '<field_name>_fid'

    $exception_value = $this->argument->options['exception']['value'];

    if (!($filter_key = global_filter_key_by_name($views_field_name))) {
      // Not found as a node property, maybe it's a field.
      if (empty($this->argument->definition['field_name'])) {
        return $exception_value;
      }
      $field_name = $this->argument->definition['field_name'];
      /* @todo generalise this beyond AddressField
      $field = field_info_field($field_name);
      if ($field['type'] == 'addressfield') {
      $column = drupal_substr($views_field_name, strlen($field_name) + 1);
      }
      */
      $filter_key = global_filter_key_by_name($field_name);
    }

    if ($filter_key) {
      $arg = global_filter_get_session_value($field_name);
      if (isset($arg) && $arg != '' && $arg != array('')) {
        // Don't reduce array(0) to empty.
        if (is_array($arg) && $arg != array(0)) {
          // Removing empty entries may not be right when filter is numeric, i.e
          // a single digit 0 will be removed. However 00 will be interpreted
          // correctly as zero.
          $arg = array_filter($arg /* , callback */);
          // For Hierarchical select: always use deepest term. For other fields
          // it doesn't matter.
          $arg = array_reverse($arg);
          if (empty($arg)) {
            return $exception_value;
          }
        }
        if (is_string($arg)) {
          if ($field = field_info_field($field_name)) {
            // Handle taxonomy terms and list fields that were configured to
            // render as text fields. Convert the entered value back to a tid or
            // list key. Accept a string of values separated by plus signs.
            $args = explode('+', $arg);
            if ($field['type'] == 'taxonomy_term_reference') {
              $arg = array();
              $vocabulary = $field['settings']['allowed_values'][0]['vocabulary'];
              foreach ($args as $value) {
                $arg[] = global_filter_get_tid($value, $vocabulary);
              }
            }
            elseif (strpos($field['type'], 'list_') === 0) {
              $arg = array();
              foreach ($args as $value) {
                $arg[] = global_filter_get_field_value_key($field, $value);
              }
            }
          }
        }
      }
      else {
        $arg = $exception_value;
      }
      // If the argument is multi-valued (combo-box, checkboxes or text field
      // with '+' or ',') string the values together separated by the appropiate
      // plus-sign (for OR, the default) or comma (for AND).
      // Note this requires the user to tick "Allow multiple values" after
      // expanding the "More" fieldset on the Contextual Filter configuration
      // panel. Otherwise only the first of the values will be used.
      // Note:
      // Be careful with spaces: have seen "very cheap" interpreted as "cheap"
      $is_and = !empty($this->argument->options['break_phrase']) &&
        !empty($this->options['break_phrase_and']);
      return is_array($arg) ? implode($is_and ? ',' : '+', $arg) : $arg;
    }
    
    static $inserted;
    
    // Make sure we don't have an infinite loop
    if($inserted) {
      $view_name = empty($this->view->human_name) ? $this->view->name : $this->view->human_name;
      drupal_set_message(t('The view %view specifies a global filter field, %name, as its default contextual filter. However there is no associated <strong>Global Filter block</strong> for %name even though one was attempted to be created. Please configure a global filter <a href="admin/structure/block">here</a> or remove this contextual filter from the view.', array(
      '%view' => $view_name, '%name' => $views_field_name)), 'warning', FALSE);
      return $exception_value;      
    }
    
    // No filter key, field or node property not found. So create it
    $filters = variable_get('global_filters', array());
    $key = count($filters) + 1;
    $filters[] = array(
      'name' => $field_name,
      'block' => 'global_filter_'.$key,
      'uses_view' => 0,
      'field' => $field_name,
      'view' => '',
      'widget' => 'default_options_select',
      'convert_to_range' => 0,
      'label' => '',
      'option_all_text' => '',
      'confirm_question' => '',
      'set_on_select' => 0,
      'global_field_or_view_default' => array(
        array(),
      ),
      'global_php_default' => '',
    );
    
    // Update the filter variable and reset the cache
    variable_set('global_filters', $filters);
    variable_set('global_filter_num_filters', $key);
    global_filter_set_parameter(null, null, null, true);
    $inserted = true;
    return self::get_argument();
  }
}