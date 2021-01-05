<div id="player-wrapper" class="<?php print $class; ?>">
  <?php if($background): ?><div class="player-background" style="background-image:url(<?php print $background; ?>);"></div><?php endif; ?>  
  <?php print render($player_menu); ?>
  <div id="riot-player-wrapper">
    <div id="player-messages"><div class="message-img"></div><div class="message"></div></div>
    <?php print $riot; ?>
  </div>
  <?php print render($social_menu); ?>
</div>

