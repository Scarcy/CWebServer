#ifndef __ELLEFSEN_SERVER__
#define __ELLEFSEN_SERVER__
#include <netinet/in.h>

typedef struct EllefsenServer {
  struct sockaddr_in serverAddress;

} EllefsenServer;

void init(size_t port);

#endif
