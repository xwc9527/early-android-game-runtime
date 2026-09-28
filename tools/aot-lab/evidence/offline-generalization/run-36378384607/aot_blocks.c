#include "agr_aot.h"

static int aot_debug_00010cfc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 68860u) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, 68868u, 0u);
    s->r[15] = 68864u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010d00(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 68864u) != 3800877570u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    s->r[15] = 68868u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010d04(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 68868u) != 3854365392u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[12] + 720u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_00010d08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 68872u) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, 68880u, 0u);
    s->r[15] = 68876u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010d0c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 68876u) != 3800877570u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    s->r[15] = 68880u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010d10(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 68880u) != 3854365384u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[12] + 712u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_00010d14(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 68884u) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, 68892u, 0u);
    s->r[15] = 68888u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010d18(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 68888u) != 3800877570u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    s->r[15] = 68892u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010d1c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 68892u) != 3854365376u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[12] + 704u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_00010d20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 68896u) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, 68904u, 0u);
    s->r[15] = 68900u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010d24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 68900u) != 3800877570u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    s->r[15] = 68904u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010d28(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 68904u) != 3854365368u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[12] + 696u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_00010d2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 68908u) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, 68916u, 0u);
    s->r[15] = 68912u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010d30(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 68912u) != 3800877570u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    s->r[15] = 68916u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010d34(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 68916u) != 3854365360u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[12] + 688u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_00010d38(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 68920u) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, 68928u, 0u);
    s->r[15] = 68924u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010d3c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 68924u) != 3800877570u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    s->r[15] = 68928u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010d40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 68928u) != 3854365352u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[12] + 680u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_00010d44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 68932u) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, 68940u, 0u);
    s->r[15] = 68936u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010d48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 68936u) != 3800877570u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    s->r[15] = 68940u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010d4c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 68940u) != 3854365344u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[12] + 672u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_00010d50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 68944u) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, 68952u, 0u);
    s->r[15] = 68948u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010d54(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 68948u) != 3800877570u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    s->r[15] = 68952u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010d58(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 68952u) != 3854365336u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[12] + 664u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_00010d80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 68992u) != 3852402692u) return AGR_AOT_MISS;
    { uint32_t addr = (69000u) + 4u; if ((rc = agr_aot_ldr(s, 0, addr))) return rc; }
    s->r[15] = 68996u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010d84(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 68996u) != 3767468032u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 0, 69004u, s->r[0]);
    s->r[15] = 69000u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010dc4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69060u) != 59693u || agr_aot_load16(s, 69062u) != 20472u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 20472u)) return AGR_AOT_FAULT;
    s->r[15] = 69064u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010dc8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69064u) != 18074u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 10, 3);
    s->r[15] = 69066u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010dca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69066u) != 26627u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 69068u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010dcc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69068u) != 17937u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 2);
    s->r[15] = 69070u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010dce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69070u) != 18064u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 8, 2);
    s->r[15] = 69072u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010dd0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69072u) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 69074u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010dd2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69074u) != 17924u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 69076u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010dd4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69076u) != 40458u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 6, s->r[13] + 40u); if (rc) return rc; }
    s->r[15] = 69078u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010dd6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69078u) != 63699u || agr_aot_load16(s, 69080u) != 13044u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) return rc; }
    s->r[15] = 69082u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010dda(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69082u) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], 69084u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ddc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69084u) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 69086u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010dde(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69086u) != 18001u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 10);
    s->r[15] = 69088u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010de0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69088u) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 69090u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010de2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69090u) != 63699u || agr_aot_load16(s, 69092u) != 13044u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) return rc; }
    s->r[15] = 69094u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010de6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69094u) != 17927u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 7, 0);
    s->r[15] = 69096u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010de8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69096u) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 69098u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010dea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69098u) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], 69100u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010dec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69100u) != 18049u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 9, 0);
    s->r[15] = 69102u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010dee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69102u) != 45382u) return AGR_AOT_MISS;
    s->r[15] = !s->r[6] ? 69122u : 69104u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010df0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69104u) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 69106u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010df2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69106u) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 69108u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010df4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69108u) != 17969u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 6);
    s->r[15] = 69110u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010df6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69110u) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 69112u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010df8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69112u) != 63699u || agr_aot_load16(s, 69114u) != 13036u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 748u); if (rc) return rc; }
    s->r[15] = 69116u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010dfc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69116u) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], 69118u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010dfe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69118u) != 17925u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 69120u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e00(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69120u) != 57344u) return AGR_AOT_MISS;
    s->r[15] = 69124u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69122u) != 17973u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 6);
    s->r[15] = 69124u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e04(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69124u) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 69126u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e06(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69126u) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 69128u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69128u) != 39179u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 44u); if (rc) return rc; }
    s->r[15] = 69130u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e0a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69130u) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 69132u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e0c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69132u) != 63699u || agr_aot_load16(s, 69134u) != 13032u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 744u); if (rc) return rc; }
    s->r[15] = 69136u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e10(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69136u) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], 69138u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e12(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69138u) != 62017u || agr_aot_load16(s, 69140u) != 16646u) return AGR_AOT_MISS;
    agr_aot_movw(s, 1, 5126u);
    s->r[15] = 69142u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e16(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69142u) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 69144u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e18(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69144u) != 17979u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 7);
    s->r[15] = 69146u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e1a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69146u) != 18051u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 11, 0);
    s->r[15] = 69148u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e1c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69148u) != 8195u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 3u);
    s->r[15] = 69150u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e1e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69150u) != 63487u || agr_aot_load16(s, 69152u) != 61300u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 68872u, 69154u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e22(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69154u) != 8196u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 4u);
    s->r[15] = 69156u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69156u) != 62017u || agr_aot_load16(s, 69158u) != 16646u) return AGR_AOT_MISS;
    agr_aot_movw(s, 1, 5126u);
    s->r[15] = 69160u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e28(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69160u) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 69162u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e2a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69162u) != 17995u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 9);
    s->r[15] = 69164u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69164u) != 63487u || agr_aot_load16(s, 69166u) != 61298u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 68884u, 69168u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e30(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69168u) != 45365u) return AGR_AOT_MISS;
    s->r[15] = !s->r[5] ? 69184u : 69170u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e32(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69170u) != 8194u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    s->r[15] = 69172u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e34(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69172u) != 62017u || agr_aot_load16(s, 69174u) != 16652u) return AGR_AOT_MISS;
    agr_aot_movw(s, 1, 5132u);
    s->r[15] = 69176u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e38(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69176u) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 69178u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e3a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69178u) != 17963u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 5);
    s->r[15] = 69180u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e3c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69180u) != 63487u || agr_aot_load16(s, 69182u) != 61296u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 68896u, 69184u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69184u) != 8196u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 4u);
    s->r[15] = 69186u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e42(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69186u) != 39180u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 48u); if (rc) return rc; }
    s->r[15] = 69188u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69188u) != 62017u || agr_aot_load16(s, 69190u) != 16899u) return AGR_AOT_MISS;
    agr_aot_movw(s, 2, 5123u);
    s->r[15] = 69192u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69192u) != 18011u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 11);
    s->r[15] = 69194u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e4a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69194u) != 63487u || agr_aot_load16(s, 69196u) != 61296u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 68908u, 69198u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e4e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69198u) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 69200u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69200u) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 69202u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e52(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69202u) != 39179u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 44u); if (rc) return rc; }
    s->r[15] = 69204u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e54(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69204u) != 18010u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 11);
    s->r[15] = 69206u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e56(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69206u) != 63699u || agr_aot_load16(s, 69208u) != 49928u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 12, s->r[3] + 776u); if (rc) return rc; }
    s->r[15] = 69210u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e5a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69210u) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 69212u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e5c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69212u) != 18400u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[12], 69214u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e5e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69214u) != 45373u) return AGR_AOT_MISS;
    s->r[15] = !s->r[5] ? 69232u : 69216u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e60(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69216u) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 69218u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e62(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69218u) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 69220u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69220u) != 17969u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 6);
    s->r[15] = 69222u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e66(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69222u) != 17962u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 5);
    s->r[15] = 69224u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e68(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69224u) != 63699u || agr_aot_load16(s, 69226u) != 49932u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 12, s->r[3] + 780u); if (rc) return rc; }
    s->r[15] = 69228u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e6c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69228u) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 69230u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e6e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69230u) != 18400u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[12], 69232u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e70(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69232u) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 69234u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69234u) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 69236u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e74(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69236u) != 18001u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 10);
    s->r[15] = 69238u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e76(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69238u) != 17994u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 9);
    s->r[15] = 69240u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69240u) != 63699u || agr_aot_load16(s, 69242u) != 21268u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 5, s->r[3] + 788u); if (rc) return rc; }
    s->r[15] = 69244u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e7c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69244u) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 69246u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e7e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69246u) != 18344u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[5], 69248u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69248u) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 69250u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e82(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69250u) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 69252u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e84(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69252u) != 17985u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 8);
    s->r[15] = 69254u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e86(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69254u) != 17978u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 7);
    s->r[15] = 69256u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e88(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69256u) != 63699u || agr_aot_load16(s, 69258u) != 21268u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 5, s->r[3] + 788u); if (rc) return rc; }
    s->r[15] = 69260u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e8c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69260u) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 69262u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e8e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69262u) != 18344u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[5], 69264u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e90(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69264u) != 59581u || agr_aot_load16(s, 69266u) != 36856u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 36856u))) return rc;
}

static int aot_debug_00010e94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69268u) != 59693u || agr_aot_load16(s, 69270u) != 17400u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 17400u)) return AGR_AOT_FAULT;
    s->r[15] = 69272u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e98(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69272u) != 17951u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 7, 3);
    s->r[15] = 69274u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e9a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69274u) != 26627u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 69276u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e9c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69276u) != 18064u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 8, 2);
    s->r[15] = 69278u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010e9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69278u) != 17937u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 2);
    s->r[15] = 69280u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ea0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69280u) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 69282u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ea2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69282u) != 17924u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 69284u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ea4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69284u) != 62017u || agr_aot_load16(s, 69286u) != 18694u) return AGR_AOT_MISS;
    agr_aot_movw(s, 9, 5126u);
    s->r[15] = 69288u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ea8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69288u) != 63699u || agr_aot_load16(s, 69290u) != 13044u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) return rc; }
    s->r[15] = 69292u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010eac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69292u) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], 69294u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010eae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69294u) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 69296u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010eb0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69296u) != 17977u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 7);
    s->r[15] = 69298u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010eb2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69298u) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 69300u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010eb4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69300u) != 63699u || agr_aot_load16(s, 69302u) != 13044u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) return rc; }
    s->r[15] = 69304u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010eb8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69304u) != 17925u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 69306u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010eba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69306u) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 69308u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ebc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69308u) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], 69310u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ebe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69310u) != 17993u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 9);
    s->r[15] = 69312u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ec0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69312u) != 17963u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 5);
    s->r[15] = 69314u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ec2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69314u) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 69316u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ec4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69316u) != 17926u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 6, 0);
    s->r[15] = 69318u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ec6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69318u) != 8194u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    s->r[15] = 69320u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ec8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69320u) != 63487u || agr_aot_load16(s, 69322u) != 61214u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 68872u, 69324u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ecc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69324u) != 17971u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 6);
    s->r[15] = 69326u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ece(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69326u) != 17993u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 9);
    s->r[15] = 69328u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ed0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69328u) != 8196u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 4u);
    s->r[15] = 69330u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ed2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69330u) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 69332u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ed4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69332u) != 63487u || agr_aot_load16(s, 69334u) != 61214u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 68884u, 69336u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ed8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69336u) != 39432u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[13] + 32u); if (rc) return rc; }
    s->r[15] = 69338u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010eda(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69338u) != 8193u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = 69340u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010edc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69340u) != 8448u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = 69342u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ede(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69342u) != 63487u || agr_aot_load16(s, 69344u) != 61228u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 68920u, 69346u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ee2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69346u) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 69348u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ee4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69348u) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 69350u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ee6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69350u) != 17977u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 7);
    s->r[15] = 69352u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ee8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69352u) != 17970u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 69354u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010eea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69354u) != 63699u || agr_aot_load16(s, 69356u) != 49940u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 12, s->r[3] + 788u); if (rc) return rc; }
    s->r[15] = 69358u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010eee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69358u) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 69360u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ef0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69360u) != 18400u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[12], 69362u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ef2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69362u) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 69364u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ef4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69364u) != 17952u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 69366u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ef6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69366u) != 17985u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 8);
    s->r[15] = 69368u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ef8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69368u) != 17962u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 5);
    s->r[15] = 69370u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010efa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69370u) != 63699u || agr_aot_load16(s, 69372u) != 25364u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 6, s->r[3] + 788u); if (rc) return rc; }
    s->r[15] = 69374u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010efe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69374u) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 69376u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f00(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69376u) != 18352u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[6], 69378u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69378u) != 59581u || agr_aot_load16(s, 69380u) != 33784u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 33784u))) return rc;
}

static int aot_debug_00010f08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69384u) != 26627u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 69386u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f0a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69386u) != 90u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 2, s->r[3], 1u);
    s->r[15] = 69388u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f0c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69388u) != 48972u) return AGR_AOT_MISS;
    agr_aot_set_itstate(s, 76u); s->r[15] = 69390u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f1a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69402u) != 59693u || agr_aot_load16(s, 69404u) != 20471u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 20471u)) return AGR_AOT_FAULT;
    s->r[15] = 69406u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f1e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69406u) != 18049u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 9, 0);
    s->r[15] = 69408u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69408u) != 17942u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 6, 2);
    s->r[15] = 69410u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f22(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69410u) != 45857u) return AGR_AOT_MISS;
    s->r[15] = !s->r[1] ? 69486u : 69412u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69412u) != 61697u || agr_aot_load16(s, 69414u) != 14591u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 8, s->r[1], 1023u);
    s->r[15] = 69416u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f28(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69416u) != 9984u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 7, 0u);
    s->r[15] = 69418u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f2a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69418u) != 18114u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 10, 8);
    s->r[15] = 69420u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69420u) != 60167u || agr_aot_load16(s, 69422u) != 1034u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 4, s->r[7], s->r[10]);
    s->r[15] = 69424u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f36(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69430u) != 227u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 3, s->r[4], 3u);
    s->r[15] = 69432u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f38(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69432u) != 37633u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 69434u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f3a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69434u) != 60169u || agr_aot_load16(s, 69436u) != 1283u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 5, s->r[9], s->r[3]);
    s->r[15] = 69438u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f3e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69438u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 69440u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69440u) != 63487u || agr_aot_load16(s, 69442u) != 65506u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 69384u | 1u, 69444u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69444u) != 17732u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[4], s->r[8]);
    s->r[15] = 69446u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f46(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69446u) != 39681u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 4u); if (rc) return rc; }
    s->r[15] = 69448u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69448u) != 18051u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 11, 0);
    s->r[15] = 69450u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f4a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69450u) != 53268u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 69494u : 69452u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f4c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69452u) != 61699u || agr_aot_load16(s, 69454u) != 8u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 0, s->r[3], 8u);
    s->r[15] = 69456u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69456u) != 17480u) return AGR_AOT_MISS;
    s->r[0] += s->r[9];
    s->r[15] = 69458u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f52(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69458u) != 63487u || agr_aot_load16(s, 69460u) != 65497u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 69384u | 1u, 69462u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f56(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69462u) != 17758u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[6], s->r[11]);
    s->r[15] = 69464u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f58(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69464u) != 53764u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 2u) ? 69476u : 69466u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f5a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69466u) != 17084u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[4], s->r[7]);
    s->r[15] = 69468u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f5c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69468u) != 53257u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 69490u : 69470u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f5e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69470u) != 61700u || agr_aot_load16(s, 69472u) != 15103u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 10, s->r[4], 1023u);
    s->r[15] = 69474u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f62(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69474u) != 59363u) return AGR_AOT_MISS;
    s->r[15] = 69420u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69476u) != 14337u) return AGR_AOT_MISS;
    agr_aot_subs(s, 0, s->r[0], 1u);
    s->r[15] = 69478u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f66(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69478u) != 17030u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[6], s->r[0]);
    s->r[15] = 69480u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f68(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69480u) != 55559u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 9u) ? 69498u : 69482u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f6a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69482u) != 7271u) return AGR_AOT_MISS;
    agr_aot_adds(s, 7, s->r[4], 1u);
    s->r[15] = 69484u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f6c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69484u) != 59358u) return AGR_AOT_MISS;
    s->r[15] = 69420u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f6e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69486u) != 17933u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 1);
    s->r[15] = 69488u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f70(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69488u) != 57347u) return AGR_AOT_MISS;
    s->r[15] = 69498u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69490u) != 9472u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 5, 0u);
    s->r[15] = 69492u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f74(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69492u) != 57345u) return AGR_AOT_MISS;
    s->r[15] = 69498u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f76(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69494u) != 17030u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[6], s->r[0]);
    s->r[15] = 69496u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69496u) != 54255u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 3u) ? 69466u : 69498u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f7a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69498u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 69500u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f7c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69500u) != 45059u) return AGR_AOT_MISS;
    s->r[13] += 12u;
    s->r[15] = 69502u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f7e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69502u) != 59581u || agr_aot_load16(s, 69504u) != 36848u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 36848u))) return rc;
}

