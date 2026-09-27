#include "agr_aot.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdatomic.h>

extern uint32_t *arm_interp_register_file(void *cpu);
extern uint32_t *arm_interp_cpsr_ptr(void *cpu);
extern uint8_t *arm_interp_memory_base(void *cpu);
extern void arm_interp_set_trace(void (*function)(uint32_t, uint32_t, uint32_t, uint32_t, const uint32_t *, uint32_t));

static int enabled;
static int diagnostic;
static FILE *trace_file;
static uint64_t trace_limit;
static atomic_uint_fast64_t trace_seen;
static atomic_int trace_incomplete;
static FILE *log_file;
static FILE *checkpoint_file;
static uint32_t executed_blocks;
static uint32_t executed_instructions;
static uint32_t fallback_count;
static uint32_t boundary_count;
static uint32_t last_miss;
static double boundary_seconds;
static double drive_seconds;
static double off_probe_seconds;
static double fallback_interpreter_seconds;
static double svc_interpreter_seconds;
static double baseline_interpreter_seconds;
static uint32_t drive_calls;
static uint32_t lookup_misses;
static uint32_t it_fallbacks;
static uint32_t guard_misses;
static uint32_t step_limit_fallbacks;
static uint32_t fallback_interpreter_instructions;
static uint32_t svc_interpreter_instructions;
static uint32_t baseline_interpreter_instructions;

static void trace_instruction(uint32_t pc, uint32_t insn, uint32_t len, uint32_t thumb,
                              const uint32_t *regs, uint32_t cpsr) {
    if (!trace_file) return;
    uint64_t ordinal = atomic_fetch_add_explicit(&trace_seen, 1, memory_order_relaxed);
    if (trace_limit && ordinal >= trace_limit) {
        atomic_store_explicit(&trace_incomplete, 1, memory_order_relaxed);
        return;
    }
    flockfile(trace_file);
    fprintf(trace_file, "%u %u %u %u %u", pc, insn, len, thumb, cpsr);
    for (uint32_t i = 0; i < 16; i++) fprintf(trace_file, " %u", regs ? regs[i] : 0);
    fputc('\n', trace_file);
    funlockfile(trace_file);
}

void agr_aot_set_trace_limit(uint64_t instruction_limit) { trace_limit = instruction_limit; }
uint64_t agr_aot_trace_seen(void) { return atomic_load_explicit(&trace_seen, memory_order_relaxed); }
int agr_aot_trace_incomplete(void) { return atomic_load_explicit(&trace_incomplete, memory_order_relaxed); }

void agr_aot_trace_open(const char *path) {
    if (trace_file) fclose(trace_file);
    atomic_store_explicit(&trace_seen, 0, memory_order_relaxed);
    atomic_store_explicit(&trace_incomplete, 0, memory_order_relaxed);
    trace_file = fopen(path, "w");
    arm_interp_set_trace(trace_file ? trace_instruction : NULL);
}

void agr_aot_trace_close(void) {
    arm_interp_set_trace(NULL);
    if (trace_file) fclose(trace_file);
    trace_file = NULL;
}

void agr_aot_log_open(const char *path) {
    if (log_file) fclose(log_file);
    log_file = fopen(path, "w");
    executed_blocks = 0;
    executed_instructions = 0;
    fallback_count = 0;
    boundary_count = 0;
    last_miss = 0;
    boundary_seconds = 0;
    drive_seconds = off_probe_seconds = 0;
    fallback_interpreter_seconds = svc_interpreter_seconds = baseline_interpreter_seconds = 0;
    drive_calls = lookup_misses = it_fallbacks = guard_misses = step_limit_fallbacks = 0;
    fallback_interpreter_instructions = svc_interpreter_instructions = baseline_interpreter_instructions = 0;
}

void agr_aot_checkpoint_open(const char *path) {
    if (checkpoint_file) fclose(checkpoint_file);
    checkpoint_file = fopen(path, "w");
}

void agr_aot_add_boundary_seconds(double seconds) { boundary_seconds += seconds; }
double agr_aot_boundary_seconds(void) { return boundary_seconds; }

void agr_aot_record_drive(double seconds, int result) {
    drive_calls++;
    if (result == AGR_AOT_OFF) off_probe_seconds += seconds;
    else drive_seconds += seconds;
}

void agr_aot_record_interpreter(double seconds, int result, uint32_t instructions) {
    if (result == AGR_AOT_MISS) {
        fallback_interpreter_seconds += seconds;
        fallback_interpreter_instructions += instructions;
    } else if (result == AGR_AOT_SVC) {
        svc_interpreter_seconds += seconds;
        svc_interpreter_instructions += instructions;
    } else {
        baseline_interpreter_seconds += seconds;
        baseline_interpreter_instructions += instructions;
    }
}

