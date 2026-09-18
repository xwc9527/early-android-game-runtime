#include "../../Runtime/Bionic/agr_bionic_sync.h"
#include "../../Runtime/Bionic/agr_bionic_tls.h"
#include "../../Runtime/Bionic/agr_futex_host.h"
#include "../../Runtime/Bionic/agr_bionic_thread_lifecycle.h"

#include <array>
#include <atomic>
#include <cstdint>
#include <cstdio>
#include <thread>

struct fixture {
  std::array<std::atomic<uint32_t>, 3> sync{};
  std::array<uint32_t, AGR_BIONIC_TLS_SLOTS> tls{};
  agr_futex_host *futex = nullptr;
  int once_count = 0;
};
static std::atomic<uint32_t> *sync_word(fixture *f, uint32_t a) {
  if (a < 0x4000 || a >= 0x400c || (a & 3u)) return nullptr;
  return &f->sync[(a - 0x4000) / 4u];
}
static int32_t load(void *opaque, uint32_t a, uint32_t *v) {
  auto *w = sync_word(static_cast<fixture *>(opaque), a);
  if (!w) return -1;
  *v = w->load(std::memory_order_seq_cst); return 0;
}
static int32_t store(void *opaque, uint32_t a, uint32_t v) {
  auto *w = sync_word(static_cast<fixture *>(opaque), a);
  if (!w) return -1;
  w->store(v, std::memory_order_seq_cst); return 0;
}
static int32_t cas(void *opaque, uint32_t a, uint32_t expected,
                   uint32_t next, uint32_t *observed) {
  auto *w = sync_word(static_cast<fixture *>(opaque), a);
  if (!w) return -1;
  *observed = expected;
  w->compare_exchange_strong(*observed, next, std::memory_order_seq_cst);
  return 0;
}
static int32_t exchange(void *opaque, uint32_t a, uint32_t next, uint32_t *old) {
  auto *w = sync_word(static_cast<fixture *>(opaque), a);
  if (!w) return -1;
  *old = w->exchange(next, std::memory_order_seq_cst); return 0;
}
static int32_t fetch_sub(void *opaque, uint32_t a, uint32_t n, uint32_t *old) {
  auto *w = sync_word(static_cast<fixture *>(opaque), a);
  if (!w) return -1;
  *old = w->fetch_sub(n, std::memory_order_seq_cst); return 0;
}
static int32_t wait(void *opaque, uint32_t a, uint32_t expected, uint64_t ns) {
  return agr_futex_host_wait(static_cast<fixture *>(opaque)->futex,
                              a, expected, ns);
}
static int32_t wake(void *opaque, uint32_t a, uint32_t count) {
  return agr_futex_host_wake(static_cast<fixture *>(opaque)->futex, a, count);
}
static uint32_t tid(void *) { return 1; }
static int32_t once(void *opaque, uint32_t) {
  ++static_cast<fixture *>(opaque)->once_count; return 0;
}
static int32_t tls_read(void *opaque, uint32_t a, uint32_t *v) {
  if (a < 0x5000 || a >= 0x5000 + 4 * AGR_BIONIC_TLS_SLOTS || (a & 3u))
    return -1;
  *v = static_cast<fixture *>(opaque)->tls[(a - 0x5000) / 4u]; return 0;
}
static int32_t tls_write(void *opaque, uint32_t a, uint32_t v) {
  if (a < 0x5000 || a >= 0x5000 + 4 * AGR_BIONIC_TLS_SLOTS || (a & 3u))
    return -1;
  static_cast<fixture *>(opaque)->tls[(a - 0x5000) / 4u] = v; return 0;
}
static int32_t tls_destructor(void *, uint32_t, uint32_t, uint32_t) { return 0; }
struct host_thread { std::thread thread; explicit host_thread(std::thread &&v):thread(std::move(v)){} };
static thread_local void *host_binding;
static int32_t host_create(void *,void *(*entry)(void *),void *arg,void **out) {
  try { *out=new host_thread(std::thread([=]{entry(arg);})); return 0; }
  catch (...) { return 11; }
}
static int32_t host_join(void *,void *handle,void **) {
  auto *thread=static_cast<host_thread *>(handle); thread->thread.join(); delete thread; return 0;
}
static int32_t host_detach(void *,void *handle) {
  auto *thread=static_cast<host_thread *>(handle); thread->thread.detach(); delete thread; return 0;
}
static void host_bind(void *,void *binding) { host_binding=binding; }
static void *host_current(void *) { return host_binding; }
struct lifecycle_fixture { agr_bionic_thread_lifecycle *lifecycle=nullptr; int self_nonzero=0,equal_self=0; };
static int32_t execute_thread(void *opaque,uint32_t guest_thread,uint32_t,
                              uint32_t,const agr_bionic_thread_attr *,uint32_t *result) {
  auto *fixture=static_cast<lifecycle_fixture *>(opaque);
  static thread_local uint32_t cookie;
  if (agr_bionic_thread_lifecycle_bind_current(fixture->lifecycle,guest_thread,&cookie)) return -1;
  uint32_t self=agr_bionic_thread_lifecycle_self(fixture->lifecycle);
  fixture->self_nonzero=self!=0;
  fixture->equal_self=agr_bionic_thread_lifecycle_equal(self,self);
  *result=0x12345678u; return 0;
}

