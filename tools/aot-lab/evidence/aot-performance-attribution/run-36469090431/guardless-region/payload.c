#include "agr_aot.h"

static int agr_region_00000(AgrAotRegs *outer) {
    uint32_t regs[16];
    memcpy(regs, outer->r, sizeof(regs));
    uint32_t cpsr = *outer->cpsr;
    AgrAotRegs local = {regs, &cpsr, outer->mem, outer->bias, 0, 0, 0, outer->source_elf, 0};
    AgrAotRegs *s = &local;
    int rc = 0, result = AGR_AOT_BOUNDARY;
    (void)rc;
    goto L_00000e94;
L_00000e94:
    if (agr_aot_stmdb_sp(s, 17400u)) { result = AGR_AOT_FAULT; goto L_exit; }
    regs[15] = s->bias + 3736u;
L_after_00000e94:
    if (regs[15] == s->bias + 3736u) goto L_00000e98;
    goto L_exit;
L_00000e98:
    agr_aot_mov_reg(s, 7, 3);
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { goto L_after_00000e98; } result = rc; goto L_exit; } }
    agr_aot_mov_reg(s, 8, 2);
    agr_aot_mov_reg(s, 1, 2);
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_movw(s, 9, 5126u);
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { goto L_after_00000e98; } result = rc; goto L_exit; } }
    agr_aot_branch_reg(s, s->r[3], (s->bias + 3758u), 1); { goto L_after_00000e98; }
L_after_00000e98:
    goto L_exit;
L_exit:
    memcpy(outer->r, regs, sizeof(regs));
    *outer->cpsr = cpsr;
    return result;
}
int agr_attribution_payload(AgrAotRegs *state) { return agr_region_00000(state); }
