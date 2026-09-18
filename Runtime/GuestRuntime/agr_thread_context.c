#include "agr_thread_context.h"

#include <stdlib.h>
#if defined(__APPLE__)
#include "../HostServices/agr_host_services.h"
#include <pthread.h>
#else
static _Thread_local agr_guest_thread_context *current_context;
#endif

static uintptr_t current_host_thread_identity(void) {
#if defined(__APPLE__)
    return (uintptr_t)pthread_self();
#else
    return 0;
#endif
}

extern void *arm_interp_create_thread(void *parent);
extern void arm_interp_destroy(void *cpu);

agr_guest_thread_context *agr_guest_thread_context_create(
    agr_process_runtime *process, void *parent_cpu, uint32_t guest_thread_id,
    uint32_t stack_base, uint32_t stack_size, uint32_t tls_base) {
    if (!process || !guest_thread_id) return NULL;
    agr_guest_thread_context *context = calloc(1, sizeof(*context));
    if (!context) return NULL;
    context->cpu = parent_cpu ? arm_interp_create_thread(parent_cpu) : NULL;
    if (parent_cpu && !context->cpu) { free(context); return NULL; }
    context->process = process;
    context->host_thread_identity = current_host_thread_identity();
    context->guest_thread_id = guest_thread_id;
    context->guest_stack_base = stack_base;
    context->guest_stack_size = stack_size;
    context->guest_tls_base = tls_base;
    context->lifecycle = AGR_GUEST_THREAD_RUNNING;
    agr_process_runtime_register_thread(process,context);
    return context;
}

agr_guest_thread_context *agr_guest_thread_context_create_main(
    agr_process_runtime *process, void *cpu, uint32_t guest_thread_id,
    uint32_t stack_base, uint32_t stack_size, uint32_t tls_base) {
    if (!process || !cpu || !guest_thread_id) return NULL;
    agr_guest_thread_context *context = calloc(1, sizeof(*context));
    if (!context) return NULL;
    context->process = process;
    context->host_thread_identity = current_host_thread_identity();
    context->cpu = cpu;
    context->guest_thread_id = guest_thread_id;
    context->guest_stack_base = stack_base;
    context->guest_stack_size = stack_size;
    context->guest_tls_base = tls_base;
    context->lifecycle = AGR_GUEST_THREAD_RUNNING;
    agr_process_runtime_register_thread(process,context);
    return context;
}

void agr_guest_thread_context_destroy(agr_guest_thread_context *context) {
    if (!context) return;
    if (agr_guest_thread_context_current() == context)
        agr_guest_thread_context_bind(NULL);
    agr_process_runtime_unregister_thread(context->process,context);
    /* The process entry CPU is owned by ProcessRuntime. Workers own clones. */
    if (context->cpu && context->guest_thread_id != 1u) arm_interp_destroy(context->cpu);
    free(context);
}

void agr_guest_thread_context_bind(agr_guest_thread_context *context) {
    if (context) context->host_thread_identity=current_host_thread_identity();
#if defined(__APPLE__)
    agr_host_services_bind_current_guest(context);
#else
    current_context = context;
#endif
}

agr_guest_thread_context *agr_guest_thread_context_current(void) {
#if defined(__APPLE__)
    return (agr_guest_thread_context *)agr_host_services_current_guest();
#else
    return current_context;
#endif
}

void agr_guest_thread_context_record_call(agr_guest_thread_context *context,
                                          const char *name, uint32_t pc) {
    if (!context) return;
    uint32_t index = context->recent_call_index++ % 32u;
    context->recent_calls[index] = (agr_thread_recent_call){name, pc};
    context->current_guest_pc = pc;
}
