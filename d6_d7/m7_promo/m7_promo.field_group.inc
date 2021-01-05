<?php
/**
 * @file
 * m7_promo.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function m7_promo_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_promo_banner|node|promo|form';
  $field_group->group_name = 'group_promo_banner';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'promo';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Banner Settings',
    'weight' => '2',
    'children' => array(
      0 => 'field_promo_banner',
      1 => 'field_promo_banner_bg',
      2 => 'field_promo_banner_body',
      3 => 'field_promo_banner_font',
      4 => 'field_promo_include_banner',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-promo-banner field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_promo_banner|node|promo|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_promo_modal_tabs|node|promo|form';
  $field_group->group_name = 'group_promo_modal_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'promo';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Deprecated',
    'weight' => '3',
    'children' => array(
      0 => 'field_promo_banner_pages',
      1 => 'field_promo_banner_visitors',
      2 => 'field_promo_modal_form',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Deprecated',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_promo_modal_tabs|node|promo|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_promo_modal_viz|node|promo|form';
  $field_group->group_name = 'group_promo_modal_viz';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'promo';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_promo_modal';
  $field_group->data = array(
    'label' => 'Visibility',
    'weight' => '35',
    'children' => array(
      0 => 'field_promo_delay',
      1 => 'field_promo_freq',
      2 => 'field_promo_modal_opt_out',
      3 => 'field_promo_modal_visitor',
      4 => 'field_promo_device_viz',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Visibility',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_promo_modal_viz|node|promo|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_promo_modal|node|promo|form';
  $field_group->group_name = 'group_promo_modal';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'promo';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Modal Settings',
    'weight' => '1',
    'children' => array(
      0 => 'body',
      1 => 'field_promo_color',
      2 => 'field_promo_font_color',
      3 => 'field_promo_headline',
      4 => 'field_promo_image',
      5 => 'field_promo_modal',
      6 => 'field_promo_phone',
      7 => 'field_promo_phone_callout',
      8 => 'field_promo_sub_head',
      9 => 'field_promo_template',
      10 => 'group_promo_modal_viz',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-promo-modal field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_promo_modal|node|promo|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_promo_settings|node|promo|form';
  $field_group->group_name = 'group_promo_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'promo';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Promo Settings',
    'weight' => '0',
    'children' => array(
      0 => 'field_promo_cta',
      1 => 'field_promo_pages',
      2 => 'field_promo_pages_rule',
      3 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Promo Settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-promo-settings field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_promo_settings|node|promo|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Banner Settings');
  t('Deprecated');
  t('Modal Settings');
  t('Promo Settings');
  t('Visibility');

  return $field_groups;
}
