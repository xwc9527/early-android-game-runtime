#include "../Runtime/Bionic/agr_bionic_thread_lifecycle.h"
#include "../Runtime/Bionic/agr_bionic_errno.h"

#include <atomic>
#include <cassert>
#include <chrono>
#include <thread>

struct fixture {
  agr_bionic_thread_lifecycle *lifecycle = nullptr;
  std::atomic<uint32_t> ran{0};
  std::atomic<uint32_t> self_ok{0};
  std::atomic<uint32_t> self_join_ok{0};
};

static int32_t execute(void *opaque, uint32_t guest_thread, uint32_t start,
                       uint32_t argument, uint32_t *result) {
  auto *f = static_cast<fixture *>(opaque);
  const uint32_t self = agr_bionic_thread_lifecycle_self(f->lifecycle);
  if (self && agr_bionic_thread_lifecycle_join(f->lifecycle, self, nullptr) ==
                  AGR_ANDROID_EDEADLK) {
    ++f->self_join_ok;
  }
  if (self && guest_thread && start) ++f->self_ok;
  ++f->ran;
  *result = argument ^ 0x5a5a5a5au;
  return 0;
}

int main() {
  agr_host_services host;
  assert(agr_host_services_init_darwin(&host) == 0);
  fixture f;
  f.lifecycle = agr_bionic_thread_lifecycle_create(&host, &f, execute);
  assert(f.lifecycle);

  uint32_t first = 0;
  assert(agr_bionic_thread_lifecycle_create_thread(f.lifecycle, 101, 0x1000,
      0x1234, AGR_BIONIC_THREAD_JOINABLE, &first) == 0);
  uint32_t result = 0;
  assert(agr_bionic_thread_lifecycle_join(f.lifecycle, first, &result) == 0);
  assert(result == (0x1234u ^ 0x5a5a5a5au));
  assert(agr_bionic_thread_lifecycle_join(f.lifecycle, first, nullptr) ==
         AGR_ANDROID_ESRCH);

  uint32_t detached = 0;
  assert(agr_bionic_thread_lifecycle_create_thread(f.lifecycle, 102, 0x1001,
      0x4321, AGR_BIONIC_THREAD_DETACHED, &detached) == 0);
  assert(agr_bionic_thread_lifecycle_detach(f.lifecycle, detached) ==
         AGR_ANDROID_EINVAL);
  const auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(5);
  while (agr_bionic_thread_lifecycle_live_count(f.lifecycle) != 0 &&
         std::chrono::steady_clock::now() < deadline) std::this_thread::yield();
  assert(agr_bionic_thread_lifecycle_live_count(f.lifecycle) == 0);

  // Lifecycle must not retain history-sized metadata. Each create/join erases
  // its record; this is the requested 100k host thread lifecycle stress.
  for (uint32_t i = 0; i < 100000; ++i) {
    uint32_t handle = 0, returned = 0;
    assert(agr_bionic_thread_lifecycle_create_thread(f.lifecycle, i + 1000,
        0x2000, i, AGR_BIONIC_THREAD_JOINABLE, &handle) == 0);
    assert(agr_bionic_thread_lifecycle_join(f.lifecycle, handle, &returned) == 0);
    assert(returned == (i ^ 0x5a5a5a5au));
  }
  assert(agr_bionic_thread_lifecycle_live_count(f.lifecycle) == 0);
  assert(f.ran == 100002 && f.self_ok == 100002 && f.self_join_ok == 100002);
  agr_bionic_thread_lifecycle_destroy(f.lifecycle);
}
