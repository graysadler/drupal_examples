<?php
/**
 * @file
 * sr_core.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function sr_core_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'header';
  $mini->category = '';
  $mini->admin_title = 'Header';
  $mini->admin_description = 'Header';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
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
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'first',
          1 => 'middle',
          2 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      'middle' => array(
        'type' => 'region',
        'title' => 'middle',
        'width' => 25,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
      ),
      'first' => array(
        'type' => 'region',
        'title' => 'first',
        'width' => 25,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'four_25_top' => NULL,
      'four_25_first' => NULL,
      'four_25_second' => NULL,
      'four_25_third' => NULL,
      'four_25_fourth' => NULL,
      'four_25_bottom' => NULL,
      'center' => NULL,
      'middle' => NULL,
      'first' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'd61079f2-be42-4a25-b045-c57c50441268';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-74d54e69-9e71-44d0-adbf-348c640b331e';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'system-main-menu';
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
    $pane->uuid = '74d54e69-9e71-44d0-adbf-348c640b331e';
    $display->content['new-74d54e69-9e71-44d0-adbf-348c640b331e'] = $pane;
    $display->panels['center'][0] = 'new-74d54e69-9e71-44d0-adbf-348c640b331e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['header'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'header_mega_menu';
  $mini->category = '';
  $mini->admin_title = 'Header Mega Menu';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'three_33_mp';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'minipanel_two_50_top' => NULL,
      'minipanel_two_50_first' => NULL,
      'minipanel_two_50_second' => NULL,
      'minipanel_two_50_bottom' => NULL,
      'minipanel_one_main' => NULL,
      'minipanel_three_33_top' => NULL,
      'minipanel_three_33_first' => NULL,
      'minipanel_three_33_second' => NULL,
      'minipanel_three_33_third' => NULL,
      'minipanel_three_33_bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'ab600b03-c09e-4337-afd0-370fa5b7b4e9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3ee2e5be-7e21-4c31-befb-016f11aed6e9';
    $pane->panel = 'minipanel_three_33_first';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Embed',
      'title' => '',
      'body' => '<div class="embed"><a class="free-embed" href="/request-free-embed">Get a free embed!</a>
<p class="amezing">Be amazing and get a <strong>FREE</strong></p>

<p class="stream">Multi-Stream Player Embed!</p>
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
    $pane->uuid = '3ee2e5be-7e21-4c31-befb-016f11aed6e9';
    $display->content['new-3ee2e5be-7e21-4c31-befb-016f11aed6e9'] = $pane;
    $display->panels['minipanel_three_33_first'][0] = 'new-3ee2e5be-7e21-4c31-befb-016f11aed6e9';
    $pane = new stdClass();
    $pane->pid = 'new-27196382-014c-463f-89ed-7e1524a74679';
    $pane->panel = 'minipanel_three_33_second';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Social Connect',
      'title' => '',
      'body' => '<div class="social-head">
                        <div class="social-connect"><p>Connect with us:</p><ul><li><a href="https://twitter.com/StreamRiot">@StreamRiot</a></li><li><a href="https://twitter.com/StreamRiot">#StreamRiot</a></li></ul></div>
                        <ul class="clearfix">
                            <li><a title="twitter" class="icon-twitter" href="#">twitter</a></li>
                            <li><a title="facebook" class="icon-facebook" href="#">Facebook</a></li>
                            <li><a title="" class="icon-other" href="#">other</a></li>
                            <li><a title="pin it" class="icon-pin" href="#">pin</a></li>
                            <li><a title="Email" class="icon-email" href="#">email</a></li>
                        </ul>
                    </div>',
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
    $pane->uuid = '27196382-014c-463f-89ed-7e1524a74679';
    $display->content['new-27196382-014c-463f-89ed-7e1524a74679'] = $pane;
    $display->panels['minipanel_three_33_second'][0] = 'new-27196382-014c-463f-89ed-7e1524a74679';
    $pane = new stdClass();
    $pane->pid = 'new-cee85487-dc3c-41d3-9dcb-cc17a472a5e5';
    $pane->panel = 'minipanel_three_33_third';
    $pane->type = 'block';
    $pane->subtype = 'user-login';
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
    $pane->uuid = 'cee85487-dc3c-41d3-9dcb-cc17a472a5e5';
    $display->content['new-cee85487-dc3c-41d3-9dcb-cc17a472a5e5'] = $pane;
    $display->panels['minipanel_three_33_third'][0] = 'new-cee85487-dc3c-41d3-9dcb-cc17a472a5e5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['header_mega_menu'] = $mini;

  return $export;
}
