#ifndef INCLUDE_DEBUG_DEBUG_H_
#define INCLUDE_DEBUG_DEBUG_H_

#include <stdio.h>

#ifdef DEBUG
#define DEBUG_PRINT(fmt, ...)                                                  \
  fprintf(stderr, "Debug: %s:%d:%s(): " fmt, __FILE__, __LINE__, __func__,     \
          ##__VA_ARGS__)
#else
#define DEBUG_PRINT(fmt, ...) (void)0
#endif
#endif // INCLUDE_DEBUG_DEBUG_H_
