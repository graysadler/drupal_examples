<?php 
  // We hide the comments and links
  hide($content['comments']);
  hide($content['links']);
?>
<div id="promo-banner" class=""<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php print render($title_suffix); ?>

  <div class="content container"<?php print $content_attributes; ?>>
    <div class="promo-body"><?php print render($content['field_promo_banner_body']); ?></div>
    <div class="promo-cta"><?php print render($content['field_promo_cta']); ?></div>
  </div>
</div>
