#ifndef AGR_SERVICE_DISPATCH_H
#define AGR_SERVICE_DISPATCH_H

#include <stdint.h>

typedef enum agr_service_affinity {
    AGR_SERVICE_CURRENT_THREAD_DIRECT = 1,
    AGR_SERVICE_EGL_CONTEXT_OWNER = 2,
    AGR_SERVICE_ANDROID_LOOPER_OWNER = 3,
    AGR_SERVICE_IOS_MAIN_THREAD = 4,
} agr_service_affinity;

typedef enum agr_service_reentrancy {
    AGR_SERVICE_NON_REENTRANT = 0,
    AGR_SERVICE_SAME_THREAD_REENTRANT = 1,
} agr_service_reentrancy;

typedef enum agr_service_memory_policy {
    AGR_SERVICE_MEMORY_NONE = 0,
    AGR_SERVICE_MEMORY_SYNC_BORROWED = 1,
    AGR_SERVICE_MEMORY_COPY_IN_OUT = 2,
} agr_service_memory_policy;

typedef enum agr_service_lock_class {
    AGR_SERVICE_LOCK_NONE = 0,
    AGR_SERVICE_LOCK_PROCESS = 1,
    AGR_SERVICE_LOCK_RESOURCE = 2,
    AGR_SERVICE_LOCK_EGL_OBJECT = 3,
} agr_service_lock_class;

typedef struct agr_service_descriptor {
    const char *name;
    agr_service_affinity affinity;
    uint32_t may_block;
    agr_service_reentrancy reentrancy;
    agr_service_memory_policy memory_policy;
    agr_service_lock_class lock_class;
} agr_service_descriptor;

const agr_service_descriptor *agr_service_descriptor_lookup(const char *name);

#endif
