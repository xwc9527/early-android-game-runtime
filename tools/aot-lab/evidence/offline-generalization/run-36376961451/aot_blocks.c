#include "agr_aot.h"

static int aot_debug_02800cfc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 41946364u) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, 41946372u, 0u);
    s->r[15] = 41946368u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800d00(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 41946368u) != 3800877570u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    s->r[15] = 41946372u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800d04(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 41946372u) != 3854365392u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[12] + 720u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_02800d08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 41946376u) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, 41946384u, 0u);
    s->r[15] = 41946380u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800d0c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 41946380u) != 3800877570u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    s->r[15] = 41946384u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800d10(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 41946384u) != 3854365384u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[12] + 712u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_02800d14(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 41946388u) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, 41946396u, 0u);
    s->r[15] = 41946392u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800d18(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 41946392u) != 3800877570u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    s->r[15] = 41946396u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800d1c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 41946396u) != 3854365376u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[12] + 704u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_02800d20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 41946400u) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, 41946408u, 0u);
    s->r[15] = 41946404u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800d24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 41946404u) != 3800877570u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    s->r[15] = 41946408u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800d28(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 41946408u) != 3854365368u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[12] + 696u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_02800d2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 41946412u) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, 41946420u, 0u);
    s->r[15] = 41946416u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800d30(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 41946416u) != 3800877570u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    s->r[15] = 41946420u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800d34(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 41946420u) != 3854365360u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[12] + 688u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_02800d38(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 41946424u) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, 41946432u, 0u);
    s->r[15] = 41946428u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800d3c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 41946428u) != 3800877570u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    s->r[15] = 41946432u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800d40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 41946432u) != 3854365352u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[12] + 680u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_02800d44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 41946436u) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, 41946444u, 0u);
    s->r[15] = 41946440u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800d48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 41946440u) != 3800877570u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    s->r[15] = 41946444u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800d4c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 41946444u) != 3854365344u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[12] + 672u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_02800d50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 41946448u) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, 41946456u, 0u);
    s->r[15] = 41946452u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800d54(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 41946452u) != 3800877570u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    s->r[15] = 41946456u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800d58(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 41946456u) != 3854365336u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[12] + 664u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_02800d80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 41946496u) != 3852402692u) return AGR_AOT_MISS;
    { uint32_t addr = (41946504u) + 4u; if ((rc = agr_aot_ldr(s, 0, addr))) return rc; }
    s->r[15] = 41946500u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800d84(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 41946500u) != 3767468032u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 0, 41946508u, s->r[0]);
    s->r[15] = 41946504u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800dc4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946564u) != 59693u || agr_aot_load16(s, 41946566u) != 20472u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 20472u)) return AGR_AOT_FAULT;
    s->r[15] = 41946568u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800dc8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946568u) != 18074u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 10, 3);
    s->r[15] = 41946570u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800dca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946570u) != 26627u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 41946572u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800dcc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946572u) != 17937u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 2);
    s->r[15] = 41946574u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800dce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946574u) != 18064u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 8, 2);
    s->r[15] = 41946576u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800dd0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946576u) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 41946578u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800dd2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946578u) != 17924u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 41946580u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800dd4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946580u) != 40458u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 6, s->r[13] + 40u); if (rc) return rc; }
    s->r[15] = 41946582u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800dd6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946582u) != 63699u || agr_aot_load16(s, 41946584u) != 13044u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) return rc; }
    s->r[15] = 41946586u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800dda(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946586u) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], 41946588u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ddc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946588u) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 41946590u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800dde(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946590u) != 18001u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 10);
    s->r[15] = 41946592u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800de0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946592u) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 41946594u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800de2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946594u) != 63699u || agr_aot_load16(s, 41946596u) != 13044u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) return rc; }
    s->r[15] = 41946598u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800de6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946598u) != 17927u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 7, 0);
    s->r[15] = 41946600u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800de8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946600u) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 41946602u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800dea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946602u) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], 41946604u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800dec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946604u) != 18049u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 9, 0);
    s->r[15] = 41946606u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800dee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946606u) != 45382u) return AGR_AOT_MISS;
    s->r[15] = !s->r[6] ? 41946626u : 41946608u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800df0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946608u) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 41946610u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800df2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946610u) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 41946612u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800df4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946612u) != 17969u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 6);
    s->r[15] = 41946614u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800df6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946614u) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 41946616u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800df8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946616u) != 63699u || agr_aot_load16(s, 41946618u) != 13036u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 748u); if (rc) return rc; }
    s->r[15] = 41946620u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800dfc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946620u) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], 41946622u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800dfe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946622u) != 17925u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 41946624u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e00(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946624u) != 57344u) return AGR_AOT_MISS;
    s->r[15] = 41946628u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946626u) != 17973u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 6);
    s->r[15] = 41946628u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e04(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946628u) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 41946630u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e06(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946630u) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 41946632u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946632u) != 39179u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 44u); if (rc) return rc; }
    s->r[15] = 41946634u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e0a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946634u) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 41946636u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e0c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946636u) != 63699u || agr_aot_load16(s, 41946638u) != 13032u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 744u); if (rc) return rc; }
    s->r[15] = 41946640u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e10(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946640u) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], 41946642u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e12(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946642u) != 62017u || agr_aot_load16(s, 41946644u) != 16646u) return AGR_AOT_MISS;
    agr_aot_movw(s, 1, 5126u);
    s->r[15] = 41946646u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e16(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946646u) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 41946648u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e18(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946648u) != 17979u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 7);
    s->r[15] = 41946650u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e1a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946650u) != 18051u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 11, 0);
    s->r[15] = 41946652u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e1c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946652u) != 8195u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 3u);
    s->r[15] = 41946654u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e1e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946654u) != 63487u || agr_aot_load16(s, 41946656u) != 61300u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41946376u, 41946658u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e22(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946658u) != 8196u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 4u);
    s->r[15] = 41946660u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946660u) != 62017u || agr_aot_load16(s, 41946662u) != 16646u) return AGR_AOT_MISS;
    agr_aot_movw(s, 1, 5126u);
    s->r[15] = 41946664u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e28(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946664u) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 41946666u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e2a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946666u) != 17995u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 9);
    s->r[15] = 41946668u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946668u) != 63487u || agr_aot_load16(s, 41946670u) != 61298u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41946388u, 41946672u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e30(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946672u) != 45365u) return AGR_AOT_MISS;
    s->r[15] = !s->r[5] ? 41946688u : 41946674u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e32(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946674u) != 8194u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    s->r[15] = 41946676u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e34(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946676u) != 62017u || agr_aot_load16(s, 41946678u) != 16652u) return AGR_AOT_MISS;
    agr_aot_movw(s, 1, 5132u);
    s->r[15] = 41946680u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e38(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946680u) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 41946682u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e3a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946682u) != 17963u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 5);
    s->r[15] = 41946684u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e3c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946684u) != 63487u || agr_aot_load16(s, 41946686u) != 61296u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41946400u, 41946688u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946688u) != 8196u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 4u);
    s->r[15] = 41946690u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e42(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946690u) != 39180u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 48u); if (rc) return rc; }
    s->r[15] = 41946692u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946692u) != 62017u || agr_aot_load16(s, 41946694u) != 16899u) return AGR_AOT_MISS;
    agr_aot_movw(s, 2, 5123u);
    s->r[15] = 41946696u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946696u) != 18011u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 11);
    s->r[15] = 41946698u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e4a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946698u) != 63487u || agr_aot_load16(s, 41946700u) != 61296u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41946412u, 41946702u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e4e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946702u) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 41946704u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946704u) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 41946706u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e52(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946706u) != 39179u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 44u); if (rc) return rc; }
    s->r[15] = 41946708u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e54(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946708u) != 18010u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 11);
    s->r[15] = 41946710u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e56(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946710u) != 63699u || agr_aot_load16(s, 41946712u) != 49928u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 12, s->r[3] + 776u); if (rc) return rc; }
    s->r[15] = 41946714u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e5a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946714u) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 41946716u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e5c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946716u) != 18400u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[12], 41946718u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e5e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946718u) != 45373u) return AGR_AOT_MISS;
    s->r[15] = !s->r[5] ? 41946736u : 41946720u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e60(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946720u) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 41946722u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e62(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946722u) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 41946724u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946724u) != 17969u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 6);
    s->r[15] = 41946726u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e66(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946726u) != 17962u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 5);
    s->r[15] = 41946728u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e68(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946728u) != 63699u || agr_aot_load16(s, 41946730u) != 49932u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 12, s->r[3] + 780u); if (rc) return rc; }
    s->r[15] = 41946732u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e6c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946732u) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 41946734u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e6e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946734u) != 18400u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[12], 41946736u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e70(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946736u) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 41946738u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946738u) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 41946740u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e74(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946740u) != 18001u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 10);
    s->r[15] = 41946742u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e76(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946742u) != 17994u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 9);
    s->r[15] = 41946744u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946744u) != 63699u || agr_aot_load16(s, 41946746u) != 21268u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 5, s->r[3] + 788u); if (rc) return rc; }
    s->r[15] = 41946748u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e7c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946748u) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 41946750u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e7e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946750u) != 18344u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[5], 41946752u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946752u) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 41946754u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e82(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946754u) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 41946756u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e84(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946756u) != 17985u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 8);
    s->r[15] = 41946758u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e86(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946758u) != 17978u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 7);
    s->r[15] = 41946760u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e88(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946760u) != 63699u || agr_aot_load16(s, 41946762u) != 21268u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 5, s->r[3] + 788u); if (rc) return rc; }
    s->r[15] = 41946764u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e8c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946764u) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 41946766u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e8e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946766u) != 18344u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[5], 41946768u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e90(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946768u) != 59581u || agr_aot_load16(s, 41946770u) != 36856u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 36856u))) return rc;
}

static int aot_debug_02800e94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946772u) != 59693u || agr_aot_load16(s, 41946774u) != 17400u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 17400u)) return AGR_AOT_FAULT;
    s->r[15] = 41946776u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e98(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946776u) != 17951u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 7, 3);
    s->r[15] = 41946778u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e9a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946778u) != 26627u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 41946780u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e9c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946780u) != 18064u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 8, 2);
    s->r[15] = 41946782u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800e9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946782u) != 17937u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 2);
    s->r[15] = 41946784u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ea0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946784u) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 41946786u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ea2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946786u) != 17924u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 41946788u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ea4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946788u) != 62017u || agr_aot_load16(s, 41946790u) != 18694u) return AGR_AOT_MISS;
    agr_aot_movw(s, 9, 5126u);
    s->r[15] = 41946792u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ea8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946792u) != 63699u || agr_aot_load16(s, 41946794u) != 13044u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) return rc; }
    s->r[15] = 41946796u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800eac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946796u) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], 41946798u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800eae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946798u) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 41946800u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800eb0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946800u) != 17977u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 7);
    s->r[15] = 41946802u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800eb2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946802u) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 41946804u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800eb4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946804u) != 63699u || agr_aot_load16(s, 41946806u) != 13044u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) return rc; }
    s->r[15] = 41946808u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800eb8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946808u) != 17925u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 41946810u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800eba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946810u) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 41946812u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ebc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946812u) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], 41946814u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ebe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946814u) != 17993u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 9);
    s->r[15] = 41946816u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ec0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946816u) != 17963u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 5);
    s->r[15] = 41946818u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ec2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946818u) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 41946820u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ec4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946820u) != 17926u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 6, 0);
    s->r[15] = 41946822u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ec6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946822u) != 8194u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    s->r[15] = 41946824u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ec8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946824u) != 63487u || agr_aot_load16(s, 41946826u) != 61214u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41946376u, 41946828u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ecc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946828u) != 17971u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 6);
    s->r[15] = 41946830u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ece(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946830u) != 17993u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 9);
    s->r[15] = 41946832u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ed0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946832u) != 8196u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 4u);
    s->r[15] = 41946834u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ed2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946834u) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 41946836u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ed4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946836u) != 63487u || agr_aot_load16(s, 41946838u) != 61214u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41946388u, 41946840u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ed8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946840u) != 39432u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[13] + 32u); if (rc) return rc; }
    s->r[15] = 41946842u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800eda(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946842u) != 8193u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = 41946844u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800edc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946844u) != 8448u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = 41946846u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ede(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946846u) != 63487u || agr_aot_load16(s, 41946848u) != 61228u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41946424u, 41946850u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ee2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946850u) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 41946852u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ee4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946852u) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 41946854u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ee6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946854u) != 17977u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 7);
    s->r[15] = 41946856u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ee8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946856u) != 17970u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 41946858u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800eea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946858u) != 63699u || agr_aot_load16(s, 41946860u) != 49940u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 12, s->r[3] + 788u); if (rc) return rc; }
    s->r[15] = 41946862u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800eee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946862u) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 41946864u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ef0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946864u) != 18400u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[12], 41946866u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ef2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946866u) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 41946868u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ef4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946868u) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 41946870u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ef6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946870u) != 17985u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 8);
    s->r[15] = 41946872u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ef8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946872u) != 17962u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 5);
    s->r[15] = 41946874u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800efa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946874u) != 63699u || agr_aot_load16(s, 41946876u) != 25364u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 6, s->r[3] + 788u); if (rc) return rc; }
    s->r[15] = 41946878u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800efe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946878u) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 41946880u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f00(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946880u) != 18352u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[6], 41946882u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946882u) != 59581u || agr_aot_load16(s, 41946884u) != 33784u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 33784u))) return rc;
}

static int aot_debug_02800f08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946888u) != 26627u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 41946890u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f0a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946890u) != 90u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 2, s->r[3], 1u);
    s->r[15] = 41946892u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f0c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946892u) != 48972u) return AGR_AOT_MISS;
    agr_aot_set_itstate(s, 76u); s->r[15] = 41946894u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f1a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946906u) != 59693u || agr_aot_load16(s, 41946908u) != 20471u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 20471u)) return AGR_AOT_FAULT;
    s->r[15] = 41946910u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f1e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946910u) != 18049u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 9, 0);
    s->r[15] = 41946912u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946912u) != 17942u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 6, 2);
    s->r[15] = 41946914u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f22(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946914u) != 45857u) return AGR_AOT_MISS;
    s->r[15] = !s->r[1] ? 41946990u : 41946916u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946916u) != 61697u || agr_aot_load16(s, 41946918u) != 14591u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 8, s->r[1], 1023u);
    s->r[15] = 41946920u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f28(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946920u) != 9984u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 7, 0u);
    s->r[15] = 41946922u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f2a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946922u) != 18114u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 10, 8);
    s->r[15] = 41946924u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946924u) != 60167u || agr_aot_load16(s, 41946926u) != 1034u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 4, s->r[7], s->r[10]);
    s->r[15] = 41946928u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f36(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946934u) != 227u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 3, s->r[4], 3u);
    s->r[15] = 41946936u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f38(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946936u) != 37633u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 41946938u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f3a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946938u) != 60169u || agr_aot_load16(s, 41946940u) != 1283u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 5, s->r[9], s->r[3]);
    s->r[15] = 41946942u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f3e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946942u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 41946944u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946944u) != 63487u || agr_aot_load16(s, 41946946u) != 65506u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41946888u | 1u, 41946948u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946948u) != 17732u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[4], s->r[8]);
    s->r[15] = 41946950u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f46(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946950u) != 39681u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 4u); if (rc) return rc; }
    s->r[15] = 41946952u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946952u) != 18051u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 11, 0);
    s->r[15] = 41946954u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f4a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946954u) != 53268u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 41946998u : 41946956u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f4c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946956u) != 61699u || agr_aot_load16(s, 41946958u) != 8u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 0, s->r[3], 8u);
    s->r[15] = 41946960u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946960u) != 17480u) return AGR_AOT_MISS;
    s->r[0] += s->r[9];
    s->r[15] = 41946962u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f52(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946962u) != 63487u || agr_aot_load16(s, 41946964u) != 65497u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41946888u | 1u, 41946966u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f56(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946966u) != 17758u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[6], s->r[11]);
    s->r[15] = 41946968u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f58(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946968u) != 53764u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 2u) ? 41946980u : 41946970u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f5a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946970u) != 17084u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[4], s->r[7]);
    s->r[15] = 41946972u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f5c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946972u) != 53257u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 41946994u : 41946974u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f5e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946974u) != 61700u || agr_aot_load16(s, 41946976u) != 15103u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 10, s->r[4], 1023u);
    s->r[15] = 41946978u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f62(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946978u) != 59363u) return AGR_AOT_MISS;
    s->r[15] = 41946924u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946980u) != 14337u) return AGR_AOT_MISS;
    agr_aot_subs(s, 0, s->r[0], 1u);
    s->r[15] = 41946982u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f66(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946982u) != 17030u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[6], s->r[0]);
    s->r[15] = 41946984u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f68(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946984u) != 55559u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 9u) ? 41947002u : 41946986u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f6a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946986u) != 7271u) return AGR_AOT_MISS;
    agr_aot_adds(s, 7, s->r[4], 1u);
    s->r[15] = 41946988u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f6c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946988u) != 59358u) return AGR_AOT_MISS;
    s->r[15] = 41946924u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f6e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946990u) != 17933u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 1);
    s->r[15] = 41946992u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f70(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946992u) != 57347u) return AGR_AOT_MISS;
    s->r[15] = 41947002u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946994u) != 9472u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 5, 0u);
    s->r[15] = 41946996u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f74(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946996u) != 57345u) return AGR_AOT_MISS;
    s->r[15] = 41947002u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f76(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41946998u) != 17030u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[6], s->r[0]);
    s->r[15] = 41947000u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947000u) != 54255u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 3u) ? 41946970u : 41947002u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f7a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947002u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 41947004u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f7c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947004u) != 45059u) return AGR_AOT_MISS;
    s->r[13] += 12u;
    s->r[15] = 41947006u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f7e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947006u) != 59581u || agr_aot_load16(s, 41947008u) != 36848u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 36848u))) return rc;
}

