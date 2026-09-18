#ifndef AGR_BIONIC_ERRNO_H
#define AGR_BIONIC_ERRNO_H

/* Guest-visible ARM32/API19 Linux errno values. These deliberately do not
 * depend on Darwin's <errno.h>, whose values differ (for example ETIMEDOUT).
 * Boundary adapters translate host errors before returning to Bionic code. */
enum {
  AGR_ANDROID_EPERM = 1,
  AGR_ANDROID_ESRCH = 3,
  AGR_ANDROID_EINTR = 4,
  AGR_ANDROID_EIO = 5,
  AGR_ANDROID_EAGAIN = 11,
  AGR_ANDROID_ENOMEM = 12,
  AGR_ANDROID_EFAULT = 14,
  AGR_ANDROID_EBUSY = 16,
  AGR_ANDROID_EEXIST = 17,
  AGR_ANDROID_EINVAL = 22,
  AGR_ANDROID_EDEADLK = 35,
  AGR_ANDROID_ENOSYS = 38,
  AGR_ANDROID_ETIMEDOUT = 110,
  AGR_ANDROID_ECANCELED = 125,
};

#endif
