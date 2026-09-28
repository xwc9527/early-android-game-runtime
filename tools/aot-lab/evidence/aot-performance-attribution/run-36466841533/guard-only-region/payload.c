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
    goto L_0009b480;
L_0009b480:
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636032u, s->source_elf + 636032u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[2], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 636022u) : (s->bias + 636036u); { goto L_after_0009b480; }
L_after_0009b480:
    if (regs[15] == s->bias + 636036u) goto L_0009b484;
    goto L_exit;
L_0009b484:
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636036u, s->source_elf + 636036u, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
    atomic_thread_fence(memory_order_seq_cst);
    { int rc = agr_aot_ldr(s, 4, s->r[5] + 4u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { goto L_after_0009b484; } result = rc; goto L_exit; } }
    { int rc = agr_aot_ldr(s, 0, s->r[4] + (s->r[6] << 2u)); if (rc) { if (rc == AGR_AOT_BOUNDARY) { goto L_after_0009b484; } result = rc; goto L_exit; } }
    s->r[15] = !s->r[0] ? (s->bias + 636078u) : (s->bias + 636048u); { goto L_after_0009b484; }
L_after_0009b484:
    if (regs[15] == s->bias + 636078u) goto L_0009b4ae;
    goto L_exit;
L_0009b4ae:
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636078u, s->source_elf + 636078u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 2, s->r[5] + 8u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { goto L_after_0009b4ae; } result = rc; goto L_exit; } }
    { uint32_t addr = s->r[4] + (s->r[6] << 2u); if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[8]); }
    regs[15] = s->bias + 636084u;
L_after_0009b4ae:
    if (regs[15] == s->bias + 636084u) goto L_0009b4b4;
    goto L_exit;
L_0009b4b4:
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636084u, s->source_elf + 636084u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = !s->r[2] ? (s->bias + 636154u) : (s->bias + 636086u); { goto L_after_0009b4b4; }
L_after_0009b4b4:
    if (regs[15] == s->bias + 636086u) goto L_0009b4b6;
    goto L_exit;
L_0009b4b6:
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636086u, s->source_elf + 636086u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 4, 0u);
    agr_aot_mov_reg(s, 7, 4);
    s->r[15] = (s->bias + 636104u); { goto L_after_0009b4b6; }
L_after_0009b4b6:
    if (regs[15] == s->bias + 636104u) goto L_0009b4c8;
    goto L_exit;
L_0009b4c2:
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636098u, s->source_elf + 636098u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_adds(s, 4, s->r[4], 1u);
    agr_aot_cmp(s, s->r[2], s->r[4]);
    s->r[15] = agr_aot_condition(s, 9u) ? (s->bias + 636158u) : (s->bias + 636104u); { goto L_after_0009b4c2; }
L_after_0009b4c2:
    if (regs[15] == s->bias + 636158u) goto L_0009b4fe;
    if (regs[15] == s->bias + 636104u) goto L_0009b4c8;
    goto L_exit;
L_0009b4c8:
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636104u, s->source_elf + 636104u, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 12u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { goto L_after_0009b4c8; } result = rc; goto L_exit; } }
    agr_aot_lsls(s, 6, s->r[4], 2u);
    { int rc = agr_aot_ldr(s, 0, s->r[3] + (s->r[4] << 2u)); if (rc) { if (rc == AGR_AOT_BOUNDARY) { goto L_after_0009b4c8; } result = rc; goto L_exit; } }
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 636098u) : (s->bias + 636116u); { goto L_after_0009b4c8; }
L_after_0009b4c8:
    if (regs[15] == s->bias + 636098u) goto L_0009b4c2;
    goto L_exit;
L_0009b4fe:
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636158u, s->source_elf + 636158u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    if ((rc = agr_aot_ldmia_sp(s, 34800u))) { if (rc == AGR_AOT_BOUNDARY) { goto L_after_0009b4fe; } result = rc; goto L_exit; }
L_after_0009b4fe:
    goto L_exit;
L_exit:
    memcpy(outer->r, regs, sizeof(regs));
    *outer->cpsr = cpsr;
    return result;
}
int agr_attribution_payload(AgrAotRegs *state) { return agr_region_00000(state); }