static int aot_debug_02800f82(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947010u) != 10241u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 1u);
    s->r[15] = 41947012u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f84(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947012u) != 53254u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 41947028u : 41947014u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f86(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947014u) != 10242u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 2u);
    s->r[15] = 41947016u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f88(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947016u) != 53256u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 41947036u : 41947018u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947018u) != 47448u) return AGR_AOT_MISS;
    s->r[15] = s->r[0] ? 41947044u : 41947020u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f8c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947020u) != 18438u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, 41947024u + 24u); if (rc) return rc; }
    s->r[15] = 41947022u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f8e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947022u) != 17528u) return AGR_AOT_MISS;
    s->r[0] += 41947026u;
    s->r[15] = 41947024u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f90(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947024u) != 26624u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 41947026u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f92(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947026u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947028u) != 18437u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, 41947032u + 20u); if (rc) return rc; }
    s->r[15] = 41947030u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f96(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947030u) != 17528u) return AGR_AOT_MISS;
    s->r[0] += 41947034u;
    s->r[15] = 41947032u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f98(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947032u) != 26624u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 41947034u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f9a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947034u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f9c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947036u) != 18436u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, 41947040u + 16u); if (rc) return rc; }
    s->r[15] = 41947038u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800f9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947038u) != 17528u) return AGR_AOT_MISS;
    s->r[0] += 41947042u;
    s->r[15] = 41947040u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fa0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947040u) != 26624u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 41947042u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fa2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947042u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fa4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947044u) != 8192u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = 41947046u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fa6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947046u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fa8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947048u) != 8214u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 22u);
    s->r[15] = 41947050u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800faa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947050u) != 0u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 0, s->r[0], 0u);
    s->r[15] = 41947052u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947052u) != 8210u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 18u);
    s->r[15] = 41947054u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947054u) != 0u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 0, s->r[0], 0u);
    s->r[15] = 41947056u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fb0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947056u) != 8206u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 14u);
    s->r[15] = 41947058u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fb2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947058u) != 0u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 0, s->r[0], 0u);
    s->r[15] = 41947060u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fb4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947060u) != 19237u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, 41947064u + 148u); if (rc) return rc; }
    s->r[15] = 41947062u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fb6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947062u) != 46451u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16499u)) return AGR_AOT_FAULT;
    s->r[15] = 41947064u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fb8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947064u) != 17531u) return AGR_AOT_MISS;
    s->r[3] += 41947068u;
    s->r[15] = 41947066u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947066u) != 26651u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 41947068u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fbc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947068u) != 17924u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 41947070u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fbe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947070u) != 7822u) return AGR_AOT_MISS;
    agr_aot_subs(s, 6, s->r[1], 2u);
    s->r[15] = 41947072u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fc0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947072u) != 45363u) return AGR_AOT_MISS;
    s->r[15] = !s->r[3] ? 41947088u : 41947074u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fc2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947074u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 41947076u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fc4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947076u) != 43265u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    s->r[15] = 41947078u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fc6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947078u) != 63487u || agr_aot_load16(s, 41947080u) != 61118u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41946436u, 41947082u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947082u) != 17925u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 41947084u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fcc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947084u) != 47445u) return AGR_AOT_MISS;
    s->r[15] = s->r[5] ? 41947108u : 41947086u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947086u) != 57359u) return AGR_AOT_MISS;
    s->r[15] = 41947120u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fd0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947088u) != 19743u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 5, 41947092u + 124u); if (rc) return rc; }
    s->r[15] = 41947090u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fd2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947090u) != 19232u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, 41947092u + 128u); if (rc) return rc; }
    s->r[15] = 41947092u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fd4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947092u) != 17533u) return AGR_AOT_MISS;
    s->r[5] += 41947096u;
    s->r[15] = 41947094u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fd6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947094u) != 26669u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 5, s->r[5] + 0u); if (rc) return rc; }
    s->r[15] = 41947096u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fd8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947096u) != 17531u) return AGR_AOT_MISS;
    s->r[3] += 41947100u;
    s->r[15] = 41947098u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fda(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947098u) != 26651u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 41947100u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fdc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947100u) != 6893u) return AGR_AOT_MISS;
    agr_aot_subs(s, 5, s->r[5], s->r[3]);
    s->r[15] = 41947102u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fde(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947102u) != 17944u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 3);
    s->r[15] = 41947104u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fe2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947106u) != 38145u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    s->r[15] = 41947108u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fe4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947108u) != 39169u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 4u); if (rc) return rc; }
    s->r[15] = 41947110u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fe6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947110u) != 17970u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 41947112u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fe8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947112u) != 63487u || agr_aot_load16(s, 41947114u) != 65431u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41946906u | 1u, 41947116u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947116u) != 17925u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 41947118u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800fee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947118u) != 47376u) return AGR_AOT_MISS;
    s->r[15] = s->r[0] ? 41947126u : 41947120u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ff0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947120u) != 24869u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    s->r[15] = 41947122u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ff2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947122u) != 8201u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 9u);
    s->r[15] = 41947124u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ff4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947124u) != 57383u) return AGR_AOT_MISS;
    s->r[15] = 41947206u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ff6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947126u) != 63487u || agr_aot_load16(s, 41947128u) != 65415u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41946888u | 1u, 41947130u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ffa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947130u) != 26731u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 4u); if (rc) return rc; }
    s->r[15] = 41947132u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ffc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947132u) != 11009u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 1u);
    s->r[15] = 41947134u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02800ffe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947134u) != 25760u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[4] + 72u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 41947136u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801000(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947136u) != 53507u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41947146u : 41947138u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801002(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947138u) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 41947140u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801004(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947140u) != 8197u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 5u);
    s->r[15] = 41947142u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801006(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947142u) != 24867u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 41947144u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801008(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947144u) != 57373u) return AGR_AOT_MISS;
    s->r[15] = 41947206u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280100a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947146u) != 11008u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 0u);
    s->r[15] = 41947148u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280100c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947148u) != 61701u || agr_aot_load16(s, 41947150u) != 4u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 0, s->r[5], 4u);
    s->r[15] = 41947152u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801010(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947152u) != 55810u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 10u) ? 41947160u : 41947154u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801012(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947154u) != 25824u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[4] + 76u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 41947156u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801014(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947156u) != 8961u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 1u);
    s->r[15] = 41947158u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801016(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947158u) != 57347u) return AGR_AOT_MISS;
    s->r[15] = 41947168u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801018(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947160u) != 63487u || agr_aot_load16(s, 41947162u) != 65398u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41946888u | 1u, 41947164u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280101c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947164u) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 41947166u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280101e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947166u) != 25824u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[4] + 76u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 41947168u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801020(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947168u) != 27872u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[4] + 76u); if (rc) return rc; }
    s->r[15] = 41947170u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801022(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947170u) != 25891u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[4] + 80u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 41947172u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801024(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947172u) != 26627u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 41947174u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801026(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947174u) != 11008u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 0u);
    s->r[15] = 41947176u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801028(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947176u) != 55817u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 10u) ? 41947198u : 41947178u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280102e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947182u) != 63487u || agr_aot_load16(s, 41947184u) != 65448u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41947010u | 1u, 41947186u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801032(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947186u) != 24864u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 41947188u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801034(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947188u) != 10240u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = 41947190u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801036(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947190u) != 48908u) return AGR_AOT_MISS;
    agr_aot_set_itstate(s, 12u); s->r[15] = 41947192u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280103e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947198u) != 63487u || agr_aot_load16(s, 41947200u) != 65379u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41946888u | 1u, 41947202u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801042(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947202u) != 24864u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 41947204u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801044(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947204u) != 8192u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = 41947206u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801046(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947206u) != 45058u) return AGR_AOT_MISS;
    s->r[13] += 8u;
    s->r[15] = 41947208u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801048(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947208u) != 48496u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_debug_02801058(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947224u) != 26627u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 41947226u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280105a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947226u) != 46352u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    s->r[15] = 41947228u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280105c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947228u) != 17924u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 41947230u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280105e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947230u) != 2008u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 0, s->r[3], 31u);
    s->r[15] = 41947232u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801060(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947232u) != 54281u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 4u) ? 41947254u : 41947234u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801066(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947238u) != 61700u || agr_aot_load16(s, 41947240u) != 72u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 72u);
    s->r[15] = 41947242u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280106a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947242u) != 53250u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 41947250u : 41947244u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280106c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947244u) != 61440u || agr_aot_load16(s, 41947246u) != 64514u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41949300u | 1u, 41947248u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801070(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947248u) != 57345u) return AGR_AOT_MISS;
    s->r[15] = 41947254u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801072(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947250u) != 61440u || agr_aot_load16(s, 41947252u) != 64503u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41949284u | 1u, 41947254u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801076(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947254u) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 41947256u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801078(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947256u) != 1881u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 1, s->r[3], 29u);
    s->r[15] = 41947258u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280107a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947258u) != 54275u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 4u) ? 41947268u : 41947260u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280107c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947260u) != 61700u || agr_aot_load16(s, 41947262u) != 208u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 208u);
    s->r[15] = 41947264u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801080(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947264u) != 61440u || agr_aot_load16(s, 41947266u) != 64512u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41949316u | 1u, 41947268u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801084(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947268u) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 41947270u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801086(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947270u) != 1818u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 2, s->r[3], 28u);
    s->r[15] = 41947272u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801088(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947272u) != 54275u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 4u) ? 41947282u : 41947274u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280108a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947274u) != 62724u || agr_aot_load16(s, 41947276u) != 28840u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 4008u);
    s->r[15] = 41947278u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280108e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947278u) != 61440u || agr_aot_load16(s, 41947280u) != 64513u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41949332u | 1u, 41947282u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801092(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947282u) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 41947284u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801094(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947284u) != 1755u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 3, s->r[3], 27u);
    s->r[15] = 41947286u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801096(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947286u) != 54277u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 4u) ? 41947300u : 41947288u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801098(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947288u) != 62724u || agr_aot_load16(s, 41947290u) != 28904u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 4072u);
    s->r[15] = 41947292u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280109c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947292u) != 59581u || agr_aot_load16(s, 41947294u) != 16400u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 16400u))) return rc;
    s->r[15] = 41947296u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947296u) != 61440u || agr_aot_load16(s, 41947298u) != 48188u) return AGR_AOT_MISS;
    s->r[15] = 41949468u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010a4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947300u) != 48400u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_debug_028010b6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947318u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947320u) != 46448u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[15] = 41947322u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010ba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947322u) != 17925u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 41947324u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010bc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947324u) != 17932u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 1);
    s->r[15] = 41947326u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010be(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947326u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 41947328u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947328u) != 27681u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 64u); if (rc) return rc; }
    s->r[15] = 41947330u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010c2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947330u) != 63487u || agr_aot_load16(s, 41947332u) != 65399u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41947060u | 1u, 41947334u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010c6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947334u) != 17926u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 6, 0);
    s->r[15] = 41947336u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947336u) != 45320u) return AGR_AOT_MISS;
    s->r[15] = !s->r[0] ? 41947342u : 41947338u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947338u) != 63487u || agr_aot_load16(s, 41947340u) != 60994u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41946448u, 41947342u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010ce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947342u) != 27683u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 64u); if (rc) return rc; }
    s->r[15] = 41947344u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010d0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947344u) != 8193u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = 41947346u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010d2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947346u) != 17961u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 5);
    s->r[15] = 41947348u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947348u) != 17954u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 4);
    s->r[15] = 41947350u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010d6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947350u) != 24939u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[5] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 41947352u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010d8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947352u) != 26923u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 16u); if (rc) return rc; }
    s->r[15] = 41947354u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010da(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947354u) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], 41947356u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947356u) != 10248u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 8u);
    s->r[15] = 41947358u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010de(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947358u) != 53486u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 41947326u : 41947360u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947360u) != 10247u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 7u);
    s->r[15] = 41947362u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010e2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947362u) != 53746u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41947338u : 41947364u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947364u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 41947366u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010e6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947366u) != 27681u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 64u); if (rc) return rc; }
    s->r[15] = 41947368u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010e8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947368u) != 63487u || agr_aot_load16(s, 41947370u) != 65509u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41947318u | 1u, 41947372u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010ec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947372u) != 7456u) return AGR_AOT_MISS;
    agr_aot_adds(s, 0, s->r[4], 4u);
    s->r[15] = 41947374u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010ee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947374u) != 61440u || agr_aot_load16(s, 41947376u) != 64429u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41949260u | 1u, 41947378u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947378u) != 59693u || agr_aot_load16(s, 41947380u) != 20464u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 20464u)) return AGR_AOT_FAULT;
    s->r[15] = 41947382u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010f6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947382u) != 7437u) return AGR_AOT_MISS;
    agr_aot_adds(s, 5, s->r[1], 4u);
    s->r[15] = 41947384u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010f8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947384u) != 63696u || agr_aot_load16(s, 41947386u) != 32780u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 8, s->r[0] + 12u); if (rc) return rc; }
    s->r[15] = 41947388u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947388u) != 17927u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 7, 0);
    s->r[15] = 41947390u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028010fe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947390u) != 63696u || agr_aot_load16(s, 41947392u) != 36888u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 9, s->r[0] + 24u); if (rc) return rc; }
    s->r[15] = 41947394u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801102(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947394u) != 18066u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 10, 2);
    s->r[15] = 41947396u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280110a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947402u) != 44035u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 4, s->r[13], 12u);
    s->r[15] = 41947404u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280110c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947404u) != 44546u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 6, s->r[13], 8u);
    s->r[15] = 41947406u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280111c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947420u) != 44410u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 5, s->r[13], 488u);
    s->r[15] = 41947422u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280111e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947422u) != 59524u || agr_aot_load16(s, 41947424u) != 15u) return AGR_AOT_MISS;
    if (agr_aot_stm(s, 4u, 15u)) return AGR_AOT_FAULT;
    s->r[15] = 41947426u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801122(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947426u) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 41947428u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801124(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947428u) != 18075u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 11, 3);
    s->r[15] = 41947430u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801126(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947430u) != 24627u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[6] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 41947432u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801128(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947432u) != 17976u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 7);
    s->r[15] = 41947434u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280112a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947434u) != 27697u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[6] + 64u); if (rc) return rc; }
    s->r[15] = 41947436u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280112c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947436u) != 63487u || agr_aot_load16(s, 41947438u) != 65346u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41947060u | 1u, 41947440u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801130(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947440u) != 61882u || agr_aot_load16(s, 41947442u) != 3840u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[10], 0u);
    s->r[15] = 41947444u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801134(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947444u) != 48916u) return AGR_AOT_MISS;
    agr_aot_set_itstate(s, 20u); s->r[15] = 41947446u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_028011b4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947572u) != 27712u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 68u); if (rc) return rc; }
    s->r[15] = 41947574u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028011b6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947574u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_028011b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947576u) != 27595u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[1] + 60u); if (rc) return rc; }
    s->r[15] = 41947578u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028011ba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947578u) != 59693u || agr_aot_load16(s, 41947580u) != 16880u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16880u)) return AGR_AOT_FAULT;
    s->r[15] = 41947582u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028011be(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947582u) != 7437u) return AGR_AOT_MISS;
    agr_aot_adds(s, 5, s->r[1], 4u);
    s->r[15] = 41947584u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028011c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947584u) != 25611u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[1] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 41947586u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028011c2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947586u) != 17927u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 7, 0);
    s->r[15] = 41947588u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028011c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947588u) != 17934u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 6, 1);
    s->r[15] = 41947590u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028011c6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947590u) != 45304u) return AGR_AOT_MISS;
    s->r[13] -= 480u;
    s->r[15] = 41947592u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028011ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947594u) != 44033u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 4, s->r[13], 4u);
    s->r[15] = 41947596u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028011cc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947596u) != 18152u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 8, 13);
    s->r[15] = 41947598u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028011dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947612u) != 59524u || agr_aot_load16(s, 41947614u) != 15u) return AGR_AOT_MISS;
    if (agr_aot_stm(s, 4u, 15u)) return AGR_AOT_FAULT;
    s->r[15] = 41947616u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028011e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947616u) != 61519u || agr_aot_load16(s, 41947618u) != 13311u) return AGR_AOT_MISS;
    s->r[3] = 4294967295u;
    s->r[15] = 41947620u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028011e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947620u) != 37632u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 41947622u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028011e6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947622u) != 17976u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 7);
    s->r[15] = 41947624u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028011e8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947624u) != 63704u || agr_aot_load16(s, 41947626u) != 4160u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[8] + 64u); if (rc) return rc; }
    s->r[15] = 41947628u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028011ec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947628u) != 63487u || agr_aot_load16(s, 41947630u) != 65250u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41947060u | 1u, 41947632u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_028011f0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947632u) != 47480u) return AGR_AOT_MISS;
    s->r[15] = s->r[0] ? 41947666u : 41947634u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_028011f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947634u) != 26939u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[7] + 16u); if (rc) return rc; }
    s->r[15] = 41947636u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028011f4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947636u) != 17977u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 7);
    s->r[15] = 41947638u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028011f6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947638u) != 18026u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 13);
    s->r[15] = 41947640u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028011f8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947640u) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], 41947642u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_028011fa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947642u) != 10248u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 8u);
    s->r[15] = 41947644u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028011fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947644u) != 17924u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 41947646u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028011fe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947646u) != 53490u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 41947622u : 41947648u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801200(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947648u) != 18024u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 13);
    s->r[15] = 41947650u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801202(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947650u) != 63487u || agr_aot_load16(s, 41947652u) != 65321u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41947224u | 1u, 41947654u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801206(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947654u) != 11270u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[4], 6u);
    s->r[15] = 41947656u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801208(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947656u) != 53507u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41947666u : 41947658u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280120a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947658u) != 17976u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 7);
    s->r[15] = 41947660u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280120c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947660u) != 17969u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 6);
    s->r[15] = 41947662u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280120e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947662u) != 63487u || agr_aot_load16(s, 41947664u) != 65363u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41947320u | 1u, 41947666u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801212(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947666u) != 8201u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 9u);
    s->r[15] = 41947668u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801214(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947668u) != 45176u) return AGR_AOT_MISS;
    s->r[13] += 480u;
    s->r[15] = 41947670u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801216(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947670u) != 59581u || agr_aot_load16(s, 41947672u) != 33264u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) return rc;
}

static int aot_debug_0280121a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947674u) != 46352u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    s->r[15] = 41947676u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280121c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947676u) != 24962u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[0] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 41947678u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280121e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947678u) != 27610u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 60u); if (rc) return rc; }
    s->r[15] = 41947680u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801220(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947680u) != 24769u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[0] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    s->r[15] = 41947682u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801222(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947682u) != 17945u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 3);
    s->r[15] = 41947684u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801224(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947684u) != 59581u || agr_aot_load16(s, 41947686u) != 16400u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 16400u))) return rc;
    s->r[15] = 41947688u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801228(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947688u) != 25626u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[3] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 41947690u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280122a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947690u) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 41947692u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280122c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947692u) != 59233u) return AGR_AOT_MISS;
    s->r[15] = 41947378u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280122e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947694u) != 26947u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 20u); if (rc) return rc; }
    s->r[15] = 41947696u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801230(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947696u) != 46448u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[15] = 41947698u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801232(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947698u) != 17925u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 41947700u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801234(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947700u) != 26822u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 6, s->r[0] + 12u); if (rc) return rc; }
    s->r[15] = 41947702u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801236(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947702u) != 17932u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 1);
    s->r[15] = 41947704u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801238(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947704u) != 25611u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[1] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 41947706u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280123a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947706u) != 45342u) return AGR_AOT_MISS;
    s->r[15] = !s->r[6] ? 41947716u : 41947708u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280123c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947708u) != 8705u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 41947710u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280123e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947710u) != 63487u || agr_aot_load16(s, 41947712u) != 65368u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41947378u | 1u, 41947714u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801242(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947714u) != 57363u) return AGR_AOT_MISS;
    s->r[15] = 41947756u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801244(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947716u) != 26883u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 16u); if (rc) return rc; }
    s->r[15] = 41947718u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801246(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947718u) != 17961u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 5);
    s->r[15] = 41947720u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801248(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947720u) != 8194u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    s->r[15] = 41947722u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280124a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947722u) != 17954u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 4);
    s->r[15] = 41947724u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280124c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947724u) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], 41947726u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280124e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947726u) != 10247u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 7u);
    s->r[15] = 41947728u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801250(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947728u) != 53253u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 41947742u : 41947730u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801252(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947730u) != 10248u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 8u);
    s->r[15] = 41947732u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801254(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947732u) != 53514u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41947756u : 41947734u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801256(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947734u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 41947736u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801258(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947736u) != 17953u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 4);
    s->r[15] = 41947738u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280125a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947738u) != 63487u || agr_aot_load16(s, 41947740u) != 65325u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41947320u | 1u, 41947742u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280125e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947742u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 41947744u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801260(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947744u) != 27681u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 64u); if (rc) return rc; }
    s->r[15] = 41947746u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801262(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947746u) != 63487u || agr_aot_load16(s, 41947748u) != 65320u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41947318u | 1u, 41947750u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801266(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947750u) != 7456u) return AGR_AOT_MISS;
    agr_aot_adds(s, 0, s->r[4], 4u);
    s->r[15] = 41947752u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801268(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947752u) != 61440u || agr_aot_load16(s, 41947754u) != 64240u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41949260u | 1u, 41947756u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280126c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947756u) != 63487u || agr_aot_load16(s, 41947758u) != 60784u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41946448u, 41947760u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801270(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947760u) != 26818u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[0] + 12u); if (rc) return rc; }
    s->r[15] = 41947762u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801272(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947762u) != 47370u) return AGR_AOT_MISS;
    s->r[15] = s->r[2] ? 41947768u : 41947764u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801274(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947764u) != 63487u || agr_aot_load16(s, 41947766u) != 49056u) return AGR_AOT_MISS;
    s->r[15] = 41947576u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801278(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947768u) != 27594u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[1] + 60u); if (rc) return rc; }
    s->r[15] = 41947770u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280127a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947770u) != 25610u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[1] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 41947772u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280127c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947772u) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 41947774u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280127e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947774u) != 59192u) return AGR_AOT_MISS;
    s->r[15] = 41947378u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801280(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947776u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801282(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947778u) != 46344u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    s->r[15] = 41947780u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801284(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947780u) != 17921u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 0);
    s->r[15] = 41947782u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801286(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947782u) != 26755u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = 41947784u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801288(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947784u) != 45323u) return AGR_AOT_MISS;
    s->r[15] = !s->r[3] ? 41947790u : 41947786u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280128a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947786u) != 8193u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = 41947788u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280128c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947788u) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], 41947790u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280128e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947790u) != 48392u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) return rc;
}

static int aot_debug_02801290(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947792u) != 46384u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16432u)) return AGR_AOT_FAULT;
    s->r[15] = 41947794u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801292(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947794u) != 10500u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[1], 4u);
    s->r[15] = 41947796u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801294(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947796u) != 55312u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 8u) ? 41947832u : 41947798u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280129a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947802u) != 773u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 5, s->r[0], 12u);
    s->r[15] = 41947804u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280129c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947804u) != 783u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 7, s->r[1], 12u);
    s->r[15] = 41947806u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280129e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947806u) != 3u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 3, s->r[0], 0u);
    s->r[15] = 41947808u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028012a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947808u) != 8193u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = 41947810u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028012a2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947810u) != 48432u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) return rc;
}

static int aot_debug_028012b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947832u) != 8194u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    s->r[15] = 41947834u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028012ba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947834u) != 48432u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) return rc;
}

static int aot_debug_028012d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947860u) != 46384u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16432u)) return AGR_AOT_FAULT;
    s->r[15] = 41947862u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028012d6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947862u) != 10500u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[1], 4u);
    s->r[15] = 41947864u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028012d8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947864u) != 55312u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 8u) ? 41947900u : 41947866u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_028012de(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947870u) != 773u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 5, s->r[0], 12u);
    s->r[15] = 41947872u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028012e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947872u) != 783u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 7, s->r[1], 12u);
    s->r[15] = 41947874u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028012e2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947874u) != 3u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 3, s->r[0], 0u);
    s->r[15] = 41947876u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028012e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947876u) != 8193u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = 41947878u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028012e6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947878u) != 48432u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) return rc;
}

static int aot_debug_028012fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947900u) != 8194u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    s->r[15] = 41947902u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028012fe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947902u) != 48432u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) return rc;
}

static int aot_debug_02801300(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947904u) != 46367u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16415u)) return AGR_AOT_FAULT;
    s->r[15] = 41947906u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801302(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947906u) != 43780u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 3, s->r[13], 16u);
    s->r[15] = 41947908u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801304(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947908u) != 17932u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 1);
    s->r[15] = 41947910u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801306(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947910u) != 8448u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = 41947912u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801308(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947912u) != 63555u || agr_aot_load16(s, 41947914u) != 11524u) return AGR_AOT_MISS;
    { uint32_t addr = (s->r[3] - 4u); s->r[3] = s->r[3] - 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 41947916u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280130c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947916u) != 17954u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 4);
    s->r[15] = 41947918u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280130e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947918u) != 37632u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 41947920u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801310(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947920u) != 17931u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = 41947922u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801312(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947922u) != 63487u || agr_aot_load16(s, 41947924u) != 65503u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41947860u | 1u, 41947926u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801316(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947926u) != 45060u) return AGR_AOT_MISS;
    s->r[13] += 16u;
    s->r[15] = 41947928u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801318(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947928u) != 48400u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_debug_0280131a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947930u) != 27603u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[2] + 60u); if (rc) return rc; }
    s->r[15] = 41947932u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280131c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947932u) != 59693u || agr_aot_load16(s, 41947934u) != 16880u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16880u)) return AGR_AOT_FAULT;
    s->r[15] = 41947936u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801320(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947936u) != 7445u) return AGR_AOT_MISS;
    agr_aot_adds(s, 5, s->r[2], 4u);
    s->r[15] = 41947938u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801322(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947938u) != 25619u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[2] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 41947940u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801324(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947940u) != 17927u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 7, 0);
    s->r[15] = 41947942u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801326(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947942u) != 18056u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 8, 1);
    s->r[15] = 41947944u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280132e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947950u) != 44055u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 4, s->r[13], 92u);
    s->r[15] = 41947952u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801330(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947952u) != 44566u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 6, s->r[13], 88u);
    s->r[15] = 41947954u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801340(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947968u) != 59524u || agr_aot_load16(s, 41947970u) != 15u) return AGR_AOT_MISS;
    if (agr_aot_stm(s, 4u, 15u)) return AGR_AOT_FAULT;
    s->r[15] = 41947972u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801344(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947972u) != 18028u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 13);
    s->r[15] = 41947974u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801346(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947974u) != 61519u || agr_aot_load16(s, 41947976u) != 13311u) return AGR_AOT_MISS;
    s->r[3] = 4294967295u;
    s->r[15] = 41947978u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280134a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947978u) != 24627u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[6] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 41947980u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280134c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947980u) != 18024u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 13);
    s->r[15] = 41947982u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280134e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947982u) != 27697u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[6] + 64u); if (rc) return rc; }
    s->r[15] = 41947984u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801350(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947984u) != 63487u || agr_aot_load16(s, 41947986u) != 65072u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41947060u | 1u, 41947988u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801354(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947988u) != 45320u) return AGR_AOT_MISS;
    s->r[15] = !s->r[0] ? 41947994u : 41947990u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801356(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947990u) != 9481u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 5, 9u);
    s->r[15] = 41947992u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801358(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947992u) != 57364u) return AGR_AOT_MISS;
    s->r[15] = 41948036u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280135a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947994u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 41947996u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280135c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947996u) != 8460u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 12u);
    s->r[15] = 41947998u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280135e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41947998u) != 18026u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 13);
    s->r[15] = 41948000u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801360(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948000u) != 63487u || agr_aot_load16(s, 41948002u) != 65486u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41947904u | 1u, 41948004u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801364(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948004u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 41948006u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801366(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948006u) != 17985u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 8);
    s->r[15] = 41948008u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801368(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948008u) != 18360u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[7], 41948010u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280136a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948010u) != 10240u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = 41948012u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280136c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948012u) != 53747u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41947990u : 41948014u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280136e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948014u) != 26915u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 16u); if (rc) return rc; }
    s->r[15] = 41948016u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801370(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948016u) != 8200u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 8u);
    s->r[15] = 41948018u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801372(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948018u) != 18025u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 13);
    s->r[15] = 41948020u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801374(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948020u) != 17970u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 41948022u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801376(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948022u) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], 41948024u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801378(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948024u) != 10245u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 5u);
    s->r[15] = 41948026u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280137a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948026u) != 17925u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 41948028u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280137c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948028u) != 53250u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 41948036u : 41948030u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280137e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948030u) != 10249u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 9u);
    s->r[15] = 41948032u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801380(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948032u) != 53732u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41947980u : 41948034u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801382(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948034u) != 59368u) return AGR_AOT_MISS;
    s->r[15] = 41947990u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801384(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948036u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 41948038u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801386(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948038u) != 63487u || agr_aot_load16(s, 41948040u) != 65127u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41947224u | 1u, 41948042u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280138a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948042u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 41948044u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280138c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948044u) != 62733u || agr_aot_load16(s, 41948046u) != 32014u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 13, s->r[13], 3854u);
    s->r[15] = 41948048u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801390(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948048u) != 59581u || agr_aot_load16(s, 41948050u) != 33264u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) return rc;
}

static int aot_debug_02801394(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948052u) != 59693u || agr_aot_load16(s, 41948054u) != 20464u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 20464u)) return AGR_AOT_FAULT;
    s->r[15] = 41948056u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801398(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948056u) != 17942u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 6, 2);
    s->r[15] = 41948058u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280139a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948058u) != 27850u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[1] + 76u); if (rc) return rc; }
    s->r[15] = 41948060u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280139c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948060u) != 45193u) return AGR_AOT_MISS;
    s->r[13] -= 36u;
    s->r[15] = 41948062u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280139e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948062u) != 18051u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 11, 0);
    s->r[15] = 41948064u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028013a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948064u) != 17932u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 1);
    s->r[15] = 41948066u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028013a2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948066u) != 7445u) return AGR_AOT_MISS;
    agr_aot_adds(s, 5, s->r[2], 4u);
    s->r[15] = 41948068u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028013a4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948068u) != 61440u || agr_aot_load16(s, 41948070u) != 2563u) return AGR_AOT_MISS;
    s->r[10] = s->r[0] & 3u;
    s->r[15] = 41948072u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028013a8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948072u) != 26642u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[2] + 0u); if (rc) return rc; }
    s->r[15] = 41948074u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028013aa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948074u) != 17951u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 7, 3);
    s->r[15] = 41948076u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028013ac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948076u) != 38150u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    s->r[15] = 41948078u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028013ae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948078u) != 37381u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 41948080u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028013b0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948080u) != 47419u) return AGR_AOT_MISS;
    s->r[15] = s->r[3] ? 41948098u : 41948082u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_028013b2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948082u) != 530u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 2, s->r[2], 8u);
    s->r[15] = 41948084u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028013b4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948084u) != 63629u || agr_aot_load16(s, 41948086u) != 12317u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 29u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    s->r[15] = 41948088u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028013b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948088u) != 37381u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 41948090u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028013ba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948090u) != 8963u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 3u);
    s->r[15] = 41948092u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028013bc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948092u) != 63629u || agr_aot_load16(s, 41948094u) != 12316u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 28u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    s->r[15] = 41948096u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028013c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948096u) != 57356u) return AGR_AOT_MISS;
    s->r[15] = 41948124u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_028013c2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948098u) != 11010u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 2u);
    s->r[15] = 41948100u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028013c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948100u) != 56330u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 12u) ? 41948124u : 41948102u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_028013c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948104u) != 63629u || agr_aot_load16(s, 41948106u) != 12317u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 29u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    s->r[15] = 41948108u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028013cc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948108u) != 1042u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 2, s->r[2], 16u);
    s->r[15] = 41948110u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028013ce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948110u) != 37381u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 41948112u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028013d0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948112u) != 45787u) return AGR_AOT_MISS;
    s->r[3] = s->r[3] & 0xffu;
    s->r[15] = 41948114u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028013d2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948114u) != 8706u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 2u);
    s->r[15] = 41948116u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028013d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948116u) != 63629u || agr_aot_load16(s, 41948118u) != 8220u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 28u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    s->r[15] = 41948120u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028013dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948124u) != 61882u || agr_aot_load16(s, 41948126u) != 3842u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[10], 2u);
    s->r[15] = 41948128u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028013e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948128u) != 27939u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 80u); if (rc) return rc; }
    s->r[15] = 41948130u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028013e2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948130u) != 48904u) return AGR_AOT_MISS;
    agr_aot_set_itstate(s, 8u); s->r[15] = 41948132u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280161c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948700u) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 41948702u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280161e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948702u) != 59065u) return AGR_AOT_MISS;
    s->r[15] = 41948052u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801620(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948704u) != 8961u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 1u);
    s->r[15] = 41948706u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801622(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948706u) != 59063u) return AGR_AOT_MISS;
    s->r[15] = 41948052u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801624(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948708u) != 8962u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 2u);
    s->r[15] = 41948710u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801626(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948710u) != 59061u) return AGR_AOT_MISS;
    s->r[15] = 41948052u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801628(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948712u) != 59693u || agr_aot_load16(s, 41948714u) != 16880u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16880u)) return AGR_AOT_FAULT;
    s->r[15] = 41948716u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280162c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948716u) != 17924u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 41948718u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280162e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948718u) != 45250u) return AGR_AOT_MISS;
    s->r[13] -= 264u;
    s->r[15] = 41948720u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801630(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948720u) != 17943u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 7, 2);
    s->r[15] = 41948722u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801632(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948722u) != 17949u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 3);
    s->r[15] = 41948724u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801634(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948724u) != 10500u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[1], 4u);
    s->r[15] = 41948726u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801636(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948726u) != 55419u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 8u) ? 41948976u : 41948728u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280163c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948732u) != 6659u) return AGR_AOT_MISS;
    agr_aot_subs(s, 3, s->r[0], s->r[0]);
    s->r[15] = 41948734u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280163e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948734u) != 10362u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 122u);
    s->r[15] = 41948736u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801640(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948736u) != 82u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 2, s->r[2], 1u);
    s->r[15] = 41948738u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801642(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948738u) != 11520u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[5], 0u);
    s->r[15] = 41948740u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801644(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948740u) != 53620u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41948976u : 41948742u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801646(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948742u) != 27523u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 56u); if (rc) return rc; }
    s->r[15] = 41948744u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280164a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948746u) != 8193u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = 41948748u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280164c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948748u) != 64000u || agr_aot_load16(s, 41948750u) != 61957u) return AGR_AOT_MISS;
    agr_aot_lsls_reg(s, 2, s->r[0], s->r[5]);
    s->r[15] = 41948752u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801652(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948754u) != 53252u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 41948766u : 41948756u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801654(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948756u) != 26650u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 41948758u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280165a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948762u) != 13060u) return AGR_AOT_MISS;
    agr_aot_adds(s, 3, s->r[3], 4u);
    s->r[15] = 41948764u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280165c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948764u) != 24690u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[6] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 41948766u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280165e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948766u) != 13569u) return AGR_AOT_MISS;
    agr_aot_adds(s, 5, s->r[5], 1u);
    s->r[15] = 41948768u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801660(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948768u) != 11536u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[5], 16u);
    s->r[15] = 41948770u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801662(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948770u) != 53747u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41948748u : 41948772u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801668(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948776u) != 61504u || agr_aot_load16(s, 41948778u) != 32901u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41949046u : 41948780u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280166c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948780u) != 25507u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[4] + 56u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 41948782u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280166e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948782u) != 57577u) return AGR_AOT_MISS;
    s->r[15] = 41949252u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801730(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948976u) != 8194u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    s->r[15] = 41948978u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801732(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41948978u) != 57479u) return AGR_AOT_MISS;
    s->r[15] = 41949252u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801776(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949046u) != 8192u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = 41949048u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801778(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949048u) != 57444u) return AGR_AOT_MISS;
    s->r[15] = 41949252u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801844(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949252u) != 45122u) return AGR_AOT_MISS;
    s->r[13] += 264u;
    s->r[15] = 41949254u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801846(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949254u) != 59581u || agr_aot_load16(s, 41949256u) != 33264u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) return rc;
}

