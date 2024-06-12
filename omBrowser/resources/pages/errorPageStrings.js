var errorTitleUnknown = "An Unknown Error has occurred";
var errorCodeUnknown = "Unknown Error";
var errorDescriptionUnknown = "Winamp has received an unknown error from the Online Service.";
var errorTitle400 = "Bad Request";
var errorCode400 = "HTTP 400 - Bad Request";
var errorDescription400 = "The request to the Online Service has not been properly formatted, there is likely a syntax error in the URL or elsewhere in the request.  This is most likely due to an error in the Online Services code.";
var errorTitle401 = "Request is Unauthorized";
var errorCode401 = "HTTP 401 - Unauthorized";
var errorDescription401 = "The Online Service has made a request that requires HTTP authentication, and the request was not authorized by the server.";
var errorTitle402 = "Payment Required";
var errorCode402 = "HTTP 402 - Payment Required";
var errorDescription402 = "The Online Service submitted a request that was not authorized, because payment is required.";
var errorTitle403 = "Access has been denied";
var errorCode403 = "HTTP 403 - Forbidden";
var errorDescription403 = "Winamp was able to connect to the server for this Online Service, however the service has returned an error indicating that you do not have access to the page.  This may be caused by a problem with the webserver configuration or other problem with the Online Service.";
var errorTitle404 = "The page cannot be found";
var errorCode404 = "HTTP 404 - File Not Found";
var errorDescription404 = "Winamp was able to connect to the server for this Online Service, however the service has returned an error indicating that the page requested can not be found.  This may be caused by a broken link, or other problem with the Online Service.";
var errorTitle405 = "The requested method is not allowed";
var errorCode405 = "HTTP 405 - Method Not Allowed";
var errorDescription405 = "The request method specified by the online service is not allowed by the server, this is likely due to a server misconfiguration, or an attempt by the online service to use a webservice in a way it does not allow";
var errorTitle406 = "The response is not acceptable";
var errorCode406 = "HTTP 406 - Not Acceptable";
var errorDescription406 = "The Online Service has made a request to a webserver, and the webserver is not able to respond in a format that the request has stated to be acceptable.";
var errorTitle407 = "Proxy authentication is required";
var errorCode407 = "HTTP 407 - Proxy Authentication Required";
var errorDescription407 = "The Online Service has made a request to a proxy server, and the proxy server requires that the request be authenticated.";
var errorTitle408 = "The request had timed out";
var errorCode408 = "HTTP 408 - Request Timeout";
var errorDescription408 = "Winamp did not send a request issued by the Online Service within the length of time that the Online Service would wait for the request.";
var errorTitle409 = "A conflict has occurred";
var errorCode409 = "HTTP 409 - Conflict";
var errorDescription409 = "The Online Service has made a request to a server where a conflicting request has been made.";
var errorTitle410 = "The requested page is gone";
var errorCode410 = "HTTP 410 - Gone";
var errorDescription410 = "The page requested by the Online Service is gone.  Permanently.  No forwarding address is known";
var errorTitle411 = "Request length must be specified";
var errorCode411 = "HTTP 411 - Length Required";
var errorDescription411 = "The Online Service has made a request to a server that requires that the request specify the length of the request, and the Online Service has not specified the length.";
var errorTitle413 = "The request is too large";
var errorCode413 = "HTTP 413 - Request Entity Too Large";
var errorDescription413 = "The Online Service has submitted a request to a webserver that has been refused because the request is too large.";
var errorTitle414 = "The request is too large";
var errorCode414 = "HTTP 414 - Request-URI Too Long";
var errorDescription414 = "The Online Service has made a request to a server that has been refused because the request URI is too long, this is likely due to an problem with the Online Service adding too many query parameters.";
var errorTitle415 = "The media type is not supported";
var errorCode415 = "HTTP 415 - Unsupported Media Type";
var errorDescription415 = "The Online Service has made a request to a resource on a server that is being refused because the request is not in a format that is supported for the request method being used.";
var errorTitle500 = "An internal server error has occured";
var errorCode500 = "HTTP 500 - Internal Server Error";
var errorDescription500 = "The Online Service has made a request to a server that has encountered an error preventing the completion of the response.";
var errorTitle501 = "Method not implemented";
var errorCode501 = "HTTP 501 - Not Implemented";
var errorDescription501 = "The Online Service has made a request to a server using a request method that the server does not support.";
var errorTitle502 = "Bad response from proxy";
var errorCode502 = "HTTP 502 - Bad Gateway";
var errorDescription502 = "The Online Service has made a request to a server acting as a proxy or a gateway.  The server has not received a valid response.";
var errorTitle503 = "The service is currently unavailable";
var errorCode503 = "HTTP 503 - Service Unavailable";
var errorDescription503 = "The Online Service has made a request to a server that is currently unable to service the request.  This may be temporary due to the server current load.";
var errorTitle504 = "The proxy has timed out.";
var errorCode504 = "HTTP 504 - Gateway Timeout";
var errorDescription504 = "The Online Service has made a request to a server acting as a proxy, and this server has not received a timely response.";
var errorTitle505 = "The HTTP version is not supported";
var errorCode505 = "HTTP 505 - HTTP Version Not Supported";
var errorDescription505 = "Winamp has made a request to the Online Service in an HTTP version not supported by the Online Service.  This is either a server configuration problem with the Online Service, or you may need to change your browser's HTTP protocol settings.";

