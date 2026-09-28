#include "agr_aot.h"

static int aot_fast_00000cdc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[13] - 4u; s->r[13] = addr; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[14]); }
    { uint32_t addr = (s->bias + 3304u) + 4u; if ((rc = agr_aot_ldr(s, 14, addr))) return rc; }
    agr_aot_add_imm(s, 14, (s->bias + 3308u), s->r[14]);
    { uint32_t addr = s->r[14] + 8u; s->r[14] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
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

static int aot_fast_000010a6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = !s->r[3] ? (s->bias + 4270u) : (s->bias + 4266u); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000010aa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[3] + s->r[0]); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000010ae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 3);
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000010b2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 9u);
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
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

static int aot_fast_000012bc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16415u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 2, 1);
    agr_aot_movs_imm(s, 1, 0u);
    agr_aot_add_imm(s, 3, s->r[13], 12u);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_mov_reg(s, 3, 1);
    agr_aot_branch_reg(s, (s->bias + 4752u) | 1u, (s->bias + 4812u), 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000012cc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 12u); if (rc) return rc; }
    s->r[13] += 20u;
    { uint32_t addr = s->r[13]; s->r[13] = s->r[13] + 4u; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
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
    {0, 0, 0},
};
const uint32_t agr_aot_debug_block_count = 0u;

const AgrAotEntry agr_aot_fast_blocks[] = {
    {3292u, aot_fast_00000cdc, 4u},
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
    {4262u, aot_fast_000010a6, 2u},
    {4266u, aot_fast_000010aa, 2u},
    {4270u, aot_fast_000010ae, 2u},
    {4274u, aot_fast_000010b2, 2u},
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
    {4796u, aot_fast_000012bc, 7u},
    {4812u, aot_fast_000012cc, 3u},
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
const uint32_t agr_aot_fast_block_count = 308u;

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
    {3292u, aot_fast_00000cdc, 4u},
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
    {4262u, aot_fast_000010a6, 2u},
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
    {4812u, aot_fast_000012cc, 3u},
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
    {4274u, aot_fast_000010b2, 2u},
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
    {4270u, aot_fast_000010ae, 2u},
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
    {4266u, aot_fast_000010aa, 2u},
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
    {4796u, aot_fast_000012bc, 7u},
    {6494u, aot_fast_0000195e, 3u},
};
const uint32_t agr_aot_fast_hash_mask = 1023u;

const uint32_t agr_aot_fast_relocatable = 1u;
const uint64_t agr_aot_input_elf_fnv64 = 13986468843527641119ull;
const uint32_t agr_aot_input_elf_bytes = 9376u;