static int aot_debug_0280184c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949260u) != 61696u || agr_aot_load16(s, 41949262u) != 308u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 1, s->r[0], 52u);
    s->r[15] = 41949264u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801854(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949268u) != 18076u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 12, 3);
    s->r[15] = 41949270u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801856(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949270u) != 18086u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 14, 4);
    s->r[15] = 41949272u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801858(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949272u) != 63564u || agr_aot_load16(s, 41949274u) != 23812u) return AGR_AOT_MISS;
    { uint32_t addr = (s->r[12] - 4u); s->r[12] = s->r[12] - 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    s->r[15] = 41949276u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801860(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949280u) != 18149u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 13, 12);
    s->r[15] = 41949282u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801862(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949282u) != 48384u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32768u))) return rc;
}

static int aot_debug_02801868(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949288u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801870(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949296u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801878(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949304u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801880(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949312u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801888(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949320u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801890(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949328u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_028018d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949396u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801918(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949464u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280192c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949484u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801940(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949504u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801944(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949508u) != 18156u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 12, 13);
    s->r[15] = 41949510u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801946(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949510u) != 46336u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16384u)) return AGR_AOT_FAULT;
    s->r[15] = 41949512u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801948(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949512u) != 59693u || agr_aot_load16(s, 41949514u) != 20480u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 20480u)) return AGR_AOT_FAULT;
    s->r[15] = 41949516u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280194c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949516u) != 59693u || agr_aot_load16(s, 41949518u) != 8191u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 8191u)) return AGR_AOT_FAULT;
    s->r[15] = 41949520u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801950(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949520u) != 61519u || agr_aot_load16(s, 41949522u) != 768u) return AGR_AOT_MISS;
    s->r[3] = 0u;
    s->r[15] = 41949524u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801954(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949524u) != 59693u || agr_aot_load16(s, 41949526u) != 12u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 12u)) return AGR_AOT_FAULT;
    s->r[15] = 41949528u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801958(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949528u) != 43265u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    s->r[15] = 41949530u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280195a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949530u) != 63487u || agr_aot_load16(s, 41949532u) != 64557u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41947576u | 1u, 41949534u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280195e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949534u) != 63709u || agr_aot_load16(s, 41949536u) != 57408u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[15] = 41949538u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801962(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949538u) != 45074u) return AGR_AOT_MISS;
    s->r[13] += 72u;
    s->r[15] = 41949540u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801964(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949540u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801968(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949544u) != 18156u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 12, 13);
    s->r[15] = 41949546u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280196a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949546u) != 46336u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16384u)) return AGR_AOT_FAULT;
    s->r[15] = 41949548u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280196c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949548u) != 59693u || agr_aot_load16(s, 41949550u) != 20480u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 20480u)) return AGR_AOT_FAULT;
    s->r[15] = 41949552u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801970(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949552u) != 59693u || agr_aot_load16(s, 41949554u) != 8191u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 8191u)) return AGR_AOT_FAULT;
    s->r[15] = 41949556u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801974(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949556u) != 61519u || agr_aot_load16(s, 41949558u) != 768u) return AGR_AOT_MISS;
    s->r[3] = 0u;
    s->r[15] = 41949560u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801978(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949560u) != 59693u || agr_aot_load16(s, 41949562u) != 12u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 12u)) return AGR_AOT_FAULT;
    s->r[15] = 41949564u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280197c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949564u) != 43265u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    s->r[15] = 41949566u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280197e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949566u) != 63487u || agr_aot_load16(s, 41949568u) != 64598u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41947694u | 1u, 41949570u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801982(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949570u) != 63709u || agr_aot_load16(s, 41949572u) != 57408u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[15] = 41949574u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801986(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949574u) != 45074u) return AGR_AOT_MISS;
    s->r[13] += 72u;
    s->r[15] = 41949576u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801988(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949576u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280198c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949580u) != 18156u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 12, 13);
    s->r[15] = 41949582u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280198e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949582u) != 46336u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16384u)) return AGR_AOT_FAULT;
    s->r[15] = 41949584u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801990(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949584u) != 59693u || agr_aot_load16(s, 41949586u) != 20480u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 20480u)) return AGR_AOT_FAULT;
    s->r[15] = 41949588u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801994(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949588u) != 59693u || agr_aot_load16(s, 41949590u) != 8191u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 8191u)) return AGR_AOT_FAULT;
    s->r[15] = 41949592u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801998(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949592u) != 61519u || agr_aot_load16(s, 41949594u) != 768u) return AGR_AOT_MISS;
    s->r[3] = 0u;
    s->r[15] = 41949596u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0280199c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949596u) != 59693u || agr_aot_load16(s, 41949598u) != 12u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 12u)) return AGR_AOT_FAULT;
    s->r[15] = 41949600u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949600u) != 43265u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    s->r[15] = 41949602u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019a2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949602u) != 63487u || agr_aot_load16(s, 41949604u) != 64613u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41947760u | 1u, 41949606u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019a6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949606u) != 63709u || agr_aot_load16(s, 41949608u) != 57408u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[15] = 41949610u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019aa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949610u) != 45074u) return AGR_AOT_MISS;
    s->r[13] += 72u;
    s->r[15] = 41949612u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019ac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949612u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019b0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949616u) != 18156u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 12, 13);
    s->r[15] = 41949618u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019b2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949618u) != 46336u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16384u)) return AGR_AOT_FAULT;
    s->r[15] = 41949620u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019b4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949620u) != 59693u || agr_aot_load16(s, 41949622u) != 20480u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 20480u)) return AGR_AOT_FAULT;
    s->r[15] = 41949624u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949624u) != 59693u || agr_aot_load16(s, 41949626u) != 8191u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 8191u)) return AGR_AOT_FAULT;
    s->r[15] = 41949628u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019bc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949628u) != 61519u || agr_aot_load16(s, 41949630u) != 768u) return AGR_AOT_MISS;
    s->r[3] = 0u;
    s->r[15] = 41949632u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949632u) != 59693u || agr_aot_load16(s, 41949634u) != 12u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 12u)) return AGR_AOT_FAULT;
    s->r[15] = 41949636u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949636u) != 43777u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 3, s->r[13], 4u);
    s->r[15] = 41949638u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019c6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949638u) != 63487u || agr_aot_load16(s, 41949640u) != 64552u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41947674u | 1u, 41949642u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949642u) != 63709u || agr_aot_load16(s, 41949644u) != 57408u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[15] = 41949646u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019ce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949646u) != 45074u) return AGR_AOT_MISS;
    s->r[13] += 72u;
    s->r[15] = 41949648u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019d0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949648u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949652u) != 18156u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 12, 13);
    s->r[15] = 41949654u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019d6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949654u) != 46336u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16384u)) return AGR_AOT_FAULT;
    s->r[15] = 41949656u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019d8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949656u) != 59693u || agr_aot_load16(s, 41949658u) != 20480u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 20480u)) return AGR_AOT_FAULT;
    s->r[15] = 41949660u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949660u) != 59693u || agr_aot_load16(s, 41949662u) != 8191u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 8191u)) return AGR_AOT_FAULT;
    s->r[15] = 41949664u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949664u) != 61519u || agr_aot_load16(s, 41949666u) != 768u) return AGR_AOT_MISS;
    s->r[3] = 0u;
    s->r[15] = 41949668u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949668u) != 59693u || agr_aot_load16(s, 41949670u) != 12u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 12u)) return AGR_AOT_FAULT;
    s->r[15] = 41949672u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019e8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949672u) != 43521u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    s->r[15] = 41949674u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019ea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949674u) != 63487u || agr_aot_load16(s, 41949676u) != 64662u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41947930u | 1u, 41949678u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019ee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949678u) != 63709u || agr_aot_load16(s, 41949680u) != 57408u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[15] = 41949682u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949682u) != 45074u) return AGR_AOT_MISS;
    s->r[13] += 72u;
    s->r[15] = 41949684u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019f4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949684u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019f8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949688u) != 31235u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = 41949690u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019fa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949690u) != 47443u) return AGR_AOT_MISS;
    s->r[15] = s->r[3] ? 41949714u : 41949692u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949692u) != 31299u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 9u); if (rc) return rc; }
    s->r[15] = 41949694u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_028019fe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949694u) != 45435u) return AGR_AOT_MISS;
    s->r[15] = !s->r[3] ? 41949728u : 41949696u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a00(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949696u) != 15105u) return AGR_AOT_MISS;
    agr_aot_subs(s, 3, s->r[3], 1u);
    s->r[15] = 41949698u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949698u) != 29251u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[0] + 9u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    s->r[15] = 41949700u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a04(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949700u) != 26691u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 4u); if (rc) return rc; }
    s->r[15] = 41949702u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a06(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949702u) != 7450u) return AGR_AOT_MISS;
    agr_aot_adds(s, 2, s->r[3], 4u);
    s->r[15] = 41949704u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949704u) != 24642u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[0] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 41949706u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a0a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949706u) != 26651u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 41949708u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a0c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949708u) != 24579u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 41949710u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a0e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949710u) != 8963u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 3u);
    s->r[15] = 41949712u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a10(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949712u) != 57344u) return AGR_AOT_MISS;
    s->r[15] = 41949716u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a12(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949714u) != 15105u) return AGR_AOT_MISS;
    agr_aot_subs(s, 3, s->r[3], 1u);
    s->r[15] = 41949716u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a14(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949716u) != 29187u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[0] + 8u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    s->r[15] = 41949718u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a16(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949718u) != 26627u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 41949720u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a18(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949720u) != 538u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 2, s->r[3], 8u);
    s->r[15] = 41949722u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a1a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949722u) != 24578u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 41949724u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a1e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949726u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949728u) != 8368u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 176u);
    s->r[15] = 41949730u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a22(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949730u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949732u) != 46367u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16415u)) return AGR_AOT_FAULT;
    s->r[15] = 41949734u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a26(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949734u) != 8448u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = 41949736u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a28(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949736u) != 43779u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 3, s->r[13], 12u);
    s->r[15] = 41949738u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a2a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949738u) != 8716u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 12u);
    s->r[15] = 41949740u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949740u) != 37632u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 41949742u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a2e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949742u) != 17931u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = 41949744u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a30(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949744u) != 63487u || agr_aot_load16(s, 41949746u) != 64558u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41947792u | 1u, 41949748u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a34(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949748u) != 38915u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 12u); if (rc) return rc; }
    s->r[15] = 41949750u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a36(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949750u) != 45061u) return AGR_AOT_MISS;
    s->r[13] += 20u;
    s->r[15] = 41949752u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a38(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949752u) != 63581u || agr_aot_load16(s, 41949754u) != 64260u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13]; s->r[13] = s->r[13] + 4u; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_02801a3c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949756u) != 59378u) return AGR_AOT_MISS;
    s->r[15] = 41949732u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a3e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949758u) != 59693u || agr_aot_load16(s, 41949760u) != 18431u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 18431u)) return AGR_AOT_FAULT;
    s->r[15] = 41949762u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a42(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949762u) != 17925u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 41949764u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949764u) != 17934u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 6, 1);
    s->r[15] = 41949766u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a46(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949766u) != 9984u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 7, 0u);
    s->r[15] = 41949768u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949768u) != 61709u || agr_aot_load16(s, 41949770u) != 2060u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 8, s->r[13], 12u);
    s->r[15] = 41949772u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a4c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949772u) != 62543u || agr_aot_load16(s, 41949774u) != 27007u) return AGR_AOT_MISS;
    s->r[9] = 4080u;
    s->r[15] = 41949776u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949776u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 41949778u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a52(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949778u) != 63487u || agr_aot_load16(s, 41949780u) != 65489u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41949688u | 1u, 41949782u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a56(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949782u) != 10416u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 176u);
    s->r[15] = 41949784u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a58(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949784u) != 17924u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 41949786u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a5a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949786u) != 53522u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41949826u : 41949788u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a5c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949788u) != 12032u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[7], 0u);
    s->r[15] = 41949790u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a5e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949790u) != 61504u || agr_aot_load16(s, 41949792u) != 33049u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41950356u : 41949794u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a62(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949794u) != 44035u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 4, s->r[13], 12u);
    s->r[15] = 41949796u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949796u) != 17977u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 7);
    s->r[15] = 41949798u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a66(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949798u) != 17979u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 7);
    s->r[15] = 41949800u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a68(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949800u) != 37888u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    s->r[15] = 41949802u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a6a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949802u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 41949804u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a6c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949804u) != 8718u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 14u);
    s->r[15] = 41949806u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a6e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949806u) != 63487u || agr_aot_load16(s, 41949808u) != 64527u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41947792u | 1u, 41949810u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949810u) != 37888u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    s->r[15] = 41949812u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a74(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949812u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 41949814u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a76(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949814u) != 17977u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 7);
    s->r[15] = 41949816u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949816u) != 8719u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 15u);
    s->r[15] = 41949818u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a7a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949818u) != 17979u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 7);
    s->r[15] = 41949820u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a7c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949820u) != 63487u || agr_aot_load16(s, 41949822u) != 64554u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41947860u | 1u, 41949824u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949824u) != 57608u) return AGR_AOT_MISS;
    s->r[15] = 41950356u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949834u) != 53525u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41949880u : 41949836u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a90(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949840u) != 17931u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = 41949842u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a92(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949842u) != 63693u || agr_aot_load16(s, 41949844u) != 32768u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    s->r[15] = 41949846u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a96(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949846u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 41949848u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a98(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949848u) != 8717u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 13u);
    s->r[15] = 41949850u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801a9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949854u) != 63487u || agr_aot_load16(s, 41949856u) != 64503u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41947792u | 1u, 41949858u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801aa2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949858u) != 39683u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 12u); if (rc) return rc; }
    s->r[15] = 41949860u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801aa4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949860u) != 61706u || agr_aot_load16(s, 41949862u) != 2564u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 10, s->r[10], 4u);
    s->r[15] = 41949864u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801aac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949868u) != 48916u) return AGR_AOT_MISS;
    agr_aot_set_itstate(s, 20u); s->r[15] = 41949870u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801ab8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949880u) != 61440u || agr_aot_load16(s, 41949882u) != 1008u) return AGR_AOT_MISS;
    s->r[3] = s->r[0] & 240u;
    s->r[15] = 41949884u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801abc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949884u) != 11136u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 128u);
    s->r[15] = 41949886u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801abe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949886u) != 53527u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41949936u : 41949888u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801ac0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949888u) != 516u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 4, s->r[0], 8u);
    s->r[15] = 41949890u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801ac2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949890u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 41949892u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801ac4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949892u) != 63487u || agr_aot_load16(s, 41949894u) != 65432u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41949688u | 1u, 41949896u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801aca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949898u) != 62896u || agr_aot_load16(s, 41949900u) != 20224u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 32768u);
    s->r[15] = 41949902u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801ace(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949902u) != 53505u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41949908u : 41949904u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801ad0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949904u) != 8201u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 9u);
    s->r[15] = 41949906u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801ad2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949906u) != 57568u) return AGR_AOT_MISS;
    s->r[15] = 41950358u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801ad4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949908u) != 260u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 4, s->r[0], 4u);
    s->r[15] = 41949910u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801ad6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949910u) != 8448u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = 41949912u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801ad8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949912u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 41949914u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801ada(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949914u) != 17931u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = 41949916u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801ade(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949918u) != 63487u || agr_aot_load16(s, 41949920u) != 64931u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41948712u | 1u, 41949922u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801ae2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949922u) != 10240u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = 41949924u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801ae4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949924u) != 53748u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41949904u : 41949926u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801aea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949930u) != 48920u) return AGR_AOT_MISS;
    agr_aot_set_itstate(s, 24u); s->r[15] = 41949932u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801af0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949936u) != 11152u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 144u);
    s->r[15] = 41949938u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801af2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949938u) != 53525u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41949984u : 41949940u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801af4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949940u) != 61440u || agr_aot_load16(s, 41949942u) != 781u) return AGR_AOT_MISS;
    s->r[3] = s->r[0] & 13u;
    s->r[15] = 41949944u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801af8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949944u) != 11021u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 13u);
    s->r[15] = 41949946u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801afa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949946u) != 53481u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 41949904u : 41949948u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801afc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949948u) != 8448u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = 41949950u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801afe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949950u) != 63693u || agr_aot_load16(s, 41949952u) != 32768u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    s->r[15] = 41949954u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949954u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 41949956u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b04(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949956u) != 61444u || agr_aot_load16(s, 41949958u) != 527u) return AGR_AOT_MISS;
    s->r[2] = s->r[4] & 15u;
    s->r[15] = 41949960u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949960u) != 17931u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = 41949962u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b0a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949962u) != 63487u || agr_aot_load16(s, 41949964u) != 64449u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41947792u | 1u, 41949966u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b0e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949966u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 41949968u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b10(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949968u) != 8448u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = 41949970u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b12(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949970u) != 63693u || agr_aot_load16(s, 41949972u) != 32768u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    s->r[15] = 41949974u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b16(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949974u) != 8717u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 13u);
    s->r[15] = 41949976u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b18(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949976u) != 17931u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = 41949978u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b1a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949978u) != 63487u || agr_aot_load16(s, 41949980u) != 64475u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41947860u | 1u, 41949982u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b1e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949982u) != 59287u) return AGR_AOT_MISS;
    s->r[15] = 41949776u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949984u) != 11168u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 160u);
    s->r[15] = 41949986u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b22(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949986u) != 53517u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41950016u : 41949988u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b26(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949990u) != 61442u || agr_aot_load16(s, 41949992u) != 519u) return AGR_AOT_MISS;
    s->r[2] = s->r[2] & 7u;
    s->r[15] = 41949994u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b2e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41949998u) != 1795u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 3, s->r[0], 28u);
    s->r[15] = 41950000u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b30(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950000u) != 62466u || agr_aot_load16(s, 41950002u) != 25215u) return AGR_AOT_MISS;
    s->r[2] = s->r[2] & 4080u;
    s->r[15] = 41950004u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b34(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950004u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 41950006u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b36(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950006u) != 48968u) return AGR_AOT_MISS;
    agr_aot_set_itstate(s, 72u); s->r[15] = 41950008u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950016u) != 11184u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 176u);
    s->r[15] = 41950018u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b42(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950018u) != 53579u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41950172u : 41950020u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950020u) != 10417u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 177u);
    s->r[15] = 41950022u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b46(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950022u) != 53515u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41950048u : 41950024u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950024u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 41950026u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b4a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950026u) != 63487u || agr_aot_load16(s, 41950028u) != 65365u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41949688u | 1u, 41950030u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b4e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950030u) != 17922u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 0);
    s->r[15] = 41950032u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950032u) != 10240u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = 41950034u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b52(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950034u) != 53437u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 41949904u : 41950036u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b58(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950040u) != 53690u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41949904u : 41950042u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b5a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950042u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 41950044u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b5c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950044u) != 17931u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = 41950046u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b5e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950046u) != 57491u) return AGR_AOT_MISS;
    s->r[15] = 41950344u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b60(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950048u) != 10418u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 178u);
    s->r[15] = 41950050u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b62(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950050u) != 53538u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41950122u : 41950052u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950052u) != 8448u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = 41950054u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b66(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950054u) != 8717u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 13u);
    s->r[15] = 41950056u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b68(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950056u) != 17931u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = 41950058u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b6a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950058u) != 63693u || agr_aot_load16(s, 41950060u) != 32768u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    s->r[15] = 41950062u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b6e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950062u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 41950064u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b70(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950064u) != 9218u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 4, 2u);
    s->r[15] = 41950066u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950066u) != 63487u || agr_aot_load16(s, 41950068u) != 64397u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41947792u | 1u, 41950070u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b76(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950070u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 41950072u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950072u) != 63487u || agr_aot_load16(s, 41950074u) != 65342u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41949688u | 1u, 41950076u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950080u) != 39683u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 12u); if (rc) return rc; }
    s->r[15] = 41950082u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b82(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950082u) != 61440u || agr_aot_load16(s, 41950084u) != 127u) return AGR_AOT_MISS;
    s->r[0] = s->r[0] & 127u;
    s->r[15] = 41950086u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b86(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950086u) != 53255u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 41950104u : 41950088u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950090u) != 13319u) return AGR_AOT_MISS;
    agr_aot_adds(s, 4, s->r[4], 7u);
    s->r[15] = 41950092u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b8c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950092u) != 17411u) return AGR_AOT_MISS;
    s->r[3] += s->r[0];
    s->r[15] = 41950094u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b8e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950094u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 41950096u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b90(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950096u) != 37635u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 41950098u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b92(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950098u) != 63487u || agr_aot_load16(s, 41950100u) != 65329u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41949688u | 1u, 41950102u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b96(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950102u) != 59377u) return AGR_AOT_MISS;
    s->r[15] = 41950076u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b98(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950104u) != 62723u || agr_aot_load16(s, 41950106u) != 29441u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 3, s->r[3], 3841u);
    s->r[15] = 41950108u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801b9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950110u) != 17432u) return AGR_AOT_MISS;
    s->r[0] += s->r[3];
    s->r[15] = 41950112u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801ba0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950112u) != 63693u || agr_aot_load16(s, 41950114u) != 32768u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    s->r[15] = 41950116u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801ba4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950116u) != 36867u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 41950118u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801ba6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950118u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 41950120u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801ba8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950120u) != 59317u) return AGR_AOT_MISS;
    s->r[15] = 41949974u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801baa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950122u) != 10419u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 179u);
    s->r[15] = 41950124u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801bac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950124u) != 53514u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41950148u : 41950126u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801bae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950126u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 41950128u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801bb0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950128u) != 63487u || agr_aot_load16(s, 41950130u) != 65314u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41949688u | 1u, 41950132u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801bb4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950132u) != 8449u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = 41950134u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801bb6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950134u) != 61440u || agr_aot_load16(s, 41950136u) != 783u) return AGR_AOT_MISS;
    s->r[3] = s->r[0] & 15u;
    s->r[15] = 41950138u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801bba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950138u) != 61440u || agr_aot_load16(s, 41950140u) != 752u) return AGR_AOT_MISS;
    s->r[2] = s->r[0] & 240u;
    s->r[15] = 41950142u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801bbe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950142u) != 13057u) return AGR_AOT_MISS;
    agr_aot_adds(s, 3, s->r[3], 1u);
    s->r[15] = 41950144u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801bc0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950144u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 41950146u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801bc2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950146u) != 57369u) return AGR_AOT_MISS;
    s->r[15] = 41950200u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801bc4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950148u) != 61440u || agr_aot_load16(s, 41950150u) != 1020u) return AGR_AOT_MISS;
    s->r[3] = s->r[0] & 252u;
    s->r[15] = 41950152u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801bc8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950152u) != 11188u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 180u);
    s->r[15] = 41950154u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801bca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950154u) != 53377u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 41949904u : 41950156u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801bcc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950156u) != 61440u || agr_aot_load16(s, 41950158u) != 1031u) return AGR_AOT_MISS;
    s->r[4] = s->r[0] & 7u;
    s->r[15] = 41950160u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801bd0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950160u) != 8449u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = 41950162u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801bd2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950162u) != 7266u) return AGR_AOT_MISS;
    agr_aot_adds(s, 2, s->r[4], 1u);
    s->r[15] = 41950164u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801bd4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950164u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 41950166u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801bd6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950166u) != 62530u || agr_aot_load16(s, 41950168u) != 8704u) return AGR_AOT_MISS;
    s->r[2] = s->r[2] | 524288u;
    s->r[15] = 41950170u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801bda(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950170u) != 59327u) return AGR_AOT_MISS;
    s->r[15] = 41950044u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801bdc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950172u) != 11200u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 192u);
    s->r[15] = 41950174u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801bde(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950174u) != 53574u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41950318u : 41950176u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801be0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950176u) != 10438u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 198u);
    s->r[15] = 41950178u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801be2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950178u) != 53516u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41950206u : 41950180u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801be4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950180u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 41950182u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801be6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950182u) != 63487u || agr_aot_load16(s, 41950184u) != 65287u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41949688u | 1u, 41950186u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801bea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950186u) != 8451u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 3u);
    s->r[15] = 41950188u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801bec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950188u) != 61440u || agr_aot_load16(s, 41950190u) != 783u) return AGR_AOT_MISS;
    s->r[3] = s->r[0] & 15u;
    s->r[15] = 41950192u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801bf0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950192u) != 61440u || agr_aot_load16(s, 41950194u) != 752u) return AGR_AOT_MISS;
    s->r[2] = s->r[0] & 240u;
    s->r[15] = 41950196u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801bf4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950196u) != 13057u) return AGR_AOT_MISS;
    agr_aot_adds(s, 3, s->r[3], 1u);
    s->r[15] = 41950198u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801bf6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950198u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 41950200u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801bfc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950204u) != 59310u) return AGR_AOT_MISS;
    s->r[15] = 41950044u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801bfe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950206u) != 10439u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 199u);
    s->r[15] = 41950208u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c00(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950208u) != 53517u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41950238u : 41950210u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950210u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 41950212u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c04(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950212u) != 63487u || agr_aot_load16(s, 41950214u) != 65272u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41949688u | 1u, 41950216u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950216u) != 17922u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 0);
    s->r[15] = 41950218u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c0a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950218u) != 10240u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = 41950220u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c0c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950220u) != 62527u || agr_aot_load16(s, 41950222u) != 44896u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 41949904u : 41950224u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c14(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950228u) != 62591u || agr_aot_load16(s, 41950230u) != 44892u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41949904u : 41950232u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c18(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950232u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 41950234u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c1a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950234u) != 8452u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 4u);
    s->r[15] = 41950236u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c1c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950236u) != 57396u) return AGR_AOT_MISS;
    s->r[15] = 41950344u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c1e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950238u) != 61440u || agr_aot_load16(s, 41950240u) != 1016u) return AGR_AOT_MISS;
    s->r[3] = s->r[0] & 248u;
    s->r[15] = 41950242u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c22(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950242u) != 11200u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 192u);
    s->r[15] = 41950244u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950244u) != 53511u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41950262u : 41950246u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c26(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950246u) != 61440u || agr_aot_load16(s, 41950248u) != 1039u) return AGR_AOT_MISS;
    s->r[4] = s->r[0] & 15u;
    s->r[15] = 41950250u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c2a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950250u) != 8451u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 3u);
    s->r[15] = 41950252u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950252u) != 7266u) return AGR_AOT_MISS;
    agr_aot_adds(s, 2, s->r[4], 1u);
    s->r[15] = 41950254u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c2e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950254u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 41950256u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c30(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950256u) != 62530u || agr_aot_load16(s, 41950258u) != 8736u) return AGR_AOT_MISS;
    s->r[2] = s->r[2] | 655360u;
    s->r[15] = 41950260u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c34(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950260u) != 59282u) return AGR_AOT_MISS;
    s->r[15] = 41950044u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c36(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950262u) != 10440u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 200u);
    s->r[15] = 41950264u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c38(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950264u) != 53513u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41950286u : 41950266u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c3a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950266u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 41950268u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c3c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950268u) != 63487u || agr_aot_load16(s, 41950270u) != 65244u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41949688u | 1u, 41950272u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950272u) != 61440u || agr_aot_load16(s, 41950274u) != 752u) return AGR_AOT_MISS;
    s->r[2] = s->r[0] & 240u;
    s->r[15] = 41950276u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950276u) != 61440u || agr_aot_load16(s, 41950278u) != 15u) return AGR_AOT_MISS;
    s->r[0] = s->r[0] & 15u;
    s->r[15] = 41950280u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950280u) != 12816u) return AGR_AOT_MISS;
    agr_aot_adds(s, 2, s->r[2], 16u);
    s->r[15] = 41950282u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c4a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950282u) != 7235u) return AGR_AOT_MISS;
    agr_aot_adds(s, 3, s->r[0], 1u);
    s->r[15] = 41950284u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c4c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950284u) != 57354u) return AGR_AOT_MISS;
    s->r[15] = 41950308u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c4e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950286u) != 10441u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 201u);
    s->r[15] = 41950288u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950288u) != 62591u || agr_aot_load16(s, 41950290u) != 44862u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41949904u : 41950292u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c54(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950292u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 41950294u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c56(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950294u) != 63487u || agr_aot_load16(s, 41950296u) != 65231u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41949688u | 1u, 41950298u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c5a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950298u) != 61440u || agr_aot_load16(s, 41950300u) != 783u) return AGR_AOT_MISS;
    s->r[3] = s->r[0] & 15u;
    s->r[15] = 41950302u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c5e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950302u) != 61440u || agr_aot_load16(s, 41950304u) != 752u) return AGR_AOT_MISS;
    s->r[2] = s->r[0] & 240u;
    s->r[15] = 41950306u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c62(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950306u) != 13057u) return AGR_AOT_MISS;
    agr_aot_adds(s, 3, s->r[3], 1u);
    s->r[15] = 41950308u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950308u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 41950310u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c66(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950310u) != 8449u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = 41950312u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c6c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950316u) != 57355u) return AGR_AOT_MISS;
    s->r[15] = 41950342u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c6e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950318u) != 61440u || agr_aot_load16(s, 41950320u) != 1016u) return AGR_AOT_MISS;
    s->r[3] = s->r[0] & 248u;
    s->r[15] = 41950322u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950322u) != 11216u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 208u);
    s->r[15] = 41950324u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c74(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950324u) != 62591u || agr_aot_load16(s, 41950326u) != 44844u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41949904u : 41950328u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950328u) != 61440u || agr_aot_load16(s, 41950330u) != 1031u) return AGR_AOT_MISS;
    s->r[4] = s->r[0] & 7u;
    s->r[15] = 41950332u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c7c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950332u) != 8449u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = 41950334u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c7e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950334u) != 7266u) return AGR_AOT_MISS;
    agr_aot_adds(s, 2, s->r[4], 1u);
    s->r[15] = 41950336u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950336u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 41950338u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c82(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950338u) != 62530u || agr_aot_load16(s, 41950340u) != 8704u) return AGR_AOT_MISS;
    s->r[2] = s->r[2] | 524288u;
    s->r[15] = 41950342u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c86(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950342u) != 8965u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 5u);
    s->r[15] = 41950344u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c88(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950344u) != 63487u || agr_aot_load16(s, 41950346u) != 64718u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41948712u | 1u, 41950348u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c8c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950348u) != 10240u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = 41950350u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c8e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950350u) != 62591u || agr_aot_load16(s, 41950352u) != 44831u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41949904u : 41950354u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c92(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950354u) != 59101u) return AGR_AOT_MISS;
    s->r[15] = 41949776u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950356u) != 8192u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = 41950358u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c96(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950358u) != 45060u) return AGR_AOT_MISS;
    s->r[13] += 16u;
    s->r[15] = 41950360u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c98(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950360u) != 59581u || agr_aot_load16(s, 41950362u) != 34800u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 34800u))) return rc;
}

