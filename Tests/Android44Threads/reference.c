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

  printf("{\"normal_busy\":%d,\"recursive_first\":%d,"
         "\"recursive_second\":%d,\"errorcheck_deadlock\":%d,"
         "\"cond_timeout\":%d,\"once_count\":%d,"
         "\"tls_key_first\":%u,\"tls_key_reused\":%u,"
         "\"tls_set_value\":%d,\"tls_after_delete\":%d}\n",
         normal_busy, recursive_first, recursive_second,
         errorcheck_deadlock, cond_timeout, once_count,
         (unsigned)first, (unsigned)reused, tls_set_value, tls_after_delete);
  return 0;
}
