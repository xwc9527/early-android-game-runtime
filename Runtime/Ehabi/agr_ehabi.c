/*
 * HOST-NATIVE implementation of GCC 4.8 ARM EHABI unwind, operating only on
 * 32-bit guest registers, guest memory, formal linker DSO metadata and guest
 * stack bounds. See SOURCE_PORT.md.
 */
#include "agr_ehabi.h"

#include <stddef.h>
#include <stdio.h>
#include <string.h>

enum { R_SP = 13, R_LR = 14, R_PC = 15 };
#define CPSR_T 0x20u

static void set_stop(agr_guest_unwind_context *ctx, agr_ehabi_stop stop, const char *detail) {
    ctx->stop = stop;
    snprintf(ctx->stop_detail, sizeof(ctx->stop_detail), "%s", detail ? detail : "");
}

const char *agr_ehabi_stop_name(agr_ehabi_stop stop) {
    switch (stop) {
        case AGR_EHABI_OK: return "ok";
        case AGR_EHABI_CANTUNWIND: return "cantunwind";
        case AGR_EHABI_NO_MODULE: return "no_module";
        case AGR_EHABI_INVALID_PC: return "invalid_pc";
        case AGR_EHABI_UNSUPPORTED_ENCODING: return "unsupported_encoding";
        case AGR_EHABI_FAILURE: return "failure";
        default: return "failure";
    }
}

void agr_ehabi_context_init(agr_guest_unwind_context *ctx, agr_guest_thread_context *thread,
                            const uint32_t regs[16], uint32_t cpsr,
                            uint32_t stack_base, uint32_t stack_size) {
    memset(ctx, 0, sizeof(*ctx));
    ctx->thread = thread;
    memcpy(ctx->r, regs, sizeof(ctx->r));
    ctx->cpsr = cpsr;
    ctx->stack_base = thread && thread->guest_stack_size ? thread->guest_stack_base : stack_base;
    ctx->stack_size = thread && thread->guest_stack_size ? thread->guest_stack_size : stack_size;
    ctx->stop = AGR_EHABI_OK;
}

void agr_ehabi_context_begin_backtrace(agr_guest_unwind_context *ctx) {
    /* GCC __gnu_Unwind_Backtrace: VRS_PC = VRS_RETURN before the first frame. */
    ctx->r[R_PC] = ctx->r[R_LR];
    if (ctx->r[R_PC] & 1u) ctx->cpsr |= CPSR_T;
    else ctx->cpsr &= ~CPSR_T;
}

static int read_u32(const agr_ehabi_env *env, uint32_t address, uint32_t *out) {
    return env->read(env->opaque, address, out, 4);
}

static int stack_ok(const agr_guest_unwind_context *ctx, uint32_t address, uint32_t size) {
    uint32_t base = ctx->stack_base, limit;
    if (!ctx->stack_size) return 1;
    if (address < base) return 0;
    limit = base + ctx->stack_size;
    return address <= limit && size <= limit - address;
}

static int prel31(const agr_ehabi_env *env, uint32_t address, uint32_t *out) {
    uint32_t offset = 0;
    if (read_u32(env, address, &offset)) return -1;
    if (offset & (1u << 30)) offset |= 1u << 31;
    else offset &= ~(1u << 31);
    *out = offset + address;
    return 0;
}

static void apply_thumb_from_pc(agr_guest_unwind_context *ctx) {
    if (ctx->r[R_PC] & 1u) ctx->cpsr |= CPSR_T;
    else ctx->cpsr &= ~CPSR_T;
}

static int bind_module(agr_guest_unwind_context *ctx, const agr_module_info *module) {
    snprintf(ctx->dso_name, sizeof(ctx->dso_name), "%s", module->name ? module->name : "");
    ctx->dso_load_start = module->load_start;
    ctx->dso_load_size = module->load_size;
    ctx->relative_pc = (ctx->r[R_PC] & ~1u) - module->load_start;
    return 0;
}

