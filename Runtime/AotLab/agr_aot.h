#ifndef AGR_AOT_H
#define AGR_AOT_H

#include <stdint.h>
#include <stdatomic.h>
#include <string.h>

enum {
    AGR_AOT_BOUNDARY = 1,
    AGR_AOT_FAULT = -1,
    AGR_AOT_OFF = 0,
    AGR_AOT_SVC = 2,
    AGR_AOT_MISS = 3
};

typedef struct AgrAotRegs {
    uint32_t *r;
    uint32_t *cpsr;
    uint8_t *mem;
} AgrAotRegs;

typedef int (*AgrAotFn)(AgrAotRegs *state);

typedef struct AgrAotEntry {
    uint32_t pc;
    AgrAotFn function;
    uint32_t instructions;
} AgrAotEntry;

extern const AgrAotEntry agr_aot_debug_blocks[];
extern const uint32_t agr_aot_debug_block_count;
extern const AgrAotEntry agr_aot_fast_blocks[];
extern const uint32_t agr_aot_fast_block_count;
extern const AgrAotEntry agr_aot_fast_hash[];
extern const uint32_t agr_aot_fast_hash_mask;

void agr_aot_set_enabled(int enabled);
void agr_aot_set_diagnostic(int enabled);
void agr_aot_trace_open(const char *path);
void agr_aot_trace_close(void);
void agr_aot_set_trace_limit(uint64_t instruction_limit);
uint64_t agr_aot_trace_seen(void);
int agr_aot_trace_incomplete(void);
void agr_aot_log_open(const char *path);
void agr_aot_log_close(void);
void agr_aot_log_host(const char *name, uint32_t slot, uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3);
void agr_aot_checkpoint_open(const char *path);
void agr_aot_add_boundary_seconds(double seconds);
double agr_aot_boundary_seconds(void);
void agr_aot_record_drive(double seconds, int result);
void agr_aot_record_interpreter(double seconds, int drive_result, uint32_t instructions);
double agr_aot_drive_seconds(void);
double agr_aot_off_probe_seconds(void);
double agr_aot_fallback_interpreter_seconds(void);
double agr_aot_svc_interpreter_seconds(void);
double agr_aot_baseline_interpreter_seconds(void);
uint32_t agr_aot_drive_calls(void);
uint32_t agr_aot_lookup_misses(void);
uint32_t agr_aot_it_fallbacks(void);
uint32_t agr_aot_guard_misses(void);
uint32_t agr_aot_step_limit_fallbacks(void);
uint32_t agr_aot_fallback_interpreter_instructions(void);
uint32_t agr_aot_svc_interpreter_instructions(void);
uint32_t agr_aot_baseline_interpreter_instructions(void);
int agr_aot_drive(void *cpu);
uint32_t agr_aot_executed_blocks(void);
uint32_t agr_aot_executed_instructions(void);
uint32_t agr_aot_fallback_count(void);
uint32_t agr_aot_boundary_count(void);
uint32_t agr_aot_miss_pc(void);
void agr_aot_count_instruction(void);
void agr_aot_count_instructions(uint32_t count);

static inline int agr_aot_fault(uint32_t address) {
    return address < 0x1000u || address > 0xfffffffcu;
}

static inline int agr_aot_fault8(uint32_t address) {
    return address < 0x1000u;
}

static inline int agr_aot_fault16(uint32_t address) {
    return address < 0x1000u || address > 0xfffffffeu;
}

static inline uint32_t agr_aot_load32(AgrAotRegs *state, uint32_t address) {
    uint32_t value = 0;
    if (agr_aot_fault(address)) return 0;
    memcpy(&value, state->mem + address, 4);
    return value;
}

static inline uint16_t agr_aot_load16(AgrAotRegs *state, uint32_t address) {
    uint16_t value = 0;
    if (agr_aot_fault(address)) return 0;
    memcpy(&value, state->mem + address, 2);
    return value;
}

static inline void agr_aot_store32(AgrAotRegs *state, uint32_t address, uint32_t value) {
    if (!agr_aot_fault(address)) memcpy(state->mem + address, &value, 4);
}

static inline void agr_aot_store8(AgrAotRegs *state, uint32_t address, uint32_t value) {
    if (!agr_aot_fault8(address)) state->mem[address] = (uint8_t)value;
}

