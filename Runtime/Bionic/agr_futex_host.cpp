#include "agr_futex_host.h"

#include <algorithm>
#include <chrono>
#include <condition_variable>
#include <limits>
#include <memory>
#include <mutex>
#include <new>
#include <unordered_map>

/* The only operations consumed by KitKat pthread.c are FUTEX_WAIT[_PRIVATE]
 * and FUTEX_WAKE[_PRIVATE]. The Bionic policy (mutex/cond/once state machines)
 * remains in its source port; this is the Darwin wait/wake boundary. */
struct agr_futex_host {
  struct queue {
    std::condition_variable cv;
    uint32_t waiters = 0;
    uint32_t pending = 0;
  };
  std::mutex lock;
  std::unordered_map<uint32_t, std::shared_ptr<queue>> queues;
  bool closing = false;
  void *opaque;
  agr_futex_read_word read;
};

extern "C" agr_futex_host *agr_futex_host_create(void *opaque,
                                                   agr_futex_read_word read) {
  if (read == nullptr) return nullptr;
  agr_futex_host *host = new (std::nothrow) agr_futex_host;
  if (host) { host->opaque = opaque; host->read = read; }
  return host;
}

extern "C" void agr_futex_host_destroy(agr_futex_host *host) {
  delete host;
}

extern "C" void agr_futex_host_cancel_all(agr_futex_host *host) {
  if (!host) return;
  std::lock_guard<std::mutex> lock(host->lock);
  host->closing = true;
  for (auto &entry : host->queues) entry.second->cv.notify_all();
}

extern "C" int32_t agr_futex_host_wait(agr_futex_host *host, uint32_t address,
                                         uint32_t expected,
                                         uint64_t relative_timeout_ns) {
  if (!host || !address || (address & 3u)) return -22; // Android EINVAL
  std::unique_lock<std::mutex> lock(host->lock);
  if (host->closing) return -125; // Android ECANCELED on process teardown.
  uint32_t actual = 0;
  if (host->read(host->opaque, address, &actual) != 0) return -14; // EFAULT
  if (actual != expected) return -11; // EAGAIN; check and enqueue are atomic
  if (relative_timeout_ns == 0) return -110; // ETIMEDOUT
  std::shared_ptr<agr_futex_host::queue> q;
  try {
    auto &slot = host->queues[address];
    if (!slot) slot = std::make_shared<agr_futex_host::queue>();
    q = slot;
  } catch (const std::bad_alloc &) {
    return -12; // Android ENOMEM
  }
  ++q->waiters;
  bool awoken = false;
  auto ready = [&] { return q->pending != 0 || host->closing; };
  if (relative_timeout_ns == UINT64_MAX) {
    q->cv.wait(lock, ready);
    awoken = true;
  } else {
    const auto duration = std::chrono::nanoseconds(
        static_cast<int64_t>(std::min<uint64_t>(relative_timeout_ns,
          static_cast<uint64_t>(std::numeric_limits<int64_t>::max()))));
    awoken = q->cv.wait_for(lock, duration, ready);
  }
  /* cancel_all also satisfies the wait predicate, but does not publish a
   * wake token. Never underflow pending while tearing down a process. */
  if (awoken && q->pending != 0) --q->pending;
  --q->waiters;
  if (q->waiters == 0) host->queues.erase(address);
  if (host->closing) return -125;
  return awoken ? 0 : -110;
}

extern "C" int32_t agr_futex_host_wake(agr_futex_host *host, uint32_t address,
                                         uint32_t maximum) {
  if (!host || !address || (address & 3u)) return -22;
  if (maximum == 0) return 0;
  std::lock_guard<std::mutex> lock(host->lock);
  auto it = host->queues.find(address);
  if (it == host->queues.end()) return 0;
  auto &q = *it->second;
  const uint32_t count = std::min(maximum, q.waiters - q.pending);
  q.pending += count;
  if (count == 1) q.cv.notify_one();
  else if (count) q.cv.notify_all();
  return static_cast<int32_t>(count);
}
