<?php
/**
 * @file
 * multistream.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function multistream_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = '200x200_ad';
  $mini->category = '';
  $mini->admin_title = '200x200 Ad';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'one_mp';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'minipanel_one_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '5e12db40-d0a5-4a35-8985-aee67e25d2fa';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f02f7544-17dd-4c42-84ed-b5d39d2f884c';
    $pane->panel = 'minipanel_one_main';
    $pane->type = 'block';
    $pane->subtype = 'simpleads-ad_groups_1073';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f02f7544-17dd-4c42-84ed-b5d39d2f884c';
    $display->content['new-f02f7544-17dd-4c42-84ed-b5d39d2f884c'] = $pane;
    $display->panels['minipanel_one_main'][0] = 'new-f02f7544-17dd-4c42-84ed-b5d39d2f884c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['200x200_ad'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = '300x250_ad';
  $mini->category = '';
  $mini->admin_title = '300x250 Ad';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'one_mp';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'minipanel_one_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'bb5ddd43-4374-49f3-8437-657c54f4cee9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d5102a89-2008-432f-ae9c-85b3fcfd7acc';
    $pane->panel = 'minipanel_one_main';
    $pane->type = 'block';
    $pane->subtype = 'simpleads-ad_groups_1074';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd5102a89-2008-432f-ae9c-85b3fcfd7acc';
    $display->content['new-d5102a89-2008-432f-ae9c-85b3fcfd7acc'] = $pane;
    $display->panels['minipanel_one_main'][0] = 'new-d5102a89-2008-432f-ae9c-85b3fcfd7acc';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['300x250_ad'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'add_new_channel';
  $mini->category = '';
  $mini->admin_title = 'Add Channel';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'two_50_mp';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'minipanel_two_50_top' => NULL,
      'minipanel_two_50_first' => NULL,
      'minipanel_two_50_second' => NULL,
      'minipanel_two_50_bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Add New Channel';
  $display->uuid = '458592a9-9a1e-4c0d-9fe2-63e65dbd37f6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-810592ff-2997-4211-a786-803c4f265ac6';
    $pane->panel = 'minipanel_two_50_bottom';
    $pane->type = 'block';
    $pane->subtype = 'multistream-multistream_add_channel';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '810592ff-2997-4211-a786-803c4f265ac6';
    $display->content['new-810592ff-2997-4211-a786-803c4f265ac6'] = $pane;
    $display->panels['minipanel_two_50_bottom'][0] = 'new-810592ff-2997-4211-a786-803c4f265ac6';
    $pane = new stdClass();
    $pane->pid = 'new-22f09e9e-0aab-4adf-a04f-8473e31e349a';
    $pane->panel = 'minipanel_two_50_bottom';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Channel Chain',
      'title' => 'Channel Chains',
      'body' => '<p>Channel chains are the fastest way to create and share multi-streams. Just add Twitch channels to our URL.</p>

<ol>
	<li>Copy &amp; paste our URL into your browser\'s address bar:
	<ol>
		<li>www.StreamRiot.com/MultiStream/</li>
	</ol>
	</li>
	<li>Add Twitch channels by name. Separate each with a forward slash: /</li>
	<li>Share the link with your friends!</li>
</ol>
',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '22f09e9e-0aab-4adf-a04f-8473e31e349a';
    $display->content['new-22f09e9e-0aab-4adf-a04f-8473e31e349a'] = $pane;
    $display->panels['minipanel_two_50_bottom'][1] = 'new-22f09e9e-0aab-4adf-a04f-8473e31e349a';
    $pane = new stdClass();
    $pane->pid = 'new-7f91e52c-0c31-4887-a174-88e7d52917cb';
    $pane->panel = 'minipanel_two_50_bottom';
    $pane->type = 'block';
    $pane->subtype = 'views-streams-block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '7f91e52c-0c31-4887-a174-88e7d52917cb';
    $display->content['new-7f91e52c-0c31-4887-a174-88e7d52917cb'] = $pane;
    $display->panels['minipanel_two_50_bottom'][2] = 'new-7f91e52c-0c31-4887-a174-88e7d52917cb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['add_new_channel'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'browse';
  $mini->category = '';
  $mini->admin_title = 'Browse';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'two_50_mp';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'minipanel_two_50_top' => NULL,
      'minipanel_two_50_first' => NULL,
      'minipanel_two_50_second' => NULL,
      'minipanel_two_50_bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7b9972da-3817-41a9-8fb3-b78acda6dd0e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c3bdbbe3-8f90-46fd-b840-dbc7e46ab420';
    $pane->panel = 'minipanel_two_50_bottom';
    $pane->type = 'block';
    $pane->subtype = 'multistream-multistream_browse_results';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c3bdbbe3-8f90-46fd-b840-dbc7e46ab420';
    $display->content['new-c3bdbbe3-8f90-46fd-b840-dbc7e46ab420'] = $pane;
    $display->panels['minipanel_two_50_bottom'][0] = 'new-c3bdbbe3-8f90-46fd-b840-dbc7e46ab420';
    $pane = new stdClass();
    $pane->pid = 'new-8008e50e-3f52-47c2-ad02-384be262ff7a';
    $pane->panel = 'minipanel_two_50_bottom';
    $pane->type = 'block';
    $pane->subtype = 'views-whats_hot-block';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8008e50e-3f52-47c2-ad02-384be262ff7a';
    $display->content['new-8008e50e-3f52-47c2-ad02-384be262ff7a'] = $pane;
    $display->panels['minipanel_two_50_bottom'][1] = 'new-8008e50e-3f52-47c2-ad02-384be262ff7a';
    $pane = new stdClass();
    $pane->pid = 'new-0300f908-667d-4a82-b412-0b0bc187de8f';
    $pane->panel = 'minipanel_two_50_bottom';
    $pane->type = 'block';
    $pane->subtype = 'views-whats_hot_games-games_whats_hot';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '0300f908-667d-4a82-b412-0b0bc187de8f';
    $display->content['new-0300f908-667d-4a82-b412-0b0bc187de8f'] = $pane;
    $display->panels['minipanel_two_50_bottom'][2] = 'new-0300f908-667d-4a82-b412-0b0bc187de8f';
    $pane = new stdClass();
    $pane->pid = 'new-92a3fa92-1305-4f2e-9dcd-c53de26dea1a';
    $pane->panel = 'minipanel_two_50_top';
    $pane->type = 'block';
    $pane->subtype = 'multistream-browse_by_game';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '92a3fa92-1305-4f2e-9dcd-c53de26dea1a';
    $display->content['new-92a3fa92-1305-4f2e-9dcd-c53de26dea1a'] = $pane;
    $display->panels['minipanel_two_50_top'][0] = 'new-92a3fa92-1305-4f2e-9dcd-c53de26dea1a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['browse'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'browse_no_results';
  $mini->category = '';
  $mini->admin_title = 'Browse - No Results';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '5723064f-6750-4fab-8244-33bdcb2bf15e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2be2885c-1df5-488e-9c07-888bab0d473c';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Search Results',
      'body' => '<p><span style="color: red;">0 Results Found</span></p>
',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2be2885c-1df5-488e-9c07-888bab0d473c';
    $display->content['new-2be2885c-1df5-488e-9c07-888bab0d473c'] = $pane;
    $display->panels['center'][0] = 'new-2be2885c-1df5-488e-9c07-888bab0d473c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['browse_no_results'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'favorites';
  $mini->category = '';
  $mini->admin_title = 'Favorites';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'two_50_mp';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'minipanel_two_50_top' => NULL,
      'minipanel_two_50_first' => NULL,
      'minipanel_two_50_second' => NULL,
      'minipanel_two_50_bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Favorites';
  $display->uuid = 'ea827f73-9623-4a1d-a297-dd0e09c1d4b8';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9a4b0ce2-de51-4273-82df-e1db02d73eba';
    $pane->panel = 'minipanel_two_50_bottom';
    $pane->type = 'panels_mini';
    $pane->subtype = 'favorites_anonymous';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 2,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Favorites',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9a4b0ce2-de51-4273-82df-e1db02d73eba';
    $display->content['new-9a4b0ce2-de51-4273-82df-e1db02d73eba'] = $pane;
    $display->panels['minipanel_two_50_bottom'][0] = 'new-9a4b0ce2-de51-4273-82df-e1db02d73eba';
    $pane = new stdClass();
    $pane->pid = 'new-c53f6de1-05b3-458f-a843-2cde2ca4da45';
    $pane->panel = 'minipanel_two_50_bottom';
    $pane->type = 'panels_mini';
    $pane->subtype = 'favorites_empty';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 2,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'favorites-empty',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c53f6de1-05b3-458f-a843-2cde2ca4da45';
    $display->content['new-c53f6de1-05b3-458f-a843-2cde2ca4da45'] = $pane;
    $display->panels['minipanel_two_50_bottom'][1] = 'new-c53f6de1-05b3-458f-a843-2cde2ca4da45';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['favorites'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'favorites_anonymous';
  $mini->category = '';
  $mini->admin_title = 'Favorites - Anonymous';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'two_50_mp';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'minipanel_one_main_fw' => NULL,
      'minipanel_one_main' => NULL,
      'minipanel_two_50_top' => NULL,
      'minipanel_two_50_first' => NULL,
      'minipanel_two_50_second' => NULL,
      'minipanel_two_50_bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '47b2bd52-a8fc-41ec-b27b-2e4894367a3b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bb6caf7a-0643-4355-96f2-cd4313b248b4';
    $pane->panel = 'minipanel_two_50_bottom';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Intro',
      'title' => '',
      'body' => '<p>Your favorite multi-streams and channels will appear here.</p>

<p>Start your own faves and sign up free!</p>
',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'bb6caf7a-0643-4355-96f2-cd4313b248b4';
    $display->content['new-bb6caf7a-0643-4355-96f2-cd4313b248b4'] = $pane;
    $display->panels['minipanel_two_50_bottom'][0] = 'new-bb6caf7a-0643-4355-96f2-cd4313b248b4';
    $pane = new stdClass();
    $pane->pid = 'new-8e277e8c-f83f-48f4-918d-5ea1d8913ed9';
    $pane->panel = 'minipanel_two_50_bottom';
    $pane->type = 'block';
    $pane->subtype = 'hybridauth-hybridauth';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8e277e8c-f83f-48f4-918d-5ea1d8913ed9';
    $display->content['new-8e277e8c-f83f-48f4-918d-5ea1d8913ed9'] = $pane;
    $display->panels['minipanel_two_50_bottom'][1] = 'new-8e277e8c-f83f-48f4-918d-5ea1d8913ed9';
    $pane = new stdClass();
    $pane->pid = 'new-d3046143-256d-4620-8332-f5f4f3c358e4';
    $pane->panel = 'minipanel_two_50_bottom';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Preview',
      'title' => '',
      'body' => '<p><img alt="favorites preview" src="/sites/all/modules/custom/multistream/images/favorites-preview.png" title="favorites preview" /></p>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'd3046143-256d-4620-8332-f5f4f3c358e4';
    $display->content['new-d3046143-256d-4620-8332-f5f4f3c358e4'] = $pane;
    $display->panels['minipanel_two_50_bottom'][2] = 'new-d3046143-256d-4620-8332-f5f4f3c358e4';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['favorites_anonymous'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'favorites_empty';
  $mini->category = '';
  $mini->admin_title = 'Favorites - Empty';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Favorites';
  $display->uuid = '1e7418ab-a647-40af-8e9c-05db310a74df';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b014b40d-a9c4-4ee9-8af5-c72e2d2c6037';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Welcome ',
      'title' => '',
      'body' => 'Welcome to your Favorites Library!

Add new multi-streams and channels by hovering your mouse over any stream thumbnail and clicking the Star icon.

Now let\'s get some awesome content in here!',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b014b40d-a9c4-4ee9-8af5-c72e2d2c6037';
    $display->content['new-b014b40d-a9c4-4ee9-8af5-c72e2d2c6037'] = $pane;
    $display->panels['center'][0] = 'new-b014b40d-a9c4-4ee9-8af5-c72e2d2c6037';
    $pane = new stdClass();
    $pane->pid = 'new-fd909f77-a7a1-4fe4-aadf-9852a685966c';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Start Adding Favs',
      'title' => 'Start Adding Favs',
      'body' => '<ul>
<li class="browse">
<strong>Browse</strong>
Find teams, channels and events
</li>
<li class="add-channel">
<strong>Add Channel by URL</strong>
Copy and paste Twitch channels
</li>
<li class="import-twitch">
<strong>Import Twitch Favs</strong>
Import channels you follow on twitch
</li>
</ul>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'fd909f77-a7a1-4fe4-aadf-9852a685966c';
    $display->content['new-fd909f77-a7a1-4fe4-aadf-9852a685966c'] = $pane;
    $display->panels['center'][1] = 'new-fd909f77-a7a1-4fe4-aadf-9852a685966c';
    $pane = new stdClass();
    $pane->pid = 'new-b34ab2d8-af93-4bbd-b065-1f3b40b84075';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'views-streams-block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'b34ab2d8-af93-4bbd-b065-1f3b40b84075';
    $display->content['new-b34ab2d8-af93-4bbd-b065-1f3b40b84075'] = $pane;
    $display->panels['center'][2] = 'new-b34ab2d8-af93-4bbd-b065-1f3b40b84075';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['favorites_empty'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'multistream_share';
  $mini->category = '';
  $mini->admin_title = 'Multistream Share';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '4dfefd84-5f01-47fa-896c-b928e1acfb1e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-36bf85ae-65e5-4b43-9653-24ba7c645d65';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'multistream-multistream_share';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '36bf85ae-65e5-4b43-9653-24ba7c645d65';
    $display->content['new-36bf85ae-65e5-4b43-9653-24ba7c645d65'] = $pane;
    $display->panels['center'][0] = 'new-36bf85ae-65e5-4b43-9653-24ba7c645d65';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['multistream_share'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'now_playing';
  $mini->category = '';
  $mini->admin_title = 'Now Playing';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'two_50_mp';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'minipanel_two_50_top' => NULL,
      'minipanel_two_50_first' => NULL,
      'minipanel_two_50_second' => NULL,
      'minipanel_two_50_bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7b1c381e-2e8b-4d68-bcc1-6ac7b8bff86a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-83f99d22-5416-432b-849d-d417a97a96ec';
    $pane->panel = 'minipanel_two_50_bottom';
    $pane->type = 'block';
    $pane->subtype = 'multistream-now_playing';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '83f99d22-5416-432b-849d-d417a97a96ec';
    $display->content['new-83f99d22-5416-432b-849d-d417a97a96ec'] = $pane;
    $display->panels['minipanel_two_50_bottom'][0] = 'new-83f99d22-5416-432b-849d-d417a97a96ec';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['now_playing'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'player_chat';
  $mini->category = '';
  $mini->admin_title = 'Player Chat';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'one_mp';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'minipanel_one_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '240cd457-29c0-470c-9c2d-8ea0cb5756bd';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0a4aa1c5-4b4b-4218-8928-6cc918c183d4';
    $pane->panel = 'minipanel_one_main';
    $pane->type = 'block';
    $pane->subtype = 'multistream-multistream_chat';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0a4aa1c5-4b4b-4218-8928-6cc918c183d4';
    $display->content['new-0a4aa1c5-4b4b-4218-8928-6cc918c183d4'] = $pane;
    $display->panels['minipanel_one_main'][0] = 'new-0a4aa1c5-4b4b-4218-8928-6cc918c183d4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['player_chat'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'player_manage';
  $mini->category = '';
  $mini->admin_title = 'Player Manage';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'two_50_mp';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'minipanel_two_50_top' => NULL,
      'minipanel_two_50_first' => NULL,
      'minipanel_two_50_second' => NULL,
      'minipanel_two_50_bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '89e58a7c-fdff-4474-9fa3-39935be2cc55';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fdcf8f85-6f05-4eb5-985c-8156b592396c';
    $pane->panel = 'minipanel_two_50_bottom';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 2,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Anonymous Content',
      'title' => 'Customize',
      'body' => '<p>Link your social networks, add Twitter feeds and upload cover images &amp; backgrounds!</p>

<p>Get started and register for a free account using social or sign up by email:</p>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'fdcf8f85-6f05-4eb5-985c-8156b592396c';
    $display->content['new-fdcf8f85-6f05-4eb5-985c-8156b592396c'] = $pane;
    $display->panels['minipanel_two_50_bottom'][0] = 'new-fdcf8f85-6f05-4eb5-985c-8156b592396c';
    $pane = new stdClass();
    $pane->pid = 'new-6a819e53-680d-4a12-bfd4-36534c3ecba9';
    $pane->panel = 'minipanel_two_50_bottom';
    $pane->type = 'block';
    $pane->subtype = 'hybridauth-hybridauth';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(),
          ),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '6a819e53-680d-4a12-bfd4-36534c3ecba9';
    $display->content['new-6a819e53-680d-4a12-bfd4-36534c3ecba9'] = $pane;
    $display->panels['minipanel_two_50_bottom'][1] = 'new-6a819e53-680d-4a12-bfd4-36534c3ecba9';
    $pane = new stdClass();
    $pane->pid = 'new-305ef337-5573-407a-91bf-1681f7aa1b5f';
    $pane->panel = 'minipanel_two_50_bottom';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 2,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Preview (Anonymous)',
      'title' => '',
      'body' => '<p><img alt="favorites preview" src="/sites/all/modules/custom/multistream/images/favorites-preview.png" title="favorites preview" /></p>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '305ef337-5573-407a-91bf-1681f7aa1b5f';
    $display->content['new-305ef337-5573-407a-91bf-1681f7aa1b5f'] = $pane;
    $display->panels['minipanel_two_50_bottom'][2] = 'new-305ef337-5573-407a-91bf-1681f7aa1b5f';
    $pane = new stdClass();
    $pane->pid = 'new-9e598516-03d4-4382-9d96-2d38ae382804';
    $pane->panel = 'minipanel_two_50_bottom';
    $pane->type = 'block';
    $pane->subtype = 'multistream-multistream_manage';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 2,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '9e598516-03d4-4382-9d96-2d38ae382804';
    $display->content['new-9e598516-03d4-4382-9d96-2d38ae382804'] = $pane;
    $display->panels['minipanel_two_50_bottom'][3] = 'new-9e598516-03d4-4382-9d96-2d38ae382804';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['player_manage'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'player_menu';
  $mini->category = '';
  $mini->admin_title = 'Player Menu';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '13e15aac-230f-4b84-a0d9-f32493804acc';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a3ced02f-685a-4ace-a838-7d1c5b819e11';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'quicktabs-player_menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a3ced02f-685a-4ace-a838-7d1c5b819e11';
    $display->content['new-a3ced02f-685a-4ace-a838-7d1c5b819e11'] = $pane;
    $display->panels['center'][0] = 'new-a3ced02f-685a-4ace-a838-7d1c5b819e11';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['player_menu'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'player_share';
  $mini->category = '';
  $mini->admin_title = 'Player Share';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'two_50_mp';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'minipanel_one_main' => NULL,
      'minipanel_two_50_top' => NULL,
      'minipanel_two_50_first' => NULL,
      'minipanel_two_50_second' => NULL,
      'minipanel_two_50_bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '86c2828a-c471-4c58-a90b-ba42b024d9ea';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-811e7dda-9750-4e63-b58e-33e2338a1ee0';
    $pane->panel = 'minipanel_two_50_bottom';
    $pane->type = 'block';
    $pane->subtype = 'multistream-multistream_share_social';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '811e7dda-9750-4e63-b58e-33e2338a1ee0';
    $display->content['new-811e7dda-9750-4e63-b58e-33e2338a1ee0'] = $pane;
    $display->panels['minipanel_two_50_bottom'][0] = 'new-811e7dda-9750-4e63-b58e-33e2338a1ee0';
    $pane = new stdClass();
    $pane->pid = 'new-5bc69b2a-91c4-4b40-9286-af497aa3f5da';
    $pane->panel = 'minipanel_two_50_bottom';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Spread the word',
      'title' => 'Spread the word',
      'body' => '<p>Like what you\'re watching? Spread the word and show what gaming is all about.</p>
',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5bc69b2a-91c4-4b40-9286-af497aa3f5da';
    $display->content['new-5bc69b2a-91c4-4b40-9286-af497aa3f5da'] = $pane;
    $display->panels['minipanel_two_50_bottom'][1] = 'new-5bc69b2a-91c4-4b40-9286-af497aa3f5da';
    $pane = new stdClass();
    $pane->pid = 'new-649b435e-e294-43ba-b9e7-663a0c2bfcee';
    $pane->panel = 'minipanel_two_50_bottom';
    $pane->type = 'block';
    $pane->subtype = 'sr_core-social_share';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '649b435e-e294-43ba-b9e7-663a0c2bfcee';
    $display->content['new-649b435e-e294-43ba-b9e7-663a0c2bfcee'] = $pane;
    $display->panels['minipanel_two_50_bottom'][2] = 'new-649b435e-e294-43ba-b9e7-663a0c2bfcee';
    $pane = new stdClass();
    $pane->pid = 'new-58157560-e1d4-4467-aa52-6582a24dd895';
    $pane->panel = 'minipanel_two_50_bottom';
    $pane->type = 'block';
    $pane->subtype = 'multistream-multistream_share_link';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '58157560-e1d4-4467-aa52-6582a24dd895';
    $display->content['new-58157560-e1d4-4467-aa52-6582a24dd895'] = $pane;
    $display->panels['minipanel_two_50_bottom'][3] = 'new-58157560-e1d4-4467-aa52-6582a24dd895';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['player_share'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'player_twitter_feed';
  $mini->category = '';
  $mini->admin_title = 'Player Twitter Feed';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'one_mp';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'minipanel_one_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '8ab793ae-27a5-40ca-afa0-005acc7c18e0';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bcccd7de-421f-4150-91fc-db967b90970e';
    $pane->panel = 'minipanel_one_main';
    $pane->type = 'block';
    $pane->subtype = 'multistream-multistream_twitter_feed';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'bcccd7de-421f-4150-91fc-db967b90970e';
    $display->content['new-bcccd7de-421f-4150-91fc-db967b90970e'] = $pane;
    $display->panels['minipanel_one_main'][0] = 'new-bcccd7de-421f-4150-91fc-db967b90970e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['player_twitter_feed'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'social_menu';
  $mini->category = '';
  $mini->admin_title = 'Social Menu';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '8ae78a56-f49e-4ea1-82fc-c6a343e4e835';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2472c78c-39da-4f1a-9583-6e531d10f252';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'quicktabs-social_menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2472c78c-39da-4f1a-9583-6e531d10f252';
    $display->content['new-2472c78c-39da-4f1a-9583-6e531d10f252'] = $pane;
    $display->panels['center'][0] = 'new-2472c78c-39da-4f1a-9583-6e531d10f252';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['social_menu'] = $mini;

  return $export;
}
