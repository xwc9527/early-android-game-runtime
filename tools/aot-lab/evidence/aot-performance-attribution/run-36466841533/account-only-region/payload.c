#include "agr_aot.h"

static int agr_region_00000(AgrAotRegs *outer) {
    uint32_t regs[16];
    memcpy(regs, outer->r, sizeof(regs));
    uint32_t cpsr = *outer->cpsr;
    AgrAotRegs local = {regs, &cpsr, outer->mem, outer->bias, 0, 0, 0, outer->source_elf, 0};
    AgrAotRegs *s = &local;
    int rc = 0, result = AGR_AOT_BOUNDARY;
    (void)rc;
    uint32_t blocks_done = 0, instructions = 0;
    goto L_0009b480;
L_0009b480:
    if (blocks_done >= outer->region_budget) goto L_exit;
    agr_aot_cmp(s, s->r[2], 0u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 636022u) : (s->bias + 636036u); { instructions++; goto L_after_0009b480; }
L_after_0009b480:
    blocks_done++;
    if (regs[15] == s->bias + 636036u) goto L_0009b484;
    goto L_exit;
L_0009b484:
    if (blocks_done >= outer->region_budget) goto L_exit;
    atomic_thread_fence(memory_order_seq_cst);
    instructions++;
    { int rc = agr_aot_ldr(s, 4, s->r[5] + 4u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b484; } result = rc; goto L_exit; } }
    instructions++;
    { int rc = agr_aot_ldr(s, 0, s->r[4] + (s->r[6] << 2u)); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b484; } result = rc; goto L_exit; } }
    instructions++;
    s->r[15] = !s->r[0] ? (s->bias + 636078u) : (s->bias + 636048u); { instructions++; goto L_after_0009b484; }
L_after_0009b484:
    blocks_done++;
    if (regs[15] == s->bias + 636078u) goto L_0009b4ae;
    goto L_exit;
L_0009b4ae:
    if (blocks_done >= outer->region_budget) goto L_exit;
    { int rc = agr_aot_ldr(s, 2, s->r[5] + 8u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b4ae; } result = rc; goto L_exit; } }
    instructions++;
    { uint32_t addr = s->r[4] + (s->r[6] << 2u); if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[8]); }
    instructions++;
    regs[15] = s->bias + 636084u;
L_after_0009b4ae:
    blocks_done++;
    if (regs[15] == s->bias + 636084u) goto L_0009b4b4;
    goto L_exit;
L_0009b4b4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    s->r[15] = !s->r[2] ? (s->bias + 636154u) : (s->bias + 636086u); { instructions++; goto L_after_0009b4b4; }
L_after_0009b4b4:
    blocks_done++;
    if (regs[15] == s->bias + 636086u) goto L_0009b4b6;
    goto L_exit;
L_0009b4b6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    agr_aot_movs_imm(s, 4, 0u);
    instructions++;
    agr_aot_mov_reg(s, 7, 4);
    instructions++;
    s->r[15] = (s->bias + 636104u); { instructions++; goto L_after_0009b4b6; }
L_after_0009b4b6:
    blocks_done++;
    if (regs[15] == s->bias + 636104u) goto L_0009b4c8;
    goto L_exit;
L_0009b4c2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    agr_aot_adds(s, 4, s->r[4], 1u);
    instructions++;
    agr_aot_cmp(s, s->r[2], s->r[4]);
    instructions++;
    s->r[15] = agr_aot_condition(s, 9u) ? (s->bias + 636158u) : (s->bias + 636104u); { instructions++; goto L_after_0009b4c2; }
L_after_0009b4c2:
    blocks_done++;
    if (regs[15] == s->bias + 636158u) goto L_0009b4fe;
    if (regs[15] == s->bias + 636104u) goto L_0009b4c8;
    goto L_exit;
L_0009b4c8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 12u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b4c8; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_lsls(s, 6, s->r[4], 2u);
    instructions++;
    { int rc = agr_aot_ldr(s, 0, s->r[3] + (s->r[4] << 2u)); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b4c8; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_cmp(s, s->r[0], 0u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 636098u) : (s->bias + 636116u); { instructions++; goto L_after_0009b4c8; }
L_after_0009b4c8:
    blocks_done++;
    if (regs[15] == s->bias + 636098u) goto L_0009b4c2;
    goto L_exit;
L_0009b4fe:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if ((rc = agr_aot_ldmia_sp(s, 34800u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b4fe; } result = rc; goto L_exit; }
    instructions++;
L_after_0009b4fe:
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
