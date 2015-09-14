
var useImages = false;
var IE = (navigator.appName=="Microsoft Internet Explorer");

// Called when a Rich Media IFRAME completes its loading
function adsRMIFOnL(win, doc)
{
    var adFrame = win.frameElement;
    var div = adFrame.parentNode;

    if (div.childNodes.length == 1)
    {
        var adSpan = doc.getElementById("adSpan");
        var adDiv = doc.getElementById("adDiv");

        if (adSpan)
        {
	    var w = adSpan.offsetWidth;

	    if (IE)
	        var h = adSpan.offsetHeight;
	    else
		var h = adDiv.offsetHeight;

	    adFrame.style.width = w + "px";
	    adFrame.style.height = h + "px";
        }
    }
}


// Returns the URL of for a given frame. This assumes the IFRAME is in a
// div and the div has the adURL property set to the URL that the 
// IFRAME should use to load an ad in a <SCRIPT> tag. This is used by the
// addoc.htm file.
function adsGetAdURL(win)
{
    var adFrame = win.frameElement;
    var div = adFrame.parentNode;

    return div.adURL;
}

// Called by the Frame source when an ad frame is created. Loads the
// ad reference document into the IFrame
function LoadFrame(win, doc)
{
    var div = win.frameElement.parentNode;
    var content;

//    content = "<html><body onload='if (parent.adsRMIFOnL) parent.adsRMIFOnL(window, document);'>";
    content = "<html><body onload='if (parent.adsRMIFOnL) setTimeout(\"parent.adsRMIFOnL(window, document)\", 100);'>";

    content += "<scr"+"ipt>inFIF=true;</scr"+"ipt>";
    content += "<scr"+"ipt>inDapIF=true;</scr"+"ipt>";

    content += "<scr" + "ipt type='text/javascript'> function closeDocument() { if(event.srcElement.readyState && event.srcElement.readyState == 'complete') { window.setTimeout(\'document.close()\', 100); } }</scr" + "ipt>";

    content += "<scr"+"ipt id='adscr' type='text/javascript' src='"+div.adURL+"'";
    content += " onreadystatechange='closeDocument();'";
    content += "></scr"+"ipt>";

    content += "</body></html>";

    // Write the content string to the document
    doc.write(content);
}

function RemoveChildren(obj)
{
    var iframe = null;

    while (obj.childNodes.length > 0) 
    {
        var child = obj.childNodes[0];

	var id = child.id;

	if (id == "adFrame")
	{
	    iframe = child;
	    iframe.src = "about:blank";
	}

	if (id)
	    child.id = "";

        if (child.childNodes.length > 0)
	    RemoveChildren(child);

        obj.removeChild(child);
    }
}

// Clear the contents of the Ad DIV
function ClearDiv()
{
    RemoveChildren(this);
}

// Clear the ad DIV, add the IFRAME, and make the ad call
function LoadAd()
{
    // First clear any existing content in the DIV
    this.ClearAd();

    // If there is no ad URL, just return
    if (!this.adURL || this.adURL == "")
	return;

    if (useImages)
    {
        var a = document.createElement('a');

	a.href = "myclick.htm";

        var img = document.createElement('img');

	this.appendChild(a);
	a.appendChild(img);

	if (this.w > 0)
	    img.width = this.w;

	if (this.h > 0)
	    img.height = this.h;

	img.src = "aol.jpg";
    }
    else
    {
        // Create the ad call IFRAME
        var iframe = document.createElement('iframe');

        // Set the properties of the iframe
        iframe.id = "adFrame";
        iframe.style.height = 0;
        iframe.style.width = 0;
        iframe.marginWidth = 0;
        iframe.marginHeight = 0;
        iframe.frameBorder = 0;
        iframe.scrolling = "no";
        iframe.width = 0;
        iframe.height = 0;

        // Put the new IFRAME into the ad div
        this.appendChild(iframe);

        // If there is a page based URL, use it instead of doc.writing into the
        // IFRAME
        if (this.adPage)
    	    iframe.src = this.adPage;
        else
        {
	    // Load the frame's content (make the ad call)
	    iframe.src = "javascript:void(parent.LoadFrame(this, document))";
        }
    }
}

var adDivs;

if (!adDivs)
    adDivs = new Array();

function CreateAdDiv(w, h, adURL, adPage)
{
    var did = "adDiv"+adDivs.length;

    // Create the ad call IFRAME
    var div = document.createElement('div');

    // Set the DIV ID
    div.id = did;

    // Setup the DIV attributes
    _SetupAdDiv(div, w, h, adURL, adPage);

    return div;
}

function SetupAdDiv(w, h, adURL, adPage)
{
    var did = "adDiv"+adDivs.length;

    // Doc write the new DIV
    document.write("<div id='" + did + "'></div>");

    // Get the new DIV object
    var div = document.getElementById(did);

    // Setup the DIV attributes
    _SetupAdDiv(div, w, h, adURL, adPage);

    return div;
}


function _SetupAdDiv(div, w, h, adURL, adPage)
{
    // Setup the onload handler
    div.RMIFOnLoad = adsRMIFOnL;
    div.LoadAd = LoadAd;
    div.ClearAd = ClearDiv;
    div.w = w;
    div.h = h;
    div.adURL = adURL;
    div.adPage = adPage;

    // Add the div to the array
    adDivs[adDivs.length] = div;
}

function LoadAds()
{
    // Clear the ads
    ClearAds();

    // Schedule the routine to actually load the ads
    setTimeout('DoLoadAds();', 100);
}

function DoLoadAds()
{
    for (i=0; i<adDivs.length; i++)
	adDivs[i].LoadAd();
}

function ClearAds()
{
    for (i=0; i<adDivs.length; i++)
	adDivs[i].ClearAd();
}


function HideAds()
{
    for (i=0; i<adDivs.length; i++)
	adDivs[i].style.display = "none";
}


function ShowAds()
{
    for (i=0; i<adDivs.length; i++)
	adDivs[i].style.display = "block";
}