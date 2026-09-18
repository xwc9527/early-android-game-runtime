/*
 * Copyright (C) 2008 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * Source port of android-4.4.4_r2 libc/bionic/pthread.c, mutex/cond/once
 * control flow. The ARM32 pthread object is a single in-guest 32-bit word;
 * direct pointer loads and __bionic_* atomics are replaced by callbacks into
 * the shared guest address space. Linux futex calls remain raw host callbacks.
 */
#include "agr_bionic_sync.h"
#include "agr_bionic_errno.h"

#include <climits>

namespace {
constexpr uint32_t kState = 3u;
constexpr uint32_t kUncontended = 1u;
constexpr uint32_t kContended = 2u;
constexpr uint32_t kCounter = 0x1ffcu;
constexpr uint32_t kCounterOne = 4u;
constexpr uint32_t kShared = 0x2000u;
constexpr uint32_t kType = 0xc000u;
constexpr uint32_t kRecursive = 0x4000u;
constexpr uint32_t kErrorcheck = 0x8000u;

bool load(agr_bionic_sync *s, uint32_t a, uint32_t *v) {
  return s && s->load && s->load(s->opaque, a, v) == 0;
}
bool store(agr_bionic_sync *s, uint32_t a, uint32_t v) {
  return s && s->store && s->store(s->opaque, a, v) == 0;
}
bool cas(agr_bionic_sync *s, uint32_t a, uint32_t old, uint32_t next,
         bool *swapped) {
  uint32_t observed = 0;
  if (!s->cas || s->cas(s->opaque, a, old, next, &observed) != 0) return false;
  *swapped = observed == old;
  return true;
}
bool exchange(agr_bionic_sync *s, uint32_t a, uint32_t next, uint32_t *old) {
  return s->exchange && s->exchange(s->opaque, a, next, old) == 0;
}
uint32_t tid(agr_bionic_sync *s) {
  return s->current_tid ? s->current_tid(s->opaque) & 0xffffu : 0;
}
}

extern "C" int32_t agr_bionic_mutex_init(agr_bionic_sync *s, uint32_t a,
                                            int32_t type) {
  if (!a || type < 0 || type > 2) return AGR_ANDROID_EINVAL;
  return store(s, a, static_cast<uint32_t>(type) << 14) ? 0 : AGR_ANDROID_EFAULT;
}

/* _normal_lock from KitKat pthread.c: 0 -> 1 fast path, exchange 2 on
 * contention, then futex-wait while the value is 2. */
extern "C" int32_t agr_bionic_mutex_lock(agr_bionic_sync *s, uint32_t a) {
  uint32_t value = 0;
  if (!a || !load(s, a, &value)) return AGR_ANDROID_EINVAL;
  const uint32_t type = value & kType, shared = value & kShared;
  if (type == 0) {
    bool won = false;
    if (!cas(s, a, shared, shared | kUncontended, &won)) return AGR_ANDROID_EFAULT;
    if (won) return 0;
    for (;;) {
      uint32_t previous = 0;
      if (!exchange(s, a, shared | kContended, &previous)) return AGR_ANDROID_EFAULT;
      if (previous == shared) return 0;
      if (!s->wait) return AGR_ANDROID_ENOSYS;
      int32_t rc = s->wait(s->opaque, a, shared | kContended, UINT64_MAX);
      if (rc != 0 && rc != -AGR_ANDROID_EAGAIN && rc != -AGR_ANDROID_EINTR) return -rc;
    }
  }
  if (type != kRecursive && type != kErrorcheck) return AGR_ANDROID_EINVAL;
  const uint32_t self = tid(s);
  if (!self) return AGR_ANDROID_EINVAL;
  const uint32_t unlocked = type | shared;
  if (value == unlocked) {
    bool won = false;
    if (!cas(s, a, value, (self << 16) | unlocked | kUncontended, &won)) return AGR_ANDROID_EFAULT;
    if (won) return 0;
  }
  for (;;) {
    if (!load(s, a, &value)) return AGR_ANDROID_EFAULT;
    if ((value & kState) != 0 && (value >> 16) == self) {
      if (type == kErrorcheck) return AGR_ANDROID_EDEADLK;
      if ((value & kCounter) == kCounter) return AGR_ANDROID_EAGAIN;
      bool won = false;
      if (!cas(s, a, value, value + kCounterOne, &won)) return AGR_ANDROID_EFAULT;
      if (won) return 0;
      continue;
    }
    if (value == unlocked) {
      bool won = false;
      if (!cas(s, a, value, (self << 16) | unlocked | kContended, &won)) return AGR_ANDROID_EFAULT;
      if (won) return 0;
      continue;
    }
    if ((value & kState) == kUncontended) {
      bool won = false;
      if (!cas(s, a, value, value ^ 3u, &won)) return AGR_ANDROID_EFAULT;
      if (!won) continue;
      value ^= 3u;
    }
    if (!s->wait) return AGR_ANDROID_ENOSYS;
    int32_t rc = s->wait(s->opaque, a, value, UINT64_MAX);
    if (rc != 0 && rc != -AGR_ANDROID_EAGAIN && rc != -AGR_ANDROID_EINTR) return -rc;
  }
}