var errorDnsDescription = "The request for the Online Service has returned a resource not found error from your browser, please ensure that you are connected to the Internet.";

var errorTitle800c0005 = "The server or proxy was not found.";
var errorCode800c0005 = "Resource Not Found";
var errorDescription800c0005 = "The request for the Online Service has returned a resource not found error from your browser, please ensure that you are connected to the Internet.";
var errorTitle800c000f = "Unable to load data from the server.";
var errorCode800c000f = "Cannot Load Data";
var errorDescription800c000f = errorDnsDescription;
var errorTitle800c0002 = "The URL could not be parsed.";
var errorCode800c0002 = "Invalid URL";
var errorDescription800c0002 = errorDnsDescription;
var errorTitle800c0003 = "No Internet session was established.";
var errorCode800c0003 = "No Session Found";
var errorDescription800c0003 = errorDnsDescription;
var errorTitle800c0004 = "The attempt to connect to the Internet has failed.";
var errorCode800c0004 = "Unable To Connect";
var errorDescription800c0004 = errorDnsDescription;
var errorTitle800c0006 = "Requested object was not found.";
var errorCode800c0006 = "Object Not Found";
var errorDescription800c0006 = errorDnsDescription;
var errorTitle800c0007 = "Requested data is not available.";
var errorCode800c0007 = "Data Not Available";
var errorDescription800c0007 = errorDnsDescription;
var errorTitle800c0008 = "The download has failed (the connection was interrupted).";
var errorCode800c0008 = "Download Failed";
var errorDescription800c0008 = errorDnsDescription;
var errorTitle800c0009 = "Authentication is needed to access the object.";
var errorCode800c0009 = "Authentication Required";
var errorDescription800c0009 = errorDnsDescription;
var errorTitle800c000a = "Required media not available or valid.";
var errorCode800c000a = "No Valid Media";
var errorDescription800c000a = errorDnsDescription;
var errorTitle800c000b = "The Internet connection has timed out.";
var errorCode800c000b = "Connection Timeout";
var errorDescription800c000b = errorDnsDescription;
var errorTitle800c000c = "Request is invalid.";
var errorCode800c000c = "Invalid Request";
var errorDescription800c000c = errorDnsDescription;
var errorTitle800c000d = "Protocol is not recognized.";
var errorCode800c000d = "Unknown Protocol";
var errorDescription800c000d = errorDnsDescription;
var errorTitle800c000e = "Navigation request has encountered a security issue.";
var errorCode800c000e = "Security Problem";
var errorDescription800c000e = errorDnsDescription;
var errorTitle800c0010 = "Unable to create an instance of the object.";
var errorCode800c0010 = "Cannot Instantiate Object";
var errorDescription800c0010 = errorDnsDescription;
var errorTitle800c0014 = "Attempt to redirect the navigation failed.";
var errorCode800c0014 = "Redirect Failed";
var errorDescription800c0014 = errorDnsDescription;
var errorTitle800c0015 = "The request is being redirected to a directory.";
var errorCode800c0015 = "Redirect To Directory";
var errorDescription800c0015 = errorDnsDescription;
var errorTitle800c0016 = "The requested resource could not be locked.";
var errorCode800c0016 = "Cannot Lock Request";
var errorDescription800c0016 = errorDnsDescription;
var errorTitle800c0017 = "Reissue request with extended binding.";
var errorCode800c0017 = "Use Extend Binding";
var errorDescription800c0017 = errorDnsDescription;
var errorTitle800c0018 = "Binding was terminated.";
var errorCode800c0018 = "Terminated Bind";
var errorDescription800c0018 = errorDnsDescription;
var errorTitle800c0100 = "The component download was declined by the user.";
var errorCode800c0100 = "Download Declined";
var errorDescription800c0100 = errorDnsDescription;
var errorTitle800c0200 = "Result is dispatched.";
var errorCode800c0200 = "Result Dispatched";
var errorDescription800c0200 = errorDnsDescription;
var errorTitle800c0300 = "Cannot replace a protected System File Protection (SFP) file.";
var errorCode800c0300 = "Cannot Replace SFP File ";
var errorDescription800c0300 = errorDnsDescription;
