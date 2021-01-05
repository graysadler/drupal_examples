(function ($) {

  // Add global_filter parameters to outboard social urls
  Drupal.behaviors.sevonePersona = {
      attach: function (context, settings) {
        /*
        $('a.social-icon').once('persona', function(){
          var params = Drupal.settings.sevone.global_filters;
          $(this).attr('addthis:url', function(index, value) {
            return value + '?' + $.param(params);
          });
        });
        */
      }
  }  
  
})(jQuery);  