extern "C" int32_t agr_bionic_mutex_trylock(agr_bionic_sync *s, uint32_t a) {
  uint32_t value = 0;
  if (!a || !load(s, a, &value)) return AGR_ANDROID_EINVAL;
  const uint32_t type = value & kType, shared = value & kShared;
  if (type != 0 && type != kRecursive && type != kErrorcheck) return AGR_ANDROID_EINVAL;
  if (type != 0 && (value & kState) != 0 && (value >> 16) == tid(s)) {
    if (type == kErrorcheck) return AGR_ANDROID_EDEADLK;
    if ((value & kCounter) == kCounter) return AGR_ANDROID_EAGAIN;
    bool won = false;
    do {
      if (!cas(s, a, value, value + kCounterOne, &won)) return AGR_ANDROID_EFAULT;
      if (won) return 0;
    } while (load(s, a, &value) && (value >> 16) == tid(s));
    return AGR_ANDROID_EBUSY;
  }
  bool won = false;
  const uint32_t self = type == 0 ? 0 : tid(s);
  if (type != 0 && !self) return AGR_ANDROID_EINVAL;
  if (!cas(s, a, shared | type,
           (self << 16) | shared | type | kUncontended, &won)) return AGR_ANDROID_EFAULT;
  return won ? 0 : AGR_ANDROID_EBUSY;
}

extern "C" int32_t agr_bionic_mutex_unlock(agr_bionic_sync *s, uint32_t a) {
  uint32_t value = 0;
  if (!a || !load(s, a, &value)) return AGR_ANDROID_EINVAL;
  const uint32_t type = value & kType, shared = value & kShared;
  if (type == 0) {
    uint32_t previous = 0;
    if (!s->fetch_sub || s->fetch_sub(s->opaque, a, 1, &previous) != 0) return AGR_ANDROID_EFAULT;
    if (previous != (shared | kUncontended)) {
      if (!store(s, a, shared)) return AGR_ANDROID_EFAULT;
      if (s->wake) s->wake(s->opaque, a, 1);
    }
    return 0;
  }
  if (type != kRecursive && type != kErrorcheck) return AGR_ANDROID_EINVAL;
  if ((value >> 16) != tid(s)) return AGR_ANDROID_EPERM;
  if (value & kCounter) {
    for (;;) {
      bool won = false;
      if (!cas(s, a, value, value - kCounterOne, &won)) return AGR_ANDROID_EFAULT;
      if (won) return 0;
      if (!load(s, a, &value)) return AGR_ANDROID_EFAULT;
    }
  }
  uint32_t previous = 0;
  if (!exchange(s, a, type | shared, &previous)) return AGR_ANDROID_EFAULT;
  if ((previous & kState) == kContended && s->wake) s->wake(s->opaque, a, 1);
  return 0;
}

extern "C" int32_t agr_bionic_mutex_destroy(agr_bionic_sync *s, uint32_t a) {
  const int32_t result = agr_bionic_mutex_trylock(s, a);
  if (result != 0) return result;
  return store(s, a, 0xdead10ccu) ? 0 : AGR_ANDROID_EFAULT;
}

