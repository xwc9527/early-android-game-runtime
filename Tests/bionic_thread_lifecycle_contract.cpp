#include "../Runtime/Bionic/agr_bionic_thread_lifecycle.h"
#include "../Runtime/Bionic/agr_bionic_errno.h"

#include <atomic>
#include <cassert>
#include <chrono>
#include <thread>

extern "C" {
void *arm_interp_create(void);
void *arm_interp_create_thread(void *parent);
void arm_interp_destroy(void *cpu);
int32_t arm_interp_load(void *cpu, uint32_t address, const uint8_t *bytes,
                        uint32_t size);
int32_t arm_interp_set_page_permissions(void *cpu, uint32_t address,
                                         uint32_t size, uint32_t protection);
int32_t arm_interp_set_reg(void *cpu, uint32_t reg, uint32_t value);
uint32_t arm_interp_get_reg(void *cpu, uint32_t reg);
void arm_interp_set_thread_tag(void *cpu, uint32_t tag);
int32_t arm_interp_run(void *cpu, uint64_t *budget, uint32_t *svc);
}

struct fixture {
  agr_bionic_thread_lifecycle *lifecycle = nullptr;
  void *parent_cpu = nullptr;
  std::atomic<uint32_t> ran{0};
  std::atomic<uint32_t> self_ok{0};
  std::atomic<uint32_t> self_join_ok{0};
  std::atomic<uint32_t> independent_cpu_ok{0};
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
  // This is the execution placement contract: Bionic's lifecycle owns a
  // Darwin pthread, and its callback creates a distinct ARM CPU handle with
  // the process memory inherited from the parent. The two-instruction ARM
  // body is supplied once through the parent address space below.
  void *cpu = arm_interp_create_thread(f->parent_cpu);
  assert(cpu && cpu != f->parent_cpu);
  assert(arm_interp_set_reg(cpu, 0, argument) == 0);
  assert(arm_interp_set_reg(cpu, 13, 0x9000) == 0);
  assert(arm_interp_set_reg(cpu, 15, start) == 0);
  arm_interp_set_thread_tag(cpu, guest_thread);
  uint64_t budget = 16;
  uint32_t svc = 0;
  assert(arm_interp_run(cpu, &budget, &svc) == 1 && svc == 0);
  assert(arm_interp_get_reg(cpu, 0) == argument);
  arm_interp_destroy(cpu);
  ++f->independent_cpu_ok;
  ++f->ran;
  *result = argument ^ 0x5a5a5a5au;
  return 0;
}

int main() {
  agr_host_services host;
  assert(agr_host_services_init_darwin(&host) == 0);
  fixture f;
  f.parent_cpu = arm_interp_create();
  assert(f.parent_cpu);
  // mov r0, r0; svc #0. The code is written only through the parent CPU; a
  // worker can execute it only if arm_interp_create_thread shares guest memory.
  const uint8_t arm_body[] = {0x00, 0x00, 0xa0, 0xe1, 0x00, 0x00, 0x00, 0xef};
  assert(arm_interp_load(f.parent_cpu, 0x2000, arm_body, sizeof(arm_body)) == 0);
  assert(arm_interp_set_page_permissions(f.parent_cpu, 0x2000, 4096, 5) == 0);
  f.lifecycle = agr_bionic_thread_lifecycle_create(&host, &f, execute);
  assert(f.lifecycle);

  uint32_t first = 0;
  assert(agr_bionic_thread_lifecycle_create_thread(f.lifecycle, 101, 0x2000,
      0x1234, AGR_BIONIC_THREAD_JOINABLE, &first) == 0);
  uint32_t result = 0;
  assert(agr_bionic_thread_lifecycle_join(f.lifecycle, first, &result) == 0);
  assert(result == (0x1234u ^ 0x5a5a5a5au));
  assert(agr_bionic_thread_lifecycle_join(f.lifecycle, first, nullptr) ==
         AGR_ANDROID_ESRCH);

  uint32_t detached = 0;
  assert(agr_bionic_thread_lifecycle_create_thread(f.lifecycle, 102, 0x2000,
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
  assert(f.ran == 100002 && f.self_ok == 100002 && f.self_join_ok == 100002 &&
         f.independent_cpu_ok == 100002);
  agr_bionic_thread_lifecycle_destroy(f.lifecycle);
  arm_interp_destroy(f.parent_cpu);
}
