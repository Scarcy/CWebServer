#include "tpool.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Hello World!\n");
  printf("Hello!!\n");
  tpool_t *threadpool;
  tpool_create(10);
  return 0;
}