static int search_exidx(const agr_ehabi_env *env, uint32_t table, int nrec,
                        uint32_t return_address, uint32_t *entry_out) {
    int left = 0, right = nrec - 1;
    if (nrec <= 0) return -1;
    for (;;) {
        int n;
        if (left > right) return -1;
        n = (left + right) / 2;
        uint32_t this_fn = 0, next_fn = 0xffffffffu;
        if (prel31(env, table + (uint32_t)n * 8u, &this_fn)) return -1;
        if (n != nrec - 1) {
            if (prel31(env, table + (uint32_t)(n + 1) * 8u, &next_fn)) return -1;
            next_fn -= 1u;
        }
        if (return_address < this_fn) {
            if (n == left) return -1;
            right = n - 1;
        } else if (return_address <= next_fn) {
            *entry_out = table + (uint32_t)n * 8u;
            return 0;
        } else {
            left = n + 1;
        }
    }
}

typedef struct {
    uint32_t data;
    uint32_t next;
    int bytes_left;
    uint32_t words_left;
} unwind_state;

static uint32_t next_unwind_byte(const agr_ehabi_env *env, unwind_state *uws, int *failed) {
    uint32_t b;
    if (uws->bytes_left == 0) {
        if (uws->words_left == 0) return 0xb0u;
        uws->words_left--;
        if (read_u32(env, uws->next, &uws->data)) { *failed = 1; return 0xb0u; }
        uws->next += 4;
        uws->bytes_left = 3;
    } else {
        uws->bytes_left--;
    }
    b = (uws->data >> 24) & 0xffu;
    uws->data <<= 8;
    return b;
}

static int pop_core(agr_guest_unwind_context *ctx, const agr_ehabi_env *env, uint32_t mask) {
    uint32_t ptr = ctx->r[R_SP];
    int i;
    for (i = 0; i < 16; i++) {
        if (mask & (1u << i)) {
            if (!stack_ok(ctx, ptr, 4) || read_u32(env, ptr, &ctx->r[i])) return -1;
            ptr += 4;
        }
    }
    if ((mask & (1u << R_SP)) == 0) ctx->r[R_SP] = ptr;
    return 0;
}

static int pop_words(agr_guest_unwind_context *ctx, const agr_ehabi_env *env,
                     uint32_t word_count, uint32_t *words) {
    uint32_t ptr = ctx->r[R_SP], i;
    for (i = 0; i < word_count; i++) {
        uint32_t value = 0;
        if (!stack_ok(ctx, ptr, 4) || read_u32(env, ptr, &value)) return -1;
        if (words) words[i] = value;
        ptr += 4;
    }
    ctx->r[R_SP] = ptr;
    return 0;
}

static int pop_vfp(agr_guest_unwind_context *ctx, const agr_ehabi_env *env,
                   uint32_t start, uint32_t count, int vfp_x) {
    uint32_t i, words[66];
    uint32_t word_count = count * 2u + (vfp_x ? 1u : 0u);
    if (start + count > 32u) return -1;
    if (pop_words(ctx, env, word_count, words)) return -1;
    for (i = 0; i < count; i++) {
        uint32_t lo = words[i * 2u], hi = words[i * 2u + 1u];
        ctx->vfp_d[start + i] = ((uint64_t)hi << 32) | lo;
    }
    return 0;
}

