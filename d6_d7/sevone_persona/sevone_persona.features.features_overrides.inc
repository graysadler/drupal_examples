<?php
/**
 * @file
 * sevone_persona.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function sevone_persona_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: views_view
  $overrides["views_view.sevone_learning_center_filter.display|default|display_options|arguments"] = array(
    'field_persona_tid' => array(
      'id' => 'field_persona_tid',
      'table' => 'field_data_field_persona',
      'field' => 'field_persona_tid',
      'default_action' => 'default',
      'default_argument_type' => 'sevone_persona_field',
      'summary' => array(
        'number_of_records' => 0,
        'format' => 'default_summary',
      ),
      'summary_options' => array(
        'items_per_page' => 25,
      ),
    ),
  );
  $overrides["views_view.sevone_supported_technologies.display|default|display_options|arguments"] = array(
    'field_persona_tid' => array(
      'id' => 'field_persona_tid',
      'table' => 'field_data_field_persona',
      'field' => 'field_persona_tid',
      'default_action' => 'default',
      'default_argument_type' => 'sevone_persona_field',
      'summary' => array(
        'number_of_records' => 0,
        'format' => 'default_summary',
      ),
      'summary_options' => array(
        'items_per_page' => 25,
      ),
    ),
  );
  $overrides["views_view.sevone_supported_technologies.display|default|display_options|fields|title|link_to_node"]["DELETED"] = TRUE;

  features_alter_code('features_overrides', $overrides);

  return $overrides;
}
