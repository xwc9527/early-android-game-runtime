#include "agr_aot.h"

static int aot_debug_00000cfc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, (s->bias + 3324u)) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, (s->bias + 3332u), 0u);
    s->r[15] = (s->bias + 3328u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000d00(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, (s->bias + 3328u)) != 3800877570u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    s->r[15] = (s->bias + 3332u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000d04(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, (s->bias + 3332u)) != 3854365392u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[12] + 720u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_00000d08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, (s->bias + 3336u)) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, (s->bias + 3344u), 0u);
    s->r[15] = (s->bias + 3340u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000d0c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, (s->bias + 3340u)) != 3800877570u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    s->r[15] = (s->bias + 3344u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000d10(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, (s->bias + 3344u)) != 3854365384u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[12] + 712u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_00000d14(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, (s->bias + 3348u)) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, (s->bias + 3356u), 0u);
    s->r[15] = (s->bias + 3352u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000d18(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, (s->bias + 3352u)) != 3800877570u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    s->r[15] = (s->bias + 3356u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000d1c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, (s->bias + 3356u)) != 3854365376u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[12] + 704u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_00000d20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, (s->bias + 3360u)) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, (s->bias + 3368u), 0u);
    s->r[15] = (s->bias + 3364u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000d24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, (s->bias + 3364u)) != 3800877570u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    s->r[15] = (s->bias + 3368u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000d28(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, (s->bias + 3368u)) != 3854365368u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[12] + 696u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_00000d2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, (s->bias + 3372u)) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, (s->bias + 3380u), 0u);
    s->r[15] = (s->bias + 3376u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000d30(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, (s->bias + 3376u)) != 3800877570u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    s->r[15] = (s->bias + 3380u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000d34(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, (s->bias + 3380u)) != 3854365360u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[12] + 688u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_00000d38(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, (s->bias + 3384u)) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, (s->bias + 3392u), 0u);
    s->r[15] = (s->bias + 3388u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000d3c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, (s->bias + 3388u)) != 3800877570u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    s->r[15] = (s->bias + 3392u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000d40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, (s->bias + 3392u)) != 3854365352u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[12] + 680u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_00000d44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, (s->bias + 3396u)) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, (s->bias + 3404u), 0u);
    s->r[15] = (s->bias + 3400u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000d48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, (s->bias + 3400u)) != 3800877570u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    s->r[15] = (s->bias + 3404u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000d4c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, (s->bias + 3404u)) != 3854365344u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[12] + 672u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_00000d50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, (s->bias + 3408u)) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, (s->bias + 3416u), 0u);
    s->r[15] = (s->bias + 3412u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000d54(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, (s->bias + 3412u)) != 3800877570u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    s->r[15] = (s->bias + 3416u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000d58(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, (s->bias + 3416u)) != 3854365336u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[12] + 664u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_00000d80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, (s->bias + 3456u)) != 3852402692u) return AGR_AOT_MISS;
    { uint32_t addr = (s->bias + 3464u) + 4u; if ((rc = agr_aot_ldr(s, 0, addr))) return rc; }
    s->r[15] = (s->bias + 3460u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000d84(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, (s->bias + 3460u)) != 3767468032u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 0, (s->bias + 3468u), s->r[0]);
    s->r[15] = (s->bias + 3464u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000dc4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3524u)) != 59693u || agr_aot_load16(s, (s->bias + 3526u)) != 20472u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 20472u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 3528u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000dc8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3528u)) != 18074u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 10, 3);
    s->r[15] = (s->bias + 3530u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000dca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3530u)) != 26627u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = (s->bias + 3532u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000dcc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3532u)) != 17937u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 2);
    s->r[15] = (s->bias + 3534u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000dce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3534u)) != 18064u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 8, 2);
    s->r[15] = (s->bias + 3536u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000dd0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3536u)) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = (s->bias + 3538u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000dd2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3538u)) != 17924u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = (s->bias + 3540u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000dd4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3540u)) != 40458u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 6, s->r[13] + 40u); if (rc) return rc; }
    s->r[15] = (s->bias + 3542u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000dd6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3542u)) != 63699u || agr_aot_load16(s, (s->bias + 3544u)) != 13044u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) return rc; }
    s->r[15] = (s->bias + 3546u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000dda(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3546u)) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], (s->bias + 3548u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ddc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3548u)) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = (s->bias + 3550u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000dde(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3550u)) != 18001u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 10);
    s->r[15] = (s->bias + 3552u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000de0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3552u)) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = (s->bias + 3554u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000de2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3554u)) != 63699u || agr_aot_load16(s, (s->bias + 3556u)) != 13044u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) return rc; }
    s->r[15] = (s->bias + 3558u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000de6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3558u)) != 17927u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 7, 0);
    s->r[15] = (s->bias + 3560u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000de8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3560u)) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = (s->bias + 3562u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000dea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3562u)) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], (s->bias + 3564u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000dec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3564u)) != 18049u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 9, 0);
    s->r[15] = (s->bias + 3566u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000dee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3566u)) != 45382u) return AGR_AOT_MISS;
    s->r[15] = !s->r[6] ? (s->bias + 3586u) : (s->bias + 3568u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000df0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3568u)) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = (s->bias + 3570u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000df2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3570u)) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = (s->bias + 3572u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000df4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3572u)) != 17969u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 6);
    s->r[15] = (s->bias + 3574u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000df6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3574u)) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = (s->bias + 3576u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000df8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3576u)) != 63699u || agr_aot_load16(s, (s->bias + 3578u)) != 13036u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 748u); if (rc) return rc; }
    s->r[15] = (s->bias + 3580u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000dfc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3580u)) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], (s->bias + 3582u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000dfe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3582u)) != 17925u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = (s->bias + 3584u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e00(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3584u)) != 57344u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 3588u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3586u)) != 17973u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 6);
    s->r[15] = (s->bias + 3588u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e04(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3588u)) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = (s->bias + 3590u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e06(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3590u)) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = (s->bias + 3592u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3592u)) != 39179u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 44u); if (rc) return rc; }
    s->r[15] = (s->bias + 3594u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e0a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3594u)) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = (s->bias + 3596u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e0c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3596u)) != 63699u || agr_aot_load16(s, (s->bias + 3598u)) != 13032u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 744u); if (rc) return rc; }
    s->r[15] = (s->bias + 3600u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e10(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3600u)) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], (s->bias + 3602u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e12(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3602u)) != 62017u || agr_aot_load16(s, (s->bias + 3604u)) != 16646u) return AGR_AOT_MISS;
    agr_aot_movw(s, 1, 5126u);
    s->r[15] = (s->bias + 3606u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e16(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3606u)) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = (s->bias + 3608u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e18(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3608u)) != 17979u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 7);
    s->r[15] = (s->bias + 3610u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e1a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3610u)) != 18051u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 11, 0);
    s->r[15] = (s->bias + 3612u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e1c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3612u)) != 8195u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 3u);
    s->r[15] = (s->bias + 3614u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e1e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3614u)) != 63487u || agr_aot_load16(s, (s->bias + 3616u)) != 61300u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 3336u), (s->bias + 3618u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e22(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3618u)) != 8196u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 4u);
    s->r[15] = (s->bias + 3620u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3620u)) != 62017u || agr_aot_load16(s, (s->bias + 3622u)) != 16646u) return AGR_AOT_MISS;
    agr_aot_movw(s, 1, 5126u);
    s->r[15] = (s->bias + 3624u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e28(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3624u)) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = (s->bias + 3626u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e2a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3626u)) != 17995u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 9);
    s->r[15] = (s->bias + 3628u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3628u)) != 63487u || agr_aot_load16(s, (s->bias + 3630u)) != 61298u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 3348u), (s->bias + 3632u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e30(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3632u)) != 45365u) return AGR_AOT_MISS;
    s->r[15] = !s->r[5] ? (s->bias + 3648u) : (s->bias + 3634u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e32(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3634u)) != 8194u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    s->r[15] = (s->bias + 3636u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e34(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3636u)) != 62017u || agr_aot_load16(s, (s->bias + 3638u)) != 16652u) return AGR_AOT_MISS;
    agr_aot_movw(s, 1, 5132u);
    s->r[15] = (s->bias + 3640u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e38(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3640u)) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = (s->bias + 3642u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e3a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3642u)) != 17963u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 5);
    s->r[15] = (s->bias + 3644u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e3c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3644u)) != 63487u || agr_aot_load16(s, (s->bias + 3646u)) != 61296u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 3360u), (s->bias + 3648u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3648u)) != 8196u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 4u);
    s->r[15] = (s->bias + 3650u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e42(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3650u)) != 39180u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 48u); if (rc) return rc; }
    s->r[15] = (s->bias + 3652u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3652u)) != 62017u || agr_aot_load16(s, (s->bias + 3654u)) != 16899u) return AGR_AOT_MISS;
    agr_aot_movw(s, 2, 5123u);
    s->r[15] = (s->bias + 3656u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3656u)) != 18011u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 11);
    s->r[15] = (s->bias + 3658u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e4a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3658u)) != 63487u || agr_aot_load16(s, (s->bias + 3660u)) != 61296u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 3372u), (s->bias + 3662u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e4e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3662u)) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = (s->bias + 3664u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3664u)) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = (s->bias + 3666u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e52(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3666u)) != 39179u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 44u); if (rc) return rc; }
    s->r[15] = (s->bias + 3668u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e54(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3668u)) != 18010u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 11);
    s->r[15] = (s->bias + 3670u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e56(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3670u)) != 63699u || agr_aot_load16(s, (s->bias + 3672u)) != 49928u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 12, s->r[3] + 776u); if (rc) return rc; }
    s->r[15] = (s->bias + 3674u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e5a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3674u)) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = (s->bias + 3676u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e5c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3676u)) != 18400u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[12], (s->bias + 3678u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e5e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3678u)) != 45373u) return AGR_AOT_MISS;
    s->r[15] = !s->r[5] ? (s->bias + 3696u) : (s->bias + 3680u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e60(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3680u)) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = (s->bias + 3682u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e62(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3682u)) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = (s->bias + 3684u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3684u)) != 17969u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 6);
    s->r[15] = (s->bias + 3686u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e66(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3686u)) != 17962u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 5);
    s->r[15] = (s->bias + 3688u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e68(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3688u)) != 63699u || agr_aot_load16(s, (s->bias + 3690u)) != 49932u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 12, s->r[3] + 780u); if (rc) return rc; }
    s->r[15] = (s->bias + 3692u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e6c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3692u)) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = (s->bias + 3694u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e6e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3694u)) != 18400u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[12], (s->bias + 3696u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e70(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3696u)) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = (s->bias + 3698u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3698u)) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = (s->bias + 3700u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e74(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3700u)) != 18001u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 10);
    s->r[15] = (s->bias + 3702u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e76(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3702u)) != 17994u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 9);
    s->r[15] = (s->bias + 3704u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3704u)) != 63699u || agr_aot_load16(s, (s->bias + 3706u)) != 21268u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 5, s->r[3] + 788u); if (rc) return rc; }
    s->r[15] = (s->bias + 3708u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e7c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3708u)) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = (s->bias + 3710u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e7e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3710u)) != 18344u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[5], (s->bias + 3712u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3712u)) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = (s->bias + 3714u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e82(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3714u)) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = (s->bias + 3716u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e84(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3716u)) != 17985u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 8);
    s->r[15] = (s->bias + 3718u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e86(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3718u)) != 17978u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 7);
    s->r[15] = (s->bias + 3720u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e88(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3720u)) != 63699u || agr_aot_load16(s, (s->bias + 3722u)) != 21268u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 5, s->r[3] + 788u); if (rc) return rc; }
    s->r[15] = (s->bias + 3724u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e8c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3724u)) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = (s->bias + 3726u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e8e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3726u)) != 18344u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[5], (s->bias + 3728u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e90(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3728u)) != 59581u || agr_aot_load16(s, (s->bias + 3730u)) != 36856u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 36856u))) return rc;
}

static int aot_debug_00000e94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3732u)) != 59693u || agr_aot_load16(s, (s->bias + 3734u)) != 17400u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 17400u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 3736u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e98(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3736u)) != 17951u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 7, 3);
    s->r[15] = (s->bias + 3738u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e9a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3738u)) != 26627u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = (s->bias + 3740u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e9c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3740u)) != 18064u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 8, 2);
    s->r[15] = (s->bias + 3742u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000e9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3742u)) != 17937u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 2);
    s->r[15] = (s->bias + 3744u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ea0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3744u)) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = (s->bias + 3746u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ea2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3746u)) != 17924u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = (s->bias + 3748u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ea4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3748u)) != 62017u || agr_aot_load16(s, (s->bias + 3750u)) != 18694u) return AGR_AOT_MISS;
    agr_aot_movw(s, 9, 5126u);
    s->r[15] = (s->bias + 3752u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ea8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3752u)) != 63699u || agr_aot_load16(s, (s->bias + 3754u)) != 13044u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) return rc; }
    s->r[15] = (s->bias + 3756u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000eac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3756u)) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], (s->bias + 3758u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000eae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3758u)) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = (s->bias + 3760u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000eb0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3760u)) != 17977u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 7);
    s->r[15] = (s->bias + 3762u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000eb2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3762u)) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = (s->bias + 3764u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000eb4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3764u)) != 63699u || agr_aot_load16(s, (s->bias + 3766u)) != 13044u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) return rc; }
    s->r[15] = (s->bias + 3768u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000eb8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3768u)) != 17925u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = (s->bias + 3770u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000eba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3770u)) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = (s->bias + 3772u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ebc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3772u)) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], (s->bias + 3774u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ebe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3774u)) != 17993u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 9);
    s->r[15] = (s->bias + 3776u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ec0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3776u)) != 17963u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 5);
    s->r[15] = (s->bias + 3778u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ec2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3778u)) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = (s->bias + 3780u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ec4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3780u)) != 17926u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 6, 0);
    s->r[15] = (s->bias + 3782u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ec6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3782u)) != 8194u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    s->r[15] = (s->bias + 3784u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ec8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3784u)) != 63487u || agr_aot_load16(s, (s->bias + 3786u)) != 61214u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 3336u), (s->bias + 3788u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ecc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3788u)) != 17971u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 6);
    s->r[15] = (s->bias + 3790u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ece(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3790u)) != 17993u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 9);
    s->r[15] = (s->bias + 3792u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ed0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3792u)) != 8196u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 4u);
    s->r[15] = (s->bias + 3794u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ed2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3794u)) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = (s->bias + 3796u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ed4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3796u)) != 63487u || agr_aot_load16(s, (s->bias + 3798u)) != 61214u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 3348u), (s->bias + 3800u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ed8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3800u)) != 39432u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[13] + 32u); if (rc) return rc; }
    s->r[15] = (s->bias + 3802u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000eda(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3802u)) != 8193u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = (s->bias + 3804u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000edc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3804u)) != 8448u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = (s->bias + 3806u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ede(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3806u)) != 63487u || agr_aot_load16(s, (s->bias + 3808u)) != 61228u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 3384u), (s->bias + 3810u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ee2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3810u)) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = (s->bias + 3812u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ee4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3812u)) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = (s->bias + 3814u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ee6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3814u)) != 17977u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 7);
    s->r[15] = (s->bias + 3816u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ee8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3816u)) != 17970u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = (s->bias + 3818u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000eea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3818u)) != 63699u || agr_aot_load16(s, (s->bias + 3820u)) != 49940u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 12, s->r[3] + 788u); if (rc) return rc; }
    s->r[15] = (s->bias + 3822u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000eee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3822u)) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = (s->bias + 3824u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ef0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3824u)) != 18400u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[12], (s->bias + 3826u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ef2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3826u)) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = (s->bias + 3828u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ef4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3828u)) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = (s->bias + 3830u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ef6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3830u)) != 17985u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 8);
    s->r[15] = (s->bias + 3832u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ef8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3832u)) != 17962u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 5);
    s->r[15] = (s->bias + 3834u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000efa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3834u)) != 63699u || agr_aot_load16(s, (s->bias + 3836u)) != 25364u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 6, s->r[3] + 788u); if (rc) return rc; }
    s->r[15] = (s->bias + 3838u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000efe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3838u)) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = (s->bias + 3840u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f00(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3840u)) != 18352u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[6], (s->bias + 3842u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3842u)) != 59581u || agr_aot_load16(s, (s->bias + 3844u)) != 33784u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 33784u))) return rc;
}

static int aot_debug_00000f08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3848u)) != 26627u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = (s->bias + 3850u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f0a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3850u)) != 90u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 2, s->r[3], 1u);
    s->r[15] = (s->bias + 3852u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f0c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3852u)) != 48972u) return AGR_AOT_MISS;
    agr_aot_set_itstate(s, 76u); s->r[15] = (s->bias + 3854u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f1a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3866u)) != 59693u || agr_aot_load16(s, (s->bias + 3868u)) != 20471u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 20471u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 3870u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f1e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3870u)) != 18049u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 9, 0);
    s->r[15] = (s->bias + 3872u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3872u)) != 17942u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 6, 2);
    s->r[15] = (s->bias + 3874u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f22(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3874u)) != 45857u) return AGR_AOT_MISS;
    s->r[15] = !s->r[1] ? (s->bias + 3950u) : (s->bias + 3876u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3876u)) != 61697u || agr_aot_load16(s, (s->bias + 3878u)) != 14591u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 8, s->r[1], 1023u);
    s->r[15] = (s->bias + 3880u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f28(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3880u)) != 9984u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 7, 0u);
    s->r[15] = (s->bias + 3882u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f2a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3882u)) != 18114u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 10, 8);
    s->r[15] = (s->bias + 3884u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3884u)) != 60167u || agr_aot_load16(s, (s->bias + 3886u)) != 1034u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 4, s->r[7], s->r[10]);
    s->r[15] = (s->bias + 3888u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f36(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3894u)) != 227u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 3, s->r[4], 3u);
    s->r[15] = (s->bias + 3896u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f38(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3896u)) != 37633u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = (s->bias + 3898u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f3a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3898u)) != 60169u || agr_aot_load16(s, (s->bias + 3900u)) != 1283u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 5, s->r[9], s->r[3]);
    s->r[15] = (s->bias + 3902u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f3e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3902u)) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = (s->bias + 3904u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3904u)) != 63487u || agr_aot_load16(s, (s->bias + 3906u)) != 65506u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 3848u) | 1u, (s->bias + 3908u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3908u)) != 17732u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[4], s->r[8]);
    s->r[15] = (s->bias + 3910u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f46(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3910u)) != 39681u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 4u); if (rc) return rc; }
    s->r[15] = (s->bias + 3912u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3912u)) != 18051u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 11, 0);
    s->r[15] = (s->bias + 3914u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f4a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3914u)) != 53268u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 3958u) : (s->bias + 3916u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f4c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3916u)) != 61699u || agr_aot_load16(s, (s->bias + 3918u)) != 8u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 0, s->r[3], 8u);
    s->r[15] = (s->bias + 3920u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3920u)) != 17480u) return AGR_AOT_MISS;
    s->r[0] += s->r[9];
    s->r[15] = (s->bias + 3922u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f52(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3922u)) != 63487u || agr_aot_load16(s, (s->bias + 3924u)) != 65497u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 3848u) | 1u, (s->bias + 3926u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f56(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3926u)) != 17758u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[6], s->r[11]);
    s->r[15] = (s->bias + 3928u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f58(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3928u)) != 53764u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 2u) ? (s->bias + 3940u) : (s->bias + 3930u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f5a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3930u)) != 17084u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[4], s->r[7]);
    s->r[15] = (s->bias + 3932u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f5c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3932u)) != 53257u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 3954u) : (s->bias + 3934u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f5e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3934u)) != 61700u || agr_aot_load16(s, (s->bias + 3936u)) != 15103u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 10, s->r[4], 1023u);
    s->r[15] = (s->bias + 3938u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f62(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3938u)) != 59363u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 3884u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3940u)) != 14337u) return AGR_AOT_MISS;
    agr_aot_subs(s, 0, s->r[0], 1u);
    s->r[15] = (s->bias + 3942u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f66(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3942u)) != 17030u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[6], s->r[0]);
    s->r[15] = (s->bias + 3944u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f68(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3944u)) != 55559u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 9u) ? (s->bias + 3962u) : (s->bias + 3946u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f6a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3946u)) != 7271u) return AGR_AOT_MISS;
    agr_aot_adds(s, 7, s->r[4], 1u);
    s->r[15] = (s->bias + 3948u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f6c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3948u)) != 59358u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 3884u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f6e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3950u)) != 17933u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 1);
    s->r[15] = (s->bias + 3952u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f70(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3952u)) != 57347u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 3962u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3954u)) != 9472u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 5, 0u);
    s->r[15] = (s->bias + 3956u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f74(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3956u)) != 57345u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 3962u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f76(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3958u)) != 17030u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[6], s->r[0]);
    s->r[15] = (s->bias + 3960u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3960u)) != 54255u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 3u) ? (s->bias + 3930u) : (s->bias + 3962u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f7a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3962u)) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = (s->bias + 3964u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f7c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3964u)) != 45059u) return AGR_AOT_MISS;
    s->r[13] += 12u;
    s->r[15] = (s->bias + 3966u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f7e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3966u)) != 59581u || agr_aot_load16(s, (s->bias + 3968u)) != 36848u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 36848u))) return rc;
}

