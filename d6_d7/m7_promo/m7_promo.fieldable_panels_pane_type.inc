<?php
/**
 * @file
 * m7_promo.fieldable_panels_pane_type.inc
 */

/**
 * Implements hook_default_fieldable_panels_pane_type().
 */
function m7_promo_default_fieldable_panels_pane_type() {
  $export = array();

  $fieldable_panels_pane_type = new stdClass();
  $fieldable_panels_pane_type->disabled = FALSE; /* Edit this to true to make a default fieldable_panels_pane_type disabled initially */
  $fieldable_panels_pane_type->api_version = 1;
  $fieldable_panels_pane_type->name = 'collapsible_message';
  $fieldable_panels_pane_type->title = 'Collapsible Message';
  $fieldable_panels_pane_type->description = 'Adds a message banner to a region of your choice. Typically in the head section of the page.';
  $export['collapsible_message'] = $fieldable_panels_pane_type;

  return $export;
}
