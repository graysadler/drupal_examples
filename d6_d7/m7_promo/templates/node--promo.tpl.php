<?php 
  // We hide the comments and links
  hide($content['comments']);
  hide($content['links']);
  hide($content['field_promo_banner_body']);
  hide($content['field_promo_image']);
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php print render($title_suffix); ?>

  <div class="content"<?php print $content_attributes; ?>>
    <div class="promo-image" <?php print (!empty($image)) ? 'style="background-image:url(' . $image . ');"' : '' ?>></div>
    <div class="promo-content">
      <h2 class="headline"><?php print render($content['field_promo_headline']); ?></h2>  
      <h2 class="sub-headline"><?php print render($content['field_promo_sub_head']); ?></h2>  
      <p class="body"><?php print render($content['body']); ?></p>  
      <?php print render($content); ?>
    </div>  
  </div>
</div>