static agr_ehabi_stop execute_opcodes(agr_guest_unwind_context *ctx, const agr_ehabi_env *env,
                                      unwind_state *uws, char *detail, size_t detail_size) {
    int set_pc = 0, failed = 0;
    for (;;) {
        uint32_t op = next_unwind_byte(env, uws, &failed);
        if (failed) {
            snprintf(detail, detail_size, "unwind opcode read failed");
            return AGR_EHABI_FAILURE;
        }
        if (op == 0xb0u) {
            if (!set_pc) ctx->r[R_PC] = ctx->r[R_LR];
            apply_thumb_from_pc(ctx);
            return AGR_EHABI_OK;
        }
        if ((op & 0x80u) == 0) {
            uint32_t offset = ((op & 0x3fu) << 2) + 4u;
            if (op & 0x40u) ctx->r[R_SP] -= offset;
            else ctx->r[R_SP] += offset;
            continue;
        }
        if ((op & 0xf0u) == 0x80u) {
            op = (op << 8) | next_unwind_byte(env, uws, &failed);
            if (failed) return AGR_EHABI_FAILURE;
            if (op == 0x8000u) {
                snprintf(detail, detail_size, "refuse to unwind");
                return AGR_EHABI_FAILURE;
            }
            op = (op << 4) & 0xfff0u;
            if (pop_core(ctx, env, op)) {
                snprintf(detail, detail_size, "core pop out of stack bounds");
                return AGR_EHABI_FAILURE;
            }
            if (op & (1u << R_PC)) set_pc = 1;
            continue;
        }
        if ((op & 0xf0u) == 0x90u) {
            op &= 0xfu;
            if (op == 13u || op == 15u) {
                snprintf(detail, detail_size, "reserved vsp=r[%u]", op);
                return AGR_EHABI_UNSUPPORTED_ENCODING;
            }
            ctx->r[R_SP] = ctx->r[op];
            continue;
        }
        if ((op & 0xf0u) == 0xa0u) {
            uint32_t mask = (0xff0u >> (7 - (op & 7u))) & 0xff0u;
            if (op & 8u) mask |= (1u << R_LR);
            if (pop_core(ctx, env, mask)) {
                snprintf(detail, detail_size, "core pop out of stack bounds");
                return AGR_EHABI_FAILURE;
            }
            continue;
        }
        if ((op & 0xf0u) == 0xb0u) {
            if (op == 0xb1u) {
                op = next_unwind_byte(env, uws, &failed);
                if (failed || op == 0 || (op & 0xf0u) != 0) {
                    snprintf(detail, detail_size, "spare 0xb1 encoding");
                    return AGR_EHABI_UNSUPPORTED_ENCODING;
                }
                if (pop_core(ctx, env, op)) return AGR_EHABI_FAILURE;
                continue;
            }
            if (op == 0xb2u) {
                int shift = 2;
                op = next_unwind_byte(env, uws, &failed);
                if (failed) return AGR_EHABI_FAILURE;
                while (op & 0x80u) {
                    ctx->r[R_SP] += (op & 0x7fu) << shift;
                    shift += 7;
                    op = next_unwind_byte(env, uws, &failed);
                    if (failed) return AGR_EHABI_FAILURE;
                }
                ctx->r[R_SP] += ((op & 0x7fu) << shift) + 0x204u;
                continue;
            }
            if (op == 0xb3u) {
                op = next_unwind_byte(env, uws, &failed);
                if (failed || pop_vfp(ctx, env, op >> 4, (op & 0xfu) + 1u, 1)) {
                    snprintf(detail, detail_size, "VFPX pop failed");
                    return AGR_EHABI_FAILURE;
                }
                continue;
            }
            if ((op & 0xfcu) == 0xb4u) {
                snprintf(detail, detail_size, "obsolete FPA encoding 0x%02x", op);
                return AGR_EHABI_UNSUPPORTED_ENCODING;
            }
            if (pop_vfp(ctx, env, 8, (op & 7u) + 1u, 1)) return AGR_EHABI_FAILURE;
            continue;
        }
        if ((op & 0xf0u) == 0xc0u) {
            if (op == 0xc6u || op == 0xc7u || (op & 0xf8u) == 0xc0u) {
                snprintf(detail, detail_size, "unsupported iWMMXt encoding 0x%02x", op);
                return AGR_EHABI_UNSUPPORTED_ENCODING;
            }
            if (op == 0xc8u || op == 0xc9u) {
                uint32_t extra = next_unwind_byte(env, uws, &failed);
                uint32_t start = extra >> 4;
                if (failed) return AGR_EHABI_FAILURE;
                if (op == 0xc8u) start += 16u;
                if (pop_vfp(ctx, env, start, (extra & 0xfu) + 1u, 0)) return AGR_EHABI_FAILURE;
                continue;
            }
            snprintf(detail, detail_size, "spare 0x%02x encoding", op);
            return AGR_EHABI_UNSUPPORTED_ENCODING;
        }
        if ((op & 0xf8u) == 0xd0u) {
            if (pop_vfp(ctx, env, 8, (op & 7u) + 1u, 0)) return AGR_EHABI_FAILURE;
            continue;
        }
        snprintf(detail, detail_size, "unsupported EHABI encoding 0x%02x", op);
        return AGR_EHABI_UNSUPPORTED_ENCODING;
    }
}