static int aot_debug_02801c9c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950364u) != 46367u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16415u)) return AGR_AOT_FAULT;
    s->r[15] = 41950366u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801c9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950366u) != 27843u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 76u); if (rc) return rc; }
    s->r[15] = 41950368u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801ca0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950368u) != 17928u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 1);
    s->r[15] = 41950370u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801ca2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950370u) != 43265u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    s->r[15] = 41950372u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801ca4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950372u) != 26714u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 4u); if (rc) return rc; }
    s->r[15] = 41950374u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801ca6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950374u) != 530u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 2, s->r[2], 8u);
    s->r[15] = 41950376u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801ca8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950376u) != 37377u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 41950378u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801caa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950378u) != 61699u || agr_aot_load16(s, 41950380u) != 520u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 2, s->r[3], 8u);
    s->r[15] = 41950382u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801cae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950382u) != 37378u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 41950384u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801cb0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950384u) != 8707u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 3u);
    s->r[15] = 41950386u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801cb2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950386u) != 63629u || agr_aot_load16(s, 41950388u) != 8204u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 12u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    s->r[15] = 41950390u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801cb6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950390u) != 31195u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[3] + 7u); if (rc) return rc; }
    s->r[15] = 41950392u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801cb8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950392u) != 63629u || agr_aot_load16(s, 41950394u) != 12301u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 13u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    s->r[15] = 41950396u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801cbc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950396u) != 63487u || agr_aot_load16(s, 41950398u) != 65215u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41949758u | 1u, 41950400u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801cc0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950400u) != 45061u) return AGR_AOT_MISS;
    s->r[13] += 20u;
    s->r[15] = 41950402u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801cc2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950402u) != 63581u || agr_aot_load16(s, 41950404u) != 64260u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13]; s->r[13] = s->r[13] + 4u; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_02801cc6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950406u) != 46344u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    s->r[15] = 41950408u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801cc8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950408u) != 63487u || agr_aot_load16(s, 41950410u) != 65208u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41949756u | 1u, 41950412u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801ccc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950412u) != 27776u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 72u); if (rc) return rc; }
    s->r[15] = 41950414u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801cce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950414u) != 48392u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) return rc;
}

static int aot_debug_02801cd0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950416u) != 46344u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    s->r[15] = 41950418u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801cd2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950418u) != 63487u || agr_aot_load16(s, 41950420u) != 65203u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41949756u | 1u, 41950422u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801cd6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950422u) != 27843u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 76u); if (rc) return rc; }
    s->r[15] = 41950424u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801cd8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950424u) != 31194u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldrb(s, 2, s->r[3] + 7u); if (rc) return rc; }
    s->r[15] = 41950426u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801cde(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950430u) != 12296u) return AGR_AOT_MISS;
    agr_aot_adds(s, 0, s->r[0], 8u);
    s->r[15] = 41950432u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801ce0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950432u) != 48392u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) return rc;
}

static int aot_debug_02801ce2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950434u) != 46344u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    s->r[15] = 41950436u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801ce4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950436u) != 63487u || agr_aot_load16(s, 41950438u) != 59444u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41946448u, 41950440u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801ce8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950440u) != 46344u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    s->r[15] = 41950442u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_02801cea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 41950442u) != 63487u || agr_aot_load16(s, 41950444u) != 59442u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 41946448u, 41950446u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800cfc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 41946372u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    { uint32_t addr = s->r[12] + 720u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_02800d08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 41946384u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    { uint32_t addr = s->r[12] + 712u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_02800d14(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 41946396u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    { uint32_t addr = s->r[12] + 704u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_02800d20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 41946408u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    { uint32_t addr = s->r[12] + 696u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_02800d2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 41946420u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    { uint32_t addr = s->r[12] + 688u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_02800d38(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 41946432u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    { uint32_t addr = s->r[12] + 680u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_02800d44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 41946444u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    { uint32_t addr = s->r[12] + 672u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_02800d50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 41946456u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    { uint32_t addr = s->r[12] + 664u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_02800d80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = (41946504u) + 4u; if ((rc = agr_aot_ldr(s, 0, addr))) return rc; }
    agr_aot_add_imm(s, 0, 41946508u, s->r[0]);
    s->r[15] = 41946504u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800dc4(AgrAotRegs *s) {
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
    agr_aot_branch_reg(s, s->r[3], 41946588u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800ddc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 1, 10);
    agr_aot_movs_imm(s, 2, 0u);
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) return rc; }
    agr_aot_mov_reg(s, 7, 0);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, s->r[3], 41946604u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800dec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 9, 0);
    s->r[15] = !s->r[6] ? 41946626u : 41946608u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800df0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_mov_reg(s, 1, 6);
    agr_aot_movs_imm(s, 2, 0u);
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 748u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[3], 41946622u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800dfe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 41946628u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800e02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 5, 6);
    s->r[15] = 41946628u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800e04(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_movs_imm(s, 2, 0u);
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 44u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 744u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[3], 41946642u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800e12(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movw(s, 1, 5126u);
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_mov_reg(s, 3, 7);
    agr_aot_mov_reg(s, 11, 0);
    agr_aot_movs_imm(s, 0, 3u);
    agr_aot_branch_reg(s, 41946376u, 41946658u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800e22(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 4u);
    agr_aot_movw(s, 1, 5126u);
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_mov_reg(s, 3, 9);
    agr_aot_branch_reg(s, 41946388u, 41946672u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800e30(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[5] ? 41946688u : 41946674u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800e32(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    agr_aot_movw(s, 1, 5132u);
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_mov_reg(s, 3, 5);
    agr_aot_branch_reg(s, 41946400u, 41946688u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800e40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 4u);
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 48u); if (rc) return rc; }
    agr_aot_movw(s, 2, 5123u);
    agr_aot_mov_reg(s, 3, 11);
    agr_aot_branch_reg(s, 41946412u, 41946702u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800e4e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 44u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 11);
    { int rc = agr_aot_ldr(s, 12, s->r[3] + 776u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_branch_reg(s, s->r[12], 41946718u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800e5e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[5] ? 41946736u : 41946720u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800e60(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_mov_reg(s, 1, 6);
    agr_aot_mov_reg(s, 2, 5);
    { int rc = agr_aot_ldr(s, 12, s->r[3] + 780u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_branch_reg(s, s->r[12], 41946736u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800e70(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_mov_reg(s, 1, 10);
    agr_aot_mov_reg(s, 2, 9);
    { int rc = agr_aot_ldr(s, 5, s->r[3] + 788u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_branch_reg(s, s->r[5], 41946752u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800e80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_mov_reg(s, 1, 8);
    agr_aot_mov_reg(s, 2, 7);
    { int rc = agr_aot_ldr(s, 5, s->r[3] + 788u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_branch_reg(s, s->r[5], 41946768u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800e90(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 36856u))) return rc;
}

static int aot_fast_02800e94(AgrAotRegs *s) {
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
    agr_aot_branch_reg(s, s->r[3], 41946798u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800eae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 1, 7);
    agr_aot_movs_imm(s, 2, 0u);
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) return rc; }
    agr_aot_mov_reg(s, 5, 0);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, s->r[3], 41946814u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800ebe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 1, 9);
    agr_aot_mov_reg(s, 3, 5);
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_mov_reg(s, 6, 0);
    agr_aot_movs_imm(s, 0, 2u);
    agr_aot_branch_reg(s, 41946376u, 41946828u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800ecc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 3, 6);
    agr_aot_mov_reg(s, 1, 9);
    agr_aot_movs_imm(s, 0, 4u);
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_branch_reg(s, 41946388u, 41946840u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800ed8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[13] + 32u); if (rc) return rc; }
    agr_aot_movs_imm(s, 0, 1u);
    agr_aot_movs_imm(s, 1, 0u);
    agr_aot_branch_reg(s, 41946424u, 41946850u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800ee2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_mov_reg(s, 1, 7);
    agr_aot_mov_reg(s, 2, 6);
    { int rc = agr_aot_ldr(s, 12, s->r[3] + 788u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_branch_reg(s, s->r[12], 41946866u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800ef2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_mov_reg(s, 1, 8);
    agr_aot_mov_reg(s, 2, 5);
    { int rc = agr_aot_ldr(s, 6, s->r[3] + 788u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_branch_reg(s, s->r[6], 41946882u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800f02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 33784u))) return rc;
}

static int aot_fast_02800f08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_lsls(s, 2, s->r[3], 1u);
    agr_aot_set_itstate(s, 76u); s->r[15] = 41946894u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800f1a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 20471u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 9, 0);
    agr_aot_mov_reg(s, 6, 2);
    s->r[15] = !s->r[1] ? 41946990u : 41946916u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800f24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 8, s->r[1], 1023u);
    agr_aot_movs_imm(s, 7, 0u);
    agr_aot_mov_reg(s, 10, 8);
    s->r[15] = 41946924u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800f2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 4, s->r[7], s->r[10]);
    s->r[15] = 41946928u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800f36(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 3, s->r[4], 3u);
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_add_imm(s, 5, s->r[9], s->r[3]);
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_branch_reg(s, 41946888u | 1u, 41946948u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800f44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[4], s->r[8]);
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 4u); if (rc) return rc; }
    agr_aot_mov_reg(s, 11, 0);
    s->r[15] = agr_aot_condition(s, 0u) ? 41946998u : 41946956u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800f4c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 0, s->r[3], 8u);
    s->r[0] += s->r[9];
    agr_aot_branch_reg(s, 41946888u | 1u, 41946966u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800f56(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[6], s->r[11]);
    s->r[15] = agr_aot_condition(s, 2u) ? 41946980u : 41946970u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800f5a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[4], s->r[7]);
    s->r[15] = agr_aot_condition(s, 0u) ? 41946994u : 41946974u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800f5e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 10, s->r[4], 1023u);
    s->r[15] = 41946924u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800f64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 0, s->r[0], 1u);
    agr_aot_cmp(s, s->r[6], s->r[0]);
    s->r[15] = agr_aot_condition(s, 9u) ? 41947002u : 41946986u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800f6a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 7, s->r[4], 1u);
    s->r[15] = 41946924u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800f6e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 5, 1);
    s->r[15] = 41947002u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800f72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 5, 0u);
    s->r[15] = 41947002u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800f76(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[6], s->r[0]);
    s->r[15] = agr_aot_condition(s, 3u) ? 41946970u : 41947002u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800f7a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[13] += 12u;
    if ((rc = agr_aot_ldmia_sp(s, 36848u))) return rc;
}

static int aot_fast_02800f82(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 1u);
    s->r[15] = agr_aot_condition(s, 0u) ? 41947028u : 41947014u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800f86(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 2u);
    s->r[15] = agr_aot_condition(s, 0u) ? 41947036u : 41947018u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800f8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = s->r[0] ? 41947044u : 41947020u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800f8c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 41947024u + 24u); if (rc) return rc; }
    s->r[0] += 41947026u;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800f94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 41947032u + 20u); if (rc) return rc; }
    s->r[0] += 41947034u;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800f9c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 41947040u + 16u); if (rc) return rc; }
    s->r[0] += 41947042u;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800fa4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800fa8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 22u);
    agr_aot_lsls(s, 0, s->r[0], 0u);
    agr_aot_movs_imm(s, 0, 18u);
    agr_aot_lsls(s, 0, s->r[0], 0u);
    agr_aot_movs_imm(s, 0, 14u);
    agr_aot_lsls(s, 0, s->r[0], 0u);
    s->r[15] = 41947060u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800fb4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 41947064u + 148u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16499u)) return AGR_AOT_FAULT;
    s->r[3] += 41947068u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_subs(s, 6, s->r[1], 2u);
    s->r[15] = !s->r[3] ? 41947088u : 41947074u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800fc2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    agr_aot_branch_reg(s, 41946436u, 41947082u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800fca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = s->r[5] ? 41947108u : 41947086u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800fce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 41947120u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800fd0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 5, 41947092u + 124u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, 41947092u + 128u); if (rc) return rc; }
    s->r[5] += 41947096u;
    { int rc = agr_aot_ldr(s, 5, s->r[5] + 0u); if (rc) return rc; }
    s->r[3] += 41947100u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_subs(s, 5, s->r[5], s->r[3]);
    agr_aot_mov_reg(s, 0, 3);
    s->r[15] = 41947104u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800fe2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    s->r[15] = 41947108u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800fe4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 4u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_branch_reg(s, 41946906u | 1u, 41947116u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800fec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = s->r[0] ? 41947126u : 41947120u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800ff0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    agr_aot_movs_imm(s, 0, 9u);
    s->r[15] = 41947206u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800ff6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 41946888u | 1u, 41947130u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02800ffa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 4u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 1u);
    { uint32_t addr = s->r[4] + 72u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = agr_aot_condition(s, 1u) ? 41947146u : 41947138u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801002(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_movs_imm(s, 0, 5u);
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 41947206u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280100a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 0u);
    agr_aot_add_imm(s, 0, s->r[5], 4u);
    s->r[15] = agr_aot_condition(s, 10u) ? 41947160u : 41947154u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801012(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 76u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_movs_imm(s, 3, 1u);
    s->r[15] = 41947168u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801018(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 41946888u | 1u, 41947164u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280101c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    { uint32_t addr = s->r[4] + 76u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 41947168u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801020(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[4] + 76u); if (rc) return rc; }
    { uint32_t addr = s->r[4] + 80u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 0u);
    s->r[15] = agr_aot_condition(s, 10u) ? 41947198u : 41947178u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280102e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 41947010u | 1u, 41947186u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801032(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_cmp(s, s->r[0], 0u);
    agr_aot_set_itstate(s, 12u); s->r[15] = 41947192u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280103e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 41946888u | 1u, 41947202u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801042(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = 41947206u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801046(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_02801058(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_lsls(s, 0, s->r[3], 31u);
    s->r[15] = agr_aot_condition(s, 4u) ? 41947254u : 41947234u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801066(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 72u);
    s->r[15] = agr_aot_condition(s, 0u) ? 41947250u : 41947244u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280106c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 41949300u | 1u, 41947248u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801070(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 41947254u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801072(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 41949284u | 1u, 41947254u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801076(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_lsls(s, 1, s->r[3], 29u);
    s->r[15] = agr_aot_condition(s, 4u) ? 41947268u : 41947260u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280107c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 208u);
    agr_aot_branch_reg(s, 41949316u | 1u, 41947268u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801084(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_lsls(s, 2, s->r[3], 28u);
    s->r[15] = agr_aot_condition(s, 4u) ? 41947282u : 41947274u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280108a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 4008u);
    agr_aot_branch_reg(s, 41949332u | 1u, 41947282u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801092(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_lsls(s, 3, s->r[3], 27u);
    s->r[15] = agr_aot_condition(s, 4u) ? 41947300u : 41947288u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801098(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 4072u);
    if ((rc = agr_aot_ldmia_sp(s, 16400u))) return rc;
    s->r[15] = 41949468u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_028010a4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_028010b6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_028010b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 5, 0);
    agr_aot_mov_reg(s, 4, 1);
    s->r[15] = 41947326u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_028010be(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 64u); if (rc) return rc; }
    agr_aot_branch_reg(s, 41947060u | 1u, 41947334u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_028010c6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 6, 0);
    s->r[15] = !s->r[0] ? 41947342u : 41947338u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_028010ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 41946448u, 41947342u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_028010ce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 64u); if (rc) return rc; }
    agr_aot_movs_imm(s, 0, 1u);
    agr_aot_mov_reg(s, 1, 5);
    agr_aot_mov_reg(s, 2, 4);
    { uint32_t addr = s->r[5] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 16u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[3], 41947356u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_028010dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 8u);
    s->r[15] = agr_aot_condition(s, 0u) ? 41947326u : 41947360u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_028010e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 7u);
    s->r[15] = agr_aot_condition(s, 1u) ? 41947338u : 41947364u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_028010e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 64u); if (rc) return rc; }
    agr_aot_branch_reg(s, 41947318u | 1u, 41947372u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_028010ec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 0, s->r[4], 4u);
    agr_aot_branch_reg(s, 41949260u | 1u, 41947378u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_028010f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 20464u)) return AGR_AOT_FAULT;
    agr_aot_adds(s, 5, s->r[1], 4u);
    { int rc = agr_aot_ldr(s, 8, s->r[0] + 12u); if (rc) return rc; }
    agr_aot_mov_reg(s, 7, 0);
    { int rc = agr_aot_ldr(s, 9, s->r[0] + 24u); if (rc) return rc; }
    agr_aot_mov_reg(s, 10, 2);
    s->r[15] = 41947396u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280110a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 4, s->r[13], 12u);
    agr_aot_add_imm(s, 6, s->r[13], 8u);
    s->r[15] = 41947406u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280111c(AgrAotRegs *s) {
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
    agr_aot_branch_reg(s, 41947060u | 1u, 41947440u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801130(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[10], 0u);
    agr_aot_set_itstate(s, 20u); s->r[15] = 41947446u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_028011b4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 68u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_028011b8(AgrAotRegs *s) {
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
    s->r[15] = 41947592u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_028011ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 4, s->r[13], 4u);
    agr_aot_mov_reg(s, 8, 13);
    s->r[15] = 41947598u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_028011dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stm(s, 4u, 15u)) return AGR_AOT_FAULT;
    s->r[3] = 4294967295u;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 41947622u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_028011e6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 7);
    { int rc = agr_aot_ldr(s, 1, s->r[8] + 64u); if (rc) return rc; }
    agr_aot_branch_reg(s, 41947060u | 1u, 41947632u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_028011f0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = s->r[0] ? 41947666u : 41947634u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_028011f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[7] + 16u); if (rc) return rc; }
    agr_aot_mov_reg(s, 1, 7);
    agr_aot_mov_reg(s, 2, 13);
    agr_aot_branch_reg(s, s->r[3], 41947642u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_028011fa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 8u);
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = agr_aot_condition(s, 0u) ? 41947622u : 41947648u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801200(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 13);
    agr_aot_branch_reg(s, 41947224u | 1u, 41947654u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801206(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[4], 6u);
    s->r[15] = agr_aot_condition(s, 1u) ? 41947666u : 41947658u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280120a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 7);
    agr_aot_mov_reg(s, 1, 6);
    agr_aot_branch_reg(s, 41947320u | 1u, 41947666u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801212(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 9u);
    s->r[13] += 480u;
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) return rc;
}

static int aot_fast_0280121a(AgrAotRegs *s) {
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
    s->r[15] = 41947378u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280122e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 20u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 5, 0);
    { int rc = agr_aot_ldr(s, 6, s->r[0] + 12u); if (rc) return rc; }
    agr_aot_mov_reg(s, 4, 1);
    { uint32_t addr = s->r[1] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = !s->r[6] ? 41947716u : 41947708u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280123c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 2, 1u);
    agr_aot_branch_reg(s, 41947378u | 1u, 41947714u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801242(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 41947756u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801244(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 16u); if (rc) return rc; }
    agr_aot_mov_reg(s, 1, 5);
    agr_aot_movs_imm(s, 0, 2u);
    agr_aot_mov_reg(s, 2, 4);
    agr_aot_branch_reg(s, s->r[3], 41947726u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280124e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 7u);
    s->r[15] = agr_aot_condition(s, 0u) ? 41947742u : 41947730u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801252(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 8u);
    s->r[15] = agr_aot_condition(s, 1u) ? 41947756u : 41947734u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801256(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 1, 4);
    agr_aot_branch_reg(s, 41947320u | 1u, 41947742u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280125e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 64u); if (rc) return rc; }
    agr_aot_branch_reg(s, 41947318u | 1u, 41947750u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801266(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 0, s->r[4], 4u);
    agr_aot_branch_reg(s, 41949260u | 1u, 41947756u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280126c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 41946448u, 41947760u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801270(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[0] + 12u); if (rc) return rc; }
    s->r[15] = s->r[2] ? 41947768u : 41947764u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801274(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 41947576u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801278(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[1] + 60u); if (rc) return rc; }
    { uint32_t addr = s->r[1] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 41947378u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801280(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801282(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 1, 0);
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = !s->r[3] ? 41947790u : 41947786u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280128a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 1u);
    agr_aot_branch_reg(s, s->r[3], 41947790u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280128e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) return rc;
}

static int aot_fast_02801290(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16432u)) return AGR_AOT_FAULT;
    agr_aot_cmp(s, s->r[1], 4u);
    s->r[15] = agr_aot_condition(s, 8u) ? 41947832u : 41947798u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280129a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 5, s->r[0], 12u);
    agr_aot_lsls(s, 7, s->r[1], 12u);
    agr_aot_lsls(s, 3, s->r[0], 0u);
    agr_aot_movs_imm(s, 0, 1u);
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) return rc;
}

