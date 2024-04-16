#include "tpool.h"
#include <pthread.h>
#include <stdio.h>
#define NOT_IMPLEMENTED                                                        \
  (printf("Function: %s is not implemented. - %s:%d", __func__, __FILE__,      \
          __LINE__))
// The Thread Pool Work Queue.
struct tpool_work {
  thread_function_t func;
  void *args;
  struct tpool_work *next;
};
// Type Alias for the Thread Pool Work Queue.
typedef struct tpool_work tpool_work_t;

// The Thread Pool itself. It contains pointers to the work queue and mutex
// conditions to prevent race conditions
// Credit to John Schember <john@nachtimwald.com> for the thread pool structure.
// Much of the thread pool implementation is inspired by his article on his C
// Thread Pool
struct tpool {
  tpool_work_t *work_first;
  tpool_work_t *work_last;
  pthread_mutex_t work_mutex;
  pthread_cond_t work_cond;
  pthread_cond_t working_cond;
  size_t working_cnt;
  size_t thread_cnt;
  bool stop;
};

// Creates the Thread Pool. Thread_count is the num of threads created for the
// pool.
void tpool_create(size_t thread_count) {
  NOT_IMPLEMENTED;
  return;
}

// Frees the memory and destructs the threadpool.
void tpool_destroy(tpool_t pool) {
  NOT_IMPLEMENTED;
  return;
}

// Add work to the Task Queue in the Thread Pool
bool tpool_add_work(tpool_t pool, thread_function_t func, void *args) {
  NOT_IMPLEMENTED;
  return false;
}

// When destroying the Thread Pool, wait for current working threads to finish
bool tpool_wait(tpool_t pool) {
  NOT_IMPLEMENTED;
  return false;
}
