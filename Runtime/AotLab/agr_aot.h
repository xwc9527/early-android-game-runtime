#ifndef AGR_AOT_H
#define AGR_AOT_H

#include <stdint.h>
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
} AgrAotEntry;

extern const AgrAotEntry agr_aot_blocks[];
extern const uint32_t agr_aot_block_count;

void agr_aot_set_enabled(int enabled);
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
int agr_aot_drive(void *cpu);
uint32_t agr_aot_executed_blocks(void);
uint32_t agr_aot_executed_instructions(void);
uint32_t agr_aot_fallback_count(void);
uint32_t agr_aot_boundary_count(void);
uint32_t agr_aot_miss_pc(void);
void agr_aot_count_instruction(void);

static inline int agr_aot_fault(uint32_t address) {
    return address < 0x1000u || address > 0xfffffffcu;
}

static inline uint32_t agr_aot_load32(AgrAotRegs *state, uint32_t address) {
    uint32_t value = 0;
    if (agr_aot_fault(address)) return 0;
    memcpy(&value, state->mem + address, 4);
    return value;
}

static inline void agr_aot_store32(AgrAotRegs *state, uint32_t address, uint32_t value) {
    if (!agr_aot_fault(address)) memcpy(state->mem + address, &value, 4);
}

static inline void agr_aot_set_nz(AgrAotRegs *state, uint32_t value) {
    *state->cpsr &= ~(3u << 30);
    *state->cpsr |= ((value >> 31) << 31) | ((value == 0) << 30);
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
