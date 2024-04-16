#ifndef __ELLEFSEN_TPOOL_H__
#define __ELLEFSEN_TPOOL_H__

#include <stdbool.h>
#include <stddef.h>

struct tpool;
typedef struct tpool tpool_t;

typedef void (*thread_function_t)(void *args);

void tpool_create(size_t thread_count);
void tpool_destroy(tpool_t pool);

bool tpool_add_work(tpool_t pool, thread_function_t func, void *args);
bool tpool_wait(tpool_t pool);

#endif
