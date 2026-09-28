#include "agr_aot.h"

static int agr_region_00000(AgrAotRegs *outer) {
    if (!outer->source_elf) return AGR_AOT_MISS;
    uint32_t regs[16];
    memcpy(regs, outer->r, sizeof(regs));
    uint32_t cpsr = *outer->cpsr;
    AgrAotRegs local = {regs, &cpsr, outer->mem, outer->bias, 0, 0, 0, outer->source_elf, 0};
    AgrAotRegs *s = &local;
    int rc = 0, result = AGR_AOT_BOUNDARY;
    (void)rc;
    uint32_t blocks_done = 0, instructions = 0;
    goto L_00000e94;
L_00000e94:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3732u, s->source_elf + 3732u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 17400u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 3736u;
L_after_00000e94:
    blocks_done++;
    if (regs[15] == s->bias + 3736u) goto L_00000e98;
    goto L_exit;
L_00000e98:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3736u, s->source_elf + 3736u, 22u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 7, 3);
    instructions++;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000e98; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 8, 2);
    instructions++;
    agr_aot_mov_reg(s, 1, 2);
    instructions++;
    agr_aot_movs_imm(s, 2, 0u);
    instructions++;
    agr_aot_mov_reg(s, 4, 0);
    instructions++;
    agr_aot_movw(s, 9, 5126u);
    instructions++;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000e98; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_branch_reg(s, s->r[3], (s->bias + 3758u), 1); { instructions++; goto L_after_00000e98; }
L_after_00000e98:
    blocks_done++;
    goto L_exit;
L_exit:
    memcpy(outer->r, regs, sizeof(regs));
    *outer->cpsr = cpsr;
    outer->region_blocks = blocks_done;
    outer->region_instructions = instructions;
    return result;
}
int agr_attribution_payload(AgrAotRegs *state) { return agr_region_00000(state); }
