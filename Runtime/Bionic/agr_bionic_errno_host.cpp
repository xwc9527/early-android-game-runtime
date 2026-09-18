#include "agr_bionic_errno_host.h"
#include "agr_bionic_errno.h"

#include <cerrno>

extern "C" int32_t agr_bionic_errno_from_host(int32_t value) {
  if (value == 0) return 0;
  if (value == EPERM) return AGR_ANDROID_EPERM;
  if (value == ESRCH) return AGR_ANDROID_ESRCH;
  if (value == EINTR) return AGR_ANDROID_EINTR;
  if (value == EAGAIN) return AGR_ANDROID_EAGAIN;
  if (value == ENOMEM) return AGR_ANDROID_ENOMEM;
  if (value == EFAULT) return AGR_ANDROID_EFAULT;
  if (value == EBUSY) return AGR_ANDROID_EBUSY;
  if (value == EEXIST) return AGR_ANDROID_EEXIST;
  if (value == EINVAL) return AGR_ANDROID_EINVAL;
  if (value == EDEADLK) return AGR_ANDROID_EDEADLK;
  if (value == ENOSYS) return AGR_ANDROID_ENOSYS;
  if (value == ETIMEDOUT) return AGR_ANDROID_ETIMEDOUT;
  return AGR_ANDROID_EIO; // Unknown host failure remains an error.
}
