#include "../../Runtime/Bionic/agr_bionic_sync.h"
#include "../../Runtime/Bionic/agr_bionic_tls.h"
#include "../../Runtime/Bionic/agr_futex_host.h"

#include <array>
#include <atomic>
#include <cstdint>
#include <cstdio>

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
  agr_bionic_tls_destroy(tls);
  agr_futex_host_destroy(f.futex);

  std::printf("{\"normal_busy\":%d,\"recursive_first\":%d,"
      "\"recursive_second\":%d,\"errorcheck_deadlock\":%d,"
      "\"cond_timeout\":%d,\"once_count\":%d,"
      "\"tls_key_first\":%u,\"tls_key_reused\":%u,"
      "\"tls_set_value\":%d,\"tls_after_delete\":%d}\n",
      normal_busy, recursive_first, recursive_second, errorcheck_deadlock,
      cond_timeout, f.once_count, first, reused, tls_set_value, tls_after_delete);
}
