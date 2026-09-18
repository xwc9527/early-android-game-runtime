/*
 * Android 4.4.4_r2 source port boundary:
 *   libc/bionic/pthread_create.cpp: creation gate and zombie publication.
 *   libc/bionic/pthread_join.cpp: self/joined/detached checks and join wait.
 *   libc/bionic/pthread_detach.cpp: detach and joined-race behavior.
 *   libc/bionic/pthread_internal.h: detached/joined/zombie flag model.
 * Linux clone, kernel TLS, gThreadList and native pthread_internal_t pointers
 * are replaced by HostServices and opaque 32-bit guest thread handles.
 */
#include "agr_bionic_thread_lifecycle.h"
#include "agr_bionic_errno.h"
#include "agr_bionic_errno_host.h"

#include <condition_variable>
#include <cstdint>
#include <memory>
#include <mutex>
#include <new>
#include <unordered_map>

struct agr_bionic_thread_lifecycle;

namespace {
constexpr uint32_t kDetached = 0x00000001u;
constexpr uint32_t kJoined = 0x00000004u;
constexpr uint32_t kZombie = 0x00000008u;

struct record {
  agr_bionic_thread_lifecycle *owner;
  uint32_t handle;
  uint32_t guest_thread;
  uint32_t start_routine;
  uint32_t argument;
  uint32_t flags;
  uint32_t return_value;
  void *host_handle;
  void *guest_context;
  std::condition_variable exited;
};
}

struct agr_bionic_thread_lifecycle {
  agr_host_services host;
  void *opaque;
  agr_bionic_thread_execute execute;
  std::mutex lock;
  std::unordered_map<uint32_t, std::unique_ptr<record>> records;
  uint32_t next_handle;
};

static void *thread_entry(void *opaque) {
  record *item = static_cast<record *>(opaque);
  agr_bionic_thread_lifecycle *owner = item->owner;
  uint32_t result = 0;
  int32_t execution = owner->execute(owner->opaque, item->guest_thread,
                                     item->start_routine, item->argument,
                                     &result);
  if (execution != 0) result = 0;
  std::unique_lock<std::mutex> lock(owner->lock);
  const uint32_t handle = item->handle;
  auto found = owner->records.find(handle);
  if (found == owner->records.end()) return nullptr;
  found->second->return_value = result;
  found->second->flags |= kZombie;
  const bool detached = (found->second->flags & kDetached) != 0;
  found->second->exited.notify_all();
  if (detached) owner->records.erase(found);
  return nullptr;
}

extern "C" agr_bionic_thread_lifecycle *agr_bionic_thread_lifecycle_create(
    const agr_host_services *host, void *opaque, agr_bionic_thread_execute execute) {
  if (!host || !host->thread_create || !host->thread_join || !host->thread_detach ||
      !execute) return nullptr;
  auto *lifecycle = new (std::nothrow) agr_bionic_thread_lifecycle;
  if (!lifecycle) return nullptr;
  lifecycle->host = *host;
  lifecycle->opaque = opaque;
  lifecycle->execute = execute;
  lifecycle->next_handle = 1;
  return lifecycle;
}

extern "C" void agr_bionic_thread_lifecycle_destroy(
    agr_bionic_thread_lifecycle *lifecycle) {
  // Runtime shutdown calls this only after all workers have been joined or
  // detached workers have exited. Do not free live guest state behind a
  // Darwin worker; lifecycle ownership is deliberately explicit.
  if (!lifecycle) return;
  {
    std::lock_guard<std::mutex> lock(lifecycle->lock);
    /* Process entry is registered for pthread_self but has no Darwin handle
     * owned by this lifecycle object. It is already stopped at Runtime
     * teardown, unlike detached workers. */
    for (auto it = lifecycle->records.begin(); it != lifecycle->records.end();) {
      const record *item = it->second.get();
      if (item->guest_thread == 1u && item->start_routine == 0 &&
          item->host_handle == nullptr) it = lifecycle->records.erase(it);
      else ++it;
    }
    if (!lifecycle->records.empty()) return;
  }
  delete lifecycle;
}

extern "C" int32_t agr_bionic_thread_lifecycle_create_thread(
    agr_bionic_thread_lifecycle *lifecycle, uint32_t guest_thread,
    uint32_t start_routine, uint32_t argument, uint32_t detached,
    uint32_t *pthread_handle) {
  if (!lifecycle || !guest_thread || !start_routine || !pthread_handle ||
      detached > 1) return AGR_ANDROID_EINVAL;
  std::unique_lock<std::mutex> lock(lifecycle->lock);
  uint32_t handle = lifecycle->next_handle++;
  if (!handle) handle = lifecycle->next_handle++;
  std::unique_ptr<record> item(new (std::nothrow) record{});
  if (!item) return AGR_ANDROID_EAGAIN;
  item->owner = lifecycle;
  item->handle = handle;
  item->guest_thread = guest_thread;
  item->start_routine = start_routine;
  item->argument = argument;
  item->flags = detached ? kDetached : 0;
  record *raw = item.get();
  try { lifecycle->records.emplace(handle, std::move(item)); }
  catch (const std::bad_alloc &) { return AGR_ANDROID_EAGAIN; }
  void *host_handle = nullptr;
  const int32_t create = lifecycle->host.thread_create(lifecycle->host.context,
      thread_entry, raw, &host_handle);
  if (create != 0) {
    lifecycle->records.erase(handle);
    return agr_bionic_errno_from_host(create);
  }
  raw->host_handle = host_handle;
  if (detached) {
    const int32_t detach_result = lifecycle->host.thread_detach(
        lifecycle->host.context, host_handle);
    if (detach_result != 0) {
      raw->flags &= ~kDetached;
      return agr_bionic_errno_from_host(detach_result);
    }
    raw->host_handle = nullptr;
  }
  *pthread_handle = handle;
  return 0;
}

