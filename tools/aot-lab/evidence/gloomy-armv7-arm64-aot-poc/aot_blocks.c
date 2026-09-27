#include "agr_aot.h"

static int aot_02800e94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    if (agr_aot_stmdb_sp(s, 17400u)) return AGR_AOT_FAULT;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 7, 3);
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 8, 2);
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 2);
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_count_instruction();
    agr_aot_movw(s, 9, 5126u);
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) return rc; }
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, s->r[3], 41946798u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_02800eae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 7);
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) return rc; }
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 5, 0);
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, s->r[3], 41946814u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_02800ebe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 9);
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 3, 5);
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 6, 0);
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 0, 2u);
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, 41946376u, 41946828u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_02800d08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, 41946384u, 0u);
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    agr_aot_count_instruction();
    { uint32_t addr = s->r[12] + 712u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
    s->r[15] = 41946388u;
    return AGR_AOT_BOUNDARY;
}

static int aot_02800ecc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 3, 6);
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 9);
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 0, 4u);
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, 41946388u, 41946840u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_02800d14(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, 41946396u, 0u);
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    agr_aot_count_instruction();
    { uint32_t addr = s->r[12] + 704u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
    s->r[15] = 41946400u;
    return AGR_AOT_BOUNDARY;
}

static int aot_02800ed8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[13] + 32u); if (rc) return rc; }
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 0, 1u);
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 1, 0u);
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, 41946424u, 41946850u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_02800d38(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, 41946432u, 0u);
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    agr_aot_count_instruction();
    { uint32_t addr = s->r[12] + 680u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
    s->r[15] = 41946436u;
    return AGR_AOT_BOUNDARY;
}

static int aot_02800ee2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 7);
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 12, s->r[3] + 788u); if (rc) return rc; }
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, s->r[12], 41946866u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_02800ef2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 8);
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 5);
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 6, s->r[3] + 788u); if (rc) return rc; }
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, s->r[6], 41946882u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_02800f02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    if ((rc = agr_aot_ldmia_sp(s, 33784u))) return rc;
}

static int aot_02800dc4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    if (agr_aot_stmdb_sp(s, 20472u)) return AGR_AOT_FAULT;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 10, 3);
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 2);
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 8, 2);
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 6, s->r[13] + 40u); if (rc) return rc; }
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) return rc; }
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, s->r[3], 41946588u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_02800ddc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 10);
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) return rc; }
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 7, 0);
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, s->r[3], 41946604u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_02800dec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 9, 0);
    agr_aot_count_instruction();
    s->r[15] = !s->r[6] ? 41946626u : 41946608u; return AGR_AOT_BOUNDARY;
}

static int aot_02800df0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 6);
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 748u); if (rc) return rc; }
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, s->r[3], 41946622u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_02800dfe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 5, 0);
    agr_aot_count_instruction();
    s->r[15] = 41946628u; return AGR_AOT_BOUNDARY;
}

static int aot_02800e04(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 44u); if (rc) return rc; }
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 744u); if (rc) return rc; }
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, s->r[3], 41946642u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_02800e12(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    agr_aot_movw(s, 1, 5126u);
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 3, 7);
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 11, 0);
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 0, 3u);
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, 41946376u, 41946658u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_02800e22(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 0, 4u);
    agr_aot_count_instruction();
    agr_aot_movw(s, 1, 5126u);
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 3, 9);
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, 41946388u, 41946672u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_02800e30(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    s->r[15] = !s->r[5] ? 41946688u : 41946674u; return AGR_AOT_BOUNDARY;
}

static int aot_02800e32(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 0, 2u);
    agr_aot_count_instruction();
    agr_aot_movw(s, 1, 5132u);
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 3, 5);
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, 41946400u, 41946688u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_02800e40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 0, 4u);
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 48u); if (rc) return rc; }
    agr_aot_count_instruction();
    agr_aot_movw(s, 2, 5123u);
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 3, 11);
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, 41946412u, 41946702u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_02800d20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, 41946408u, 0u);
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    agr_aot_count_instruction();
    { uint32_t addr = s->r[12] + 696u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
    s->r[15] = 41946412u;
    return AGR_AOT_BOUNDARY;
}

static int aot_02800d2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, 41946420u, 0u);
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    agr_aot_count_instruction();
    { uint32_t addr = s->r[12] + 688u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
    s->r[15] = 41946424u;
    return AGR_AOT_BOUNDARY;
}

static int aot_02800e4e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 44u); if (rc) return rc; }
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 11);
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 12, s->r[3] + 776u); if (rc) return rc; }
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, s->r[12], 41946718u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_02800e5e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    s->r[15] = !s->r[5] ? 41946736u : 41946720u; return AGR_AOT_BOUNDARY;
}

static int aot_02800e60(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 6);
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 5);
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 12, s->r[3] + 780u); if (rc) return rc; }
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, s->r[12], 41946736u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_02800e70(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 10);
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 9);
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 5, s->r[3] + 788u); if (rc) return rc; }
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, s->r[5], 41946752u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_02800e80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 8);
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 7);
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 5, s->r[3] + 788u); if (rc) return rc; }
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, s->r[5], 41946768u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_02800e90(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    agr_aot_count_instruction();
    if ((rc = agr_aot_ldmia_sp(s, 36856u))) return rc;
}

const AgrAotEntry agr_aot_blocks[] = {
    {41946376u, aot_02800d08},
    {41946388u, aot_02800d14},
    {41946400u, aot_02800d20},
    {41946412u, aot_02800d2c},
    {41946424u, aot_02800d38},
    {41946564u, aot_02800dc4},
    {41946588u, aot_02800ddc},
    {41946604u, aot_02800dec},
    {41946608u, aot_02800df0},
    {41946622u, aot_02800dfe},
    {41946628u, aot_02800e04},
    {41946642u, aot_02800e12},
    {41946658u, aot_02800e22},
    {41946672u, aot_02800e30},
    {41946674u, aot_02800e32},
    {41946688u, aot_02800e40},
    {41946702u, aot_02800e4e},
    {41946718u, aot_02800e5e},
    {41946720u, aot_02800e60},
    {41946736u, aot_02800e70},
    {41946752u, aot_02800e80},
    {41946768u, aot_02800e90},
    {41946772u, aot_02800e94},
    {41946798u, aot_02800eae},
    {41946814u, aot_02800ebe},
    {41946828u, aot_02800ecc},
    {41946840u, aot_02800ed8},
    {41946850u, aot_02800ee2},
    {41946866u, aot_02800ef2},
    {41946882u, aot_02800f02},
};
const uint32_t agr_aot_block_count = 30u;
