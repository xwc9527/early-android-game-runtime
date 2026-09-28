/* Replay a captured real ARMv7 segment with the existing interpreter oracle. */
#include "attribution_segment.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifdef AGR_ATTRIBUTION_COMPILED
#include "agr_aot.h"
#endif

extern void *arm_interp_create(void);
extern void arm_interp_destroy(void *);
extern int32_t arm_interp_load(void *, uint32_t, const uint8_t *, uint32_t);
extern uint32_t *arm_interp_register_file(void *);
extern uint32_t *arm_interp_cpsr_ptr(void *);
extern uint8_t *arm_interp_memory_base(void *);
extern int32_t arm_interp_run(void *, uint64_t *, uint32_t *);

typedef struct Snapshot {
    uint32_t pc, cpsr, page_count, elf_bytes;
    uint32_t regs[16];
    uint32_t *page_addresses;
    uint8_t *page_data;
    uint8_t *elf_data;
} Snapshot;

static void fail(const char *message) { fprintf(stderr, "%s\n", message); exit(1); }

static Snapshot read_snapshot(const char *path) {
    FILE *file = fopen(path, "rb");
    if (!file) fail("snapshot open failed");
    uint32_t header[5];
    if (fread(header, sizeof(header), 1, file) != 1 ||
        header[0] != 0x41504341u || header[1] != 1u ||
        header[4] != AGR_ATTRIBUTION_PAGE_COUNT) fail("snapshot header mismatch");
    Snapshot s = {.pc = header[2], .cpsr = header[3], .page_count = header[4]};
    if (s.pc != AGR_ATTRIBUTION_ENTRY_PC || s.cpsr != AGR_ATTRIBUTION_ENTRY_CPSR ||
        fread(s.regs, sizeof(uint32_t), 16, file) != 16 ||
        memcmp(s.regs, agr_attribution_entry_regs, sizeof(s.regs)) ||
        fread(&s.elf_bytes, sizeof(uint32_t), 1, file) != 1)
        fail("snapshot entry mismatch");
    s.page_addresses = calloc(s.page_count, sizeof(uint32_t));
    s.page_data = malloc((size_t)s.page_count * 4096u);
    s.elf_data = malloc(s.elf_bytes);
    if (!s.page_addresses || !s.page_data || !s.elf_data) fail("snapshot allocation failed");
    for (uint32_t i = 0; i < s.page_count; i++) {
        if (fread(&s.page_addresses[i], sizeof(uint32_t), 1, file) != 1 ||
            s.page_addresses[i] != agr_attribution_expected_pages[i] ||
            fread(s.page_data + (size_t)i * 4096u, 4096, 1, file) != 1)
            fail("snapshot guest page mismatch");
    }
    if (fread(s.elf_data, s.elf_bytes, 1, file) != 1 || fgetc(file) != EOF)
        fail("snapshot ELF/length mismatch");
    fclose(file);
    return s;
}

static void reset_cpu(void *cpu, const Snapshot *s) {
    for (uint32_t i = 0; i < s->page_count; i++) {
        if (arm_interp_load(cpu, s->page_addresses[i],
                            s->page_data + (size_t)i * 4096u, 4096u))
            fail("snapshot page load failed");
    }
    uint32_t *regs = arm_interp_register_file(cpu);
    uint32_t *cpsr = arm_interp_cpsr_ptr(cpu);
    if (!regs || !cpsr) fail("interpreter architectural state unavailable");
    memcpy(regs, s->regs, sizeof(s->regs));
    *cpsr = s->cpsr;
}

static uint64_t ticks(void) {
    struct timespec ts;
    if (clock_gettime(CLOCK_MONOTONIC, &ts)) fail("clock failed");
    return (uint64_t)ts.tv_sec * UINT64_C(1000000000) + (uint64_t)ts.tv_nsec;
}

static uint64_t guest_pages_fnv(void *cpu, const Snapshot *s) {
    const uint8_t *mem = arm_interp_memory_base(cpu);
    if (!mem) fail("guest memory unavailable");
    uint64_t hash = UINT64_C(14695981039346656037);
    for (uint32_t page = 0; page < s->page_count; page++) {
        const uint8_t *bytes = mem + s->page_addresses[page];
        for (uint32_t i = 0; i < 4096; i++)
            hash = (hash ^ bytes[i]) * UINT64_C(1099511628211);
    }
    return hash;
}

#ifdef AGR_ATTRIBUTION_COMPILED
#ifdef AGR_ATTRIBUTION_PAYLOAD
extern int agr_attribution_payload(AgrAotRegs *);
#endif
#ifdef AGR_ATTRIBUTION_SCALAR
extern int agr_attribution_scalar(AgrAotRegs *);
#endif
static const AgrAotEntry *lookup_entry(uint32_t guest_pc) {
    uint32_t pc = guest_pc - 65536u;
    if (agr_aot_fast_direct_count) {
        uint32_t delta = pc - agr_aot_fast_direct_base;
        if ((delta & 1u) || (delta >> 1u) >= agr_aot_fast_direct_count)
            return NULL;
        uint32_t slot = agr_aot_fast_direct[delta >> 1u];
        return slot ? &agr_aot_fast_blocks[slot - 1u] : NULL;
    }
    uint32_t low = 0, high = agr_aot_fast_block_count;
    while (low < high) {
        uint32_t middle = low + (high - low) / 2;
        if (agr_aot_fast_blocks[middle].pc == pc) return &agr_aot_fast_blocks[middle];
        if (agr_aot_fast_blocks[middle].pc < pc) low = middle + 1;
        else high = middle;
    }
    return NULL;
}