extern "C" int32_t agr_bionic_thread_lifecycle_join(
    agr_bionic_thread_lifecycle *lifecycle, uint32_t handle,
    uint32_t *return_value) {
  if (!lifecycle || !handle) return AGR_ANDROID_EINVAL;
  std::unique_lock<std::mutex> lock(lifecycle->lock);
  auto found = lifecycle->records.find(handle);
  if (found == lifecycle->records.end()) return AGR_ANDROID_ESRCH;
  if (lifecycle->host.thread_guest_binding &&
      lifecycle->host.thread_guest_binding(lifecycle->host.context) == found->second.get())
    return AGR_ANDROID_EDEADLK;
  if (found->second->flags & kDetached) return AGR_ANDROID_EINVAL;
  if (found->second->flags & kJoined) return AGR_ANDROID_EINVAL;
  found->second->flags |= kJoined;
  while ((found->second->flags & kZombie) == 0)
    found->second->exited.wait(lock);
  if (return_value) *return_value = found->second->return_value;
  void *host_handle = found->second->host_handle;
  lock.unlock();
  const int32_t join_result = lifecycle->host.thread_join(lifecycle->host.context,
                                                          host_handle, nullptr);
  if (join_result != 0) return agr_bionic_errno_from_host(join_result);
  lock.lock();
  auto final = lifecycle->records.find(handle);
  if (final != lifecycle->records.end()) lifecycle->records.erase(final);
  return 0;
}

extern "C" int32_t agr_bionic_thread_lifecycle_detach(
    agr_bionic_thread_lifecycle *lifecycle, uint32_t handle) {
  if (!lifecycle || !handle) return AGR_ANDROID_EINVAL;
  std::unique_lock<std::mutex> lock(lifecycle->lock);
  auto found = lifecycle->records.find(handle);
  if (found == lifecycle->records.end()) return AGR_ANDROID_ESRCH;
  if (found->second->flags & kDetached) return AGR_ANDROID_EINVAL;
  if (found->second->flags & kJoined) return 0; // KitKat keeps the joiner owner.
  const int32_t result = lifecycle->host.thread_detach(lifecycle->host.context,
                                                       found->second->host_handle);
  if (result != 0) return agr_bionic_errno_from_host(result);
  found->second->host_handle = nullptr;
  found->second->flags |= kDetached;
  if (found->second->flags & kZombie) lifecycle->records.erase(found);
  return 0;
}

extern "C" int32_t agr_bionic_thread_lifecycle_bind_current(
    agr_bionic_thread_lifecycle *lifecycle, uint32_t guest_thread,
    void *guest_context) {
  if (!lifecycle || !guest_thread || !guest_context ||
      !lifecycle->host.thread_bind_guest) return AGR_ANDROID_EINVAL;
  std::lock_guard<std::mutex> lock(lifecycle->lock);
  for (auto &entry : lifecycle->records) {
    record *item = entry.second.get();
    if (item->guest_thread != guest_thread) continue;
    item->guest_context = guest_context;
    lifecycle->host.thread_bind_guest(lifecycle->host.context, guest_context);
    return 0;
  }
  return AGR_ANDROID_ESRCH;
}

extern "C" int32_t agr_bionic_thread_lifecycle_register_current(
    agr_bionic_thread_lifecycle *lifecycle, uint32_t guest_thread,
    uint32_t pthread_handle, void *guest_context) {
  if (!lifecycle || !guest_thread || !pthread_handle || !guest_context ||
      !lifecycle->host.thread_bind_guest) return AGR_ANDROID_EINVAL;
  std::lock_guard<std::mutex> lock(lifecycle->lock);
  if (lifecycle->records.count(pthread_handle)) return AGR_ANDROID_EEXIST;
  std::unique_ptr<record> item(new (std::nothrow) record{});
  if (!item) return AGR_ANDROID_EAGAIN;
  item->owner = lifecycle;
  item->handle = pthread_handle;
  item->guest_thread = guest_thread;
  item->guest_context = guest_context;
  item->flags = kDetached; /* The process entry thread has no joinable host handle. */
  try { lifecycle->records.emplace(pthread_handle, std::move(item)); }
  catch (const std::bad_alloc &) { return AGR_ANDROID_EAGAIN; }
  if (pthread_handle >= lifecycle->next_handle) lifecycle->next_handle = pthread_handle + 1u;
  lifecycle->host.thread_bind_guest(lifecycle->host.context, guest_context);
  return 0;
}

extern "C" uint32_t agr_bionic_thread_lifecycle_self(
    agr_bionic_thread_lifecycle *lifecycle) {
  if (!lifecycle || !lifecycle->host.thread_guest_binding) return 0;
  void *guest_context = lifecycle->host.thread_guest_binding(lifecycle->host.context);
  if (!guest_context) return 0;
  std::lock_guard<std::mutex> lock(lifecycle->lock);
  for (const auto &entry : lifecycle->records)
    if (entry.second->guest_context == guest_context) return entry.second->handle;
  return 0;
}

extern "C" int32_t agr_bionic_thread_lifecycle_equal(uint32_t one, uint32_t two) {
  return one == two;
}

extern "C" uint32_t agr_bionic_thread_lifecycle_live_count(
    agr_bionic_thread_lifecycle *lifecycle) {
  if (!lifecycle) return 0;
  std::lock_guard<std::mutex> lock(lifecycle->lock);
  return static_cast<uint32_t>(lifecycle->records.size());
}
