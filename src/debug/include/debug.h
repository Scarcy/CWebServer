/***
 * A Header only Library for Debug functionality.
 * The root CMakeLists.txt that compiles the executable sets the debug flag
 *option. If it's set, this library will then #define the DEBUG_PRINT Macro
 *Function. If it's not in debug mode, it defines a macro function with an empty
 *body.
 ***/

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

// Uses a clever do/while(0) trick.
// Even though it's technically a loop, it only executes once.
// A problem with multi function call macros is that it can break depending on
// the context it's used. With the do/while(0) we wrap the entire Macro in a
// codeblock, making it safe no matter where the macro is used
#define NOT_IMPLEMENTED()                                                      \
  do {                                                                         \
    fprintf(stderr, "%s : %s  -  Not Implemented Yet :)\n", __FILE__,          \
            __func__);                                                         \
    return;                                                                    \
  } while (0)
#endif // INCLUDE_DEBUG_DEBUG_H_
