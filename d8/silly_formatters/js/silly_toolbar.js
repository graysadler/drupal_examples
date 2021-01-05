(function ($, Drupal) {
  "use strict";

  // Apply toolbar behavior to applicable field formatters
  Drupal.behaviors.sillyToolbar = {
    attach: function (context, settings) {
		$('.silly-tooltip').qtip({
			content: 'This is a silly Tooltip!'	
	  	});
    }
  };

}(jQuery, Drupal));