static int aot_fast_028012b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) return rc;
}

static int aot_fast_028012d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16432u)) return AGR_AOT_FAULT;
    agr_aot_cmp(s, s->r[1], 4u);
    s->r[15] = agr_aot_condition(s, 8u) ? 41947900u : 41947866u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_028012de(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 5, s->r[0], 12u);
    agr_aot_lsls(s, 7, s->r[1], 12u);
    agr_aot_lsls(s, 3, s->r[0], 0u);
    agr_aot_movs_imm(s, 0, 1u);
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) return rc;
}

static int aot_fast_028012fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) return rc;
}

static int aot_fast_02801300(AgrAotRegs *s) {
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
    agr_aot_branch_reg(s, 41947860u | 1u, 41947926u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801316(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 16u;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_0280131a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[2] + 60u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16880u)) return AGR_AOT_FAULT;
    agr_aot_adds(s, 5, s->r[2], 4u);
    { uint32_t addr = s->r[2] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_mov_reg(s, 7, 0);
    agr_aot_mov_reg(s, 8, 1);
    s->r[15] = 41947944u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280132e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 4, s->r[13], 92u);
    agr_aot_add_imm(s, 6, s->r[13], 88u);
    s->r[15] = 41947954u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801340(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stm(s, 4u, 15u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 13);
    s->r[3] = 4294967295u;
    { uint32_t addr = s->r[6] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 41947980u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280134c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 13);
    { int rc = agr_aot_ldr(s, 1, s->r[6] + 64u); if (rc) return rc; }
    agr_aot_branch_reg(s, 41947060u | 1u, 41947988u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801354(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[0] ? 41947994u : 41947990u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801356(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 5, 9u);
    s->r[15] = 41948036u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280135a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_movs_imm(s, 1, 12u);
    agr_aot_mov_reg(s, 2, 13);
    agr_aot_branch_reg(s, 41947904u | 1u, 41948004u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801364(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_mov_reg(s, 1, 8);
    agr_aot_branch_reg(s, s->r[7], 41948010u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280136a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 41947990u : 41948014u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280136e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 16u); if (rc) return rc; }
    agr_aot_movs_imm(s, 0, 8u);
    agr_aot_mov_reg(s, 1, 13);
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_branch_reg(s, s->r[3], 41948024u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801378(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 5u);
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = agr_aot_condition(s, 0u) ? 41948036u : 41948030u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280137e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 9u);
    s->r[15] = agr_aot_condition(s, 1u) ? 41947980u : 41948034u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801382(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 41947990u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801384(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 41947224u | 1u, 41948042u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280138a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_add_imm(s, 13, s->r[13], 3854u);
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) return rc;
}

static int aot_fast_02801394(AgrAotRegs *s) {
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
    s->r[15] = s->r[3] ? 41948098u : 41948082u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_028013b2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 2, s->r[2], 8u);
    { uint32_t addr = s->r[13] + 29u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    { uint32_t addr = s->r[13] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_movs_imm(s, 3, 3u);
    { uint32_t addr = s->r[13] + 28u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    s->r[15] = 41948124u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_028013c2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 2u);
    s->r[15] = agr_aot_condition(s, 12u) ? 41948124u : 41948102u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_028013c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[13] + 29u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    agr_aot_lsls(s, 2, s->r[2], 16u);
    { uint32_t addr = s->r[13] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[3] = s->r[3] & 0xffu;
    agr_aot_movs_imm(s, 2, 2u);
    { uint32_t addr = s->r[13] + 28u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    s->r[15] = 41948120u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_028013dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[10], 2u);
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 80u); if (rc) return rc; }
    agr_aot_set_itstate(s, 8u); s->r[15] = 41948132u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280161c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 41948052u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801620(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 3, 1u);
    s->r[15] = 41948052u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801624(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 3, 2u);
    s->r[15] = 41948052u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801628(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16880u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    s->r[13] -= 264u;
    agr_aot_mov_reg(s, 7, 2);
    agr_aot_mov_reg(s, 5, 3);
    agr_aot_cmp(s, s->r[1], 4u);
    s->r[15] = agr_aot_condition(s, 8u) ? 41948976u : 41948728u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280163c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 3, s->r[0], s->r[0]);
    agr_aot_cmp(s, s->r[0], 122u);
    agr_aot_lsls(s, 2, s->r[2], 1u);
    agr_aot_cmp(s, s->r[5], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 41948976u : 41948742u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801646(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 56u); if (rc) return rc; }
    s->r[15] = 41948744u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280164a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = 41948748u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280164c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls_reg(s, 2, s->r[0], s->r[5]);
    s->r[15] = 41948752u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801652(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 41948766u : 41948756u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801654(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 41948758u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280165a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 3, s->r[3], 4u);
    { uint32_t addr = s->r[6] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 41948766u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280165e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 5, s->r[5], 1u);
    agr_aot_cmp(s, s->r[5], 16u);
    s->r[15] = agr_aot_condition(s, 1u) ? 41948748u : 41948772u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801668(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41949046u : 41948780u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280166c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 56u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 41949252u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801730(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    s->r[15] = 41949252u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801776(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = 41949252u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801844(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 264u;
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) return rc;
}

static int aot_fast_0280184c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 1, s->r[0], 52u);
    s->r[15] = 41949264u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801854(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 12, 3);
    agr_aot_mov_reg(s, 14, 4);
    { uint32_t addr = (s->r[12] - 4u); s->r[12] = s->r[12] - 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    s->r[15] = 41949276u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801860(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 13, 12);
    if ((rc = agr_aot_ldmia_sp(s, 32768u))) return rc;
}

static int aot_fast_02801868(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801870(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801878(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801880(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801888(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801890(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_028018d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801918(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280192c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801940(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801944(AgrAotRegs *s) {
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
    agr_aot_branch_reg(s, 41947576u | 1u, 41949534u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280195e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[13] += 72u;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801968(AgrAotRegs *s) {
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
    agr_aot_branch_reg(s, 41947694u | 1u, 41949570u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801982(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[13] += 72u;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0280198c(AgrAotRegs *s) {
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
    agr_aot_branch_reg(s, 41947760u | 1u, 41949606u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_028019a6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[13] += 72u;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_028019b0(AgrAotRegs *s) {
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
    agr_aot_branch_reg(s, 41947674u | 1u, 41949642u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_028019ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[13] += 72u;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_028019d4(AgrAotRegs *s) {
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
    agr_aot_branch_reg(s, 41947930u | 1u, 41949678u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_028019ee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[13] += 72u;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_028019f8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = s->r[3] ? 41949714u : 41949692u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_028019fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 9u); if (rc) return rc; }
    s->r[15] = !s->r[3] ? 41949728u : 41949696u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801a00(AgrAotRegs *s) {
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
    s->r[15] = 41949716u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801a12(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 3, s->r[3], 1u);
    s->r[15] = 41949716u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801a14(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[0] + 8u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_lsls(s, 2, s->r[3], 8u);
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 41949724u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801a1e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801a20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 176u);
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801a24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16415u)) return AGR_AOT_FAULT;
    agr_aot_movs_imm(s, 1, 0u);
    agr_aot_add_imm(s, 3, s->r[13], 12u);
    agr_aot_movs_imm(s, 2, 12u);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_mov_reg(s, 3, 1);
    agr_aot_branch_reg(s, 41947792u | 1u, 41949748u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801a34(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 12u); if (rc) return rc; }
    s->r[13] += 20u;
    { uint32_t addr = s->r[13]; s->r[13] = s->r[13] + 4u; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_02801a3c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 41949732u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801a3e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 18431u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 5, 0);
    agr_aot_mov_reg(s, 6, 1);
    agr_aot_movs_imm(s, 7, 0u);
    agr_aot_add_imm(s, 8, s->r[13], 12u);
    s->r[9] = 4080u;
    s->r[15] = 41949776u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801a50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 41949688u | 1u, 41949782u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801a56(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 176u);
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = agr_aot_condition(s, 1u) ? 41949826u : 41949788u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801a5c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[7], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 41950356u : 41949794u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801a62(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 4, s->r[13], 12u);
    agr_aot_mov_reg(s, 1, 7);
    agr_aot_mov_reg(s, 3, 7);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_movs_imm(s, 2, 14u);
    agr_aot_branch_reg(s, 41947792u | 1u, 41949810u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801a72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 1, 7);
    agr_aot_movs_imm(s, 2, 15u);
    agr_aot_mov_reg(s, 3, 7);
    agr_aot_branch_reg(s, 41947860u | 1u, 41949824u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801a80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 41950356u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801a8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41949880u : 41949836u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801a90(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 3, 1);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_movs_imm(s, 2, 13u);
    s->r[15] = 41949850u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801a9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 41947792u | 1u, 41949858u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801aa2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 12u); if (rc) return rc; }
    agr_aot_add_imm(s, 10, s->r[10], 4u);
    s->r[15] = 41949864u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801aac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_set_itstate(s, 20u); s->r[15] = 41949870u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801ab8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[3] = s->r[0] & 240u;
    agr_aot_cmp(s, s->r[3], 128u);
    s->r[15] = agr_aot_condition(s, 1u) ? 41949936u : 41949888u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801ac0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 4, s->r[0], 8u);
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 41949688u | 1u, 41949896u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801aca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 32768u);
    s->r[15] = agr_aot_condition(s, 1u) ? 41949908u : 41949904u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801ad0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 9u);
    s->r[15] = 41950358u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801ad4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 4, s->r[0], 4u);
    agr_aot_movs_imm(s, 1, 0u);
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = 41949916u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801ade(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 41948712u | 1u, 41949922u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801ae2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 41949904u : 41949926u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801aea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_set_itstate(s, 24u); s->r[15] = 41949932u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801af0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 144u);
    s->r[15] = agr_aot_condition(s, 1u) ? 41949984u : 41949940u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801af4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[3] = s->r[0] & 13u;
    agr_aot_cmp(s, s->r[3], 13u);
    s->r[15] = agr_aot_condition(s, 0u) ? 41949904u : 41949948u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801afc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    agr_aot_mov_reg(s, 0, 5);
    s->r[2] = s->r[4] & 15u;
    agr_aot_mov_reg(s, 3, 1);
    agr_aot_branch_reg(s, 41947792u | 1u, 41949966u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801b0e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_movs_imm(s, 1, 0u);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    s->r[15] = 41949974u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801b16(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 2, 13u);
    agr_aot_mov_reg(s, 3, 1);
    agr_aot_branch_reg(s, 41947860u | 1u, 41949982u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801b1e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 41949776u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801b20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 160u);
    s->r[15] = agr_aot_condition(s, 1u) ? 41950016u : 41949988u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801b26(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[2] = s->r[2] & 7u;
    s->r[15] = 41949994u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801b2e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 3, s->r[0], 28u);
    s->r[2] = s->r[2] & 4080u;
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_set_itstate(s, 72u); s->r[15] = 41950008u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801b40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 176u);
    s->r[15] = agr_aot_condition(s, 1u) ? 41950172u : 41950020u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801b44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 177u);
    s->r[15] = agr_aot_condition(s, 1u) ? 41950048u : 41950024u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801b48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 41949688u | 1u, 41950030u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801b4e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 2, 0);
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 41949904u : 41950036u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801b58(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41949904u : 41950042u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801b5a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 41950044u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801b5c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = 41950344u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801b60(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 178u);
    s->r[15] = agr_aot_condition(s, 1u) ? 41950122u : 41950052u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801b64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    agr_aot_movs_imm(s, 2, 13u);
    agr_aot_mov_reg(s, 3, 1);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_movs_imm(s, 4, 2u);
    agr_aot_branch_reg(s, 41947792u | 1u, 41950070u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801b76(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 41949688u | 1u, 41950076u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801b80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 12u); if (rc) return rc; }
    s->r[0] = s->r[0] & 127u;
    s->r[15] = agr_aot_condition(s, 0u) ? 41950104u : 41950088u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801b8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 4, s->r[4], 7u);
    s->r[3] += s->r[0];
    agr_aot_mov_reg(s, 0, 6);
    { uint32_t addr = s->r[13] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 41949688u | 1u, 41950102u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801b96(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 41950076u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801b98(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 3, s->r[3], 3841u);
    s->r[15] = 41950108u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801b9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[0] += s->r[3];
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    { uint32_t addr = s->r[13] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 41949974u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801baa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 179u);
    s->r[15] = agr_aot_condition(s, 1u) ? 41950148u : 41950126u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801bae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 41949688u | 1u, 41950132u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801bb4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 1, 1u);
    s->r[3] = s->r[0] & 15u;
    s->r[2] = s->r[0] & 240u;
    agr_aot_adds(s, 3, s->r[3], 1u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 41950200u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801bc4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[3] = s->r[0] & 252u;
    agr_aot_cmp(s, s->r[3], 180u);
    s->r[15] = agr_aot_condition(s, 0u) ? 41949904u : 41950156u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801bcc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[4] = s->r[0] & 7u;
    agr_aot_movs_imm(s, 1, 1u);
    agr_aot_adds(s, 2, s->r[4], 1u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[2] = s->r[2] | 524288u;
    s->r[15] = 41950044u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801bdc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 192u);
    s->r[15] = agr_aot_condition(s, 1u) ? 41950318u : 41950176u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801be0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 198u);
    s->r[15] = agr_aot_condition(s, 1u) ? 41950206u : 41950180u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801be4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 41949688u | 1u, 41950186u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801bea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 1, 3u);
    s->r[3] = s->r[0] & 15u;
    s->r[2] = s->r[0] & 240u;
    agr_aot_adds(s, 3, s->r[3], 1u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 41950200u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801bfc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 41950044u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801bfe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 199u);
    s->r[15] = agr_aot_condition(s, 1u) ? 41950238u : 41950210u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801c02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 41949688u | 1u, 41950216u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801c08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 2, 0);
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 41949904u : 41950224u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801c14(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 41949904u : 41950232u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801c18(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_movs_imm(s, 1, 4u);
    s->r[15] = 41950344u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801c1e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[3] = s->r[0] & 248u;
    agr_aot_cmp(s, s->r[3], 192u);
    s->r[15] = agr_aot_condition(s, 1u) ? 41950262u : 41950246u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801c26(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[4] = s->r[0] & 15u;
    agr_aot_movs_imm(s, 1, 3u);
    agr_aot_adds(s, 2, s->r[4], 1u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[2] = s->r[2] | 655360u;
    s->r[15] = 41950044u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801c36(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 200u);
    s->r[15] = agr_aot_condition(s, 1u) ? 41950286u : 41950266u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801c3a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 41949688u | 1u, 41950272u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801c40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[2] = s->r[0] & 240u;
    s->r[0] = s->r[0] & 15u;
    agr_aot_adds(s, 2, s->r[2], 16u);
    agr_aot_adds(s, 3, s->r[0], 1u);
    s->r[15] = 41950308u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801c4e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 201u);
    s->r[15] = agr_aot_condition(s, 1u) ? 41949904u : 41950292u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801c54(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 41949688u | 1u, 41950298u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801c5a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[3] = s->r[0] & 15u;
    s->r[2] = s->r[0] & 240u;
    agr_aot_adds(s, 3, s->r[3], 1u);
    s->r[15] = 41950308u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801c64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = 41950312u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801c6c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 41950342u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801c6e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[3] = s->r[0] & 248u;
    agr_aot_cmp(s, s->r[3], 208u);
    s->r[15] = agr_aot_condition(s, 1u) ? 41949904u : 41950328u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801c78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[4] = s->r[0] & 7u;
    agr_aot_movs_imm(s, 1, 1u);
    agr_aot_adds(s, 2, s->r[4], 1u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[2] = s->r[2] | 524288u;
    s->r[15] = 41950342u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801c86(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 3, 5u);
    s->r[15] = 41950344u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801c88(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 41948712u | 1u, 41950348u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801c8c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 41949904u : 41950354u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801c92(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 41949776u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801c94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = 41950358u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801c96(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 16u;
    if ((rc = agr_aot_ldmia_sp(s, 34800u))) return rc;
}

static int aot_fast_02801c9c(AgrAotRegs *s) {
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
    agr_aot_branch_reg(s, 41949758u | 1u, 41950400u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801cc0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 20u;
    { uint32_t addr = s->r[13]; s->r[13] = s->r[13] + 4u; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_02801cc6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    agr_aot_branch_reg(s, 41949756u | 1u, 41950412u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801ccc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 72u); if (rc) return rc; }
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) return rc;
}

static int aot_fast_02801cd0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    agr_aot_branch_reg(s, 41949756u | 1u, 41950422u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801cd6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 76u); if (rc) return rc; }
    { int rc = agr_aot_ldrb(s, 2, s->r[3] + 7u); if (rc) return rc; }
    s->r[15] = 41950426u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801cde(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 0, s->r[0], 8u);
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) return rc;
}

static int aot_fast_02801ce2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    agr_aot_branch_reg(s, 41946448u, 41950440u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_02801ce8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    agr_aot_branch_reg(s, 41946448u, 41950446u, 1); return AGR_AOT_BOUNDARY;
}

const AgrAotEntry agr_aot_debug_blocks[] = {
    {41946364u, aot_debug_02800cfc, 1u},
    {41946368u, aot_debug_02800d00, 1u},
    {41946372u, aot_debug_02800d04, 1u},
    {41946376u, aot_debug_02800d08, 1u},
    {41946380u, aot_debug_02800d0c, 1u},
    {41946384u, aot_debug_02800d10, 1u},
    {41946388u, aot_debug_02800d14, 1u},
    {41946392u, aot_debug_02800d18, 1u},
    {41946396u, aot_debug_02800d1c, 1u},
    {41946400u, aot_debug_02800d20, 1u},
    {41946404u, aot_debug_02800d24, 1u},
    {41946408u, aot_debug_02800d28, 1u},
    {41946412u, aot_debug_02800d2c, 1u},
    {41946416u, aot_debug_02800d30, 1u},
    {41946420u, aot_debug_02800d34, 1u},
    {41946424u, aot_debug_02800d38, 1u},
    {41946428u, aot_debug_02800d3c, 1u},
    {41946432u, aot_debug_02800d40, 1u},
    {41946436u, aot_debug_02800d44, 1u},
    {41946440u, aot_debug_02800d48, 1u},
    {41946444u, aot_debug_02800d4c, 1u},
    {41946448u, aot_debug_02800d50, 1u},
    {41946452u, aot_debug_02800d54, 1u},
    {41946456u, aot_debug_02800d58, 1u},
    {41946496u, aot_debug_02800d80, 1u},
    {41946500u, aot_debug_02800d84, 1u},
    {41946564u, aot_debug_02800dc4, 1u},
    {41946568u, aot_debug_02800dc8, 1u},
    {41946570u, aot_debug_02800dca, 1u},
    {41946572u, aot_debug_02800dcc, 1u},
    {41946574u, aot_debug_02800dce, 1u},
    {41946576u, aot_debug_02800dd0, 1u},
    {41946578u, aot_debug_02800dd2, 1u},
    {41946580u, aot_debug_02800dd4, 1u},
    {41946582u, aot_debug_02800dd6, 1u},
    {41946586u, aot_debug_02800dda, 1u},
    {41946588u, aot_debug_02800ddc, 1u},
    {41946590u, aot_debug_02800dde, 1u},
    {41946592u, aot_debug_02800de0, 1u},
    {41946594u, aot_debug_02800de2, 1u},
    {41946598u, aot_debug_02800de6, 1u},
    {41946600u, aot_debug_02800de8, 1u},
    {41946602u, aot_debug_02800dea, 1u},
    {41946604u, aot_debug_02800dec, 1u},
    {41946606u, aot_debug_02800dee, 1u},
    {41946608u, aot_debug_02800df0, 1u},
    {41946610u, aot_debug_02800df2, 1u},
    {41946612u, aot_debug_02800df4, 1u},
    {41946614u, aot_debug_02800df6, 1u},
    {41946616u, aot_debug_02800df8, 1u},
    {41946620u, aot_debug_02800dfc, 1u},
    {41946622u, aot_debug_02800dfe, 1u},
    {41946624u, aot_debug_02800e00, 1u},
    {41946626u, aot_debug_02800e02, 1u},
    {41946628u, aot_debug_02800e04, 1u},
    {41946630u, aot_debug_02800e06, 1u},
    {41946632u, aot_debug_02800e08, 1u},
    {41946634u, aot_debug_02800e0a, 1u},
    {41946636u, aot_debug_02800e0c, 1u},
    {41946640u, aot_debug_02800e10, 1u},
    {41946642u, aot_debug_02800e12, 1u},
    {41946646u, aot_debug_02800e16, 1u},
    {41946648u, aot_debug_02800e18, 1u},
    {41946650u, aot_debug_02800e1a, 1u},
    {41946652u, aot_debug_02800e1c, 1u},
    {41946654u, aot_debug_02800e1e, 1u},
    {41946658u, aot_debug_02800e22, 1u},
    {41946660u, aot_debug_02800e24, 1u},
    {41946664u, aot_debug_02800e28, 1u},
    {41946666u, aot_debug_02800e2a, 1u},
    {41946668u, aot_debug_02800e2c, 1u},
    {41946672u, aot_debug_02800e30, 1u},
    {41946674u, aot_debug_02800e32, 1u},
    {41946676u, aot_debug_02800e34, 1u},
    {41946680u, aot_debug_02800e38, 1u},
    {41946682u, aot_debug_02800e3a, 1u},
    {41946684u, aot_debug_02800e3c, 1u},
    {41946688u, aot_debug_02800e40, 1u},
    {41946690u, aot_debug_02800e42, 1u},
    {41946692u, aot_debug_02800e44, 1u},
    {41946696u, aot_debug_02800e48, 1u},
    {41946698u, aot_debug_02800e4a, 1u},
    {41946702u, aot_debug_02800e4e, 1u},
    {41946704u, aot_debug_02800e50, 1u},
    {41946706u, aot_debug_02800e52, 1u},
    {41946708u, aot_debug_02800e54, 1u},
    {41946710u, aot_debug_02800e56, 1u},
    {41946714u, aot_debug_02800e5a, 1u},
    {41946716u, aot_debug_02800e5c, 1u},
    {41946718u, aot_debug_02800e5e, 1u},
    {41946720u, aot_debug_02800e60, 1u},
    {41946722u, aot_debug_02800e62, 1u},
    {41946724u, aot_debug_02800e64, 1u},
    {41946726u, aot_debug_02800e66, 1u},
    {41946728u, aot_debug_02800e68, 1u},
    {41946732u, aot_debug_02800e6c, 1u},
    {41946734u, aot_debug_02800e6e, 1u},
    {41946736u, aot_debug_02800e70, 1u},
    {41946738u, aot_debug_02800e72, 1u},
    {41946740u, aot_debug_02800e74, 1u},
    {41946742u, aot_debug_02800e76, 1u},
    {41946744u, aot_debug_02800e78, 1u},
    {41946748u, aot_debug_02800e7c, 1u},
    {41946750u, aot_debug_02800e7e, 1u},
    {41946752u, aot_debug_02800e80, 1u},
    {41946754u, aot_debug_02800e82, 1u},
    {41946756u, aot_debug_02800e84, 1u},
    {41946758u, aot_debug_02800e86, 1u},
    {41946760u, aot_debug_02800e88, 1u},
    {41946764u, aot_debug_02800e8c, 1u},
    {41946766u, aot_debug_02800e8e, 1u},
    {41946768u, aot_debug_02800e90, 1u},
    {41946772u, aot_debug_02800e94, 1u},
    {41946776u, aot_debug_02800e98, 1u},
    {41946778u, aot_debug_02800e9a, 1u},
    {41946780u, aot_debug_02800e9c, 1u},
    {41946782u, aot_debug_02800e9e, 1u},
    {41946784u, aot_debug_02800ea0, 1u},
    {41946786u, aot_debug_02800ea2, 1u},
    {41946788u, aot_debug_02800ea4, 1u},
    {41946792u, aot_debug_02800ea8, 1u},
    {41946796u, aot_debug_02800eac, 1u},
    {41946798u, aot_debug_02800eae, 1u},
    {41946800u, aot_debug_02800eb0, 1u},
    {41946802u, aot_debug_02800eb2, 1u},
    {41946804u, aot_debug_02800eb4, 1u},
    {41946808u, aot_debug_02800eb8, 1u},
    {41946810u, aot_debug_02800eba, 1u},
    {41946812u, aot_debug_02800ebc, 1u},
    {41946814u, aot_debug_02800ebe, 1u},
    {41946816u, aot_debug_02800ec0, 1u},
    {41946818u, aot_debug_02800ec2, 1u},
    {41946820u, aot_debug_02800ec4, 1u},
    {41946822u, aot_debug_02800ec6, 1u},
    {41946824u, aot_debug_02800ec8, 1u},
    {41946828u, aot_debug_02800ecc, 1u},
    {41946830u, aot_debug_02800ece, 1u},
    {41946832u, aot_debug_02800ed0, 1u},
    {41946834u, aot_debug_02800ed2, 1u},
    {41946836u, aot_debug_02800ed4, 1u},
    {41946840u, aot_debug_02800ed8, 1u},
    {41946842u, aot_debug_02800eda, 1u},
    {41946844u, aot_debug_02800edc, 1u},
    {41946846u, aot_debug_02800ede, 1u},
    {41946850u, aot_debug_02800ee2, 1u},
    {41946852u, aot_debug_02800ee4, 1u},
    {41946854u, aot_debug_02800ee6, 1u},
    {41946856u, aot_debug_02800ee8, 1u},
    {41946858u, aot_debug_02800eea, 1u},
    {41946862u, aot_debug_02800eee, 1u},
    {41946864u, aot_debug_02800ef0, 1u},
    {41946866u, aot_debug_02800ef2, 1u},
    {41946868u, aot_debug_02800ef4, 1u},
    {41946870u, aot_debug_02800ef6, 1u},
    {41946872u, aot_debug_02800ef8, 1u},
    {41946874u, aot_debug_02800efa, 1u},
    {41946878u, aot_debug_02800efe, 1u},
    {41946880u, aot_debug_02800f00, 1u},
    {41946882u, aot_debug_02800f02, 1u},
    {41946888u, aot_debug_02800f08, 1u},
    {41946890u, aot_debug_02800f0a, 1u},
    {41946892u, aot_debug_02800f0c, 1u},
    {41946906u, aot_debug_02800f1a, 1u},
    {41946910u, aot_debug_02800f1e, 1u},
    {41946912u, aot_debug_02800f20, 1u},
    {41946914u, aot_debug_02800f22, 1u},
    {41946916u, aot_debug_02800f24, 1u},
    {41946920u, aot_debug_02800f28, 1u},
    {41946922u, aot_debug_02800f2a, 1u},
    {41946924u, aot_debug_02800f2c, 1u},
    {41946934u, aot_debug_02800f36, 1u},
    {41946936u, aot_debug_02800f38, 1u},
    {41946938u, aot_debug_02800f3a, 1u},
    {41946942u, aot_debug_02800f3e, 1u},
    {41946944u, aot_debug_02800f40, 1u},
    {41946948u, aot_debug_02800f44, 1u},
    {41946950u, aot_debug_02800f46, 1u},
    {41946952u, aot_debug_02800f48, 1u},
    {41946954u, aot_debug_02800f4a, 1u},
    {41946956u, aot_debug_02800f4c, 1u},
    {41946960u, aot_debug_02800f50, 1u},
    {41946962u, aot_debug_02800f52, 1u},
    {41946966u, aot_debug_02800f56, 1u},
    {41946968u, aot_debug_02800f58, 1u},
    {41946970u, aot_debug_02800f5a, 1u},
    {41946972u, aot_debug_02800f5c, 1u},
    {41946974u, aot_debug_02800f5e, 1u},
    {41946978u, aot_debug_02800f62, 1u},
    {41946980u, aot_debug_02800f64, 1u},
    {41946982u, aot_debug_02800f66, 1u},
    {41946984u, aot_debug_02800f68, 1u},
    {41946986u, aot_debug_02800f6a, 1u},
    {41946988u, aot_debug_02800f6c, 1u},
    {41946990u, aot_debug_02800f6e, 1u},
    {41946992u, aot_debug_02800f70, 1u},
    {41946994u, aot_debug_02800f72, 1u},
    {41946996u, aot_debug_02800f74, 1u},
    {41946998u, aot_debug_02800f76, 1u},
    {41947000u, aot_debug_02800f78, 1u},
    {41947002u, aot_debug_02800f7a, 1u},
    {41947004u, aot_debug_02800f7c, 1u},
    {41947006u, aot_debug_02800f7e, 1u},
    {41947010u, aot_debug_02800f82, 1u},
    {41947012u, aot_debug_02800f84, 1u},
    {41947014u, aot_debug_02800f86, 1u},
    {41947016u, aot_debug_02800f88, 1u},
    {41947018u, aot_debug_02800f8a, 1u},
    {41947020u, aot_debug_02800f8c, 1u},
    {41947022u, aot_debug_02800f8e, 1u},
    {41947024u, aot_debug_02800f90, 1u},
    {41947026u, aot_debug_02800f92, 1u},
    {41947028u, aot_debug_02800f94, 1u},
    {41947030u, aot_debug_02800f96, 1u},
    {41947032u, aot_debug_02800f98, 1u},
    {41947034u, aot_debug_02800f9a, 1u},
    {41947036u, aot_debug_02800f9c, 1u},
    {41947038u, aot_debug_02800f9e, 1u},
    {41947040u, aot_debug_02800fa0, 1u},
    {41947042u, aot_debug_02800fa2, 1u},
    {41947044u, aot_debug_02800fa4, 1u},
    {41947046u, aot_debug_02800fa6, 1u},
    {41947048u, aot_debug_02800fa8, 1u},
    {41947050u, aot_debug_02800faa, 1u},
    {41947052u, aot_debug_02800fac, 1u},
    {41947054u, aot_debug_02800fae, 1u},
    {41947056u, aot_debug_02800fb0, 1u},
    {41947058u, aot_debug_02800fb2, 1u},
    {41947060u, aot_debug_02800fb4, 1u},
    {41947062u, aot_debug_02800fb6, 1u},
    {41947064u, aot_debug_02800fb8, 1u},
    {41947066u, aot_debug_02800fba, 1u},
    {41947068u, aot_debug_02800fbc, 1u},
    {41947070u, aot_debug_02800fbe, 1u},
    {41947072u, aot_debug_02800fc0, 1u},
    {41947074u, aot_debug_02800fc2, 1u},
    {41947076u, aot_debug_02800fc4, 1u},
    {41947078u, aot_debug_02800fc6, 1u},
    {41947082u, aot_debug_02800fca, 1u},
    {41947084u, aot_debug_02800fcc, 1u},
    {41947086u, aot_debug_02800fce, 1u},
    {41947088u, aot_debug_02800fd0, 1u},
    {41947090u, aot_debug_02800fd2, 1u},
    {41947092u, aot_debug_02800fd4, 1u},
    {41947094u, aot_debug_02800fd6, 1u},
    {41947096u, aot_debug_02800fd8, 1u},
    {41947098u, aot_debug_02800fda, 1u},
    {41947100u, aot_debug_02800fdc, 1u},
    {41947102u, aot_debug_02800fde, 1u},
    {41947106u, aot_debug_02800fe2, 1u},
    {41947108u, aot_debug_02800fe4, 1u},
    {41947110u, aot_debug_02800fe6, 1u},
    {41947112u, aot_debug_02800fe8, 1u},
    {41947116u, aot_debug_02800fec, 1u},
    {41947118u, aot_debug_02800fee, 1u},
    {41947120u, aot_debug_02800ff0, 1u},
    {41947122u, aot_debug_02800ff2, 1u},
    {41947124u, aot_debug_02800ff4, 1u},
    {41947126u, aot_debug_02800ff6, 1u},
    {41947130u, aot_debug_02800ffa, 1u},
    {41947132u, aot_debug_02800ffc, 1u},
    {41947134u, aot_debug_02800ffe, 1u},
    {41947136u, aot_debug_02801000, 1u},
    {41947138u, aot_debug_02801002, 1u},
    {41947140u, aot_debug_02801004, 1u},
    {41947142u, aot_debug_02801006, 1u},
    {41947144u, aot_debug_02801008, 1u},
    {41947146u, aot_debug_0280100a, 1u},
    {41947148u, aot_debug_0280100c, 1u},
    {41947152u, aot_debug_02801010, 1u},
    {41947154u, aot_debug_02801012, 1u},
    {41947156u, aot_debug_02801014, 1u},
    {41947158u, aot_debug_02801016, 1u},
    {41947160u, aot_debug_02801018, 1u},
    {41947164u, aot_debug_0280101c, 1u},
    {41947166u, aot_debug_0280101e, 1u},
    {41947168u, aot_debug_02801020, 1u},
    {41947170u, aot_debug_02801022, 1u},
    {41947172u, aot_debug_02801024, 1u},
    {41947174u, aot_debug_02801026, 1u},
    {41947176u, aot_debug_02801028, 1u},
    {41947182u, aot_debug_0280102e, 1u},
    {41947186u, aot_debug_02801032, 1u},
    {41947188u, aot_debug_02801034, 1u},
    {41947190u, aot_debug_02801036, 1u},
    {41947198u, aot_debug_0280103e, 1u},
    {41947202u, aot_debug_02801042, 1u},
    {41947204u, aot_debug_02801044, 1u},
    {41947206u, aot_debug_02801046, 1u},
    {41947208u, aot_debug_02801048, 1u},
    {41947224u, aot_debug_02801058, 1u},
    {41947226u, aot_debug_0280105a, 1u},
    {41947228u, aot_debug_0280105c, 1u},
    {41947230u, aot_debug_0280105e, 1u},
    {41947232u, aot_debug_02801060, 1u},
    {41947238u, aot_debug_02801066, 1u},
    {41947242u, aot_debug_0280106a, 1u},
    {41947244u, aot_debug_0280106c, 1u},
    {41947248u, aot_debug_02801070, 1u},
    {41947250u, aot_debug_02801072, 1u},
    {41947254u, aot_debug_02801076, 1u},
    {41947256u, aot_debug_02801078, 1u},
    {41947258u, aot_debug_0280107a, 1u},
    {41947260u, aot_debug_0280107c, 1u},
    {41947264u, aot_debug_02801080, 1u},
    {41947268u, aot_debug_02801084, 1u},
    {41947270u, aot_debug_02801086, 1u},
    {41947272u, aot_debug_02801088, 1u},
    {41947274u, aot_debug_0280108a, 1u},
    {41947278u, aot_debug_0280108e, 1u},
    {41947282u, aot_debug_02801092, 1u},
    {41947284u, aot_debug_02801094, 1u},
    {41947286u, aot_debug_02801096, 1u},
    {41947288u, aot_debug_02801098, 1u},
    {41947292u, aot_debug_0280109c, 1u},
    {41947296u, aot_debug_028010a0, 1u},
    {41947300u, aot_debug_028010a4, 1u},
    {41947318u, aot_debug_028010b6, 1u},
    {41947320u, aot_debug_028010b8, 1u},
    {41947322u, aot_debug_028010ba, 1u},
    {41947324u, aot_debug_028010bc, 1u},
    {41947326u, aot_debug_028010be, 1u},
    {41947328u, aot_debug_028010c0, 1u},
    {41947330u, aot_debug_028010c2, 1u},
    {41947334u, aot_debug_028010c6, 1u},
    {41947336u, aot_debug_028010c8, 1u},
    {41947338u, aot_debug_028010ca, 1u},
    {41947342u, aot_debug_028010ce, 1u},
    {41947344u, aot_debug_028010d0, 1u},
    {41947346u, aot_debug_028010d2, 1u},
    {41947348u, aot_debug_028010d4, 1u},
    {41947350u, aot_debug_028010d6, 1u},
    {41947352u, aot_debug_028010d8, 1u},
    {41947354u, aot_debug_028010da, 1u},
    {41947356u, aot_debug_028010dc, 1u},
    {41947358u, aot_debug_028010de, 1u},
    {41947360u, aot_debug_028010e0, 1u},
    {41947362u, aot_debug_028010e2, 1u},
    {41947364u, aot_debug_028010e4, 1u},
    {41947366u, aot_debug_028010e6, 1u},
    {41947368u, aot_debug_028010e8, 1u},
    {41947372u, aot_debug_028010ec, 1u},
    {41947374u, aot_debug_028010ee, 1u},
    {41947378u, aot_debug_028010f2, 1u},
    {41947382u, aot_debug_028010f6, 1u},
    {41947384u, aot_debug_028010f8, 1u},
    {41947388u, aot_debug_028010fc, 1u},
    {41947390u, aot_debug_028010fe, 1u},
    {41947394u, aot_debug_02801102, 1u},
    {41947402u, aot_debug_0280110a, 1u},
    {41947404u, aot_debug_0280110c, 1u},
    {41947420u, aot_debug_0280111c, 1u},
    {41947422u, aot_debug_0280111e, 1u},
    {41947426u, aot_debug_02801122, 1u},
    {41947428u, aot_debug_02801124, 1u},
    {41947430u, aot_debug_02801126, 1u},
    {41947432u, aot_debug_02801128, 1u},
    {41947434u, aot_debug_0280112a, 1u},
    {41947436u, aot_debug_0280112c, 1u},
    {41947440u, aot_debug_02801130, 1u},
    {41947444u, aot_debug_02801134, 1u},
    {41947572u, aot_debug_028011b4, 1u},
    {41947574u, aot_debug_028011b6, 1u},
    {41947576u, aot_debug_028011b8, 1u},
    {41947578u, aot_debug_028011ba, 1u},
    {41947582u, aot_debug_028011be, 1u},
    {41947584u, aot_debug_028011c0, 1u},
    {41947586u, aot_debug_028011c2, 1u},
    {41947588u, aot_debug_028011c4, 1u},
    {41947590u, aot_debug_028011c6, 1u},
    {41947594u, aot_debug_028011ca, 1u},
    {41947596u, aot_debug_028011cc, 1u},
    {41947612u, aot_debug_028011dc, 1u},
    {41947616u, aot_debug_028011e0, 1u},
    {41947620u, aot_debug_028011e4, 1u},
    {41947622u, aot_debug_028011e6, 1u},
    {41947624u, aot_debug_028011e8, 1u},
    {41947628u, aot_debug_028011ec, 1u},
    {41947632u, aot_debug_028011f0, 1u},
    {41947634u, aot_debug_028011f2, 1u},
    {41947636u, aot_debug_028011f4, 1u},
    {41947638u, aot_debug_028011f6, 1u},
    {41947640u, aot_debug_028011f8, 1u},
    {41947642u, aot_debug_028011fa, 1u},
    {41947644u, aot_debug_028011fc, 1u},
    {41947646u, aot_debug_028011fe, 1u},
    {41947648u, aot_debug_02801200, 1u},
    {41947650u, aot_debug_02801202, 1u},
    {41947654u, aot_debug_02801206, 1u},
    {41947656u, aot_debug_02801208, 1u},
    {41947658u, aot_debug_0280120a, 1u},
    {41947660u, aot_debug_0280120c, 1u},
    {41947662u, aot_debug_0280120e, 1u},
    {41947666u, aot_debug_02801212, 1u},
    {41947668u, aot_debug_02801214, 1u},
    {41947670u, aot_debug_02801216, 1u},
    {41947674u, aot_debug_0280121a, 1u},
    {41947676u, aot_debug_0280121c, 1u},
    {41947678u, aot_debug_0280121e, 1u},
    {41947680u, aot_debug_02801220, 1u},
    {41947682u, aot_debug_02801222, 1u},
    {41947684u, aot_debug_02801224, 1u},
    {41947688u, aot_debug_02801228, 1u},
    {41947690u, aot_debug_0280122a, 1u},
    {41947692u, aot_debug_0280122c, 1u},
    {41947694u, aot_debug_0280122e, 1u},
    {41947696u, aot_debug_02801230, 1u},
    {41947698u, aot_debug_02801232, 1u},
    {41947700u, aot_debug_02801234, 1u},
    {41947702u, aot_debug_02801236, 1u},
    {41947704u, aot_debug_02801238, 1u},
    {41947706u, aot_debug_0280123a, 1u},
    {41947708u, aot_debug_0280123c, 1u},
    {41947710u, aot_debug_0280123e, 1u},
    {41947714u, aot_debug_02801242, 1u},
    {41947716u, aot_debug_02801244, 1u},
    {41947718u, aot_debug_02801246, 1u},
    {41947720u, aot_debug_02801248, 1u},
    {41947722u, aot_debug_0280124a, 1u},
    {41947724u, aot_debug_0280124c, 1u},
    {41947726u, aot_debug_0280124e, 1u},
    {41947728u, aot_debug_02801250, 1u},
    {41947730u, aot_debug_02801252, 1u},
    {41947732u, aot_debug_02801254, 1u},
    {41947734u, aot_debug_02801256, 1u},
    {41947736u, aot_debug_02801258, 1u},
    {41947738u, aot_debug_0280125a, 1u},
    {41947742u, aot_debug_0280125e, 1u},
    {41947744u, aot_debug_02801260, 1u},
    {41947746u, aot_debug_02801262, 1u},
    {41947750u, aot_debug_02801266, 1u},
    {41947752u, aot_debug_02801268, 1u},
    {41947756u, aot_debug_0280126c, 1u},
    {41947760u, aot_debug_02801270, 1u},
    {41947762u, aot_debug_02801272, 1u},
    {41947764u, aot_debug_02801274, 1u},
    {41947768u, aot_debug_02801278, 1u},
    {41947770u, aot_debug_0280127a, 1u},
    {41947772u, aot_debug_0280127c, 1u},
    {41947774u, aot_debug_0280127e, 1u},
    {41947776u, aot_debug_02801280, 1u},
    {41947778u, aot_debug_02801282, 1u},
    {41947780u, aot_debug_02801284, 1u},
    {41947782u, aot_debug_02801286, 1u},
    {41947784u, aot_debug_02801288, 1u},
    {41947786u, aot_debug_0280128a, 1u},
    {41947788u, aot_debug_0280128c, 1u},
    {41947790u, aot_debug_0280128e, 1u},
    {41947792u, aot_debug_02801290, 1u},
    {41947794u, aot_debug_02801292, 1u},
    {41947796u, aot_debug_02801294, 1u},
    {41947802u, aot_debug_0280129a, 1u},
    {41947804u, aot_debug_0280129c, 1u},
    {41947806u, aot_debug_0280129e, 1u},
    {41947808u, aot_debug_028012a0, 1u},
    {41947810u, aot_debug_028012a2, 1u},
    {41947832u, aot_debug_028012b8, 1u},
    {41947834u, aot_debug_028012ba, 1u},
    {41947860u, aot_debug_028012d4, 1u},
    {41947862u, aot_debug_028012d6, 1u},
    {41947864u, aot_debug_028012d8, 1u},
    {41947870u, aot_debug_028012de, 1u},
    {41947872u, aot_debug_028012e0, 1u},
    {41947874u, aot_debug_028012e2, 1u},
    {41947876u, aot_debug_028012e4, 1u},
    {41947878u, aot_debug_028012e6, 1u},
    {41947900u, aot_debug_028012fc, 1u},
    {41947902u, aot_debug_028012fe, 1u},
    {41947904u, aot_debug_02801300, 1u},
    {41947906u, aot_debug_02801302, 1u},
    {41947908u, aot_debug_02801304, 1u},
    {41947910u, aot_debug_02801306, 1u},
    {41947912u, aot_debug_02801308, 1u},
    {41947916u, aot_debug_0280130c, 1u},
    {41947918u, aot_debug_0280130e, 1u},
    {41947920u, aot_debug_02801310, 1u},
    {41947922u, aot_debug_02801312, 1u},
    {41947926u, aot_debug_02801316, 1u},
    {41947928u, aot_debug_02801318, 1u},
    {41947930u, aot_debug_0280131a, 1u},
    {41947932u, aot_debug_0280131c, 1u},
    {41947936u, aot_debug_02801320, 1u},
    {41947938u, aot_debug_02801322, 1u},
    {41947940u, aot_debug_02801324, 1u},
    {41947942u, aot_debug_02801326, 1u},
    {41947950u, aot_debug_0280132e, 1u},
    {41947952u, aot_debug_02801330, 1u},
    {41947968u, aot_debug_02801340, 1u},
    {41947972u, aot_debug_02801344, 1u},
    {41947974u, aot_debug_02801346, 1u},
    {41947978u, aot_debug_0280134a, 1u},
    {41947980u, aot_debug_0280134c, 1u},
    {41947982u, aot_debug_0280134e, 1u},
    {41947984u, aot_debug_02801350, 1u},
    {41947988u, aot_debug_02801354, 1u},
    {41947990u, aot_debug_02801356, 1u},
    {41947992u, aot_debug_02801358, 1u},
    {41947994u, aot_debug_0280135a, 1u},
    {41947996u, aot_debug_0280135c, 1u},
    {41947998u, aot_debug_0280135e, 1u},
    {41948000u, aot_debug_02801360, 1u},
    {41948004u, aot_debug_02801364, 1u},
    {41948006u, aot_debug_02801366, 1u},
    {41948008u, aot_debug_02801368, 1u},
    {41948010u, aot_debug_0280136a, 1u},
    {41948012u, aot_debug_0280136c, 1u},
    {41948014u, aot_debug_0280136e, 1u},
    {41948016u, aot_debug_02801370, 1u},
    {41948018u, aot_debug_02801372, 1u},
    {41948020u, aot_debug_02801374, 1u},
    {41948022u, aot_debug_02801376, 1u},
    {41948024u, aot_debug_02801378, 1u},
    {41948026u, aot_debug_0280137a, 1u},
    {41948028u, aot_debug_0280137c, 1u},
    {41948030u, aot_debug_0280137e, 1u},
    {41948032u, aot_debug_02801380, 1u},
    {41948034u, aot_debug_02801382, 1u},
    {41948036u, aot_debug_02801384, 1u},
    {41948038u, aot_debug_02801386, 1u},
    {41948042u, aot_debug_0280138a, 1u},
    {41948044u, aot_debug_0280138c, 1u},
    {41948048u, aot_debug_02801390, 1u},
    {41948052u, aot_debug_02801394, 1u},
    {41948056u, aot_debug_02801398, 1u},
    {41948058u, aot_debug_0280139a, 1u},
    {41948060u, aot_debug_0280139c, 1u},
    {41948062u, aot_debug_0280139e, 1u},
    {41948064u, aot_debug_028013a0, 1u},
    {41948066u, aot_debug_028013a2, 1u},
    {41948068u, aot_debug_028013a4, 1u},
    {41948072u, aot_debug_028013a8, 1u},
    {41948074u, aot_debug_028013aa, 1u},
    {41948076u, aot_debug_028013ac, 1u},
    {41948078u, aot_debug_028013ae, 1u},
    {41948080u, aot_debug_028013b0, 1u},
    {41948082u, aot_debug_028013b2, 1u},
    {41948084u, aot_debug_028013b4, 1u},
    {41948088u, aot_debug_028013b8, 1u},
    {41948090u, aot_debug_028013ba, 1u},
    {41948092u, aot_debug_028013bc, 1u},
    {41948096u, aot_debug_028013c0, 1u},
    {41948098u, aot_debug_028013c2, 1u},
    {41948100u, aot_debug_028013c4, 1u},
    {41948104u, aot_debug_028013c8, 1u},
    {41948108u, aot_debug_028013cc, 1u},
    {41948110u, aot_debug_028013ce, 1u},
    {41948112u, aot_debug_028013d0, 1u},
    {41948114u, aot_debug_028013d2, 1u},
    {41948116u, aot_debug_028013d4, 1u},
    {41948124u, aot_debug_028013dc, 1u},
    {41948128u, aot_debug_028013e0, 1u},
    {41948130u, aot_debug_028013e2, 1u},
    {41948700u, aot_debug_0280161c, 1u},
    {41948702u, aot_debug_0280161e, 1u},
    {41948704u, aot_debug_02801620, 1u},
    {41948706u, aot_debug_02801622, 1u},
    {41948708u, aot_debug_02801624, 1u},
    {41948710u, aot_debug_02801626, 1u},
    {41948712u, aot_debug_02801628, 1u},
    {41948716u, aot_debug_0280162c, 1u},
    {41948718u, aot_debug_0280162e, 1u},
    {41948720u, aot_debug_02801630, 1u},
    {41948722u, aot_debug_02801632, 1u},
    {41948724u, aot_debug_02801634, 1u},
    {41948726u, aot_debug_02801636, 1u},
    {41948732u, aot_debug_0280163c, 1u},
    {41948734u, aot_debug_0280163e, 1u},
    {41948736u, aot_debug_02801640, 1u},
    {41948738u, aot_debug_02801642, 1u},
    {41948740u, aot_debug_02801644, 1u},
    {41948742u, aot_debug_02801646, 1u},
    {41948746u, aot_debug_0280164a, 1u},
    {41948748u, aot_debug_0280164c, 1u},
    {41948754u, aot_debug_02801652, 1u},
    {41948756u, aot_debug_02801654, 1u},
    {41948762u, aot_debug_0280165a, 1u},
    {41948764u, aot_debug_0280165c, 1u},
    {41948766u, aot_debug_0280165e, 1u},
    {41948768u, aot_debug_02801660, 1u},
    {41948770u, aot_debug_02801662, 1u},
    {41948776u, aot_debug_02801668, 1u},
    {41948780u, aot_debug_0280166c, 1u},
    {41948782u, aot_debug_0280166e, 1u},
    {41948976u, aot_debug_02801730, 1u},
    {41948978u, aot_debug_02801732, 1u},
    {41949046u, aot_debug_02801776, 1u},
    {41949048u, aot_debug_02801778, 1u},
    {41949252u, aot_debug_02801844, 1u},
    {41949254u, aot_debug_02801846, 1u},
    {41949260u, aot_debug_0280184c, 1u},
    {41949268u, aot_debug_02801854, 1u},
    {41949270u, aot_debug_02801856, 1u},
    {41949272u, aot_debug_02801858, 1u},
    {41949280u, aot_debug_02801860, 1u},
    {41949282u, aot_debug_02801862, 1u},
    {41949288u, aot_debug_02801868, 1u},
    {41949296u, aot_debug_02801870, 1u},
    {41949304u, aot_debug_02801878, 1u},
    {41949312u, aot_debug_02801880, 1u},
    {41949320u, aot_debug_02801888, 1u},
    {41949328u, aot_debug_02801890, 1u},
    {41949396u, aot_debug_028018d4, 1u},
    {41949464u, aot_debug_02801918, 1u},
    {41949484u, aot_debug_0280192c, 1u},
    {41949504u, aot_debug_02801940, 1u},
    {41949508u, aot_debug_02801944, 1u},
    {41949510u, aot_debug_02801946, 1u},
    {41949512u, aot_debug_02801948, 1u},
    {41949516u, aot_debug_0280194c, 1u},
    {41949520u, aot_debug_02801950, 1u},
    {41949524u, aot_debug_02801954, 1u},
    {41949528u, aot_debug_02801958, 1u},
    {41949530u, aot_debug_0280195a, 1u},
    {41949534u, aot_debug_0280195e, 1u},
    {41949538u, aot_debug_02801962, 1u},
    {41949540u, aot_debug_02801964, 1u},
    {41949544u, aot_debug_02801968, 1u},
    {41949546u, aot_debug_0280196a, 1u},
    {41949548u, aot_debug_0280196c, 1u},
    {41949552u, aot_debug_02801970, 1u},
    {41949556u, aot_debug_02801974, 1u},
    {41949560u, aot_debug_02801978, 1u},
    {41949564u, aot_debug_0280197c, 1u},
    {41949566u, aot_debug_0280197e, 1u},
    {41949570u, aot_debug_02801982, 1u},
    {41949574u, aot_debug_02801986, 1u},
    {41949576u, aot_debug_02801988, 1u},
    {41949580u, aot_debug_0280198c, 1u},
    {41949582u, aot_debug_0280198e, 1u},
    {41949584u, aot_debug_02801990, 1u},
    {41949588u, aot_debug_02801994, 1u},
    {41949592u, aot_debug_02801998, 1u},
    {41949596u, aot_debug_0280199c, 1u},
    {41949600u, aot_debug_028019a0, 1u},
    {41949602u, aot_debug_028019a2, 1u},
    {41949606u, aot_debug_028019a6, 1u},
    {41949610u, aot_debug_028019aa, 1u},
    {41949612u, aot_debug_028019ac, 1u},
    {41949616u, aot_debug_028019b0, 1u},
    {41949618u, aot_debug_028019b2, 1u},
    {41949620u, aot_debug_028019b4, 1u},
    {41949624u, aot_debug_028019b8, 1u},
    {41949628u, aot_debug_028019bc, 1u},
    {41949632u, aot_debug_028019c0, 1u},
    {41949636u, aot_debug_028019c4, 1u},
    {41949638u, aot_debug_028019c6, 1u},
    {41949642u, aot_debug_028019ca, 1u},
    {41949646u, aot_debug_028019ce, 1u},
    {41949648u, aot_debug_028019d0, 1u},
    {41949652u, aot_debug_028019d4, 1u},
    {41949654u, aot_debug_028019d6, 1u},
    {41949656u, aot_debug_028019d8, 1u},
    {41949660u, aot_debug_028019dc, 1u},
    {41949664u, aot_debug_028019e0, 1u},
    {41949668u, aot_debug_028019e4, 1u},
    {41949672u, aot_debug_028019e8, 1u},
    {41949674u, aot_debug_028019ea, 1u},
    {41949678u, aot_debug_028019ee, 1u},
    {41949682u, aot_debug_028019f2, 1u},
    {41949684u, aot_debug_028019f4, 1u},
    {41949688u, aot_debug_028019f8, 1u},
    {41949690u, aot_debug_028019fa, 1u},
    {41949692u, aot_debug_028019fc, 1u},
    {41949694u, aot_debug_028019fe, 1u},
    {41949696u, aot_debug_02801a00, 1u},
    {41949698u, aot_debug_02801a02, 1u},
    {41949700u, aot_debug_02801a04, 1u},
    {41949702u, aot_debug_02801a06, 1u},
    {41949704u, aot_debug_02801a08, 1u},
    {41949706u, aot_debug_02801a0a, 1u},
    {41949708u, aot_debug_02801a0c, 1u},
    {41949710u, aot_debug_02801a0e, 1u},
    {41949712u, aot_debug_02801a10, 1u},
    {41949714u, aot_debug_02801a12, 1u},
    {41949716u, aot_debug_02801a14, 1u},
    {41949718u, aot_debug_02801a16, 1u},
    {41949720u, aot_debug_02801a18, 1u},
    {41949722u, aot_debug_02801a1a, 1u},
    {41949726u, aot_debug_02801a1e, 1u},
    {41949728u, aot_debug_02801a20, 1u},
    {41949730u, aot_debug_02801a22, 1u},
    {41949732u, aot_debug_02801a24, 1u},
    {41949734u, aot_debug_02801a26, 1u},
    {41949736u, aot_debug_02801a28, 1u},
    {41949738u, aot_debug_02801a2a, 1u},
    {41949740u, aot_debug_02801a2c, 1u},
    {41949742u, aot_debug_02801a2e, 1u},
    {41949744u, aot_debug_02801a30, 1u},
    {41949748u, aot_debug_02801a34, 1u},
    {41949750u, aot_debug_02801a36, 1u},
    {41949752u, aot_debug_02801a38, 1u},
    {41949756u, aot_debug_02801a3c, 1u},
    {41949758u, aot_debug_02801a3e, 1u},
    {41949762u, aot_debug_02801a42, 1u},
    {41949764u, aot_debug_02801a44, 1u},
    {41949766u, aot_debug_02801a46, 1u},
    {41949768u, aot_debug_02801a48, 1u},
    {41949772u, aot_debug_02801a4c, 1u},
    {41949776u, aot_debug_02801a50, 1u},
    {41949778u, aot_debug_02801a52, 1u},
    {41949782u, aot_debug_02801a56, 1u},
    {41949784u, aot_debug_02801a58, 1u},
    {41949786u, aot_debug_02801a5a, 1u},
    {41949788u, aot_debug_02801a5c, 1u},
    {41949790u, aot_debug_02801a5e, 1u},
    {41949794u, aot_debug_02801a62, 1u},
    {41949796u, aot_debug_02801a64, 1u},
    {41949798u, aot_debug_02801a66, 1u},
    {41949800u, aot_debug_02801a68, 1u},
    {41949802u, aot_debug_02801a6a, 1u},
    {41949804u, aot_debug_02801a6c, 1u},
    {41949806u, aot_debug_02801a6e, 1u},
    {41949810u, aot_debug_02801a72, 1u},
    {41949812u, aot_debug_02801a74, 1u},
    {41949814u, aot_debug_02801a76, 1u},
    {41949816u, aot_debug_02801a78, 1u},
    {41949818u, aot_debug_02801a7a, 1u},
    {41949820u, aot_debug_02801a7c, 1u},
    {41949824u, aot_debug_02801a80, 1u},
    {41949834u, aot_debug_02801a8a, 1u},
    {41949840u, aot_debug_02801a90, 1u},
    {41949842u, aot_debug_02801a92, 1u},
    {41949846u, aot_debug_02801a96, 1u},
    {41949848u, aot_debug_02801a98, 1u},
    {41949854u, aot_debug_02801a9e, 1u},
    {41949858u, aot_debug_02801aa2, 1u},
    {41949860u, aot_debug_02801aa4, 1u},
    {41949868u, aot_debug_02801aac, 1u},
    {41949880u, aot_debug_02801ab8, 1u},
    {41949884u, aot_debug_02801abc, 1u},
    {41949886u, aot_debug_02801abe, 1u},
    {41949888u, aot_debug_02801ac0, 1u},
    {41949890u, aot_debug_02801ac2, 1u},
    {41949892u, aot_debug_02801ac4, 1u},
    {41949898u, aot_debug_02801aca, 1u},
    {41949902u, aot_debug_02801ace, 1u},
    {41949904u, aot_debug_02801ad0, 1u},
    {41949906u, aot_debug_02801ad2, 1u},
    {41949908u, aot_debug_02801ad4, 1u},
    {41949910u, aot_debug_02801ad6, 1u},
    {41949912u, aot_debug_02801ad8, 1u},
    {41949914u, aot_debug_02801ada, 1u},
    {41949918u, aot_debug_02801ade, 1u},
    {41949922u, aot_debug_02801ae2, 1u},
    {41949924u, aot_debug_02801ae4, 1u},
    {41949930u, aot_debug_02801aea, 1u},
    {41949936u, aot_debug_02801af0, 1u},
    {41949938u, aot_debug_02801af2, 1u},
    {41949940u, aot_debug_02801af4, 1u},
    {41949944u, aot_debug_02801af8, 1u},
    {41949946u, aot_debug_02801afa, 1u},
    {41949948u, aot_debug_02801afc, 1u},
    {41949950u, aot_debug_02801afe, 1u},
    {41949954u, aot_debug_02801b02, 1u},
    {41949956u, aot_debug_02801b04, 1u},
    {41949960u, aot_debug_02801b08, 1u},
    {41949962u, aot_debug_02801b0a, 1u},
    {41949966u, aot_debug_02801b0e, 1u},
    {41949968u, aot_debug_02801b10, 1u},
    {41949970u, aot_debug_02801b12, 1u},
    {41949974u, aot_debug_02801b16, 1u},
    {41949976u, aot_debug_02801b18, 1u},
    {41949978u, aot_debug_02801b1a, 1u},
    {41949982u, aot_debug_02801b1e, 1u},
    {41949984u, aot_debug_02801b20, 1u},
    {41949986u, aot_debug_02801b22, 1u},
    {41949990u, aot_debug_02801b26, 1u},
    {41949998u, aot_debug_02801b2e, 1u},
    {41950000u, aot_debug_02801b30, 1u},
    {41950004u, aot_debug_02801b34, 1u},
    {41950006u, aot_debug_02801b36, 1u},
    {41950016u, aot_debug_02801b40, 1u},
    {41950018u, aot_debug_02801b42, 1u},
    {41950020u, aot_debug_02801b44, 1u},
    {41950022u, aot_debug_02801b46, 1u},
    {41950024u, aot_debug_02801b48, 1u},
    {41950026u, aot_debug_02801b4a, 1u},
    {41950030u, aot_debug_02801b4e, 1u},
    {41950032u, aot_debug_02801b50, 1u},
    {41950034u, aot_debug_02801b52, 1u},
    {41950040u, aot_debug_02801b58, 1u},
    {41950042u, aot_debug_02801b5a, 1u},
    {41950044u, aot_debug_02801b5c, 1u},
    {41950046u, aot_debug_02801b5e, 1u},
    {41950048u, aot_debug_02801b60, 1u},
    {41950050u, aot_debug_02801b62, 1u},
    {41950052u, aot_debug_02801b64, 1u},
    {41950054u, aot_debug_02801b66, 1u},
    {41950056u, aot_debug_02801b68, 1u},
    {41950058u, aot_debug_02801b6a, 1u},
    {41950062u, aot_debug_02801b6e, 1u},
    {41950064u, aot_debug_02801b70, 1u},
    {41950066u, aot_debug_02801b72, 1u},
    {41950070u, aot_debug_02801b76, 1u},
    {41950072u, aot_debug_02801b78, 1u},
    {41950080u, aot_debug_02801b80, 1u},
    {41950082u, aot_debug_02801b82, 1u},
    {41950086u, aot_debug_02801b86, 1u},
    {41950090u, aot_debug_02801b8a, 1u},
    {41950092u, aot_debug_02801b8c, 1u},
    {41950094u, aot_debug_02801b8e, 1u},
    {41950096u, aot_debug_02801b90, 1u},
    {41950098u, aot_debug_02801b92, 1u},
    {41950102u, aot_debug_02801b96, 1u},
    {41950104u, aot_debug_02801b98, 1u},
    {41950110u, aot_debug_02801b9e, 1u},
    {41950112u, aot_debug_02801ba0, 1u},
    {41950116u, aot_debug_02801ba4, 1u},
    {41950118u, aot_debug_02801ba6, 1u},
    {41950120u, aot_debug_02801ba8, 1u},
    {41950122u, aot_debug_02801baa, 1u},
    {41950124u, aot_debug_02801bac, 1u},
    {41950126u, aot_debug_02801bae, 1u},
    {41950128u, aot_debug_02801bb0, 1u},
    {41950132u, aot_debug_02801bb4, 1u},
    {41950134u, aot_debug_02801bb6, 1u},
    {41950138u, aot_debug_02801bba, 1u},
    {41950142u, aot_debug_02801bbe, 1u},
    {41950144u, aot_debug_02801bc0, 1u},
    {41950146u, aot_debug_02801bc2, 1u},
    {41950148u, aot_debug_02801bc4, 1u},
    {41950152u, aot_debug_02801bc8, 1u},
    {41950154u, aot_debug_02801bca, 1u},
    {41950156u, aot_debug_02801bcc, 1u},
    {41950160u, aot_debug_02801bd0, 1u},
    {41950162u, aot_debug_02801bd2, 1u},
    {41950164u, aot_debug_02801bd4, 1u},
    {41950166u, aot_debug_02801bd6, 1u},
    {41950170u, aot_debug_02801bda, 1u},
    {41950172u, aot_debug_02801bdc, 1u},
    {41950174u, aot_debug_02801bde, 1u},
    {41950176u, aot_debug_02801be0, 1u},
    {41950178u, aot_debug_02801be2, 1u},
    {41950180u, aot_debug_02801be4, 1u},
    {41950182u, aot_debug_02801be6, 1u},
    {41950186u, aot_debug_02801bea, 1u},
    {41950188u, aot_debug_02801bec, 1u},
    {41950192u, aot_debug_02801bf0, 1u},
    {41950196u, aot_debug_02801bf4, 1u},
    {41950198u, aot_debug_02801bf6, 1u},
    {41950204u, aot_debug_02801bfc, 1u},
    {41950206u, aot_debug_02801bfe, 1u},
    {41950208u, aot_debug_02801c00, 1u},
    {41950210u, aot_debug_02801c02, 1u},
    {41950212u, aot_debug_02801c04, 1u},
    {41950216u, aot_debug_02801c08, 1u},
    {41950218u, aot_debug_02801c0a, 1u},
    {41950220u, aot_debug_02801c0c, 1u},
    {41950228u, aot_debug_02801c14, 1u},
    {41950232u, aot_debug_02801c18, 1u},
    {41950234u, aot_debug_02801c1a, 1u},
    {41950236u, aot_debug_02801c1c, 1u},
    {41950238u, aot_debug_02801c1e, 1u},
    {41950242u, aot_debug_02801c22, 1u},
    {41950244u, aot_debug_02801c24, 1u},
    {41950246u, aot_debug_02801c26, 1u},
    {41950250u, aot_debug_02801c2a, 1u},
    {41950252u, aot_debug_02801c2c, 1u},
    {41950254u, aot_debug_02801c2e, 1u},
    {41950256u, aot_debug_02801c30, 1u},
    {41950260u, aot_debug_02801c34, 1u},
    {41950262u, aot_debug_02801c36, 1u},
    {41950264u, aot_debug_02801c38, 1u},
    {41950266u, aot_debug_02801c3a, 1u},
    {41950268u, aot_debug_02801c3c, 1u},
    {41950272u, aot_debug_02801c40, 1u},
    {41950276u, aot_debug_02801c44, 1u},
    {41950280u, aot_debug_02801c48, 1u},
    {41950282u, aot_debug_02801c4a, 1u},
    {41950284u, aot_debug_02801c4c, 1u},
    {41950286u, aot_debug_02801c4e, 1u},
    {41950288u, aot_debug_02801c50, 1u},
    {41950292u, aot_debug_02801c54, 1u},
    {41950294u, aot_debug_02801c56, 1u},
    {41950298u, aot_debug_02801c5a, 1u},
    {41950302u, aot_debug_02801c5e, 1u},
    {41950306u, aot_debug_02801c62, 1u},
    {41950308u, aot_debug_02801c64, 1u},
    {41950310u, aot_debug_02801c66, 1u},
    {41950316u, aot_debug_02801c6c, 1u},
    {41950318u, aot_debug_02801c6e, 1u},
    {41950322u, aot_debug_02801c72, 1u},
    {41950324u, aot_debug_02801c74, 1u},
    {41950328u, aot_debug_02801c78, 1u},
    {41950332u, aot_debug_02801c7c, 1u},
    {41950334u, aot_debug_02801c7e, 1u},
    {41950336u, aot_debug_02801c80, 1u},
    {41950338u, aot_debug_02801c82, 1u},
    {41950342u, aot_debug_02801c86, 1u},
    {41950344u, aot_debug_02801c88, 1u},
    {41950348u, aot_debug_02801c8c, 1u},
    {41950350u, aot_debug_02801c8e, 1u},
    {41950354u, aot_debug_02801c92, 1u},
    {41950356u, aot_debug_02801c94, 1u},
    {41950358u, aot_debug_02801c96, 1u},
    {41950360u, aot_debug_02801c98, 1u},
    {41950364u, aot_debug_02801c9c, 1u},
    {41950366u, aot_debug_02801c9e, 1u},
    {41950368u, aot_debug_02801ca0, 1u},
    {41950370u, aot_debug_02801ca2, 1u},
    {41950372u, aot_debug_02801ca4, 1u},
    {41950374u, aot_debug_02801ca6, 1u},
    {41950376u, aot_debug_02801ca8, 1u},
    {41950378u, aot_debug_02801caa, 1u},
    {41950382u, aot_debug_02801cae, 1u},
    {41950384u, aot_debug_02801cb0, 1u},
    {41950386u, aot_debug_02801cb2, 1u},
    {41950390u, aot_debug_02801cb6, 1u},
    {41950392u, aot_debug_02801cb8, 1u},
    {41950396u, aot_debug_02801cbc, 1u},
    {41950400u, aot_debug_02801cc0, 1u},
    {41950402u, aot_debug_02801cc2, 1u},
    {41950406u, aot_debug_02801cc6, 1u},
    {41950408u, aot_debug_02801cc8, 1u},
    {41950412u, aot_debug_02801ccc, 1u},
    {41950414u, aot_debug_02801cce, 1u},
    {41950416u, aot_debug_02801cd0, 1u},
    {41950418u, aot_debug_02801cd2, 1u},
    {41950422u, aot_debug_02801cd6, 1u},
    {41950424u, aot_debug_02801cd8, 1u},
    {41950430u, aot_debug_02801cde, 1u},
    {41950432u, aot_debug_02801ce0, 1u},
    {41950434u, aot_debug_02801ce2, 1u},
    {41950436u, aot_debug_02801ce4, 1u},
    {41950440u, aot_debug_02801ce8, 1u},
    {41950442u, aot_debug_02801cea, 1u},
};
const uint32_t agr_aot_debug_block_count = 925u;

const AgrAotEntry agr_aot_fast_blocks[] = {
    {41946364u, aot_fast_02800cfc, 3u},
    {41946376u, aot_fast_02800d08, 3u},
    {41946388u, aot_fast_02800d14, 3u},
    {41946400u, aot_fast_02800d20, 3u},
    {41946412u, aot_fast_02800d2c, 3u},
    {41946424u, aot_fast_02800d38, 3u},
    {41946436u, aot_fast_02800d44, 3u},
    {41946448u, aot_fast_02800d50, 3u},
    {41946496u, aot_fast_02800d80, 2u},
    {41946564u, aot_fast_02800dc4, 10u},
    {41946588u, aot_fast_02800ddc, 7u},
    {41946604u, aot_fast_02800dec, 2u},
    {41946608u, aot_fast_02800df0, 6u},
    {41946622u, aot_fast_02800dfe, 2u},
    {41946626u, aot_fast_02800e02, 1u},
    {41946628u, aot_fast_02800e04, 6u},
    {41946642u, aot_fast_02800e12, 6u},
    {41946658u, aot_fast_02800e22, 5u},
    {41946672u, aot_fast_02800e30, 1u},
    {41946674u, aot_fast_02800e32, 5u},
    {41946688u, aot_fast_02800e40, 5u},
    {41946702u, aot_fast_02800e4e, 7u},
    {41946718u, aot_fast_02800e5e, 1u},
    {41946720u, aot_fast_02800e60, 7u},
    {41946736u, aot_fast_02800e70, 7u},
    {41946752u, aot_fast_02800e80, 7u},
    {41946768u, aot_fast_02800e90, 1u},
    {41946772u, aot_fast_02800e94, 10u},
    {41946798u, aot_fast_02800eae, 7u},
    {41946814u, aot_fast_02800ebe, 6u},
    {41946828u, aot_fast_02800ecc, 5u},
    {41946840u, aot_fast_02800ed8, 4u},
    {41946850u, aot_fast_02800ee2, 7u},
    {41946866u, aot_fast_02800ef2, 7u},
    {41946882u, aot_fast_02800f02, 1u},
    {41946888u, aot_fast_02800f08, 3u},
    {41946906u, aot_fast_02800f1a, 4u},
    {41946916u, aot_fast_02800f24, 3u},
    {41946924u, aot_fast_02800f2c, 1u},
    {41946934u, aot_fast_02800f36, 5u},
    {41946948u, aot_fast_02800f44, 4u},
    {41946956u, aot_fast_02800f4c, 3u},
    {41946966u, aot_fast_02800f56, 2u},
    {41946970u, aot_fast_02800f5a, 2u},
    {41946974u, aot_fast_02800f5e, 2u},
    {41946980u, aot_fast_02800f64, 3u},
    {41946986u, aot_fast_02800f6a, 2u},
    {41946990u, aot_fast_02800f6e, 2u},
    {41946994u, aot_fast_02800f72, 2u},
    {41946998u, aot_fast_02800f76, 2u},
    {41947002u, aot_fast_02800f7a, 3u},
    {41947010u, aot_fast_02800f82, 2u},
    {41947014u, aot_fast_02800f86, 2u},
    {41947018u, aot_fast_02800f8a, 1u},
    {41947020u, aot_fast_02800f8c, 4u},
    {41947028u, aot_fast_02800f94, 4u},
    {41947036u, aot_fast_02800f9c, 4u},
    {41947044u, aot_fast_02800fa4, 2u},
    {41947048u, aot_fast_02800fa8, 6u},
    {41947060u, aot_fast_02800fb4, 7u},
    {41947074u, aot_fast_02800fc2, 3u},
    {41947082u, aot_fast_02800fca, 2u},
    {41947086u, aot_fast_02800fce, 1u},
    {41947088u, aot_fast_02800fd0, 8u},
    {41947106u, aot_fast_02800fe2, 1u},
    {41947108u, aot_fast_02800fe4, 3u},
    {41947116u, aot_fast_02800fec, 2u},
    {41947120u, aot_fast_02800ff0, 3u},
    {41947126u, aot_fast_02800ff6, 1u},
    {41947130u, aot_fast_02800ffa, 4u},
    {41947138u, aot_fast_02801002, 4u},
    {41947146u, aot_fast_0280100a, 3u},
    {41947154u, aot_fast_02801012, 3u},
    {41947160u, aot_fast_02801018, 1u},
    {41947164u, aot_fast_0280101c, 2u},
    {41947168u, aot_fast_02801020, 5u},
    {41947182u, aot_fast_0280102e, 1u},
    {41947186u, aot_fast_02801032, 3u},
    {41947198u, aot_fast_0280103e, 1u},
    {41947202u, aot_fast_02801042, 2u},
    {41947206u, aot_fast_02801046, 2u},
    {41947224u, aot_fast_02801058, 5u},
    {41947238u, aot_fast_02801066, 2u},
    {41947244u, aot_fast_0280106c, 1u},
    {41947248u, aot_fast_02801070, 1u},
    {41947250u, aot_fast_02801072, 1u},
    {41947254u, aot_fast_02801076, 3u},
    {41947260u, aot_fast_0280107c, 2u},
    {41947268u, aot_fast_02801084, 3u},
    {41947274u, aot_fast_0280108a, 2u},
    {41947282u, aot_fast_02801092, 3u},
    {41947288u, aot_fast_02801098, 3u},
    {41947300u, aot_fast_028010a4, 1u},
    {41947318u, aot_fast_028010b6, 1u},
    {41947320u, aot_fast_028010b8, 3u},
    {41947326u, aot_fast_028010be, 3u},
    {41947334u, aot_fast_028010c6, 2u},
    {41947338u, aot_fast_028010ca, 1u},
    {41947342u, aot_fast_028010ce, 7u},
    {41947356u, aot_fast_028010dc, 2u},
    {41947360u, aot_fast_028010e0, 2u},
    {41947364u, aot_fast_028010e4, 3u},
    {41947372u, aot_fast_028010ec, 2u},
    {41947378u, aot_fast_028010f2, 6u},
    {41947402u, aot_fast_0280110a, 2u},
    {41947420u, aot_fast_0280111c, 8u},
    {41947440u, aot_fast_02801130, 2u},
    {41947572u, aot_fast_028011b4, 2u},
    {41947576u, aot_fast_028011b8, 7u},
    {41947594u, aot_fast_028011ca, 2u},
    {41947612u, aot_fast_028011dc, 3u},
    {41947622u, aot_fast_028011e6, 3u},
    {41947632u, aot_fast_028011f0, 1u},
    {41947634u, aot_fast_028011f2, 4u},
    {41947642u, aot_fast_028011fa, 3u},
    {41947648u, aot_fast_02801200, 2u},
    {41947654u, aot_fast_02801206, 2u},
    {41947658u, aot_fast_0280120a, 3u},
    {41947666u, aot_fast_02801212, 3u},
    {41947674u, aot_fast_0280121a, 9u},
    {41947694u, aot_fast_0280122e, 7u},
    {41947708u, aot_fast_0280123c, 2u},
    {41947714u, aot_fast_02801242, 1u},
    {41947716u, aot_fast_02801244, 5u},
    {41947726u, aot_fast_0280124e, 2u},
    {41947730u, aot_fast_02801252, 2u},
    {41947734u, aot_fast_02801256, 3u},
    {41947742u, aot_fast_0280125e, 3u},
    {41947750u, aot_fast_02801266, 2u},
    {41947756u, aot_fast_0280126c, 1u},
    {41947760u, aot_fast_02801270, 2u},
    {41947764u, aot_fast_02801274, 1u},
    {41947768u, aot_fast_02801278, 4u},
    {41947776u, aot_fast_02801280, 1u},
    {41947778u, aot_fast_02801282, 4u},
    {41947786u, aot_fast_0280128a, 2u},
    {41947790u, aot_fast_0280128e, 1u},
    {41947792u, aot_fast_02801290, 3u},
    {41947802u, aot_fast_0280129a, 5u},
    {41947832u, aot_fast_028012b8, 2u},
    {41947860u, aot_fast_028012d4, 3u},
    {41947870u, aot_fast_028012de, 5u},
    {41947900u, aot_fast_028012fc, 2u},
    {41947904u, aot_fast_02801300, 9u},
    {41947926u, aot_fast_02801316, 2u},
    {41947930u, aot_fast_0280131a, 6u},
    {41947950u, aot_fast_0280132e, 2u},
    {41947968u, aot_fast_02801340, 4u},
    {41947980u, aot_fast_0280134c, 3u},
    {41947988u, aot_fast_02801354, 1u},
    {41947990u, aot_fast_02801356, 2u},
    {41947994u, aot_fast_0280135a, 4u},
    {41948004u, aot_fast_02801364, 3u},
    {41948010u, aot_fast_0280136a, 2u},
    {41948014u, aot_fast_0280136e, 5u},
    {41948024u, aot_fast_02801378, 3u},
    {41948030u, aot_fast_0280137e, 2u},
    {41948034u, aot_fast_02801382, 1u},
    {41948036u, aot_fast_02801384, 2u},
    {41948042u, aot_fast_0280138a, 3u},
    {41948052u, aot_fast_02801394, 13u},
    {41948082u, aot_fast_028013b2, 6u},
    {41948098u, aot_fast_028013c2, 2u},
    {41948104u, aot_fast_028013c8, 6u},
    {41948124u, aot_fast_028013dc, 3u},
    {41948700u, aot_fast_0280161c, 2u},
    {41948704u, aot_fast_02801620, 2u},
    {41948708u, aot_fast_02801624, 2u},
    {41948712u, aot_fast_02801628, 7u},
    {41948732u, aot_fast_0280163c, 5u},
    {41948742u, aot_fast_02801646, 1u},
    {41948746u, aot_fast_0280164a, 1u},
    {41948748u, aot_fast_0280164c, 1u},
    {41948754u, aot_fast_02801652, 1u},
    {41948756u, aot_fast_02801654, 1u},
    {41948762u, aot_fast_0280165a, 2u},
    {41948766u, aot_fast_0280165e, 3u},
    {41948776u, aot_fast_02801668, 1u},
    {41948780u, aot_fast_0280166c, 2u},
    {41948976u, aot_fast_02801730, 2u},
    {41949046u, aot_fast_02801776, 2u},
    {41949252u, aot_fast_02801844, 2u},
    {41949260u, aot_fast_0280184c, 1u},
    {41949268u, aot_fast_02801854, 3u},
    {41949280u, aot_fast_02801860, 2u},
    {41949288u, aot_fast_02801868, 1u},
    {41949296u, aot_fast_02801870, 1u},
    {41949304u, aot_fast_02801878, 1u},
    {41949312u, aot_fast_02801880, 1u},
    {41949320u, aot_fast_02801888, 1u},
    {41949328u, aot_fast_02801890, 1u},
    {41949396u, aot_fast_028018d4, 1u},
    {41949464u, aot_fast_02801918, 1u},
    {41949484u, aot_fast_0280192c, 1u},
    {41949504u, aot_fast_02801940, 1u},
    {41949508u, aot_fast_02801944, 8u},
    {41949534u, aot_fast_0280195e, 3u},
    {41949544u, aot_fast_02801968, 8u},
    {41949570u, aot_fast_02801982, 3u},
    {41949580u, aot_fast_0280198c, 8u},
    {41949606u, aot_fast_028019a6, 3u},
    {41949616u, aot_fast_028019b0, 8u},
    {41949642u, aot_fast_028019ca, 3u},
    {41949652u, aot_fast_028019d4, 8u},
    {41949678u, aot_fast_028019ee, 3u},
    {41949688u, aot_fast_028019f8, 2u},
    {41949692u, aot_fast_028019fc, 2u},
    {41949696u, aot_fast_02801a00, 9u},
    {41949714u, aot_fast_02801a12, 1u},
    {41949716u, aot_fast_02801a14, 4u},
    {41949726u, aot_fast_02801a1e, 1u},
    {41949728u, aot_fast_02801a20, 2u},
    {41949732u, aot_fast_02801a24, 7u},
    {41949748u, aot_fast_02801a34, 3u},
    {41949756u, aot_fast_02801a3c, 1u},
    {41949758u, aot_fast_02801a3e, 6u},
    {41949776u, aot_fast_02801a50, 2u},
    {41949782u, aot_fast_02801a56, 3u},
    {41949788u, aot_fast_02801a5c, 2u},
    {41949794u, aot_fast_02801a62, 7u},
    {41949810u, aot_fast_02801a72, 6u},
    {41949824u, aot_fast_02801a80, 1u},
    {41949834u, aot_fast_02801a8a, 1u},
    {41949840u, aot_fast_02801a90, 4u},
    {41949854u, aot_fast_02801a9e, 1u},
    {41949858u, aot_fast_02801aa2, 2u},
    {41949868u, aot_fast_02801aac, 1u},
    {41949880u, aot_fast_02801ab8, 3u},
    {41949888u, aot_fast_02801ac0, 3u},
    {41949898u, aot_fast_02801aca, 2u},
    {41949904u, aot_fast_02801ad0, 2u},
    {41949908u, aot_fast_02801ad4, 4u},
    {41949918u, aot_fast_02801ade, 1u},
    {41949922u, aot_fast_02801ae2, 2u},
    {41949930u, aot_fast_02801aea, 1u},
    {41949936u, aot_fast_02801af0, 2u},
    {41949940u, aot_fast_02801af4, 3u},
    {41949948u, aot_fast_02801afc, 6u},
    {41949966u, aot_fast_02801b0e, 3u},
    {41949974u, aot_fast_02801b16, 3u},
    {41949982u, aot_fast_02801b1e, 1u},
    {41949984u, aot_fast_02801b20, 2u},
    {41949990u, aot_fast_02801b26, 1u},
    {41949998u, aot_fast_02801b2e, 4u},
    {41950016u, aot_fast_02801b40, 2u},
    {41950020u, aot_fast_02801b44, 2u},
    {41950024u, aot_fast_02801b48, 2u},
    {41950030u, aot_fast_02801b4e, 3u},
    {41950040u, aot_fast_02801b58, 1u},
    {41950042u, aot_fast_02801b5a, 1u},
    {41950044u, aot_fast_02801b5c, 2u},
    {41950048u, aot_fast_02801b60, 2u},
    {41950052u, aot_fast_02801b64, 7u},
    {41950070u, aot_fast_02801b76, 2u},
    {41950080u, aot_fast_02801b80, 3u},
    {41950090u, aot_fast_02801b8a, 5u},
    {41950102u, aot_fast_02801b96, 1u},
    {41950104u, aot_fast_02801b98, 1u},
    {41950110u, aot_fast_02801b9e, 5u},
    {41950122u, aot_fast_02801baa, 2u},
    {41950126u, aot_fast_02801bae, 2u},
    {41950132u, aot_fast_02801bb4, 6u},
    {41950148u, aot_fast_02801bc4, 3u},
    {41950156u, aot_fast_02801bcc, 6u},
    {41950172u, aot_fast_02801bdc, 2u},
    {41950176u, aot_fast_02801be0, 2u},
    {41950180u, aot_fast_02801be4, 2u},
    {41950186u, aot_fast_02801bea, 5u},
    {41950204u, aot_fast_02801bfc, 1u},
    {41950206u, aot_fast_02801bfe, 2u},
    {41950210u, aot_fast_02801c02, 2u},
    {41950216u, aot_fast_02801c08, 3u},
    {41950228u, aot_fast_02801c14, 1u},
    {41950232u, aot_fast_02801c18, 3u},
    {41950238u, aot_fast_02801c1e, 3u},
    {41950246u, aot_fast_02801c26, 6u},
    {41950262u, aot_fast_02801c36, 2u},
    {41950266u, aot_fast_02801c3a, 2u},
    {41950272u, aot_fast_02801c40, 5u},
    {41950286u, aot_fast_02801c4e, 2u},
    {41950292u, aot_fast_02801c54, 2u},
    {41950298u, aot_fast_02801c5a, 3u},
    {41950308u, aot_fast_02801c64, 2u},
    {41950316u, aot_fast_02801c6c, 1u},
    {41950318u, aot_fast_02801c6e, 3u},
    {41950328u, aot_fast_02801c78, 5u},
    {41950342u, aot_fast_02801c86, 1u},
    {41950344u, aot_fast_02801c88, 1u},
    {41950348u, aot_fast_02801c8c, 2u},
    {41950354u, aot_fast_02801c92, 1u},
    {41950356u, aot_fast_02801c94, 1u},
    {41950358u, aot_fast_02801c96, 2u},
    {41950364u, aot_fast_02801c9c, 14u},
    {41950400u, aot_fast_02801cc0, 2u},
    {41950406u, aot_fast_02801cc6, 2u},
    {41950412u, aot_fast_02801ccc, 2u},
    {41950416u, aot_fast_02801cd0, 2u},
    {41950422u, aot_fast_02801cd6, 2u},
    {41950430u, aot_fast_02801cde, 2u},
    {41950434u, aot_fast_02801ce2, 2u},
    {41950440u, aot_fast_02801ce8, 2u},
};
const uint32_t agr_aot_fast_block_count = 301u;

const AgrAotEntry agr_aot_fast_hash[] = {
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41946436u, aot_fast_02800d44, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41948082u, aot_fast_028013b2, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41948030u, aot_fast_0280137e, 2u},
    {41949728u, aot_fast_02801a20, 2u},
    {0u, 0, 0u},
    {41946980u, aot_fast_02800f64, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41948976u, aot_fast_02801730, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947926u, aot_fast_02801316, 2u},
    {41947576u, aot_fast_028011b8, 7u},
    {41949974u, aot_fast_02801b16, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950272u, aot_fast_02801c40, 5u},
    {41949922u, aot_fast_02801ae2, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41946772u, aot_fast_02800e94, 10u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947420u, aot_fast_0280111c, 8u},
    {0u, 0, 0u},
    {41946720u, aot_fast_02800e60, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947018u, aot_fast_02800f8a, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947666u, aot_fast_02801212, 3u},
    {41949714u, aot_fast_02801a12, 1u},
    {41946966u, aot_fast_02800f56, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41949312u, aot_fast_02801880, 1u},
    {0u, 0, 0u},
    {41946564u, aot_fast_02800dc4, 10u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41949260u, aot_fast_0280184c, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947860u, aot_fast_028012d4, 3u},
    {41949908u, aot_fast_02801ad4, 4u},
    {41947160u, aot_fast_02801018, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950206u, aot_fast_02801bfe, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947108u, aot_fast_02800fe4, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947756u, aot_fast_0280126c, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41948754u, aot_fast_02801652, 1u},
    {0u, 0, 0u},
    {41950102u, aot_fast_02801b96, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950400u, aot_fast_02801cc0, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950348u, aot_fast_02801c8c, 2u},
    {41947950u, aot_fast_0280132e, 2u},
    {41949998u, aot_fast_02801b2e, 4u},
    {41947250u, aot_fast_02801072, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947198u, aot_fast_0280103e, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41949544u, aot_fast_02801968, 8u},
    {41947146u, aot_fast_0280100a, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947742u, aot_fast_0280125e, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41946990u, aot_fast_02800f6e, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947988u, aot_fast_02801354, 1u},
    {0u, 0, 0u},
    {41947288u, aot_fast_02801098, 3u},
    {0u, 0, 0u},
    {41946588u, aot_fast_02800ddc, 7u},
    {0u, 0, 0u},
    {41949984u, aot_fast_02801b20, 2u},
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
    {41947832u, aot_fast_028012b8, 2u},
    {41949880u, aot_fast_02801ab8, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950126u, aot_fast_02801bae, 2u},
    {41949776u, aot_fast_02801a50, 2u},
    {41947378u, aot_fast_028010f2, 6u},
    {41947028u, aot_fast_02800f94, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947326u, aot_fast_028010be, 3u},
    {0u, 0, 0u},
    {41946626u, aot_fast_02800e02, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947274u, aot_fast_0280108a, 2u},
    {41946924u, aot_fast_02800f2c, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947572u, aot_fast_028011b4, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947870u, aot_fast_028012de, 5u},
    {41949918u, aot_fast_02801ade, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950216u, aot_fast_02801c08, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41946768u, aot_fast_02800e90, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41949464u, aot_fast_02801918, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947714u, aot_fast_02801242, 1u},
    {41947364u, aot_fast_028010e4, 3u},
    {41947014u, aot_fast_02800f86, 2u},
    {41948712u, aot_fast_02801628, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950358u, aot_fast_02801c96, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947260u, aot_fast_0280107c, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41949606u, aot_fast_028019a6, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41949904u, aot_fast_02801ad0, 2u},
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
    {41947402u, aot_fast_0280110a, 2u},
    {0u, 0, 0u},
    {41946702u, aot_fast_02800e4e, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41949748u, aot_fast_02801a34, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947648u, aot_fast_02801200, 2u},
    {41949696u, aot_fast_02801a00, 9u},
    {41946948u, aot_fast_02800f44, 4u},
    {0u, 0, 0u},
    {41950344u, aot_fast_02801c88, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950292u, aot_fast_02801c54, 2u},
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
    {41947790u, aot_fast_0280128e, 1u},
    {41947440u, aot_fast_02801130, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41946688u, aot_fast_02800e40, 5u},
    {41950434u, aot_fast_02801ce2, 2u},
    {41948036u, aot_fast_02801384, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41946986u, aot_fast_02800f6a, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947634u, aot_fast_028011f2, 4u},
    {0u, 0, 0u},
    {41946934u, aot_fast_02800f36, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41949280u, aot_fast_02801860, 2u},
    {41946882u, aot_fast_02800f02, 1u},
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
    {41947776u, aot_fast_02801280, 1u},
    {41949824u, aot_fast_02801a80, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41946376u, aot_fast_02800d08, 3u},
    {41950122u, aot_fast_02801baa, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41946674u, aot_fast_02800e32, 5u},
    {0u, 0, 0u},
    {41950070u, aot_fast_02801b76, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41946622u, aot_fast_02800dfe, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950316u, aot_fast_02801c6c, 1u},
    {41949966u, aot_fast_02801b0e, 3u},
    {41949616u, aot_fast_028019b0, 8u},
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
    {41949810u, aot_fast_02801a72, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41949758u, aot_fast_02801a3e, 6u},
    {41947360u, aot_fast_028010e0, 2u},
    {41947010u, aot_fast_02800f82, 2u},
    {41948708u, aot_fast_02801624, 2u},
    {41950406u, aot_fast_02801cc6, 2u},
    {0u, 0, 0u},
    {41947658u, aot_fast_0280120a, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41946608u, aot_fast_02800df0, 6u},
    {41950354u, aot_fast_02801c92, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41949304u, aot_fast_02801878, 1u},
    {41946906u, aot_fast_02800f1a, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947904u, aot_fast_02801300, 9u},
    {0u, 0, 0u},
    {41949252u, aot_fast_02801844, 2u},
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
    {41946400u, aot_fast_02800d20, 3u},
    {41948098u, aot_fast_028013c2, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947048u, aot_fast_02800fa8, 6u},
    {41948746u, aot_fast_0280164a, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947994u, aot_fast_0280135a, 4u},
    {41949692u, aot_fast_028019fc, 2u},
    {41950042u, aot_fast_02801b5a, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41949990u, aot_fast_02801b26, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41946840u, aot_fast_02800ed8, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947138u, aot_fast_02801002, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947786u, aot_fast_0280128a, 2u},
    {41949484u, aot_fast_0280192c, 1u},
    {41947086u, aot_fast_02800fce, 1u},
    {41946736u, aot_fast_02800e70, 7u},
    {41949834u, aot_fast_02801a8a, 1u},
    {41950132u, aot_fast_02801bb4, 6u},
    {41947734u, aot_fast_02801256, 3u},
    {41949782u, aot_fast_02801a56, 3u},
    {0u, 0, 0u},
    {41948732u, aot_fast_0280163c, 5u},
    {41950430u, aot_fast_02801cde, 2u},
    {41950080u, aot_fast_02801b80, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947980u, aot_fast_0280134c, 3u},
    {41949678u, aot_fast_028019ee, 3u},
    {41949328u, aot_fast_02801890, 1u},
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
    {41946424u, aot_fast_02800d38, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947020u, aot_fast_02800f8c, 4u},
    {0u, 0, 0u},
    {41950416u, aot_fast_02801cd0, 2u},
    {0u, 0, 0u},
    {41949716u, aot_fast_02801a14, 4u},
    {41947318u, aot_fast_028010b6, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950364u, aot_fast_02801c9c, 14u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41946916u, aot_fast_02800f24, 3u},
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
    {41949858u, aot_fast_02801aa2, 2u},
    {41949508u, aot_fast_02801944, 8u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950156u, aot_fast_02801bcc, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41948756u, aot_fast_02801654, 1u},
    {0u, 0, 0u},
    {41950104u, aot_fast_02801b98, 1u},
    {0u, 0, 0u},
    {41947356u, aot_fast_028010dc, 2u},
    {0u, 0, 0u},
    {41948704u, aot_fast_02801620, 2u},
    {0u, 0, 0u},
    {41948004u, aot_fast_02801364, 3u},
    {41947654u, aot_fast_02801206, 2u},
    {41950052u, aot_fast_02801b64, 7u},
    {0u, 0, 0u},
    {41946604u, aot_fast_02800dec, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950298u, aot_fast_02801c5a, 3u},
    {41947900u, aot_fast_028012fc, 2u},
    {41949948u, aot_fast_02801afc, 6u},
    {0u, 0, 0u},
    {41946850u, aot_fast_02800ee2, 7u},
    {0u, 0, 0u},
    {41950246u, aot_fast_02801c26, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41946798u, aot_fast_02800eae, 7u},
    {41946448u, aot_fast_02800d50, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947044u, aot_fast_02800fa4, 2u},
    {41948742u, aot_fast_02801646, 1u},
    {41950440u, aot_fast_02801ce8, 2u},
    {41948042u, aot_fast_0280138a, 3u},
    {41950090u, aot_fast_02801b8a, 5u},
    {41947342u, aot_fast_028010ce, 7u},
    {0u, 0, 0u},
    {41946642u, aot_fast_02800e12, 6u},
    {0u, 0, 0u},
    {41947990u, aot_fast_02801356, 2u},
    {41949688u, aot_fast_028019f8, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947238u, aot_fast_02801066, 2u},
    {41946888u, aot_fast_02800f08, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947186u, aot_fast_02801032, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950232u, aot_fast_02801c18, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950180u, aot_fast_02801be4, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947082u, aot_fast_02800fca, 2u},
    {41948780u, aot_fast_0280166c, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947730u, aot_fast_02801252, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41949726u, aot_fast_02801a1e, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41946628u, aot_fast_02800e04, 6u},
    {0u, 0, 0u},
    {41950024u, aot_fast_02801b48, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947224u, aot_fast_02801058, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41949570u, aot_fast_02801982, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41949868u, aot_fast_02801aac, 1u},
    {0u, 0, 0u},
    {41947120u, aot_fast_02800ff0, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947768u, aot_fast_02801278, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41946718u, aot_fast_02800e5e, 1u},
    {41948766u, aot_fast_0280165e, 3u},
    {0u, 0, 0u},
    {41947716u, aot_fast_02801244, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950412u, aot_fast_02801ccc, 2u},
    {41948014u, aot_fast_0280136e, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947612u, aot_fast_028011dc, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950308u, aot_fast_02801c64, 2u},
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
    {41950204u, aot_fast_02801bfc, 1u},
    {41949854u, aot_fast_02801a9e, 1u},
    {41949504u, aot_fast_02801940, 1u},
    {41947106u, aot_fast_02800fe2, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41948104u, aot_fast_028013c8, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41948052u, aot_fast_02801394, 13u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947002u, aot_fast_02800f7a, 3u},
    {41948700u, aot_fast_0280161c, 2u},
    {0u, 0, 0u},
    {41950048u, aot_fast_02801b60, 2u},
    {0u, 0, 0u},
    {41947300u, aot_fast_028010a4, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947248u, aot_fast_02801070, 1u},
    {41949296u, aot_fast_02801870, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41946496u, aot_fast_02800d80, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947792u, aot_fast_02801290, 3u},
    {41949840u, aot_fast_02801a90, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41949788u, aot_fast_02801a5c, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947338u, aot_fast_028010ca, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41949982u, aot_fast_02801b1e, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41949930u, aot_fast_02801aea, 1u},
    {41949580u, aot_fast_0280198c, 8u},
    {41947182u, aot_fast_0280102e, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950228u, aot_fast_02801c14, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947130u, aot_fast_02800ffa, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950176u, aot_fast_02801be0, 2u},
    {41947778u, aot_fast_02801282, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41948776u, aot_fast_02801668, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947726u, aot_fast_0280124e, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950422u, aot_fast_02801cd6, 2u},
    {41948024u, aot_fast_02801378, 3u},
    {41947674u, aot_fast_0280121a, 9u},
    {0u, 0, 0u},
    {41946974u, aot_fast_02800f5e, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950020u, aot_fast_02801b44, 2u},
    {41947622u, aot_fast_028011e6, 3u},
    {41949320u, aot_fast_02801888, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950318u, aot_fast_02801c6e, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41949268u, aot_fast_02801854, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950266u, aot_fast_02801c3a, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947168u, aot_fast_02801020, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947116u, aot_fast_02800fec, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947764u, aot_fast_02801274, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41948762u, aot_fast_0280165a, 2u},
    {41946364u, aot_fast_02800cfc, 3u},
    {41950110u, aot_fast_02801b9e, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41948010u, aot_fast_0280136a, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950356u, aot_fast_02801c94, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947206u, aot_fast_02801046, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947154u, aot_fast_02801012, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947802u, aot_fast_0280129a, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41946752u, aot_fast_02800e80, 7u},
    {0u, 0, 0u},
    {41950148u, aot_fast_02801bc4, 3u},
    {41947750u, aot_fast_02801266, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41948748u, aot_fast_0280164c, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41949396u, aot_fast_028018d4, 1u},
    {41946998u, aot_fast_02800f76, 2u},
    {41949046u, aot_fast_02801776, 2u},
    {0u, 0, 0u},
    {41950044u, aot_fast_02801b5c, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950342u, aot_fast_02801c86, 1u},
    {0u, 0, 0u},
    {41947594u, aot_fast_028011ca, 2u},
    {41947244u, aot_fast_0280106c, 1u},
    {41949642u, aot_fast_028019ca, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41949940u, aot_fast_02801af4, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950238u, aot_fast_02801c1e, 3u},
    {41949888u, aot_fast_02801ac0, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950186u, aot_fast_02801bea, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947088u, aot_fast_02800fd0, 8u},
    {0u, 0, 0u},
    {41946388u, aot_fast_02800d14, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947036u, aot_fast_02800f9c, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41948034u, aot_fast_02801382, 1u},
    {41949732u, aot_fast_02801a24, 7u},
    {41947334u, aot_fast_028010c6, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950030u, aot_fast_02801b4e, 3u},
    {41947632u, aot_fast_028011f0, 1u},
    {41947282u, aot_fast_02801092, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950328u, aot_fast_02801c78, 5u},
    {41947930u, aot_fast_0280131a, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41946828u, aot_fast_02800ecc, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947126u, aot_fast_02800ff6, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41948124u, aot_fast_028013dc, 3u},
    {41950172u, aot_fast_02801bdc, 2u},
    {0u, 0, 0u},
    {41947074u, aot_fast_02800fc2, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947372u, aot_fast_028010ec, 2u},
    {0u, 0, 0u},
    {41946672u, aot_fast_02800e30, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947320u, aot_fast_028010b8, 3u},
    {41946970u, aot_fast_02800f5a, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947968u, aot_fast_02801340, 4u},
    {41950016u, aot_fast_02801b40, 2u},
    {41947268u, aot_fast_02801084, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41946866u, aot_fast_02800ef2, 7u},
    {0u, 0, 0u},
    {41950262u, aot_fast_02801c36, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947164u, aot_fast_0280101c, 2u},
    {41946814u, aot_fast_02800ebe, 6u},
    {0u, 0, 0u},
    {41950210u, aot_fast_02801c02, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41946412u, aot_fast_02800d2c, 3u},
    {0u, 0, 0u},
    {41947760u, aot_fast_02801270, 2u},
    {0u, 0, 0u},
    {41947060u, aot_fast_02800fb4, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947708u, aot_fast_0280123c, 2u},
    {41949756u, aot_fast_02801a3c, 1u},
    {0u, 0, 0u},
    {41946658u, aot_fast_02800e22, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41946956u, aot_fast_02800f4c, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41949652u, aot_fast_028019d4, 8u},
    {41947254u, aot_fast_02801076, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947202u, aot_fast_02801042, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41949898u, aot_fast_02801aca, 2u},
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
    {41949794u, aot_fast_02801a62, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41947694u, aot_fast_0280122e, 7u},
    {0u, 0, 0u},
    {41946994u, aot_fast_02800f72, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950040u, aot_fast_02801b58, 1u},
    {41947642u, aot_fast_028011fa, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41949288u, aot_fast_02801868, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41950286u, aot_fast_02801c4e, 2u},
    {41949936u, aot_fast_02801af0, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {41949534u, aot_fast_0280195e, 3u},
};
const uint32_t agr_aot_fast_hash_mask = 1023u;
