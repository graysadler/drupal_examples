<?php
/**
 * @file
 * sevone_persona.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function sevone_persona_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sevone_persona_analytics';
  $strongarm->value = array(
    'field_persona' => 'dimension15',
  );
  $export['sevone_persona_analytics'] = $strongarm;

  features_alter_code('variable', $export);

  return $export;
}
