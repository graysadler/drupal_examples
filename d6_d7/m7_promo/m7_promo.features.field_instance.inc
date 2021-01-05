<?php
/**
 * @file
 * m7_promo.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function m7_promo_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'field_collection_item-field_promo_cta-field_promo_cta_link'.
  $field_instances['field_collection_item-field_promo_cta-field_promo_cta_link'] = array(
    'bundle' => 'field_promo_cta',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the call to action text and url.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_cta_link',
    'label' => 'Link',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 0,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'exclude_cv' => FALSE,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'rel_remove' => 'default',
      'title' => 'optional',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 'optional',
      'user_register_form' => FALSE,
      'validate_url' => 0,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_promo_cta-field_promo_cta_phone'.
  $field_instances['field_collection_item-field_promo_cta-field_promo_cta_phone'] = array(
    'bundle' => 'field_promo_cta',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the phone number in the following format: 1-###-###-####.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_cta_phone',
    'label' => 'Phone Number',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_promo_cta-field_promo_cta_phone_text'.
  $field_instances['field_collection_item-field_promo_cta-field_promo_cta_phone_text'] = array(
    'bundle' => 'field_promo_cta',
    'default_value' => array(
      0 => array(
        'value' => 'Call Now',
      ),
    ),
    'deleted' => 0,
    'description' => 'Enter the text to display in this CTA. When clicked on, the user will be prompted to dial the number.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_cta_phone_text',
    'label' => 'Phone Text',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_promo_cta-field_promo_cta_type'.
  $field_instances['field_collection_item-field_promo_cta-field_promo_cta_type'] = array(
    'bundle' => 'field_promo_cta',
    'default_value' => array(
      0 => array(
        'value' => 'link',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_cta_type',
    'label' => 'Type',
    'required' => 1,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_promo_cta-field_promo_cta_viz'.
  $field_instances['field_collection_item-field_promo_cta-field_promo_cta_viz'] = array(
    'bundle' => 'field_promo_cta',
    'default_value' => array(
      0 => array(
        'value' => 'always',
      ),
    ),
    'deleted' => 0,
    'description' => 'Choose when this CTA should be visible.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_cta_viz',
    'label' => 'Device Visibility',
    'required' => 1,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'fieldable_panels_pane-collapsible_message-field_promo_banner_bg'.
  $field_instances['fieldable_panels_pane-collapsible_message-field_promo_banner_bg'] = array(
    'bundle' => 'collapsible_message',
    'default_value' => array(
      0 => array(
        'rgb' => '#338a86',
      ),
    ),
    'deleted' => 0,
    'description' => 'Select a background color for this message banner.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'color_field',
        'settings' => array(),
        'type' => 'color_field_default_formatter',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'fieldable_panels_pane',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_banner_bg',
    'label' => 'Background Color',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'color_field',
      'settings' => array(),
      'type' => 'color_field_default_widget',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'fieldable_panels_pane-collapsible_message-field_promo_banner_body'.
  $field_instances['fieldable_panels_pane-collapsible_message-field_promo_banner_body'] = array(
    'bundle' => 'collapsible_message',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the copy of the message here. ',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'fieldable_panels_pane',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_banner_body',
    'label' => 'Message Copy',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'fieldable_panels_pane-collapsible_message-field_promo_banner_font'.
  $field_instances['fieldable_panels_pane-collapsible_message-field_promo_banner_font'] = array(
    'bundle' => 'collapsible_message',
    'default_value' => array(
      0 => array(
        'rgb' => '#FFFFFF',
      ),
    ),
    'deleted' => 0,
    'description' => 'Select a color for the banner message.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'color_field',
        'settings' => array(),
        'type' => 'color_field_default_formatter',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'fieldable_panels_pane',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_banner_font',
    'label' => 'Message Color',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'color_field',
      'settings' => array(),
      'type' => 'color_field_default_widget',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-promo-body'.
  $field_instances['node-promo-body'] = array(
    'bundle' => 'promo',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'active' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'archived' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'sidebar' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'body',
    'label' => 'Body',
    'required' => 0,
    'settings' => array(
      'display_summary' => 0,
      'exclude_cv' => FALSE,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 39,
    ),
  );

  // Exported field_instance: 'node-promo-field_promo_banner'.
  $field_instances['node-promo-field_promo_banner'] = array(
    'bundle' => 'promo',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => 'If selected, the promotion will display as a banner on all pages regardless of visibility selected in "Promo Settings"',
    'display' => array(
      'active' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'archived' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'sidebar' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_banner',
    'label' => 'Show Banner',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 46,
    ),
  );

  // Exported field_instance: 'node-promo-field_promo_banner_bg'.
  $field_instances['node-promo-field_promo_banner_bg'] = array(
    'bundle' => 'promo',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select a background color for this promotional banner.',
    'display' => array(
      'active' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'archived' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'sidebar' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_banner_bg',
    'label' => 'Background',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'color_field',
      'settings' => array(),
      'type' => 'color_field_default_widget',
      'weight' => 47,
    ),
  );

  // Exported field_instance: 'node-promo-field_promo_banner_body'.
  $field_instances['node-promo-field_promo_banner_body'] = array(
    'bundle' => 'promo',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the promotional banner copy. You may change the foreground color of specfic text by using the WYSIWYG.',
    'display' => array(
      'active' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'archived' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'sidebar' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_banner_body',
    'label' => 'Promo Copy',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
      ),
      'type' => 'text_textarea',
      'weight' => 49,
    ),
  );

  // Exported field_instance: 'node-promo-field_promo_banner_font'.
  $field_instances['node-promo-field_promo_banner_font'] = array(
    'bundle' => 'promo',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'active' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'archived' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'sidebar' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_banner_font',
    'label' => 'Font Color',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'color_field',
      'settings' => array(),
      'type' => 'color_field_default_widget',
      'weight' => 48,
    ),
  );

  // Exported field_instance: 'node-promo-field_promo_color'.
  $field_instances['node-promo-field_promo_color'] = array(
    'bundle' => 'promo',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select a background color for this promotion.',
    'display' => array(
      'active' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'archived' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'sidebar' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_color',
    'label' => 'Background Color',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'color_field',
      'settings' => array(),
      'type' => 'color_field_default_widget',
      'weight' => 43,
    ),
  );

  // Exported field_instance: 'node-promo-field_promo_cta'.
  $field_instances['node-promo-field_promo_cta'] = array(
    'bundle' => 'promo',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Create one or more Call to Action links/buttons with visibility options for mobile and desktop.',
    'display' => array(
      'active' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'archived' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'field_collection',
        'settings' => array(
          'add' => '',
          'delete' => '',
          'description' => 1,
          'edit' => '',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 6,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'sidebar' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_cta',
    'label' => 'Call to Actions',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-promo-field_promo_delay'.
  $field_instances['node-promo-field_promo_delay'] = array(
    'bundle' => 'promo',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Enter the number of seconds to delay the modal from appearing.',
    'display' => array(
      'active' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'archived' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'sidebar' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_delay',
    'label' => 'Modal Delay',
    'required' => 1,
    'settings' => array(
      'exclude_cv' => FALSE,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => 'second|seconds',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 53,
    ),
  );

  // Exported field_instance: 'node-promo-field_promo_device_viz'.
  $field_instances['node-promo-field_promo_device_viz'] = array(
    'bundle' => 'promo',
    'default_value' => array(
      0 => array(
        'value' => 'tablet',
      ),
      1 => array(
        'value' => 'desktop',
      ),
    ),
    'deleted' => 0,
    'description' => 'Modal will only be visible on the selected devices.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'sidebar' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_device_viz',
    'label' => 'Device Visibility',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 50,
    ),
  );

  // Exported field_instance: 'node-promo-field_promo_font_color'.
  $field_instances['node-promo-field_promo_font_color'] = array(
    'bundle' => 'promo',
    'default_value' => array(
      0 => array(
        'rgb' => '#333333',
      ),
    ),
    'deleted' => 0,
    'description' => 'Select the font color to be used with this promotion.',
    'display' => array(
      'active' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'archived' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'sidebar' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_font_color',
    'label' => 'Font Color',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'color_field',
      'settings' => array(),
      'type' => 'color_field_default_widget',
      'weight' => 44,
    ),
  );

  // Exported field_instance: 'node-promo-field_promo_freq'.
  $field_instances['node-promo-field_promo_freq'] = array(
    'bundle' => 'promo',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => 'Enter a number to reflect the frequency of page views this modal should appear. Ex: 3 will show the modal on every third page view.',
    'display' => array(
      'active' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'archived' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'sidebar' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_freq',
    'label' => 'Modal Frequency',
    'required' => 1,
    'settings' => array(
      'exclude_cv' => FALSE,
      'max' => '',
      'min' => 1,
      'prefix' => '',
      'suffix' => 'page view|page views',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 52,
    ),
  );

  // Exported field_instance: 'node-promo-field_promo_headline'.
  $field_instances['node-promo-field_promo_headline'] = array(
    'bundle' => 'promo',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Headline (H1) text',
    'display' => array(
      'active' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'archived' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'sidebar' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_headline',
    'label' => 'Headline',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 37,
    ),
  );

  // Exported field_instance: 'node-promo-field_promo_image'.
  $field_instances['node-promo-field_promo_image'] = array(
    'bundle' => 'promo',
    'deleted' => 0,
    'description' => 'A featured or background image to use in the promotion.',
    'display' => array(
      'active' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'archived' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'promo_portrait',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'sidebar' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'exclude_cv' => FALSE,
      'file_directory' => 'promo',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'iinhtml5video' => 0,
          'private' => 'private',
          'public' => 'public',
          'vimeo' => 0,
          'youtube' => 0,
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 'media_default--media_browser_1',
          'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
          'media_internet' => 'media_internet',
          'upload' => 'upload',
        ),
        'manualcrop_crop_info' => 1,
        'manualcrop_default_crop_area' => 1,
        'manualcrop_enable' => 1,
        'manualcrop_inline_crop' => 0,
        'manualcrop_instant_crop' => FALSE,
        'manualcrop_instant_preview' => 1,
        'manualcrop_keyboard' => 1,
        'manualcrop_maximize_default_crop_area' => 0,
        'manualcrop_require_cropping' => array(),
        'manualcrop_styles_list' => array(
          'promo_full' => 'promo_full',
          'promo_portrait' => 'promo_portrait',
          'promo_split' => 'promo_split',
        ),
        'manualcrop_styles_mode' => 'include',
        'manualcrop_thumblist' => 0,
      ),
      'type' => 'media_generic',
      'weight' => 42,
    ),
  );

  // Exported field_instance: 'node-promo-field_promo_include_banner'.
  $field_instances['node-promo-field_promo_include_banner'] = array(
    'bundle' => 'promo',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'If selected, this promo will also display a banner at the top of the page.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'sidebar' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_include_banner',
    'label' => 'Include Banner',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 45,
    ),
  );

  // Exported field_instance: 'node-promo-field_promo_modal'.
  $field_instances['node-promo-field_promo_modal'] = array(
    'bundle' => 'promo',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => 'If selected, this promotion will display in a popup modal.',
    'display' => array(
      'active' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'archived' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'sidebar' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_modal',
    'label' => 'Show Modal',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 34,
    ),
  );

  // Exported field_instance: 'node-promo-field_promo_modal_opt_out'.
  $field_instances['node-promo-field_promo_modal_opt_out'] = array(
    'bundle' => 'promo',
    'default_value' => array(
      0 => array(
        'value' => 60,
      ),
    ),
    'deleted' => 0,
    'description' => 'The number of minutes to hide this promo modal after the user opts out. Set to 0 to always hide this promo modal after a user opts out.',
    'display' => array(
      'active' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'archived' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'sidebar' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_modal_opt_out',
    'label' => 'Opt-Out Time',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'max' => '',
      'min' => 0,
      'prefix' => '',
      'suffix' => 'minute|minutes',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 54,
    ),
  );

  // Exported field_instance: 'node-promo-field_promo_modal_visitor'.
  $field_instances['node-promo-field_promo_modal_visitor'] = array(
    'bundle' => 'promo',
    'default_value' => array(
      0 => array(
        'value' => 'all',
      ),
    ),
    'deleted' => 0,
    'description' => 'Select the type of visitor that should experience this modal promotion: New, Returning or All',
    'display' => array(
      'active' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'archived' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'sidebar' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_modal_visitor',
    'label' => 'Type of Visitors',
    'required' => 1,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 51,
    ),
  );

  // Exported field_instance: 'node-promo-field_promo_pages'.
  $field_instances['node-promo-field_promo_pages'] = array(
    'bundle' => 'promo',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the relative paths which the promotion should or should not appear on. Use &lt;front&gt; for the front page. Separate each page by a new line.',
    'display' => array(
      'active' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'archived' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'sidebar' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_pages',
    'label' => 'Pages',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-promo-field_promo_pages_rule'.
  $field_instances['node-promo-field_promo_pages_rule'] = array(
    'bundle' => 'promo',
    'default_value' => array(
      0 => array(
        'value' => 'except',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'active' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'archived' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'sidebar' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_pages_rule',
    'label' => 'Show On',
    'required' => 1,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-promo-field_promo_phone'.
  $field_instances['node-promo-field_promo_phone'] = array(
    'bundle' => 'promo',
    'default_value' => array(
      0 => array(
        'value' => '1-877-730-5444',
      ),
    ),
    'deleted' => 0,
    'description' => 'Add an optional vanity phone number. Enter value in the following format: 1-###-###-####',
    'display' => array(
      'active' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'archived' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'sidebar' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_phone',
    'label' => 'Vanity Phone',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 40,
    ),
  );

  // Exported field_instance: 'node-promo-field_promo_phone_callout'.
  $field_instances['node-promo-field_promo_phone_callout'] = array(
    'bundle' => 'promo',
    'default_value' => array(
      0 => array(
        'value' => 'Call Us Today!',
      ),
    ),
    'deleted' => 0,
    'description' => 'Add an optional call-out that will precede the vanity phone number.',
    'display' => array(
      'active' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'archived' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'sidebar' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_phone_callout',
    'label' => 'Vanity Phone Call-out',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 41,
    ),
  );

  // Exported field_instance: 'node-promo-field_promo_sub_head'.
  $field_instances['node-promo-field_promo_sub_head'] = array(
    'bundle' => 'promo',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Sub headline (H2) text.',
    'display' => array(
      'active' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'archived' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'sidebar' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_sub_head',
    'label' => 'Sub Headline',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 38,
    ),
  );

  // Exported field_instance: 'node-promo-field_promo_template'.
  $field_instances['node-promo-field_promo_template'] = array(
    'bundle' => 'promo',
    'default_value' => array(
      0 => array(
        'value' => 'text',
      ),
    ),
    'deleted' => 0,
    'description' => 'Select a template to use for this promotion.',
    'display' => array(
      'active' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'archived' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'sidebar' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_promo_template',
    'label' => 'Modal Template',
    'required' => 1,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 36,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('A featured or background image to use in the promotion.');
  t('Add an optional call-out that will precede the vanity phone number.');
  t('Add an optional vanity phone number. Enter value in the following format: 1-###-###-####');
  t('Background');
  t('Background Color');
  t('Body');
  t('Call to Actions');
  t('Choose when this CTA should be visible.');
  t('Create one or more Call to Action links/buttons with visibility options for mobile and desktop.');
  t('Device Visibility');
  t('Enter a number to reflect the frequency of page views this modal should appear. Ex: 3 will show the modal on every third page view.');
  t('Enter the call to action text and url.');
  t('Enter the copy of the message here. ');
  t('Enter the number of seconds to delay the modal from appearing.');
  t('Enter the phone number in the following format: 1-###-###-####.');
  t('Enter the promotional banner copy. You may change the foreground color of specfic text by using the WYSIWYG.');
  t('Enter the relative paths which the promotion should or should not appear on. Use &lt;front&gt; for the front page. Separate each page by a new line.');
  t('Enter the text to display in this CTA. When clicked on, the user will be prompted to dial the number.');
  t('Font Color');
  t('Headline');
  t('Headline (H1) text');
  t('If selected, the promotion will display as a banner on all pages regardless of visibility selected in "Promo Settings"');
  t('If selected, this promo will also display a banner at the top of the page.');
  t('If selected, this promotion will display in a popup modal.');
  t('Image');
  t('Include Banner');
  t('Link');
  t('Message Color');
  t('Message Copy');
  t('Modal Delay');
  t('Modal Frequency');
  t('Modal Template');
  t('Modal will only be visible on the selected devices.');
  t('Opt-Out Time');
  t('Pages');
  t('Phone Number');
  t('Phone Text');
  t('Promo Copy');
  t('Select a background color for this message banner.');
  t('Select a background color for this promotion.');
  t('Select a background color for this promotional banner.');
  t('Select a color for the banner message.');
  t('Select a template to use for this promotion.');
  t('Select the font color to be used with this promotion.');
  t('Select the type of visitor that should experience this modal promotion: New, Returning or All');
  t('Show Banner');
  t('Show Modal');
  t('Show On');
  t('Sub Headline');
  t('Sub headline (H2) text.');
  t('The number of minutes to hide this promo modal after the user opts out. Set to 0 to always hide this promo modal after a user opts out.');
  t('Type');
  t('Type of Visitors');
  t('Vanity Phone');
  t('Vanity Phone Call-out');

  return $field_instances;
}
