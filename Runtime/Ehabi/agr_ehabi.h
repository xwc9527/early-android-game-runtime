#ifndef AGR_EHABI_H
#define AGR_EHABI_H

#include <stdint.h>
#include "../GuestRuntime/agr_thread_context.h"
#include "../NativeCore/agr_runtime.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Formal ARM EHABI Phase 1 unwind context. Register, stack, Thumb state and
 * return addresses are guest-visible ARM32 values. The context is snapshotted
 * from GuestThreadContext; it does not replace it.
 */
typedef enum agr_ehabi_stop {
    AGR_EHABI_OK = 0,
    AGR_EHABI_CANTUNWIND = 1,
    AGR_EHABI_NO_MODULE = 2,
    AGR_EHABI_INVALID_PC = 3,
    AGR_EHABI_UNSUPPORTED_ENCODING = 4,
    AGR_EHABI_FAILURE = 5
} agr_ehabi_stop;

#define AGR_EXIDX_CANTUNWIND 1u
#define EXIDX_CANTUNWIND AGR_EXIDX_CANTUNWIND

typedef struct agr_guest_unwind_context {
    agr_guest_thread_context *thread; /* snapshot source; not replaced */
    uint32_t r[16]; /* r0-r15; SP=r[13], LR=r[14], PC=r[15] */
    uint32_t cpsr; /* CPSR_T (bit 5) is ARM/Thumb execution state */
    uint32_t stack_base;
    uint32_t stack_size;
    char dso_name[64];
    uint32_t dso_load_start;
    uint32_t dso_load_size;
    uint32_t relative_pc;
    uint32_t exidx_entry;
    uint32_t exidx_insn;
    uint32_t fnstart;
    uint64_t vfp_d[32];
    agr_ehabi_stop stop;
    char stop_detail[96];
} agr_guest_unwind_context;

typedef struct agr_guest_unwind_frame {
    char dso[64];
    uint32_t relative_pc;
    uint32_t sp;
    uint32_t lr;
    uint32_t thumb;
} agr_guest_unwind_frame;

typedef struct agr_ehabi_env {
    void *opaque;
    int32_t (*read)(void *opaque, uint32_t address, void *data, uint32_t size);
    int32_t (*find_module)(void *opaque, uint32_t pc, agr_module_info *out);
} agr_ehabi_env;

void agr_ehabi_context_init(agr_guest_unwind_context *ctx,
                            agr_guest_thread_context *thread,
                            const uint32_t regs[16], uint32_t cpsr,
                            uint32_t stack_base, uint32_t stack_size);
void agr_ehabi_context_begin_backtrace(agr_guest_unwind_context *ctx);
int32_t agr_ehabi_unwind_step(agr_guest_unwind_context *ctx,
                              const agr_ehabi_env *env);
int32_t agr_ehabi_backtrace(agr_guest_unwind_context *ctx,
                            const agr_ehabi_env *env,
                            agr_guest_unwind_frame *frames, uint32_t max_frames,
                            uint32_t *count);
const char *agr_ehabi_stop_name(agr_ehabi_stop stop);

/* Runtime-backed env using formal linker metadata and guest memory callbacks. */
void agr_ehabi_env_from_runtime(agr_ehabi_env *env, agr_runtime *runtime);
int32_t agr_ehabi_backtrace_runtime(agr_runtime *runtime,
                                    agr_guest_unwind_context *ctx,
                                    agr_guest_unwind_frame *frames,
                                    uint32_t max_frames, uint32_t *count);

#ifdef __cplusplus
}
#endif
#endif
