#include "../Runtime/Bionic/agr_bionic_sync.h"
#include "../Runtime/Bionic/agr_bionic_errno.h"
#include "../Runtime/Bionic/agr_futex_host.h"

#include <atomic>
#include <cassert>
#include <cstdio>
#include <chrono>
#include <thread>
#include <vector>

struct fixture {
  std::atomic<uint32_t> words[4]{};
  agr_futex_host *futex = nullptr;
  std::atomic<uint32_t> init_count{0};
};
static thread_local uint32_t guest_tid = 1;
static std::atomic<uint32_t> next_tid{2};

static std::atomic<uint32_t> *word(fixture *f, uint32_t address) {
  if (address < 0x4000 || address >= 0x4010 || (address & 3)) return nullptr;
  return &f->words[(address - 0x4000) / 4];
}
static int32_t load(void *opaque, uint32_t address, uint32_t *value) {
  auto *w = word(static_cast<fixture *>(opaque), address);
  if (!w) return -1;
  *value = w->load(std::memory_order_seq_cst); return 0;
}
static int32_t store(void *opaque, uint32_t address, uint32_t value) {
  auto *w = word(static_cast<fixture *>(opaque), address);
  if (!w) return -1;
  w->store(value, std::memory_order_seq_cst); return 0;
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
  *previous = w->exchange(value, std::memory_order_seq_cst); return 0;
}
static int32_t fetch_sub(void *opaque, uint32_t address, uint32_t value,
                          uint32_t *previous) {
  auto *w = word(static_cast<fixture *>(opaque), address);
  if (!w) return -1;
  *previous = w->fetch_sub(value, std::memory_order_seq_cst); return 0;
}
static int32_t wait(void *opaque, uint32_t address, uint32_t expected,
                     uint64_t ns) {
  return agr_futex_host_wait(static_cast<fixture *>(opaque)->futex,
                              address, expected, ns);
}
static int32_t wake(void *opaque, uint32_t address, uint32_t count) {
  return agr_futex_host_wake(static_cast<fixture *>(opaque)->futex,
                              address, count);
}
static uint32_t current_tid(void *) { return guest_tid; }
static int32_t invoke_once(void *opaque, uint32_t) {
  static_cast<fixture *>(opaque)->init_count.fetch_add(1); return 0;
}

