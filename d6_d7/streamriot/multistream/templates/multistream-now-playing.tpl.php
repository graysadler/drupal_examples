<?php //print $save_queue; ?>
<span class="">In Player #</span>
<div id="now-playing">
  <?php foreach($now_playing as $stream): ?>
  	<?php print render($stream); ?>
  <?php endforeach;?>
</div>
<div id="queue">
  <h2 class="pane-title title">Queue</h2>
  <span class="">Add to Player #</span>
  <?php foreach($queue as $stream): ?>
  	<?php print render($stream); ?>
  <?php endforeach;?>
</div>