extern "C" int32_t agr_bionic_cond_init(agr_bionic_sync *s, uint32_t a,
                                           int32_t shared) {
  if (!a || (shared != 0 && shared != 1)) return AGR_ANDROID_EINVAL;
  return store(s, a, static_cast<uint32_t>(shared)) ? 0 : AGR_ANDROID_EFAULT;
}
extern "C" int32_t agr_bionic_cond_destroy(agr_bionic_sync *s, uint32_t a) {
  if (!a) return AGR_ANDROID_EINVAL;
  return store(s, a, 0xdeadc04du) ? 0 : AGR_ANDROID_EFAULT;
}

static int32_t pulse(agr_bionic_sync *s, uint32_t a, uint32_t count) {
  uint32_t old = 0;
  if (!a || !load(s, a, &old)) return AGR_ANDROID_EINVAL;
  for (;;) {
    const uint32_t next = ((old - 2u) & ~1u) | (old & 1u);
    bool won = false;
    if (!cas(s, a, old, next, &won)) return AGR_ANDROID_EFAULT;
    if (won) break;
    if (!load(s, a, &old)) return AGR_ANDROID_EFAULT;
  }
  if (s->wake) s->wake(s->opaque, a, count);
  return 0;
}
extern "C" int32_t agr_bionic_cond_signal(agr_bionic_sync *s, uint32_t a) {
  return pulse(s, a, 1);
}
extern "C" int32_t agr_bionic_cond_broadcast(agr_bionic_sync *s, uint32_t a) {
  return pulse(s, a, INT_MAX);
}
extern "C" int32_t agr_bionic_cond_wait_relative(agr_bionic_sync *s,
                                                    uint32_t cond, uint32_t mutex,
                                                    uint64_t timeout_ns) {
  uint32_t old = 0;
  if (!cond || !mutex || !load(s, cond, &old)) return AGR_ANDROID_EINVAL;
  int32_t rc = agr_bionic_mutex_unlock(s, mutex);
  if (rc != 0) return rc;
  const int32_t waited = s->wait ? s->wait(s->opaque, cond, old, timeout_ns) : -AGR_ANDROID_ENOSYS;
  rc = agr_bionic_mutex_lock(s, mutex);
  if (rc != 0) return rc;
  if (waited == -AGR_ANDROID_ETIMEDOUT) return AGR_ANDROID_ETIMEDOUT;
  if (waited < 0 && waited != -AGR_ANDROID_EAGAIN && waited != -AGR_ANDROID_EINTR) return -waited;
  return 0;
}

/* pthread_once from KitKat pthread.c: 0 -> INITIALIZING(1) -> COMPLETED(2),
 * with futex waiters and release publication before waking all. */
extern "C" int32_t agr_bionic_once(agr_bionic_sync *s, uint32_t control,
                                     uint32_t init_function) {
  if (!control || !s || !s->invoke_once) return AGR_ANDROID_EINVAL;
  for (;;) {
    uint32_t old = 0;
    if (!load(s, control, &old)) return AGR_ANDROID_EFAULT;
    if (old & 2u) return 0;
    bool won = false;
    if (!cas(s, control, old, old | 1u, &won)) return AGR_ANDROID_EFAULT;
    if (!won) continue;
    if (!(old & 1u)) break;
    if (!s->wait) return AGR_ANDROID_ENOSYS;
    const int32_t waited = s->wait(s->opaque, control, old | 1u, UINT64_MAX);
    if (waited < 0 && waited != -AGR_ANDROID_EAGAIN && waited != -AGR_ANDROID_EINTR) return -waited;
  }
  int32_t rc = s->invoke_once(s->opaque, init_function);
  if (rc != 0) {
    /* KitKat documents exceptions/fork during init as unsupported. Do not
     * report success or strand other callers if the guest callback fails. */
    store(s, control, 0);
    if (s->wake) s->wake(s->opaque, control, INT_MAX);
    return rc;
  }
  if (!store(s, control, 2u)) return AGR_ANDROID_EFAULT;
  if (s->wake) s->wake(s->opaque, control, INT_MAX);
  return 0;
}
