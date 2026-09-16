#ifndef AGR_ANDROIDFW_HOST_COMPAT_H
#define AGR_ANDROIDFW_HOST_COMPAT_H

#include <stdint.h>

#ifdef _WIN32
extern "C" intptr_t agr_duplicate_osfhandle(int fd);
#define _get_osfhandle agr_duplicate_osfhandle
#endif

#endif
