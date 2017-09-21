(function ($) {
    'use strict';

        Drupal.behaviors.iin_panels_extras = {
            attach: function (context, settings) {
                var expanderText = $('.pane-atom-expanding-list .field-name-field-list-item-title');
                var expandingContent = $('.pane-atom-expanding-list .field-name-field-list-item-title + div');

                if (expanderText && expandingContent && expandingContent.collapse) {
                    // Initialy we collapse all questions
                    expandingContent.collapse('hide');

                    // We create the area that holds the expandable list icon
                    var expanderIcon = expanderText.parent().prepend('<span class="expand-icon"></span>');
                    expanderIcon = expanderIcon.children(0);

                    // We need to do this so that the initial collapse works properly
                    expandingContent.css('height', '0px');
                    expanderText.prev().addClass('closed');

                    expanderIcon.click(function() {
                        $(this).next().next().collapse('toggle');
                    });

                    expanderText.click(function () {
                        $(this).next().collapse('toggle');
                    });

                    expandingContent.on('hide.bs.collapse', function () {
                        $(this).prev().prev().addClass('closed');
                    });
                    expandingContent.on('show.bs.collapse', function () {
                        $(this).prev().prev().removeClass('closed');
                    });
                }
                
                // Randomly show three blog post in curation
                $('#blog-curated-post').once('random-display', function(){
                  var n = $(this).find('.blog-curated-post').length;        
                  if (n == 0) {
                    //return;
                  }        
                  var posts = $('#blog-curated-post .blog-curated-post');
                  posts = shuffle(posts);
                  $(this).html(posts);
                  
                  //$(this).find('.blog-curated-post').each(function())
                  //n = n - 1; //eq starts at 0
                  //var r = Math.floor(Math.random()*(n-0+1)+0);
                  var max = 3;
                  for (var i = 0; i < max; i++) {
                    //$(this).find('.blog-curated-post').eq(i).css('display', 'block');
                  }
                });                 
            }
        };

})(jQuery);

/**
 * Shuffles array in place.
 * @param {Array} a items The array containing the items.
 */
function shuffle(a) {
    var j, x, i;
    for (i = a.length; i; i -= 1) {
        j = Math.floor(Math.random() * i);
        x = a[i - 1];
        a[i - 1] = a[j];
        a[j] = x;
    }
    
    return a;
}
