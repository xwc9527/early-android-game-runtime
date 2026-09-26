#include "../Runtime/Bionic/agr_bionic_errno.h"
#include "../Runtime/Bionic/agr_bionic_sync.h"
#include "../Runtime/Bionic/agr_futex_host.h"

#include <atomic>
#include <cassert>
#include <cstdio>
#include <thread>

struct fixture {
  std::atomic<uint32_t> words[2]{};
  agr_futex_host *futex = nullptr;
  std::atomic<int> fail_fetch_sub{0};
  std::atomic<int> waits{0};
  std::atomic<int> unlocks{0};
};

static thread_local uint32_t guest_tid = 1;

static std::atomic<uint32_t> *word(fixture *f, uint32_t address) {
  if (address < 0x4000 || address >= 0x4008 || (address & 3)) return nullptr;
  return &f->words[(address - 0x4000) / 4];
}
static int32_t load(void *opaque, uint32_t address, uint32_t *value) {
  auto *w = word(static_cast<fixture *>(opaque), address);
  if (!w) return -1;
  *value = w->load(std::memory_order_seq_cst);
  return 0;
}
static int32_t store(void *opaque, uint32_t address, uint32_t value) {
  auto *w = word(static_cast<fixture *>(opaque), address);
  if (!w) return -1;
  w->store(value, std::memory_order_seq_cst);
  return 0;
}
static int32_t cas(void *opaque, uint32_t address, uint32_t expected,
                   uint32_t value, uint32_t *observed) {
  auto *w = word(static_cast<fixture *>(opaque), address);
  if (!w) return -1;
  *observed = expected;
  w->compare_exchange_strong(*observed, value, std::memory_order_seq_cst);
  return 0;
}
static int32_t exchange(void *opaque, uint32_t address, uint32_t value,
                        uint32_t *previous) {
  auto *w = word(static_cast<fixture *>(opaque), address);
  if (!w) return -1;
  *previous = w->exchange(value, std::memory_order_seq_cst);
  return 0;
}
static int32_t fetch_sub(void *opaque, uint32_t address, uint32_t value,
                         uint32_t *previous) {
  auto *f = static_cast<fixture *>(opaque);
  auto *w = word(f, address);
  if (!w) return -1;
  *previous = w->fetch_sub(value, std::memory_order_seq_cst);
  f->unlocks.fetch_add(1);
  if (f->fail_fetch_sub.exchange(0) == 1) return -1;
  return 0;
}
static int32_t wait(void *opaque, uint32_t address, uint32_t expected, uint64_t ns) {
  auto *f = static_cast<fixture *>(opaque);
  f->waits.fetch_add(1);
  return agr_futex_host_wait(f->futex, address, expected, ns);
}
static int32_t wake(void *opaque, uint32_t address, uint32_t count) {
  return agr_futex_host_wake(static_cast<fixture *>(opaque)->futex, address, count);
}
static uint32_t current_tid(void *) { return guest_tid; }

static agr_bionic_sync bind(fixture *f) {
  return agr_bionic_sync{f, load, store, cas, exchange, fetch_sub,
                         wait, wake, current_tid, nullptr};
}

int main() {
  constexpr uint32_t mutex = 0x4000, cond = 0x4004;
  fixture f;
  f.futex = agr_futex_host_create(&f, load);
  agr_bionic_sync sync = bind(&f);
  assert(agr_bionic_mutex_init(&sync, mutex, 0) == 0);
  assert(agr_bionic_cond_init(&sync, cond, 0) == 0);
  std::atomic<uint32_t> suspend_count{1};
  std::atomic<int> waiter_rc{-99};
  std::thread waiter([&] {
    guest_tid = 2;
    assert(agr_bionic_mutex_lock(&sync, mutex) == 0);
    while (suspend_count.load() != 0) {
      waiter_rc = agr_bionic_cond_wait_relative(&sync, cond, mutex, UINT64_MAX);
      if (waiter_rc != 0) break;
    }
    assert(suspend_count.load() == 0);
    assert(agr_bionic_mutex_trylock(&sync, mutex) != 0);
    assert(agr_bionic_mutex_unlock(&sync, mutex) == 0);
  });
  while (f.waits.load() == 0) std::this_thread::yield();
  guest_tid = 3;
  assert(agr_bionic_mutex_lock(&sync, mutex) == 0);
  suspend_count.store(0);
  assert(agr_bionic_cond_broadcast(&sync, cond) == 0);
  assert(agr_bionic_mutex_unlock(&sync, mutex) == 0);
  waiter.join();
  std::printf("SUSPEND_WAIT_WAKE rc=%d payload=%u relocked=1\n",
              waiter_rc.load(), suspend_count.load());
  assert(waiter_rc.load() == 0);

  f.fail_fetch_sub.store(1);
  int waits_before = f.waits.load();
  assert(agr_bionic_mutex_lock(&sync, mutex) == 0);
  std::atomic<int> ignored{-99};
  std::thread woken([&] {
    guest_tid = 4;
    ignored = agr_bionic_cond_wait_relative(&sync, cond, mutex, UINT64_MAX);
    assert(agr_bionic_mutex_unlock(&sync, mutex) == 0);
  });
  while (f.waits.load() == waits_before) std::this_thread::yield();
  guest_tid = 5;
  assert(agr_bionic_mutex_lock(&sync, mutex) == 0);
  assert(agr_bionic_cond_broadcast(&sync, cond) == 0);
  assert(agr_bionic_mutex_unlock(&sync, mutex) == 0);
  woken.join();
  std::printf("UNLOCK_ERROR_IGNORED waited=%d returned=%d\n",
              f.waits.load() > waits_before ? 1 : 0, ignored.load());
  assert(f.waits.load() > waits_before);
  assert(ignored.load() == 0);
  std::printf("SUSPEND_PATH ok=1\n");
  agr_futex_host_destroy(f.futex);
  return 0;
}
