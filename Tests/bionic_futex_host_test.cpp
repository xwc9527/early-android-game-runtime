#include "../Runtime/Bionic/agr_futex_host.h"

#include <atomic>
#include <cassert>
#include <chrono>
#include <thread>

static int32_t read_word(void *opaque, uint32_t address, uint32_t *value) {
  if (address != 0x4000) return -1;
  *value = static_cast<std::atomic<uint32_t> *>(opaque)->load();
  return 0;
}

static void wake_until_queued(agr_futex_host *futex, uint32_t count) {
  const auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(5);
  while (std::chrono::steady_clock::now() < deadline) {
    if (agr_futex_host_wake(futex, 0x4000, count) == static_cast<int32_t>(count)) return;
    std::this_thread::yield();
  }
  assert(false && "guest futex waiters never queued");
}

int main() {
  std::atomic<uint32_t> word{7};
  agr_futex_host *futex = agr_futex_host_create(&word, read_word);
  assert(futex);
  assert(agr_futex_host_wait(futex, 0x4000, 8, 1000000) == -11);
  assert(agr_futex_host_wait(futex, 0x4000, 7, 0) == -110);
  assert(agr_futex_host_wait(futex, 0x4004, 7, 1000000) == -14);
  assert(agr_futex_host_wait(futex, 0x4000, 7, 1000000) == -110);
  assert(agr_futex_host_wake(futex, 0x4000, 1) == 0);

  for (int i = 0; i < 1000; ++i) {
    std::atomic<int32_t> result{-999};
    std::thread waiter([&] {
      result.store(agr_futex_host_wait(futex, 0x4000, 7, 5000000000ULL));
    });
    wake_until_queued(futex, 1);
    waiter.join();
    assert(result.load() == 0);
  }

  std::atomic<int32_t> first{-999}, second{-999};
  std::thread a([&] { first = agr_futex_host_wait(futex, 0x4000, 7, 5000000000ULL); });
  std::thread b([&] { second = agr_futex_host_wait(futex, 0x4000, 7, 5000000000ULL); });
  wake_until_queued(futex, 2);
  a.join(); b.join();
  assert(first == 0 && second == 0);
  agr_futex_host_destroy(futex);
}
