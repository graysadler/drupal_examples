<?php
/**
 * @file
 * multistream.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function multistream_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'browse';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Browse';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'views_delta_browse_streams-browse_streams',
      'hide_title' => 1,
      'title' => 'Sreams',
      'weight' => '-100',
      'type' => 'block',
    ),
    1 => array(
      'bid' => 'views_delta_52e595723d92c4789cc68736aa193d4d',
      'hide_title' => 1,
      'title' => 'Multi-streams',
      'weight' => '-99',
      'type' => 'block',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Browse');
  t('Multi-streams');
  t('Sreams');

  $export['browse'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'player_menu';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Player Menu';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'panels_mini_delta_now_playing',
      'hide_title' => 1,
      'title' => 'Now Playing',
      'weight' => '-100',
      'type' => 'block',
    ),
    1 => array(
      'bid' => 'panels_mini_delta_browse',
      'hide_title' => 1,
      'title' => 'Browse',
      'weight' => '-99',
      'type' => 'block',
    ),
    2 => array(
      'bid' => 'panels_mini_delta_add_new_channel',
      'hide_title' => 1,
      'title' => 'Add Channel',
      'weight' => '-98',
      'type' => 'block',
    ),
    3 => array(
      'bid' => 'panels_mini_delta_favorites',
      'hide_title' => 1,
      'title' => 'Favorites',
      'weight' => '-97',
      'type' => 'block',
    ),
    4 => array(
      'bid' => 'panels_mini_delta_player_manage',
      'hide_title' => 1,
      'title' => 'Manage',
      'weight' => '-96',
      'type' => 'block',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'Sky';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Add Channel');
  t('Browse');
  t('Favorites');
  t('Manage');
  t('Now Playing');
  t('Player Menu');

  $export['player_menu'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'social_menu';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Social Menu';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'panels_mini_delta_player_twitter_feed',
      'hide_title' => 1,
      'title' => 'Twitter',
      'weight' => '-100',
      'type' => 'block',
    ),
    1 => array(
      'bid' => 'panels_mini_delta_player_chat',
      'hide_title' => 1,
      'title' => 'Chat',
      'weight' => '-99',
      'type' => 'block',
    ),
    2 => array(
      'bid' => 'panels_mini_delta_player_share',
      'hide_title' => 1,
      'title' => 'Share',
      'weight' => '-98',
      'type' => 'block',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'Sky';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Chat');
  t('Share');
  t('Social Menu');
  t('Twitter');

  $export['social_menu'] = $quicktabs;

  return $export;
}
