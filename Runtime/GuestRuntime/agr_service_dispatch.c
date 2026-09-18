#include "agr_service_dispatch.h"

#include <string.h>

/* CurrentThreadDirect is already executable.  The other affinities are
 * registered now so worker calls cannot silently fall back to global state. */
static const agr_service_descriptor services[] = {
    {"pthread_create", AGR_SERVICE_CURRENT_THREAD_DIRECT, 0, AGR_SERVICE_NON_REENTRANT, AGR_SERVICE_MEMORY_SYNC_BORROWED, AGR_SERVICE_LOCK_PROCESS},
    {"pthread_join", AGR_SERVICE_CURRENT_THREAD_DIRECT, 1, AGR_SERVICE_NON_REENTRANT, AGR_SERVICE_MEMORY_SYNC_BORROWED, AGR_SERVICE_LOCK_PROCESS},
    {"pthread_detach", AGR_SERVICE_CURRENT_THREAD_DIRECT, 0, AGR_SERVICE_NON_REENTRANT, AGR_SERVICE_MEMORY_NONE, AGR_SERVICE_LOCK_PROCESS},
    {"pthread_setspecific", AGR_SERVICE_CURRENT_THREAD_DIRECT, 0, AGR_SERVICE_NON_REENTRANT, AGR_SERVICE_MEMORY_NONE, AGR_SERVICE_LOCK_PROCESS},
    {"pthread_getspecific", AGR_SERVICE_CURRENT_THREAD_DIRECT, 0, AGR_SERVICE_NON_REENTRANT, AGR_SERVICE_MEMORY_NONE, AGR_SERVICE_LOCK_PROCESS},
    {"eglMakeCurrent", AGR_SERVICE_EGL_CONTEXT_OWNER, 0, AGR_SERVICE_NON_REENTRANT, AGR_SERVICE_MEMORY_NONE, AGR_SERVICE_LOCK_EGL_OBJECT},
    {"ANativeActivity_onCreate", AGR_SERVICE_ANDROID_LOOPER_OWNER, 0, AGR_SERVICE_NON_REENTRANT, AGR_SERVICE_MEMORY_COPY_IN_OUT, AGR_SERVICE_LOCK_PROCESS},
    {"UIKitWindowMutation", AGR_SERVICE_IOS_MAIN_THREAD, 0, AGR_SERVICE_NON_REENTRANT, AGR_SERVICE_MEMORY_NONE, AGR_SERVICE_LOCK_NONE},
};

const agr_service_descriptor *agr_service_descriptor_lookup(const char *name) {
    if (!name) return NULL;
    for (uint32_t i = 0; i < sizeof(services) / sizeof(services[0]); ++i)
        if (!strcmp(name, services[i].name)) return &services[i];
    return NULL;
}
