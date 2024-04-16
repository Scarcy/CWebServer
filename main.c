#include "tpool.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Does not work currently. Not sure why
#ifdef DEBUG_ENABLE
  printf("Debugging is enabled.\n");
#endif

  printf("Hello World!\n");
  printf("Hello!!\n");
  tpool_create(10);
  return 0;
}
