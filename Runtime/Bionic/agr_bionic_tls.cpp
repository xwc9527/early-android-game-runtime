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
 * Source port of android-4.4.4_r2 libc/bionic/pthread_key.cpp and
 * libc/private/bionic_tls.h. Guest 32-bit TLS slots replace native pointers;
 * the bitmap, first-free key reuse, key deletion across live threads, and
 * four-pass destructor control flow remain from Bionic.
 */
#include "agr_bionic_tls.h"
#include "agr_bionic_errno.h"

#include <array>
#include <mutex>
#include <new>
#include <unordered_map>

struct agr_bionic_tls {
  struct thread { uint32_t base; };
  void *opaque;
  agr_bionic_tls_read read;
  agr_bionic_tls_write write;
  agr_bionic_tls_invoke invoke;
  std::mutex lock;
  std::array<bool, AGR_BIONIC_TLS_SLOTS> allocated{};
  std::array<uint32_t, AGR_BIONIC_TLS_SLOTS> destructors{};
  std::unordered_map<uint32_t, thread> threads;
};

static uint32_t slot(uint32_t base, uint32_t key) { return base + key * 4u; }

extern "C" agr_bionic_tls *agr_bionic_tls_create(void *opaque,
    agr_bionic_tls_read read, agr_bionic_tls_write write,
    agr_bionic_tls_invoke invoke) {
  if (!read || !write || !invoke) return nullptr;
  auto *tls = new (std::nothrow) agr_bionic_tls;
  if (tls) { tls->opaque = opaque; tls->read = read;
             tls->write = write; tls->invoke = invoke; }
  return tls;
}
extern "C" void agr_bionic_tls_destroy(agr_bionic_tls *tls) { delete tls; }

extern "C" int32_t agr_bionic_tls_register_thread(agr_bionic_tls *tls,
    uint32_t tid, uint32_t base, uint32_t descriptor) {
  if (!tls || !tid || !base || (base & 3u) || base > UINT32_MAX - 560u)
    return AGR_ANDROID_EINVAL;
  std::lock_guard<std::mutex> guard(tls->lock);
  if (tls->threads.count(tid)) return AGR_ANDROID_EEXIST;
  for (uint32_t key = 0; key < AGR_BIONIC_TLS_SLOTS; ++key)
    if (tls->write(tls->opaque, slot(base, key), 0) != 0) return AGR_ANDROID_EFAULT;
  if (tls->write(tls->opaque, slot(base, 0), base) != 0 ||
      tls->write(tls->opaque, slot(base, 1), descriptor) != 0) return AGR_ANDROID_EFAULT;
  try { tls->threads.emplace(tid, agr_bionic_tls::thread{base}); }
  catch (const std::bad_alloc &) { return AGR_ANDROID_ENOMEM; }
  return 0;
}

extern "C" int32_t agr_bionic_tls_key_create(agr_bionic_tls *tls,
    uint32_t destructor, uint32_t *key) {
  if (!tls || !key) return AGR_ANDROID_EINVAL;
  std::lock_guard<std::mutex> guard(tls->lock);
  for (uint32_t i = AGR_BIONIC_TLS_FIRST_USER_SLOT; i < AGR_BIONIC_TLS_SLOTS; ++i)
    if (!tls->allocated[i]) {
      tls->allocated[i] = true; tls->destructors[i] = destructor;
      *key = i; return 0;
    }
  return AGR_ANDROID_EAGAIN;
}

extern "C" int32_t agr_bionic_tls_key_delete(agr_bionic_tls *tls,
    uint32_t key) {
  if (!tls || key < AGR_BIONIC_TLS_FIRST_USER_SLOT ||
      key >= AGR_BIONIC_TLS_SLOTS) return AGR_ANDROID_EINVAL;
  std::lock_guard<std::mutex> guard(tls->lock);
  if (!tls->allocated[key]) return AGR_ANDROID_EINVAL;
  for (auto &entry : tls->threads)
    if (tls->write(tls->opaque, slot(entry.second.base, key), 0) != 0)
      return AGR_ANDROID_EFAULT;
  tls->allocated[key] = false; tls->destructors[key] = 0;
  return 0;
}

extern "C" int32_t agr_bionic_tls_setspecific(agr_bionic_tls *tls,
    uint32_t tid, uint32_t key, uint32_t value) {
  if (!tls || key < AGR_BIONIC_TLS_FIRST_USER_SLOT ||
      key >= AGR_BIONIC_TLS_SLOTS) return AGR_ANDROID_EINVAL;
  std::lock_guard<std::mutex> guard(tls->lock);
  auto it = tls->threads.find(tid);
  if (it == tls->threads.end() || !tls->allocated[key]) return AGR_ANDROID_EINVAL;
  return tls->write(tls->opaque, slot(it->second.base, key), value) == 0 ? 0 : AGR_ANDROID_EFAULT;
}

