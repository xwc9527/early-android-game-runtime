#include "agr_aot.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdatomic.h>

extern uint32_t *arm_interp_register_file(void *cpu);
extern uint32_t *arm_interp_cpsr_ptr(void *cpu);
extern uint8_t *arm_interp_memory_base(void *cpu);
extern void arm_interp_set_trace(void (*function)(uint32_t, uint32_t, uint32_t, uint32_t, const uint32_t *, uint32_t));

static int enabled;
/* Older generated artifacts omit the optional dense ELF PC index. */
__attribute__((weak)) const uint32_t agr_aot_fast_direct_base = 0;
__attribute__((weak)) const uint32_t agr_aot_fast_direct_count = 0;
__attribute__((weak)) const uint32_t agr_aot_fast_direct[] = {0};
__attribute__((weak)) const uint32_t agr_aot_fast_relocatable = 0;
__attribute__((weak)) const uint64_t agr_aot_input_elf_fnv64 = 0;
__attribute__((weak)) const uint32_t agr_aot_input_elf_bytes = 0;
static uint32_t image_bias;
static uint8_t *source_elf;
static int diagnostic;
static FILE *trace_file;
static uint64_t trace_limit;
static atomic_uint_fast64_t trace_seen;
static atomic_int trace_incomplete;
static FILE *log_file;
static FILE *checkpoint_file;
static FILE *fallback_file;
static uint32_t fallback_log_count;
static int fallback_log_incomplete;
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
static uint32_t region_chained_blocks;
static uint32_t lookup_misses;
static uint32_t it_fallbacks;
static uint32_t guard_misses;
static uint32_t mode_misses;
static uint32_t step_limit_fallbacks;
static uint32_t fallback_interpreter_instructions;
static uint32_t svc_interpreter_instructions;
static uint32_t baseline_interpreter_instructions;
static const char *probe_stop_host;
static int probe_stopped;

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
    drive_calls = lookup_misses = it_fallbacks = guard_misses = mode_misses = step_limit_fallbacks = 0;
    region_chained_blocks = 0;
    fallback_interpreter_instructions = svc_interpreter_instructions = baseline_interpreter_instructions = 0;
    probe_stop_host = NULL;
    probe_stopped = 0;
}

void agr_aot_probe_stop_before_host(const char *name) { probe_stop_host = name; }
int agr_aot_probe_stopped(void) { return probe_stopped; }

void agr_aot_checkpoint_open(const char *path) {
    if (checkpoint_file) fclose(checkpoint_file);
    checkpoint_file = fopen(path, "w");
}

void agr_aot_add_boundary_seconds(double seconds) { if (!probe_stopped) boundary_seconds += seconds; }
double agr_aot_boundary_seconds(void) { return boundary_seconds; }

void agr_aot_record_drive(double seconds, int result) {
    if (probe_stopped) return;
    drive_calls++;
    if (result == AGR_AOT_OFF) off_probe_seconds += seconds;
    else drive_seconds += seconds;
}

void agr_aot_fallback_open(const char *path) {
    if (fallback_file) fclose(fallback_file);
    fallback_file = fopen(path, "w");
    fallback_log_count = 0;
    fallback_log_incomplete = fallback_file == NULL;
}

int agr_aot_fallback_log_incomplete(void) { return fallback_log_incomplete; }

static void record_fallback(const char *reason, uint32_t pc, uint32_t cpsr) {
    if (!fallback_file) return;
    if (fallback_log_count == 100000u) {
        fallback_log_incomplete = 1;
        return;
    }
    if (fprintf(fallback_file, "%s %08x %08x\n", reason, pc, cpsr) < 0)
        fallback_log_incomplete = 1;
    fallback_log_count++;
}

void agr_aot_record_interpreter(double seconds, int result, uint32_t instructions) {
    if (probe_stopped) return;
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
    if (fallback_file && fclose(fallback_file) != 0) fallback_log_incomplete = 1;
    fallback_file = NULL;
}

void agr_aot_log_host(const char *name, uint32_t slot, uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) {
    if (log_file)
        fprintf(log_file, "%s %u %u %u %u %u\n", name ? name : "host", slot, r0, r1, r2, r3);
    if (!probe_stopped && probe_stop_host && name && !strcmp(name, probe_stop_host)) {
        probe_stopped = 1;
        enabled = 0;
        agr_aot_trace_close();
        agr_aot_log_close();
    }
}

void agr_aot_set_enabled(int value) { enabled = value; }
void agr_aot_set_diagnostic(int value) { diagnostic = value; }
void agr_aot_set_image_bias(uint32_t load_bias) { image_bias = load_bias; }
void agr_aot_bind_elf(const void *bytes, uint32_t size, uint32_t load_bias) {
    if (!agr_aot_fast_relocatable || !bytes || size != agr_aot_input_elf_bytes) return;
    const uint8_t *data = (const uint8_t *)bytes;
    uint64_t hash = UINT64_C(14695981039346656037);
    for (uint32_t i = 0; i < size; i++) hash = (hash ^ data[i]) * UINT64_C(1099511628211);
    if (hash == agr_aot_input_elf_fnv64) {
#ifdef AGR_AOT_REGION_COMPILER
        uint8_t *snapshot = malloc(size);
        if (!snapshot) { image_bias = 0; return; }
        memcpy(snapshot, bytes, size);
        free(source_elf);
        source_elf = snapshot;
#endif
        image_bias = load_bias;
    }
}

