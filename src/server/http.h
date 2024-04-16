#ifndef __ELLEFSEN_WEBSERVER__
#define __ELLEFSEN_WEBSERVER__


typedef struct HttpRequest{
  char* httpMethod;
  char* url;
  char* httpVersion;
  char** headers;
  char* requestBody;
  int headersCount;
} HttpRequest;

typedef struct HttpResponse{
  int statuscode;
  char** headers;
  char* body;
  int headersCount;
} HttpResponse;

// Request Handler alias for HttpRequest function pointers. Used to setup functions that should be called at specific routes
typedef HttpResponse (*RequestHandler)(const HttpRequest*);

typedef struct Route{
  char* path;
  RequestHandler handler;
} Route;


#endif
