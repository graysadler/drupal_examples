<?php
//kpr(get_defined_vars());
//kpr($theme_hook_suggestions);
//template naming
//page--[CONTENT TYPE].tpl.php
?>
<?php if (theme_get_setting('mothership_poorthemers_helper')) { ?>
    <!--page.tpl.php-->
<?php } ?>

<?php print $mothership_poorthemers_helper; ?>

<?php if ($page['user_bar']): ?>
    <div id="user-wrapper" class="fullwidth">
        <div class="container">
            <div role="user">
                <div class="user-region">
                    <?php print render($page['user_bar']); ?>
                </div>
            </div>
        </div><!--/.container-->
    </div><!--/#user-wrapper-->
<?php endif; ?>

<?php if ($site_name OR $site_slogan OR $logo OR $page['header']): ?>
    <div id="header-wrapper" class="fullwidth nofix">
        <div class="">
            <header role="banner" class="row clearfix">
                <div class="siteinfo">
                    <?php if ($logo): ?>
                        <div class="logo">
                            <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home">
                                <img src="<?php print $logo; ?>" class="logo-img" alt="<?php print t('Home'); ?>" />
                            </a>
                        </div>
                    <?php endif; ?>

                </div>
                <?php print render($title_prefix); ?>
                <?php if ($title): ?>
                    <h1 class="page-title"><?php print $title; ?></h1>
                <?php endif; ?>
                <?php print render($title_suffix); ?>
                
                <?php if ($page['header']): ?>
                    <div class="header-region">
                        <?php print render($page['header']); ?>
                    </div>
                <?php endif; ?>

            </header>
        </div><!--/.container-->
    </div><!--/#header-wrapper-->
<?php endif; ?>

<?php if ($page['highlighted'] OR $messages): ?>
    <div id="highlighted-wrapper" class="fullwidth">
        <div class="container">
            <?php print render($page['highlighted']); ?>
            <div class="drupal-messages">
                <?php //print $messages; ?>
            </div>
        </div><!--/.container-->
    </div><!--/#highlighted-wrapper-->
<?php endif; ?>

<div id="content-wrapper" class="fullwidth">
  <div role="main" id="main-content">

      <?php if ($action_links): ?>
          <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>

      <?php if (isset($tabs['#primary'][0]) || isset($tabs['#secondary'][0])): ?>
          <nav class="tabs"><?php print render($tabs); ?></nav>
      <?php endif; ?>

      <?php print render($page['content_pre']); ?>

      <?php print render($page['content']); ?>

      <?php print render($page['content_post']); ?>

  </div><!--/main-->
</div><!--/#content-wrapper-->