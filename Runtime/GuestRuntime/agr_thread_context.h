#ifndef AGR_THREAD_CONTEXT_H
#define AGR_THREAD_CONTEXT_H

#include <stdint.h>

typedef struct agr_process_runtime agr_process_runtime;
typedef struct agr_guest_thread_context agr_guest_thread_context;

typedef enum agr_guest_thread_lifecycle {
    AGR_GUEST_THREAD_RUNNING = 1,
    AGR_GUEST_THREAD_NATIVE_WAIT = 2,
    AGR_GUEST_THREAD_VM_WAIT = 3,
    AGR_GUEST_THREAD_EXITED = 4,
} agr_guest_thread_lifecycle;

typedef struct agr_thread_recent_call {
    const char *name;
    uint32_t pc;
} agr_thread_recent_call;

struct agr_guest_thread_context {
    agr_process_runtime *process;
    void *cpu;
    uintptr_t host_thread_identity;
    uint32_t guest_thread_id;
    uint32_t pthread_handle;
    uint32_t guest_stack_base;
    uint32_t guest_stack_size;
    uint32_t guest_tls_base;
    uint32_t guest_errno_address;
    uint32_t current_guest_pc;
    uint32_t callback_depth;
    uint32_t exit_result;
    uint32_t tls_destructor_active;
    uint32_t jni_env_handle;
    uint32_t jni_local_frame_depth;
    uint32_t jni_dispatch_depth;
    agr_guest_thread_lifecycle lifecycle;
    agr_thread_recent_call recent_calls[32];
    uint32_t recent_call_index;
    struct agr_guest_thread_context *next;
};

agr_guest_thread_context *agr_guest_thread_context_create(
    agr_process_runtime *process, void *parent_cpu, uint32_t guest_thread_id,
    uint32_t stack_base, uint32_t stack_size, uint32_t tls_base);
agr_guest_thread_context *agr_guest_thread_context_create_main(
    agr_process_runtime *process, void *cpu, uint32_t guest_thread_id,
    uint32_t stack_base, uint32_t stack_size, uint32_t tls_base);
void agr_guest_thread_context_destroy(agr_guest_thread_context *context);
void agr_guest_thread_context_bind(agr_guest_thread_context *context);
agr_guest_thread_context *agr_guest_thread_context_current(void);
void agr_guest_thread_context_record_call(agr_guest_thread_context *context,
                                          const char *name, uint32_t pc);
void agr_process_runtime_register_thread(agr_process_runtime *process,
                                         agr_guest_thread_context *context);
void agr_process_runtime_unregister_thread(agr_process_runtime *process,
                                           agr_guest_thread_context *context);

#endif