static inline void agr_aot_store16(AgrAotRegs *state, uint32_t address, uint32_t value) {
    uint16_t half = (uint16_t)value;
    if (!agr_aot_fault16(address)) memcpy(state->mem + address, &half, 2);
}

static inline void agr_aot_set_nz(AgrAotRegs *state, uint32_t value) {
    *state->cpsr &= ~(3u << 30);
    *state->cpsr |= ((value >> 31) << 31) | ((value == 0) << 30);
}

static inline void agr_aot_set_nzcv(AgrAotRegs *state, uint32_t value,
                                    uint32_t carry, uint32_t overflow) {
    *state->cpsr &= ~(15u << 28);
    *state->cpsr |= ((value >> 31) << 31) | ((value == 0) << 30) |
                    ((carry & 1u) << 29) | ((overflow & 1u) << 28);
}

static inline void agr_aot_adds(AgrAotRegs *state, uint32_t rd,
                                uint32_t left, uint32_t right) {
    uint64_t wide = (uint64_t)left + right;
    uint32_t value = (uint32_t)wide;
    uint32_t overflow = ((~(left ^ right) & (left ^ value)) >> 31) & 1u;
    state->r[rd] = value;
    agr_aot_set_nzcv(state, value, (uint32_t)(wide >> 32), overflow);
}

static inline void agr_aot_subs(AgrAotRegs *state, uint32_t rd,
                                uint32_t left, uint32_t right) {
    uint32_t value = left - right;
    uint32_t overflow = (((left ^ right) & (left ^ value)) >> 31) & 1u;
    state->r[rd] = value;
    agr_aot_set_nzcv(state, value, left >= right, overflow);
}

static inline void agr_aot_cmp(AgrAotRegs *state, uint32_t left, uint32_t right) {
    uint32_t value = left - right;
    uint32_t overflow = (((left ^ right) & (left ^ value)) >> 31) & 1u;
    agr_aot_set_nzcv(state, value, left >= right, overflow);
}

static inline void agr_aot_lsls(AgrAotRegs *state, uint32_t rd,
                                uint32_t value, uint32_t amount) {
    uint32_t result = amount ? value << amount : value;
    uint32_t old_carry = (*state->cpsr >> 29) & 1u;
    uint32_t carry = amount ? (value >> (32u - amount)) & 1u : old_carry;
    state->r[rd] = result;
    *state->cpsr &= ~(7u << 29);
    *state->cpsr |= ((result >> 31) << 31) | ((result == 0) << 30) | (carry << 29);
}

static inline void agr_aot_lsls_reg(AgrAotRegs *state, uint32_t rd,
                                    uint32_t value, uint32_t amount_register) {
    uint32_t amount = amount_register & 0xffu;
    uint32_t old_carry = (*state->cpsr >> 29) & 1u;
    uint32_t result, carry;
    if (amount == 0) { result = value; carry = old_carry; }
    else if (amount < 32) { result = value << amount; carry = (value >> (32u - amount)) & 1u; }
    else if (amount == 32) { result = 0; carry = value & 1u; }
    else { result = 0; carry = 0; }
    state->r[rd] = result;
    *state->cpsr &= ~(7u << 29);
    *state->cpsr |= ((result >> 31) << 31) | ((result == 0) << 30) | (carry << 29);
}

static inline int agr_aot_condition(const AgrAotRegs *state, uint32_t condition) {
    uint32_t n = (*state->cpsr >> 31) & 1u, z = (*state->cpsr >> 30) & 1u;
    uint32_t c = (*state->cpsr >> 29) & 1u, v = (*state->cpsr >> 28) & 1u;
    switch (condition & 15u) {
        case 0: return z; case 1: return !z; case 2: return c; case 3: return !c;
        case 4: return n; case 5: return !n; case 6: return v; case 7: return !v;
        case 8: return c && !z; case 9: return !c || z;
        case 10: return n == v; case 11: return n != v;
        case 12: return !z && n == v; case 13: return z || n != v;
        case 14: return 1; default: return 0;
    }
}

static inline uint32_t agr_aot_reg(const AgrAotRegs *state, uint32_t index, uint32_t pc, int thumb) {
    if (index != 15) return state->r[index];
    return pc + (thumb ? 4u : 8u);
}

