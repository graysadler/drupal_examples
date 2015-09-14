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