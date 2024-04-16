#include "debug.h"
#include "server.h"
#include "tpool.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
  // Does not work currently. Not sure why

  DEBUG_PRINT("Debug Enabled..\n");
  printf("Hello World!\n");
  printf("Hello!!\n");
  tpool_create(10);
  init(80);
  return 0;
}
