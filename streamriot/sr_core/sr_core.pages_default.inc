<?php
/**
 * @file
 * sr_core.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function sr_core_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'blog_panel_context';
  $handler->task = 'blog';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Blogs',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'three_25_50_25';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'sidebar_first',
          1 => 'center',
          2 => 'sidebar_second',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => '54.41375384625165',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'center-content',
      ),
      'sidebar_first' => array(
        'type' => 'region',
        'title' => 'Sidebar first',
        'width' => 21.77053101007,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'sidebar-first blog-side-first',
      ),
      'sidebar_second' => array(
        'type' => 'region',
        'title' => 'Sidebar second',
        'width' => '23.815715143678588',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'sidebar-second',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'blog_leftside' => NULL,
      'blog_rightside' => NULL,
      'sidebar_first' => NULL,
      'sidebar_second' => NULL,
      'watch_video' => NULL,
      'three_25_50_25_top' => NULL,
      'three_25_50_25_first' => NULL,
      'three_25_50_25_second' => NULL,
      'three_25_50_25_third' => NULL,
      'three_25_50_25_bottom' => NULL,
    ),
    'sidebar_first' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = 'Blogs';
  $display->uuid = '228deba0-dcb9-466f-a359-883312fa6286';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d724fb46-a4fc-4f33-911c-102514b82904';
    $pane->panel = 'three_25_50_25_first';
    $pane->type = 'block';
    $pane->subtype = 'block-5';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Welcome to our blog!',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd724fb46-a4fc-4f33-911c-102514b82904';
    $display->content['new-d724fb46-a4fc-4f33-911c-102514b82904'] = $pane;
    $display->panels['three_25_50_25_first'][0] = 'new-d724fb46-a4fc-4f33-911c-102514b82904';
    $pane = new stdClass();
    $pane->pid = 'new-5e701ae6-f3dc-45c5-9242-12095fd901a6';
    $pane->panel = 'three_25_50_25_first';
    $pane->type = 'block';
    $pane->subtype = 'views-tweets-block_1';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5e701ae6-f3dc-45c5-9242-12095fd901a6';
    $display->content['new-5e701ae6-f3dc-45c5-9242-12095fd901a6'] = $pane;
    $display->panels['three_25_50_25_first'][1] = 'new-5e701ae6-f3dc-45c5-9242-12095fd901a6';
    $pane = new stdClass();
    $pane->pid = 'new-4928218f-a282-46fe-93b4-1221c8050d38';
    $pane->panel = 'three_25_50_25_first';
    $pane->type = 'block';
    $pane->subtype = 'block-6';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'watch-video',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '4928218f-a282-46fe-93b4-1221c8050d38';
    $display->content['new-4928218f-a282-46fe-93b4-1221c8050d38'] = $pane;
    $display->panels['three_25_50_25_first'][2] = 'new-4928218f-a282-46fe-93b4-1221c8050d38';
    $pane = new stdClass();
    $pane->pid = 'new-26141c3b-81a0-4953-8fb1-bba1379df17d';
    $pane->panel = 'three_25_50_25_first';
    $pane->type = 'block';
    $pane->subtype = 'views-social_feed-social_feed';
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
    $pane->uuid = '26141c3b-81a0-4953-8fb1-bba1379df17d';
    $display->content['new-26141c3b-81a0-4953-8fb1-bba1379df17d'] = $pane;
    $display->panels['three_25_50_25_first'][3] = 'new-26141c3b-81a0-4953-8fb1-bba1379df17d';
    $pane = new stdClass();
    $pane->pid = 'new-71655c5f-dc17-4b28-96bf-31e6dc920563';
    $pane->panel = 'three_25_50_25_second';
    $pane->type = 'block';
    $pane->subtype = 'views-blog_listing-block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '71655c5f-dc17-4b28-96bf-31e6dc920563';
    $display->content['new-71655c5f-dc17-4b28-96bf-31e6dc920563'] = $pane;
    $display->panels['three_25_50_25_second'][0] = 'new-71655c5f-dc17-4b28-96bf-31e6dc920563';
    $pane = new stdClass();
    $pane->pid = 'new-717543c5-a9d8-444c-a3ca-a6f37e5ccab5';
    $pane->panel = 'three_25_50_25_third';
    $pane->type = 'block';
    $pane->subtype = 'simpleads-ad_groups_318';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'advertisement',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '717543c5-a9d8-444c-a3ca-a6f37e5ccab5';
    $display->content['new-717543c5-a9d8-444c-a3ca-a6f37e5ccab5'] = $pane;
    $display->panels['three_25_50_25_third'][0] = 'new-717543c5-a9d8-444c-a3ca-a6f37e5ccab5';
    $pane = new stdClass();
    $pane->pid = 'new-02568cbb-b40a-4dbe-8280-c816f0fda262';
    $pane->panel = 'three_25_50_25_third';
    $pane->type = 'block';
    $pane->subtype = 'quicktabs-popular_blog';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '02568cbb-b40a-4dbe-8280-c816f0fda262';
    $display->content['new-02568cbb-b40a-4dbe-8280-c816f0fda262'] = $pane;
    $display->panels['three_25_50_25_third'][1] = 'new-02568cbb-b40a-4dbe-8280-c816f0fda262';
    $pane = new stdClass();
    $pane->pid = 'new-55523c4e-bfb5-4cb2-a4e4-dc7d373b1740';
    $pane->panel = 'three_25_50_25_third';
    $pane->type = 'block';
    $pane->subtype = 'views-blog_right_side_block-block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '55523c4e-bfb5-4cb2-a4e4-dc7d373b1740';
    $display->content['new-55523c4e-bfb5-4cb2-a4e4-dc7d373b1740'] = $pane;
    $display->panels['three_25_50_25_third'][2] = 'new-55523c4e-bfb5-4cb2-a4e4-dc7d373b1740';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['blog_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'contact_site_panel_context';
  $handler->task = 'contact_site';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'three_25_50_25';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'three_25_50_25_top' => NULL,
      'three_25_50_25_first' => NULL,
      'three_25_50_25_second' => NULL,
      'three_25_50_25_third' => NULL,
      'three_25_50_25_bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '17c19609-cc8f-4b34-b9a6-2913693f9709';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c48f376f-cac5-4d48-b83d-e9736b43cc10';
    $pane->panel = 'three_25_50_25_first';
    $pane->type = 'block';
    $pane->subtype = 'sr_core-social_share';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Hi! We\'re StreamRiot :)',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c48f376f-cac5-4d48-b83d-e9736b43cc10';
    $display->content['new-c48f376f-cac5-4d48-b83d-e9736b43cc10'] = $pane;
    $display->panels['three_25_50_25_first'][0] = 'new-c48f376f-cac5-4d48-b83d-e9736b43cc10';
    $pane = new stdClass();
    $pane->pid = 'new-35049117-37a5-4c57-bb67-202c7c938599';
    $pane->panel = 'three_25_50_25_first';
    $pane->type = 'block';
    $pane->subtype = 'views-social_feed-social_feed';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '35049117-37a5-4c57-bb67-202c7c938599';
    $display->content['new-35049117-37a5-4c57-bb67-202c7c938599'] = $pane;
    $display->panels['three_25_50_25_first'][1] = 'new-35049117-37a5-4c57-bb67-202c7c938599';
    $pane = new stdClass();
    $pane->pid = 'new-671f38f2-086a-444c-9efe-38e0e0f95287';
    $pane->panel = 'three_25_50_25_second';
    $pane->type = 'contact';
    $pane->subtype = 'contact';
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
    $pane->uuid = '671f38f2-086a-444c-9efe-38e0e0f95287';
    $display->content['new-671f38f2-086a-444c-9efe-38e0e0f95287'] = $pane;
    $display->panels['three_25_50_25_second'][0] = 'new-671f38f2-086a-444c-9efe-38e0e0f95287';
    $pane = new stdClass();
    $pane->pid = 'new-4045c147-dbe0-4d36-9551-752ddc947956';
    $pane->panel = 'three_25_50_25_third';
    $pane->type = 'block';
    $pane->subtype = 'simpleads-ad_groups_318';
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
    $pane->uuid = '4045c147-dbe0-4d36-9551-752ddc947956';
    $display->content['new-4045c147-dbe0-4d36-9551-752ddc947956'] = $pane;
    $display->panels['three_25_50_25_third'][0] = 'new-4045c147-dbe0-4d36-9551-752ddc947956';
    $pane = new stdClass();
    $pane->pid = 'new-075112ec-98ad-4436-bce1-a9893267875d';
    $pane->panel = 'three_25_50_25_third';
    $pane->type = 'block';
    $pane->subtype = 'views-blog_right_side_block-block';
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
    $pane->uuid = '075112ec-98ad-4436-bce1-a9893267875d';
    $display->content['new-075112ec-98ad-4436-bce1-a9893267875d'] = $pane;
    $display->panels['three_25_50_25_third'][1] = 'new-075112ec-98ad-4436-bce1-a9893267875d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-671f38f2-086a-444c-9efe-38e0e0f95287';
  $handler->conf['display'] = $display;
  $export['contact_site_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -99;
  $handler->conf = array(
    'title' => 'Basic page set up',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'blog' => 'blog',
              'help' => 'help',
              'staff' => 'staff',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'three_25_50_25';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'sidebar_first',
          1 => 'center',
          2 => 'sidebar_second',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => '52.4142945866848',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'center-content blog-related',
      ),
      'sidebar_second' => array(
        'type' => 'region',
        'title' => 'Sidebar second',
        'width' => '22.986177274171503',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'sidebar-second',
      ),
      'sidebar_first' => array(
        'type' => 'region',
        'title' => 'Sidebar first',
        'width' => '24.599528139143704',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'sidebar-first',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'sidebar_second' => NULL,
      'sidebar_first' => NULL,
      'three_25_50_25_top' => NULL,
      'three_25_50_25_first' => NULL,
      'three_25_50_25_second' => NULL,
      'three_25_50_25_third' => NULL,
      'three_25_50_25_bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'c9676f1e-0b6f-4ee4-b3a0-8e36ac7f19ff';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-290e6bad-25ae-4d4b-81d3-7aa1591401a1';
    $pane->panel = 'three_25_50_25_first';
    $pane->type = 'block';
    $pane->subtype = 'block-5';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Welcome to our blog!',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '290e6bad-25ae-4d4b-81d3-7aa1591401a1';
    $display->content['new-290e6bad-25ae-4d4b-81d3-7aa1591401a1'] = $pane;
    $display->panels['three_25_50_25_first'][0] = 'new-290e6bad-25ae-4d4b-81d3-7aa1591401a1';
    $pane = new stdClass();
    $pane->pid = 'new-51a2a894-381a-42c7-bd35-151f60f26028';
    $pane->panel = 'three_25_50_25_first';
    $pane->type = 'block';
    $pane->subtype = 'views-tweets-block_1';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '51a2a894-381a-42c7-bd35-151f60f26028';
    $display->content['new-51a2a894-381a-42c7-bd35-151f60f26028'] = $pane;
    $display->panels['three_25_50_25_first'][1] = 'new-51a2a894-381a-42c7-bd35-151f60f26028';
    $pane = new stdClass();
    $pane->pid = 'new-57a81ce7-d8d7-4440-9fc2-ed8ea715c7c2';
    $pane->panel = 'three_25_50_25_second';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 1,
      'no_extras' => 1,
      'override_title' => 0,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 1,
      'leave_node_title' => 0,
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '57a81ce7-d8d7-4440-9fc2-ed8ea715c7c2';
    $display->content['new-57a81ce7-d8d7-4440-9fc2-ed8ea715c7c2'] = $pane;
    $display->panels['three_25_50_25_second'][0] = 'new-57a81ce7-d8d7-4440-9fc2-ed8ea715c7c2';
    $pane = new stdClass();
    $pane->pid = 'new-0599a3d1-e5fa-4be1-b867-69753dbc21f4';
    $pane->panel = 'three_25_50_25_third';
    $pane->type = 'block';
    $pane->subtype = 'simpleads-ad_groups_318';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'advertisement',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0599a3d1-e5fa-4be1-b867-69753dbc21f4';
    $display->content['new-0599a3d1-e5fa-4be1-b867-69753dbc21f4'] = $pane;
    $display->panels['three_25_50_25_third'][0] = 'new-0599a3d1-e5fa-4be1-b867-69753dbc21f4';
    $pane = new stdClass();
    $pane->pid = 'new-612aee74-a173-4b01-ba67-d0db726b4ad5';
    $pane->panel = 'three_25_50_25_third';
    $pane->type = 'block';
    $pane->subtype = 'views-blog_right_side_block-block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '612aee74-a173-4b01-ba67-d0db726b4ad5';
    $display->content['new-612aee74-a173-4b01-ba67-d0db726b4ad5'] = $pane;
    $display->panels['three_25_50_25_third'][1] = 'new-612aee74-a173-4b01-ba67-d0db726b4ad5';
    $pane = new stdClass();
    $pane->pid = 'new-decc128c-1f84-40db-9d23-10f750c41bb8';
    $pane->panel = 'three_25_50_25_top';
    $pane->type = 'page_tabs';
    $pane->subtype = 'page_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'both',
      'id' => 'tabs',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'decc128c-1f84-40db-9d23-10f750c41bb8';
    $display->content['new-decc128c-1f84-40db-9d23-10f750c41bb8'] = $pane;
    $display->panels['three_25_50_25_top'][0] = 'new-decc128c-1f84-40db-9d23-10f750c41bb8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_edit_panel_context';
  $handler->task = 'user_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'three_25_50_25';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'three_25_50_25_top' => NULL,
      'three_25_50_25_first' => NULL,
      'three_25_50_25_second' => NULL,
      'three_25_50_25_third' => NULL,
      'three_25_50_25_bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '40151331-2e38-4cec-876b-fabfb82d7d4c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2df8118a-bc94-4f32-8195-aa9a12812701';
    $pane->panel = 'three_25_50_25_first';
    $pane->type = 'user_profile';
    $pane->subtype = 'user_profile';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_user_edit_1',
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
    $pane->uuid = '2df8118a-bc94-4f32-8195-aa9a12812701';
    $display->content['new-2df8118a-bc94-4f32-8195-aa9a12812701'] = $pane;
    $display->panels['three_25_50_25_first'][0] = 'new-2df8118a-bc94-4f32-8195-aa9a12812701';
    $pane = new stdClass();
    $pane->pid = 'new-03e63dac-0ee9-45c6-902e-e564010bafa6';
    $pane->panel = 'three_25_50_25_first';
    $pane->type = 'user_picture';
    $pane->subtype = 'user_picture';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_user_edit_1',
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
    $pane->uuid = '03e63dac-0ee9-45c6-902e-e564010bafa6';
    $display->content['new-03e63dac-0ee9-45c6-902e-e564010bafa6'] = $pane;
    $display->panels['three_25_50_25_first'][1] = 'new-03e63dac-0ee9-45c6-902e-e564010bafa6';
    $pane = new stdClass();
    $pane->pid = 'new-79d73009-647a-4140-b38e-a0e2571bb7f9';
    $pane->panel = 'three_25_50_25_first';
    $pane->type = 'entity_field_extra';
    $pane->subtype = 'user:hybridauth_identities';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_user_edit_1',
      'override_title' => 1,
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
    $pane->uuid = '79d73009-647a-4140-b38e-a0e2571bb7f9';
    $display->content['new-79d73009-647a-4140-b38e-a0e2571bb7f9'] = $pane;
    $display->panels['three_25_50_25_first'][2] = 'new-79d73009-647a-4140-b38e-a0e2571bb7f9';
    $pane = new stdClass();
    $pane->pid = 'new-218900a8-0f55-4be3-b74f-d8f354dad2a3';
    $pane->panel = 'three_25_50_25_second';
    $pane->type = 'form';
    $pane->subtype = 'form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_user_edit_1',
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
    $pane->uuid = '218900a8-0f55-4be3-b74f-d8f354dad2a3';
    $display->content['new-218900a8-0f55-4be3-b74f-d8f354dad2a3'] = $pane;
    $display->panels['three_25_50_25_second'][0] = 'new-218900a8-0f55-4be3-b74f-d8f354dad2a3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-218900a8-0f55-4be3-b74f-d8f354dad2a3';
  $handler->conf['display'] = $display;
  $export['user_edit_panel_context'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function sr_core_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'help_page';
  $page->task = 'page';
  $page->admin_title = 'Help page';
  $page->admin_description = '';
  $page->path = 'help/%node';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_help_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'help_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel Help',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'three_inset_left';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'sidebar_first',
          1 => 'center',
          2 => 'sidebar_second',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => '52.93224331096638',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'center-content',
      ),
      'sidebar_first' => array(
        'type' => 'region',
        'title' => 'Sidebar First',
        'width' => '23.907305142864036',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'sidebar-first',
      ),
      'sidebar_second' => array(
        'type' => 'region',
        'title' => 'Sidebar second',
        'width' => '23.160451546169583',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'sidebar-second',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'sidebar_first' => NULL,
      'sidebar_second' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'HELP';
  $display->uuid = '59342960-7014-4e63-b212-bc6b70bf5107';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ee5d3b4e-520c-4e5a-9b47-0b7162cbd2ee';
    $pane->panel = 'three_inset_left_inset';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Help page banner',
      'title' => '<none>',
      'body' => '<?php 
global $base_url; 
echo "<img src=\'".$base_url."/sites/default/files/z2.jpg\' />"; 
?>',
      'format' => 'php_code',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ee5d3b4e-520c-4e5a-9b47-0b7162cbd2ee';
    $display->content['new-ee5d3b4e-520c-4e5a-9b47-0b7162cbd2ee'] = $pane;
    $display->panels['three_inset_left_inset'][0] = 'new-ee5d3b4e-520c-4e5a-9b47-0b7162cbd2ee';
    $pane = new stdClass();
    $pane->pid = 'new-f68cc17f-d8ab-4943-b8dd-514be5320cd7';
    $pane->panel = 'three_inset_left_inset';
    $pane->type = 'block';
    $pane->subtype = 'views-help_and_faq_block-block_2';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f68cc17f-d8ab-4943-b8dd-514be5320cd7';
    $display->content['new-f68cc17f-d8ab-4943-b8dd-514be5320cd7'] = $pane;
    $display->panels['three_inset_left_inset'][1] = 'new-f68cc17f-d8ab-4943-b8dd-514be5320cd7';
    $pane = new stdClass();
    $pane->pid = 'new-800d4b93-1b61-4844-b0b6-87dbfb8cff37';
    $pane->panel = 'three_inset_left_middle';
    $pane->type = 'block';
    $pane->subtype = 'quicktabs-help_center';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Find Solutions Here',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '800d4b93-1b61-4844-b0b6-87dbfb8cff37';
    $display->content['new-800d4b93-1b61-4844-b0b6-87dbfb8cff37'] = $pane;
    $display->panels['three_inset_left_middle'][0] = 'new-800d4b93-1b61-4844-b0b6-87dbfb8cff37';
    $pane = new stdClass();
    $pane->pid = 'new-42feb274-2aa7-4f88-84f9-e60a300ee09e';
    $pane->panel = 'three_inset_left_sidebar';
    $pane->type = 'block';
    $pane->subtype = 'formblock-contact_site';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Send Us Your Questions!',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'contact-right-detail',
      'css_class' => 'contact-right-detail',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '42feb274-2aa7-4f88-84f9-e60a300ee09e';
    $display->content['new-42feb274-2aa7-4f88-84f9-e60a300ee09e'] = $pane;
    $display->panels['three_inset_left_sidebar'][0] = 'new-42feb274-2aa7-4f88-84f9-e60a300ee09e';
    $pane = new stdClass();
    $pane->pid = 'new-6e65782d-9b68-4563-99b3-9d422aefe4f6';
    $pane->panel = 'three_inset_left_sidebar';
    $pane->type = 'block';
    $pane->subtype = 'block-10';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '6e65782d-9b68-4563-99b3-9d422aefe4f6';
    $display->content['new-6e65782d-9b68-4563-99b3-9d422aefe4f6'] = $pane;
    $display->panels['three_inset_left_sidebar'][1] = 'new-6e65782d-9b68-4563-99b3-9d422aefe4f6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['help_page'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'home';
  $page->task = 'page';
  $page->admin_title = 'Home';
  $page->admin_description = 'Streamriot home page';
  $page->path = 'home';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_home_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'home';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'home page panel ',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
          1 => 1,
          2 => 5,
          3 => 6,
          4 => 7,
          5 => 8,
          6 => 9,
          7 => 10,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 2,
        ),
        'parent' => 'main',
        'class' => 'Gallery',
      ),
      2 => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'children' => array(
          0 => 3,
          1 => 4,
        ),
        'class' => 'Gallery data',
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'gallery_item1_',
          1 => 'gallery_item1',
          2 => 'gallery_item2',
        ),
        'parent' => '2',
        'class' => 'Gallery1',
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'gallery_text',
        ),
        'parent' => '2',
        'class' => 'Gallery2',
      ),
      'gallery_item1' => array(
        'type' => 'region',
        'title' => 'Gallery Center',
        'width' => '51.14838687948425',
        'width_type' => '%',
        'parent' => '3',
        'class' => '',
      ),
      'gallery_item1_' => array(
        'type' => 'region',
        'title' => 'Gallery item1',
        'width' => '23.93024092053218',
        'width_type' => '%',
        'parent' => '3',
        'class' => '',
      ),
      'gallery_item2' => array(
        'type' => 'region',
        'title' => 'Gallery item2',
        'width' => '24.921372199983566',
        'width_type' => '%',
        'parent' => '3',
        'class' => '',
      ),
      'gallery_text' => array(
        'type' => 'region',
        'title' => 'Gallery text',
        'width' => 100,
        'width_type' => '%',
        'parent' => '4',
        'class' => '',
      ),
      5 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'signup',
        ),
        'parent' => 'main',
        'class' => 'Signup',
      ),
      'signup' => array(
        'type' => 'region',
        'title' => 'Signup',
        'width' => 100,
        'width_type' => '%',
        'parent' => '5',
        'class' => '',
      ),
      6 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'multistream_player1',
          1 => 'multistream_player',
        ),
        'parent' => 'main',
        'class' => 'multistream-player',
      ),
      'multistream_player1' => array(
        'type' => 'region',
        'title' => 'multistream-player1',
        'width' => 50,
        'width_type' => '%',
        'parent' => '6',
        'class' => '',
      ),
      'multistream_player' => array(
        'type' => 'region',
        'title' => 'multistream-player2',
        'width' => 50,
        'width_type' => '%',
        'parent' => '6',
        'class' => '',
      ),
      7 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'teamdata',
        ),
        'parent' => 'main',
        'class' => 'team',
      ),
      'teamdata' => array(
        'type' => 'region',
        'title' => 'teamdata',
        'width' => 100,
        'width_type' => '%',
        'parent' => '7',
        'class' => '',
      ),
      8 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'streamriot',
        ),
        'parent' => 'main',
        'class' => 'streamroits-home',
      ),
      'streamriot' => array(
        'type' => 'region',
        'title' => 'Streamriot',
        'width' => 100,
        'width_type' => '%',
        'parent' => '8',
        'class' => '',
      ),
      9 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'gray_blue',
        ),
        'parent' => 'main',
        'class' => 'gray-blue',
      ),
      'gray_blue' => array(
        'type' => 'region',
        'title' => 'Gray Blue',
        'width' => 100,
        'width_type' => '%',
        'parent' => '9',
        'class' => '',
      ),
      10 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'advertizement_on_home',
        ),
        'parent' => 'main',
        'class' => 'advertizment-onhome',
      ),
      'advertizement_on_home' => array(
        'type' => 'region',
        'title' => 'advertizement-on home',
        'width' => 100,
        'width_type' => '%',
        'parent' => '10',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'gallery' => NULL,
      'gallery_item1' => NULL,
      'gallery_item2' => NULL,
      'gallery_text' => NULL,
      'gallery_item1_' => NULL,
      'signup' => NULL,
      'multistream_player1' => NULL,
      'multistream_player' => NULL,
      'teamdata' => NULL,
      'streamriot' => NULL,
      'gray_blue' => NULL,
      'advertizement_on_home' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Streamriot';
  $display->uuid = '4e072ec2-8801-443e-9829-ff4edc618267';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0cad5ba7-bc8e-441f-8ea5-68c7e9d9ffa7';
    $pane->panel = 'advertizement_on_home';
    $pane->type = 'block';
    $pane->subtype = 'views-tweets_home-block_1';
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
    $pane->uuid = '0cad5ba7-bc8e-441f-8ea5-68c7e9d9ffa7';
    $display->content['new-0cad5ba7-bc8e-441f-8ea5-68c7e9d9ffa7'] = $pane;
    $display->panels['advertizement_on_home'][0] = 'new-0cad5ba7-bc8e-441f-8ea5-68c7e9d9ffa7';
    $pane = new stdClass();
    $pane->pid = 'new-4c606c20-04c0-42da-abcb-d7f5c4002943';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'multistream-multistream_chain_browse';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4c606c20-04c0-42da-abcb-d7f5c4002943';
    $display->content['new-4c606c20-04c0-42da-abcb-d7f5c4002943'] = $pane;
    $display->panels['center'][0] = 'new-4c606c20-04c0-42da-abcb-d7f5c4002943';
    $pane = new stdClass();
    $pane->pid = 'new-cb975902-d7fd-40f5-a994-0b6b7969cb6e';
    $pane->panel = 'gallery_item1';
    $pane->type = 'block';
    $pane->subtype = 'views-slider_stream_home-block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'cb975902-d7fd-40f5-a994-0b6b7969cb6e';
    $display->content['new-cb975902-d7fd-40f5-a994-0b6b7969cb6e'] = $pane;
    $display->panels['gallery_item1'][0] = 'new-cb975902-d7fd-40f5-a994-0b6b7969cb6e';
    $pane = new stdClass();
    $pane->pid = 'new-2b9c6253-024e-46cc-bbd1-d7f62df64195';
    $pane->panel = 'gallery_item1_';
    $pane->type = 'block';
    $pane->subtype = 'views-home_page_term-block_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2b9c6253-024e-46cc-bbd1-d7f62df64195';
    $display->content['new-2b9c6253-024e-46cc-bbd1-d7f62df64195'] = $pane;
    $display->panels['gallery_item1_'][0] = 'new-2b9c6253-024e-46cc-bbd1-d7f62df64195';
    $pane = new stdClass();
    $pane->pid = 'new-227c3e45-b33d-4954-9329-e0820fc56244';
    $pane->panel = 'gallery_item2';
    $pane->type = 'block';
    $pane->subtype = 'views-home_page_term-block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '227c3e45-b33d-4954-9329-e0820fc56244';
    $display->content['new-227c3e45-b33d-4954-9329-e0820fc56244'] = $pane;
    $display->panels['gallery_item2'][0] = 'new-227c3e45-b33d-4954-9329-e0820fc56244';
    $pane = new stdClass();
    $pane->pid = 'new-0d184085-0363-4adb-b1fd-3e00d02c19f8';
    $pane->panel = 'gallery_text';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Gallery bottom text',
      'title' => '',
      'body' => '<h2><span>Hi! </span> We‘re StreamRiot</h2>

<div class="gallery-text">
<h3 class="first nomobile">StreamRiot is a next-gen digital Multi-Live Streaming Video Player.</h3>

<h3 class="second nomobile">We‘re purpose-built to expand e-Sports media into new real-time applications.</h3>

<p class="first mobile">Watch multiple live streams at the same time!</p>
</div>
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
    $pane->uuid = '0d184085-0363-4adb-b1fd-3e00d02c19f8';
    $display->content['new-0d184085-0363-4adb-b1fd-3e00d02c19f8'] = $pane;
    $display->panels['gallery_text'][0] = 'new-0d184085-0363-4adb-b1fd-3e00d02c19f8';
    $pane = new stdClass();
    $pane->pid = 'new-6bf7d550-87b2-4c7f-9ead-0a4f38b1b32d';
    $pane->panel = 'gallery_text';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Mobile Riot Player',
      'title' => '',
      'body' => '<div class="image-riotplayer container"></div>',
      'format' => 'php_code',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'mobile',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '6bf7d550-87b2-4c7f-9ead-0a4f38b1b32d';
    $display->content['new-6bf7d550-87b2-4c7f-9ead-0a4f38b1b32d'] = $pane;
    $display->panels['gallery_text'][1] = 'new-6bf7d550-87b2-4c7f-9ead-0a4f38b1b32d';
    $pane = new stdClass();
    $pane->pid = 'new-88d8dc12-ebd1-4870-a528-6b23a4a7a18e';
    $pane->panel = 'gallery_text';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Mobile: SR is Built for Gamers',
      'title' => '<span>SR is</span> Built for Gamers!',
      'body' => '<h3>Interact with Twitch.tv chats, and join social conversations with gamers around the world!</h3>
',
      'format' => 'php_code',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'mobile',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '88d8dc12-ebd1-4870-a528-6b23a4a7a18e';
    $display->content['new-88d8dc12-ebd1-4870-a528-6b23a4a7a18e'] = $pane;
    $display->panels['gallery_text'][2] = 'new-88d8dc12-ebd1-4870-a528-6b23a4a7a18e';
    $pane = new stdClass();
    $pane->pid = 'new-342a37b2-a520-490b-8971-1dc71aabc370';
    $pane->panel = 'gray_blue';
    $pane->type = 'block';
    $pane->subtype = 'views-blog_right_side_block-block_3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'grid_width' => ' ',
        'left_margin' => '',
        'right_margin' => '',
        'float' => 'float-left',
        'custom_classes' => '',
        'custom_attrib' => '',
      ),
      'style' => 'parrot_styles',
    );
    $pane->css = array(
      'css_id' => 'blog-slider-home',
      'css_class' => 'blog-slider-home',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '342a37b2-a520-490b-8971-1dc71aabc370';
    $display->content['new-342a37b2-a520-490b-8971-1dc71aabc370'] = $pane;
    $display->panels['gray_blue'][0] = 'new-342a37b2-a520-490b-8971-1dc71aabc370';
    $pane = new stdClass();
    $pane->pid = 'new-35d0bae9-d62c-430c-a04b-33cdad3dad7e';
    $pane->panel = 'gray_blue';
    $pane->type = 'block';
    $pane->subtype = 'simpleads-ad_groups_319';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'advertisement',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '35d0bae9-d62c-430c-a04b-33cdad3dad7e';
    $display->content['new-35d0bae9-d62c-430c-a04b-33cdad3dad7e'] = $pane;
    $display->panels['gray_blue'][1] = 'new-35d0bae9-d62c-430c-a04b-33cdad3dad7e';
    $pane = new stdClass();
    $pane->pid = 'new-4c378d1a-2b76-41ee-b0e2-2396d2fe81d1';
    $pane->panel = 'multistream_player';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Player',
      'title' => '<none>',
      'body' => '<p><img src="/sites/default/files/computer-low.jpg" alt="Multi-Stream Player Preview"/></p>
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
    $pane->uuid = '4c378d1a-2b76-41ee-b0e2-2396d2fe81d1';
    $display->content['new-4c378d1a-2b76-41ee-b0e2-2396d2fe81d1'] = $pane;
    $display->panels['multistream_player'][0] = 'new-4c378d1a-2b76-41ee-b0e2-2396d2fe81d1';
    $pane = new stdClass();
    $pane->pid = 'new-2d6ad897-39ce-4bc8-9804-d4a1cbb7e021';
    $pane->panel = 'multistream_player1';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'stream-player-text',
      'title' => '<none>',
      'body' => '<div class="stream-player">
<h2 class="stream-title">Get a multi-stream player on your site! <span>(it’s free)</span></h2>

<ul class="stream-list">
	<li>Give visitors a new interactive playground directly from your website</li>
	<li>Connect with viewers around the world with powerful social media integration tools</li>
	<li>Standard Player embeds are free! Need hosting? We can help :)</li>
</ul>
<a class="stram-button" href="/about">I want more info</a> <a class="stram-button" href="/request-free-embed">Request a Free Embed</a></div>
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
    $pane->uuid = '2d6ad897-39ce-4bc8-9804-d4a1cbb7e021';
    $display->content['new-2d6ad897-39ce-4bc8-9804-d4a1cbb7e021'] = $pane;
    $display->panels['multistream_player1'][0] = 'new-2d6ad897-39ce-4bc8-9804-d4a1cbb7e021';
    $pane = new stdClass();
    $pane->pid = 'new-21cc1ea7-07ac-402e-a823-6cfceac092cc';
    $pane->panel = 'signup';
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
      'admin_title' => 'Signup section',
      'title' => '<none>',
      'body' => '<div class="signup-home">
<div class="inner-signup">
<div class="container inner-signup-container">
<div class="inner-signup-first item nomobile"><a class="watch" href="/multistream"><img alt="Watch Live" src="/sites/default/files/watchlive.png" /></a>
<div class="with-out-hover">
<div class="sign-title"><a href="/multistream">watch live</a></div>

<p class="sign-desc">Watch multiple live streams from our multi-stream player.</p>
</div>

<div class="hover-conetnt">
<div class="sign-title"><a href="/multistream">watch now</a></div>

<p class="sign-desc">Explore the #1 Multi-Stream Player for gamers and e-Sports</p>
</div>
</div>

<div class="inner-signup-second item nomobile"><a --="" class="sign-free" href="/user/register"><img alt="Sign Up" src="/sites/default/files/signupfree.png" /> </a>

<div class="with-out-hover">
<div class="sign-title"><a href="/user/register">connect &amp; share</a></div>

<p class="sign-desc">Connect viewers to your social networks with StreamRiot!</p>
</div>

<div class="hover-conetnt">
<div class="sign-title"><a href="/user/register">sign up free</a></div>

<p class="sign-desc">Start customizing your own multi-streams with a free account.</p>
<a href="/user/register"><span class="already-sign">already registered? sign in</span></a></div>
</div>

<div class="inner-signup-third item nomobile"><a class="watch" href="/multistream"><img alt="Promote" src="/sites/default/files/promote.png" /></a>

<div class="with-out-hover">
<div class="sign-title"><a href="#">promote</a></div>

<p class="sign-desc">Customize our player and promote your events &amp; friends. We can help.</p>
</div>

<div class="hover-conetnt">
<div class="sign-title"><a href="#">wanna promote?</a></div>

<p class="sign-desc">Ask how we can help with your events &amp; tournaments.</p>
</div>
</div>

<div class="inner-signup-last item nomobile"><a class="watch" href="/multistream"><img alt="Dominate" src="/sites/default/files/domenati.png" /></a>

<div class="with-out-hover">
<div class="sign-title"><a href="/multistream">dominate</a></div>

<p class="sign-desc">Quickly access and share your mult-streams. Dominate e-Sports.</p>
</div>

<div class="hover-conetnt">
<div class="sign-title"><a href="/user/register">sign up free</a></div>

<p class="sign-desc">Start your own Favorites Library with a free account</p>
<a href="/user/register"><span class="already-sign">already registered? sign in</span></a></div>
</div>

<p class="mobile"><strong>Visit the full StreamRiot site</strong> to experience our Multi-Live Stream Player</p>
</div>
</div>
</div>
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
    $pane->uuid = '21cc1ea7-07ac-402e-a823-6cfceac092cc';
    $display->content['new-21cc1ea7-07ac-402e-a823-6cfceac092cc'] = $pane;
    $display->panels['signup'][0] = 'new-21cc1ea7-07ac-402e-a823-6cfceac092cc';
    $pane = new stdClass();
    $pane->pid = 'new-11f3c875-446f-4330-b409-264d417516bc';
    $pane->panel = 'streamriot';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'wanna know more ',
      'title' => '<none>',
      'body' => '<div class="stream-wanna">
<h3>Wanna know more about StreamRiot?</h3>
<a class="sr" href="/about">I Need More SR!</a></div>
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
    $pane->uuid = '11f3c875-446f-4330-b409-264d417516bc';
    $display->content['new-11f3c875-446f-4330-b409-264d417516bc'] = $pane;
    $display->panels['streamriot'][0] = 'new-11f3c875-446f-4330-b409-264d417516bc';
    $pane = new stdClass();
    $pane->pid = 'new-7438394f-1da4-4099-80c4-e623032a22fa';
    $pane->panel = 'teamdata';
    $pane->type = 'block';
    $pane->subtype = 'views-staff_on_home-block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'grid_width' => ' ',
        'left_margin' => '',
        'right_margin' => '',
        'float' => 'float-left',
        'custom_classes' => 'lock-border-bottom-orange my-block',
        'custom_attrib' => '',
      ),
      'style' => 'parrot_styles',
    );
    $pane->css = array(
      'css_id' => 'staff-home-view',
      'css_class' => 'staff-home-view clearfix',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7438394f-1da4-4099-80c4-e623032a22fa';
    $display->content['new-7438394f-1da4-4099-80c4-e623032a22fa'] = $pane;
    $display->panels['teamdata'][0] = 'new-7438394f-1da4-4099-80c4-e623032a22fa';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home'] = $page;

  return $pages;

}
