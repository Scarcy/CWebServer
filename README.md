# Webserver in C

<!--toc:start-->
- [Webserver in C](#webserver-in-c)
  - [Thread Pool](#thread-pool)
    - [Pseudo Steps for Using Thread Pool](#pseudo-steps-for-using-thread-pool)
  - [Routing](#routing)
    - [RoutingManager](#routingmanager)
    - [Route Mapping](#route-mapping)
  - [HTTP](#http)
    - [Easiest first implementation](#easiest-first-implementation)
    - [Harder solutions](#harder-solutions)
  - [Server](#server)
    - [HttpResponses](#httpresponses)
  - [Structs](#structs)
    - [Socket](#socket)
    - [ThreadPool](#threadpool)
    - [ThreadPoolWorker](#threadpoolworker)
    - [RouteHandler Function Pointer type](#routehandler-function-pointer-type)
    - [HttpResponse](#httpresponse)
    - [HttpRequest](#httprequest)
    - [Route](#route)
<!--toc:end-->

## Thread Pool

- [Inspiration Source](https://nachtimwald.com/2019/04/12/thread-pool-in-c/)
- [ ] Initialization Functions
  - [ ] Create
  - [ ] Destroy
- [ ] Task Queue
- [ ] Since we want the threads to check routes after creation:
  - I need to find a way to do that without compromising it's extendability.
  - If I directly check the route from the threadpool library,
  it will be tightly coupled to the server code.

### Pseudo Steps for Using Thread Pool

1. Server receives a request.
2. Server sends that request to the thread pool working Queue.
3. Main Thread Pool function loops infinitely;
Checking if there are threads that are available and not working.
4. If a thread finishes it's work, it picks up the next task in the Queue.
5. Right after a worker thread picks work, it should call the RoutingManager

## Routing

I want to emulate a form of MVC where we setup URL Routes (Like "/home")
and assign a function to that HTTP request.
Example usage of the proposed Routing system:
`registerRoute("/home", homeHandler)`
Where "homeHandler" would be a function pointer.

### RoutingManager

This is a function that will return a function pointer to the ThreadPoolWorkers.
Once a Request is being processed, the ThreadPoolWorker sends the URL of the
request to the RouteManager.
The RouteManager shall then check if there's a match.
If the HTTP Request matches a registered route,
return the function pointer of that Route Struct.

If there's no match found, return a function pointer to a 'notFoundHandler'.

### Route Mapping

Once the Server Receives a HTTP Request it will be sent to a
RouteMapper that checks the URL Path and sees if it matches a
registered route. If there's no match,
return 404 and maybe return a default NotFound page.

## HTTP

There's many ways to implement the HTTP and I'm not sure which one I'll implement.

### Easiest first implementation

The easiest thing would be to make `.http` files.
Create http files, name matching the http route.
Read the contents into char buffers and memcpy into HttpResponseBody.

### Harder solutions

To be able to support dynamic web sites I need to come up with ways to generate HTML.
Could iteratively snprintf strings into a buffer.

## Server

- [ ] Initialise Socket
- [ ] Bind to Port and Accept Connections
- [ ] Add Incoming Requests to the Thread Pool's Task Queue.

### HttpResponses

I will look into creating a simplified and reusable HTTP Response system.
This might be a function that takes a Status Code and the ResponseBody
associated with the Route.
It will then handle the outward communication with the connected clients.

## Structs

- ### Socket

  - Since a different thread will respond to the HttpRequest
  - We will need to pass the request to the functions that will respond to it.

- ### ThreadPool

  - The ThreadPool itself

- ### ThreadPoolWorker

  - Workers circulating in the thread pool

- ### RouteHandler Function Pointer type

  - A `typedef` that creates a function signature.
  - Psuedo version:
    - `typedef HttpResponse (*RequestHandler)(const HttpRequest)`
    - Function signature for a function pointer that:
      - Param: A constant HttpRequest
      - Returns: HttpResponse

- ### HttpResponse

  - A struct containing all relevant information for the response.

- ### HttpRequest

  - Contains the data that the connected client sent to our server.

- ### Route

  - Request URL/Path String.
  - RouteHandler function pointer accociated with the Route.
  - Maybe a HTML file that is returned.