static int aot_debug_00000f82(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3970u)) != 10241u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 1u);
    s->r[15] = (s->bias + 3972u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f84(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3972u)) != 53254u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 3988u) : (s->bias + 3974u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f86(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3974u)) != 10242u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 2u);
    s->r[15] = (s->bias + 3976u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f88(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3976u)) != 53256u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 3996u) : (s->bias + 3978u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3978u)) != 47448u) return AGR_AOT_MISS;
    s->r[15] = s->r[0] ? (s->bias + 4004u) : (s->bias + 3980u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f8c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3980u)) != 18438u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, (s->bias + 3984u) + 24u); if (rc) return rc; }
    s->r[15] = (s->bias + 3982u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f8e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3982u)) != 17528u) return AGR_AOT_MISS;
    s->r[0] += (s->bias + 3986u);
    s->r[15] = (s->bias + 3984u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f90(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3984u)) != 26624u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = (s->bias + 3986u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f92(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3986u)) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3988u)) != 18437u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, (s->bias + 3992u) + 20u); if (rc) return rc; }
    s->r[15] = (s->bias + 3990u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f96(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3990u)) != 17528u) return AGR_AOT_MISS;
    s->r[0] += (s->bias + 3994u);
    s->r[15] = (s->bias + 3992u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f98(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3992u)) != 26624u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = (s->bias + 3994u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f9a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3994u)) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f9c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3996u)) != 18436u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, (s->bias + 4000u) + 16u); if (rc) return rc; }
    s->r[15] = (s->bias + 3998u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000f9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 3998u)) != 17528u) return AGR_AOT_MISS;
    s->r[0] += (s->bias + 4002u);
    s->r[15] = (s->bias + 4000u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fa0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4000u)) != 26624u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = (s->bias + 4002u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fa2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4002u)) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fa4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4004u)) != 8192u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = (s->bias + 4006u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fa6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4006u)) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fa8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4008u)) != 8214u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 22u);
    s->r[15] = (s->bias + 4010u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000faa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4010u)) != 0u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 0, s->r[0], 0u);
    s->r[15] = (s->bias + 4012u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4012u)) != 8210u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 18u);
    s->r[15] = (s->bias + 4014u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4014u)) != 0u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 0, s->r[0], 0u);
    s->r[15] = (s->bias + 4016u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fb0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4016u)) != 8206u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 14u);
    s->r[15] = (s->bias + 4018u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fb2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4018u)) != 0u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 0, s->r[0], 0u);
    s->r[15] = (s->bias + 4020u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fb4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4020u)) != 19237u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, (s->bias + 4024u) + 148u); if (rc) return rc; }
    s->r[15] = (s->bias + 4022u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fb6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4022u)) != 46451u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16499u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 4024u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fb8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4024u)) != 17531u) return AGR_AOT_MISS;
    s->r[3] += (s->bias + 4028u);
    s->r[15] = (s->bias + 4026u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4026u)) != 26651u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = (s->bias + 4028u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fbc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4028u)) != 17924u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = (s->bias + 4030u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fbe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4030u)) != 7822u) return AGR_AOT_MISS;
    agr_aot_subs(s, 6, s->r[1], 2u);
    s->r[15] = (s->bias + 4032u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fc0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4032u)) != 45363u) return AGR_AOT_MISS;
    s->r[15] = !s->r[3] ? (s->bias + 4048u) : (s->bias + 4034u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fc2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4034u)) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = (s->bias + 4036u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fc4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4036u)) != 43265u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    s->r[15] = (s->bias + 4038u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fc6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4038u)) != 63487u || agr_aot_load16(s, (s->bias + 4040u)) != 61118u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 3396u), (s->bias + 4042u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4042u)) != 17925u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = (s->bias + 4044u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fcc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4044u)) != 47445u) return AGR_AOT_MISS;
    s->r[15] = s->r[5] ? (s->bias + 4068u) : (s->bias + 4046u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4046u)) != 57359u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 4080u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fd0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4048u)) != 19743u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 5, (s->bias + 4052u) + 124u); if (rc) return rc; }
    s->r[15] = (s->bias + 4050u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fd2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4050u)) != 19232u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, (s->bias + 4052u) + 128u); if (rc) return rc; }
    s->r[15] = (s->bias + 4052u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fd4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4052u)) != 17533u) return AGR_AOT_MISS;
    s->r[5] += (s->bias + 4056u);
    s->r[15] = (s->bias + 4054u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fd6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4054u)) != 26669u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 5, s->r[5] + 0u); if (rc) return rc; }
    s->r[15] = (s->bias + 4056u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fd8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4056u)) != 17531u) return AGR_AOT_MISS;
    s->r[3] += (s->bias + 4060u);
    s->r[15] = (s->bias + 4058u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fda(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4058u)) != 26651u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = (s->bias + 4060u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fdc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4060u)) != 6893u) return AGR_AOT_MISS;
    agr_aot_subs(s, 5, s->r[5], s->r[3]);
    s->r[15] = (s->bias + 4062u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fde(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4062u)) != 17944u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 3);
    s->r[15] = (s->bias + 4064u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fe2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4066u)) != 38145u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    s->r[15] = (s->bias + 4068u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fe4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4068u)) != 39169u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 4u); if (rc) return rc; }
    s->r[15] = (s->bias + 4070u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fe6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4070u)) != 17970u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = (s->bias + 4072u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fe8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4072u)) != 63487u || agr_aot_load16(s, (s->bias + 4074u)) != 65431u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 3866u) | 1u, (s->bias + 4076u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4076u)) != 17925u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = (s->bias + 4078u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000fee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4078u)) != 47376u) return AGR_AOT_MISS;
    s->r[15] = s->r[0] ? (s->bias + 4086u) : (s->bias + 4080u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ff0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4080u)) != 24869u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    s->r[15] = (s->bias + 4082u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ff2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4082u)) != 8201u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 9u);
    s->r[15] = (s->bias + 4084u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ff4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4084u)) != 57383u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 4166u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ff6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4086u)) != 63487u || agr_aot_load16(s, (s->bias + 4088u)) != 65415u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 3848u) | 1u, (s->bias + 4090u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ffa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4090u)) != 26731u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 4u); if (rc) return rc; }
    s->r[15] = (s->bias + 4092u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ffc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4092u)) != 11009u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 1u);
    s->r[15] = (s->bias + 4094u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00000ffe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4094u)) != 25760u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[4] + 72u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = (s->bias + 4096u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001000(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4096u)) != 53507u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 4106u) : (s->bias + 4098u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001002(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4098u)) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = (s->bias + 4100u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001004(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4100u)) != 8197u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 5u);
    s->r[15] = (s->bias + 4102u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001006(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4102u)) != 24867u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = (s->bias + 4104u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001008(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4104u)) != 57373u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 4166u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000100a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4106u)) != 11008u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 0u);
    s->r[15] = (s->bias + 4108u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000100c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4108u)) != 61701u || agr_aot_load16(s, (s->bias + 4110u)) != 4u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 0, s->r[5], 4u);
    s->r[15] = (s->bias + 4112u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001010(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4112u)) != 55810u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 10u) ? (s->bias + 4120u) : (s->bias + 4114u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001012(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4114u)) != 25824u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[4] + 76u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = (s->bias + 4116u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001014(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4116u)) != 8961u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 1u);
    s->r[15] = (s->bias + 4118u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001016(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4118u)) != 57347u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 4128u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001018(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4120u)) != 63487u || agr_aot_load16(s, (s->bias + 4122u)) != 65398u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 3848u) | 1u, (s->bias + 4124u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000101c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4124u)) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = (s->bias + 4126u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000101e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4126u)) != 25824u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[4] + 76u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = (s->bias + 4128u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001020(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4128u)) != 27872u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[4] + 76u); if (rc) return rc; }
    s->r[15] = (s->bias + 4130u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001022(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4130u)) != 25891u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[4] + 80u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = (s->bias + 4132u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001024(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4132u)) != 26627u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = (s->bias + 4134u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001026(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4134u)) != 11008u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 0u);
    s->r[15] = (s->bias + 4136u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001028(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4136u)) != 55817u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 10u) ? (s->bias + 4158u) : (s->bias + 4138u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000102e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4142u)) != 63487u || agr_aot_load16(s, (s->bias + 4144u)) != 65448u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 3970u) | 1u, (s->bias + 4146u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001032(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4146u)) != 24864u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = (s->bias + 4148u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001034(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4148u)) != 10240u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = (s->bias + 4150u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001036(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4150u)) != 48908u) return AGR_AOT_MISS;
    agr_aot_set_itstate(s, 12u); s->r[15] = (s->bias + 4152u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000103e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4158u)) != 63487u || agr_aot_load16(s, (s->bias + 4160u)) != 65379u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 3848u) | 1u, (s->bias + 4162u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001042(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4162u)) != 24864u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = (s->bias + 4164u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001044(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4164u)) != 8192u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = (s->bias + 4166u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001046(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4166u)) != 45058u) return AGR_AOT_MISS;
    s->r[13] += 8u;
    s->r[15] = (s->bias + 4168u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001048(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4168u)) != 48496u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_debug_00001058(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4184u)) != 26627u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = (s->bias + 4186u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000105a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4186u)) != 46352u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 4188u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000105c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4188u)) != 17924u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = (s->bias + 4190u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000105e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4190u)) != 2008u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 0, s->r[3], 31u);
    s->r[15] = (s->bias + 4192u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001060(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4192u)) != 54281u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 4u) ? (s->bias + 4214u) : (s->bias + 4194u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001066(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4198u)) != 61700u || agr_aot_load16(s, (s->bias + 4200u)) != 72u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 72u);
    s->r[15] = (s->bias + 4202u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000106a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4202u)) != 53250u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 4210u) : (s->bias + 4204u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000106c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4204u)) != 61440u || agr_aot_load16(s, (s->bias + 4206u)) != 64514u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 6260u) | 1u, (s->bias + 4208u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001070(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4208u)) != 57345u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 4214u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001072(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4210u)) != 61440u || agr_aot_load16(s, (s->bias + 4212u)) != 64503u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 6244u) | 1u, (s->bias + 4214u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001076(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4214u)) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = (s->bias + 4216u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001078(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4216u)) != 1881u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 1, s->r[3], 29u);
    s->r[15] = (s->bias + 4218u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000107a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4218u)) != 54275u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 4u) ? (s->bias + 4228u) : (s->bias + 4220u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000107c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4220u)) != 61700u || agr_aot_load16(s, (s->bias + 4222u)) != 208u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 208u);
    s->r[15] = (s->bias + 4224u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001080(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4224u)) != 61440u || agr_aot_load16(s, (s->bias + 4226u)) != 64512u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 6276u) | 1u, (s->bias + 4228u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001084(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4228u)) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = (s->bias + 4230u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001086(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4230u)) != 1818u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 2, s->r[3], 28u);
    s->r[15] = (s->bias + 4232u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001088(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4232u)) != 54275u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 4u) ? (s->bias + 4242u) : (s->bias + 4234u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000108a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4234u)) != 62724u || agr_aot_load16(s, (s->bias + 4236u)) != 28840u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 4008u);
    s->r[15] = (s->bias + 4238u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000108e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4238u)) != 61440u || agr_aot_load16(s, (s->bias + 4240u)) != 64513u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 6292u) | 1u, (s->bias + 4242u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001092(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4242u)) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = (s->bias + 4244u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001094(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4244u)) != 1755u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 3, s->r[3], 27u);
    s->r[15] = (s->bias + 4246u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001096(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4246u)) != 54277u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 4u) ? (s->bias + 4260u) : (s->bias + 4248u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001098(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4248u)) != 62724u || agr_aot_load16(s, (s->bias + 4250u)) != 28904u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 4072u);
    s->r[15] = (s->bias + 4252u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000109c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4252u)) != 59581u || agr_aot_load16(s, (s->bias + 4254u)) != 16400u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 16400u))) return rc;
    s->r[15] = (s->bias + 4256u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4256u)) != 61440u || agr_aot_load16(s, (s->bias + 4258u)) != 48188u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 6428u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010a4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4260u)) != 48400u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_debug_000010b6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4278u)) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4280u)) != 46448u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 4282u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010ba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4282u)) != 17925u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = (s->bias + 4284u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010bc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4284u)) != 17932u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 1);
    s->r[15] = (s->bias + 4286u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010be(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4286u)) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = (s->bias + 4288u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4288u)) != 27681u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 64u); if (rc) return rc; }
    s->r[15] = (s->bias + 4290u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010c2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4290u)) != 63487u || agr_aot_load16(s, (s->bias + 4292u)) != 65399u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 4020u) | 1u, (s->bias + 4294u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010c6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4294u)) != 17926u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 6, 0);
    s->r[15] = (s->bias + 4296u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4296u)) != 45320u) return AGR_AOT_MISS;
    s->r[15] = !s->r[0] ? (s->bias + 4302u) : (s->bias + 4298u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4298u)) != 63487u || agr_aot_load16(s, (s->bias + 4300u)) != 60994u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 3408u), (s->bias + 4302u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010ce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4302u)) != 27683u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 64u); if (rc) return rc; }
    s->r[15] = (s->bias + 4304u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010d0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4304u)) != 8193u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = (s->bias + 4306u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010d2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4306u)) != 17961u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 5);
    s->r[15] = (s->bias + 4308u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4308u)) != 17954u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 4);
    s->r[15] = (s->bias + 4310u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010d6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4310u)) != 24939u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[5] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = (s->bias + 4312u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010d8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4312u)) != 26923u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 16u); if (rc) return rc; }
    s->r[15] = (s->bias + 4314u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010da(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4314u)) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], (s->bias + 4316u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4316u)) != 10248u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 8u);
    s->r[15] = (s->bias + 4318u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010de(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4318u)) != 53486u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 4286u) : (s->bias + 4320u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4320u)) != 10247u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 7u);
    s->r[15] = (s->bias + 4322u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010e2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4322u)) != 53746u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 4298u) : (s->bias + 4324u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4324u)) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = (s->bias + 4326u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010e6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4326u)) != 27681u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 64u); if (rc) return rc; }
    s->r[15] = (s->bias + 4328u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010e8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4328u)) != 63487u || agr_aot_load16(s, (s->bias + 4330u)) != 65509u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 4278u) | 1u, (s->bias + 4332u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010ec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4332u)) != 7456u) return AGR_AOT_MISS;
    agr_aot_adds(s, 0, s->r[4], 4u);
    s->r[15] = (s->bias + 4334u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010ee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4334u)) != 61440u || agr_aot_load16(s, (s->bias + 4336u)) != 64429u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 6220u) | 1u, (s->bias + 4338u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4338u)) != 59693u || agr_aot_load16(s, (s->bias + 4340u)) != 20464u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 20464u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 4342u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010f6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4342u)) != 7437u) return AGR_AOT_MISS;
    agr_aot_adds(s, 5, s->r[1], 4u);
    s->r[15] = (s->bias + 4344u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010f8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4344u)) != 63696u || agr_aot_load16(s, (s->bias + 4346u)) != 32780u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 8, s->r[0] + 12u); if (rc) return rc; }
    s->r[15] = (s->bias + 4348u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4348u)) != 17927u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 7, 0);
    s->r[15] = (s->bias + 4350u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000010fe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4350u)) != 63696u || agr_aot_load16(s, (s->bias + 4352u)) != 36888u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 9, s->r[0] + 24u); if (rc) return rc; }
    s->r[15] = (s->bias + 4354u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001102(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4354u)) != 18066u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 10, 2);
    s->r[15] = (s->bias + 4356u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000110a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4362u)) != 44035u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 4, s->r[13], 12u);
    s->r[15] = (s->bias + 4364u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000110c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4364u)) != 44546u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 6, s->r[13], 8u);
    s->r[15] = (s->bias + 4366u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000111c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4380u)) != 44410u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 5, s->r[13], 488u);
    s->r[15] = (s->bias + 4382u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000111e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4382u)) != 59524u || agr_aot_load16(s, (s->bias + 4384u)) != 15u) return AGR_AOT_MISS;
    if (agr_aot_stm(s, 4u, 15u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 4386u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001122(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4386u)) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = (s->bias + 4388u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001124(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4388u)) != 18075u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 11, 3);
    s->r[15] = (s->bias + 4390u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001126(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4390u)) != 24627u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[6] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = (s->bias + 4392u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001128(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4392u)) != 17976u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 7);
    s->r[15] = (s->bias + 4394u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000112a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4394u)) != 27697u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[6] + 64u); if (rc) return rc; }
    s->r[15] = (s->bias + 4396u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000112c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4396u)) != 63487u || agr_aot_load16(s, (s->bias + 4398u)) != 65346u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 4020u) | 1u, (s->bias + 4400u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001130(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4400u)) != 61882u || agr_aot_load16(s, (s->bias + 4402u)) != 3840u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[10], 0u);
    s->r[15] = (s->bias + 4404u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001134(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4404u)) != 48916u) return AGR_AOT_MISS;
    agr_aot_set_itstate(s, 20u); s->r[15] = (s->bias + 4406u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000011b4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4532u)) != 27712u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 68u); if (rc) return rc; }
    s->r[15] = (s->bias + 4534u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000011b6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4534u)) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000011b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4536u)) != 27595u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[1] + 60u); if (rc) return rc; }
    s->r[15] = (s->bias + 4538u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000011ba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4538u)) != 59693u || agr_aot_load16(s, (s->bias + 4540u)) != 16880u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16880u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 4542u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000011be(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4542u)) != 7437u) return AGR_AOT_MISS;
    agr_aot_adds(s, 5, s->r[1], 4u);
    s->r[15] = (s->bias + 4544u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000011c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4544u)) != 25611u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[1] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = (s->bias + 4546u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000011c2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4546u)) != 17927u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 7, 0);
    s->r[15] = (s->bias + 4548u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000011c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4548u)) != 17934u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 6, 1);
    s->r[15] = (s->bias + 4550u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000011c6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4550u)) != 45304u) return AGR_AOT_MISS;
    s->r[13] -= 480u;
    s->r[15] = (s->bias + 4552u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000011ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4554u)) != 44033u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 4, s->r[13], 4u);
    s->r[15] = (s->bias + 4556u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000011cc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4556u)) != 18152u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 8, 13);
    s->r[15] = (s->bias + 4558u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000011dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4572u)) != 59524u || agr_aot_load16(s, (s->bias + 4574u)) != 15u) return AGR_AOT_MISS;
    if (agr_aot_stm(s, 4u, 15u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 4576u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000011e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4576u)) != 61519u || agr_aot_load16(s, (s->bias + 4578u)) != 13311u) return AGR_AOT_MISS;
    s->r[3] = 4294967295u;
    s->r[15] = (s->bias + 4580u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000011e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4580u)) != 37632u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = (s->bias + 4582u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000011e6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4582u)) != 17976u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 7);
    s->r[15] = (s->bias + 4584u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000011e8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4584u)) != 63704u || agr_aot_load16(s, (s->bias + 4586u)) != 4160u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[8] + 64u); if (rc) return rc; }
    s->r[15] = (s->bias + 4588u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000011ec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4588u)) != 63487u || agr_aot_load16(s, (s->bias + 4590u)) != 65250u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 4020u) | 1u, (s->bias + 4592u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000011f0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4592u)) != 47480u) return AGR_AOT_MISS;
    s->r[15] = s->r[0] ? (s->bias + 4626u) : (s->bias + 4594u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000011f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4594u)) != 26939u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[7] + 16u); if (rc) return rc; }
    s->r[15] = (s->bias + 4596u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000011f4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4596u)) != 17977u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 7);
    s->r[15] = (s->bias + 4598u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000011f6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4598u)) != 18026u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 13);
    s->r[15] = (s->bias + 4600u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000011f8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4600u)) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], (s->bias + 4602u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000011fa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4602u)) != 10248u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 8u);
    s->r[15] = (s->bias + 4604u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000011fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4604u)) != 17924u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = (s->bias + 4606u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000011fe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4606u)) != 53490u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 4582u) : (s->bias + 4608u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001200(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4608u)) != 18024u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 13);
    s->r[15] = (s->bias + 4610u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001202(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4610u)) != 63487u || agr_aot_load16(s, (s->bias + 4612u)) != 65321u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 4184u) | 1u, (s->bias + 4614u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001206(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4614u)) != 11270u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[4], 6u);
    s->r[15] = (s->bias + 4616u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001208(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4616u)) != 53507u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 4626u) : (s->bias + 4618u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000120a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4618u)) != 17976u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 7);
    s->r[15] = (s->bias + 4620u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000120c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4620u)) != 17969u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 6);
    s->r[15] = (s->bias + 4622u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000120e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4622u)) != 63487u || agr_aot_load16(s, (s->bias + 4624u)) != 65363u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 4280u) | 1u, (s->bias + 4626u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001212(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4626u)) != 8201u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 9u);
    s->r[15] = (s->bias + 4628u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001214(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4628u)) != 45176u) return AGR_AOT_MISS;
    s->r[13] += 480u;
    s->r[15] = (s->bias + 4630u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001216(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4630u)) != 59581u || agr_aot_load16(s, (s->bias + 4632u)) != 33264u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) return rc;
}

static int aot_debug_0000121a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4634u)) != 46352u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 4636u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000121c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4636u)) != 24962u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[0] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = (s->bias + 4638u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000121e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4638u)) != 27610u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 60u); if (rc) return rc; }
    s->r[15] = (s->bias + 4640u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001220(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4640u)) != 24769u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[0] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    s->r[15] = (s->bias + 4642u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001222(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4642u)) != 17945u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 3);
    s->r[15] = (s->bias + 4644u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001224(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4644u)) != 59581u || agr_aot_load16(s, (s->bias + 4646u)) != 16400u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 16400u))) return rc;
    s->r[15] = (s->bias + 4648u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001228(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4648u)) != 25626u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[3] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = (s->bias + 4650u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000122a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4650u)) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = (s->bias + 4652u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000122c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4652u)) != 59233u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 4338u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000122e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4654u)) != 26947u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 20u); if (rc) return rc; }
    s->r[15] = (s->bias + 4656u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001230(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4656u)) != 46448u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 4658u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001232(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4658u)) != 17925u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = (s->bias + 4660u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001234(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4660u)) != 26822u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 6, s->r[0] + 12u); if (rc) return rc; }
    s->r[15] = (s->bias + 4662u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001236(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4662u)) != 17932u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 1);
    s->r[15] = (s->bias + 4664u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001238(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4664u)) != 25611u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[1] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = (s->bias + 4666u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000123a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4666u)) != 45342u) return AGR_AOT_MISS;
    s->r[15] = !s->r[6] ? (s->bias + 4676u) : (s->bias + 4668u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000123c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4668u)) != 8705u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = (s->bias + 4670u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000123e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4670u)) != 63487u || agr_aot_load16(s, (s->bias + 4672u)) != 65368u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 4338u) | 1u, (s->bias + 4674u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001242(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4674u)) != 57363u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 4716u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001244(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4676u)) != 26883u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 16u); if (rc) return rc; }
    s->r[15] = (s->bias + 4678u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001246(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4678u)) != 17961u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 5);
    s->r[15] = (s->bias + 4680u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001248(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4680u)) != 8194u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    s->r[15] = (s->bias + 4682u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000124a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4682u)) != 17954u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 4);
    s->r[15] = (s->bias + 4684u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000124c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4684u)) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], (s->bias + 4686u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000124e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4686u)) != 10247u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 7u);
    s->r[15] = (s->bias + 4688u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001250(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4688u)) != 53253u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 4702u) : (s->bias + 4690u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001252(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4690u)) != 10248u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 8u);
    s->r[15] = (s->bias + 4692u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001254(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4692u)) != 53514u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 4716u) : (s->bias + 4694u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001256(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4694u)) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = (s->bias + 4696u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001258(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4696u)) != 17953u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 4);
    s->r[15] = (s->bias + 4698u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000125a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4698u)) != 63487u || agr_aot_load16(s, (s->bias + 4700u)) != 65325u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 4280u) | 1u, (s->bias + 4702u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000125e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4702u)) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = (s->bias + 4704u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001260(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4704u)) != 27681u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 64u); if (rc) return rc; }
    s->r[15] = (s->bias + 4706u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001262(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4706u)) != 63487u || agr_aot_load16(s, (s->bias + 4708u)) != 65320u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 4278u) | 1u, (s->bias + 4710u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001266(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4710u)) != 7456u) return AGR_AOT_MISS;
    agr_aot_adds(s, 0, s->r[4], 4u);
    s->r[15] = (s->bias + 4712u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001268(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4712u)) != 61440u || agr_aot_load16(s, (s->bias + 4714u)) != 64240u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 6220u) | 1u, (s->bias + 4716u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000126c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4716u)) != 63487u || agr_aot_load16(s, (s->bias + 4718u)) != 60784u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 3408u), (s->bias + 4720u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001270(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4720u)) != 26818u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[0] + 12u); if (rc) return rc; }
    s->r[15] = (s->bias + 4722u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001272(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4722u)) != 47370u) return AGR_AOT_MISS;
    s->r[15] = s->r[2] ? (s->bias + 4728u) : (s->bias + 4724u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001274(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4724u)) != 63487u || agr_aot_load16(s, (s->bias + 4726u)) != 49056u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 4536u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001278(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4728u)) != 27594u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[1] + 60u); if (rc) return rc; }
    s->r[15] = (s->bias + 4730u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000127a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4730u)) != 25610u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[1] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = (s->bias + 4732u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000127c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4732u)) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = (s->bias + 4734u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000127e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4734u)) != 59192u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 4338u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001280(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4736u)) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001282(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4738u)) != 46344u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 4740u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001284(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4740u)) != 17921u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 0);
    s->r[15] = (s->bias + 4742u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001286(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4742u)) != 26755u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = (s->bias + 4744u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001288(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4744u)) != 45323u) return AGR_AOT_MISS;
    s->r[15] = !s->r[3] ? (s->bias + 4750u) : (s->bias + 4746u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000128a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4746u)) != 8193u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = (s->bias + 4748u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000128c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4748u)) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], (s->bias + 4750u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000128e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4750u)) != 48392u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) return rc;
}

static int aot_debug_00001290(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4752u)) != 46384u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16432u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 4754u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001292(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4754u)) != 10500u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[1], 4u);
    s->r[15] = (s->bias + 4756u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001294(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4756u)) != 55312u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 8u) ? (s->bias + 4792u) : (s->bias + 4758u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000129a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4762u)) != 773u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 5, s->r[0], 12u);
    s->r[15] = (s->bias + 4764u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000129c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4764u)) != 783u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 7, s->r[1], 12u);
    s->r[15] = (s->bias + 4766u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000129e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4766u)) != 3u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 3, s->r[0], 0u);
    s->r[15] = (s->bias + 4768u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000012a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4768u)) != 8193u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = (s->bias + 4770u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000012a2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4770u)) != 48432u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) return rc;
}

static int aot_debug_000012b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4792u)) != 8194u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    s->r[15] = (s->bias + 4794u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000012ba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4794u)) != 48432u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) return rc;
}

static int aot_debug_000012d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4820u)) != 46384u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16432u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 4822u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000012d6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4822u)) != 10500u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[1], 4u);
    s->r[15] = (s->bias + 4824u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000012d8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4824u)) != 55312u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 8u) ? (s->bias + 4860u) : (s->bias + 4826u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000012de(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4830u)) != 773u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 5, s->r[0], 12u);
    s->r[15] = (s->bias + 4832u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000012e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4832u)) != 783u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 7, s->r[1], 12u);
    s->r[15] = (s->bias + 4834u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000012e2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4834u)) != 3u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 3, s->r[0], 0u);
    s->r[15] = (s->bias + 4836u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000012e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4836u)) != 8193u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = (s->bias + 4838u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000012e6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4838u)) != 48432u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) return rc;
}

static int aot_debug_000012fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4860u)) != 8194u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    s->r[15] = (s->bias + 4862u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000012fe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4862u)) != 48432u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) return rc;
}

static int aot_debug_00001300(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4864u)) != 46367u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16415u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 4866u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001302(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4866u)) != 43780u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 3, s->r[13], 16u);
    s->r[15] = (s->bias + 4868u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001304(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4868u)) != 17932u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 1);
    s->r[15] = (s->bias + 4870u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001306(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4870u)) != 8448u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = (s->bias + 4872u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001308(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4872u)) != 63555u || agr_aot_load16(s, (s->bias + 4874u)) != 11524u) return AGR_AOT_MISS;
    { uint32_t addr = (s->r[3] - 4u); s->r[3] = s->r[3] - 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = (s->bias + 4876u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000130c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4876u)) != 17954u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 4);
    s->r[15] = (s->bias + 4878u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000130e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4878u)) != 37632u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = (s->bias + 4880u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001310(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4880u)) != 17931u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = (s->bias + 4882u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001312(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4882u)) != 63487u || agr_aot_load16(s, (s->bias + 4884u)) != 65503u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 4820u) | 1u, (s->bias + 4886u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001316(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4886u)) != 45060u) return AGR_AOT_MISS;
    s->r[13] += 16u;
    s->r[15] = (s->bias + 4888u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001318(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4888u)) != 48400u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_debug_0000131a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4890u)) != 27603u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[2] + 60u); if (rc) return rc; }
    s->r[15] = (s->bias + 4892u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000131c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4892u)) != 59693u || agr_aot_load16(s, (s->bias + 4894u)) != 16880u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16880u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 4896u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001320(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4896u)) != 7445u) return AGR_AOT_MISS;
    agr_aot_adds(s, 5, s->r[2], 4u);
    s->r[15] = (s->bias + 4898u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001322(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4898u)) != 25619u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[2] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = (s->bias + 4900u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001324(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4900u)) != 17927u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 7, 0);
    s->r[15] = (s->bias + 4902u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001326(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4902u)) != 18056u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 8, 1);
    s->r[15] = (s->bias + 4904u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000132e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4910u)) != 44055u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 4, s->r[13], 92u);
    s->r[15] = (s->bias + 4912u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001330(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4912u)) != 44566u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 6, s->r[13], 88u);
    s->r[15] = (s->bias + 4914u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001340(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4928u)) != 59524u || agr_aot_load16(s, (s->bias + 4930u)) != 15u) return AGR_AOT_MISS;
    if (agr_aot_stm(s, 4u, 15u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 4932u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001344(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4932u)) != 18028u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 13);
    s->r[15] = (s->bias + 4934u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001346(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4934u)) != 61519u || agr_aot_load16(s, (s->bias + 4936u)) != 13311u) return AGR_AOT_MISS;
    s->r[3] = 4294967295u;
    s->r[15] = (s->bias + 4938u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000134a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4938u)) != 24627u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[6] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = (s->bias + 4940u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000134c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4940u)) != 18024u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 13);
    s->r[15] = (s->bias + 4942u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000134e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4942u)) != 27697u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[6] + 64u); if (rc) return rc; }
    s->r[15] = (s->bias + 4944u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001350(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4944u)) != 63487u || agr_aot_load16(s, (s->bias + 4946u)) != 65072u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 4020u) | 1u, (s->bias + 4948u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001354(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4948u)) != 45320u) return AGR_AOT_MISS;
    s->r[15] = !s->r[0] ? (s->bias + 4954u) : (s->bias + 4950u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001356(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4950u)) != 9481u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 5, 9u);
    s->r[15] = (s->bias + 4952u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001358(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4952u)) != 57364u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 4996u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000135a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4954u)) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = (s->bias + 4956u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000135c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4956u)) != 8460u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 12u);
    s->r[15] = (s->bias + 4958u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000135e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4958u)) != 18026u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 13);
    s->r[15] = (s->bias + 4960u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001360(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4960u)) != 63487u || agr_aot_load16(s, (s->bias + 4962u)) != 65486u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 4864u) | 1u, (s->bias + 4964u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001364(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4964u)) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = (s->bias + 4966u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001366(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4966u)) != 17985u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 8);
    s->r[15] = (s->bias + 4968u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001368(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4968u)) != 18360u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[7], (s->bias + 4970u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000136a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4970u)) != 10240u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = (s->bias + 4972u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000136c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4972u)) != 53747u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 4950u) : (s->bias + 4974u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000136e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4974u)) != 26915u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 16u); if (rc) return rc; }
    s->r[15] = (s->bias + 4976u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001370(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4976u)) != 8200u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 8u);
    s->r[15] = (s->bias + 4978u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001372(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4978u)) != 18025u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 13);
    s->r[15] = (s->bias + 4980u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001374(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4980u)) != 17970u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = (s->bias + 4982u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001376(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4982u)) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], (s->bias + 4984u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001378(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4984u)) != 10245u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 5u);
    s->r[15] = (s->bias + 4986u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000137a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4986u)) != 17925u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = (s->bias + 4988u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000137c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4988u)) != 53250u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 4996u) : (s->bias + 4990u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000137e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4990u)) != 10249u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 9u);
    s->r[15] = (s->bias + 4992u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001380(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4992u)) != 53732u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 4940u) : (s->bias + 4994u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001382(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4994u)) != 59368u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 4950u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001384(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4996u)) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = (s->bias + 4998u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001386(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 4998u)) != 63487u || agr_aot_load16(s, (s->bias + 5000u)) != 65127u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 4184u) | 1u, (s->bias + 5002u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000138a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5002u)) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = (s->bias + 5004u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000138c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5004u)) != 62733u || agr_aot_load16(s, (s->bias + 5006u)) != 32014u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 13, s->r[13], 3854u);
    s->r[15] = (s->bias + 5008u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001390(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5008u)) != 59581u || agr_aot_load16(s, (s->bias + 5010u)) != 33264u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) return rc;
}