void agr_aot_log_close(void) {
    if (log_file) fclose(log_file);
    log_file = NULL;
    if (checkpoint_file) fclose(checkpoint_file);
    checkpoint_file = NULL;
}

void agr_aot_log_host(const char *name, uint32_t slot, uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) {
    if (!log_file) return;
    fprintf(log_file, "%s %u %u %u %u %u\n", name ? name : "host", slot, r0, r1, r2, r3);
}

void agr_aot_set_enabled(int value) { enabled = value; }
void agr_aot_set_diagnostic(int value) { diagnostic = value; }

static AgrAotFn lookup(uint32_t pc) {
    const AgrAotEntry *blocks = diagnostic ? agr_aot_debug_blocks : agr_aot_fast_blocks;
    uint32_t low = 0, high = diagnostic ? agr_aot_debug_block_count : agr_aot_fast_block_count;
    while (low < high) {
        uint32_t mid = low + (high - low) / 2u;
        uint32_t found = blocks[mid].pc;
        if (found == pc) return blocks[mid].function;
        if (found < pc) low = mid + 1u;
        else high = mid;
    }
    return NULL;
}

int agr_aot_drive(void *cpu) {
    uint32_t block_count = diagnostic ? agr_aot_debug_block_count : agr_aot_fast_block_count;
    if (!enabled || !block_count || !cpu) return AGR_AOT_OFF;
    uint32_t *regs = arm_interp_register_file(cpu);
    uint32_t *cpsr = arm_interp_cpsr_ptr(cpu);
    uint8_t *memory = arm_interp_memory_base(cpu);
    if (!regs || !cpsr || !memory) return AGR_AOT_FAULT;
    AgrAotRegs state = {regs, cpsr, memory};
    for (uint32_t step = 0; step < 100000u; step++) {
        uint32_t pc = regs[15];
        /* The interpreter owns Thumb IT predication until its ITSTATE clears. */
        if (*cpsr & 0x0600fc00u) {
            fallback_count++;
            it_fallbacks++;
            last_miss = pc;
            return AGR_AOT_MISS;
        }
        if ((*cpsr & 0x20u) == 0 && !agr_aot_fault(pc)) {
            uint32_t word = agr_aot_load32(&state, pc);
            if ((word & 0xff000000u) == 0xef000000u) {
                boundary_count++;
                return AGR_AOT_SVC;
            }
        }
        AgrAotFn function = lookup(pc);
        if (!function) {
            fallback_count++;
            lookup_misses++;
            last_miss = pc;
            return AGR_AOT_MISS;
        }
        if (checkpoint_file) {
            fprintf(checkpoint_file, "%u %u", pc, *cpsr);
            for (uint32_t i = 0; i < 16; i++) fprintf(checkpoint_file, " %u", regs[i]);
            fputc('\n', checkpoint_file);
        }
        executed_blocks++;
        int result = function(&state);
        if (result == AGR_AOT_FAULT) return AGR_AOT_FAULT;
        if (result == AGR_AOT_MISS) {
            fallback_count++;
            guard_misses++;
            last_miss = pc;
            return AGR_AOT_MISS;
        }
    }
    fallback_count++;
    step_limit_fallbacks++;
    last_miss = regs[15];
    return AGR_AOT_MISS;
}

uint32_t agr_aot_executed_blocks(void) { return executed_blocks; }
uint32_t agr_aot_executed_instructions(void) { return executed_instructions; }
uint32_t agr_aot_fallback_count(void) { return fallback_count; }
uint32_t agr_aot_boundary_count(void) { return boundary_count; }
uint32_t agr_aot_miss_pc(void) { return last_miss; }

void agr_aot_count_instruction(void) { executed_instructions++; }
void agr_aot_count_instructions(uint32_t count) { executed_instructions += count; }
double agr_aot_drive_seconds(void) { return drive_seconds; }
double agr_aot_off_probe_seconds(void) { return off_probe_seconds; }
double agr_aot_fallback_interpreter_seconds(void) { return fallback_interpreter_seconds; }
double agr_aot_svc_interpreter_seconds(void) { return svc_interpreter_seconds; }
double agr_aot_baseline_interpreter_seconds(void) { return baseline_interpreter_seconds; }
uint32_t agr_aot_drive_calls(void) { return drive_calls; }
uint32_t agr_aot_lookup_misses(void) { return lookup_misses; }
uint32_t agr_aot_it_fallbacks(void) { return it_fallbacks; }
uint32_t agr_aot_guard_misses(void) { return guard_misses; }
uint32_t agr_aot_step_limit_fallbacks(void) { return step_limit_fallbacks; }
uint32_t agr_aot_fallback_interpreter_instructions(void) { return fallback_interpreter_instructions; }
uint32_t agr_aot_svc_interpreter_instructions(void) { return svc_interpreter_instructions; }
uint32_t agr_aot_baseline_interpreter_instructions(void) { return baseline_interpreter_instructions; }
