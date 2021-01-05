function LoadStreams() {
  loadPlayers();
}

  
function loadPlayers() {  
  var swf = getFlashMovie("riot-player");
  var obj = Drupal.settings.multistream;
  swf.loadPlayers(obj);   
}

function getFlashMovie(movieName) {
      var isIE = navigator.appName.indexOf("Microsoft") != -1;
      return (isIE) ? window[movieName] : document[movieName];
}

function updatePlayerStreams() {
  try {
    var swf = getFlashMovie("riot-player");
    var obj = Drupal.settings.multistream;
    swf.updateStreams(obj);
  } catch(e) {
    console.log('error in updatePlayerStreams() ' + e);
  }
}

function updatePlayerStream(playerNum, stream_id, shift) {
  if(!playerNum || !stream_id) {
    return;
  }
  
  if(!shift) {
    shift = false;
  }
  
  try {
    var swf = getFlashMovie("riot-player");
    swf.updateStream(playerNum, stream_id, shift, false);
    //swf.updateStream(1, 1);
  } catch(e) {
    console.log('error in updatePlayerStream() ' + e);
  }
}

function swapPlayers(thisNum, thatNum) {
  if(!thisNum || !thatNum) {
    return;
  }
  
  try {
    var swf = getFlashMovie("riot-player");
    swf.swapPlayers(thisNum, thatNum, false);
    //swf.updateStream(1, 1);
  } catch(e) {
    console.log('error in swapPlayers() ' + e);
  }
}

function removeStream(playerNum) {
  try {
    if(playerNum == 'q') {
      return;
    }
    var swf = getFlashMovie("riot-player");
    swf.removeStream(playerNum, true);
  } catch(e) {
    console.log('error in removeStream() ' + e);

  }
}

(function ($) {
  $(window).bind('beforeunload', function(){
    return 'Are you sure?';
  });
  
  Drupal.behaviors.SRPlayer = {
      attach: function(context, settings) {
        $('div#riot-player-wrapper:not(.processed)').each(function() {
          $(this).addClass('processed');
          var flashvars = {};
          var params = {allowScriptAccess: "always", allowFullScreen: "true", allowNetworking: "all", wmode: "transparent"};
          var attributes = {};
          try {
            swfobject.embedSWF(Drupal.settings.multistream.playerSwf, "riot-player", '100%', '100%', "9.0.0", "expressInstall.swf", flashvars, params, attributes);
            $('#riot-player').show();
          } catch(e) {
            console.log(e);
          }
        });
      }
  }  
  

})(jQuery);