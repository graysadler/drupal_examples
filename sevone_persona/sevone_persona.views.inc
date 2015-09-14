<?php
/**
 * @file
 * sevone_persona.views.inc
 *
 * Defines the SevOne Persona/Identity default argument plugins.
 */

/**
 * Implements hook_views_plugins().
 */
function sevone_persona_views_plugins() {
  $plugins = array(
    'argument default' => array(
      'sevone_persona_field' => array(
        'title' => t('SevOne Persona/Identity'),
        'handler' => 'sevone_persona_plugin_argument_default_sevone_persona_field',
      ),
    ),
  );
  return $plugins;
}