#include "../Runtime/Bionic/agr_bionic_errno.h"
#include "../Runtime/Bionic/agr_bionic_errno_host.h"

#include <cassert>
#include <cerrno>

int main() {
  assert(agr_bionic_errno_from_host(0) == 0);
  assert(agr_bionic_errno_from_host(EINVAL) == AGR_ANDROID_EINVAL);
  assert(agr_bionic_errno_from_host(EDEADLK) == AGR_ANDROID_EDEADLK);
  assert(agr_bionic_errno_from_host(ETIMEDOUT) == AGR_ANDROID_ETIMEDOUT);
  assert(agr_bionic_errno_from_host(ENOSYS) == AGR_ANDROID_ENOSYS);
  assert(agr_bionic_errno_from_host(99999) == AGR_ANDROID_EIO);
}