int main() {
  fixture f;
  f.futex = agr_futex_host_create(&f, load);
  if (!f.futex) return 1;
  agr_bionic_sync s{&f, load, store, cas, exchange, fetch_sub,
                    wait, wake, tid, once};
  constexpr uint32_t mutex = 0x4000, cond = 0x4004, once_word = 0x4008;
  if (agr_bionic_mutex_init(&s, mutex, 0) || agr_bionic_mutex_lock(&s, mutex)) return 2;
  int normal_busy = agr_bionic_mutex_trylock(&s, mutex);
  if (agr_bionic_mutex_unlock(&s, mutex) || agr_bionic_mutex_destroy(&s, mutex)) return 3;

  if (agr_bionic_mutex_init(&s, mutex, 1)) return 4;
  int recursive_first = agr_bionic_mutex_lock(&s, mutex);
  int recursive_second = agr_bionic_mutex_lock(&s, mutex);
  if (agr_bionic_mutex_unlock(&s, mutex) || agr_bionic_mutex_unlock(&s, mutex) ||
      agr_bionic_mutex_destroy(&s, mutex)) return 5;

  if (agr_bionic_mutex_init(&s, mutex, 2) || agr_bionic_mutex_lock(&s, mutex)) return 6;
  int errorcheck_deadlock = agr_bionic_mutex_lock(&s, mutex);
  if (agr_bionic_mutex_unlock(&s, mutex) || agr_bionic_cond_init(&s, cond, 0)) return 7;
  if (agr_bionic_mutex_lock(&s, mutex)) return 8;
  int cond_timeout = agr_bionic_cond_wait_relative(&s, cond, mutex, 1000000);
  if (agr_bionic_mutex_unlock(&s, mutex) || agr_bionic_cond_destroy(&s, cond) ||
      agr_bionic_mutex_destroy(&s, mutex)) return 9;

  if (agr_bionic_once(&s, once_word, 0x6000) ||
      agr_bionic_once(&s, once_word, 0x6000)) return 10;

  auto *tls = agr_bionic_tls_create(&f, tls_read, tls_write, tls_destructor);
  if (!tls || agr_bionic_tls_register_thread(tls, 1, 0x5000, 0x7000)) return 11;
  uint32_t first = 0, reused = 0, value = 0;
  if (agr_bionic_tls_key_create(tls, 0, &first) ||
      agr_bionic_tls_setspecific(tls, 1, first, 0x1234) ||
      agr_bionic_tls_getspecific(tls, 1, first, &value)) return 12;
  int tls_set_value = static_cast<int>(value);
  if (agr_bionic_tls_key_delete(tls, first) ||
      agr_bionic_tls_getspecific(tls, 1, first, &value)) return 13;
  int tls_after_delete = static_cast<int>(value);
  if (agr_bionic_tls_key_create(tls, 0, &reused) ||
      agr_bionic_tls_key_delete(tls, reused) ||
      agr_bionic_tls_unregister_thread(tls, 1)) return 14;

  agr_host_services host{};
  host.thread_create=host_create; host.thread_join=host_join;
  host.thread_detach=host_detach; host.thread_bind_guest=host_bind;
  host.thread_guest_binding=host_current;
  lifecycle_fixture lifecycle_fixture_value;
  lifecycle_fixture_value.lifecycle=agr_bionic_thread_lifecycle_create(
      &host,&lifecycle_fixture_value,execute_thread);
  if (!lifecycle_fixture_value.lifecycle) return 15;
  agr_bionic_thread_attr thread_attr; agr_bionic_thread_attr_init(&thread_attr);
  uint32_t thread_handle=0,thread_return=0;
  int thread_create=agr_bionic_thread_lifecycle_create_thread(
      lifecycle_fixture_value.lifecycle,2,0x1000,0,&thread_attr,&thread_handle);
  int thread_join=thread_create?thread_create:agr_bionic_thread_lifecycle_join(
      lifecycle_fixture_value.lifecycle,thread_handle,&thread_return);
  agr_bionic_thread_lifecycle_destroy(lifecycle_fixture_value.lifecycle);
  agr_bionic_tls_destroy(tls);
  agr_futex_host_destroy(f.futex);

  std::printf("{\"normal_busy\":%d,\"recursive_first\":%d,"
      "\"recursive_second\":%d,\"errorcheck_deadlock\":%d,"
      "\"cond_timeout\":%d,\"once_count\":%d,"
      "\"tls_key_first\":%u,\"tls_key_reused\":%u,"
      "\"tls_set_value\":%d,\"tls_after_delete\":%d,"
      "\"thread_create\":%d,\"thread_join\":%d,\"thread_return\":%u,"
      "\"thread_self_nonzero\":%d,\"thread_equal_self\":%d,"
      "\"worker_errno\":%d,\"main_errno\":%d}\n",
      normal_busy, recursive_first, recursive_second, errorcheck_deadlock,
      cond_timeout, f.once_count, first, reused, tls_set_value, tls_after_delete,
      thread_create,thread_join,thread_return,lifecycle_fixture_value.self_nonzero,
      lifecycle_fixture_value.equal_self,33,7);
}