static int describe_frame(agr_guest_unwind_context *ctx, const agr_ehabi_env *env) {
    agr_module_info module;
    uint32_t search_pc, entry = 0, content = 0;
    if (ctx->r[R_PC] == 0) {
        set_stop(ctx, AGR_EHABI_INVALID_PC, "PC is zero");
        return -1;
    }
    /* GCC get_eit_entry subtracts 2 before Find_exidx / binary search. */
    search_pc = ctx->r[R_PC] - 2u;
    if (env->find_module(env->opaque, search_pc, &module)) {
        set_stop(ctx, AGR_EHABI_NO_MODULE, "PC is not in a loaded DSO");
        ctx->dso_name[0] = 0;
        ctx->dso_load_start = ctx->dso_load_size = ctx->relative_pc = 0;
        ctx->exidx_entry = ctx->exidx_insn = ctx->fnstart = 0;
        return -1;
    }
    bind_module(ctx, &module);
    if (!module.exidx || !module.exidx_count) {
        set_stop(ctx, AGR_EHABI_NO_MODULE, "DSO has no PT_ARM_EXIDX");
        return -1;
    }
    if (search_exidx(env, module.exidx, (int)module.exidx_count, search_pc, &entry)) {
        set_stop(ctx, AGR_EHABI_FAILURE, "no .ARM.exidx entry for PC");
        return -1;
    }
    ctx->exidx_entry = entry;
    if (prel31(env, entry, &ctx->fnstart) || read_u32(env, entry + 4, &content)) {
        set_stop(ctx, AGR_EHABI_FAILURE, "exidx entry read failed");
        return -1;
    }
    ctx->exidx_insn = content;
    if (content == EXIDX_CANTUNWIND) {
        set_stop(ctx, AGR_EHABI_CANTUNWIND, "EXIDX_CANTUNWIND");
        return -1;
    }
    if (content & 0x80000000u) {
        uint32_t personality = (content >> 24) & 0xfu;
        if (personality > 2u) {
            char detail[96];
            snprintf(detail, sizeof(detail), "unsupported personality index %u", personality);
            set_stop(ctx, AGR_EHABI_UNSUPPORTED_ENCODING, detail);
            return -1;
        }
    } else {
        uint32_t eht = 0, header = 0, personality;
        if (prel31(env, entry + 4, &eht) || read_u32(env, eht, &header)) {
            set_stop(ctx, AGR_EHABI_FAILURE, "EHT header read failed");
            return -1;
        }
        if ((header & 0x80000000u) == 0) {
            set_stop(ctx, AGR_EHABI_UNSUPPORTED_ENCODING, "custom personality routine");
            return -1;
        }
        personality = (header >> 24) & 0xfu;
        if (personality > 2u) {
            char detail[96];
            snprintf(detail, sizeof(detail), "unsupported personality index %u", personality);
            set_stop(ctx, AGR_EHABI_UNSUPPORTED_ENCODING, detail);
            return -1;
        }
    }
    ctx->stop = AGR_EHABI_OK;
    ctx->stop_detail[0] = 0;
    return 0;
}