static int aot_debug_00010f82(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69506u) != 10241u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 1u);
    s->r[15] = 69508u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f84(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69508u) != 53254u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 69524u : 69510u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f86(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69510u) != 10242u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 2u);
    s->r[15] = 69512u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f88(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69512u) != 53256u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 69532u : 69514u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69514u) != 47448u) return AGR_AOT_MISS;
    s->r[15] = s->r[0] ? 69540u : 69516u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f8c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69516u) != 18438u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, 69520u + 24u); if (rc) return rc; }
    s->r[15] = 69518u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f8e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69518u) != 17528u) return AGR_AOT_MISS;
    s->r[0] += 69522u;
    s->r[15] = 69520u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f90(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69520u) != 26624u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 69522u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f92(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69522u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69524u) != 18437u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, 69528u + 20u); if (rc) return rc; }
    s->r[15] = 69526u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f96(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69526u) != 17528u) return AGR_AOT_MISS;
    s->r[0] += 69530u;
    s->r[15] = 69528u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f98(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69528u) != 26624u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 69530u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f9a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69530u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f9c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69532u) != 18436u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, 69536u + 16u); if (rc) return rc; }
    s->r[15] = 69534u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010f9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69534u) != 17528u) return AGR_AOT_MISS;
    s->r[0] += 69538u;
    s->r[15] = 69536u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fa0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69536u) != 26624u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 69538u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fa2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69538u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fa4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69540u) != 8192u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = 69542u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fa6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69542u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fa8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69544u) != 8214u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 22u);
    s->r[15] = 69546u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010faa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69546u) != 0u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 0, s->r[0], 0u);
    s->r[15] = 69548u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69548u) != 8210u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 18u);
    s->r[15] = 69550u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69550u) != 0u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 0, s->r[0], 0u);
    s->r[15] = 69552u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fb0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69552u) != 8206u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 14u);
    s->r[15] = 69554u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fb2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69554u) != 0u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 0, s->r[0], 0u);
    s->r[15] = 69556u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fb4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69556u) != 19237u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, 69560u + 148u); if (rc) return rc; }
    s->r[15] = 69558u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fb6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69558u) != 46451u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16499u)) return AGR_AOT_FAULT;
    s->r[15] = 69560u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fb8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69560u) != 17531u) return AGR_AOT_MISS;
    s->r[3] += 69564u;
    s->r[15] = 69562u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69562u) != 26651u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 69564u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fbc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69564u) != 17924u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 69566u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fbe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69566u) != 7822u) return AGR_AOT_MISS;
    agr_aot_subs(s, 6, s->r[1], 2u);
    s->r[15] = 69568u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fc0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69568u) != 45363u) return AGR_AOT_MISS;
    s->r[15] = !s->r[3] ? 69584u : 69570u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fc2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69570u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 69572u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fc4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69572u) != 43265u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    s->r[15] = 69574u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fc6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69574u) != 63487u || agr_aot_load16(s, 69576u) != 61118u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 68932u, 69578u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69578u) != 17925u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 69580u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fcc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69580u) != 47445u) return AGR_AOT_MISS;
    s->r[15] = s->r[5] ? 69604u : 69582u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69582u) != 57359u) return AGR_AOT_MISS;
    s->r[15] = 69616u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fd0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69584u) != 19743u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 5, 69588u + 124u); if (rc) return rc; }
    s->r[15] = 69586u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fd2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69586u) != 19232u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, 69588u + 128u); if (rc) return rc; }
    s->r[15] = 69588u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fd4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69588u) != 17533u) return AGR_AOT_MISS;
    s->r[5] += 69592u;
    s->r[15] = 69590u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fd6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69590u) != 26669u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 5, s->r[5] + 0u); if (rc) return rc; }
    s->r[15] = 69592u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fd8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69592u) != 17531u) return AGR_AOT_MISS;
    s->r[3] += 69596u;
    s->r[15] = 69594u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fda(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69594u) != 26651u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 69596u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fdc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69596u) != 6893u) return AGR_AOT_MISS;
    agr_aot_subs(s, 5, s->r[5], s->r[3]);
    s->r[15] = 69598u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fde(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69598u) != 17944u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 3);
    s->r[15] = 69600u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fe2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69602u) != 38145u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    s->r[15] = 69604u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fe4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69604u) != 39169u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 4u); if (rc) return rc; }
    s->r[15] = 69606u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fe6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69606u) != 17970u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 69608u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fe8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69608u) != 63487u || agr_aot_load16(s, 69610u) != 65431u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 69402u | 1u, 69612u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69612u) != 17925u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 69614u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010fee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69614u) != 47376u) return AGR_AOT_MISS;
    s->r[15] = s->r[0] ? 69622u : 69616u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ff0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69616u) != 24869u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    s->r[15] = 69618u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ff2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69618u) != 8201u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 9u);
    s->r[15] = 69620u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ff4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69620u) != 57383u) return AGR_AOT_MISS;
    s->r[15] = 69702u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ff6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69622u) != 63487u || agr_aot_load16(s, 69624u) != 65415u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 69384u | 1u, 69626u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ffa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69626u) != 26731u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 4u); if (rc) return rc; }
    s->r[15] = 69628u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ffc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69628u) != 11009u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 1u);
    s->r[15] = 69630u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00010ffe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69630u) != 25760u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[4] + 72u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 69632u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011000(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69632u) != 53507u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 69642u : 69634u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011002(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69634u) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 69636u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011004(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69636u) != 8197u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 5u);
    s->r[15] = 69638u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011006(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69638u) != 24867u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 69640u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011008(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69640u) != 57373u) return AGR_AOT_MISS;
    s->r[15] = 69702u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001100a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69642u) != 11008u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 0u);
    s->r[15] = 69644u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001100c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69644u) != 61701u || agr_aot_load16(s, 69646u) != 4u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 0, s->r[5], 4u);
    s->r[15] = 69648u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011010(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69648u) != 55810u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 10u) ? 69656u : 69650u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011012(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69650u) != 25824u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[4] + 76u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 69652u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011014(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69652u) != 8961u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 1u);
    s->r[15] = 69654u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011016(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69654u) != 57347u) return AGR_AOT_MISS;
    s->r[15] = 69664u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011018(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69656u) != 63487u || agr_aot_load16(s, 69658u) != 65398u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 69384u | 1u, 69660u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001101c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69660u) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 69662u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001101e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69662u) != 25824u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[4] + 76u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 69664u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011020(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69664u) != 27872u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[4] + 76u); if (rc) return rc; }
    s->r[15] = 69666u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011022(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69666u) != 25891u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[4] + 80u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 69668u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011024(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69668u) != 26627u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 69670u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011026(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69670u) != 11008u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 0u);
    s->r[15] = 69672u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011028(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69672u) != 55817u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 10u) ? 69694u : 69674u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001102e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69678u) != 63487u || agr_aot_load16(s, 69680u) != 65448u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 69506u | 1u, 69682u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011032(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69682u) != 24864u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 69684u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011034(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69684u) != 10240u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = 69686u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011036(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69686u) != 48908u) return AGR_AOT_MISS;
    agr_aot_set_itstate(s, 12u); s->r[15] = 69688u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001103e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69694u) != 63487u || agr_aot_load16(s, 69696u) != 65379u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 69384u | 1u, 69698u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011042(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69698u) != 24864u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 69700u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011044(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69700u) != 8192u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = 69702u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011046(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69702u) != 45058u) return AGR_AOT_MISS;
    s->r[13] += 8u;
    s->r[15] = 69704u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011048(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69704u) != 48496u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_debug_00011058(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69720u) != 26627u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 69722u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001105a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69722u) != 46352u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    s->r[15] = 69724u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001105c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69724u) != 17924u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 69726u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001105e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69726u) != 2008u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 0, s->r[3], 31u);
    s->r[15] = 69728u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011060(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69728u) != 54281u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 4u) ? 69750u : 69730u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011066(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69734u) != 61700u || agr_aot_load16(s, 69736u) != 72u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 72u);
    s->r[15] = 69738u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001106a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69738u) != 53250u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 69746u : 69740u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001106c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69740u) != 61440u || agr_aot_load16(s, 69742u) != 64514u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 71796u | 1u, 69744u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011070(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69744u) != 57345u) return AGR_AOT_MISS;
    s->r[15] = 69750u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011072(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69746u) != 61440u || agr_aot_load16(s, 69748u) != 64503u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 71780u | 1u, 69750u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011076(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69750u) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 69752u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011078(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69752u) != 1881u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 1, s->r[3], 29u);
    s->r[15] = 69754u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001107a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69754u) != 54275u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 4u) ? 69764u : 69756u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001107c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69756u) != 61700u || agr_aot_load16(s, 69758u) != 208u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 208u);
    s->r[15] = 69760u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011080(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69760u) != 61440u || agr_aot_load16(s, 69762u) != 64512u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 71812u | 1u, 69764u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011084(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69764u) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 69766u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011086(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69766u) != 1818u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 2, s->r[3], 28u);
    s->r[15] = 69768u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011088(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69768u) != 54275u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 4u) ? 69778u : 69770u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001108a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69770u) != 62724u || agr_aot_load16(s, 69772u) != 28840u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 4008u);
    s->r[15] = 69774u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001108e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69774u) != 61440u || agr_aot_load16(s, 69776u) != 64513u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 71828u | 1u, 69778u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011092(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69778u) != 26659u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 69780u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011094(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69780u) != 1755u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 3, s->r[3], 27u);
    s->r[15] = 69782u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011096(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69782u) != 54277u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 4u) ? 69796u : 69784u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011098(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69784u) != 62724u || agr_aot_load16(s, 69786u) != 28904u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 4072u);
    s->r[15] = 69788u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001109c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69788u) != 59581u || agr_aot_load16(s, 69790u) != 16400u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 16400u))) return rc;
    s->r[15] = 69792u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69792u) != 61440u || agr_aot_load16(s, 69794u) != 48188u) return AGR_AOT_MISS;
    s->r[15] = 71964u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110a4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69796u) != 48400u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_debug_000110b6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69814u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69816u) != 46448u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[15] = 69818u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110ba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69818u) != 17925u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 69820u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110bc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69820u) != 17932u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 1);
    s->r[15] = 69822u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110be(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69822u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 69824u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69824u) != 27681u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 64u); if (rc) return rc; }
    s->r[15] = 69826u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110c2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69826u) != 63487u || agr_aot_load16(s, 69828u) != 65399u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 69556u | 1u, 69830u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110c6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69830u) != 17926u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 6, 0);
    s->r[15] = 69832u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69832u) != 45320u) return AGR_AOT_MISS;
    s->r[15] = !s->r[0] ? 69838u : 69834u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69834u) != 63487u || agr_aot_load16(s, 69836u) != 60994u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 68944u, 69838u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110ce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69838u) != 27683u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 64u); if (rc) return rc; }
    s->r[15] = 69840u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110d0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69840u) != 8193u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = 69842u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110d2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69842u) != 17961u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 5);
    s->r[15] = 69844u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69844u) != 17954u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 4);
    s->r[15] = 69846u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110d6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69846u) != 24939u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[5] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 69848u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110d8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69848u) != 26923u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 16u); if (rc) return rc; }
    s->r[15] = 69850u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110da(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69850u) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], 69852u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69852u) != 10248u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 8u);
    s->r[15] = 69854u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110de(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69854u) != 53486u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 69822u : 69856u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69856u) != 10247u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 7u);
    s->r[15] = 69858u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110e2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69858u) != 53746u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 69834u : 69860u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69860u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 69862u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110e6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69862u) != 27681u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 64u); if (rc) return rc; }
    s->r[15] = 69864u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110e8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69864u) != 63487u || agr_aot_load16(s, 69866u) != 65509u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 69814u | 1u, 69868u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110ec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69868u) != 7456u) return AGR_AOT_MISS;
    agr_aot_adds(s, 0, s->r[4], 4u);
    s->r[15] = 69870u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110ee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69870u) != 61440u || agr_aot_load16(s, 69872u) != 64429u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 71756u | 1u, 69874u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69874u) != 59693u || agr_aot_load16(s, 69876u) != 20464u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 20464u)) return AGR_AOT_FAULT;
    s->r[15] = 69878u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110f6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69878u) != 7437u) return AGR_AOT_MISS;
    agr_aot_adds(s, 5, s->r[1], 4u);
    s->r[15] = 69880u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110f8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69880u) != 63696u || agr_aot_load16(s, 69882u) != 32780u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 8, s->r[0] + 12u); if (rc) return rc; }
    s->r[15] = 69884u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69884u) != 17927u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 7, 0);
    s->r[15] = 69886u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000110fe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69886u) != 63696u || agr_aot_load16(s, 69888u) != 36888u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 9, s->r[0] + 24u); if (rc) return rc; }
    s->r[15] = 69890u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011102(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69890u) != 18066u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 10, 2);
    s->r[15] = 69892u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001110a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69898u) != 44035u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 4, s->r[13], 12u);
    s->r[15] = 69900u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001110c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69900u) != 44546u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 6, s->r[13], 8u);
    s->r[15] = 69902u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001111c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69916u) != 44410u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 5, s->r[13], 488u);
    s->r[15] = 69918u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001111e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69918u) != 59524u || agr_aot_load16(s, 69920u) != 15u) return AGR_AOT_MISS;
    if (agr_aot_stm(s, 4u, 15u)) return AGR_AOT_FAULT;
    s->r[15] = 69922u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011122(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69922u) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 69924u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011124(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69924u) != 18075u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 11, 3);
    s->r[15] = 69926u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011126(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69926u) != 24627u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[6] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 69928u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011128(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69928u) != 17976u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 7);
    s->r[15] = 69930u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001112a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69930u) != 27697u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[6] + 64u); if (rc) return rc; }
    s->r[15] = 69932u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001112c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69932u) != 63487u || agr_aot_load16(s, 69934u) != 65346u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 69556u | 1u, 69936u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011130(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69936u) != 61882u || agr_aot_load16(s, 69938u) != 3840u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[10], 0u);
    s->r[15] = 69940u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011134(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 69940u) != 48916u) return AGR_AOT_MISS;
    agr_aot_set_itstate(s, 20u); s->r[15] = 69942u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_000111b4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70068u) != 27712u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 68u); if (rc) return rc; }
    s->r[15] = 70070u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000111b6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70070u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000111b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70072u) != 27595u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[1] + 60u); if (rc) return rc; }
    s->r[15] = 70074u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000111ba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70074u) != 59693u || agr_aot_load16(s, 70076u) != 16880u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16880u)) return AGR_AOT_FAULT;
    s->r[15] = 70078u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000111be(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70078u) != 7437u) return AGR_AOT_MISS;
    agr_aot_adds(s, 5, s->r[1], 4u);
    s->r[15] = 70080u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000111c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70080u) != 25611u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[1] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 70082u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000111c2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70082u) != 17927u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 7, 0);
    s->r[15] = 70084u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000111c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70084u) != 17934u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 6, 1);
    s->r[15] = 70086u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000111c6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70086u) != 45304u) return AGR_AOT_MISS;
    s->r[13] -= 480u;
    s->r[15] = 70088u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000111ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70090u) != 44033u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 4, s->r[13], 4u);
    s->r[15] = 70092u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000111cc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70092u) != 18152u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 8, 13);
    s->r[15] = 70094u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000111dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70108u) != 59524u || agr_aot_load16(s, 70110u) != 15u) return AGR_AOT_MISS;
    if (agr_aot_stm(s, 4u, 15u)) return AGR_AOT_FAULT;
    s->r[15] = 70112u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000111e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70112u) != 61519u || agr_aot_load16(s, 70114u) != 13311u) return AGR_AOT_MISS;
    s->r[3] = 4294967295u;
    s->r[15] = 70116u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000111e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70116u) != 37632u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 70118u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000111e6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70118u) != 17976u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 7);
    s->r[15] = 70120u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000111e8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70120u) != 63704u || agr_aot_load16(s, 70122u) != 4160u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[8] + 64u); if (rc) return rc; }
    s->r[15] = 70124u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000111ec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70124u) != 63487u || agr_aot_load16(s, 70126u) != 65250u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 69556u | 1u, 70128u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000111f0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70128u) != 47480u) return AGR_AOT_MISS;
    s->r[15] = s->r[0] ? 70162u : 70130u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_000111f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70130u) != 26939u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[7] + 16u); if (rc) return rc; }
    s->r[15] = 70132u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000111f4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70132u) != 17977u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 7);
    s->r[15] = 70134u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000111f6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70134u) != 18026u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 13);
    s->r[15] = 70136u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000111f8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70136u) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], 70138u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000111fa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70138u) != 10248u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 8u);
    s->r[15] = 70140u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000111fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70140u) != 17924u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 70142u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000111fe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70142u) != 53490u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 70118u : 70144u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011200(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70144u) != 18024u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 13);
    s->r[15] = 70146u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011202(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70146u) != 63487u || agr_aot_load16(s, 70148u) != 65321u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 69720u | 1u, 70150u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011206(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70150u) != 11270u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[4], 6u);
    s->r[15] = 70152u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011208(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70152u) != 53507u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 70162u : 70154u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001120a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70154u) != 17976u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 7);
    s->r[15] = 70156u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001120c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70156u) != 17969u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 6);
    s->r[15] = 70158u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001120e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70158u) != 63487u || agr_aot_load16(s, 70160u) != 65363u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 69816u | 1u, 70162u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011212(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70162u) != 8201u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 9u);
    s->r[15] = 70164u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011214(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70164u) != 45176u) return AGR_AOT_MISS;
    s->r[13] += 480u;
    s->r[15] = 70166u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011216(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70166u) != 59581u || agr_aot_load16(s, 70168u) != 33264u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) return rc;
}

static int aot_debug_0001121a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70170u) != 46352u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    s->r[15] = 70172u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001121c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70172u) != 24962u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[0] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 70174u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001121e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70174u) != 27610u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 60u); if (rc) return rc; }
    s->r[15] = 70176u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011220(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70176u) != 24769u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[0] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    s->r[15] = 70178u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011222(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70178u) != 17945u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 3);
    s->r[15] = 70180u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011224(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70180u) != 59581u || agr_aot_load16(s, 70182u) != 16400u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 16400u))) return rc;
    s->r[15] = 70184u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011228(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70184u) != 25626u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[3] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 70186u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001122a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70186u) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 70188u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001122c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70188u) != 59233u) return AGR_AOT_MISS;
    s->r[15] = 69874u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001122e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70190u) != 26947u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 20u); if (rc) return rc; }
    s->r[15] = 70192u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011230(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70192u) != 46448u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[15] = 70194u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011232(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70194u) != 17925u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 70196u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011234(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70196u) != 26822u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 6, s->r[0] + 12u); if (rc) return rc; }
    s->r[15] = 70198u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011236(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70198u) != 17932u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 1);
    s->r[15] = 70200u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011238(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70200u) != 25611u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[1] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 70202u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001123a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70202u) != 45342u) return AGR_AOT_MISS;
    s->r[15] = !s->r[6] ? 70212u : 70204u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001123c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70204u) != 8705u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 70206u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001123e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70206u) != 63487u || agr_aot_load16(s, 70208u) != 65368u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 69874u | 1u, 70210u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011242(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70210u) != 57363u) return AGR_AOT_MISS;
    s->r[15] = 70252u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011244(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70212u) != 26883u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 16u); if (rc) return rc; }
    s->r[15] = 70214u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011246(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70214u) != 17961u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 5);
    s->r[15] = 70216u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011248(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70216u) != 8194u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    s->r[15] = 70218u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001124a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70218u) != 17954u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 4);
    s->r[15] = 70220u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001124c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70220u) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], 70222u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001124e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70222u) != 10247u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 7u);
    s->r[15] = 70224u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011250(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70224u) != 53253u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 70238u : 70226u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011252(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70226u) != 10248u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 8u);
    s->r[15] = 70228u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011254(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70228u) != 53514u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 70252u : 70230u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011256(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70230u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 70232u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011258(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70232u) != 17953u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 4);
    s->r[15] = 70234u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001125a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70234u) != 63487u || agr_aot_load16(s, 70236u) != 65325u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 69816u | 1u, 70238u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001125e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70238u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 70240u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011260(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70240u) != 27681u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 64u); if (rc) return rc; }
    s->r[15] = 70242u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011262(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70242u) != 63487u || agr_aot_load16(s, 70244u) != 65320u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 69814u | 1u, 70246u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011266(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70246u) != 7456u) return AGR_AOT_MISS;
    agr_aot_adds(s, 0, s->r[4], 4u);
    s->r[15] = 70248u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011268(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70248u) != 61440u || agr_aot_load16(s, 70250u) != 64240u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 71756u | 1u, 70252u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001126c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70252u) != 63487u || agr_aot_load16(s, 70254u) != 60784u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 68944u, 70256u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011270(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70256u) != 26818u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[0] + 12u); if (rc) return rc; }
    s->r[15] = 70258u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011272(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70258u) != 47370u) return AGR_AOT_MISS;
    s->r[15] = s->r[2] ? 70264u : 70260u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011274(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70260u) != 63487u || agr_aot_load16(s, 70262u) != 49056u) return AGR_AOT_MISS;
    s->r[15] = 70072u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011278(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70264u) != 27594u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[1] + 60u); if (rc) return rc; }
    s->r[15] = 70266u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001127a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70266u) != 25610u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[1] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 70268u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001127c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70268u) != 8704u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 70270u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001127e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70270u) != 59192u) return AGR_AOT_MISS;
    s->r[15] = 69874u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011280(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70272u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011282(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70274u) != 46344u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    s->r[15] = 70276u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011284(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70276u) != 17921u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 0);
    s->r[15] = 70278u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011286(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70278u) != 26755u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = 70280u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011288(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70280u) != 45323u) return AGR_AOT_MISS;
    s->r[15] = !s->r[3] ? 70286u : 70282u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001128a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70282u) != 8193u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = 70284u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001128c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70284u) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], 70286u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001128e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70286u) != 48392u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) return rc;
}

static int aot_debug_00011290(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70288u) != 46384u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16432u)) return AGR_AOT_FAULT;
    s->r[15] = 70290u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011292(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70290u) != 10500u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[1], 4u);
    s->r[15] = 70292u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011294(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70292u) != 55312u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 8u) ? 70328u : 70294u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001129a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70298u) != 773u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 5, s->r[0], 12u);
    s->r[15] = 70300u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001129c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70300u) != 783u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 7, s->r[1], 12u);
    s->r[15] = 70302u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001129e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70302u) != 3u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 3, s->r[0], 0u);
    s->r[15] = 70304u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000112a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70304u) != 8193u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = 70306u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000112a2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70306u) != 48432u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) return rc;
}

static int aot_debug_000112b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70328u) != 8194u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    s->r[15] = 70330u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000112ba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70330u) != 48432u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) return rc;
}

static int aot_debug_000112d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70356u) != 46384u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16432u)) return AGR_AOT_FAULT;
    s->r[15] = 70358u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000112d6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70358u) != 10500u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[1], 4u);
    s->r[15] = 70360u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000112d8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70360u) != 55312u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 8u) ? 70396u : 70362u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_000112de(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70366u) != 773u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 5, s->r[0], 12u);
    s->r[15] = 70368u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000112e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70368u) != 783u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 7, s->r[1], 12u);
    s->r[15] = 70370u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000112e2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70370u) != 3u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 3, s->r[0], 0u);
    s->r[15] = 70372u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000112e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70372u) != 8193u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = 70374u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000112e6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70374u) != 48432u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) return rc;
}

static int aot_debug_000112fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70396u) != 8194u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    s->r[15] = 70398u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000112fe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70398u) != 48432u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) return rc;
}

static int aot_debug_00011300(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70400u) != 46367u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16415u)) return AGR_AOT_FAULT;
    s->r[15] = 70402u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011302(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70402u) != 43780u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 3, s->r[13], 16u);
    s->r[15] = 70404u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011304(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70404u) != 17932u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 1);
    s->r[15] = 70406u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011306(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70406u) != 8448u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = 70408u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011308(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70408u) != 63555u || agr_aot_load16(s, 70410u) != 11524u) return AGR_AOT_MISS;
    { uint32_t addr = (s->r[3] - 4u); s->r[3] = s->r[3] - 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 70412u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001130c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70412u) != 17954u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 4);
    s->r[15] = 70414u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001130e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70414u) != 37632u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 70416u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011310(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70416u) != 17931u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = 70418u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011312(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70418u) != 63487u || agr_aot_load16(s, 70420u) != 65503u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 70356u | 1u, 70422u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011316(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70422u) != 45060u) return AGR_AOT_MISS;
    s->r[13] += 16u;
    s->r[15] = 70424u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011318(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70424u) != 48400u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_debug_0001131a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70426u) != 27603u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[2] + 60u); if (rc) return rc; }
    s->r[15] = 70428u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001131c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70428u) != 59693u || agr_aot_load16(s, 70430u) != 16880u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16880u)) return AGR_AOT_FAULT;
    s->r[15] = 70432u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011320(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70432u) != 7445u) return AGR_AOT_MISS;
    agr_aot_adds(s, 5, s->r[2], 4u);
    s->r[15] = 70434u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011322(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70434u) != 25619u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[2] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 70436u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011324(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70436u) != 17927u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 7, 0);
    s->r[15] = 70438u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011326(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70438u) != 18056u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 8, 1);
    s->r[15] = 70440u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001132e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70446u) != 44055u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 4, s->r[13], 92u);
    s->r[15] = 70448u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011330(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70448u) != 44566u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 6, s->r[13], 88u);
    s->r[15] = 70450u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011340(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70464u) != 59524u || agr_aot_load16(s, 70466u) != 15u) return AGR_AOT_MISS;
    if (agr_aot_stm(s, 4u, 15u)) return AGR_AOT_FAULT;
    s->r[15] = 70468u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011344(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70468u) != 18028u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 13);
    s->r[15] = 70470u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011346(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70470u) != 61519u || agr_aot_load16(s, 70472u) != 13311u) return AGR_AOT_MISS;
    s->r[3] = 4294967295u;
    s->r[15] = 70474u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001134a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70474u) != 24627u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[6] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 70476u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001134c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70476u) != 18024u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 13);
    s->r[15] = 70478u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001134e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70478u) != 27697u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[6] + 64u); if (rc) return rc; }
    s->r[15] = 70480u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011350(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70480u) != 63487u || agr_aot_load16(s, 70482u) != 65072u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 69556u | 1u, 70484u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011354(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70484u) != 45320u) return AGR_AOT_MISS;
    s->r[15] = !s->r[0] ? 70490u : 70486u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011356(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70486u) != 9481u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 5, 9u);
    s->r[15] = 70488u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011358(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70488u) != 57364u) return AGR_AOT_MISS;
    s->r[15] = 70532u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001135a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70490u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 70492u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001135c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70492u) != 8460u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 12u);
    s->r[15] = 70494u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001135e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70494u) != 18026u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 13);
    s->r[15] = 70496u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011360(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70496u) != 63487u || agr_aot_load16(s, 70498u) != 65486u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 70400u | 1u, 70500u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011364(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70500u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 70502u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011366(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70502u) != 17985u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 8);
    s->r[15] = 70504u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011368(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70504u) != 18360u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[7], 70506u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001136a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70506u) != 10240u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = 70508u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001136c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70508u) != 53747u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 70486u : 70510u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001136e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70510u) != 26915u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 16u); if (rc) return rc; }
    s->r[15] = 70512u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011370(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70512u) != 8200u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 8u);
    s->r[15] = 70514u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011372(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70514u) != 18025u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 13);
    s->r[15] = 70516u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011374(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70516u) != 17970u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 70518u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011376(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70518u) != 18328u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[3], 70520u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011378(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70520u) != 10245u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 5u);
    s->r[15] = 70522u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001137a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70522u) != 17925u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 70524u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001137c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70524u) != 53250u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 70532u : 70526u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001137e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70526u) != 10249u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 9u);
    s->r[15] = 70528u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011380(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70528u) != 53732u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 70476u : 70530u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011382(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70530u) != 59368u) return AGR_AOT_MISS;
    s->r[15] = 70486u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011384(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70532u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 70534u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011386(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70534u) != 63487u || agr_aot_load16(s, 70536u) != 65127u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 69720u | 1u, 70538u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001138a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70538u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 70540u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001138c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70540u) != 62733u || agr_aot_load16(s, 70542u) != 32014u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 13, s->r[13], 3854u);
    s->r[15] = 70544u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011390(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70544u) != 59581u || agr_aot_load16(s, 70546u) != 33264u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) return rc;
}

static int aot_debug_00011394(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70548u) != 59693u || agr_aot_load16(s, 70550u) != 20464u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 20464u)) return AGR_AOT_FAULT;
    s->r[15] = 70552u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011398(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70552u) != 17942u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 6, 2);
    s->r[15] = 70554u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001139a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70554u) != 27850u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[1] + 76u); if (rc) return rc; }
    s->r[15] = 70556u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001139c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70556u) != 45193u) return AGR_AOT_MISS;
    s->r[13] -= 36u;
    s->r[15] = 70558u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001139e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70558u) != 18051u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 11, 0);
    s->r[15] = 70560u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000113a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70560u) != 17932u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 1);
    s->r[15] = 70562u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000113a2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70562u) != 7445u) return AGR_AOT_MISS;
    agr_aot_adds(s, 5, s->r[2], 4u);
    s->r[15] = 70564u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000113a4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70564u) != 61440u || agr_aot_load16(s, 70566u) != 2563u) return AGR_AOT_MISS;
    s->r[10] = s->r[0] & 3u;
    s->r[15] = 70568u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000113a8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70568u) != 26642u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[2] + 0u); if (rc) return rc; }
    s->r[15] = 70570u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000113aa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70570u) != 17951u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 7, 3);
    s->r[15] = 70572u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000113ac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70572u) != 38150u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    s->r[15] = 70574u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000113ae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70574u) != 37381u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 70576u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000113b0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70576u) != 47419u) return AGR_AOT_MISS;
    s->r[15] = s->r[3] ? 70594u : 70578u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_000113b2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70578u) != 530u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 2, s->r[2], 8u);
    s->r[15] = 70580u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000113b4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70580u) != 63629u || agr_aot_load16(s, 70582u) != 12317u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 29u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    s->r[15] = 70584u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000113b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70584u) != 37381u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 70586u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000113ba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70586u) != 8963u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 3u);
    s->r[15] = 70588u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000113bc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70588u) != 63629u || agr_aot_load16(s, 70590u) != 12316u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 28u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    s->r[15] = 70592u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000113c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70592u) != 57356u) return AGR_AOT_MISS;
    s->r[15] = 70620u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_000113c2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70594u) != 11010u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 2u);
    s->r[15] = 70596u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000113c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70596u) != 56330u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 12u) ? 70620u : 70598u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_000113c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70600u) != 63629u || agr_aot_load16(s, 70602u) != 12317u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 29u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    s->r[15] = 70604u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000113cc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70604u) != 1042u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 2, s->r[2], 16u);
    s->r[15] = 70606u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000113ce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70606u) != 37381u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 70608u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000113d0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70608u) != 45787u) return AGR_AOT_MISS;
    s->r[3] = s->r[3] & 0xffu;
    s->r[15] = 70610u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000113d2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70610u) != 8706u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 2u);
    s->r[15] = 70612u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000113d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70612u) != 63629u || agr_aot_load16(s, 70614u) != 8220u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 28u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    s->r[15] = 70616u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000113dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70620u) != 61882u || agr_aot_load16(s, 70622u) != 3842u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[10], 2u);
    s->r[15] = 70624u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000113e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70624u) != 27939u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 80u); if (rc) return rc; }
    s->r[15] = 70626u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000113e2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 70626u) != 48904u) return AGR_AOT_MISS;
    agr_aot_set_itstate(s, 8u); s->r[15] = 70628u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001161c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71196u) != 8960u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 71198u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001161e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71198u) != 59065u) return AGR_AOT_MISS;
    s->r[15] = 70548u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011620(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71200u) != 8961u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 1u);
    s->r[15] = 71202u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011622(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71202u) != 59063u) return AGR_AOT_MISS;
    s->r[15] = 70548u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011624(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71204u) != 8962u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 2u);
    s->r[15] = 71206u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011626(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71206u) != 59061u) return AGR_AOT_MISS;
    s->r[15] = 70548u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011628(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71208u) != 59693u || agr_aot_load16(s, 71210u) != 16880u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16880u)) return AGR_AOT_FAULT;
    s->r[15] = 71212u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001162c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71212u) != 17924u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 71214u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001162e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71214u) != 45250u) return AGR_AOT_MISS;
    s->r[13] -= 264u;
    s->r[15] = 71216u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011630(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71216u) != 17943u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 7, 2);
    s->r[15] = 71218u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011632(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71218u) != 17949u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 3);
    s->r[15] = 71220u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011634(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71220u) != 10500u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[1], 4u);
    s->r[15] = 71222u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011636(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71222u) != 55419u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 8u) ? 71472u : 71224u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001163c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71228u) != 6659u) return AGR_AOT_MISS;
    agr_aot_subs(s, 3, s->r[0], s->r[0]);
    s->r[15] = 71230u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001163e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71230u) != 10362u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 122u);
    s->r[15] = 71232u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011640(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71232u) != 82u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 2, s->r[2], 1u);
    s->r[15] = 71234u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011642(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71234u) != 11520u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[5], 0u);
    s->r[15] = 71236u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011644(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71236u) != 53620u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 71472u : 71238u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011646(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71238u) != 27523u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 56u); if (rc) return rc; }
    s->r[15] = 71240u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001164a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71242u) != 8193u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = 71244u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001164c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71244u) != 64000u || agr_aot_load16(s, 71246u) != 61957u) return AGR_AOT_MISS;
    agr_aot_lsls_reg(s, 2, s->r[0], s->r[5]);
    s->r[15] = 71248u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011652(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71250u) != 53252u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 71262u : 71252u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011654(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71252u) != 26650u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 71254u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001165a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71258u) != 13060u) return AGR_AOT_MISS;
    agr_aot_adds(s, 3, s->r[3], 4u);
    s->r[15] = 71260u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001165c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71260u) != 24690u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[6] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 71262u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001165e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71262u) != 13569u) return AGR_AOT_MISS;
    agr_aot_adds(s, 5, s->r[5], 1u);
    s->r[15] = 71264u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011660(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71264u) != 11536u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[5], 16u);
    s->r[15] = 71266u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011662(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71266u) != 53747u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 71244u : 71268u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011668(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71272u) != 61504u || agr_aot_load16(s, 71274u) != 32901u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 71542u : 71276u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001166c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71276u) != 25507u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[4] + 56u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 71278u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001166e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71278u) != 57577u) return AGR_AOT_MISS;
    s->r[15] = 71748u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011730(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71472u) != 8194u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    s->r[15] = 71474u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011732(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71474u) != 57479u) return AGR_AOT_MISS;
    s->r[15] = 71748u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011776(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71542u) != 8192u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = 71544u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011778(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71544u) != 57444u) return AGR_AOT_MISS;
    s->r[15] = 71748u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011844(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71748u) != 45122u) return AGR_AOT_MISS;
    s->r[13] += 264u;
    s->r[15] = 71750u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011846(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71750u) != 59581u || agr_aot_load16(s, 71752u) != 33264u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) return rc;
}

