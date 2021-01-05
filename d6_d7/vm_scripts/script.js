/* global Drupal */
(function ($) {
  Drupal.behaviors.findPartner = {
      attach: function (context) {
        $('.find-a-partner .field-name-field-cta-link a').once('search', function(){
          $(this).click(function(e) {            
            e.preventDefault();
            e.stopPropagation();
            
            $(this).closest('.find-a-partner').find('form').submit();
            
            return false;
          });
        });
      }
  }
  
  // Open pdf documents and ext links in a new tab
  Drupal.behaviors.docsNewTab = {
      attach: function (context) {
        $('a[href$=".pdf"]').once('newtab', function(){
          $(this).attr('target', '_blank');
        });
        
        $('a[href]').once('click', function(e) {
          $(this).click(function(e) {
            var url = $(this).attr('href');
            var urlParse = Drupal.parseStringUrl(url);
            
            if(urlParse.host == 'www.addthis.com') {
              return;
            }
            if (urlParse.host !== location.host) {
              // external
              
              e.preventDefault();              
              window.open(urlParse.href, '_blank');
              return false;
            }
          });            
        });
      }
  }
  
  // Open video in colorbox when preview is clicked
  Drupal.behaviors.videoPopup = {
      attach: function (context) {
        /*
        $('.node-resource-type-video').once('popup', function(){
          $(this).click(function(e) {
            e.preventDefault();
            e.stopPropagation();
            var $video = $(this).find('.file-video');
            $.colorbox({href:$video, inline:true, innerWidth:640, innerHeight:390});
            return false;
          });
        });
        
        $('.node-resource-type-video a').once('popup', function(){
          $(this).click(function(e) {
            e.preventDefault();
            e.stopPropagation();
            var $video = $(this).closest('.node-resource-type-video').find('.file-video');
            $.colorbox({href:$video, inline:true, innerWidth:640, innerHeight:390});
            return false;
          });
        });  
        */
        
        $('.field-name-field-video-thumbnail').once('popup', function(){
          $(this).click(function(e) {
            e.preventDefault();
            e.stopPropagation();
            var video = $(this).find('.video-embed');
            var fid = $(video).attr('data-fid');
            $.colorbox({href:'/video-embed/'+fid, inline:false, width:'75%', onComplete:
              function(){
                $.colorbox.resize();
              }
            }).resize();
            
            //$.colorbox({href:$video, inline:true, width:'75%'});
            return false;
          });
        });          
      }
  }  
  
  Drupal.behaviors.owlCarousel = {
      attach: function (context) {
        $('.owl .view-content, .owl .field-items, .owl .field-type-field-collection').once(function(){
          var count = $(this).children().length;
          var showCenter = false;
          var autoPlay = false;
          
          $(this).closest('.owl').parent(':first').addClass('owled');
          if( $(this).closest('.owl').hasClass('auto')) {
            autoPlay = true;
          }
          
          // ugly but it'll do
          if ($(this).find('.node-isotope').length || $(this).find('.entity-award').length || $(this).find('.entity-stat').length) {
            $(this).addClass('owl-shadow');
            
            if(count <= 3) {
              showCenter = true;
            }                         
          }
          
          $(this).addClass('owl-carousel').owlCarousel({
            loop:true,
            margin:19,
            responsiveClass:true,
            //center:true,
            stagePadding:15,
            //autoWidth:true,
            navText:[,],
            //center:true,
            autoplay:autoPlay,
            responsive:{
                0:{
                    items:1,
                    nav:true,
                    loop:true,
                    center:showCenter
                },
                800:{
                    items:2,
                    nav:true,
                    loop:true,
                },
                1120:{
                    items:3,
                    nav:true,
                    loop:true,
                    center:showCenter
                    
                }
            }
          });
          
          $(this).trigger('refresh.owl.carousel');
          Drupal.behaviors.varimatrixClickableItem.attach();
        });
      }
  }
  
  /**
   * make node divs clickable like links
   */
  Drupal.parseStringUrl = function(url) {
    var a = document.createElement('a');
    a.href = url;
    return a;
  };
  Drupal.behaviors.varimatrixClickableItem = {
    attach: function (context) {
      $('[data-url]', context).each(function() {
        var url = $(this).data('url');
        var urlParse = Drupal.parseStringUrl(url);
        var mobileToggle = $('.mobile-menu-toggle', context);
        var isMobile = mobileToggle.is(':visible');
        
        $(this).addClass('item-clickable');

        // Hover event
        if (isMobile == false) {
          $(this).hover(
            function() {
              $( this ).addClass( "hovered" );
            }, function() {
              $(this).removeClass( "hovered" );
            }
          );
        }
      
        // Disable Links within block
        $(this).find('a').on('click', function(e) {
          if ($(this).attr('href') === urlParse.href) {
            //e.preventDefault();
            //e.stopPropagation();
            //return false;
          }
        });

        // Click event
        $(this).on('click', function(e) {
          var target = $(e.target);
          if (target.hasClass('at4-icon') || target.hasClass('node-resource-type-video')) {
            e.preventDefault();
            e.stopPropagation();
            return false;
          }
          
          // if on mobile, don't continue if haven't triggered hover yet
          if (isMobile) {
            if ($(this).hasClass('hovered')) {
              $(this).removeClass('hovered');
            } else {
              $('.hovered').removeClass('hovered');
              $(this).addClass('hovered');
              e.preventDefault();
              e.stopPropagation();
              return false;                            
            }
          }
          if (urlParse.host !== location.host || url.substr(url.length - 4) == '.pdf') {
            // external
            window.open(urlParse.href, '_blank');
          }
          else {
            // internal
            window.location = url;
          }
          e.preventDefault();
        });
      });
    }
  };

  /**
   * Allows non-link items to have hover class
   */
  Drupal.behaviors.varimatrixHoverableItem = {
    attach: function (context) {
      $('[data-hover]', context).each(function() {
        $(this).addClass('item-hoverable');

        if ($(this).data('url')) {
          return;
        }

        // Hover event
        $(this).hover(
          function() {
            $( this ).addClass( "hovered" );
          }, function() {
            $(this).removeClass( "hovered" );
          }
        );
      });
    }
  };

  /**
   * Enables drop-down language selector.
   */
  Drupal.behaviors.verimatrixLanguageSelector = {
    attach: function (context) {
      var languageSelector = $('.language-switcher-locale-url', context).clone();
      var languageLink = $('.block-menu-menu-utility-menu a.language:first, .pane-menu-utility-menu a.language:first', context);
      languageSelector.addClass('menu');
      languageLink.after(languageSelector);

      // Bind click event on utility nav language link.
      languageLink.click(function(e) {
        e.preventDefault();
        languageSelector.toggleClass('open');
      });
    }
  }
  
  /**
   * Collapse functionality.
   */
  Drupal.behaviors.verimatrixCollapse = {
    attach: function (context) {
      if ($('[data-collapse]', context).size() > 0) {
        $('[data-collapse]', context).each(function() {
          var collapseToggle = $(this);
          var collapseTarget = $(this).data('collapse');
          
          if ($(collapseTarget, context).size() > 0) {
            collapseTarget = $(collapseTarget, context);
            
            collapseToggle.click(function(e) {
              e.preventDefault();
              collapseToggle.toggleClass('target-open');
              collapseTarget.toggleClass('open');
            });
          }
          else {
            collapseToggle.hide();
          }
        });
      }
    }
  }   

  /**
   * Fake hover functionality.
   */
  Drupal.behaviors.verimatrixFakeHover = {
    attach: function (context) {
      $('ul.menu li', context).hover(
        function() {
          $( this ).addClass( "li-hover" );
        }, function() {
          $(this).removeClass( "li-hover" );
        }        
      );
    }
  }
  
  /**
   * Fake hover functionality.
   */
  Drupal.behaviors.verimatrixMenuToggles = {
    attach: function (context) {
      $('<i class="menu-toggle"></i>').appendTo($('.menu-has-children', context));
      
      $('.menu-toggle').click(function(e) {
        e.preventDefault();
        ul = $(this).parents('.li-menu-has-children').find('ul');
        if (ul.size() > 0) {
          $(this).toggleClass('target-open');
          ul.toggleClass('open');
        }
        return;
      });
    }
  }  
  
  /**
   * Mega / Dropdown menu helpers
   */
  Drupal.behaviors.verimatrixMegaMenu = {
    attach: function (context) {
      // Alter height of menu menus
      Drupal.verimatrixMegaMenuSetHeight(context);
      $(window).resize(function() {
        Drupal.verimatrixMegaMenuSetHeight(context);
      });
    }
  };
  
  /**
   * Mega menu height & fixed header helper
   *
   * If mega menu is longer than screen with fixed
   * header menu dropdown cannot be scrolled
   */
  Drupal.verimatrixMegaMenuSetHeight = function(context) {
    var megaMenus = $('.menu-minipanel-panel .panel-display', context);
    var navBar = $('#header-wrapper', context);
    var screenHeight = $(window).height();
    var mobileToggle = $('.mobile-menu-toggle', context);
    
    if (megaMenus.size() > 0) {
      if (mobileToggle.is(':visible')) {
        console.log('mobile');
        $(megaMenus).each(function() {
          $(this).height('auto');
          $(this).removeClass('mega-menu-scrollable');
        });
        
        return;
      }      
      
      if (navBar.size() > 0) {
        screenHeight = screenHeight - navBar.innerHeight();
      }
      if ($('body', context).hasClass('admin-menu')) {
        screenHeight = screenHeight - 32;
      }
  
      $(megaMenus).each(function() {
        if ($(this).innerHeight() >= screenHeight - 150) {
          $(this).height(screenHeight - 150);
          $(this).addClass('mega-menu-scrollable');
        }
        else {
          $(this).height('auto');
          $(this).removeClass('mega-menu-scrollable');
        }
      });
    }
  };  
  
})(jQuery);
