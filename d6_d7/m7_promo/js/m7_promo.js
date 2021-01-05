(function ($) {
  Drupal.m7_promo_modalClose = function(bannerId) {
    //$('#' + bannerId).prependTo('#sticky-header').show();    
  }
  
  Drupal.behaviors.m7_promo_form = {
    attach: function (context, settings) {
      
      $('.field-name-field-promo-cta-type').once('promo', function() {        
        var parent = $(this).closest('.cta-item');
        var label = $(parent).find('.link-field-title label');
        var labelText = $(label).text();

        $(this).find('select').change(function(e) {
          var val = $(this).val();
          
          if (val == 'phone') {
            $(parent).addClass('cta-phone');
          } else {
            $(parent).removeClass('cta-phone');
          }
        });
      });
      
      /*
      $('select[name="field_promo_template[und]"]').change(function(){
        var value = $(this).val();
        var cropVal = false;
        
        switch (value) {
          case 'image-full':
            cropVal = 'promo_full';
            break;
          case 'split':
            cropVal = 'promo_split';            
            break;            
          case 'portrait':
            cropVal = 'promo_portrait';            
            break;
          default:
        }
        
        if (cropVal) {
          $('select[name="field_promo_image[und][0][manualcrop_style]"]').val(cropVal).trigger('change');
        }
      });
      */
    }
  };
})(jQuery);