static int aot_debug_00001394(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5012u)) != 59693u || agr_aot_load16(s, (s->bias + 5014u)) != 20464u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 20464u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 5016u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001398(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5016u)) != 17942u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 6, 2);
    s->r[15] = (s->bias + 5018u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000139a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5018u)) != 27850u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[1] + 76u); if (rc) return rc; }
    s->r[15] = (s->bias + 5020u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000139c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5020u)) != 45193u) return AGR_AOT_MISS;
    s->r[13] -= 36u;
    s->r[15] = (s->bias + 5022u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000139e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5022u)) != 18051u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 11, 0);
    s->r[15] = (s->bias + 5024u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000013a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5024u)) != 17932u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 1);
    s->r[15] = (s->bias + 5026u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000013a2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5026u)) != 7445u) return AGR_AOT_MISS;
    agr_aot_adds(s, 5, s->r[2], 4u);
    s->r[15] = (s->bias + 5028u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000013a4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5028u)) != 61440u || agr_aot_load16(s, (s->bias + 5030u)) != 2563u) return AGR_AOT_MISS;
    s->r[10] = s->r[0] & 3u;
    s->r[15] = (s->bias + 5032u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000013a8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5032u)) != 26642u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[2] + 0u); if (rc) return rc; }
    s->r[15] = (s->bias + 5034u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000013aa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5034u)) != 17951u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 7, 3);
    s->r[15] = (s->bias + 5036u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000013ac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5036u)) != 38150u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    s->r[15] = (s->bias + 5038u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000013ae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5038u)) != 37381u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = (s->bias + 5040u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000013b0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5040u)) != 47419u) return AGR_AOT_MISS;
    s->r[15] = s->r[3] ? (s->bias + 5058u) : (s->bias + 5042u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000013b2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5042u)) != 530u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 2, s->r[2], 8u);
    s->r[15] = (s->bias + 5044u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000013b4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5044u)) != 63629u || agr_aot_load16(s, (s->bias + 5046u)) != 12317u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 29u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    s->r[15] = (s->bias + 5048u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000013b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5048u)) != 37381u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = (s->bias + 5050u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000013ba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5050u)) != 8963u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 3u);
    s->r[15] = (s->bias + 5052u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000013bc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5052u)) != 63629u || agr_aot_load16(s, (s->bias + 5054u)) != 12316u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 28u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    s->r[15] = (s->bias + 5056u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000013c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5056u)) != 57356u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 5084u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000013c2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5058u)) != 11010u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 2u);
    s->r[15] = (s->bias + 5060u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000013c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5060u)) != 56330u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 12u) ? (s->bias + 5084u) : (s->bias + 5062u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000013c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5064u)) != 63629u || agr_aot_load16(s, (s->bias + 5066u)) != 12317u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 29u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    s->r[15] = (s->bias + 5068u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000013cc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5068u)) != 1042u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 2, s->r[2], 16u);
    s->r[15] = (s->bias + 5070u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000013ce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5070u)) != 37381u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = (s->bias + 5072u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000013d0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5072u)) != 45787u) return AGR_AOT_MISS;
    s->r[3] = s->r[3] & 0xffu;
    s->r[15] = (s->bias + 5074u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000013d2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5074u)) != 8706u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 2u);
    s->r[15] = (s->bias + 5076u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000013d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5076u)) != 63629u || agr_aot_load16(s, (s->bias + 5078u)) != 8220u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 28u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    s->r[15] = (s->bias + 5080u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000013dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5084u)) != 61882u || agr_aot_load16(s, (s->bias + 5086u)) != 3842u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[10], 2u);
    s->r[15] = (s->bias + 5088u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000013e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5088u)) != 27939u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 80u); if (rc) return rc; }
    s->r[15] = (s->bias + 5090u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000013e2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5090u)) != 48904u) return AGR_AOT_MISS;
    agr_aot_set_itstate(s, 8u); s->r[15] = (s->bias + 5092u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000161c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5660u)) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = (s->bias + 5662u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000161e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5662u)) != 59065u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 5012u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001620(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5664u)) != 8961u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 1u);
    s->r[15] = (s->bias + 5666u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001622(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5666u)) != 59063u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 5012u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001624(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5668u)) != 8962u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 2u);
    s->r[15] = (s->bias + 5670u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001626(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5670u)) != 59061u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 5012u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001628(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5672u)) != 59693u || agr_aot_load16(s, (s->bias + 5674u)) != 16880u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16880u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 5676u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000162c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5676u)) != 17924u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = (s->bias + 5678u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000162e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5678u)) != 45250u) return AGR_AOT_MISS;
    s->r[13] -= 264u;
    s->r[15] = (s->bias + 5680u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001630(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5680u)) != 17943u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 7, 2);
    s->r[15] = (s->bias + 5682u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001632(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5682u)) != 17949u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 3);
    s->r[15] = (s->bias + 5684u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001634(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5684u)) != 10500u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[1], 4u);
    s->r[15] = (s->bias + 5686u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001636(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5686u)) != 55419u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 8u) ? (s->bias + 5936u) : (s->bias + 5688u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000163c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5692u)) != 6659u) return AGR_AOT_MISS;
    agr_aot_subs(s, 3, s->r[0], s->r[0]);
    s->r[15] = (s->bias + 5694u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000163e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5694u)) != 10362u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 122u);
    s->r[15] = (s->bias + 5696u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001640(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5696u)) != 82u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 2, s->r[2], 1u);
    s->r[15] = (s->bias + 5698u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001642(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5698u)) != 11520u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[5], 0u);
    s->r[15] = (s->bias + 5700u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001644(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5700u)) != 53620u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 5936u) : (s->bias + 5702u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001646(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5702u)) != 27523u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 56u); if (rc) return rc; }
    s->r[15] = (s->bias + 5704u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000164a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5706u)) != 8193u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = (s->bias + 5708u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000164c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5708u)) != 64000u || agr_aot_load16(s, (s->bias + 5710u)) != 61957u) return AGR_AOT_MISS;
    agr_aot_lsls_reg(s, 2, s->r[0], s->r[5]);
    s->r[15] = (s->bias + 5712u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001652(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5714u)) != 53252u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 5726u) : (s->bias + 5716u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001654(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5716u)) != 26650u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = (s->bias + 5718u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000165a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5722u)) != 13060u) return AGR_AOT_MISS;
    agr_aot_adds(s, 3, s->r[3], 4u);
    s->r[15] = (s->bias + 5724u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000165c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5724u)) != 24690u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[6] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = (s->bias + 5726u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000165e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5726u)) != 13569u) return AGR_AOT_MISS;
    agr_aot_adds(s, 5, s->r[5], 1u);
    s->r[15] = (s->bias + 5728u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001660(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5728u)) != 11536u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[5], 16u);
    s->r[15] = (s->bias + 5730u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001662(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5730u)) != 53747u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 5708u) : (s->bias + 5732u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001668(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5736u)) != 61504u || agr_aot_load16(s, (s->bias + 5738u)) != 32901u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6006u) : (s->bias + 5740u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000166c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5740u)) != 25507u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[4] + 56u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = (s->bias + 5742u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000166e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5742u)) != 57577u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 6212u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001730(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5936u)) != 8194u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    s->r[15] = (s->bias + 5938u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001732(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 5938u)) != 57479u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 6212u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001776(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6006u)) != 8192u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = (s->bias + 6008u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001778(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6008u)) != 57444u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 6212u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001844(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6212u)) != 45122u) return AGR_AOT_MISS;
    s->r[13] += 264u;
    s->r[15] = (s->bias + 6214u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001846(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6214u)) != 59581u || agr_aot_load16(s, (s->bias + 6216u)) != 33264u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) return rc;
}

static int aot_debug_0000184c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6220u)) != 61696u || agr_aot_load16(s, (s->bias + 6222u)) != 308u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 1, s->r[0], 52u);
    s->r[15] = (s->bias + 6224u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001854(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6228u)) != 18076u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 12, 3);
    s->r[15] = (s->bias + 6230u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001856(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6230u)) != 18086u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 14, 4);
    s->r[15] = (s->bias + 6232u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001858(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6232u)) != 63564u || agr_aot_load16(s, (s->bias + 6234u)) != 23812u) return AGR_AOT_MISS;
    { uint32_t addr = (s->r[12] - 4u); s->r[12] = s->r[12] - 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    s->r[15] = (s->bias + 6236u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001860(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6240u)) != 18149u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 13, 12);
    s->r[15] = (s->bias + 6242u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001862(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6242u)) != 48384u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32768u))) return rc;
}

static int aot_debug_00001868(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6248u)) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001870(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6256u)) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001878(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6264u)) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001880(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6272u)) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001888(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6280u)) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001890(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6288u)) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000018d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6356u)) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001918(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6424u)) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000192c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6444u)) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001940(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6464u)) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001944(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6468u)) != 18156u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 12, 13);
    s->r[15] = (s->bias + 6470u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001946(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6470u)) != 46336u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16384u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 6472u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001948(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6472u)) != 59693u || agr_aot_load16(s, (s->bias + 6474u)) != 20480u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 20480u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 6476u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000194c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6476u)) != 59693u || agr_aot_load16(s, (s->bias + 6478u)) != 8191u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 8191u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 6480u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001950(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6480u)) != 61519u || agr_aot_load16(s, (s->bias + 6482u)) != 768u) return AGR_AOT_MISS;
    s->r[3] = 0u;
    s->r[15] = (s->bias + 6484u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001954(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6484u)) != 59693u || agr_aot_load16(s, (s->bias + 6486u)) != 12u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 12u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 6488u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001958(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6488u)) != 43265u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    s->r[15] = (s->bias + 6490u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000195a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6490u)) != 63487u || agr_aot_load16(s, (s->bias + 6492u)) != 64557u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 4536u) | 1u, (s->bias + 6494u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000195e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6494u)) != 63709u || agr_aot_load16(s, (s->bias + 6496u)) != 57408u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[15] = (s->bias + 6498u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001962(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6498u)) != 45074u) return AGR_AOT_MISS;
    s->r[13] += 72u;
    s->r[15] = (s->bias + 6500u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001964(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6500u)) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001968(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6504u)) != 18156u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 12, 13);
    s->r[15] = (s->bias + 6506u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000196a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6506u)) != 46336u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16384u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 6508u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000196c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6508u)) != 59693u || agr_aot_load16(s, (s->bias + 6510u)) != 20480u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 20480u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 6512u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001970(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6512u)) != 59693u || agr_aot_load16(s, (s->bias + 6514u)) != 8191u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 8191u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 6516u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001974(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6516u)) != 61519u || agr_aot_load16(s, (s->bias + 6518u)) != 768u) return AGR_AOT_MISS;
    s->r[3] = 0u;
    s->r[15] = (s->bias + 6520u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001978(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6520u)) != 59693u || agr_aot_load16(s, (s->bias + 6522u)) != 12u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 12u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 6524u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000197c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6524u)) != 43265u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    s->r[15] = (s->bias + 6526u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000197e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6526u)) != 63487u || agr_aot_load16(s, (s->bias + 6528u)) != 64598u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 4654u) | 1u, (s->bias + 6530u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001982(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6530u)) != 63709u || agr_aot_load16(s, (s->bias + 6532u)) != 57408u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[15] = (s->bias + 6534u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001986(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6534u)) != 45074u) return AGR_AOT_MISS;
    s->r[13] += 72u;
    s->r[15] = (s->bias + 6536u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001988(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6536u)) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000198c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6540u)) != 18156u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 12, 13);
    s->r[15] = (s->bias + 6542u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000198e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6542u)) != 46336u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16384u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 6544u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001990(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6544u)) != 59693u || agr_aot_load16(s, (s->bias + 6546u)) != 20480u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 20480u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 6548u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001994(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6548u)) != 59693u || agr_aot_load16(s, (s->bias + 6550u)) != 8191u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 8191u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 6552u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001998(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6552u)) != 61519u || agr_aot_load16(s, (s->bias + 6554u)) != 768u) return AGR_AOT_MISS;
    s->r[3] = 0u;
    s->r[15] = (s->bias + 6556u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0000199c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6556u)) != 59693u || agr_aot_load16(s, (s->bias + 6558u)) != 12u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 12u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 6560u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6560u)) != 43265u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    s->r[15] = (s->bias + 6562u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019a2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6562u)) != 63487u || agr_aot_load16(s, (s->bias + 6564u)) != 64613u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 4720u) | 1u, (s->bias + 6566u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019a6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6566u)) != 63709u || agr_aot_load16(s, (s->bias + 6568u)) != 57408u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[15] = (s->bias + 6570u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019aa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6570u)) != 45074u) return AGR_AOT_MISS;
    s->r[13] += 72u;
    s->r[15] = (s->bias + 6572u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019ac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6572u)) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019b0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6576u)) != 18156u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 12, 13);
    s->r[15] = (s->bias + 6578u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019b2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6578u)) != 46336u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16384u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 6580u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019b4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6580u)) != 59693u || agr_aot_load16(s, (s->bias + 6582u)) != 20480u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 20480u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 6584u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6584u)) != 59693u || agr_aot_load16(s, (s->bias + 6586u)) != 8191u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 8191u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 6588u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019bc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6588u)) != 61519u || agr_aot_load16(s, (s->bias + 6590u)) != 768u) return AGR_AOT_MISS;
    s->r[3] = 0u;
    s->r[15] = (s->bias + 6592u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6592u)) != 59693u || agr_aot_load16(s, (s->bias + 6594u)) != 12u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 12u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 6596u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6596u)) != 43777u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 3, s->r[13], 4u);
    s->r[15] = (s->bias + 6598u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019c6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6598u)) != 63487u || agr_aot_load16(s, (s->bias + 6600u)) != 64552u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 4634u) | 1u, (s->bias + 6602u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6602u)) != 63709u || agr_aot_load16(s, (s->bias + 6604u)) != 57408u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[15] = (s->bias + 6606u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019ce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6606u)) != 45074u) return AGR_AOT_MISS;
    s->r[13] += 72u;
    s->r[15] = (s->bias + 6608u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019d0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6608u)) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6612u)) != 18156u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 12, 13);
    s->r[15] = (s->bias + 6614u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019d6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6614u)) != 46336u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16384u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 6616u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019d8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6616u)) != 59693u || agr_aot_load16(s, (s->bias + 6618u)) != 20480u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 20480u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 6620u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6620u)) != 59693u || agr_aot_load16(s, (s->bias + 6622u)) != 8191u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 8191u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 6624u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6624u)) != 61519u || agr_aot_load16(s, (s->bias + 6626u)) != 768u) return AGR_AOT_MISS;
    s->r[3] = 0u;
    s->r[15] = (s->bias + 6628u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6628u)) != 59693u || agr_aot_load16(s, (s->bias + 6630u)) != 12u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 12u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 6632u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019e8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6632u)) != 43521u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    s->r[15] = (s->bias + 6634u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019ea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6634u)) != 63487u || agr_aot_load16(s, (s->bias + 6636u)) != 64662u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 4890u) | 1u, (s->bias + 6638u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019ee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6638u)) != 63709u || agr_aot_load16(s, (s->bias + 6640u)) != 57408u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[15] = (s->bias + 6642u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6642u)) != 45074u) return AGR_AOT_MISS;
    s->r[13] += 72u;
    s->r[15] = (s->bias + 6644u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019f4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6644u)) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019f8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6648u)) != 31235u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = (s->bias + 6650u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019fa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6650u)) != 47443u) return AGR_AOT_MISS;
    s->r[15] = s->r[3] ? (s->bias + 6674u) : (s->bias + 6652u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6652u)) != 31299u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 9u); if (rc) return rc; }
    s->r[15] = (s->bias + 6654u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000019fe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6654u)) != 45435u) return AGR_AOT_MISS;
    s->r[15] = !s->r[3] ? (s->bias + 6688u) : (s->bias + 6656u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a00(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6656u)) != 15105u) return AGR_AOT_MISS;
    agr_aot_subs(s, 3, s->r[3], 1u);
    s->r[15] = (s->bias + 6658u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6658u)) != 29251u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[0] + 9u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    s->r[15] = (s->bias + 6660u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a04(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6660u)) != 26691u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 4u); if (rc) return rc; }
    s->r[15] = (s->bias + 6662u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a06(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6662u)) != 7450u) return AGR_AOT_MISS;
    agr_aot_adds(s, 2, s->r[3], 4u);
    s->r[15] = (s->bias + 6664u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6664u)) != 24642u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[0] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = (s->bias + 6666u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a0a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6666u)) != 26651u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = (s->bias + 6668u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a0c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6668u)) != 24579u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = (s->bias + 6670u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a0e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6670u)) != 8963u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 3u);
    s->r[15] = (s->bias + 6672u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a10(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6672u)) != 57344u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 6676u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a12(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6674u)) != 15105u) return AGR_AOT_MISS;
    agr_aot_subs(s, 3, s->r[3], 1u);
    s->r[15] = (s->bias + 6676u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a14(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6676u)) != 29187u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[0] + 8u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    s->r[15] = (s->bias + 6678u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a16(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6678u)) != 26627u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = (s->bias + 6680u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a18(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6680u)) != 538u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 2, s->r[3], 8u);
    s->r[15] = (s->bias + 6682u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a1a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6682u)) != 24578u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = (s->bias + 6684u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a1e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6686u)) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6688u)) != 8368u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 176u);
    s->r[15] = (s->bias + 6690u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a22(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6690u)) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6692u)) != 46367u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16415u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 6694u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a26(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6694u)) != 8448u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = (s->bias + 6696u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a28(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6696u)) != 43779u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 3, s->r[13], 12u);
    s->r[15] = (s->bias + 6698u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a2a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6698u)) != 8716u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 12u);
    s->r[15] = (s->bias + 6700u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6700u)) != 37632u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = (s->bias + 6702u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a2e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6702u)) != 17931u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = (s->bias + 6704u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a30(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6704u)) != 63487u || agr_aot_load16(s, (s->bias + 6706u)) != 64558u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 4752u) | 1u, (s->bias + 6708u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a34(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6708u)) != 38915u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 12u); if (rc) return rc; }
    s->r[15] = (s->bias + 6710u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a36(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6710u)) != 45061u) return AGR_AOT_MISS;
    s->r[13] += 20u;
    s->r[15] = (s->bias + 6712u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a38(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6712u)) != 63581u || agr_aot_load16(s, (s->bias + 6714u)) != 64260u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13]; s->r[13] = s->r[13] + 4u; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_00001a3c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6716u)) != 59378u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 6692u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a3e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6718u)) != 59693u || agr_aot_load16(s, (s->bias + 6720u)) != 18431u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 18431u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 6722u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a42(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6722u)) != 17925u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = (s->bias + 6724u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6724u)) != 17934u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 6, 1);
    s->r[15] = (s->bias + 6726u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a46(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6726u)) != 9984u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 7, 0u);
    s->r[15] = (s->bias + 6728u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6728u)) != 61709u || agr_aot_load16(s, (s->bias + 6730u)) != 2060u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 8, s->r[13], 12u);
    s->r[15] = (s->bias + 6732u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a4c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6732u)) != 62543u || agr_aot_load16(s, (s->bias + 6734u)) != 27007u) return AGR_AOT_MISS;
    s->r[9] = 4080u;
    s->r[15] = (s->bias + 6736u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6736u)) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = (s->bias + 6738u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a52(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6738u)) != 63487u || agr_aot_load16(s, (s->bias + 6740u)) != 65489u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 6742u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a56(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6742u)) != 10416u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 176u);
    s->r[15] = (s->bias + 6744u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a58(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6744u)) != 17924u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = (s->bias + 6746u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a5a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6746u)) != 53522u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6786u) : (s->bias + 6748u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a5c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6748u)) != 12032u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[7], 0u);
    s->r[15] = (s->bias + 6750u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a5e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6750u)) != 61504u || agr_aot_load16(s, (s->bias + 6752u)) != 33049u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7316u) : (s->bias + 6754u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a62(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6754u)) != 44035u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 4, s->r[13], 12u);
    s->r[15] = (s->bias + 6756u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6756u)) != 17977u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 7);
    s->r[15] = (s->bias + 6758u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a66(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6758u)) != 17979u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 7);
    s->r[15] = (s->bias + 6760u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a68(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6760u)) != 37888u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    s->r[15] = (s->bias + 6762u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a6a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6762u)) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = (s->bias + 6764u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a6c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6764u)) != 8718u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 14u);
    s->r[15] = (s->bias + 6766u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a6e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6766u)) != 63487u || agr_aot_load16(s, (s->bias + 6768u)) != 64527u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 4752u) | 1u, (s->bias + 6770u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6770u)) != 37888u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    s->r[15] = (s->bias + 6772u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a74(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6772u)) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = (s->bias + 6774u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a76(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6774u)) != 17977u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 7);
    s->r[15] = (s->bias + 6776u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6776u)) != 8719u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 15u);
    s->r[15] = (s->bias + 6778u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a7a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6778u)) != 17979u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 7);
    s->r[15] = (s->bias + 6780u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a7c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6780u)) != 63487u || agr_aot_load16(s, (s->bias + 6782u)) != 64554u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 4820u) | 1u, (s->bias + 6784u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6784u)) != 57608u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 7316u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6794u)) != 53525u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6840u) : (s->bias + 6796u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a90(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6800u)) != 17931u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = (s->bias + 6802u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a92(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6802u)) != 63693u || agr_aot_load16(s, (s->bias + 6804u)) != 32768u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    s->r[15] = (s->bias + 6806u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a96(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6806u)) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = (s->bias + 6808u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a98(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6808u)) != 8717u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 13u);
    s->r[15] = (s->bias + 6810u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001a9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6814u)) != 63487u || agr_aot_load16(s, (s->bias + 6816u)) != 64503u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 4752u) | 1u, (s->bias + 6818u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001aa2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6818u)) != 39683u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 12u); if (rc) return rc; }
    s->r[15] = (s->bias + 6820u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001aa4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6820u)) != 61706u || agr_aot_load16(s, (s->bias + 6822u)) != 2564u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 10, s->r[10], 4u);
    s->r[15] = (s->bias + 6824u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001aac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6828u)) != 48916u) return AGR_AOT_MISS;
    agr_aot_set_itstate(s, 20u); s->r[15] = (s->bias + 6830u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001ab8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6840u)) != 61440u || agr_aot_load16(s, (s->bias + 6842u)) != 1008u) return AGR_AOT_MISS;
    s->r[3] = s->r[0] & 240u;
    s->r[15] = (s->bias + 6844u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001abc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6844u)) != 11136u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 128u);
    s->r[15] = (s->bias + 6846u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001abe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6846u)) != 53527u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6896u) : (s->bias + 6848u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001ac0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6848u)) != 516u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 4, s->r[0], 8u);
    s->r[15] = (s->bias + 6850u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001ac2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6850u)) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = (s->bias + 6852u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001ac4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6852u)) != 63487u || agr_aot_load16(s, (s->bias + 6854u)) != 65432u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 6856u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001aca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6858u)) != 62896u || agr_aot_load16(s, (s->bias + 6860u)) != 20224u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 32768u);
    s->r[15] = (s->bias + 6862u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001ace(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6862u)) != 53505u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6868u) : (s->bias + 6864u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001ad0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6864u)) != 8201u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 9u);
    s->r[15] = (s->bias + 6866u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001ad2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6866u)) != 57568u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 7318u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001ad4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6868u)) != 260u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 4, s->r[0], 4u);
    s->r[15] = (s->bias + 6870u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001ad6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6870u)) != 8448u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = (s->bias + 6872u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001ad8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6872u)) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = (s->bias + 6874u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001ada(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6874u)) != 17931u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = (s->bias + 6876u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001ade(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6878u)) != 63487u || agr_aot_load16(s, (s->bias + 6880u)) != 64931u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 5672u) | 1u, (s->bias + 6882u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001ae2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6882u)) != 10240u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = (s->bias + 6884u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001ae4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6884u)) != 53748u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6864u) : (s->bias + 6886u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001aea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6890u)) != 48920u) return AGR_AOT_MISS;
    agr_aot_set_itstate(s, 24u); s->r[15] = (s->bias + 6892u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001af0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6896u)) != 11152u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 144u);
    s->r[15] = (s->bias + 6898u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001af2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6898u)) != 53525u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6944u) : (s->bias + 6900u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001af4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6900u)) != 61440u || agr_aot_load16(s, (s->bias + 6902u)) != 781u) return AGR_AOT_MISS;
    s->r[3] = s->r[0] & 13u;
    s->r[15] = (s->bias + 6904u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001af8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6904u)) != 11021u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 13u);
    s->r[15] = (s->bias + 6906u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001afa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6906u)) != 53481u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 6864u) : (s->bias + 6908u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001afc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6908u)) != 8448u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = (s->bias + 6910u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001afe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6910u)) != 63693u || agr_aot_load16(s, (s->bias + 6912u)) != 32768u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    s->r[15] = (s->bias + 6914u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6914u)) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = (s->bias + 6916u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b04(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6916u)) != 61444u || agr_aot_load16(s, (s->bias + 6918u)) != 527u) return AGR_AOT_MISS;
    s->r[2] = s->r[4] & 15u;
    s->r[15] = (s->bias + 6920u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6920u)) != 17931u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = (s->bias + 6922u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b0a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6922u)) != 63487u || agr_aot_load16(s, (s->bias + 6924u)) != 64449u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 4752u) | 1u, (s->bias + 6926u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b0e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6926u)) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = (s->bias + 6928u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b10(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6928u)) != 8448u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = (s->bias + 6930u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b12(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6930u)) != 63693u || agr_aot_load16(s, (s->bias + 6932u)) != 32768u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    s->r[15] = (s->bias + 6934u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b16(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6934u)) != 8717u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 13u);
    s->r[15] = (s->bias + 6936u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b18(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6936u)) != 17931u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = (s->bias + 6938u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b1a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6938u)) != 63487u || agr_aot_load16(s, (s->bias + 6940u)) != 64475u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 4820u) | 1u, (s->bias + 6942u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b1e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6942u)) != 59287u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 6736u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6944u)) != 11168u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 160u);
    s->r[15] = (s->bias + 6946u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b22(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6946u)) != 53517u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6976u) : (s->bias + 6948u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b26(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6950u)) != 61442u || agr_aot_load16(s, (s->bias + 6952u)) != 519u) return AGR_AOT_MISS;
    s->r[2] = s->r[2] & 7u;
    s->r[15] = (s->bias + 6954u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b2e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6958u)) != 1795u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 3, s->r[0], 28u);
    s->r[15] = (s->bias + 6960u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b30(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6960u)) != 62466u || agr_aot_load16(s, (s->bias + 6962u)) != 25215u) return AGR_AOT_MISS;
    s->r[2] = s->r[2] & 4080u;
    s->r[15] = (s->bias + 6964u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b34(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6964u)) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = (s->bias + 6966u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b36(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6966u)) != 48968u) return AGR_AOT_MISS;
    agr_aot_set_itstate(s, 72u); s->r[15] = (s->bias + 6968u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6976u)) != 11184u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 176u);
    s->r[15] = (s->bias + 6978u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b42(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6978u)) != 53579u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7132u) : (s->bias + 6980u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6980u)) != 10417u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 177u);
    s->r[15] = (s->bias + 6982u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b46(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6982u)) != 53515u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7008u) : (s->bias + 6984u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6984u)) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = (s->bias + 6986u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b4a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6986u)) != 63487u || agr_aot_load16(s, (s->bias + 6988u)) != 65365u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 6990u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b4e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6990u)) != 17922u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 0);
    s->r[15] = (s->bias + 6992u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6992u)) != 10240u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = (s->bias + 6994u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b52(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 6994u)) != 53437u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 6864u) : (s->bias + 6996u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b58(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7000u)) != 53690u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6864u) : (s->bias + 7002u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b5a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7002u)) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = (s->bias + 7004u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b5c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7004u)) != 17931u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = (s->bias + 7006u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b5e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7006u)) != 57491u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 7304u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b60(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7008u)) != 10418u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 178u);
    s->r[15] = (s->bias + 7010u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b62(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7010u)) != 53538u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7082u) : (s->bias + 7012u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7012u)) != 8448u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = (s->bias + 7014u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b66(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7014u)) != 8717u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 13u);
    s->r[15] = (s->bias + 7016u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b68(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7016u)) != 17931u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = (s->bias + 7018u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b6a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7018u)) != 63693u || agr_aot_load16(s, (s->bias + 7020u)) != 32768u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    s->r[15] = (s->bias + 7022u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b6e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7022u)) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = (s->bias + 7024u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b70(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7024u)) != 9218u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 4, 2u);
    s->r[15] = (s->bias + 7026u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7026u)) != 63487u || agr_aot_load16(s, (s->bias + 7028u)) != 64397u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 4752u) | 1u, (s->bias + 7030u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b76(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7030u)) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = (s->bias + 7032u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7032u)) != 63487u || agr_aot_load16(s, (s->bias + 7034u)) != 65342u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 7036u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7040u)) != 39683u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 12u); if (rc) return rc; }
    s->r[15] = (s->bias + 7042u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b82(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7042u)) != 61440u || agr_aot_load16(s, (s->bias + 7044u)) != 127u) return AGR_AOT_MISS;
    s->r[0] = s->r[0] & 127u;
    s->r[15] = (s->bias + 7046u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b86(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7046u)) != 53255u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 7064u) : (s->bias + 7048u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7050u)) != 13319u) return AGR_AOT_MISS;
    agr_aot_adds(s, 4, s->r[4], 7u);
    s->r[15] = (s->bias + 7052u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b8c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7052u)) != 17411u) return AGR_AOT_MISS;
    s->r[3] += s->r[0];
    s->r[15] = (s->bias + 7054u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b8e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7054u)) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = (s->bias + 7056u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b90(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7056u)) != 37635u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = (s->bias + 7058u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b92(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7058u)) != 63487u || agr_aot_load16(s, (s->bias + 7060u)) != 65329u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 7062u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b96(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7062u)) != 59377u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 7036u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b98(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7064u)) != 62723u || agr_aot_load16(s, (s->bias + 7066u)) != 29441u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 3, s->r[3], 3841u);
    s->r[15] = (s->bias + 7068u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001b9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7070u)) != 17432u) return AGR_AOT_MISS;
    s->r[0] += s->r[3];
    s->r[15] = (s->bias + 7072u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001ba0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7072u)) != 63693u || agr_aot_load16(s, (s->bias + 7074u)) != 32768u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    s->r[15] = (s->bias + 7076u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001ba4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7076u)) != 36867u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = (s->bias + 7078u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001ba6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7078u)) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = (s->bias + 7080u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001ba8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7080u)) != 59317u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 6934u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001baa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7082u)) != 10419u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 179u);
    s->r[15] = (s->bias + 7084u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001bac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7084u)) != 53514u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7108u) : (s->bias + 7086u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001bae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7086u)) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = (s->bias + 7088u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001bb0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7088u)) != 63487u || agr_aot_load16(s, (s->bias + 7090u)) != 65314u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 7092u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001bb4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7092u)) != 8449u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = (s->bias + 7094u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001bb6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7094u)) != 61440u || agr_aot_load16(s, (s->bias + 7096u)) != 783u) return AGR_AOT_MISS;
    s->r[3] = s->r[0] & 15u;
    s->r[15] = (s->bias + 7098u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001bba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7098u)) != 61440u || agr_aot_load16(s, (s->bias + 7100u)) != 752u) return AGR_AOT_MISS;
    s->r[2] = s->r[0] & 240u;
    s->r[15] = (s->bias + 7102u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001bbe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7102u)) != 13057u) return AGR_AOT_MISS;
    agr_aot_adds(s, 3, s->r[3], 1u);
    s->r[15] = (s->bias + 7104u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001bc0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7104u)) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = (s->bias + 7106u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001bc2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7106u)) != 57369u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 7160u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001bc4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7108u)) != 61440u || agr_aot_load16(s, (s->bias + 7110u)) != 1020u) return AGR_AOT_MISS;
    s->r[3] = s->r[0] & 252u;
    s->r[15] = (s->bias + 7112u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001bc8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7112u)) != 11188u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 180u);
    s->r[15] = (s->bias + 7114u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001bca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7114u)) != 53377u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 6864u) : (s->bias + 7116u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001bcc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7116u)) != 61440u || agr_aot_load16(s, (s->bias + 7118u)) != 1031u) return AGR_AOT_MISS;
    s->r[4] = s->r[0] & 7u;
    s->r[15] = (s->bias + 7120u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001bd0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7120u)) != 8449u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = (s->bias + 7122u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001bd2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7122u)) != 7266u) return AGR_AOT_MISS;
    agr_aot_adds(s, 2, s->r[4], 1u);
    s->r[15] = (s->bias + 7124u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001bd4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7124u)) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = (s->bias + 7126u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001bd6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7126u)) != 62530u || agr_aot_load16(s, (s->bias + 7128u)) != 8704u) return AGR_AOT_MISS;
    s->r[2] = s->r[2] | 524288u;
    s->r[15] = (s->bias + 7130u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001bda(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7130u)) != 59327u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 7004u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001bdc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7132u)) != 11200u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 192u);
    s->r[15] = (s->bias + 7134u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001bde(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7134u)) != 53574u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7278u) : (s->bias + 7136u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001be0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7136u)) != 10438u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 198u);
    s->r[15] = (s->bias + 7138u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001be2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7138u)) != 53516u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7166u) : (s->bias + 7140u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001be4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7140u)) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = (s->bias + 7142u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001be6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7142u)) != 63487u || agr_aot_load16(s, (s->bias + 7144u)) != 65287u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 7146u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001bea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7146u)) != 8451u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 3u);
    s->r[15] = (s->bias + 7148u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001bec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7148u)) != 61440u || agr_aot_load16(s, (s->bias + 7150u)) != 783u) return AGR_AOT_MISS;
    s->r[3] = s->r[0] & 15u;
    s->r[15] = (s->bias + 7152u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001bf0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7152u)) != 61440u || agr_aot_load16(s, (s->bias + 7154u)) != 752u) return AGR_AOT_MISS;
    s->r[2] = s->r[0] & 240u;
    s->r[15] = (s->bias + 7156u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001bf4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7156u)) != 13057u) return AGR_AOT_MISS;
    agr_aot_adds(s, 3, s->r[3], 1u);
    s->r[15] = (s->bias + 7158u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001bf6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7158u)) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = (s->bias + 7160u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001bfc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7164u)) != 59310u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 7004u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001bfe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7166u)) != 10439u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 199u);
    s->r[15] = (s->bias + 7168u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c00(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7168u)) != 53517u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7198u) : (s->bias + 7170u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7170u)) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = (s->bias + 7172u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c04(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7172u)) != 63487u || agr_aot_load16(s, (s->bias + 7174u)) != 65272u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 7176u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7176u)) != 17922u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 0);
    s->r[15] = (s->bias + 7178u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c0a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7178u)) != 10240u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = (s->bias + 7180u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c0c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7180u)) != 62527u || agr_aot_load16(s, (s->bias + 7182u)) != 44896u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 6864u) : (s->bias + 7184u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c14(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7188u)) != 62591u || agr_aot_load16(s, (s->bias + 7190u)) != 44892u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6864u) : (s->bias + 7192u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c18(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7192u)) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = (s->bias + 7194u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c1a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7194u)) != 8452u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 4u);
    s->r[15] = (s->bias + 7196u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c1c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7196u)) != 57396u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 7304u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c1e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7198u)) != 61440u || agr_aot_load16(s, (s->bias + 7200u)) != 1016u) return AGR_AOT_MISS;
    s->r[3] = s->r[0] & 248u;
    s->r[15] = (s->bias + 7202u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c22(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7202u)) != 11200u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 192u);
    s->r[15] = (s->bias + 7204u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7204u)) != 53511u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7222u) : (s->bias + 7206u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c26(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7206u)) != 61440u || agr_aot_load16(s, (s->bias + 7208u)) != 1039u) return AGR_AOT_MISS;
    s->r[4] = s->r[0] & 15u;
    s->r[15] = (s->bias + 7210u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c2a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7210u)) != 8451u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 3u);
    s->r[15] = (s->bias + 7212u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7212u)) != 7266u) return AGR_AOT_MISS;
    agr_aot_adds(s, 2, s->r[4], 1u);
    s->r[15] = (s->bias + 7214u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c2e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7214u)) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = (s->bias + 7216u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c30(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7216u)) != 62530u || agr_aot_load16(s, (s->bias + 7218u)) != 8736u) return AGR_AOT_MISS;
    s->r[2] = s->r[2] | 655360u;
    s->r[15] = (s->bias + 7220u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c34(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7220u)) != 59282u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 7004u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c36(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7222u)) != 10440u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 200u);
    s->r[15] = (s->bias + 7224u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c38(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7224u)) != 53513u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7246u) : (s->bias + 7226u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c3a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7226u)) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = (s->bias + 7228u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c3c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7228u)) != 63487u || agr_aot_load16(s, (s->bias + 7230u)) != 65244u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 7232u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7232u)) != 61440u || agr_aot_load16(s, (s->bias + 7234u)) != 752u) return AGR_AOT_MISS;
    s->r[2] = s->r[0] & 240u;
    s->r[15] = (s->bias + 7236u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7236u)) != 61440u || agr_aot_load16(s, (s->bias + 7238u)) != 15u) return AGR_AOT_MISS;
    s->r[0] = s->r[0] & 15u;
    s->r[15] = (s->bias + 7240u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7240u)) != 12816u) return AGR_AOT_MISS;
    agr_aot_adds(s, 2, s->r[2], 16u);
    s->r[15] = (s->bias + 7242u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c4a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7242u)) != 7235u) return AGR_AOT_MISS;
    agr_aot_adds(s, 3, s->r[0], 1u);
    s->r[15] = (s->bias + 7244u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c4c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7244u)) != 57354u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 7268u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c4e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7246u)) != 10441u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 201u);
    s->r[15] = (s->bias + 7248u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7248u)) != 62591u || agr_aot_load16(s, (s->bias + 7250u)) != 44862u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6864u) : (s->bias + 7252u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c54(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7252u)) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = (s->bias + 7254u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c56(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7254u)) != 63487u || agr_aot_load16(s, (s->bias + 7256u)) != 65231u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 7258u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c5a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7258u)) != 61440u || agr_aot_load16(s, (s->bias + 7260u)) != 783u) return AGR_AOT_MISS;
    s->r[3] = s->r[0] & 15u;
    s->r[15] = (s->bias + 7262u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c5e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7262u)) != 61440u || agr_aot_load16(s, (s->bias + 7264u)) != 752u) return AGR_AOT_MISS;
    s->r[2] = s->r[0] & 240u;
    s->r[15] = (s->bias + 7266u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c62(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7266u)) != 13057u) return AGR_AOT_MISS;
    agr_aot_adds(s, 3, s->r[3], 1u);
    s->r[15] = (s->bias + 7268u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7268u)) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = (s->bias + 7270u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c66(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7270u)) != 8449u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = (s->bias + 7272u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c6c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7276u)) != 57355u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 7302u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c6e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7278u)) != 61440u || agr_aot_load16(s, (s->bias + 7280u)) != 1016u) return AGR_AOT_MISS;
    s->r[3] = s->r[0] & 248u;
    s->r[15] = (s->bias + 7282u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7282u)) != 11216u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 208u);
    s->r[15] = (s->bias + 7284u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c74(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7284u)) != 62591u || agr_aot_load16(s, (s->bias + 7286u)) != 44844u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6864u) : (s->bias + 7288u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7288u)) != 61440u || agr_aot_load16(s, (s->bias + 7290u)) != 1031u) return AGR_AOT_MISS;
    s->r[4] = s->r[0] & 7u;
    s->r[15] = (s->bias + 7292u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c7c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7292u)) != 8449u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = (s->bias + 7294u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c7e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7294u)) != 7266u) return AGR_AOT_MISS;
    agr_aot_adds(s, 2, s->r[4], 1u);
    s->r[15] = (s->bias + 7296u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7296u)) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = (s->bias + 7298u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c82(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7298u)) != 62530u || agr_aot_load16(s, (s->bias + 7300u)) != 8704u) return AGR_AOT_MISS;
    s->r[2] = s->r[2] | 524288u;
    s->r[15] = (s->bias + 7302u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c86(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7302u)) != 8965u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 5u);
    s->r[15] = (s->bias + 7304u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c88(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7304u)) != 63487u || agr_aot_load16(s, (s->bias + 7306u)) != 64718u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 5672u) | 1u, (s->bias + 7308u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c8c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7308u)) != 10240u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = (s->bias + 7310u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c8e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7310u)) != 62591u || agr_aot_load16(s, (s->bias + 7312u)) != 44831u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6864u) : (s->bias + 7314u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c92(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7314u)) != 59101u) return AGR_AOT_MISS;
    s->r[15] = (s->bias + 6736u); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7316u)) != 8192u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = (s->bias + 7318u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c96(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7318u)) != 45060u) return AGR_AOT_MISS;
    s->r[13] += 16u;
    s->r[15] = (s->bias + 7320u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c98(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7320u)) != 59581u || agr_aot_load16(s, (s->bias + 7322u)) != 34800u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 34800u))) return rc;
}

