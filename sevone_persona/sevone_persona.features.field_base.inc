<?php
/**
 * @file
 * sevone_persona.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function sevone_persona_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_persona'
  $field_bases['field_persona'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_persona',
    'foreign keys' => array(
      'tid' => array(
        'columns' => array(
          'tid' => 'tid',
        ),
        'table' => 'taxonomy_term_data',
      ),
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'persona',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  features_alter_code('field_base', $field_bases);

  return $field_bases;
}