static int aot_debug_0001184c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71756u) != 61696u || agr_aot_load16(s, 71758u) != 308u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 1, s->r[0], 52u);
    s->r[15] = 71760u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011854(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71764u) != 18076u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 12, 3);
    s->r[15] = 71766u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011856(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71766u) != 18086u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 14, 4);
    s->r[15] = 71768u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011858(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71768u) != 63564u || agr_aot_load16(s, 71770u) != 23812u) return AGR_AOT_MISS;
    { uint32_t addr = (s->r[12] - 4u); s->r[12] = s->r[12] - 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    s->r[15] = 71772u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011860(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71776u) != 18149u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 13, 12);
    s->r[15] = 71778u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011862(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71778u) != 48384u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32768u))) return rc;
}

static int aot_debug_00011868(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71784u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011870(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71792u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011878(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71800u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011880(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71808u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011888(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71816u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011890(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71824u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000118d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71892u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011918(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71960u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001192c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 71980u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011940(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72000u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011944(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72004u) != 18156u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 12, 13);
    s->r[15] = 72006u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011946(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72006u) != 46336u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16384u)) return AGR_AOT_FAULT;
    s->r[15] = 72008u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011948(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72008u) != 59693u || agr_aot_load16(s, 72010u) != 20480u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 20480u)) return AGR_AOT_FAULT;
    s->r[15] = 72012u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001194c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72012u) != 59693u || agr_aot_load16(s, 72014u) != 8191u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 8191u)) return AGR_AOT_FAULT;
    s->r[15] = 72016u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011950(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72016u) != 61519u || agr_aot_load16(s, 72018u) != 768u) return AGR_AOT_MISS;
    s->r[3] = 0u;
    s->r[15] = 72020u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011954(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72020u) != 59693u || agr_aot_load16(s, 72022u) != 12u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 12u)) return AGR_AOT_FAULT;
    s->r[15] = 72024u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011958(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72024u) != 43265u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    s->r[15] = 72026u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001195a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72026u) != 63487u || agr_aot_load16(s, 72028u) != 64557u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 70072u | 1u, 72030u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001195e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72030u) != 63709u || agr_aot_load16(s, 72032u) != 57408u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[15] = 72034u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011962(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72034u) != 45074u) return AGR_AOT_MISS;
    s->r[13] += 72u;
    s->r[15] = 72036u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011964(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72036u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011968(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72040u) != 18156u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 12, 13);
    s->r[15] = 72042u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001196a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72042u) != 46336u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16384u)) return AGR_AOT_FAULT;
    s->r[15] = 72044u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001196c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72044u) != 59693u || agr_aot_load16(s, 72046u) != 20480u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 20480u)) return AGR_AOT_FAULT;
    s->r[15] = 72048u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011970(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72048u) != 59693u || agr_aot_load16(s, 72050u) != 8191u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 8191u)) return AGR_AOT_FAULT;
    s->r[15] = 72052u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011974(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72052u) != 61519u || agr_aot_load16(s, 72054u) != 768u) return AGR_AOT_MISS;
    s->r[3] = 0u;
    s->r[15] = 72056u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011978(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72056u) != 59693u || agr_aot_load16(s, 72058u) != 12u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 12u)) return AGR_AOT_FAULT;
    s->r[15] = 72060u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001197c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72060u) != 43265u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    s->r[15] = 72062u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001197e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72062u) != 63487u || agr_aot_load16(s, 72064u) != 64598u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 70190u | 1u, 72066u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011982(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72066u) != 63709u || agr_aot_load16(s, 72068u) != 57408u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[15] = 72070u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011986(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72070u) != 45074u) return AGR_AOT_MISS;
    s->r[13] += 72u;
    s->r[15] = 72072u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011988(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72072u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001198c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72076u) != 18156u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 12, 13);
    s->r[15] = 72078u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001198e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72078u) != 46336u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16384u)) return AGR_AOT_FAULT;
    s->r[15] = 72080u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011990(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72080u) != 59693u || agr_aot_load16(s, 72082u) != 20480u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 20480u)) return AGR_AOT_FAULT;
    s->r[15] = 72084u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011994(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72084u) != 59693u || agr_aot_load16(s, 72086u) != 8191u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 8191u)) return AGR_AOT_FAULT;
    s->r[15] = 72088u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011998(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72088u) != 61519u || agr_aot_load16(s, 72090u) != 768u) return AGR_AOT_MISS;
    s->r[3] = 0u;
    s->r[15] = 72092u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_0001199c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72092u) != 59693u || agr_aot_load16(s, 72094u) != 12u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 12u)) return AGR_AOT_FAULT;
    s->r[15] = 72096u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72096u) != 43265u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    s->r[15] = 72098u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119a2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72098u) != 63487u || agr_aot_load16(s, 72100u) != 64613u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 70256u | 1u, 72102u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119a6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72102u) != 63709u || agr_aot_load16(s, 72104u) != 57408u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[15] = 72106u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119aa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72106u) != 45074u) return AGR_AOT_MISS;
    s->r[13] += 72u;
    s->r[15] = 72108u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119ac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72108u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119b0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72112u) != 18156u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 12, 13);
    s->r[15] = 72114u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119b2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72114u) != 46336u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16384u)) return AGR_AOT_FAULT;
    s->r[15] = 72116u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119b4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72116u) != 59693u || agr_aot_load16(s, 72118u) != 20480u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 20480u)) return AGR_AOT_FAULT;
    s->r[15] = 72120u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72120u) != 59693u || agr_aot_load16(s, 72122u) != 8191u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 8191u)) return AGR_AOT_FAULT;
    s->r[15] = 72124u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119bc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72124u) != 61519u || agr_aot_load16(s, 72126u) != 768u) return AGR_AOT_MISS;
    s->r[3] = 0u;
    s->r[15] = 72128u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72128u) != 59693u || agr_aot_load16(s, 72130u) != 12u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 12u)) return AGR_AOT_FAULT;
    s->r[15] = 72132u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72132u) != 43777u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 3, s->r[13], 4u);
    s->r[15] = 72134u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119c6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72134u) != 63487u || agr_aot_load16(s, 72136u) != 64552u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 70170u | 1u, 72138u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72138u) != 63709u || agr_aot_load16(s, 72140u) != 57408u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[15] = 72142u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119ce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72142u) != 45074u) return AGR_AOT_MISS;
    s->r[13] += 72u;
    s->r[15] = 72144u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119d0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72144u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72148u) != 18156u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 12, 13);
    s->r[15] = 72150u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119d6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72150u) != 46336u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16384u)) return AGR_AOT_FAULT;
    s->r[15] = 72152u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119d8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72152u) != 59693u || agr_aot_load16(s, 72154u) != 20480u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 20480u)) return AGR_AOT_FAULT;
    s->r[15] = 72156u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72156u) != 59693u || agr_aot_load16(s, 72158u) != 8191u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 8191u)) return AGR_AOT_FAULT;
    s->r[15] = 72160u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72160u) != 61519u || agr_aot_load16(s, 72162u) != 768u) return AGR_AOT_MISS;
    s->r[3] = 0u;
    s->r[15] = 72164u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72164u) != 59693u || agr_aot_load16(s, 72166u) != 12u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 12u)) return AGR_AOT_FAULT;
    s->r[15] = 72168u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119e8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72168u) != 43521u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    s->r[15] = 72170u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119ea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72170u) != 63487u || agr_aot_load16(s, 72172u) != 64662u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 70426u | 1u, 72174u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119ee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72174u) != 63709u || agr_aot_load16(s, 72176u) != 57408u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[15] = 72178u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72178u) != 45074u) return AGR_AOT_MISS;
    s->r[13] += 72u;
    s->r[15] = 72180u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119f4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72180u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119f8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72184u) != 31235u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = 72186u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119fa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72186u) != 47443u) return AGR_AOT_MISS;
    s->r[15] = s->r[3] ? 72210u : 72188u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72188u) != 31299u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 9u); if (rc) return rc; }
    s->r[15] = 72190u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_000119fe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72190u) != 45435u) return AGR_AOT_MISS;
    s->r[15] = !s->r[3] ? 72224u : 72192u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a00(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72192u) != 15105u) return AGR_AOT_MISS;
    agr_aot_subs(s, 3, s->r[3], 1u);
    s->r[15] = 72194u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72194u) != 29251u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[0] + 9u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    s->r[15] = 72196u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a04(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72196u) != 26691u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 4u); if (rc) return rc; }
    s->r[15] = 72198u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a06(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72198u) != 7450u) return AGR_AOT_MISS;
    agr_aot_adds(s, 2, s->r[3], 4u);
    s->r[15] = 72200u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72200u) != 24642u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[0] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 72202u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a0a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72202u) != 26651u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 72204u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a0c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72204u) != 24579u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 72206u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a0e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72206u) != 8963u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 3u);
    s->r[15] = 72208u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a10(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72208u) != 57344u) return AGR_AOT_MISS;
    s->r[15] = 72212u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a12(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72210u) != 15105u) return AGR_AOT_MISS;
    agr_aot_subs(s, 3, s->r[3], 1u);
    s->r[15] = 72212u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a14(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72212u) != 29187u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[0] + 8u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    s->r[15] = 72214u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a16(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72214u) != 26627u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 72216u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a18(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72216u) != 538u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 2, s->r[3], 8u);
    s->r[15] = 72218u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a1a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72218u) != 24578u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 72220u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a1e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72222u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72224u) != 8368u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 176u);
    s->r[15] = 72226u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a22(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72226u) != 18288u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72228u) != 46367u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16415u)) return AGR_AOT_FAULT;
    s->r[15] = 72230u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a26(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72230u) != 8448u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = 72232u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a28(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72232u) != 43779u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 3, s->r[13], 12u);
    s->r[15] = 72234u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a2a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72234u) != 8716u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 12u);
    s->r[15] = 72236u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72236u) != 37632u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 72238u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a2e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72238u) != 17931u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = 72240u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a30(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72240u) != 63487u || agr_aot_load16(s, 72242u) != 64558u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 70288u | 1u, 72244u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a34(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72244u) != 38915u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 12u); if (rc) return rc; }
    s->r[15] = 72246u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a36(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72246u) != 45061u) return AGR_AOT_MISS;
    s->r[13] += 20u;
    s->r[15] = 72248u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a38(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72248u) != 63581u || agr_aot_load16(s, 72250u) != 64260u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13]; s->r[13] = s->r[13] + 4u; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_00011a3c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72252u) != 59378u) return AGR_AOT_MISS;
    s->r[15] = 72228u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a3e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72254u) != 59693u || agr_aot_load16(s, 72256u) != 18431u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 18431u)) return AGR_AOT_FAULT;
    s->r[15] = 72258u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a42(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72258u) != 17925u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 72260u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72260u) != 17934u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 6, 1);
    s->r[15] = 72262u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a46(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72262u) != 9984u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 7, 0u);
    s->r[15] = 72264u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72264u) != 61709u || agr_aot_load16(s, 72266u) != 2060u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 8, s->r[13], 12u);
    s->r[15] = 72268u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a4c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72268u) != 62543u || agr_aot_load16(s, 72270u) != 27007u) return AGR_AOT_MISS;
    s->r[9] = 4080u;
    s->r[15] = 72272u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72272u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 72274u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a52(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72274u) != 63487u || agr_aot_load16(s, 72276u) != 65489u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 72184u | 1u, 72278u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a56(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72278u) != 10416u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 176u);
    s->r[15] = 72280u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a58(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72280u) != 17924u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 72282u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a5a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72282u) != 53522u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 72322u : 72284u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a5c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72284u) != 12032u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[7], 0u);
    s->r[15] = 72286u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a5e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72286u) != 61504u || agr_aot_load16(s, 72288u) != 33049u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 72852u : 72290u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a62(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72290u) != 44035u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 4, s->r[13], 12u);
    s->r[15] = 72292u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72292u) != 17977u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 7);
    s->r[15] = 72294u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a66(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72294u) != 17979u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 7);
    s->r[15] = 72296u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a68(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72296u) != 37888u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    s->r[15] = 72298u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a6a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72298u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 72300u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a6c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72300u) != 8718u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 14u);
    s->r[15] = 72302u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a6e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72302u) != 63487u || agr_aot_load16(s, 72304u) != 64527u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 70288u | 1u, 72306u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72306u) != 37888u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    s->r[15] = 72308u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a74(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72308u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 72310u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a76(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72310u) != 17977u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 1, 7);
    s->r[15] = 72312u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72312u) != 8719u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 15u);
    s->r[15] = 72314u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a7a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72314u) != 17979u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 7);
    s->r[15] = 72316u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a7c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72316u) != 63487u || agr_aot_load16(s, 72318u) != 64554u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 70356u | 1u, 72320u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72320u) != 57608u) return AGR_AOT_MISS;
    s->r[15] = 72852u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72330u) != 53525u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 72376u : 72332u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a90(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72336u) != 17931u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = 72338u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a92(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72338u) != 63693u || agr_aot_load16(s, 72340u) != 32768u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    s->r[15] = 72342u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a96(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72342u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 72344u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a98(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72344u) != 8717u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 13u);
    s->r[15] = 72346u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011a9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72350u) != 63487u || agr_aot_load16(s, 72352u) != 64503u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 70288u | 1u, 72354u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011aa2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72354u) != 39683u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 12u); if (rc) return rc; }
    s->r[15] = 72356u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011aa4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72356u) != 61706u || agr_aot_load16(s, 72358u) != 2564u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 10, s->r[10], 4u);
    s->r[15] = 72360u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011aac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72364u) != 48916u) return AGR_AOT_MISS;
    agr_aot_set_itstate(s, 20u); s->r[15] = 72366u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011ab8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72376u) != 61440u || agr_aot_load16(s, 72378u) != 1008u) return AGR_AOT_MISS;
    s->r[3] = s->r[0] & 240u;
    s->r[15] = 72380u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011abc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72380u) != 11136u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 128u);
    s->r[15] = 72382u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011abe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72382u) != 53527u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 72432u : 72384u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011ac0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72384u) != 516u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 4, s->r[0], 8u);
    s->r[15] = 72386u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011ac2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72386u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 72388u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011ac4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72388u) != 63487u || agr_aot_load16(s, 72390u) != 65432u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 72184u | 1u, 72392u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011aca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72394u) != 62896u || agr_aot_load16(s, 72396u) != 20224u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 32768u);
    s->r[15] = 72398u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011ace(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72398u) != 53505u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 72404u : 72400u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011ad0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72400u) != 8201u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 9u);
    s->r[15] = 72402u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011ad2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72402u) != 57568u) return AGR_AOT_MISS;
    s->r[15] = 72854u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011ad4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72404u) != 260u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 4, s->r[0], 4u);
    s->r[15] = 72406u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011ad6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72406u) != 8448u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = 72408u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011ad8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72408u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 72410u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011ada(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72410u) != 17931u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = 72412u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011ade(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72414u) != 63487u || agr_aot_load16(s, 72416u) != 64931u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 71208u | 1u, 72418u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011ae2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72418u) != 10240u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = 72420u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011ae4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72420u) != 53748u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 72400u : 72422u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011aea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72426u) != 48920u) return AGR_AOT_MISS;
    agr_aot_set_itstate(s, 24u); s->r[15] = 72428u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011af0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72432u) != 11152u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 144u);
    s->r[15] = 72434u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011af2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72434u) != 53525u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 72480u : 72436u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011af4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72436u) != 61440u || agr_aot_load16(s, 72438u) != 781u) return AGR_AOT_MISS;
    s->r[3] = s->r[0] & 13u;
    s->r[15] = 72440u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011af8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72440u) != 11021u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 13u);
    s->r[15] = 72442u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011afa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72442u) != 53481u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 72400u : 72444u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011afc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72444u) != 8448u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = 72446u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011afe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72446u) != 63693u || agr_aot_load16(s, 72448u) != 32768u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    s->r[15] = 72450u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72450u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 72452u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b04(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72452u) != 61444u || agr_aot_load16(s, 72454u) != 527u) return AGR_AOT_MISS;
    s->r[2] = s->r[4] & 15u;
    s->r[15] = 72456u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72456u) != 17931u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = 72458u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b0a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72458u) != 63487u || agr_aot_load16(s, 72460u) != 64449u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 70288u | 1u, 72462u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b0e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72462u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 72464u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b10(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72464u) != 8448u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = 72466u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b12(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72466u) != 63693u || agr_aot_load16(s, 72468u) != 32768u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    s->r[15] = 72470u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b16(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72470u) != 8717u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 13u);
    s->r[15] = 72472u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b18(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72472u) != 17931u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = 72474u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b1a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72474u) != 63487u || agr_aot_load16(s, 72476u) != 64475u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 70356u | 1u, 72478u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b1e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72478u) != 59287u) return AGR_AOT_MISS;
    s->r[15] = 72272u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72480u) != 11168u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 160u);
    s->r[15] = 72482u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b22(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72482u) != 53517u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 72512u : 72484u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b26(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72486u) != 61442u || agr_aot_load16(s, 72488u) != 519u) return AGR_AOT_MISS;
    s->r[2] = s->r[2] & 7u;
    s->r[15] = 72490u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b2e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72494u) != 1795u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 3, s->r[0], 28u);
    s->r[15] = 72496u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b30(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72496u) != 62466u || agr_aot_load16(s, 72498u) != 25215u) return AGR_AOT_MISS;
    s->r[2] = s->r[2] & 4080u;
    s->r[15] = 72500u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b34(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72500u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 72502u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b36(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72502u) != 48968u) return AGR_AOT_MISS;
    agr_aot_set_itstate(s, 72u); s->r[15] = 72504u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72512u) != 11184u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 176u);
    s->r[15] = 72514u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b42(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72514u) != 53579u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 72668u : 72516u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72516u) != 10417u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 177u);
    s->r[15] = 72518u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b46(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72518u) != 53515u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 72544u : 72520u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72520u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 72522u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b4a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72522u) != 63487u || agr_aot_load16(s, 72524u) != 65365u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 72184u | 1u, 72526u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b4e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72526u) != 17922u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 0);
    s->r[15] = 72528u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72528u) != 10240u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = 72530u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b52(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72530u) != 53437u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 72400u : 72532u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b58(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72536u) != 53690u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 72400u : 72538u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b5a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72538u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 72540u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b5c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72540u) != 17931u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = 72542u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b5e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72542u) != 57491u) return AGR_AOT_MISS;
    s->r[15] = 72840u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b60(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72544u) != 10418u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 178u);
    s->r[15] = 72546u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b62(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72546u) != 53538u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 72618u : 72548u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72548u) != 8448u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = 72550u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b66(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72550u) != 8717u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 13u);
    s->r[15] = 72552u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b68(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72552u) != 17931u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = 72554u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b6a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72554u) != 63693u || agr_aot_load16(s, 72556u) != 32768u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    s->r[15] = 72558u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b6e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72558u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 72560u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b70(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72560u) != 9218u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 4, 2u);
    s->r[15] = 72562u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72562u) != 63487u || agr_aot_load16(s, 72564u) != 64397u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 70288u | 1u, 72566u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b76(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72566u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 72568u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72568u) != 63487u || agr_aot_load16(s, 72570u) != 65342u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 72184u | 1u, 72572u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72576u) != 39683u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 12u); if (rc) return rc; }
    s->r[15] = 72578u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b82(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72578u) != 61440u || agr_aot_load16(s, 72580u) != 127u) return AGR_AOT_MISS;
    s->r[0] = s->r[0] & 127u;
    s->r[15] = 72582u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b86(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72582u) != 53255u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 72600u : 72584u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72586u) != 13319u) return AGR_AOT_MISS;
    agr_aot_adds(s, 4, s->r[4], 7u);
    s->r[15] = 72588u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b8c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72588u) != 17411u) return AGR_AOT_MISS;
    s->r[3] += s->r[0];
    s->r[15] = 72590u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b8e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72590u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 72592u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b90(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72592u) != 37635u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 72594u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b92(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72594u) != 63487u || agr_aot_load16(s, 72596u) != 65329u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 72184u | 1u, 72598u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b96(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72598u) != 59377u) return AGR_AOT_MISS;
    s->r[15] = 72572u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b98(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72600u) != 62723u || agr_aot_load16(s, 72602u) != 29441u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 3, s->r[3], 3841u);
    s->r[15] = 72604u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011b9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72606u) != 17432u) return AGR_AOT_MISS;
    s->r[0] += s->r[3];
    s->r[15] = 72608u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011ba0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72608u) != 63693u || agr_aot_load16(s, 72610u) != 32768u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    s->r[15] = 72612u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011ba4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72612u) != 36867u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 72614u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011ba6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72614u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 72616u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011ba8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72616u) != 59317u) return AGR_AOT_MISS;
    s->r[15] = 72470u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011baa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72618u) != 10419u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 179u);
    s->r[15] = 72620u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011bac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72620u) != 53514u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 72644u : 72622u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011bae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72622u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 72624u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011bb0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72624u) != 63487u || agr_aot_load16(s, 72626u) != 65314u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 72184u | 1u, 72628u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011bb4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72628u) != 8449u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = 72630u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011bb6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72630u) != 61440u || agr_aot_load16(s, 72632u) != 783u) return AGR_AOT_MISS;
    s->r[3] = s->r[0] & 15u;
    s->r[15] = 72634u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011bba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72634u) != 61440u || agr_aot_load16(s, 72636u) != 752u) return AGR_AOT_MISS;
    s->r[2] = s->r[0] & 240u;
    s->r[15] = 72638u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011bbe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72638u) != 13057u) return AGR_AOT_MISS;
    agr_aot_adds(s, 3, s->r[3], 1u);
    s->r[15] = 72640u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011bc0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72640u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 72642u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011bc2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72642u) != 57369u) return AGR_AOT_MISS;
    s->r[15] = 72696u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011bc4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72644u) != 61440u || agr_aot_load16(s, 72646u) != 1020u) return AGR_AOT_MISS;
    s->r[3] = s->r[0] & 252u;
    s->r[15] = 72648u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011bc8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72648u) != 11188u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 180u);
    s->r[15] = 72650u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011bca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72650u) != 53377u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 72400u : 72652u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011bcc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72652u) != 61440u || agr_aot_load16(s, 72654u) != 1031u) return AGR_AOT_MISS;
    s->r[4] = s->r[0] & 7u;
    s->r[15] = 72656u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011bd0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72656u) != 8449u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = 72658u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011bd2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72658u) != 7266u) return AGR_AOT_MISS;
    agr_aot_adds(s, 2, s->r[4], 1u);
    s->r[15] = 72660u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011bd4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72660u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 72662u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011bd6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72662u) != 62530u || agr_aot_load16(s, 72664u) != 8704u) return AGR_AOT_MISS;
    s->r[2] = s->r[2] | 524288u;
    s->r[15] = 72666u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011bda(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72666u) != 59327u) return AGR_AOT_MISS;
    s->r[15] = 72540u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011bdc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72668u) != 11200u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 192u);
    s->r[15] = 72670u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011bde(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72670u) != 53574u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 72814u : 72672u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011be0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72672u) != 10438u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 198u);
    s->r[15] = 72674u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011be2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72674u) != 53516u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 72702u : 72676u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011be4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72676u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 72678u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011be6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72678u) != 63487u || agr_aot_load16(s, 72680u) != 65287u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 72184u | 1u, 72682u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011bea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72682u) != 8451u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 3u);
    s->r[15] = 72684u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011bec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72684u) != 61440u || agr_aot_load16(s, 72686u) != 783u) return AGR_AOT_MISS;
    s->r[3] = s->r[0] & 15u;
    s->r[15] = 72688u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011bf0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72688u) != 61440u || agr_aot_load16(s, 72690u) != 752u) return AGR_AOT_MISS;
    s->r[2] = s->r[0] & 240u;
    s->r[15] = 72692u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011bf4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72692u) != 13057u) return AGR_AOT_MISS;
    agr_aot_adds(s, 3, s->r[3], 1u);
    s->r[15] = 72694u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011bf6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72694u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 72696u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011bfc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72700u) != 59310u) return AGR_AOT_MISS;
    s->r[15] = 72540u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011bfe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72702u) != 10439u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 199u);
    s->r[15] = 72704u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c00(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72704u) != 53517u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 72734u : 72706u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72706u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 72708u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c04(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72708u) != 63487u || agr_aot_load16(s, 72710u) != 65272u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 72184u | 1u, 72712u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72712u) != 17922u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 2, 0);
    s->r[15] = 72714u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c0a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72714u) != 10240u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = 72716u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c0c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72716u) != 62527u || agr_aot_load16(s, 72718u) != 44896u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 72400u : 72720u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c14(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72724u) != 62591u || agr_aot_load16(s, 72726u) != 44892u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 72400u : 72728u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c18(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72728u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 72730u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c1a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72730u) != 8452u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 4u);
    s->r[15] = 72732u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c1c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72732u) != 57396u) return AGR_AOT_MISS;
    s->r[15] = 72840u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c1e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72734u) != 61440u || agr_aot_load16(s, 72736u) != 1016u) return AGR_AOT_MISS;
    s->r[3] = s->r[0] & 248u;
    s->r[15] = 72738u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c22(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72738u) != 11200u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 192u);
    s->r[15] = 72740u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72740u) != 53511u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 72758u : 72742u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c26(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72742u) != 61440u || agr_aot_load16(s, 72744u) != 1039u) return AGR_AOT_MISS;
    s->r[4] = s->r[0] & 15u;
    s->r[15] = 72746u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c2a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72746u) != 8451u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 3u);
    s->r[15] = 72748u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72748u) != 7266u) return AGR_AOT_MISS;
    agr_aot_adds(s, 2, s->r[4], 1u);
    s->r[15] = 72750u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c2e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72750u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 72752u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c30(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72752u) != 62530u || agr_aot_load16(s, 72754u) != 8736u) return AGR_AOT_MISS;
    s->r[2] = s->r[2] | 655360u;
    s->r[15] = 72756u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c34(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72756u) != 59282u) return AGR_AOT_MISS;
    s->r[15] = 72540u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c36(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72758u) != 10440u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 200u);
    s->r[15] = 72760u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c38(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72760u) != 53513u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 72782u : 72762u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c3a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72762u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 72764u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c3c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72764u) != 63487u || agr_aot_load16(s, 72766u) != 65244u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 72184u | 1u, 72768u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72768u) != 61440u || agr_aot_load16(s, 72770u) != 752u) return AGR_AOT_MISS;
    s->r[2] = s->r[0] & 240u;
    s->r[15] = 72772u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72772u) != 61440u || agr_aot_load16(s, 72774u) != 15u) return AGR_AOT_MISS;
    s->r[0] = s->r[0] & 15u;
    s->r[15] = 72776u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72776u) != 12816u) return AGR_AOT_MISS;
    agr_aot_adds(s, 2, s->r[2], 16u);
    s->r[15] = 72778u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c4a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72778u) != 7235u) return AGR_AOT_MISS;
    agr_aot_adds(s, 3, s->r[0], 1u);
    s->r[15] = 72780u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c4c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72780u) != 57354u) return AGR_AOT_MISS;
    s->r[15] = 72804u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c4e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72782u) != 10441u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 201u);
    s->r[15] = 72784u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72784u) != 62591u || agr_aot_load16(s, 72786u) != 44862u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 72400u : 72788u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c54(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72788u) != 17968u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 72790u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c56(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72790u) != 63487u || agr_aot_load16(s, 72792u) != 65231u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 72184u | 1u, 72794u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c5a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72794u) != 61440u || agr_aot_load16(s, 72796u) != 783u) return AGR_AOT_MISS;
    s->r[3] = s->r[0] & 15u;
    s->r[15] = 72798u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c5e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72798u) != 61440u || agr_aot_load16(s, 72800u) != 752u) return AGR_AOT_MISS;
    s->r[2] = s->r[0] & 240u;
    s->r[15] = 72802u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c62(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72802u) != 13057u) return AGR_AOT_MISS;
    agr_aot_adds(s, 3, s->r[3], 1u);
    s->r[15] = 72804u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72804u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 72806u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c66(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72806u) != 8449u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = 72808u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c6c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72812u) != 57355u) return AGR_AOT_MISS;
    s->r[15] = 72838u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c6e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72814u) != 61440u || agr_aot_load16(s, 72816u) != 1016u) return AGR_AOT_MISS;
    s->r[3] = s->r[0] & 248u;
    s->r[15] = 72818u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72818u) != 11216u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[3], 208u);
    s->r[15] = 72820u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c74(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72820u) != 62591u || agr_aot_load16(s, 72822u) != 44844u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 72400u : 72824u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72824u) != 61440u || agr_aot_load16(s, 72826u) != 1031u) return AGR_AOT_MISS;
    s->r[4] = s->r[0] & 7u;
    s->r[15] = 72828u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c7c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72828u) != 8449u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = 72830u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c7e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72830u) != 7266u) return AGR_AOT_MISS;
    agr_aot_adds(s, 2, s->r[4], 1u);
    s->r[15] = 72832u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72832u) != 17960u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 72834u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c82(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72834u) != 62530u || agr_aot_load16(s, 72836u) != 8704u) return AGR_AOT_MISS;
    s->r[2] = s->r[2] | 524288u;
    s->r[15] = 72838u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c86(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72838u) != 8965u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 3, 5u);
    s->r[15] = 72840u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c88(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72840u) != 63487u || agr_aot_load16(s, 72842u) != 64718u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 71208u | 1u, 72844u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c8c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72844u) != 10240u) return AGR_AOT_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = 72846u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c8e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72846u) != 62591u || agr_aot_load16(s, 72848u) != 44831u) return AGR_AOT_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 72400u : 72850u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c92(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72850u) != 59101u) return AGR_AOT_MISS;
    s->r[15] = 72272u; return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72852u) != 8192u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = 72854u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c96(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72854u) != 45060u) return AGR_AOT_MISS;
    s->r[13] += 16u;
    s->r[15] = 72856u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c98(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72856u) != 59581u || agr_aot_load16(s, 72858u) != 34800u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 34800u))) return rc;
}

