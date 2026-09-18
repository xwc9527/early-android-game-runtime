#include <errno.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

/* API19 Bionic exports this non-POSIX relative timeout variant. */
extern int pthread_cond_timedwait_relative_np(pthread_cond_t *, pthread_mutex_t *,
                                               const struct timespec *);

static int once_count;
static void initialize_once(void) { ++once_count; }
typedef struct { int self_nonzero, equal_self, worker_errno; } worker_result;
static void *thread_body(void *opaque) {
  worker_result *result=(worker_result *)opaque;
  pthread_t self=pthread_self();
  result->self_nonzero=self!=0;
  result->equal_self=pthread_equal(self,pthread_self());
  errno=33; result->worker_errno=errno;
  return (void *)(uintptr_t)0x12345678u;
}

int main(void) {
  pthread_mutex_t mutex;
  pthread_mutex_init(&mutex, NULL);
  pthread_mutex_lock(&mutex);
  int normal_busy = pthread_mutex_trylock(&mutex);
  pthread_mutex_unlock(&mutex);
  pthread_mutex_destroy(&mutex);

  pthread_mutexattr_t attr;
  pthread_mutexattr_init(&attr);
  pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
  pthread_mutex_init(&mutex, &attr);
  int recursive_first = pthread_mutex_lock(&mutex);
  int recursive_second = pthread_mutex_lock(&mutex);
  pthread_mutex_unlock(&mutex);
  pthread_mutex_unlock(&mutex);
  pthread_mutex_destroy(&mutex);

  pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);
  pthread_mutex_init(&mutex, &attr);
  pthread_mutex_lock(&mutex);
  int errorcheck_deadlock = pthread_mutex_lock(&mutex);
  pthread_mutex_unlock(&mutex);
  pthread_mutexattr_destroy(&attr);

  pthread_cond_t cond;
  pthread_cond_init(&cond, NULL);
  pthread_mutex_lock(&mutex);
  const struct timespec wait_time = {0, 1000000};
  int cond_timeout = pthread_cond_timedwait_relative_np(&cond, &mutex, &wait_time);
  pthread_mutex_unlock(&mutex);
  pthread_cond_destroy(&cond);
  pthread_mutex_destroy(&mutex);

  pthread_once_t once = PTHREAD_ONCE_INIT;
  pthread_once(&once, initialize_once);
  pthread_once(&once, initialize_once);

  pthread_key_t first, reused;
  pthread_key_create(&first, NULL);
  pthread_setspecific(first, (void *)(uintptr_t)0x1234);
  int tls_set_value = (int)((uintptr_t)pthread_getspecific(first));
  pthread_key_delete(first);
  int tls_after_delete = (int)((uintptr_t)pthread_getspecific(first));
  pthread_key_create(&reused, NULL);
  pthread_key_delete(reused);

  errno=7;
  worker_result worker={0}; pthread_t thread; void *thread_result=0;
  int create_result=pthread_create(&thread,NULL,thread_body,&worker);
  int join_result=create_result?create_result:pthread_join(thread,&thread_result);
  int main_errno=errno;

  printf("{\"normal_busy\":%d,\"recursive_first\":%d,"
         "\"recursive_second\":%d,\"errorcheck_deadlock\":%d,"
         "\"cond_timeout\":%d,\"once_count\":%d,"
         "\"tls_key_first\":%u,\"tls_key_reused\":%u,"
         "\"tls_set_value\":%d,\"tls_after_delete\":%d,"
         "\"thread_create\":%d,\"thread_join\":%d,\"thread_return\":%u,"
         "\"thread_self_nonzero\":%d,\"thread_equal_self\":%d,"
         "\"worker_errno\":%d,\"main_errno\":%d}\n",
         normal_busy, recursive_first, recursive_second,
         errorcheck_deadlock, cond_timeout, once_count,
         (unsigned)first, (unsigned)reused, tls_set_value, tls_after_delete,
         create_result,join_result,(unsigned)(uintptr_t)thread_result,
         worker.self_nonzero,worker.equal_self,worker.worker_errno,main_errno);
  return 0;
}