extern "C" int32_t agr_bionic_tls_getspecific(agr_bionic_tls *tls,
    uint32_t tid, uint32_t key, uint32_t *value) {
  if (!tls || !value) return AGR_ANDROID_EINVAL;
  *value = 0;
  if (key < AGR_BIONIC_TLS_FIRST_USER_SLOT || key >= AGR_BIONIC_TLS_SLOTS)
    return 0; // Bionic pthread_getspecific returns NULL for invalid keys.
  std::lock_guard<std::mutex> guard(tls->lock);
  auto it = tls->threads.find(tid);
  if (it == tls->threads.end()) return AGR_ANDROID_ESRCH;
  return tls->read(tls->opaque, slot(it->second.base, key), value) == 0 ? 0 : AGR_ANDROID_EFAULT;
}

extern "C" uint32_t agr_bionic_tls_errno_address(agr_bionic_tls *tls,
    uint32_t tid) {
  if (!tls) return 0;
  std::lock_guard<std::mutex> guard(tls->lock);
  auto it = tls->threads.find(tid);
  return it == tls->threads.end() ? 0 : slot(it->second.base, AGR_BIONIC_TLS_ERRNO_SLOT);
}

extern "C" int32_t agr_bionic_tls_errno_read(agr_bionic_tls *tls,
    uint32_t tid, uint32_t *value) {
  if (!tls || !value) return AGR_ANDROID_EINVAL;
  std::lock_guard<std::mutex> guard(tls->lock);
  auto it = tls->threads.find(tid);
  if (it == tls->threads.end()) return AGR_ANDROID_ESRCH;
  return tls->read(tls->opaque,
      slot(it->second.base, AGR_BIONIC_TLS_ERRNO_SLOT), value) == 0
      ? 0 : AGR_ANDROID_EFAULT;
}

extern "C" int32_t agr_bionic_tls_errno_write(agr_bionic_tls *tls,
    uint32_t tid, uint32_t value) {
  if (!tls) return AGR_ANDROID_EINVAL;
  std::lock_guard<std::mutex> guard(tls->lock);
  auto it = tls->threads.find(tid);
  if (it == tls->threads.end()) return AGR_ANDROID_ESRCH;
  return tls->write(tls->opaque,
      slot(it->second.base, AGR_BIONIC_TLS_ERRNO_SLOT), value) == 0
      ? 0 : AGR_ANDROID_EFAULT;
}

extern "C" int32_t agr_bionic_tls_cleanup_thread(agr_bionic_tls *tls,
    uint32_t tid) {
  if (!tls) return AGR_ANDROID_EINVAL;
  std::unique_lock<std::mutex> guard(tls->lock);
  auto it = tls->threads.find(tid);
  if (it == tls->threads.end()) return AGR_ANDROID_ESRCH;
  const uint32_t base = it->second.base;
  // pthread_key.cpp ScopedTlsMapAccess::CleanAll: clear the value before
  // invoking, unlock around guest code, and repeat up to four passes.
  for (int round = 0; round < 4; ++round) {
    uint32_t called = 0;
    for (uint32_t key = AGR_BIONIC_TLS_FIRST_USER_SLOT;
         key < AGR_BIONIC_TLS_SLOTS; ++key) {
      if (!tls->allocated[key] || !tls->destructors[key]) continue;
      uint32_t value = 0;
      if (tls->read(tls->opaque, slot(base, key), &value) != 0) return AGR_ANDROID_EFAULT;
      if (!value) continue;
      if (tls->write(tls->opaque, slot(base, key), 0) != 0) return AGR_ANDROID_EFAULT;
      uint32_t destructor = tls->destructors[key];
      guard.unlock();
      int32_t rc = tls->invoke(tls->opaque, tid, destructor, value);
      guard.lock();
      if (rc) return rc;
      ++called;
    }
    if (!called) break;
  }
  return 0;
}

extern "C" int32_t agr_bionic_tls_unregister_thread(agr_bionic_tls *tls,
    uint32_t tid) {
  if (!tls) return AGR_ANDROID_EINVAL;
  std::lock_guard<std::mutex> guard(tls->lock);
  return tls->threads.erase(tid) ? 0 : AGR_ANDROID_ESRCH;
}
