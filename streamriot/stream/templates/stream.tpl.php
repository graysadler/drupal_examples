<div class="stream-wrapper" data-id="<?php print $content['stream_id']; ?>" data-provider="<?php print $content['provider']; ?>" data-channel="<?php print $content['channel'];?>" data-pos="<?php print $content['position']; ?>">
	<div class="image-wrapper">
		<div class="image"><?php print render($content['image']); ?></div>
		<div class="image-overlay"></div>		
	</div>
	<div class="channel"><?php print render($content['channel']); ?></div>
	<div class="viewers"><?php print render($content['viewers']); ?></div>
	<div class="category"><?php print render($content['category']); ?></div>
	<div class="stream-actions">
  	<ul class="add-to-player">
  		<li class="item add-q" data-pos="q">Q</li>
  		<li class="item add-1" data-pos="1">1</li>
  		<li class="item add-2" data-pos="2">2</li>
  		<li class="item add-3" data-pos="3">3</li>
  		<li class="item add-4" data-pos="4">4</li>
  		<li class="item add-5" data-pos="5">5</li>
    </ul>
  	<?php print $content['favorite']; ?>
  	<div class="remove"></div>		
	</div>
</div>