static int aot_debug_00001c9c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7324u)) != 46367u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16415u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 7326u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001c9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7326u)) != 27843u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 76u); if (rc) return rc; }
    s->r[15] = (s->bias + 7328u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001ca0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7328u)) != 17928u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 1);
    s->r[15] = (s->bias + 7330u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001ca2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7330u)) != 43265u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    s->r[15] = (s->bias + 7332u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001ca4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7332u)) != 26714u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 4u); if (rc) return rc; }
    s->r[15] = (s->bias + 7334u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001ca6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7334u)) != 530u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 2, s->r[2], 8u);
    s->r[15] = (s->bias + 7336u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001ca8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7336u)) != 37377u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = (s->bias + 7338u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001caa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7338u)) != 61699u || agr_aot_load16(s, (s->bias + 7340u)) != 520u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 2, s->r[3], 8u);
    s->r[15] = (s->bias + 7342u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001cae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7342u)) != 37378u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = (s->bias + 7344u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001cb0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7344u)) != 8707u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 3u);
    s->r[15] = (s->bias + 7346u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001cb2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7346u)) != 63629u || agr_aot_load16(s, (s->bias + 7348u)) != 8204u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 12u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    s->r[15] = (s->bias + 7350u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001cb6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7350u)) != 31195u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[3] + 7u); if (rc) return rc; }
    s->r[15] = (s->bias + 7352u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001cb8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7352u)) != 63629u || agr_aot_load16(s, (s->bias + 7354u)) != 12301u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 13u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    s->r[15] = (s->bias + 7356u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001cbc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7356u)) != 63487u || agr_aot_load16(s, (s->bias + 7358u)) != 65215u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 6718u) | 1u, (s->bias + 7360u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001cc0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7360u)) != 45061u) return AGR_AOT_MISS;
    s->r[13] += 20u;
    s->r[15] = (s->bias + 7362u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001cc2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7362u)) != 63581u || agr_aot_load16(s, (s->bias + 7364u)) != 64260u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13]; s->r[13] = s->r[13] + 4u; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_00001cc6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7366u)) != 46344u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 7368u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001cc8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7368u)) != 63487u || agr_aot_load16(s, (s->bias + 7370u)) != 65208u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 6716u) | 1u, (s->bias + 7372u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001ccc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7372u)) != 27776u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 72u); if (rc) return rc; }
    s->r[15] = (s->bias + 7374u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001cce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7374u)) != 48392u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) return rc;
}

static int aot_debug_00001cd0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7376u)) != 46344u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 7378u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001cd2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7378u)) != 63487u || agr_aot_load16(s, (s->bias + 7380u)) != 65203u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 6716u) | 1u, (s->bias + 7382u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001cd6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7382u)) != 27843u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 76u); if (rc) return rc; }
    s->r[15] = (s->bias + 7384u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001cd8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7384u)) != 31194u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldrb(s, 2, s->r[3] + 7u); if (rc) return rc; }
    s->r[15] = (s->bias + 7386u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001cde(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7390u)) != 12296u) return AGR_AOT_MISS;
    agr_aot_adds(s, 0, s->r[0], 8u);
    s->r[15] = (s->bias + 7392u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001ce0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7392u)) != 48392u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) return rc;
}