int main() {
  fixture f;
  f.futex = agr_futex_host_create(&f, load);
  agr_bionic_sync sync{&f, load, store, cas, exchange, fetch_sub,
                       wait, wake, current_tid, invoke_once};
  constexpr uint32_t mutex = 0x4000, cond = 0x4004, once = 0x4008;
  assert(agr_bionic_mutex_init(&sync, mutex, 0) == 0);
  std::fprintf(stderr, "sync: normal mutex contention\n");
  assert(agr_bionic_mutex_lock(&sync, mutex) == 0);
  assert(agr_bionic_mutex_trylock(&sync, mutex) != 0);
  std::atomic<uint32_t> acquired{0};
  std::thread contender([&] {
    guest_tid = next_tid++;
    assert(agr_bionic_mutex_lock(&sync, mutex) == 0);
    ++acquired;
    assert(agr_bionic_mutex_unlock(&sync, mutex) == 0);
  });
  while ((f.words[0].load() & 3u) != 2u) std::this_thread::yield();
  assert(agr_bionic_mutex_unlock(&sync, mutex) == 0);
  contender.join();
  assert(acquired == 1);
  assert(agr_bionic_mutex_destroy(&sync, mutex) == 0);
  std::fprintf(stderr, "sync: recursive and errorcheck\n");
  // KitKat pthread_mutex_destroy writes 0xdead10cc. Locking a destroyed
  // mutex is undefined; its normal-lock path may wait forever on that word.
  // Verify the AOSP sentinel, then reinitialize before the next contract.
  assert(f.words[0].load() == 0xdead10ccu);
  std::fprintf(stderr, "sync: recursive init\n");

  assert(agr_bionic_mutex_init(&sync, mutex, 1) == 0);
  assert(agr_bionic_mutex_lock(&sync, mutex) == 0);
  std::fprintf(stderr, "sync: recursive first lock\n");
  assert(agr_bionic_mutex_lock(&sync, mutex) == 0);
  std::fprintf(stderr, "sync: recursive second lock\n");
  assert(agr_bionic_mutex_unlock(&sync, mutex) == 0);
  assert(agr_bionic_mutex_unlock(&sync, mutex) == 0);
  std::fprintf(stderr, "sync: recursive unlocks\n");
  assert(agr_bionic_mutex_destroy(&sync, mutex) == 0);
  std::fprintf(stderr, "sync: recursive destroyed\n");
  assert(agr_bionic_mutex_init(&sync, mutex, 2) == 0);
  assert(agr_bionic_mutex_lock(&sync, mutex) == 0);
  std::fprintf(stderr, "sync: errorcheck first lock\n");
  assert(agr_bionic_mutex_lock(&sync, mutex) == AGR_ANDROID_EDEADLK);
  std::fprintf(stderr, "sync: errorcheck deadlock result\n");
  assert(agr_bionic_mutex_unlock(&sync, mutex) == 0);

  assert(agr_bionic_cond_init(&sync, cond, 0) == 0);
  std::fprintf(stderr, "sync: condition timeout and signal\n");
  assert(agr_bionic_mutex_lock(&sync, mutex) == 0);
  assert(agr_bionic_cond_wait_relative(&sync, cond, mutex, 1000000) == AGR_ANDROID_ETIMEDOUT);
  assert(agr_bionic_mutex_unlock(&sync, mutex) == 0);
  std::atomic<uint32_t> ready{0}, done{0};
  std::thread signaler([&] {
    guest_tid = next_tid++;
    assert(agr_bionic_mutex_lock(&sync, mutex) == 0);
    ready = 1;
    assert(agr_bionic_cond_signal(&sync, cond) == 0);
    assert(agr_bionic_mutex_unlock(&sync, mutex) == 0);
  });
  assert(agr_bionic_mutex_lock(&sync, mutex) == 0);
  while (!ready) assert(agr_bionic_cond_wait_relative(&sync, cond, mutex, 5000000000ULL) == 0);
  done = 1;
  assert(agr_bionic_mutex_unlock(&sync, mutex) == 0);
  signaler.join();
  assert(done == 1);
  assert(agr_bionic_cond_destroy(&sync, cond) == 0);
  std::fprintf(stderr, "sync: once concurrent callers\n");

  std::vector<std::thread> callers;
  for (uint32_t i = 0; i < 16; ++i) callers.emplace_back([&] {
    guest_tid = next_tid++;
    assert(agr_bionic_once(&sync, once, 0xdeadbeefu) == 0);
  });
  for (auto &thread : callers) thread.join();
  assert(f.init_count == 1);
  assert(f.words[2] == 2);
  std::fprintf(stderr, "sync: repeated contended lock\n");
  assert(agr_bionic_mutex_init(&sync, mutex, 0) == 0);
  uint32_t counter = 0;
  callers.clear();
  for (uint32_t i = 0; i < 4; ++i) callers.emplace_back([&] {
    guest_tid = next_tid++;
    for (uint32_t n = 0; n < 5000; ++n) {
      assert(agr_bionic_mutex_lock(&sync, mutex) == 0);
      ++counter;
      assert(agr_bionic_mutex_unlock(&sync, mutex) == 0);
    }
  });
  for (auto &thread : callers) thread.join();
  assert(counter == 20000);
  std::fprintf(stderr, "sync: condition broadcast\n");
  assert(agr_bionic_cond_init(&sync, cond, 0) == 0);
  std::atomic<uint32_t> waiting{0}, awakened{0};
  bool release = false;
  callers.clear();
  for (uint32_t i = 0; i < 4; ++i) callers.emplace_back([&] {
    guest_tid = next_tid++;
    assert(agr_bionic_mutex_lock(&sync, mutex) == 0);
    ++waiting;
    while (!release)
      assert(agr_bionic_cond_wait_relative(&sync, cond, mutex, 5000000000ULL) == 0);
    ++awakened;
    assert(agr_bionic_mutex_unlock(&sync, mutex) == 0);
  });
  while (waiting != 4) std::this_thread::yield();
  assert(agr_bionic_mutex_lock(&sync, mutex) == 0);
  release = true;
  assert(agr_bionic_cond_broadcast(&sync, cond) == 0);
  assert(agr_bionic_mutex_unlock(&sync, mutex) == 0);
  for (auto &thread : callers) thread.join();
  assert(awakened == 4);
  assert(agr_bionic_cond_destroy(&sync, cond) == 0);
  assert(agr_bionic_mutex_destroy(&sync, mutex) == 0);
  agr_futex_host_destroy(f.futex);
}
