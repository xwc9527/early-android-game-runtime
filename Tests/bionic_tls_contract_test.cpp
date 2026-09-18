#include "../Runtime/Bionic/agr_bionic_tls.h"
#include "../Runtime/Bionic/agr_bionic_errno.h"

#include <array>
#include <cassert>
#include <cstdint>

struct fixture {
  std::array<uint32_t, AGR_BIONIC_TLS_SLOTS> first{};
  std::array<uint32_t, AGR_BIONIC_TLS_SLOTS> second{};
  agr_bionic_tls *tls = nullptr;
  uint32_t key = 0, destructor_calls = 0;
};
static uint32_t *slot(fixture *f, uint32_t address) {
  if (address >= 0x1000 && address < 0x1000 + 4 * AGR_BIONIC_TLS_SLOTS && !(address & 3))
    return &f->first[(address - 0x1000) / 4];
  if (address >= 0x2000 && address < 0x2000 + 4 * AGR_BIONIC_TLS_SLOTS && !(address & 3))
    return &f->second[(address - 0x2000) / 4];
  return nullptr;
}
static int32_t read(void *opaque, uint32_t address, uint32_t *value) {
  auto *word = slot(static_cast<fixture *>(opaque), address);
  if (!word) return -1;
  *value = *word; return 0;
}
static int32_t write(void *opaque, uint32_t address, uint32_t value) {
  auto *word = slot(static_cast<fixture *>(opaque), address);
  if (!word) return -1;
  *word = value; return 0;
}
static int32_t invoke(void *opaque, uint32_t tid, uint32_t destructor,
                       uint32_t value) {
  auto *f = static_cast<fixture *>(opaque);
  assert(tid == 1 && destructor == 0x9000 && value == 0x1234);
  ++f->destructor_calls;
  if (f->destructor_calls == 1)
    assert(agr_bionic_tls_setspecific(f->tls, tid, f->key, value) == 0);
  return 0;
}
int main() {
  fixture f;
  f.tls = agr_bionic_tls_create(&f, read, write, invoke);
  assert(f.tls);
  assert(agr_bionic_tls_register_thread(f.tls, 1, 0x1000, 0x3000) == 0);
  assert(agr_bionic_tls_register_thread(f.tls, 2, 0x2000, 0x4000) == 0);
  assert(f.first[0] == 0x1000 && f.second[1] == 0x4000);
  assert(agr_bionic_tls_errno_address(f.tls, 1) == 0x1008);
  assert(agr_bionic_tls_errno_address(f.tls, 2) == 0x2008);
  f.first[2] = 11; f.second[2] = 22;
  assert(f.first[2] != f.second[2]);
  uint32_t first_errno = 0, second_errno = 0;
  assert(agr_bionic_tls_errno_read(f.tls, 1, &first_errno) == 0 && first_errno == 11);
  assert(agr_bionic_tls_errno_read(f.tls, 2, &second_errno) == 0 && second_errno == 22);
  assert(agr_bionic_tls_errno_write(f.tls, 1, 35) == 0);
  assert(f.first[2] == 35 && f.second[2] == 22);
  assert(agr_bionic_tls_key_create(f.tls, 0, &f.key) == 0);
  assert(f.key == AGR_BIONIC_TLS_FIRST_APP_KEY);
  assert(agr_bionic_tls_setspecific(f.tls, 1, f.key, 111) == 0);
  assert(agr_bionic_tls_setspecific(f.tls, 2, f.key, 222) == 0);
  uint32_t value = 0;
  assert(agr_bionic_tls_getspecific(f.tls, 1, f.key, &value) == 0 && value == 111);
  assert(agr_bionic_tls_getspecific(f.tls, 2, f.key, &value) == 0 && value == 222);
  assert(agr_bionic_tls_key_delete(f.tls, f.key) == 0);
  assert(agr_bionic_tls_getspecific(f.tls, 1, f.key, &value) == 0 && value == 0);
  assert(agr_bionic_tls_getspecific(f.tls, 2, f.key, &value) == 0 && value == 0);
  assert(agr_bionic_tls_setspecific(f.tls, 1, f.key, 1) == AGR_ANDROID_EINVAL);
  for (uint32_t i = 0; i < 100000; ++i) {
    uint32_t cycle_key = 0;
    assert(agr_bionic_tls_key_create(f.tls, 0, &cycle_key) == 0);
    assert(cycle_key == f.key);
    assert(agr_bionic_tls_setspecific(f.tls, 1, cycle_key, i + 1) == 0);
    assert(agr_bionic_tls_key_delete(f.tls, cycle_key) == 0);
  }
  uint32_t reused = 0;
  assert(agr_bionic_tls_key_create(f.tls, 0x9000, &reused) == 0);
  assert(reused == f.key);
  assert(agr_bionic_tls_setspecific(f.tls, 1, f.key, 0x1234) == 0);
  assert(agr_bionic_tls_cleanup_thread(f.tls, 1) == 0);
  assert(f.destructor_calls == 2);
  assert(agr_bionic_tls_getspecific(f.tls, 1, f.key, &value) == 0 && value == 0);
  assert(agr_bionic_tls_unregister_thread(f.tls, 1) == 0);
  assert(agr_bionic_tls_unregister_thread(f.tls, 2) == 0);
  agr_bionic_tls_destroy(f.tls);
}