static uint32_t run_compiled(void *cpu, const Snapshot *snapshot,
                             uint32_t *drive_calls, uint32_t *chained) {
    uint32_t *regs = arm_interp_register_file(cpu);
    uint32_t *cpsr = arm_interp_cpsr_ptr(cpu);
    AgrAotRegs state = {regs, cpsr, arm_interp_memory_base(cpu), 65536u,
                        64u, 0u, 0u, snapshot->elf_data, 0u};
#if defined(AGR_ATTRIBUTION_PAYLOAD) || defined(AGR_ATTRIBUTION_SCALAR)
#ifdef AGR_ATTRIBUTION_SCALAR
    if (agr_attribution_scalar(&state) != AGR_AOT_BOUNDARY ||
#else
    if (agr_attribution_payload(&state) != AGR_AOT_BOUNDARY ||
#endif
        regs[15] != AGR_ATTRIBUTION_POST_PC)
        fail("direct payload architectural exit mismatch");
    (*drive_calls)++;
    return AGR_ATTRIBUTION_INSTRUCTIONS;
#else
    uint32_t instructions = 0;
    for (uint32_t iteration = 0; iteration < 10000u &&
         regs[15] != AGR_ATTRIBUTION_POST_PC; iteration++) {
        const AgrAotEntry *entry = lookup_entry(regs[15]);
        if (!entry) fail("compiled segment lookup miss");
        state.region_entry = entry->region_entry;
        state.region_blocks = state.region_instructions = 0;
        int result = entry->function(&state);
        if (result != AGR_AOT_BOUNDARY)
            fail("compiled segment boundary/forward-progress failure");
#ifdef AGR_ATTRIBUTION_REGION
        if (!state.region_blocks || state.region_blocks > state.region_budget)
            fail("region accounting mismatch");
        instructions += state.region_instructions;
        *chained += state.region_blocks - 1u;
#else
        instructions += entry->instructions;
#endif
        (*drive_calls)++;
    }
    if (regs[15] != AGR_ATTRIBUTION_POST_PC) fail("compiled segment exceeded drive limit");
    return instructions;
#endif
}
#endif

int main(int argc, char **argv) {
    if (argc != 3) fail("usage: attribution_replay SNAPSHOT REPETITIONS");
    Snapshot s = read_snapshot(argv[1]);
    uint32_t repetitions = (uint32_t)strtoul(argv[2], NULL, 10);
    if (!repetitions || repetitions > 1000000u) fail("invalid repetitions");
    void *cpu = arm_interp_create();
    if (!cpu) fail("interpreter creation failed");
    uint64_t elapsed = 0;
    uint64_t final_page_hash = 0;
    uint32_t drive_calls = 0, chained_blocks = 0;
    for (uint32_t i = 0; i < repetitions; i++) {
        reset_cpu(cpu, &s);
#ifdef AGR_ATTRIBUTION_COMPILED
        uint64_t before = ticks();
        uint32_t instructions = run_compiled(cpu, &s, &drive_calls, &chained_blocks);
        elapsed += ticks() - before;
        if (instructions != AGR_ATTRIBUTION_INSTRUCTIONS)
            fail("compiled instruction count differs from interpreter trace");
#else
        uint64_t budget = AGR_ATTRIBUTION_INSTRUCTIONS;
        uint32_t svc = 0;
        uint64_t before = ticks();
        int32_t outcome = arm_interp_run(cpu, &budget, &svc);
        elapsed += ticks() - before;
        if (outcome || budget || svc) fail("interpreter segment did not complete normally");
#endif
        uint32_t *regs = arm_interp_register_file(cpu);
        uint32_t cpsr = *arm_interp_cpsr_ptr(cpu);
        if (memcmp(regs, agr_attribution_post_regs, 16 * sizeof(uint32_t)) ||
            cpsr != AGR_ATTRIBUTION_POST_CPSR || regs[15] != AGR_ATTRIBUTION_POST_PC) {
            fprintf(stderr, "state mismatch iteration=%u pc=%08x expected=%08x cpsr=%08x expected=%08x\n",
                    i, regs[15], AGR_ATTRIBUTION_POST_PC, cpsr, AGR_ATTRIBUTION_POST_CPSR);
            fail("interpreter trace replay mismatch");
        }
        if (!i) final_page_hash = guest_pages_fnv(cpu, &s);
        else if (final_page_hash != guest_pages_fnv(cpu, &s))
            fail("guest memory result changed between repetitions");
    }
    printf("{\"label\":\"%s\",\"backend\":\"%s\","
           "\"repetitions\":%u,\"guest_instructions_per_repetition\":%u,"
           "\"elapsed_ns\":%llu,\"drive_calls\":%u,\"chained_blocks\":%u,"
           "\"final_pages_fnv64\":\"%016llx\",\"state_equal\":true}\n",
           AGR_ATTRIBUTION_LABEL,
#ifdef AGR_ATTRIBUTION_SCALAR
           "scalar-region",
#elif defined(AGR_ATTRIBUTION_PAYLOAD)
           "guardless-region",
#elif defined(AGR_ATTRIBUTION_REGION)
           "indexed-region",
#elif defined(AGR_ATTRIBUTION_COMPILED)
           "generated-c",
#else
           "interpreter",
#endif
           repetitions, AGR_ATTRIBUTION_INSTRUCTIONS,
           (unsigned long long)elapsed, drive_calls, chained_blocks,
           (unsigned long long)final_page_hash);
    arm_interp_destroy(cpu);
    return 0;
}
