<?php
/**
 * @file
 * multistream.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function multistream_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_images|node|multistream|form';
  $field_group->group_name = 'group_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'multistream';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Upload Images',
    'weight' => '2',
    'children' => array(
      0 => 'field_stream_image',
      1 => 'field_cover',
      2 => 'field_player_background',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Upload Images',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'upload-images',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_images|node|multistream|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_settings|node|multistream|form';
  $field_group->group_name = 'group_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'multistream';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'More Settings',
    'weight' => '3',
    'children' => array(
      0 => 'body',
      1 => 'field_game_category',
      2 => 'field_event_dates',
      3 => 'field_stream_category',
      4 => 'metatags',
      5 => 'title',
      6 => 'path',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'More Settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'more-settings',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_settings|node|multistream|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_social_medi|node|multistream|form';
  $field_group->group_name = 'group_social_medi';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'multistream';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Social Media',
    'weight' => '1',
    'children' => array(
      0 => 'field_facebook',
      1 => 'field_google_plus',
      2 => 'field_reddit',
      3 => 'field_twitter',
      4 => 'field_website',
      5 => 'field_youtube',
      6 => 'field_twitter_feed',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Social Media',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'social-media',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_social_medi|node|multistream|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_streams|node|multistream|form';
  $field_group->group_name = 'group_streams';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'multistream';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Streams',
    'weight' => '0',
    'children' => array(
      0 => 'field_streams',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Streams',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'streams',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_streams|node|multistream|form'] = $field_group;

  return $export;
}