static inline void agr_aot_movs_imm(AgrAotRegs *state, uint32_t rd, uint32_t immediate) {
    state->r[rd] = immediate;
    agr_aot_set_nz(state, immediate);
}

static inline void agr_aot_mov_reg(AgrAotRegs *state, uint32_t rd, uint32_t rm) {
    state->r[rd] = state->r[rm];
}

static inline void agr_aot_movw(AgrAotRegs *state, uint32_t rd, uint32_t immediate) {
    state->r[rd] = immediate & 0xffffu;
}

static inline int agr_aot_ldr(AgrAotRegs *state, uint32_t rt, uint32_t address) {
    if (agr_aot_fault(address)) return AGR_AOT_FAULT;
    uint32_t value = agr_aot_load32(state, address);
    if (rt == 15) {
        *state->cpsr = (value & 1u) ? (*state->cpsr | 0x20u) : (*state->cpsr & ~0x20u);
        state->r[15] = value & ~1u;
        return AGR_AOT_BOUNDARY;
    }
    state->r[rt] = value;
    return 0;
}

static inline int agr_aot_ldrb(AgrAotRegs *state, uint32_t rt, uint32_t address) {
    if (agr_aot_fault8(address)) return AGR_AOT_FAULT;
    state->r[rt] = state->mem[address];
    return 0;
}

static inline int agr_aot_ldrh(AgrAotRegs *state, uint32_t rt, uint32_t address) {
    if (agr_aot_fault16(address)) return AGR_AOT_FAULT;
    uint16_t value = 0;
    memcpy(&value, state->mem + address, 2);
    state->r[rt] = value;
    return 0;
}

static inline void agr_aot_set_itstate(AgrAotRegs *state, uint32_t value) {
    *state->cpsr &= ~0x0600fc00u;
    *state->cpsr |= ((value & 0xfcu) << 8) | ((value & 3u) << 25);
}

static inline int agr_aot_stmdb_sp(AgrAotRegs *state, uint32_t mask) {
    uint32_t count = 0;
    for (uint32_t i = 0; i < 16; i++) if (mask & (1u << i)) count++;
    uint32_t address = state->r[13] - count * 4u;
    if (agr_aot_fault(address)) return AGR_AOT_FAULT;
    for (uint32_t i = 0; i < 16; i++) {
        if (mask & (1u << i)) {
            agr_aot_store32(state, address, state->r[i]);
            address += 4u;
        }
    }
    state->r[13] -= count * 4u;
    return 0;
}

static inline int agr_aot_stm(AgrAotRegs *state, uint32_t rn, uint32_t mask) {
    uint32_t address = state->r[rn];
    for (uint32_t i = 0; i < 16; i++) {
        if (mask & (1u << i)) {
            if (agr_aot_fault(address)) return AGR_AOT_FAULT;
            agr_aot_store32(state, address, state->r[i]);
            address += 4u;
        }
    }
    return 0;
}

static inline int agr_aot_ldmia_sp(AgrAotRegs *state, uint32_t mask) {
    uint32_t address = state->r[13];
    uint32_t count = 0;
    uint32_t values[16];
    for (uint32_t i = 0; i < 16; i++) {
        if (mask & (1u << i)) {
            if (agr_aot_fault(address)) return AGR_AOT_FAULT;
            values[i] = agr_aot_load32(state, address);
            address += 4u;
            count++;
        }
    }
    state->r[13] += count * 4u;
    for (uint32_t i = 0; i < 16; i++) if (mask & (1u << i)) state->r[i] = values[i];
    if (mask & (1u << 15)) {
        uint32_t value = state->r[15];
        *state->cpsr = (value & 1u) ? (*state->cpsr | 0x20u) : (*state->cpsr & ~0x20u);
        state->r[15] = value & ~1u;
        return AGR_AOT_BOUNDARY;
    }
    return 0;
}

static inline void agr_aot_add_imm(AgrAotRegs *state, uint32_t rd, uint32_t base, uint32_t immediate) {
    state->r[rd] = base + immediate;
}

static inline void agr_aot_branch_reg(AgrAotRegs *state, uint32_t target, uint32_t link, int link_thumb) {
    if (link) {
        state->r[14] = link | (link_thumb ? 1u : 0u);
    }
    *state->cpsr = (target & 1u) ? (*state->cpsr | 0x20u) : (*state->cpsr & ~0x20u);
    state->r[15] = target & ~1u;
}

#endif