static int aot_debug_00011c9c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72860u) != 46367u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16415u)) return AGR_AOT_FAULT;
    s->r[15] = 72862u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011c9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72862u) != 27843u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 76u); if (rc) return rc; }
    s->r[15] = 72864u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011ca0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72864u) != 17928u) return AGR_AOT_MISS;
    agr_aot_mov_reg(s, 0, 1);
    s->r[15] = 72866u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011ca2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72866u) != 43265u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    s->r[15] = 72868u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011ca4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72868u) != 26714u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 4u); if (rc) return rc; }
    s->r[15] = 72870u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011ca6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72870u) != 530u) return AGR_AOT_MISS;
    agr_aot_lsls(s, 2, s->r[2], 8u);
    s->r[15] = 72872u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011ca8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72872u) != 37377u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 72874u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011caa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72874u) != 61699u || agr_aot_load16(s, 72876u) != 520u) return AGR_AOT_MISS;
    agr_aot_add_imm(s, 2, s->r[3], 8u);
    s->r[15] = 72878u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011cae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72878u) != 37378u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 72880u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011cb0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72880u) != 8707u) return AGR_AOT_MISS;
    agr_aot_movs_imm(s, 2, 3u);
    s->r[15] = 72882u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011cb2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72882u) != 63629u || agr_aot_load16(s, 72884u) != 8204u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 12u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    s->r[15] = 72886u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011cb6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72886u) != 31195u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[3] + 7u); if (rc) return rc; }
    s->r[15] = 72888u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011cb8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72888u) != 63629u || agr_aot_load16(s, 72890u) != 12301u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13] + 13u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    s->r[15] = 72892u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011cbc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72892u) != 63487u || agr_aot_load16(s, 72894u) != 65215u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 72254u | 1u, 72896u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011cc0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72896u) != 45061u) return AGR_AOT_MISS;
    s->r[13] += 20u;
    s->r[15] = 72898u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011cc2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72898u) != 63581u || agr_aot_load16(s, 72900u) != 64260u) return AGR_AOT_MISS;
    { uint32_t addr = s->r[13]; s->r[13] = s->r[13] + 4u; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_debug_00011cc6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72902u) != 46344u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    s->r[15] = 72904u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011cc8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72904u) != 63487u || agr_aot_load16(s, 72906u) != 65208u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 72252u | 1u, 72908u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011ccc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72908u) != 27776u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 72u); if (rc) return rc; }
    s->r[15] = 72910u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011cce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72910u) != 48392u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) return rc;
}

static int aot_debug_00011cd0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72912u) != 46344u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    s->r[15] = 72914u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011cd2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72914u) != 63487u || agr_aot_load16(s, 72916u) != 65203u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 72252u | 1u, 72918u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011cd6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72918u) != 27843u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 76u); if (rc) return rc; }
    s->r[15] = 72920u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011cd8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72920u) != 31194u) return AGR_AOT_MISS;
    { int rc = agr_aot_ldrb(s, 2, s->r[3] + 7u); if (rc) return rc; }
    s->r[15] = 72922u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011cde(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72926u) != 12296u) return AGR_AOT_MISS;
    agr_aot_adds(s, 0, s->r[0], 8u);
    s->r[15] = 72928u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011ce0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72928u) != 48392u) return AGR_AOT_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) return rc;
}

static int aot_debug_00011ce2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72930u) != 46344u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    s->r[15] = 72932u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011ce4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72932u) != 63487u || agr_aot_load16(s, 72934u) != 59444u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 68944u, 72936u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011ce8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72936u) != 46344u) return AGR_AOT_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    s->r[15] = 72938u;
    return AGR_AOT_BOUNDARY;
}

static int aot_debug_00011cea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 72938u) != 63487u || agr_aot_load16(s, 72940u) != 59442u) return AGR_AOT_MISS;
    agr_aot_branch_reg(s, 68944u, 72942u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010cfc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 68868u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    { uint32_t addr = s->r[12] + 720u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00010d08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 68880u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    { uint32_t addr = s->r[12] + 712u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00010d14(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 68892u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    { uint32_t addr = s->r[12] + 704u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00010d20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 68904u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    { uint32_t addr = s->r[12] + 696u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00010d2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 68916u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    { uint32_t addr = s->r[12] + 688u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00010d38(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 68928u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    { uint32_t addr = s->r[12] + 680u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00010d44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 68940u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    { uint32_t addr = s->r[12] + 672u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00010d50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 68952u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    { uint32_t addr = s->r[12] + 664u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00010d80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = (69000u) + 4u; if ((rc = agr_aot_ldr(s, 0, addr))) return rc; }
    agr_aot_add_imm(s, 0, 69004u, s->r[0]);
    s->r[15] = 69000u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010dc4(AgrAotRegs *s) {
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
    agr_aot_branch_reg(s, s->r[3], 69084u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010ddc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 1, 10);
    agr_aot_movs_imm(s, 2, 0u);
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) return rc; }
    agr_aot_mov_reg(s, 7, 0);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, s->r[3], 69100u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010dec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 9, 0);
    s->r[15] = !s->r[6] ? 69122u : 69104u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010df0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_mov_reg(s, 1, 6);
    agr_aot_movs_imm(s, 2, 0u);
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 748u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[3], 69118u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010dfe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 69124u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010e02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 5, 6);
    s->r[15] = 69124u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010e04(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_movs_imm(s, 2, 0u);
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 44u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 744u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[3], 69138u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010e12(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movw(s, 1, 5126u);
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_mov_reg(s, 3, 7);
    agr_aot_mov_reg(s, 11, 0);
    agr_aot_movs_imm(s, 0, 3u);
    agr_aot_branch_reg(s, 68872u, 69154u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010e22(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 4u);
    agr_aot_movw(s, 1, 5126u);
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_mov_reg(s, 3, 9);
    agr_aot_branch_reg(s, 68884u, 69168u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010e30(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[5] ? 69184u : 69170u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010e32(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    agr_aot_movw(s, 1, 5132u);
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_mov_reg(s, 3, 5);
    agr_aot_branch_reg(s, 68896u, 69184u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010e40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 4u);
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 48u); if (rc) return rc; }
    agr_aot_movw(s, 2, 5123u);
    agr_aot_mov_reg(s, 3, 11);
    agr_aot_branch_reg(s, 68908u, 69198u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010e4e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 44u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 11);
    { int rc = agr_aot_ldr(s, 12, s->r[3] + 776u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_branch_reg(s, s->r[12], 69214u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010e5e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[5] ? 69232u : 69216u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010e60(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_mov_reg(s, 1, 6);
    agr_aot_mov_reg(s, 2, 5);
    { int rc = agr_aot_ldr(s, 12, s->r[3] + 780u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_branch_reg(s, s->r[12], 69232u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010e70(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_mov_reg(s, 1, 10);
    agr_aot_mov_reg(s, 2, 9);
    { int rc = agr_aot_ldr(s, 5, s->r[3] + 788u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_branch_reg(s, s->r[5], 69248u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010e80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_mov_reg(s, 1, 8);
    agr_aot_mov_reg(s, 2, 7);
    { int rc = agr_aot_ldr(s, 5, s->r[3] + 788u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_branch_reg(s, s->r[5], 69264u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010e90(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 36856u))) return rc;
}

static int aot_fast_00010e94(AgrAotRegs *s) {
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
    agr_aot_branch_reg(s, s->r[3], 69294u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010eae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 1, 7);
    agr_aot_movs_imm(s, 2, 0u);
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) return rc; }
    agr_aot_mov_reg(s, 5, 0);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, s->r[3], 69310u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010ebe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 1, 9);
    agr_aot_mov_reg(s, 3, 5);
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_mov_reg(s, 6, 0);
    agr_aot_movs_imm(s, 0, 2u);
    agr_aot_branch_reg(s, 68872u, 69324u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010ecc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 3, 6);
    agr_aot_mov_reg(s, 1, 9);
    agr_aot_movs_imm(s, 0, 4u);
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_branch_reg(s, 68884u, 69336u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010ed8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[13] + 32u); if (rc) return rc; }
    agr_aot_movs_imm(s, 0, 1u);
    agr_aot_movs_imm(s, 1, 0u);
    agr_aot_branch_reg(s, 68920u, 69346u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010ee2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_mov_reg(s, 1, 7);
    agr_aot_mov_reg(s, 2, 6);
    { int rc = agr_aot_ldr(s, 12, s->r[3] + 788u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_branch_reg(s, s->r[12], 69362u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010ef2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_mov_reg(s, 1, 8);
    agr_aot_mov_reg(s, 2, 5);
    { int rc = agr_aot_ldr(s, 6, s->r[3] + 788u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_branch_reg(s, s->r[6], 69378u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010f02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 33784u))) return rc;
}

static int aot_fast_00010f08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_lsls(s, 2, s->r[3], 1u);
    agr_aot_set_itstate(s, 76u); s->r[15] = 69390u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010f1a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 20471u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 9, 0);
    agr_aot_mov_reg(s, 6, 2);
    s->r[15] = !s->r[1] ? 69486u : 69412u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010f24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 8, s->r[1], 1023u);
    agr_aot_movs_imm(s, 7, 0u);
    agr_aot_mov_reg(s, 10, 8);
    s->r[15] = 69420u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010f2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 4, s->r[7], s->r[10]);
    s->r[15] = 69424u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010f36(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 3, s->r[4], 3u);
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_add_imm(s, 5, s->r[9], s->r[3]);
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_branch_reg(s, 69384u | 1u, 69444u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010f44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[4], s->r[8]);
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 4u); if (rc) return rc; }
    agr_aot_mov_reg(s, 11, 0);
    s->r[15] = agr_aot_condition(s, 0u) ? 69494u : 69452u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010f4c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 0, s->r[3], 8u);
    s->r[0] += s->r[9];
    agr_aot_branch_reg(s, 69384u | 1u, 69462u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010f56(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[6], s->r[11]);
    s->r[15] = agr_aot_condition(s, 2u) ? 69476u : 69466u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010f5a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[4], s->r[7]);
    s->r[15] = agr_aot_condition(s, 0u) ? 69490u : 69470u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010f5e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 10, s->r[4], 1023u);
    s->r[15] = 69420u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010f64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 0, s->r[0], 1u);
    agr_aot_cmp(s, s->r[6], s->r[0]);
    s->r[15] = agr_aot_condition(s, 9u) ? 69498u : 69482u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010f6a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 7, s->r[4], 1u);
    s->r[15] = 69420u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010f6e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 5, 1);
    s->r[15] = 69498u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010f72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 5, 0u);
    s->r[15] = 69498u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010f76(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[6], s->r[0]);
    s->r[15] = agr_aot_condition(s, 3u) ? 69466u : 69498u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010f7a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[13] += 12u;
    if ((rc = agr_aot_ldmia_sp(s, 36848u))) return rc;
}

static int aot_fast_00010f82(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 1u);
    s->r[15] = agr_aot_condition(s, 0u) ? 69524u : 69510u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010f86(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 2u);
    s->r[15] = agr_aot_condition(s, 0u) ? 69532u : 69514u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010f8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = s->r[0] ? 69540u : 69516u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010f8c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 69520u + 24u); if (rc) return rc; }
    s->r[0] += 69522u;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010f94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 69528u + 20u); if (rc) return rc; }
    s->r[0] += 69530u;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010f9c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 69536u + 16u); if (rc) return rc; }
    s->r[0] += 69538u;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010fa4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010fa8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 22u);
    agr_aot_lsls(s, 0, s->r[0], 0u);
    agr_aot_movs_imm(s, 0, 18u);
    agr_aot_lsls(s, 0, s->r[0], 0u);
    agr_aot_movs_imm(s, 0, 14u);
    agr_aot_lsls(s, 0, s->r[0], 0u);
    s->r[15] = 69556u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010fb4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 69560u + 148u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16499u)) return AGR_AOT_FAULT;
    s->r[3] += 69564u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_subs(s, 6, s->r[1], 2u);
    s->r[15] = !s->r[3] ? 69584u : 69570u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010fc2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    agr_aot_branch_reg(s, 68932u, 69578u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010fca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = s->r[5] ? 69604u : 69582u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010fce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 69616u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010fd0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 5, 69588u + 124u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, 69588u + 128u); if (rc) return rc; }
    s->r[5] += 69592u;
    { int rc = agr_aot_ldr(s, 5, s->r[5] + 0u); if (rc) return rc; }
    s->r[3] += 69596u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_subs(s, 5, s->r[5], s->r[3]);
    agr_aot_mov_reg(s, 0, 3);
    s->r[15] = 69600u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010fe2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    s->r[15] = 69604u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010fe4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 4u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_branch_reg(s, 69402u | 1u, 69612u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010fec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = s->r[0] ? 69622u : 69616u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010ff0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    agr_aot_movs_imm(s, 0, 9u);
    s->r[15] = 69702u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010ff6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 69384u | 1u, 69626u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00010ffa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 4u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 1u);
    { uint32_t addr = s->r[4] + 72u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = agr_aot_condition(s, 1u) ? 69642u : 69634u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011002(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_movs_imm(s, 0, 5u);
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 69702u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001100a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 0u);
    agr_aot_add_imm(s, 0, s->r[5], 4u);
    s->r[15] = agr_aot_condition(s, 10u) ? 69656u : 69650u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011012(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 76u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_movs_imm(s, 3, 1u);
    s->r[15] = 69664u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011018(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 69384u | 1u, 69660u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001101c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    { uint32_t addr = s->r[4] + 76u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 69664u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011020(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[4] + 76u); if (rc) return rc; }
    { uint32_t addr = s->r[4] + 80u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 0u);
    s->r[15] = agr_aot_condition(s, 10u) ? 69694u : 69674u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001102e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 69506u | 1u, 69682u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011032(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_cmp(s, s->r[0], 0u);
    agr_aot_set_itstate(s, 12u); s->r[15] = 69688u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001103e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 69384u | 1u, 69698u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011042(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = 69702u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011046(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00011058(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_lsls(s, 0, s->r[3], 31u);
    s->r[15] = agr_aot_condition(s, 4u) ? 69750u : 69730u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011066(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 72u);
    s->r[15] = agr_aot_condition(s, 0u) ? 69746u : 69740u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001106c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 71796u | 1u, 69744u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011070(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 69750u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011072(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 71780u | 1u, 69750u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011076(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_lsls(s, 1, s->r[3], 29u);
    s->r[15] = agr_aot_condition(s, 4u) ? 69764u : 69756u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001107c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 208u);
    agr_aot_branch_reg(s, 71812u | 1u, 69764u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011084(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_lsls(s, 2, s->r[3], 28u);
    s->r[15] = agr_aot_condition(s, 4u) ? 69778u : 69770u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001108a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 4008u);
    agr_aot_branch_reg(s, 71828u | 1u, 69778u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011092(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_lsls(s, 3, s->r[3], 27u);
    s->r[15] = agr_aot_condition(s, 4u) ? 69796u : 69784u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011098(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 4072u);
    if ((rc = agr_aot_ldmia_sp(s, 16400u))) return rc;
    s->r[15] = 71964u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000110a4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_000110b6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000110b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 5, 0);
    agr_aot_mov_reg(s, 4, 1);
    s->r[15] = 69822u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000110be(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 64u); if (rc) return rc; }
    agr_aot_branch_reg(s, 69556u | 1u, 69830u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000110c6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 6, 0);
    s->r[15] = !s->r[0] ? 69838u : 69834u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000110ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 68944u, 69838u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000110ce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 64u); if (rc) return rc; }
    agr_aot_movs_imm(s, 0, 1u);
    agr_aot_mov_reg(s, 1, 5);
    agr_aot_mov_reg(s, 2, 4);
    { uint32_t addr = s->r[5] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 16u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[3], 69852u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000110dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 8u);
    s->r[15] = agr_aot_condition(s, 0u) ? 69822u : 69856u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000110e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 7u);
    s->r[15] = agr_aot_condition(s, 1u) ? 69834u : 69860u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000110e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 64u); if (rc) return rc; }
    agr_aot_branch_reg(s, 69814u | 1u, 69868u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000110ec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 0, s->r[4], 4u);
    agr_aot_branch_reg(s, 71756u | 1u, 69874u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000110f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 20464u)) return AGR_AOT_FAULT;
    agr_aot_adds(s, 5, s->r[1], 4u);
    { int rc = agr_aot_ldr(s, 8, s->r[0] + 12u); if (rc) return rc; }
    agr_aot_mov_reg(s, 7, 0);
    { int rc = agr_aot_ldr(s, 9, s->r[0] + 24u); if (rc) return rc; }
    agr_aot_mov_reg(s, 10, 2);
    s->r[15] = 69892u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001110a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 4, s->r[13], 12u);
    agr_aot_add_imm(s, 6, s->r[13], 8u);
    s->r[15] = 69902u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001111c(AgrAotRegs *s) {
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
    agr_aot_branch_reg(s, 69556u | 1u, 69936u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011130(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[10], 0u);
    agr_aot_set_itstate(s, 20u); s->r[15] = 69942u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000111b4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 68u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000111b8(AgrAotRegs *s) {
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
    s->r[15] = 70088u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000111ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 4, s->r[13], 4u);
    agr_aot_mov_reg(s, 8, 13);
    s->r[15] = 70094u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000111dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stm(s, 4u, 15u)) return AGR_AOT_FAULT;
    s->r[3] = 4294967295u;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 70118u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000111e6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 7);
    { int rc = agr_aot_ldr(s, 1, s->r[8] + 64u); if (rc) return rc; }
    agr_aot_branch_reg(s, 69556u | 1u, 70128u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000111f0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = s->r[0] ? 70162u : 70130u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000111f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[7] + 16u); if (rc) return rc; }
    agr_aot_mov_reg(s, 1, 7);
    agr_aot_mov_reg(s, 2, 13);
    agr_aot_branch_reg(s, s->r[3], 70138u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000111fa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 8u);
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = agr_aot_condition(s, 0u) ? 70118u : 70144u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011200(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 13);
    agr_aot_branch_reg(s, 69720u | 1u, 70150u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011206(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[4], 6u);
    s->r[15] = agr_aot_condition(s, 1u) ? 70162u : 70154u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001120a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 7);
    agr_aot_mov_reg(s, 1, 6);
    agr_aot_branch_reg(s, 69816u | 1u, 70162u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011212(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 9u);
    s->r[13] += 480u;
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) return rc;
}

static int aot_fast_0001121a(AgrAotRegs *s) {
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
    s->r[15] = 69874u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001122e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 20u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 5, 0);
    { int rc = agr_aot_ldr(s, 6, s->r[0] + 12u); if (rc) return rc; }
    agr_aot_mov_reg(s, 4, 1);
    { uint32_t addr = s->r[1] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = !s->r[6] ? 70212u : 70204u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001123c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 2, 1u);
    agr_aot_branch_reg(s, 69874u | 1u, 70210u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011242(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 70252u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011244(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 16u); if (rc) return rc; }
    agr_aot_mov_reg(s, 1, 5);
    agr_aot_movs_imm(s, 0, 2u);
    agr_aot_mov_reg(s, 2, 4);
    agr_aot_branch_reg(s, s->r[3], 70222u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001124e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 7u);
    s->r[15] = agr_aot_condition(s, 0u) ? 70238u : 70226u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011252(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 8u);
    s->r[15] = agr_aot_condition(s, 1u) ? 70252u : 70230u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011256(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 1, 4);
    agr_aot_branch_reg(s, 69816u | 1u, 70238u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001125e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 64u); if (rc) return rc; }
    agr_aot_branch_reg(s, 69814u | 1u, 70246u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011266(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 0, s->r[4], 4u);
    agr_aot_branch_reg(s, 71756u | 1u, 70252u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001126c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 68944u, 70256u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011270(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[0] + 12u); if (rc) return rc; }
    s->r[15] = s->r[2] ? 70264u : 70260u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011274(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 70072u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011278(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[1] + 60u); if (rc) return rc; }
    { uint32_t addr = s->r[1] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 69874u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011280(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011282(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 1, 0);
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = !s->r[3] ? 70286u : 70282u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001128a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 1u);
    agr_aot_branch_reg(s, s->r[3], 70286u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001128e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) return rc;
}

static int aot_fast_00011290(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16432u)) return AGR_AOT_FAULT;
    agr_aot_cmp(s, s->r[1], 4u);
    s->r[15] = agr_aot_condition(s, 8u) ? 70328u : 70294u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001129a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 5, s->r[0], 12u);
    agr_aot_lsls(s, 7, s->r[1], 12u);
    agr_aot_lsls(s, 3, s->r[0], 0u);
    agr_aot_movs_imm(s, 0, 1u);
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) return rc;
}