static int aot_debug_00001ce2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7394u)) != 46344u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 7396u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001ce4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7396u)) != 63487u || agr_aot_load16(s, (s->bias + 7398u)) != 59444u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 3408u), (s->bias + 7400u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001ce8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7400u)) != 46344u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    s->r[15] = (s->bias + 7402u);
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00001cea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, (s->bias + 7402u)) != 63487u || agr_aot_load16(s, (s->bias + 7404u)) != 59442u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, (s->bias + 3408u), (s->bias + 7406u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000cfc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, (s->bias + 3332u), 0u);
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    { uint32_t addr = s->r[12] + 720u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00000d08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, (s->bias + 3344u), 0u);
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    { uint32_t addr = s->r[12] + 712u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00000d14(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, (s->bias + 3356u), 0u);
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    { uint32_t addr = s->r[12] + 704u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00000d20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, (s->bias + 3368u), 0u);
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    { uint32_t addr = s->r[12] + 696u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00000d2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, (s->bias + 3380u), 0u);
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    { uint32_t addr = s->r[12] + 688u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00000d38(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, (s->bias + 3392u), 0u);
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    { uint32_t addr = s->r[12] + 680u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00000d44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, (s->bias + 3404u), 0u);
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    { uint32_t addr = s->r[12] + 672u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00000d50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, (s->bias + 3416u), 0u);
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    { uint32_t addr = s->r[12] + 664u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00000d80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = (s->bias + 3464u) + 4u; if ((rc = agr_aot_ldr(s, 0, addr))) return rc; }
    agr_aot_add_imm(s, 0, (s->bias + 3468u), s->r[0]);
    s->r[15] = (s->bias + 3464u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000dc4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 20472u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 10, 3);
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 1, 2);
    agr_aot_mov_reg(s, 8, 2);
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_mov_reg(s, 4, 0);
    { int rc = agr_aot_ldr(s, 6, s->r[13] + 40u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[3], (s->bias + 3548u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000ddc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 1, 10);
    agr_aot_movs_imm(s, 2, 0u);
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) return rc; }
    agr_aot_mov_reg(s, 7, 0);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, s->r[3], (s->bias + 3564u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000dec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 9, 0);
    s->r[15] = !s->r[6] ? (s->bias + 3586u) : (s->bias + 3568u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000df0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_mov_reg(s, 1, 6);
    agr_aot_movs_imm(s, 2, 0u);
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 748u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[3], (s->bias + 3582u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000dfe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = (s->bias + 3588u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000e02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 5, 6);
    s->r[15] = (s->bias + 3588u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000e04(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_movs_imm(s, 2, 0u);
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 44u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 744u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[3], (s->bias + 3602u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000e12(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movw(s, 1, 5126u);
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_mov_reg(s, 3, 7);
    agr_aot_mov_reg(s, 11, 0);
    agr_aot_movs_imm(s, 0, 3u);
    agr_aot_branch_reg(s, (s->bias + 3336u), (s->bias + 3618u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000e22(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 4u);
    agr_aot_movw(s, 1, 5126u);
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_mov_reg(s, 3, 9);
    agr_aot_branch_reg(s, (s->bias + 3348u), (s->bias + 3632u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000e30(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[5] ? (s->bias + 3648u) : (s->bias + 3634u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000e32(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    agr_aot_movw(s, 1, 5132u);
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_mov_reg(s, 3, 5);
    agr_aot_branch_reg(s, (s->bias + 3360u), (s->bias + 3648u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000e40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 4u);
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 48u); if (rc) return rc; }
    agr_aot_movw(s, 2, 5123u);
    agr_aot_mov_reg(s, 3, 11);
    agr_aot_branch_reg(s, (s->bias + 3372u), (s->bias + 3662u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000e4e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 44u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 11);
    { int rc = agr_aot_ldr(s, 12, s->r[3] + 776u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_branch_reg(s, s->r[12], (s->bias + 3678u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000e5e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[5] ? (s->bias + 3696u) : (s->bias + 3680u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000e60(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_mov_reg(s, 1, 6);
    agr_aot_mov_reg(s, 2, 5);
    { int rc = agr_aot_ldr(s, 12, s->r[3] + 780u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_branch_reg(s, s->r[12], (s->bias + 3696u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000e70(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_mov_reg(s, 1, 10);
    agr_aot_mov_reg(s, 2, 9);
    { int rc = agr_aot_ldr(s, 5, s->r[3] + 788u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_branch_reg(s, s->r[5], (s->bias + 3712u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000e80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_mov_reg(s, 1, 8);
    agr_aot_mov_reg(s, 2, 7);
    { int rc = agr_aot_ldr(s, 5, s->r[3] + 788u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_branch_reg(s, s->r[5], (s->bias + 3728u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000e90(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 36856u))) return rc;
}

static int aot_fast_00000e94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 17400u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 7, 3);
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 8, 2);
    agr_aot_mov_reg(s, 1, 2);
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_movw(s, 9, 5126u);
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[3], (s->bias + 3758u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000eae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 1, 7);
    agr_aot_movs_imm(s, 2, 0u);
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) return rc; }
    agr_aot_mov_reg(s, 5, 0);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, s->r[3], (s->bias + 3774u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000ebe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 1, 9);
    agr_aot_mov_reg(s, 3, 5);
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_mov_reg(s, 6, 0);
    agr_aot_movs_imm(s, 0, 2u);
    agr_aot_branch_reg(s, (s->bias + 3336u), (s->bias + 3788u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000ecc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 3, 6);
    agr_aot_mov_reg(s, 1, 9);
    agr_aot_movs_imm(s, 0, 4u);
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_branch_reg(s, (s->bias + 3348u), (s->bias + 3800u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000ed8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[13] + 32u); if (rc) return rc; }
    agr_aot_movs_imm(s, 0, 1u);
    agr_aot_movs_imm(s, 1, 0u);
    agr_aot_branch_reg(s, (s->bias + 3384u), (s->bias + 3810u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000ee2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_mov_reg(s, 1, 7);
    agr_aot_mov_reg(s, 2, 6);
    { int rc = agr_aot_ldr(s, 12, s->r[3] + 788u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_branch_reg(s, s->r[12], (s->bias + 3826u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000ef2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_mov_reg(s, 1, 8);
    agr_aot_mov_reg(s, 2, 5);
    { int rc = agr_aot_ldr(s, 6, s->r[3] + 788u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_branch_reg(s, s->r[6], (s->bias + 3842u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000f02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 33784u))) return rc;
}

static int aot_fast_00000f08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_lsls(s, 2, s->r[3], 1u);
    agr_aot_set_itstate(s, 76u); s->r[15] = (s->bias + 3854u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000f1a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 20471u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 9, 0);
    agr_aot_mov_reg(s, 6, 2);
    s->r[15] = !s->r[1] ? (s->bias + 3950u) : (s->bias + 3876u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000f24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 8, s->r[1], 1023u);
    agr_aot_movs_imm(s, 7, 0u);
    agr_aot_mov_reg(s, 10, 8);
    s->r[15] = (s->bias + 3884u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000f2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 4, s->r[7], s->r[10]);
    s->r[15] = (s->bias + 3888u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000f36(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 3, s->r[4], 3u);
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_add_imm(s, 5, s->r[9], s->r[3]);
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_branch_reg(s, (s->bias + 3848u) | 1u, (s->bias + 3908u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000f44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[4], s->r[8]);
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 4u); if (rc) return rc; }
    agr_aot_mov_reg(s, 11, 0);
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 3958u) : (s->bias + 3916u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000f4c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 0, s->r[3], 8u);
    s->r[0] += s->r[9];
    agr_aot_branch_reg(s, (s->bias + 3848u) | 1u, (s->bias + 3926u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000f56(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[6], s->r[11]);
    s->r[15] = agr_aot_condition(s, 2u) ? (s->bias + 3940u) : (s->bias + 3930u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000f5a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[4], s->r[7]);
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 3954u) : (s->bias + 3934u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000f5e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 10, s->r[4], 1023u);
    s->r[15] = (s->bias + 3884u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000f64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 0, s->r[0], 1u);
    agr_aot_cmp(s, s->r[6], s->r[0]);
    s->r[15] = agr_aot_condition(s, 9u) ? (s->bias + 3962u) : (s->bias + 3946u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000f6a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 7, s->r[4], 1u);
    s->r[15] = (s->bias + 3884u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000f6e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 5, 1);
    s->r[15] = (s->bias + 3962u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000f72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 5, 0u);
    s->r[15] = (s->bias + 3962u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000f76(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[6], s->r[0]);
    s->r[15] = agr_aot_condition(s, 3u) ? (s->bias + 3930u) : (s->bias + 3962u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000f7a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[13] += 12u;
    if ((rc = agr_aot_ldmia_sp(s, 36848u))) return rc;
}

static int aot_fast_00000f82(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 1u);
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 3988u) : (s->bias + 3974u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000f86(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 2u);
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 3996u) : (s->bias + 3978u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000f8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = s->r[0] ? (s->bias + 4004u) : (s->bias + 3980u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000f8c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, (s->bias + 3984u) + 24u); if (rc) return rc; }
    s->r[0] += (s->bias + 3986u);
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000f94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, (s->bias + 3992u) + 20u); if (rc) return rc; }
    s->r[0] += (s->bias + 3994u);
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000f9c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, (s->bias + 4000u) + 16u); if (rc) return rc; }
    s->r[0] += (s->bias + 4002u);
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000fa4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000fa8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 22u);
    agr_aot_lsls(s, 0, s->r[0], 0u);
    agr_aot_movs_imm(s, 0, 18u);
    agr_aot_lsls(s, 0, s->r[0], 0u);
    agr_aot_movs_imm(s, 0, 14u);
    agr_aot_lsls(s, 0, s->r[0], 0u);
    s->r[15] = (s->bias + 4020u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000fb4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, (s->bias + 4024u) + 148u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16499u)) return AGR_AOT_FAULT;
    s->r[3] += (s->bias + 4028u);
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_subs(s, 6, s->r[1], 2u);
    s->r[15] = !s->r[3] ? (s->bias + 4048u) : (s->bias + 4034u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000fc2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    agr_aot_branch_reg(s, (s->bias + 3396u), (s->bias + 4042u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000fca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = s->r[5] ? (s->bias + 4068u) : (s->bias + 4046u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000fce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = (s->bias + 4080u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000fd0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 5, (s->bias + 4052u) + 124u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, (s->bias + 4052u) + 128u); if (rc) return rc; }
    s->r[5] += (s->bias + 4056u);
    { int rc = agr_aot_ldr(s, 5, s->r[5] + 0u); if (rc) return rc; }
    s->r[3] += (s->bias + 4060u);
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_subs(s, 5, s->r[5], s->r[3]);
    agr_aot_mov_reg(s, 0, 3);
    s->r[15] = (s->bias + 4064u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000fe2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    s->r[15] = (s->bias + 4068u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000fe4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 4u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_branch_reg(s, (s->bias + 3866u) | 1u, (s->bias + 4076u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000fec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = s->r[0] ? (s->bias + 4086u) : (s->bias + 4080u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000ff0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    agr_aot_movs_imm(s, 0, 9u);
    s->r[15] = (s->bias + 4166u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000ff6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, (s->bias + 3848u) | 1u, (s->bias + 4090u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00000ffa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 4u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 1u);
    { uint32_t addr = s->r[4] + 72u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 4106u) : (s->bias + 4098u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001002(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_movs_imm(s, 0, 5u);
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = (s->bias + 4166u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000100a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 0u);
    agr_aot_add_imm(s, 0, s->r[5], 4u);
    s->r[15] = agr_aot_condition(s, 10u) ? (s->bias + 4120u) : (s->bias + 4114u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001012(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 76u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_movs_imm(s, 3, 1u);
    s->r[15] = (s->bias + 4128u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001018(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, (s->bias + 3848u) | 1u, (s->bias + 4124u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000101c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    { uint32_t addr = s->r[4] + 76u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = (s->bias + 4128u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001020(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[4] + 76u); if (rc) return rc; }
    { uint32_t addr = s->r[4] + 80u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 0u);
    s->r[15] = agr_aot_condition(s, 10u) ? (s->bias + 4158u) : (s->bias + 4138u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000102e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, (s->bias + 3970u) | 1u, (s->bias + 4146u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001032(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_cmp(s, s->r[0], 0u);
    agr_aot_set_itstate(s, 12u); s->r[15] = (s->bias + 4152u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000103e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, (s->bias + 3848u) | 1u, (s->bias + 4162u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001042(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = (s->bias + 4166u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001046(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00001058(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_lsls(s, 0, s->r[3], 31u);
    s->r[15] = agr_aot_condition(s, 4u) ? (s->bias + 4214u) : (s->bias + 4194u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001066(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 72u);
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 4210u) : (s->bias + 4204u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000106c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, (s->bias + 6260u) | 1u, (s->bias + 4208u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001070(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = (s->bias + 4214u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001072(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, (s->bias + 6244u) | 1u, (s->bias + 4214u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001076(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_lsls(s, 1, s->r[3], 29u);
    s->r[15] = agr_aot_condition(s, 4u) ? (s->bias + 4228u) : (s->bias + 4220u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000107c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 208u);
    agr_aot_branch_reg(s, (s->bias + 6276u) | 1u, (s->bias + 4228u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001084(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_lsls(s, 2, s->r[3], 28u);
    s->r[15] = agr_aot_condition(s, 4u) ? (s->bias + 4242u) : (s->bias + 4234u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000108a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 4008u);
    agr_aot_branch_reg(s, (s->bias + 6292u) | 1u, (s->bias + 4242u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001092(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_lsls(s, 3, s->r[3], 27u);
    s->r[15] = agr_aot_condition(s, 4u) ? (s->bias + 4260u) : (s->bias + 4248u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001098(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 4072u);
    if ((rc = agr_aot_ldmia_sp(s, 16400u))) return rc;
    s->r[15] = (s->bias + 6428u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000010a4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_000010b6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000010b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 5, 0);
    agr_aot_mov_reg(s, 4, 1);
    s->r[15] = (s->bias + 4286u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000010be(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 64u); if (rc) return rc; }
    agr_aot_branch_reg(s, (s->bias + 4020u) | 1u, (s->bias + 4294u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000010c6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 6, 0);
    s->r[15] = !s->r[0] ? (s->bias + 4302u) : (s->bias + 4298u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000010ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, (s->bias + 3408u), (s->bias + 4302u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000010ce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 64u); if (rc) return rc; }
    agr_aot_movs_imm(s, 0, 1u);
    agr_aot_mov_reg(s, 1, 5);
    agr_aot_mov_reg(s, 2, 4);
    { uint32_t addr = s->r[5] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 16u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[3], (s->bias + 4316u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000010dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 8u);
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 4286u) : (s->bias + 4320u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000010e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 7u);
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 4298u) : (s->bias + 4324u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000010e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 64u); if (rc) return rc; }
    agr_aot_branch_reg(s, (s->bias + 4278u) | 1u, (s->bias + 4332u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000010ec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 0, s->r[4], 4u);
    agr_aot_branch_reg(s, (s->bias + 6220u) | 1u, (s->bias + 4338u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000010f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 20464u)) return AGR_AOT_FAULT;
    agr_aot_adds(s, 5, s->r[1], 4u);
    { int rc = agr_aot_ldr(s, 8, s->r[0] + 12u); if (rc) return rc; }
    agr_aot_mov_reg(s, 7, 0);
    { int rc = agr_aot_ldr(s, 9, s->r[0] + 24u); if (rc) return rc; }
    agr_aot_mov_reg(s, 10, 2);
    s->r[15] = (s->bias + 4356u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000110a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 4, s->r[13], 12u);
    agr_aot_add_imm(s, 6, s->r[13], 8u);
    s->r[15] = (s->bias + 4366u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000111c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 5, s->r[13], 488u);
    if (agr_aot_stm(s, 4u, 15u)) return AGR_AOT_FAULT;
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_mov_reg(s, 11, 3);
    { uint32_t addr = s->r[6] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_mov_reg(s, 0, 7);
    { int rc = agr_aot_ldr(s, 1, s->r[6] + 64u); if (rc) return rc; }
    agr_aot_branch_reg(s, (s->bias + 4020u) | 1u, (s->bias + 4400u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001130(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[10], 0u);
    agr_aot_set_itstate(s, 20u); s->r[15] = (s->bias + 4406u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000011b4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 68u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000011b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[1] + 60u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16880u)) return AGR_AOT_FAULT;
    agr_aot_adds(s, 5, s->r[1], 4u);
    { uint32_t addr = s->r[1] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_mov_reg(s, 7, 0);
    agr_aot_mov_reg(s, 6, 1);
    s->r[13] -= 480u;
    s->r[15] = (s->bias + 4552u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000011ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 4, s->r[13], 4u);
    agr_aot_mov_reg(s, 8, 13);
    s->r[15] = (s->bias + 4558u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000011dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stm(s, 4u, 15u)) return AGR_AOT_FAULT;
    s->r[3] = 4294967295u;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = (s->bias + 4582u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000011e6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 7);
    { int rc = agr_aot_ldr(s, 1, s->r[8] + 64u); if (rc) return rc; }
    agr_aot_branch_reg(s, (s->bias + 4020u) | 1u, (s->bias + 4592u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000011f0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = s->r[0] ? (s->bias + 4626u) : (s->bias + 4594u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000011f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[7] + 16u); if (rc) return rc; }
    agr_aot_mov_reg(s, 1, 7);
    agr_aot_mov_reg(s, 2, 13);
    agr_aot_branch_reg(s, s->r[3], (s->bias + 4602u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000011fa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 8u);
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 4582u) : (s->bias + 4608u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001200(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 13);
    agr_aot_branch_reg(s, (s->bias + 4184u) | 1u, (s->bias + 4614u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001206(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[4], 6u);
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 4626u) : (s->bias + 4618u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000120a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 7);
    agr_aot_mov_reg(s, 1, 6);
    agr_aot_branch_reg(s, (s->bias + 4280u) | 1u, (s->bias + 4626u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001212(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 9u);
    s->r[13] += 480u;
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) return rc;
}

static int aot_fast_0000121a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    { uint32_t addr = s->r[0] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 60u); if (rc) return rc; }
    { uint32_t addr = s->r[0] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    agr_aot_mov_reg(s, 1, 3);
    if ((rc = agr_aot_ldmia_sp(s, 16400u))) return rc;
    { uint32_t addr = s->r[3] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = (s->bias + 4338u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000122e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 20u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 5, 0);
    { int rc = agr_aot_ldr(s, 6, s->r[0] + 12u); if (rc) return rc; }
    agr_aot_mov_reg(s, 4, 1);
    { uint32_t addr = s->r[1] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = !s->r[6] ? (s->bias + 4676u) : (s->bias + 4668u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000123c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 2, 1u);
    agr_aot_branch_reg(s, (s->bias + 4338u) | 1u, (s->bias + 4674u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001242(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = (s->bias + 4716u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001244(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 16u); if (rc) return rc; }
    agr_aot_mov_reg(s, 1, 5);
    agr_aot_movs_imm(s, 0, 2u);
    agr_aot_mov_reg(s, 2, 4);
    agr_aot_branch_reg(s, s->r[3], (s->bias + 4686u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000124e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 7u);
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 4702u) : (s->bias + 4690u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001252(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 8u);
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 4716u) : (s->bias + 4694u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001256(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 1, 4);
    agr_aot_branch_reg(s, (s->bias + 4280u) | 1u, (s->bias + 4702u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000125e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 64u); if (rc) return rc; }
    agr_aot_branch_reg(s, (s->bias + 4278u) | 1u, (s->bias + 4710u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001266(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 0, s->r[4], 4u);
    agr_aot_branch_reg(s, (s->bias + 6220u) | 1u, (s->bias + 4716u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000126c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, (s->bias + 3408u), (s->bias + 4720u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001270(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[0] + 12u); if (rc) return rc; }
    s->r[15] = s->r[2] ? (s->bias + 4728u) : (s->bias + 4724u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001274(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = (s->bias + 4536u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001278(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[1] + 60u); if (rc) return rc; }
    { uint32_t addr = s->r[1] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = (s->bias + 4338u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001280(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001282(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 1, 0);
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = !s->r[3] ? (s->bias + 4750u) : (s->bias + 4746u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000128a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 1u);
    agr_aot_branch_reg(s, s->r[3], (s->bias + 4750u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000128e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) return rc;
}

static int aot_fast_00001290(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16432u)) return AGR_AOT_FAULT;
    agr_aot_cmp(s, s->r[1], 4u);
    s->r[15] = agr_aot_condition(s, 8u) ? (s->bias + 4792u) : (s->bias + 4758u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000129a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 5, s->r[0], 12u);
    agr_aot_lsls(s, 7, s->r[1], 12u);
    agr_aot_lsls(s, 3, s->r[0], 0u);
    agr_aot_movs_imm(s, 0, 1u);
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) return rc;
}

static int aot_fast_000012b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) return rc;
}

static int aot_fast_000012d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16432u)) return AGR_AOT_FAULT;
    agr_aot_cmp(s, s->r[1], 4u);
    s->r[15] = agr_aot_condition(s, 8u) ? (s->bias + 4860u) : (s->bias + 4826u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000012de(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 5, s->r[0], 12u);
    agr_aot_lsls(s, 7, s->r[1], 12u);
    agr_aot_lsls(s, 3, s->r[0], 0u);
    agr_aot_movs_imm(s, 0, 1u);
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) return rc;
}

static int aot_fast_000012fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) return rc;
}

static int aot_fast_00001300(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16415u)) return AGR_AOT_FAULT;
    agr_aot_add_imm(s, 3, s->r[13], 16u);
    agr_aot_mov_reg(s, 4, 1);
    agr_aot_movs_imm(s, 1, 0u);
    { uint32_t addr = (s->r[3] - 4u); s->r[3] = s->r[3] - 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_mov_reg(s, 2, 4);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_mov_reg(s, 3, 1);
    agr_aot_branch_reg(s, (s->bias + 4820u) | 1u, (s->bias + 4886u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001316(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 16u;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_0000131a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[2] + 60u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16880u)) return AGR_AOT_FAULT;
    agr_aot_adds(s, 5, s->r[2], 4u);
    { uint32_t addr = s->r[2] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_mov_reg(s, 7, 0);
    agr_aot_mov_reg(s, 8, 1);
    s->r[15] = (s->bias + 4904u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000132e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 4, s->r[13], 92u);
    agr_aot_add_imm(s, 6, s->r[13], 88u);
    s->r[15] = (s->bias + 4914u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001340(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stm(s, 4u, 15u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 13);
    s->r[3] = 4294967295u;
    { uint32_t addr = s->r[6] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = (s->bias + 4940u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000134c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 13);
    { int rc = agr_aot_ldr(s, 1, s->r[6] + 64u); if (rc) return rc; }
    agr_aot_branch_reg(s, (s->bias + 4020u) | 1u, (s->bias + 4948u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001354(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[0] ? (s->bias + 4954u) : (s->bias + 4950u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001356(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 5, 9u);
    s->r[15] = (s->bias + 4996u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000135a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_movs_imm(s, 1, 12u);
    agr_aot_mov_reg(s, 2, 13);
    agr_aot_branch_reg(s, (s->bias + 4864u) | 1u, (s->bias + 4964u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001364(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_mov_reg(s, 1, 8);
    agr_aot_branch_reg(s, s->r[7], (s->bias + 4970u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000136a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 4950u) : (s->bias + 4974u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000136e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 16u); if (rc) return rc; }
    agr_aot_movs_imm(s, 0, 8u);
    agr_aot_mov_reg(s, 1, 13);
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_branch_reg(s, s->r[3], (s->bias + 4984u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001378(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 5u);
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 4996u) : (s->bias + 4990u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000137e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 9u);
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 4940u) : (s->bias + 4994u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001382(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = (s->bias + 4950u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001384(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, (s->bias + 4184u) | 1u, (s->bias + 5002u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000138a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_add_imm(s, 13, s->r[13], 3854u);
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) return rc;
}

static int aot_fast_00001394(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 20464u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 6, 2);
    { int rc = agr_aot_ldr(s, 2, s->r[1] + 76u); if (rc) return rc; }
    s->r[13] -= 36u;
    agr_aot_mov_reg(s, 11, 0);
    agr_aot_mov_reg(s, 4, 1);
    agr_aot_adds(s, 5, s->r[2], 4u);
    s->r[10] = s->r[0] & 3u;
    { int rc = agr_aot_ldr(s, 2, s->r[2] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 7, 3);
    { uint32_t addr = s->r[13] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { uint32_t addr = s->r[13] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = s->r[3] ? (s->bias + 5058u) : (s->bias + 5042u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000013b2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 2, s->r[2], 8u);
    { uint32_t addr = s->r[13] + 29u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    { uint32_t addr = s->r[13] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_movs_imm(s, 3, 3u);
    { uint32_t addr = s->r[13] + 28u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    s->r[15] = (s->bias + 5084u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000013c2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 2u);
    s->r[15] = agr_aot_condition(s, 12u) ? (s->bias + 5084u) : (s->bias + 5062u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000013c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[13] + 29u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    agr_aot_lsls(s, 2, s->r[2], 16u);
    { uint32_t addr = s->r[13] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[3] = s->r[3] & 0xffu;
    agr_aot_movs_imm(s, 2, 2u);
    { uint32_t addr = s->r[13] + 28u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    s->r[15] = (s->bias + 5080u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000013dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[10], 2u);
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 80u); if (rc) return rc; }
    agr_aot_set_itstate(s, 8u); s->r[15] = (s->bias + 5092u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000161c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = (s->bias + 5012u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001620(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 3, 1u);
    s->r[15] = (s->bias + 5012u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001624(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 3, 2u);
    s->r[15] = (s->bias + 5012u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001628(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16880u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    s->r[13] -= 264u;
    agr_aot_mov_reg(s, 7, 2);
    agr_aot_mov_reg(s, 5, 3);
    agr_aot_cmp(s, s->r[1], 4u);
    s->r[15] = agr_aot_condition(s, 8u) ? (s->bias + 5936u) : (s->bias + 5688u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000163c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 3, s->r[0], s->r[0]);
    agr_aot_cmp(s, s->r[0], 122u);
    agr_aot_lsls(s, 2, s->r[2], 1u);
    agr_aot_cmp(s, s->r[5], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 5936u) : (s->bias + 5702u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001646(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 56u); if (rc) return rc; }
    s->r[15] = (s->bias + 5704u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000164a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = (s->bias + 5708u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000164c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls_reg(s, 2, s->r[0], s->r[5]);
    s->r[15] = (s->bias + 5712u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001652(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 5726u) : (s->bias + 5716u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001654(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = (s->bias + 5718u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000165a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 3, s->r[3], 4u);
    { uint32_t addr = s->r[6] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = (s->bias + 5726u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000165e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 5, s->r[5], 1u);
    agr_aot_cmp(s, s->r[5], 16u);
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 5708u) : (s->bias + 5732u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001668(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6006u) : (s->bias + 5740u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000166c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 56u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = (s->bias + 6212u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001730(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    s->r[15] = (s->bias + 6212u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001776(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = (s->bias + 6212u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001844(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 264u;
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) return rc;
}

static int aot_fast_0000184c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 1, s->r[0], 52u);
    s->r[15] = (s->bias + 6224u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001854(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 12, 3);
    agr_aot_mov_reg(s, 14, 4);
    { uint32_t addr = (s->r[12] - 4u); s->r[12] = s->r[12] - 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    s->r[15] = (s->bias + 6236u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001860(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 13, 12);
    if ((rc = agr_aot_ldmia_sp(s, 32768u))) return rc;
}

static int aot_fast_00001868(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001870(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001878(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001880(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001888(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001890(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000018d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001918(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000192c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001940(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001944(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 12, 13);
    if (agr_aot_stmdb_sp(s, 16384u)) return AGR_AOT_FAULT;
    if (agr_aot_stmdb_sp(s, 20480u)) return AGR_AOT_FAULT;
    if (agr_aot_stmdb_sp(s, 8191u)) return AGR_AOT_FAULT;
    s->r[3] = 0u;
    if (agr_aot_stmdb_sp(s, 12u)) return AGR_AOT_FAULT;
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    agr_aot_branch_reg(s, (s->bias + 4536u) | 1u, (s->bias + 6494u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000195e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[13] += 72u;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001968(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 12, 13);
    if (agr_aot_stmdb_sp(s, 16384u)) return AGR_AOT_FAULT;
    if (agr_aot_stmdb_sp(s, 20480u)) return AGR_AOT_FAULT;
    if (agr_aot_stmdb_sp(s, 8191u)) return AGR_AOT_FAULT;
    s->r[3] = 0u;
    if (agr_aot_stmdb_sp(s, 12u)) return AGR_AOT_FAULT;
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    agr_aot_branch_reg(s, (s->bias + 4654u) | 1u, (s->bias + 6530u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001982(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[13] += 72u;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0000198c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 12, 13);
    if (agr_aot_stmdb_sp(s, 16384u)) return AGR_AOT_FAULT;
    if (agr_aot_stmdb_sp(s, 20480u)) return AGR_AOT_FAULT;
    if (agr_aot_stmdb_sp(s, 8191u)) return AGR_AOT_FAULT;
    s->r[3] = 0u;
    if (agr_aot_stmdb_sp(s, 12u)) return AGR_AOT_FAULT;
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    agr_aot_branch_reg(s, (s->bias + 4720u) | 1u, (s->bias + 6566u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000019a6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[13] += 72u;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000019b0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 12, 13);
    if (agr_aot_stmdb_sp(s, 16384u)) return AGR_AOT_FAULT;
    if (agr_aot_stmdb_sp(s, 20480u)) return AGR_AOT_FAULT;
    if (agr_aot_stmdb_sp(s, 8191u)) return AGR_AOT_FAULT;
    s->r[3] = 0u;
    if (agr_aot_stmdb_sp(s, 12u)) return AGR_AOT_FAULT;
    agr_aot_add_imm(s, 3, s->r[13], 4u);
    agr_aot_branch_reg(s, (s->bias + 4634u) | 1u, (s->bias + 6602u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000019ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[13] += 72u;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000019d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 12, 13);
    if (agr_aot_stmdb_sp(s, 16384u)) return AGR_AOT_FAULT;
    if (agr_aot_stmdb_sp(s, 20480u)) return AGR_AOT_FAULT;
    if (agr_aot_stmdb_sp(s, 8191u)) return AGR_AOT_FAULT;
    s->r[3] = 0u;
    if (agr_aot_stmdb_sp(s, 12u)) return AGR_AOT_FAULT;
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_branch_reg(s, (s->bias + 4890u) | 1u, (s->bias + 6638u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000019ee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[13] += 72u;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000019f8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = s->r[3] ? (s->bias + 6674u) : (s->bias + 6652u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000019fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 9u); if (rc) return rc; }
    s->r[15] = !s->r[3] ? (s->bias + 6688u) : (s->bias + 6656u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001a00(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 3, s->r[3], 1u);
    { uint32_t addr = s->r[0] + 9u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 4u); if (rc) return rc; }
    agr_aot_adds(s, 2, s->r[3], 4u);
    { uint32_t addr = s->r[0] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_movs_imm(s, 3, 3u);
    s->r[15] = (s->bias + 6676u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001a12(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 3, s->r[3], 1u);
    s->r[15] = (s->bias + 6676u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001a14(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[0] + 8u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_lsls(s, 2, s->r[3], 8u);
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = (s->bias + 6684u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001a1e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001a20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 176u);
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001a24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16415u)) return AGR_AOT_FAULT;
    agr_aot_movs_imm(s, 1, 0u);
    agr_aot_add_imm(s, 3, s->r[13], 12u);
    agr_aot_movs_imm(s, 2, 12u);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_mov_reg(s, 3, 1);
    agr_aot_branch_reg(s, (s->bias + 4752u) | 1u, (s->bias + 6708u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001a34(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 12u); if (rc) return rc; }
    s->r[13] += 20u;
    { uint32_t addr = s->r[13]; s->r[13] = s->r[13] + 4u; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00001a3c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = (s->bias + 6692u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001a3e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 18431u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 5, 0);
    agr_aot_mov_reg(s, 6, 1);
    agr_aot_movs_imm(s, 7, 0u);
    agr_aot_add_imm(s, 8, s->r[13], 12u);
    s->r[9] = 4080u;
    s->r[15] = (s->bias + 6736u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001a50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 6742u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001a56(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 176u);
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6786u) : (s->bias + 6748u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001a5c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[7], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7316u) : (s->bias + 6754u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001a62(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 4, s->r[13], 12u);
    agr_aot_mov_reg(s, 1, 7);
    agr_aot_mov_reg(s, 3, 7);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_movs_imm(s, 2, 14u);
    agr_aot_branch_reg(s, (s->bias + 4752u) | 1u, (s->bias + 6770u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001a72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 1, 7);
    agr_aot_movs_imm(s, 2, 15u);
    agr_aot_mov_reg(s, 3, 7);
    agr_aot_branch_reg(s, (s->bias + 4820u) | 1u, (s->bias + 6784u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001a80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = (s->bias + 7316u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001a8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6840u) : (s->bias + 6796u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001a90(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 3, 1);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_movs_imm(s, 2, 13u);
    s->r[15] = (s->bias + 6810u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001a9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, (s->bias + 4752u) | 1u, (s->bias + 6818u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001aa2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 12u); if (rc) return rc; }
    agr_aot_add_imm(s, 10, s->r[10], 4u);
    s->r[15] = (s->bias + 6824u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001aac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_set_itstate(s, 20u); s->r[15] = (s->bias + 6830u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001ab8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[3] = s->r[0] & 240u;
    agr_aot_cmp(s, s->r[3], 128u);
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6896u) : (s->bias + 6848u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001ac0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 4, s->r[0], 8u);
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 6856u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001aca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 32768u);
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6868u) : (s->bias + 6864u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001ad0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 9u);
    s->r[15] = (s->bias + 7318u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001ad4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 4, s->r[0], 4u);
    agr_aot_movs_imm(s, 1, 0u);
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = (s->bias + 6876u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001ade(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, (s->bias + 5672u) | 1u, (s->bias + 6882u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001ae2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6864u) : (s->bias + 6886u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001aea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_set_itstate(s, 24u); s->r[15] = (s->bias + 6892u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001af0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 144u);
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6944u) : (s->bias + 6900u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001af4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[3] = s->r[0] & 13u;
    agr_aot_cmp(s, s->r[3], 13u);
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 6864u) : (s->bias + 6908u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001afc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    agr_aot_mov_reg(s, 0, 5);
    s->r[2] = s->r[4] & 15u;
    agr_aot_mov_reg(s, 3, 1);
    agr_aot_branch_reg(s, (s->bias + 4752u) | 1u, (s->bias + 6926u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001b0e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_movs_imm(s, 1, 0u);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    s->r[15] = (s->bias + 6934u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001b16(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 2, 13u);
    agr_aot_mov_reg(s, 3, 1);
    agr_aot_branch_reg(s, (s->bias + 4820u) | 1u, (s->bias + 6942u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001b1e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = (s->bias + 6736u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001b20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 160u);
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6976u) : (s->bias + 6948u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001b26(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[2] = s->r[2] & 7u;
    s->r[15] = (s->bias + 6954u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001b2e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 3, s->r[0], 28u);
    s->r[2] = s->r[2] & 4080u;
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_set_itstate(s, 72u); s->r[15] = (s->bias + 6968u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001b40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 176u);
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7132u) : (s->bias + 6980u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001b44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 177u);
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7008u) : (s->bias + 6984u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001b48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 6990u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001b4e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 2, 0);
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 6864u) : (s->bias + 6996u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001b58(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6864u) : (s->bias + 7002u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001b5a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = (s->bias + 7004u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001b5c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = (s->bias + 7304u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001b60(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 178u);
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7082u) : (s->bias + 7012u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001b64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    agr_aot_movs_imm(s, 2, 13u);
    agr_aot_mov_reg(s, 3, 1);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_movs_imm(s, 4, 2u);
    agr_aot_branch_reg(s, (s->bias + 4752u) | 1u, (s->bias + 7030u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001b76(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 7036u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001b80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 12u); if (rc) return rc; }
    s->r[0] = s->r[0] & 127u;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 7064u) : (s->bias + 7048u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001b8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 4, s->r[4], 7u);
    s->r[3] += s->r[0];
    agr_aot_mov_reg(s, 0, 6);
    { uint32_t addr = s->r[13] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 7062u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001b96(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = (s->bias + 7036u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001b98(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 3, s->r[3], 3841u);
    s->r[15] = (s->bias + 7068u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001b9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[0] += s->r[3];
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    { uint32_t addr = s->r[13] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = (s->bias + 6934u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001baa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 179u);
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7108u) : (s->bias + 7086u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001bae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 7092u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001bb4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 1, 1u);
    s->r[3] = s->r[0] & 15u;
    s->r[2] = s->r[0] & 240u;
    agr_aot_adds(s, 3, s->r[3], 1u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = (s->bias + 7160u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001bc4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[3] = s->r[0] & 252u;
    agr_aot_cmp(s, s->r[3], 180u);
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 6864u) : (s->bias + 7116u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001bcc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[4] = s->r[0] & 7u;
    agr_aot_movs_imm(s, 1, 1u);
    agr_aot_adds(s, 2, s->r[4], 1u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[2] = s->r[2] | 524288u;
    s->r[15] = (s->bias + 7004u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001bdc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 192u);
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7278u) : (s->bias + 7136u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001be0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 198u);
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7166u) : (s->bias + 7140u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001be4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 7146u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001bea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 1, 3u);
    s->r[3] = s->r[0] & 15u;
    s->r[2] = s->r[0] & 240u;
    agr_aot_adds(s, 3, s->r[3], 1u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = (s->bias + 7160u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001bfc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = (s->bias + 7004u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001bfe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 199u);
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7198u) : (s->bias + 7170u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001c02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 7176u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001c08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 2, 0);
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 6864u) : (s->bias + 7184u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001c14(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6864u) : (s->bias + 7192u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001c18(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_movs_imm(s, 1, 4u);
    s->r[15] = (s->bias + 7304u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001c1e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[3] = s->r[0] & 248u;
    agr_aot_cmp(s, s->r[3], 192u);
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7222u) : (s->bias + 7206u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001c26(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[4] = s->r[0] & 15u;
    agr_aot_movs_imm(s, 1, 3u);
    agr_aot_adds(s, 2, s->r[4], 1u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[2] = s->r[2] | 655360u;
    s->r[15] = (s->bias + 7004u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001c36(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 200u);
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7246u) : (s->bias + 7226u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001c3a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 7232u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001c40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[2] = s->r[0] & 240u;
    s->r[0] = s->r[0] & 15u;
    agr_aot_adds(s, 2, s->r[2], 16u);
    agr_aot_adds(s, 3, s->r[0], 1u);
    s->r[15] = (s->bias + 7268u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001c4e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 201u);
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6864u) : (s->bias + 7252u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001c54(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 7258u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001c5a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[3] = s->r[0] & 15u;
    s->r[2] = s->r[0] & 240u;
    agr_aot_adds(s, 3, s->r[3], 1u);
    s->r[15] = (s->bias + 7268u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001c64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = (s->bias + 7272u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001c6c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = (s->bias + 7302u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001c6e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[3] = s->r[0] & 248u;
    agr_aot_cmp(s, s->r[3], 208u);
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6864u) : (s->bias + 7288u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001c78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[4] = s->r[0] & 7u;
    agr_aot_movs_imm(s, 1, 1u);
    agr_aot_adds(s, 2, s->r[4], 1u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[2] = s->r[2] | 524288u;
    s->r[15] = (s->bias + 7302u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001c86(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 3, 5u);
    s->r[15] = (s->bias + 7304u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001c88(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, (s->bias + 5672u) | 1u, (s->bias + 7308u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001c8c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6864u) : (s->bias + 7314u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001c92(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = (s->bias + 6736u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001c94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = (s->bias + 7318u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001c96(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 16u;
    if ((rc = agr_aot_ldmia_sp(s, 34800u))) return rc;
}

static int aot_fast_00001c9c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16415u)) return AGR_AOT_FAULT;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 76u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 1);
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 4u); if (rc) return rc; }
    agr_aot_lsls(s, 2, s->r[2], 8u);
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_add_imm(s, 2, s->r[3], 8u);
    { uint32_t addr = s->r[13] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_movs_imm(s, 2, 3u);
    { uint32_t addr = s->r[13] + 12u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    { int rc = agr_aot_ldrb(s, 3, s->r[3] + 7u); if (rc) return rc; }
    { uint32_t addr = s->r[13] + 13u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, (s->bias + 6718u) | 1u, (s->bias + 7360u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001cc0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 20u;
    { uint32_t addr = s->r[13]; s->r[13] = s->r[13] + 4u; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00001cc6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    agr_aot_branch_reg(s, (s->bias + 6716u) | 1u, (s->bias + 7372u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001ccc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 72u); if (rc) return rc; }
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) return rc;
}

static int aot_fast_00001cd0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    agr_aot_branch_reg(s, (s->bias + 6716u) | 1u, (s->bias + 7382u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001cd6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 76u); if (rc) return rc; }
    { int rc = agr_aot_ldrb(s, 2, s->r[3] + 7u); if (rc) return rc; }
    s->r[15] = (s->bias + 7386u);
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001cde(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 0, s->r[0], 8u);
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) return rc;
}

static int aot_fast_00001ce2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    agr_aot_branch_reg(s, (s->bias + 3408u), (s->bias + 7400u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00001ce8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    agr_aot_branch_reg(s, (s->bias + 3408u), (s->bias + 7406u), 1); return AGR_AOT_BOUNDARY;
}

const AgrAotEntry agr_aot_debug_blocks[] = {
    {3324u, aot_debug_00000cfc, 1u},
    {3328u, aot_debug_00000d00, 1u},
    {3332u, aot_debug_00000d04, 1u},
    {3336u, aot_debug_00000d08, 1u},
    {3340u, aot_debug_00000d0c, 1u},
    {3344u, aot_debug_00000d10, 1u},
    {3348u, aot_debug_00000d14, 1u},
    {3352u, aot_debug_00000d18, 1u},
    {3356u, aot_debug_00000d1c, 1u},
    {3360u, aot_debug_00000d20, 1u},
    {3364u, aot_debug_00000d24, 1u},
    {3368u, aot_debug_00000d28, 1u},
    {3372u, aot_debug_00000d2c, 1u},
    {3376u, aot_debug_00000d30, 1u},
    {3380u, aot_debug_00000d34, 1u},
    {3384u, aot_debug_00000d38, 1u},
    {3388u, aot_debug_00000d3c, 1u},
    {3392u, aot_debug_00000d40, 1u},
    {3396u, aot_debug_00000d44, 1u},
    {3400u, aot_debug_00000d48, 1u},
    {3404u, aot_debug_00000d4c, 1u},
    {3408u, aot_debug_00000d50, 1u},
    {3412u, aot_debug_00000d54, 1u},
    {3416u, aot_debug_00000d58, 1u},
    {3456u, aot_debug_00000d80, 1u},
    {3460u, aot_debug_00000d84, 1u},
    {3524u, aot_debug_00000dc4, 1u},
    {3528u, aot_debug_00000dc8, 1u},
    {3530u, aot_debug_00000dca, 1u},
    {3532u, aot_debug_00000dcc, 1u},
    {3534u, aot_debug_00000dce, 1u},
    {3536u, aot_debug_00000dd0, 1u},
    {3538u, aot_debug_00000dd2, 1u},
    {3540u, aot_debug_00000dd4, 1u},
    {3542u, aot_debug_00000dd6, 1u},
    {3546u, aot_debug_00000dda, 1u},
    {3548u, aot_debug_00000ddc, 1u},
    {3550u, aot_debug_00000dde, 1u},
    {3552u, aot_debug_00000de0, 1u},
    {3554u, aot_debug_00000de2, 1u},
    {3558u, aot_debug_00000de6, 1u},
    {3560u, aot_debug_00000de8, 1u},
    {3562u, aot_debug_00000dea, 1u},
    {3564u, aot_debug_00000dec, 1u},
    {3566u, aot_debug_00000dee, 1u},
    {3568u, aot_debug_00000df0, 1u},
    {3570u, aot_debug_00000df2, 1u},
    {3572u, aot_debug_00000df4, 1u},
    {3574u, aot_debug_00000df6, 1u},
    {3576u, aot_debug_00000df8, 1u},
    {3580u, aot_debug_00000dfc, 1u},
    {3582u, aot_debug_00000dfe, 1u},
    {3584u, aot_debug_00000e00, 1u},
    {3586u, aot_debug_00000e02, 1u},
    {3588u, aot_debug_00000e04, 1u},
    {3590u, aot_debug_00000e06, 1u},
    {3592u, aot_debug_00000e08, 1u},
    {3594u, aot_debug_00000e0a, 1u},
    {3596u, aot_debug_00000e0c, 1u},
    {3600u, aot_debug_00000e10, 1u},
    {3602u, aot_debug_00000e12, 1u},
    {3606u, aot_debug_00000e16, 1u},
    {3608u, aot_debug_00000e18, 1u},
    {3610u, aot_debug_00000e1a, 1u},
    {3612u, aot_debug_00000e1c, 1u},
    {3614u, aot_debug_00000e1e, 1u},
    {3618u, aot_debug_00000e22, 1u},
    {3620u, aot_debug_00000e24, 1u},
    {3624u, aot_debug_00000e28, 1u},
    {3626u, aot_debug_00000e2a, 1u},
    {3628u, aot_debug_00000e2c, 1u},
    {3632u, aot_debug_00000e30, 1u},
    {3634u, aot_debug_00000e32, 1u},
    {3636u, aot_debug_00000e34, 1u},
    {3640u, aot_debug_00000e38, 1u},
    {3642u, aot_debug_00000e3a, 1u},
    {3644u, aot_debug_00000e3c, 1u},
    {3648u, aot_debug_00000e40, 1u},
    {3650u, aot_debug_00000e42, 1u},
    {3652u, aot_debug_00000e44, 1u},
    {3656u, aot_debug_00000e48, 1u},
    {3658u, aot_debug_00000e4a, 1u},
    {3662u, aot_debug_00000e4e, 1u},
    {3664u, aot_debug_00000e50, 1u},
    {3666u, aot_debug_00000e52, 1u},
    {3668u, aot_debug_00000e54, 1u},
    {3670u, aot_debug_00000e56, 1u},
    {3674u, aot_debug_00000e5a, 1u},
    {3676u, aot_debug_00000e5c, 1u},
    {3678u, aot_debug_00000e5e, 1u},
    {3680u, aot_debug_00000e60, 1u},
    {3682u, aot_debug_00000e62, 1u},
    {3684u, aot_debug_00000e64, 1u},
    {3686u, aot_debug_00000e66, 1u},
    {3688u, aot_debug_00000e68, 1u},
    {3692u, aot_debug_00000e6c, 1u},
    {3694u, aot_debug_00000e6e, 1u},
    {3696u, aot_debug_00000e70, 1u},
    {3698u, aot_debug_00000e72, 1u},
    {3700u, aot_debug_00000e74, 1u},
    {3702u, aot_debug_00000e76, 1u},
    {3704u, aot_debug_00000e78, 1u},
    {3708u, aot_debug_00000e7c, 1u},
    {3710u, aot_debug_00000e7e, 1u},
    {3712u, aot_debug_00000e80, 1u},
    {3714u, aot_debug_00000e82, 1u},
    {3716u, aot_debug_00000e84, 1u},
    {3718u, aot_debug_00000e86, 1u},
    {3720u, aot_debug_00000e88, 1u},
    {3724u, aot_debug_00000e8c, 1u},
    {3726u, aot_debug_00000e8e, 1u},
    {3728u, aot_debug_00000e90, 1u},
    {3732u, aot_debug_00000e94, 1u},
    {3736u, aot_debug_00000e98, 1u},
    {3738u, aot_debug_00000e9a, 1u},
    {3740u, aot_debug_00000e9c, 1u},
    {3742u, aot_debug_00000e9e, 1u},
    {3744u, aot_debug_00000ea0, 1u},
    {3746u, aot_debug_00000ea2, 1u},
    {3748u, aot_debug_00000ea4, 1u},
    {3752u, aot_debug_00000ea8, 1u},
    {3756u, aot_debug_00000eac, 1u},
    {3758u, aot_debug_00000eae, 1u},
    {3760u, aot_debug_00000eb0, 1u},
    {3762u, aot_debug_00000eb2, 1u},
    {3764u, aot_debug_00000eb4, 1u},
    {3768u, aot_debug_00000eb8, 1u},
    {3770u, aot_debug_00000eba, 1u},
    {3772u, aot_debug_00000ebc, 1u},
    {3774u, aot_debug_00000ebe, 1u},
    {3776u, aot_debug_00000ec0, 1u},
    {3778u, aot_debug_00000ec2, 1u},
    {3780u, aot_debug_00000ec4, 1u},
    {3782u, aot_debug_00000ec6, 1u},
    {3784u, aot_debug_00000ec8, 1u},
    {3788u, aot_debug_00000ecc, 1u},
    {3790u, aot_debug_00000ece, 1u},
    {3792u, aot_debug_00000ed0, 1u},
    {3794u, aot_debug_00000ed2, 1u},
    {3796u, aot_debug_00000ed4, 1u},
    {3800u, aot_debug_00000ed8, 1u},
    {3802u, aot_debug_00000eda, 1u},
    {3804u, aot_debug_00000edc, 1u},
    {3806u, aot_debug_00000ede, 1u},
    {3810u, aot_debug_00000ee2, 1u},
    {3812u, aot_debug_00000ee4, 1u},
    {3814u, aot_debug_00000ee6, 1u},
    {3816u, aot_debug_00000ee8, 1u},
    {3818u, aot_debug_00000eea, 1u},
    {3822u, aot_debug_00000eee, 1u},
    {3824u, aot_debug_00000ef0, 1u},
    {3826u, aot_debug_00000ef2, 1u},
    {3828u, aot_debug_00000ef4, 1u},
    {3830u, aot_debug_00000ef6, 1u},
    {3832u, aot_debug_00000ef8, 1u},
    {3834u, aot_debug_00000efa, 1u},
    {3838u, aot_debug_00000efe, 1u},
    {3840u, aot_debug_00000f00, 1u},
    {3842u, aot_debug_00000f02, 1u},
    {3848u, aot_debug_00000f08, 1u},
    {3850u, aot_debug_00000f0a, 1u},
    {3852u, aot_debug_00000f0c, 1u},
    {3866u, aot_debug_00000f1a, 1u},
    {3870u, aot_debug_00000f1e, 1u},
    {3872u, aot_debug_00000f20, 1u},
    {3874u, aot_debug_00000f22, 1u},
    {3876u, aot_debug_00000f24, 1u},
    {3880u, aot_debug_00000f28, 1u},
    {3882u, aot_debug_00000f2a, 1u},
    {3884u, aot_debug_00000f2c, 1u},
    {3894u, aot_debug_00000f36, 1u},
    {3896u, aot_debug_00000f38, 1u},
    {3898u, aot_debug_00000f3a, 1u},
    {3902u, aot_debug_00000f3e, 1u},
    {3904u, aot_debug_00000f40, 1u},
    {3908u, aot_debug_00000f44, 1u},
    {3910u, aot_debug_00000f46, 1u},
    {3912u, aot_debug_00000f48, 1u},
    {3914u, aot_debug_00000f4a, 1u},
    {3916u, aot_debug_00000f4c, 1u},
    {3920u, aot_debug_00000f50, 1u},
    {3922u, aot_debug_00000f52, 1u},
    {3926u, aot_debug_00000f56, 1u},
    {3928u, aot_debug_00000f58, 1u},
    {3930u, aot_debug_00000f5a, 1u},
    {3932u, aot_debug_00000f5c, 1u},
    {3934u, aot_debug_00000f5e, 1u},
    {3938u, aot_debug_00000f62, 1u},
    {3940u, aot_debug_00000f64, 1u},
    {3942u, aot_debug_00000f66, 1u},
    {3944u, aot_debug_00000f68, 1u},
    {3946u, aot_debug_00000f6a, 1u},
    {3948u, aot_debug_00000f6c, 1u},
    {3950u, aot_debug_00000f6e, 1u},
    {3952u, aot_debug_00000f70, 1u},
    {3954u, aot_debug_00000f72, 1u},
    {3956u, aot_debug_00000f74, 1u},
    {3958u, aot_debug_00000f76, 1u},
    {3960u, aot_debug_00000f78, 1u},
    {3962u, aot_debug_00000f7a, 1u},
    {3964u, aot_debug_00000f7c, 1u},
    {3966u, aot_debug_00000f7e, 1u},
    {3970u, aot_debug_00000f82, 1u},
    {3972u, aot_debug_00000f84, 1u},
    {3974u, aot_debug_00000f86, 1u},
    {3976u, aot_debug_00000f88, 1u},
    {3978u, aot_debug_00000f8a, 1u},
    {3980u, aot_debug_00000f8c, 1u},
    {3982u, aot_debug_00000f8e, 1u},
    {3984u, aot_debug_00000f90, 1u},
    {3986u, aot_debug_00000f92, 1u},
    {3988u, aot_debug_00000f94, 1u},
    {3990u, aot_debug_00000f96, 1u},
    {3992u, aot_debug_00000f98, 1u},
    {3994u, aot_debug_00000f9a, 1u},
    {3996u, aot_debug_00000f9c, 1u},
    {3998u, aot_debug_00000f9e, 1u},
    {4000u, aot_debug_00000fa0, 1u},
    {4002u, aot_debug_00000fa2, 1u},
    {4004u, aot_debug_00000fa4, 1u},
    {4006u, aot_debug_00000fa6, 1u},
    {4008u, aot_debug_00000fa8, 1u},
    {4010u, aot_debug_00000faa, 1u},
    {4012u, aot_debug_00000fac, 1u},
    {4014u, aot_debug_00000fae, 1u},
    {4016u, aot_debug_00000fb0, 1u},
    {4018u, aot_debug_00000fb2, 1u},
    {4020u, aot_debug_00000fb4, 1u},
    {4022u, aot_debug_00000fb6, 1u},
    {4024u, aot_debug_00000fb8, 1u},
    {4026u, aot_debug_00000fba, 1u},
    {4028u, aot_debug_00000fbc, 1u},
    {4030u, aot_debug_00000fbe, 1u},
    {4032u, aot_debug_00000fc0, 1u},
    {4034u, aot_debug_00000fc2, 1u},
    {4036u, aot_debug_00000fc4, 1u},
    {4038u, aot_debug_00000fc6, 1u},
    {4042u, aot_debug_00000fca, 1u},
    {4044u, aot_debug_00000fcc, 1u},
    {4046u, aot_debug_00000fce, 1u},
    {4048u, aot_debug_00000fd0, 1u},
    {4050u, aot_debug_00000fd2, 1u},
    {4052u, aot_debug_00000fd4, 1u},
    {4054u, aot_debug_00000fd6, 1u},
    {4056u, aot_debug_00000fd8, 1u},
    {4058u, aot_debug_00000fda, 1u},
    {4060u, aot_debug_00000fdc, 1u},
    {4062u, aot_debug_00000fde, 1u},
    {4066u, aot_debug_00000fe2, 1u},
    {4068u, aot_debug_00000fe4, 1u},
    {4070u, aot_debug_00000fe6, 1u},
    {4072u, aot_debug_00000fe8, 1u},
    {4076u, aot_debug_00000fec, 1u},
    {4078u, aot_debug_00000fee, 1u},
    {4080u, aot_debug_00000ff0, 1u},
    {4082u, aot_debug_00000ff2, 1u},
    {4084u, aot_debug_00000ff4, 1u},
    {4086u, aot_debug_00000ff6, 1u},
    {4090u, aot_debug_00000ffa, 1u},
    {4092u, aot_debug_00000ffc, 1u},
    {4094u, aot_debug_00000ffe, 1u},
    {4096u, aot_debug_00001000, 1u},
    {4098u, aot_debug_00001002, 1u},
    {4100u, aot_debug_00001004, 1u},
    {4102u, aot_debug_00001006, 1u},
    {4104u, aot_debug_00001008, 1u},
    {4106u, aot_debug_0000100a, 1u},
    {4108u, aot_debug_0000100c, 1u},
    {4112u, aot_debug_00001010, 1u},
    {4114u, aot_debug_00001012, 1u},
    {4116u, aot_debug_00001014, 1u},
    {4118u, aot_debug_00001016, 1u},
    {4120u, aot_debug_00001018, 1u},
    {4124u, aot_debug_0000101c, 1u},
    {4126u, aot_debug_0000101e, 1u},
    {4128u, aot_debug_00001020, 1u},
    {4130u, aot_debug_00001022, 1u},
    {4132u, aot_debug_00001024, 1u},
    {4134u, aot_debug_00001026, 1u},
    {4136u, aot_debug_00001028, 1u},
    {4142u, aot_debug_0000102e, 1u},
    {4146u, aot_debug_00001032, 1u},
    {4148u, aot_debug_00001034, 1u},
    {4150u, aot_debug_00001036, 1u},
    {4158u, aot_debug_0000103e, 1u},
    {4162u, aot_debug_00001042, 1u},
    {4164u, aot_debug_00001044, 1u},
    {4166u, aot_debug_00001046, 1u},
    {4168u, aot_debug_00001048, 1u},
    {4184u, aot_debug_00001058, 1u},
    {4186u, aot_debug_0000105a, 1u},
    {4188u, aot_debug_0000105c, 1u},
    {4190u, aot_debug_0000105e, 1u},
    {4192u, aot_debug_00001060, 1u},
    {4198u, aot_debug_00001066, 1u},
    {4202u, aot_debug_0000106a, 1u},
    {4204u, aot_debug_0000106c, 1u},
    {4208u, aot_debug_00001070, 1u},
    {4210u, aot_debug_00001072, 1u},
    {4214u, aot_debug_00001076, 1u},
    {4216u, aot_debug_00001078, 1u},
    {4218u, aot_debug_0000107a, 1u},
    {4220u, aot_debug_0000107c, 1u},
    {4224u, aot_debug_00001080, 1u},
    {4228u, aot_debug_00001084, 1u},
    {4230u, aot_debug_00001086, 1u},
    {4232u, aot_debug_00001088, 1u},
    {4234u, aot_debug_0000108a, 1u},
    {4238u, aot_debug_0000108e, 1u},
    {4242u, aot_debug_00001092, 1u},
    {4244u, aot_debug_00001094, 1u},
    {4246u, aot_debug_00001096, 1u},
    {4248u, aot_debug_00001098, 1u},
    {4252u, aot_debug_0000109c, 1u},
    {4256u, aot_debug_000010a0, 1u},
    {4260u, aot_debug_000010a4, 1u},
    {4278u, aot_debug_000010b6, 1u},
    {4280u, aot_debug_000010b8, 1u},
    {4282u, aot_debug_000010ba, 1u},
    {4284u, aot_debug_000010bc, 1u},
    {4286u, aot_debug_000010be, 1u},
    {4288u, aot_debug_000010c0, 1u},
    {4290u, aot_debug_000010c2, 1u},
    {4294u, aot_debug_000010c6, 1u},
    {4296u, aot_debug_000010c8, 1u},
    {4298u, aot_debug_000010ca, 1u},
    {4302u, aot_debug_000010ce, 1u},
    {4304u, aot_debug_000010d0, 1u},
    {4306u, aot_debug_000010d2, 1u},
    {4308u, aot_debug_000010d4, 1u},
    {4310u, aot_debug_000010d6, 1u},
    {4312u, aot_debug_000010d8, 1u},
    {4314u, aot_debug_000010da, 1u},
    {4316u, aot_debug_000010dc, 1u},
    {4318u, aot_debug_000010de, 1u},
    {4320u, aot_debug_000010e0, 1u},
    {4322u, aot_debug_000010e2, 1u},
    {4324u, aot_debug_000010e4, 1u},
    {4326u, aot_debug_000010e6, 1u},
    {4328u, aot_debug_000010e8, 1u},
    {4332u, aot_debug_000010ec, 1u},
    {4334u, aot_debug_000010ee, 1u},
    {4338u, aot_debug_000010f2, 1u},
    {4342u, aot_debug_000010f6, 1u},
    {4344u, aot_debug_000010f8, 1u},
    {4348u, aot_debug_000010fc, 1u},
    {4350u, aot_debug_000010fe, 1u},
    {4354u, aot_debug_00001102, 1u},
    {4362u, aot_debug_0000110a, 1u},
    {4364u, aot_debug_0000110c, 1u},
    {4380u, aot_debug_0000111c, 1u},
    {4382u, aot_debug_0000111e, 1u},
    {4386u, aot_debug_00001122, 1u},
    {4388u, aot_debug_00001124, 1u},
    {4390u, aot_debug_00001126, 1u},
    {4392u, aot_debug_00001128, 1u},
    {4394u, aot_debug_0000112a, 1u},
    {4396u, aot_debug_0000112c, 1u},
    {4400u, aot_debug_00001130, 1u},
    {4404u, aot_debug_00001134, 1u},
    {4532u, aot_debug_000011b4, 1u},
    {4534u, aot_debug_000011b6, 1u},
    {4536u, aot_debug_000011b8, 1u},
    {4538u, aot_debug_000011ba, 1u},
    {4542u, aot_debug_000011be, 1u},
    {4544u, aot_debug_000011c0, 1u},
    {4546u, aot_debug_000011c2, 1u},
    {4548u, aot_debug_000011c4, 1u},
    {4550u, aot_debug_000011c6, 1u},
    {4554u, aot_debug_000011ca, 1u},
    {4556u, aot_debug_000011cc, 1u},
    {4572u, aot_debug_000011dc, 1u},
    {4576u, aot_debug_000011e0, 1u},
    {4580u, aot_debug_000011e4, 1u},
    {4582u, aot_debug_000011e6, 1u},
    {4584u, aot_debug_000011e8, 1u},
    {4588u, aot_debug_000011ec, 1u},
    {4592u, aot_debug_000011f0, 1u},
    {4594u, aot_debug_000011f2, 1u},
    {4596u, aot_debug_000011f4, 1u},
    {4598u, aot_debug_000011f6, 1u},
    {4600u, aot_debug_000011f8, 1u},
    {4602u, aot_debug_000011fa, 1u},
    {4604u, aot_debug_000011fc, 1u},
    {4606u, aot_debug_000011fe, 1u},
    {4608u, aot_debug_00001200, 1u},
    {4610u, aot_debug_00001202, 1u},
    {4614u, aot_debug_00001206, 1u},
    {4616u, aot_debug_00001208, 1u},
    {4618u, aot_debug_0000120a, 1u},
    {4620u, aot_debug_0000120c, 1u},
    {4622u, aot_debug_0000120e, 1u},
    {4626u, aot_debug_00001212, 1u},
    {4628u, aot_debug_00001214, 1u},
    {4630u, aot_debug_00001216, 1u},
    {4634u, aot_debug_0000121a, 1u},
    {4636u, aot_debug_0000121c, 1u},
    {4638u, aot_debug_0000121e, 1u},
    {4640u, aot_debug_00001220, 1u},
    {4642u, aot_debug_00001222, 1u},
    {4644u, aot_debug_00001224, 1u},
    {4648u, aot_debug_00001228, 1u},
    {4650u, aot_debug_0000122a, 1u},
    {4652u, aot_debug_0000122c, 1u},
    {4654u, aot_debug_0000122e, 1u},
    {4656u, aot_debug_00001230, 1u},
    {4658u, aot_debug_00001232, 1u},
    {4660u, aot_debug_00001234, 1u},
    {4662u, aot_debug_00001236, 1u},
    {4664u, aot_debug_00001238, 1u},
    {4666u, aot_debug_0000123a, 1u},
    {4668u, aot_debug_0000123c, 1u},
    {4670u, aot_debug_0000123e, 1u},
    {4674u, aot_debug_00001242, 1u},
    {4676u, aot_debug_00001244, 1u},
    {4678u, aot_debug_00001246, 1u},
    {4680u, aot_debug_00001248, 1u},
    {4682u, aot_debug_0000124a, 1u},
    {4684u, aot_debug_0000124c, 1u},
    {4686u, aot_debug_0000124e, 1u},
    {4688u, aot_debug_00001250, 1u},
    {4690u, aot_debug_00001252, 1u},
    {4692u, aot_debug_00001254, 1u},
    {4694u, aot_debug_00001256, 1u},
    {4696u, aot_debug_00001258, 1u},
    {4698u, aot_debug_0000125a, 1u},
    {4702u, aot_debug_0000125e, 1u},
    {4704u, aot_debug_00001260, 1u},
    {4706u, aot_debug_00001262, 1u},
    {4710u, aot_debug_00001266, 1u},
    {4712u, aot_debug_00001268, 1u},
    {4716u, aot_debug_0000126c, 1u},
    {4720u, aot_debug_00001270, 1u},
    {4722u, aot_debug_00001272, 1u},
    {4724u, aot_debug_00001274, 1u},
    {4728u, aot_debug_00001278, 1u},
    {4730u, aot_debug_0000127a, 1u},
    {4732u, aot_debug_0000127c, 1u},
    {4734u, aot_debug_0000127e, 1u},
    {4736u, aot_debug_00001280, 1u},
    {4738u, aot_debug_00001282, 1u},
    {4740u, aot_debug_00001284, 1u},
    {4742u, aot_debug_00001286, 1u},
    {4744u, aot_debug_00001288, 1u},
    {4746u, aot_debug_0000128a, 1u},
    {4748u, aot_debug_0000128c, 1u},
    {4750u, aot_debug_0000128e, 1u},
    {4752u, aot_debug_00001290, 1u},
    {4754u, aot_debug_00001292, 1u},
    {4756u, aot_debug_00001294, 1u},
    {4762u, aot_debug_0000129a, 1u},
    {4764u, aot_debug_0000129c, 1u},
    {4766u, aot_debug_0000129e, 1u},
    {4768u, aot_debug_000012a0, 1u},
    {4770u, aot_debug_000012a2, 1u},
    {4792u, aot_debug_000012b8, 1u},
    {4794u, aot_debug_000012ba, 1u},
    {4820u, aot_debug_000012d4, 1u},
    {4822u, aot_debug_000012d6, 1u},
    {4824u, aot_debug_000012d8, 1u},
    {4830u, aot_debug_000012de, 1u},
    {4832u, aot_debug_000012e0, 1u},
    {4834u, aot_debug_000012e2, 1u},
    {4836u, aot_debug_000012e4, 1u},
    {4838u, aot_debug_000012e6, 1u},
    {4860u, aot_debug_000012fc, 1u},
    {4862u, aot_debug_000012fe, 1u},
    {4864u, aot_debug_00001300, 1u},
    {4866u, aot_debug_00001302, 1u},
    {4868u, aot_debug_00001304, 1u},
    {4870u, aot_debug_00001306, 1u},
    {4872u, aot_debug_00001308, 1u},
    {4876u, aot_debug_0000130c, 1u},
    {4878u, aot_debug_0000130e, 1u},
    {4880u, aot_debug_00001310, 1u},
    {4882u, aot_debug_00001312, 1u},
    {4886u, aot_debug_00001316, 1u},
    {4888u, aot_debug_00001318, 1u},
    {4890u, aot_debug_0000131a, 1u},
    {4892u, aot_debug_0000131c, 1u},
    {4896u, aot_debug_00001320, 1u},
    {4898u, aot_debug_00001322, 1u},
    {4900u, aot_debug_00001324, 1u},
    {4902u, aot_debug_00001326, 1u},
    {4910u, aot_debug_0000132e, 1u},
    {4912u, aot_debug_00001330, 1u},
    {4928u, aot_debug_00001340, 1u},
    {4932u, aot_debug_00001344, 1u},
    {4934u, aot_debug_00001346, 1u},
    {4938u, aot_debug_0000134a, 1u},
    {4940u, aot_debug_0000134c, 1u},
    {4942u, aot_debug_0000134e, 1u},
    {4944u, aot_debug_00001350, 1u},
    {4948u, aot_debug_00001354, 1u},
    {4950u, aot_debug_00001356, 1u},
    {4952u, aot_debug_00001358, 1u},
    {4954u, aot_debug_0000135a, 1u},
    {4956u, aot_debug_0000135c, 1u},
    {4958u, aot_debug_0000135e, 1u},
    {4960u, aot_debug_00001360, 1u},
    {4964u, aot_debug_00001364, 1u},
    {4966u, aot_debug_00001366, 1u},
    {4968u, aot_debug_00001368, 1u},
    {4970u, aot_debug_0000136a, 1u},
    {4972u, aot_debug_0000136c, 1u},
    {4974u, aot_debug_0000136e, 1u},
    {4976u, aot_debug_00001370, 1u},
    {4978u, aot_debug_00001372, 1u},
    {4980u, aot_debug_00001374, 1u},
    {4982u, aot_debug_00001376, 1u},
    {4984u, aot_debug_00001378, 1u},
    {4986u, aot_debug_0000137a, 1u},
    {4988u, aot_debug_0000137c, 1u},
    {4990u, aot_debug_0000137e, 1u},
    {4992u, aot_debug_00001380, 1u},
    {4994u, aot_debug_00001382, 1u},
    {4996u, aot_debug_00001384, 1u},
    {4998u, aot_debug_00001386, 1u},
    {5002u, aot_debug_0000138a, 1u},
    {5004u, aot_debug_0000138c, 1u},
    {5008u, aot_debug_00001390, 1u},
    {5012u, aot_debug_00001394, 1u},
    {5016u, aot_debug_00001398, 1u},
    {5018u, aot_debug_0000139a, 1u},
    {5020u, aot_debug_0000139c, 1u},
    {5022u, aot_debug_0000139e, 1u},
    {5024u, aot_debug_000013a0, 1u},
    {5026u, aot_debug_000013a2, 1u},
    {5028u, aot_debug_000013a4, 1u},
    {5032u, aot_debug_000013a8, 1u},
    {5034u, aot_debug_000013aa, 1u},
    {5036u, aot_debug_000013ac, 1u},
    {5038u, aot_debug_000013ae, 1u},
    {5040u, aot_debug_000013b0, 1u},
    {5042u, aot_debug_000013b2, 1u},
    {5044u, aot_debug_000013b4, 1u},
    {5048u, aot_debug_000013b8, 1u},
    {5050u, aot_debug_000013ba, 1u},
    {5052u, aot_debug_000013bc, 1u},
    {5056u, aot_debug_000013c0, 1u},
    {5058u, aot_debug_000013c2, 1u},
    {5060u, aot_debug_000013c4, 1u},
    {5064u, aot_debug_000013c8, 1u},
    {5068u, aot_debug_000013cc, 1u},
    {5070u, aot_debug_000013ce, 1u},
    {5072u, aot_debug_000013d0, 1u},
    {5074u, aot_debug_000013d2, 1u},
    {5076u, aot_debug_000013d4, 1u},
    {5084u, aot_debug_000013dc, 1u},
    {5088u, aot_debug_000013e0, 1u},
    {5090u, aot_debug_000013e2, 1u},
    {5660u, aot_debug_0000161c, 1u},
    {5662u, aot_debug_0000161e, 1u},
    {5664u, aot_debug_00001620, 1u},
    {5666u, aot_debug_00001622, 1u},
    {5668u, aot_debug_00001624, 1u},
    {5670u, aot_debug_00001626, 1u},
    {5672u, aot_debug_00001628, 1u},
    {5676u, aot_debug_0000162c, 1u},
    {5678u, aot_debug_0000162e, 1u},
    {5680u, aot_debug_00001630, 1u},
    {5682u, aot_debug_00001632, 1u},
    {5684u, aot_debug_00001634, 1u},
    {5686u, aot_debug_00001636, 1u},
    {5692u, aot_debug_0000163c, 1u},
    {5694u, aot_debug_0000163e, 1u},
    {5696u, aot_debug_00001640, 1u},
    {5698u, aot_debug_00001642, 1u},
    {5700u, aot_debug_00001644, 1u},
    {5702u, aot_debug_00001646, 1u},
    {5706u, aot_debug_0000164a, 1u},
    {5708u, aot_debug_0000164c, 1u},
    {5714u, aot_debug_00001652, 1u},
    {5716u, aot_debug_00001654, 1u},
    {5722u, aot_debug_0000165a, 1u},
    {5724u, aot_debug_0000165c, 1u},
    {5726u, aot_debug_0000165e, 1u},
    {5728u, aot_debug_00001660, 1u},
    {5730u, aot_debug_00001662, 1u},
    {5736u, aot_debug_00001668, 1u},
    {5740u, aot_debug_0000166c, 1u},
    {5742u, aot_debug_0000166e, 1u},
    {5936u, aot_debug_00001730, 1u},
    {5938u, aot_debug_00001732, 1u},
    {6006u, aot_debug_00001776, 1u},
    {6008u, aot_debug_00001778, 1u},
    {6212u, aot_debug_00001844, 1u},
    {6214u, aot_debug_00001846, 1u},
    {6220u, aot_debug_0000184c, 1u},
    {6228u, aot_debug_00001854, 1u},
    {6230u, aot_debug_00001856, 1u},
    {6232u, aot_debug_00001858, 1u},
    {6240u, aot_debug_00001860, 1u},
    {6242u, aot_debug_00001862, 1u},
    {6248u, aot_debug_00001868, 1u},
    {6256u, aot_debug_00001870, 1u},
    {6264u, aot_debug_00001878, 1u},
    {6272u, aot_debug_00001880, 1u},
    {6280u, aot_debug_00001888, 1u},
    {6288u, aot_debug_00001890, 1u},
    {6356u, aot_debug_000018d4, 1u},
    {6424u, aot_debug_00001918, 1u},
    {6444u, aot_debug_0000192c, 1u},
    {6464u, aot_debug_00001940, 1u},
    {6468u, aot_debug_00001944, 1u},
    {6470u, aot_debug_00001946, 1u},
    {6472u, aot_debug_00001948, 1u},
    {6476u, aot_debug_0000194c, 1u},
    {6480u, aot_debug_00001950, 1u},
    {6484u, aot_debug_00001954, 1u},
    {6488u, aot_debug_00001958, 1u},
    {6490u, aot_debug_0000195a, 1u},
    {6494u, aot_debug_0000195e, 1u},
    {6498u, aot_debug_00001962, 1u},
    {6500u, aot_debug_00001964, 1u},
    {6504u, aot_debug_00001968, 1u},
    {6506u, aot_debug_0000196a, 1u},
    {6508u, aot_debug_0000196c, 1u},
    {6512u, aot_debug_00001970, 1u},
    {6516u, aot_debug_00001974, 1u},
    {6520u, aot_debug_00001978, 1u},
    {6524u, aot_debug_0000197c, 1u},
    {6526u, aot_debug_0000197e, 1u},
    {6530u, aot_debug_00001982, 1u},
    {6534u, aot_debug_00001986, 1u},
    {6536u, aot_debug_00001988, 1u},
    {6540u, aot_debug_0000198c, 1u},
    {6542u, aot_debug_0000198e, 1u},
    {6544u, aot_debug_00001990, 1u},
    {6548u, aot_debug_00001994, 1u},
    {6552u, aot_debug_00001998, 1u},
    {6556u, aot_debug_0000199c, 1u},
    {6560u, aot_debug_000019a0, 1u},
    {6562u, aot_debug_000019a2, 1u},
    {6566u, aot_debug_000019a6, 1u},
    {6570u, aot_debug_000019aa, 1u},
    {6572u, aot_debug_000019ac, 1u},
    {6576u, aot_debug_000019b0, 1u},
    {6578u, aot_debug_000019b2, 1u},
    {6580u, aot_debug_000019b4, 1u},
    {6584u, aot_debug_000019b8, 1u},
    {6588u, aot_debug_000019bc, 1u},
    {6592u, aot_debug_000019c0, 1u},
    {6596u, aot_debug_000019c4, 1u},
    {6598u, aot_debug_000019c6, 1u},
    {6602u, aot_debug_000019ca, 1u},
    {6606u, aot_debug_000019ce, 1u},
    {6608u, aot_debug_000019d0, 1u},
    {6612u, aot_debug_000019d4, 1u},
    {6614u, aot_debug_000019d6, 1u},
    {6616u, aot_debug_000019d8, 1u},
    {6620u, aot_debug_000019dc, 1u},
    {6624u, aot_debug_000019e0, 1u},
    {6628u, aot_debug_000019e4, 1u},
    {6632u, aot_debug_000019e8, 1u},
    {6634u, aot_debug_000019ea, 1u},
    {6638u, aot_debug_000019ee, 1u},
    {6642u, aot_debug_000019f2, 1u},
    {6644u, aot_debug_000019f4, 1u},
    {6648u, aot_debug_000019f8, 1u},
    {6650u, aot_debug_000019fa, 1u},
    {6652u, aot_debug_000019fc, 1u},
    {6654u, aot_debug_000019fe, 1u},
    {6656u, aot_debug_00001a00, 1u},
    {6658u, aot_debug_00001a02, 1u},
    {6660u, aot_debug_00001a04, 1u},
    {6662u, aot_debug_00001a06, 1u},
    {6664u, aot_debug_00001a08, 1u},
    {6666u, aot_debug_00001a0a, 1u},
    {6668u, aot_debug_00001a0c, 1u},
    {6670u, aot_debug_00001a0e, 1u},
    {6672u, aot_debug_00001a10, 1u},
    {6674u, aot_debug_00001a12, 1u},
    {6676u, aot_debug_00001a14, 1u},
    {6678u, aot_debug_00001a16, 1u},
    {6680u, aot_debug_00001a18, 1u},
    {6682u, aot_debug_00001a1a, 1u},
    {6686u, aot_debug_00001a1e, 1u},
    {6688u, aot_debug_00001a20, 1u},
    {6690u, aot_debug_00001a22, 1u},
    {6692u, aot_debug_00001a24, 1u},
    {6694u, aot_debug_00001a26, 1u},
    {6696u, aot_debug_00001a28, 1u},
    {6698u, aot_debug_00001a2a, 1u},
    {6700u, aot_debug_00001a2c, 1u},
    {6702u, aot_debug_00001a2e, 1u},
    {6704u, aot_debug_00001a30, 1u},
    {6708u, aot_debug_00001a34, 1u},
    {6710u, aot_debug_00001a36, 1u},
    {6712u, aot_debug_00001a38, 1u},
    {6716u, aot_debug_00001a3c, 1u},
    {6718u, aot_debug_00001a3e, 1u},
    {6722u, aot_debug_00001a42, 1u},
    {6724u, aot_debug_00001a44, 1u},
    {6726u, aot_debug_00001a46, 1u},
    {6728u, aot_debug_00001a48, 1u},
    {6732u, aot_debug_00001a4c, 1u},
    {6736u, aot_debug_00001a50, 1u},
    {6738u, aot_debug_00001a52, 1u},
    {6742u, aot_debug_00001a56, 1u},
    {6744u, aot_debug_00001a58, 1u},
    {6746u, aot_debug_00001a5a, 1u},
    {6748u, aot_debug_00001a5c, 1u},
    {6750u, aot_debug_00001a5e, 1u},
    {6754u, aot_debug_00001a62, 1u},
    {6756u, aot_debug_00001a64, 1u},
    {6758u, aot_debug_00001a66, 1u},
    {6760u, aot_debug_00001a68, 1u},
    {6762u, aot_debug_00001a6a, 1u},
    {6764u, aot_debug_00001a6c, 1u},
    {6766u, aot_debug_00001a6e, 1u},
    {6770u, aot_debug_00001a72, 1u},
    {6772u, aot_debug_00001a74, 1u},
    {6774u, aot_debug_00001a76, 1u},
    {6776u, aot_debug_00001a78, 1u},
    {6778u, aot_debug_00001a7a, 1u},
    {6780u, aot_debug_00001a7c, 1u},
    {6784u, aot_debug_00001a80, 1u},
    {6794u, aot_debug_00001a8a, 1u},
    {6800u, aot_debug_00001a90, 1u},
    {6802u, aot_debug_00001a92, 1u},
    {6806u, aot_debug_00001a96, 1u},
    {6808u, aot_debug_00001a98, 1u},
    {6814u, aot_debug_00001a9e, 1u},
    {6818u, aot_debug_00001aa2, 1u},
    {6820u, aot_debug_00001aa4, 1u},
    {6828u, aot_debug_00001aac, 1u},
    {6840u, aot_debug_00001ab8, 1u},
    {6844u, aot_debug_00001abc, 1u},
    {6846u, aot_debug_00001abe, 1u},
    {6848u, aot_debug_00001ac0, 1u},
    {6850u, aot_debug_00001ac2, 1u},
    {6852u, aot_debug_00001ac4, 1u},
    {6858u, aot_debug_00001aca, 1u},
    {6862u, aot_debug_00001ace, 1u},
    {6864u, aot_debug_00001ad0, 1u},
    {6866u, aot_debug_00001ad2, 1u},
    {6868u, aot_debug_00001ad4, 1u},
    {6870u, aot_debug_00001ad6, 1u},
    {6872u, aot_debug_00001ad8, 1u},
    {6874u, aot_debug_00001ada, 1u},
    {6878u, aot_debug_00001ade, 1u},
    {6882u, aot_debug_00001ae2, 1u},
    {6884u, aot_debug_00001ae4, 1u},
    {6890u, aot_debug_00001aea, 1u},
    {6896u, aot_debug_00001af0, 1u},
    {6898u, aot_debug_00001af2, 1u},
    {6900u, aot_debug_00001af4, 1u},
    {6904u, aot_debug_00001af8, 1u},
    {6906u, aot_debug_00001afa, 1u},
    {6908u, aot_debug_00001afc, 1u},
    {6910u, aot_debug_00001afe, 1u},
    {6914u, aot_debug_00001b02, 1u},
    {6916u, aot_debug_00001b04, 1u},
    {6920u, aot_debug_00001b08, 1u},
    {6922u, aot_debug_00001b0a, 1u},
    {6926u, aot_debug_00001b0e, 1u},
    {6928u, aot_debug_00001b10, 1u},
    {6930u, aot_debug_00001b12, 1u},
    {6934u, aot_debug_00001b16, 1u},
    {6936u, aot_debug_00001b18, 1u},
    {6938u, aot_debug_00001b1a, 1u},
    {6942u, aot_debug_00001b1e, 1u},
    {6944u, aot_debug_00001b20, 1u},
    {6946u, aot_debug_00001b22, 1u},
    {6950u, aot_debug_00001b26, 1u},
    {6958u, aot_debug_00001b2e, 1u},
    {6960u, aot_debug_00001b30, 1u},
    {6964u, aot_debug_00001b34, 1u},
    {6966u, aot_debug_00001b36, 1u},
    {6976u, aot_debug_00001b40, 1u},
    {6978u, aot_debug_00001b42, 1u},
    {6980u, aot_debug_00001b44, 1u},
    {6982u, aot_debug_00001b46, 1u},
    {6984u, aot_debug_00001b48, 1u},
    {6986u, aot_debug_00001b4a, 1u},
    {6990u, aot_debug_00001b4e, 1u},
    {6992u, aot_debug_00001b50, 1u},
    {6994u, aot_debug_00001b52, 1u},
    {7000u, aot_debug_00001b58, 1u},
    {7002u, aot_debug_00001b5a, 1u},
    {7004u, aot_debug_00001b5c, 1u},
    {7006u, aot_debug_00001b5e, 1u},
    {7008u, aot_debug_00001b60, 1u},
    {7010u, aot_debug_00001b62, 1u},
    {7012u, aot_debug_00001b64, 1u},
    {7014u, aot_debug_00001b66, 1u},
    {7016u, aot_debug_00001b68, 1u},
    {7018u, aot_debug_00001b6a, 1u},
    {7022u, aot_debug_00001b6e, 1u},
    {7024u, aot_debug_00001b70, 1u},
    {7026u, aot_debug_00001b72, 1u},
    {7030u, aot_debug_00001b76, 1u},
    {7032u, aot_debug_00001b78, 1u},
    {7040u, aot_debug_00001b80, 1u},
    {7042u, aot_debug_00001b82, 1u},
    {7046u, aot_debug_00001b86, 1u},
    {7050u, aot_debug_00001b8a, 1u},
    {7052u, aot_debug_00001b8c, 1u},
    {7054u, aot_debug_00001b8e, 1u},
    {7056u, aot_debug_00001b90, 1u},
    {7058u, aot_debug_00001b92, 1u},
    {7062u, aot_debug_00001b96, 1u},
    {7064u, aot_debug_00001b98, 1u},
    {7070u, aot_debug_00001b9e, 1u},
    {7072u, aot_debug_00001ba0, 1u},
    {7076u, aot_debug_00001ba4, 1u},
    {7078u, aot_debug_00001ba6, 1u},
    {7080u, aot_debug_00001ba8, 1u},
    {7082u, aot_debug_00001baa, 1u},
    {7084u, aot_debug_00001bac, 1u},
    {7086u, aot_debug_00001bae, 1u},
    {7088u, aot_debug_00001bb0, 1u},
    {7092u, aot_debug_00001bb4, 1u},
    {7094u, aot_debug_00001bb6, 1u},
    {7098u, aot_debug_00001bba, 1u},
    {7102u, aot_debug_00001bbe, 1u},
    {7104u, aot_debug_00001bc0, 1u},
    {7106u, aot_debug_00001bc2, 1u},
    {7108u, aot_debug_00001bc4, 1u},
    {7112u, aot_debug_00001bc8, 1u},
    {7114u, aot_debug_00001bca, 1u},
    {7116u, aot_debug_00001bcc, 1u},
    {7120u, aot_debug_00001bd0, 1u},
    {7122u, aot_debug_00001bd2, 1u},
    {7124u, aot_debug_00001bd4, 1u},
    {7126u, aot_debug_00001bd6, 1u},
    {7130u, aot_debug_00001bda, 1u},
    {7132u, aot_debug_00001bdc, 1u},
    {7134u, aot_debug_00001bde, 1u},
    {7136u, aot_debug_00001be0, 1u},
    {7138u, aot_debug_00001be2, 1u},
    {7140u, aot_debug_00001be4, 1u},
    {7142u, aot_debug_00001be6, 1u},
    {7146u, aot_debug_00001bea, 1u},
    {7148u, aot_debug_00001bec, 1u},
    {7152u, aot_debug_00001bf0, 1u},
    {7156u, aot_debug_00001bf4, 1u},
    {7158u, aot_debug_00001bf6, 1u},
    {7164u, aot_debug_00001bfc, 1u},
    {7166u, aot_debug_00001bfe, 1u},
    {7168u, aot_debug_00001c00, 1u},
    {7170u, aot_debug_00001c02, 1u},
    {7172u, aot_debug_00001c04, 1u},
    {7176u, aot_debug_00001c08, 1u},
    {7178u, aot_debug_00001c0a, 1u},
    {7180u, aot_debug_00001c0c, 1u},
    {7188u, aot_debug_00001c14, 1u},
    {7192u, aot_debug_00001c18, 1u},
    {7194u, aot_debug_00001c1a, 1u},
    {7196u, aot_debug_00001c1c, 1u},
    {7198u, aot_debug_00001c1e, 1u},
    {7202u, aot_debug_00001c22, 1u},
    {7204u, aot_debug_00001c24, 1u},
    {7206u, aot_debug_00001c26, 1u},
    {7210u, aot_debug_00001c2a, 1u},
    {7212u, aot_debug_00001c2c, 1u},
    {7214u, aot_debug_00001c2e, 1u},
    {7216u, aot_debug_00001c30, 1u},
    {7220u, aot_debug_00001c34, 1u},
    {7222u, aot_debug_00001c36, 1u},
    {7224u, aot_debug_00001c38, 1u},
    {7226u, aot_debug_00001c3a, 1u},
    {7228u, aot_debug_00001c3c, 1u},
    {7232u, aot_debug_00001c40, 1u},
    {7236u, aot_debug_00001c44, 1u},
    {7240u, aot_debug_00001c48, 1u},
    {7242u, aot_debug_00001c4a, 1u},
    {7244u, aot_debug_00001c4c, 1u},
    {7246u, aot_debug_00001c4e, 1u},
    {7248u, aot_debug_00001c50, 1u},
    {7252u, aot_debug_00001c54, 1u},
    {7254u, aot_debug_00001c56, 1u},
    {7258u, aot_debug_00001c5a, 1u},
    {7262u, aot_debug_00001c5e, 1u},
    {7266u, aot_debug_00001c62, 1u},
    {7268u, aot_debug_00001c64, 1u},
    {7270u, aot_debug_00001c66, 1u},
    {7276u, aot_debug_00001c6c, 1u},
    {7278u, aot_debug_00001c6e, 1u},
    {7282u, aot_debug_00001c72, 1u},
    {7284u, aot_debug_00001c74, 1u},
    {7288u, aot_debug_00001c78, 1u},
    {7292u, aot_debug_00001c7c, 1u},
    {7294u, aot_debug_00001c7e, 1u},
    {7296u, aot_debug_00001c80, 1u},
    {7298u, aot_debug_00001c82, 1u},
    {7302u, aot_debug_00001c86, 1u},
    {7304u, aot_debug_00001c88, 1u},
    {7308u, aot_debug_00001c8c, 1u},
    {7310u, aot_debug_00001c8e, 1u},
    {7314u, aot_debug_00001c92, 1u},
    {7316u, aot_debug_00001c94, 1u},
    {7318u, aot_debug_00001c96, 1u},
    {7320u, aot_debug_00001c98, 1u},
    {7324u, aot_debug_00001c9c, 1u},
    {7326u, aot_debug_00001c9e, 1u},
    {7328u, aot_debug_00001ca0, 1u},
    {7330u, aot_debug_00001ca2, 1u},
    {7332u, aot_debug_00001ca4, 1u},
    {7334u, aot_debug_00001ca6, 1u},
    {7336u, aot_debug_00001ca8, 1u},
    {7338u, aot_debug_00001caa, 1u},
    {7342u, aot_debug_00001cae, 1u},
    {7344u, aot_debug_00001cb0, 1u},
    {7346u, aot_debug_00001cb2, 1u},
    {7350u, aot_debug_00001cb6, 1u},
    {7352u, aot_debug_00001cb8, 1u},
    {7356u, aot_debug_00001cbc, 1u},
    {7360u, aot_debug_00001cc0, 1u},
    {7362u, aot_debug_00001cc2, 1u},
    {7366u, aot_debug_00001cc6, 1u},
    {7368u, aot_debug_00001cc8, 1u},
    {7372u, aot_debug_00001ccc, 1u},
    {7374u, aot_debug_00001cce, 1u},
    {7376u, aot_debug_00001cd0, 1u},
    {7378u, aot_debug_00001cd2, 1u},
    {7382u, aot_debug_00001cd6, 1u},
    {7384u, aot_debug_00001cd8, 1u},
    {7390u, aot_debug_00001cde, 1u},
    {7392u, aot_debug_00001ce0, 1u},
    {7394u, aot_debug_00001ce2, 1u},
    {7396u, aot_debug_00001ce4, 1u},
    {7400u, aot_debug_00001ce8, 1u},
    {7402u, aot_debug_00001cea, 1u},
};
const uint32_t agr_aot_debug_block_count = 925u;

const AgrAotEntry agr_aot_fast_blocks[] = {
    {3324u, aot_fast_00000cfc, 3u},
    {3336u, aot_fast_00000d08, 3u},
    {3348u, aot_fast_00000d14, 3u},
    {3360u, aot_fast_00000d20, 3u},
    {3372u, aot_fast_00000d2c, 3u},
    {3384u, aot_fast_00000d38, 3u},
    {3396u, aot_fast_00000d44, 3u},
    {3408u, aot_fast_00000d50, 3u},
    {3456u, aot_fast_00000d80, 2u},
    {3524u, aot_fast_00000dc4, 10u},
    {3548u, aot_fast_00000ddc, 7u},
    {3564u, aot_fast_00000dec, 2u},
    {3568u, aot_fast_00000df0, 6u},
    {3582u, aot_fast_00000dfe, 2u},
    {3586u, aot_fast_00000e02, 1u},
    {3588u, aot_fast_00000e04, 6u},
    {3602u, aot_fast_00000e12, 6u},
    {3618u, aot_fast_00000e22, 5u},
    {3632u, aot_fast_00000e30, 1u},
    {3634u, aot_fast_00000e32, 5u},
    {3648u, aot_fast_00000e40, 5u},
    {3662u, aot_fast_00000e4e, 7u},
    {3678u, aot_fast_00000e5e, 1u},
    {3680u, aot_fast_00000e60, 7u},
    {3696u, aot_fast_00000e70, 7u},
    {3712u, aot_fast_00000e80, 7u},
    {3728u, aot_fast_00000e90, 1u},
    {3732u, aot_fast_00000e94, 10u},
    {3758u, aot_fast_00000eae, 7u},
    {3774u, aot_fast_00000ebe, 6u},
    {3788u, aot_fast_00000ecc, 5u},
    {3800u, aot_fast_00000ed8, 4u},
    {3810u, aot_fast_00000ee2, 7u},
    {3826u, aot_fast_00000ef2, 7u},
    {3842u, aot_fast_00000f02, 1u},
    {3848u, aot_fast_00000f08, 3u},
    {3866u, aot_fast_00000f1a, 4u},
    {3876u, aot_fast_00000f24, 3u},
    {3884u, aot_fast_00000f2c, 1u},
    {3894u, aot_fast_00000f36, 5u},
    {3908u, aot_fast_00000f44, 4u},
    {3916u, aot_fast_00000f4c, 3u},
    {3926u, aot_fast_00000f56, 2u},
    {3930u, aot_fast_00000f5a, 2u},
    {3934u, aot_fast_00000f5e, 2u},
    {3940u, aot_fast_00000f64, 3u},
    {3946u, aot_fast_00000f6a, 2u},
    {3950u, aot_fast_00000f6e, 2u},
    {3954u, aot_fast_00000f72, 2u},
    {3958u, aot_fast_00000f76, 2u},
    {3962u, aot_fast_00000f7a, 3u},
    {3970u, aot_fast_00000f82, 2u},
    {3974u, aot_fast_00000f86, 2u},
    {3978u, aot_fast_00000f8a, 1u},
    {3980u, aot_fast_00000f8c, 4u},
    {3988u, aot_fast_00000f94, 4u},
    {3996u, aot_fast_00000f9c, 4u},
    {4004u, aot_fast_00000fa4, 2u},
    {4008u, aot_fast_00000fa8, 6u},
    {4020u, aot_fast_00000fb4, 7u},
    {4034u, aot_fast_00000fc2, 3u},
    {4042u, aot_fast_00000fca, 2u},
    {4046u, aot_fast_00000fce, 1u},
    {4048u, aot_fast_00000fd0, 8u},
    {4066u, aot_fast_00000fe2, 1u},
    {4068u, aot_fast_00000fe4, 3u},
    {4076u, aot_fast_00000fec, 2u},
    {4080u, aot_fast_00000ff0, 3u},
    {4086u, aot_fast_00000ff6, 1u},
    {4090u, aot_fast_00000ffa, 4u},
    {4098u, aot_fast_00001002, 4u},
    {4106u, aot_fast_0000100a, 3u},
    {4114u, aot_fast_00001012, 3u},
    {4120u, aot_fast_00001018, 1u},
    {4124u, aot_fast_0000101c, 2u},
    {4128u, aot_fast_00001020, 5u},
    {4142u, aot_fast_0000102e, 1u},
    {4146u, aot_fast_00001032, 3u},
    {4158u, aot_fast_0000103e, 1u},
    {4162u, aot_fast_00001042, 2u},
    {4166u, aot_fast_00001046, 2u},
    {4184u, aot_fast_00001058, 5u},
    {4198u, aot_fast_00001066, 2u},
    {4204u, aot_fast_0000106c, 1u},
    {4208u, aot_fast_00001070, 1u},
    {4210u, aot_fast_00001072, 1u},
    {4214u, aot_fast_00001076, 3u},
    {4220u, aot_fast_0000107c, 2u},
    {4228u, aot_fast_00001084, 3u},
    {4234u, aot_fast_0000108a, 2u},
    {4242u, aot_fast_00001092, 3u},
    {4248u, aot_fast_00001098, 3u},
    {4260u, aot_fast_000010a4, 1u},
    {4278u, aot_fast_000010b6, 1u},
    {4280u, aot_fast_000010b8, 3u},
    {4286u, aot_fast_000010be, 3u},
    {4294u, aot_fast_000010c6, 2u},
    {4298u, aot_fast_000010ca, 1u},
    {4302u, aot_fast_000010ce, 7u},
    {4316u, aot_fast_000010dc, 2u},
    {4320u, aot_fast_000010e0, 2u},
    {4324u, aot_fast_000010e4, 3u},
    {4332u, aot_fast_000010ec, 2u},
    {4338u, aot_fast_000010f2, 6u},
    {4362u, aot_fast_0000110a, 2u},
    {4380u, aot_fast_0000111c, 8u},
    {4400u, aot_fast_00001130, 2u},
    {4532u, aot_fast_000011b4, 2u},
    {4536u, aot_fast_000011b8, 7u},
    {4554u, aot_fast_000011ca, 2u},
    {4572u, aot_fast_000011dc, 3u},
    {4582u, aot_fast_000011e6, 3u},
    {4592u, aot_fast_000011f0, 1u},
    {4594u, aot_fast_000011f2, 4u},
    {4602u, aot_fast_000011fa, 3u},
    {4608u, aot_fast_00001200, 2u},
    {4614u, aot_fast_00001206, 2u},
    {4618u, aot_fast_0000120a, 3u},
    {4626u, aot_fast_00001212, 3u},
    {4634u, aot_fast_0000121a, 9u},
    {4654u, aot_fast_0000122e, 7u},
    {4668u, aot_fast_0000123c, 2u},
    {4674u, aot_fast_00001242, 1u},
    {4676u, aot_fast_00001244, 5u},
    {4686u, aot_fast_0000124e, 2u},
    {4690u, aot_fast_00001252, 2u},
    {4694u, aot_fast_00001256, 3u},
    {4702u, aot_fast_0000125e, 3u},
    {4710u, aot_fast_00001266, 2u},
    {4716u, aot_fast_0000126c, 1u},
    {4720u, aot_fast_00001270, 2u},
    {4724u, aot_fast_00001274, 1u},
    {4728u, aot_fast_00001278, 4u},
    {4736u, aot_fast_00001280, 1u},
    {4738u, aot_fast_00001282, 4u},
    {4746u, aot_fast_0000128a, 2u},
    {4750u, aot_fast_0000128e, 1u},
    {4752u, aot_fast_00001290, 3u},
    {4762u, aot_fast_0000129a, 5u},
    {4792u, aot_fast_000012b8, 2u},
    {4820u, aot_fast_000012d4, 3u},
    {4830u, aot_fast_000012de, 5u},
    {4860u, aot_fast_000012fc, 2u},
    {4864u, aot_fast_00001300, 9u},
    {4886u, aot_fast_00001316, 2u},
    {4890u, aot_fast_0000131a, 6u},
    {4910u, aot_fast_0000132e, 2u},
    {4928u, aot_fast_00001340, 4u},
    {4940u, aot_fast_0000134c, 3u},
    {4948u, aot_fast_00001354, 1u},
    {4950u, aot_fast_00001356, 2u},
    {4954u, aot_fast_0000135a, 4u},
    {4964u, aot_fast_00001364, 3u},
    {4970u, aot_fast_0000136a, 2u},
    {4974u, aot_fast_0000136e, 5u},
    {4984u, aot_fast_00001378, 3u},
    {4990u, aot_fast_0000137e, 2u},
    {4994u, aot_fast_00001382, 1u},
    {4996u, aot_fast_00001384, 2u},
    {5002u, aot_fast_0000138a, 3u},
    {5012u, aot_fast_00001394, 13u},
    {5042u, aot_fast_000013b2, 6u},
    {5058u, aot_fast_000013c2, 2u},
    {5064u, aot_fast_000013c8, 6u},
    {5084u, aot_fast_000013dc, 3u},
    {5660u, aot_fast_0000161c, 2u},
    {5664u, aot_fast_00001620, 2u},
    {5668u, aot_fast_00001624, 2u},
    {5672u, aot_fast_00001628, 7u},
    {5692u, aot_fast_0000163c, 5u},
    {5702u, aot_fast_00001646, 1u},
    {5706u, aot_fast_0000164a, 1u},
    {5708u, aot_fast_0000164c, 1u},
    {5714u, aot_fast_00001652, 1u},
    {5716u, aot_fast_00001654, 1u},
    {5722u, aot_fast_0000165a, 2u},
    {5726u, aot_fast_0000165e, 3u},
    {5736u, aot_fast_00001668, 1u},
    {5740u, aot_fast_0000166c, 2u},
    {5936u, aot_fast_00001730, 2u},
    {6006u, aot_fast_00001776, 2u},
    {6212u, aot_fast_00001844, 2u},
    {6220u, aot_fast_0000184c, 1u},
    {6228u, aot_fast_00001854, 3u},
    {6240u, aot_fast_00001860, 2u},
    {6248u, aot_fast_00001868, 1u},
    {6256u, aot_fast_00001870, 1u},
    {6264u, aot_fast_00001878, 1u},
    {6272u, aot_fast_00001880, 1u},
    {6280u, aot_fast_00001888, 1u},
    {6288u, aot_fast_00001890, 1u},
    {6356u, aot_fast_000018d4, 1u},
    {6424u, aot_fast_00001918, 1u},
    {6444u, aot_fast_0000192c, 1u},
    {6464u, aot_fast_00001940, 1u},
    {6468u, aot_fast_00001944, 8u},
    {6494u, aot_fast_0000195e, 3u},
    {6504u, aot_fast_00001968, 8u},
    {6530u, aot_fast_00001982, 3u},
    {6540u, aot_fast_0000198c, 8u},
    {6566u, aot_fast_000019a6, 3u},
    {6576u, aot_fast_000019b0, 8u},
    {6602u, aot_fast_000019ca, 3u},
    {6612u, aot_fast_000019d4, 8u},
    {6638u, aot_fast_000019ee, 3u},
    {6648u, aot_fast_000019f8, 2u},
    {6652u, aot_fast_000019fc, 2u},
    {6656u, aot_fast_00001a00, 9u},
    {6674u, aot_fast_00001a12, 1u},
    {6676u, aot_fast_00001a14, 4u},
    {6686u, aot_fast_00001a1e, 1u},
    {6688u, aot_fast_00001a20, 2u},
    {6692u, aot_fast_00001a24, 7u},
    {6708u, aot_fast_00001a34, 3u},
    {6716u, aot_fast_00001a3c, 1u},
    {6718u, aot_fast_00001a3e, 6u},
    {6736u, aot_fast_00001a50, 2u},
    {6742u, aot_fast_00001a56, 3u},
    {6748u, aot_fast_00001a5c, 2u},
    {6754u, aot_fast_00001a62, 7u},
    {6770u, aot_fast_00001a72, 6u},
    {6784u, aot_fast_00001a80, 1u},
    {6794u, aot_fast_00001a8a, 1u},
    {6800u, aot_fast_00001a90, 4u},
    {6814u, aot_fast_00001a9e, 1u},
    {6818u, aot_fast_00001aa2, 2u},
    {6828u, aot_fast_00001aac, 1u},
    {6840u, aot_fast_00001ab8, 3u},
    {6848u, aot_fast_00001ac0, 3u},
    {6858u, aot_fast_00001aca, 2u},
    {6864u, aot_fast_00001ad0, 2u},
    {6868u, aot_fast_00001ad4, 4u},
    {6878u, aot_fast_00001ade, 1u},
    {6882u, aot_fast_00001ae2, 2u},
    {6890u, aot_fast_00001aea, 1u},
    {6896u, aot_fast_00001af0, 2u},
    {6900u, aot_fast_00001af4, 3u},
    {6908u, aot_fast_00001afc, 6u},
    {6926u, aot_fast_00001b0e, 3u},
    {6934u, aot_fast_00001b16, 3u},
    {6942u, aot_fast_00001b1e, 1u},
    {6944u, aot_fast_00001b20, 2u},
    {6950u, aot_fast_00001b26, 1u},
    {6958u, aot_fast_00001b2e, 4u},
    {6976u, aot_fast_00001b40, 2u},
    {6980u, aot_fast_00001b44, 2u},
    {6984u, aot_fast_00001b48, 2u},
    {6990u, aot_fast_00001b4e, 3u},
    {7000u, aot_fast_00001b58, 1u},
    {7002u, aot_fast_00001b5a, 1u},
    {7004u, aot_fast_00001b5c, 2u},
    {7008u, aot_fast_00001b60, 2u},
    {7012u, aot_fast_00001b64, 7u},
    {7030u, aot_fast_00001b76, 2u},
    {7040u, aot_fast_00001b80, 3u},
    {7050u, aot_fast_00001b8a, 5u},
    {7062u, aot_fast_00001b96, 1u},
    {7064u, aot_fast_00001b98, 1u},
    {7070u, aot_fast_00001b9e, 5u},
    {7082u, aot_fast_00001baa, 2u},
    {7086u, aot_fast_00001bae, 2u},
    {7092u, aot_fast_00001bb4, 6u},
    {7108u, aot_fast_00001bc4, 3u},
    {7116u, aot_fast_00001bcc, 6u},
    {7132u, aot_fast_00001bdc, 2u},
    {7136u, aot_fast_00001be0, 2u},
    {7140u, aot_fast_00001be4, 2u},
    {7146u, aot_fast_00001bea, 5u},
    {7164u, aot_fast_00001bfc, 1u},
    {7166u, aot_fast_00001bfe, 2u},
    {7170u, aot_fast_00001c02, 2u},
    {7176u, aot_fast_00001c08, 3u},
    {7188u, aot_fast_00001c14, 1u},
    {7192u, aot_fast_00001c18, 3u},
    {7198u, aot_fast_00001c1e, 3u},
    {7206u, aot_fast_00001c26, 6u},
    {7222u, aot_fast_00001c36, 2u},
    {7226u, aot_fast_00001c3a, 2u},
    {7232u, aot_fast_00001c40, 5u},
    {7246u, aot_fast_00001c4e, 2u},
    {7252u, aot_fast_00001c54, 2u},
    {7258u, aot_fast_00001c5a, 3u},
    {7268u, aot_fast_00001c64, 2u},
    {7276u, aot_fast_00001c6c, 1u},
    {7278u, aot_fast_00001c6e, 3u},
    {7288u, aot_fast_00001c78, 5u},
    {7302u, aot_fast_00001c86, 1u},
    {7304u, aot_fast_00001c88, 1u},
    {7308u, aot_fast_00001c8c, 2u},
    {7314u, aot_fast_00001c92, 1u},
    {7316u, aot_fast_00001c94, 1u},
    {7318u, aot_fast_00001c96, 2u},
    {7324u, aot_fast_00001c9c, 14u},
    {7360u, aot_fast_00001cc0, 2u},
    {7366u, aot_fast_00001cc6, 2u},
    {7372u, aot_fast_00001ccc, 2u},
    {7376u, aot_fast_00001cd0, 2u},
    {7382u, aot_fast_00001cd6, 2u},
    {7390u, aot_fast_00001cde, 2u},
    {7394u, aot_fast_00001ce2, 2u},
    {7400u, aot_fast_00001ce8, 2u},
};
const uint32_t agr_aot_fast_block_count = 301u;

const AgrAotEntry agr_aot_fast_hash[] = {
    {0u, 0, 0u},
    {0u, 0, 0u},
    {3396u, aot_fast_00000d44, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {5042u, aot_fast_000013b2, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4990u, aot_fast_0000137e, 2u},
    {6688u, aot_fast_00001a20, 2u},
    {0u, 0, 0u},
    {3940u, aot_fast_00000f64, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {5936u, aot_fast_00001730, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4886u, aot_fast_00001316, 2u},
    {4536u, aot_fast_000011b8, 7u},
    {6934u, aot_fast_00001b16, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {7232u, aot_fast_00001c40, 5u},
    {6882u, aot_fast_00001ae2, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {3732u, aot_fast_00000e94, 10u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4380u, aot_fast_0000111c, 8u},
    {0u, 0, 0u},
    {3680u, aot_fast_00000e60, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {3978u, aot_fast_00000f8a, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4626u, aot_fast_00001212, 3u},
    {6674u, aot_fast_00001a12, 1u},
    {3926u, aot_fast_00000f56, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {6272u, aot_fast_00001880, 1u},
    {0u, 0, 0u},
    {3524u, aot_fast_00000dc4, 10u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {6220u, aot_fast_0000184c, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4820u, aot_fast_000012d4, 3u},
    {6868u, aot_fast_00001ad4, 4u},
    {4120u, aot_fast_00001018, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {7166u, aot_fast_00001bfe, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4068u, aot_fast_00000fe4, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4716u, aot_fast_0000126c, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {5714u, aot_fast_00001652, 1u},
    {0u, 0, 0u},
    {7062u, aot_fast_00001b96, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {7360u, aot_fast_00001cc0, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {7308u, aot_fast_00001c8c, 2u},
    {4910u, aot_fast_0000132e, 2u},
    {6958u, aot_fast_00001b2e, 4u},
    {4210u, aot_fast_00001072, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4158u, aot_fast_0000103e, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {6504u, aot_fast_00001968, 8u},
    {4106u, aot_fast_0000100a, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4702u, aot_fast_0000125e, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {3950u, aot_fast_00000f6e, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4948u, aot_fast_00001354, 1u},
    {0u, 0, 0u},
    {4248u, aot_fast_00001098, 3u},
    {0u, 0, 0u},
    {3548u, aot_fast_00000ddc, 7u},
    {0u, 0, 0u},
    {6944u, aot_fast_00001b20, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4792u, aot_fast_000012b8, 2u},
    {6840u, aot_fast_00001ab8, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {7086u, aot_fast_00001bae, 2u},
    {6736u, aot_fast_00001a50, 2u},
    {4338u, aot_fast_000010f2, 6u},
    {3988u, aot_fast_00000f94, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4286u, aot_fast_000010be, 3u},
    {0u, 0, 0u},
    {3586u, aot_fast_00000e02, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4234u, aot_fast_0000108a, 2u},
    {3884u, aot_fast_00000f2c, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4532u, aot_fast_000011b4, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4830u, aot_fast_000012de, 5u},
    {6878u, aot_fast_00001ade, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {7176u, aot_fast_00001c08, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {3728u, aot_fast_00000e90, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {6424u, aot_fast_00001918, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4674u, aot_fast_00001242, 1u},
    {4324u, aot_fast_000010e4, 3u},
    {3974u, aot_fast_00000f86, 2u},
    {5672u, aot_fast_00001628, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {7318u, aot_fast_00001c96, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4220u, aot_fast_0000107c, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {6566u, aot_fast_000019a6, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {6864u, aot_fast_00001ad0, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4362u, aot_fast_0000110a, 2u},
    {0u, 0, 0u},
    {3662u, aot_fast_00000e4e, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {6708u, aot_fast_00001a34, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4608u, aot_fast_00001200, 2u},
    {6656u, aot_fast_00001a00, 9u},
    {3908u, aot_fast_00000f44, 4u},
    {0u, 0, 0u},
    {7304u, aot_fast_00001c88, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {7252u, aot_fast_00001c54, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4750u, aot_fast_0000128e, 1u},
    {4400u, aot_fast_00001130, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {3648u, aot_fast_00000e40, 5u},
    {7394u, aot_fast_00001ce2, 2u},
    {4996u, aot_fast_00001384, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {3946u, aot_fast_00000f6a, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4594u, aot_fast_000011f2, 4u},
    {0u, 0, 0u},
    {3894u, aot_fast_00000f36, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {6240u, aot_fast_00001860, 2u},
    {3842u, aot_fast_00000f02, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4736u, aot_fast_00001280, 1u},
    {6784u, aot_fast_00001a80, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {3336u, aot_fast_00000d08, 3u},
    {7082u, aot_fast_00001baa, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {3634u, aot_fast_00000e32, 5u},
    {0u, 0, 0u},
    {7030u, aot_fast_00001b76, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {3582u, aot_fast_00000dfe, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {7276u, aot_fast_00001c6c, 1u},
    {6926u, aot_fast_00001b0e, 3u},
    {6576u, aot_fast_000019b0, 8u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {6770u, aot_fast_00001a72, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {6718u, aot_fast_00001a3e, 6u},
    {4320u, aot_fast_000010e0, 2u},
    {3970u, aot_fast_00000f82, 2u},
    {5668u, aot_fast_00001624, 2u},
    {7366u, aot_fast_00001cc6, 2u},
    {0u, 0, 0u},
    {4618u, aot_fast_0000120a, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {3568u, aot_fast_00000df0, 6u},
    {7314u, aot_fast_00001c92, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {6264u, aot_fast_00001878, 1u},
    {3866u, aot_fast_00000f1a, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4864u, aot_fast_00001300, 9u},
    {0u, 0, 0u},
    {6212u, aot_fast_00001844, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {3360u, aot_fast_00000d20, 3u},
    {5058u, aot_fast_000013c2, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4008u, aot_fast_00000fa8, 6u},
    {5706u, aot_fast_0000164a, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4954u, aot_fast_0000135a, 4u},
    {6652u, aot_fast_000019fc, 2u},
    {7002u, aot_fast_00001b5a, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {6950u, aot_fast_00001b26, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {3800u, aot_fast_00000ed8, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4098u, aot_fast_00001002, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4746u, aot_fast_0000128a, 2u},
    {6444u, aot_fast_0000192c, 1u},
    {4046u, aot_fast_00000fce, 1u},
    {3696u, aot_fast_00000e70, 7u},
    {6794u, aot_fast_00001a8a, 1u},
    {7092u, aot_fast_00001bb4, 6u},
    {4694u, aot_fast_00001256, 3u},
    {6742u, aot_fast_00001a56, 3u},
    {0u, 0, 0u},
    {5692u, aot_fast_0000163c, 5u},
    {7390u, aot_fast_00001cde, 2u},
    {7040u, aot_fast_00001b80, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4940u, aot_fast_0000134c, 3u},
    {6638u, aot_fast_000019ee, 3u},
    {6288u, aot_fast_00001890, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {3384u, aot_fast_00000d38, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {3980u, aot_fast_00000f8c, 4u},
    {0u, 0, 0u},
    {7376u, aot_fast_00001cd0, 2u},
    {0u, 0, 0u},
    {6676u, aot_fast_00001a14, 4u},
    {4278u, aot_fast_000010b6, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {7324u, aot_fast_00001c9c, 14u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {3876u, aot_fast_00000f24, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {6818u, aot_fast_00001aa2, 2u},
    {6468u, aot_fast_00001944, 8u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {7116u, aot_fast_00001bcc, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {5716u, aot_fast_00001654, 1u},
    {0u, 0, 0u},
    {7064u, aot_fast_00001b98, 1u},
    {0u, 0, 0u},
    {4316u, aot_fast_000010dc, 2u},
    {0u, 0, 0u},
    {5664u, aot_fast_00001620, 2u},
    {0u, 0, 0u},
    {4964u, aot_fast_00001364, 3u},
    {4614u, aot_fast_00001206, 2u},
    {7012u, aot_fast_00001b64, 7u},
    {0u, 0, 0u},
    {3564u, aot_fast_00000dec, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {7258u, aot_fast_00001c5a, 3u},
    {4860u, aot_fast_000012fc, 2u},
    {6908u, aot_fast_00001afc, 6u},
    {0u, 0, 0u},
    {3810u, aot_fast_00000ee2, 7u},
    {0u, 0, 0u},
    {7206u, aot_fast_00001c26, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {3758u, aot_fast_00000eae, 7u},
    {3408u, aot_fast_00000d50, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4004u, aot_fast_00000fa4, 2u},
    {5702u, aot_fast_00001646, 1u},
    {7400u, aot_fast_00001ce8, 2u},
    {5002u, aot_fast_0000138a, 3u},
    {7050u, aot_fast_00001b8a, 5u},
    {4302u, aot_fast_000010ce, 7u},
    {0u, 0, 0u},
    {3602u, aot_fast_00000e12, 6u},
    {0u, 0, 0u},
    {4950u, aot_fast_00001356, 2u},
    {6648u, aot_fast_000019f8, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4198u, aot_fast_00001066, 2u},
    {3848u, aot_fast_00000f08, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4146u, aot_fast_00001032, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {7192u, aot_fast_00001c18, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {7140u, aot_fast_00001be4, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4042u, aot_fast_00000fca, 2u},
    {5740u, aot_fast_0000166c, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4690u, aot_fast_00001252, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {6686u, aot_fast_00001a1e, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {3588u, aot_fast_00000e04, 6u},
    {0u, 0, 0u},
    {6984u, aot_fast_00001b48, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4184u, aot_fast_00001058, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {6530u, aot_fast_00001982, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {6828u, aot_fast_00001aac, 1u},
    {0u, 0, 0u},
    {4080u, aot_fast_00000ff0, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4728u, aot_fast_00001278, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {3678u, aot_fast_00000e5e, 1u},
    {5726u, aot_fast_0000165e, 3u},
    {0u, 0, 0u},
    {4676u, aot_fast_00001244, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {7372u, aot_fast_00001ccc, 2u},
    {4974u, aot_fast_0000136e, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4572u, aot_fast_000011dc, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {7268u, aot_fast_00001c64, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {7164u, aot_fast_00001bfc, 1u},
    {6814u, aot_fast_00001a9e, 1u},
    {6464u, aot_fast_00001940, 1u},
    {4066u, aot_fast_00000fe2, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {5064u, aot_fast_000013c8, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {5012u, aot_fast_00001394, 13u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {3962u, aot_fast_00000f7a, 3u},
    {5660u, aot_fast_0000161c, 2u},
    {0u, 0, 0u},
    {7008u, aot_fast_00001b60, 2u},
    {0u, 0, 0u},
    {4260u, aot_fast_000010a4, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4208u, aot_fast_00001070, 1u},
    {6256u, aot_fast_00001870, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {3456u, aot_fast_00000d80, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4752u, aot_fast_00001290, 3u},
    {6800u, aot_fast_00001a90, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {6748u, aot_fast_00001a5c, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4298u, aot_fast_000010ca, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {6942u, aot_fast_00001b1e, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {6890u, aot_fast_00001aea, 1u},
    {6540u, aot_fast_0000198c, 8u},
    {4142u, aot_fast_0000102e, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {7188u, aot_fast_00001c14, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4090u, aot_fast_00000ffa, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {7136u, aot_fast_00001be0, 2u},
    {4738u, aot_fast_00001282, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {5736u, aot_fast_00001668, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4686u, aot_fast_0000124e, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {7382u, aot_fast_00001cd6, 2u},
    {4984u, aot_fast_00001378, 3u},
    {4634u, aot_fast_0000121a, 9u},
    {0u, 0, 0u},
    {3934u, aot_fast_00000f5e, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {6980u, aot_fast_00001b44, 2u},
    {4582u, aot_fast_000011e6, 3u},
    {6280u, aot_fast_00001888, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {7278u, aot_fast_00001c6e, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {6228u, aot_fast_00001854, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {7226u, aot_fast_00001c3a, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4128u, aot_fast_00001020, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4076u, aot_fast_00000fec, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4724u, aot_fast_00001274, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {5722u, aot_fast_0000165a, 2u},
    {3324u, aot_fast_00000cfc, 3u},
    {7070u, aot_fast_00001b9e, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4970u, aot_fast_0000136a, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {7316u, aot_fast_00001c94, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4166u, aot_fast_00001046, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4114u, aot_fast_00001012, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4762u, aot_fast_0000129a, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {3712u, aot_fast_00000e80, 7u},
    {0u, 0, 0u},
    {7108u, aot_fast_00001bc4, 3u},
    {4710u, aot_fast_00001266, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {5708u, aot_fast_0000164c, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {6356u, aot_fast_000018d4, 1u},
    {3958u, aot_fast_00000f76, 2u},
    {6006u, aot_fast_00001776, 2u},
    {0u, 0, 0u},
    {7004u, aot_fast_00001b5c, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {7302u, aot_fast_00001c86, 1u},
    {0u, 0, 0u},
    {4554u, aot_fast_000011ca, 2u},
    {4204u, aot_fast_0000106c, 1u},
    {6602u, aot_fast_000019ca, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {6900u, aot_fast_00001af4, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {7198u, aot_fast_00001c1e, 3u},
    {6848u, aot_fast_00001ac0, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {7146u, aot_fast_00001bea, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4048u, aot_fast_00000fd0, 8u},
    {0u, 0, 0u},
    {3348u, aot_fast_00000d14, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {3996u, aot_fast_00000f9c, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4994u, aot_fast_00001382, 1u},
    {6692u, aot_fast_00001a24, 7u},
    {4294u, aot_fast_000010c6, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {6990u, aot_fast_00001b4e, 3u},
    {4592u, aot_fast_000011f0, 1u},
    {4242u, aot_fast_00001092, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {7288u, aot_fast_00001c78, 5u},
    {4890u, aot_fast_0000131a, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {3788u, aot_fast_00000ecc, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4086u, aot_fast_00000ff6, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {5084u, aot_fast_000013dc, 3u},
    {7132u, aot_fast_00001bdc, 2u},
    {0u, 0, 0u},
    {4034u, aot_fast_00000fc2, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4332u, aot_fast_000010ec, 2u},
    {0u, 0, 0u},
    {3632u, aot_fast_00000e30, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4280u, aot_fast_000010b8, 3u},
    {3930u, aot_fast_00000f5a, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4928u, aot_fast_00001340, 4u},
    {6976u, aot_fast_00001b40, 2u},
    {4228u, aot_fast_00001084, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {3826u, aot_fast_00000ef2, 7u},
    {0u, 0, 0u},
    {7222u, aot_fast_00001c36, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4124u, aot_fast_0000101c, 2u},
    {3774u, aot_fast_00000ebe, 6u},
    {0u, 0, 0u},
    {7170u, aot_fast_00001c02, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {3372u, aot_fast_00000d2c, 3u},
    {0u, 0, 0u},
    {4720u, aot_fast_00001270, 2u},
    {0u, 0, 0u},
    {4020u, aot_fast_00000fb4, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4668u, aot_fast_0000123c, 2u},
    {6716u, aot_fast_00001a3c, 1u},
    {0u, 0, 0u},
    {3618u, aot_fast_00000e22, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {3916u, aot_fast_00000f4c, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {6612u, aot_fast_000019d4, 8u},
    {4214u, aot_fast_00001076, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4162u, aot_fast_00001042, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {6858u, aot_fast_00001aca, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {6754u, aot_fast_00001a62, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {4654u, aot_fast_0000122e, 7u},
    {0u, 0, 0u},
    {3954u, aot_fast_00000f72, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {7000u, aot_fast_00001b58, 1u},
    {4602u, aot_fast_000011fa, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {6248u, aot_fast_00001868, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {7246u, aot_fast_00001c4e, 2u},
    {6896u, aot_fast_00001af0, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {6494u, aot_fast_0000195e, 3u},
};
const uint32_t agr_aot_fast_hash_mask = 1023u;

const uint32_t agr_aot_fast_relocatable = 1u;