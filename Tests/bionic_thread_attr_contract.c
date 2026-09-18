#include "../Runtime/Bionic/agr_bionic_thread_attr.h"
#include "../Runtime/Bionic/agr_bionic_errno.h"

#include <assert.h>
#include <stdint.h>

int main(void) {
  agr_bionic_thread_attr attr;
  assert(agr_bionic_thread_attr_init(&attr) == 0);
  assert(sizeof(attr) == 24);
  assert(attr.stack_size == 1040384u && attr.guard_size == 4096u);
  agr_bionic_thread_stack_layout layout;
  assert(agr_bionic_thread_compute_stack_layout(&attr, 0x10000000u, &layout) == 0);
  assert(layout.size == 1040384u && layout.guard_size == 4096u);
  assert(layout.tls_base == 0x10000000u + 1040384u - 560u);
  assert(layout.initial_sp == layout.tls_base && layout.user_stack == 0);
  assert(agr_bionic_thread_attr_setdetachstate(&attr, 1) == 0);
  assert((attr.flags & 1u) == 1u);
  assert(agr_bionic_thread_attr_setstacksize(&attr, 8191) == AGR_ANDROID_EINVAL);
  assert(agr_bionic_thread_attr_setstacksize(&attr, 10000) == 0);
  assert(agr_bionic_thread_compute_stack_layout(&attr, 0x20000000u, &layout) == 0);
  assert(layout.size == 12288u);
  assert(agr_bionic_thread_attr_setstack(&attr, 0x30001000u, 16384) == 0);
  assert(agr_bionic_thread_compute_stack_layout(&attr, 0, &layout) == 0);
  assert(layout.base == 0x30001000u && layout.user_stack == 1);
  assert(agr_bionic_thread_attr_setguardsize(&attr, 5000) == 0);
  assert(agr_bionic_thread_compute_stack_layout(&attr, 0, &layout) == 0);
  assert(layout.guard_size == 8192u);
  assert(agr_bionic_thread_attr_setstack(&attr, 0x30001001u, 16384) == AGR_ANDROID_EINVAL);
  assert(agr_bionic_thread_attr_destroy(&attr) == 0);
  return 0;
}
