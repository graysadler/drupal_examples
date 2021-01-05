<div<?php print drupal_attributes($style_attributes); ?>>
  <?php if ($title): ?>
    <h3 class="pane-title"><?php print $title; ?></h3>
  <?php endif; ?>

  <?php print render($content); ?>
</div>