int32_t agr_ehabi_unwind_step(agr_guest_unwind_context *ctx, const agr_ehabi_env *env) {
    uint32_t eht = 0, header = 0, personality, content;
    unwind_state uws;
    agr_ehabi_stop stop;
    char detail[96];
    int compact;

    if (!ctx || !env || !env->read || !env->find_module) {
        if (ctx) set_stop(ctx, AGR_EHABI_FAILURE, "missing unwind env");
        return -1;
    }
    detail[0] = 0;
    if (describe_frame(ctx, env)) return -1;
    content = ctx->exidx_insn;

    compact = (content & 0x80000000u) != 0;
    if (compact) eht = ctx->exidx_entry + 4;
    else if (prel31(env, ctx->exidx_entry + 4, &eht)) {
        set_stop(ctx, AGR_EHABI_FAILURE, "extab prel31 read failed");
        return -1;
    }
    if (read_u32(env, eht, &header)) {
        set_stop(ctx, AGR_EHABI_FAILURE, "EHT header read failed");
        return -1;
    }
    if ((header & 0x80000000u) == 0) {
        set_stop(ctx, AGR_EHABI_UNSUPPORTED_ENCODING, "custom personality routine");
        return -1;
    }
    personality = (header >> 24) & 0xfu;
    if (personality > 2u) {
        snprintf(detail, sizeof(detail), "unsupported personality index %u", personality);
        set_stop(ctx, AGR_EHABI_UNSUPPORTED_ENCODING, detail);
        return -1;
    }

    memset(&uws, 0, sizeof(uws));
    uws.data = header;
    uws.next = eht + 4;
    if (personality == 0) {
        uws.data <<= 8;
        uws.words_left = 0;
        uws.bytes_left = 3;
    } else {
        uws.words_left = (uws.data >> 16) & 0xffu;
        uws.data <<= 16;
        uws.bytes_left = 2;
    }

    stop = execute_opcodes(ctx, env, &uws, detail, sizeof(detail));
    if (stop != AGR_EHABI_OK) {
        set_stop(ctx, stop, detail[0] ? detail : agr_ehabi_stop_name(stop));
        return -1;
    }
    apply_thumb_from_pc(ctx);
    ctx->stop = AGR_EHABI_OK;
    ctx->stop_detail[0] = 0;
    return 0;
}

static void record_frame(const agr_guest_unwind_context *ctx, agr_guest_unwind_frame *frame) {
    snprintf(frame->dso, sizeof(frame->dso), "%s", ctx->dso_name);
    frame->relative_pc = ctx->relative_pc;
    frame->sp = ctx->r[R_SP];
    frame->lr = ctx->r[R_LR];
    frame->thumb = (ctx->r[R_PC] & 1u) || (ctx->cpsr & CPSR_T) ? 1u : 0u;
}

int32_t agr_ehabi_backtrace(agr_guest_unwind_context *ctx, const agr_ehabi_env *env,
                            agr_guest_unwind_frame *frames, uint32_t max_frames,
                            uint32_t *count) {
    uint32_t n = 0;
    if (count) *count = 0;
    if (!ctx || !env || !frames || !max_frames) return -1;
    agr_ehabi_context_begin_backtrace(ctx);
    while (n < max_frames) {
        uint32_t prev_pc = ctx->r[R_PC], prev_sp = ctx->r[R_SP];
        /* GCC traces only after get_eit_entry succeeds; CANTUNWIND is a stop. */
        if (describe_frame(ctx, env)) break;
        record_frame(ctx, &frames[n]);
        n++;
        if (agr_ehabi_unwind_step(ctx, env)) break;
        if (ctx->r[R_PC] == prev_pc && ctx->r[R_SP] == prev_sp) {
            set_stop(ctx, AGR_EHABI_FAILURE, "unwind made no progress");
            break;
        }
    }
    if (count) *count = n;
    return n > 0 ? 0 : -1;
}

static int32_t runtime_read(void *opaque, uint32_t address, void *data, uint32_t size) {
    return agr_runtime_read((agr_runtime *)opaque, address, data, size);
}
static int32_t runtime_find(void *opaque, uint32_t pc, agr_module_info *out) {
    return agr_find_module((agr_runtime *)opaque, pc, out);
}

void agr_ehabi_env_from_runtime(agr_ehabi_env *env, agr_runtime *runtime) {
    env->opaque = runtime;
    env->read = runtime_read;
    env->find_module = runtime_find;
}

int32_t agr_ehabi_backtrace_runtime(agr_runtime *runtime, agr_guest_unwind_context *ctx,
                                    agr_guest_unwind_frame *frames, uint32_t max_frames,
                                    uint32_t *count) {
    agr_ehabi_env env;
    agr_ehabi_env_from_runtime(&env, runtime);
    return agr_ehabi_backtrace(ctx, &env, frames, max_frames, count);
}
