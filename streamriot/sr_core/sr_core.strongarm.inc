<?php
/**
 * @file
 * sr_core.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function sr_core_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_help';
  $strongarm->value = 0;
  $export['comment_anonymous_help'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_staff';
  $strongarm->value = 0;
  $export['comment_anonymous_staff'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_help';
  $strongarm->value = 0;
  $export['comment_default_mode_help'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_staff';
  $strongarm->value = 1;
  $export['comment_default_mode_staff'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_help';
  $strongarm->value = '50';
  $export['comment_default_per_page_help'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_staff';
  $strongarm->value = '50';
  $export['comment_default_per_page_staff'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_help';
  $strongarm->value = 1;
  $export['comment_form_location_help'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_staff';
  $strongarm->value = 1;
  $export['comment_form_location_staff'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_help';
  $strongarm->value = '1';
  $export['comment_help'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_help';
  $strongarm->value = '1';
  $export['comment_preview_help'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_staff';
  $strongarm->value = '1';
  $export['comment_preview_staff'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_staff';
  $strongarm->value = '1';
  $export['comment_staff'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_help';
  $strongarm->value = 1;
  $export['comment_subject_field_help'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_staff';
  $strongarm->value = 1;
  $export['comment_subject_field_staff'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_webform';
  $strongarm->value = '0';
  $export['comment_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'elysia_cron_alert_interval';
  $strongarm->value = '60';
  $export['elysia_cron_alert_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'elysia_cron_default_rules';
  $strongarm->value = array(
    '*/1 * * * *' => 'Every minutes',
    '*/3 * * * *' => 'Every 3 minutes',
    '*/5 * * * *' => 'Every 5 minutes',
    '*/10 * * * *' => 'Every 10 minutes',
    '*/15 * * * *' => 'Every 15 minutes',
    '*/30 * * * *' => 'Every 30 minutes',
    '0 * * * *' => 'Every hour',
    '0 */6 * * *' => 'Every 6 hours',
    '4 0 * * *' => 'Once a day',
    '4 0 * * 0' => 'Once a week',
    '4 0 1 * *' => 'Once a month',
  );
  $export['elysia_cron_default_rules'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__help';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '4',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '3',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__help'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__staff';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'teaser_large' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '6',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '1',
        ),
      ),
      'display' => array(
        'sharethis' => array(
          'default' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__staff'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hybridauth_provider_Facebook_display';
  $strongarm->value = 'popup';
  $export['hybridauth_provider_Facebook_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hybridauth_provider_Facebook_enabled';
  $strongarm->value = 1;
  $export['hybridauth_provider_Facebook_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hybridauth_provider_Facebook_scope';
  $strongarm->value = array(
    'user_about_me' => 'user_about_me',
    'email' => 'email',
    'user_activities' => 0,
    'user_birthday' => 0,
    'user_checkins' => 0,
    'user_education_history' => 0,
    'user_events' => 0,
    'user_groups' => 0,
    'user_hometown' => 0,
    'user_interests' => 0,
    'user_likes' => 0,
    'user_location' => 0,
    'user_notes' => 0,
    'user_online_presence' => 0,
    'user_photos' => 0,
    'user_questions' => 0,
    'user_relationships' => 0,
    'user_relationship_details' => 0,
    'user_religion_politics' => 0,
    'user_status' => 0,
    'user_videos' => 0,
    'user_website' => 0,
    'user_work_history' => 0,
    'read_friendlists' => 0,
    'read_insights' => 0,
    'read_mailbox' => 0,
    'read_requests' => 0,
    'read_stream' => 0,
    'xmpp_login' => 0,
    'ads_management' => 0,
    'create_event' => 0,
    'manage_friendlists' => 0,
    'manage_notifications' => 0,
    'offline_access' => 0,
    'publish_checkins' => 0,
    'publish_stream' => 0,
    'rsvp_event' => 0,
    'sms' => 0,
    'publish_actions' => 0,
  );
  $export['hybridauth_provider_Facebook_scope'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hybridauth_provider_Facebook_weight';
  $strongarm->value = '50';
  $export['hybridauth_provider_Facebook_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hybridauth_provider_Facebook_window_height';
  $strongarm->value = '500';
  $export['hybridauth_provider_Facebook_window_height'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hybridauth_provider_Facebook_window_type';
  $strongarm->value = 'popup';
  $export['hybridauth_provider_Facebook_window_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hybridauth_provider_Facebook_window_width';
  $strongarm->value = '800';
  $export['hybridauth_provider_Facebook_window_width'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hybridauth_provider_TwitchTV_enabled';
  $strongarm->value = 1;
  $export['hybridauth_provider_TwitchTV_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hybridauth_provider_TwitchTV_weight';
  $strongarm->value = '50';
  $export['hybridauth_provider_TwitchTV_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hybridauth_provider_TwitchTV_window_height';
  $strongarm->value = '500';
  $export['hybridauth_provider_TwitchTV_window_height'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hybridauth_provider_TwitchTV_window_type';
  $strongarm->value = 'popup';
  $export['hybridauth_provider_TwitchTV_window_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hybridauth_provider_TwitchTV_window_width';
  $strongarm->value = '800';
  $export['hybridauth_provider_TwitchTV_window_width'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hybridauth_provider_Twitter_enabled';
  $strongarm->value = 1;
  $export['hybridauth_provider_Twitter_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hybridauth_provider_Twitter_weight';
  $strongarm->value = '50';
  $export['hybridauth_provider_Twitter_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hybridauth_provider_Twitter_window_height';
  $strongarm->value = '500';
  $export['hybridauth_provider_Twitter_window_height'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hybridauth_provider_Twitter_window_type';
  $strongarm->value = 'popup';
  $export['hybridauth_provider_Twitter_window_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hybridauth_provider_Twitter_window_width';
  $strongarm->value = '800';
  $export['hybridauth_provider_Twitter_window_width'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hybridauth_register';
  $strongarm->value = '0';
  $export['hybridauth_register'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hybridauth_registration_password';
  $strongarm->value = 0;
  $export['hybridauth_registration_password'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hybridauth_registration_username_change';
  $strongarm->value = 0;
  $export['hybridauth_registration_username_change'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hybridauth_remove_password_fields';
  $strongarm->value = 0;
  $export['hybridauth_remove_password_fields'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hybridauth_required_fields';
  $strongarm->value = array(
    'email' => 'email',
    'firstName' => 0,
    'lastName' => 0,
    'gender' => 0,
  );
  $export['hybridauth_required_fields'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hybridauth_username';
  $strongarm->value = '[user:hybridauth:firstName] [user:hybridauth:lastName]';
  $export['hybridauth_username'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_confirm_email_at_registration';
  $strongarm->value = '0';
  $export['logintoboggan_confirm_email_at_registration'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_immediate_login_on_register';
  $strongarm->value = 1;
  $export['logintoboggan_immediate_login_on_register'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_login_successful_message';
  $strongarm->value = '0';
  $export['logintoboggan_login_successful_message'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_login_with_email';
  $strongarm->value = '1';
  $export['logintoboggan_login_with_email'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_minimum_password_length';
  $strongarm->value = '4';
  $export['logintoboggan_minimum_password_length'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_override_destination_parameter';
  $strongarm->value = 1;
  $export['logintoboggan_override_destination_parameter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_pre_auth_role';
  $strongarm->value = '2';
  $export['logintoboggan_pre_auth_role'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_purge_unvalidated_user_interval';
  $strongarm->value = '15379200';
  $export['logintoboggan_purge_unvalidated_user_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_redirect_on_confirm';
  $strongarm->value = 'multistream';
  $export['logintoboggan_redirect_on_confirm'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_redirect_on_register';
  $strongarm->value = 'multistream';
  $export['logintoboggan_redirect_on_register'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_unified_login';
  $strongarm->value = 1;
  $export['logintoboggan_unified_login'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_help';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_help'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_staff';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_staff'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_help';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_help'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_staff';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_staff'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_help';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_help'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_multistream';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_multistream'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_staff';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_staff'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_help';
  $strongarm->value = '1';
  $export['node_preview_help'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_staff';
  $strongarm->value = '0';
  $export['node_preview_staff'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_help';
  $strongarm->value = 0;
  $export['node_submitted_help'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_staff';
  $strongarm->value = 0;
  $export['node_submitted_staff'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_manager_user_edit_disabled';
  $strongarm->value = FALSE;
  $export['page_manager_user_edit_disabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_article';
  $strongarm->value = array(
    'status' => 0,
    'view modes' => array(),
  );
  $export['panelizer_defaults_node_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_blog';
  $strongarm->value = array(
    'status' => 1,
    'view modes' => array(
      'page_manager' => array(
        'status' => 1,
        'default' => 1,
        'choice' => 0,
      ),
      'default' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'full' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'teaser' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'teaser_large' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_node_blog'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_help';
  $strongarm->value = array(
    'status' => 1,
    'view modes' => array(
      'page_manager' => array(
        'status' => 1,
        'default' => 1,
        'choice' => 0,
      ),
      'default' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'teaser' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'teaser_large' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_node_help'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_page';
  $strongarm->value = array(
    'status' => 1,
    'view modes' => array(
      'page_manager' => array(
        'status' => 1,
        'default' => 1,
        'choice' => 0,
      ),
      'default' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'teaser' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'teaser_large' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_node_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_staff';
  $strongarm->value = array(
    'status' => 1,
    'view modes' => array(
      'page_manager' => array(
        'status' => 1,
        'default' => 1,
        'choice' => 0,
      ),
      'default' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'teaser' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'teaser_large' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_node_staff'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_webform';
  $strongarm->value = array(
    'status' => 1,
    'view modes' => array(
      'page_manager' => array(
        'status' => 1,
        'default' => 1,
        'choice' => 0,
      ),
      'default' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'teaser' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'teaser_large' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_node_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_taxonomy_term_game_category';
  $strongarm->value = array(
    'status' => 1,
    'view modes' => array(
      'page_manager' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'default' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_taxonomy_term_game_category'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_taxonomy_term_solutions';
  $strongarm->value = array(
    'status' => 1,
    'view modes' => array(
      'page_manager' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'default' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_taxonomy_term_solutions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_taxonomy_term_tags';
  $strongarm->value = array(
    'status' => 0,
    'view modes' => array(),
  );
  $export['panelizer_defaults_taxonomy_term_tags'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_user_user';
  $strongarm->value = array(
    'status' => 1,
    'view modes' => array(
      'page_manager' => array(
        'status' => 1,
        'default' => 1,
        'choice' => 0,
      ),
      'default' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_user_user'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:blog:default_selection';
  $strongarm->value = 0;
  $export['panelizer_node:blog:default_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:blog:full_selection';
  $strongarm->value = 0;
  $export['panelizer_node:blog:full_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:blog:page_manager_selection';
  $strongarm->value = 'node:blog:default';
  $export['panelizer_node:blog:page_manager_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:blog:teaser_large_selection';
  $strongarm->value = 0;
  $export['panelizer_node:blog:teaser_large_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:blog:teaser_selection';
  $strongarm->value = 0;
  $export['panelizer_node:blog:teaser_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:blog_allowed_layouts';
  $strongarm->value = 'O:22:"panels_allowed_layouts":4:{s:9:"allow_new";b:1;s:11:"module_name";s:19:"panelizer_node:blog";s:23:"allowed_layout_settings";a:9:{s:8:"flexible";b:1;s:14:"twocol_stacked";b:1;s:13:"twocol_bricks";b:1;s:25:"threecol_25_50_25_stacked";b:1;s:6:"onecol";b:1;s:6:"twocol";b:1;s:25:"threecol_33_34_33_stacked";b:1;s:17:"threecol_33_34_33";b:1;s:17:"threecol_25_50_25";b:1;}s:10:"form_state";N;}';
  $export['panelizer_node:blog_allowed_layouts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:blog_allowed_layouts_default';
  $strongarm->value = 0;
  $export['panelizer_node:blog_allowed_layouts_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:blog_allowed_types';
  $strongarm->value = array(
    'page_breadcrumb-page_breadcrumb' => 'page_breadcrumb-page_breadcrumb',
    'page_help-page_help' => 'page_help-page_help',
    'page_feed_icons-page_feed_icons' => 'page_feed_icons-page_feed_icons',
    'page_logo-page_logo' => 'page_logo-page_logo',
    'page_tabs-page_tabs' => 'page_tabs-page_tabs',
    'page_site_name-page_site_name' => 'page_site_name-page_site_name',
    'page_messages-page_messages' => 'page_messages-page_messages',
    'page_slogan-page_slogan' => 'page_slogan-page_slogan',
    'page_title-page_title' => 'page_title-page_title',
    'page_primary_links-page_primary_links' => 'page_primary_links-page_primary_links',
    'page_actions-page_actions' => 'page_actions-page_actions',
    'page_secondary_links-page_secondary_links' => 'page_secondary_links-page_secondary_links',
    'node_form_title-node_form_title' => 'node_form_title-node_form_title',
    'node_form_comment-node_form_comment' => 'node_form_comment-node_form_comment',
    'node_form_publishing-node_form_publishing' => 'node_form_publishing-node_form_publishing',
    'node_form_menu-node_form_menu' => 'node_form_menu-node_form_menu',
    'node_form_buttons-node_form_buttons' => 'node_form_buttons-node_form_buttons',
    'node_form_language-node_form_language' => 'node_form_language-node_form_language',
    'node_form_author-node_form_author' => 'node_form_author-node_form_author',
    'node_form_path-node_form_path' => 'node_form_path-node_form_path',
    'node_form_log-node_form_log' => 'node_form_log-node_form_log',
    'form-form' => 'form-form',
    'node-node' => 'node-node',
    'node_comments-node_comments' => 'node_comments-node_comments',
    'node_attachments-node_attachments' => 'node_attachments-node_attachments',
    'node_updated-node_updated' => 'node_updated-node_updated',
    'node_body-node_body' => 'node_body-node_body',
    'node_comment_form-node_comment_form' => 'node_comment_form-node_comment_form',
    'node_content-node_content' => 'node_content-node_content',
    'node_terms-node_terms' => 'node_terms-node_terms',
    'node_title-node_title' => 'node_title-node_title',
    'node_created-node_created' => 'node_created-node_created',
    'node_links-node_links' => 'node_links-node_links',
    'node_type_desc-node_type_desc' => 'node_type_desc-node_type_desc',
    'node_author-node_author' => 'node_author-node_author',
    'term_description-term_description' => 'term_description-term_description',
    'term_list-term_list' => 'term_list-term_list',
    'comment_reply_form-comment_reply_form' => 'comment_reply_form-comment_reply_form',
    'user_contact-user_contact' => 'user_contact-user_contact',
    'contact-contact' => 'contact-contact',
    'user_signature-user_signature' => 'user_signature-user_signature',
    'user_profile-user_profile' => 'user_profile-user_profile',
    'user_picture-user_picture' => 'user_picture-user_picture',
    'search_form-search_form' => 'search_form-search_form',
    'search_result-search_result' => 'search_result-search_result',
    'vocabulary_terms-vocabulary_terms' => 'vocabulary_terms-vocabulary_terms',
    'panelizer_form_default-panelizer_form_default' => 'panelizer_form_default-panelizer_form_default',
    'entity_form_field-comment:comment_body' => 'entity_form_field-comment:comment_body',
    'entity_form_field-node:body' => 'entity_form_field-node:body',
    'entity_form_field-node:field_tags' => 'entity_form_field-node:field_tags',
    'entity_form_field-node:field_image' => 'entity_form_field-node:field_image',
    'token-node:source' => 'token-node:source',
    'token-node:log' => 'token-node:log',
    'token-node:content-type' => 'token-node:content-type',
    'token-node:comment-count' => 'token-node:comment-count',
    'token-node:comment-count-new' => 'token-node:comment-count-new',
    'token-node:menu-link' => 'token-node:menu-link',
    'token-node:metatag' => 'token-node:metatag',
    'token-node:nid' => 'token-node:nid',
    'token-node:vid' => 'token-node:vid',
    'token-node:title' => 'token-node:title',
    'token-node:body' => 'token-node:body',
    'token-node:summary' => 'token-node:summary',
    'token-node:language' => 'token-node:language',
    'token-node:url' => 'token-node:url',
    'token-node:edit-url' => 'token-node:edit-url',
    'token-node:created' => 'token-node:created',
    'token-node:changed' => 'token-node:changed',
    'token-node:author' => 'token-node:author',
    'token-node:original' => 'token-node:original',
    'token-node:field_tags' => 'token-node:field_tags',
    'token-node:field_image' => 'token-node:field_image',
    'token-content-type:name' => 'token-content-type:name',
    'token-content-type:machine-name' => 'token-content-type:machine-name',
    'token-content-type:description' => 'token-content-type:description',
    'token-content-type:node-count' => 'token-content-type:node-count',
    'token-content-type:edit-url' => 'token-content-type:edit-url',
    'token-term:edit-url' => 'token-term:edit-url',
    'token-term:parents' => 'token-term:parents',
    'token-term:root' => 'token-term:root',
    'token-term:metatag' => 'token-term:metatag',
    'token-term:tid' => 'token-term:tid',
    'token-term:name' => 'token-term:name',
    'token-term:description' => 'token-term:description',
    'token-term:node-count' => 'token-term:node-count',
    'token-term:url' => 'token-term:url',
    'token-term:vocabulary' => 'token-term:vocabulary',
    'token-term:parent' => 'token-term:parent',
    'token-term:original' => 'token-term:original',
    'token-vocabulary:machine-name' => 'token-vocabulary:machine-name',
    'token-vocabulary:edit-url' => 'token-vocabulary:edit-url',
    'token-vocabulary:vid' => 'token-vocabulary:vid',
    'token-vocabulary:name' => 'token-vocabulary:name',
    'token-vocabulary:description' => 'token-vocabulary:description',
    'token-vocabulary:node-count' => 'token-vocabulary:node-count',
    'token-vocabulary:term-count' => 'token-vocabulary:term-count',
    'token-vocabulary:original' => 'token-vocabulary:original',
    'token-file:basename' => 'token-file:basename',
    'token-file:extension' => 'token-file:extension',
    'token-file:size-raw' => 'token-file:size-raw',
    'token-file:fid' => 'token-file:fid',
    'token-file:name' => 'token-file:name',
    'token-file:path' => 'token-file:path',
    'token-file:mime' => 'token-file:mime',
    'token-file:size' => 'token-file:size',
    'token-file:url' => 'token-file:url',
    'token-file:timestamp' => 'token-file:timestamp',
    'token-file:owner' => 'token-file:owner',
    'token-file:original' => 'token-file:original',
    'token-user:cancel-url' => 'token-user:cancel-url',
    'token-user:one-time-login-url' => 'token-user:one-time-login-url',
    'token-user:picture' => 'token-user:picture',
    'token-user:roles' => 'token-user:roles',
    'token-user:uid' => 'token-user:uid',
    'token-user:name' => 'token-user:name',
    'token-user:mail' => 'token-user:mail',
    'token-user:url' => 'token-user:url',
    'token-user:edit-url' => 'token-user:edit-url',
    'token-user:last-login' => 'token-user:last-login',
    'token-user:created' => 'token-user:created',
    'token-user:original' => 'token-user:original',
    'token-current-user:ip-address' => 'token-current-user:ip-address',
    'token-menu-link:mlid' => 'token-menu-link:mlid',
    'token-menu-link:title' => 'token-menu-link:title',
    'token-menu-link:url' => 'token-menu-link:url',
    'token-menu-link:parent' => 'token-menu-link:parent',
    'token-menu-link:parents' => 'token-menu-link:parents',
    'token-menu-link:root' => 'token-menu-link:root',
    'token-menu-link:menu' => 'token-menu-link:menu',
    'token-menu-link:edit-url' => 'token-menu-link:edit-url',
    'token-current-page:title' => 'token-current-page:title',
    'token-current-page:url' => 'token-current-page:url',
    'token-current-page:page-number' => 'token-current-page:page-number',
    'token-current-page:query' => 'token-current-page:query',
    'token-url:path' => 'token-url:path',
    'token-url:relative' => 'token-url:relative',
    'token-url:absolute' => 'token-url:absolute',
    'token-url:brief' => 'token-url:brief',
    'token-url:unaliased' => 'token-url:unaliased',
    'token-url:args' => 'token-url:args',
    'token-array:first' => 'token-array:first',
    'token-array:last' => 'token-array:last',
    'token-array:count' => 'token-array:count',
    'token-array:reversed' => 'token-array:reversed',
    'token-array:keys' => 'token-array:keys',
    'token-array:join' => 'token-array:join',
    'token-array:value' => 'token-array:value',
    'token-array:join-path' => 'token-array:join-path',
    'token-random:number' => 'token-random:number',
    'token-random:hash' => 'token-random:hash',
    'token-comment:cid' => 'token-comment:cid',
    'token-comment:hostname' => 'token-comment:hostname',
    'token-comment:name' => 'token-comment:name',
    'token-comment:mail' => 'token-comment:mail',
    'token-comment:homepage' => 'token-comment:homepage',
    'token-comment:title' => 'token-comment:title',
    'token-comment:body' => 'token-comment:body',
    'token-comment:url' => 'token-comment:url',
    'token-comment:edit-url' => 'token-comment:edit-url',
    'token-comment:created' => 'token-comment:created',
    'token-comment:changed' => 'token-comment:changed',
    'token-comment:parent' => 'token-comment:parent',
    'token-comment:node' => 'token-comment:node',
    'token-comment:author' => 'token-comment:author',
    'token-comment:original' => 'token-comment:original',
    'token-menu:name' => 'token-menu:name',
    'token-menu:machine-name' => 'token-menu:machine-name',
    'token-menu:description' => 'token-menu:description',
    'token-menu:menu-link-count' => 'token-menu:menu-link-count',
    'token-menu:edit-url' => 'token-menu:edit-url',
    'token-metatag:title' => 'token-metatag:title',
    'token-metatag:description' => 'token-metatag:description',
    'token-metatag:abstract' => 'token-metatag:abstract',
    'token-metatag:keywords' => 'token-metatag:keywords',
    'token-metatag:robots' => 'token-metatag:robots',
    'token-metatag:news_keywords' => 'token-metatag:news_keywords',
    'token-metatag:standout' => 'token-metatag:standout',
    'token-metatag:generator' => 'token-metatag:generator',
    'token-metatag:rights' => 'token-metatag:rights',
    'token-metatag:image_src' => 'token-metatag:image_src',
    'token-metatag:canonical' => 'token-metatag:canonical',
    'token-metatag:shortlink' => 'token-metatag:shortlink',
    'token-metatag:publisher' => 'token-metatag:publisher',
    'token-metatag:author' => 'token-metatag:author',
    'token-metatag:original-source' => 'token-metatag:original-source',
    'token-metatag:revisit-after' => 'token-metatag:revisit-after',
    'token-metatag:content-language' => 'token-metatag:content-language',
    'token-site:name' => 'token-site:name',
    'token-site:slogan' => 'token-site:slogan',
    'token-site:mail' => 'token-site:mail',
    'token-site:url' => 'token-site:url',
    'token-site:url-brief' => 'token-site:url-brief',
    'token-site:login-url' => 'token-site:login-url',
    'token-date:short' => 'token-date:short',
    'token-date:medium' => 'token-date:medium',
    'token-date:long' => 'token-date:long',
    'token-date:custom' => 'token-date:custom',
    'token-date:since' => 'token-date:since',
    'token-date:raw' => 'token-date:raw',
    'token-view:name' => 'token-view:name',
    'token-view:description' => 'token-view:description',
    'token-view:machine-name' => 'token-view:machine-name',
    'token-view:title' => 'token-view:title',
    'token-view:url' => 'token-view:url',
    'entity_field_extra-taxonomy_term:description' => 'entity_field_extra-taxonomy_term:description',
    'entity_field_extra-user:summary' => 'entity_field_extra-user:summary',
    'entity_field-comment:comment_body' => 'entity_field-comment:comment_body',
    'entity_field-node:body' => 'entity_field-node:body',
    'entity_field-node:field_tags' => 'entity_field-node:field_tags',
    'entity_field-node:field_image' => 'entity_field-node:field_image',
    'block-blog-recent' => 'block-blog-recent',
    'block-comment-recent' => 'block-comment-recent',
    'block-menu-devel' => 'block-menu-devel',
    'block-node-syndicate' => 'block-node-syndicate',
    'block-node-recent' => 'block-node-recent',
    'block-search-form' => 'block-search-form',
    'block-system-powered-by' => 'block-system-powered-by',
    'block-system-help' => 'block-system-help',
    'block-system-navigation' => 'block-system-navigation',
    'block-system-management' => 'block-system-management',
    'block-system-user-menu' => 'block-system-user-menu',
    'block-system-main-menu' => 'block-system-main-menu',
    'block-user-login' => 'block-user-login',
    'block-user-new' => 'block-user-new',
    'block-user-online' => 'block-user-online',
    'block-devel-execute_php' => 'block-devel-execute_php',
    'block-devel-switch_user' => 'block-devel-switch_user',
    'custom-custom' => 'custom-custom',
  );
  $export['panelizer_node:blog_allowed_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:blog_allowed_types_default';
  $strongarm->value = 0;
  $export['panelizer_node:blog_allowed_types_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:blog_default';
  $strongarm->value = array(
    'entity_form_field' => 'entity_form_field',
    'token' => 'token',
    'entity_field_extra' => 'entity_field_extra',
    'entity_field' => 'entity_field',
    'block' => 'block',
    'custom' => 'custom',
    'panels_mini' => 'panels_mini',
    'other' => 'other',
  );
  $export['panelizer_node:blog_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:help:default_selection';
  $strongarm->value = 0;
  $export['panelizer_node:help:default_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:help:page_manager_selection';
  $strongarm->value = 'node:help:default';
  $export['panelizer_node:help:page_manager_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:help:teaser_large_selection';
  $strongarm->value = 0;
  $export['panelizer_node:help:teaser_large_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:help:teaser_selection';
  $strongarm->value = 0;
  $export['panelizer_node:help:teaser_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:help_allowed_layouts';
  $strongarm->value = 'O:22:"panels_allowed_layouts":4:{s:9:"allow_new";b:1;s:11:"module_name";s:19:"panelizer_node:help";s:23:"allowed_layout_settings";a:32:{s:8:"flexible";b:1;s:14:"twocol_stacked";b:1;s:6:"onecol";b:1;s:6:"twocol";b:1;s:25:"threecol_25_50_25_stacked";b:1;s:17:"threecol_33_34_33";b:1;s:25:"threecol_33_34_33_stacked";b:1;s:17:"threecol_25_50_25";b:1;s:13:"twocol_bricks";b:1;s:25:"mothership-html5page-page";b:1;s:22:"mothership-3colstacked";b:1;s:22:"mothership-2colstacked";b:1;s:20:"mothership-prototype";b:1;s:6:"two_50";b:1;s:14:"three_25_50_25";b:1;s:16:"three_inset_left";b:1;s:9:"two_66_33";b:1;s:13:"two_33_66_alt";b:1;s:3:"one";b:1;s:17:"three_inset_right";b:1;s:8:"three_33";b:1;s:6:"one_fw";b:1;s:9:"two_33_66";b:1;s:7:"four_25";b:1;s:9:"two_brick";b:1;s:6:"one_mp";b:1;s:9:"two_50_mp";b:1;s:11:"three_33_mp";b:1;s:10:"four_25_mp";b:1;s:9:"one_mp_fw";b:1;s:14:"three_33_mp_fw";b:1;s:12:"two_50_mp_fw";b:1;}s:10:"form_state";N;}';
  $export['panelizer_node:help_allowed_layouts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:help_allowed_layouts_default';
  $strongarm->value = 1;
  $export['panelizer_node:help_allowed_layouts_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:help_allowed_types_default';
  $strongarm->value = 1;
  $export['panelizer_node:help_allowed_types_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:help_default';
  $strongarm->value = array(
    'block' => 'block',
    'entity_form_field' => 'entity_form_field',
    'entity_field_extra' => 'entity_field_extra',
    'entity_field' => 'entity_field',
    'custom' => 'custom',
    'token' => 'token',
    'entity_view' => 'entity_view',
    'flag_link' => 'flag_link',
    'panels_mini' => 'panels_mini',
    'other' => 'other',
  );
  $export['panelizer_node:help_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:page:default_selection';
  $strongarm->value = 0;
  $export['panelizer_node:page:default_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:page:page_manager_selection';
  $strongarm->value = 'node:page:default';
  $export['panelizer_node:page:page_manager_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:page:teaser_large_selection';
  $strongarm->value = 0;
  $export['panelizer_node:page:teaser_large_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:page:teaser_selection';
  $strongarm->value = 0;
  $export['panelizer_node:page:teaser_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:staff:default_selection';
  $strongarm->value = 0;
  $export['panelizer_node:staff:default_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:staff:page_manager_selection';
  $strongarm->value = 'node:staff:default';
  $export['panelizer_node:staff:page_manager_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:staff:teaser_large_selection';
  $strongarm->value = 0;
  $export['panelizer_node:staff:teaser_large_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:staff:teaser_selection';
  $strongarm->value = 0;
  $export['panelizer_node:staff:teaser_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:webform:default_selection';
  $strongarm->value = 0;
  $export['panelizer_node:webform:default_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:webform:page_manager_selection';
  $strongarm->value = 'node:webform:default';
  $export['panelizer_node:webform:page_manager_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:webform:teaser_large_selection';
  $strongarm->value = 0;
  $export['panelizer_node:webform:teaser_large_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:webform:teaser_selection';
  $strongarm->value = 0;
  $export['panelizer_node:webform:teaser_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_user:user:default_selection';
  $strongarm->value = 0;
  $export['panelizer_user:user:default_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_user:user:page_manager_selection';
  $strongarm->value = 'user:user:default';
  $export['panelizer_user:user:page_manager_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panels_page_allowed_layouts';
  $strongarm->value = 'O:22:"panels_allowed_layouts":4:{s:9:"allow_new";b:1;s:11:"module_name";s:11:"panels_page";s:23:"allowed_layout_settings";a:29:{s:8:"flexible";b:1;s:14:"twocol_stacked";b:1;s:13:"twocol_bricks";b:1;s:25:"threecol_25_50_25_stacked";b:1;s:6:"onecol";b:1;s:6:"twocol";b:1;s:25:"threecol_33_34_33_stacked";b:1;s:17:"threecol_33_34_33";b:1;s:17:"threecol_25_50_25";b:1;s:25:"mothership-html5page-page";b:1;s:12:"two_50_mp_fw";b:1;s:9:"one_mp_fw";b:1;s:14:"three_33_mp_fw";b:1;s:8:"three_33";b:1;s:13:"two_33_66_alt";b:1;s:6:"two_50";b:1;s:6:"one_fw";b:1;s:14:"three_25_50_25";b:1;s:16:"three_inset_left";b:1;s:3:"one";b:1;s:9:"two_brick";b:1;s:7:"four_25";b:1;s:9:"two_33_66";b:1;s:17:"three_inset_right";b:1;s:9:"two_66_33";b:1;s:11:"three_33_mp";b:1;s:6:"one_mp";b:1;s:10:"four_25_mp";b:1;s:9:"two_50_mp";b:1;}s:10:"form_state";N;}';
  $export['panels_page_allowed_layouts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panels_page_default';
  $strongarm->value = array(
    'entity_form_field' => 'entity_form_field',
    'token' => 'token',
    'entity_field_extra' => 'entity_field_extra',
    'entity_field' => 'entity_field',
    'block' => 'block',
    'custom' => 'custom',
    'panels_mini' => 'panels_mini',
    'other' => 'other',
  );
  $export['panels_page_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'themekey_attributes';
  $strongarm->value = array(
    'blog:uid' => array(
      'description' => 'Blog: User ID - The id of the user (uid) who owns the blog.',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 1,
    ),
    'comment:cid' => array(
      'description' => 'Comment: ID - The id of a comment (cid). See <a href="/admin/content/comment">admin/content/comment</a> for your published comments or <a href="/admin/content/comment/approval">admin/content/comment/approval</a> for comments awaiting approval',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 1,
    ),
    'drupal:base_path' => array(
      'description' => 'Drupal: Base path - If Drupal is installed in a subdirectory, the base path will be \'/[subdirectory]/\', otherwise just \'/\'.',
      'page cache' => 1,
    ),
    'drupal:get_q' => array(
      'description' => 'Drupal: $_GET[\'q\'] - Current value of Drupal\'s query parameter "q"',
      'validator' => '',
      'page cache' => 1,
    ),
    'drupal:is_front_page' => array(
      'description' => 'Drupal: Is front page - \'true\' if current page is front page, otherwise just \'false\'.',
      'validator' => 'themekey_validator_string_boolean',
      'page cache' => 1,
    ),
    'drupal:path' => array(
      'description' => 'Drupal: Drupal path like "node/add/story" or path alias with support for wildcards.<br />
Query parameters are stripped off before the path gets examined. P.e. "node/add/story?destination=node" becomes "node/add/story" first. If you want to access query parameters, have a look at the <strong>system:query_param</strong> property.<br />
Wildcard characters are "#" for numeric parts and "%" for all characters. To match conditions against a certain part, use an identifier with the wildcard. For example "comment/reply/#xyz" matches all paths with "comment/reply" and a numeric third argument. You can then specify conditions for every wildcard argument using the property "drupal:path:wildcard" and the identifier you choose ("xyz" in this example).<br />
These are the possible wildcard replacements for foo/bar/42/test.html:<pre>
foo/bar/42/test.html
foo/bar/42/%
foo/bar/42
foo/bar/%/test.html
foo/bar/%/%
foo/bar/%
foo/bar/#/test.html
foo/bar/#/%
foo/bar/#
foo/bar
foo/%/42/test.html
foo/%/42/%
foo/%/42
foo/%/%/test.html
foo/%/%/%
foo/%/%
foo/%/#/test.html
foo/%/#/%
foo/%/#
foo/%
foo
%/bar/42/test.html
%/bar/42/%
%/bar/42
%/bar/%/test.html
%/bar/%/%
%/bar/%
%/bar/#/test.html
%/bar/#/%
%/bar/#
%/bar
%/%/42/test.html
%/%/42/%
%/%/42
%/%/%/test.html
%/%/%/%
%/%/%
%/%/#/test.html
%/%/#/%
%/%/#
%/%
%
</pre>',
      'validator' => 'themekey_validator_drupal_path',
      'page cache' => 1,
    ),
    'drupal:path:wildcard' => array(
      'description' => 'Wildcard of "drupal:path". See explanation of "drupal:path" for details.',
      'validator' => 'themekey_validator_wildcard',
      'page cache' => 1,
    ),
    'drupal:path_is_admin' => array(
      'description' => 'Drupal: Path is admin - \'true\' if current page\'s path belongs to the admin section, otherwise just \'false\'.',
      'validator' => 'themekey_validator_string_boolean',
      'page cache' => 1,
    ),
    'node:body_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">body</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:body_summary' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">summary</em> of the field <em class="placeholder">body</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:body_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">body</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:changed' => array(
      'description' => 'Node: Changed date - The date when the node was last edited/updated, formatted as unix timestamp like "1248873565".',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 1,
    ),
    'node:changed_date' => array(
      'description' => 'Node: Changed date - The date without the time when the node was last edited/updated, formatted like "2009-12-24"',
      'validator' => 'themekey_validator_date',
      'page cache' => 1,
    ),
    'node:changed_date_time' => array(
      'description' => 'Node: Changed date - The date including the time when the node was last edited/updated, formatted like "2009-12-24 18:13:24"',
      'validator' => 'themekey_validator_date_time',
      'page cache' => 1,
    ),
    'node:created' => array(
      'description' => 'Node: Created date - The date when the node was created, formatted as unix timestamp like "1248873565".',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 1,
    ),
    'node:created_date' => array(
      'description' => 'Node: Created date - The date without the time when the node was created, formatted like "2009-12-24"',
      'validator' => 'themekey_validator_date',
      'page cache' => 1,
    ),
    'node:created_date_time' => array(
      'description' => 'Node: Created date - The date including the time when the node was created, formatted like "2009-12-24 18:13:24"',
      'validator' => 'themekey_validator_date_time',
      'page cache' => 1,
    ),
    'node:field_ad_category_tid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">tid</em> of the field <em class="placeholder">field_ad_category</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_ad_end_date_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_ad_end_date</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_ad_end_date_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_ad_end_date</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_ad_flash_description' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">description</em> of the field <em class="placeholder">field_ad_flash</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_ad_flash_display' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">display</em> of the field <em class="placeholder">field_ad_flash</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_ad_flash_fid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">fid</em> of the field <em class="placeholder">field_ad_flash</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_ad_image_alt' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">alt</em> of the field <em class="placeholder">field_ad_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_ad_image_fid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">fid</em> of the field <em class="placeholder">field_ad_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_ad_image_height' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">height</em> of the field <em class="placeholder">field_ad_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_ad_image_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_ad_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_ad_image_width' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">width</em> of the field <em class="placeholder">field_ad_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_ad_start_date_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_ad_start_date</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_ad_start_date_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_ad_start_date</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_ad_status_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_ad_status</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_ad_text_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_ad_text</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_ad_text_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_ad_text</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_ad_type_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_ad_type</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_ad_url_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_ad_url</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_ad_url_taget_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_ad_url_taget</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_ad_url_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_ad_url</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_ask_question_tid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">tid</em> of the field <em class="placeholder">field_ask_question</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_blog_images_alt' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">alt</em> of the field <em class="placeholder">field_blog_images</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_blog_images_fid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">fid</em> of the field <em class="placeholder">field_blog_images</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_blog_images_height' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">height</em> of the field <em class="placeholder">field_blog_images</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_blog_images_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_blog_images</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_blog_images_width' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">width</em> of the field <em class="placeholder">field_blog_images</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_cover_alt' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">alt</em> of the field <em class="placeholder">field_cover</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_cover_fid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">fid</em> of the field <em class="placeholder">field_cover</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_cover_height' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">height</em> of the field <em class="placeholder">field_cover</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_cover_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_cover</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_cover_width' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">width</em> of the field <em class="placeholder">field_cover</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_event_dates_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_event_dates</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_event_dates_value2' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value2</em> of the field <em class="placeholder">field_event_dates</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_facebook_external_id_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_facebook_external_id</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_facebook_external_id_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_facebook_external_id</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_facebook_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_facebook</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_facebook_link_attributes' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">attributes</em> of the field <em class="placeholder">field_facebook_link</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_facebook_link_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_facebook_link</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_facebook_link_url' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">url</em> of the field <em class="placeholder">field_facebook_link</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_facebook_picture_alt' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">alt</em> of the field <em class="placeholder">field_facebook_picture</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_facebook_picture_fid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">fid</em> of the field <em class="placeholder">field_facebook_picture</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_facebook_picture_height' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">height</em> of the field <em class="placeholder">field_facebook_picture</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_facebook_picture_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_facebook_picture</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_facebook_picture_width' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">width</em> of the field <em class="placeholder">field_facebook_picture</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_facebook_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_facebook</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_game_category_tid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">tid</em> of the field <em class="placeholder">field_game_category</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_google_plus_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_google_plus</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_google_plus_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_google_plus</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_image_alt' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">alt</em> of the field <em class="placeholder">field_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_image_fid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">fid</em> of the field <em class="placeholder">field_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_image_height' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">height</em> of the field <em class="placeholder">field_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_image_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_image_width' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">width</em> of the field <em class="placeholder">field_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_player_background_alt' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">alt</em> of the field <em class="placeholder">field_player_background</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_player_background_fid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">fid</em> of the field <em class="placeholder">field_player_background</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_player_background_height' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">height</em> of the field <em class="placeholder">field_player_background</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_player_background_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_player_background</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_player_background_width' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">width</em> of the field <em class="placeholder">field_player_background</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_proffesion_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_proffesion</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_proffesion_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_proffesion</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_reddit_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_reddit</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_reddit_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_reddit</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_right_side_listing_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_right_side_listing</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_staff_image_alt' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">alt</em> of the field <em class="placeholder">field_staff_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_staff_image_fid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">fid</em> of the field <em class="placeholder">field_staff_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_staff_image_height' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">height</em> of the field <em class="placeholder">field_staff_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_staff_image_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_staff_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_staff_image_width' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">width</em> of the field <em class="placeholder">field_staff_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_stream_category_tid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">tid</em> of the field <em class="placeholder">field_stream_category</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_stream_image_alt' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">alt</em> of the field <em class="placeholder">field_stream_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_stream_image_fid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">fid</em> of the field <em class="placeholder">field_stream_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_stream_image_height' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">height</em> of the field <em class="placeholder">field_stream_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_stream_image_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_stream_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_stream_image_width' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">width</em> of the field <em class="placeholder">field_stream_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_streams_target_id' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">target_id</em> of the field <em class="placeholder">field_streams</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_tags_tid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">tid</em> of the field <em class="placeholder">field_tags</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_tweet_external_id_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_tweet_external_id</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_tweet_external_id_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_tweet_external_id</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_tweet_link_attributes' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">attributes</em> of the field <em class="placeholder">field_tweet_link</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_tweet_link_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_tweet_link</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_tweet_link_url' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">url</em> of the field <em class="placeholder">field_tweet_link</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_tweet_user_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_tweet_user</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_tweet_user_name_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_tweet_user_name</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_tweet_user_name_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_tweet_user_name</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_tweet_user_picture_alt' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">alt</em> of the field <em class="placeholder">field_tweet_user_picture</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_tweet_user_picture_fid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">fid</em> of the field <em class="placeholder">field_tweet_user_picture</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_tweet_user_picture_height' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">height</em> of the field <em class="placeholder">field_tweet_user_picture</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_tweet_user_picture_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_tweet_user_picture</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_tweet_user_picture_width' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">width</em> of the field <em class="placeholder">field_tweet_user_picture</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_tweet_user_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_tweet_user</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_twitch_team_name_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_twitch_team_name</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_twitch_team_name_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_twitch_team_name</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_twitch_team_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_twitch_team</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_twitter_feed_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_twitter_feed</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_twitter_feed_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_twitter_feed</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_twitter_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_twitter</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_twitter_id_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_twitter_id</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_twitter_id_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_twitter_id</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_twitter_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_twitter</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_website_attributes' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">attributes</em> of the field <em class="placeholder">field_website</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_website_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_website</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_website_url' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">url</em> of the field <em class="placeholder">field_website</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_youtube_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_youtube</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_youtube_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_youtube</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:language' => array(
      'description' => 'Node: Language - The code of the selected language of a node (formatted like "en" or "de") or "neutral". See <a href="/admin/config/language">admin/config/language</a> for the codes of your enabled languages',
      'validator' => 'themekey_validator_language',
      'page cache' => 1,
    ),
    'node:nid' => array(
      'description' => 'Node: ID - The id of a node (nid), can be found in the URL of the node, "node/23" or "node/23/edit" (23 = nid)',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 1,
    ),
    'node:promote' => array(
      'description' => 'Node: Promoted - If the node is promoted to the front page. Possible values are "0" for true and "1" for false.',
      'validator' => 'themekey_validator_numeric_boolean',
      'page cache' => 1,
    ),
    'node:sticky' => array(
      'description' => 'Node: Sticky - If the node is set "Sticky at top of lists". Possible values are "0" for true and "1" for false.',
      'validator' => 'themekey_validator_numeric_boolean',
      'page cache' => 1,
    ),
    'node:title' => array(
      'description' => 'Node: Title - The title of the node.',
      'page cache' => 1,
    ),
    'node:type' => array(
      'description' => 'Node: Type - The machine-readable content type of the node. See <a href="/admin/structure/types">admin/structure/types</a> for your content types (use column "Type"). Drupal default types are "page" and "story".',
      'validator' => 'themekey_validator_node_type',
      'page cache' => 1,
    ),
    'node:uid' => array(
      'description' => 'Node: User ID - The node author\'s user id (uid). The user id can be found in the URL of the user\'s profile page, "user/23" or "user/23/edit" (23 = uid). See <a href="/admin/user/user/list">admin/user/user/list</a> for your users.',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 1,
    ),
    'node:vid' => array(
      'description' => 'Node: The version id of a node (vid), mostly for internal use within ThemeKey. In most cases it\'s better to use node:nid within your rule chains.',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 1,
    ),
    'path:node_alias' => array(
      'description' => 'Path: Node alias - The path alias assigned to a node.',
      'validator' => '',
      'page cache' => 1,
    ),
    'system:cookie' => array(
      'description' => 'System: Cookie - Every single cookie and its value if present will be formatted like \'COOKIE_NAME=COOKIE_VALUE\'',
      'page cache' => 0,
    ),
    'system:date' => array(
      'description' => 'System: Date - Current time formatted as Y-m-d (example: 2009-12-24)',
      'validator' => 'themekey_validator_date',
      'page cache' => 2,
    ),
    'system:date_time' => array(
      'description' => 'System: Date Time - Current time formatted as Y-m-d H:i:s (example: 2009-12-24 18:30:10)',
      'validator' => 'themekey_validator_date_time',
      'page cache' => 2,
    ),
    'system:day_of_month' => array(
      'description' => 'System: Day of Month - Current day of the month formatted as 1 - 31',
      'validator' => 'themekey_validator_day_of_month',
      'page cache' => 2,
    ),
    'system:day_of_week' => array(
      'description' => 'System: Day of Week - Current day of the week formatted as three letters \'Mon\' through \'Sun\'',
      'validator' => 'themekey_validator_day_of_week',
      'page cache' => 2,
    ),
    'system:dummy' => array(
      'description' => 'System: Dummy - Dummy property. Value is always \'dummy\'',
      'page cache' => 1,
    ),
    'system:host' => array(
      'description' => 'System: HTTP_HOST - The hostname/domain of the site without http:// or https://, like "www.drupal.org" or "www.biologis.com"',
      'validator' => 'themekey_validator_http_host',
      'page cache' => 1,
    ),
    'system:http_header' => array(
      'description' => 'System: HTTP Header - Every single HTTP header and its value if present will be formatted like \'HEADER_NAME=HEADER_VALUE\'',
      'page cache' => 0,
    ),
    'system:https' => array(
      'description' => 'System: \'HTTPS\' - Set to \'true\' value if the script was queried through the HTTPS protocol, otherwise \'false\'.',
      'validator' => 'themekey_validator_string_boolean',
      'page cache' => 1,
    ),
    'system:month' => array(
      'description' => 'System: Month - Current month formatted as \'Jan\' through \'Dec\'',
      'validator' => 'themekey_validator_month',
      'page cache' => 2,
    ),
    'system:post' => array(
      'description' => 'System: POST - Every single POST value formatted like \'POST_VARIABLE_NAME=POST_VARIABLE_VALUE\'. Example: form_id=node_form. If the POST value is not a scalar but a complex type like array or object, the resulting string is formatted as \'POST_VARIABLE_NAME\' without a value.',
      'page cache' => 0,
    ),
    'system:query_param' => array(
      'description' => 'System: Query Parameter - Every single query parameter other than \'q\' and its value, if present. Note that values are url decoded. Example: \'?q=node&foo=bar&dummy&filter=tid%3A27\' will cause three entries \'foo=bar\', \'dummy\' and \'filter=tid:27\'. For \'q\', see property drupal:get_q.',
      'page cache' => 1,
    ),
    'system:query_string' => array(
      'description' => 'System: Query String - Complete query string except parameter \'q\'. Example: \'?q=node&foo=bar&dummy&filter=tid%3A27\' will result in \'foo=bar&dummy&filter=tid%3A27\'. For \'q\' see property drupal:get_q.',
      'page cache' => 1,
    ),
    'system:random' => array(
      'description' => 'System: Random - A random value that could be \'0\' or 1\'.',
      'validator' => 'themekey_validator_numeric_boolean',
      'page cache' => 0,
    ),
    'system:referer' => array(
      'description' => 'System: \'HTTP_REFERER\' - The address of the page (if any) which referred the user agent to the current page. This is set by the user agent. Not all user agents will set this, and some provide the ability to modify HTTP_REFERER as a feature. In short, it cannot really be trusted.',
      'page cache' => 0,
    ),
    'system:remote_ip' => array(
      'description' => 'System: \'REMOTE_ADDR\' - The IP address from which the user is viewing the current page.',
      'validator' => 'themekey_validator_ip_address',
      'page cache' => 0,
    ),
    'system:server_ip' => array(
      'description' => 'System: \'SERVER_ADDR\' - The IP address of the server under which the current script is executing.',
      'validator' => 'themekey_validator_ip_address',
      'page cache' => 0,
    ),
    'system:server_name' => array(
      'description' => 'System:  \'SERVER_NAME\' - The name of the server host under which the current script is executing. If the script is running on a virtual host, this will be the value defined for that virtual host.',
      'page cache' => 0,
    ),
    'system:server_port' => array(
      'description' => 'System: \'SERVER_PORT\' - The port on the server machine being used by the web server for communication. For default setups, this will be \'80\'; using SSL, for instance, will change this to whatever your defined secure HTTP port is.',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 0,
    ),
    'system:session' => array(
      'description' => 'System: Session - Every single session parameter and its value, if a value is present and a simple type (string, integer, boolean). Booleans are represented as integers; \'1\' as TRUE and \'0\' as FALSE.',
      'page cache' => 1,
    ),
    'system:time' => array(
      'description' => 'System: Time - Current time formatted as H:i:s (example: 18:30:10)',
      'validator' => 'themekey_validator_time',
      'page cache' => 2,
    ),
    'system:user_agent' => array(
      'description' => 'System: \'HTTP_USER_AGENT\' - Contents of the User-Agent: header from the current request, if there is one. This is a string denoting the user agent which is accessing the page. A typical example is: Mozilla/4.5 [en] (X11; U; Linux 2.2.9 i586).',
      'page cache' => 0,
    ),
    'system:user_browser' => array(
      'description' => 'System: Browser - Information about user\'s browser. Possible values: \'Blazer [VERSION]\', \'Internet Explorer [VERSION]\', \'Internet Explorer Mobile [VERSION]\', \'Mozilla Firefox [VERSION]\', \'Netscape [VERSION]\', \'Google Chrome [VERSION]\', \'Safari [VERSION]\', \'Galeon [VERSION]\', \'Konqueror [VERSION]\', \'Gecko based\', \'Opera [VERSION]\', \'Lynx [VERSION]\', \'Fennec [VERSION]\', \'Maemo [VERSION]\', \'unknown\'',
      'page cache' => 0,
      'deprecated' => TRUE,
      'deprecated message' => 'Property system:user_browser is deprecated. Consider to use one of the new properties ThemeKey provides in combination with <a href="https://drupal.org/project/browscap">Browscap</a>, <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect API</a>, or <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect</a>.',
    ),
    'system:user_browser_simplified' => array(
      'description' => 'System: Browser - Simplified information about user\'s browser. Possible values: \'Blazer\', \'Internet Explorer\', \'Internet Explorer Mobile\', \'Mozilla Firefox\', \'Netscape\', \'Google Chrome\', \'Safari\', \'Galeon\', \'Konqueror\', \'Gecko based\', \'Opera\', \'Lynx\', \'Fennec\', \'Maemo\', \'unknown\'',
      'page cache' => 0,
      'deprecated' => TRUE,
      'deprecated message' => 'Property system:user_browser_simplified is deprecated. Consider to use one of the new properties ThemeKey provides in combination with <a href="https://drupal.org/project/browscap">Browscap</a>, <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect API</a>, or <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect</a>.',
    ),
    'system:user_os' => array(
      'description' => 'System: Operating System - Information about user\'s browser. Possible values: \'Windows XP\', \'Windows Vista\', \'Windows 98\', \'Windows 2000\', \'Windows 2003 server\', \'Windows NT\',  \'Windows ME\', \'Windows CE\', \'Windows ME\', \'Windows Phone\', \'iPhone\', \'iPad\', \'Mac OS X\', \'Macintosh\', \'Linux\', \'Free BSD\', \'Symbian\', \'webOS\', \'Android\', \'Blackberry\', \'unknown\'',
      'page cache' => 0,
      'deprecated' => TRUE,
      'deprecated message' => 'Property system:user_os is deprecated. Consider to use one of the new properties ThemeKey provides in combination with <a href="https://drupal.org/project/browscap">Browscap</a>, <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect API</a>, or <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect</a>.',
    ),
    'system:user_os_simplified' => array(
      'description' => 'System: Operating System - Simplified information about user\'s browser. Possible values: \'Windows\', \'Windows Phone\', \'iPhone\', \'iPad\', \'Mac OS X\', \'Macintosh\', \'Linux\', \'Free BSD\', \'Symbian\', \'webOS\', \'Android\', \'Blackberry\', \'unknown\'',
      'page cache' => 0,
      'deprecated' => TRUE,
      'deprecated message' => 'Property system:user_os_simplified is deprecated. Consider to use one of the new properties ThemeKey provides in combination with <a href="https://drupal.org/project/browscap">Browscap</a>, <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect API</a>, or <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect</a>.',
    ),
    'taxonomy:name' => array(
      'description' => 'Taxonomy: Name - The term name (name) of a taxonomy term without support for translations.',
      'validator' => '',
      'page cache' => 1,
    ),
    'taxonomy:tid' => array(
      'description' => 'Taxonomy: Term - The term id (tid) of a taxonomy term.',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 1,
    ),
    'taxonomy:tid_and_childs' => array(
      'description' => 'Taxonomy: Term and its childs - The term id (tid) of a taxonomy term. If set, all child terms of this term will be used too.',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 0,
    ),
    'taxonomy:vid' => array(
      'description' => 'Taxonomy: Vocabulary - The vocabulary id (vid) of a taxonomy vocabulary. See <a href="/admin/structure/taxonomy">admin/structure/taxonomy</a> for your vocabularies.',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 1,
    ),
    'themekey_ui:author_triggers_theme' => array(
      'description' => 'The property, themekey_ui:author_triggers_theme, could not be selected from the property drop down. You get this static property by activating <a href="/admin/config/user-interface/themekey/settings/ui">Let the user select a theme that will be used to display all content she creates.</a>. Afterwards, you can move the property to any position in the rule chain. When done, it triggers the switch to the theme the author selected in her user profile for own content, a contact form or blog pages.',
      'page cache' => 1,
      'static' => TRUE,
    ),
    'themekey_ui:node_triggers_theme' => array(
      'description' => 'The property, themekey_ui:node_triggers_theme, could not be selected from the property drop-down. You get this static property by activating <a href="/admin/config/user-interface/themekey/settings/ui">Show theme option in create/edit node forms</a>. Afterwards, you can move the property to any position in the rule chain. When done, it triggers the switch to the theme assigned to the current node using ThemeKey UI.',
      'page cache' => 1,
      'static' => TRUE,
    ),
    'user:hostname' => array(
      'description' => 'User: Hostname - The user hostname property which is the IP address of client machine, adjusted for reverse proxy. Text from Drupal bootstrap.inc:
      If Drupal is behind a reverse proxy, we use the X-Forwarded-For header instead of $_SERVER[\'REMOTE_ADDR\'], which would be the IP address of the proxy server, and not the client\'s.',
      'validator' => 'themekey_validator_http_host',
      'page cache' => 0,
    ),
    'user:language' => array(
      'description' => 'User: Language - The language the user has set in the settings of his profile page.
      Format is the language code (for example "en" for English or "de" for German) that can be found on <a href="/admin/config/regional/language/overview">admin/config/regional/language/overview</a>.',
      'validator' => 'themekey_validator_language',
      'page cache' => 1,
    ),
    'user:name' => array(
      'description' => 'User: Name - The username of the user. See <a href="/admin/people/people">admin/people/people</a> for your users.',
      'page cache' => 1,
    ),
    'user:role' => array(
      'description' => 'User: Role - Defined user roles (examples: \'anonymous user\', \'authenticated user\')',
      'validator' => 'themekey_validator_role',
      'page cache' => 1,
    ),
    'user:uid' => array(
      'description' => 'User: ID - The id of the user (uid). The user id can be found in the URL of the users profile page, "user/23" or "user/23/edit" (23 = uid). See <a href="/admin/people/people">admin/people/people</a> for your users.',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 1,
    ),
    'views:human_name' => array(
      'description' => 'Views: Human Name - The (human readable) name of a view',
      'page cache' => 1,
    ),
    'views:machine_name' => array(
      'description' => 'Views: Machine Name - The machine name of a view',
      'page cache' => 1,
    ),
    'views:vid' => array(
      'description' => 'Views: VID - The vid of a view (vid)',
      'validator' => 'themekey_validator_ctype_digit',
      'page cache' => 1,
    ),
  );
  $export['themekey_attributes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'themekey_maps';
  $strongarm->value = array(
    0 => array(
      'src' => 'node:nid',
      'dst' => 'blog:uid',
      'callback' => 'themekey_blog_nid2uid',
    ),
    1 => array(
      'src' => 'blog:uid',
      'dst' => 'themekey_ui:author_triggers_theme',
      'callback' => 'themekey_blog_author2theme',
    ),
    2 => array(
      'src' => 'comment:cid',
      'dst' => 'node:nid',
      'callback' => 'themekey_comment_cid2nid',
    ),
    3 => array(
      'src' => 'contact:uid',
      'dst' => 'themekey_ui:author_triggers_theme',
      'callback' => 'themekey_contact_uid2theme',
    ),
    4 => array(
      'src' => 'node:nid',
      'dst' => 'node:changed',
      'callback' => 'themekey_node_nid2changed',
    ),
    5 => array(
      'src' => 'node:nid',
      'dst' => 'node:created',
      'callback' => 'themekey_node_nid2created',
    ),
    6 => array(
      'src' => 'node:changed',
      'dst' => 'node:changed_date_time',
      'callback' => 'themekey_node_timestamp2datetime',
    ),
    7 => array(
      'src' => 'node:created',
      'dst' => 'node:created_date_time',
      'callback' => 'themekey_node_timestamp2datetime',
    ),
    8 => array(
      'src' => 'node:changed',
      'dst' => 'node:changed_date',
      'callback' => 'themekey_node_timestamp2date',
    ),
    9 => array(
      'src' => 'node:created',
      'dst' => 'node:created_date',
      'callback' => 'themekey_node_timestamp2date',
    ),
    10 => array(
      'src' => 'node:nid',
      'dst' => 'node:language',
      'callback' => 'themekey_node_nid2language',
    ),
    11 => array(
      'src' => 'node:nid',
      'dst' => 'node:vid',
      'callback' => 'themekey_node_nid2vid',
    ),
    12 => array(
      'src' => 'node:nid',
      'dst' => 'node:promote',
      'callback' => 'themekey_node_nid2promote',
    ),
    13 => array(
      'src' => 'node:nid',
      'dst' => 'node:sticky',
      'callback' => 'themekey_node_nid2sticky',
    ),
    14 => array(
      'src' => 'node:nid',
      'dst' => 'node:type',
      'callback' => 'themekey_node_nid2type',
    ),
    15 => array(
      'src' => 'node:nid',
      'dst' => 'node:uid',
      'callback' => 'themekey_node_nid2uid',
    ),
    16 => array(
      'src' => 'node:nid',
      'dst' => 'node:title',
      'callback' => 'themekey_node_nid2title',
    ),
    17 => array(
      'src' => 'drupal:get_q',
      'dst' => 'node:type',
      'callback' => 'themekey_node_get_q2type',
    ),
    18 => array(
      'src' => 'node:nid',
      'dst' => 'node:body_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'body',
        'type' => 'text_with_summary',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    19 => array(
      'src' => 'node:nid',
      'dst' => 'node:body_summary',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'body',
        'type' => 'text_with_summary',
        'column' => 'summary',
        'translatable' => '0',
      ),
    ),
    20 => array(
      'src' => 'node:nid',
      'dst' => 'node:body_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'body',
        'type' => 'text_with_summary',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    21 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_image_fid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_image',
        'type' => 'image',
        'column' => 'fid',
        'translatable' => '0',
      ),
    ),
    22 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_image_alt',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_image',
        'type' => 'image',
        'column' => 'alt',
        'translatable' => '0',
      ),
    ),
    23 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_image_title',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_image',
        'type' => 'image',
        'column' => 'title',
        'translatable' => '0',
      ),
    ),
    24 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_image_width',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_image',
        'type' => 'image',
        'column' => 'width',
        'translatable' => '0',
      ),
    ),
    25 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_image_height',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_image',
        'type' => 'image',
        'column' => 'height',
        'translatable' => '0',
      ),
    ),
    26 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_blog_images_fid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_blog_images',
        'type' => 'image',
        'column' => 'fid',
        'translatable' => '0',
      ),
    ),
    27 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_blog_images_alt',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_blog_images',
        'type' => 'image',
        'column' => 'alt',
        'translatable' => '0',
      ),
    ),
    28 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_blog_images_title',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_blog_images',
        'type' => 'image',
        'column' => 'title',
        'translatable' => '0',
      ),
    ),
    29 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_blog_images_width',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_blog_images',
        'type' => 'image',
        'column' => 'width',
        'translatable' => '0',
      ),
    ),
    30 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_blog_images_height',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_blog_images',
        'type' => 'image',
        'column' => 'height',
        'translatable' => '0',
      ),
    ),
    31 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_game_category_tid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_game_category',
        'type' => 'taxonomy_term_reference',
        'column' => 'tid',
        'translatable' => '0',
      ),
    ),
    32 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_stream_image_fid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_stream_image',
        'type' => 'image',
        'column' => 'fid',
        'translatable' => '0',
      ),
    ),
    33 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_stream_image_alt',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_stream_image',
        'type' => 'image',
        'column' => 'alt',
        'translatable' => '0',
      ),
    ),
    34 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_stream_image_title',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_stream_image',
        'type' => 'image',
        'column' => 'title',
        'translatable' => '0',
      ),
    ),
    35 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_stream_image_width',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_stream_image',
        'type' => 'image',
        'column' => 'width',
        'translatable' => '0',
      ),
    ),
    36 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_stream_image_height',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_stream_image',
        'type' => 'image',
        'column' => 'height',
        'translatable' => '0',
      ),
    ),
    37 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_ask_question_tid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_ask_question',
        'type' => 'taxonomy_term_reference',
        'column' => 'tid',
        'translatable' => '0',
      ),
    ),
    38 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_tags_tid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_tags',
        'type' => 'taxonomy_term_reference',
        'column' => 'tid',
        'translatable' => '0',
      ),
    ),
    39 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_right_side_listing_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_right_side_listing',
        'type' => 'list_boolean',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    40 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_staff_image_fid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_staff_image',
        'type' => 'image',
        'column' => 'fid',
        'translatable' => '0',
      ),
    ),
    41 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_staff_image_alt',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_staff_image',
        'type' => 'image',
        'column' => 'alt',
        'translatable' => '0',
      ),
    ),
    42 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_staff_image_title',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_staff_image',
        'type' => 'image',
        'column' => 'title',
        'translatable' => '0',
      ),
    ),
    43 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_staff_image_width',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_staff_image',
        'type' => 'image',
        'column' => 'width',
        'translatable' => '0',
      ),
    ),
    44 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_staff_image_height',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_staff_image',
        'type' => 'image',
        'column' => 'height',
        'translatable' => '0',
      ),
    ),
    45 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_twitter_id_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_twitter_id',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    46 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_twitter_id_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_twitter_id',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    47 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_proffesion_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_proffesion',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    48 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_proffesion_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_proffesion',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    49 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_facebook_external_id_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_facebook_external_id',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    50 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_facebook_external_id_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_facebook_external_id',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    51 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_facebook_link_url',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_facebook_link',
        'type' => 'link_field',
        'column' => 'url',
        'translatable' => '0',
      ),
    ),
    52 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_facebook_link_title',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_facebook_link',
        'type' => 'link_field',
        'column' => 'title',
        'translatable' => '0',
      ),
    ),
    53 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_facebook_link_attributes',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_facebook_link',
        'type' => 'link_field',
        'column' => 'attributes',
        'translatable' => '0',
      ),
    ),
    54 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_facebook_picture_fid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_facebook_picture',
        'type' => 'image',
        'column' => 'fid',
        'translatable' => '0',
      ),
    ),
    55 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_facebook_picture_alt',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_facebook_picture',
        'type' => 'image',
        'column' => 'alt',
        'translatable' => '0',
      ),
    ),
    56 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_facebook_picture_title',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_facebook_picture',
        'type' => 'image',
        'column' => 'title',
        'translatable' => '0',
      ),
    ),
    57 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_facebook_picture_width',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_facebook_picture',
        'type' => 'image',
        'column' => 'width',
        'translatable' => '0',
      ),
    ),
    58 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_facebook_picture_height',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_facebook_picture',
        'type' => 'image',
        'column' => 'height',
        'translatable' => '0',
      ),
    ),
    59 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_tweet_user_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_tweet_user',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    60 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_tweet_user_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_tweet_user',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    61 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_tweet_user_picture_fid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_tweet_user_picture',
        'type' => 'image',
        'column' => 'fid',
        'translatable' => '0',
      ),
    ),
    62 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_tweet_user_picture_alt',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_tweet_user_picture',
        'type' => 'image',
        'column' => 'alt',
        'translatable' => '0',
      ),
    ),
    63 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_tweet_user_picture_title',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_tweet_user_picture',
        'type' => 'image',
        'column' => 'title',
        'translatable' => '0',
      ),
    ),
    64 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_tweet_user_picture_width',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_tweet_user_picture',
        'type' => 'image',
        'column' => 'width',
        'translatable' => '0',
      ),
    ),
    65 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_tweet_user_picture_height',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_tweet_user_picture',
        'type' => 'image',
        'column' => 'height',
        'translatable' => '0',
      ),
    ),
    66 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_tweet_link_url',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_tweet_link',
        'type' => 'link_field',
        'column' => 'url',
        'translatable' => '0',
      ),
    ),
    67 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_tweet_link_title',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_tweet_link',
        'type' => 'link_field',
        'column' => 'title',
        'translatable' => '0',
      ),
    ),
    68 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_tweet_link_attributes',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_tweet_link',
        'type' => 'link_field',
        'column' => 'attributes',
        'translatable' => '0',
      ),
    ),
    69 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_tweet_external_id_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_tweet_external_id',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    70 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_tweet_external_id_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_tweet_external_id',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    71 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_tweet_user_name_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_tweet_user_name',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    72 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_tweet_user_name_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_tweet_user_name',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    73 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_cover_fid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_cover',
        'type' => 'image',
        'column' => 'fid',
        'translatable' => '0',
      ),
    ),
    74 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_cover_alt',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_cover',
        'type' => 'image',
        'column' => 'alt',
        'translatable' => '0',
      ),
    ),
    75 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_cover_title',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_cover',
        'type' => 'image',
        'column' => 'title',
        'translatable' => '0',
      ),
    ),
    76 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_cover_width',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_cover',
        'type' => 'image',
        'column' => 'width',
        'translatable' => '0',
      ),
    ),
    77 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_cover_height',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_cover',
        'type' => 'image',
        'column' => 'height',
        'translatable' => '0',
      ),
    ),
    78 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_event_dates_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_event_dates',
        'type' => 'datetime',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    79 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_event_dates_value2',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_event_dates',
        'type' => 'datetime',
        'column' => 'value2',
        'translatable' => '0',
      ),
    ),
    80 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_facebook_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_facebook',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    81 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_facebook_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_facebook',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    82 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_google_plus_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_google_plus',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    83 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_google_plus_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_google_plus',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    84 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_player_background_fid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_player_background',
        'type' => 'image',
        'column' => 'fid',
        'translatable' => '0',
      ),
    ),
    85 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_player_background_alt',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_player_background',
        'type' => 'image',
        'column' => 'alt',
        'translatable' => '0',
      ),
    ),
    86 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_player_background_title',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_player_background',
        'type' => 'image',
        'column' => 'title',
        'translatable' => '0',
      ),
    ),
    87 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_player_background_width',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_player_background',
        'type' => 'image',
        'column' => 'width',
        'translatable' => '0',
      ),
    ),
    88 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_player_background_height',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_player_background',
        'type' => 'image',
        'column' => 'height',
        'translatable' => '0',
      ),
    ),
    89 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_reddit_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_reddit',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    90 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_reddit_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_reddit',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    91 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_stream_category_tid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_stream_category',
        'type' => 'taxonomy_term_reference',
        'column' => 'tid',
        'translatable' => '0',
      ),
    ),
    92 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_streams_target_id',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_streams',
        'type' => 'entityreference',
        'column' => 'target_id',
        'translatable' => '0',
      ),
    ),
    93 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_twitter_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_twitter',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    94 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_twitter_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_twitter',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    95 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_website_url',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_website',
        'type' => 'link_field',
        'column' => 'url',
        'translatable' => '0',
      ),
    ),
    96 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_website_title',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_website',
        'type' => 'link_field',
        'column' => 'title',
        'translatable' => '0',
      ),
    ),
    97 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_website_attributes',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_website',
        'type' => 'link_field',
        'column' => 'attributes',
        'translatable' => '0',
      ),
    ),
    98 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_youtube_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_youtube',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    99 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_youtube_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_youtube',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    100 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_twitter_feed_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_twitter_feed',
        'type' => 'text_long',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    101 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_twitter_feed_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_twitter_feed',
        'type' => 'text_long',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    102 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_ad_type_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_ad_type',
        'type' => 'list_text',
        'column' => 'value',
        'translatable' => '1',
      ),
    ),
    103 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_ad_image_fid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_ad_image',
        'type' => 'image',
        'column' => 'fid',
        'translatable' => '1',
      ),
    ),
    104 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_ad_image_alt',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_ad_image',
        'type' => 'image',
        'column' => 'alt',
        'translatable' => '1',
      ),
    ),
    105 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_ad_image_title',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_ad_image',
        'type' => 'image',
        'column' => 'title',
        'translatable' => '1',
      ),
    ),
    106 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_ad_image_width',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_ad_image',
        'type' => 'image',
        'column' => 'width',
        'translatable' => '1',
      ),
    ),
    107 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_ad_image_height',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_ad_image',
        'type' => 'image',
        'column' => 'height',
        'translatable' => '1',
      ),
    ),
    108 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_ad_flash_fid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_ad_flash',
        'type' => 'file',
        'column' => 'fid',
        'translatable' => '1',
      ),
    ),
    109 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_ad_flash_display',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_ad_flash',
        'type' => 'file',
        'column' => 'display',
        'translatable' => '1',
      ),
    ),
    110 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_ad_flash_description',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_ad_flash',
        'type' => 'file',
        'column' => 'description',
        'translatable' => '1',
      ),
    ),
    111 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_ad_text_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_ad_text',
        'type' => 'text_long',
        'column' => 'value',
        'translatable' => '1',
      ),
    ),
    112 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_ad_text_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_ad_text',
        'type' => 'text_long',
        'column' => 'format',
        'translatable' => '1',
      ),
    ),
    113 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_ad_url_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_ad_url',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '1',
      ),
    ),
    114 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_ad_url_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_ad_url',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '1',
      ),
    ),
    115 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_ad_url_taget_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_ad_url_taget',
        'type' => 'list_boolean',
        'column' => 'value',
        'translatable' => '1',
      ),
    ),
    116 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_ad_category_tid',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_ad_category',
        'type' => 'taxonomy_term_reference',
        'column' => 'tid',
        'translatable' => '0',
      ),
    ),
    117 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_ad_start_date_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_ad_start_date',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '1',
      ),
    ),
    118 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_ad_start_date_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_ad_start_date',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '1',
      ),
    ),
    119 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_ad_end_date_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_ad_end_date',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '1',
      ),
    ),
    120 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_ad_end_date_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_ad_end_date',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '1',
      ),
    ),
    121 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_ad_status_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_ad_status',
        'type' => 'list_boolean',
        'column' => 'value',
        'translatable' => '1',
      ),
    ),
    122 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_twitch_team_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_twitch_team',
        'type' => 'list_boolean',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    123 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_twitch_team_name_value',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_twitch_team_name',
        'type' => 'text',
        'column' => 'value',
        'translatable' => '0',
      ),
    ),
    124 => array(
      'src' => 'node:nid',
      'dst' => 'node:field_twitch_team_name_format',
      'callback' => 'themekey_node_nid2field_value',
      'args' => array(
        'field_name' => 'field_twitch_team_name',
        'type' => 'text',
        'column' => 'format',
        'translatable' => '0',
      ),
    ),
    125 => array(
      'src' => 'node:nid',
      'dst' => 'path:node_alias',
      'callback' => 'themekey_path_nid2alias',
    ),
    126 => array(
      'src' => 'system:dummy',
      'dst' => 'system:query_param',
      'callback' => 'themekey_dummy2query_param',
    ),
    127 => array(
      'src' => 'system:dummy',
      'dst' => 'system:cookie',
      'callback' => 'themekey_dummy2cookie',
    ),
    128 => array(
      'src' => 'system:dummy',
      'dst' => 'system:http_header',
      'callback' => 'themekey_dummy2http_header',
    ),
    129 => array(
      'src' => 'system:dummy',
      'dst' => 'system:post',
      'callback' => 'themekey_dummy2post',
    ),
    130 => array(
      'src' => 'system:dummy',
      'dst' => 'system:query_string',
      'callback' => 'themekey_dummy2query_string',
    ),
    131 => array(
      'src' => 'system:dummy',
      'dst' => 'system:date_time',
      'callback' => 'themekey_dummy2date_time',
    ),
    132 => array(
      'src' => 'system:dummy',
      'dst' => 'system:date',
      'callback' => 'themekey_dummy2date',
    ),
    133 => array(
      'src' => 'system:dummy',
      'dst' => 'system:month',
      'callback' => 'themekey_dummy2month',
    ),
    134 => array(
      'src' => 'system:dummy',
      'dst' => 'system:time',
      'callback' => 'themekey_dummy2time',
    ),
    135 => array(
      'src' => 'system:dummy',
      'dst' => 'system:day_of_week',
      'callback' => 'themekey_dummy2day_of_week',
    ),
    136 => array(
      'src' => 'system:dummy',
      'dst' => 'system:day_of_month',
      'callback' => 'themekey_dummy2day_of_month',
    ),
    137 => array(
      'src' => 'system:dummy',
      'dst' => 'system:user_browser',
      'callback' => 'themekey_dummy2user_browser',
    ),
    138 => array(
      'src' => 'system:dummy',
      'dst' => 'system:user_os',
      'callback' => 'themekey_dummy2user_os',
    ),
    139 => array(
      'src' => 'system:user_browser',
      'dst' => 'system:user_browser_simplified',
      'callback' => 'themekey_user_browser2user_browser_simplified',
    ),
    140 => array(
      'src' => 'system:user_os',
      'dst' => 'system:user_os_simplified',
      'callback' => 'themekey_user_os2user_os_simplified',
    ),
    141 => array(
      'src' => 'system:dummy',
      'dst' => 'system:session',
      'callback' => 'themekey_dummy2session',
    ),
    142 => array(
      'src' => 'taxonomy:tid',
      'dst' => 'taxonomy:vid',
      'callback' => 'themekey_taxonomy_tid2vid',
    ),
    143 => array(
      'src' => 'taxonomy:tid',
      'dst' => 'taxonomy:tid_and_childs',
      'callback' => 'themekey_taxonomy_tid2tid_and_parents',
    ),
    144 => array(
      'src' => 'node:nid',
      'dst' => 'taxonomy:tid',
      'callback' => 'themekey_taxonomy_nid2tid',
    ),
    145 => array(
      'src' => 'taxonomy:tid',
      'dst' => 'taxonomy:name',
      'callback' => 'themekey_taxonomy_tid2name',
    ),
    146 => array(
      'src' => 'profile:uid',
      'dst' => 'themekey_ui:author_triggers_theme',
      'callback' => 'themekey_user_profile2theme',
    ),
    147 => array(
      'src' => 'drupal:get_q',
      'dst' => 'views:vid',
      'callback' => 'themekey_views_getq2vid',
    ),
    148 => array(
      'src' => 'drupal:get_q',
      'dst' => 'views:machine_name',
      'callback' => 'themekey_views_getq2machine_name',
    ),
    149 => array(
      'src' => 'drupal:get_q',
      'dst' => 'views:human_name',
      'callback' => 'themekey_views_getq2human_name',
    ),
    150 => array(
      'src' => 'node:nid',
      'dst' => 'themekey_ui:node_triggers_theme',
      'callback' => 'themekey_ui_nid2theme',
    ),
    151 => array(
      'src' => 'node:nid',
      'dst' => 'themekey_ui:author_triggers_theme',
      'callback' => 'themekey_ui_node_author2theme',
    ),
  );
  $export['themekey_maps'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'themekey_modules';
  $strongarm->value = array(
    0 => 'admin_menu',
    1 => 'blog',
    2 => 'comment',
    3 => 'contact',
    4 => 'node',
    5 => 'path',
    6 => 'system',
    7 => 'taxonomy',
    8 => 'user',
    9 => 'views',
  );
  $export['themekey_modules'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'themekey_paths';
  $strongarm->value = array(
    0 => array(
      'path' => 'node/#/revisions/#/view',
      'callbacks' => array(),
      'wildcards' => array(
        1 => 'node:nid',
        3 => 'node:vid',
      ),
      'weight' => 10,
      'fit' => 21,
    ),
    1 => array(
      'path' => 'comment/reply/#/#',
      'callbacks' => array(),
      'wildcards' => array(
        2 => 'node:nid',
        3 => 'comment:cid',
      ),
      'weight' => 3,
      'fit' => 12,
    ),
    2 => array(
      'path' => 'comment/reply/#',
      'callbacks' => array(),
      'wildcards' => array(
        2 => 'node:nid',
      ),
      'weight' => 1,
      'fit' => 6,
    ),
    3 => array(
      'path' => 'taxonomy/term/#',
      'callbacks' => array(),
      'wildcards' => array(
        2 => 'taxonomy:tid',
      ),
      'weight' => 1,
      'fit' => 6,
    ),
    4 => array(
      'path' => 'comment/#/edit',
      'callbacks' => array(),
      'wildcards' => array(
        1 => 'comment:cid',
      ),
      'weight' => 2,
      'fit' => 5,
    ),
    5 => array(
      'path' => 'comment/#/delete',
      'callbacks' => array(),
      'wildcards' => array(
        1 => 'comment:cid',
      ),
      'weight' => 2,
      'fit' => 5,
    ),
    6 => array(
      'path' => 'user/#/contact',
      'callbacks' => array(),
      'wildcards' => array(
        1 => 'contact:uid',
      ),
      'weight' => 2,
      'fit' => 5,
    ),
    7 => array(
      'path' => 'user/#/edit',
      'callbacks' => array(),
      'wildcards' => array(
        1 => 'profile:uid',
      ),
      'weight' => 2,
      'fit' => 5,
    ),
    8 => array(
      'path' => 'blog/#',
      'callbacks' => array(),
      'wildcards' => array(
        1 => 'blog:uid',
      ),
      'weight' => 1,
      'fit' => 2,
    ),
    9 => array(
      'path' => 'node/#',
      'callbacks' => array(),
      'wildcards' => array(
        1 => 'node:nid',
      ),
      'weight' => 1,
      'fit' => 2,
    ),
    10 => array(
      'path' => 'user/#',
      'callbacks' => array(),
      'wildcards' => array(
        1 => 'profile:uid',
      ),
      'weight' => 1,
      'fit' => 2,
    ),
  );
  $export['themekey_paths'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'themekey_properties';
  $strongarm->value = array(
    'blog:uid' => 'blog:uid',
    'comment:cid' => 'comment:cid',
    'drupal:base_path' => 'drupal:base_path',
    'drupal:get_q' => 'drupal:get_q',
    'drupal:is_front_page' => 'drupal:is_front_page',
    'drupal:path' => 'drupal:path',
    'drupal:path:wildcard' => 'drupal:path:wildcard',
    'drupal:path_is_admin' => 'drupal:path_is_admin',
    'node:body_format' => 'node:body_format',
    'node:body_summary' => 'node:body_summary',
    'node:body_value' => 'node:body_value',
    'node:changed' => 'node:changed',
    'node:changed_date' => 'node:changed_date',
    'node:changed_date_time' => 'node:changed_date_time',
    'node:created' => 'node:created',
    'node:created_date' => 'node:created_date',
    'node:created_date_time' => 'node:created_date_time',
    'node:field_ad_category_tid' => 'node:field_ad_category_tid',
    'node:field_ad_end_date_format' => 'node:field_ad_end_date_format',
    'node:field_ad_end_date_value' => 'node:field_ad_end_date_value',
    'node:field_ad_flash_description' => 'node:field_ad_flash_description',
    'node:field_ad_flash_display' => 'node:field_ad_flash_display',
    'node:field_ad_flash_fid' => 'node:field_ad_flash_fid',
    'node:field_ad_image_alt' => 'node:field_ad_image_alt',
    'node:field_ad_image_fid' => 'node:field_ad_image_fid',
    'node:field_ad_image_height' => 'node:field_ad_image_height',
    'node:field_ad_image_title' => 'node:field_ad_image_title',
    'node:field_ad_image_width' => 'node:field_ad_image_width',
    'node:field_ad_start_date_format' => 'node:field_ad_start_date_format',
    'node:field_ad_start_date_value' => 'node:field_ad_start_date_value',
    'node:field_ad_status_value' => 'node:field_ad_status_value',
    'node:field_ad_text_format' => 'node:field_ad_text_format',
    'node:field_ad_text_value' => 'node:field_ad_text_value',
    'node:field_ad_type_value' => 'node:field_ad_type_value',
    'node:field_ad_url_format' => 'node:field_ad_url_format',
    'node:field_ad_url_taget_value' => 'node:field_ad_url_taget_value',
    'node:field_ad_url_value' => 'node:field_ad_url_value',
    'node:field_ask_question_tid' => 'node:field_ask_question_tid',
    'node:field_blog_images_alt' => 'node:field_blog_images_alt',
    'node:field_blog_images_fid' => 'node:field_blog_images_fid',
    'node:field_blog_images_height' => 'node:field_blog_images_height',
    'node:field_blog_images_title' => 'node:field_blog_images_title',
    'node:field_blog_images_width' => 'node:field_blog_images_width',
    'node:field_cover_alt' => 'node:field_cover_alt',
    'node:field_cover_fid' => 'node:field_cover_fid',
    'node:field_cover_height' => 'node:field_cover_height',
    'node:field_cover_title' => 'node:field_cover_title',
    'node:field_cover_width' => 'node:field_cover_width',
    'node:field_event_dates_value' => 'node:field_event_dates_value',
    'node:field_event_dates_value2' => 'node:field_event_dates_value2',
    'node:field_facebook_external_id_format' => 'node:field_facebook_external_id_format',
    'node:field_facebook_external_id_value' => 'node:field_facebook_external_id_value',
    'node:field_facebook_format' => 'node:field_facebook_format',
    'node:field_facebook_link_attributes' => 'node:field_facebook_link_attributes',
    'node:field_facebook_link_title' => 'node:field_facebook_link_title',
    'node:field_facebook_link_url' => 'node:field_facebook_link_url',
    'node:field_facebook_picture_alt' => 'node:field_facebook_picture_alt',
    'node:field_facebook_picture_fid' => 'node:field_facebook_picture_fid',
    'node:field_facebook_picture_height' => 'node:field_facebook_picture_height',
    'node:field_facebook_picture_title' => 'node:field_facebook_picture_title',
    'node:field_facebook_picture_width' => 'node:field_facebook_picture_width',
    'node:field_facebook_value' => 'node:field_facebook_value',
    'node:field_game_category_tid' => 'node:field_game_category_tid',
    'node:field_google_plus_format' => 'node:field_google_plus_format',
    'node:field_google_plus_value' => 'node:field_google_plus_value',
    'node:field_image_alt' => 'node:field_image_alt',
    'node:field_image_fid' => 'node:field_image_fid',
    'node:field_image_height' => 'node:field_image_height',
    'node:field_image_title' => 'node:field_image_title',
    'node:field_image_width' => 'node:field_image_width',
    'node:field_player_background_alt' => 'node:field_player_background_alt',
    'node:field_player_background_fid' => 'node:field_player_background_fid',
    'node:field_player_background_height' => 'node:field_player_background_height',
    'node:field_player_background_title' => 'node:field_player_background_title',
    'node:field_player_background_width' => 'node:field_player_background_width',
    'node:field_proffesion_format' => 'node:field_proffesion_format',
    'node:field_proffesion_value' => 'node:field_proffesion_value',
    'node:field_reddit_format' => 'node:field_reddit_format',
    'node:field_reddit_value' => 'node:field_reddit_value',
    'node:field_right_side_listing_value' => 'node:field_right_side_listing_value',
    'node:field_staff_image_alt' => 'node:field_staff_image_alt',
    'node:field_staff_image_fid' => 'node:field_staff_image_fid',
    'node:field_staff_image_height' => 'node:field_staff_image_height',
    'node:field_staff_image_title' => 'node:field_staff_image_title',
    'node:field_staff_image_width' => 'node:field_staff_image_width',
    'node:field_stream_category_tid' => 'node:field_stream_category_tid',
    'node:field_stream_image_alt' => 'node:field_stream_image_alt',
    'node:field_stream_image_fid' => 'node:field_stream_image_fid',
    'node:field_stream_image_height' => 'node:field_stream_image_height',
    'node:field_stream_image_title' => 'node:field_stream_image_title',
    'node:field_stream_image_width' => 'node:field_stream_image_width',
    'node:field_streams_target_id' => 'node:field_streams_target_id',
    'node:field_tags_tid' => 'node:field_tags_tid',
    'node:field_tweet_external_id_format' => 'node:field_tweet_external_id_format',
    'node:field_tweet_external_id_value' => 'node:field_tweet_external_id_value',
    'node:field_tweet_link_attributes' => 'node:field_tweet_link_attributes',
    'node:field_tweet_link_title' => 'node:field_tweet_link_title',
    'node:field_tweet_link_url' => 'node:field_tweet_link_url',
    'node:field_tweet_user_format' => 'node:field_tweet_user_format',
    'node:field_tweet_user_name_format' => 'node:field_tweet_user_name_format',
    'node:field_tweet_user_name_value' => 'node:field_tweet_user_name_value',
    'node:field_tweet_user_picture_alt' => 'node:field_tweet_user_picture_alt',
    'node:field_tweet_user_picture_fid' => 'node:field_tweet_user_picture_fid',
    'node:field_tweet_user_picture_height' => 'node:field_tweet_user_picture_height',
    'node:field_tweet_user_picture_title' => 'node:field_tweet_user_picture_title',
    'node:field_tweet_user_picture_width' => 'node:field_tweet_user_picture_width',
    'node:field_tweet_user_value' => 'node:field_tweet_user_value',
    'node:field_twitch_team_name_format' => 'node:field_twitch_team_name_format',
    'node:field_twitch_team_name_value' => 'node:field_twitch_team_name_value',
    'node:field_twitch_team_value' => 'node:field_twitch_team_value',
    'node:field_twitter_feed_format' => 'node:field_twitter_feed_format',
    'node:field_twitter_feed_value' => 'node:field_twitter_feed_value',
    'node:field_twitter_format' => 'node:field_twitter_format',
    'node:field_twitter_id_format' => 'node:field_twitter_id_format',
    'node:field_twitter_id_value' => 'node:field_twitter_id_value',
    'node:field_twitter_value' => 'node:field_twitter_value',
    'node:field_website_attributes' => 'node:field_website_attributes',
    'node:field_website_title' => 'node:field_website_title',
    'node:field_website_url' => 'node:field_website_url',
    'node:field_youtube_format' => 'node:field_youtube_format',
    'node:field_youtube_value' => 'node:field_youtube_value',
    'node:language' => 'node:language',
    'node:nid' => 'node:nid',
    'node:promote' => 'node:promote',
    'node:sticky' => 'node:sticky',
    'node:title' => 'node:title',
    'node:type' => 'node:type',
    'node:uid' => 'node:uid',
    'node:vid' => 'node:vid',
    'path:node_alias' => 'path:node_alias',
    'system:cookie' => 'system:cookie',
    'system:date' => 'system:date',
    'system:date_time' => 'system:date_time',
    'system:day_of_month' => 'system:day_of_month',
    'system:day_of_week' => 'system:day_of_week',
    'system:dummy' => 'system:dummy',
    'system:host' => 'system:host',
    'system:http_header' => 'system:http_header',
    'system:https' => 'system:https',
    'system:month' => 'system:month',
    'system:post' => 'system:post',
    'system:query_param' => 'system:query_param',
    'system:query_string' => 'system:query_string',
    'system:random' => 'system:random',
    'system:referer' => 'system:referer',
    'system:remote_ip' => 'system:remote_ip',
    'system:server_ip' => 'system:server_ip',
    'system:server_name' => 'system:server_name',
    'system:server_port' => 'system:server_port',
    'system:session' => 'system:session',
    'system:time' => 'system:time',
    'system:user_agent' => 'system:user_agent',
    'system:user_browser' => 'system:user_browser',
    'system:user_browser_simplified' => 'system:user_browser_simplified',
    'system:user_os' => 'system:user_os',
    'system:user_os_simplified' => 'system:user_os_simplified',
    'taxonomy:name' => 'taxonomy:name',
    'taxonomy:tid' => 'taxonomy:tid',
    'taxonomy:tid_and_childs' => 'taxonomy:tid_and_childs',
    'taxonomy:vid' => 'taxonomy:vid',
    'user:hostname' => 'user:hostname',
    'user:language' => 'user:language',
    'user:name' => 'user:name',
    'user:role' => 'user:role',
    'user:uid' => 'user:uid',
    'views:human_name' => 'views:human_name',
    'views:machine_name' => 'views:machine_name',
    'views:vid' => 'views:vid',
  );
  $export['themekey_properties'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_default';
  $strongarm->value = 'streamriot';
  $export['theme_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_parrot_settings';
  $strongarm->value = array(
    'toggle_logo' => 1,
    'toggle_name' => 0,
    'toggle_slogan' => 0,
    'toggle_node_user_picture' => 1,
    'toggle_comment_user_picture' => 1,
    'toggle_comment_user_verification' => 1,
    'toggle_favicon' => 1,
    'default_logo' => 1,
    'logo_path' => '',
    'logo_upload' => '',
    'default_favicon' => 1,
    'favicon_path' => '',
    'favicon_upload' => '',
    'mothership_poorthemers_helper' => 0,
    'mothership_rebuild_registry' => 0,
    'mothership_test' => 0,
    'mothership_mediaquery_indicator' => 0,
    'mothership_script_place_footer' => 1,
    'mothership_js_onefile' => 0,
    'mothership_js_jquery_latest' => 0,
    'mothership_js_jquerycdn' => 0,
    'mothership_js_jquerycdn_version' => '0',
    'mothership_respondjs' => 1,
    'mothership_modernizr' => 1,
    'mothership_selectivizr' => 1,
    'mothership_js_nuke_module' => 0,
    'mothership_js_nuke_module_contrib' => 0,
    'mothership_js_nuke_misc' => 0,
    'mothership_js_freeform' => '',
    'mothership_css_onefile' => 0,
    'mothership_css_reset' => 0,
    'mothership_css_reset_html5' => 0,
    'mothership_css_normalize' => 0,
    'mothership_css_layout' => 1,
    'mothership_css_default' => 0,
    'mothership_css_mothershipstyles' => 0,
    'mothership_css_nuke_theme' => 0,
    'mothership_css_nuke_admin' => 0,
    'mothership_css_nuke_module_contrib' => 0,
    'mothership_css_nuke_module_all' => 0,
    'mothership_css_nuke_book' => 0,
    'mothership_css_nuke_systemtoolbar' => 0,
    'mothership_css_nuke_system_message' => 0,
    'mothership_css_nuke_system_menus' => 0,
    'mothership_css_nuke_system_theme' => 0,
    'mothership_css_freeform' => '',
    'mothership_classes_body_html' => 1,
    'mothership_classes_body_loggedin' => 1,
    'mothership_classes_body_front' => 0,
    'mothership_classes_body_layout' => 0,
    'mothership_classes_body_toolbar' => 0,
    'mothership_classes_body_pagenode' => 1,
    'mothership_classes_body_nodetype' => 0,
    'mothership_classes_body_path' => 0,
    'mothership_classes_body_path_first' => 0,
    'mothership_classes_body_status' => 0,
    'mothership_classes_body_freeform' => '',
    'mothership_region_wrapper' => 1,
    'mothership_classes_region' => 1,
    'mothership_classes_region_freeform' => '',
    'mothership_classes_block' => 1,
    'mothership_classes_block_id' => 0,
    'mothership_classes_block_id_as_class' => 0,
    'mothership_classes_block_contentdiv' => 1,
    'mothership_classes_block_freeform' => '',
    'mothership_classes_node' => 0,
    'mothership_classes_node_state' => 0,
    'mothership_classes_node_id' => 0,
    'mothership_classes_node_freeform' => '',
    'mothership_classes_node_links_inline' => 0,
    'mothership_classes_node_links_links' => 0,
    'mothership_classes_field_field' => 0,
    'mothership_classes_field_name' => 1,
    'mothership_classes_field_type' => 0,
    'mothership_classes_field_label' => 1,
    'mothership_classes_field_freeform' => '',
    'mothership_classes_form_container_wrapper' => 0,
    'mothership_classes_form_container_type' => 0,
    'mothership_classes_form_container_name' => 0,
    'mothership_classes_form_container_widget' => 0,
    'mothership_classes_form_container_id' => 0,
    'mothership_classes_form_wrapper_formitem' => 1,
    'mothership_classes_form_wrapper_formtype' => 1,
    'mothership_classes_form_wrapper_formname' => 1,
    'mothership_classes_form_freeform' => '',
    'mothership_classes_form_label' => 1,
    'mothership_classes_form_input' => 1,
    'mothership_form_required' => 1,
    'mothership_classes_form_description' => 1,
    'mothership_classes_form_placeholder_label' => 0,
    'mothership_classes_form_placeholder_link' => '',
    'mothership_classes_form_placeholder_email' => '',
    'mothership_classes_menu_items_mlid' => 1,
    'mothership_classes_menu_wrapper' => 1,
    'mothership_classes_menu_items_firstlast' => 1,
    'mothership_classes_menu_items_active' => 0,
    'mothership_classes_menu_collapsed' => 0,
    'mothership_classes_menu_leaf' => 1,
    'mothership_classes_view' => 1,
    'mothership_classes_view_name' => 1,
    'mothership_classes_view_view_id' => 0,
    'mothership_classes_view_row' => 1,
    'mothership_classes_view_row_count' => 1,
    'mothership_classes_view_row_first_last' => 1,
    'mothership_classes_view_row_rename' => 0,
    'panels_seperator' => 1,
    'mothership_classes_state' => 0,
    'mothership_404' => 0,
    'mothership_frontpage_default_message' => 1,
    'mothership_content_block_wrapper' => 1,
    'mothership_goodies_login' => 0,
    'mothership_mobile' => 1,
    'mothership_viewport' => 1,
    'mothership_viewport_maximumscale' => 0,
  );
  $export['theme_parrot_settings'] = $strongarm;

  return $export;
}