static int aot_fast_000112b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) return rc;
}

static int aot_fast_000112d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16432u)) return AGR_AOT_FAULT;
    agr_aot_cmp(s, s->r[1], 4u);
    s->r[15] = agr_aot_condition(s, 8u) ? 70396u : 70362u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000112de(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 5, s->r[0], 12u);
    agr_aot_lsls(s, 7, s->r[1], 12u);
    agr_aot_lsls(s, 3, s->r[0], 0u);
    agr_aot_movs_imm(s, 0, 1u);
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) return rc;
}

static int aot_fast_000112fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) return rc;
}

static int aot_fast_00011300(AgrAotRegs *s) {
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
    agr_aot_branch_reg(s, 70356u | 1u, 70422u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011316(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 16u;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_0001131a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[2] + 60u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16880u)) return AGR_AOT_FAULT;
    agr_aot_adds(s, 5, s->r[2], 4u);
    { uint32_t addr = s->r[2] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_mov_reg(s, 7, 0);
    agr_aot_mov_reg(s, 8, 1);
    s->r[15] = 70440u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001132e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 4, s->r[13], 92u);
    agr_aot_add_imm(s, 6, s->r[13], 88u);
    s->r[15] = 70450u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011340(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stm(s, 4u, 15u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 13);
    s->r[3] = 4294967295u;
    { uint32_t addr = s->r[6] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 70476u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001134c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 13);
    { int rc = agr_aot_ldr(s, 1, s->r[6] + 64u); if (rc) return rc; }
    agr_aot_branch_reg(s, 69556u | 1u, 70484u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011354(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[0] ? 70490u : 70486u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011356(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 5, 9u);
    s->r[15] = 70532u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001135a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_movs_imm(s, 1, 12u);
    agr_aot_mov_reg(s, 2, 13);
    agr_aot_branch_reg(s, 70400u | 1u, 70500u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011364(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_mov_reg(s, 1, 8);
    agr_aot_branch_reg(s, s->r[7], 70506u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001136a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 70486u : 70510u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001136e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 16u); if (rc) return rc; }
    agr_aot_movs_imm(s, 0, 8u);
    agr_aot_mov_reg(s, 1, 13);
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_branch_reg(s, s->r[3], 70520u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011378(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 5u);
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = agr_aot_condition(s, 0u) ? 70532u : 70526u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001137e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 9u);
    s->r[15] = agr_aot_condition(s, 1u) ? 70476u : 70530u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011382(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 70486u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011384(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 69720u | 1u, 70538u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001138a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_add_imm(s, 13, s->r[13], 3854u);
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) return rc;
}

static int aot_fast_00011394(AgrAotRegs *s) {
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
    s->r[15] = s->r[3] ? 70594u : 70578u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000113b2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 2, s->r[2], 8u);
    { uint32_t addr = s->r[13] + 29u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    { uint32_t addr = s->r[13] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_movs_imm(s, 3, 3u);
    { uint32_t addr = s->r[13] + 28u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    s->r[15] = 70620u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000113c2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 2u);
    s->r[15] = agr_aot_condition(s, 12u) ? 70620u : 70598u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000113c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[13] + 29u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    agr_aot_lsls(s, 2, s->r[2], 16u);
    { uint32_t addr = s->r[13] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[3] = s->r[3] & 0xffu;
    agr_aot_movs_imm(s, 2, 2u);
    { uint32_t addr = s->r[13] + 28u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    s->r[15] = 70616u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000113dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[10], 2u);
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 80u); if (rc) return rc; }
    agr_aot_set_itstate(s, 8u); s->r[15] = 70628u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001161c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 70548u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011620(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 3, 1u);
    s->r[15] = 70548u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011624(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 3, 2u);
    s->r[15] = 70548u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011628(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16880u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    s->r[13] -= 264u;
    agr_aot_mov_reg(s, 7, 2);
    agr_aot_mov_reg(s, 5, 3);
    agr_aot_cmp(s, s->r[1], 4u);
    s->r[15] = agr_aot_condition(s, 8u) ? 71472u : 71224u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001163c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 3, s->r[0], s->r[0]);
    agr_aot_cmp(s, s->r[0], 122u);
    agr_aot_lsls(s, 2, s->r[2], 1u);
    agr_aot_cmp(s, s->r[5], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 71472u : 71238u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011646(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 56u); if (rc) return rc; }
    s->r[15] = 71240u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001164a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = 71244u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001164c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls_reg(s, 2, s->r[0], s->r[5]);
    s->r[15] = 71248u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011652(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 71262u : 71252u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011654(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 71254u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001165a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 3, s->r[3], 4u);
    { uint32_t addr = s->r[6] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 71262u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001165e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 5, s->r[5], 1u);
    agr_aot_cmp(s, s->r[5], 16u);
    s->r[15] = agr_aot_condition(s, 1u) ? 71244u : 71268u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011668(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 71542u : 71276u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001166c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 56u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 71748u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011730(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    s->r[15] = 71748u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011776(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = 71748u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011844(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 264u;
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) return rc;
}

static int aot_fast_0001184c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 1, s->r[0], 52u);
    s->r[15] = 71760u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011854(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 12, 3);
    agr_aot_mov_reg(s, 14, 4);
    { uint32_t addr = (s->r[12] - 4u); s->r[12] = s->r[12] - 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    s->r[15] = 71772u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011860(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 13, 12);
    if ((rc = agr_aot_ldmia_sp(s, 32768u))) return rc;
}

static int aot_fast_00011868(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011870(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011878(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011880(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011888(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011890(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000118d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011918(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001192c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011940(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011944(AgrAotRegs *s) {
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
    agr_aot_branch_reg(s, 70072u | 1u, 72030u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001195e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[13] += 72u;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011968(AgrAotRegs *s) {
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
    agr_aot_branch_reg(s, 70190u | 1u, 72066u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011982(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[13] += 72u;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0001198c(AgrAotRegs *s) {
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
    agr_aot_branch_reg(s, 70256u | 1u, 72102u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000119a6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[13] += 72u;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000119b0(AgrAotRegs *s) {
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
    agr_aot_branch_reg(s, 70170u | 1u, 72138u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000119ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[13] += 72u;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000119d4(AgrAotRegs *s) {
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
    agr_aot_branch_reg(s, 70426u | 1u, 72174u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000119ee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[13] += 72u;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000119f8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = s->r[3] ? 72210u : 72188u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000119fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 9u); if (rc) return rc; }
    s->r[15] = !s->r[3] ? 72224u : 72192u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011a00(AgrAotRegs *s) {
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
    s->r[15] = 72212u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011a12(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 3, s->r[3], 1u);
    s->r[15] = 72212u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011a14(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[0] + 8u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_lsls(s, 2, s->r[3], 8u);
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 72220u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011a1e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011a20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 176u);
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011a24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16415u)) return AGR_AOT_FAULT;
    agr_aot_movs_imm(s, 1, 0u);
    agr_aot_add_imm(s, 3, s->r[13], 12u);
    agr_aot_movs_imm(s, 2, 12u);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_mov_reg(s, 3, 1);
    agr_aot_branch_reg(s, 70288u | 1u, 72244u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011a34(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 12u); if (rc) return rc; }
    s->r[13] += 20u;
    { uint32_t addr = s->r[13]; s->r[13] = s->r[13] + 4u; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00011a3c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 72228u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011a3e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 18431u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 5, 0);
    agr_aot_mov_reg(s, 6, 1);
    agr_aot_movs_imm(s, 7, 0u);
    agr_aot_add_imm(s, 8, s->r[13], 12u);
    s->r[9] = 4080u;
    s->r[15] = 72272u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011a50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 72184u | 1u, 72278u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011a56(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 176u);
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = agr_aot_condition(s, 1u) ? 72322u : 72284u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011a5c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[7], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 72852u : 72290u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011a62(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 4, s->r[13], 12u);
    agr_aot_mov_reg(s, 1, 7);
    agr_aot_mov_reg(s, 3, 7);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_movs_imm(s, 2, 14u);
    agr_aot_branch_reg(s, 70288u | 1u, 72306u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011a72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 1, 7);
    agr_aot_movs_imm(s, 2, 15u);
    agr_aot_mov_reg(s, 3, 7);
    agr_aot_branch_reg(s, 70356u | 1u, 72320u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011a80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 72852u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011a8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 72376u : 72332u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011a90(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 3, 1);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_movs_imm(s, 2, 13u);
    s->r[15] = 72346u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011a9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 70288u | 1u, 72354u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011aa2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 12u); if (rc) return rc; }
    agr_aot_add_imm(s, 10, s->r[10], 4u);
    s->r[15] = 72360u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011aac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_set_itstate(s, 20u); s->r[15] = 72366u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011ab8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[3] = s->r[0] & 240u;
    agr_aot_cmp(s, s->r[3], 128u);
    s->r[15] = agr_aot_condition(s, 1u) ? 72432u : 72384u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011ac0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 4, s->r[0], 8u);
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 72184u | 1u, 72392u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011aca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 32768u);
    s->r[15] = agr_aot_condition(s, 1u) ? 72404u : 72400u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011ad0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 9u);
    s->r[15] = 72854u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011ad4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 4, s->r[0], 4u);
    agr_aot_movs_imm(s, 1, 0u);
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = 72412u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011ade(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 71208u | 1u, 72418u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011ae2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 72400u : 72422u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011aea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_set_itstate(s, 24u); s->r[15] = 72428u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011af0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 144u);
    s->r[15] = agr_aot_condition(s, 1u) ? 72480u : 72436u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011af4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[3] = s->r[0] & 13u;
    agr_aot_cmp(s, s->r[3], 13u);
    s->r[15] = agr_aot_condition(s, 0u) ? 72400u : 72444u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011afc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    agr_aot_mov_reg(s, 0, 5);
    s->r[2] = s->r[4] & 15u;
    agr_aot_mov_reg(s, 3, 1);
    agr_aot_branch_reg(s, 70288u | 1u, 72462u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011b0e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_movs_imm(s, 1, 0u);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    s->r[15] = 72470u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011b16(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 2, 13u);
    agr_aot_mov_reg(s, 3, 1);
    agr_aot_branch_reg(s, 70356u | 1u, 72478u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011b1e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 72272u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011b20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 160u);
    s->r[15] = agr_aot_condition(s, 1u) ? 72512u : 72484u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011b26(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[2] = s->r[2] & 7u;
    s->r[15] = 72490u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011b2e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 3, s->r[0], 28u);
    s->r[2] = s->r[2] & 4080u;
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_set_itstate(s, 72u); s->r[15] = 72504u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011b40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 176u);
    s->r[15] = agr_aot_condition(s, 1u) ? 72668u : 72516u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011b44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 177u);
    s->r[15] = agr_aot_condition(s, 1u) ? 72544u : 72520u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011b48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 72184u | 1u, 72526u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011b4e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 2, 0);
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 72400u : 72532u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011b58(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 72400u : 72538u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011b5a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 72540u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011b5c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = 72840u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011b60(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 178u);
    s->r[15] = agr_aot_condition(s, 1u) ? 72618u : 72548u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011b64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    agr_aot_movs_imm(s, 2, 13u);
    agr_aot_mov_reg(s, 3, 1);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_movs_imm(s, 4, 2u);
    agr_aot_branch_reg(s, 70288u | 1u, 72566u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011b76(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 72184u | 1u, 72572u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011b80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 12u); if (rc) return rc; }
    s->r[0] = s->r[0] & 127u;
    s->r[15] = agr_aot_condition(s, 0u) ? 72600u : 72584u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011b8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 4, s->r[4], 7u);
    s->r[3] += s->r[0];
    agr_aot_mov_reg(s, 0, 6);
    { uint32_t addr = s->r[13] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 72184u | 1u, 72598u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011b96(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 72572u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011b98(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 3, s->r[3], 3841u);
    s->r[15] = 72604u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011b9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[0] += s->r[3];
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    { uint32_t addr = s->r[13] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 72470u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011baa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 179u);
    s->r[15] = agr_aot_condition(s, 1u) ? 72644u : 72622u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011bae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 72184u | 1u, 72628u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011bb4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 1, 1u);
    s->r[3] = s->r[0] & 15u;
    s->r[2] = s->r[0] & 240u;
    agr_aot_adds(s, 3, s->r[3], 1u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 72696u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011bc4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[3] = s->r[0] & 252u;
    agr_aot_cmp(s, s->r[3], 180u);
    s->r[15] = agr_aot_condition(s, 0u) ? 72400u : 72652u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011bcc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[4] = s->r[0] & 7u;
    agr_aot_movs_imm(s, 1, 1u);
    agr_aot_adds(s, 2, s->r[4], 1u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[2] = s->r[2] | 524288u;
    s->r[15] = 72540u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011bdc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 192u);
    s->r[15] = agr_aot_condition(s, 1u) ? 72814u : 72672u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011be0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 198u);
    s->r[15] = agr_aot_condition(s, 1u) ? 72702u : 72676u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011be4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 72184u | 1u, 72682u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011bea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 1, 3u);
    s->r[3] = s->r[0] & 15u;
    s->r[2] = s->r[0] & 240u;
    agr_aot_adds(s, 3, s->r[3], 1u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 72696u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011bfc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 72540u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011bfe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 199u);
    s->r[15] = agr_aot_condition(s, 1u) ? 72734u : 72706u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011c02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 72184u | 1u, 72712u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011c08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 2, 0);
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 72400u : 72720u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011c14(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 72400u : 72728u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011c18(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_movs_imm(s, 1, 4u);
    s->r[15] = 72840u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011c1e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[3] = s->r[0] & 248u;
    agr_aot_cmp(s, s->r[3], 192u);
    s->r[15] = agr_aot_condition(s, 1u) ? 72758u : 72742u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011c26(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[4] = s->r[0] & 15u;
    agr_aot_movs_imm(s, 1, 3u);
    agr_aot_adds(s, 2, s->r[4], 1u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[2] = s->r[2] | 655360u;
    s->r[15] = 72540u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011c36(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 200u);
    s->r[15] = agr_aot_condition(s, 1u) ? 72782u : 72762u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011c3a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 72184u | 1u, 72768u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011c40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[2] = s->r[0] & 240u;
    s->r[0] = s->r[0] & 15u;
    agr_aot_adds(s, 2, s->r[2], 16u);
    agr_aot_adds(s, 3, s->r[0], 1u);
    s->r[15] = 72804u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011c4e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 201u);
    s->r[15] = agr_aot_condition(s, 1u) ? 72400u : 72788u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011c54(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 72184u | 1u, 72794u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011c5a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[3] = s->r[0] & 15u;
    s->r[2] = s->r[0] & 240u;
    agr_aot_adds(s, 3, s->r[3], 1u);
    s->r[15] = 72804u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011c64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = 72808u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011c6c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 72838u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011c6e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[3] = s->r[0] & 248u;
    agr_aot_cmp(s, s->r[3], 208u);
    s->r[15] = agr_aot_condition(s, 1u) ? 72400u : 72824u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011c78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[4] = s->r[0] & 7u;
    agr_aot_movs_imm(s, 1, 1u);
    agr_aot_adds(s, 2, s->r[4], 1u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[2] = s->r[2] | 524288u;
    s->r[15] = 72838u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011c86(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 3, 5u);
    s->r[15] = 72840u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011c88(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 71208u | 1u, 72844u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011c8c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 72400u : 72850u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011c92(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 72272u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011c94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = 72854u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011c96(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 16u;
    if ((rc = agr_aot_ldmia_sp(s, 34800u))) return rc;
}

static int aot_fast_00011c9c(AgrAotRegs *s) {
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
    agr_aot_branch_reg(s, 72254u | 1u, 72896u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011cc0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 20u;
    { uint32_t addr = s->r[13]; s->r[13] = s->r[13] + 4u; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00011cc6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    agr_aot_branch_reg(s, 72252u | 1u, 72908u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011ccc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 72u); if (rc) return rc; }
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) return rc;
}

static int aot_fast_00011cd0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    agr_aot_branch_reg(s, 72252u | 1u, 72918u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011cd6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 76u); if (rc) return rc; }
    { int rc = agr_aot_ldrb(s, 2, s->r[3] + 7u); if (rc) return rc; }
    s->r[15] = 72922u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011cde(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 0, s->r[0], 8u);
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) return rc;
}

static int aot_fast_00011ce2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    agr_aot_branch_reg(s, 68944u, 72936u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00011ce8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    agr_aot_branch_reg(s, 68944u, 72942u, 1); return AGR_AOT_BOUNDARY;
}

const AgrAotEntry agr_aot_debug_blocks[] = {
    {68860u, aot_debug_00010cfc, 1u},
    {68864u, aot_debug_00010d00, 1u},
    {68868u, aot_debug_00010d04, 1u},
    {68872u, aot_debug_00010d08, 1u},
    {68876u, aot_debug_00010d0c, 1u},
    {68880u, aot_debug_00010d10, 1u},
    {68884u, aot_debug_00010d14, 1u},
    {68888u, aot_debug_00010d18, 1u},
    {68892u, aot_debug_00010d1c, 1u},
    {68896u, aot_debug_00010d20, 1u},
    {68900u, aot_debug_00010d24, 1u},
    {68904u, aot_debug_00010d28, 1u},
    {68908u, aot_debug_00010d2c, 1u},
    {68912u, aot_debug_00010d30, 1u},
    {68916u, aot_debug_00010d34, 1u},
    {68920u, aot_debug_00010d38, 1u},
    {68924u, aot_debug_00010d3c, 1u},
    {68928u, aot_debug_00010d40, 1u},
    {68932u, aot_debug_00010d44, 1u},
    {68936u, aot_debug_00010d48, 1u},
    {68940u, aot_debug_00010d4c, 1u},
    {68944u, aot_debug_00010d50, 1u},
    {68948u, aot_debug_00010d54, 1u},
    {68952u, aot_debug_00010d58, 1u},
    {68992u, aot_debug_00010d80, 1u},
    {68996u, aot_debug_00010d84, 1u},
    {69060u, aot_debug_00010dc4, 1u},
    {69064u, aot_debug_00010dc8, 1u},
    {69066u, aot_debug_00010dca, 1u},
    {69068u, aot_debug_00010dcc, 1u},
    {69070u, aot_debug_00010dce, 1u},
    {69072u, aot_debug_00010dd0, 1u},
    {69074u, aot_debug_00010dd2, 1u},
    {69076u, aot_debug_00010dd4, 1u},
    {69078u, aot_debug_00010dd6, 1u},
    {69082u, aot_debug_00010dda, 1u},
    {69084u, aot_debug_00010ddc, 1u},
    {69086u, aot_debug_00010dde, 1u},
    {69088u, aot_debug_00010de0, 1u},
    {69090u, aot_debug_00010de2, 1u},
    {69094u, aot_debug_00010de6, 1u},
    {69096u, aot_debug_00010de8, 1u},
    {69098u, aot_debug_00010dea, 1u},
    {69100u, aot_debug_00010dec, 1u},
    {69102u, aot_debug_00010dee, 1u},
    {69104u, aot_debug_00010df0, 1u},
    {69106u, aot_debug_00010df2, 1u},
    {69108u, aot_debug_00010df4, 1u},
    {69110u, aot_debug_00010df6, 1u},
    {69112u, aot_debug_00010df8, 1u},
    {69116u, aot_debug_00010dfc, 1u},
    {69118u, aot_debug_00010dfe, 1u},
    {69120u, aot_debug_00010e00, 1u},
    {69122u, aot_debug_00010e02, 1u},
    {69124u, aot_debug_00010e04, 1u},
    {69126u, aot_debug_00010e06, 1u},
    {69128u, aot_debug_00010e08, 1u},
    {69130u, aot_debug_00010e0a, 1u},
    {69132u, aot_debug_00010e0c, 1u},
    {69136u, aot_debug_00010e10, 1u},
    {69138u, aot_debug_00010e12, 1u},
    {69142u, aot_debug_00010e16, 1u},
    {69144u, aot_debug_00010e18, 1u},
    {69146u, aot_debug_00010e1a, 1u},
    {69148u, aot_debug_00010e1c, 1u},
    {69150u, aot_debug_00010e1e, 1u},
    {69154u, aot_debug_00010e22, 1u},
    {69156u, aot_debug_00010e24, 1u},
    {69160u, aot_debug_00010e28, 1u},
    {69162u, aot_debug_00010e2a, 1u},
    {69164u, aot_debug_00010e2c, 1u},
    {69168u, aot_debug_00010e30, 1u},
    {69170u, aot_debug_00010e32, 1u},
    {69172u, aot_debug_00010e34, 1u},
    {69176u, aot_debug_00010e38, 1u},
    {69178u, aot_debug_00010e3a, 1u},
    {69180u, aot_debug_00010e3c, 1u},
    {69184u, aot_debug_00010e40, 1u},
    {69186u, aot_debug_00010e42, 1u},
    {69188u, aot_debug_00010e44, 1u},
    {69192u, aot_debug_00010e48, 1u},
    {69194u, aot_debug_00010e4a, 1u},
    {69198u, aot_debug_00010e4e, 1u},
    {69200u, aot_debug_00010e50, 1u},
    {69202u, aot_debug_00010e52, 1u},
    {69204u, aot_debug_00010e54, 1u},
    {69206u, aot_debug_00010e56, 1u},
    {69210u, aot_debug_00010e5a, 1u},
    {69212u, aot_debug_00010e5c, 1u},
    {69214u, aot_debug_00010e5e, 1u},
    {69216u, aot_debug_00010e60, 1u},
    {69218u, aot_debug_00010e62, 1u},
    {69220u, aot_debug_00010e64, 1u},
    {69222u, aot_debug_00010e66, 1u},
    {69224u, aot_debug_00010e68, 1u},
    {69228u, aot_debug_00010e6c, 1u},
    {69230u, aot_debug_00010e6e, 1u},
    {69232u, aot_debug_00010e70, 1u},
    {69234u, aot_debug_00010e72, 1u},
    {69236u, aot_debug_00010e74, 1u},
    {69238u, aot_debug_00010e76, 1u},
    {69240u, aot_debug_00010e78, 1u},
    {69244u, aot_debug_00010e7c, 1u},
    {69246u, aot_debug_00010e7e, 1u},
    {69248u, aot_debug_00010e80, 1u},
    {69250u, aot_debug_00010e82, 1u},
    {69252u, aot_debug_00010e84, 1u},
    {69254u, aot_debug_00010e86, 1u},
    {69256u, aot_debug_00010e88, 1u},
    {69260u, aot_debug_00010e8c, 1u},
    {69262u, aot_debug_00010e8e, 1u},
    {69264u, aot_debug_00010e90, 1u},
    {69268u, aot_debug_00010e94, 1u},
    {69272u, aot_debug_00010e98, 1u},
    {69274u, aot_debug_00010e9a, 1u},
    {69276u, aot_debug_00010e9c, 1u},
    {69278u, aot_debug_00010e9e, 1u},
    {69280u, aot_debug_00010ea0, 1u},
    {69282u, aot_debug_00010ea2, 1u},
    {69284u, aot_debug_00010ea4, 1u},
    {69288u, aot_debug_00010ea8, 1u},
    {69292u, aot_debug_00010eac, 1u},
    {69294u, aot_debug_00010eae, 1u},
    {69296u, aot_debug_00010eb0, 1u},
    {69298u, aot_debug_00010eb2, 1u},
    {69300u, aot_debug_00010eb4, 1u},
    {69304u, aot_debug_00010eb8, 1u},
    {69306u, aot_debug_00010eba, 1u},
    {69308u, aot_debug_00010ebc, 1u},
    {69310u, aot_debug_00010ebe, 1u},
    {69312u, aot_debug_00010ec0, 1u},
    {69314u, aot_debug_00010ec2, 1u},
    {69316u, aot_debug_00010ec4, 1u},
    {69318u, aot_debug_00010ec6, 1u},
    {69320u, aot_debug_00010ec8, 1u},
    {69324u, aot_debug_00010ecc, 1u},
    {69326u, aot_debug_00010ece, 1u},
    {69328u, aot_debug_00010ed0, 1u},
    {69330u, aot_debug_00010ed2, 1u},
    {69332u, aot_debug_00010ed4, 1u},
    {69336u, aot_debug_00010ed8, 1u},
    {69338u, aot_debug_00010eda, 1u},
    {69340u, aot_debug_00010edc, 1u},
    {69342u, aot_debug_00010ede, 1u},
    {69346u, aot_debug_00010ee2, 1u},
    {69348u, aot_debug_00010ee4, 1u},
    {69350u, aot_debug_00010ee6, 1u},
    {69352u, aot_debug_00010ee8, 1u},
    {69354u, aot_debug_00010eea, 1u},
    {69358u, aot_debug_00010eee, 1u},
    {69360u, aot_debug_00010ef0, 1u},
    {69362u, aot_debug_00010ef2, 1u},
    {69364u, aot_debug_00010ef4, 1u},
    {69366u, aot_debug_00010ef6, 1u},
    {69368u, aot_debug_00010ef8, 1u},
    {69370u, aot_debug_00010efa, 1u},
    {69374u, aot_debug_00010efe, 1u},
    {69376u, aot_debug_00010f00, 1u},
    {69378u, aot_debug_00010f02, 1u},
    {69384u, aot_debug_00010f08, 1u},
    {69386u, aot_debug_00010f0a, 1u},
    {69388u, aot_debug_00010f0c, 1u},
    {69402u, aot_debug_00010f1a, 1u},
    {69406u, aot_debug_00010f1e, 1u},
    {69408u, aot_debug_00010f20, 1u},
    {69410u, aot_debug_00010f22, 1u},
    {69412u, aot_debug_00010f24, 1u},
    {69416u, aot_debug_00010f28, 1u},
    {69418u, aot_debug_00010f2a, 1u},
    {69420u, aot_debug_00010f2c, 1u},
    {69430u, aot_debug_00010f36, 1u},
    {69432u, aot_debug_00010f38, 1u},
    {69434u, aot_debug_00010f3a, 1u},
    {69438u, aot_debug_00010f3e, 1u},
    {69440u, aot_debug_00010f40, 1u},
    {69444u, aot_debug_00010f44, 1u},
    {69446u, aot_debug_00010f46, 1u},
    {69448u, aot_debug_00010f48, 1u},
    {69450u, aot_debug_00010f4a, 1u},
    {69452u, aot_debug_00010f4c, 1u},
    {69456u, aot_debug_00010f50, 1u},
    {69458u, aot_debug_00010f52, 1u},
    {69462u, aot_debug_00010f56, 1u},
    {69464u, aot_debug_00010f58, 1u},
    {69466u, aot_debug_00010f5a, 1u},
    {69468u, aot_debug_00010f5c, 1u},
    {69470u, aot_debug_00010f5e, 1u},
    {69474u, aot_debug_00010f62, 1u},
    {69476u, aot_debug_00010f64, 1u},
    {69478u, aot_debug_00010f66, 1u},
    {69480u, aot_debug_00010f68, 1u},
    {69482u, aot_debug_00010f6a, 1u},
    {69484u, aot_debug_00010f6c, 1u},
    {69486u, aot_debug_00010f6e, 1u},
    {69488u, aot_debug_00010f70, 1u},
    {69490u, aot_debug_00010f72, 1u},
    {69492u, aot_debug_00010f74, 1u},
    {69494u, aot_debug_00010f76, 1u},
    {69496u, aot_debug_00010f78, 1u},
    {69498u, aot_debug_00010f7a, 1u},
    {69500u, aot_debug_00010f7c, 1u},
    {69502u, aot_debug_00010f7e, 1u},
    {69506u, aot_debug_00010f82, 1u},
    {69508u, aot_debug_00010f84, 1u},
    {69510u, aot_debug_00010f86, 1u},
    {69512u, aot_debug_00010f88, 1u},
    {69514u, aot_debug_00010f8a, 1u},
    {69516u, aot_debug_00010f8c, 1u},
    {69518u, aot_debug_00010f8e, 1u},
    {69520u, aot_debug_00010f90, 1u},
    {69522u, aot_debug_00010f92, 1u},
    {69524u, aot_debug_00010f94, 1u},
    {69526u, aot_debug_00010f96, 1u},
    {69528u, aot_debug_00010f98, 1u},
    {69530u, aot_debug_00010f9a, 1u},
    {69532u, aot_debug_00010f9c, 1u},
    {69534u, aot_debug_00010f9e, 1u},
    {69536u, aot_debug_00010fa0, 1u},
    {69538u, aot_debug_00010fa2, 1u},
    {69540u, aot_debug_00010fa4, 1u},
    {69542u, aot_debug_00010fa6, 1u},
    {69544u, aot_debug_00010fa8, 1u},
    {69546u, aot_debug_00010faa, 1u},
    {69548u, aot_debug_00010fac, 1u},
    {69550u, aot_debug_00010fae, 1u},
    {69552u, aot_debug_00010fb0, 1u},
    {69554u, aot_debug_00010fb2, 1u},
    {69556u, aot_debug_00010fb4, 1u},
    {69558u, aot_debug_00010fb6, 1u},
    {69560u, aot_debug_00010fb8, 1u},
    {69562u, aot_debug_00010fba, 1u},
    {69564u, aot_debug_00010fbc, 1u},
    {69566u, aot_debug_00010fbe, 1u},
    {69568u, aot_debug_00010fc0, 1u},
    {69570u, aot_debug_00010fc2, 1u},
    {69572u, aot_debug_00010fc4, 1u},
    {69574u, aot_debug_00010fc6, 1u},
    {69578u, aot_debug_00010fca, 1u},
    {69580u, aot_debug_00010fcc, 1u},
    {69582u, aot_debug_00010fce, 1u},
    {69584u, aot_debug_00010fd0, 1u},
    {69586u, aot_debug_00010fd2, 1u},
    {69588u, aot_debug_00010fd4, 1u},
    {69590u, aot_debug_00010fd6, 1u},
    {69592u, aot_debug_00010fd8, 1u},
    {69594u, aot_debug_00010fda, 1u},
    {69596u, aot_debug_00010fdc, 1u},
    {69598u, aot_debug_00010fde, 1u},
    {69602u, aot_debug_00010fe2, 1u},
    {69604u, aot_debug_00010fe4, 1u},
    {69606u, aot_debug_00010fe6, 1u},
    {69608u, aot_debug_00010fe8, 1u},
    {69612u, aot_debug_00010fec, 1u},
    {69614u, aot_debug_00010fee, 1u},
    {69616u, aot_debug_00010ff0, 1u},
    {69618u, aot_debug_00010ff2, 1u},
    {69620u, aot_debug_00010ff4, 1u},
    {69622u, aot_debug_00010ff6, 1u},
    {69626u, aot_debug_00010ffa, 1u},
    {69628u, aot_debug_00010ffc, 1u},
    {69630u, aot_debug_00010ffe, 1u},
    {69632u, aot_debug_00011000, 1u},
    {69634u, aot_debug_00011002, 1u},
    {69636u, aot_debug_00011004, 1u},
    {69638u, aot_debug_00011006, 1u},
    {69640u, aot_debug_00011008, 1u},
    {69642u, aot_debug_0001100a, 1u},
    {69644u, aot_debug_0001100c, 1u},
    {69648u, aot_debug_00011010, 1u},
    {69650u, aot_debug_00011012, 1u},
    {69652u, aot_debug_00011014, 1u},
    {69654u, aot_debug_00011016, 1u},
    {69656u, aot_debug_00011018, 1u},
    {69660u, aot_debug_0001101c, 1u},
    {69662u, aot_debug_0001101e, 1u},
    {69664u, aot_debug_00011020, 1u},
    {69666u, aot_debug_00011022, 1u},
    {69668u, aot_debug_00011024, 1u},
    {69670u, aot_debug_00011026, 1u},
    {69672u, aot_debug_00011028, 1u},
    {69678u, aot_debug_0001102e, 1u},
    {69682u, aot_debug_00011032, 1u},
    {69684u, aot_debug_00011034, 1u},
    {69686u, aot_debug_00011036, 1u},
    {69694u, aot_debug_0001103e, 1u},
    {69698u, aot_debug_00011042, 1u},
    {69700u, aot_debug_00011044, 1u},
    {69702u, aot_debug_00011046, 1u},
    {69704u, aot_debug_00011048, 1u},
    {69720u, aot_debug_00011058, 1u},
    {69722u, aot_debug_0001105a, 1u},
    {69724u, aot_debug_0001105c, 1u},
    {69726u, aot_debug_0001105e, 1u},
    {69728u, aot_debug_00011060, 1u},
    {69734u, aot_debug_00011066, 1u},
    {69738u, aot_debug_0001106a, 1u},
    {69740u, aot_debug_0001106c, 1u},
    {69744u, aot_debug_00011070, 1u},
    {69746u, aot_debug_00011072, 1u},
    {69750u, aot_debug_00011076, 1u},
    {69752u, aot_debug_00011078, 1u},
    {69754u, aot_debug_0001107a, 1u},
    {69756u, aot_debug_0001107c, 1u},
    {69760u, aot_debug_00011080, 1u},
    {69764u, aot_debug_00011084, 1u},
    {69766u, aot_debug_00011086, 1u},
    {69768u, aot_debug_00011088, 1u},
    {69770u, aot_debug_0001108a, 1u},
    {69774u, aot_debug_0001108e, 1u},
    {69778u, aot_debug_00011092, 1u},
    {69780u, aot_debug_00011094, 1u},
    {69782u, aot_debug_00011096, 1u},
    {69784u, aot_debug_00011098, 1u},
    {69788u, aot_debug_0001109c, 1u},
    {69792u, aot_debug_000110a0, 1u},
    {69796u, aot_debug_000110a4, 1u},
    {69814u, aot_debug_000110b6, 1u},
    {69816u, aot_debug_000110b8, 1u},
    {69818u, aot_debug_000110ba, 1u},
    {69820u, aot_debug_000110bc, 1u},
    {69822u, aot_debug_000110be, 1u},
    {69824u, aot_debug_000110c0, 1u},
    {69826u, aot_debug_000110c2, 1u},
    {69830u, aot_debug_000110c6, 1u},
    {69832u, aot_debug_000110c8, 1u},
    {69834u, aot_debug_000110ca, 1u},
    {69838u, aot_debug_000110ce, 1u},
    {69840u, aot_debug_000110d0, 1u},
    {69842u, aot_debug_000110d2, 1u},
    {69844u, aot_debug_000110d4, 1u},
    {69846u, aot_debug_000110d6, 1u},
    {69848u, aot_debug_000110d8, 1u},
    {69850u, aot_debug_000110da, 1u},
    {69852u, aot_debug_000110dc, 1u},
    {69854u, aot_debug_000110de, 1u},
    {69856u, aot_debug_000110e0, 1u},
    {69858u, aot_debug_000110e2, 1u},
    {69860u, aot_debug_000110e4, 1u},
    {69862u, aot_debug_000110e6, 1u},
    {69864u, aot_debug_000110e8, 1u},
    {69868u, aot_debug_000110ec, 1u},
    {69870u, aot_debug_000110ee, 1u},
    {69874u, aot_debug_000110f2, 1u},
    {69878u, aot_debug_000110f6, 1u},
    {69880u, aot_debug_000110f8, 1u},
    {69884u, aot_debug_000110fc, 1u},
    {69886u, aot_debug_000110fe, 1u},
    {69890u, aot_debug_00011102, 1u},
    {69898u, aot_debug_0001110a, 1u},
    {69900u, aot_debug_0001110c, 1u},
    {69916u, aot_debug_0001111c, 1u},
    {69918u, aot_debug_0001111e, 1u},
    {69922u, aot_debug_00011122, 1u},
    {69924u, aot_debug_00011124, 1u},
    {69926u, aot_debug_00011126, 1u},
    {69928u, aot_debug_00011128, 1u},
    {69930u, aot_debug_0001112a, 1u},
    {69932u, aot_debug_0001112c, 1u},
    {69936u, aot_debug_00011130, 1u},
    {69940u, aot_debug_00011134, 1u},
    {70068u, aot_debug_000111b4, 1u},
    {70070u, aot_debug_000111b6, 1u},
    {70072u, aot_debug_000111b8, 1u},
    {70074u, aot_debug_000111ba, 1u},
    {70078u, aot_debug_000111be, 1u},
    {70080u, aot_debug_000111c0, 1u},
    {70082u, aot_debug_000111c2, 1u},
    {70084u, aot_debug_000111c4, 1u},
    {70086u, aot_debug_000111c6, 1u},
    {70090u, aot_debug_000111ca, 1u},
    {70092u, aot_debug_000111cc, 1u},
    {70108u, aot_debug_000111dc, 1u},
    {70112u, aot_debug_000111e0, 1u},
    {70116u, aot_debug_000111e4, 1u},
    {70118u, aot_debug_000111e6, 1u},
    {70120u, aot_debug_000111e8, 1u},
    {70124u, aot_debug_000111ec, 1u},
    {70128u, aot_debug_000111f0, 1u},
    {70130u, aot_debug_000111f2, 1u},
    {70132u, aot_debug_000111f4, 1u},
    {70134u, aot_debug_000111f6, 1u},
    {70136u, aot_debug_000111f8, 1u},
    {70138u, aot_debug_000111fa, 1u},
    {70140u, aot_debug_000111fc, 1u},
    {70142u, aot_debug_000111fe, 1u},
    {70144u, aot_debug_00011200, 1u},
    {70146u, aot_debug_00011202, 1u},
    {70150u, aot_debug_00011206, 1u},
    {70152u, aot_debug_00011208, 1u},
    {70154u, aot_debug_0001120a, 1u},
    {70156u, aot_debug_0001120c, 1u},
    {70158u, aot_debug_0001120e, 1u},
    {70162u, aot_debug_00011212, 1u},
    {70164u, aot_debug_00011214, 1u},
    {70166u, aot_debug_00011216, 1u},
    {70170u, aot_debug_0001121a, 1u},
    {70172u, aot_debug_0001121c, 1u},
    {70174u, aot_debug_0001121e, 1u},
    {70176u, aot_debug_00011220, 1u},
    {70178u, aot_debug_00011222, 1u},
    {70180u, aot_debug_00011224, 1u},
    {70184u, aot_debug_00011228, 1u},
    {70186u, aot_debug_0001122a, 1u},
    {70188u, aot_debug_0001122c, 1u},
    {70190u, aot_debug_0001122e, 1u},
    {70192u, aot_debug_00011230, 1u},
    {70194u, aot_debug_00011232, 1u},
    {70196u, aot_debug_00011234, 1u},
    {70198u, aot_debug_00011236, 1u},
    {70200u, aot_debug_00011238, 1u},
    {70202u, aot_debug_0001123a, 1u},
    {70204u, aot_debug_0001123c, 1u},
    {70206u, aot_debug_0001123e, 1u},
    {70210u, aot_debug_00011242, 1u},
    {70212u, aot_debug_00011244, 1u},
    {70214u, aot_debug_00011246, 1u},
    {70216u, aot_debug_00011248, 1u},
    {70218u, aot_debug_0001124a, 1u},
    {70220u, aot_debug_0001124c, 1u},
    {70222u, aot_debug_0001124e, 1u},
    {70224u, aot_debug_00011250, 1u},
    {70226u, aot_debug_00011252, 1u},
    {70228u, aot_debug_00011254, 1u},
    {70230u, aot_debug_00011256, 1u},
    {70232u, aot_debug_00011258, 1u},
    {70234u, aot_debug_0001125a, 1u},
    {70238u, aot_debug_0001125e, 1u},
    {70240u, aot_debug_00011260, 1u},
    {70242u, aot_debug_00011262, 1u},
    {70246u, aot_debug_00011266, 1u},
    {70248u, aot_debug_00011268, 1u},
    {70252u, aot_debug_0001126c, 1u},
    {70256u, aot_debug_00011270, 1u},
    {70258u, aot_debug_00011272, 1u},
    {70260u, aot_debug_00011274, 1u},
    {70264u, aot_debug_00011278, 1u},
    {70266u, aot_debug_0001127a, 1u},
    {70268u, aot_debug_0001127c, 1u},
    {70270u, aot_debug_0001127e, 1u},
    {70272u, aot_debug_00011280, 1u},
    {70274u, aot_debug_00011282, 1u},
    {70276u, aot_debug_00011284, 1u},
    {70278u, aot_debug_00011286, 1u},
    {70280u, aot_debug_00011288, 1u},
    {70282u, aot_debug_0001128a, 1u},
    {70284u, aot_debug_0001128c, 1u},
    {70286u, aot_debug_0001128e, 1u},
    {70288u, aot_debug_00011290, 1u},
    {70290u, aot_debug_00011292, 1u},
    {70292u, aot_debug_00011294, 1u},
    {70298u, aot_debug_0001129a, 1u},
    {70300u, aot_debug_0001129c, 1u},
    {70302u, aot_debug_0001129e, 1u},
    {70304u, aot_debug_000112a0, 1u},
    {70306u, aot_debug_000112a2, 1u},
    {70328u, aot_debug_000112b8, 1u},
    {70330u, aot_debug_000112ba, 1u},
    {70356u, aot_debug_000112d4, 1u},
    {70358u, aot_debug_000112d6, 1u},
    {70360u, aot_debug_000112d8, 1u},
    {70366u, aot_debug_000112de, 1u},
    {70368u, aot_debug_000112e0, 1u},
    {70370u, aot_debug_000112e2, 1u},
    {70372u, aot_debug_000112e4, 1u},
    {70374u, aot_debug_000112e6, 1u},
    {70396u, aot_debug_000112fc, 1u},
    {70398u, aot_debug_000112fe, 1u},
    {70400u, aot_debug_00011300, 1u},
    {70402u, aot_debug_00011302, 1u},
    {70404u, aot_debug_00011304, 1u},
    {70406u, aot_debug_00011306, 1u},
    {70408u, aot_debug_00011308, 1u},
    {70412u, aot_debug_0001130c, 1u},
    {70414u, aot_debug_0001130e, 1u},
    {70416u, aot_debug_00011310, 1u},
    {70418u, aot_debug_00011312, 1u},
    {70422u, aot_debug_00011316, 1u},
    {70424u, aot_debug_00011318, 1u},
    {70426u, aot_debug_0001131a, 1u},
    {70428u, aot_debug_0001131c, 1u},
    {70432u, aot_debug_00011320, 1u},
    {70434u, aot_debug_00011322, 1u},
    {70436u, aot_debug_00011324, 1u},
    {70438u, aot_debug_00011326, 1u},
    {70446u, aot_debug_0001132e, 1u},
    {70448u, aot_debug_00011330, 1u},
    {70464u, aot_debug_00011340, 1u},
    {70468u, aot_debug_00011344, 1u},
    {70470u, aot_debug_00011346, 1u},
    {70474u, aot_debug_0001134a, 1u},
    {70476u, aot_debug_0001134c, 1u},
    {70478u, aot_debug_0001134e, 1u},
    {70480u, aot_debug_00011350, 1u},
    {70484u, aot_debug_00011354, 1u},
    {70486u, aot_debug_00011356, 1u},
    {70488u, aot_debug_00011358, 1u},
    {70490u, aot_debug_0001135a, 1u},
    {70492u, aot_debug_0001135c, 1u},
    {70494u, aot_debug_0001135e, 1u},
    {70496u, aot_debug_00011360, 1u},
    {70500u, aot_debug_00011364, 1u},
    {70502u, aot_debug_00011366, 1u},
    {70504u, aot_debug_00011368, 1u},
    {70506u, aot_debug_0001136a, 1u},
    {70508u, aot_debug_0001136c, 1u},
    {70510u, aot_debug_0001136e, 1u},
    {70512u, aot_debug_00011370, 1u},
    {70514u, aot_debug_00011372, 1u},
    {70516u, aot_debug_00011374, 1u},
    {70518u, aot_debug_00011376, 1u},
    {70520u, aot_debug_00011378, 1u},
    {70522u, aot_debug_0001137a, 1u},
    {70524u, aot_debug_0001137c, 1u},
    {70526u, aot_debug_0001137e, 1u},
    {70528u, aot_debug_00011380, 1u},
    {70530u, aot_debug_00011382, 1u},
    {70532u, aot_debug_00011384, 1u},
    {70534u, aot_debug_00011386, 1u},
    {70538u, aot_debug_0001138a, 1u},
    {70540u, aot_debug_0001138c, 1u},
    {70544u, aot_debug_00011390, 1u},
    {70548u, aot_debug_00011394, 1u},
    {70552u, aot_debug_00011398, 1u},
    {70554u, aot_debug_0001139a, 1u},
    {70556u, aot_debug_0001139c, 1u},
    {70558u, aot_debug_0001139e, 1u},
    {70560u, aot_debug_000113a0, 1u},
    {70562u, aot_debug_000113a2, 1u},
    {70564u, aot_debug_000113a4, 1u},
    {70568u, aot_debug_000113a8, 1u},
    {70570u, aot_debug_000113aa, 1u},
    {70572u, aot_debug_000113ac, 1u},
    {70574u, aot_debug_000113ae, 1u},
    {70576u, aot_debug_000113b0, 1u},
    {70578u, aot_debug_000113b2, 1u},
    {70580u, aot_debug_000113b4, 1u},
    {70584u, aot_debug_000113b8, 1u},
    {70586u, aot_debug_000113ba, 1u},
    {70588u, aot_debug_000113bc, 1u},
    {70592u, aot_debug_000113c0, 1u},
    {70594u, aot_debug_000113c2, 1u},
    {70596u, aot_debug_000113c4, 1u},
    {70600u, aot_debug_000113c8, 1u},
    {70604u, aot_debug_000113cc, 1u},
    {70606u, aot_debug_000113ce, 1u},
    {70608u, aot_debug_000113d0, 1u},
    {70610u, aot_debug_000113d2, 1u},
    {70612u, aot_debug_000113d4, 1u},
    {70620u, aot_debug_000113dc, 1u},
    {70624u, aot_debug_000113e0, 1u},
    {70626u, aot_debug_000113e2, 1u},
    {71196u, aot_debug_0001161c, 1u},
    {71198u, aot_debug_0001161e, 1u},
    {71200u, aot_debug_00011620, 1u},
    {71202u, aot_debug_00011622, 1u},
    {71204u, aot_debug_00011624, 1u},
    {71206u, aot_debug_00011626, 1u},
    {71208u, aot_debug_00011628, 1u},
    {71212u, aot_debug_0001162c, 1u},
    {71214u, aot_debug_0001162e, 1u},
    {71216u, aot_debug_00011630, 1u},
    {71218u, aot_debug_00011632, 1u},
    {71220u, aot_debug_00011634, 1u},
    {71222u, aot_debug_00011636, 1u},
    {71228u, aot_debug_0001163c, 1u},
    {71230u, aot_debug_0001163e, 1u},
    {71232u, aot_debug_00011640, 1u},
    {71234u, aot_debug_00011642, 1u},
    {71236u, aot_debug_00011644, 1u},
    {71238u, aot_debug_00011646, 1u},
    {71242u, aot_debug_0001164a, 1u},
    {71244u, aot_debug_0001164c, 1u},
    {71250u, aot_debug_00011652, 1u},
    {71252u, aot_debug_00011654, 1u},
    {71258u, aot_debug_0001165a, 1u},
    {71260u, aot_debug_0001165c, 1u},
    {71262u, aot_debug_0001165e, 1u},
    {71264u, aot_debug_00011660, 1u},
    {71266u, aot_debug_00011662, 1u},
    {71272u, aot_debug_00011668, 1u},
    {71276u, aot_debug_0001166c, 1u},
    {71278u, aot_debug_0001166e, 1u},
    {71472u, aot_debug_00011730, 1u},
    {71474u, aot_debug_00011732, 1u},
    {71542u, aot_debug_00011776, 1u},
    {71544u, aot_debug_00011778, 1u},
    {71748u, aot_debug_00011844, 1u},
    {71750u, aot_debug_00011846, 1u},
    {71756u, aot_debug_0001184c, 1u},
    {71764u, aot_debug_00011854, 1u},
    {71766u, aot_debug_00011856, 1u},
    {71768u, aot_debug_00011858, 1u},
    {71776u, aot_debug_00011860, 1u},
    {71778u, aot_debug_00011862, 1u},
    {71784u, aot_debug_00011868, 1u},
    {71792u, aot_debug_00011870, 1u},
    {71800u, aot_debug_00011878, 1u},
    {71808u, aot_debug_00011880, 1u},
    {71816u, aot_debug_00011888, 1u},
    {71824u, aot_debug_00011890, 1u},
    {71892u, aot_debug_000118d4, 1u},
    {71960u, aot_debug_00011918, 1u},
    {71980u, aot_debug_0001192c, 1u},
    {72000u, aot_debug_00011940, 1u},
    {72004u, aot_debug_00011944, 1u},
    {72006u, aot_debug_00011946, 1u},
    {72008u, aot_debug_00011948, 1u},
    {72012u, aot_debug_0001194c, 1u},
    {72016u, aot_debug_00011950, 1u},
    {72020u, aot_debug_00011954, 1u},
    {72024u, aot_debug_00011958, 1u},
    {72026u, aot_debug_0001195a, 1u},
    {72030u, aot_debug_0001195e, 1u},
    {72034u, aot_debug_00011962, 1u},
    {72036u, aot_debug_00011964, 1u},
    {72040u, aot_debug_00011968, 1u},
    {72042u, aot_debug_0001196a, 1u},
    {72044u, aot_debug_0001196c, 1u},
    {72048u, aot_debug_00011970, 1u},
    {72052u, aot_debug_00011974, 1u},
    {72056u, aot_debug_00011978, 1u},
    {72060u, aot_debug_0001197c, 1u},
    {72062u, aot_debug_0001197e, 1u},
    {72066u, aot_debug_00011982, 1u},
    {72070u, aot_debug_00011986, 1u},
    {72072u, aot_debug_00011988, 1u},
    {72076u, aot_debug_0001198c, 1u},
    {72078u, aot_debug_0001198e, 1u},
    {72080u, aot_debug_00011990, 1u},
    {72084u, aot_debug_00011994, 1u},
    {72088u, aot_debug_00011998, 1u},
    {72092u, aot_debug_0001199c, 1u},
    {72096u, aot_debug_000119a0, 1u},
    {72098u, aot_debug_000119a2, 1u},
    {72102u, aot_debug_000119a6, 1u},
    {72106u, aot_debug_000119aa, 1u},
    {72108u, aot_debug_000119ac, 1u},
    {72112u, aot_debug_000119b0, 1u},
    {72114u, aot_debug_000119b2, 1u},
    {72116u, aot_debug_000119b4, 1u},
    {72120u, aot_debug_000119b8, 1u},
    {72124u, aot_debug_000119bc, 1u},
    {72128u, aot_debug_000119c0, 1u},
    {72132u, aot_debug_000119c4, 1u},
    {72134u, aot_debug_000119c6, 1u},
    {72138u, aot_debug_000119ca, 1u},
    {72142u, aot_debug_000119ce, 1u},
    {72144u, aot_debug_000119d0, 1u},
    {72148u, aot_debug_000119d4, 1u},
    {72150u, aot_debug_000119d6, 1u},
    {72152u, aot_debug_000119d8, 1u},
    {72156u, aot_debug_000119dc, 1u},
    {72160u, aot_debug_000119e0, 1u},
    {72164u, aot_debug_000119e4, 1u},
    {72168u, aot_debug_000119e8, 1u},
    {72170u, aot_debug_000119ea, 1u},
    {72174u, aot_debug_000119ee, 1u},
    {72178u, aot_debug_000119f2, 1u},
    {72180u, aot_debug_000119f4, 1u},
    {72184u, aot_debug_000119f8, 1u},
    {72186u, aot_debug_000119fa, 1u},
    {72188u, aot_debug_000119fc, 1u},
    {72190u, aot_debug_000119fe, 1u},
    {72192u, aot_debug_00011a00, 1u},
    {72194u, aot_debug_00011a02, 1u},
    {72196u, aot_debug_00011a04, 1u},
    {72198u, aot_debug_00011a06, 1u},
    {72200u, aot_debug_00011a08, 1u},
    {72202u, aot_debug_00011a0a, 1u},
    {72204u, aot_debug_00011a0c, 1u},
    {72206u, aot_debug_00011a0e, 1u},
    {72208u, aot_debug_00011a10, 1u},
    {72210u, aot_debug_00011a12, 1u},
    {72212u, aot_debug_00011a14, 1u},
    {72214u, aot_debug_00011a16, 1u},
    {72216u, aot_debug_00011a18, 1u},
    {72218u, aot_debug_00011a1a, 1u},
    {72222u, aot_debug_00011a1e, 1u},
    {72224u, aot_debug_00011a20, 1u},
    {72226u, aot_debug_00011a22, 1u},
    {72228u, aot_debug_00011a24, 1u},
    {72230u, aot_debug_00011a26, 1u},
    {72232u, aot_debug_00011a28, 1u},
    {72234u, aot_debug_00011a2a, 1u},
    {72236u, aot_debug_00011a2c, 1u},
    {72238u, aot_debug_00011a2e, 1u},
    {72240u, aot_debug_00011a30, 1u},
    {72244u, aot_debug_00011a34, 1u},
    {72246u, aot_debug_00011a36, 1u},
    {72248u, aot_debug_00011a38, 1u},
    {72252u, aot_debug_00011a3c, 1u},
    {72254u, aot_debug_00011a3e, 1u},
    {72258u, aot_debug_00011a42, 1u},
    {72260u, aot_debug_00011a44, 1u},
    {72262u, aot_debug_00011a46, 1u},
    {72264u, aot_debug_00011a48, 1u},
    {72268u, aot_debug_00011a4c, 1u},
    {72272u, aot_debug_00011a50, 1u},
    {72274u, aot_debug_00011a52, 1u},
    {72278u, aot_debug_00011a56, 1u},
    {72280u, aot_debug_00011a58, 1u},
    {72282u, aot_debug_00011a5a, 1u},
    {72284u, aot_debug_00011a5c, 1u},
    {72286u, aot_debug_00011a5e, 1u},
    {72290u, aot_debug_00011a62, 1u},
    {72292u, aot_debug_00011a64, 1u},
    {72294u, aot_debug_00011a66, 1u},
    {72296u, aot_debug_00011a68, 1u},
    {72298u, aot_debug_00011a6a, 1u},
    {72300u, aot_debug_00011a6c, 1u},
    {72302u, aot_debug_00011a6e, 1u},
    {72306u, aot_debug_00011a72, 1u},
    {72308u, aot_debug_00011a74, 1u},
    {72310u, aot_debug_00011a76, 1u},
    {72312u, aot_debug_00011a78, 1u},
    {72314u, aot_debug_00011a7a, 1u},
    {72316u, aot_debug_00011a7c, 1u},
    {72320u, aot_debug_00011a80, 1u},
    {72330u, aot_debug_00011a8a, 1u},
    {72336u, aot_debug_00011a90, 1u},
    {72338u, aot_debug_00011a92, 1u},
    {72342u, aot_debug_00011a96, 1u},
    {72344u, aot_debug_00011a98, 1u},
    {72350u, aot_debug_00011a9e, 1u},
    {72354u, aot_debug_00011aa2, 1u},
    {72356u, aot_debug_00011aa4, 1u},
    {72364u, aot_debug_00011aac, 1u},
    {72376u, aot_debug_00011ab8, 1u},
    {72380u, aot_debug_00011abc, 1u},
    {72382u, aot_debug_00011abe, 1u},
    {72384u, aot_debug_00011ac0, 1u},
    {72386u, aot_debug_00011ac2, 1u},
    {72388u, aot_debug_00011ac4, 1u},
    {72394u, aot_debug_00011aca, 1u},
    {72398u, aot_debug_00011ace, 1u},
    {72400u, aot_debug_00011ad0, 1u},
    {72402u, aot_debug_00011ad2, 1u},
    {72404u, aot_debug_00011ad4, 1u},
    {72406u, aot_debug_00011ad6, 1u},
    {72408u, aot_debug_00011ad8, 1u},
    {72410u, aot_debug_00011ada, 1u},
    {72414u, aot_debug_00011ade, 1u},
    {72418u, aot_debug_00011ae2, 1u},
    {72420u, aot_debug_00011ae4, 1u},
    {72426u, aot_debug_00011aea, 1u},
    {72432u, aot_debug_00011af0, 1u},
    {72434u, aot_debug_00011af2, 1u},
    {72436u, aot_debug_00011af4, 1u},
    {72440u, aot_debug_00011af8, 1u},
    {72442u, aot_debug_00011afa, 1u},
    {72444u, aot_debug_00011afc, 1u},
    {72446u, aot_debug_00011afe, 1u},
    {72450u, aot_debug_00011b02, 1u},
    {72452u, aot_debug_00011b04, 1u},
    {72456u, aot_debug_00011b08, 1u},
    {72458u, aot_debug_00011b0a, 1u},
    {72462u, aot_debug_00011b0e, 1u},
    {72464u, aot_debug_00011b10, 1u},
    {72466u, aot_debug_00011b12, 1u},
    {72470u, aot_debug_00011b16, 1u},
    {72472u, aot_debug_00011b18, 1u},
    {72474u, aot_debug_00011b1a, 1u},
    {72478u, aot_debug_00011b1e, 1u},
    {72480u, aot_debug_00011b20, 1u},
    {72482u, aot_debug_00011b22, 1u},
    {72486u, aot_debug_00011b26, 1u},
    {72494u, aot_debug_00011b2e, 1u},
    {72496u, aot_debug_00011b30, 1u},
    {72500u, aot_debug_00011b34, 1u},
    {72502u, aot_debug_00011b36, 1u},
    {72512u, aot_debug_00011b40, 1u},
    {72514u, aot_debug_00011b42, 1u},
    {72516u, aot_debug_00011b44, 1u},
    {72518u, aot_debug_00011b46, 1u},
    {72520u, aot_debug_00011b48, 1u},
    {72522u, aot_debug_00011b4a, 1u},
    {72526u, aot_debug_00011b4e, 1u},
    {72528u, aot_debug_00011b50, 1u},
    {72530u, aot_debug_00011b52, 1u},
    {72536u, aot_debug_00011b58, 1u},
    {72538u, aot_debug_00011b5a, 1u},
    {72540u, aot_debug_00011b5c, 1u},
    {72542u, aot_debug_00011b5e, 1u},
    {72544u, aot_debug_00011b60, 1u},
    {72546u, aot_debug_00011b62, 1u},
    {72548u, aot_debug_00011b64, 1u},
    {72550u, aot_debug_00011b66, 1u},
    {72552u, aot_debug_00011b68, 1u},
    {72554u, aot_debug_00011b6a, 1u},
    {72558u, aot_debug_00011b6e, 1u},
    {72560u, aot_debug_00011b70, 1u},
    {72562u, aot_debug_00011b72, 1u},
    {72566u, aot_debug_00011b76, 1u},
    {72568u, aot_debug_00011b78, 1u},
    {72576u, aot_debug_00011b80, 1u},
    {72578u, aot_debug_00011b82, 1u},
    {72582u, aot_debug_00011b86, 1u},
    {72586u, aot_debug_00011b8a, 1u},
    {72588u, aot_debug_00011b8c, 1u},
    {72590u, aot_debug_00011b8e, 1u},
    {72592u, aot_debug_00011b90, 1u},
    {72594u, aot_debug_00011b92, 1u},
    {72598u, aot_debug_00011b96, 1u},
    {72600u, aot_debug_00011b98, 1u},
    {72606u, aot_debug_00011b9e, 1u},
    {72608u, aot_debug_00011ba0, 1u},
    {72612u, aot_debug_00011ba4, 1u},
    {72614u, aot_debug_00011ba6, 1u},
    {72616u, aot_debug_00011ba8, 1u},
    {72618u, aot_debug_00011baa, 1u},
    {72620u, aot_debug_00011bac, 1u},
    {72622u, aot_debug_00011bae, 1u},
    {72624u, aot_debug_00011bb0, 1u},
    {72628u, aot_debug_00011bb4, 1u},
    {72630u, aot_debug_00011bb6, 1u},
    {72634u, aot_debug_00011bba, 1u},
    {72638u, aot_debug_00011bbe, 1u},
    {72640u, aot_debug_00011bc0, 1u},
    {72642u, aot_debug_00011bc2, 1u},
    {72644u, aot_debug_00011bc4, 1u},
    {72648u, aot_debug_00011bc8, 1u},
    {72650u, aot_debug_00011bca, 1u},
    {72652u, aot_debug_00011bcc, 1u},
    {72656u, aot_debug_00011bd0, 1u},
    {72658u, aot_debug_00011bd2, 1u},
    {72660u, aot_debug_00011bd4, 1u},
    {72662u, aot_debug_00011bd6, 1u},
    {72666u, aot_debug_00011bda, 1u},
    {72668u, aot_debug_00011bdc, 1u},
    {72670u, aot_debug_00011bde, 1u},
    {72672u, aot_debug_00011be0, 1u},
    {72674u, aot_debug_00011be2, 1u},
    {72676u, aot_debug_00011be4, 1u},
    {72678u, aot_debug_00011be6, 1u},
    {72682u, aot_debug_00011bea, 1u},
    {72684u, aot_debug_00011bec, 1u},
    {72688u, aot_debug_00011bf0, 1u},
    {72692u, aot_debug_00011bf4, 1u},
    {72694u, aot_debug_00011bf6, 1u},
    {72700u, aot_debug_00011bfc, 1u},
    {72702u, aot_debug_00011bfe, 1u},
    {72704u, aot_debug_00011c00, 1u},
    {72706u, aot_debug_00011c02, 1u},
    {72708u, aot_debug_00011c04, 1u},
    {72712u, aot_debug_00011c08, 1u},
    {72714u, aot_debug_00011c0a, 1u},
    {72716u, aot_debug_00011c0c, 1u},
    {72724u, aot_debug_00011c14, 1u},
    {72728u, aot_debug_00011c18, 1u},
    {72730u, aot_debug_00011c1a, 1u},
    {72732u, aot_debug_00011c1c, 1u},
    {72734u, aot_debug_00011c1e, 1u},
    {72738u, aot_debug_00011c22, 1u},
    {72740u, aot_debug_00011c24, 1u},
    {72742u, aot_debug_00011c26, 1u},
    {72746u, aot_debug_00011c2a, 1u},
    {72748u, aot_debug_00011c2c, 1u},
    {72750u, aot_debug_00011c2e, 1u},
    {72752u, aot_debug_00011c30, 1u},
    {72756u, aot_debug_00011c34, 1u},
    {72758u, aot_debug_00011c36, 1u},
    {72760u, aot_debug_00011c38, 1u},
    {72762u, aot_debug_00011c3a, 1u},
    {72764u, aot_debug_00011c3c, 1u},
    {72768u, aot_debug_00011c40, 1u},
    {72772u, aot_debug_00011c44, 1u},
    {72776u, aot_debug_00011c48, 1u},
    {72778u, aot_debug_00011c4a, 1u},
    {72780u, aot_debug_00011c4c, 1u},
    {72782u, aot_debug_00011c4e, 1u},
    {72784u, aot_debug_00011c50, 1u},
    {72788u, aot_debug_00011c54, 1u},
    {72790u, aot_debug_00011c56, 1u},
    {72794u, aot_debug_00011c5a, 1u},
    {72798u, aot_debug_00011c5e, 1u},
    {72802u, aot_debug_00011c62, 1u},
    {72804u, aot_debug_00011c64, 1u},
    {72806u, aot_debug_00011c66, 1u},
    {72812u, aot_debug_00011c6c, 1u},
    {72814u, aot_debug_00011c6e, 1u},
    {72818u, aot_debug_00011c72, 1u},
    {72820u, aot_debug_00011c74, 1u},
    {72824u, aot_debug_00011c78, 1u},
    {72828u, aot_debug_00011c7c, 1u},
    {72830u, aot_debug_00011c7e, 1u},
    {72832u, aot_debug_00011c80, 1u},
    {72834u, aot_debug_00011c82, 1u},
    {72838u, aot_debug_00011c86, 1u},
    {72840u, aot_debug_00011c88, 1u},
    {72844u, aot_debug_00011c8c, 1u},
    {72846u, aot_debug_00011c8e, 1u},
    {72850u, aot_debug_00011c92, 1u},
    {72852u, aot_debug_00011c94, 1u},
    {72854u, aot_debug_00011c96, 1u},
    {72856u, aot_debug_00011c98, 1u},
    {72860u, aot_debug_00011c9c, 1u},
    {72862u, aot_debug_00011c9e, 1u},
    {72864u, aot_debug_00011ca0, 1u},
    {72866u, aot_debug_00011ca2, 1u},
    {72868u, aot_debug_00011ca4, 1u},
    {72870u, aot_debug_00011ca6, 1u},
    {72872u, aot_debug_00011ca8, 1u},
    {72874u, aot_debug_00011caa, 1u},
    {72878u, aot_debug_00011cae, 1u},
    {72880u, aot_debug_00011cb0, 1u},
    {72882u, aot_debug_00011cb2, 1u},
    {72886u, aot_debug_00011cb6, 1u},
    {72888u, aot_debug_00011cb8, 1u},
    {72892u, aot_debug_00011cbc, 1u},
    {72896u, aot_debug_00011cc0, 1u},
    {72898u, aot_debug_00011cc2, 1u},
    {72902u, aot_debug_00011cc6, 1u},
    {72904u, aot_debug_00011cc8, 1u},
    {72908u, aot_debug_00011ccc, 1u},
    {72910u, aot_debug_00011cce, 1u},
    {72912u, aot_debug_00011cd0, 1u},
    {72914u, aot_debug_00011cd2, 1u},
    {72918u, aot_debug_00011cd6, 1u},
    {72920u, aot_debug_00011cd8, 1u},
    {72926u, aot_debug_00011cde, 1u},
    {72928u, aot_debug_00011ce0, 1u},
    {72930u, aot_debug_00011ce2, 1u},
    {72932u, aot_debug_00011ce4, 1u},
    {72936u, aot_debug_00011ce8, 1u},
    {72938u, aot_debug_00011cea, 1u},
};
const uint32_t agr_aot_debug_block_count = 925u;

const AgrAotEntry agr_aot_fast_blocks[] = {
    {68860u, aot_fast_00010cfc, 3u},
    {68872u, aot_fast_00010d08, 3u},
    {68884u, aot_fast_00010d14, 3u},
    {68896u, aot_fast_00010d20, 3u},
    {68908u, aot_fast_00010d2c, 3u},
    {68920u, aot_fast_00010d38, 3u},
    {68932u, aot_fast_00010d44, 3u},
    {68944u, aot_fast_00010d50, 3u},
    {68992u, aot_fast_00010d80, 2u},
    {69060u, aot_fast_00010dc4, 10u},
    {69084u, aot_fast_00010ddc, 7u},
    {69100u, aot_fast_00010dec, 2u},
    {69104u, aot_fast_00010df0, 6u},
    {69118u, aot_fast_00010dfe, 2u},
    {69122u, aot_fast_00010e02, 1u},
    {69124u, aot_fast_00010e04, 6u},
    {69138u, aot_fast_00010e12, 6u},
    {69154u, aot_fast_00010e22, 5u},
    {69168u, aot_fast_00010e30, 1u},
    {69170u, aot_fast_00010e32, 5u},
    {69184u, aot_fast_00010e40, 5u},
    {69198u, aot_fast_00010e4e, 7u},
    {69214u, aot_fast_00010e5e, 1u},
    {69216u, aot_fast_00010e60, 7u},
    {69232u, aot_fast_00010e70, 7u},
    {69248u, aot_fast_00010e80, 7u},
    {69264u, aot_fast_00010e90, 1u},
    {69268u, aot_fast_00010e94, 10u},
    {69294u, aot_fast_00010eae, 7u},
    {69310u, aot_fast_00010ebe, 6u},
    {69324u, aot_fast_00010ecc, 5u},
    {69336u, aot_fast_00010ed8, 4u},
    {69346u, aot_fast_00010ee2, 7u},
    {69362u, aot_fast_00010ef2, 7u},
    {69378u, aot_fast_00010f02, 1u},
    {69384u, aot_fast_00010f08, 3u},
    {69402u, aot_fast_00010f1a, 4u},
    {69412u, aot_fast_00010f24, 3u},
    {69420u, aot_fast_00010f2c, 1u},
    {69430u, aot_fast_00010f36, 5u},
    {69444u, aot_fast_00010f44, 4u},
    {69452u, aot_fast_00010f4c, 3u},
    {69462u, aot_fast_00010f56, 2u},
    {69466u, aot_fast_00010f5a, 2u},
    {69470u, aot_fast_00010f5e, 2u},
    {69476u, aot_fast_00010f64, 3u},
    {69482u, aot_fast_00010f6a, 2u},
    {69486u, aot_fast_00010f6e, 2u},
    {69490u, aot_fast_00010f72, 2u},
    {69494u, aot_fast_00010f76, 2u},
    {69498u, aot_fast_00010f7a, 3u},
    {69506u, aot_fast_00010f82, 2u},
    {69510u, aot_fast_00010f86, 2u},
    {69514u, aot_fast_00010f8a, 1u},
    {69516u, aot_fast_00010f8c, 4u},
    {69524u, aot_fast_00010f94, 4u},
    {69532u, aot_fast_00010f9c, 4u},
    {69540u, aot_fast_00010fa4, 2u},
    {69544u, aot_fast_00010fa8, 6u},
    {69556u, aot_fast_00010fb4, 7u},
    {69570u, aot_fast_00010fc2, 3u},
    {69578u, aot_fast_00010fca, 2u},
    {69582u, aot_fast_00010fce, 1u},
    {69584u, aot_fast_00010fd0, 8u},
    {69602u, aot_fast_00010fe2, 1u},
    {69604u, aot_fast_00010fe4, 3u},
    {69612u, aot_fast_00010fec, 2u},
    {69616u, aot_fast_00010ff0, 3u},
    {69622u, aot_fast_00010ff6, 1u},
    {69626u, aot_fast_00010ffa, 4u},
    {69634u, aot_fast_00011002, 4u},
    {69642u, aot_fast_0001100a, 3u},
    {69650u, aot_fast_00011012, 3u},
    {69656u, aot_fast_00011018, 1u},
    {69660u, aot_fast_0001101c, 2u},
    {69664u, aot_fast_00011020, 5u},
    {69678u, aot_fast_0001102e, 1u},
    {69682u, aot_fast_00011032, 3u},
    {69694u, aot_fast_0001103e, 1u},
    {69698u, aot_fast_00011042, 2u},
    {69702u, aot_fast_00011046, 2u},
    {69720u, aot_fast_00011058, 5u},
    {69734u, aot_fast_00011066, 2u},
    {69740u, aot_fast_0001106c, 1u},
    {69744u, aot_fast_00011070, 1u},
    {69746u, aot_fast_00011072, 1u},
    {69750u, aot_fast_00011076, 3u},
    {69756u, aot_fast_0001107c, 2u},
    {69764u, aot_fast_00011084, 3u},
    {69770u, aot_fast_0001108a, 2u},
    {69778u, aot_fast_00011092, 3u},
    {69784u, aot_fast_00011098, 3u},
    {69796u, aot_fast_000110a4, 1u},
    {69814u, aot_fast_000110b6, 1u},
    {69816u, aot_fast_000110b8, 3u},
    {69822u, aot_fast_000110be, 3u},
    {69830u, aot_fast_000110c6, 2u},
    {69834u, aot_fast_000110ca, 1u},
    {69838u, aot_fast_000110ce, 7u},
    {69852u, aot_fast_000110dc, 2u},
    {69856u, aot_fast_000110e0, 2u},
    {69860u, aot_fast_000110e4, 3u},
    {69868u, aot_fast_000110ec, 2u},
    {69874u, aot_fast_000110f2, 6u},
    {69898u, aot_fast_0001110a, 2u},
    {69916u, aot_fast_0001111c, 8u},
    {69936u, aot_fast_00011130, 2u},
    {70068u, aot_fast_000111b4, 2u},
    {70072u, aot_fast_000111b8, 7u},
    {70090u, aot_fast_000111ca, 2u},
    {70108u, aot_fast_000111dc, 3u},
    {70118u, aot_fast_000111e6, 3u},
    {70128u, aot_fast_000111f0, 1u},
    {70130u, aot_fast_000111f2, 4u},
    {70138u, aot_fast_000111fa, 3u},
    {70144u, aot_fast_00011200, 2u},
    {70150u, aot_fast_00011206, 2u},
    {70154u, aot_fast_0001120a, 3u},
    {70162u, aot_fast_00011212, 3u},
    {70170u, aot_fast_0001121a, 9u},
    {70190u, aot_fast_0001122e, 7u},
    {70204u, aot_fast_0001123c, 2u},
    {70210u, aot_fast_00011242, 1u},
    {70212u, aot_fast_00011244, 5u},
    {70222u, aot_fast_0001124e, 2u},
    {70226u, aot_fast_00011252, 2u},
    {70230u, aot_fast_00011256, 3u},
    {70238u, aot_fast_0001125e, 3u},
    {70246u, aot_fast_00011266, 2u},
    {70252u, aot_fast_0001126c, 1u},
    {70256u, aot_fast_00011270, 2u},
    {70260u, aot_fast_00011274, 1u},
    {70264u, aot_fast_00011278, 4u},
    {70272u, aot_fast_00011280, 1u},
    {70274u, aot_fast_00011282, 4u},
    {70282u, aot_fast_0001128a, 2u},
    {70286u, aot_fast_0001128e, 1u},
    {70288u, aot_fast_00011290, 3u},
    {70298u, aot_fast_0001129a, 5u},
    {70328u, aot_fast_000112b8, 2u},
    {70356u, aot_fast_000112d4, 3u},
    {70366u, aot_fast_000112de, 5u},
    {70396u, aot_fast_000112fc, 2u},
    {70400u, aot_fast_00011300, 9u},
    {70422u, aot_fast_00011316, 2u},
    {70426u, aot_fast_0001131a, 6u},
    {70446u, aot_fast_0001132e, 2u},
    {70464u, aot_fast_00011340, 4u},
    {70476u, aot_fast_0001134c, 3u},
    {70484u, aot_fast_00011354, 1u},
    {70486u, aot_fast_00011356, 2u},
    {70490u, aot_fast_0001135a, 4u},
    {70500u, aot_fast_00011364, 3u},
    {70506u, aot_fast_0001136a, 2u},
    {70510u, aot_fast_0001136e, 5u},
    {70520u, aot_fast_00011378, 3u},
    {70526u, aot_fast_0001137e, 2u},
    {70530u, aot_fast_00011382, 1u},
    {70532u, aot_fast_00011384, 2u},
    {70538u, aot_fast_0001138a, 3u},
    {70548u, aot_fast_00011394, 13u},
    {70578u, aot_fast_000113b2, 6u},
    {70594u, aot_fast_000113c2, 2u},
    {70600u, aot_fast_000113c8, 6u},
    {70620u, aot_fast_000113dc, 3u},
    {71196u, aot_fast_0001161c, 2u},
    {71200u, aot_fast_00011620, 2u},
    {71204u, aot_fast_00011624, 2u},
    {71208u, aot_fast_00011628, 7u},
    {71228u, aot_fast_0001163c, 5u},
    {71238u, aot_fast_00011646, 1u},
    {71242u, aot_fast_0001164a, 1u},
    {71244u, aot_fast_0001164c, 1u},
    {71250u, aot_fast_00011652, 1u},
    {71252u, aot_fast_00011654, 1u},
    {71258u, aot_fast_0001165a, 2u},
    {71262u, aot_fast_0001165e, 3u},
    {71272u, aot_fast_00011668, 1u},
    {71276u, aot_fast_0001166c, 2u},
    {71472u, aot_fast_00011730, 2u},
    {71542u, aot_fast_00011776, 2u},
    {71748u, aot_fast_00011844, 2u},
    {71756u, aot_fast_0001184c, 1u},
    {71764u, aot_fast_00011854, 3u},
    {71776u, aot_fast_00011860, 2u},
    {71784u, aot_fast_00011868, 1u},
    {71792u, aot_fast_00011870, 1u},
    {71800u, aot_fast_00011878, 1u},
    {71808u, aot_fast_00011880, 1u},
    {71816u, aot_fast_00011888, 1u},
    {71824u, aot_fast_00011890, 1u},
    {71892u, aot_fast_000118d4, 1u},
    {71960u, aot_fast_00011918, 1u},
    {71980u, aot_fast_0001192c, 1u},
    {72000u, aot_fast_00011940, 1u},
    {72004u, aot_fast_00011944, 8u},
    {72030u, aot_fast_0001195e, 3u},
    {72040u, aot_fast_00011968, 8u},
    {72066u, aot_fast_00011982, 3u},
    {72076u, aot_fast_0001198c, 8u},
    {72102u, aot_fast_000119a6, 3u},
    {72112u, aot_fast_000119b0, 8u},
    {72138u, aot_fast_000119ca, 3u},
    {72148u, aot_fast_000119d4, 8u},
    {72174u, aot_fast_000119ee, 3u},
    {72184u, aot_fast_000119f8, 2u},
    {72188u, aot_fast_000119fc, 2u},
    {72192u, aot_fast_00011a00, 9u},
    {72210u, aot_fast_00011a12, 1u},
    {72212u, aot_fast_00011a14, 4u},
    {72222u, aot_fast_00011a1e, 1u},
    {72224u, aot_fast_00011a20, 2u},
    {72228u, aot_fast_00011a24, 7u},
    {72244u, aot_fast_00011a34, 3u},
    {72252u, aot_fast_00011a3c, 1u},
    {72254u, aot_fast_00011a3e, 6u},
    {72272u, aot_fast_00011a50, 2u},
    {72278u, aot_fast_00011a56, 3u},
    {72284u, aot_fast_00011a5c, 2u},
    {72290u, aot_fast_00011a62, 7u},
    {72306u, aot_fast_00011a72, 6u},
    {72320u, aot_fast_00011a80, 1u},
    {72330u, aot_fast_00011a8a, 1u},
    {72336u, aot_fast_00011a90, 4u},
    {72350u, aot_fast_00011a9e, 1u},
    {72354u, aot_fast_00011aa2, 2u},
    {72364u, aot_fast_00011aac, 1u},
    {72376u, aot_fast_00011ab8, 3u},
    {72384u, aot_fast_00011ac0, 3u},
    {72394u, aot_fast_00011aca, 2u},
    {72400u, aot_fast_00011ad0, 2u},
    {72404u, aot_fast_00011ad4, 4u},
    {72414u, aot_fast_00011ade, 1u},
    {72418u, aot_fast_00011ae2, 2u},
    {72426u, aot_fast_00011aea, 1u},
    {72432u, aot_fast_00011af0, 2u},
    {72436u, aot_fast_00011af4, 3u},
    {72444u, aot_fast_00011afc, 6u},
    {72462u, aot_fast_00011b0e, 3u},
    {72470u, aot_fast_00011b16, 3u},
    {72478u, aot_fast_00011b1e, 1u},
    {72480u, aot_fast_00011b20, 2u},
    {72486u, aot_fast_00011b26, 1u},
    {72494u, aot_fast_00011b2e, 4u},
    {72512u, aot_fast_00011b40, 2u},
    {72516u, aot_fast_00011b44, 2u},
    {72520u, aot_fast_00011b48, 2u},
    {72526u, aot_fast_00011b4e, 3u},
    {72536u, aot_fast_00011b58, 1u},
    {72538u, aot_fast_00011b5a, 1u},
    {72540u, aot_fast_00011b5c, 2u},
    {72544u, aot_fast_00011b60, 2u},
    {72548u, aot_fast_00011b64, 7u},
    {72566u, aot_fast_00011b76, 2u},
    {72576u, aot_fast_00011b80, 3u},
    {72586u, aot_fast_00011b8a, 5u},
    {72598u, aot_fast_00011b96, 1u},
    {72600u, aot_fast_00011b98, 1u},
    {72606u, aot_fast_00011b9e, 5u},
    {72618u, aot_fast_00011baa, 2u},
    {72622u, aot_fast_00011bae, 2u},
    {72628u, aot_fast_00011bb4, 6u},
    {72644u, aot_fast_00011bc4, 3u},
    {72652u, aot_fast_00011bcc, 6u},
    {72668u, aot_fast_00011bdc, 2u},
    {72672u, aot_fast_00011be0, 2u},
    {72676u, aot_fast_00011be4, 2u},
    {72682u, aot_fast_00011bea, 5u},
    {72700u, aot_fast_00011bfc, 1u},
    {72702u, aot_fast_00011bfe, 2u},
    {72706u, aot_fast_00011c02, 2u},
    {72712u, aot_fast_00011c08, 3u},
    {72724u, aot_fast_00011c14, 1u},
    {72728u, aot_fast_00011c18, 3u},
    {72734u, aot_fast_00011c1e, 3u},
    {72742u, aot_fast_00011c26, 6u},
    {72758u, aot_fast_00011c36, 2u},
    {72762u, aot_fast_00011c3a, 2u},
    {72768u, aot_fast_00011c40, 5u},
    {72782u, aot_fast_00011c4e, 2u},
    {72788u, aot_fast_00011c54, 2u},
    {72794u, aot_fast_00011c5a, 3u},
    {72804u, aot_fast_00011c64, 2u},
    {72812u, aot_fast_00011c6c, 1u},
    {72814u, aot_fast_00011c6e, 3u},
    {72824u, aot_fast_00011c78, 5u},
    {72838u, aot_fast_00011c86, 1u},
    {72840u, aot_fast_00011c88, 1u},
    {72844u, aot_fast_00011c8c, 2u},
    {72850u, aot_fast_00011c92, 1u},
    {72852u, aot_fast_00011c94, 1u},
    {72854u, aot_fast_00011c96, 2u},
    {72860u, aot_fast_00011c9c, 14u},
    {72896u, aot_fast_00011cc0, 2u},
    {72902u, aot_fast_00011cc6, 2u},
    {72908u, aot_fast_00011ccc, 2u},
    {72912u, aot_fast_00011cd0, 2u},
    {72918u, aot_fast_00011cd6, 2u},
    {72926u, aot_fast_00011cde, 2u},
    {72930u, aot_fast_00011ce2, 2u},
    {72936u, aot_fast_00011ce8, 2u},
};
const uint32_t agr_aot_fast_block_count = 301u;

const AgrAotEntry agr_aot_fast_hash[] = {
    {0u, 0, 0u},
    {0u, 0, 0u},
    {68932u, aot_fast_00010d44, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70578u, aot_fast_000113b2, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70526u, aot_fast_0001137e, 2u},
    {72224u, aot_fast_00011a20, 2u},
    {0u, 0, 0u},
    {69476u, aot_fast_00010f64, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {71472u, aot_fast_00011730, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70422u, aot_fast_00011316, 2u},
    {70072u, aot_fast_000111b8, 7u},
    {72470u, aot_fast_00011b16, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72768u, aot_fast_00011c40, 5u},
    {72418u, aot_fast_00011ae2, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69268u, aot_fast_00010e94, 10u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69916u, aot_fast_0001111c, 8u},
    {0u, 0, 0u},
    {69216u, aot_fast_00010e60, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69514u, aot_fast_00010f8a, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70162u, aot_fast_00011212, 3u},
    {72210u, aot_fast_00011a12, 1u},
    {69462u, aot_fast_00010f56, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {71808u, aot_fast_00011880, 1u},
    {0u, 0, 0u},
    {69060u, aot_fast_00010dc4, 10u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {71756u, aot_fast_0001184c, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70356u, aot_fast_000112d4, 3u},
    {72404u, aot_fast_00011ad4, 4u},
    {69656u, aot_fast_00011018, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72702u, aot_fast_00011bfe, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69604u, aot_fast_00010fe4, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70252u, aot_fast_0001126c, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {71250u, aot_fast_00011652, 1u},
    {0u, 0, 0u},
    {72598u, aot_fast_00011b96, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72896u, aot_fast_00011cc0, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72844u, aot_fast_00011c8c, 2u},
    {70446u, aot_fast_0001132e, 2u},
    {72494u, aot_fast_00011b2e, 4u},
    {69746u, aot_fast_00011072, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69694u, aot_fast_0001103e, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72040u, aot_fast_00011968, 8u},
    {69642u, aot_fast_0001100a, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70238u, aot_fast_0001125e, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69486u, aot_fast_00010f6e, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70484u, aot_fast_00011354, 1u},
    {0u, 0, 0u},
    {69784u, aot_fast_00011098, 3u},
    {0u, 0, 0u},
    {69084u, aot_fast_00010ddc, 7u},
    {0u, 0, 0u},
    {72480u, aot_fast_00011b20, 2u},
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
    {70328u, aot_fast_000112b8, 2u},
    {72376u, aot_fast_00011ab8, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72622u, aot_fast_00011bae, 2u},
    {72272u, aot_fast_00011a50, 2u},
    {69874u, aot_fast_000110f2, 6u},
    {69524u, aot_fast_00010f94, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69822u, aot_fast_000110be, 3u},
    {0u, 0, 0u},
    {69122u, aot_fast_00010e02, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69770u, aot_fast_0001108a, 2u},
    {69420u, aot_fast_00010f2c, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70068u, aot_fast_000111b4, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70366u, aot_fast_000112de, 5u},
    {72414u, aot_fast_00011ade, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72712u, aot_fast_00011c08, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69264u, aot_fast_00010e90, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {71960u, aot_fast_00011918, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70210u, aot_fast_00011242, 1u},
    {69860u, aot_fast_000110e4, 3u},
    {69510u, aot_fast_00010f86, 2u},
    {71208u, aot_fast_00011628, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72854u, aot_fast_00011c96, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69756u, aot_fast_0001107c, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72102u, aot_fast_000119a6, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72400u, aot_fast_00011ad0, 2u},
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
    {69898u, aot_fast_0001110a, 2u},
    {0u, 0, 0u},
    {69198u, aot_fast_00010e4e, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72244u, aot_fast_00011a34, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70144u, aot_fast_00011200, 2u},
    {72192u, aot_fast_00011a00, 9u},
    {69444u, aot_fast_00010f44, 4u},
    {0u, 0, 0u},
    {72840u, aot_fast_00011c88, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72788u, aot_fast_00011c54, 2u},
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
    {70286u, aot_fast_0001128e, 1u},
    {69936u, aot_fast_00011130, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69184u, aot_fast_00010e40, 5u},
    {72930u, aot_fast_00011ce2, 2u},
    {70532u, aot_fast_00011384, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69482u, aot_fast_00010f6a, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70130u, aot_fast_000111f2, 4u},
    {0u, 0, 0u},
    {69430u, aot_fast_00010f36, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {71776u, aot_fast_00011860, 2u},
    {69378u, aot_fast_00010f02, 1u},
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
    {70272u, aot_fast_00011280, 1u},
    {72320u, aot_fast_00011a80, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {68872u, aot_fast_00010d08, 3u},
    {72618u, aot_fast_00011baa, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69170u, aot_fast_00010e32, 5u},
    {0u, 0, 0u},
    {72566u, aot_fast_00011b76, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69118u, aot_fast_00010dfe, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72812u, aot_fast_00011c6c, 1u},
    {72462u, aot_fast_00011b0e, 3u},
    {72112u, aot_fast_000119b0, 8u},
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
    {72306u, aot_fast_00011a72, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72254u, aot_fast_00011a3e, 6u},
    {69856u, aot_fast_000110e0, 2u},
    {69506u, aot_fast_00010f82, 2u},
    {71204u, aot_fast_00011624, 2u},
    {72902u, aot_fast_00011cc6, 2u},
    {0u, 0, 0u},
    {70154u, aot_fast_0001120a, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69104u, aot_fast_00010df0, 6u},
    {72850u, aot_fast_00011c92, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {71800u, aot_fast_00011878, 1u},
    {69402u, aot_fast_00010f1a, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70400u, aot_fast_00011300, 9u},
    {0u, 0, 0u},
    {71748u, aot_fast_00011844, 2u},
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
    {68896u, aot_fast_00010d20, 3u},
    {70594u, aot_fast_000113c2, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69544u, aot_fast_00010fa8, 6u},
    {71242u, aot_fast_0001164a, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70490u, aot_fast_0001135a, 4u},
    {72188u, aot_fast_000119fc, 2u},
    {72538u, aot_fast_00011b5a, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72486u, aot_fast_00011b26, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69336u, aot_fast_00010ed8, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69634u, aot_fast_00011002, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70282u, aot_fast_0001128a, 2u},
    {71980u, aot_fast_0001192c, 1u},
    {69582u, aot_fast_00010fce, 1u},
    {69232u, aot_fast_00010e70, 7u},
    {72330u, aot_fast_00011a8a, 1u},
    {72628u, aot_fast_00011bb4, 6u},
    {70230u, aot_fast_00011256, 3u},
    {72278u, aot_fast_00011a56, 3u},
    {0u, 0, 0u},
    {71228u, aot_fast_0001163c, 5u},
    {72926u, aot_fast_00011cde, 2u},
    {72576u, aot_fast_00011b80, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70476u, aot_fast_0001134c, 3u},
    {72174u, aot_fast_000119ee, 3u},
    {71824u, aot_fast_00011890, 1u},
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
    {68920u, aot_fast_00010d38, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69516u, aot_fast_00010f8c, 4u},
    {0u, 0, 0u},
    {72912u, aot_fast_00011cd0, 2u},
    {0u, 0, 0u},
    {72212u, aot_fast_00011a14, 4u},
    {69814u, aot_fast_000110b6, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72860u, aot_fast_00011c9c, 14u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69412u, aot_fast_00010f24, 3u},
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
    {72354u, aot_fast_00011aa2, 2u},
    {72004u, aot_fast_00011944, 8u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72652u, aot_fast_00011bcc, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {71252u, aot_fast_00011654, 1u},
    {0u, 0, 0u},
    {72600u, aot_fast_00011b98, 1u},
    {0u, 0, 0u},
    {69852u, aot_fast_000110dc, 2u},
    {0u, 0, 0u},
    {71200u, aot_fast_00011620, 2u},
    {0u, 0, 0u},
    {70500u, aot_fast_00011364, 3u},
    {70150u, aot_fast_00011206, 2u},
    {72548u, aot_fast_00011b64, 7u},
    {0u, 0, 0u},
    {69100u, aot_fast_00010dec, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72794u, aot_fast_00011c5a, 3u},
    {70396u, aot_fast_000112fc, 2u},
    {72444u, aot_fast_00011afc, 6u},
    {0u, 0, 0u},
    {69346u, aot_fast_00010ee2, 7u},
    {0u, 0, 0u},
    {72742u, aot_fast_00011c26, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69294u, aot_fast_00010eae, 7u},
    {68944u, aot_fast_00010d50, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69540u, aot_fast_00010fa4, 2u},
    {71238u, aot_fast_00011646, 1u},
    {72936u, aot_fast_00011ce8, 2u},
    {70538u, aot_fast_0001138a, 3u},
    {72586u, aot_fast_00011b8a, 5u},
    {69838u, aot_fast_000110ce, 7u},
    {0u, 0, 0u},
    {69138u, aot_fast_00010e12, 6u},
    {0u, 0, 0u},
    {70486u, aot_fast_00011356, 2u},
    {72184u, aot_fast_000119f8, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69734u, aot_fast_00011066, 2u},
    {69384u, aot_fast_00010f08, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69682u, aot_fast_00011032, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72728u, aot_fast_00011c18, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72676u, aot_fast_00011be4, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69578u, aot_fast_00010fca, 2u},
    {71276u, aot_fast_0001166c, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70226u, aot_fast_00011252, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72222u, aot_fast_00011a1e, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69124u, aot_fast_00010e04, 6u},
    {0u, 0, 0u},
    {72520u, aot_fast_00011b48, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69720u, aot_fast_00011058, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72066u, aot_fast_00011982, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72364u, aot_fast_00011aac, 1u},
    {0u, 0, 0u},
    {69616u, aot_fast_00010ff0, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70264u, aot_fast_00011278, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69214u, aot_fast_00010e5e, 1u},
    {71262u, aot_fast_0001165e, 3u},
    {0u, 0, 0u},
    {70212u, aot_fast_00011244, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72908u, aot_fast_00011ccc, 2u},
    {70510u, aot_fast_0001136e, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70108u, aot_fast_000111dc, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72804u, aot_fast_00011c64, 2u},
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
    {72700u, aot_fast_00011bfc, 1u},
    {72350u, aot_fast_00011a9e, 1u},
    {72000u, aot_fast_00011940, 1u},
    {69602u, aot_fast_00010fe2, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70600u, aot_fast_000113c8, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70548u, aot_fast_00011394, 13u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69498u, aot_fast_00010f7a, 3u},
    {71196u, aot_fast_0001161c, 2u},
    {0u, 0, 0u},
    {72544u, aot_fast_00011b60, 2u},
    {0u, 0, 0u},
    {69796u, aot_fast_000110a4, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69744u, aot_fast_00011070, 1u},
    {71792u, aot_fast_00011870, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {68992u, aot_fast_00010d80, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70288u, aot_fast_00011290, 3u},
    {72336u, aot_fast_00011a90, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72284u, aot_fast_00011a5c, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69834u, aot_fast_000110ca, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72478u, aot_fast_00011b1e, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72426u, aot_fast_00011aea, 1u},
    {72076u, aot_fast_0001198c, 8u},
    {69678u, aot_fast_0001102e, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72724u, aot_fast_00011c14, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69626u, aot_fast_00010ffa, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72672u, aot_fast_00011be0, 2u},
    {70274u, aot_fast_00011282, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {71272u, aot_fast_00011668, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70222u, aot_fast_0001124e, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72918u, aot_fast_00011cd6, 2u},
    {70520u, aot_fast_00011378, 3u},
    {70170u, aot_fast_0001121a, 9u},
    {0u, 0, 0u},
    {69470u, aot_fast_00010f5e, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72516u, aot_fast_00011b44, 2u},
    {70118u, aot_fast_000111e6, 3u},
    {71816u, aot_fast_00011888, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72814u, aot_fast_00011c6e, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {71764u, aot_fast_00011854, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72762u, aot_fast_00011c3a, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69664u, aot_fast_00011020, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69612u, aot_fast_00010fec, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70260u, aot_fast_00011274, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {71258u, aot_fast_0001165a, 2u},
    {68860u, aot_fast_00010cfc, 3u},
    {72606u, aot_fast_00011b9e, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70506u, aot_fast_0001136a, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72852u, aot_fast_00011c94, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69702u, aot_fast_00011046, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69650u, aot_fast_00011012, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70298u, aot_fast_0001129a, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69248u, aot_fast_00010e80, 7u},
    {0u, 0, 0u},
    {72644u, aot_fast_00011bc4, 3u},
    {70246u, aot_fast_00011266, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {71244u, aot_fast_0001164c, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {71892u, aot_fast_000118d4, 1u},
    {69494u, aot_fast_00010f76, 2u},
    {71542u, aot_fast_00011776, 2u},
    {0u, 0, 0u},
    {72540u, aot_fast_00011b5c, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72838u, aot_fast_00011c86, 1u},
    {0u, 0, 0u},
    {70090u, aot_fast_000111ca, 2u},
    {69740u, aot_fast_0001106c, 1u},
    {72138u, aot_fast_000119ca, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72436u, aot_fast_00011af4, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72734u, aot_fast_00011c1e, 3u},
    {72384u, aot_fast_00011ac0, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72682u, aot_fast_00011bea, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69584u, aot_fast_00010fd0, 8u},
    {0u, 0, 0u},
    {68884u, aot_fast_00010d14, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69532u, aot_fast_00010f9c, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70530u, aot_fast_00011382, 1u},
    {72228u, aot_fast_00011a24, 7u},
    {69830u, aot_fast_000110c6, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72526u, aot_fast_00011b4e, 3u},
    {70128u, aot_fast_000111f0, 1u},
    {69778u, aot_fast_00011092, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72824u, aot_fast_00011c78, 5u},
    {70426u, aot_fast_0001131a, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69324u, aot_fast_00010ecc, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69622u, aot_fast_00010ff6, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70620u, aot_fast_000113dc, 3u},
    {72668u, aot_fast_00011bdc, 2u},
    {0u, 0, 0u},
    {69570u, aot_fast_00010fc2, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69868u, aot_fast_000110ec, 2u},
    {0u, 0, 0u},
    {69168u, aot_fast_00010e30, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69816u, aot_fast_000110b8, 3u},
    {69466u, aot_fast_00010f5a, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70464u, aot_fast_00011340, 4u},
    {72512u, aot_fast_00011b40, 2u},
    {69764u, aot_fast_00011084, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69362u, aot_fast_00010ef2, 7u},
    {0u, 0, 0u},
    {72758u, aot_fast_00011c36, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69660u, aot_fast_0001101c, 2u},
    {69310u, aot_fast_00010ebe, 6u},
    {0u, 0, 0u},
    {72706u, aot_fast_00011c02, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {68908u, aot_fast_00010d2c, 3u},
    {0u, 0, 0u},
    {70256u, aot_fast_00011270, 2u},
    {0u, 0, 0u},
    {69556u, aot_fast_00010fb4, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70204u, aot_fast_0001123c, 2u},
    {72252u, aot_fast_00011a3c, 1u},
    {0u, 0, 0u},
    {69154u, aot_fast_00010e22, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69452u, aot_fast_00010f4c, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72148u, aot_fast_000119d4, 8u},
    {69750u, aot_fast_00011076, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {69698u, aot_fast_00011042, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72394u, aot_fast_00011aca, 2u},
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
    {72290u, aot_fast_00011a62, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {70190u, aot_fast_0001122e, 7u},
    {0u, 0, 0u},
    {69490u, aot_fast_00010f72, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72536u, aot_fast_00011b58, 1u},
    {70138u, aot_fast_000111fa, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {71784u, aot_fast_00011868, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72782u, aot_fast_00011c4e, 2u},
    {72432u, aot_fast_00011af0, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {72030u, aot_fast_0001195e, 3u},
};
const uint32_t agr_aot_fast_hash_mask = 1023u;