static const AgrAotEntry *lookup(uint32_t pc) {
    if (agr_aot_fast_relocatable && !image_bias) return NULL;
    if (agr_aot_fast_relocatable) pc -= image_bias;
    if (!diagnostic) {
        if (agr_aot_fast_direct_count) {
            uint32_t delta = pc - agr_aot_fast_direct_base;
            if ((delta & 1u) || (delta >> 1u) >= agr_aot_fast_direct_count) return NULL;
            uint32_t slot = agr_aot_fast_direct[delta >> 1u];
            return slot ? &agr_aot_fast_blocks[slot - 1u] : NULL;
        }
        uint32_t index = ((pc >> 1u) * 2654435761u) & agr_aot_fast_hash_mask;
        for (uint32_t probe = 0; probe <= agr_aot_fast_hash_mask; probe++) {
            uint32_t found = agr_aot_fast_hash[index].pc;
            if (found == pc) return &agr_aot_fast_hash[index];
            if (!found) return NULL;
            index = (index + 1u) & agr_aot_fast_hash_mask;
        }
        return NULL;
    }
    const AgrAotEntry *blocks = agr_aot_debug_blocks;
    uint32_t low = 0, high = agr_aot_debug_block_count;
    while (low < high) {
        uint32_t mid = low + (high - low) / 2u;
        uint32_t found = blocks[mid].pc;
        if (found == pc) return &blocks[mid];
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
    AgrAotRegs state = {regs, cpsr, memory, agr_aot_fast_relocatable ? image_bias : 0,
                        0, 0, 0, source_elf};
    uint32_t local_blocks = 0, local_instructions = 0;
#define AGR_AOT_RETURN(value) do { \
    executed_blocks += local_blocks; \
    executed_instructions += local_instructions; \
    return (value); \
} while (0)
    for (uint32_t step = 0; step < 100000u;) {
        uint32_t pc = regs[15];
        /* The interpreter owns Thumb IT predication until its ITSTATE clears. */
        if (*cpsr & 0x0600fc00u) {
            fallback_count++;
            it_fallbacks++;
            last_miss = pc;
            record_fallback("it_state", pc, *cpsr);
            AGR_AOT_RETURN(AGR_AOT_MISS);
        }
        if ((*cpsr & 0x20u) == 0 && !agr_aot_fault(pc)) {
            uint32_t word = agr_aot_load32(&state, pc);
            if ((word & 0xff000000u) == 0xef000000u) {
                boundary_count++;
                record_fallback("svc", pc, *cpsr);
                AGR_AOT_RETURN(AGR_AOT_SVC);
            }
        }
        const AgrAotEntry *entry = lookup(pc);
        if (!entry) {
            fallback_count++;
            lookup_misses++;
            last_miss = pc;
            record_fallback("lookup_miss", pc, *cpsr);
            AGR_AOT_RETURN(AGR_AOT_MISS);
        }
        if (checkpoint_file) {
            fprintf(checkpoint_file, "%u %u", pc, *cpsr);
            for (uint32_t i = 0; i < 16; i++) fprintf(checkpoint_file, " %u", regs[i]);
            fputc('\n', checkpoint_file);
        }
#ifdef AGR_AOT_REGION_COMPILER
        state.region_budget = checkpoint_file ? 1u : 64u;
        if (state.region_budget > 100000u - step) state.region_budget = 100000u - step;
        state.region_blocks = state.region_instructions = 0;
#else
        local_blocks++;
#endif
        int result = entry->function(&state);
#ifdef AGR_AOT_REGION_COMPILER
        if (state.region_blocks > state.region_budget) AGR_AOT_RETURN(AGR_AOT_FAULT);
        local_blocks += state.region_blocks;
        local_instructions += state.region_instructions;
        if (state.region_blocks > 1u) region_chained_blocks += state.region_blocks - 1u;
        step += state.region_blocks ? state.region_blocks : 1u;
#else
        if (result != AGR_AOT_MISS && result != AGR_AOT_MODE_MISS)
            local_instructions += entry->instructions;
        step++;
#endif
        if (result == AGR_AOT_FAULT) AGR_AOT_RETURN(AGR_AOT_FAULT);
        if (result == AGR_AOT_MODE_MISS) {
            fallback_count++;
            mode_misses++;
#ifdef AGR_AOT_REGION_COMPILER
            pc = regs[15];
#endif
            last_miss = pc;
            record_fallback("mode_miss", pc, *cpsr);
            AGR_AOT_RETURN(AGR_AOT_MISS);
        }
        if (result == AGR_AOT_MISS) {
            fallback_count++;
            guard_misses++;
#ifdef AGR_AOT_REGION_COMPILER
            pc = regs[15];
#endif
            last_miss = pc;
            record_fallback("guard_miss", pc, *cpsr);
            AGR_AOT_RETURN(AGR_AOT_MISS);
        }
    }
    fallback_count++;
    step_limit_fallbacks++;
    last_miss = regs[15];
    record_fallback("step_limit", regs[15], *cpsr);
    AGR_AOT_RETURN(AGR_AOT_MISS);
#undef AGR_AOT_RETURN
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
uint32_t agr_aot_region_chained_blocks(void) { return region_chained_blocks; }
uint32_t agr_aot_lookup_misses(void) { return lookup_misses; }
uint32_t agr_aot_it_fallbacks(void) { return it_fallbacks; }
uint32_t agr_aot_guard_misses(void) { return guard_misses; }
uint32_t agr_aot_mode_misses(void) { return mode_misses; }
uint32_t agr_aot_step_limit_fallbacks(void) { return step_limit_fallbacks; }
uint32_t agr_aot_fallback_interpreter_instructions(void) { return fallback_interpreter_instructions; }
uint32_t agr_aot_svc_interpreter_instructions(void) { return svc_interpreter_instructions; }
uint32_t agr_aot_baseline_interpreter_instructions(void) { return baseline_interpreter_instructions; }
