#include "agr_aot.h"

static int aot_fast_00046a90(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 289432u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 659456u);
    { uint32_t addr = s->r[12] + 700u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00046a9c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 289444u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 659456u);
    { uint32_t addr = s->r[12] + 692u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00046ab4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 289468u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 659456u);
    { uint32_t addr = s->r[12] + 676u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00046b20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 289576u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 659456u);
    { uint32_t addr = s->r[12] + 604u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00046b2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 289588u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 659456u);
    { uint32_t addr = s->r[12] + 596u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00046b38(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 289600u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 659456u);
    { uint32_t addr = s->r[12] + 588u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00046b74(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 289660u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 659456u);
    { uint32_t addr = s->r[12] + 548u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00046e68(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 290416u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 659456u);
    { uint32_t addr = s->r[12] + 44u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00046e98(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 290464u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 659456u);
    { uint32_t addr = s->r[12] + 12u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00046ea4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 290476u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 659456u);
    { uint32_t addr = s->r[12] + 4u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00046ee0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 290536u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 655360u);
    { uint32_t addr = s->r[12] + 4060u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00046eec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 290548u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 655360u);
    { uint32_t addr = s->r[12] + 4052u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00046ef8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 290560u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 655360u);
    { uint32_t addr = s->r[12] + 4044u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00046fac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 290740u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 655360u);
    { uint32_t addr = s->r[12] + 3924u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00046fb8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 290752u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 655360u);
    { uint32_t addr = s->r[12] + 3916u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00046fc4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 290764u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 655360u);
    { uint32_t addr = s->r[12] + 3908u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00046fd0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 290776u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 655360u);
    { uint32_t addr = s->r[12] + 3900u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00046fdc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 290788u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 655360u);
    { uint32_t addr = s->r[12] + 3892u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00046fe8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 290800u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 655360u);
    { uint32_t addr = s->r[12] + 3884u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00046ff4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 290812u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 655360u);
    { uint32_t addr = s->r[12] + 3876u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00047000(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 290824u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 655360u);
    { uint32_t addr = s->r[12] + 3868u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_0004700c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 290836u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 655360u);
    { uint32_t addr = s->r[12] + 3860u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00047018(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 290848u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 655360u);
    { uint32_t addr = s->r[12] + 3852u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00047024(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 290860u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 655360u);
    { uint32_t addr = s->r[12] + 3844u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_0004709c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 290980u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 655360u);
    { uint32_t addr = s->r[12] + 3764u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_000471ec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 291316u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 655360u);
    { uint32_t addr = s->r[12] + 3540u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00047288(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, 291472u, 0u);
    agr_aot_add_imm(s, 12, s->r[12], 655360u);
    { uint32_t addr = s->r[12] + 3436u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_00047794(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 48u)) return AGR_AOT_FAULT;
    agr_aot_add_imm(s, 3, s->r[0], 8u);
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = 292766u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000477a2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 4, s->r[2], 1u);
    s->r[15] = 292772u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000477a8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[5], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 292766u : 292780u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000477ac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 0u);
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = agr_aot_condition(s, 12u) ? 292794u : 292788u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000477b4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 48u))) return rc;
    s->r[15] = 788308u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000477ba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 48u))) return rc;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000477c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = (292808u) + 4u; if ((rc = agr_aot_ldr(s, 0, addr))) return rc; }
    agr_aot_add_imm(s, 0, 292812u, s->r[0]);
    s->r[15] = 292808u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000477d0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 292824u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 292824u + 60u); if (rc) return rc; }
    s->r[4] += 292828u;
    s->r[6] += 292830u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 292836u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000477e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 292840u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 292846u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 292850u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000477f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 292852u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 292860u;
    agr_aot_branch_reg(s, 792908u | 1u, 292862u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000477fe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 292864u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 292872u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 292876u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0004780c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00047824(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 292908u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 292908u + 60u); if (rc) return rc; }
    s->r[4] += 292912u;
    s->r[6] += 292914u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 292920u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047838(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 292924u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 292930u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 292934u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047846(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 292936u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 292944u;
    agr_aot_branch_reg(s, 792908u | 1u, 292946u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047852(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 292948u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 292956u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 292960u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047860(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00047878(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 292992u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 292992u + 60u); if (rc) return rc; }
    s->r[4] += 292996u;
    s->r[6] += 292998u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 293004u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0004788c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293008u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 293014u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 293018u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0004789a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293020u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 293028u;
    agr_aot_branch_reg(s, 792908u | 1u, 293030u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000478a6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293032u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 293040u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 293044u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000478b4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_000478cc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 293076u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 293076u + 60u); if (rc) return rc; }
    s->r[4] += 293080u;
    s->r[6] += 293082u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 293088u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000478e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293092u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 293098u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 293102u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000478ee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293104u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 293112u;
    agr_aot_branch_reg(s, 792908u | 1u, 293114u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000478fa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293116u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 293124u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 293128u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047908(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00047920(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 293160u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 293160u + 60u); if (rc) return rc; }
    s->r[4] += 293164u;
    s->r[6] += 293166u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 293172u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047934(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293176u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 293182u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 293186u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047942(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293188u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 293196u;
    agr_aot_branch_reg(s, 792908u | 1u, 293198u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0004794e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293200u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 293208u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 293212u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0004795c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00047974(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 293244u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 293244u + 60u); if (rc) return rc; }
    s->r[4] += 293248u;
    s->r[6] += 293250u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 293256u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047988(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293260u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 293266u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 293270u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047996(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293272u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 293280u;
    agr_aot_branch_reg(s, 792908u | 1u, 293282u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000479a2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293284u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 293292u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 293296u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000479b0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_000479c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 293328u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 293328u + 60u); if (rc) return rc; }
    s->r[4] += 293332u;
    s->r[6] += 293334u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 293340u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000479dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293344u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 293350u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 293354u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000479ea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293356u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 293364u;
    agr_aot_branch_reg(s, 792908u | 1u, 293366u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000479f6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293368u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 293376u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 293380u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047a04(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00047a1c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 293412u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 293412u + 60u); if (rc) return rc; }
    s->r[4] += 293416u;
    s->r[6] += 293418u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 293424u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047a30(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293428u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 293434u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 293438u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047a3e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293440u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 293448u;
    agr_aot_branch_reg(s, 792908u | 1u, 293450u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047a4a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293452u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 293460u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 293464u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047a58(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00047a70(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 293496u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 293496u + 60u); if (rc) return rc; }
    s->r[4] += 293500u;
    s->r[6] += 293502u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 293508u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047a84(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293512u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 293518u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 293522u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047a92(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293524u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 293532u;
    agr_aot_branch_reg(s, 792908u | 1u, 293534u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047a9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293536u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 293544u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 293548u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047aac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00047ac4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 293580u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 293580u + 60u); if (rc) return rc; }
    s->r[4] += 293584u;
    s->r[6] += 293586u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 293592u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047ad8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293596u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 293602u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 293606u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047ae6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293608u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 293616u;
    agr_aot_branch_reg(s, 792908u | 1u, 293618u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047af2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293620u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 293628u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 293632u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047b00(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00047b18(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 293664u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 293664u + 60u); if (rc) return rc; }
    s->r[4] += 293668u;
    s->r[6] += 293670u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 293676u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047b2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293680u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 293686u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 293690u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047b3a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293692u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 293700u;
    agr_aot_branch_reg(s, 792908u | 1u, 293702u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047b46(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293704u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 293712u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 293716u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047b54(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00047b6c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 293748u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 293748u + 60u); if (rc) return rc; }
    s->r[4] += 293752u;
    s->r[6] += 293754u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 293760u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047b80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293764u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 293770u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 293774u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047b8e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293776u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 293784u;
    agr_aot_branch_reg(s, 792908u | 1u, 293786u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047b9a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293788u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 293796u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 293800u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047ba8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00047bc0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 293832u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 293832u + 60u); if (rc) return rc; }
    s->r[4] += 293836u;
    s->r[6] += 293838u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 293844u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047bd4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293848u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 293854u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 293858u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047be2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293860u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 293868u;
    agr_aot_branch_reg(s, 792908u | 1u, 293870u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047bee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293872u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 293880u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 293884u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047bfc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00047c14(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 293916u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 293916u + 60u); if (rc) return rc; }
    s->r[4] += 293920u;
    s->r[6] += 293922u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 293928u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047c28(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293932u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 293938u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 293942u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047c36(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293944u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 293952u;
    agr_aot_branch_reg(s, 792908u | 1u, 293954u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047c42(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 293956u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 293964u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 293968u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047c50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00047c68(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 294000u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 294000u + 60u); if (rc) return rc; }
    s->r[4] += 294004u;
    s->r[6] += 294006u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 294012u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047c7c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294016u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 294022u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 294026u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047c8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294028u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 294036u;
    agr_aot_branch_reg(s, 792908u | 1u, 294038u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047c96(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294040u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 294048u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 294052u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047ca4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00047cbc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 294084u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 294084u + 60u); if (rc) return rc; }
    s->r[4] += 294088u;
    s->r[6] += 294090u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 294096u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047cd0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294100u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 294106u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 294110u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047cde(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294112u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 294120u;
    agr_aot_branch_reg(s, 792908u | 1u, 294122u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047cea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294124u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 294132u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 294136u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047cf8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00047d10(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 294168u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 294168u + 60u); if (rc) return rc; }
    s->r[4] += 294172u;
    s->r[6] += 294174u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 294180u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047d24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294184u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 294190u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 294194u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047d32(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294196u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 294204u;
    agr_aot_branch_reg(s, 792908u | 1u, 294206u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047d3e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294208u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 294216u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 294220u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047d4c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00047d64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 294252u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 294252u + 60u); if (rc) return rc; }
    s->r[4] += 294256u;
    s->r[6] += 294258u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 294264u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047d78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294268u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 294274u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 294278u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047d86(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294280u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 294288u;
    agr_aot_branch_reg(s, 792908u | 1u, 294290u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047d92(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294292u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 294300u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 294304u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047da0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00047db8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 294336u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 294336u + 60u); if (rc) return rc; }
    s->r[4] += 294340u;
    s->r[6] += 294342u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 294348u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047dcc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294352u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 294358u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 294362u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047dda(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294364u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 294372u;
    agr_aot_branch_reg(s, 792908u | 1u, 294374u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047de6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294376u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 294384u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 294388u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047df4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00047e0c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 294420u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 294420u + 60u); if (rc) return rc; }
    s->r[4] += 294424u;
    s->r[6] += 294426u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 294432u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047e20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294436u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 294442u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 294446u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047e2e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294448u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 294456u;
    agr_aot_branch_reg(s, 792908u | 1u, 294458u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047e3a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294460u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 294468u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 294472u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047e48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00047e60(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 294504u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 294504u + 60u); if (rc) return rc; }
    s->r[4] += 294508u;
    s->r[6] += 294510u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 294516u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047e74(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294520u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 294526u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 294530u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047e82(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294532u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 294540u;
    agr_aot_branch_reg(s, 792908u | 1u, 294542u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047e8e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294544u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 294552u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 294556u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047e9c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00047eb4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 294588u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 294588u + 60u); if (rc) return rc; }
    s->r[4] += 294592u;
    s->r[6] += 294594u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 294600u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047ec8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294604u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 294610u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 294614u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047ed6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294616u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 294624u;
    agr_aot_branch_reg(s, 792908u | 1u, 294626u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047ee2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294628u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 294636u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 294640u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047ef0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00047f08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 294672u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 294672u + 60u); if (rc) return rc; }
    s->r[4] += 294676u;
    s->r[6] += 294678u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 294684u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047f1c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294688u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 294694u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 294698u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047f2a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294700u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 294708u;
    agr_aot_branch_reg(s, 792908u | 1u, 294710u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047f36(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294712u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 294720u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 294724u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047f44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00047f5c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 294756u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 294756u + 60u); if (rc) return rc; }
    s->r[4] += 294760u;
    s->r[6] += 294762u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 294768u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047f70(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294772u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 294778u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 294782u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047f7e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294784u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 294792u;
    agr_aot_branch_reg(s, 792908u | 1u, 294794u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047f8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294796u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 294804u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 294808u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047f98(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00047fb0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 294840u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 294840u + 60u); if (rc) return rc; }
    s->r[4] += 294844u;
    s->r[6] += 294846u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 294852u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047fc4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294856u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 294862u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 294866u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047fd2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294868u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 294876u;
    agr_aot_branch_reg(s, 792908u | 1u, 294878u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047fde(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294880u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 294888u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 294892u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00047fec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00048004(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 294924u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 294924u + 60u); if (rc) return rc; }
    s->r[4] += 294928u;
    s->r[6] += 294930u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 294936u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048018(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294940u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 294946u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 294950u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048026(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294952u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 294960u;
    agr_aot_branch_reg(s, 792908u | 1u, 294962u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048032(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 294964u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 294972u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 294976u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048040(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00048058(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 295008u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 295008u + 60u); if (rc) return rc; }
    s->r[4] += 295012u;
    s->r[6] += 295014u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 295020u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0004806c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295024u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 295030u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 295034u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0004807a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295036u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 295044u;
    agr_aot_branch_reg(s, 792908u | 1u, 295046u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048086(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295048u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 295056u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 295060u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048094(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_000480ac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 295092u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 295092u + 60u); if (rc) return rc; }
    s->r[4] += 295096u;
    s->r[6] += 295098u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 295104u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000480c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295108u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 295114u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 295118u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000480ce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295120u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 295128u;
    agr_aot_branch_reg(s, 792908u | 1u, 295130u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000480da(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295132u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 295140u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 295144u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000480e8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00048100(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 295176u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 295176u + 60u); if (rc) return rc; }
    s->r[4] += 295180u;
    s->r[6] += 295182u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 295188u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048114(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295192u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 295198u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 295202u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048122(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295204u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 295212u;
    agr_aot_branch_reg(s, 792908u | 1u, 295214u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0004812e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295216u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 295224u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 295228u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0004813c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00048154(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 295260u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 295260u + 60u); if (rc) return rc; }
    s->r[4] += 295264u;
    s->r[6] += 295266u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 295272u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048168(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295276u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 295282u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 295286u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048176(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295288u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 295296u;
    agr_aot_branch_reg(s, 792908u | 1u, 295298u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048182(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295300u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 295308u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 295312u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048190(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_000481a8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 295344u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 295344u + 60u); if (rc) return rc; }
    s->r[4] += 295348u;
    s->r[6] += 295350u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 295356u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000481bc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295360u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 295366u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 295370u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000481ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295372u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 295380u;
    agr_aot_branch_reg(s, 792908u | 1u, 295382u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000481d6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295384u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 295392u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 295396u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000481e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_000481fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 295428u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 295428u + 60u); if (rc) return rc; }
    s->r[4] += 295432u;
    s->r[6] += 295434u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 295440u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048210(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295444u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 295450u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 295454u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0004821e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295456u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 295464u;
    agr_aot_branch_reg(s, 792908u | 1u, 295466u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0004822a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295468u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 295476u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 295480u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048238(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00048250(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    { int rc = agr_aot_ldr(s, 4, 295508u + 28u); if (rc) return rc; }
    s->r[4] += 295512u;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 295516u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0004825c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295520u + 20u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, 295520u + 24u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 295526u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[2] += 295530u;
    if ((rc = agr_aot_ldmia_sp(s, 16400u))) return rc;
    s->r[15] = 602820u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0004827c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 295556u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 295556u + 60u); if (rc) return rc; }
    s->r[4] += 295560u;
    s->r[6] += 295562u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 295568u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048290(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295572u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 295578u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 295582u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0004829e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295584u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 295592u;
    agr_aot_branch_reg(s, 792908u | 1u, 295594u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000482aa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295596u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 295604u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 295608u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000482b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_000482d0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 295640u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 295640u + 60u); if (rc) return rc; }
    s->r[4] += 295644u;
    s->r[6] += 295646u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 295652u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000482e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295656u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 295662u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 295666u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000482f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295668u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 295676u;
    agr_aot_branch_reg(s, 792908u | 1u, 295678u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000482fe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295680u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 295688u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 295692u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0004830c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00048324(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    { int rc = agr_aot_ldr(s, 4, 295720u + 28u); if (rc) return rc; }
    s->r[4] += 295724u;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 295728u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048330(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295732u + 20u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, 295732u + 24u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 295738u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[2] += 295742u;
    if ((rc = agr_aot_ldmia_sp(s, 16400u))) return rc;
    s->r[15] = 602820u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048350(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 295768u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 295768u + 60u); if (rc) return rc; }
    s->r[4] += 295772u;
    s->r[6] += 295774u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 295780u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048364(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295784u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 295790u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 295794u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048372(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295796u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 295804u;
    agr_aot_branch_reg(s, 792908u | 1u, 295806u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0004837e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295808u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 295816u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 295820u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0004838c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_000483a4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 295852u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 295852u + 60u); if (rc) return rc; }
    s->r[4] += 295856u;
    s->r[6] += 295858u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 295864u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000483b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295868u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 295874u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 295878u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000483c6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295880u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 295888u;
    agr_aot_branch_reg(s, 792908u | 1u, 295890u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000483d2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295892u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 295900u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 295904u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000483e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_000483f8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    { int rc = agr_aot_ldr(s, 4, 295932u + 28u); if (rc) return rc; }
    s->r[4] += 295936u;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 295940u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048404(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295944u + 20u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, 295944u + 24u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 295950u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[2] += 295954u;
    if ((rc = agr_aot_ldmia_sp(s, 16400u))) return rc;
    s->r[15] = 602820u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048424(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 295980u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 295980u + 60u); if (rc) return rc; }
    s->r[4] += 295984u;
    s->r[6] += 295986u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 295992u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048438(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 295996u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 296002u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 296006u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048446(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 296008u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 296016u;
    agr_aot_branch_reg(s, 792908u | 1u, 296018u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048452(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 296020u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 296028u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 296032u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048460(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00048478(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 296064u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 296064u + 60u); if (rc) return rc; }
    s->r[4] += 296068u;
    s->r[6] += 296070u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 296076u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0004848c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 296080u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 296086u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 296090u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0004849a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 296092u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 296100u;
    agr_aot_branch_reg(s, 792908u | 1u, 296102u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000484a6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 296104u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 296112u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 296116u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000484b4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_000484cc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 296148u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 296148u + 60u); if (rc) return rc; }
    s->r[4] += 296152u;
    s->r[6] += 296154u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 296160u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000484e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 296164u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 296170u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 296174u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000484ee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 296176u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 296184u;
    agr_aot_branch_reg(s, 792908u | 1u, 296186u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000484fa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 296188u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 296196u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 296200u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048508(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00048520(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 296228u + 12u); if (rc) return rc; }
    agr_aot_movs_imm(s, 2, 0u);
    s->r[3] += 296232u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[3] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048534(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    { int rc = agr_aot_ldr(s, 4, 296248u + 44u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 0, 296252u + 44u); if (rc) return rc; }
    s->r[4] += 296254u;
    { int rc = agr_aot_ldr(s, 1, 296256u + 44u); if (rc) return rc; }
    s->r[0] += 296258u;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 4);
    s->r[1] += 296264u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 296268u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0004854c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 296272u + 32u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, 296272u + 36u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 4);
    s->r[0] += 296278u;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    s->r[1] += 296282u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    if ((rc = agr_aot_ldmia_sp(s, 16400u))) return rc;
    s->r[15] = 602820u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048578(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 296320u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 296320u + 60u); if (rc) return rc; }
    s->r[4] += 296324u;
    s->r[6] += 296326u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 296332u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0004858c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 296336u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 296342u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 296346u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0004859a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 296348u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 296356u;
    agr_aot_branch_reg(s, 792908u | 1u, 296358u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000485a6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 296360u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 296368u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 296372u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000485b4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_000485cc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, 296404u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 296404u + 60u); if (rc) return rc; }
    s->r[4] += 296408u;
    s->r[6] += 296410u;
    agr_aot_adds(s, 5, s->r[4], 4u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602956u | 1u, 296416u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000485e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 296420u + 48u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 296426u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 296430u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000485ee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 296432u + 40u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[1] += 296440u;
    agr_aot_branch_reg(s, 792908u | 1u, 296442u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000485fa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 296444u + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 6);
    s->r[1] += 296452u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 602820u | 1u, 296456u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048608(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_00048620(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_movs_imm(s, 3, 0u);
    { int rc = agr_aot_ldr(s, 4, 296488u + 40u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, 296488u + 44u); if (rc) return rc; }
    s->r[4] += 296492u;
    s->r[1] += 296494u;
    agr_aot_mov_reg(s, 0, 4);
    { uint32_t addr = s->r[4] + 4u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 290852u, 296500u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048634(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 296504u + 32u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, 296504u + 36u); if (rc) return rc; }
    s->r[1] += 296508u;
    s->r[2] += 296510u;
    agr_aot_subs(s, 3, 1u, s->r[0]);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_set_itstate(s, 56u); s->r[15] = 296516u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048660(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 296548u + 8u); if (rc) return rc; }
    agr_aot_movs_imm(s, 2, 0u);
    s->r[3] += 296552u;
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0004866e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 2, s->r[1], 0u);
    s->r[15] = 296560u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048670(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 296564u + 168u); if (rc) return rc; }
    s->r[3] += 296566u;
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_lsls(s, 0, s->r[2], 31u);
    agr_aot_set_itstate(s, 92u); s->r[15] = 296570u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0004874c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 296784u + 168u); if (rc) return rc; }
    s->r[3] += 296786u;
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_lsls(s, 0, s->r[2], 31u);
    agr_aot_set_itstate(s, 92u); s->r[15] = 296790u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048828(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16440u)) return AGR_AOT_FAULT;
    { int rc = agr_aot_ldr(s, 3, 297004u + 56u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 4, 297008u + 56u); if (rc) return rc; }
    s->r[3] += 297010u;
    { int rc = agr_aot_ldr(s, 5, 297012u + 56u); if (rc) return rc; }
    s->r[4] += 297014u;
    { int rc = agr_aot_ldr(s, 1, 297016u + 56u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 3);
    s->r[5] += 297020u;
    agr_aot_mov_reg(s, 2, 4);
    s->r[1] += 297024u;
    agr_aot_adds(s, 5, s->r[5], 8u);
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    agr_aot_branch_reg(s, 602820u | 1u, 297030u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00048846(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 297032u + 44u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 4);
    { int rc = agr_aot_ldr(s, 4, 297036u + 44u); if (rc) return rc; }
    s->r[3] += 297040u;
    { int rc = agr_aot_ldr(s, 1, 297040u + 44u); if (rc) return rc; }
    s->r[4] += 297044u;
    agr_aot_adds(s, 4, s->r[4], 8u);
    agr_aot_mov_reg(s, 0, 3);
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    s->r[1] += 297052u;
    if ((rc = agr_aot_ldmia_sp(s, 16440u))) return rc;
    s->r[15] = 602820u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009174c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 17392u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 7, 2);
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    s->r[13] -= 36u;
    { int rc = agr_aot_ldr(s, 2, 595800u + 284u); if (rc) return rc; }
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_mov_reg(s, 9, 1);
    s->r[2] += 595808u;
    { uint32_t addr = s->r[3] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, 595812u + 276u); if (rc) return rc; }
    s->r[2] += 595816u;
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, 595820u + 272u); if (rc) return rc; }
    s->r[2] += 595824u;
    { uint32_t addr = s->r[3] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, 595828u + 268u); if (rc) return rc; }
    s->r[2] += 595832u;
    { uint32_t addr = s->r[3] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, 595836u + 264u); if (rc) return rc; }
    s->r[2] += 595840u;
    { uint32_t addr = s->r[3] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, 595844u + 260u); if (rc) return rc; }
    s->r[2] += 595848u;
    { uint32_t addr = s->r[3] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, 595852u + 256u); if (rc) return rc; }
    s->r[2] += 595856u;
    { uint32_t addr = s->r[3] + 56u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, 595860u + 252u); if (rc) return rc; }
    s->r[2] += 595864u;
    { uint32_t addr = s->r[3] + 60u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, 595868u + 248u); if (rc) return rc; }
    s->r[2] += 595872u;
    { uint32_t addr = s->r[3] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, 595876u + 244u); if (rc) return rc; }
    s->r[2] += 595880u;
    { uint32_t addr = s->r[3] + 28u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, 595884u + 240u); if (rc) return rc; }
    s->r[2] += 595888u;
    { uint32_t addr = s->r[3] + 40u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, 595892u + 236u); if (rc) return rc; }
    s->r[2] += 595896u;
    { uint32_t addr = s->r[3] + 44u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_movs_imm(s, 0, 148u);
    { int rc = agr_aot_ldr(s, 2, 595904u + 228u); if (rc) return rc; }
    s->r[2] += 595906u;
    { uint32_t addr = s->r[3] + 48u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_branch_reg(s, 290408u, 595910u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000917c6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    agr_aot_movs_imm(s, 2, 148u);
    agr_aot_mov_reg(s, 5, 0);
    agr_aot_add_imm(s, 6, s->r[5], 64u);
    agr_aot_add_imm(s, 8, s->r[5], 68u);
    agr_aot_branch_reg(s, 289460u, 595928u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000917d8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    { uint32_t addr = s->r[5] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 290732u, 595938u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000917e2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 8);
    agr_aot_movs_imm(s, 1, 0u);
    agr_aot_branch_reg(s, 290744u, 595946u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000917ea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[9], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 595970u : 595952u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000917f0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 7);
    agr_aot_branch_reg(s, 290408u, 595958u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000917f6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[5] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    agr_aot_mov_reg(s, 1, 9);
    agr_aot_mov_reg(s, 2, 7);
    { uint32_t addr = s->r[5] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_branch_reg(s, 289580u, 595970u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00091802(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 13);
    agr_aot_branch_reg(s, 290756u, 595976u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00091808(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[0] ? 596008u : 595978u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009180a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 290528u, 595982u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009180e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 5, 0u);
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 290540u, 595990u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00091816(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 595992u + 144u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, 595996u + 144u); if (rc) return rc; }
    s->r[1] += 595998u;
    s->r[2] += 596000u;
    agr_aot_mov_reg(s, 3, 0);
    agr_aot_movs_imm(s, 0, 6u);
    agr_aot_branch_reg(s, 289436u, 596006u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00091826(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 596074u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00091828(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 0u); if (rc) return rc; }
    agr_aot_add_imm(s, 7, s->r[13], 8u);
    agr_aot_mov_reg(s, 0, 7);
    { uint32_t addr = s->r[5] + 72u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 4u); if (rc) return rc; }
    { uint32_t addr = s->r[5] + 76u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 290768u, 596024u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00091838(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 1, 1u);
    agr_aot_mov_reg(s, 0, 7);
    agr_aot_branch_reg(s, 290780u, 596032u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00091840(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, 596036u + 108u); if (rc) return rc; }
    agr_aot_add_imm(s, 0, s->r[5], 80u);
    agr_aot_mov_reg(s, 1, 7);
    s->r[2] += 596044u;
    agr_aot_mov_reg(s, 3, 5);
    agr_aot_branch_reg(s, 290792u, 596048u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00091850(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 290456u, 596054u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00091856(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 108u); if (rc) return rc; }
    s->r[15] = s->r[3] ? 596068u : 596058u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009185a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 8);
    agr_aot_mov_reg(s, 1, 6);
    agr_aot_branch_reg(s, 290552u, 596066u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00091862(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 596054u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00091864(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 290468u, 596074u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009186a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 28u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    s->r[13] += 36u;
    if ((rc = agr_aot_ldmia_sp(s, 33776u))) return rc;
}

static int aot_fast_000918b4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 596152u + 8u); if (rc) return rc; }
    s->r[3] += 596154u;
    agr_aot_adds(s, 3, s->r[3], 8u);
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000918c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 4, s->r[4], 22u);
    agr_aot_lsls(s, 5, s->r[0], 0u);
    agr_aot_movs_imm(s, 0, 0u);
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000918c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000918cc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000918d0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 596180u + 16u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    s->r[3] += 596184u;
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_adds(s, 3, s->r[3], 8u);
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 601516u | 1u, 596192u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000918e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_0009247c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16440u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_branch_reg(s, 600236u | 1u, 599172u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092484(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 1, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 599174u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009248a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[1], 71u);
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = agr_aot_condition(s, 0u) ? 599196u : 599184u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092490(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 599288u : 599188u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092494(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 4, 3);
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_mov_reg(s, 0, 4);
    if ((rc = agr_aot_ldmia_sp(s, 32824u))) return rc;
}

static int aot_fast_0009249c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 1, s->r[4] + 1u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[1], 78u);
    s->r[15] = agr_aot_condition(s, 1u) ? 599184u : 599202u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000924a2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 1, s->r[4] + 2u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[1], 85u);
    s->r[15] = agr_aot_condition(s, 1u) ? 599184u : 599208u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000924a8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 1, s->r[4] + 3u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[1], 67u);
    s->r[15] = agr_aot_condition(s, 1u) ? 599184u : 599214u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000924ae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 1, s->r[4] + 4u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[1], 67u);
    s->r[15] = agr_aot_condition(s, 1u) ? 599184u : 599220u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000924b4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 1, s->r[4] + 5u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[1], 43u);
    s->r[15] = agr_aot_condition(s, 1u) ? 599184u : 599226u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000924ba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 1, s->r[4] + 6u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[1], 43u);
    s->r[15] = agr_aot_condition(s, 1u) ? 599184u : 599232u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000924c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 1, s->r[4] + 7u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[1], 1u);
    s->r[15] = agr_aot_condition(s, 8u) ? 599184u : 599238u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000924c6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = (s->r[4] - 12u); if ((rc = agr_aot_ldr(s, 5, addr))) return rc; }
    agr_aot_cmp(s, s->r[5], 0u);
    s->r[15] = agr_aot_condition(s, 11u) ? 599282u : 599246u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000924ce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 5, s->r[5], 1u);
    s->r[15] = 599248u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000924d0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[0] + 4u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[2], s->r[3]);
    { uint32_t addr = (s->r[4] - 12u); if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    agr_aot_add_imm(s, 1, s->r[1], 1023u);
    { uint32_t addr = s->r[0] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    agr_aot_set_itstate(s, 28u); s->r[15] = 599264u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000924f6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 599248u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000924f8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 601972u | 1u, 599292u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000924fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 1, s->r[1], 1u);
    s->r[15] = agr_aot_condition(s, 0u) ? 599300u : 599296u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092500(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 601524u | 1u, 599300u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092504(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 599856u | 1u, 599304u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092508(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    agr_aot_branch_reg(s, 600192u | 1u, 599310u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009250e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 2, 0);
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 599442u : 599318u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009251a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[1], 71u);
    s->r[15] = agr_aot_condition(s, 0u) ? 599340u : 599326u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009251e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_adds(s, 0, s->r[0], 32u);
    { uint32_t addr = s->r[2] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    if ((rc = agr_aot_ldmia_sp(s, 16392u))) return rc;
    s->r[15] = 826846u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092530(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[1], 78u);
    s->r[15] = agr_aot_condition(s, 1u) ? 599326u : 599348u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092538(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[1], 85u);
    s->r[15] = agr_aot_condition(s, 1u) ? 599326u : 599356u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092540(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[1], 67u);
    s->r[15] = agr_aot_condition(s, 1u) ? 599326u : 599364u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092548(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[1], 67u);
    s->r[15] = agr_aot_condition(s, 1u) ? 599326u : 599372u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092550(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[1], 43u);
    s->r[15] = agr_aot_condition(s, 1u) ? 599326u : 599380u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092558(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[1], 43u);
    s->r[15] = agr_aot_condition(s, 1u) ? 599326u : 599388u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092560(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[1], 1u);
    s->r[15] = agr_aot_condition(s, 8u) ? 599326u : 599396u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092564(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[0] + 20u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[1], 0u);
    s->r[15] = agr_aot_condition(s, 11u) ? 599414u : 599402u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009256a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 1, s->r[1], 1u);
    s->r[15] = agr_aot_condition(s, 0u) ? 599424u : 599406u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009256e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 3, s->r[1], 1u);
    s->r[15] = agr_aot_condition(s, 0u) ? 599438u : 599410u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092572(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[0] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) return rc;
}

static int aot_fast_00092576(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 1, s->r[1], 1u);
    s->r[15] = agr_aot_condition(s, 1u) ? 599410u : 599418u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009257a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 16u); if (rc) return rc; }
    { uint32_t addr = s->r[2] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 599410u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092580(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[0] + 16u); if (rc) return rc; }
    agr_aot_adds(s, 0, s->r[0], 32u);
    if ((rc = agr_aot_ldmia_sp(s, 16392u))) return rc;
    { uint32_t addr = s->r[2] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    s->r[15] = 826846u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009258e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 601972u | 1u, 599442u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092592(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) return rc;
}

static int aot_fast_0009266c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    agr_aot_cmp(s, s->r[0], 0u);
    agr_aot_set_itstate(s, 20u); s->r[15] = 599666u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000926d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 71u);
    s->r[15] = agr_aot_condition(s, 0u) ? 599774u : 599770u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000926da(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000926de(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 1u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 78u);
    s->r[15] = agr_aot_condition(s, 1u) ? 599770u : 599780u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000926e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 2u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 85u);
    s->r[15] = agr_aot_condition(s, 1u) ? 599770u : 599786u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000926ea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 3u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 67u);
    s->r[15] = agr_aot_condition(s, 1u) ? 599770u : 599792u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000926f0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 4u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 67u);
    s->r[15] = agr_aot_condition(s, 1u) ? 599770u : 599798u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000926f6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 5u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 43u);
    s->r[15] = agr_aot_condition(s, 1u) ? 599770u : 599804u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000926fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 6u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 43u);
    s->r[15] = agr_aot_condition(s, 1u) ? 599770u : 599810u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092702(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 0, s->r[0] + 7u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[0], 1u);
    agr_aot_set_itstate(s, 140u); s->r[15] = 599816u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092730(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 20464u)) return AGR_AOT_FAULT;
    s->r[13] -= 28u;
    { int rc = agr_aot_ldr(s, 4, 599864u + 244u); if (rc) return rc; }
    agr_aot_mov_reg(s, 7, 0);
    s->r[4] += 599870u;
    agr_aot_branch_reg(s, 599764u | 1u, 599872u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092740(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[0] ? 599902u : 599874u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092742(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = (s->r[7] - 24u); if ((rc = agr_aot_ldr(s, 8, addr))) return rc; }
    agr_aot_mov_reg(s, 0, 7);
    { uint32_t addr = (s->r[7] - 20u); if ((rc = agr_aot_ldr(s, 5, addr))) return rc; }
    { int rc = agr_aot_ldr(s, 6, s->r[7] + 40u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 10, s->r[7] + 48u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 7, s->r[7] + 52u); if (rc) return rc; }
    agr_aot_branch_reg(s, 599164u | 1u, 599896u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092758(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 8);
    agr_aot_branch_reg(s, 601992u | 1u, 599902u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009275e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 7);
    agr_aot_branch_reg(s, 599164u | 1u, 599908u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092764(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 602000u | 1u, 599912u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092768(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 599164u | 1u, 599916u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009276c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 601972u | 1u, 599920u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092770(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 599164u | 1u, 599924u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092774(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 600192u | 1u, 599928u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092778(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 11, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 599932u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092780(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 1u);
    s->r[15] = agr_aot_condition(s, 0u) ? 600042u : 599940u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092784(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 3, s->r[11], 120u);
    s->r[15] = 599944u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092788(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 2, s->r[13], 24u);
    s->r[8] = 0u;
    agr_aot_mov_reg(s, 9, 7);
    agr_aot_mov_reg(s, 7, 8);
    { uint32_t addr = (s->r[2] - 8u); s->r[2] = s->r[2] - 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 599958u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009279a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 3, s->r[13], 20u);
    { uint32_t addr = s->r[13] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[10]); }
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[13] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_cmp(s, s->r[7], s->r[6]);
    s->r[15] = agr_aot_condition(s, 10u) ? 600068u : 599976u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000927a8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[9] + 0u); if (rc) return rc; }
    s->r[15] = !s->r[3] ? 600064u : 599982u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000927ae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 10, s->r[3] + (s->r[9] << 0u)); if (rc) return rc; }
    s->r[15] = 599986u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000927b2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 0, s->r[11], 32u);
    agr_aot_mov_reg(s, 1, 10);
    agr_aot_movs_imm(s, 2, 0u);
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 4u); if (rc) return rc; }
    agr_aot_branch_reg(s, 601536u | 1u, 600000u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000927c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 3, 0);
    s->r[15] = s->r[0] ? 600048u : 600004u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000927c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 600008u + 104u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 10);
    { int rc = agr_aot_ldr(s, 14, s->r[10] + 0u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[13], 20u);
    { uint32_t addr = s->r[13] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_movs_imm(s, 3, 1u);
    { int rc = agr_aot_ldr(s, 1, s->r[4] + s->r[1]); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 12, s->r[14] + 16u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[12], 600026u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000927da(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[13] + 8u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[0], 0u);
    agr_aot_set_itstate(s, 24u); s->r[15] = 600032u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000927ea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[11] + 0u); if (rc) return rc; }
    s->r[15] = 599944u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000927f0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 601060u | 1u, 600052u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000927f4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 599304u | 1u, 600056u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000927f8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 599304u | 1u, 600060u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000927fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 601524u | 1u, 600064u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092800(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 10, 3);
    s->r[15] = 599986u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092804(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[8], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 600100u : 600074u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009280a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 4u);
    agr_aot_branch_reg(s, 602296u | 1u, 600080u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092810(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 600084u + 32u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, 600084u + 28u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, 600088u + 32u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[4] + s->r[3]); if (rc) return rc; }
    agr_aot_adds(s, 3, s->r[3], 8u);
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { int rc = agr_aot_ldr(s, 1, s->r[4] + s->r[1]); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, s->r[4] + s->r[2]); if (rc) return rc; }
    agr_aot_branch_reg(s, 600912u | 1u, 600100u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092824(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_branch_reg(s, 601932u | 1u, 600106u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009282e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 5, s->r[0], 0u);
    s->r[15] = 600112u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009283c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = !s->r[0] ? 600138u : 600130u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092842(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 4u); if (rc) return rc; }
    s->r[15] = s->r[3] ? 600142u : 600134u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092846(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    { uint32_t addr = s->r[4] + 4u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    s->r[15] = 600138u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009284a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_0009284e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 290816u, 600148u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092854(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 600134u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092880(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    { int rc = agr_aot_ldr(s, 3, 600196u + 32u); if (rc) return rc; }
    s->r[3] += 600200u;
    { int rc = agr_aot_ldrb(s, 2, s->r[3] + 4u); if (rc) return rc; }
    s->r[15] = s->r[2] ? 600208u : 600202u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009288a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 600204u + 28u); if (rc) return rc; }
    s->r[0] += 600208u;
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) return rc;
}

static int aot_fast_00092890(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 290828u, 600214u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092896(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) return rc;
}

static int aot_fast_000928ac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 600240u + 76u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    s->r[3] += 600244u;
    { int rc = agr_aot_ldr(s, 4, 600244u + 76u); if (rc) return rc; }
    { int rc = agr_aot_ldrb(s, 2, s->r[3] + 4u); if (rc) return rc; }
    s->r[4] += 600250u;
    s->r[15] = s->r[2] ? 600254u : 600250u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000928ba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_000928be(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 290828u, 600260u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000928c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 600250u : 600266u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000928ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 12u);
    agr_aot_branch_reg(s, 290408u, 600272u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000928d0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = !s->r[0] ? 600298u : 600276u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000928d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 600280u + 44u); if (rc) return rc; }
    agr_aot_mov_reg(s, 1, 0);
    s->r[3] += 600284u;
    { int rc = agr_aot_ldr(s, 0, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 290840u, 600288u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000928e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = s->r[0] ? 600298u : 600290u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000928e2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    { uint32_t addr = s->r[4] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    { uint32_t addr = s->r[4] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 600250u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000928ea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 601972u | 1u, 600302u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000928ee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 1, s->r[1], 1u);
    s->r[15] = agr_aot_condition(s, 0u) ? 600310u : 600306u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000928f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 601524u | 1u, 600310u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000928f6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 599856u | 1u, 600314u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000928fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 4, s->r[6] + s->r[3]); if (rc) return rc; }
    agr_aot_lsls(s, 5, s->r[0], 0u);
    { int rc = agr_aot_ldrb(s, 6, s->r[6] + s->r[3]); if (rc) return rc; }
    agr_aot_lsls(s, 5, s->r[0], 0u);
    { int rc = agr_aot_ldrb(s, 4, s->r[1] + s->r[3]); if (rc) return rc; }
    agr_aot_lsls(s, 5, s->r[0], 0u);
    { int rc = agr_aot_ldr(s, 3, 600332u + 20u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    s->r[3] += 600336u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_adds(s, 3, s->r[3], 8u);
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 600672u | 1u, 600346u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009291a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_00092a1c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 601516u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092a60(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 600676u + 20u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    s->r[3] += 600680u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_adds(s, 3, s->r[3], 8u);
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 596148u | 1u, 600690u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092a72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_00092b50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 17400u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_mov_reg(s, 8, 1);
    agr_aot_mov_reg(s, 9, 2);
    agr_aot_branch_reg(s, 600236u | 1u, 600926u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092b5e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 5, 600928u + 120u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, 600932u + 120u); if (rc) return rc; }
    s->r[15] = 600930u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092b66(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[5] += 600938u;
    { int rc = agr_aot_ldr(s, 5, s->r[5] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, 600940u + 116u); if (rc) return rc; }
    s->r[3] += 600944u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    s->r[12] = 1u;
    { int rc = agr_aot_ldr(s, 2, s->r[5] + 0u); if (rc) return rc; }
    s->r[1] += 600954u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    s->r[14] = 71u;
    agr_aot_movs_imm(s, 5, 78u);
    { int rc = agr_aot_ldr(s, 7, s->r[0] + 4u); if (rc) return rc; }
    s->r[7] += s->r[12];
    { uint32_t addr = s->r[0] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = (s->r[4] - 120u); if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    agr_aot_movs_imm(s, 7, 85u);
    { uint32_t addr = (s->r[4] - 128u); if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[12]); }
    s->r[8] = 0u;
    { uint32_t addr = (s->r[4] - 112u); if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_movs_imm(s, 2, 67u);
    { uint32_t addr = (s->r[4] - 108u); if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 600992u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092ba4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 3, 43u);
    { uint32_t addr = (s->r[4] - 80u); if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    s->r[15] = 601002u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092bba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = (s->r[4] - 116u); if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[9]); }
    s->r[15] = 601022u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092bca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 828576u | 1u, 601038u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092bce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 599164u | 1u, 601044u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092bd4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 601972u | 1u, 601048u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092bd8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 7, 601052u + 360u); if (rc) return rc; }
    agr_aot_lsls(s, 5, s->r[0], 0u);
    { int rc = agr_aot_ldr(s, 7, 601056u + 352u); if (rc) return rc; }
    agr_aot_lsls(s, 5, s->r[0], 0u);
    s->r[15] = 601056u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092be4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_branch_reg(s, 600236u | 1u, 601066u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092bea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[0] + 4u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_adds(s, 2, s->r[2], 1u);
    { uint32_t addr = s->r[0] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = !s->r[3] ? 601104u : 601076u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092bf8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 71u);
    s->r[15] = agr_aot_condition(s, 0u) ? 601108u : 601084u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092bfc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 601088u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092c00(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 4, s->r[3], 32u);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 828648u | 1u, 601098u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092c0a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 599164u | 1u, 601104u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092c10(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 601972u | 1u, 601108u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092c18(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 78u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601084u : 601116u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092c20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 85u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601084u : 601124u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092c28(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 67u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601084u : 601132u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092c30(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 67u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601084u : 601140u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092c38(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 43u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601084u : 601148u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092c40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 43u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601084u : 601156u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092c48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 1u);
    s->r[15] = agr_aot_condition(s, 8u) ? 601084u : 601164u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092c4c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 20u); if (rc) return rc; }
    s->r[15] = 601166u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092c50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[3] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 601088u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092d08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 17392u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 5, 0);
    { int rc = agr_aot_ldr(s, 6, s->r[0] + 0u); if (rc) return rc; }
    s->r[13] -= 44u;
    agr_aot_movs_imm(s, 4, 0u);
    agr_aot_mov_reg(s, 8, 1);
    s->r[14] = 16u;
    agr_aot_mov_reg(s, 1, 3);
    { uint32_t addr = (s->r[6] - 4u); if ((rc = agr_aot_ldr(s, 0, addr))) return rc; }
    agr_aot_mov_reg(s, 9, 2);
    { uint32_t addr = (s->r[6] - 8u); if ((rc = agr_aot_ldr(s, 12, addr))) return rc; }
    agr_aot_mov_reg(s, 7, 3);
    { uint32_t addr = s->r[13] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    agr_aot_mov_reg(s, 3, 2);
    { int rc = agr_aot_ldr(s, 6, s->r[0] + 0u); if (rc) return rc; }
    s->r[12] += s->r[5];
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    agr_aot_movs_imm(s, 2, 6u);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[12]); }
    agr_aot_add_imm(s, 12, s->r[13], 20u);
    { uint32_t addr = s->r[13] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { uint32_t addr = s->r[13] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[12]); }
    { uint32_t addr = s->r[13] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { int rc = agr_aot_ldr(s, 6, s->r[6] + 28u); if (rc) return rc; }
    { uint32_t addr = s->r[13] + 28u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[13] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[13] + 36u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[14]); }
    agr_aot_branch_reg(s, s->r[6], 601426u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092d52(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 20u); if (rc) return rc; }
    s->r[15] = !s->r[0] ? 601474u : 601430u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092d56(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 4, s->r[13] + 32u); if (rc) return rc; }
    s->r[3] = s->r[4] & 6u;
    agr_aot_cmp(s, s->r[3], 6u);
    s->r[15] = agr_aot_condition(s, 0u) ? 601476u : 601440u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092d60(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 28u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, s->r[13] + 24u); if (rc) return rc; }
    s->r[15] = 601444u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092d66(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[2] = s->r[2] & 6u;
    agr_aot_cmp(s, s->r[2], 6u);
    s->r[15] = agr_aot_condition(s, 0u) ? 601476u : 601454u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092d6e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[3] = s->r[3] & 5u;
    agr_aot_cmp(s, s->r[3], 4u);
    s->r[15] = agr_aot_condition(s, 0u) ? 601474u : 601462u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092d76(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = s->r[4] ? 601474u : 601464u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092d78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[7], 0u);
    s->r[15] = agr_aot_condition(s, 11u) ? 601482u : 601468u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092d7c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[7] += s->r[0];
    agr_aot_cmp(s, s->r[5], s->r[7]);
    s->r[15] = agr_aot_condition(s, 0u) ? 601476u : 601474u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092d82(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = 601476u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092d84(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 44u;
    if ((rc = agr_aot_ldmia_sp(s, 33776u))) return rc;
}

static int aot_fast_00092d8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 3, s->r[7], 2u);
    s->r[15] = agr_aot_condition(s, 0u) ? 601474u : 601486u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092d8e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 4, s->r[9] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 0);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    agr_aot_mov_reg(s, 1, 7);
    agr_aot_mov_reg(s, 3, 8);
    agr_aot_mov_reg(s, 0, 9);
    { int rc = agr_aot_ldr(s, 4, s->r[4] + 32u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[4], 601504u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092da0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[0] = s->r[0] & 6u;
    agr_aot_cmp(s, s->r[0], 6u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601474u : 601512u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092da8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 20u); if (rc) return rc; }
    s->r[15] = 601476u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092dac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[0] ? 601522u : 601518u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092dae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 831120u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092db2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092db4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 30u)) return AGR_AOT_FAULT;
    agr_aot_branch_reg(s, 601820u | 1u, 601530u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092dba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 30u))) return rc;
    agr_aot_branch_reg(s, 828612u | 1u, 601536u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092dc0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16880u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 5, 1);
    { int rc = agr_aot_ldrb(s, 2, s->r[0] + 0u); if (rc) return rc; }
    s->r[13] -= 8u;
    agr_aot_mov_reg(s, 6, 3);
    agr_aot_cmp(s, s->r[2], 71u);
    s->r[15] = agr_aot_condition(s, 0u) ? 601614u : 601552u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092dd0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 4, 601556u + 156u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[4] += 601562u;
    { int rc = agr_aot_ldr(s, 4, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 601562u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092dda(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    s->r[8] = 1u;
    { int rc = agr_aot_ldr(s, 3, s->r[2] + 8u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[3], 601574u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092de6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[0] ? 601586u : 601576u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092de8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 4u); if (rc) return rc; }
    s->r[8] = 2u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 601586u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092df2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 7, s->r[5] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 1, 4);
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_movs_imm(s, 3, 1u);
    { int rc = agr_aot_ldr(s, 4, s->r[7] + 16u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[4], 601600u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092e00(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[0] ? 601608u : 601602u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092e02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 4u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 8);
    { uint32_t addr = s->r[6] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 601608u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092e08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) return rc;
}

static int aot_fast_00092e0e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 1u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 78u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601552u : 601620u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092e14(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 2u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 85u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601552u : 601626u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092e1a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 3u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 67u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601552u : 601632u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092e20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 4u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 70u);
    s->r[15] = agr_aot_condition(s, 0u) ? 601684u : 601638u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092e26(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 4u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 67u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601552u : 601644u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092e2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 5u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 43u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601552u : 601650u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092e32(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 6u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 43u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601552u : 601656u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092e38(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 7u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 1u);
    s->r[15] = agr_aot_condition(s, 8u) ? 601552u : 601662u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092e3e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 601674u : 601664u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092e40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = (s->r[0] - 32u); if ((rc = agr_aot_ldr(s, 4, addr))) return rc; }
    agr_aot_adds(s, 0, s->r[0], 88u);
    s->r[15] = 601670u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092e46(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 601562u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092e4a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = (s->r[0] - 32u); if ((rc = agr_aot_ldr(s, 0, addr))) return rc; }
    { uint32_t addr = (s->r[0] - 120u); if ((rc = agr_aot_ldr(s, 4, addr))) return rc; }
    s->r[15] = 601670u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092e54(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 5u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 79u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601638u : 601690u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092e5a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 6u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 82u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601638u : 601696u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092e60(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 7u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601638u : 601702u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092e66(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 4, 601704u + 12u); if (rc) return rc; }
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[4] += 601710u;
    { int rc = agr_aot_ldr(s, 4, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 601562u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092e78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_branch_reg(s, 600236u | 1u, 601728u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092e80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 601730u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092e86(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 71u);
    s->r[15] = agr_aot_condition(s, 0u) ? 601748u : 601738u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092e8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = s->r[3] ? 601816u : 601742u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092e8e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[0] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 601744u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092e90(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 1u);
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_00092e94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[4] + 1u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 78u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601738u : 601754u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092e9a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[4] + 2u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 85u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601738u : 601760u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092ea0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[4] + 3u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 67u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601738u : 601766u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092ea6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[4] + 4u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 67u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601738u : 601772u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092eac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[4] + 5u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 43u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601738u : 601778u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092eb2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[4] + 6u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 43u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601738u : 601784u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092eb8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[4] + 7u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 1u);
    s->r[15] = agr_aot_condition(s, 8u) ? 601738u : 601790u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092ebe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = (s->r[4] - 4u); if ((rc = agr_aot_ldr(s, 3, addr))) return rc; }
    agr_aot_adds(s, 3, s->r[3], 1u);
    { uint32_t addr = (s->r[4] - 4u); if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_cmp(s, s->r[3], 1u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601744u : 601804u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092ecc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 8u); if (rc) return rc; }
    { uint32_t addr = (s->r[4] - 8u); if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[0] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_movs_imm(s, 0, 1u);
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_00092ed8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 601972u | 1u, 601820u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092edc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    agr_aot_branch_reg(s, 600236u | 1u, 601826u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092ee2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = !s->r[3] ? 601928u : 601830u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092eea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 71u);
    s->r[15] = agr_aot_condition(s, 0u) ? 601848u : 601838u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092eee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    { uint32_t addr = s->r[0] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 601842u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092ef2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 0, s->r[3], 32u);
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) return rc;
}

static int aot_fast_00092efc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 78u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601838u : 601856u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092f04(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 85u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601838u : 601864u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092f0c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 67u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601838u : 601872u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092f14(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 67u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601838u : 601880u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092f1c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 43u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601838u : 601888u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092f24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 43u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601838u : 601896u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092f2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 1u);
    s->r[15] = agr_aot_condition(s, 8u) ? 601838u : 601904u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092f30(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 28u); if (rc) return rc; }
    agr_aot_subs(s, 2, s->r[2], 1u);
    { uint32_t addr = s->r[3] + 28u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_cmp(s, s->r[2], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 601842u : 601914u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092f3a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 24u); if (rc) return rc; }
    agr_aot_movs_imm(s, 1, 0u);
    { uint32_t addr = s->r[0] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_add_imm(s, 0, s->r[3], 32u);
    { uint32_t addr = s->r[3] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) return rc;
}

static int aot_fast_00092f48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 601972u | 1u, 601932u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092f4c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    agr_aot_branch_reg(s, s->r[0], 601936u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092f50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 290804u, 601940u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092f54(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 599164u | 1u, 601944u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092f58(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 290804u, 601948u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092f5c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 5, 1);
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_branch_reg(s, 599304u | 1u, 601956u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092f64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 5, s->r[5], 1u);
    s->r[15] = agr_aot_condition(s, 0u) ? 601964u : 601960u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092f68(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 601524u | 1u, 601964u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092f6c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 599856u | 1u, 601970u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092f74(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    { int rc = agr_aot_ldr(s, 3, 601976u + 12u); if (rc) return rc; }
    s->r[3] += 601980u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 0, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 601932u | 1u, 601986u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092f84(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 601992u + 304u); if (rc) return rc; }
    agr_aot_lsls(s, 5, s->r[0], 0u);
    s->r[15] = 601992u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092f88(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    agr_aot_branch_reg(s, s->r[0], 601996u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092f8c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 601972u | 1u, 602000u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092f90(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    { int rc = agr_aot_ldr(s, 3, 602004u + 12u); if (rc) return rc; }
    s->r[3] += 602008u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 0, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 601992u | 1u, 602014u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092fa0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 602020u + 176u); if (rc) return rc; }
    agr_aot_lsls(s, 5, s->r[0], 0u);
    { int rc = agr_aot_ldr(s, 3, 602024u + 12u); if (rc) return rc; }
    s->r[3] += 602026u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_mov_reg(s, 0, 2);
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092fb4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 602040u + 120u); if (rc) return rc; }
    agr_aot_lsls(s, 5, s->r[0], 0u);
    { int rc = agr_aot_ldr(s, 3, 602044u + 12u); if (rc) return rc; }
    s->r[3] += 602046u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_mov_reg(s, 0, 2);
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092fc8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 602060u + 24u); if (rc) return rc; }
    agr_aot_lsls(s, 5, s->r[0], 0u);
    s->r[15] = 602060u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092fcc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    agr_aot_branch_reg(s, 599660u | 1u, 602066u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00092fd2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) return rc;
}

static int aot_fast_00093068(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    agr_aot_movs_imm(s, 0, 4u);
    agr_aot_branch_reg(s, 602296u | 1u, 602224u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093070(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 602228u + 16u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, 602228u + 20u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, 602232u + 20u); if (rc) return rc; }
    s->r[3] += 602234u;
    agr_aot_adds(s, 3, s->r[3], 8u);
    s->r[1] += 602238u;
    s->r[2] += 602240u;
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 600912u | 1u, 602244u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093084(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 5, 222u);
    agr_aot_lsls(s, 5, s->r[0], 0u);
    agr_aot_movs_imm(s, 5, 194u);
    agr_aot_lsls(s, 5, s->r[0], 0u);
    s->r[15] = 602252u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093090(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    agr_aot_movs_imm(s, 0, 4u);
    agr_aot_branch_reg(s, 602296u | 1u, 602264u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093098(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 602268u + 16u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, 602268u + 20u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, 602272u + 20u); if (rc) return rc; }
    s->r[3] += 602274u;
    agr_aot_adds(s, 3, s->r[3], 8u);
    s->r[1] += 602278u;
    s->r[2] += 602280u;
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 600912u | 1u, 602284u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000930ac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 5, 206u);
    agr_aot_lsls(s, 5, s->r[0], 0u);
    agr_aot_movs_imm(s, 5, 166u);
    agr_aot_lsls(s, 5, s->r[0], 0u);
    s->r[15] = 602292u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000930b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16440u)) return AGR_AOT_FAULT;
    agr_aot_add_imm(s, 5, s->r[0], 128u);
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_branch_reg(s, 290408u, 602308u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000930c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = !s->r[0] ? 602328u : 602312u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000930c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_movs_imm(s, 1, 0u);
    agr_aot_movs_imm(s, 2, 128u);
    agr_aot_branch_reg(s, 289460u, 602322u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000930d2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 128u);
    if ((rc = agr_aot_ldmia_sp(s, 32824u))) return rc;
}

static int aot_fast_000930d8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 602332u + 96u); if (rc) return rc; }
    s->r[0] += 602334u;
    agr_aot_branch_reg(s, 290456u, 602336u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000930e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = s->r[0] ? 602416u : 602338u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000930e2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 602340u + 92u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[5], 512u);
    s->r[3] += 602348u;
    { int rc = agr_aot_ldr(s, 1, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_set_itstate(s, 156u); s->r[15] = 602350u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093128(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 1, s->r[1], 1u);
    s->r[15] = agr_aot_condition(s, 0u) ? 602422u : 602412u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009312c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 601524u | 1u, 602416u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093130(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 602216u | 1u, 602420u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093134(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 602408u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093136(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 599856u | 1u, 602426u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009313c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 60u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_lsls(s, 5, s->r[0], 0u);
    { uint32_t addr = s->r[3] + 60u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_lsls(s, 5, s->r[0], 0u);
    { uint32_t addr = s->r[6] + 56u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_lsls(s, 5, s->r[0], 0u);
    { uint32_t addr = s->r[6] + 56u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    agr_aot_lsls(s, 5, s->r[0], 0u);
    { uint32_t addr = s->r[5] + 56u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_lsls(s, 5, s->r[0], 0u);
    s->r[15] = 602448u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093150(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 602452u + 92u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    s->r[3] += 602456u;
    agr_aot_cmp(s, s->r[0], s->r[3]);
    s->r[15] = agr_aot_condition(s, 3u) ? 602466u : 602458u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009315a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 2, s->r[3], 3200u);
    agr_aot_cmp(s, s->r[0], s->r[2]);
    s->r[15] = agr_aot_condition(s, 3u) ? 602476u : 602466u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093162(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 0, s->r[0], 128u);
    if ((rc = agr_aot_ldmia_sp(s, 16400u))) return rc;
    s->r[15] = 831120u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009316c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 3, s->r[0], s->r[3]);
    { int rc = agr_aot_ldr(s, 0, 602480u + 68u); if (rc) return rc; }
    s->r[0] += 602484u;
    s->r[15] = 602482u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093174(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 290456u, 602488u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093178(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = s->r[0] ? 602520u : 602490u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009317a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, 602492u + 60u); if (rc) return rc; }
    agr_aot_movs_imm(s, 1, 1u);
    { int rc = agr_aot_ldr(s, 0, 602496u + 60u); if (rc) return rc; }
    agr_aot_lsls_reg(s, 4, s->r[1], s->r[4]);
    s->r[2] += 602504u;
    s->r[0] += 602506u;
    { int rc = agr_aot_ldr(s, 1, s->r[2] + 0u); if (rc) return rc; }
    s->r[15] = 602506u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009318e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[2] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    agr_aot_branch_reg(s, 290468u, 602516u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093194(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = s->r[0] ? 602532u : 602518u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093196(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_00093198(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 602216u | 1u, 602524u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009319c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 1, s->r[1], 1u);
    s->r[15] = agr_aot_condition(s, 0u) ? 602538u : 602528u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000931a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 601524u | 1u, 602532u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000931a4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 602256u | 1u, 602536u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000931a8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 602524u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000931aa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 599856u | 1u, 602542u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000931b0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[6] + 52u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_lsls(s, 5, s->r[0], 0u);
    { uint32_t addr = s->r[1] + 52u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    agr_aot_lsls(s, 5, s->r[0], 0u);
    { uint32_t addr = s->r[7] + 48u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    agr_aot_lsls(s, 5, s->r[0], 0u);
    { uint32_t addr = s->r[6] + 48u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    agr_aot_lsls(s, 5, s->r[0], 0u);
    if (agr_aot_stmdb_sp(s, 16440u)) return AGR_AOT_FAULT;
    agr_aot_movs_imm(s, 0, 120u);
    agr_aot_branch_reg(s, 290408u, 602568u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000931c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = !s->r[0] ? 602586u : 602572u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000931cc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_movs_imm(s, 1, 0u);
    agr_aot_movs_imm(s, 2, 120u);
    agr_aot_branch_reg(s, 289460u, 602582u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000931d6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    if ((rc = agr_aot_ldmia_sp(s, 32824u))) return rc;
}

static int aot_fast_000931da(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 602588u + 92u); if (rc) return rc; }
    s->r[0] += 602592u;
    agr_aot_branch_reg(s, 290456u, 602594u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000931e2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = s->r[0] ? 602676u : 602596u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000931e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 602600u + 84u); if (rc) return rc; }
    s->r[3] += 602602u;
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 3, 2);
    s->r[15] = 602614u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000931ee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 0, s->r[0], 1u);
    s->r[15] = 602608u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000931f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 32u);
    s->r[15] = agr_aot_condition(s, 0u) ? 602658u : 602614u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000931f6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 1, s->r[3], 31u);
    s->r[15] = agr_aot_condition(s, 4u) ? 602606u : 602618u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000931fa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 602620u + 68u); if (rc) return rc; }
    agr_aot_movs_imm(s, 5, 1u);
    s->r[15] = 602622u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093204(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 4, 602632u + 60u); if (rc) return rc; }
    s->r[3] += 602634u;
    { int rc = agr_aot_ldr(s, 0, 602636u + 60u); if (rc) return rc; }
    s->r[15] = 602634u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009320c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[4] += 602640u;
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[0] += 602644u;
    s->r[15] = 602642u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093216(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 290468u, 602650u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009321a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 602572u : 602654u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009321e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 602256u | 1u, 602658u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093222(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 601972u | 1u, 602662u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093226(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 1, s->r[1], 1u);
    s->r[15] = agr_aot_condition(s, 0u) ? 602672u : 602666u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009322a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 601524u | 1u, 602670u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009322e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 602662u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093230(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 599856u | 1u, 602676u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093234(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 602216u | 1u, 602680u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093238(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 44u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_lsls(s, 5, s->r[0], 0u);
    s->r[15] = 602684u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009323e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 5, s->r[0], 0u);
    s->r[15] = 602688u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093242(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 5, s->r[0], 0u);
    s->r[15] = 602692u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093246(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 5, s->r[0], 0u);
    { uint32_t addr = s->r[5] + 40u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    agr_aot_lsls(s, 5, s->r[0], 0u);
    s->r[15] = 602700u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009324c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 602704u + 100u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    s->r[3] += 602708u;
    agr_aot_cmp(s, s->r[0], s->r[3]);
    s->r[15] = agr_aot_condition(s, 3u) ? 602718u : 602710u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093256(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 2, s->r[3], 3696u);
    agr_aot_cmp(s, s->r[0], s->r[2]);
    s->r[15] = agr_aot_condition(s, 3u) ? 602726u : 602718u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009325e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 16400u))) return rc;
    s->r[15] = 831120u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093266(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 3, s->r[0], s->r[3]);
    agr_aot_movw(s, 2, 34953u);
    s->r[2] = (s->r[2] & 0xffffu) | (34952u << 16);
    { int rc = agr_aot_ldr(s, 0, 602740u + 68u); if (rc) return rc; }
    s->r[15] = 602738u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093276(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[0] += 602746u;
    s->r[15] = 602744u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009327a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 290456u, 602750u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009327e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = s->r[0] ? 602782u : 602752u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093280(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, 602756u + 56u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 1u);
    { int rc = agr_aot_ldr(s, 0, 602760u + 56u); if (rc) return rc; }
    agr_aot_lsls_reg(s, 4, s->r[3], s->r[4]);
    s->r[2] += 602766u;
    s->r[0] += 602768u;
    { int rc = agr_aot_ldr(s, 3, s->r[2] + 0u); if (rc) return rc; }
    s->r[15] = 602768u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093294(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[2] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 290468u, 602778u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009329a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = s->r[0] ? 602794u : 602780u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009329c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_0009329e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 602216u | 1u, 602786u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000932a2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 1, s->r[1], 1u);
    s->r[15] = agr_aot_condition(s, 0u) ? 602800u : 602790u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000932a6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 601524u | 1u, 602794u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000932aa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 602256u | 1u, 602798u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000932ae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 602786u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000932b0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 599856u | 1u, 602804u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000932b6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 5, s->r[0], 0u);
    { uint32_t addr = s->r[0] + 36u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    agr_aot_lsls(s, 5, s->r[0], 0u);
    s->r[15] = 602812u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000932be(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 5, s->r[0], 0u);
    { uint32_t addr = s->r[6] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_lsls(s, 5, s->r[0], 0u);
    s->r[15] = 602820u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000932c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 3, 0);
    agr_aot_mov_reg(s, 0, 1);
    agr_aot_mov_reg(s, 1, 3);
    s->r[15] = 831152u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009334c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 20464u)) return AGR_AOT_FAULT;
    s->r[13] -= 20u;
    { int rc = agr_aot_ldr(s, 4, 602964u + 1204u); if (rc) return rc; }
    agr_aot_mov_reg(s, 11, 0);
    { int rc = agr_aot_ldr(s, 3, 602972u + 1200u); if (rc) return rc; }
    s->r[4] += 602976u;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + s->r[3]); if (rc) return rc; }
    { uint32_t addr = s->r[13] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = 602982u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009336a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 0, s->r[8], 1u);
    s->r[15] = 602990u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093372(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[1], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 602982u : 602998u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093376(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    atomic_thread_fence(memory_order_seq_cst);
    agr_aot_cmp(s, s->r[8], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 603016u : 603008u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093380(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 11);
    s->r[13] += 20u;
    if ((rc = agr_aot_ldmia_sp(s, 36848u))) return rc;
}

static int aot_fast_00093388(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 603020u + 1156u); if (rc) return rc; }
    agr_aot_movs_imm(s, 0, 1u);
    { int rc = agr_aot_ldr(s, 1, 603024u + 1156u); if (rc) return rc; }
    s->r[7] = 4294967295u;
    { int rc = agr_aot_ldr(s, 2, 603032u + 1152u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[4] + s->r[3]); if (rc) return rc; }
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[0]); }
    { int rc = agr_aot_ldr(s, 9, s->r[4] + (s->r[1] << 0u)); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[4] + s->r[2]); if (rc) return rc; }
    agr_aot_add_imm(s, 0, s->r[9], 28u);
    agr_aot_adds(s, 3, s->r[3], 8u);
    { uint32_t addr = s->r[9] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    if (agr_aot_stm(s, 9u, 264u)) return AGR_AOT_FAULT;
    { uint32_t addr = s->r[9] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    { uint32_t addr = s->r[9] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    { uint32_t addr = s->r[9] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    { uint32_t addr = s->r[9] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 691896u | 1u, 603080u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000933c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, 603084u + 1104u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 0, 603088u + 1104u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, 603092u + 1104u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, s->r[4] + s->r[2]); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 4u); if (rc) return rc; }
    agr_aot_add_imm(s, 10, s->r[2], 8u);
    { uint32_t addr = s->r[9] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[10]); }
    { int rc = agr_aot_ldr(s, 2, s->r[4] + s->r[0]); if (rc) return rc; }
    { uint32_t addr = s->r[9] + 36u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[13] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_adds(s, 2, s->r[2], 84u);
    { uint32_t addr = s->r[9] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { int rc = agr_aot_ldr(s, 5, s->r[4] + s->r[1]); if (rc) return rc; }
    agr_aot_add_imm(s, 0, s->r[5], 28u);
    if (agr_aot_stm(s, 5u, 264u)) return AGR_AOT_FAULT;
    { uint32_t addr = s->r[5] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    { uint32_t addr = s->r[5] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    { uint32_t addr = s->r[5] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    { uint32_t addr = s->r[5] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    { uint32_t addr = s->r[5] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 691896u | 1u, 603154u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093412(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 12u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, 603160u + 1040u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 4u); if (rc) return rc; }
    { uint32_t addr = s->r[5] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { uint32_t addr = s->r[5] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[10]); }
    { uint32_t addr = s->r[5] + 36u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { int rc = agr_aot_ldr(s, 6, s->r[4] + s->r[2]); if (rc) return rc; }
    agr_aot_add_imm(s, 0, s->r[6], 28u);
    if (agr_aot_stm(s, 6u, 264u)) return AGR_AOT_FAULT;
    { uint32_t addr = s->r[6] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    { uint32_t addr = s->r[6] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    { uint32_t addr = s->r[6] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    { uint32_t addr = s->r[6] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    { uint32_t addr = s->r[6] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    agr_aot_branch_reg(s, 691896u | 1u, 603204u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093444(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 603208u + 996u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 12u); if (rc) return rc; }
    { uint32_t addr = s->r[6] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[10]); }
    agr_aot_add_imm(s, 2, s->r[0], 168u);
    { uint32_t addr = s->r[6] + 36u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { int rc = agr_aot_ldr(s, 7, s->r[4] + s->r[3]); if (rc) return rc; }
    agr_aot_add_imm(s, 10, s->r[7], 4u);
    agr_aot_mov_reg(s, 0, 10);
    agr_aot_branch_reg(s, 612328u | 1u, 603232u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093460(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 603236u + 972u); if (rc) return rc; }
    { uint32_t addr = s->r[7] + 116u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    agr_aot_mov_reg(s, 0, 10);
    { uint32_t addr = s->r[7] + 120u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[8]); }
    agr_aot_mov_reg(s, 1, 9);
    { uint32_t addr = s->r[7] + 121u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[8]); }
    { uint32_t addr = s->r[7] + 124u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    { uint32_t addr = s->r[7] + 128u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    { uint32_t addr = s->r[7] + 132u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    { uint32_t addr = s->r[7] + 136u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    { int rc = agr_aot_ldr(s, 10, s->r[4] + (s->r[3] << 0u)); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[10], 12u);
    agr_aot_add_imm(s, 3, s->r[10], 32u);
    if (agr_aot_stm(s, 7u, 12u)) return AGR_AOT_FAULT;
    agr_aot_branch_reg(s, 605660u | 1u, 603286u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093496(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 603288u + 924u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 8, s->r[4] + (s->r[3] << 0u)); if (rc) return rc; }
    agr_aot_add_imm(s, 9, s->r[8], 8u);
    agr_aot_mov_reg(s, 0, 9);
    agr_aot_branch_reg(s, 612328u | 1u, 603302u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000934a6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, 603304u + 912u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    { uint32_t addr = s->r[8] + 120u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[8] + 124u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    agr_aot_mov_reg(s, 0, 9);
    { uint32_t addr = s->r[8] + 125u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    agr_aot_mov_reg(s, 1, 5);
    { uint32_t addr = s->r[8] + 128u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[8] + 132u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[8] + 136u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[8] + 140u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { int rc = agr_aot_ldr(s, 2, s->r[4] + s->r[2]); if (rc) return rc; }
    { uint32_t addr = s->r[8] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_add_imm(s, 3, s->r[2], 12u);
    agr_aot_adds(s, 2, s->r[2], 32u);
    { uint32_t addr = s->r[8] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[8] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 605660u | 1u, 603362u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000934e2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 603364u + 856u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 5, s->r[4] + s->r[3]); if (rc) return rc; }
    agr_aot_add_imm(s, 9, s->r[5], 4u);
    agr_aot_mov_reg(s, 0, 9);
    agr_aot_branch_reg(s, 612328u | 1u, 603376u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000934f0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 3, s->r[10], 32u);
    agr_aot_add_imm(s, 2, s->r[10], 12u);
    agr_aot_mov_reg(s, 0, 9);
    if (agr_aot_stm(s, 5u, 12u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 1, 6);
    agr_aot_movs_imm(s, 3, 0u);
    { uint32_t addr = s->r[5] + 116u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[5] + 120u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    { uint32_t addr = s->r[5] + 121u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    { uint32_t addr = s->r[5] + 124u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[5] + 128u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[5] + 132u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[5] + 136u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 605660u | 1u, 603422u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009351e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 603424u + 800u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 9, s->r[4] + (s->r[3] << 0u)); if (rc) return rc; }
    agr_aot_add_imm(s, 3, s->r[9], 4u);
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_mov_reg(s, 0, 3);
    agr_aot_branch_reg(s, 612328u | 1u, 603440u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093530(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 4u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[10], 12u);
    agr_aot_mov_reg(s, 1, 6);
    agr_aot_mov_reg(s, 0, 3);
    agr_aot_add_imm(s, 3, s->r[10], 32u);
    if (agr_aot_stm(s, 9u, 12u)) return AGR_AOT_FAULT;
    agr_aot_movs_imm(s, 3, 0u);
    { uint32_t addr = s->r[9] + 116u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[9] + 120u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    { uint32_t addr = s->r[9] + 121u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    { uint32_t addr = s->r[9] + 124u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[9] + 128u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[9] + 132u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[9] + 136u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 605660u | 1u, 603492u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093564(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 603496u + 732u); if (rc) return rc; }
    s->r[10] = 0u;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 16u); if (rc) return rc; }
    s->r[9] = 4294967295u;
    { int rc = agr_aot_ldr(s, 2, 603508u + 724u); if (rc) return rc; }
    { uint32_t addr = s->r[5] + 116u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    s->r[3] = s->r[3] | 8192u;
    { uint32_t addr = s->r[8] + 120u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[5] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { int rc = agr_aot_ldr(s, 8, s->r[4] + (s->r[1] << 0u)); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[4] + s->r[2]); if (rc) return rc; }
    agr_aot_add_imm(s, 0, s->r[8], 28u);
    agr_aot_adds(s, 3, s->r[3], 8u);
    { uint32_t addr = s->r[8] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[10]); }
    if (agr_aot_stm(s, 8u, 1032u)) return AGR_AOT_FAULT;
    { uint32_t addr = s->r[8] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[10]); }
    { uint32_t addr = s->r[8] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[10]); }
    { uint32_t addr = s->r[8] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[10]); }
    { uint32_t addr = s->r[8] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[10]); }
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 691896u | 1u, 603560u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000935a8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[13] + 12u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 0, 603564u + 672u); if (rc) return rc; }
    agr_aot_add_imm(s, 1, s->r[2], 84u);
    { int rc = agr_aot_ldr(s, 2, 603572u + 668u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 4u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 7, s->r[4] + s->r[0]); if (rc) return rc; }
    { uint32_t addr = s->r[8] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    agr_aot_adds(s, 7, s->r[7], 8u);
    { uint32_t addr = s->r[8] + 36u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[9]); }
    { uint32_t addr = s->r[8] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { int rc = agr_aot_ldr(s, 5, s->r[4] + s->r[2]); if (rc) return rc; }
    agr_aot_add_imm(s, 0, s->r[5], 28u);
    if (agr_aot_stm(s, 5u, 1032u)) return AGR_AOT_FAULT;
    { uint32_t addr = s->r[5] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[10]); }
    { uint32_t addr = s->r[5] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[10]); }
    { uint32_t addr = s->r[5] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[10]); }
    { uint32_t addr = s->r[5] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[10]); }
    { uint32_t addr = s->r[5] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[10]); }
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 691896u | 1u, 603624u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000935e8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, 603628u + 616u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 12u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 4u); if (rc) return rc; }
    { uint32_t addr = s->r[5] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[5] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    { uint32_t addr = s->r[5] + 36u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[9]); }
    { int rc = agr_aot_ldr(s, 6, s->r[4] + s->r[2]); if (rc) return rc; }
    agr_aot_add_imm(s, 0, s->r[6], 28u);
    if (agr_aot_stm(s, 6u, 1032u)) return AGR_AOT_FAULT;
    { uint32_t addr = s->r[6] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[10]); }
    { uint32_t addr = s->r[6] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[10]); }
    { uint32_t addr = s->r[6] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[10]); }
    { uint32_t addr = s->r[6] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[10]); }
    { uint32_t addr = s->r[6] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[10]); }
    agr_aot_branch_reg(s, 691896u | 1u, 603672u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093618(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 603676u + 572u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 12u); if (rc) return rc; }
    { uint32_t addr = s->r[6] + 36u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[9]); }
    agr_aot_add_imm(s, 2, s->r[1], 168u);
    { uint32_t addr = s->r[6] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { int rc = agr_aot_ldr(s, 7, s->r[4] + s->r[3]); if (rc) return rc; }
    agr_aot_add_imm(s, 9, s->r[7], 4u);
    agr_aot_mov_reg(s, 0, 9);
    agr_aot_branch_reg(s, 612328u | 1u, 603700u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093634(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 603704u + 548u); if (rc) return rc; }
    { uint32_t addr = s->r[7] + 116u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[10]); }
    agr_aot_mov_reg(s, 0, 9);
    { uint32_t addr = s->r[7] + 120u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[10]); }
    agr_aot_mov_reg(s, 1, 8);
    { uint32_t addr = s->r[7] + 124u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[10]); }
    { uint32_t addr = s->r[7] + 128u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[10]); }
    { uint32_t addr = s->r[7] + 132u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[10]); }
    { uint32_t addr = s->r[7] + 136u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[10]); }
    { uint32_t addr = s->r[7] + 140u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[10]); }
    { int rc = agr_aot_ldr(s, 9, s->r[4] + (s->r[3] << 0u)); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[9], 12u);
    agr_aot_add_imm(s, 3, s->r[9], 32u);
    if (agr_aot_stm(s, 7u, 12u)) return AGR_AOT_FAULT;
    agr_aot_branch_reg(s, 606732u | 1u, 603754u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009366a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 603756u + 500u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 8, s->r[4] + (s->r[3] << 0u)); if (rc) return rc; }
    agr_aot_add_imm(s, 10, s->r[8], 8u);
    agr_aot_mov_reg(s, 0, 10);
    agr_aot_branch_reg(s, 612328u | 1u, 603770u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009367a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, 603772u + 488u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    { uint32_t addr = s->r[8] + 120u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[8] + 124u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_mov_reg(s, 0, 10);
    { uint32_t addr = s->r[8] + 128u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    agr_aot_mov_reg(s, 1, 5);
    { uint32_t addr = s->r[8] + 132u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[8] + 136u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[8] + 140u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[8] + 144u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { int rc = agr_aot_ldr(s, 2, s->r[4] + s->r[2]); if (rc) return rc; }
    { uint32_t addr = s->r[8] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_add_imm(s, 3, s->r[2], 12u);
    agr_aot_adds(s, 2, s->r[2], 32u);
    { uint32_t addr = s->r[8] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[8] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 606732u | 1u, 603830u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000936b6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 603832u + 432u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 5, s->r[4] + s->r[3]); if (rc) return rc; }
    agr_aot_add_imm(s, 10, s->r[5], 4u);
    agr_aot_mov_reg(s, 0, 10);
    agr_aot_branch_reg(s, 612328u | 1u, 603844u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000936c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 3, s->r[9], 32u);
    agr_aot_add_imm(s, 2, s->r[9], 12u);
    agr_aot_mov_reg(s, 0, 10);
    if (agr_aot_stm(s, 5u, 12u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 1, 6);
    agr_aot_movs_imm(s, 3, 0u);
    { uint32_t addr = s->r[5] + 116u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[5] + 120u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[5] + 124u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    { uint32_t addr = s->r[5] + 128u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[5] + 132u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[5] + 136u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[5] + 140u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 606732u | 1u, 603890u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000936f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 603892u + 376u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 10, s->r[4] + (s->r[3] << 0u)); if (rc) return rc; }
    agr_aot_add_imm(s, 3, s->r[10], 4u);
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_mov_reg(s, 0, 3);
    agr_aot_branch_reg(s, 612328u | 1u, 603908u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093704(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 4u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[9], 12u);
    agr_aot_mov_reg(s, 1, 6);
    agr_aot_mov_reg(s, 0, 3);
    agr_aot_add_imm(s, 3, s->r[9], 32u);
    if (agr_aot_stm(s, 10u, 12u)) return AGR_AOT_FAULT;
    agr_aot_movs_imm(s, 3, 0u);
    { uint32_t addr = s->r[10] + 116u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[10] + 120u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[10] + 124u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    { uint32_t addr = s->r[10] + 128u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[10] + 132u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[10] + 136u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[10] + 140u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 606732u | 1u, 603960u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093738(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 16u); if (rc) return rc; }
    { uint32_t addr = s->r[8] + 120u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    s->r[3] = s->r[3] | 8192u;
    { uint32_t addr = s->r[5] + 116u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[5] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 8u); if (rc) return rc; }
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = 603980u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093750(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 2, s->r[2], 1u);
    s->r[15] = 603986u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093756(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 603980u : 603994u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009375a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 11);
    atomic_thread_fence(memory_order_seq_cst);
    s->r[13] += 20u;
    if ((rc = agr_aot_ldmia_sp(s, 36848u))) return rc;
}

static int aot_fast_00093d20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16440u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 5, 0);
    agr_aot_mov_reg(s, 0, 1);
    agr_aot_mov_reg(s, 4, 1);
    agr_aot_branch_reg(s, 625512u | 1u, 605484u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093d2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[0] ? 605532u : 605486u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093d2e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 620456u | 1u, 605492u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093d34(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[5] + 124u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 605494u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093d36(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 625800u | 1u, 605500u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093d3c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[0] ? 605542u : 605502u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093d3e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 622652u | 1u, 605508u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093d44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[5] + 128u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 605512u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093d48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 625868u | 1u, 605518u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093d4e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[0] ? 605536u : 605520u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093d50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 622720u | 1u, 605526u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093d56(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[5] + 132u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    if ((rc = agr_aot_ldmia_sp(s, 32824u))) return rc;
}

static int aot_fast_00093d5c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[5] + 124u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 605494u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093d60(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[5] + 132u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    if ((rc = agr_aot_ldmia_sp(s, 32824u))) return rc;
}

static int aot_fast_00093d66(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[5] + 128u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 605512u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093ddc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16440u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_mov_reg(s, 5, 1);
    agr_aot_branch_reg(s, 686060u | 1u, 605670u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093de6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_add_imm(s, 1, s->r[4], 108u);
    agr_aot_branch_reg(s, 605472u | 1u, 605680u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00093df0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 120u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    agr_aot_subs(s, 5, 1u, s->r[5]);
    s->r[3] = 0u;
    { uint32_t addr = s->r[4] + 116u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    agr_aot_set_itstate(s, 56u); s->r[15] = 605696u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009414c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16440u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 5, 0);
    agr_aot_mov_reg(s, 0, 1);
    agr_aot_mov_reg(s, 4, 1);
    agr_aot_branch_reg(s, 715968u | 1u, 606552u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00094158(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[0] ? 606602u : 606554u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009415a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 711076u | 1u, 606560u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00094160(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[5] + 128u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 606564u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00094164(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 716256u | 1u, 606570u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009416a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[0] ? 606614u : 606572u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009416c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 713108u | 1u, 606578u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00094172(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[5] + 132u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 606582u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00094176(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 716324u | 1u, 606588u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009417c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[0] ? 606608u : 606590u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009417e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 713176u | 1u, 606596u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00094184(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[5] + 136u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    if ((rc = agr_aot_ldmia_sp(s, 32824u))) return rc;
}

static int aot_fast_0009418a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[5] + 128u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 606564u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00094190(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[5] + 136u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    if ((rc = agr_aot_ldmia_sp(s, 32824u))) return rc;
}

static int aot_fast_00094196(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[5] + 132u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 606582u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009420c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16440u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_mov_reg(s, 5, 1);
    agr_aot_branch_reg(s, 686060u | 1u, 606742u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00094216(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_add_imm(s, 1, s->r[4], 108u);
    agr_aot_branch_reg(s, 606540u | 1u, 606752u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00094220(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 124u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    agr_aot_subs(s, 5, 1u, s->r[5]);
    s->r[3] = 0u;
    { uint32_t addr = s->r[4] + 116u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_set_itstate(s, 56u); s->r[15] = 606766u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00094b28(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 609068u + 28u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    s->r[3] += 609072u;
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_adds(s, 3, s->r[3], 8u);
    { uint32_t addr = s->r[0]; s->r[0] = s->r[0] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 791360u | 1u, 609082u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00094b3a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_00094b7c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_branch_reg(s, 609064u | 1u, 609156u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00094b84(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 609160u + 8u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    s->r[3] += 609164u;
    agr_aot_adds(s, 3, s->r[3], 8u);
    { uint32_t addr = s->r[4] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_00094b94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_branch_reg(s, 609064u | 1u, 609180u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00094b9c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 609184u + 8u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    s->r[3] += 609188u;
    agr_aot_adds(s, 3, s->r[3], 8u);
    { uint32_t addr = s->r[4] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_000957e8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    agr_aot_movs_imm(s, 1, 0u);
    { int rc = agr_aot_ldr(s, 6, 612336u + 64u); if (rc) return rc; }
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_add_imm(s, 5, s->r[0], 36u);
    agr_aot_add_imm(s, 3, s->r[0], 44u);
    agr_aot_adds(s, 0, s->r[0], 108u);
    s->r[6] += 612350u;
    agr_aot_mov_reg(s, 2, 1);
    agr_aot_adds(s, 6, s->r[6], 8u);
    { uint32_t addr = s->r[4] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { uint32_t addr = s->r[4] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[4] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { uint32_t addr = s->r[4] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { uint32_t addr = s->r[4] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { uint32_t addr = s->r[4] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { uint32_t addr = s->r[4] + 28u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { uint32_t addr = s->r[4] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    s->r[15] = 612370u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00095812(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = (s->r[3] - 8u); if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_adds(s, 3, s->r[3], 8u);
    { uint32_t addr = (s->r[3] - 12u); if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_cmp(s, s->r[3], s->r[0]);
    s->r[15] = agr_aot_condition(s, 1u) ? 612370u : 612384u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00095820(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 104u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    agr_aot_mov_reg(s, 0, 3);
    agr_aot_movs_imm(s, 3, 8u);
    { uint32_t addr = s->r[4] + 100u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 691896u | 1u, 612396u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009582c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_000970b4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 618680u + 48u); if (rc) return rc; }
    agr_aot_adds(s, 2, s->r[2], 0u);
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    s->r[3] += 618686u;
    { uint32_t addr = s->r[0] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    agr_aot_set_itstate(s, 24u); s->r[15] = 618688u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00097538(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 619836u + 36u); if (rc) return rc; }
    agr_aot_adds(s, 1, s->r[1], 0u);
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    s->r[3] += 619842u;
    agr_aot_set_itstate(s, 24u); s->r[15] = 619842u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000977a8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 620460u + 60u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_mov_reg(s, 0, 3);
    s->r[0] += 620468u;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 701280u | 1u, 620472u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000977b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, s->r[3] + 8u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[0], s->r[1]);
    s->r[15] = agr_aot_condition(s, 2u) ? 620510u : 620482u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000977c2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[3] + (s->r[0] << 2u)); if (rc) return rc; }
    s->r[15] = !s->r[0] ? 620510u : 620488u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000977c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 620492u + 32u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    { int rc = agr_aot_ldr(s, 2, 620496u + 32u); if (rc) return rc; }
    s->r[1] += 620498u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[2] += 620502u;
    { int rc = agr_aot_ldr(s, 2, s->r[2] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 601352u | 1u, 620506u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000977da(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[0] ? 620514u : 620508u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000977dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_000977de(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 783776u | 1u, 620514u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000977e2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 794072u | 1u, 620518u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000977e8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 0, s->r[5], 14u);
    agr_aot_lsls(s, 5, s->r[0], 0u);
    agr_aot_lsls(s, 6, s->r[1], 14u);
    agr_aot_lsls(s, 5, s->r[0], 0u);
    agr_aot_lsls(s, 6, s->r[1], 14u);
    agr_aot_lsls(s, 5, s->r[0], 0u);
    if (agr_aot_stmdb_sp(s, 20464u)) return AGR_AOT_FAULT;
    s->r[13] -= 68u;
    agr_aot_add_imm(s, 4, s->r[13], 48u);
    agr_aot_mov_reg(s, 11, 1);
    { int rc = agr_aot_ldr(s, 5, s->r[13] + 104u); if (rc) return rc; }
    agr_aot_mov_reg(s, 8, 2);
    { uint32_t addr = s->r[13] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[13] + 44u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_add_imm(s, 0, s->r[5], 108u);
    { int rc = agr_aot_ldr(s, 7, s->r[13] + 32u); if (rc) return rc; }
    s->r[15] = 620556u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00097810(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 4, s->r[13] + 116u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 9, s->r[13] + 120u); if (rc) return rc; }
    if (agr_aot_stm(s, 7u, 12u)) return AGR_AOT_FAULT;
    { uint32_t addr = s->r[13] + 40u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    s->r[15] = 620572u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00097820(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 620456u | 1u, 620580u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00097824(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[4], s->r[9]);
    agr_aot_mov_reg(s, 6, 0);
    s->r[15] = agr_aot_condition(s, 0u) ? 620760u : 620586u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009782a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 7, s->r[13], 56u);
    { uint32_t addr = s->r[13] + 36u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    s->r[15] = 620706u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00097830(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 5, s->r[4], 1u);
    agr_aot_cmp(s, s->r[9], s->r[5]);
    s->r[15] = agr_aot_condition(s, 0u) ? 620760u : 620598u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00097836(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 1, s->r[4] + 1u); if (rc) return rc; }
    agr_aot_add_imm(s, 12, s->r[6], s->r[1]);
    s->r[15] = 620604u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00097840(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[7], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 620808u : 620612u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00097844(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[7], 79u);
    agr_aot_set_itstate(s, 24u); s->r[15] = 620616u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009785e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[11] + 0u); if (rc) return rc; }
    agr_aot_add_imm(s, 0, s->r[13], 56u);
    { uint32_t addr = s->r[13] + 48u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    agr_aot_mov_reg(s, 1, 11);
    { uint32_t addr = s->r[13] + 52u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[10]); }
    { int rc = agr_aot_ldr(s, 4, s->r[3] + 8u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 104u); if (rc) return rc; }
    { uint32_t addr = s->r[13] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { int rc = agr_aot_ldr(s, 7, s->r[13] + 32u); if (rc) return rc; }
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 40u); if (rc) return rc; }
    { uint32_t addr = s->r[13] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 112u); if (rc) return rc; }
    { uint32_t addr = s->r[13] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 620674u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00097886(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[4], 620680u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00097888(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 4, s->r[13] + 36u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 8, s->r[13] + 56u); if (rc) return rc; }
    s->r[15] = 620686u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00097896(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[13] + 48u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    { uint32_t addr = s->r[13] + 52u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[1]); }
    agr_aot_adds(s, 4, s->r[5], 1u);
    agr_aot_cmp(s, s->r[9], s->r[4]);
    s->r[15] = agr_aot_condition(s, 0u) ? 620760u : 620706u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000978a2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 1, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_adds(s, 5, s->r[6], s->r[1]);
    s->r[15] = 620710u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000978aa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[2] ? 620788u : 620716u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000978ac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 37u);
    s->r[15] = agr_aot_condition(s, 0u) ? 620592u : 620720u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000978b0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 1, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[10], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 620752u : 620728u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000978b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[8] + 20u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, s->r[8] + 24u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], s->r[2]);
    s->r[15] = agr_aot_condition(s, 2u) ? 620872u : 620740u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000978c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[1]); }
    { int rc = agr_aot_ldr(s, 3, s->r[8] + 20u); if (rc) return rc; }
    agr_aot_adds(s, 3, s->r[3], 1u);
    { uint32_t addr = s->r[8] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 620752u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000978d0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 5, 4);
    agr_aot_adds(s, 4, s->r[5], 1u);
    agr_aot_cmp(s, s->r[9], s->r[4]);
    s->r[15] = agr_aot_condition(s, 1u) ? 620706u : 620760u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000978d8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 5, s->r[13] + 32u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 7, s->r[13] + 44u); if (rc) return rc; }
    { uint32_t addr = s->r[13] + 48u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    { uint32_t addr = s->r[13] + 52u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[10]); }
    s->r[15] = 620772u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000978e8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stm(s, 7u, 3u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 0, 7);
    s->r[13] += 68u;
    if ((rc = agr_aot_ldmia_sp(s, 36848u))) return rc;
}

static int aot_fast_000978f4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[6] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 6);
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 32u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[3], 620796u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000978fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 620720u : 620800u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00097900(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 2, 0);
    { uint32_t addr = s->r[5] + 285u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[0]); }
    s->r[15] = 620716u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00097908(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[6] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 7);
    agr_aot_mov_reg(s, 0, 6);
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 32u); if (rc) return rc; }
    { uint32_t addr = s->r[13] + 28u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[12]); }
    agr_aot_branch_reg(s, s->r[3], 620822u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00097916(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 12, s->r[13] + 28u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 0);
    agr_aot_mov_reg(s, 7, 0);
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 620638u : 620834u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00097922(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[7], 79u);
    agr_aot_set_itstate(s, 24u); s->r[15] = 620838u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00097948(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[8] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 8);
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 52u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[3], 620882u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00097952(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 0, s->r[0], 1u);
    agr_aot_set_itstate(s, 4u); s->r[15] = 620886u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009803c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    { int rc = agr_aot_ldr(s, 0, 622660u + 48u); if (rc) return rc; }
    s->r[0] += 622662u;
    agr_aot_branch_reg(s, 701280u | 1u, 622664u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00098048(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, s->r[3] + 8u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[0], s->r[1]);
    s->r[15] = agr_aot_condition(s, 2u) ? 622700u : 622674u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00098052(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[3] + (s->r[0] << 2u)); if (rc) return rc; }
    s->r[15] = !s->r[0] ? 622700u : 622680u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00098058(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 622684u + 28u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    { int rc = agr_aot_ldr(s, 2, 622688u + 28u); if (rc) return rc; }
    s->r[1] += 622690u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[2] += 622694u;
    agr_aot_branch_reg(s, 601352u | 1u, 622696u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00098068(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[0] ? 622704u : 622698u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009806a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_0009806c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 783776u | 1u, 622704u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00098070(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 794072u | 1u, 622708u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00098074(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 6, s->r[6] + s->r[2]); if (rc) return rc; }
    agr_aot_lsls(s, 5, s->r[0], 0u);
    s->r[15] = 622712u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00098080(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    { int rc = agr_aot_ldr(s, 0, 622728u + 48u); if (rc) return rc; }
    s->r[0] += 622730u;
    agr_aot_branch_reg(s, 701280u | 1u, 622732u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009808c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, s->r[3] + 8u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[0], s->r[1]);
    s->r[15] = agr_aot_condition(s, 2u) ? 622768u : 622742u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00098096(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[3] + (s->r[0] << 2u)); if (rc) return rc; }
    s->r[15] = !s->r[0] ? 622768u : 622748u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009809c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 622752u + 28u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    { int rc = agr_aot_ldr(s, 2, 622756u + 28u); if (rc) return rc; }
    s->r[1] += 622758u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[2] += 622762u;
    agr_aot_branch_reg(s, 601352u | 1u, 622764u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000980ac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[0] ? 622772u : 622766u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000980ae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_000980b0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 783776u | 1u, 622772u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000980b4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 794072u | 1u, 622776u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000980b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 6, s->r[6] + s->r[1]); if (rc) return rc; }
    agr_aot_lsls(s, 5, s->r[0], 0u);
    s->r[15] = 622780u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00098b68(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 625516u + 60u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_mov_reg(s, 0, 3);
    s->r[0] += 625524u;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 701280u | 1u, 625528u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00098b78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, s->r[3] + 8u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[0], s->r[1]);
    s->r[15] = agr_aot_condition(s, 2u) ? 625570u : 625538u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00098b82(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[3] + (s->r[0] << 2u)); if (rc) return rc; }
    s->r[15] = !s->r[0] ? 625572u : 625544u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00098b88(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 625548u + 32u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    { int rc = agr_aot_ldr(s, 2, 625552u + 32u); if (rc) return rc; }
    s->r[1] += 625554u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[2] += 625558u;
    { int rc = agr_aot_ldr(s, 2, s->r[2] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 601352u | 1u, 625562u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00098b9a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 0, s->r[0], 0u);
    agr_aot_set_itstate(s, 24u); s->r[15] = 625566u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00098ba2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = 625572u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00098ba4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_00098c88(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    { int rc = agr_aot_ldr(s, 0, 625808u + 48u); if (rc) return rc; }
    s->r[0] += 625810u;
    agr_aot_branch_reg(s, 701280u | 1u, 625812u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00098c94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, s->r[3] + 8u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[0], s->r[1]);
    s->r[15] = agr_aot_condition(s, 2u) ? 625852u : 625822u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00098c9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[3] + (s->r[0] << 2u)); if (rc) return rc; }
    s->r[15] = !s->r[0] ? 625854u : 625828u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00098ca4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 625832u + 28u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    { int rc = agr_aot_ldr(s, 2, 625836u + 28u); if (rc) return rc; }
    s->r[1] += 625838u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[2] += 625842u;
    agr_aot_branch_reg(s, 601352u | 1u, 625844u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00098cb4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 0, s->r[0], 0u);
    agr_aot_set_itstate(s, 24u); s->r[15] = 625848u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00098cbc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = 625854u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00098cbe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_00098ccc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    { int rc = agr_aot_ldr(s, 0, 625876u + 48u); if (rc) return rc; }
    s->r[0] += 625878u;
    agr_aot_branch_reg(s, 701280u | 1u, 625880u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00098cd8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, s->r[3] + 8u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[0], s->r[1]);
    s->r[15] = agr_aot_condition(s, 2u) ? 625920u : 625890u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00098ce2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[3] + (s->r[0] << 2u)); if (rc) return rc; }
    s->r[15] = !s->r[0] ? 625922u : 625896u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00098ce8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 625900u + 28u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    { int rc = agr_aot_ldr(s, 2, 625904u + 28u); if (rc) return rc; }
    s->r[1] += 625906u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[2] += 625910u;
    agr_aot_branch_reg(s, 601352u | 1u, 625912u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_00098cf8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 0, s->r[0], 0u);
    agr_aot_set_itstate(s, 24u); s->r[15] = 625916u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_00098d00(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = 625922u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_00098d02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_0009ff90(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16440u)) return AGR_AOT_FAULT;
    agr_aot_adds(s, 1, s->r[1], 0u);
    { int rc = agr_aot_ldr(s, 3, 655256u + 44u); if (rc) return rc; }
    agr_aot_mov_reg(s, 4, 0);
    { int rc = agr_aot_ldr(s, 5, 655260u + 44u); if (rc) return rc; }
    agr_aot_set_itstate(s, 24u); s->r[15] = 655260u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_0009fff8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16440u)) return AGR_AOT_FAULT;
    agr_aot_adds(s, 1, s->r[1], 0u);
    { int rc = agr_aot_ldr(s, 3, 655360u + 44u); if (rc) return rc; }
    agr_aot_mov_reg(s, 4, 0);
    { int rc = agr_aot_ldr(s, 5, 655364u + 44u); if (rc) return rc; }
    agr_aot_set_itstate(s, 24u); s->r[15] = 655364u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a77ec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16432u)) return AGR_AOT_FAULT;
    s->r[13] -= 12u;
    agr_aot_add_imm(s, 5, s->r[13], 4u);
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_movs_imm(s, 3, 6u);
    { uint32_t addr = s->r[0] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[0] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_movw(s, 3, 4098u);
    agr_aot_mov_reg(s, 0, 5);
    { uint32_t addr = s->r[4] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 691896u | 1u, 686088u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a7808(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 1, 5);
    agr_aot_add_imm(s, 0, s->r[4], 108u);
    agr_aot_branch_reg(s, 700628u | 1u, 686098u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a7812(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_branch_reg(s, 700720u | 1u, 686104u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a7818(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 12u;
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) return rc;
}

static int aot_fast_000a8358(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16440u)) return AGR_AOT_FAULT;
    { int rc = agr_aot_ldr(s, 4, 688988u + 40u); if (rc) return rc; }
    s->r[4] += 688992u;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 688992u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8364(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 689004u : 688998u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8366(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 689000u + 32u); if (rc) return rc; }
    s->r[0] += 689004u;
    if ((rc = agr_aot_ldmia_sp(s, 32824u))) return rc;
}

static int aot_fast_000a836c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 793728u | 1u, 689010u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8372(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 688998u : 689014u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8376(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 689016u + 20u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    s->r[3] += 689022u;
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    agr_aot_branch_reg(s, 793948u | 1u, 689026u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8382(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 688998u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8390(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 20464u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    { int rc = agr_aot_ldr(s, 6, 689048u + 2216u); if (rc) return rc; }
    agr_aot_movs_imm(s, 5, 0u);
    { int rc = agr_aot_ldr(s, 7, 689056u + 2212u); if (rc) return rc; }
    agr_aot_mov_reg(s, 3, 5);
    s->r[6] += 689062u;
    agr_aot_mov_reg(s, 2, 5);
    s->r[7] += 689066u;
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { int rc = agr_aot_ldr(s, 5, 689068u + 2204u); if (rc) return rc; }
    s->r[14] = 28u;
    { uint32_t addr = s->r[4] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    s->r[13] -= 20u;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_mov_reg(s, 1, 7);
    { uint32_t addr = s->r[4] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[14]); }
    s->r[5] += 689090u;
    { uint32_t addr = s->r[4] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[4] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    s->r[15] = 689098u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a83c6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[4] + 4u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 12u); if (rc) return rc; }
    s->r[15] = 689098u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a83ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[1] + s->r[3]; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[0] + s->r[3]; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_adds(s, 3, s->r[3], 4u);
    agr_aot_cmp(s, s->r[3], 112u);
    s->r[15] = agr_aot_condition(s, 1u) ? 689094u : 689108u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a83d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 6, 689112u + 2164u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 7, 689116u + 2164u); if (rc) return rc; }
    s->r[6] += 689120u;
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    s->r[7] += 689124u;
    { uint32_t addr = s->r[6] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    agr_aot_branch_reg(s, 700396u | 1u, 689128u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a83e8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 3, 4u);
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_movs_imm(s, 1, 0u);
    { int rc = agr_aot_ldrh(s, 0, s->r[0] + 0u); if (rc) return rc; }
    { uint32_t addr = s->r[7] + 0u; if (agr_aot_fault16(addr)) return AGR_AOT_FAULT; agr_aot_store16(s, addr, s->r[0]); }
    { uint32_t addr = s->r[2] + s->r[3]; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    agr_aot_adds(s, 3, s->r[3], 4u);
    agr_aot_cmp(s, s->r[3], 24u);
    s->r[15] = agr_aot_condition(s, 0u) ? 689156u : 689146u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a83fa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[4] + 16u); if (rc) return rc; }
    { uint32_t addr = s->r[2] + s->r[3]; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    agr_aot_adds(s, 3, s->r[3], 4u);
    agr_aot_cmp(s, s->r[3], 24u);
    s->r[15] = agr_aot_condition(s, 1u) ? 689146u : 689156u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8404(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 689160u + 2124u); if (rc) return rc; }
    agr_aot_movs_imm(s, 1, 0u);
    agr_aot_mov_reg(s, 2, 1);
    agr_aot_movs_imm(s, 3, 1u);
    s->r[0] += 689170u;
    agr_aot_branch_reg(s, 703588u | 1u, 689172u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8414(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 689176u + 2112u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    { int rc = agr_aot_ldr(s, 2, 689180u + 2112u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[3]); if (rc) return rc; }
    s->r[2] += 689188u;
    agr_aot_branch_reg(s, 701340u | 1u, 689190u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8426(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 689192u + 2104u); if (rc) return rc; }
    agr_aot_movs_imm(s, 1, 1u);
    s->r[0] += 689200u;
    agr_aot_branch_reg(s, 655248u | 1u, 689202u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8432(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 689204u + 2096u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    { int rc = agr_aot_ldr(s, 2, 689212u + 2092u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[3]); if (rc) return rc; }
    s->r[2] += 689218u;
    agr_aot_branch_reg(s, 701340u | 1u, 689220u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8444(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 689224u + 2084u); if (rc) return rc; }
    agr_aot_movs_imm(s, 7, 1u);
    { int rc = agr_aot_ldr(s, 0, 689228u + 2084u); if (rc) return rc; }
    agr_aot_movs_imm(s, 2, 0u);
    s->r[3] += 689236u;
    { int rc = agr_aot_ldr(s, 6, 689236u + 2080u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 12, 689240u + 2080u); if (rc) return rc; }
    agr_aot_mov_reg(s, 1, 2);
    { uint32_t addr = s->r[3] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    s->r[6] += 689250u;
    { int rc = agr_aot_ldr(s, 0, s->r[5] + s->r[0]); if (rc) return rc; }
    { uint32_t addr = s->r[6] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[3] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_mov_reg(s, 0, 6);
    { int rc = agr_aot_ldr(s, 7, s->r[13] + 4u); if (rc) return rc; }
    { uint32_t addr = s->r[3] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_add_imm(s, 14, s->r[7], 8u);
    { uint32_t addr = s->r[3] + 16u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[14]); }
    { uint32_t addr = s->r[3] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[3] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[3] + 28u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[3] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[3] + 36u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    { uint32_t addr = s->r[3] + 37u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    { uint32_t addr = s->r[3] + 100u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    { int rc = agr_aot_ldr(s, 2, s->r[5] + (s->r[12] << 0u)); if (rc) return rc; }
    { uint32_t addr = s->r[6] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_adds(s, 2, s->r[2], 8u);
    { uint32_t addr = s->r[6] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_branch_reg(s, 794996u | 1u, 689306u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a849a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 689308u + 2016u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    { int rc = agr_aot_ldr(s, 2, 689316u + 2012u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 10, s->r[5] + (s->r[3] << 0u)); if (rc) return rc; }
    s->r[2] += 689324u;
    agr_aot_mov_reg(s, 1, 10);
    agr_aot_branch_reg(s, 701340u | 1u, 689328u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a84b0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 689332u + 2000u); if (rc) return rc; }
    agr_aot_movs_imm(s, 2, 1u);
    { int rc = agr_aot_ldr(s, 1, 689336u + 2000u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    s->r[3] += 689344u;
    { int rc = agr_aot_ldr(s, 6, 689344u + 1996u); if (rc) return rc; }
    { uint32_t addr = s->r[3] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_mov_reg(s, 2, 3);
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[1]); if (rc) return rc; }
    agr_aot_adds(s, 1, s->r[1], 8u);
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[6]); if (rc) return rc; }
    agr_aot_branch_reg(s, 701340u | 1u, 689362u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a84d2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 689364u + 1980u); if (rc) return rc; }
    agr_aot_movs_imm(s, 2, 1u);
    { int rc = agr_aot_ldr(s, 1, 689372u + 1976u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    s->r[3] += 689378u;
    { int rc = agr_aot_ldr(s, 6, 689380u + 1972u); if (rc) return rc; }
    { uint32_t addr = s->r[3] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_mov_reg(s, 2, 3);
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[1]); if (rc) return rc; }
    agr_aot_adds(s, 1, s->r[1], 8u);
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[6]); if (rc) return rc; }
    agr_aot_branch_reg(s, 701340u | 1u, 689396u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a84f4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 689400u + 1956u); if (rc) return rc; }
    agr_aot_movs_imm(s, 1, 1u);
    { int rc = agr_aot_ldr(s, 2, 689404u + 1956u); if (rc) return rc; }
    s->r[3] += 689410u;
    { uint32_t addr = s->r[3] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { int rc = agr_aot_ldr(s, 2, s->r[5] + s->r[2]); if (rc) return rc; }
    agr_aot_adds(s, 2, s->r[2], 8u);
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_branch_reg(s, 700360u | 1u, 689420u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a850c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, 689424u + 1940u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, 689428u + 1940u); if (rc) return rc; }
    s->r[2] += 689432u;
    { uint32_t addr = s->r[2] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_mov_reg(s, 0, 4);
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[3]); if (rc) return rc; }
    agr_aot_branch_reg(s, 701340u | 1u, 689440u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8520(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 689444u + 1928u); if (rc) return rc; }
    agr_aot_movs_imm(s, 6, 1u);
    { int rc = agr_aot_ldr(s, 0, 689448u + 1928u); if (rc) return rc; }
    agr_aot_movs_imm(s, 7, 0u);
    s->r[3] += 689456u;
    { int rc = agr_aot_ldr(s, 14, 689456u + 1924u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 8, 689460u + 1924u); if (rc) return rc; }
    agr_aot_mov_reg(s, 1, 7);
    { uint32_t addr = s->r[3] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    s->r[14] += 689470u;
    { int rc = agr_aot_ldr(s, 0, s->r[5] + s->r[0]); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 7);
    { uint32_t addr = s->r[14] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[3] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_mov_reg(s, 0, 14);
    { int rc = agr_aot_ldr(s, 6, s->r[13] + 4u); if (rc) return rc; }
    { uint32_t addr = s->r[3] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    agr_aot_add_imm(s, 12, s->r[6], 8u);
    { uint32_t addr = s->r[3] + 16u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[7]); }
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[12]); }
    { uint32_t addr = s->r[3] + 17u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[7]); }
    { uint32_t addr = s->r[3] + 18u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[7]); }
    { uint32_t addr = s->r[3] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[3] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[3] + 28u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[3] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[3] + 36u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[3] + 40u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[3] + 44u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[3] + 48u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[7]); }
    { uint32_t addr = s->r[3] + 49u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[7]); }
    { uint32_t addr = s->r[3] + 50u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[7]); }
    { uint32_t addr = s->r[3] + 51u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[7]); }
    { uint32_t addr = s->r[3] + 52u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[7]); }
    { uint32_t addr = s->r[3] + 53u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[7]); }
    { uint32_t addr = s->r[3] + 54u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[7]); }
    { uint32_t addr = s->r[3] + 55u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[7]); }
    { uint32_t addr = s->r[3] + 67u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[7]); }
    { int rc = agr_aot_ldr(s, 6, s->r[5] + (s->r[8] << 0u)); if (rc) return rc; }
    { uint32_t addr = s->r[14] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_adds(s, 6, s->r[6], 8u);
    { uint32_t addr = s->r[14] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    agr_aot_branch_reg(s, 795908u | 1u, 689568u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a85a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 689572u + 1816u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    { int rc = agr_aot_ldr(s, 2, 689576u + 1816u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 9, s->r[5] + (s->r[3] << 0u)); if (rc) return rc; }
    s->r[2] += 689586u;
    agr_aot_mov_reg(s, 1, 9);
    agr_aot_branch_reg(s, 701340u | 1u, 689590u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a85b6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 6, 689592u + 1804u); if (rc) return rc; }
    s->r[12] = 1u;
    { int rc = agr_aot_ldr(s, 3, 689600u + 1800u); if (rc) return rc; }
    agr_aot_movs_imm(s, 7, 0u);
    s->r[6] += 689608u;
    { int rc = agr_aot_ldr(s, 14, 689608u + 1796u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 8, 689612u + 1796u); if (rc) return rc; }
    agr_aot_mov_reg(s, 1, 7);
    s->r[14] += 689620u;
    { uint32_t addr = s->r[6] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[12]); }
    { int rc = agr_aot_ldr(s, 3, s->r[5] + s->r[3]); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 7);
    { uint32_t addr = s->r[14] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[12]); }
    agr_aot_mov_reg(s, 0, 14);
    agr_aot_adds(s, 3, s->r[3], 8u);
    { uint32_t addr = s->r[6] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[6] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 16u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 17u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 18u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 28u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 36u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 40u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 44u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 48u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 49u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 50u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 51u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 52u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 53u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 54u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 55u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 67u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[7]); }
    { int rc = agr_aot_ldr(s, 3, s->r[5] + (s->r[8] << 0u)); if (rc) return rc; }
    { uint32_t addr = s->r[14] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    agr_aot_adds(s, 3, s->r[3], 8u);
    { uint32_t addr = s->r[14] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 795720u | 1u, 689714u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8632(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 689716u + 1696u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    { int rc = agr_aot_ldr(s, 2, 689724u + 1692u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 8, s->r[5] + (s->r[3] << 0u)); if (rc) return rc; }
    s->r[2] += 689732u;
    agr_aot_mov_reg(s, 1, 8);
    agr_aot_branch_reg(s, 701340u | 1u, 689736u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8648(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 689740u + 1680u); if (rc) return rc; }
    agr_aot_movs_imm(s, 2, 1u);
    { int rc = agr_aot_ldr(s, 1, 689744u + 1680u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    s->r[3] += 689752u;
    { int rc = agr_aot_ldr(s, 6, 689752u + 1676u); if (rc) return rc; }
    { uint32_t addr = s->r[3] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_mov_reg(s, 2, 3);
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[1]); if (rc) return rc; }
    agr_aot_adds(s, 1, s->r[1], 8u);
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[6]); if (rc) return rc; }
    agr_aot_branch_reg(s, 701340u | 1u, 689770u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a866a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 689772u + 1660u); if (rc) return rc; }
    agr_aot_movs_imm(s, 2, 1u);
    { int rc = agr_aot_ldr(s, 1, 689780u + 1656u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    s->r[3] += 689786u;
    { int rc = agr_aot_ldr(s, 6, 689788u + 1652u); if (rc) return rc; }
    { uint32_t addr = s->r[3] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_mov_reg(s, 2, 3);
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[1]); if (rc) return rc; }
    agr_aot_adds(s, 1, s->r[1], 8u);
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[6]); if (rc) return rc; }
    agr_aot_branch_reg(s, 701340u | 1u, 689804u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a868c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 6, 689808u + 1636u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 1u);
    { int rc = agr_aot_ldr(s, 14, 689812u + 1636u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 3);
    s->r[6] += 689820u;
    { int rc = agr_aot_ldr(s, 0, 689820u + 1632u); if (rc) return rc; }
    agr_aot_movs_imm(s, 7, 0u);
    { uint32_t addr = s->r[6] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[0] += 689830u;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + (s->r[14] << 0u)); if (rc) return rc; }
    agr_aot_mov_reg(s, 1, 6);
    { uint32_t addr = s->r[6] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    agr_aot_adds(s, 3, s->r[3], 8u);
    { uint32_t addr = s->r[6] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[6] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 28u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 36u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 40u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 44u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 48u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 52u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 56u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 60u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 68u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 72u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 76u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 80u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 84u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 88u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 92u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 96u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 100u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 104u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 108u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 112u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 116u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 120u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 124u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 128u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 132u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 136u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 140u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 144u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 148u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 152u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 156u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 160u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 164u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 168u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 172u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 176u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 180u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 184u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 188u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 192u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[6] + 196u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[7]); }
    agr_aot_branch_reg(s, 618676u | 1u, 689974u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8736(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 689976u + 1480u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    { int rc = agr_aot_ldr(s, 2, 689984u + 1476u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[5] + s->r[3]); if (rc) return rc; }
    s->r[2] += 689990u;
    agr_aot_mov_reg(s, 1, 3);
    { uint32_t addr = s->r[13] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 701340u | 1u, 689996u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a874c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 690000u + 1464u); if (rc) return rc; }
    agr_aot_movs_imm(s, 2, 1u);
    { int rc = agr_aot_ldr(s, 1, 690004u + 1464u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    s->r[3] += 690012u;
    { int rc = agr_aot_ldr(s, 7, 690012u + 1460u); if (rc) return rc; }
    { uint32_t addr = s->r[3] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_mov_reg(s, 2, 3);
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[1]); if (rc) return rc; }
    agr_aot_adds(s, 1, s->r[1], 8u);
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[7]); if (rc) return rc; }
    agr_aot_branch_reg(s, 701340u | 1u, 690030u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a876e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 690032u + 1444u); if (rc) return rc; }
    agr_aot_movs_imm(s, 2, 1u);
    { int rc = agr_aot_ldr(s, 1, 690040u + 1440u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    s->r[3] += 690046u;
    { int rc = agr_aot_ldr(s, 7, 690048u + 1436u); if (rc) return rc; }
    { uint32_t addr = s->r[3] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_mov_reg(s, 2, 3);
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[1]); if (rc) return rc; }
    agr_aot_adds(s, 1, s->r[1], 8u);
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[7]); if (rc) return rc; }
    agr_aot_branch_reg(s, 701340u | 1u, 690064u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8790(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 690068u + 1420u); if (rc) return rc; }
    agr_aot_movs_imm(s, 1, 1u);
    s->r[0] += 690074u;
    agr_aot_branch_reg(s, 619832u | 1u, 690076u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a879c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 690080u + 1412u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    { int rc = agr_aot_ldr(s, 2, 690084u + 1412u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[3]); if (rc) return rc; }
    s->r[2] += 690092u;
    agr_aot_branch_reg(s, 701340u | 1u, 690094u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a87ae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 690096u + 1404u); if (rc) return rc; }
    agr_aot_movs_imm(s, 1, 1u);
    s->r[0] += 690104u;
    agr_aot_branch_reg(s, 697636u | 1u, 690106u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a87ba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 690108u + 1396u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    { int rc = agr_aot_ldr(s, 2, 690116u + 1392u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[3]); if (rc) return rc; }
    s->r[2] += 690122u;
    agr_aot_branch_reg(s, 701340u | 1u, 690124u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a87cc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 690128u + 1384u); if (rc) return rc; }
    agr_aot_movs_imm(s, 1, 1u);
    s->r[0] += 690134u;
    agr_aot_branch_reg(s, 655352u | 1u, 690136u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a87d8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 690140u + 1376u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    { int rc = agr_aot_ldr(s, 2, 690144u + 1376u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[3]); if (rc) return rc; }
    s->r[2] += 690152u;
    agr_aot_branch_reg(s, 701340u | 1u, 690154u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a87ea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 690156u + 1368u); if (rc) return rc; }
    agr_aot_movs_imm(s, 6, 1u);
    { int rc = agr_aot_ldr(s, 2, 690164u + 1364u); if (rc) return rc; }
    agr_aot_movs_imm(s, 7, 0u);
    s->r[3] += 690170u;
    { int rc = agr_aot_ldr(s, 14, 690172u + 1360u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 11, 690176u + 1360u); if (rc) return rc; }
    agr_aot_mov_reg(s, 1, 7);
    s->r[14] += 690182u;
    { uint32_t addr = s->r[3] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { int rc = agr_aot_ldr(s, 2, s->r[5] + s->r[2]); if (rc) return rc; }
    { uint32_t addr = s->r[14] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    agr_aot_mov_reg(s, 0, 14);
    agr_aot_adds(s, 2, s->r[2], 8u);
    { uint32_t addr = s->r[3] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[3] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[3] + 16u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[7]); }
    { uint32_t addr = s->r[3] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[3] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[3] + 28u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[3] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[3] + 36u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[3] + 40u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[3] + 292u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[7]); }
    { int rc = agr_aot_ldr(s, 2, s->r[5] + (s->r[11] << 0u)); if (rc) return rc; }
    { uint32_t addr = s->r[14] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_adds(s, 2, s->r[2], 8u);
    { uint32_t addr = s->r[14] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_branch_reg(s, 795184u | 1u, 690234u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a883a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 690236u + 1304u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    { int rc = agr_aot_ldr(s, 2, 690244u + 1300u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[5] + s->r[3]); if (rc) return rc; }
    s->r[2] += 690250u;
    agr_aot_mov_reg(s, 1, 3);
    { uint32_t addr = s->r[13] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 701340u | 1u, 690256u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8850(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 690260u + 1288u); if (rc) return rc; }
    agr_aot_movs_imm(s, 2, 1u);
    { int rc = agr_aot_ldr(s, 1, 690264u + 1288u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    s->r[3] += 690272u;
    { int rc = agr_aot_ldr(s, 7, 690272u + 1284u); if (rc) return rc; }
    { uint32_t addr = s->r[3] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_mov_reg(s, 2, 3);
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[1]); if (rc) return rc; }
    agr_aot_adds(s, 1, s->r[1], 8u);
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[7]); if (rc) return rc; }
    agr_aot_branch_reg(s, 701340u | 1u, 690290u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8872(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 690292u + 1268u); if (rc) return rc; }
    agr_aot_movs_imm(s, 2, 1u);
    { int rc = agr_aot_ldr(s, 1, 690300u + 1264u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    s->r[3] += 690306u;
    { int rc = agr_aot_ldr(s, 7, 690308u + 1260u); if (rc) return rc; }
    { uint32_t addr = s->r[3] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_mov_reg(s, 2, 3);
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[1]); if (rc) return rc; }
    agr_aot_adds(s, 1, s->r[1], 8u);
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[7]); if (rc) return rc; }
    agr_aot_branch_reg(s, 701340u | 1u, 690324u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8894(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 690328u + 1244u); if (rc) return rc; }
    agr_aot_movs_imm(s, 1, 1u);
    { int rc = agr_aot_ldr(s, 2, 690332u + 1244u); if (rc) return rc; }
    s->r[3] += 690338u;
    { uint32_t addr = s->r[3] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { int rc = agr_aot_ldr(s, 2, s->r[5] + s->r[2]); if (rc) return rc; }
    agr_aot_adds(s, 2, s->r[2], 8u);
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_branch_reg(s, 700360u | 1u, 690348u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a88ac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, 690352u + 1228u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, 690356u + 1228u); if (rc) return rc; }
    s->r[2] += 690360u;
    { uint32_t addr = s->r[2] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_mov_reg(s, 0, 4);
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[3]); if (rc) return rc; }
    agr_aot_branch_reg(s, 701340u | 1u, 690368u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a88c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 7, 690372u + 1216u); if (rc) return rc; }
    agr_aot_movs_imm(s, 0, 1u);
    { int rc = agr_aot_ldr(s, 2, 690376u + 1216u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    s->r[7] += 690384u;
    { int rc = agr_aot_ldr(s, 14, 690384u + 1212u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 12, 690388u + 1212u); if (rc) return rc; }
    agr_aot_mov_reg(s, 1, 3);
    s->r[14] += 690396u;
    { uint32_t addr = s->r[7] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    { int rc = agr_aot_ldr(s, 2, s->r[5] + s->r[2]); if (rc) return rc; }
    { uint32_t addr = s->r[14] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_mov_reg(s, 0, 14);
    agr_aot_adds(s, 2, s->r[2], 8u);
    { uint32_t addr = s->r[7] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[7] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_mov_reg(s, 2, 3);
    { uint32_t addr = s->r[7] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[7] + 16u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    { uint32_t addr = s->r[7] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[7] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[7] + 28u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[7] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[7] + 36u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[7] + 40u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[7] + 44u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[7] + 48u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[7] + 52u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[7] + 56u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    { uint32_t addr = s->r[7] + 57u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    { uint32_t addr = s->r[7] + 58u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    { uint32_t addr = s->r[7] + 59u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    { uint32_t addr = s->r[7] + 60u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    { uint32_t addr = s->r[7] + 61u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    { uint32_t addr = s->r[7] + 62u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    { uint32_t addr = s->r[7] + 63u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    { uint32_t addr = s->r[7] + 108u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    { int rc = agr_aot_ldr(s, 3, s->r[5] + (s->r[12] << 0u)); if (rc) return rc; }
    { uint32_t addr = s->r[14] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    agr_aot_adds(s, 3, s->r[3], 8u);
    { uint32_t addr = s->r[14] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 796300u | 1u, 690488u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8938(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 690492u + 1112u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    { int rc = agr_aot_ldr(s, 2, 690496u + 1112u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[5] + s->r[3]); if (rc) return rc; }
    s->r[2] += 690504u;
    agr_aot_mov_reg(s, 1, 3);
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 701340u | 1u, 690510u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a894e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 690512u + 1100u); if (rc) return rc; }
    agr_aot_movs_imm(s, 6, 1u);
    { int rc = agr_aot_ldr(s, 0, 690520u + 1096u); if (rc) return rc; }
    agr_aot_movs_imm(s, 2, 0u);
    s->r[3] += 690526u;
    { int rc = agr_aot_ldr(s, 14, 690528u + 1092u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 7, 690532u + 1092u); if (rc) return rc; }
    agr_aot_mov_reg(s, 1, 2);
    s->r[14] += 690538u;
    { uint32_t addr = s->r[3] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { int rc = agr_aot_ldr(s, 0, s->r[5] + s->r[0]); if (rc) return rc; }
    { uint32_t addr = s->r[14] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    agr_aot_adds(s, 0, s->r[0], 8u);
    { uint32_t addr = s->r[3] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_mov_reg(s, 0, 14);
    { uint32_t addr = s->r[3] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[3] + 16u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    { uint32_t addr = s->r[3] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[3] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[3] + 28u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[3] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[3] + 36u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[3] + 40u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[3] + 44u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[3] + 48u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[3] + 52u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[3] + 56u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    { uint32_t addr = s->r[3] + 57u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    { uint32_t addr = s->r[3] + 58u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    { uint32_t addr = s->r[3] + 59u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    { uint32_t addr = s->r[3] + 60u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    { uint32_t addr = s->r[3] + 61u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    { uint32_t addr = s->r[3] + 62u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    { uint32_t addr = s->r[3] + 63u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    { uint32_t addr = s->r[3] + 108u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    { int rc = agr_aot_ldr(s, 7, s->r[5] + s->r[7]); if (rc) return rc; }
    { uint32_t addr = s->r[14] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_adds(s, 7, s->r[7], 8u);
    { uint32_t addr = s->r[14] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    agr_aot_branch_reg(s, 796096u | 1u, 690626u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a89c2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 690628u + 1000u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    { int rc = agr_aot_ldr(s, 2, 690632u + 1000u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 11, s->r[5] + (s->r[3] << 0u)); if (rc) return rc; }
    s->r[2] += 690640u;
    agr_aot_mov_reg(s, 1, 11);
    agr_aot_branch_reg(s, 701340u | 1u, 690644u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a89d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 690648u + 988u); if (rc) return rc; }
    agr_aot_movs_imm(s, 2, 1u);
    { int rc = agr_aot_ldr(s, 1, 690652u + 988u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    s->r[3] += 690656u;
    { int rc = agr_aot_ldr(s, 7, 690656u + 988u); if (rc) return rc; }
    { uint32_t addr = s->r[3] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_mov_reg(s, 2, 3);
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[1]); if (rc) return rc; }
    agr_aot_adds(s, 1, s->r[1], 8u);
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[7]); if (rc) return rc; }
    agr_aot_branch_reg(s, 701340u | 1u, 690672u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a89f0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 690676u + 972u); if (rc) return rc; }
    agr_aot_movs_imm(s, 2, 1u);
    { int rc = agr_aot_ldr(s, 1, 690680u + 972u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    s->r[3] += 690684u;
    { int rc = agr_aot_ldr(s, 7, 690684u + 972u); if (rc) return rc; }
    { uint32_t addr = s->r[3] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_mov_reg(s, 2, 3);
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[1]); if (rc) return rc; }
    agr_aot_adds(s, 1, s->r[1], 8u);
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[7]); if (rc) return rc; }
    agr_aot_branch_reg(s, 701340u | 1u, 690700u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8a0c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 7, 690704u + 956u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 1u);
    { int rc = agr_aot_ldr(s, 14, 690708u + 956u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 3);
    s->r[7] += 690714u;
    { int rc = agr_aot_ldr(s, 0, 690716u + 952u); if (rc) return rc; }
    agr_aot_movs_imm(s, 6, 0u);
    { uint32_t addr = s->r[7] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[0] += 690722u;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + (s->r[14] << 0u)); if (rc) return rc; }
    agr_aot_mov_reg(s, 1, 7);
    { uint32_t addr = s->r[7] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    agr_aot_adds(s, 3, s->r[3], 8u);
    { uint32_t addr = s->r[7] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[7] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 28u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 36u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 40u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 44u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 48u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 52u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 56u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 60u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 68u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 72u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 76u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 80u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 84u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 88u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 92u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 96u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 100u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 104u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 108u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 112u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 116u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 120u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 124u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 128u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 132u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 136u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 140u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 144u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 148u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 152u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 156u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 160u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 164u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 168u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 172u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 176u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 180u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 184u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 188u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 192u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[7] + 196u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[6]); }
    agr_aot_branch_reg(s, 709296u | 1u, 690866u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8ab2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 690868u + 804u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    { int rc = agr_aot_ldr(s, 2, 690872u + 804u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 7, s->r[5] + s->r[3]); if (rc) return rc; }
    s->r[2] += 690878u;
    agr_aot_mov_reg(s, 1, 7);
    agr_aot_branch_reg(s, 701340u | 1u, 690882u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8ac2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 690884u + 796u); if (rc) return rc; }
    agr_aot_movs_imm(s, 1, 1u);
    { int rc = agr_aot_ldr(s, 2, 690888u + 796u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    s->r[3] += 690894u;
    { int rc = agr_aot_ldr(s, 14, 690896u + 792u); if (rc) return rc; }
    { uint32_t addr = s->r[3] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[2]); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 3);
    agr_aot_adds(s, 1, s->r[1], 8u);
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { int rc = agr_aot_ldr(s, 1, s->r[5] + (s->r[14] << 0u)); if (rc) return rc; }
    agr_aot_branch_reg(s, 701340u | 1u, 690914u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8ae2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 690916u + 776u); if (rc) return rc; }
    agr_aot_movs_imm(s, 1, 1u);
    { int rc = agr_aot_ldr(s, 2, 690920u + 776u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    s->r[3] += 690926u;
    { int rc = agr_aot_ldr(s, 14, 690928u + 772u); if (rc) return rc; }
    { uint32_t addr = s->r[3] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[2]); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 3);
    agr_aot_adds(s, 1, s->r[1], 8u);
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { int rc = agr_aot_ldr(s, 1, s->r[5] + (s->r[14] << 0u)); if (rc) return rc; }
    agr_aot_branch_reg(s, 701340u | 1u, 690946u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8b02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 690948u + 756u); if (rc) return rc; }
    agr_aot_movs_imm(s, 1, 1u);
    s->r[0] += 690954u;
    agr_aot_branch_reg(s, 710452u | 1u, 690956u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8b0c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 690960u + 748u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    { int rc = agr_aot_ldr(s, 2, 690964u + 748u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, s->r[5] + s->r[3]); if (rc) return rc; }
    s->r[2] += 690968u;
    agr_aot_branch_reg(s, 701340u | 1u, 690970u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8b1a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 10);
    { int rc = agr_aot_ldr(s, 5, s->r[4] + 12u); if (rc) return rc; }
    agr_aot_branch_reg(s, 701280u | 1u, 690978u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8b22(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 690980u + 736u); if (rc) return rc; }
    s->r[3] += 690984u;
    { uint32_t addr = s->r[5] + (s->r[0] << 2u); if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_mov_reg(s, 0, 9);
    { int rc = agr_aot_ldr(s, 5, s->r[4] + 12u); if (rc) return rc; }
    agr_aot_branch_reg(s, 701280u | 1u, 690994u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8b32(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 690996u + 724u); if (rc) return rc; }
    s->r[3] += 691000u;
    { uint32_t addr = s->r[5] + (s->r[0] << 2u); if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_mov_reg(s, 0, 8);
    { int rc = agr_aot_ldr(s, 5, s->r[4] + 12u); if (rc) return rc; }
    agr_aot_branch_reg(s, 701280u | 1u, 691010u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8b42(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 691012u + 712u); if (rc) return rc; }
    s->r[3] += 691016u;
    { uint32_t addr = s->r[5] + (s->r[0] << 2u); if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 12u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 5, s->r[4] + 12u); if (rc) return rc; }
    agr_aot_branch_reg(s, 701280u | 1u, 691026u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8b52(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 691028u + 700u); if (rc) return rc; }
    s->r[3] += 691032u;
    { uint32_t addr = s->r[5] + (s->r[0] << 2u); if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 8u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 5, s->r[4] + 12u); if (rc) return rc; }
    agr_aot_branch_reg(s, 701280u | 1u, 691042u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8b62(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 691044u + 688u); if (rc) return rc; }
    s->r[3] += 691048u;
    { uint32_t addr = s->r[5] + (s->r[0] << 2u); if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 4u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 5, s->r[4] + 12u); if (rc) return rc; }
    agr_aot_branch_reg(s, 701280u | 1u, 691058u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8b72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 691060u + 676u); if (rc) return rc; }
    s->r[3] += 691064u;
    { uint32_t addr = s->r[5] + (s->r[0] << 2u); if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_mov_reg(s, 0, 11);
    { int rc = agr_aot_ldr(s, 5, s->r[4] + 12u); if (rc) return rc; }
    agr_aot_branch_reg(s, 701280u | 1u, 691074u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8b82(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 691076u + 664u); if (rc) return rc; }
    s->r[3] += 691080u;
    { uint32_t addr = s->r[5] + (s->r[0] << 2u); if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_mov_reg(s, 0, 7);
    { int rc = agr_aot_ldr(s, 5, s->r[4] + 12u); if (rc) return rc; }
    agr_aot_branch_reg(s, 701280u | 1u, 691090u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8b92(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 691092u + 652u); if (rc) return rc; }
    s->r[3] += 691096u;
    { uint32_t addr = s->r[5] + (s->r[0] << 2u); if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_mov_reg(s, 0, 4);
    s->r[13] += 20u;
    if ((rc = agr_aot_ldmia_sp(s, 36848u))) return rc;
}

static int aot_fast_000a8e70(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 691828u + 48u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, 691828u + 52u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16440u)) return AGR_AOT_FAULT;
    s->r[0] += 691834u;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 4, 691836u + 48u); if (rc) return rc; }
    s->r[1] += 691840u;
    agr_aot_branch_reg(s, 290972u, 691842u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8e82(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[4] += 691846u;
    { int rc = agr_aot_ldr(s, 4, s->r[4] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = !s->r[3] ? 691852u : 691850u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8e8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32824u))) return rc;
}

static int aot_fast_000a8e8c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 5, 691856u + 32u); if (rc) return rc; }
    agr_aot_movs_imm(s, 1, 2u);
    s->r[5] += 691860u;
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_branch_reg(s, 689040u | 1u, 691864u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8e98(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 691868u + 24u); if (rc) return rc; }
    { uint32_t addr = s->r[4] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    s->r[3] += 691872u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    { uint32_t addr = s->r[3] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    if ((rc = agr_aot_ldmia_sp(s, 32824u))) return rc;
}

static int aot_fast_000a8eb8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    agr_aot_movs_imm(s, 3, 0u);
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_branch_reg(s, 691824u | 1u, 691908u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8ec4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 5, 691912u + 120u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, 691912u + 124u); if (rc) return rc; }
    s->r[5] += 691916u;
    { int rc = agr_aot_ldr(s, 5, s->r[5] + 0u); if (rc) return rc; }
    s->r[3] += 691920u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, s->r[5] + 0u); if (rc) return rc; }
    { uint32_t addr = s->r[4] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[2], s->r[3]);
    s->r[15] = agr_aot_condition(s, 0u) ? 691982u : 691930u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8eda(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 688984u | 1u, 691934u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8ede(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 6, 0);
    agr_aot_branch_reg(s, 290456u, 691940u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8ee4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = s->r[0] ? 692008u : 691942u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8ee6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 0u); if (rc) return rc; }
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = 691948u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8ef0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 1, s->r[1], 1u);
    s->r[15] = 691954u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8ef6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 691948u : 691962u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8efa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    atomic_thread_fence(memory_order_seq_cst);
    agr_aot_mov_reg(s, 0, 6);
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 0u); if (rc) return rc; }
    { uint32_t addr = s->r[4] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 290468u, 691976u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8f08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = s->r[0] ? 692020u : 691978u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8f0a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_000a8f0e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = 691986u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8f16(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 1, s->r[1], 1u);
    s->r[15] = 691992u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8f1c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 691986u : 692000u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8f20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    atomic_thread_fence(memory_order_seq_cst);
    agr_aot_mov_reg(s, 0, 4);
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_000a8f28(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 602216u | 1u, 692012u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8f2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 1, s->r[1], 1u);
    s->r[15] = agr_aot_condition(s, 0u) ? 692026u : 692016u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8f30(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 601524u | 1u, 692020u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8f34(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 602256u | 1u, 692024u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8f38(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 692012u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8f3a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 599856u | 1u, 692030u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8f48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_branch_reg(s, 691824u | 1u, 692046u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8f4e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 4, 692048u + 20u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, 692052u + 20u); if (rc) return rc; }
    s->r[4] += 692054u;
    s->r[3] += 692056u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    { int rc = agr_aot_ldr(s, 1, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 699536u | 1u, 692064u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000a8f60(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_000aa524(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16440u)) return AGR_AOT_FAULT;
    agr_aot_adds(s, 1, s->r[1], 0u);
    { int rc = agr_aot_ldr(s, 3, 697644u + 52u); if (rc) return rc; }
    agr_aot_mov_reg(s, 4, 0);
    { int rc = agr_aot_ldr(s, 5, 697648u + 52u); if (rc) return rc; }
    agr_aot_set_itstate(s, 24u); s->r[15] = 697648u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aac90(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aac94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[1] + 0u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 20464u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 9, 1);
    { int rc = agr_aot_ldr(s, 6, 699552u + 452u); if (rc) return rc; }
    s->r[13] -= 20u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 16u); if (rc) return rc; }
    agr_aot_mov_reg(s, 4, 0);
    s->r[6] += 699560u;
    { int rc = agr_aot_ldr(s, 6, s->r[6] + 0u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[6], 12u);
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { int rc = agr_aot_ldr(s, 10, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[10], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 699974u : 699578u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aacba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 4u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[2], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 699950u : 699586u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aacc2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 8, 3);
    agr_aot_mov_reg(s, 0, 10);
    agr_aot_movs_imm(s, 5, 0u);
    s->r[15] = 699596u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aaccc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = (s->r[8] + 4u); s->r[8] = s->r[8] + 4u; if ((rc = agr_aot_ldr(s, 7, addr))) return rc; }
    agr_aot_adds(s, 5, s->r[5], 1u);
    agr_aot_mov_reg(s, 1, 7);
    agr_aot_branch_reg(s, 289592u, 699608u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aacd8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 3, 1u, s->r[0]);
    agr_aot_set_itstate(s, 56u); s->r[15] = 699614u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aae2e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 10);
    agr_aot_branch_reg(s, 289652u, 699956u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aae34(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 1, 10);
    agr_aot_mov_reg(s, 2, 0);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 789428u | 1u, 699966u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aae3e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[13] += 20u;
    if ((rc = agr_aot_ldmia_sp(s, 36848u))) return rc;
}

static int aot_fast_000aae46(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[6] + 0u); if (rc) return rc; }
    agr_aot_movs_imm(s, 5, 42u);
    agr_aot_mov_reg(s, 1, 10);
    agr_aot_movs_imm(s, 3, 1u);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    agr_aot_branch_reg(s, 789068u | 1u, 699988u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aae54(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 699966u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aafc8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 700364u + 20u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, 700364u + 24u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    s->r[1] += 700370u;
    s->r[0] += 700372u;
    agr_aot_branch_reg(s, 290972u, 700374u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aafd6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 700376u + 16u); if (rc) return rc; }
    s->r[3] += 700380u;
    { int rc = agr_aot_ldr(s, 0, s->r[3] + 0u); if (rc) return rc; }
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) return rc;
}

static int aot_fast_000aafec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 700400u + 4u); if (rc) return rc; }
    s->r[0] += 700402u;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aaff6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 3, s->r[0], 0u);
    s->r[15] = 700408u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aaff8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[0] + 4u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = !s->r[2] ? 700486u : 700416u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab000(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = !s->r[3] ? 700480u : 700420u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab004(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 4, 0u);
    s->r[15] = 700434u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab008(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[5] + 4u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 8u); if (rc) return rc; }
    s->r[15] = 700428u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab00c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 4, s->r[4], 1u);
    agr_aot_cmp(s, s->r[3], s->r[4]);
    s->r[15] = agr_aot_condition(s, 9u) ? 700478u : 700434u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab012(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[2] + (s->r[4] << 2u)); if (rc) return rc; }
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 700428u : 700442u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab01a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 3, s->r[0], 4u);
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = 700448u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab024(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 1, s->r[2], 1u);
    s->r[15] = 700454u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab02a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[6], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 700448u : 700462u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab02e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 1u);
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = agr_aot_condition(s, 1u) ? 700424u : 700470u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab036(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[3], 700476u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab03c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 700424u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab03e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[2] ? 700486u : 700480u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab040(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 2);
    agr_aot_branch_reg(s, 600604u | 1u, 700486u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab046(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[5] + 12u); if (rc) return rc; }
    s->r[15] = !s->r[2] ? 700560u : 700490u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab04a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 8u); if (rc) return rc; }
    s->r[15] = !s->r[3] ? 700554u : 700494u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab04e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 4, 0u);
    s->r[15] = 700508u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab052(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[5] + 12u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 8u); if (rc) return rc; }
    s->r[15] = 700502u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab056(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 4, s->r[4], 1u);
    agr_aot_cmp(s, s->r[3], s->r[4]);
    s->r[15] = agr_aot_condition(s, 9u) ? 700552u : 700508u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab05c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[2] + (s->r[4] << 2u)); if (rc) return rc; }
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 700502u : 700516u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab064(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 3, s->r[0], 4u);
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = 700522u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab06e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 1, s->r[2], 1u);
    s->r[15] = 700528u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab074(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[6], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 700522u : 700536u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab078(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 1u);
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = agr_aot_condition(s, 1u) ? 700498u : 700544u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab080(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[3], 700550u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab086(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 700498u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab088(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[2] ? 700560u : 700554u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab08a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 2);
    agr_aot_branch_reg(s, 600604u | 1u, 700560u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab090(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 16u); if (rc) return rc; }
    s->r[15] = !s->r[3] ? 700590u : 700564u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab094(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 4, 0u);
    s->r[15] = 700566u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab096(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[3] + s->r[4]); if (rc) return rc; }
    s->r[15] = !s->r[0] ? 700576u : 700570u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab09a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 600604u | 1u, 700574u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab09e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 16u); if (rc) return rc; }
    s->r[15] = 700576u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab0a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 4, s->r[4], 4u);
    agr_aot_cmp(s, s->r[4], 24u);
    s->r[15] = agr_aot_condition(s, 1u) ? 700566u : 700582u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab0a6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[3] ? 700590u : 700584u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab0a8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 3);
    agr_aot_branch_reg(s, 600604u | 1u, 700590u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab0ae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_000ab0d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 6, 1);
    { int rc = agr_aot_ldr(s, 3, s->r[1] + 0u); if (rc) return rc; }
    atomic_thread_fence(memory_order_seq_cst);
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 700640u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab0e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 1, s->r[1], 1u);
    s->r[15] = 700646u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab0ea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 700640u : 700654u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab0ee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    atomic_thread_fence(memory_order_seq_cst);
    { int rc = agr_aot_ldr(s, 4, s->r[5] + 0u); if (rc) return rc; }
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = 700664u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab0fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 1, s->r[3], 1u);
    s->r[15] = 700670u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab102(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 700664u : 700678u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab106(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 1u);
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = agr_aot_condition(s, 0u) ? 700694u : 700686u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab10e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[6] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    { uint32_t addr = s->r[5] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_000ab116(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[4], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 700686u : 700698u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab11a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 700408u | 1u, 700704u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab120(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 601516u | 1u, 700710u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab126(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[6] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    { uint32_t addr = s->r[5] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_000ab130(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16440u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 5, 0);
    { int rc = agr_aot_ldr(s, 4, s->r[0] + 0u); if (rc) return rc; }
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = 700730u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab13e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 1, s->r[3], 1u);
    s->r[15] = 700736u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab144(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 700730u : 700744u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab148(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 1u);
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = agr_aot_condition(s, 0u) ? 700756u : 700752u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab150(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    if ((rc = agr_aot_ldmia_sp(s, 32824u))) return rc;
}

static int aot_fast_000ab154(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[4], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 700752u : 700760u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab158(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 700408u | 1u, 700766u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab15e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 601516u | 1u, 700772u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab164(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    if ((rc = agr_aot_ldmia_sp(s, 32824u))) return rc;
}

static int aot_fast_000ab360(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16u)) return AGR_AOT_FAULT;
    s->r[15] = !s->r[3] ? 701296u : 701286u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab366(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 3);
    { uint32_t addr = s->r[13]; s->r[13] = s->r[13] + 4u; if ((rc = agr_aot_ldr(s, 4, addr))) return rc; }
    agr_aot_subs(s, 0, s->r[0], 1u);
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab370(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, 701300u + 36u); if (rc) return rc; }
    atomic_thread_fence(memory_order_seq_cst);
    s->r[2] += 701306u;
    s->r[15] = 701304u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab37c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 1, s->r[3], 1u);
    s->r[15] = 701310u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab382(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[4], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 701304u : 701318u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab386(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 3, s->r[3], 1u);
    atomic_thread_fence(memory_order_seq_cst);
    { uint32_t addr = s->r[13]; s->r[13] = s->r[13] + 4u; if ((rc = agr_aot_ldr(s, 4, addr))) return rc; }
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_mov_reg(s, 0, 3);
    agr_aot_subs(s, 0, s->r[0], 1u);
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab398(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 7, s->r[7], 122u);
    agr_aot_lsls(s, 4, s->r[0], 0u);
    s->r[15] = 701340u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab39c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 18416u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 5, 0);
    agr_aot_mov_reg(s, 8, 2);
    agr_aot_cmp(s, s->r[2], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 701690u : 701354u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab3aa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 1);
    agr_aot_branch_reg(s, 701280u | 1u, 701360u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab3b0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 8u); if (rc) return rc; }
    agr_aot_subs(s, 3, s->r[3], 1u);
    agr_aot_cmp(s, s->r[0], s->r[3]);
    agr_aot_mov_reg(s, 6, 0);
    s->r[15] = agr_aot_condition(s, 9u) ? 701550u : 701370u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab3ba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 7, s->r[0], 4u);
    { int rc = agr_aot_ldr(s, 9, s->r[5] + 4u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[7], 532676608u);
    agr_aot_set_itstate(s, 148u); s->r[15] = 701382u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab46e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 3, s->r[8], 4u);
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = 701558u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab47a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 1, s->r[1], 1u);
    s->r[15] = 701564u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab480(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 701558u : 701572u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab484(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    atomic_thread_fence(memory_order_seq_cst);
    { int rc = agr_aot_ldr(s, 4, s->r[5] + 4u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 0, s->r[4] + (s->r[6] << 2u)); if (rc) return rc; }
    s->r[15] = !s->r[0] ? 701614u : 701584u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab490(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 3, s->r[0], 4u);
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = 701590u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab49a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 7, s->r[2], 1u);
    s->r[15] = 701596u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab4a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[12], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 701590u : 701606u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab4a6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 1u);
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = agr_aot_condition(s, 0u) ? 701702u : 701614u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab4ae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[5] + 8u); if (rc) return rc; }
    { uint32_t addr = s->r[4] + (s->r[6] << 2u); if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    s->r[15] = !s->r[2] ? 701690u : 701622u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab4b6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 4, 0u);
    agr_aot_mov_reg(s, 7, 4);
    s->r[15] = 701640u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab4bc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 12u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, s->r[5] + 8u); if (rc) return rc; }
    { uint32_t addr = s->r[3] + s->r[6]; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    s->r[15] = 701634u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab4c2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 4, s->r[4], 1u);
    agr_aot_cmp(s, s->r[2], s->r[4]);
    s->r[15] = agr_aot_condition(s, 9u) ? 701694u : 701640u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab4c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 12u); if (rc) return rc; }
    agr_aot_lsls(s, 6, s->r[4], 2u);
    { int rc = agr_aot_ldr(s, 0, s->r[3] + (s->r[4] << 2u)); if (rc) return rc; }
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 701634u : 701652u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab4d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 3, s->r[0], 4u);
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = 701658u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab4de(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 1, s->r[2], 1u);
    s->r[15] = 701664u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab4e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[12], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 701658u : 701674u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab4ea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 1u);
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = agr_aot_condition(s, 1u) ? 701628u : 701682u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab4f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[3], 701688u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab4f8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 701628u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab4fa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 34800u))) return rc;
}

static int aot_fast_000ab4fe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 34800u))) return rc;
}

static int aot_fast_000ab506(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[3], 701708u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ab50c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 701614u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000abc64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16440u)) return AGR_AOT_FAULT;
    agr_aot_adds(s, 3, s->r[3], 0u);
    { int rc = agr_aot_ldr(s, 5, 703596u + 92u); if (rc) return rc; }
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_set_itstate(s, 24u); s->r[15] = 703598u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ad2b0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 709300u + 48u); if (rc) return rc; }
    agr_aot_adds(s, 2, s->r[2], 0u);
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    s->r[3] += 709306u;
    { uint32_t addr = s->r[0] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    agr_aot_set_itstate(s, 24u); s->r[15] = 709308u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ad734(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 710456u + 36u); if (rc) return rc; }
    agr_aot_adds(s, 1, s->r[1], 0u);
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    s->r[3] += 710462u;
    agr_aot_set_itstate(s, 24u); s->r[15] = 710462u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ad9a4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 711080u + 60u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_mov_reg(s, 0, 3);
    s->r[0] += 711088u;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 701280u | 1u, 711092u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ad9b4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, s->r[3] + 8u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[0], s->r[1]);
    s->r[15] = agr_aot_condition(s, 2u) ? 711130u : 711102u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ad9be(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[3] + (s->r[0] << 2u)); if (rc) return rc; }
    s->r[15] = !s->r[0] ? 711130u : 711108u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ad9c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 711112u + 32u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    { int rc = agr_aot_ldr(s, 2, 711116u + 32u); if (rc) return rc; }
    s->r[1] += 711118u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[2] += 711122u;
    { int rc = agr_aot_ldr(s, 2, s->r[2] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 601352u | 1u, 711126u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ad9d6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[0] ? 711134u : 711128u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ad9d8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_000ad9da(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 783776u | 1u, 711134u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ad9de(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 794072u | 1u, 711138u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ad9e6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 3, s->r[0], 0u);
    s->r[15] = 711144u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ad9ea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 3, s->r[0], 0u);
    s->r[15] = 711148u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ad9ee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 3, s->r[0], 0u);
    if (agr_aot_stmdb_sp(s, 20464u)) return AGR_AOT_FAULT;
    s->r[13] -= 60u;
    agr_aot_add_imm(s, 9, s->r[13], 40u);
    agr_aot_mov_reg(s, 10, 1);
    { int rc = agr_aot_ldr(s, 5, s->r[13] + 96u); if (rc) return rc; }
    agr_aot_mov_reg(s, 7, 2);
    { uint32_t addr = s->r[13] + 36u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_add_imm(s, 0, s->r[5], 108u);
    { int rc = agr_aot_ldr(s, 4, s->r[13] + 108u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, s->r[13] + 112u); if (rc) return rc; }
    if (agr_aot_stm(s, 9u, 12u)) return AGR_AOT_FAULT;
    s->r[15] = 711182u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ada12(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 711076u | 1u, 711190u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ada16(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[4], s->r[6]);
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = agr_aot_condition(s, 0u) ? 711390u : 711196u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ada1c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 3, s->r[13], 48u);
    { uint32_t addr = s->r[13] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 711242u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ada22(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[8], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 711236u : 711210u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ada2a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[7] + 20u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, s->r[7] + 24u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], s->r[2]);
    s->r[15] = agr_aot_condition(s, 2u) ? 711424u : 711218u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ada32(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[3]; s->r[3] = s->r[3] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { uint32_t addr = s->r[7] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 711224u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ada3c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 8, 0u, s->r[3]);
    s->r[15] = 711232u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ada44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 4, s->r[4], 4u);
    agr_aot_cmp(s, s->r[6], s->r[4]);
    s->r[15] = agr_aot_condition(s, 0u) ? 711390u : 711242u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ada4a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_movs_imm(s, 2, 0u);
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 48u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[3], 711254u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ada56(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 37u);
    s->r[15] = agr_aot_condition(s, 1u) ? 711202u : 711258u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ada5a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, s->r[4], 4u);
    agr_aot_cmp(s, s->r[6], s->r[12]);
    s->r[15] = agr_aot_condition(s, 0u) ? 711390u : 711266u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ada62(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 0u); if (rc) return rc; }
    agr_aot_movs_imm(s, 2, 0u);
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 4u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 48u); if (rc) return rc; }
    { uint32_t addr = s->r[13] + 28u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[12]); }
    agr_aot_branch_reg(s, s->r[3], 711282u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ada72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 12, s->r[13] + 28u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[0], 79u);
    agr_aot_set_itstate(s, 24u); s->r[15] = 711290u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000adade(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 4, s->r[13] + 36u); if (rc) return rc; }
    { uint32_t addr = s->r[13] + 40u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[13] + 44u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[8]); }
    s->r[15] = 711398u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000adaea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stm(s, 4u, 3u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 0, 4);
    s->r[13] += 60u;
    if ((rc = agr_aot_ldmia_sp(s, 36848u))) return rc;
}

static int aot_fast_000adb00(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[7] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 7);
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 52u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[3], 711432u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000adb08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 1, 0);
    s->r[15] = 711224u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae194(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    { int rc = agr_aot_ldr(s, 0, 713116u + 48u); if (rc) return rc; }
    s->r[0] += 713118u;
    agr_aot_branch_reg(s, 701280u | 1u, 713120u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae1a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, s->r[3] + 8u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[0], s->r[1]);
    s->r[15] = agr_aot_condition(s, 2u) ? 713156u : 713130u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae1aa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[3] + (s->r[0] << 2u)); if (rc) return rc; }
    s->r[15] = !s->r[0] ? 713156u : 713136u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae1b0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 713140u + 28u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    { int rc = agr_aot_ldr(s, 2, 713144u + 28u); if (rc) return rc; }
    s->r[1] += 713146u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[2] += 713150u;
    agr_aot_branch_reg(s, 601352u | 1u, 713152u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae1c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[0] ? 713160u : 713154u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae1c2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_000ae1c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 783776u | 1u, 713160u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae1c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 794072u | 1u, 713164u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae1ce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 4, s->r[0], 0u);
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 664u); if (rc) return rc; }
    agr_aot_lsls(s, 3, s->r[0], 0u);
    { int rc = agr_aot_ldrh(s, 2, s->r[3] + 22u); if (rc) return rc; }
    agr_aot_lsls(s, 3, s->r[0], 0u);
    s->r[15] = 713176u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae1d8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    { int rc = agr_aot_ldr(s, 0, 713184u + 48u); if (rc) return rc; }
    s->r[0] += 713186u;
    agr_aot_branch_reg(s, 701280u | 1u, 713188u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae1e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, s->r[3] + 8u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[0], s->r[1]);
    s->r[15] = agr_aot_condition(s, 2u) ? 713224u : 713198u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae1ee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[3] + (s->r[0] << 2u)); if (rc) return rc; }
    s->r[15] = !s->r[0] ? 713224u : 713204u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae1f4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 713208u + 28u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    { int rc = agr_aot_ldr(s, 2, 713212u + 28u); if (rc) return rc; }
    s->r[1] += 713214u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[2] += 713218u;
    agr_aot_branch_reg(s, 601352u | 1u, 713220u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae204(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[0] ? 713228u : 713222u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae206(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_000ae208(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 783776u | 1u, 713228u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae20c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 794072u | 1u, 713232u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae212(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 4, s->r[0], 0u);
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 392u); if (rc) return rc; }
    agr_aot_lsls(s, 3, s->r[0], 0u);
    { int rc = agr_aot_ldrh(s, 6, s->r[0] + 24u); if (rc) return rc; }
    agr_aot_lsls(s, 3, s->r[0], 0u);
    s->r[15] = 713244u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae21c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    { int rc = agr_aot_ldr(s, 0, 713252u + 48u); if (rc) return rc; }
    s->r[0] += 713254u;
    agr_aot_branch_reg(s, 701280u | 1u, 713256u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae228(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, s->r[3] + 8u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[0], s->r[1]);
    s->r[15] = agr_aot_condition(s, 2u) ? 713292u : 713266u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae232(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[3] + (s->r[0] << 2u)); if (rc) return rc; }
    s->r[15] = !s->r[0] ? 713292u : 713272u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae238(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 713276u + 28u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    { int rc = agr_aot_ldr(s, 2, 713280u + 28u); if (rc) return rc; }
    s->r[1] += 713282u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[2] += 713286u;
    agr_aot_branch_reg(s, 601352u | 1u, 713288u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae248(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[0] ? 713296u : 713290u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae24a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_000ae24c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 783776u | 1u, 713296u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae250(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 794072u | 1u, 713300u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae256(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 4, s->r[0], 0u);
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 120u); if (rc) return rc; }
    agr_aot_lsls(s, 3, s->r[0], 0u);
    { int rc = agr_aot_ldrh(s, 2, s->r[2] + 24u); if (rc) return rc; }
    agr_aot_lsls(s, 3, s->r[0], 0u);
    if (agr_aot_stmdb_sp(s, 20464u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 5, 0);
    s->r[13] -= 60u;
    agr_aot_mov_reg(s, 0, 1);
    agr_aot_movs_imm(s, 3, 1u);
    { uint32_t addr = s->r[5] + 108u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    agr_aot_mov_reg(s, 10, 1);
    agr_aot_branch_reg(s, 713244u | 1u, 713334u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae276(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 4, 0);
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 8u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[3], 713342u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae27e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 12u); if (rc) return rc; }
    { uint32_t addr = s->r[5] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, s->r[3], 713352u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae288(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 32u); if (rc) return rc; }
    { uint32_t addr = s->r[5] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, s->r[3], 713362u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae292(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 1, 4);
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 16u); if (rc) return rc; }
    { uint32_t addr = s->r[5] + 52u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_add_imm(s, 0, s->r[13], 8u);
    agr_aot_branch_reg(s, s->r[3], 713374u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae29e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[13] + 8u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 713380u + 936u); if (rc) return rc; }
    agr_aot_mov_reg(s, 3, 2);
    s->r[6] += 713384u;
    { int rc = agr_aot_ldr(s, 6, s->r[6] + 0u); if (rc) return rc; }
    { uint32_t addr = (s->r[3] - 12u); s->r[3] = s->r[3] - 12u; if ((rc = agr_aot_ldr(s, 0, addr))) return rc; }
    agr_aot_cmp(s, s->r[3], s->r[6]);
    { uint32_t addr = s->r[5] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = agr_aot_condition(s, 1u) ? 713788u : 713396u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae2b4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 602060u | 1u, 713400u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae2b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_add_imm(s, 8, s->r[13], 12u);
    agr_aot_mov_reg(s, 7, 0);
    agr_aot_mov_reg(s, 1, 4);
    agr_aot_mov_reg(s, 0, 8);
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 16u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[3], 713416u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae2c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 8);
    agr_aot_mov_reg(s, 1, 7);
    { int rc = agr_aot_ldr(s, 2, s->r[5] + 12u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_branch_reg(s, 786644u | 1u, 713428u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae2d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 12u); if (rc) return rc; }
    s->r[15] = 713430u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae2da(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], s->r[6]);
    s->r[15] = agr_aot_condition(s, 1u) ? 713966u : 713440u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae2e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 12u); if (rc) return rc; }
    { uint32_t addr = s->r[5] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    s->r[15] = !s->r[3] ? 713458u : 713446u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae2ea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 0u);
    agr_aot_set_itstate(s, 212u); s->r[15] = 713454u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae2f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_add_imm(s, 0, s->r[13], 16u);
    { uint32_t addr = s->r[5] + 16u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    agr_aot_mov_reg(s, 1, 4);
    { int rc = agr_aot_ldr(s, 3, s->r[2] + 20u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[3], 713470u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae2fe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[13] + 16u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 713476u + 844u); if (rc) return rc; }
    agr_aot_mov_reg(s, 3, 2);
    s->r[6] += 713480u;
    { int rc = agr_aot_ldr(s, 6, s->r[6] + 0u); if (rc) return rc; }
    { uint32_t addr = (s->r[3] - 12u); s->r[3] = s->r[3] - 12u; if ((rc = agr_aot_ldr(s, 0, addr))) return rc; }
    agr_aot_cmp(s, s->r[3], s->r[6]);
    { uint32_t addr = s->r[5] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = agr_aot_condition(s, 1u) ? 713932u : 713492u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae314(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 532676608u);
    agr_aot_set_itstate(s, 148u); s->r[15] = 713498u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae43c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 2, s->r[2], 4u);
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = 713794u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae446(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 0, s->r[1], 1u);
    s->r[15] = 713800u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae44c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[7], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 713794u : 713808u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae450(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[1], 0u);
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = agr_aot_condition(s, 13u) ? 714090u : 713818u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae45a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[5] + 12u); if (rc) return rc; }
    s->r[15] = 713396u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae4cc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 2, s->r[2], 4u);
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = 713938u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae4d6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 14, s->r[1], 1023u);
    s->r[15] = 713946u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae4de(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 713938u : 713954u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae4e2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[1], 0u);
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = agr_aot_condition(s, 13u) ? 714110u : 713962u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae4ea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[5] + 32u); if (rc) return rc; }
    s->r[15] = 713492u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae4ee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 3, s->r[3], 4u);
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = 713972u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae4f8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 14, s->r[2], 1023u);
    s->r[15] = 713980u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae500(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[1], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 713972u : 713988u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae504(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 0u);
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = agr_aot_condition(s, 12u) ? 713440u : 713998u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae50e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 1, s->r[13], 52u);
    agr_aot_branch_reg(s, 788308u | 1u, 714004u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae514(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 713440u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae56a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 3);
    agr_aot_add_imm(s, 1, s->r[13], 52u);
    agr_aot_branch_reg(s, 788308u | 1u, 714098u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae572(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 713818u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae57e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 3);
    agr_aot_add_imm(s, 1, s->r[13], 52u);
    agr_aot_branch_reg(s, 760044u | 1u, 714118u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ae586(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 713962u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aecc0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 715972u + 60u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_mov_reg(s, 0, 3);
    s->r[0] += 715980u;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 701280u | 1u, 715984u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aecd0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, s->r[3] + 8u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[0], s->r[1]);
    s->r[15] = agr_aot_condition(s, 2u) ? 716026u : 715994u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aecda(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[3] + (s->r[0] << 2u)); if (rc) return rc; }
    s->r[15] = !s->r[0] ? 716028u : 716000u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aece0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 716004u + 32u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    { int rc = agr_aot_ldr(s, 2, 716008u + 32u); if (rc) return rc; }
    s->r[1] += 716010u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[2] += 716014u;
    { int rc = agr_aot_ldr(s, 2, s->r[2] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 601352u | 1u, 716018u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aecf2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 0, s->r[0], 0u);
    agr_aot_set_itstate(s, 24u); s->r[15] = 716022u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aecfa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = 716028u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aecfc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_000aede0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    { int rc = agr_aot_ldr(s, 0, 716264u + 48u); if (rc) return rc; }
    s->r[0] += 716266u;
    agr_aot_branch_reg(s, 701280u | 1u, 716268u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aedec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, s->r[3] + 8u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[0], s->r[1]);
    s->r[15] = agr_aot_condition(s, 2u) ? 716308u : 716278u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aedf6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[3] + (s->r[0] << 2u)); if (rc) return rc; }
    s->r[15] = !s->r[0] ? 716310u : 716284u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aedfc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 716288u + 28u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    { int rc = agr_aot_ldr(s, 2, 716292u + 28u); if (rc) return rc; }
    s->r[1] += 716294u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[2] += 716298u;
    agr_aot_branch_reg(s, 601352u | 1u, 716300u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aee0c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 0, s->r[0], 0u);
    agr_aot_set_itstate(s, 24u); s->r[15] = 716304u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aee14(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = 716310u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aee16(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_000aee24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    { int rc = agr_aot_ldr(s, 0, 716332u + 48u); if (rc) return rc; }
    s->r[0] += 716334u;
    agr_aot_branch_reg(s, 701280u | 1u, 716336u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aee30(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, s->r[3] + 8u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[0], s->r[1]);
    s->r[15] = agr_aot_condition(s, 2u) ? 716376u : 716346u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aee3a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[3] + (s->r[0] << 2u)); if (rc) return rc; }
    s->r[15] = !s->r[0] ? 716378u : 716352u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aee40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 716356u + 28u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    { int rc = agr_aot_ldr(s, 2, 716360u + 28u); if (rc) return rc; }
    s->r[1] += 716362u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[2] += 716366u;
    agr_aot_branch_reg(s, 601352u | 1u, 716368u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aee50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 0, s->r[0], 0u);
    agr_aot_set_itstate(s, 24u); s->r[15] = 716372u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aee58(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = 716378u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000aee5a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_000b98ec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 601516u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf5a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    agr_aot_movs_imm(s, 0, 4u);
    agr_aot_branch_reg(s, 602296u | 1u, 783784u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf5a8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 783788u + 24u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, 783788u + 28u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, 783792u + 28u); if (rc) return rc; }
    s->r[3] += 783794u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_adds(s, 3, s->r[3], 8u);
    s->r[1] += 783800u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[2] += 783804u;
    { int rc = agr_aot_ldr(s, 2, s->r[2] + 0u); if (rc) return rc; }
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 600912u | 1u, 783810u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf5c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[2] + 54u; if (agr_aot_fault16(addr)) return AGR_AOT_FAULT; agr_aot_store16(s, addr, s->r[6]); }
    agr_aot_lsls(s, 2, s->r[0], 0u);
    { uint32_t addr = s->r[2] + 54u; if (agr_aot_fault16(addr)) return AGR_AOT_FAULT; agr_aot_store16(s, addr, s->r[4]); }
    agr_aot_lsls(s, 2, s->r[0], 0u);
    { uint32_t addr = s->r[2] + 54u; if (agr_aot_fault16(addr)) return AGR_AOT_FAULT; agr_aot_store16(s, addr, s->r[4]); }
    agr_aot_lsls(s, 2, s->r[0], 0u);
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    agr_aot_movs_imm(s, 0, 4u);
    agr_aot_branch_reg(s, 602296u | 1u, 783832u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf5d8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 783836u + 24u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, 783836u + 28u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, 783840u + 28u); if (rc) return rc; }
    s->r[3] += 783842u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_adds(s, 3, s->r[3], 8u);
    s->r[1] += 783848u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[2] += 783852u;
    { int rc = agr_aot_ldr(s, 2, s->r[2] + 0u); if (rc) return rc; }
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 600912u | 1u, 783858u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf5f4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[6] + 52u; if (agr_aot_fault16(addr)) return AGR_AOT_FAULT; agr_aot_store16(s, addr, s->r[2]); }
    agr_aot_lsls(s, 2, s->r[0], 0u);
    { uint32_t addr = s->r[6] + 52u; if (agr_aot_fault16(addr)) return AGR_AOT_FAULT; agr_aot_store16(s, addr, s->r[0]); }
    agr_aot_lsls(s, 2, s->r[0], 0u);
    { uint32_t addr = s->r[6] + 52u; if (agr_aot_fault16(addr)) return AGR_AOT_FAULT; agr_aot_store16(s, addr, s->r[0]); }
    agr_aot_lsls(s, 2, s->r[0], 0u);
    s->r[15] = 783872u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf600(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 6, 0);
    s->r[13] -= 16u;
    agr_aot_movs_imm(s, 0, 8u);
    agr_aot_branch_reg(s, 602296u | 1u, 783884u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf60c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 5, s->r[13], 12u);
    agr_aot_mov_reg(s, 1, 6);
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_branch_reg(s, 792908u | 1u, 783898u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf61a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_mov_reg(s, 1, 5);
    agr_aot_branch_reg(s, 609064u | 1u, 783906u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf622(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 12u); if (rc) return rc; }
    agr_aot_add_imm(s, 1, s->r[13], 8u);
    agr_aot_subs(s, 0, s->r[0], 12u);
    agr_aot_branch_reg(s, 788312u | 1u, 783916u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf62c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 783920u + 36u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, 783920u + 40u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 783926u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[2] += 783930u;
    { int rc = agr_aot_ldr(s, 2, s->r[2] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 600912u | 1u, 783934u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf63e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602448u | 1u, 783940u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf644(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 601524u | 1u, 783944u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf648(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 12u); if (rc) return rc; }
    agr_aot_add_imm(s, 1, s->r[13], 8u);
    agr_aot_subs(s, 0, s->r[0], 12u);
    agr_aot_branch_reg(s, 788312u | 1u, 783954u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf652(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 783934u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf714(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 6, 0);
    s->r[13] -= 16u;
    agr_aot_movs_imm(s, 0, 8u);
    agr_aot_branch_reg(s, 602296u | 1u, 784160u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf720(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 5, s->r[13], 12u);
    agr_aot_mov_reg(s, 1, 6);
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_branch_reg(s, 792908u | 1u, 784174u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf72e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_mov_reg(s, 1, 5);
    agr_aot_branch_reg(s, 609148u | 1u, 784182u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf736(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 12u); if (rc) return rc; }
    agr_aot_add_imm(s, 1, s->r[13], 8u);
    agr_aot_subs(s, 0, s->r[0], 12u);
    agr_aot_branch_reg(s, 788312u | 1u, 784192u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf740(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 784196u + 36u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, 784196u + 40u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 784202u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[2] += 784206u;
    { int rc = agr_aot_ldr(s, 2, s->r[2] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 600912u | 1u, 784210u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf752(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602448u | 1u, 784216u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf758(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 601524u | 1u, 784220u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf75c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 12u); if (rc) return rc; }
    agr_aot_add_imm(s, 1, s->r[13], 8u);
    agr_aot_subs(s, 0, s->r[0], 12u);
    agr_aot_branch_reg(s, 788312u | 1u, 784230u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf766(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 784210u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf770(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 6, 0);
    s->r[13] -= 16u;
    agr_aot_movs_imm(s, 0, 8u);
    agr_aot_branch_reg(s, 602296u | 1u, 784252u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf77c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 5, s->r[13], 12u);
    agr_aot_mov_reg(s, 1, 6);
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_branch_reg(s, 792908u | 1u, 784266u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf78a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_mov_reg(s, 1, 5);
    agr_aot_branch_reg(s, 609172u | 1u, 784274u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf792(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 12u); if (rc) return rc; }
    agr_aot_add_imm(s, 1, s->r[13], 8u);
    agr_aot_subs(s, 0, s->r[0], 12u);
    agr_aot_branch_reg(s, 788312u | 1u, 784284u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf79c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 784288u + 36u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, 784288u + 40u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 4);
    s->r[1] += 784294u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[2] += 784298u;
    { int rc = agr_aot_ldr(s, 2, s->r[2] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, 600912u | 1u, 784302u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf7ae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 602448u | 1u, 784308u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf7b4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 601524u | 1u, 784312u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf7b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 12u); if (rc) return rc; }
    agr_aot_add_imm(s, 1, s->r[13], 8u);
    agr_aot_subs(s, 0, s->r[0], 12u);
    agr_aot_branch_reg(s, 788312u | 1u, 784322u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000bf7c2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 784302u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0020(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 2, s->r[2], 12u);
    { uint32_t addr = s->r[1] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c002c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0030(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    { uint32_t addr = (s->r[3] - 12u); if ((rc = agr_aot_ldr(s, 0, addr))) return rc; }
    s->r[0] += s->r[3];
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c003c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[1] + 0u); if (rc) return rc; }
    { uint32_t addr = (s->r[3] - 12u); if ((rc = agr_aot_ldr(s, 2, addr))) return rc; }
    s->r[3] += s->r[2];
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0048(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[1] + 0u); if (rc) return rc; }
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0050(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0054(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    { uint32_t addr = (s->r[3] - 12u); if ((rc = agr_aot_ldr(s, 0, addr))) return rc; }
    s->r[0] += s->r[3];
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0060(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[1] + 0u); if (rc) return rc; }
    { uint32_t addr = (s->r[3] - 12u); if ((rc = agr_aot_ldr(s, 2, addr))) return rc; }
    s->r[3] += s->r[2];
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c006c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[1] + 0u); if (rc) return rc; }
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0074(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    { uint32_t addr = (s->r[3] - 12u); if ((rc = agr_aot_ldr(s, 0, addr))) return rc; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c007c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movw(s, 0, 65532u);
    s->r[0] = (s->r[0] & 0xffffu) | (16383u << 16);
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0088(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    { uint32_t addr = (s->r[3] - 8u); if ((rc = agr_aot_ldr(s, 0, addr))) return rc; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0090(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    { uint32_t addr = (s->r[3] - 12u); if ((rc = agr_aot_ldr(s, 0, addr))) return rc; }
    agr_aot_subs(s, 0, 1u, s->r[0]);
    agr_aot_set_itstate(s, 56u); s->r[15] = 786588u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c00d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    { int rc = agr_aot_ldr(s, 6, s->r[0] + 0u); if (rc) return rc; }
    { uint32_t addr = (s->r[6] - 12u); if ((rc = agr_aot_ldr(s, 5, addr))) return rc; }
    agr_aot_cmp(s, s->r[3], s->r[5]);
    s->r[15] = agr_aot_condition(s, 8u) ? 786696u : 786656u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c00e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 4, s->r[5], s->r[3]);
    agr_aot_cmp(s, s->r[4], s->r[2]);
    agr_aot_set_itstate(s, 40u); s->r[15] = 786662u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0108(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 786700u + 4u); if (rc) return rc; }
    s->r[0] += 786702u;
    agr_aot_branch_reg(s, 784240u | 1u, 786704u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0110(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = agr_aot_condition(s, 2u) ? 786464u : 786706u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0112(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 1, s->r[0], 0u);
    { int rc = agr_aot_ldr(s, 2, s->r[0] + 0u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16u)) return AGR_AOT_FAULT;
    { uint32_t addr = (s->r[2] - 4u); if ((rc = agr_aot_ldr(s, 3, addr))) return rc; }
    agr_aot_cmp(s, s->r[3], 0u);
    agr_aot_set_itstate(s, 188u); s->r[15] = 786720u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0678(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movw(s, 3, 65532u);
    s->r[3] = (s->r[3] & 0xffffu) | (16383u << 16);
    agr_aot_cmp(s, s->r[0], s->r[3]);
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = agr_aot_condition(s, 8u) ? 788170u : 788104u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0688(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], s->r[1]);
    s->r[15] = agr_aot_condition(s, 9u) ? 788154u : 788108u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c068c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 2, s->r[1], 1u);
    agr_aot_cmp(s, s->r[4], s->r[2]);
    agr_aot_set_itstate(s, 56u); s->r[15] = 788114u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c06ba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 13u);
    agr_aot_branch_reg(s, 599660u | 1u, 788162u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c06c2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    { uint32_t addr = s->r[0] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_000c06ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 788172u + 8u); if (rc) return rc; }
    s->r[0] += 788176u;
    agr_aot_branch_reg(s, 784148u | 1u, 788178u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c06d6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 1, s->r[0], 0u);
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 6, 1);
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = s->r[0] ? 788202u : 788192u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c06e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 788196u + 60u); if (rc) return rc; }
    s->r[3] += 788198u;
    agr_aot_adds(s, 3, s->r[3], 12u);
    agr_aot_mov_reg(s, 0, 3);
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_000c06ea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    agr_aot_branch_reg(s, 788088u | 1u, 788208u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c06f0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[4], 1u);
    agr_aot_mov_reg(s, 5, 0);
    agr_aot_add_imm(s, 3, s->r[0], 12u);
    s->r[15] = agr_aot_condition(s, 0u) ? 788250u : 788218u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c06fa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 3);
    agr_aot_mov_reg(s, 1, 6);
    agr_aot_mov_reg(s, 2, 4);
    agr_aot_branch_reg(s, 289460u, 788228u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0704(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 3, 0);
    s->r[15] = 788230u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0706(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, 788232u + 28u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 3);
    s->r[2] += 788238u;
    agr_aot_cmp(s, s->r[5], s->r[2]);
    agr_aot_set_itstate(s, 31u); s->r[15] = 788240u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c071a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[5] + 12u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[6]); }
    s->r[15] = 788230u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0754(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 601516u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0758(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 788316u + 12u); if (rc) return rc; }
    s->r[3] += 788318u;
    agr_aot_cmp(s, s->r[3], s->r[0]);
    s->r[15] = agr_aot_condition(s, 1u) ? 788322u : 788320u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0760(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0762(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 292756u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0790(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 20464u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 7, 0);
    { int rc = agr_aot_ldr(s, 4, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 5, 1);
    s->r[15] = 788378u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c079e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] -= 12u;
    agr_aot_mov_reg(s, 6, 2);
    agr_aot_mov_reg(s, 9, 3);
    { uint32_t addr = (s->r[4] - 12u); if ((rc = agr_aot_ldr(s, 0, addr))) return rc; }
    { uint32_t addr = (s->r[4] - 8u); if ((rc = agr_aot_ldr(s, 1, addr))) return rc; }
    s->r[8] += s->r[0];
    s->r[15] = 788398u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c07b2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[8], s->r[1]);
    s->r[15] = 788404u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c07b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = agr_aot_condition(s, 8u) ? 788418u : 788410u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c07ba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = (s->r[4] - 4u); if ((rc = agr_aot_ldr(s, 3, addr))) return rc; }
    agr_aot_cmp(s, s->r[3], 0u);
    s->r[15] = agr_aot_condition(s, 13u) ? 788526u : 788418u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c07c2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 11, s->r[13], 4u);
    agr_aot_mov_reg(s, 0, 8);
    agr_aot_mov_reg(s, 2, 11);
    agr_aot_branch_reg(s, 788088u | 1u, 788430u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c07ce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 4, s->r[0], 12u);
    s->r[15] = !s->r[5] ? 788446u : 788436u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c07d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[5], 1u);
    { int rc = agr_aot_ldr(s, 1, s->r[7] + 0u); if (rc) return rc; }
    s->r[15] = agr_aot_condition(s, 1u) ? 788574u : 788442u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c07da(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[1] + 0u); if (rc) return rc; }
    { uint32_t addr = s->r[0] + 12u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    s->r[15] = 788446u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c07de(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[10], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 788498u : 788452u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c07e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[7] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, 788456u + 152u); if (rc) return rc; }
    agr_aot_subs(s, 0, s->r[0], 12u);
    s->r[3] += 788462u;
    agr_aot_cmp(s, s->r[0], s->r[3]);
    s->r[15] = agr_aot_condition(s, 1u) ? 788598u : 788464u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c07f0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[7] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { int rc = agr_aot_ldr(s, 3, 788468u + 144u); if (rc) return rc; }
    s->r[15] = 788468u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c07f8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[3] += 788476u;
    agr_aot_cmp(s, s->r[2], s->r[3]);
    agr_aot_set_itstate(s, 31u); s->r[15] = 788478u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0812(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[7] + 0u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[10], 1u);
    s->r[9] += s->r[5];
    s->r[5] += s->r[6];
    agr_aot_add_imm(s, 0, s->r[4], s->r[9]);
    agr_aot_add_imm(s, 1, s->r[3], s->r[5]);
    s->r[15] = agr_aot_condition(s, 1u) ? 788590u : 788518u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0826(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[3] + s->r[5]); if (rc) return rc; }
    s->r[15] = 788520u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c082c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 788452u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c082e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], s->r[9]);
    agr_aot_set_itstate(s, 24u); s->r[15] = 788530u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c085e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_mov_reg(s, 2, 5);
    agr_aot_branch_reg(s, 289580u, 788582u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0866(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[10], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 788452u : 788588u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c086c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 788498u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c086e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 2, 10);
    agr_aot_branch_reg(s, 289580u, 788596u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0874(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 788452u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0876(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 1, 11);
    agr_aot_branch_reg(s, 292756u | 1u, 788604u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c087c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 788464u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0a4c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 17400u)) return AGR_AOT_FAULT;
    agr_aot_movw(s, 4, 65532u);
    { int rc = agr_aot_ldr(s, 7, s->r[0] + 0u); if (rc) return rc; }
    s->r[4] = (s->r[4] & 0xffffu) | (16383u << 16);
    agr_aot_mov_reg(s, 6, 0);
    agr_aot_mov_reg(s, 8, 1);
    agr_aot_mov_reg(s, 5, 3);
    s->r[15] = 789088u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0a64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = (s->r[7] - 12u); if ((rc = agr_aot_ldr(s, 7, addr))) return rc; }
    agr_aot_subs(s, 4, s->r[4], s->r[7]);
    s->r[4] += s->r[2];
    agr_aot_cmp(s, s->r[3], s->r[4]);
    s->r[15] = agr_aot_condition(s, 8u) ? 789140u : 789104u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0a70(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 788368u | 1u, 789108u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0a74(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[5] ? 789134u : 789110u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0a76(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[6] + 0u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[5], 1u);
    agr_aot_add_imm(s, 0, s->r[3], s->r[8]);
    agr_aot_set_itstate(s, 8u); s->r[15] = 789120u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0a8e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    if ((rc = agr_aot_ldmia_sp(s, 33784u))) return rc;
}

static int aot_fast_000c0a94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 789144u + 4u); if (rc) return rc; }
    s->r[0] += 789146u;
    agr_aot_branch_reg(s, 784148u | 1u, 789148u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0a9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 1, s->r[0], 0u);
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    { int rc = agr_aot_ldr(s, 4, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 3, 1);
    agr_aot_movs_imm(s, 1, 0u);
    { uint32_t addr = (s->r[4] - 12u); if ((rc = agr_aot_ldr(s, 4, addr))) return rc; }
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_mov_reg(s, 2, 4);
    agr_aot_branch_reg(s, 789068u | 1u, 789174u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0ab6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_000c0b84(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16632u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 7, 3);
    { int rc = agr_aot_ldr(s, 4, s->r[13] + 24u); if (rc) return rc; }
    agr_aot_mov_reg(s, 5, 0);
    agr_aot_mov_reg(s, 6, 1);
    agr_aot_mov_reg(s, 3, 4);
    agr_aot_branch_reg(s, 788368u | 1u, 789396u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0b94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[4] ? 789416u : 789398u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0b96(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 0u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[4], 1u);
    agr_aot_add_imm(s, 0, s->r[3], s->r[6]);
    s->r[15] = agr_aot_condition(s, 0u) ? 789420u : 789408u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0ba0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 1, 7);
    agr_aot_mov_reg(s, 2, 4);
    agr_aot_branch_reg(s, 289580u, 789416u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0ba8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    if ((rc = agr_aot_ldmia_sp(s, 33016u))) return rc;
}

static int aot_fast_000c0bac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 2, s->r[7] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 789424u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0bb2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 33016u))) return rc;
}

static int aot_fast_000c0bb4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16624u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 5, 0);
    { int rc = agr_aot_ldr(s, 4, s->r[5] + 0u); if (rc) return rc; }
    agr_aot_movw(s, 0, 65532u);
    s->r[0] = (s->r[0] & 0xffffu) | (16383u << 16);
    s->r[13] -= 12u;
    agr_aot_cmp(s, s->r[2], s->r[0]);
    agr_aot_mov_reg(s, 3, 1);
    agr_aot_mov_reg(s, 6, 2);
    { uint32_t addr = (s->r[4] - 12u); if ((rc = agr_aot_ldr(s, 7, addr))) return rc; }
    s->r[15] = agr_aot_condition(s, 8u) ? 789568u : 789456u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0bd0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[1], s->r[4]);
    s->r[15] = agr_aot_condition(s, 2u) ? 789476u : 789460u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0bd4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 2, 7);
    agr_aot_movs_imm(s, 1, 0u);
    agr_aot_branch_reg(s, 789380u | 1u, 789472u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0be0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 12u;
    if ((rc = agr_aot_ldmia_sp(s, 33008u))) return rc;
}

static int aot_fast_000c0be4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 0, s->r[4], s->r[7]);
    agr_aot_cmp(s, s->r[1], s->r[0]);
    s->r[15] = agr_aot_condition(s, 8u) ? 789460u : 789482u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0bea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = (s->r[4] - 4u); if ((rc = agr_aot_ldr(s, 0, addr))) return rc; }
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 12u) ? 789460u : 789490u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0bf2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 0, s->r[1], s->r[4]);
    agr_aot_cmp(s, s->r[2], s->r[0]);
    s->r[15] = agr_aot_condition(s, 8u) ? 789542u : 789496u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0bf8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[6], 1u);
    s->r[15] = agr_aot_condition(s, 0u) ? 789560u : 789500u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0bfc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 289580u, 789506u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0c02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 4, s->r[5] + 0u); if (rc) return rc; }
    s->r[15] = 789508u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0c04(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 789512u + 64u); if (rc) return rc; }
    s->r[15] = 789510u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0c0a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[3] += 789518u;
    agr_aot_cmp(s, s->r[2], s->r[3]);
    agr_aot_set_itstate(s, 31u); s->r[15] = 789520u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0c26(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 789508u : 789546u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0c2a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[6], 1u);
    s->r[15] = agr_aot_condition(s, 0u) ? 789560u : 789550u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0c2e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 289568u, 789556u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0c34(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 4, s->r[5] + 0u); if (rc) return rc; }
    s->r[15] = 789508u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0c38(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[3] + 0u); if (rc) return rc; }
    { uint32_t addr = s->r[4] + 0u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    { int rc = agr_aot_ldr(s, 4, s->r[5] + 0u); if (rc) return rc; }
    s->r[15] = 789508u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0c40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 789572u + 8u); if (rc) return rc; }
    s->r[0] += 789574u;
    agr_aot_branch_reg(s, 784148u | 1u, 789576u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0c4a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 2, s->r[0], 0u);
    s->r[15] = 789580u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0c4e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 1, s->r[0], 0u);
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    s->r[13] -= 8u;
    agr_aot_add_imm(s, 3, s->r[13], 8u);
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 789592u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0c60(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 789428u | 1u, 789604u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0c64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_000c0eac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16440u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 3, 1);
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 790194u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0eb4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[0] += s->r[2];
    agr_aot_mov_reg(s, 2, 3);
    agr_aot_branch_reg(s, 788088u | 1u, 790204u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0ebc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 5, 0);
    agr_aot_adds(s, 0, s->r[0], 12u);
    s->r[15] = !s->r[2] ? 790232u : 790212u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0ec4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 1u);
    agr_aot_add_imm(s, 3, s->r[5], 12u);
    s->r[15] = agr_aot_condition(s, 0u) ? 790250u : 790220u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0ecc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 3);
    agr_aot_add_imm(s, 1, s->r[4], 12u);
    agr_aot_branch_reg(s, 289580u, 790230u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0ed6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 790232u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0ed8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 790236u + 24u); if (rc) return rc; }
    s->r[3] += 790238u;
    agr_aot_cmp(s, s->r[5], s->r[3]);
    agr_aot_set_itstate(s, 31u); s->r[15] = 790240u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c0eea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 2, s->r[4] + 12u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 3);
    { uint32_t addr = s->r[5] + 12u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    { int rc = agr_aot_ldr(s, 2, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 790232u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1340(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[1] + 0u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    { uint32_t addr = (s->r[3] - 4u); if ((rc = agr_aot_ldr(s, 2, addr))) return rc; }
    s->r[13] -= 8u;
    s->r[15] = 791372u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1350(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 0u);
    s->r[15] = agr_aot_condition(s, 11u) ? 791398u : 791380u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1354(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, 791384u + 56u); if (rc) return rc; }
    s->r[2] += 791386u;
    agr_aot_cmp(s, s->r[0], s->r[2]);
    s->r[15] = agr_aot_condition(s, 1u) ? 791414u : 791388u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c135c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 3);
    { uint32_t addr = s->r[4] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_mov_reg(s, 0, 4);
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_000c1366(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_branch_reg(s, 790188u | 1u, 791406u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c136e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_mov_reg(s, 0, 4);
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_000c1376(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 2, s->r[3], 4u);
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = 791420u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1380(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 0, s->r[0], 1u);
    s->r[15] = 791426u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1386(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[1], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 791420u : 791434u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c138a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = 791388u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1564(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], s->r[1]);
    agr_aot_mov_reg(s, 3, 1);
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = agr_aot_condition(s, 0u) ? 791990u : 791918u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c156e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[0] ? 792000u : 791920u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1570(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 6, s->r[1], s->r[0]);
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = 791924u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1574(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 788088u | 1u, 791930u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c157a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[6], 1u);
    agr_aot_mov_reg(s, 5, 0);
    agr_aot_add_imm(s, 3, s->r[0], 12u);
    s->r[15] = agr_aot_condition(s, 1u) ? 791976u : 791940u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1584(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 2, s->r[4] + 0u); if (rc) return rc; }
    { uint32_t addr = s->r[5] + 12u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    s->r[15] = 791944u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1588(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, 791948u + 64u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 3);
    s->r[2] += 791952u;
    agr_aot_cmp(s, s->r[5], s->r[2]);
    agr_aot_set_itstate(s, 31u); s->r[15] = 791954u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c159c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 788088u | 1u, 791968u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c15a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 6, 4);
    agr_aot_add_imm(s, 3, s->r[0], 12u);
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 791976u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c15a8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 3);
    agr_aot_mov_reg(s, 1, 4);
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_branch_reg(s, 289580u, 791986u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c15b2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 3, 0);
    s->r[15] = 791944u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c15b6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 791992u + 24u); if (rc) return rc; }
    s->r[3] += 791996u;
    agr_aot_adds(s, 3, s->r[3], 12u);
    agr_aot_mov_reg(s, 0, 3);
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_000c15c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 791964u : 792004u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c15c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 792008u + 12u); if (rc) return rc; }
    s->r[0] += 792010u;
    s->r[15] = 792008u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c15c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 783872u | 1u, 792012u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c15cc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = agr_aot_condition(s, 5u) ? 792008u : 792014u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c15ce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 2, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 5u) ? 791924u : 792018u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c15d2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 2, s->r[0], 0u);
    { int rc = agr_aot_ldrh(s, 2, s->r[3] + 58u); if (rc) return rc; }
    agr_aot_lsls(s, 1, s->r[0], 0u);
    s->r[15] = 792024u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c15d8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 6, 0);
    { int rc = agr_aot_ldr(s, 4, s->r[1] + 0u); if (rc) return rc; }
    s->r[13] -= 8u;
    { uint32_t addr = (s->r[4] - 12u); if ((rc = agr_aot_ldr(s, 5, addr))) return rc; }
    agr_aot_cmp(s, s->r[2], s->r[5]);
    s->r[15] = agr_aot_condition(s, 8u) ? 792072u : 792040u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c15e8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 5, s->r[5], s->r[2]);
    agr_aot_adds(s, 0, s->r[4], s->r[2]);
    agr_aot_cmp(s, s->r[5], s->r[3]);
    agr_aot_set_itstate(s, 148u); s->r[15] = 792048u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1608(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 792076u + 4u); if (rc) return rc; }
    s->r[0] += 792078u;
    agr_aot_branch_reg(s, 784240u | 1u, 792080u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1612(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 1, s->r[0], 0u);
    if (agr_aot_stmdb_sp(s, 16440u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 5, 0);
    { int rc = agr_aot_ldr(s, 4, s->r[1] + 0u); if (rc) return rc; }
    { uint32_t addr = (s->r[4] - 12u); if ((rc = agr_aot_ldr(s, 4, addr))) return rc; }
    agr_aot_cmp(s, s->r[2], s->r[4]);
    s->r[15] = agr_aot_condition(s, 8u) ? 792106u : 792098u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1622(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 792024u | 1u, 792102u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1626(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    if ((rc = agr_aot_ldmia_sp(s, 32824u))) return rc;
}

static int aot_fast_000c162a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 792108u + 8u); if (rc) return rc; }
    s->r[0] += 792112u;
    agr_aot_branch_reg(s, 784240u | 1u, 792114u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1636(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 1, s->r[0], 0u);
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 6, 0);
    { int rc = agr_aot_ldr(s, 4, s->r[1] + 0u); if (rc) return rc; }
    { uint32_t addr = (s->r[4] - 12u); if ((rc = agr_aot_ldr(s, 5, addr))) return rc; }
    agr_aot_cmp(s, s->r[2], s->r[5]);
    s->r[15] = agr_aot_condition(s, 8u) ? 792164u : 792134u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1646(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 5, s->r[5], s->r[2]);
    agr_aot_adds(s, 0, s->r[4], s->r[2]);
    agr_aot_cmp(s, s->r[5], s->r[3]);
    agr_aot_set_itstate(s, 148u); s->r[15] = 792142u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1650(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 1, s->r[2], s->r[3]);
    { int rc = agr_aot_ldr(s, 2, s->r[13] + 16u); if (rc) return rc; }
    s->r[1] += s->r[4];
    s->r[3] = 0u;
    agr_aot_branch_reg(s, 791908u | 1u, 792158u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c165e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[6] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_mov_reg(s, 0, 6);
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_000c1664(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 792168u + 4u); if (rc) return rc; }
    s->r[0] += 792170u;
    agr_aot_branch_reg(s, 784240u | 1u, 792172u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c166e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 1, s->r[0], 0u);
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_mov_reg(s, 0, 1);
    agr_aot_mov_reg(s, 1, 2);
    agr_aot_mov_reg(s, 2, 3);
    s->r[3] = 0u;
    agr_aot_branch_reg(s, 791908u | 1u, 792194u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1682(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_mov_reg(s, 0, 4);
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_000c1688(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], s->r[1]);
    agr_aot_mov_reg(s, 3, 1);
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = agr_aot_condition(s, 0u) ? 792282u : 792210u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1692(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[0] ? 792292u : 792212u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1694(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 6, s->r[1], s->r[0]);
    agr_aot_movs_imm(s, 1, 0u);
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 788088u | 1u, 792222u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c169e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[6], 1u);
    agr_aot_mov_reg(s, 5, 0);
    agr_aot_add_imm(s, 3, s->r[0], 12u);
    s->r[15] = agr_aot_condition(s, 1u) ? 792268u : 792232u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c16a4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 4, s->r[1], 12u);
    s->r[15] = agr_aot_condition(s, 1u) ? 792268u : 792232u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c16a8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 2, s->r[4] + 0u); if (rc) return rc; }
    { uint32_t addr = s->r[5] + 12u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    s->r[15] = 792236u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c16ac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, 792240u + 64u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 3);
    s->r[2] += 792244u;
    agr_aot_cmp(s, s->r[5], s->r[2]);
    agr_aot_set_itstate(s, 31u); s->r[15] = 792246u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c16c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 788088u | 1u, 792260u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c16c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 6, 4);
    agr_aot_add_imm(s, 3, s->r[0], 12u);
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 792268u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c16cc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 3);
    agr_aot_mov_reg(s, 1, 4);
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_branch_reg(s, 289580u, 792278u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c16d6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 3, 0);
    s->r[15] = 792236u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c16da(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 792284u + 24u); if (rc) return rc; }
    s->r[3] += 792288u;
    agr_aot_adds(s, 3, s->r[3], 12u);
    agr_aot_mov_reg(s, 0, 3);
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_000c16e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 792256u : 792296u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c16e8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 792300u + 12u); if (rc) return rc; }
    s->r[0] += 792302u;
    agr_aot_branch_reg(s, 783872u | 1u, 792304u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c16f0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = agr_aot_condition(s, 4u) ? 792228u : 792306u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c16f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 2, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 4u) ? 792144u : 792310u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c16f6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 2, s->r[0], 0u);
    { int rc = agr_aot_ldrh(s, 6, s->r[6] + 48u); if (rc) return rc; }
    agr_aot_lsls(s, 1, s->r[0], 0u);
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_mov_reg(s, 0, 1);
    s->r[1] += s->r[2];
    agr_aot_mov_reg(s, 2, 3);
    s->r[3] = 0u;
    agr_aot_branch_reg(s, 792200u | 1u, 792334u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c170e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_mov_reg(s, 0, 4);
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_000c194c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 1);
    agr_aot_mov_reg(s, 5, 0);
    agr_aot_mov_reg(s, 6, 2);
    s->r[1] = 4294967295u;
    s->r[15] = !s->r[4] ? 792930u : 792922u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c195a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 289652u, 792928u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1960(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 1, s->r[4], s->r[0]);
    s->r[15] = 792930u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1962(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_mov_reg(s, 2, 6);
    s->r[3] = 0u;
    agr_aot_branch_reg(s, 792200u | 1u, 792942u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c196e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[5] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_mov_reg(s, 0, 5);
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_000c1c80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 17392u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 5, 0);
    { int rc = agr_aot_ldr(s, 4, s->r[0] + 0u); if (rc) return rc; }
    s->r[13] -= 20u;
    s->r[4] = s->r[4] & 1u;
    s->r[15] = s->r[4] ? 793832u : 793744u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1c90(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 3, 1u);
    agr_aot_mov_reg(s, 6, 4);
    s->r[15] = 793748u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1ca0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 8, s->r[13], 12u);
    agr_aot_mov_reg(s, 7, 4);
    s->r[15] = 793766u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1ca6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[13] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = 793772u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1cb0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], s->r[7]);
    s->r[15] = agr_aot_condition(s, 1u) ? 793788u : 793780u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1cb8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[1], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 793772u : 793788u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1cbc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = agr_aot_condition(s, 1u) ? 793804u : 793794u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1cc2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 4, 1u);
    s->r[15] = 793796u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1cc4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    s->r[13] += 20u;
    if ((rc = agr_aot_ldmia_sp(s, 33776u))) return rc;
}

static int aot_fast_000c1ccc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 1u);
    { uint32_t addr = s->r[8] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = agr_aot_condition(s, 0u) ? 793796u : 793812u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1cd4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], s->r[6]);
    s->r[15] = agr_aot_condition(s, 0u) ? 793842u : 793816u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1cd8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    agr_aot_mov_reg(s, 1, 5);
    agr_aot_movs_imm(s, 2, 0u);
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 12u); if (rc) return rc; }
    agr_aot_movs_imm(s, 0, 240u);
    agr_aot_branch_reg(s, 291308u, 793830u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1ce6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 793766u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1ce8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 4, 0u);
    agr_aot_mov_reg(s, 0, 4);
    s->r[13] += 20u;
    if ((rc = agr_aot_ldmia_sp(s, 33776u))) return rc;
}

static int aot_fast_000c1cf2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = 793846u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1cfa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], s->r[3]);
    s->r[15] = agr_aot_condition(s, 1u) ? 793862u : 793854u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1d02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[1], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 793846u : 793862u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1d06(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = agr_aot_condition(s, 0u) ? 793876u : 793868u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1d0c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 1u);
    s->r[15] = agr_aot_condition(s, 0u) ? 793796u : 793872u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1d10(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 793766u : 793876u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1d14(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[13] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[9]); }
    s->r[15] = 793816u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1d5c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_movs_imm(s, 2, 1u);
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = 793958u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1d72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[4], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 793962u : 793974u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1d78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = agr_aot_condition(s, 1u) ? 793984u : 793982u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1d7e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_000c1d80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 1, 0);
    s->r[15] = 793986u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1d86(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 240u);
    agr_aot_branch_reg(s, 291308u, 793996u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1d8c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_000c1dd8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    agr_aot_movs_imm(s, 0, 4u);
    agr_aot_branch_reg(s, 602296u | 1u, 794080u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1de0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 794084u + 24u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, 794084u + 28u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, 794088u + 28u); if (rc) return rc; }
    s->r[3] += 794090u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_adds(s, 3, s->r[3], 8u);
    s->r[1] += 794096u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[2] += 794100u;
    { int rc = agr_aot_ldr(s, 2, s->r[2] + 0u); if (rc) return rc; }
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 600912u | 1u, 794106u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1dfe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 2, s->r[0], 0u);
    s->r[15] = 794112u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1e02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 2, s->r[0], 0u);
    s->r[15] = 794116u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1e06(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 2, s->r[0], 0u);
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    agr_aot_movs_imm(s, 0, 4u);
    agr_aot_branch_reg(s, 602296u | 1u, 794128u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1e10(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 794132u + 24u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, 794132u + 28u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, 794136u + 28u); if (rc) return rc; }
    s->r[3] += 794138u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_adds(s, 3, s->r[3], 8u);
    s->r[1] += 794144u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[2] += 794148u;
    { int rc = agr_aot_ldr(s, 2, s->r[2] + 0u); if (rc) return rc; }
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 600912u | 1u, 794154u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1e2e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 2, s->r[0], 0u);
    s->r[15] = 794160u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1e32(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 2, s->r[0], 0u);
    s->r[15] = 794164u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1e36(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 2, s->r[0], 0u);
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1e3c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 1u);
    s->r[15] = 794174u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1e42(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    { uint32_t addr = (s->r[1] - 32u); if ((rc = agr_aot_ldr(s, 4, addr))) return rc; }
    s->r[15] = agr_aot_condition(s, 8u) ? 794242u : 794186u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1e4a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 3);
    agr_aot_branch_reg(s, 602700u | 1u, 794192u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1e54(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = 794200u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1e5c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 2, s->r[2], 1u);
    s->r[15] = 794206u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1e62(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[1], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 794200u : 794214u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1e66(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = s->r[2] ? 794240u : 794220u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1e6c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = (s->r[4] - 116u); if ((rc = agr_aot_ldr(s, 3, addr))) return rc; }
    s->r[15] = !s->r[3] ? 794230u : 794226u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1e72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, s->r[3], 794230u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1e76(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    if ((rc = agr_aot_ldmia_sp(s, 16400u))) return rc;
    s->r[15] = 602448u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1e80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_000c1e82(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = (s->r[4] - 108u); if ((rc = agr_aot_ldr(s, 0, addr))) return rc; }
    agr_aot_branch_reg(s, 601932u | 1u, 794250u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1e8c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1e94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16u)) return AGR_AOT_FAULT;
    s->r[13] -= 12u;
    agr_aot_add_imm(s, 4, s->r[13], 8u);
    s->r[15] = 794266u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1e9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[13] += 12u;
    { uint32_t addr = s->r[13]; s->r[13] = s->r[13] + 4u; if ((rc = agr_aot_ldr(s, 4, addr))) return rc; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1eac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = !s->r[3] ? 794312u : 794288u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1eb0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 3, s->r[3], 128u);
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = 794294u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1eba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 1, s->r[1], 1u);
    s->r[15] = 794300u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1ec0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 794294u : 794308u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1ec4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    atomic_thread_fence(memory_order_seq_cst);
    s->r[15] = 794312u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1ec8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1ecc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    agr_aot_branch_reg(s, 794284u | 1u, 794326u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c1ed6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 4);
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_000c2174(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16632u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    { int rc = agr_aot_ldr(s, 5, s->r[0] + 8u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[5], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 795108u : 795006u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c217e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 795008u + 152u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 46u);
    { uint32_t addr = s->r[5] + 36u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    agr_aot_movs_imm(s, 2, 0u);
    { int rc = agr_aot_ldr(s, 6, s->r[4] + 8u); if (rc) return rc; }
    s->r[1] += 795022u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 7, 795024u + 140u); if (rc) return rc; }
    agr_aot_mov_reg(s, 3, 2);
    { int rc = agr_aot_ldr(s, 0, s->r[1] + 0u); if (rc) return rc; }
    agr_aot_movs_imm(s, 1, 44u);
    s->r[7] += 795034u;
    { uint32_t addr = s->r[5] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[5] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[5] + 16u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    { uint32_t addr = s->r[6] + 37u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[1]); }
    s->r[15] = 795042u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c21a2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[4] + 8u); if (rc) return rc; }
    { int rc = agr_aot_ldrb(s, 1, s->r[0] + s->r[3]); if (rc) return rc; }
    s->r[2] += s->r[3];
    agr_aot_adds(s, 3, s->r[3], 1u);
    agr_aot_cmp(s, s->r[3], 36u);
    { uint32_t addr = s->r[2] + 38u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[1]); }
    s->r[15] = agr_aot_condition(s, 1u) ? 795042u : 795058u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c21b2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, 795060u + 108u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 0u);
    s->r[2] += 795066u;
    { int rc = agr_aot_ldr(s, 2, s->r[2] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 0, s->r[2] + 0u); if (rc) return rc; }
    s->r[15] = 795068u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c21bc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[4] + 8u); if (rc) return rc; }
    { int rc = agr_aot_ldrb(s, 1, s->r[0] + s->r[3]); if (rc) return rc; }
    s->r[2] += s->r[3];
    agr_aot_adds(s, 3, s->r[3], 1u);
    agr_aot_cmp(s, s->r[3], 26u);
    { uint32_t addr = s->r[2] + 74u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[1]); }
    s->r[15] = agr_aot_condition(s, 1u) ? 795068u : 795084u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c21cc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 8u); if (rc) return rc; }
    agr_aot_movs_imm(s, 2, 5u);
    { int rc = agr_aot_ldr(s, 0, 795092u + 80u); if (rc) return rc; }
    agr_aot_movs_imm(s, 4, 4u);
    { int rc = agr_aot_ldr(s, 1, 795096u + 80u); if (rc) return rc; }
    s->r[0] += 795098u;
    { uint32_t addr = s->r[3] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    s->r[1] += 795102u;
    { uint32_t addr = s->r[3] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    { uint32_t addr = s->r[3] + 28u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { uint32_t addr = s->r[3] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    if ((rc = agr_aot_ldmia_sp(s, 33016u))) return rc;
}

static int aot_fast_000c21e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 104u);
    agr_aot_branch_reg(s, 599660u | 1u, 795114u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c21ea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 795116u + 64u); if (rc) return rc; }
    s->r[3] += 795120u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_adds(s, 3, s->r[3], 8u);
    { uint32_t addr = s->r[0] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 16u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 28u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 36u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 37u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 100u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[5]); }
    agr_aot_mov_reg(s, 5, 0);
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[4] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 795006u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c2230(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16632u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 5, 0);
    { int rc = agr_aot_ldr(s, 4, s->r[0] + 8u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[4], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 795288u : 795194u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c223a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 795196u + 140u); if (rc) return rc; }
    agr_aot_movs_imm(s, 1, 0u);
    { int rc = agr_aot_ldr(s, 7, 795200u + 140u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 4);
    s->r[0] += 795206u;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 3, 1);
    s->r[7] += 795212u;
    { uint32_t addr = s->r[4] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_movs_imm(s, 6, 46u);
    agr_aot_movs_imm(s, 5, 44u);
    { uint32_t addr = s->r[4] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[1]); }
    { uint32_t addr = s->r[4] + 36u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = (s->r[2] + 40u); s->r[2] = s->r[2] + 40u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    s->r[15] = 795228u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c225c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 1, s->r[0] + s->r[3]); if (rc) return rc; }
    agr_aot_adds(s, 3, s->r[3], 1u);
    agr_aot_cmp(s, s->r[3], 36u);
    { uint32_t addr = (s->r[2] + 4u); s->r[2] = s->r[2] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    s->r[15] = agr_aot_condition(s, 1u) ? 795228u : 795240u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c2268(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 795244u + 100u); if (rc) return rc; }
    agr_aot_add_imm(s, 2, s->r[4], 184u);
    agr_aot_movs_imm(s, 3, 0u);
    s->r[1] += 795252u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 0, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 795254u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c2276(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 1, s->r[0] + s->r[3]); if (rc) return rc; }
    agr_aot_adds(s, 3, s->r[3], 1u);
    agr_aot_cmp(s, s->r[3], 26u);
    { uint32_t addr = (s->r[2] + 4u); s->r[2] = s->r[2] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    s->r[15] = agr_aot_condition(s, 1u) ? 795254u : 795266u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c2282(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, 795268u + 80u); if (rc) return rc; }
    agr_aot_movs_imm(s, 0, 4u);
    { int rc = agr_aot_ldr(s, 2, 795272u + 80u); if (rc) return rc; }
    agr_aot_movs_imm(s, 3, 5u);
    s->r[1] += 795278u;
    { uint32_t addr = s->r[4] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[2] += 795282u;
    { uint32_t addr = s->r[4] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { uint32_t addr = s->r[4] + 28u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[4] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    if ((rc = agr_aot_ldmia_sp(s, 33016u))) return rc;
}

static int aot_fast_000c2298(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[0] = 296u;
    agr_aot_branch_reg(s, 599660u | 1u, 795296u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c22a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 795300u + 56u); if (rc) return rc; }
    s->r[3] += 795302u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_adds(s, 3, s->r[3], 8u);
    { uint32_t addr = s->r[0] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 16u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 28u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 36u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 40u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 292u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[4]); }
    agr_aot_mov_reg(s, 4, 0);
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[5] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 795194u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c2448(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16632u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    { int rc = agr_aot_ldr(s, 5, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = !s->r[5] ? 795806u : 795728u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c2450(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 795732u + 160u); if (rc) return rc; }
    agr_aot_movs_imm(s, 2, 46u);
    { uint32_t addr = s->r[5] + 17u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    agr_aot_movs_imm(s, 6, 44u);
    { int rc = agr_aot_ldr(s, 2, s->r[4] + 8u); if (rc) return rc; }
    s->r[3] += 795742u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 5, 795744u + 152u); if (rc) return rc; }
    agr_aot_movs_imm(s, 1, 0u);
    { int rc = agr_aot_ldr(s, 0, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 3, 1);
    { uint32_t addr = s->r[2] + 18u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[6]); }
    s->r[5] += 795756u;
    { int rc = agr_aot_ldr(s, 5, s->r[5] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, s->r[4] + 8u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 5, s->r[5] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 795764u + 136u); if (rc) return rc; }
    { uint32_t addr = s->r[2] + 48u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    { int rc = agr_aot_ldr(s, 7, s->r[4] + 8u); if (rc) return rc; }
    s->r[6] += 795770u;
    { uint32_t addr = s->r[2] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { uint32_t addr = s->r[2] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[2] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[2] + 28u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[2] + 36u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[2] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { uint32_t addr = s->r[2] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { uint32_t addr = s->r[2] + 40u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { uint32_t addr = s->r[2] + 44u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { uint32_t addr = s->r[7] + 52u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 795788u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c248c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[4] + 8u); if (rc) return rc; }
    { int rc = agr_aot_ldrb(s, 1, s->r[5] + s->r[3]); if (rc) return rc; }
    s->r[2] += s->r[3];
    agr_aot_adds(s, 3, s->r[3], 1u);
    agr_aot_cmp(s, s->r[3], 11u);
    { uint32_t addr = s->r[2] + 56u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[1]); }
    s->r[15] = agr_aot_condition(s, 1u) ? 795788u : 795804u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c249c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 33016u))) return rc;
}

static int aot_fast_000c249e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 68u);
    agr_aot_branch_reg(s, 599660u | 1u, 795812u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c24a4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 795816u + 88u); if (rc) return rc; }
    s->r[3] += 795818u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_adds(s, 3, s->r[3], 8u);
    { uint32_t addr = s->r[0] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 16u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 17u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 18u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 28u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 36u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 40u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 44u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 48u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 49u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 50u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 51u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 52u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 53u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 54u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 55u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 67u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[5]); }
    agr_aot_mov_reg(s, 5, 0);
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[4] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 795728u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c2504(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16632u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    { int rc = agr_aot_ldr(s, 5, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = !s->r[5] ? 795994u : 795916u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c250c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 795920u + 160u); if (rc) return rc; }
    agr_aot_movs_imm(s, 2, 46u);
    { uint32_t addr = s->r[5] + 17u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[2]); }
    agr_aot_movs_imm(s, 6, 44u);
    { int rc = agr_aot_ldr(s, 2, s->r[4] + 8u); if (rc) return rc; }
    s->r[3] += 795930u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 5, 795932u + 152u); if (rc) return rc; }
    agr_aot_movs_imm(s, 1, 0u);
    { int rc = agr_aot_ldr(s, 0, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 3, 1);
    { uint32_t addr = s->r[2] + 18u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[6]); }
    s->r[5] += 795944u;
    { int rc = agr_aot_ldr(s, 5, s->r[5] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, s->r[4] + 8u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 5, s->r[5] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 795952u + 136u); if (rc) return rc; }
    { uint32_t addr = s->r[2] + 48u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    { int rc = agr_aot_ldr(s, 7, s->r[4] + 8u); if (rc) return rc; }
    s->r[6] += 795958u;
    { uint32_t addr = s->r[2] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { uint32_t addr = s->r[2] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[2] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[2] + 28u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[2] + 36u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[2] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { uint32_t addr = s->r[2] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { uint32_t addr = s->r[2] + 40u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { uint32_t addr = s->r[2] + 44u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { uint32_t addr = s->r[7] + 52u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 795976u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c2548(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[4] + 8u); if (rc) return rc; }
    { int rc = agr_aot_ldrb(s, 1, s->r[5] + s->r[3]); if (rc) return rc; }
    s->r[2] += s->r[3];
    agr_aot_adds(s, 3, s->r[3], 1u);
    agr_aot_cmp(s, s->r[3], 11u);
    { uint32_t addr = s->r[2] + 56u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[1]); }
    s->r[15] = agr_aot_condition(s, 1u) ? 795976u : 795992u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c2558(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 33016u))) return rc;
}

static int aot_fast_000c255a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 68u);
    agr_aot_branch_reg(s, 599660u | 1u, 796000u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c2560(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 796004u + 88u); if (rc) return rc; }
    s->r[3] += 796006u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_adds(s, 3, s->r[3], 8u);
    { uint32_t addr = s->r[0] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 16u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 17u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 18u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 28u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 36u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 40u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 44u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 48u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 49u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 50u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 51u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 52u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 53u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 54u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 55u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[5]); }
    { uint32_t addr = s->r[0] + 67u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[5]); }
    agr_aot_mov_reg(s, 5, 0);
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[4] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 795916u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c25c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16880u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 5, 0);
    { int rc = agr_aot_ldr(s, 4, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = !s->r[4] ? 796194u : 796106u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c25ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 796108u + 172u); if (rc) return rc; }
    agr_aot_movs_imm(s, 2, 0u);
    { int rc = agr_aot_ldr(s, 7, 796112u + 172u); if (rc) return rc; }
    s->r[8] = 46u;
    s->r[3] += 796120u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, 796124u + 164u); if (rc) return rc; }
    s->r[7] += 796126u;
    { uint32_t addr = s->r[4] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { int rc = agr_aot_ldr(s, 0, s->r[3] + 0u); if (rc) return rc; }
    s->r[1] += 796132u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 796136u + 156u); if (rc) return rc; }
    s->r[12] = 44u;
    agr_aot_mov_reg(s, 3, 2);
    { uint32_t addr = s->r[4] + 56u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[6] += 796146u;
    { int rc = agr_aot_ldr(s, 7, s->r[5] + 8u); if (rc) return rc; }
    { uint32_t addr = s->r[4] + 28u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[4] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[4] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[4] + 40u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[4] + 48u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[4] + 52u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[4] + 36u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[4] + 44u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[4] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    { uint32_t addr = s->r[4] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[12]); }
    { uint32_t addr = s->r[7] + 60u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    { int rc = agr_aot_ldr(s, 4, s->r[1] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, s->r[5] + 8u); if (rc) return rc; }
    s->r[15] = 796176u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c2610(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 1, s->r[4] + s->r[3]); if (rc) return rc; }
    agr_aot_adds(s, 3, s->r[3], 1u);
    agr_aot_cmp(s, s->r[3], 11u);
    agr_aot_add_imm(s, 2, s->r[2], 4u);
    { uint32_t addr = s->r[2] + 60u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    s->r[15] = agr_aot_condition(s, 1u) ? 796176u : 796190u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c261e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) return rc;
}

static int aot_fast_000c2622(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 112u);
    agr_aot_branch_reg(s, 599660u | 1u, 796200u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c2628(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 796204u + 92u); if (rc) return rc; }
    s->r[3] += 796206u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_adds(s, 3, s->r[3], 8u);
    { uint32_t addr = s->r[0] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 16u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 28u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 36u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 40u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 44u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 48u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 52u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 56u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 57u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 58u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 59u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 60u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 61u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 62u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 63u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 108u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[4]); }
    agr_aot_mov_reg(s, 4, 0);
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[5] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 796106u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c268c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16880u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 5, 0);
    { int rc = agr_aot_ldr(s, 4, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = !s->r[4] ? 796398u : 796310u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c2696(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 796312u + 172u); if (rc) return rc; }
    agr_aot_movs_imm(s, 2, 0u);
    { int rc = agr_aot_ldr(s, 7, 796316u + 172u); if (rc) return rc; }
    s->r[8] = 46u;
    s->r[3] += 796324u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 1, 796328u + 164u); if (rc) return rc; }
    s->r[7] += 796330u;
    { uint32_t addr = s->r[4] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[7]); }
    { int rc = agr_aot_ldr(s, 0, s->r[3] + 0u); if (rc) return rc; }
    s->r[1] += 796336u;
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 6, 796340u + 156u); if (rc) return rc; }
    s->r[12] = 44u;
    agr_aot_mov_reg(s, 3, 2);
    { uint32_t addr = s->r[4] + 56u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[6] += 796350u;
    { int rc = agr_aot_ldr(s, 7, s->r[5] + 8u); if (rc) return rc; }
    { uint32_t addr = s->r[4] + 28u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[4] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[4] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[4] + 40u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[4] + 48u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[4] + 52u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    { uint32_t addr = s->r[4] + 36u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[4] + 44u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[6]); }
    { uint32_t addr = s->r[4] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    { uint32_t addr = s->r[4] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[12]); }
    { uint32_t addr = s->r[7] + 60u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    { int rc = agr_aot_ldr(s, 4, s->r[1] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, s->r[5] + 8u); if (rc) return rc; }
    s->r[15] = 796380u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c26dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 1, s->r[4] + s->r[3]); if (rc) return rc; }
    agr_aot_adds(s, 3, s->r[3], 1u);
    agr_aot_cmp(s, s->r[3], 11u);
    agr_aot_add_imm(s, 2, s->r[2], 4u);
    { uint32_t addr = s->r[2] + 60u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    s->r[15] = agr_aot_condition(s, 1u) ? 796380u : 796394u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c26ea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) return rc;
}

static int aot_fast_000c26ee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 112u);
    agr_aot_branch_reg(s, 599660u | 1u, 796404u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c26f4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 796408u + 92u); if (rc) return rc; }
    s->r[3] += 796410u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_adds(s, 3, s->r[3], 8u);
    { uint32_t addr = s->r[0] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 16u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 24u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 28u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 36u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 40u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 44u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 48u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 52u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 56u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 57u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 58u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 59u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 60u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 61u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 62u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 63u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[4]); }
    { uint32_t addr = s->r[0] + 108u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[4]); }
    agr_aot_mov_reg(s, 4, 0);
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { uint32_t addr = s->r[5] + 8u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 796310u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9a64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_lsls(s, 2, s->r[3], 1u);
    agr_aot_set_itstate(s, 76u); s->r[15] = 825962u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9a76(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 20471u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 9, 0);
    agr_aot_mov_reg(s, 6, 2);
    s->r[15] = !s->r[1] ? 826058u : 825984u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9a80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 8, s->r[1], 1023u);
    agr_aot_movs_imm(s, 7, 0u);
    agr_aot_mov_reg(s, 10, 8);
    s->r[15] = 825992u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9a88(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 4, s->r[7], s->r[10]);
    s->r[15] = 825996u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9a92(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 3, s->r[4], 3u);
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_add_imm(s, 5, s->r[9], s->r[3]);
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_branch_reg(s, 825956u | 1u, 826016u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9aa0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[4], s->r[8]);
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 4u); if (rc) return rc; }
    agr_aot_mov_reg(s, 11, 0);
    s->r[15] = agr_aot_condition(s, 0u) ? 826066u : 826024u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9aa8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 0, s->r[3], 8u);
    s->r[0] += s->r[9];
    agr_aot_branch_reg(s, 825956u | 1u, 826034u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9ab2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[6], s->r[11]);
    s->r[15] = agr_aot_condition(s, 2u) ? 826048u : 826038u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9ab6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[4], s->r[7]);
    s->r[15] = agr_aot_condition(s, 0u) ? 826062u : 826042u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9aba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 10, s->r[4], 1023u);
    s->r[15] = 825992u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9ac0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 0, s->r[0], 1u);
    agr_aot_cmp(s, s->r[6], s->r[0]);
    s->r[15] = agr_aot_condition(s, 9u) ? 826070u : 826054u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9ac6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 7, s->r[4], 1u);
    s->r[15] = 825992u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9aca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 5, 1);
    s->r[15] = 826070u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9ace(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 5, 0u);
    s->r[15] = 826070u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9ad2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[6], s->r[0]);
    s->r[15] = agr_aot_condition(s, 3u) ? 826038u : 826070u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9ad6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[13] += 12u;
    if ((rc = agr_aot_ldmia_sp(s, 36848u))) return rc;
}

static int aot_fast_000c9ade(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 1u);
    s->r[15] = agr_aot_condition(s, 0u) ? 826096u : 826082u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9ae2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 2u);
    s->r[15] = agr_aot_condition(s, 0u) ? 826104u : 826086u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9ae6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = s->r[0] ? 826112u : 826088u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9ae8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 826092u + 24u); if (rc) return rc; }
    s->r[0] += 826094u;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9af0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 826100u + 20u); if (rc) return rc; }
    s->r[0] += 826102u;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9af8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, 826108u + 16u); if (rc) return rc; }
    s->r[0] += 826110u;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9b00(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9b04(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 827260u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9b10(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, 826132u + 148u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16499u)) return AGR_AOT_FAULT;
    s->r[3] += 826136u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_subs(s, 6, s->r[1], 2u);
    s->r[15] = !s->r[3] ? 826156u : 826142u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9b1e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    agr_aot_branch_reg(s, 291464u, 826150u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9b26(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = s->r[5] ? 826176u : 826154u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9b2a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 826188u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9b2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 5, 826160u + 124u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, 826160u + 128u); if (rc) return rc; }
    s->r[5] += 826164u;
    { int rc = agr_aot_ldr(s, 5, s->r[5] + 0u); if (rc) return rc; }
    s->r[3] += 826168u;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    agr_aot_subs(s, 5, s->r[5], s->r[3]);
    agr_aot_mov_reg(s, 0, 3);
    s->r[15] = 826172u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9b3e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    s->r[15] = 826176u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9b40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 4u); if (rc) return rc; }
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_branch_reg(s, 825974u | 1u, 826184u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9b48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = s->r[0] ? 826194u : 826188u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9b4c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    agr_aot_movs_imm(s, 0, 9u);
    s->r[15] = 826274u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9b52(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 825956u | 1u, 826198u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9b56(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 4u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 1u);
    { uint32_t addr = s->r[4] + 72u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = agr_aot_condition(s, 1u) ? 826214u : 826206u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9b5e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    agr_aot_movs_imm(s, 0, 5u);
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 826274u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9b66(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 0u);
    agr_aot_add_imm(s, 0, s->r[5], 4u);
    s->r[15] = agr_aot_condition(s, 10u) ? 826228u : 826222u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9b6e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 76u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_movs_imm(s, 3, 1u);
    s->r[15] = 826236u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9b74(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 825956u | 1u, 826232u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9b78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 3, 0u);
    { uint32_t addr = s->r[4] + 76u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 826236u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9b7c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[4] + 76u); if (rc) return rc; }
    { uint32_t addr = s->r[4] + 80u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], 0u);
    s->r[15] = agr_aot_condition(s, 10u) ? 826266u : 826246u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9b8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 826078u | 1u, 826254u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9b8e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_cmp(s, s->r[0], 0u);
    agr_aot_set_itstate(s, 12u); s->r[15] = 826260u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9b9a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 825956u | 1u, 826270u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9b9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = 826274u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9ba2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 8u;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) return rc;
}

static int aot_fast_000c9bb4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16400u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    agr_aot_lsls(s, 0, s->r[3], 31u);
    s->r[15] = agr_aot_condition(s, 4u) ? 826322u : 826302u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9bc2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 72u);
    s->r[15] = agr_aot_condition(s, 0u) ? 826318u : 826312u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9bc8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 828368u | 1u, 826316u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9bcc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 826322u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9bce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 828352u | 1u, 826322u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9bd2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_lsls(s, 1, s->r[3], 29u);
    s->r[15] = agr_aot_condition(s, 4u) ? 826336u : 826328u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9bd8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 208u);
    agr_aot_branch_reg(s, 828384u | 1u, 826336u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9be0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_lsls(s, 2, s->r[3], 28u);
    s->r[15] = agr_aot_condition(s, 4u) ? 826350u : 826342u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9be6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 4008u);
    agr_aot_branch_reg(s, 828400u | 1u, 826350u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9bee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    agr_aot_lsls(s, 3, s->r[3], 27u);
    s->r[15] = agr_aot_condition(s, 4u) ? 826368u : 826356u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9bf4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 0, s->r[4], 4072u);
    if ((rc = agr_aot_ldmia_sp(s, 16400u))) return rc;
    s->r[15] = 828536u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9c00(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_000c9c02(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = !s->r[3] ? 826378u : 826374u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9c06(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[3] + s->r[0]); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9c0a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 3);
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9c0e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 9u);
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9c12(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9c14(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 5, 0);
    agr_aot_mov_reg(s, 4, 1);
    s->r[15] = 826394u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9c1a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 64u); if (rc) return rc; }
    agr_aot_branch_reg(s, 826128u | 1u, 826402u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9c22(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 6, 0);
    s->r[15] = !s->r[0] ? 826410u : 826406u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9c26(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 290804u, 826410u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9c2a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 64u); if (rc) return rc; }
    agr_aot_movs_imm(s, 0, 1u);
    agr_aot_mov_reg(s, 1, 5);
    agr_aot_mov_reg(s, 2, 4);
    { uint32_t addr = s->r[5] + 20u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 16u); if (rc) return rc; }
    agr_aot_branch_reg(s, s->r[3], 826424u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9c38(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 8u);
    s->r[15] = agr_aot_condition(s, 0u) ? 826394u : 826428u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9c3c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 7u);
    s->r[15] = agr_aot_condition(s, 1u) ? 826406u : 826432u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9c40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 64u); if (rc) return rc; }
    agr_aot_branch_reg(s, 826386u | 1u, 826440u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9c48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 0, s->r[4], 4u);
    agr_aot_branch_reg(s, 828328u | 1u, 826446u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9c4e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 20464u)) return AGR_AOT_FAULT;
    agr_aot_adds(s, 5, s->r[1], 4u);
    { int rc = agr_aot_ldr(s, 8, s->r[0] + 12u); if (rc) return rc; }
    agr_aot_mov_reg(s, 7, 0);
    { int rc = agr_aot_ldr(s, 9, s->r[0] + 24u); if (rc) return rc; }
    agr_aot_mov_reg(s, 10, 2);
    s->r[15] = 826464u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9c66(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 4, s->r[13], 12u);
    agr_aot_add_imm(s, 6, s->r[13], 8u);
    s->r[15] = 826474u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9c78(AgrAotRegs *s) {
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
    agr_aot_branch_reg(s, 826128u | 1u, 826508u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9c8c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[10], 0u);
    agr_aot_set_itstate(s, 20u); s->r[15] = 826514u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9d14(AgrAotRegs *s) {
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
    s->r[15] = 826660u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9d26(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 4, s->r[13], 4u);
    agr_aot_mov_reg(s, 8, 13);
    s->r[15] = 826666u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9d38(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stm(s, 4u, 15u)) return AGR_AOT_FAULT;
    s->r[3] = 4294967295u;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 826690u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9d42(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 7);
    { int rc = agr_aot_ldr(s, 1, s->r[8] + 64u); if (rc) return rc; }
    agr_aot_branch_reg(s, 826128u | 1u, 826700u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9d4c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = s->r[0] ? 826734u : 826702u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9d4e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[7] + 16u); if (rc) return rc; }
    agr_aot_mov_reg(s, 1, 7);
    agr_aot_mov_reg(s, 2, 13);
    agr_aot_branch_reg(s, s->r[3], 826710u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9d56(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 8u);
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = agr_aot_condition(s, 0u) ? 826690u : 826716u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9d5c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 13);
    agr_aot_branch_reg(s, 826292u | 1u, 826722u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9d62(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[4], 6u);
    s->r[15] = agr_aot_condition(s, 1u) ? 826734u : 826726u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9d66(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 7);
    agr_aot_mov_reg(s, 1, 6);
    agr_aot_branch_reg(s, 826388u | 1u, 826734u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9d6e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 9u);
    s->r[13] += 480u;
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) return rc;
}

static int aot_fast_000c9d76(AgrAotRegs *s) {
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
    s->r[15] = 826446u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9d8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 20u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16496u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 5, 0);
    { int rc = agr_aot_ldr(s, 6, s->r[0] + 12u); if (rc) return rc; }
    agr_aot_mov_reg(s, 4, 1);
    { uint32_t addr = s->r[1] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = !s->r[6] ? 826784u : 826776u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9d98(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 2, 1u);
    agr_aot_branch_reg(s, 826446u | 1u, 826782u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9d9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 826824u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9da0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 16u); if (rc) return rc; }
    agr_aot_mov_reg(s, 1, 5);
    agr_aot_movs_imm(s, 0, 2u);
    agr_aot_mov_reg(s, 2, 4);
    agr_aot_branch_reg(s, s->r[3], 826794u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9daa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 7u);
    s->r[15] = agr_aot_condition(s, 0u) ? 826810u : 826798u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9dae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 8u);
    s->r[15] = agr_aot_condition(s, 1u) ? 826824u : 826802u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9db2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 1, 4);
    agr_aot_branch_reg(s, 826388u | 1u, 826810u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9dba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 64u); if (rc) return rc; }
    agr_aot_branch_reg(s, 826386u | 1u, 826818u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9dc2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 0, s->r[4], 4u);
    agr_aot_branch_reg(s, 828328u | 1u, 826824u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9dc8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 290804u, 826828u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9dcc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[0] + 12u); if (rc) return rc; }
    s->r[15] = s->r[2] ? 826836u : 826832u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9dd0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 826644u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9dd4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[1] + 60u); if (rc) return rc; }
    { uint32_t addr = s->r[1] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 826446u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9dde(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16392u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 1, 0);
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = !s->r[3] ? 826858u : 826854u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9de6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 1u);
    agr_aot_branch_reg(s, s->r[3], 826858u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9dea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) return rc;
}

static int aot_fast_000c9dec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16432u)) return AGR_AOT_FAULT;
    agr_aot_cmp(s, s->r[1], 4u);
    s->r[15] = agr_aot_condition(s, 8u) ? 826900u : 826866u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9df6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 5, s->r[0], 12u);
    agr_aot_lsls(s, 7, s->r[1], 12u);
    agr_aot_lsls(s, 3, s->r[0], 0u);
    agr_aot_movs_imm(s, 0, 1u);
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) return rc;
}

static int aot_fast_000c9e14(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) return rc;
}

static int aot_fast_000c9e18(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16415u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 2, 1);
    agr_aot_movs_imm(s, 1, 0u);
    agr_aot_add_imm(s, 3, s->r[13], 12u);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_mov_reg(s, 3, 1);
    agr_aot_branch_reg(s, 826860u | 1u, 826920u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9e28(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 12u); if (rc) return rc; }
    s->r[13] += 20u;
    { uint32_t addr = s->r[13]; s->r[13] = s->r[13] + 4u; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_000c9e30(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16432u)) return AGR_AOT_FAULT;
    agr_aot_cmp(s, s->r[1], 4u);
    s->r[15] = agr_aot_condition(s, 8u) ? 826968u : 826934u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9e3a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 5, s->r[0], 12u);
    agr_aot_lsls(s, 7, s->r[1], 12u);
    agr_aot_lsls(s, 3, s->r[0], 0u);
    agr_aot_movs_imm(s, 0, 1u);
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) return rc;
}

static int aot_fast_000c9e58(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) return rc;
}

static int aot_fast_000c9e5c(AgrAotRegs *s) {
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
    agr_aot_branch_reg(s, 826928u | 1u, 826994u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9e72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 16u;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) return rc;
}

static int aot_fast_000c9e76(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[2] + 60u); if (rc) return rc; }
    if (agr_aot_stmdb_sp(s, 16880u)) return AGR_AOT_FAULT;
    agr_aot_adds(s, 5, s->r[2], 4u);
    { uint32_t addr = s->r[2] + 64u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_mov_reg(s, 7, 0);
    agr_aot_mov_reg(s, 8, 1);
    s->r[15] = 827012u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9e8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 4, s->r[13], 92u);
    agr_aot_add_imm(s, 6, s->r[13], 88u);
    s->r[15] = 827022u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9e9c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stm(s, 4u, 15u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 13);
    s->r[3] = 4294967295u;
    { uint32_t addr = s->r[6] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 827048u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9ea8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 13);
    { int rc = agr_aot_ldr(s, 1, s->r[6] + 64u); if (rc) return rc; }
    agr_aot_branch_reg(s, 826128u | 1u, 827056u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9eb0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[0] ? 827062u : 827058u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9eb2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 5, 9u);
    s->r[15] = 827104u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9eb6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_movs_imm(s, 1, 12u);
    agr_aot_mov_reg(s, 2, 13);
    agr_aot_branch_reg(s, 826972u | 1u, 827072u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9ec0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_mov_reg(s, 1, 8);
    agr_aot_branch_reg(s, s->r[7], 827078u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9ec6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 827058u : 827082u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9eca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 16u); if (rc) return rc; }
    agr_aot_movs_imm(s, 0, 8u);
    agr_aot_mov_reg(s, 1, 13);
    agr_aot_mov_reg(s, 2, 6);
    agr_aot_branch_reg(s, s->r[3], 827092u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9ed4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 5u);
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = agr_aot_condition(s, 0u) ? 827104u : 827098u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9eda(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 9u);
    s->r[15] = agr_aot_condition(s, 1u) ? 827048u : 827102u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9ede(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 827058u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9ee0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 826292u | 1u, 827110u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9ee6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_add_imm(s, 13, s->r[13], 3854u);
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) return rc;
}

static int aot_fast_000c9f54(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 8, s->r[5] + 0u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[8], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 827696u : 827232u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9f60(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[7], 2u);
    s->r[15] = agr_aot_condition(s, 1u) ? 827242u : 827236u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9f64(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 4u); if (rc) return rc; }
    agr_aot_adds(s, 5, s->r[5], 8u);
    s->r[15] = 827252u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9f6e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 5, s->r[5], 4u);
    s->r[15] = 827248u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9f74(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 72u); if (rc) return rc; }
    s->r[15] = 827254u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9f7a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 827260u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9f7c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[2] += s->r[1];
    agr_aot_movs_imm(s, 1, 15u);
    if (agr_aot_stm(s, 13u, 12u)) return AGR_AOT_FAULT;
    agr_aot_branch_reg(s, 826904u | 1u, 827272u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9f88(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[13] + 0u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 4u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[2], s->r[0]);
    s->r[15] = agr_aot_condition(s, 8u) ? 827296u : 827280u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9f94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[2] += s->r[1];
    agr_aot_cmp(s, s->r[0], s->r[2]);
    agr_aot_set_itstate(s, 44u); s->r[15] = 827290u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9fa0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    s->r[3] = s->r[3] & 1u;
    s->r[8] = s->r[8] & 1u;
    s->r[15] = 827306u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9fae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[8], 1u);
    s->r[15] = agr_aot_condition(s, 0u) ? 827374u : 827316u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9fb4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = agr_aot_condition(s, 3u) ? 827326u : 827318u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9fb6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[8], 2u);
    s->r[15] = agr_aot_condition(s, 0u) ? 827516u : 827324u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9fbc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 827756u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9fbe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 8, s->r[5], 4u);
    agr_aot_cmp(s, s->r[10], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 827370u : 827336u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9fc8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = !s->r[2] ? 827370u : 827338u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9fca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_branch_reg(s, 825956u | 1u, 827344u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9fd0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 56u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    agr_aot_mov_reg(s, 5, 0);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 601720u | 1u, 827356u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9fdc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 827756u : 827362u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9fe2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_movs_imm(s, 1, 15u);
    agr_aot_mov_reg(s, 2, 5);
    s->r[15] = 827504u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9fea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 5, 8);
    s->r[15] = 827220u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9fee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[10], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 827460u : 827380u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9ff4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 827512u : 827384u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000c9ff8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 4u); if (rc) return rc; }
    { int rc = agr_aot_ldr(s, 2, s->r[5] + 0u); if (rc) return rc; }
    agr_aot_adds(s, 1, s->r[3], 2u);
    s->r[15] = 827390u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca002(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 827756u : 827398u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca006(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 8u); if (rc) return rc; }
    agr_aot_adds(s, 3, s->r[3], 1u);
    { uint32_t addr = s->r[13] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    s->r[15] = agr_aot_condition(s, 0u) ? 827430u : 827406u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca00e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 0, s->r[5], 4u);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    agr_aot_branch_reg(s, 826370u | 1u, 827414u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca016(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[13] + 0u); if (rc) return rc; }
    agr_aot_add_imm(s, 3, s->r[13], 16u);
    agr_aot_mov_reg(s, 1, 0);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 601536u | 1u, 827426u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca022(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 8, 0);
    s->r[15] = !s->r[0] ? 827512u : 827430u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca026(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_movs_imm(s, 1, 13u);
    agr_aot_branch_reg(s, 826904u | 1u, 827438u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca02e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[8], 2u);
    { int rc = agr_aot_ldr(s, 2, s->r[13] + 16u); if (rc) return rc; }
    { uint32_t addr = s->r[4] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = agr_aot_condition(s, 1u) ? 827456u : 827448u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca038(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 3, 4);
    { uint32_t addr = (s->r[3] + 44u); s->r[3] = s->r[3] + 44u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 827606u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca040(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 36u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 827608u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca044(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_movs_imm(s, 1, 13u);
    { int rc = agr_aot_ldr(s, 8, s->r[4] + 32u); if (rc) return rc; }
    agr_aot_branch_reg(s, 826904u | 1u, 827472u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca050(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[8], s->r[0]);
    s->r[15] = agr_aot_condition(s, 1u) ? 827512u : 827476u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca054(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 40u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[5], s->r[3]);
    s->r[15] = agr_aot_condition(s, 1u) ? 827512u : 827482u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca05a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 827484u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca05c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 825956u | 1u, 827488u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca060(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 1, 15u);
    agr_aot_mov_reg(s, 2, 0);
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 826972u | 1u, 827498u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca06a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_movs_imm(s, 1, 0u);
    agr_aot_mov_reg(s, 2, 4);
    s->r[15] = 827504u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca070(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 826972u | 1u, 827508u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca074(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 7u);
    s->r[15] = 827758u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca078(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 5, s->r[5], 8u);
    s->r[15] = 827220u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca07c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 0u); if (rc) return rc; }
    s->r[15] = 827518u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca082(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[10], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 827614u : 827528u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca088(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[2], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 827674u : 827532u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca090(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 827544u : 827538u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca092(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[8], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 827674u : 827544u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca098(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[12] = 0u;
    s->r[15] = 827548u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca09c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[12], s->r[8]);
    s->r[15] = agr_aot_condition(s, 0u) ? 827594u : 827552u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca0a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 12, s->r[12], 1u);
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 8u); if (rc) return rc; }
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[12]); }
    s->r[15] = 827562u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca0ae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[13] + 16u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 826370u | 1u, 827572u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca0b4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 2, 0u);
    agr_aot_add_imm(s, 3, s->r[13], 16u);
    agr_aot_mov_reg(s, 1, 0);
    agr_aot_mov_reg(s, 0, 4);
    agr_aot_branch_reg(s, 601536u | 1u, 827584u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca0c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 12, s->r[13] + 4u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 827548u : 827592u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca0c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 827674u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca0ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_movs_imm(s, 1, 13u);
    agr_aot_branch_reg(s, 826904u | 1u, 827602u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca0d2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 16u); if (rc) return rc; }
    { uint32_t addr = s->r[4] + 32u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    s->r[15] = 827606u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca0d6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 36u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 827608u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca0d8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 40u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    agr_aot_movs_imm(s, 0, 6u);
    s->r[15] = 827758u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca0de(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 32u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_movs_imm(s, 1, 13u);
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 826904u | 1u, 827626u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca0ea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 4u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], s->r[0]);
    s->r[15] = agr_aot_condition(s, 1u) ? 827674u : 827632u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca0f0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 40u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[5], s->r[3]);
    s->r[15] = agr_aot_condition(s, 1u) ? 827674u : 827638u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca0f6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 3, 4u);
    agr_aot_movs_imm(s, 1, 0u);
    { uint32_t addr = s->r[4] + 48u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_adds(s, 3, s->r[5], s->r[3]);
    { uint32_t addr = s->r[4] + 40u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    { uint32_t addr = s->r[4] + 44u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[1]); }
    { uint32_t addr = s->r[4] + 52u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 0u); if (rc) return rc; }
    agr_aot_cmp(s, s->r[3], s->r[1]);
    s->r[15] = agr_aot_condition(s, 10u) ? 827670u : 827660u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca10c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 0, s->r[8], 1u);
    s->r[15] = 827664u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca114(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 827484u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca116(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[9] = 1u;
    s->r[15] = 827674u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca11a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 0u); if (rc) return rc; }
    agr_aot_add_imm(s, 8, s->r[8], 1u);
    agr_aot_cmp(s, s->r[3], 0u);
    agr_aot_set_itstate(s, 184u); s->r[15] = 827684u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca130(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[7], 2u);
    s->r[15] = agr_aot_condition(s, 13u) ? 827706u : 827700u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca134(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 826382u | 1u, 827704u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca138(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 827714u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca13a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_add_imm(s, 1, s->r[13], 20u);
    agr_aot_branch_reg(s, 828826u | 1u, 827714u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca142(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = s->r[0] ? 827756u : 827716u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca144(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[9], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 827726u : 827722u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca14a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 8u);
    s->r[15] = 827758u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca14e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 1, 15u);
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 826904u | 1u, 827734u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca156(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 1, 14u);
    agr_aot_mov_reg(s, 2, 0);
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 826972u | 1u, 827744u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca160(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, 827748u + 16u); if (rc) return rc; }
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_movs_imm(s, 1, 15u);
    s->r[2] += 827754u;
    { int rc = agr_aot_ldr(s, 2, s->r[2] + 0u); if (rc) return rc; }
    s->r[15] = 827504u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca16c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 9u);
    s->r[15] = 827758u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca16e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 36u;
    if ((rc = agr_aot_ldmia_sp(s, 36848u))) return rc;
}

static int aot_fast_000ca184(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16880u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 4, 0);
    s->r[13] -= 264u;
    agr_aot_mov_reg(s, 7, 2);
    agr_aot_mov_reg(s, 5, 3);
    agr_aot_cmp(s, s->r[1], 4u);
    s->r[15] = agr_aot_condition(s, 8u) ? 828044u : 827796u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca198(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 3, s->r[0], s->r[0]);
    agr_aot_cmp(s, s->r[0], 122u);
    agr_aot_lsls(s, 2, s->r[2], 1u);
    agr_aot_cmp(s, s->r[5], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 828044u : 827810u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca1a2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 56u); if (rc) return rc; }
    s->r[15] = 827812u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca1a6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = 827816u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca1a8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls_reg(s, 2, s->r[0], s->r[5]);
    s->r[15] = 827820u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca1ae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = agr_aot_condition(s, 0u) ? 827834u : 827824u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca1b0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 827826u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca1b6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 3, s->r[3], 4u);
    { uint32_t addr = s->r[6] + 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 827834u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca1ba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 5, s->r[5], 1u);
    agr_aot_cmp(s, s->r[5], 16u);
    s->r[15] = agr_aot_condition(s, 1u) ? 827816u : 827840u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca1c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 828114u : 827848u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca1c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[4] + 56u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    s->r[15] = 828320u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca28c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 2u);
    s->r[15] = 828320u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca2d2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = 828320u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca3a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 264u;
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) return rc;
}

static int aot_fast_000ca3a8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 1, s->r[0], 52u);
    s->r[15] = 828332u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca3b0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 12, 3);
    agr_aot_mov_reg(s, 14, 4);
    { uint32_t addr = (s->r[12] - 4u); s->r[12] = s->r[12] - 4u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[5]); }
    s->r[15] = 828344u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca3bc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 13, 12);
    if ((rc = agr_aot_ldmia_sp(s, 32768u))) return rc;
}

static int aot_fast_000ca3c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca3cc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca3d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca3dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca3e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca3ec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca430(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca474(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca488(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca49c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca4a0(AgrAotRegs *s) {
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
    agr_aot_branch_reg(s, 826644u | 1u, 828602u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca4ba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[13] += 72u;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca4c4(AgrAotRegs *s) {
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
    agr_aot_branch_reg(s, 826762u | 1u, 828638u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca4de(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[13] += 72u;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca4e8(AgrAotRegs *s) {
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
    agr_aot_branch_reg(s, 826828u | 1u, 828674u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca502(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[13] += 72u;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca50c(AgrAotRegs *s) {
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
    agr_aot_branch_reg(s, 826742u | 1u, 828710u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca526(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[13] += 72u;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca530(AgrAotRegs *s) {
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
    agr_aot_branch_reg(s, 826998u | 1u, 828746u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca54a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) return rc; }
    s->r[13] += 72u;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca554(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = s->r[3] ? 828782u : 828760u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca558(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 9u); if (rc) return rc; }
    s->r[15] = !s->r[3] ? 828796u : 828764u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca55c(AgrAotRegs *s) {
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
    s->r[15] = 828784u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca56e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_subs(s, 3, s->r[3], 1u);
    s->r[15] = 828784u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca570(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[0] + 8u; if (agr_aot_fault8(addr)) return AGR_AOT_FAULT; agr_aot_store8(s, addr, s->r[3]); }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    agr_aot_lsls(s, 2, s->r[3], 8u);
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[2]); }
    s->r[15] = 828792u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca57a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca57c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 176u);
    agr_aot_branch_reg(s, s->r[14], 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca580(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 16415u)) return AGR_AOT_FAULT;
    agr_aot_movs_imm(s, 1, 0u);
    agr_aot_add_imm(s, 3, s->r[13], 12u);
    agr_aot_movs_imm(s, 2, 12u);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_mov_reg(s, 3, 1);
    agr_aot_branch_reg(s, 826860u | 1u, 828816u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca590(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 12u); if (rc) return rc; }
    s->r[13] += 20u;
    { uint32_t addr = s->r[13]; s->r[13] = s->r[13] + 4u; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_fast_000ca59a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    if (agr_aot_stmdb_sp(s, 18431u)) return AGR_AOT_FAULT;
    agr_aot_mov_reg(s, 5, 0);
    agr_aot_mov_reg(s, 6, 1);
    agr_aot_movs_imm(s, 7, 0u);
    agr_aot_add_imm(s, 8, s->r[13], 12u);
    s->r[9] = 4080u;
    s->r[15] = 828844u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca5ac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 828756u | 1u, 828850u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca5b2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 176u);
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = agr_aot_condition(s, 1u) ? 828894u : 828856u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca5b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[7], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 829424u : 828862u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca5be(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 4, s->r[13], 12u);
    agr_aot_mov_reg(s, 1, 7);
    agr_aot_mov_reg(s, 3, 7);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_movs_imm(s, 2, 14u);
    agr_aot_branch_reg(s, 826860u | 1u, 828878u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca5ce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[4]); }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 1, 7);
    agr_aot_movs_imm(s, 2, 15u);
    agr_aot_mov_reg(s, 3, 7);
    agr_aot_branch_reg(s, 826928u | 1u, 828892u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca5dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 829424u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca5e6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 828948u : 828904u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca5ec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 3, 1);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_movs_imm(s, 2, 13u);
    s->r[15] = 828918u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca5fa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 826860u | 1u, 828926u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca5fe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 12u); if (rc) return rc; }
    agr_aot_add_imm(s, 10, s->r[10], 4u);
    s->r[15] = 828932u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca608(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_set_itstate(s, 20u); s->r[15] = 828938u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca614(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[3] = s->r[0] & 240u;
    agr_aot_cmp(s, s->r[3], 128u);
    s->r[15] = agr_aot_condition(s, 1u) ? 829004u : 828956u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca61c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 4, s->r[0], 8u);
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 828756u | 1u, 828964u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca626(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 32768u);
    s->r[15] = agr_aot_condition(s, 1u) ? 828976u : 828972u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca62c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 9u);
    s->r[15] = 829426u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca630(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 4, s->r[0], 4u);
    agr_aot_movs_imm(s, 1, 0u);
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = 828984u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca63a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 827780u | 1u, 828990u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca63e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 828972u : 828994u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca646(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_set_itstate(s, 24u); s->r[15] = 829000u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca64c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 144u);
    s->r[15] = agr_aot_condition(s, 1u) ? 829052u : 829008u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca650(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[3] = s->r[0] & 13u;
    agr_aot_cmp(s, s->r[3], 13u);
    s->r[15] = agr_aot_condition(s, 0u) ? 828972u : 829016u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca658(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    agr_aot_mov_reg(s, 0, 5);
    s->r[2] = s->r[4] & 15u;
    agr_aot_mov_reg(s, 3, 1);
    agr_aot_branch_reg(s, 826860u | 1u, 829034u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca66a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_movs_imm(s, 1, 0u);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    s->r[15] = 829042u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca672(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 2, 13u);
    agr_aot_mov_reg(s, 3, 1);
    agr_aot_branch_reg(s, 826928u | 1u, 829050u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca67a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 828844u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca67c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 160u);
    s->r[15] = agr_aot_condition(s, 1u) ? 829084u : 829056u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca682(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[2] = s->r[2] & 7u;
    s->r[15] = 829062u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca68a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_lsls(s, 3, s->r[0], 28u);
    s->r[2] = s->r[2] & 4080u;
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_set_itstate(s, 72u); s->r[15] = 829076u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca69c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 176u);
    s->r[15] = agr_aot_condition(s, 1u) ? 829240u : 829088u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca6a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 177u);
    s->r[15] = agr_aot_condition(s, 1u) ? 829116u : 829092u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca6a4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 828756u | 1u, 829098u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca6aa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 2, 0);
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 828972u : 829104u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca6b4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 828972u : 829110u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca6b6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 829112u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca6b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = 829412u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca6bc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 178u);
    s->r[15] = agr_aot_condition(s, 1u) ? 829190u : 829120u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca6c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 1, 0u);
    agr_aot_movs_imm(s, 2, 13u);
    agr_aot_mov_reg(s, 3, 1);
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_movs_imm(s, 4, 2u);
    agr_aot_branch_reg(s, 826860u | 1u, 829138u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca6d2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 828756u | 1u, 829144u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca6dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 12u); if (rc) return rc; }
    s->r[0] = s->r[0] & 127u;
    s->r[15] = agr_aot_condition(s, 0u) ? 829172u : 829156u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca6e6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_adds(s, 4, s->r[4], 7u);
    s->r[3] += s->r[0];
    agr_aot_mov_reg(s, 0, 6);
    { uint32_t addr = s->r[13] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[3]); }
    agr_aot_branch_reg(s, 828756u | 1u, 829170u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca6f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 829144u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca6f4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_add_imm(s, 3, s->r[3], 3841u);
    s->r[15] = 829176u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca6fa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[0] += s->r[3];
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[8]); }
    { uint32_t addr = s->r[13] + 12u; if (agr_aot_fault(addr)) return AGR_AOT_FAULT; agr_aot_store32(s, addr, s->r[0]); }
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 829042u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca706(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 179u);
    s->r[15] = agr_aot_condition(s, 1u) ? 829216u : 829194u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca70a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 828756u | 1u, 829200u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca710(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 1, 1u);
    s->r[3] = s->r[0] & 15u;
    s->r[2] = s->r[0] & 240u;
    agr_aot_adds(s, 3, s->r[3], 1u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 829268u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca720(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[3] = s->r[0] & 252u;
    agr_aot_cmp(s, s->r[3], 180u);
    s->r[15] = agr_aot_condition(s, 0u) ? 828972u : 829224u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca728(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[4] = s->r[0] & 7u;
    agr_aot_movs_imm(s, 1, 1u);
    agr_aot_adds(s, 2, s->r[4], 1u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[2] = s->r[2] | 524288u;
    s->r[15] = 829112u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca738(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[3], 192u);
    s->r[15] = agr_aot_condition(s, 1u) ? 829386u : 829244u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca73c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 198u);
    s->r[15] = agr_aot_condition(s, 1u) ? 829274u : 829248u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca740(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 828756u | 1u, 829254u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca746(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 1, 3u);
    s->r[3] = s->r[0] & 15u;
    s->r[2] = s->r[0] & 240u;
    agr_aot_adds(s, 3, s->r[3], 1u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 829268u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca758(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 829112u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca75a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 199u);
    s->r[15] = agr_aot_condition(s, 1u) ? 829306u : 829278u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca75e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 828756u | 1u, 829284u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca764(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 2, 0);
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 0u) ? 828972u : 829292u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca770(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = agr_aot_condition(s, 1u) ? 828972u : 829300u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca774(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_movs_imm(s, 1, 4u);
    s->r[15] = 829412u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca77a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[3] = s->r[0] & 248u;
    agr_aot_cmp(s, s->r[3], 192u);
    s->r[15] = agr_aot_condition(s, 1u) ? 829330u : 829314u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca782(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[4] = s->r[0] & 15u;
    agr_aot_movs_imm(s, 1, 3u);
    agr_aot_adds(s, 2, s->r[4], 1u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[2] = s->r[2] | 655360u;
    s->r[15] = 829112u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca792(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 200u);
    s->r[15] = agr_aot_condition(s, 1u) ? 829354u : 829334u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca796(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 828756u | 1u, 829340u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca79c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[2] = s->r[0] & 240u;
    s->r[0] = s->r[0] & 15u;
    agr_aot_adds(s, 2, s->r[2], 16u);
    agr_aot_adds(s, 3, s->r[0], 1u);
    s->r[15] = 829376u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca7aa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 201u);
    s->r[15] = agr_aot_condition(s, 1u) ? 828972u : 829360u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca7b0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 6);
    agr_aot_branch_reg(s, 828756u | 1u, 829366u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca7b6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[3] = s->r[0] & 15u;
    s->r[2] = s->r[0] & 240u;
    agr_aot_adds(s, 3, s->r[3], 1u);
    s->r[15] = 829376u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca7c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 0, 5);
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = 829380u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca7c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 829410u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca7ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[3] = s->r[0] & 248u;
    agr_aot_cmp(s, s->r[3], 208u);
    s->r[15] = agr_aot_condition(s, 1u) ? 828972u : 829396u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca7d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[4] = s->r[0] & 7u;
    agr_aot_movs_imm(s, 1, 1u);
    agr_aot_adds(s, 2, s->r[4], 1u);
    agr_aot_mov_reg(s, 0, 5);
    s->r[2] = s->r[2] | 524288u;
    s->r[15] = 829410u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca7e2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 3, 5u);
    s->r[15] = 829412u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca7e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 827780u | 1u, 829416u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca7e8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_cmp(s, s->r[0], 0u);
    s->r[15] = agr_aot_condition(s, 1u) ? 828972u : 829422u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca7ee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[15] = 828844u; return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca7f0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = 829426u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000ca7f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    s->r[13] += 16u;
    if ((rc = agr_aot_ldmia_sp(s, 34800u))) return rc;
}

static int aot_fast_000cae90(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 831124u, 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000cae92(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 8, 8);
    s->r[15] = 831124u;
    return AGR_AOT_BOUNDARY;
}

static int aot_fast_000caeb0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_branch_reg(s, 831156u, 0u, 0); return AGR_AOT_BOUNDARY;
}

static int aot_fast_000caeb2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u) != 0x20u) return AGR_AOT_MODE_MISS;
    agr_aot_mov_reg(s, 8, 8);
    s->r[15] = 831156u;
    return AGR_AOT_BOUNDARY;
}

const AgrAotEntry agr_aot_debug_blocks[] = {
    {0, 0, 0},
};
const uint32_t agr_aot_debug_block_count = 0u;

const AgrAotEntry agr_aot_fast_blocks[] = {
    {289424u, aot_fast_00046a90, 3u},
    {289436u, aot_fast_00046a9c, 3u},
    {289460u, aot_fast_00046ab4, 3u},
    {289568u, aot_fast_00046b20, 3u},
    {289580u, aot_fast_00046b2c, 3u},
    {289592u, aot_fast_00046b38, 3u},
    {289652u, aot_fast_00046b74, 3u},
    {290408u, aot_fast_00046e68, 3u},
    {290456u, aot_fast_00046e98, 3u},
    {290468u, aot_fast_00046ea4, 3u},
    {290528u, aot_fast_00046ee0, 3u},
    {290540u, aot_fast_00046eec, 3u},
    {290552u, aot_fast_00046ef8, 3u},
    {290732u, aot_fast_00046fac, 3u},
    {290744u, aot_fast_00046fb8, 3u},
    {290756u, aot_fast_00046fc4, 3u},
    {290768u, aot_fast_00046fd0, 3u},
    {290780u, aot_fast_00046fdc, 3u},
    {290792u, aot_fast_00046fe8, 3u},
    {290804u, aot_fast_00046ff4, 3u},
    {290816u, aot_fast_00047000, 3u},
    {290828u, aot_fast_0004700c, 3u},
    {290840u, aot_fast_00047018, 3u},
    {290852u, aot_fast_00047024, 3u},
    {290972u, aot_fast_0004709c, 3u},
    {291308u, aot_fast_000471ec, 3u},
    {291464u, aot_fast_00047288, 3u},
    {292756u, aot_fast_00047794, 3u},
    {292770u, aot_fast_000477a2, 1u},
    {292776u, aot_fast_000477a8, 2u},
    {292780u, aot_fast_000477ac, 3u},
    {292788u, aot_fast_000477b4, 2u},
    {292794u, aot_fast_000477ba, 2u},
    {292800u, aot_fast_000477c0, 2u},
    {292816u, aot_fast_000477d0, 9u},
    {292836u, aot_fast_000477e4, 6u},
    {292850u, aot_fast_000477f2, 5u},
    {292862u, aot_fast_000477fe, 6u},
    {292876u, aot_fast_0004780c, 2u},
    {292900u, aot_fast_00047824, 9u},
    {292920u, aot_fast_00047838, 6u},
    {292934u, aot_fast_00047846, 5u},
    {292946u, aot_fast_00047852, 6u},
    {292960u, aot_fast_00047860, 2u},
    {292984u, aot_fast_00047878, 9u},
    {293004u, aot_fast_0004788c, 6u},
    {293018u, aot_fast_0004789a, 5u},
    {293030u, aot_fast_000478a6, 6u},
    {293044u, aot_fast_000478b4, 2u},
    {293068u, aot_fast_000478cc, 9u},
    {293088u, aot_fast_000478e0, 6u},
    {293102u, aot_fast_000478ee, 5u},
    {293114u, aot_fast_000478fa, 6u},
    {293128u, aot_fast_00047908, 2u},
    {293152u, aot_fast_00047920, 9u},
    {293172u, aot_fast_00047934, 6u},
    {293186u, aot_fast_00047942, 5u},
    {293198u, aot_fast_0004794e, 6u},
    {293212u, aot_fast_0004795c, 2u},
    {293236u, aot_fast_00047974, 9u},
    {293256u, aot_fast_00047988, 6u},
    {293270u, aot_fast_00047996, 5u},
    {293282u, aot_fast_000479a2, 6u},
    {293296u, aot_fast_000479b0, 2u},
    {293320u, aot_fast_000479c8, 9u},
    {293340u, aot_fast_000479dc, 6u},
    {293354u, aot_fast_000479ea, 5u},
    {293366u, aot_fast_000479f6, 6u},
    {293380u, aot_fast_00047a04, 2u},
    {293404u, aot_fast_00047a1c, 9u},
    {293424u, aot_fast_00047a30, 6u},
    {293438u, aot_fast_00047a3e, 5u},
    {293450u, aot_fast_00047a4a, 6u},
    {293464u, aot_fast_00047a58, 2u},
    {293488u, aot_fast_00047a70, 9u},
    {293508u, aot_fast_00047a84, 6u},
    {293522u, aot_fast_00047a92, 5u},
    {293534u, aot_fast_00047a9e, 6u},
    {293548u, aot_fast_00047aac, 2u},
    {293572u, aot_fast_00047ac4, 9u},
    {293592u, aot_fast_00047ad8, 6u},
    {293606u, aot_fast_00047ae6, 5u},
    {293618u, aot_fast_00047af2, 6u},
    {293632u, aot_fast_00047b00, 2u},
    {293656u, aot_fast_00047b18, 9u},
    {293676u, aot_fast_00047b2c, 6u},
    {293690u, aot_fast_00047b3a, 5u},
    {293702u, aot_fast_00047b46, 6u},
    {293716u, aot_fast_00047b54, 2u},
    {293740u, aot_fast_00047b6c, 9u},
    {293760u, aot_fast_00047b80, 6u},
    {293774u, aot_fast_00047b8e, 5u},
    {293786u, aot_fast_00047b9a, 6u},
    {293800u, aot_fast_00047ba8, 2u},
    {293824u, aot_fast_00047bc0, 9u},
    {293844u, aot_fast_00047bd4, 6u},
    {293858u, aot_fast_00047be2, 5u},
    {293870u, aot_fast_00047bee, 6u},
    {293884u, aot_fast_00047bfc, 2u},
    {293908u, aot_fast_00047c14, 9u},
    {293928u, aot_fast_00047c28, 6u},
    {293942u, aot_fast_00047c36, 5u},
    {293954u, aot_fast_00047c42, 6u},
    {293968u, aot_fast_00047c50, 2u},
    {293992u, aot_fast_00047c68, 9u},
    {294012u, aot_fast_00047c7c, 6u},
    {294026u, aot_fast_00047c8a, 5u},
    {294038u, aot_fast_00047c96, 6u},
    {294052u, aot_fast_00047ca4, 2u},
    {294076u, aot_fast_00047cbc, 9u},
    {294096u, aot_fast_00047cd0, 6u},
    {294110u, aot_fast_00047cde, 5u},
    {294122u, aot_fast_00047cea, 6u},
    {294136u, aot_fast_00047cf8, 2u},
    {294160u, aot_fast_00047d10, 9u},
    {294180u, aot_fast_00047d24, 6u},
    {294194u, aot_fast_00047d32, 5u},
    {294206u, aot_fast_00047d3e, 6u},
    {294220u, aot_fast_00047d4c, 2u},
    {294244u, aot_fast_00047d64, 9u},
    {294264u, aot_fast_00047d78, 6u},
    {294278u, aot_fast_00047d86, 5u},
    {294290u, aot_fast_00047d92, 6u},
    {294304u, aot_fast_00047da0, 2u},
    {294328u, aot_fast_00047db8, 9u},
    {294348u, aot_fast_00047dcc, 6u},
    {294362u, aot_fast_00047dda, 5u},
    {294374u, aot_fast_00047de6, 6u},
    {294388u, aot_fast_00047df4, 2u},
    {294412u, aot_fast_00047e0c, 9u},
    {294432u, aot_fast_00047e20, 6u},
    {294446u, aot_fast_00047e2e, 5u},
    {294458u, aot_fast_00047e3a, 6u},
    {294472u, aot_fast_00047e48, 2u},
    {294496u, aot_fast_00047e60, 9u},
    {294516u, aot_fast_00047e74, 6u},
    {294530u, aot_fast_00047e82, 5u},
    {294542u, aot_fast_00047e8e, 6u},
    {294556u, aot_fast_00047e9c, 2u},
    {294580u, aot_fast_00047eb4, 9u},
    {294600u, aot_fast_00047ec8, 6u},
    {294614u, aot_fast_00047ed6, 5u},
    {294626u, aot_fast_00047ee2, 6u},
    {294640u, aot_fast_00047ef0, 2u},
    {294664u, aot_fast_00047f08, 9u},
    {294684u, aot_fast_00047f1c, 6u},
    {294698u, aot_fast_00047f2a, 5u},
    {294710u, aot_fast_00047f36, 6u},
    {294724u, aot_fast_00047f44, 2u},
    {294748u, aot_fast_00047f5c, 9u},
    {294768u, aot_fast_00047f70, 6u},
    {294782u, aot_fast_00047f7e, 5u},
    {294794u, aot_fast_00047f8a, 6u},
    {294808u, aot_fast_00047f98, 2u},
    {294832u, aot_fast_00047fb0, 9u},
    {294852u, aot_fast_00047fc4, 6u},
    {294866u, aot_fast_00047fd2, 5u},
    {294878u, aot_fast_00047fde, 6u},
    {294892u, aot_fast_00047fec, 2u},
    {294916u, aot_fast_00048004, 9u},
    {294936u, aot_fast_00048018, 6u},
    {294950u, aot_fast_00048026, 5u},
    {294962u, aot_fast_00048032, 6u},
    {294976u, aot_fast_00048040, 2u},
    {295000u, aot_fast_00048058, 9u},
    {295020u, aot_fast_0004806c, 6u},
    {295034u, aot_fast_0004807a, 5u},
    {295046u, aot_fast_00048086, 6u},
    {295060u, aot_fast_00048094, 2u},
    {295084u, aot_fast_000480ac, 9u},
    {295104u, aot_fast_000480c0, 6u},
    {295118u, aot_fast_000480ce, 5u},
    {295130u, aot_fast_000480da, 6u},
    {295144u, aot_fast_000480e8, 2u},
    {295168u, aot_fast_00048100, 9u},
    {295188u, aot_fast_00048114, 6u},
    {295202u, aot_fast_00048122, 5u},
    {295214u, aot_fast_0004812e, 6u},
    {295228u, aot_fast_0004813c, 2u},
    {295252u, aot_fast_00048154, 9u},
    {295272u, aot_fast_00048168, 6u},
    {295286u, aot_fast_00048176, 5u},
    {295298u, aot_fast_00048182, 6u},
    {295312u, aot_fast_00048190, 2u},
    {295336u, aot_fast_000481a8, 9u},
    {295356u, aot_fast_000481bc, 6u},
    {295370u, aot_fast_000481ca, 5u},
    {295382u, aot_fast_000481d6, 6u},
    {295396u, aot_fast_000481e4, 2u},
    {295420u, aot_fast_000481fc, 9u},
    {295440u, aot_fast_00048210, 6u},
    {295454u, aot_fast_0004821e, 5u},
    {295466u, aot_fast_0004822a, 6u},
    {295480u, aot_fast_00048238, 2u},
    {295504u, aot_fast_00048250, 5u},
    {295516u, aot_fast_0004825c, 8u},
    {295548u, aot_fast_0004827c, 9u},
    {295568u, aot_fast_00048290, 6u},
    {295582u, aot_fast_0004829e, 5u},
    {295594u, aot_fast_000482aa, 6u},
    {295608u, aot_fast_000482b8, 2u},
    {295632u, aot_fast_000482d0, 9u},
    {295652u, aot_fast_000482e4, 6u},
    {295666u, aot_fast_000482f2, 5u},
    {295678u, aot_fast_000482fe, 6u},
    {295692u, aot_fast_0004830c, 2u},
    {295716u, aot_fast_00048324, 5u},
    {295728u, aot_fast_00048330, 8u},
    {295760u, aot_fast_00048350, 9u},
    {295780u, aot_fast_00048364, 6u},
    {295794u, aot_fast_00048372, 5u},
    {295806u, aot_fast_0004837e, 6u},
    {295820u, aot_fast_0004838c, 2u},
    {295844u, aot_fast_000483a4, 9u},
    {295864u, aot_fast_000483b8, 6u},
    {295878u, aot_fast_000483c6, 5u},
    {295890u, aot_fast_000483d2, 6u},
    {295904u, aot_fast_000483e0, 2u},
    {295928u, aot_fast_000483f8, 5u},
    {295940u, aot_fast_00048404, 8u},
    {295972u, aot_fast_00048424, 9u},
    {295992u, aot_fast_00048438, 6u},
    {296006u, aot_fast_00048446, 5u},
    {296018u, aot_fast_00048452, 6u},
    {296032u, aot_fast_00048460, 2u},
    {296056u, aot_fast_00048478, 9u},
    {296076u, aot_fast_0004848c, 6u},
    {296090u, aot_fast_0004849a, 5u},
    {296102u, aot_fast_000484a6, 6u},
    {296116u, aot_fast_000484b4, 2u},
    {296140u, aot_fast_000484cc, 9u},
    {296160u, aot_fast_000484e0, 6u},
    {296174u, aot_fast_000484ee, 5u},
    {296186u, aot_fast_000484fa, 6u},
    {296200u, aot_fast_00048508, 2u},
    {296224u, aot_fast_00048520, 7u},
    {296244u, aot_fast_00048534, 11u},
    {296268u, aot_fast_0004854c, 9u},
    {296312u, aot_fast_00048578, 9u},
    {296332u, aot_fast_0004858c, 6u},
    {296346u, aot_fast_0004859a, 5u},
    {296358u, aot_fast_000485a6, 6u},
    {296372u, aot_fast_000485b4, 2u},
    {296396u, aot_fast_000485cc, 9u},
    {296416u, aot_fast_000485e0, 6u},
    {296430u, aot_fast_000485ee, 5u},
    {296442u, aot_fast_000485fa, 6u},
    {296456u, aot_fast_00048608, 2u},
    {296480u, aot_fast_00048620, 9u},
    {296500u, aot_fast_00048634, 7u},
    {296544u, aot_fast_00048660, 5u},
    {296558u, aot_fast_0004866e, 1u},
    {296560u, aot_fast_00048670, 5u},
    {296780u, aot_fast_0004874c, 5u},
    {297000u, aot_fast_00048828, 14u},
    {297030u, aot_fast_00048846, 12u},
    {595788u, aot_fast_0009174c, 59u},
    {595910u, aot_fast_000917c6, 6u},
    {595928u, aot_fast_000917d8, 4u},
    {595938u, aot_fast_000917e2, 3u},
    {595946u, aot_fast_000917ea, 2u},
    {595952u, aot_fast_000917f0, 2u},
    {595958u, aot_fast_000917f6, 5u},
    {595970u, aot_fast_00091802, 2u},
    {595976u, aot_fast_00091808, 1u},
    {595978u, aot_fast_0009180a, 1u},
    {595982u, aot_fast_0009180e, 3u},
    {595990u, aot_fast_00091816, 7u},
    {596006u, aot_fast_00091826, 1u},
    {596008u, aot_fast_00091828, 7u},
    {596024u, aot_fast_00091838, 3u},
    {596032u, aot_fast_00091840, 6u},
    {596048u, aot_fast_00091850, 2u},
    {596054u, aot_fast_00091856, 2u},
    {596058u, aot_fast_0009185a, 3u},
    {596066u, aot_fast_00091862, 1u},
    {596068u, aot_fast_00091864, 2u},
    {596074u, aot_fast_0009186a, 3u},
    {596148u, aot_fast_000918b4, 5u},
    {596160u, aot_fast_000918c0, 4u},
    {596168u, aot_fast_000918c8, 2u},
    {596172u, aot_fast_000918cc, 2u},
    {596176u, aot_fast_000918d0, 7u},
    {596192u, aot_fast_000918e0, 2u},
    {599164u, aot_fast_0009247c, 3u},
    {599172u, aot_fast_00092484, 1u},
    {599178u, aot_fast_0009248a, 3u},
    {599184u, aot_fast_00092490, 2u},
    {599188u, aot_fast_00092494, 4u},
    {599196u, aot_fast_0009249c, 3u},
    {599202u, aot_fast_000924a2, 3u},
    {599208u, aot_fast_000924a8, 3u},
    {599214u, aot_fast_000924ae, 3u},
    {599220u, aot_fast_000924b4, 3u},
    {599226u, aot_fast_000924ba, 3u},
    {599232u, aot_fast_000924c0, 3u},
    {599238u, aot_fast_000924c6, 3u},
    {599246u, aot_fast_000924ce, 1u},
    {599248u, aot_fast_000924d0, 6u},
    {599286u, aot_fast_000924f6, 1u},
    {599288u, aot_fast_000924f8, 1u},
    {599292u, aot_fast_000924fc, 2u},
    {599296u, aot_fast_00092500, 1u},
    {599300u, aot_fast_00092504, 1u},
    {599304u, aot_fast_00092508, 2u},
    {599310u, aot_fast_0009250e, 4u},
    {599322u, aot_fast_0009251a, 2u},
    {599326u, aot_fast_0009251e, 5u},
    {599344u, aot_fast_00092530, 2u},
    {599352u, aot_fast_00092538, 2u},
    {599360u, aot_fast_00092540, 2u},
    {599368u, aot_fast_00092548, 2u},
    {599376u, aot_fast_00092550, 2u},
    {599384u, aot_fast_00092558, 2u},
    {599392u, aot_fast_00092560, 2u},
    {599396u, aot_fast_00092564, 3u},
    {599402u, aot_fast_0009256a, 2u},
    {599406u, aot_fast_0009256e, 2u},
    {599410u, aot_fast_00092572, 2u},
    {599414u, aot_fast_00092576, 2u},
    {599418u, aot_fast_0009257a, 3u},
    {599424u, aot_fast_00092580, 5u},
    {599438u, aot_fast_0009258e, 1u},
    {599442u, aot_fast_00092592, 1u},
    {599660u, aot_fast_0009266c, 3u},
    {599764u, aot_fast_000926d4, 3u},
    {599770u, aot_fast_000926da, 2u},
    {599774u, aot_fast_000926de, 3u},
    {599780u, aot_fast_000926e4, 3u},
    {599786u, aot_fast_000926ea, 3u},
    {599792u, aot_fast_000926f0, 3u},
    {599798u, aot_fast_000926f6, 3u},
    {599804u, aot_fast_000926fc, 3u},
    {599810u, aot_fast_00092702, 3u},
    {599856u, aot_fast_00092730, 6u},
    {599872u, aot_fast_00092740, 1u},
    {599874u, aot_fast_00092742, 7u},
    {599896u, aot_fast_00092758, 2u},
    {599902u, aot_fast_0009275e, 2u},
    {599908u, aot_fast_00092764, 1u},
    {599912u, aot_fast_00092768, 1u},
    {599916u, aot_fast_0009276c, 1u},
    {599920u, aot_fast_00092770, 1u},
    {599924u, aot_fast_00092774, 1u},
    {599928u, aot_fast_00092778, 1u},
    {599936u, aot_fast_00092780, 2u},
    {599940u, aot_fast_00092784, 1u},
    {599944u, aot_fast_00092788, 5u},
    {599962u, aot_fast_0009279a, 6u},
    {599976u, aot_fast_000927a8, 2u},
    {599982u, aot_fast_000927ae, 1u},
    {599986u, aot_fast_000927b2, 5u},
    {600000u, aot_fast_000927c0, 2u},
    {600004u, aot_fast_000927c4, 9u},
    {600026u, aot_fast_000927da, 3u},
    {600042u, aot_fast_000927ea, 2u},
    {600048u, aot_fast_000927f0, 1u},
    {600052u, aot_fast_000927f4, 1u},
    {600056u, aot_fast_000927f8, 1u},
    {600060u, aot_fast_000927fc, 1u},
    {600064u, aot_fast_00092800, 2u},
    {600068u, aot_fast_00092804, 2u},
    {600074u, aot_fast_0009280a, 2u},
    {600080u, aot_fast_00092810, 9u},
    {600100u, aot_fast_00092824, 2u},
    {600110u, aot_fast_0009282e, 1u},
    {600124u, aot_fast_0009283c, 3u},
    {600130u, aot_fast_00092842, 2u},
    {600134u, aot_fast_00092846, 2u},
    {600138u, aot_fast_0009284a, 2u},
    {600142u, aot_fast_0009284e, 2u},
    {600148u, aot_fast_00092854, 1u},
    {600192u, aot_fast_00092880, 5u},
    {600202u, aot_fast_0009288a, 3u},
    {600208u, aot_fast_00092890, 2u},
    {600214u, aot_fast_00092896, 1u},
    {600236u, aot_fast_000928ac, 7u},
    {600250u, aot_fast_000928ba, 2u},
    {600254u, aot_fast_000928be, 2u},
    {600260u, aot_fast_000928c4, 3u},
    {600266u, aot_fast_000928ca, 2u},
    {600272u, aot_fast_000928d0, 2u},
    {600276u, aot_fast_000928d4, 5u},
    {600288u, aot_fast_000928e0, 1u},
    {600290u, aot_fast_000928e2, 4u},
    {600298u, aot_fast_000928ea, 1u},
    {600302u, aot_fast_000928ee, 2u},
    {600306u, aot_fast_000928f2, 1u},
    {600310u, aot_fast_000928f6, 1u},
    {600316u, aot_fast_000928fc, 14u},
    {600346u, aot_fast_0009291a, 2u},
    {600604u, aot_fast_00092a1c, 1u},
    {600672u, aot_fast_00092a60, 8u},
    {600690u, aot_fast_00092a72, 2u},
    {600912u, aot_fast_00092b50, 5u},
    {600926u, aot_fast_00092b5e, 2u},
    {600934u, aot_fast_00092b66, 22u},
    {600996u, aot_fast_00092ba4, 2u},
    {601018u, aot_fast_00092bba, 1u},
    {601034u, aot_fast_00092bca, 1u},
    {601038u, aot_fast_00092bce, 2u},
    {601044u, aot_fast_00092bd4, 1u},
    {601048u, aot_fast_00092bd8, 4u},
    {601060u, aot_fast_00092be4, 2u},
    {601066u, aot_fast_00092bea, 5u},
    {601080u, aot_fast_00092bf8, 2u},
    {601084u, aot_fast_00092bfc, 2u},
    {601088u, aot_fast_00092c00, 3u},
    {601098u, aot_fast_00092c0a, 2u},
    {601104u, aot_fast_00092c10, 1u},
    {601112u, aot_fast_00092c18, 2u},
    {601120u, aot_fast_00092c20, 2u},
    {601128u, aot_fast_00092c28, 2u},
    {601136u, aot_fast_00092c30, 2u},
    {601144u, aot_fast_00092c38, 2u},
    {601152u, aot_fast_00092c40, 2u},
    {601160u, aot_fast_00092c48, 2u},
    {601164u, aot_fast_00092c4c, 1u},
    {601168u, aot_fast_00092c50, 2u},
    {601352u, aot_fast_00092d08, 28u},
    {601426u, aot_fast_00092d52, 2u},
    {601430u, aot_fast_00092d56, 4u},
    {601440u, aot_fast_00092d60, 2u},
    {601446u, aot_fast_00092d66, 3u},
    {601454u, aot_fast_00092d6e, 3u},
    {601462u, aot_fast_00092d76, 1u},
    {601464u, aot_fast_00092d78, 2u},
    {601468u, aot_fast_00092d7c, 3u},
    {601474u, aot_fast_00092d82, 1u},
    {601476u, aot_fast_00092d84, 2u},
    {601482u, aot_fast_00092d8a, 2u},
    {601486u, aot_fast_00092d8e, 8u},
    {601504u, aot_fast_00092da0, 3u},
    {601512u, aot_fast_00092da8, 2u},
    {601516u, aot_fast_00092dac, 1u},
    {601518u, aot_fast_00092dae, 1u},
    {601522u, aot_fast_00092db2, 1u},
    {601524u, aot_fast_00092db4, 2u},
    {601530u, aot_fast_00092dba, 2u},
    {601536u, aot_fast_00092dc0, 7u},
    {601552u, aot_fast_00092dd0, 5u},
    {601562u, aot_fast_00092dda, 5u},
    {601574u, aot_fast_00092de6, 1u},
    {601576u, aot_fast_00092de8, 4u},
    {601586u, aot_fast_00092df2, 7u},
    {601600u, aot_fast_00092e00, 1u},
    {601602u, aot_fast_00092e02, 3u},
    {601608u, aot_fast_00092e08, 2u},
    {601614u, aot_fast_00092e0e, 3u},
    {601620u, aot_fast_00092e14, 3u},
    {601626u, aot_fast_00092e1a, 3u},
    {601632u, aot_fast_00092e20, 3u},
    {601638u, aot_fast_00092e26, 3u},
    {601644u, aot_fast_00092e2c, 3u},
    {601650u, aot_fast_00092e32, 3u},
    {601656u, aot_fast_00092e38, 3u},
    {601662u, aot_fast_00092e3e, 1u},
    {601664u, aot_fast_00092e40, 2u},
    {601670u, aot_fast_00092e46, 2u},
    {601674u, aot_fast_00092e4a, 3u},
    {601684u, aot_fast_00092e54, 3u},
    {601690u, aot_fast_00092e5a, 3u},
    {601696u, aot_fast_00092e60, 3u},
    {601702u, aot_fast_00092e66, 5u},
    {601720u, aot_fast_00092e78, 3u},
    {601728u, aot_fast_00092e80, 1u},
    {601734u, aot_fast_00092e86, 2u},
    {601738u, aot_fast_00092e8a, 2u},
    {601742u, aot_fast_00092e8e, 1u},
    {601744u, aot_fast_00092e90, 2u},
    {601748u, aot_fast_00092e94, 3u},
    {601754u, aot_fast_00092e9a, 3u},
    {601760u, aot_fast_00092ea0, 3u},
    {601766u, aot_fast_00092ea6, 3u},
    {601772u, aot_fast_00092eac, 3u},
    {601778u, aot_fast_00092eb2, 3u},
    {601784u, aot_fast_00092eb8, 3u},
    {601790u, aot_fast_00092ebe, 5u},
    {601804u, aot_fast_00092ecc, 5u},
    {601816u, aot_fast_00092ed8, 1u},
    {601820u, aot_fast_00092edc, 2u},
    {601826u, aot_fast_00092ee2, 2u},
    {601834u, aot_fast_00092eea, 2u},
    {601838u, aot_fast_00092eee, 2u},
    {601842u, aot_fast_00092ef2, 2u},
    {601852u, aot_fast_00092efc, 2u},
    {601860u, aot_fast_00092f04, 2u},
    {601868u, aot_fast_00092f0c, 2u},
    {601876u, aot_fast_00092f14, 2u},
    {601884u, aot_fast_00092f1c, 2u},
    {601892u, aot_fast_00092f24, 2u},
    {601900u, aot_fast_00092f2c, 2u},
    {601904u, aot_fast_00092f30, 5u},
    {601914u, aot_fast_00092f3a, 6u},
    {601928u, aot_fast_00092f48, 1u},
    {601932u, aot_fast_00092f4c, 2u},
    {601936u, aot_fast_00092f50, 1u},
    {601940u, aot_fast_00092f54, 1u},
    {601944u, aot_fast_00092f58, 1u},
    {601948u, aot_fast_00092f5c, 3u},
    {601956u, aot_fast_00092f64, 2u},
    {601960u, aot_fast_00092f68, 1u},
    {601964u, aot_fast_00092f6c, 2u},
    {601972u, aot_fast_00092f74, 6u},
    {601988u, aot_fast_00092f84, 2u},
    {601992u, aot_fast_00092f88, 2u},
    {601996u, aot_fast_00092f8c, 1u},
    {602000u, aot_fast_00092f90, 6u},
    {602016u, aot_fast_00092fa0, 9u},
    {602036u, aot_fast_00092fb4, 9u},
    {602056u, aot_fast_00092fc8, 2u},
    {602060u, aot_fast_00092fcc, 2u},
    {602066u, aot_fast_00092fd2, 1u},
    {602216u, aot_fast_00093068, 3u},
    {602224u, aot_fast_00093070, 9u},
    {602244u, aot_fast_00093084, 4u},
    {602256u, aot_fast_00093090, 3u},
    {602264u, aot_fast_00093098, 9u},
    {602284u, aot_fast_000930ac, 4u},
    {602296u, aot_fast_000930b8, 4u},
    {602308u, aot_fast_000930c4, 2u},
    {602312u, aot_fast_000930c8, 4u},
    {602322u, aot_fast_000930d2, 2u},
    {602328u, aot_fast_000930d8, 3u},
    {602336u, aot_fast_000930e0, 1u},
    {602338u, aot_fast_000930e2, 5u},
    {602408u, aot_fast_00093128, 2u},
    {602412u, aot_fast_0009312c, 1u},
    {602416u, aot_fast_00093130, 1u},
    {602420u, aot_fast_00093134, 1u},
    {602422u, aot_fast_00093136, 1u},
    {602428u, aot_fast_0009313c, 10u},
    {602448u, aot_fast_00093150, 5u},
    {602458u, aot_fast_0009315a, 3u},
    {602466u, aot_fast_00093162, 3u},
    {602476u, aot_fast_0009316c, 3u},
    {602484u, aot_fast_00093174, 1u},
    {602488u, aot_fast_00093178, 1u},
    {602490u, aot_fast_0009317a, 7u},
    {602510u, aot_fast_0009318e, 2u},
    {602516u, aot_fast_00093194, 1u},
    {602518u, aot_fast_00093196, 1u},
    {602520u, aot_fast_00093198, 1u},
    {602524u, aot_fast_0009319c, 2u},
    {602528u, aot_fast_000931a0, 1u},
    {602532u, aot_fast_000931a4, 1u},
    {602536u, aot_fast_000931a8, 1u},
    {602538u, aot_fast_000931aa, 1u},
    {602544u, aot_fast_000931b0, 11u},
    {602568u, aot_fast_000931c8, 2u},
    {602572u, aot_fast_000931cc, 4u},
    {602582u, aot_fast_000931d6, 2u},
    {602586u, aot_fast_000931da, 3u},
    {602594u, aot_fast_000931e2, 1u},
    {602596u, aot_fast_000931e4, 5u},
    {602606u, aot_fast_000931ee, 1u},
    {602610u, aot_fast_000931f2, 2u},
    {602614u, aot_fast_000931f6, 2u},
    {602618u, aot_fast_000931fa, 2u},
    {602628u, aot_fast_00093204, 3u},
    {602636u, aot_fast_0009320c, 3u},
    {602646u, aot_fast_00093216, 1u},
    {602650u, aot_fast_0009321a, 2u},
    {602654u, aot_fast_0009321e, 1u},
    {602658u, aot_fast_00093222, 1u},
    {602662u, aot_fast_00093226, 2u},
    {602666u, aot_fast_0009322a, 1u},
    {602670u, aot_fast_0009322e, 1u},
    {602672u, aot_fast_00093230, 1u},
    {602676u, aot_fast_00093234, 1u},
    {602680u, aot_fast_00093238, 2u},
    {602686u, aot_fast_0009323e, 1u},
    {602690u, aot_fast_00093242, 1u},
    {602694u, aot_fast_00093246, 3u},
    {602700u, aot_fast_0009324c, 5u},
    {602710u, aot_fast_00093256, 3u},
    {602718u, aot_fast_0009325e, 2u},
    {602726u, aot_fast_00093266, 4u},
    {602742u, aot_fast_00093276, 1u},
    {602746u, aot_fast_0009327a, 1u},
    {602750u, aot_fast_0009327e, 1u},
    {602752u, aot_fast_00093280, 7u},
    {602772u, aot_fast_00093294, 2u},
    {602778u, aot_fast_0009329a, 1u},
    {602780u, aot_fast_0009329c, 1u},
    {602782u, aot_fast_0009329e, 1u},
    {602786u, aot_fast_000932a2, 2u},
    {602790u, aot_fast_000932a6, 1u},
    {602794u, aot_fast_000932aa, 1u},
    {602798u, aot_fast_000932ae, 1u},
    {602800u, aot_fast_000932b0, 1u},
    {602806u, aot_fast_000932b6, 3u},
    {602814u, aot_fast_000932be, 3u},
    {602820u, aot_fast_000932c4, 4u},
    {602956u, aot_fast_0009334c, 9u},
    {602986u, aot_fast_0009336a, 1u},
    {602994u, aot_fast_00093372, 2u},
    {602998u, aot_fast_00093376, 3u},
    {603008u, aot_fast_00093380, 3u},
    {603016u, aot_fast_00093388, 19u},
    {603080u, aot_fast_000933c8, 22u},
    {603154u, aot_fast_00093412, 15u},
    {603204u, aot_fast_00093444, 10u},
    {603232u, aot_fast_00093460, 15u},
    {603286u, aot_fast_00093496, 5u},
    {603302u, aot_fast_000934a6, 18u},
    {603362u, aot_fast_000934e2, 5u},
    {603376u, aot_fast_000934f0, 14u},
    {603422u, aot_fast_0009351e, 6u},
    {603440u, aot_fast_00093530, 15u},
    {603492u, aot_fast_00093564, 21u},
    {603560u, aot_fast_000935a8, 20u},
    {603624u, aot_fast_000935e8, 15u},
    {603672u, aot_fast_00093618, 10u},
    {603700u, aot_fast_00093634, 15u},
    {603754u, aot_fast_0009366a, 5u},
    {603770u, aot_fast_0009367a, 18u},
    {603830u, aot_fast_000936b6, 5u},
    {603844u, aot_fast_000936c4, 14u},
    {603890u, aot_fast_000936f2, 6u},
    {603908u, aot_fast_00093704, 15u},
    {603960u, aot_fast_00093738, 7u},
    {603984u, aot_fast_00093750, 1u},
    {603990u, aot_fast_00093756, 2u},
    {603994u, aot_fast_0009375a, 4u},
    {605472u, aot_fast_00093d20, 5u},
    {605484u, aot_fast_00093d2c, 1u},
    {605486u, aot_fast_00093d2e, 2u},
    {605492u, aot_fast_00093d34, 1u},
    {605494u, aot_fast_00093d36, 2u},
    {605500u, aot_fast_00093d3c, 1u},
    {605502u, aot_fast_00093d3e, 2u},
    {605508u, aot_fast_00093d44, 1u},
    {605512u, aot_fast_00093d48, 2u},
    {605518u, aot_fast_00093d4e, 1u},
    {605520u, aot_fast_00093d50, 2u},
    {605526u, aot_fast_00093d56, 2u},
    {605532u, aot_fast_00093d5c, 2u},
    {605536u, aot_fast_00093d60, 2u},
    {605542u, aot_fast_00093d66, 2u},
    {605660u, aot_fast_00093ddc, 4u},
    {605670u, aot_fast_00093de6, 3u},
    {605680u, aot_fast_00093df0, 5u},
    {606540u, aot_fast_0009414c, 5u},
    {606552u, aot_fast_00094158, 1u},
    {606554u, aot_fast_0009415a, 2u},
    {606560u, aot_fast_00094160, 1u},
    {606564u, aot_fast_00094164, 2u},
    {606570u, aot_fast_0009416a, 1u},
    {606572u, aot_fast_0009416c, 2u},
    {606578u, aot_fast_00094172, 1u},
    {606582u, aot_fast_00094176, 2u},
    {606588u, aot_fast_0009417c, 1u},
    {606590u, aot_fast_0009417e, 2u},
    {606596u, aot_fast_00094184, 2u},
    {606602u, aot_fast_0009418a, 2u},
    {606608u, aot_fast_00094190, 2u},
    {606614u, aot_fast_00094196, 2u},
    {606732u, aot_fast_0009420c, 4u},
    {606742u, aot_fast_00094216, 3u},
    {606752u, aot_fast_00094220, 5u},
    {609064u, aot_fast_00094b28, 7u},
    {609082u, aot_fast_00094b3a, 2u},
    {609148u, aot_fast_00094b7c, 3u},
    {609156u, aot_fast_00094b84, 6u},
    {609172u, aot_fast_00094b94, 3u},
    {609180u, aot_fast_00094b9c, 6u},
    {612328u, aot_fast_000957e8, 19u},
    {612370u, aot_fast_00095812, 5u},
    {612384u, aot_fast_00095820, 5u},
    {612396u, aot_fast_0009582c, 2u},
    {618676u, aot_fast_000970b4, 6u},
    {619832u, aot_fast_00097538, 5u},
    {620456u, aot_fast_000977a8, 7u},
    {620472u, aot_fast_000977b8, 5u},
    {620482u, aot_fast_000977c2, 2u},
    {620488u, aot_fast_000977c8, 8u},
    {620506u, aot_fast_000977da, 1u},
    {620508u, aot_fast_000977dc, 1u},
    {620510u, aot_fast_000977de, 1u},
    {620514u, aot_fast_000977e2, 1u},
    {620520u, aot_fast_000977e8, 16u},
    {620560u, aot_fast_00097810, 4u},
    {620576u, aot_fast_00097820, 1u},
    {620580u, aot_fast_00097824, 3u},
    {620586u, aot_fast_0009782a, 3u},
    {620592u, aot_fast_00097830, 3u},
    {620598u, aot_fast_00097836, 2u},
    {620608u, aot_fast_00097840, 2u},
    {620612u, aot_fast_00097844, 2u},
    {620638u, aot_fast_0009785e, 15u},
    {620678u, aot_fast_00097886, 1u},
    {620680u, aot_fast_00097888, 2u},
    {620694u, aot_fast_00097896, 5u},
    {620706u, aot_fast_000978a2, 2u},
    {620714u, aot_fast_000978aa, 1u},
    {620716u, aot_fast_000978ac, 2u},
    {620720u, aot_fast_000978b0, 3u},
    {620728u, aot_fast_000978b8, 4u},
    {620740u, aot_fast_000978c4, 4u},
    {620752u, aot_fast_000978d0, 4u},
    {620760u, aot_fast_000978d8, 4u},
    {620776u, aot_fast_000978e8, 4u},
    {620788u, aot_fast_000978f4, 4u},
    {620796u, aot_fast_000978fc, 2u},
    {620800u, aot_fast_00097900, 3u},
    {620808u, aot_fast_00097908, 6u},
    {620822u, aot_fast_00097916, 5u},
    {620834u, aot_fast_00097922, 2u},
    {620872u, aot_fast_00097948, 4u},
    {620882u, aot_fast_00097952, 2u},
    {622652u, aot_fast_0009803c, 5u},
    {622664u, aot_fast_00098048, 5u},
    {622674u, aot_fast_00098052, 2u},
    {622680u, aot_fast_00098058, 7u},
    {622696u, aot_fast_00098068, 1u},
    {622698u, aot_fast_0009806a, 1u},
    {622700u, aot_fast_0009806c, 1u},
    {622704u, aot_fast_00098070, 1u},
    {622708u, aot_fast_00098074, 2u},
    {622720u, aot_fast_00098080, 5u},
    {622732u, aot_fast_0009808c, 5u},
    {622742u, aot_fast_00098096, 2u},
    {622748u, aot_fast_0009809c, 7u},
    {622764u, aot_fast_000980ac, 1u},
    {622766u, aot_fast_000980ae, 1u},
    {622768u, aot_fast_000980b0, 1u},
    {622772u, aot_fast_000980b4, 1u},
    {622776u, aot_fast_000980b8, 2u},
    {625512u, aot_fast_00098b68, 7u},
    {625528u, aot_fast_00098b78, 5u},
    {625538u, aot_fast_00098b82, 2u},
    {625544u, aot_fast_00098b88, 8u},
    {625562u, aot_fast_00098b9a, 2u},
    {625570u, aot_fast_00098ba2, 1u},
    {625572u, aot_fast_00098ba4, 1u},
    {625800u, aot_fast_00098c88, 5u},
    {625812u, aot_fast_00098c94, 5u},
    {625822u, aot_fast_00098c9e, 2u},
    {625828u, aot_fast_00098ca4, 7u},
    {625844u, aot_fast_00098cb4, 2u},
    {625852u, aot_fast_00098cbc, 1u},
    {625854u, aot_fast_00098cbe, 1u},
    {625868u, aot_fast_00098ccc, 5u},
    {625880u, aot_fast_00098cd8, 5u},
    {625890u, aot_fast_00098ce2, 2u},
    {625896u, aot_fast_00098ce8, 7u},
    {625912u, aot_fast_00098cf8, 2u},
    {625920u, aot_fast_00098d00, 1u},
    {625922u, aot_fast_00098d02, 1u},
    {655248u, aot_fast_0009ff90, 6u},
    {655352u, aot_fast_0009fff8, 6u},
    {686060u, aot_fast_000a77ec, 12u},
    {686088u, aot_fast_000a7808, 3u},
    {686098u, aot_fast_000a7812, 2u},
    {686104u, aot_fast_000a7818, 2u},
    {688984u, aot_fast_000a8358, 4u},
    {688996u, aot_fast_000a8364, 1u},
    {688998u, aot_fast_000a8366, 3u},
    {689004u, aot_fast_000a836c, 2u},
    {689010u, aot_fast_000a8372, 2u},
    {689014u, aot_fast_000a8376, 5u},
    {689026u, aot_fast_000a8382, 1u},
    {689040u, aot_fast_000a8390, 21u},
    {689094u, aot_fast_000a83c6, 2u},
    {689098u, aot_fast_000a83ca, 5u},
    {689108u, aot_fast_000a83d4, 7u},
    {689128u, aot_fast_000a83e8, 9u},
    {689146u, aot_fast_000a83fa, 5u},
    {689156u, aot_fast_000a8404, 6u},
    {689172u, aot_fast_000a8414, 6u},
    {689190u, aot_fast_000a8426, 4u},
    {689202u, aot_fast_000a8432, 6u},
    {689220u, aot_fast_000a8444, 32u},
    {689306u, aot_fast_000a849a, 7u},
    {689328u, aot_fast_000a84b0, 13u},
    {689362u, aot_fast_000a84d2, 13u},
    {689396u, aot_fast_000a84f4, 9u},
    {689420u, aot_fast_000a850c, 7u},
    {689440u, aot_fast_000a8520, 44u},
    {689568u, aot_fast_000a85a0, 7u},
    {689590u, aot_fast_000a85b6, 42u},
    {689714u, aot_fast_000a8632, 7u},
    {689736u, aot_fast_000a8648, 13u},
    {689770u, aot_fast_000a866a, 13u},
    {689804u, aot_fast_000a868c, 62u},
    {689974u, aot_fast_000a8736, 8u},
    {689996u, aot_fast_000a874c, 13u},
    {690030u, aot_fast_000a876e, 13u},
    {690064u, aot_fast_000a8790, 4u},
    {690076u, aot_fast_000a879c, 6u},
    {690094u, aot_fast_000a87ae, 4u},
    {690106u, aot_fast_000a87ba, 6u},
    {690124u, aot_fast_000a87cc, 4u},
    {690136u, aot_fast_000a87d8, 6u},
    {690154u, aot_fast_000a87ea, 30u},
    {690234u, aot_fast_000a883a, 8u},
    {690256u, aot_fast_000a8850, 13u},
    {690290u, aot_fast_000a8872, 13u},
    {690324u, aot_fast_000a8894, 9u},
    {690348u, aot_fast_000a88ac, 7u},
    {690368u, aot_fast_000a88c0, 42u},
    {690488u, aot_fast_000a8938, 8u},
    {690510u, aot_fast_000a894e, 41u},
    {690626u, aot_fast_000a89c2, 7u},
    {690644u, aot_fast_000a89d4, 13u},
    {690672u, aot_fast_000a89f0, 13u},
    {690700u, aot_fast_000a8a0c, 62u},
    {690866u, aot_fast_000a8ab2, 7u},
    {690882u, aot_fast_000a8ac2, 13u},
    {690914u, aot_fast_000a8ae2, 13u},
    {690946u, aot_fast_000a8b02, 4u},
    {690956u, aot_fast_000a8b0c, 6u},
    {690970u, aot_fast_000a8b1a, 3u},
    {690978u, aot_fast_000a8b22, 6u},
    {690994u, aot_fast_000a8b32, 6u},
    {691010u, aot_fast_000a8b42, 6u},
    {691026u, aot_fast_000a8b52, 6u},
    {691042u, aot_fast_000a8b62, 6u},
    {691058u, aot_fast_000a8b72, 6u},
    {691074u, aot_fast_000a8b82, 6u},
    {691090u, aot_fast_000a8b92, 6u},
    {691824u, aot_fast_000a8e70, 8u},
    {691842u, aot_fast_000a8e82, 4u},
    {691850u, aot_fast_000a8e8a, 1u},
    {691852u, aot_fast_000a8e8c, 5u},
    {691864u, aot_fast_000a8e98, 6u},
    {691896u, aot_fast_000a8eb8, 5u},
    {691908u, aot_fast_000a8ec4, 11u},
    {691930u, aot_fast_000a8eda, 1u},
    {691934u, aot_fast_000a8ede, 2u},
    {691940u, aot_fast_000a8ee4, 1u},
    {691942u, aot_fast_000a8ee6, 2u},
    {691952u, aot_fast_000a8ef0, 1u},
    {691958u, aot_fast_000a8ef6, 2u},
    {691962u, aot_fast_000a8efa, 5u},
    {691976u, aot_fast_000a8f08, 1u},
    {691978u, aot_fast_000a8f0a, 2u},
    {691982u, aot_fast_000a8f0e, 1u},
    {691990u, aot_fast_000a8f16, 1u},
    {691996u, aot_fast_000a8f1c, 2u},
    {692000u, aot_fast_000a8f20, 3u},
    {692008u, aot_fast_000a8f28, 1u},
    {692012u, aot_fast_000a8f2c, 2u},
    {692016u, aot_fast_000a8f30, 1u},
    {692020u, aot_fast_000a8f34, 1u},
    {692024u, aot_fast_000a8f38, 1u},
    {692026u, aot_fast_000a8f3a, 1u},
    {692040u, aot_fast_000a8f48, 2u},
    {692046u, aot_fast_000a8f4e, 8u},
    {692064u, aot_fast_000a8f60, 2u},
    {697636u, aot_fast_000aa524, 6u},
    {699536u, aot_fast_000aac90, 2u},
    {699540u, aot_fast_000aac94, 14u},
    {699578u, aot_fast_000aacba, 3u},
    {699586u, aot_fast_000aacc2, 4u},
    {699596u, aot_fast_000aaccc, 4u},
    {699608u, aot_fast_000aacd8, 2u},
    {699950u, aot_fast_000aae2e, 2u},
    {699956u, aot_fast_000aae34, 4u},
    {699966u, aot_fast_000aae3e, 3u},
    {699974u, aot_fast_000aae46, 6u},
    {699988u, aot_fast_000aae54, 1u},
    {700360u, aot_fast_000aafc8, 6u},
    {700374u, aot_fast_000aafd6, 4u},
    {700396u, aot_fast_000aafec, 3u},
    {700406u, aot_fast_000aaff6, 1u},
    {700408u, aot_fast_000aaff8, 4u},
    {700416u, aot_fast_000ab000, 2u},
    {700420u, aot_fast_000ab004, 2u},
    {700424u, aot_fast_000ab008, 2u},
    {700428u, aot_fast_000ab00c, 3u},
    {700434u, aot_fast_000ab012, 3u},
    {700442u, aot_fast_000ab01a, 2u},
    {700452u, aot_fast_000ab024, 1u},
    {700458u, aot_fast_000ab02a, 2u},
    {700462u, aot_fast_000ab02e, 3u},
    {700470u, aot_fast_000ab036, 3u},
    {700476u, aot_fast_000ab03c, 1u},
    {700478u, aot_fast_000ab03e, 1u},
    {700480u, aot_fast_000ab040, 2u},
    {700486u, aot_fast_000ab046, 2u},
    {700490u, aot_fast_000ab04a, 2u},
    {700494u, aot_fast_000ab04e, 2u},
    {700498u, aot_fast_000ab052, 2u},
    {700502u, aot_fast_000ab056, 3u},
    {700508u, aot_fast_000ab05c, 3u},
    {700516u, aot_fast_000ab064, 2u},
    {700526u, aot_fast_000ab06e, 1u},
    {700532u, aot_fast_000ab074, 2u},
    {700536u, aot_fast_000ab078, 3u},
    {700544u, aot_fast_000ab080, 3u},
    {700550u, aot_fast_000ab086, 1u},
    {700552u, aot_fast_000ab088, 1u},
    {700554u, aot_fast_000ab08a, 2u},
    {700560u, aot_fast_000ab090, 2u},
    {700564u, aot_fast_000ab094, 1u},
    {700566u, aot_fast_000ab096, 2u},
    {700570u, aot_fast_000ab09a, 1u},
    {700574u, aot_fast_000ab09e, 1u},
    {700576u, aot_fast_000ab0a0, 3u},
    {700582u, aot_fast_000ab0a6, 1u},
    {700584u, aot_fast_000ab0a8, 2u},
    {700590u, aot_fast_000ab0ae, 2u},
    {700628u, aot_fast_000ab0d4, 5u},
    {700644u, aot_fast_000ab0e4, 1u},
    {700650u, aot_fast_000ab0ea, 2u},
    {700654u, aot_fast_000ab0ee, 3u},
    {700668u, aot_fast_000ab0fc, 1u},
    {700674u, aot_fast_000ab102, 2u},
    {700678u, aot_fast_000ab106, 3u},
    {700686u, aot_fast_000ab10e, 4u},
    {700694u, aot_fast_000ab116, 2u},
    {700698u, aot_fast_000ab11a, 2u},
    {700704u, aot_fast_000ab120, 2u},
    {700710u, aot_fast_000ab126, 4u},
    {700720u, aot_fast_000ab130, 4u},
    {700734u, aot_fast_000ab13e, 1u},
    {700740u, aot_fast_000ab144, 2u},
    {700744u, aot_fast_000ab148, 3u},
    {700752u, aot_fast_000ab150, 2u},
    {700756u, aot_fast_000ab154, 2u},
    {700760u, aot_fast_000ab158, 2u},
    {700766u, aot_fast_000ab15e, 2u},
    {700772u, aot_fast_000ab164, 2u},
    {701280u, aot_fast_000ab360, 3u},
    {701286u, aot_fast_000ab366, 4u},
    {701296u, aot_fast_000ab370, 3u},
    {701308u, aot_fast_000ab37c, 1u},
    {701314u, aot_fast_000ab382, 2u},
    {701318u, aot_fast_000ab386, 7u},
    {701336u, aot_fast_000ab398, 2u},
    {701340u, aot_fast_000ab39c, 5u},
    {701354u, aot_fast_000ab3aa, 2u},
    {701360u, aot_fast_000ab3b0, 5u},
    {701370u, aot_fast_000ab3ba, 4u},
    {701550u, aot_fast_000ab46e, 2u},
    {701562u, aot_fast_000ab47a, 1u},
    {701568u, aot_fast_000ab480, 2u},
    {701572u, aot_fast_000ab484, 4u},
    {701584u, aot_fast_000ab490, 2u},
    {701594u, aot_fast_000ab49a, 1u},
    {701600u, aot_fast_000ab4a0, 2u},
    {701606u, aot_fast_000ab4a6, 3u},
    {701614u, aot_fast_000ab4ae, 3u},
    {701622u, aot_fast_000ab4b6, 3u},
    {701628u, aot_fast_000ab4bc, 3u},
    {701634u, aot_fast_000ab4c2, 3u},
    {701640u, aot_fast_000ab4c8, 5u},
    {701652u, aot_fast_000ab4d4, 2u},
    {701662u, aot_fast_000ab4de, 1u},
    {701668u, aot_fast_000ab4e4, 2u},
    {701674u, aot_fast_000ab4ea, 3u},
    {701682u, aot_fast_000ab4f2, 3u},
    {701688u, aot_fast_000ab4f8, 1u},
    {701690u, aot_fast_000ab4fa, 1u},
    {701694u, aot_fast_000ab4fe, 1u},
    {701702u, aot_fast_000ab506, 3u},
    {701708u, aot_fast_000ab50c, 1u},
    {703588u, aot_fast_000abc64, 5u},
    {709296u, aot_fast_000ad2b0, 6u},
    {710452u, aot_fast_000ad734, 5u},
    {711076u, aot_fast_000ad9a4, 7u},
    {711092u, aot_fast_000ad9b4, 5u},
    {711102u, aot_fast_000ad9be, 2u},
    {711108u, aot_fast_000ad9c4, 8u},
    {711126u, aot_fast_000ad9d6, 1u},
    {711128u, aot_fast_000ad9d8, 1u},
    {711130u, aot_fast_000ad9da, 1u},
    {711134u, aot_fast_000ad9de, 1u},
    {711142u, aot_fast_000ad9e6, 1u},
    {711146u, aot_fast_000ad9ea, 1u},
    {711150u, aot_fast_000ad9ee, 12u},
    {711186u, aot_fast_000ada12, 1u},
    {711190u, aot_fast_000ada16, 3u},
    {711196u, aot_fast_000ada1c, 3u},
    {711202u, aot_fast_000ada22, 3u},
    {711210u, aot_fast_000ada2a, 4u},
    {711218u, aot_fast_000ada32, 2u},
    {711228u, aot_fast_000ada3c, 1u},
    {711236u, aot_fast_000ada44, 3u},
    {711242u, aot_fast_000ada4a, 6u},
    {711254u, aot_fast_000ada56, 2u},
    {711258u, aot_fast_000ada5a, 3u},
    {711266u, aot_fast_000ada62, 7u},
    {711282u, aot_fast_000ada72, 3u},
    {711390u, aot_fast_000adade, 3u},
    {711402u, aot_fast_000adaea, 4u},
    {711424u, aot_fast_000adb00, 4u},
    {711432u, aot_fast_000adb08, 2u},
    {713108u, aot_fast_000ae194, 5u},
    {713120u, aot_fast_000ae1a0, 5u},
    {713130u, aot_fast_000ae1aa, 2u},
    {713136u, aot_fast_000ae1b0, 7u},
    {713152u, aot_fast_000ae1c0, 1u},
    {713154u, aot_fast_000ae1c2, 1u},
    {713156u, aot_fast_000ae1c4, 1u},
    {713160u, aot_fast_000ae1c8, 1u},
    {713166u, aot_fast_000ae1ce, 5u},
    {713176u, aot_fast_000ae1d8, 5u},
    {713188u, aot_fast_000ae1e4, 5u},
    {713198u, aot_fast_000ae1ee, 2u},
    {713204u, aot_fast_000ae1f4, 7u},
    {713220u, aot_fast_000ae204, 1u},
    {713222u, aot_fast_000ae206, 1u},
    {713224u, aot_fast_000ae208, 1u},
    {713228u, aot_fast_000ae20c, 1u},
    {713234u, aot_fast_000ae212, 5u},
    {713244u, aot_fast_000ae21c, 5u},
    {713256u, aot_fast_000ae228, 5u},
    {713266u, aot_fast_000ae232, 2u},
    {713272u, aot_fast_000ae238, 7u},
    {713288u, aot_fast_000ae248, 1u},
    {713290u, aot_fast_000ae24a, 1u},
    {713292u, aot_fast_000ae24c, 1u},
    {713296u, aot_fast_000ae250, 1u},
    {713302u, aot_fast_000ae256, 13u},
    {713334u, aot_fast_000ae276, 4u},
    {713342u, aot_fast_000ae27e, 5u},
    {713352u, aot_fast_000ae288, 5u},
    {713362u, aot_fast_000ae292, 6u},
    {713374u, aot_fast_000ae29e, 9u},
    {713396u, aot_fast_000ae2b4, 1u},
    {713400u, aot_fast_000ae2b8, 7u},
    {713416u, aot_fast_000ae2c8, 5u},
    {713428u, aot_fast_000ae2d4, 1u},
    {713434u, aot_fast_000ae2da, 2u},
    {713440u, aot_fast_000ae2e0, 3u},
    {713450u, aot_fast_000ae2ea, 2u},
    {713458u, aot_fast_000ae2f2, 6u},
    {713470u, aot_fast_000ae2fe, 9u},
    {713492u, aot_fast_000ae314, 2u},
    {713788u, aot_fast_000ae43c, 2u},
    {713798u, aot_fast_000ae446, 1u},
    {713804u, aot_fast_000ae44c, 2u},
    {713808u, aot_fast_000ae450, 3u},
    {713818u, aot_fast_000ae45a, 2u},
    {713932u, aot_fast_000ae4cc, 2u},
    {713942u, aot_fast_000ae4d6, 1u},
    {713950u, aot_fast_000ae4de, 2u},
    {713954u, aot_fast_000ae4e2, 3u},
    {713962u, aot_fast_000ae4ea, 2u},
    {713966u, aot_fast_000ae4ee, 2u},
    {713976u, aot_fast_000ae4f8, 1u},
    {713984u, aot_fast_000ae500, 2u},
    {713988u, aot_fast_000ae504, 3u},
    {713998u, aot_fast_000ae50e, 2u},
    {714004u, aot_fast_000ae514, 1u},
    {714090u, aot_fast_000ae56a, 3u},
    {714098u, aot_fast_000ae572, 1u},
    {714110u, aot_fast_000ae57e, 3u},
    {714118u, aot_fast_000ae586, 1u},
    {715968u, aot_fast_000aecc0, 7u},
    {715984u, aot_fast_000aecd0, 5u},
    {715994u, aot_fast_000aecda, 2u},
    {716000u, aot_fast_000aece0, 8u},
    {716018u, aot_fast_000aecf2, 2u},
    {716026u, aot_fast_000aecfa, 1u},
    {716028u, aot_fast_000aecfc, 1u},
    {716256u, aot_fast_000aede0, 5u},
    {716268u, aot_fast_000aedec, 5u},
    {716278u, aot_fast_000aedf6, 2u},
    {716284u, aot_fast_000aedfc, 7u},
    {716300u, aot_fast_000aee0c, 2u},
    {716308u, aot_fast_000aee14, 1u},
    {716310u, aot_fast_000aee16, 1u},
    {716324u, aot_fast_000aee24, 5u},
    {716336u, aot_fast_000aee30, 5u},
    {716346u, aot_fast_000aee3a, 2u},
    {716352u, aot_fast_000aee40, 7u},
    {716368u, aot_fast_000aee50, 2u},
    {716376u, aot_fast_000aee58, 1u},
    {716378u, aot_fast_000aee5a, 1u},
    {760044u, aot_fast_000b98ec, 1u},
    {783776u, aot_fast_000bf5a0, 3u},
    {783784u, aot_fast_000bf5a8, 12u},
    {783812u, aot_fast_000bf5c4, 9u},
    {783832u, aot_fast_000bf5d8, 12u},
    {783860u, aot_fast_000bf5f4, 6u},
    {783872u, aot_fast_000bf600, 5u},
    {783884u, aot_fast_000bf60c, 6u},
    {783898u, aot_fast_000bf61a, 3u},
    {783906u, aot_fast_000bf622, 4u},
    {783916u, aot_fast_000bf62c, 8u},
    {783934u, aot_fast_000bf63e, 2u},
    {783940u, aot_fast_000bf644, 1u},
    {783944u, aot_fast_000bf648, 4u},
    {783954u, aot_fast_000bf652, 1u},
    {784148u, aot_fast_000bf714, 5u},
    {784160u, aot_fast_000bf720, 6u},
    {784174u, aot_fast_000bf72e, 3u},
    {784182u, aot_fast_000bf736, 4u},
    {784192u, aot_fast_000bf740, 8u},
    {784210u, aot_fast_000bf752, 2u},
    {784216u, aot_fast_000bf758, 1u},
    {784220u, aot_fast_000bf75c, 4u},
    {784230u, aot_fast_000bf766, 1u},
    {784240u, aot_fast_000bf770, 5u},
    {784252u, aot_fast_000bf77c, 6u},
    {784266u, aot_fast_000bf78a, 3u},
    {784274u, aot_fast_000bf792, 4u},
    {784284u, aot_fast_000bf79c, 8u},
    {784302u, aot_fast_000bf7ae, 2u},
    {784308u, aot_fast_000bf7b4, 1u},
    {784312u, aot_fast_000bf7b8, 4u},
    {784322u, aot_fast_000bf7c2, 1u},
    {786464u, aot_fast_000c0020, 3u},
    {786476u, aot_fast_000c002c, 2u},
    {786480u, aot_fast_000c0030, 4u},
    {786492u, aot_fast_000c003c, 5u},
    {786504u, aot_fast_000c0048, 3u},
    {786512u, aot_fast_000c0050, 2u},
    {786516u, aot_fast_000c0054, 4u},
    {786528u, aot_fast_000c0060, 5u},
    {786540u, aot_fast_000c006c, 3u},
    {786548u, aot_fast_000c0074, 3u},
    {786556u, aot_fast_000c007c, 3u},
    {786568u, aot_fast_000c0088, 3u},
    {786576u, aot_fast_000c0090, 4u},
    {786644u, aot_fast_000c00d4, 5u},
    {786656u, aot_fast_000c00e0, 3u},
    {786696u, aot_fast_000c0108, 3u},
    {786704u, aot_fast_000c0110, 1u},
    {786706u, aot_fast_000c0112, 6u},
    {788088u, aot_fast_000c0678, 6u},
    {788104u, aot_fast_000c0688, 2u},
    {788108u, aot_fast_000c068c, 3u},
    {788154u, aot_fast_000c06ba, 2u},
    {788162u, aot_fast_000c06c2, 4u},
    {788170u, aot_fast_000c06ca, 3u},
    {788182u, aot_fast_000c06d6, 5u},
    {788192u, aot_fast_000c06e0, 5u},
    {788202u, aot_fast_000c06ea, 2u},
    {788208u, aot_fast_000c06f0, 4u},
    {788218u, aot_fast_000c06fa, 4u},
    {788228u, aot_fast_000c0704, 1u},
    {788230u, aot_fast_000c0706, 5u},
    {788250u, aot_fast_000c071a, 2u},
    {788308u, aot_fast_000c0754, 1u},
    {788312u, aot_fast_000c0758, 4u},
    {788320u, aot_fast_000c0760, 1u},
    {788322u, aot_fast_000c0762, 1u},
    {788368u, aot_fast_000c0790, 4u},
    {788382u, aot_fast_000c079e, 6u},
    {788402u, aot_fast_000c07b2, 1u},
    {788408u, aot_fast_000c07b8, 1u},
    {788410u, aot_fast_000c07ba, 3u},
    {788418u, aot_fast_000c07c2, 4u},
    {788430u, aot_fast_000c07ce, 2u},
    {788436u, aot_fast_000c07d4, 3u},
    {788442u, aot_fast_000c07da, 2u},
    {788446u, aot_fast_000c07de, 2u},
    {788452u, aot_fast_000c07e4, 6u},
    {788464u, aot_fast_000c07f0, 2u},
    {788472u, aot_fast_000c07f8, 3u},
    {788498u, aot_fast_000c0812, 7u},
    {788518u, aot_fast_000c0826, 1u},
    {788524u, aot_fast_000c082c, 1u},
    {788526u, aot_fast_000c082e, 2u},
    {788574u, aot_fast_000c085e, 3u},
    {788582u, aot_fast_000c0866, 2u},
    {788588u, aot_fast_000c086c, 1u},
    {788590u, aot_fast_000c086e, 2u},
    {788596u, aot_fast_000c0874, 1u},
    {788598u, aot_fast_000c0876, 2u},
    {788604u, aot_fast_000c087c, 1u},
    {789068u, aot_fast_000c0a4c, 7u},
    {789092u, aot_fast_000c0a64, 5u},
    {789104u, aot_fast_000c0a70, 1u},
    {789108u, aot_fast_000c0a74, 1u},
    {789110u, aot_fast_000c0a76, 4u},
    {789134u, aot_fast_000c0a8e, 2u},
    {789140u, aot_fast_000c0a94, 3u},
    {789150u, aot_fast_000c0a9e, 10u},
    {789174u, aot_fast_000c0ab6, 2u},
    {789380u, aot_fast_000c0b84, 7u},
    {789396u, aot_fast_000c0b94, 1u},
    {789398u, aot_fast_000c0b96, 4u},
    {789408u, aot_fast_000c0ba0, 3u},
    {789416u, aot_fast_000c0ba8, 2u},
    {789420u, aot_fast_000c0bac, 2u},
    {789426u, aot_fast_000c0bb2, 1u},
    {789428u, aot_fast_000c0bb4, 11u},
    {789456u, aot_fast_000c0bd0, 2u},
    {789460u, aot_fast_000c0bd4, 5u},
    {789472u, aot_fast_000c0be0, 2u},
    {789476u, aot_fast_000c0be4, 3u},
    {789482u, aot_fast_000c0bea, 3u},
    {789490u, aot_fast_000c0bf2, 3u},
    {789496u, aot_fast_000c0bf8, 2u},
    {789500u, aot_fast_000c0bfc, 2u},
    {789506u, aot_fast_000c0c02, 1u},
    {789508u, aot_fast_000c0c04, 1u},
    {789514u, aot_fast_000c0c0a, 3u},
    {789542u, aot_fast_000c0c26, 2u},
    {789546u, aot_fast_000c0c2a, 2u},
    {789550u, aot_fast_000c0c2e, 2u},
    {789556u, aot_fast_000c0c34, 2u},
    {789560u, aot_fast_000c0c38, 4u},
    {789568u, aot_fast_000c0c40, 3u},
    {789578u, aot_fast_000c0c4a, 1u},
    {789582u, aot_fast_000c0c4e, 5u},
    {789600u, aot_fast_000c0c60, 1u},
    {789604u, aot_fast_000c0c64, 3u},
    {790188u, aot_fast_000c0eac, 3u},
    {790196u, aot_fast_000c0eb4, 3u},
    {790204u, aot_fast_000c0ebc, 4u},
    {790212u, aot_fast_000c0ec4, 3u},
    {790220u, aot_fast_000c0ecc, 3u},
    {790230u, aot_fast_000c0ed6, 1u},
    {790232u, aot_fast_000c0ed8, 4u},
    {790250u, aot_fast_000c0eea, 5u},
    {791360u, aot_fast_000c1340, 5u},
    {791376u, aot_fast_000c1350, 2u},
    {791380u, aot_fast_000c1354, 4u},
    {791388u, aot_fast_000c135c, 5u},
    {791398u, aot_fast_000c1366, 3u},
    {791406u, aot_fast_000c136e, 4u},
    {791414u, aot_fast_000c1376, 2u},
    {791424u, aot_fast_000c1380, 1u},
    {791430u, aot_fast_000c1386, 2u},
    {791434u, aot_fast_000c138a, 2u},
    {791908u, aot_fast_000c1564, 5u},
    {791918u, aot_fast_000c156e, 1u},
    {791920u, aot_fast_000c1570, 2u},
    {791924u, aot_fast_000c1574, 2u},
    {791930u, aot_fast_000c157a, 4u},
    {791940u, aot_fast_000c1584, 2u},
    {791944u, aot_fast_000c1588, 5u},
    {791964u, aot_fast_000c159c, 1u},
    {791968u, aot_fast_000c15a0, 3u},
    {791976u, aot_fast_000c15a8, 4u},
    {791986u, aot_fast_000c15b2, 2u},
    {791990u, aot_fast_000c15b6, 5u},
    {792000u, aot_fast_000c15c0, 2u},
    {792004u, aot_fast_000c15c4, 2u},
    {792008u, aot_fast_000c15c8, 1u},
    {792012u, aot_fast_000c15cc, 1u},
    {792014u, aot_fast_000c15ce, 2u},
    {792018u, aot_fast_000c15d2, 3u},
    {792024u, aot_fast_000c15d8, 7u},
    {792040u, aot_fast_000c15e8, 4u},
    {792072u, aot_fast_000c1608, 3u},
    {792082u, aot_fast_000c1612, 7u},
    {792098u, aot_fast_000c1622, 1u},
    {792102u, aot_fast_000c1626, 2u},
    {792106u, aot_fast_000c162a, 3u},
    {792118u, aot_fast_000c1636, 7u},
    {792134u, aot_fast_000c1646, 4u},
    {792144u, aot_fast_000c1650, 5u},
    {792158u, aot_fast_000c165e, 3u},
    {792164u, aot_fast_000c1664, 3u},
    {792174u, aot_fast_000c166e, 8u},
    {792194u, aot_fast_000c1682, 3u},
    {792200u, aot_fast_000c1688, 5u},
    {792210u, aot_fast_000c1692, 1u},
    {792212u, aot_fast_000c1694, 4u},
    {792222u, aot_fast_000c169e, 4u},
    {792228u, aot_fast_000c16a4, 2u},
    {792232u, aot_fast_000c16a8, 2u},
    {792236u, aot_fast_000c16ac, 5u},
    {792256u, aot_fast_000c16c0, 1u},
    {792260u, aot_fast_000c16c4, 3u},
    {792268u, aot_fast_000c16cc, 4u},
    {792278u, aot_fast_000c16d6, 2u},
    {792282u, aot_fast_000c16da, 5u},
    {792292u, aot_fast_000c16e4, 2u},
    {792296u, aot_fast_000c16e8, 3u},
    {792304u, aot_fast_000c16f0, 1u},
    {792306u, aot_fast_000c16f2, 2u},
    {792310u, aot_fast_000c16f6, 10u},
    {792334u, aot_fast_000c170e, 3u},
    {792908u, aot_fast_000c194c, 6u},
    {792922u, aot_fast_000c195a, 2u},
    {792928u, aot_fast_000c1960, 1u},
    {792930u, aot_fast_000c1962, 4u},
    {792942u, aot_fast_000c196e, 3u},
    {793728u, aot_fast_000c1c80, 6u},
    {793744u, aot_fast_000c1c90, 2u},
    {793760u, aot_fast_000c1ca0, 2u},
    {793766u, aot_fast_000c1ca6, 2u},
    {793776u, aot_fast_000c1cb0, 2u},
    {793784u, aot_fast_000c1cb8, 2u},
    {793788u, aot_fast_000c1cbc, 2u},
    {793794u, aot_fast_000c1cc2, 1u},
    {793796u, aot_fast_000c1cc4, 3u},
    {793804u, aot_fast_000c1ccc, 3u},
    {793812u, aot_fast_000c1cd4, 2u},
    {793816u, aot_fast_000c1cd8, 6u},
    {793830u, aot_fast_000c1ce6, 1u},
    {793832u, aot_fast_000c1ce8, 4u},
    {793842u, aot_fast_000c1cf2, 1u},
    {793850u, aot_fast_000c1cfa, 2u},
    {793858u, aot_fast_000c1d02, 2u},
    {793862u, aot_fast_000c1d06, 2u},
    {793868u, aot_fast_000c1d0c, 2u},
    {793872u, aot_fast_000c1d10, 2u},
    {793876u, aot_fast_000c1d14, 2u},
    {793948u, aot_fast_000c1d5c, 4u},
    {793970u, aot_fast_000c1d72, 2u},
    {793976u, aot_fast_000c1d78, 2u},
    {793982u, aot_fast_000c1d7e, 1u},
    {793984u, aot_fast_000c1d80, 1u},
    {793990u, aot_fast_000c1d86, 2u},
    {793996u, aot_fast_000c1d8c, 1u},
    {794072u, aot_fast_000c1dd8, 3u},
    {794080u, aot_fast_000c1de0, 12u},
    {794110u, aot_fast_000c1dfe, 1u},
    {794114u, aot_fast_000c1e02, 1u},
    {794118u, aot_fast_000c1e06, 4u},
    {794128u, aot_fast_000c1e10, 12u},
    {794158u, aot_fast_000c1e2e, 1u},
    {794162u, aot_fast_000c1e32, 1u},
    {794166u, aot_fast_000c1e36, 2u},
    {794172u, aot_fast_000c1e3c, 1u},
    {794178u, aot_fast_000c1e42, 3u},
    {794186u, aot_fast_000c1e4a, 2u},
    {794196u, aot_fast_000c1e54, 1u},
    {794204u, aot_fast_000c1e5c, 1u},
    {794210u, aot_fast_000c1e62, 2u},
    {794214u, aot_fast_000c1e66, 2u},
    {794220u, aot_fast_000c1e6c, 2u},
    {794226u, aot_fast_000c1e72, 2u},
    {794230u, aot_fast_000c1e76, 3u},
    {794240u, aot_fast_000c1e80, 1u},
    {794242u, aot_fast_000c1e82, 2u},
    {794252u, aot_fast_000c1e8c, 3u},
    {794260u, aot_fast_000c1e94, 3u},
    {794270u, aot_fast_000c1e9e, 5u},
    {794284u, aot_fast_000c1eac, 2u},
    {794288u, aot_fast_000c1eb0, 2u},
    {794298u, aot_fast_000c1eba, 1u},
    {794304u, aot_fast_000c1ec0, 2u},
    {794308u, aot_fast_000c1ec4, 1u},
    {794312u, aot_fast_000c1ec8, 1u},
    {794316u, aot_fast_000c1ecc, 4u},
    {794326u, aot_fast_000c1ed6, 2u},
    {794996u, aot_fast_000c2174, 5u},
    {795006u, aot_fast_000c217e, 16u},
    {795042u, aot_fast_000c21a2, 7u},
    {795058u, aot_fast_000c21b2, 5u},
    {795068u, aot_fast_000c21bc, 7u},
    {795084u, aot_fast_000c21cc, 12u},
    {795108u, aot_fast_000c21e4, 2u},
    {795114u, aot_fast_000c21ea, 19u},
    {795184u, aot_fast_000c2230, 5u},
    {795194u, aot_fast_000c223a, 16u},
    {795228u, aot_fast_000c225c, 5u},
    {795240u, aot_fast_000c2268, 6u},
    {795254u, aot_fast_000c2276, 5u},
    {795266u, aot_fast_000c2282, 11u},
    {795288u, aot_fast_000c2298, 2u},
    {795296u, aot_fast_000c22a0, 19u},
    {795720u, aot_fast_000c2448, 4u},
    {795728u, aot_fast_000c2450, 30u},
    {795788u, aot_fast_000c248c, 7u},
    {795804u, aot_fast_000c249c, 1u},
    {795806u, aot_fast_000c249e, 2u},
    {795812u, aot_fast_000c24a4, 30u},
    {795908u, aot_fast_000c2504, 4u},
    {795916u, aot_fast_000c250c, 30u},
    {795976u, aot_fast_000c2548, 7u},
    {795992u, aot_fast_000c2558, 1u},
    {795994u, aot_fast_000c255a, 2u},
    {796000u, aot_fast_000c2560, 30u},
    {796096u, aot_fast_000c25c0, 4u},
    {796106u, aot_fast_000c25ca, 31u},
    {796176u, aot_fast_000c2610, 6u},
    {796190u, aot_fast_000c261e, 1u},
    {796194u, aot_fast_000c2622, 2u},
    {796200u, aot_fast_000c2628, 30u},
    {796300u, aot_fast_000c268c, 4u},
    {796310u, aot_fast_000c2696, 31u},
    {796380u, aot_fast_000c26dc, 6u},
    {796394u, aot_fast_000c26ea, 1u},
    {796398u, aot_fast_000c26ee, 2u},
    {796404u, aot_fast_000c26f4, 30u},
    {825956u, aot_fast_000c9a64, 3u},
    {825974u, aot_fast_000c9a76, 4u},
    {825984u, aot_fast_000c9a80, 3u},
    {825992u, aot_fast_000c9a88, 1u},
    {826002u, aot_fast_000c9a92, 5u},
    {826016u, aot_fast_000c9aa0, 4u},
    {826024u, aot_fast_000c9aa8, 3u},
    {826034u, aot_fast_000c9ab2, 2u},
    {826038u, aot_fast_000c9ab6, 2u},
    {826042u, aot_fast_000c9aba, 2u},
    {826048u, aot_fast_000c9ac0, 3u},
    {826054u, aot_fast_000c9ac6, 2u},
    {826058u, aot_fast_000c9aca, 2u},
    {826062u, aot_fast_000c9ace, 2u},
    {826066u, aot_fast_000c9ad2, 2u},
    {826070u, aot_fast_000c9ad6, 3u},
    {826078u, aot_fast_000c9ade, 2u},
    {826082u, aot_fast_000c9ae2, 2u},
    {826086u, aot_fast_000c9ae6, 1u},
    {826088u, aot_fast_000c9ae8, 4u},
    {826096u, aot_fast_000c9af0, 4u},
    {826104u, aot_fast_000c9af8, 4u},
    {826112u, aot_fast_000c9b00, 2u},
    {826116u, aot_fast_000c9b04, 1u},
    {826128u, aot_fast_000c9b10, 7u},
    {826142u, aot_fast_000c9b1e, 3u},
    {826150u, aot_fast_000c9b26, 2u},
    {826154u, aot_fast_000c9b2a, 1u},
    {826156u, aot_fast_000c9b2c, 8u},
    {826174u, aot_fast_000c9b3e, 1u},
    {826176u, aot_fast_000c9b40, 3u},
    {826184u, aot_fast_000c9b48, 2u},
    {826188u, aot_fast_000c9b4c, 3u},
    {826194u, aot_fast_000c9b52, 1u},
    {826198u, aot_fast_000c9b56, 4u},
    {826206u, aot_fast_000c9b5e, 4u},
    {826214u, aot_fast_000c9b66, 3u},
    {826222u, aot_fast_000c9b6e, 3u},
    {826228u, aot_fast_000c9b74, 1u},
    {826232u, aot_fast_000c9b78, 2u},
    {826236u, aot_fast_000c9b7c, 5u},
    {826250u, aot_fast_000c9b8a, 1u},
    {826254u, aot_fast_000c9b8e, 3u},
    {826266u, aot_fast_000c9b9a, 1u},
    {826270u, aot_fast_000c9b9e, 2u},
    {826274u, aot_fast_000c9ba2, 2u},
    {826292u, aot_fast_000c9bb4, 5u},
    {826306u, aot_fast_000c9bc2, 2u},
    {826312u, aot_fast_000c9bc8, 1u},
    {826316u, aot_fast_000c9bcc, 1u},
    {826318u, aot_fast_000c9bce, 1u},
    {826322u, aot_fast_000c9bd2, 3u},
    {826328u, aot_fast_000c9bd8, 2u},
    {826336u, aot_fast_000c9be0, 3u},
    {826342u, aot_fast_000c9be6, 2u},
    {826350u, aot_fast_000c9bee, 3u},
    {826356u, aot_fast_000c9bf4, 3u},
    {826368u, aot_fast_000c9c00, 1u},
    {826370u, aot_fast_000c9c02, 2u},
    {826374u, aot_fast_000c9c06, 2u},
    {826378u, aot_fast_000c9c0a, 2u},
    {826382u, aot_fast_000c9c0e, 2u},
    {826386u, aot_fast_000c9c12, 1u},
    {826388u, aot_fast_000c9c14, 3u},
    {826394u, aot_fast_000c9c1a, 3u},
    {826402u, aot_fast_000c9c22, 2u},
    {826406u, aot_fast_000c9c26, 1u},
    {826410u, aot_fast_000c9c2a, 7u},
    {826424u, aot_fast_000c9c38, 2u},
    {826428u, aot_fast_000c9c3c, 2u},
    {826432u, aot_fast_000c9c40, 3u},
    {826440u, aot_fast_000c9c48, 2u},
    {826446u, aot_fast_000c9c4e, 6u},
    {826470u, aot_fast_000c9c66, 2u},
    {826488u, aot_fast_000c9c78, 8u},
    {826508u, aot_fast_000c9c8c, 2u},
    {826644u, aot_fast_000c9d14, 7u},
    {826662u, aot_fast_000c9d26, 2u},
    {826680u, aot_fast_000c9d38, 3u},
    {826690u, aot_fast_000c9d42, 3u},
    {826700u, aot_fast_000c9d4c, 1u},
    {826702u, aot_fast_000c9d4e, 4u},
    {826710u, aot_fast_000c9d56, 3u},
    {826716u, aot_fast_000c9d5c, 2u},
    {826722u, aot_fast_000c9d62, 2u},
    {826726u, aot_fast_000c9d66, 3u},
    {826734u, aot_fast_000c9d6e, 3u},
    {826742u, aot_fast_000c9d76, 9u},
    {826762u, aot_fast_000c9d8a, 7u},
    {826776u, aot_fast_000c9d98, 2u},
    {826782u, aot_fast_000c9d9e, 1u},
    {826784u, aot_fast_000c9da0, 5u},
    {826794u, aot_fast_000c9daa, 2u},
    {826798u, aot_fast_000c9dae, 2u},
    {826802u, aot_fast_000c9db2, 3u},
    {826810u, aot_fast_000c9dba, 3u},
    {826818u, aot_fast_000c9dc2, 2u},
    {826824u, aot_fast_000c9dc8, 1u},
    {826828u, aot_fast_000c9dcc, 2u},
    {826832u, aot_fast_000c9dd0, 1u},
    {826836u, aot_fast_000c9dd4, 4u},
    {826846u, aot_fast_000c9dde, 4u},
    {826854u, aot_fast_000c9de6, 2u},
    {826858u, aot_fast_000c9dea, 1u},
    {826860u, aot_fast_000c9dec, 3u},
    {826870u, aot_fast_000c9df6, 5u},
    {826900u, aot_fast_000c9e14, 2u},
    {826904u, aot_fast_000c9e18, 7u},
    {826920u, aot_fast_000c9e28, 3u},
    {826928u, aot_fast_000c9e30, 3u},
    {826938u, aot_fast_000c9e3a, 5u},
    {826968u, aot_fast_000c9e58, 2u},
    {826972u, aot_fast_000c9e5c, 9u},
    {826994u, aot_fast_000c9e72, 2u},
    {826998u, aot_fast_000c9e76, 6u},
    {827018u, aot_fast_000c9e8a, 2u},
    {827036u, aot_fast_000c9e9c, 4u},
    {827048u, aot_fast_000c9ea8, 3u},
    {827056u, aot_fast_000c9eb0, 1u},
    {827058u, aot_fast_000c9eb2, 2u},
    {827062u, aot_fast_000c9eb6, 4u},
    {827072u, aot_fast_000c9ec0, 3u},
    {827078u, aot_fast_000c9ec6, 2u},
    {827082u, aot_fast_000c9eca, 5u},
    {827092u, aot_fast_000c9ed4, 3u},
    {827098u, aot_fast_000c9eda, 2u},
    {827102u, aot_fast_000c9ede, 1u},
    {827104u, aot_fast_000c9ee0, 2u},
    {827110u, aot_fast_000c9ee6, 3u},
    {827220u, aot_fast_000c9f54, 3u},
    {827232u, aot_fast_000c9f60, 2u},
    {827236u, aot_fast_000c9f64, 3u},
    {827246u, aot_fast_000c9f6e, 1u},
    {827252u, aot_fast_000c9f74, 1u},
    {827258u, aot_fast_000c9f7a, 1u},
    {827260u, aot_fast_000c9f7c, 4u},
    {827272u, aot_fast_000c9f88, 4u},
    {827284u, aot_fast_000c9f94, 3u},
    {827296u, aot_fast_000c9fa0, 3u},
    {827310u, aot_fast_000c9fae, 2u},
    {827316u, aot_fast_000c9fb4, 1u},
    {827318u, aot_fast_000c9fb6, 2u},
    {827324u, aot_fast_000c9fbc, 1u},
    {827326u, aot_fast_000c9fbe, 3u},
    {827336u, aot_fast_000c9fc8, 1u},
    {827338u, aot_fast_000c9fca, 2u},
    {827344u, aot_fast_000c9fd0, 4u},
    {827356u, aot_fast_000c9fdc, 2u},
    {827362u, aot_fast_000c9fe2, 4u},
    {827370u, aot_fast_000c9fea, 2u},
    {827374u, aot_fast_000c9fee, 2u},
    {827380u, aot_fast_000c9ff4, 2u},
    {827384u, aot_fast_000c9ff8, 3u},
    {827394u, aot_fast_000ca002, 1u},
    {827398u, aot_fast_000ca006, 4u},
    {827406u, aot_fast_000ca00e, 3u},
    {827414u, aot_fast_000ca016, 5u},
    {827426u, aot_fast_000ca022, 2u},
    {827430u, aot_fast_000ca026, 3u},
    {827438u, aot_fast_000ca02e, 4u},
    {827448u, aot_fast_000ca038, 3u},
    {827456u, aot_fast_000ca040, 2u},
    {827460u, aot_fast_000ca044, 4u},
    {827472u, aot_fast_000ca050, 2u},
    {827476u, aot_fast_000ca054, 3u},
    {827482u, aot_fast_000ca05a, 1u},
    {827484u, aot_fast_000ca05c, 1u},
    {827488u, aot_fast_000ca060, 4u},
    {827498u, aot_fast_000ca06a, 3u},
    {827504u, aot_fast_000ca070, 1u},
    {827508u, aot_fast_000ca074, 2u},
    {827512u, aot_fast_000ca078, 2u},
    {827516u, aot_fast_000ca07c, 1u},
    {827522u, aot_fast_000ca082, 2u},
    {827528u, aot_fast_000ca088, 2u},
    {827536u, aot_fast_000ca090, 1u},
    {827538u, aot_fast_000ca092, 2u},
    {827544u, aot_fast_000ca098, 1u},
    {827548u, aot_fast_000ca09c, 2u},
    {827552u, aot_fast_000ca0a0, 3u},
    {827566u, aot_fast_000ca0ae, 2u},
    {827572u, aot_fast_000ca0b4, 5u},
    {827584u, aot_fast_000ca0c0, 3u},
    {827592u, aot_fast_000ca0c8, 1u},
    {827594u, aot_fast_000ca0ca, 3u},
    {827602u, aot_fast_000ca0d2, 2u},
    {827606u, aot_fast_000ca0d6, 1u},
    {827608u, aot_fast_000ca0d8, 3u},
    {827614u, aot_fast_000ca0de, 5u},
    {827626u, aot_fast_000ca0ea, 3u},
    {827632u, aot_fast_000ca0f0, 3u},
    {827638u, aot_fast_000ca0f6, 10u},
    {827660u, aot_fast_000ca10c, 1u},
    {827668u, aot_fast_000ca114, 1u},
    {827670u, aot_fast_000ca116, 1u},
    {827674u, aot_fast_000ca11a, 4u},
    {827696u, aot_fast_000ca130, 2u},
    {827700u, aot_fast_000ca134, 1u},
    {827704u, aot_fast_000ca138, 1u},
    {827706u, aot_fast_000ca13a, 3u},
    {827714u, aot_fast_000ca142, 1u},
    {827716u, aot_fast_000ca144, 2u},
    {827722u, aot_fast_000ca14a, 2u},
    {827726u, aot_fast_000ca14e, 3u},
    {827734u, aot_fast_000ca156, 4u},
    {827744u, aot_fast_000ca160, 6u},
    {827756u, aot_fast_000ca16c, 1u},
    {827758u, aot_fast_000ca16e, 2u},
    {827780u, aot_fast_000ca184, 7u},
    {827800u, aot_fast_000ca198, 5u},
    {827810u, aot_fast_000ca1a2, 1u},
    {827814u, aot_fast_000ca1a6, 1u},
    {827816u, aot_fast_000ca1a8, 1u},
    {827822u, aot_fast_000ca1ae, 1u},
    {827824u, aot_fast_000ca1b0, 1u},
    {827830u, aot_fast_000ca1b6, 2u},
    {827834u, aot_fast_000ca1ba, 3u},
    {827844u, aot_fast_000ca1c4, 1u},
    {827848u, aot_fast_000ca1c8, 2u},
    {828044u, aot_fast_000ca28c, 2u},
    {828114u, aot_fast_000ca2d2, 2u},
    {828320u, aot_fast_000ca3a0, 2u},
    {828328u, aot_fast_000ca3a8, 1u},
    {828336u, aot_fast_000ca3b0, 3u},
    {828348u, aot_fast_000ca3bc, 2u},
    {828356u, aot_fast_000ca3c4, 1u},
    {828364u, aot_fast_000ca3cc, 1u},
    {828372u, aot_fast_000ca3d4, 1u},
    {828380u, aot_fast_000ca3dc, 1u},
    {828388u, aot_fast_000ca3e4, 1u},
    {828396u, aot_fast_000ca3ec, 1u},
    {828464u, aot_fast_000ca430, 1u},
    {828532u, aot_fast_000ca474, 1u},
    {828552u, aot_fast_000ca488, 1u},
    {828572u, aot_fast_000ca49c, 1u},
    {828576u, aot_fast_000ca4a0, 8u},
    {828602u, aot_fast_000ca4ba, 3u},
    {828612u, aot_fast_000ca4c4, 8u},
    {828638u, aot_fast_000ca4de, 3u},
    {828648u, aot_fast_000ca4e8, 8u},
    {828674u, aot_fast_000ca502, 3u},
    {828684u, aot_fast_000ca50c, 8u},
    {828710u, aot_fast_000ca526, 3u},
    {828720u, aot_fast_000ca530, 8u},
    {828746u, aot_fast_000ca54a, 3u},
    {828756u, aot_fast_000ca554, 2u},
    {828760u, aot_fast_000ca558, 2u},
    {828764u, aot_fast_000ca55c, 9u},
    {828782u, aot_fast_000ca56e, 1u},
    {828784u, aot_fast_000ca570, 4u},
    {828794u, aot_fast_000ca57a, 1u},
    {828796u, aot_fast_000ca57c, 2u},
    {828800u, aot_fast_000ca580, 7u},
    {828816u, aot_fast_000ca590, 3u},
    {828826u, aot_fast_000ca59a, 6u},
    {828844u, aot_fast_000ca5ac, 2u},
    {828850u, aot_fast_000ca5b2, 3u},
    {828856u, aot_fast_000ca5b8, 2u},
    {828862u, aot_fast_000ca5be, 7u},
    {828878u, aot_fast_000ca5ce, 6u},
    {828892u, aot_fast_000ca5dc, 1u},
    {828902u, aot_fast_000ca5e6, 1u},
    {828908u, aot_fast_000ca5ec, 4u},
    {828922u, aot_fast_000ca5fa, 1u},
    {828926u, aot_fast_000ca5fe, 2u},
    {828936u, aot_fast_000ca608, 1u},
    {828948u, aot_fast_000ca614, 3u},
    {828956u, aot_fast_000ca61c, 3u},
    {828966u, aot_fast_000ca626, 2u},
    {828972u, aot_fast_000ca62c, 2u},
    {828976u, aot_fast_000ca630, 4u},
    {828986u, aot_fast_000ca63a, 1u},
    {828990u, aot_fast_000ca63e, 2u},
    {828998u, aot_fast_000ca646, 1u},
    {829004u, aot_fast_000ca64c, 2u},
    {829008u, aot_fast_000ca650, 3u},
    {829016u, aot_fast_000ca658, 6u},
    {829034u, aot_fast_000ca66a, 3u},
    {829042u, aot_fast_000ca672, 3u},
    {829050u, aot_fast_000ca67a, 1u},
    {829052u, aot_fast_000ca67c, 2u},
    {829058u, aot_fast_000ca682, 1u},
    {829066u, aot_fast_000ca68a, 4u},
    {829084u, aot_fast_000ca69c, 2u},
    {829088u, aot_fast_000ca6a0, 2u},
    {829092u, aot_fast_000ca6a4, 2u},
    {829098u, aot_fast_000ca6aa, 3u},
    {829108u, aot_fast_000ca6b4, 1u},
    {829110u, aot_fast_000ca6b6, 1u},
    {829112u, aot_fast_000ca6b8, 2u},
    {829116u, aot_fast_000ca6bc, 2u},
    {829120u, aot_fast_000ca6c0, 7u},
    {829138u, aot_fast_000ca6d2, 2u},
    {829148u, aot_fast_000ca6dc, 3u},
    {829158u, aot_fast_000ca6e6, 5u},
    {829170u, aot_fast_000ca6f2, 1u},
    {829172u, aot_fast_000ca6f4, 1u},
    {829178u, aot_fast_000ca6fa, 5u},
    {829190u, aot_fast_000ca706, 2u},
    {829194u, aot_fast_000ca70a, 2u},
    {829200u, aot_fast_000ca710, 6u},
    {829216u, aot_fast_000ca720, 3u},
    {829224u, aot_fast_000ca728, 6u},
    {829240u, aot_fast_000ca738, 2u},
    {829244u, aot_fast_000ca73c, 2u},
    {829248u, aot_fast_000ca740, 2u},
    {829254u, aot_fast_000ca746, 5u},
    {829272u, aot_fast_000ca758, 1u},
    {829274u, aot_fast_000ca75a, 2u},
    {829278u, aot_fast_000ca75e, 2u},
    {829284u, aot_fast_000ca764, 3u},
    {829296u, aot_fast_000ca770, 1u},
    {829300u, aot_fast_000ca774, 3u},
    {829306u, aot_fast_000ca77a, 3u},
    {829314u, aot_fast_000ca782, 6u},
    {829330u, aot_fast_000ca792, 2u},
    {829334u, aot_fast_000ca796, 2u},
    {829340u, aot_fast_000ca79c, 5u},
    {829354u, aot_fast_000ca7aa, 2u},
    {829360u, aot_fast_000ca7b0, 2u},
    {829366u, aot_fast_000ca7b6, 3u},
    {829376u, aot_fast_000ca7c0, 2u},
    {829384u, aot_fast_000ca7c8, 1u},
    {829386u, aot_fast_000ca7ca, 3u},
    {829396u, aot_fast_000ca7d4, 5u},
    {829410u, aot_fast_000ca7e2, 1u},
    {829412u, aot_fast_000ca7e4, 1u},
    {829416u, aot_fast_000ca7e8, 2u},
    {829422u, aot_fast_000ca7ee, 1u},
    {829424u, aot_fast_000ca7f0, 1u},
    {829426u, aot_fast_000ca7f2, 2u},
    {831120u, aot_fast_000cae90, 1u},
    {831122u, aot_fast_000cae92, 1u},
    {831152u, aot_fast_000caeb0, 1u},
    {831154u, aot_fast_000caeb2, 1u},
};
const uint32_t agr_aot_fast_block_count = 1712u;

const AgrAotEntry agr_aot_fast_hash[] = {
    {0u, 0, 0u},
    {0u, 0, 0u},
    {605508u, aot_fast_00093d44, 1u},
    {826342u, aot_fast_000c9be6, 2u},
    {825992u, aot_fast_000c9a88, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {792174u, aot_fast_000c166e, 8u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {716346u, aot_fast_000aee3a, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {599908u, aot_fast_00092764, 1u},
    {829284u, aot_fast_000ca764, 3u},
    {599208u, aot_fast_000924a8, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {596058u, aot_fast_0009185a, 3u},
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
    {829426u, aot_fast_000ca7f2, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {827326u, aot_fast_000c9fbe, 3u},
    {294496u, aot_fast_00047e60, 9u},
    {793858u, aot_fast_000c1d02, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {620776u, aot_fast_000978e8, 4u},
    {784266u, aot_fast_000bf78a, 3u},
    {783916u, aot_fast_000bf62c, 8u},
    {0u, 0, 0u},
    {701296u, aot_fast_000ab370, 3u},
    {0u, 0, 0u},
    {618676u, aot_fast_000970b4, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600192u, aot_fast_00092880, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {713130u, aot_fast_000ae1aa, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {686104u, aot_fast_000a7818, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601734u, aot_fast_00092e86, 2u},
    {0u, 0, 0u},
    {601034u, aot_fast_00092bca, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {829360u, aot_fast_000ca7b0, 2u},
    {0u, 0, 0u},
    {689396u, aot_fast_000a84f4, 9u},
    {0u, 0, 0u},
    {295480u, aot_fast_00048238, 2u},
    {295130u, aot_fast_000480da, 6u},
    {713272u, aot_fast_000ae238, 7u},
    {827260u, aot_fast_000c9f7c, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {293380u, aot_fast_00047a04, 2u},
    {293030u, aot_fast_000478a6, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601876u, aot_fast_00092f14, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {788192u, aot_fast_000c06e0, 5u},
    {0u, 0, 0u},
    {295972u, aot_fast_00048424, 9u},
    {0u, 0, 0u},
    {295272u, aot_fast_00048168, 6u},
    {0u, 0, 0u},
    {794284u, aot_fast_000c1eac, 2u},
    {605518u, aot_fast_00093d4e, 1u},
    {826702u, aot_fast_000c9d4e, 4u},
    {293522u, aot_fast_00047a92, 5u},
    {293172u, aot_fast_00047934, 6u},
    {826002u, aot_fast_000c9a92, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602718u, aot_fast_0009325e, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {625544u, aot_fast_00098b88, 8u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {690030u, aot_fast_000a876e, 13u},
    {796176u, aot_fast_000c2610, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {827544u, aot_fast_000ca098, 1u},
    {0u, 0, 0u},
    {605660u, aot_fast_00093ddc, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {596068u, aot_fast_00091864, 2u},
    {0u, 0, 0u},
    {603560u, aot_fast_000935a8, 20u},
    {783784u, aot_fast_000bf5a8, 12u},
    {791976u, aot_fast_000c15a8, 4u},
    {602510u, aot_fast_0009318e, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600060u, aot_fast_000927fc, 1u},
    {0u, 0, 0u},
    {599360u, aot_fast_00092540, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {827336u, aot_fast_000c9fc8, 1u},
    {0u, 0, 0u},
    {793868u, aot_fast_000c1d0c, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {292756u, aot_fast_00047794, 3u},
    {792118u, aot_fast_000c1636, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {692064u, aot_fast_000a8f60, 2u},
    {601602u, aot_fast_00092e02, 3u},
    {625828u, aot_fast_00098ca4, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600202u, aot_fast_0009288a, 3u},
    {0u, 0, 0u},
    {828878u, aot_fast_000ca5ce, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826428u, aot_fast_000c9c3c, 2u},
    {711390u, aot_fast_000adade, 3u},
    {826078u, aot_fast_000c9ade, 2u},
    {0u, 0, 0u},
    {603844u, aot_fast_000936c4, 14u},
    {792260u, aot_fast_000c16c4, 3u},
    {0u, 0, 0u},
    {602794u, aot_fast_000932aa, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601744u, aot_fast_00092e90, 2u},
    {831120u, aot_fast_000cae90, 1u},
    {601044u, aot_fast_00092bd4, 1u},
    {789110u, aot_fast_000c0a76, 4u},
    {789460u, aot_fast_000c0bd4, 5u},
    {690106u, aot_fast_000a87ba, 6u},
    {788410u, aot_fast_000c07ba, 3u},
    {0u, 0, 0u},
    {828320u, aot_fast_000ca3a0, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826920u, aot_fast_000c9e28, 3u},
    {0u, 0, 0u},
    {293740u, aot_fast_00047b6c, 9u},
    {0u, 0, 0u},
    {620720u, aot_fast_000978b0, 3u},
    {784210u, aot_fast_000bf752, 2u},
    {783860u, aot_fast_000bf5f4, 6u},
    {603286u, aot_fast_00093496, 5u},
    {0u, 0, 0u},
    {602586u, aot_fast_000931da, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601536u, aot_fast_00092dc0, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {599786u, aot_fast_000926ea, 3u},
    {296332u, aot_fast_0004858c, 6u},
    {788202u, aot_fast_000c06ea, 2u},
    {295632u, aot_fast_000482d0, 9u},
    {606578u, aot_fast_00094172, 1u},
    {796394u, aot_fast_000c26ea, 1u},
    {827062u, aot_fast_000c9eb6, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {792194u, aot_fast_000c1682, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {290732u, aot_fast_00046fac, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {691090u, aot_fast_000a8b92, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {599928u, aot_fast_00092778, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {294724u, aot_fast_00047f44, 2u},
    {294374u, aot_fast_00047de6, 6u},
    {605670u, aot_fast_00093de6, 3u},
    {826154u, aot_fast_000c9b2a, 1u},
    {826854u, aot_fast_000c9de6, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {791986u, aot_fast_000c15b2, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602520u, aot_fast_00093198, 1u},
    {0u, 0, 0u},
    {601820u, aot_fast_00092edc, 2u},
    {0u, 0, 0u},
    {601120u, aot_fast_00092c20, 2u},
    {690882u, aot_fast_000a8ac2, 13u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {828746u, aot_fast_000ca54a, 3u},
    {828396u, aot_fast_000ca3ec, 1u},
    {0u, 0, 0u},
    {827696u, aot_fast_000ca130, 2u},
    {294866u, aot_fast_00047fd2, 5u},
    {294516u, aot_fast_00047e74, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {711258u, aot_fast_000ada5a, 3u},
    {620796u, aot_fast_000978fc, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {603362u, aot_fast_000934e2, 5u},
    {0u, 0, 0u},
    {602662u, aot_fast_00093226, 2u},
    {602312u, aot_fast_000930c8, 4u},
    {0u, 0, 0u},
    {716300u, aot_fast_000aee0c, 2u},
    {0u, 0, 0u},
    {600912u, aot_fast_00092b50, 5u},
    {0u, 0, 0u},
    {690324u, aot_fast_000a8894, 9u},
    {689974u, aot_fast_000a8736, 8u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {786528u, aot_fast_000c0060, 5u},
    {827488u, aot_fast_000ca060, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826088u, aot_fast_000c9ae8, 4u},
    {0u, 0, 0u},
    {612396u, aot_fast_0009582c, 2u},
    {0u, 0, 0u},
    {791920u, aot_fast_000c1570, 2u},
    {603154u, aot_fast_00093412, 15u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700408u, aot_fast_000aaff8, 4u},
    {601754u, aot_fast_00092e9a, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600004u, aot_fast_000927c4, 9u},
    {0u, 0, 0u},
    {296200u, aot_fast_00048508, 2u},
    {599304u, aot_fast_00092508, 2u},
    {713292u, aot_fast_000ae24c, 1u},
    {0u, 0, 0u},
    {655248u, aot_fast_0009ff90, 6u},
    {794162u, aot_fast_000c1e32, 1u},
    {793812u, aot_fast_000c1cd4, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {784220u, aot_fast_000bf75c, 4u},
    {0u, 0, 0u},
    {701600u, aot_fast_000ab4a0, 2u},
    {0u, 0, 0u},
    {602596u, aot_fast_000931e4, 5u},
    {700550u, aot_fast_000ab086, 1u},
    {692008u, aot_fast_000a8f28, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {796404u, aot_fast_000c26f4, 30u},
    {829172u, aot_fast_000ca6f4, 1u},
    {295992u, aot_fast_00048438, 6u},
    {713434u, aot_fast_000ae2da, 2u},
    {606588u, aot_fast_0009417c, 1u},
    {0u, 0, 0u},
    {794304u, aot_fast_000c1ec0, 2u},
    {826722u, aot_fast_000c9d62, 2u},
    {827072u, aot_fast_000c9ec0, 3u},
    {0u, 0, 0u},
    {620872u, aot_fast_00097948, 4u},
    {595946u, aot_fast_000917ea, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {716376u, aot_fast_000aee58, 1u},
    {716026u, aot_fast_000aecfa, 1u},
    {609180u, aot_fast_00094b9c, 6u},
    {0u, 0, 0u},
    {600288u, aot_fast_000928e0, 1u},
    {829314u, aot_fast_000ca782, 6u},
    {0u, 0, 0u},
    {599238u, aot_fast_000924c6, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {295084u, aot_fast_000480ac, 9u},
    {622764u, aot_fast_000980ac, 1u},
    {605680u, aot_fast_00093df0, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {711126u, aot_fast_000ad9d6, 1u},
    {292984u, aot_fast_00047878, 9u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {691942u, aot_fast_000a8ee6, 2u},
    {0u, 0, 0u},
    {789546u, aot_fast_000c0c2a, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600080u, aot_fast_00092810, 9u},
    {0u, 0, 0u},
    {828756u, aot_fast_000ca554, 2u},
    {0u, 0, 0u},
    {795288u, aot_fast_000c2298, 2u},
    {827706u, aot_fast_000ca13a, 3u},
    {827356u, aot_fast_000c9fdc, 2u},
    {0u, 0, 0u},
    {605472u, aot_fast_00093d20, 5u},
    {826306u, aot_fast_000c9bc2, 2u},
    {825956u, aot_fast_000c9a64, 3u},
    {0u, 0, 0u},
    {292776u, aot_fast_000477a8, 2u},
    {620456u, aot_fast_000977a8, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602672u, aot_fast_00093230, 1u},
    {602322u, aot_fast_000930d2, 2u},
    {601972u, aot_fast_00092f74, 6u},
    {716310u, aot_fast_000aee16, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {599872u, aot_fast_00092740, 1u},
    {829248u, aot_fast_000ca740, 2u},
    {599172u, aot_fast_00092484, 1u},
    {0u, 0, 0u},
    {713160u, aot_fast_000ae1c8, 1u},
    {622698u, aot_fast_0009806a, 1u},
    {827498u, aot_fast_000ca06a, 3u},
    {826798u, aot_fast_000c9dae, 2u},
    {293968u, aot_fast_00047c50, 2u},
    {293618u, aot_fast_00047af2, 6u},
    {827848u, aot_fast_000ca1c8, 2u},
    {620598u, aot_fast_00097836, 2u},
    {0u, 0, 0u},
    {791930u, aot_fast_000c157a, 4u},
    {0u, 0, 0u},
    {602814u, aot_fast_000932be, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {290468u, aot_fast_00046ea4, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {788430u, aot_fast_000c07ce, 2u},
    {296560u, aot_fast_00048670, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {713302u, aot_fast_000ae256, 13u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {794172u, aot_fast_000c1e3c, 1u},
    {294110u, aot_fast_00047cde, 5u},
    {293760u, aot_fast_00047b80, 6u},
    {711202u, aot_fast_000ada22, 3u},
    {620740u, aot_fast_000978c4, 4u},
    {784230u, aot_fast_000bf766, 1u},
    {792072u, aot_fast_000c1608, 3u},
    {0u, 0, 0u},
    {602956u, aot_fast_0009334c, 9u},
    {602606u, aot_fast_000931ee, 1u},
    {602256u, aot_fast_00093090, 3u},
    {700560u, aot_fast_000ab090, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {689568u, aot_fast_000a85a0, 7u},
    {0u, 0, 0u},
    {295652u, aot_fast_000482e4, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {827082u, aot_fast_000c9eca, 5u},
    {0u, 0, 0u},
    {826382u, aot_fast_000c9c0e, 2u},
    {0u, 0, 0u},
    {620882u, aot_fast_00097952, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {619832u, aot_fast_00097538, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600298u, aot_fast_000928ea, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {599248u, aot_fast_000924d0, 6u},
    {295794u, aot_fast_00048372, 5u},
    {689010u, aot_fast_000a8372, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826174u, aot_fast_000c9b3e, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700494u, aot_fast_000ab04e, 2u},
    {691952u, aot_fast_000a8ef0, 1u},
    {0u, 0, 0u},
    {789556u, aot_fast_000c0c34, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {829116u, aot_fast_000ca6bc, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {827716u, aot_fast_000ca144, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826316u, aot_fast_000c9bcc, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {701336u, aot_fast_000ab398, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601632u, aot_fast_00092e20, 3u},
    {699586u, aot_fast_000aacc2, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {828908u, aot_fast_000ca5ec, 4u},
    {0u, 0, 0u},
    {295728u, aot_fast_00048330, 8u},
    {0u, 0, 0u},
    {622708u, aot_fast_00098074, 2u},
    {786548u, aot_fast_000c0074, 3u},
    {294328u, aot_fast_00047db8, 9u},
    {827508u, aot_fast_000ca074, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {596032u, aot_fast_00091840, 6u},
    {620608u, aot_fast_00097840, 2u},
    {791940u, aot_fast_000c1584, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {290828u, aot_fast_0004700c, 3u},
    {700428u, aot_fast_000ab00c, 3u},
    {0u, 0, 0u},
    {789490u, aot_fast_000c0bf2, 3u},
    {789140u, aot_fast_000c0a94, 3u},
    {0u, 0, 0u},
    {690136u, aot_fast_000a87d8, 6u},
    {829050u, aot_fast_000ca67a, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {793832u, aot_fast_000c1ce8, 4u},
    {826250u, aot_fast_000c9b8a, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {784240u, aot_fast_000bf770, 5u},
    {792082u, aot_fast_000c1612, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700570u, aot_fast_000ab09a, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {690978u, aot_fast_000a8b22, 6u},
    {0u, 0, 0u},
    {788582u, aot_fast_000c0866, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {713804u, aot_fast_000ae44c, 2u},
    {0u, 0, 0u},
    {295312u, aot_fast_00048190, 2u},
    {294962u, aot_fast_00048032, 6u},
    {606608u, aot_fast_00094190, 2u},
    {826742u, aot_fast_000c9d76, 9u},
    {827092u, aot_fast_000c9ed4, 3u},
    {826042u, aot_fast_000c9aba, 2u},
    {293212u, aot_fast_0004795c, 2u},
    {292862u, aot_fast_000477fe, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602408u, aot_fast_00093128, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {829334u, aot_fast_000ca796, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {295454u, aot_fast_0004821e, 5u},
    {295104u, aot_fast_000480c0, 6u},
    {827584u, aot_fast_000ca0c0, 3u},
    {0u, 0, 0u},
    {793766u, aot_fast_000c1ca6, 2u},
    {826184u, aot_fast_000c9b48, 2u},
    {293354u, aot_fast_000479ea, 5u},
    {293004u, aot_fast_0004788c, 6u},
    {711146u, aot_fast_000ad9ea, 1u},
    {784174u, aot_fast_000bf72e, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {691962u, aot_fast_000a8efa, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600100u, aot_fast_00092824, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {827726u, aot_fast_000ca14e, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {605492u, aot_fast_00093d34, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {792158u, aot_fast_000c165e, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601992u, aot_fast_00092f88, 2u},
    {0u, 0, 0u},
    {625868u, aot_fast_00098ccc, 5u},
    {699596u, aot_fast_000aaccc, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {788308u, aot_fast_000c0754, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826818u, aot_fast_000c9dc2, 2u},
    {703588u, aot_fast_000abc64, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602484u, aot_fast_00093174, 1u},
    {0u, 0, 0u},
    {601784u, aot_fast_00092eb8, 3u},
    {691896u, aot_fast_000a8eb8, 5u},
    {601084u, aot_fast_00092bfc, 2u},
    {789150u, aot_fast_000c0a9e, 10u},
    {789500u, aot_fast_000c0bfc, 2u},
    {829410u, aot_fast_000ca7e2, 1u},
    {0u, 0, 0u},
    {828710u, aot_fast_000ca526, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {827660u, aot_fast_000ca10c, 1u},
    {827310u, aot_fast_000c9fae, 2u},
    {0u, 0, 0u},
    {793842u, aot_fast_000c1cf2, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {620760u, aot_fast_000978d8, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {701280u, aot_fast_000ab360, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601576u, aot_fast_00092de8, 4u},
    {0u, 0, 0u},
    {289580u, aot_fast_00046b2c, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {296372u, aot_fast_000485b4, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {622652u, aot_fast_0009803c, 5u},
    {786492u, aot_fast_000c003c, 5u},
    {793984u, aot_fast_000c1d80, 1u},
    {826402u, aot_fast_000c9c22, 2u},
    {293572u, aot_fast_00047ac4, 9u},
    {827102u, aot_fast_000c9ede, 1u},
    {595976u, aot_fast_00091808, 1u},
    {686088u, aot_fast_000a7808, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601018u, aot_fast_00092bba, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {713256u, aot_fast_000ae228, 5u},
    {827594u, aot_fast_000ca0ca, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {793776u, aot_fast_000c1cb0, 2u},
    {826194u, aot_fast_000c9b52, 1u},
    {0u, 0, 0u},
    {620694u, aot_fast_00097896, 5u},
    {603960u, aot_fast_00093738, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601860u, aot_fast_00092f04, 2u},
    {0u, 0, 0u},
    {601160u, aot_fast_00092c48, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600110u, aot_fast_0009282e, 1u},
    {788526u, aot_fast_000c082e, 2u},
    {599410u, aot_fast_00092572, 2u},
    {689172u, aot_fast_000a8414, 6u},
    {714098u, aot_fast_000ae572, 1u},
    {606552u, aot_fast_00094158, 1u},
    {0u, 0, 0u},
    {294556u, aot_fast_00047e9c, 2u},
    {294206u, aot_fast_00047d3e, 6u},
    {605502u, aot_fast_00093d3e, 2u},
    {826336u, aot_fast_000c9be0, 3u},
    {827036u, aot_fast_000c9e9c, 4u},
    {595910u, aot_fast_000917c6, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {699956u, aot_fast_000aae34, 4u},
    {0u, 0, 0u},
    {625528u, aot_fast_00098b78, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {599902u, aot_fast_0009275e, 2u},
    {829278u, aot_fast_000ca75e, 2u},
    {599202u, aot_fast_000924a2, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {786568u, aot_fast_000c0088, 3u},
    {294698u, aot_fast_00047f2a, 5u},
    {294348u, aot_fast_00047dcc, 6u},
    {826828u, aot_fast_000c9dcc, 2u},
    {826128u, aot_fast_000c9b10, 7u},
    {827528u, aot_fast_000ca088, 2u},
    {0u, 0, 0u},
    {792310u, aot_fast_000c16f6, 10u},
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
    {599344u, aot_fast_00092530, 2u},
    {295890u, aot_fast_000483d2, 6u},
    {828720u, aot_fast_000ca530, 8u},
    {827670u, aot_fast_000ca116, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826270u, aot_fast_000c9b9e, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {792102u, aot_fast_000c1626, 2u},
    {701640u, aot_fast_000ab4c8, 5u},
    {602986u, aot_fast_0009336a, 1u},
    {602636u, aot_fast_0009320c, 3u},
    {700590u, aot_fast_000ab0ae, 2u},
    {601936u, aot_fast_00092f50, 1u},
    {601586u, aot_fast_00092df2, 7u},
    {625812u, aot_fast_00098c94, 5u},
    {699540u, aot_fast_000aac94, 14u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {828862u, aot_fast_000ca5be, 7u},
    {296032u, aot_fast_00048460, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826762u, aot_fast_000c9d8a, 7u},
    {0u, 0, 0u},
    {826062u, aot_fast_000c9ace, 2u},
    {0u, 0, 0u},
    {612370u, aot_fast_00095812, 5u},
    {686098u, aot_fast_000a7812, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602778u, aot_fast_0009329a, 1u},
    {602428u, aot_fast_0009313c, 10u},
    {0u, 0, 0u},
    {601728u, aot_fast_00092e80, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {829354u, aot_fast_000ca7aa, 2u},
    {829004u, aot_fast_000ca64c, 2u},
    {296174u, aot_fast_000484ee, 5u},
    {689040u, aot_fast_000a8390, 21u},
    {713266u, aot_fast_000ae232, 2u},
    {713966u, aot_fast_000ae4ee, 2u},
    {786644u, aot_fast_000c00d4, 5u},
    {826904u, aot_fast_000c9e18, 7u},
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
    {691982u, aot_fast_000a8f0e, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {599770u, aot_fast_000926da, 2u},
    {828796u, aot_fast_000ca57c, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {294916u, aot_fast_00048004, 9u},
    {0u, 0, 0u},
    {605512u, aot_fast_00093d48, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {292816u, aot_fast_000477d0, 9u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601662u, aot_fast_00092e3e, 1u},
    {699966u, aot_fast_000aae3e, 3u},
    {625538u, aot_fast_00098b82, 2u},
    {691074u, aot_fast_000a8b82, 6u},
    {716000u, aot_fast_000aece0, 8u},
    {599912u, aot_fast_00092768, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {827538u, aot_fast_000ca092, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826488u, aot_fast_000c9c78, 8u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {620638u, aot_fast_0009785e, 15u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {603204u, aot_fast_00093444, 10u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700458u, aot_fast_000ab02a, 2u},
    {601804u, aot_fast_00092ecc, 5u},
    {601454u, aot_fast_00092d6e, 3u},
    {601104u, aot_fast_00092c10, 1u},
    {690866u, aot_fast_000a8ab2, 7u},
    {790220u, aot_fast_000c0ecc, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {828380u, aot_fast_000ca3dc, 1u},
    {713342u, aot_fast_000ae27e, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {793862u, aot_fast_000c1d06, 2u},
    {293800u, aot_fast_00047ba8, 2u},
    {293450u, aot_fast_00047a4a, 6u},
    {711242u, aot_fast_000ada4a, 6u},
    {760044u, aot_fast_000b98ec, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602646u, aot_fast_00093216, 1u},
    {602296u, aot_fast_000930b8, 4u},
    {0u, 0, 0u},
    {716284u, aot_fast_000aedfc, 7u},
    {625822u, aot_fast_00098c9e, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {295692u, aot_fast_0004830c, 2u},
    {827822u, aot_fast_000ca1ae, 1u},
    {786512u, aot_fast_000c0050, 2u},
    {827472u, aot_fast_000ca050, 2u},
    {0u, 0, 0u},
    {293942u, aot_fast_00047c36, 5u},
    {293592u, aot_fast_00047ad8, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {290792u, aot_fast_00046fe8, 3u},
    {601738u, aot_fast_00092e8a, 2u},
    {691850u, aot_fast_000a8e8a, 1u},
    {601038u, aot_fast_00092bce, 2u},
    {789104u, aot_fast_000c0a70, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {599288u, aot_fast_000924f8, 1u},
    {713976u, aot_fast_000ae4f8, 1u},
    {0u, 0, 0u},
    {827614u, aot_fast_000ca0de, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {793796u, aot_fast_000c1cc4, 3u},
    {826214u, aot_fast_000c9b66, 3u},
    {0u, 0, 0u},
    {620714u, aot_fast_000978aa, 1u},
    {595788u, aot_fast_0009174c, 59u},
    {0u, 0, 0u},
    {701584u, aot_fast_000ab490, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601530u, aot_fast_00092dba, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600130u, aot_fast_00092842, 2u},
    {599780u, aot_fast_000926e4, 3u},
    {714118u, aot_fast_000ae586, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {606572u, aot_fast_0009416c, 2u},
    {827406u, aot_fast_000ca00e, 3u},
    {794288u, aot_fast_000c1eb0, 2u},
    {827056u, aot_fast_000c9eb0, 1u},
    {826356u, aot_fast_000c9bf4, 3u},
    {827756u, aot_fast_000ca16c, 1u},
    {0u, 0, 0u},
    {620506u, aot_fast_000977da, 1u},
    {0u, 0, 0u},
    {603422u, aot_fast_0009351e, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600272u, aot_fast_000928d0, 2u},
    {0u, 0, 0u},
    {828948u, aot_fast_000ca614, 3u},
    {0u, 0, 0u},
    {688984u, aot_fast_000a8358, 4u},
    {0u, 0, 0u},
    {622748u, aot_fast_0009809c, 7u},
    {827548u, aot_fast_000ca09c, 2u},
    {794080u, aot_fast_000c1de0, 12u},
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
    {790230u, aot_fast_000c0ed6, 1u},
    {601464u, aot_fast_00092d78, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600064u, aot_fast_00092800, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {713352u, aot_fast_000ae288, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {294160u, aot_fast_00047d10, 9u},
    {793872u, aot_fast_000c1d10, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601956u, aot_fast_00092f64, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {599856u, aot_fast_00092730, 6u},
    {0u, 0, 0u},
    {828532u, aot_fast_000ca474, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {827482u, aot_fast_000ca05a, 1u},
    {0u, 0, 0u},
    {826782u, aot_fast_000c9d9e, 1u},
    {826432u, aot_fast_000c9c40, 3u},
    {826082u, aot_fast_000c9ae2, 2u},
    {0u, 0, 0u},
    {596006u, aot_fast_00091826, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602798u, aot_fast_000932ae, 1u},
    {602448u, aot_fast_00093150, 5u},
    {700752u, aot_fast_000ab150, 2u},
    {601748u, aot_fast_00092e94, 3u},
    {0u, 0, 0u},
    {601048u, aot_fast_00092bd8, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {296544u, aot_fast_00048660, 5u},
    {828674u, aot_fast_000ca502, 3u},
    {295844u, aot_fast_000483a4, 9u},
    {0u, 0, 0u},
    {295144u, aot_fast_000480e8, 2u},
    {294794u, aot_fast_00047f8a, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {711186u, aot_fast_000ada12, 1u},
    {293044u, aot_fast_000478b4, 2u},
    {596148u, aot_fast_000918b4, 5u},
    {603990u, aot_fast_00093756, 2u},
    {701594u, aot_fast_000ab49a, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700544u, aot_fast_000ab080, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {796398u, aot_fast_000c26ee, 2u},
    {828816u, aot_fast_000ca590, 3u},
    {689202u, aot_fast_000a8432, 6u},
    {713428u, aot_fast_000ae2d4, 1u},
    {295286u, aot_fast_00048176, 5u},
    {294936u, aot_fast_00048018, 6u},
    {606582u, aot_fast_00094176, 2u},
    {605532u, aot_fast_00093d5c, 2u},
    {793948u, aot_fast_000c1d5c, 4u},
    {794298u, aot_fast_000c1eba, 1u},
    {293186u, aot_fast_00047942, 5u},
    {292836u, aot_fast_000477e4, 6u},
    {826016u, aot_fast_000c9aa0, 4u},
    {826716u, aot_fast_000c9d5c, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700686u, aot_fast_000ab10e, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {789398u, aot_fast_000c0b96, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {796190u, aot_fast_000c261e, 1u},
    {599232u, aot_fast_000924c0, 3u},
    {0u, 0, 0u},
    {713220u, aot_fast_000ae204, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826858u, aot_fast_000c9dea, 1u},
    {826508u, aot_fast_000c9c8c, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {784148u, aot_fast_000bf714, 5u},
    {791990u, aot_fast_000c15b6, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602524u, aot_fast_0009319c, 2u},
    {700478u, aot_fast_000ab03e, 1u},
    {290528u, aot_fast_00046ee0, 3u},
    {601474u, aot_fast_00092d82, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600074u, aot_fast_0009280a, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {713362u, aot_fast_000ae292, 6u},
    {827700u, aot_fast_000ca134, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {620800u, aot_fast_00097900, 3u},
    {292770u, aot_fast_000477a2, 1u},
    {783940u, aot_fast_000bf644, 1u},
    {0u, 0, 0u},
    {603016u, aot_fast_00093388, 19u},
    {602666u, aot_fast_0009322a, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {828892u, aot_fast_000ca5dc, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {713154u, aot_fast_000ae1c2, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {620592u, aot_fast_00097830, 3u},
    {0u, 0, 0u},
    {791924u, aot_fast_000c1574, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602458u, aot_fast_0009315a, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {829384u, aot_fast_000ca7c8, 1u},
    {689770u, aot_fast_000a866a, 13u},
    {689420u, aot_fast_000a850c, 7u},
    {795916u, aot_fast_000c250c, 30u},
    {295504u, aot_fast_00048250, 5u},
    {713296u, aot_fast_000ae250, 1u},
    {827284u, aot_fast_000c9f94, 3u},
    {794166u, aot_fast_000c1e36, 2u},
    {793816u, aot_fast_000c1cd8, 6u},
    {828684u, aot_fast_000ca50c, 8u},
    {293404u, aot_fast_00047a1c, 9u},
    {711196u, aot_fast_000ada1c, 3u},
    {829034u, aot_fast_000ca66a, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700554u, aot_fast_000ab08a, 2u},
    {601900u, aot_fast_00092f2c, 2u},
    {692012u, aot_fast_000a8f2c, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {296346u, aot_fast_0004859a, 5u},
    {713788u, aot_fast_000ae43c, 2u},
    {828826u, aot_fast_000ca59a, 6u},
    {0u, 0, 0u},
    {827426u, aot_fast_000ca022, 2u},
    {794308u, aot_fast_000c1ec4, 1u},
    {605542u, aot_fast_00093d66, 2u},
    {826726u, aot_fast_000c9d66, 3u},
    {0u, 0, 0u},
    {792908u, aot_fast_000c194c, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602742u, aot_fast_00093276, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {789408u, aot_fast_000c0ba0, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {796200u, aot_fast_000c2628, 30u},
    {0u, 0, 0u},
    {689004u, aot_fast_000a836c, 2u},
    {0u, 0, 0u},
    {622768u, aot_fast_000980b0, 1u},
    {0u, 0, 0u},
    {294388u, aot_fast_00047df4, 2u},
    {294038u, aot_fast_00047c96, 6u},
    {0u, 0, 0u},
    {711130u, aot_fast_000ad9da, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {792000u, aot_fast_000c15c0, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601834u, aot_fast_00092eea, 2u},
    {790250u, aot_fast_000c0eea, 5u},
    {789550u, aot_fast_000c0c2e, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {829110u, aot_fast_000ca6b6, 1u},
    {599384u, aot_fast_00092558, 2u},
    {689146u, aot_fast_000a83fa, 5u},
    {795992u, aot_fast_000c2558, 1u},
    {828760u, aot_fast_000ca558, 2u},
    {0u, 0, 0u},
    {294530u, aot_fast_00047e82, 5u},
    {294180u, aot_fast_00047d24, 6u},
    {794242u, aot_fast_000c1e82, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {292780u, aot_fast_000477ac, 3u},
    {0u, 0, 0u},
    {603376u, aot_fast_000934f0, 14u},
    {0u, 0, 0u},
    {602676u, aot_fast_00093234, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601626u, aot_fast_00092e1a, 3u},
    {625852u, aot_fast_00098cbc, 1u},
    {600926u, aot_fast_00092b5e, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {828902u, aot_fast_000ca5e6, 1u},
    {828552u, aot_fast_000ca488, 1u},
    {0u, 0, 0u},
    {795084u, aot_fast_000c21cc, 12u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826802u, aot_fast_000c9db2, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700772u, aot_fast_000ab164, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {789134u, aot_fast_000c0a8e, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {295864u, aot_fast_000483b8, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {596168u, aot_fast_000918c8, 2u},
    {0u, 0, 0u},
    {783884u, aot_fast_000bf60c, 6u},
    {701614u, aot_fast_000ab4ae, 3u},
    {791376u, aot_fast_000c1350, 2u},
    {602610u, aot_fast_000931f2, 2u},
    {700564u, aot_fast_000ab094, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {599810u, aot_fast_00092702, 3u},
    {0u, 0, 0u},
    {296006u, aot_fast_00048446, 5u},
    {713798u, aot_fast_000ae446, 1u},
    {606602u, aot_fast_0009418a, 2u},
    {786476u, aot_fast_000c002c, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826386u, aot_fast_000c9c12, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602752u, aot_fast_00093280, 7u},
    {0u, 0, 0u},
    {290756u, aot_fast_00046fc4, 3u},
    {601702u, aot_fast_00092e66, 5u},
    {601352u, aot_fast_00092d08, 28u},
    {0u, 0, 0u},
    {789068u, aot_fast_000c0a4c, 7u},
    {600302u, aot_fast_000928ee, 2u},
    {690064u, aot_fast_000a8790, 4u},
    {689714u, aot_fast_000a8632, 7u},
    {788368u, aot_fast_000c0790, 4u},
    {689014u, aot_fast_000a8376, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {294748u, aot_fast_00047f5c, 9u},
    {794110u, aot_fast_000c1dfe, 1u},
    {793760u, aot_fast_000c1ca0, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {620678u, aot_fast_00097886, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602544u, aot_fast_000931b0, 11u},
    {700498u, aot_fast_000ab052, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601144u, aot_fast_00092c38, 2u},
    {789560u, aot_fast_000c0c38, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {829120u, aot_fast_000ca6c0, 7u},
    {0u, 0, 0u},
    {295940u, aot_fast_00048404, 8u},
    {689156u, aot_fast_000a8404, 6u},
    {0u, 0, 0u},
    {827370u, aot_fast_000c9fea, 2u},
    {794252u, aot_fast_000c1e8c, 3u},
    {605486u, aot_fast_00093d2e, 2u},
    {0u, 0, 0u},
    {711282u, aot_fast_000ada72, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {701690u, aot_fast_000ab4fa, 1u},
    {701340u, aot_fast_000ab39c, 5u},
    {602686u, aot_fast_0009323e, 1u},
    {602336u, aot_fast_000930e0, 1u},
    {0u, 0, 0u},
    {716324u, aot_fast_000aee24, 5u},
    {0u, 0, 0u},
    {625512u, aot_fast_00098b68, 7u},
    {0u, 0, 0u},
    {600236u, aot_fast_000928ac, 7u},
    {690348u, aot_fast_000a88ac, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {295382u, aot_fast_000481d6, 6u},
    {827512u, aot_fast_000ca078, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {293632u, aot_fast_00047b00, 2u},
    {293282u, aot_fast_000479a2, 6u},
    {620612u, aot_fast_00097844, 2u},
    {711424u, aot_fast_000adb00, 4u},
    {791944u, aot_fast_000c1588, 5u},
    {826112u, aot_fast_000c9b00, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601778u, aot_fast_00092eb2, 3u},
    {831154u, aot_fast_000caeb2, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {296224u, aot_fast_00048520, 7u},
    {689440u, aot_fast_000a8520, 44u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {794186u, aot_fast_000c1e4a, 2u},
    {0u, 0, 0u},
    {293774u, aot_fast_00047b8e, 5u},
    {293424u, aot_fast_00047a30, 6u},
    {826254u, aot_fast_000c9b8e, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700574u, aot_fast_000ab09e, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {713808u, aot_fast_000ae450, 3u},
    {295666u, aot_fast_000482f2, 5u},
    {713108u, aot_fast_000ae194, 5u},
    {713458u, aot_fast_000ae2f2, 6u},
    {795728u, aot_fast_000c2450, 30u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {792928u, aot_fast_000c1960, 1u},
    {595970u, aot_fast_00091802, 2u},
    {792228u, aot_fast_000c16a4, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602412u, aot_fast_0009312c, 1u},
    {0u, 0, 0u},
    {691824u, aot_fast_000a8e70, 8u},
    {0u, 0, 0u},
    {789428u, aot_fast_000c0bb4, 11u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {599962u, aot_fast_0009279a, 6u},
    {0u, 0, 0u},
    {713950u, aot_fast_000ae4de, 2u},
    {828638u, aot_fast_000ca4de, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826188u, aot_fast_000c9b4c, 3u},
    {711150u, aot_fast_000ad9ee, 12u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700508u, aot_fast_000ab05c, 3u},
    {0u, 0, 0u},
    {601504u, aot_fast_00092da0, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {297000u, aot_fast_00048828, 14u},
    {788170u, aot_fast_000c06ca, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {827380u, aot_fast_000c9ff4, 2u},
    {0u, 0, 0u},
    {826680u, aot_fast_000c9d38, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {292800u, aot_fast_000477c0, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700650u, aot_fast_000ab0ea, 2u},
    {601996u, aot_fast_00092f8c, 1u},
    {699950u, aot_fast_000aae2e, 2u},
    {715984u, aot_fast_000aecd0, 5u},
    {691058u, aot_fast_000a8b72, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {599896u, aot_fast_00092758, 2u},
    {296442u, aot_fast_000485fa, 6u},
    {599196u, aot_fast_0009249c, 3u},
    {788312u, aot_fast_000c0758, 4u},
    {795804u, aot_fast_000c249c, 1u},
    {827522u, aot_fast_000ca082, 2u},
    {828572u, aot_fast_000ca49c, 1u},
    {828922u, aot_fast_000ca5fa, 1u},
    {293992u, aot_fast_00047c68, 9u},
    {829272u, aot_fast_000ca758, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {792304u, aot_fast_000c16f0, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602488u, aot_fast_00093178, 1u},
    {700442u, aot_fast_000ab01a, 2u},
    {790204u, aot_fast_000c0ebc, 4u},
    {0u, 0, 0u},
    {601088u, aot_fast_00092c00, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {788104u, aot_fast_000c0688, 2u},
    {0u, 0, 0u},
    {828364u, aot_fast_000ca3cc, 1u},
    {0u, 0, 0u},
    {786704u, aot_fast_000c0110, 1u},
    {0u, 0, 0u},
    {794196u, aot_fast_000c1e54, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {701634u, aot_fast_000ab4c2, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700584u, aot_fast_000ab0a8, 2u},
    {0u, 0, 0u},
    {716268u, aot_fast_000aedec, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {788596u, aot_fast_000c0874, 1u},
    {0u, 0, 0u},
    {828856u, aot_fast_000ca5b8, 2u},
    {713818u, aot_fast_000ae45a, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {294976u, aot_fast_00048040, 2u},
    {294626u, aot_fast_00047ee2, 6u},
    {827456u, aot_fast_000ca040, 2u},
    {826406u, aot_fast_000c9c26, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {292876u, aot_fast_0004780c, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602772u, aot_fast_00093294, 2u},
    {602422u, aot_fast_00093136, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600672u, aot_fast_00092a60, 8u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {828998u, aot_fast_000ca646, 1u},
    {828648u, aot_fast_000ca4e8, 8u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {295118u, aot_fast_000480ce, 5u},
    {294768u, aot_fast_00047f70, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826198u, aot_fast_000c9b56, 4u},
    {0u, 0, 0u},
    {293018u, aot_fast_0004789a, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {701568u, aot_fast_000ab480, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {691976u, aot_fast_000a8f08, 1u},
    {0u, 0, 0u},
    {601164u, aot_fast_00092c4c, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {599764u, aot_fast_000926d4, 3u},
    {599414u, aot_fast_00092576, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826690u, aot_fast_000c9d42, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {701360u, aot_fast_000ab3b0, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601656u, aot_fast_00092e38, 3u},
    {715994u, aot_fast_000aecda, 2u},
    {609148u, aot_fast_00094b7c, 3u},
    {0u, 0, 0u},
    {690368u, aot_fast_000a88c0, 42u},
    {788322u, aot_fast_000c0762, 1u},
    {0u, 0, 0u},
    {296102u, aot_fast_000484a6, 6u},
    {0u, 0, 0u},
    {795114u, aot_fast_000c21ea, 19u},
    {622732u, aot_fast_0009808c, 5u},
    {0u, 0, 0u},
    {826832u, aot_fast_000c9dd0, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {791964u, aot_fast_000c159c, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {290852u, aot_fast_00047024, 3u},
    {700452u, aot_fast_000ab024, 1u},
    {0u, 0, 0u},
    {601098u, aot_fast_00092c0a, 2u},
    {789514u, aot_fast_000c0c0a, 3u},
    {690510u, aot_fast_000a894e, 41u},
    {600048u, aot_fast_000927f0, 1u},
    {788464u, aot_fast_000c07f0, 2u},
    {296244u, aot_fast_00048534, 11u},
    {829424u, aot_fast_000ca7f0, 1u},
    {0u, 0, 0u},
    {827674u, aot_fast_000ca11a, 4u},
    {827324u, aot_fast_000c9fbc, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826274u, aot_fast_000c9ba2, 2u},
    {711236u, aot_fast_000ada44, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {792106u, aot_fast_000c162a, 3u},
    {0u, 0, 0u},
    {791406u, aot_fast_000c136e, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601940u, aot_fast_00092f54, 1u},
    {716278u, aot_fast_000aedf6, 2u},
    {0u, 0, 0u},
    {609082u, aot_fast_00094b3a, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {829216u, aot_fast_000ca720, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {295336u, aot_fast_000481a8, 9u},
    {827816u, aot_fast_000ca1a8, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826066u, aot_fast_000c9ad2, 2u},
    {293236u, aot_fast_00047974, 9u},
    {595990u, aot_fast_00091816, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602782u, aot_fast_0009329e, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {599982u, aot_fast_000927ae, 1u},
    {690094u, aot_fast_000a87ae, 4u},
    {829008u, aot_fast_000ca650, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {827608u, aot_fast_000ca0d8, 3u},
    {827258u, aot_fast_000c9f7a, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {603624u, aot_fast_000935e8, 15u},
    {792040u, aot_fast_000c15e8, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602224u, aot_fast_00093070, 9u},
    {0u, 0, 0u},
    {601524u, aot_fast_00092db4, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600124u, aot_fast_0009283c, 3u},
    {599774u, aot_fast_000926de, 3u},
    {599424u, aot_fast_00092580, 5u},
    {828800u, aot_fast_000ca580, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {294220u, aot_fast_00047d4c, 2u},
    {293870u, aot_fast_00047bee, 6u},
    {826350u, aot_fast_000c9bee, 3u},
    {826700u, aot_fast_000c9d4c, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {701370u, aot_fast_000ab3ba, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602016u, aot_fast_00092fa0, 9u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600266u, aot_fast_000928ca, 2u},
    {599916u, aot_fast_0009276c, 1u},
    {0u, 0, 0u},
    {689328u, aot_fast_000a84b0, 13u},
    {0u, 0, 0u},
    {713204u, aot_fast_000ae1f4, 7u},
    {622742u, aot_fast_00098096, 2u},
    {0u, 0, 0u},
    {294362u, aot_fast_00047dda, 5u},
    {294012u, aot_fast_00047c7c, 6u},
    {826142u, aot_fast_000c9b1e, 3u},
    {0u, 0, 0u},
    {596066u, aot_fast_00091862, 1u},
    {603908u, aot_fast_00093704, 15u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700462u, aot_fast_000ab02e, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {789174u, aot_fast_000c0ab6, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {829084u, aot_fast_000ca69c, 2u},
    {0u, 0, 0u},
    {295904u, aot_fast_000483e0, 2u},
    {795266u, aot_fast_000c2282, 11u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {784274u, aot_fast_000bf792, 4u},
    {603700u, aot_fast_00093634, 15u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602650u, aot_fast_0009321a, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601600u, aot_fast_00092e00, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {296396u, aot_fast_000485cc, 9u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {795058u, aot_fast_000c21b2, 5u},
    {786516u, aot_fast_000c0054, 4u},
    {827476u, aot_fast_000ca054, 3u},
    {826776u, aot_fast_000c9d98, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {612384u, aot_fast_00095820, 5u},
    {620576u, aot_fast_00097820, 1u},
    {603492u, aot_fast_00093564, 21u},
    {791908u, aot_fast_000c1564, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700396u, aot_fast_000aafec, 3u},
    {601742u, aot_fast_00092e8e, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {789108u, aot_fast_000c0a74, 1u},
    {0u, 0, 0u},
    {788408u, aot_fast_000c07b8, 1u},
    {0u, 0, 0u},
    {599292u, aot_fast_000924fc, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {603984u, aot_fast_00093750, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601884u, aot_fast_00092f1c, 2u},
    {691996u, aot_fast_000a8f1c, 2u},
    {789600u, aot_fast_000c0c60, 1u},
    {690946u, aot_fast_000a8b02, 4u},
    {0u, 0, 0u},
    {297030u, aot_fast_00048846, 12u},
    {600134u, aot_fast_00092846, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {294580u, aot_fast_00047eb4, 9u},
    {605526u, aot_fast_00093d56, 2u},
    {826710u, aot_fast_000c9d56, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {620510u, aot_fast_000977de, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602726u, aot_fast_00093266, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600276u, aot_fast_000928d4, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {599226u, aot_fast_000924ba, 3u},
    {828602u, aot_fast_000ca4ba, 3u},
    {0u, 0, 0u},
    {827552u, aot_fast_000ca0a0, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {792334u, aot_fast_000c170e, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602518u, aot_fast_00093196, 1u},
    {0u, 0, 0u},
    {691930u, aot_fast_000a8eda, 1u},
    {601468u, aot_fast_00092d7c, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600068u, aot_fast_00092804, 2u},
    {0u, 0, 0u},
    {599368u, aot_fast_00092548, 2u},
    {795976u, aot_fast_000c2548, 7u},
    {828044u, aot_fast_000ca28c, 2u},
    {295214u, aot_fast_0004812e, 6u},
    {827344u, aot_fast_000c9fd0, 4u},
    {794226u, aot_fast_000c1e72, 2u},
    {793876u, aot_fast_000c1d14, 2u},
    {826644u, aot_fast_000c9d14, 7u},
    {293464u, aot_fast_00047a58, 2u},
    {293114u, aot_fast_000478fa, 6u},
    {784284u, aot_fast_000bf79c, 8u},
    {783934u, aot_fast_000bf63e, 2u},
    {826994u, aot_fast_000c9e72, 2u},
    {701314u, aot_fast_000ab382, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601960u, aot_fast_00092f68, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {690672u, aot_fast_000a89f0, 13u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {296056u, aot_fast_00048478, 9u},
    {0u, 0, 0u},
    {295356u, aot_fast_000481bc, 6u},
    {795068u, aot_fast_000c21bc, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {293606u, aot_fast_00047ae6, 5u},
    {293256u, aot_fast_00047988, 6u},
    {620586u, aot_fast_0009782a, 3u},
    {792268u, aot_fast_000c16cc, 4u},
    {791918u, aot_fast_000c156e, 1u},
    {826086u, aot_fast_000c9ae6, 1u},
    {0u, 0, 0u},
    {700756u, aot_fast_000ab154, 2u},
    {700406u, aot_fast_000aaff6, 1u},
    {290456u, aot_fast_00046e98, 3u},
    {691864u, aot_fast_000a8e98, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {788418u, aot_fast_000c07c2, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {828328u, aot_fast_000ca3a8, 1u},
    {713290u, aot_fast_000ae24a, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826928u, aot_fast_000c9e30, 3u},
    {0u, 0, 0u},
    {826228u, aot_fast_000c9b74, 1u},
    {711190u, aot_fast_000ada16, 3u},
    {620728u, aot_fast_000978b8, 4u},
    {603994u, aot_fast_0009375a, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {791360u, aot_fast_000c1340, 5u},
    {602594u, aot_fast_000931e2, 1u},
    {602244u, aot_fast_00093084, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {690956u, aot_fast_000a8b0c, 6u},
    {0u, 0, 0u},
    {690256u, aot_fast_000a8850, 13u},
    {829170u, aot_fast_000ca6f2, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {605536u, aot_fast_00093d60, 2u},
    {826370u, aot_fast_000c9c02, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {612328u, aot_fast_000957e8, 19u},
    {620520u, aot_fast_000977e8, 16u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602036u, aot_fast_00092fb4, 9u},
    {0u, 0, 0u},
    {625912u, aot_fast_00098cf8, 2u},
    {625562u, aot_fast_00098b9a, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {599936u, aot_fast_00092780, 2u},
    {796194u, aot_fast_000c2622, 2u},
    {828612u, aot_fast_000ca4c4, 8u},
    {688998u, aot_fast_000a8366, 3u},
    {713224u, aot_fast_000ae208, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {793744u, aot_fast_000c1c90, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602528u, aot_fast_000931a0, 1u},
    {0u, 0, 0u},
    {691940u, aot_fast_000a8ee4, 1u},
    {0u, 0, 0u},
    {601128u, aot_fast_00092c28, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {827704u, aot_fast_000ca138, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {293824u, aot_fast_00047bc0, 9u},
    {711266u, aot_fast_000ada62, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {783944u, aot_fast_000bf648, 4u},
    {701674u, aot_fast_000ab4ea, 3u},
    {0u, 0, 0u},
    {602670u, aot_fast_0009322e, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601620u, aot_fast_00092e14, 3u},
    {716308u, aot_fast_000aee14, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {296416u, aot_fast_000485e0, 6u},
    {0u, 0, 0u},
    {295716u, aot_fast_00048324, 5u},
    {0u, 0, 0u},
    {622696u, aot_fast_00098068, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826446u, aot_fast_000c9c4e, 6u},
    {826096u, aot_fast_000c9af0, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {792278u, aot_fast_000c16d6, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700766u, aot_fast_000ab15e, 2u},
    {290816u, aot_fast_00047000, 3u},
    {700416u, aot_fast_000ab000, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {690124u, aot_fast_000a87cc, 4u},
    {296558u, aot_fast_0004866e, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {827638u, aot_fast_000ca0f6, 10u},
    {294808u, aot_fast_00047f98, 2u},
    {294458u, aot_fast_00047e3a, 6u},
    {826938u, aot_fast_000c9e3a, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {291308u, aot_fast_000471ec, 3u},
    {0u, 0, 0u},
    {601904u, aot_fast_00092f30, 5u},
    {692016u, aot_fast_000a8f30, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {599804u, aot_fast_000926fc, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {606596u, aot_fast_00094184, 2u},
    {294950u, aot_fast_00048026, 5u},
    {294600u, aot_fast_00047ec8, 6u},
    {794312u, aot_fast_000c1ec8, 1u},
    {827430u, aot_fast_000ca026, 3u},
    {827780u, aot_fast_000ca184, 7u},
    {0u, 0, 0u},
    {292850u, aot_fast_000477f2, 5u},
    {792212u, aot_fast_000c1694, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602746u, aot_fast_0009327a, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601696u, aot_fast_00092e60, 3u},
    {625922u, aot_fast_00098d02, 1u},
    {600996u, aot_fast_00092ba4, 2u},
    {625572u, aot_fast_00098ba4, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {828972u, aot_fast_000ca62c, 2u},
    {599246u, aot_fast_000924ce, 1u},
    {0u, 0, 0u},
    {713234u, aot_fast_000ae212, 5u},
    {622772u, aot_fast_000980b4, 1u},
    {827572u, aot_fast_000ca0b4, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {711134u, aot_fast_000ad9de, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {783812u, aot_fast_000bf5c4, 9u},
    {792004u, aot_fast_000c15c4, 2u},
    {0u, 0, 0u},
    {602538u, aot_fast_000931aa, 1u},
    {0u, 0, 0u},
    {601838u, aot_fast_00092eee, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {788154u, aot_fast_000c06ba, 2u},
    {828764u, aot_fast_000ca55c, 9u},
    {0u, 0, 0u},
    {795296u, aot_fast_000c22a0, 19u},
    {827714u, aot_fast_000ca142, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {783954u, aot_fast_000bf652, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602680u, aot_fast_00093238, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {715968u, aot_fast_000aecc0, 7u},
    {691042u, aot_fast_000a8b62, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {296076u, aot_fast_0004848c, 6u},
    {795788u, aot_fast_000c248c, 7u},
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
    {601772u, aot_fast_00092eac, 3u},
    {790188u, aot_fast_000c0eac, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {788088u, aot_fast_000c0678, 6u},
    {599322u, aot_fast_0009251a, 2u},
    {828348u, aot_fast_000ca3bc, 2u},
    {0u, 0, 0u},
    {295168u, aot_fast_00048100, 9u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {793830u, aot_fast_000c1ce6, 1u},
    {0u, 0, 0u},
    {711210u, aot_fast_000ada2a, 4u},
    {293068u, aot_fast_000478cc, 9u},
    {596172u, aot_fast_000918cc, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {791380u, aot_fast_000c1354, 4u},
    {602614u, aot_fast_000931f6, 2u},
    {602264u, aot_fast_00093098, 9u},
    {601914u, aot_fast_00092f3a, 6u},
    {692026u, aot_fast_000a8f3a, 1u},
    {0u, 0, 0u},
    {289568u, aot_fast_00046b20, 3u},
    {690626u, aot_fast_000a89c2, 7u},
    {0u, 0, 0u},
    {788230u, aot_fast_000c0706, 5u},
    {829190u, aot_fast_000ca706, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {786480u, aot_fast_000c0030, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {792922u, aot_fast_000c195a, 2u},
    {0u, 0, 0u},
    {792222u, aot_fast_000c169e, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700710u, aot_fast_000ab126, 4u},
    {602056u, aot_fast_00092fc8, 2u},
    {700360u, aot_fast_000aafc8, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600306u, aot_fast_000928f2, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {713244u, aot_fast_000ae21c, 5u},
    {0u, 0, 0u},
    {827232u, aot_fast_000c9f60, 2u},
    {794114u, aot_fast_000c1e02, 1u},
    {294052u, aot_fast_00047ca4, 2u},
    {293702u, aot_fast_00047b46, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {792014u, aot_fast_000c15ce, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700502u, aot_fast_000ab056, 3u},
    {290552u, aot_fast_00046ef8, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {295594u, aot_fast_000482aa, 6u},
    {606540u, aot_fast_0009414c, 5u},
    {827374u, aot_fast_000c9fee, 2u},
    {0u, 0, 0u},
    {294194u, aot_fast_00047d32, 5u},
    {293844u, aot_fast_00047bd4, 6u},
    {825974u, aot_fast_000c9a76, 4u},
    {0u, 0, 0u},
    {292794u, aot_fast_000477ba, 2u},
    {0u, 0, 0u},
    {701694u, aot_fast_000ab4fe, 1u},
    {0u, 0, 0u},
    {602690u, aot_fast_00093242, 1u},
    {700644u, aot_fast_000ab0e4, 1u},
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
    {786556u, aot_fast_000c007c, 3u},
    {827516u, aot_fast_000ca07c, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826116u, aot_fast_000c9b04, 1u},
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
    {289436u, aot_fast_00046a9c, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {829058u, aot_fast_000ca682, 1u},
    {697636u, aot_fast_000aa524, 6u},
    {295878u, aot_fast_000483c6, 5u},
    {689094u, aot_fast_000a83c6, 2u},
    {795240u, aot_fast_000c2268, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {783898u, aot_fast_000bf61a, 3u},
    {701628u, aot_fast_000ab4bc, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601574u, aot_fast_00092de6, 1u},
    {625800u, aot_fast_00098c88, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {788590u, aot_fast_000c086e, 2u},
    {829200u, aot_fast_000ca710, 6u},
    {828850u, aot_fast_000ca5b2, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {827800u, aot_fast_000ca198, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {793982u, aot_fast_000c1d7e, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {792232u, aot_fast_000c16a8, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602416u, aot_fast_00093130, 1u},
    {602066u, aot_fast_00092fd2, 1u},
    {700720u, aot_fast_000ab130, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600316u, aot_fast_000928fc, 14u},
    {788382u, aot_fast_000c079e, 6u},
    {0u, 0, 0u},
    {713954u, aot_fast_000ae4e2, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {827592u, aot_fast_000ca0c8, 1u},
    {0u, 0, 0u},
    {294412u, aot_fast_00047e0c, 9u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {784182u, aot_fast_000bf736, 4u},
    {783832u, aot_fast_000bf5d8, 12u},
    {701562u, aot_fast_000ab47a, 1u},
    {792024u, aot_fast_000c15d8, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {788524u, aot_fast_000c082c, 1u},
    {0u, 0, 0u},
    {828784u, aot_fast_000ca570, 4u},
    {0u, 0, 0u},
    {713396u, aot_fast_000ae2b4, 1u},
    {827734u, aot_fast_000ca156, 4u},
    {655352u, aot_fast_0009fff8, 6u},
    {827384u, aot_fast_000c9ff8, 3u},
    {605500u, aot_fast_00093d3c, 1u},
    {0u, 0, 0u},
    {825984u, aot_fast_000c9a80, 3u},
    {620834u, aot_fast_00097922, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {701354u, aot_fast_000ab3aa, 2u},
    {602700u, aot_fast_0009324c, 5u},
    {700654u, aot_fast_000ab0ee, 3u},
    {602000u, aot_fast_00092f90, 6u},
    {601650u, aot_fast_00092e32, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600250u, aot_fast_000928ba, 2u},
    {0u, 0, 0u},
    {828926u, aot_fast_000ca5fe, 2u},
    {828576u, aot_fast_000ca4a0, 8u},
    {0u, 0, 0u},
    {295396u, aot_fast_000481e4, 2u},
    {295046u, aot_fast_00048086, 6u},
    {713188u, aot_fast_000ae1e4, 5u},
    {795108u, aot_fast_000c21e4, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {293296u, aot_fast_000479b0, 2u},
    {292946u, aot_fast_00047852, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {789508u, aot_fast_000c0c04, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600042u, aot_fast_000927ea, 2u},
    {689804u, aot_fast_000a868c, 62u},
    {690154u, aot_fast_000a87ea, 30u},
    {788108u, aot_fast_000c068c, 3u},
    {796300u, aot_fast_000c268c, 4u},
    {295188u, aot_fast_00048114, 6u},
    {827318u, aot_fast_000c9fb6, 2u},
    {826968u, aot_fast_000c9e58, 2u},
    {793850u, aot_fast_000c1cfa, 2u},
    {827668u, aot_fast_000ca114, 1u},
    {293438u, aot_fast_00047a3e, 5u},
    {293088u, aot_fast_000478e0, 6u},
    {596192u, aot_fast_000918e0, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602284u, aot_fast_000930ac, 4u},
    {692046u, aot_fast_000a8f4e, 8u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {788250u, aot_fast_000c071a, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {795042u, aot_fast_000c21a2, 7u},
    {827460u, aot_fast_000ca044, 4u},
    {827110u, aot_fast_000c9ee6, 3u},
    {827810u, aot_fast_000ca1a2, 1u},
    {826410u, aot_fast_000c9c2a, 7u},
    {0u, 0, 0u},
    {792942u, aot_fast_000c196e, 3u},
    {620560u, aot_fast_00097810, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {290780u, aot_fast_00046fdc, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {789092u, aot_fast_000c0a64, 5u},
    {0u, 0, 0u},
    {599976u, aot_fast_000927a8, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {795184u, aot_fast_000c2230, 5u},
    {827602u, aot_fast_000ca0d2, 2u},
    {827252u, aot_fast_000c9f74, 1u},
    {0u, 0, 0u},
    {793784u, aot_fast_000c1cb8, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {784192u, aot_fast_000bf740, 8u},
    {0u, 0, 0u},
    {701572u, aot_fast_000ab484, 4u},
    {0u, 0, 0u},
    {602568u, aot_fast_000931c8, 2u},
    {0u, 0, 0u},
    {601868u, aot_fast_00092f0c, 2u},
    {601518u, aot_fast_00092dae, 1u},
    {601168u, aot_fast_00092c50, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {599418u, aot_fast_0009257a, 3u},
    {828794u, aot_fast_000ca57a, 1u},
    {0u, 0, 0u},
    {606560u, aot_fast_00094160, 1u},
    {827394u, aot_fast_000ca002, 1u},
    {827744u, aot_fast_000ca160, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602710u, aot_fast_00093256, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600260u, aot_fast_000928c4, 3u},
    {0u, 0, 0u},
    {296456u, aot_fast_00048608, 2u},
    {828936u, aot_fast_000ca608, 1u},
    {0u, 0, 0u},
    {713198u, aot_fast_000ae1ee, 2u},
    {786576u, aot_fast_000c0090, 4u},
    {827536u, aot_fast_000ca090, 1u},
    {826836u, aot_fast_000c9dd4, 4u},
    {0u, 0, 0u},
    {293656u, aot_fast_00047b18, 9u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {783776u, aot_fast_000bf5a0, 3u},
    {791968u, aot_fast_000c15a0, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600052u, aot_fast_000927f4, 1u},
    {796310u, aot_fast_000c2696, 31u},
    {599352u, aot_fast_00092538, 2u},
    {0u, 0, 0u},
    {295548u, aot_fast_0004827c, 9u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {794210u, aot_fast_000c1e62, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602994u, aot_fast_00093372, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601944u, aot_fast_00092f58, 1u},
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
    {294640u, aot_fast_00047ef0, 2u},
    {294290u, aot_fast_00047d92, 6u},
    {0u, 0, 0u},
    {826070u, aot_fast_000c9ad6, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602786u, aot_fast_000932a2, 2u},
    {700740u, aot_fast_000ab144, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {599986u, aot_fast_000927b2, 5u},
    {788402u, aot_fast_000c07b2, 1u},
    {599286u, aot_fast_000924f6, 1u},
    {0u, 0, 0u},
    {795194u, aot_fast_000c223a, 16u},
    {0u, 0, 0u},
    {294782u, aot_fast_00047f7e, 5u},
    {294432u, aot_fast_00047e20, 6u},
    {793794u, aot_fast_000c1cc2, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700532u, aot_fast_000ab074, 2u},
    {691990u, aot_fast_000a8f16, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {689190u, aot_fast_000a8426, 4u},
    {713416u, aot_fast_000ae2c8, 5u},
    {606570u, aot_fast_0009416a, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {605520u, aot_fast_00093d50, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {595928u, aot_fast_000917d8, 4u},
    {603770u, aot_fast_0009367a, 18u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700674u, aot_fast_000ab102, 2u},
    {0u, 0, 0u},
    {601670u, aot_fast_00092e46, 2u},
    {625896u, aot_fast_00098ce8, 7u},
    {699974u, aot_fast_000aae46, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {599920u, aot_fast_00092770, 1u},
    {829296u, aot_fast_000ca770, 1u},
    {296116u, aot_fast_000484b4, 2u},
    {599220u, aot_fast_000924b4, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826846u, aot_fast_000c9dde, 4u},
    {793728u, aot_fast_000c1c80, 6u},
    {0u, 0, 0u},
    {711108u, aot_fast_000ad9c4, 8u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601462u, aot_fast_00092d76, 1u},
    {601112u, aot_fast_00092c18, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {829088u, aot_fast_000ca6a0, 2u},
    {0u, 0, 0u},
    {828388u, aot_fast_000ca3e4, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {827338u, aot_fast_000c9fca, 2u},
    {794220u, aot_fast_000c1e6c, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {620788u, aot_fast_000978f4, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {701308u, aot_fast_000ab37c, 1u},
    {602654u, aot_fast_0009321e, 1u},
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
    {713492u, aot_fast_000ae314, 2u},
    {827830u, aot_fast_000ca1b6, 2u},
    {295000u, aot_fast_00048058, 9u},
    {622680u, aot_fast_00098058, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {292900u, aot_fast_00047824, 9u},
    {620580u, aot_fast_00097824, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {831122u, aot_fast_000cae92, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600346u, aot_fast_0009291a, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {599296u, aot_fast_00092500, 1u},
    {713984u, aot_fast_000ae500, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {827272u, aot_fast_000c9f88, 4u},
    {0u, 0, 0u},
    {793804u, aot_fast_000c1ccc, 3u},
    {826222u, aot_fast_000c9b6e, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {692000u, aot_fast_000a8f20, 3u},
    {0u, 0, 0u},
    {789604u, aot_fast_000c0c64, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600138u, aot_fast_0009284a, 2u},
    {0u, 0, 0u},
    {599438u, aot_fast_0009258e, 1u},
    {828464u, aot_fast_000ca430, 1u},
    {828114u, aot_fast_000ca2d2, 2u},
    {794996u, aot_fast_000c2174, 5u},
    {827414u, aot_fast_000ca016, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {293884u, aot_fast_00047bfc, 2u},
    {293534u, aot_fast_00047a9e, 6u},
    {0u, 0, 0u},
    {595938u, aot_fast_000917e2, 3u},
    {620514u, aot_fast_000977e2, 1u},
    {0u, 0, 0u},
    {603080u, aot_fast_000933c8, 22u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {716368u, aot_fast_000aee50, 2u},
    {716018u, aot_fast_000aecf2, 2u},
    {609172u, aot_fast_00094b94, 3u},
    {789396u, aot_fast_000c0b94, 1u},
    {0u, 0, 0u},
    {829306u, aot_fast_000ca77a, 3u},
    {828956u, aot_fast_000ca61c, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {294026u, aot_fast_00047c8a, 5u},
    {293676u, aot_fast_00047b2c, 6u},
    {826156u, aot_fast_000c9b2c, 8u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700476u, aot_fast_000ab03c, 1u},
    {691934u, aot_fast_000a8ede, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {829098u, aot_fast_000ca6aa, 3u},
    {296268u, aot_fast_0004854c, 9u},
    {0u, 0, 0u},
    {295568u, aot_fast_00048290, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {794230u, aot_fast_000c1e76, 3u},
    {826998u, aot_fast_000c9e76, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {701668u, aot_fast_000ab4e4, 2u},
    {701318u, aot_fast_000ab386, 7u},
    {791430u, aot_fast_000c1386, 2u},
    {0u, 0, 0u},
    {601964u, aot_fast_00092f6c, 2u},
    {601614u, aot_fast_00092e0e, 3u},
    {0u, 0, 0u},
    {691026u, aot_fast_000a8b52, 6u},
    {0u, 0, 0u},
    {600214u, aot_fast_00092896, 1u},
    {829240u, aot_fast_000ca738, 2u},
    {0u, 0, 0u},
    {599164u, aot_fast_0009247c, 3u},
    {0u, 0, 0u},
    {713152u, aot_fast_000ae1c0, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826440u, aot_fast_000c9c48, 2u},
    {711402u, aot_fast_000adaea, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602806u, aot_fast_000932b6, 3u},
    {700760u, aot_fast_000ab158, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {789472u, aot_fast_000c0be0, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {827632u, aot_fast_000ca0f0, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826232u, aot_fast_000c9b78, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {783872u, aot_fast_000bf600, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700552u, aot_fast_000ab088, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600148u, aot_fast_00092854, 1u},
    {599798u, aot_fast_000926f6, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {606590u, aot_fast_0009417e, 2u},
    {786464u, aot_fast_000c0020, 3u},
    {795006u, aot_fast_000c217e, 16u},
    {294244u, aot_fast_00047d64, 9u},
    {826374u, aot_fast_000c9c06, 2u},
    {826024u, aot_fast_000c9aa8, 3u},
    {0u, 0, 0u},
    {686060u, aot_fast_000a77ec, 12u},
    {0u, 0, 0u},
    {603440u, aot_fast_00093530, 15u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700694u, aot_fast_000ab116, 2u},
    {290744u, aot_fast_00046fb8, 3u},
    {601690u, aot_fast_00092e5a, 3u},
    {716028u, aot_fast_000aecfc, 1u},
    {716378u, aot_fast_000aee5a, 1u},
    {0u, 0, 0u},
    {600290u, aot_fast_000928e2, 4u},
    {599940u, aot_fast_00092784, 1u},
    {828966u, aot_fast_000ca626, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {606732u, aot_fast_0009420c, 4u},
    {622766u, aot_fast_000980ae, 1u},
    {713228u, aot_fast_000ae20c, 1u},
    {827566u, aot_fast_000ca0ae, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {711128u, aot_fast_000ad9d8, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {603232u, aot_fast_00093460, 15u},
    {0u, 0, 0u},
    {602532u, aot_fast_000931a4, 1u},
    {700486u, aot_fast_000ab046, 2u},
    {0u, 0, 0u},
    {601482u, aot_fast_00092d8a, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {788498u, aot_fast_000c0812, 7u},
    {829108u, aot_fast_000ca6b4, 1u},
    {0u, 0, 0u},
    {295928u, aot_fast_000483f8, 5u},
    {0u, 0, 0u},
    {295228u, aot_fast_0004813c, 2u},
    {294878u, aot_fast_00047fde, 6u},
    {794240u, aot_fast_000c1e80, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {293128u, aot_fast_00047908, 2u},
    {620808u, aot_fast_00097908, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700628u, aot_fast_000ab0d4, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {699578u, aot_fast_000aacba, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {599874u, aot_fast_00092742, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {295370u, aot_fast_000481ca, 5u},
    {295020u, aot_fast_0004806c, 6u},
    {622700u, aot_fast_0009806c, 1u},
    {786540u, aot_fast_000c006c, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {293270u, aot_fast_00047996, 5u},
    {292920u, aot_fast_00047838, 6u},
    {596024u, aot_fast_00091838, 3u},
    {792282u, aot_fast_000c16da, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602466u, aot_fast_00093162, 3u},
    {700420u, aot_fast_000ab004, 2u},
    {601766u, aot_fast_00092ea6, 3u},
    {0u, 0, 0u},
    {601066u, aot_fast_00092bea, 5u},
    {789482u, aot_fast_000c0bea, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {829042u, aot_fast_000ca672, 3u},
    {714004u, aot_fast_000ae514, 1u},
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
    {692020u, aot_fast_000a8f34, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {690970u, aot_fast_000a8b1a, 3u},
    {0u, 0, 0u},
    {788574u, aot_fast_000c085e, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {689220u, aot_fast_000a8444, 32u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {794316u, aot_fast_000c1ecc, 4u},
    {826734u, aot_fast_000c9d6e, 3u},
    {0u, 0, 0u},
    {826034u, aot_fast_000c9ab2, 2u},
    {0u, 0, 0u},
    {595958u, aot_fast_000917f6, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602750u, aot_fast_0009327e, 1u},
    {700704u, aot_fast_000ab120, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {789416u, aot_fast_000c0ba8, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {828976u, aot_fast_000ca630, 4u},
    {689362u, aot_fast_000a84d2, 13u},
    {0u, 0, 0u},
    {606742u, aot_fast_00094216, 3u},
    {622776u, aot_fast_000980b8, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826176u, aot_fast_000c9b40, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {792008u, aot_fast_000c15c8, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601842u, aot_fast_00092ef2, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {599392u, aot_fast_00092560, 2u},
    {796000u, aot_fast_000c2560, 30u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {827018u, aot_fast_000c9e8a, 2u},
    {605484u, aot_fast_00093d2c, 1u},
    {826318u, aot_fast_000c9bce, 1u},
    {293488u, aot_fast_00047a70, 9u},
    {0u, 0, 0u},
    {292788u, aot_fast_000477b4, 2u},
    {784308u, aot_fast_000bf7b4, 1u},
    {701688u, aot_fast_000ab4f8, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600934u, aot_fast_00092b66, 22u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {296780u, aot_fast_0004874c, 5u},
    {296430u, aot_fast_000485ee, 5u},
    {599184u, aot_fast_00092490, 2u},
    {689996u, aot_fast_000a874c, 13u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826810u, aot_fast_000c9dba, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {792292u, aot_fast_000c16e4, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602476u, aot_fast_0009316c, 3u},
    {0u, 0, 0u},
    {831152u, aot_fast_000caeb0, 1u},
    {601426u, aot_fast_00092d52, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {690488u, aot_fast_000a8938, 8u},
    {600026u, aot_fast_000927da, 3u},
    {788442u, aot_fast_000c07da, 2u},
    {599326u, aot_fast_0009251e, 5u},
    {829052u, aot_fast_000ca67c, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {294472u, aot_fast_00047e48, 2u},
    {294122u, aot_fast_00047cea, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {596176u, aot_fast_000918d0, 7u},
    {620752u, aot_fast_000978d0, 4u},
    {0u, 0, 0u},
    {701622u, aot_fast_000ab4b6, 3u},
    {0u, 0, 0u},
    {602618u, aot_fast_000931fa, 2u},
    {290972u, aot_fast_0004709c, 3u},
    {0u, 0, 0u},
    {716256u, aot_fast_000aede0, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {829194u, aot_fast_000ca70a, 2u},
    {828844u, aot_fast_000ca5ac, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {294614u, aot_fast_00047ed6, 5u},
    {294264u, aot_fast_00047d78, 6u},
    {793976u, aot_fast_000c1d78, 2u},
    {794326u, aot_fast_000c1ed6, 2u},
    {826394u, aot_fast_000c9c1a, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {291464u, aot_fast_00047288, 3u},
    {0u, 0, 0u},
    {602060u, aot_fast_00092fcc, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {789426u, aot_fast_000c0bb2, 1u},
    {0u, 0, 0u},
    {600310u, aot_fast_000928f6, 1u},
    {0u, 0, 0u},
    {828986u, aot_fast_000ca63a, 1u},
    {0u, 0, 0u},
    {295806u, aot_fast_0004837e, 6u},
    {606752u, aot_fast_00094220, 5u},
    {0u, 0, 0u},
    {827236u, aot_fast_000c9f64, 3u},
    {794118u, aot_fast_000c1e06, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {792018u, aot_fast_000c15d2, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601852u, aot_fast_00092efc, 2u},
    {0u, 0, 0u},
    {601152u, aot_fast_00092c40, 2u},
    {690914u, aot_fast_000a8ae2, 13u},
    {789568u, aot_fast_000c0c40, 3u},
    {788518u, aot_fast_000c0826, 1u},
    {0u, 0, 0u},
    {599402u, aot_fast_0009256a, 2u},
    {714090u, aot_fast_000ae56a, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {794260u, aot_fast_000c1e94, 3u},
    {605494u, aot_fast_00093d36, 2u},
    {826328u, aot_fast_000c9bd8, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602694u, aot_fast_00093246, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601644u, aot_fast_00092e2c, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {296090u, aot_fast_0004849a, 5u},
    {689306u, aot_fast_000a849a, 7u},
    {0u, 0, 0u},
    {622720u, aot_fast_00098080, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826470u, aot_fast_000c9c66, 2u},
    {711432u, aot_fast_000adb08, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {290840u, aot_fast_00047018, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {788452u, aot_fast_000c07e4, 6u},
    {829412u, aot_fast_000ca7e4, 1u},
    {0u, 0, 0u},
    {689098u, aot_fast_000a83ca, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {294832u, aot_fast_00047fb0, 9u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {784252u, aot_fast_000bf77c, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602628u, aot_fast_00093204, 3u},
    {700582u, aot_fast_000ab0a6, 1u},
    {601928u, aot_fast_00092f48, 1u},
    {692040u, aot_fast_000a8f48, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {690290u, aot_fast_000a8872, 13u},
    {0u, 0, 0u},
    {689590u, aot_fast_000a85b6, 42u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {827104u, aot_fast_000c9ee0, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826054u, aot_fast_000c9ac6, 2u},
    {0u, 0, 0u},
    {595978u, aot_fast_0009180a, 1u},
    {792236u, aot_fast_000c16ac, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602420u, aot_fast_00093134, 1u},
    {700374u, aot_fast_000aafd6, 4u},
    {601720u, aot_fast_00092e78, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {295466u, aot_fast_0004822a, 6u},
    {0u, 0, 0u},
    {827246u, aot_fast_000c9f6e, 1u},
    {794128u, aot_fast_000c1e10, 12u},
    {0u, 0, 0u},
    {293716u, aot_fast_00047b54, 2u},
    {293366u, aot_fast_000479f6, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700516u, aot_fast_000ab064, 2u},
    {0u, 0, 0u},
    {601512u, aot_fast_00092da8, 2u},
    {789578u, aot_fast_000c0c4a, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {829138u, aot_fast_000ca6d2, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {295608u, aot_fast_000482b8, 2u},
    {606554u, aot_fast_0009415a, 2u},
    {713400u, aot_fast_000ae2b8, 7u},
    {794270u, aot_fast_000c1e9e, 5u},
    {0u, 0, 0u},
    {293858u, aot_fast_00047be2, 5u},
    {293508u, aot_fast_00047a84, 6u},
    {0u, 0, 0u},
    {620488u, aot_fast_000977c8, 8u},
    {603754u, aot_fast_0009366a, 5u},
    {701708u, aot_fast_000ab50c, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {625880u, aot_fast_00098cd8, 5u},
    {699608u, aot_fast_000aacd8, 2u},
    {600604u, aot_fast_00092a1c, 1u},
    {600254u, aot_fast_000928be, 2u},
    {788320u, aot_fast_000c0760, 1u},
    {0u, 0, 0u},
    {795812u, aot_fast_000c24a4, 30u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {711092u, aot_fast_000ad9b4, 5u},
    {596054u, aot_fast_00091856, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {691908u, aot_fast_000a8ec4, 11u},
    {601446u, aot_fast_00092d66, 3u},
    {790212u, aot_fast_000c0ec4, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {829422u, aot_fast_000ca7ee, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {689108u, aot_fast_000a83d4, 7u},
    {713334u, aot_fast_000ae276, 4u},
    {795254u, aot_fast_000c2276, 5u},
    {828372u, aot_fast_000ca3d4, 1u},
    {794204u, aot_fast_000c1e5c, 1u},
    {826972u, aot_fast_000c9e5c, 9u},
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
    {289592u, aot_fast_00046b38, 3u},
    {0u, 0, 0u},
    {788604u, aot_fast_000c087c, 1u},
    {0u, 0, 0u},
    {796096u, aot_fast_000c25c0, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {827814u, aot_fast_000ca1a6, 1u},
    {622664u, aot_fast_00098048, 5u},
    {786504u, aot_fast_000c0048, 3u},
    {793996u, aot_fast_000c1d8c, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {603830u, aot_fast_000936b6, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602780u, aot_fast_0009329c, 1u},
    {700734u, aot_fast_000ab13e, 1u},
    {0u, 0, 0u},
    {691842u, aot_fast_000a8e82, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {827606u, aot_fast_000ca0d6, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {294076u, aot_fast_00047cbc, 9u},
    {793788u, aot_fast_000c1cbc, 2u},
    {826206u, aot_fast_000c9b5e, 4u},
    {620706u, aot_fast_000978a2, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602572u, aot_fast_000931cc, 4u},
    {700526u, aot_fast_000ab06e, 1u},
    {0u, 0, 0u},
    {601522u, aot_fast_00092db2, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {690234u, aot_fast_000a883a, 8u},
    {796380u, aot_fast_000c26dc, 6u},
    {714110u, aot_fast_000ae57e, 3u},
    {829148u, aot_fast_000ca6dc, 3u},
    {0u, 0, 0u},
    {606564u, aot_fast_00094164, 2u},
    {827398u, aot_fast_000ca006, 4u},
    {827048u, aot_fast_000c9ea8, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700668u, aot_fast_000ab0fc, 1u},
    {0u, 0, 0u},
    {601664u, aot_fast_00092e40, 2u},
    {625890u, aot_fast_00098ce2, 2u},
    {609156u, aot_fast_00094b84, 6u},
    {716352u, aot_fast_000aee40, 7u},
    {789380u, aot_fast_000c0b84, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {599214u, aot_fast_000924ae, 3u},
    {295760u, aot_fast_00048350, 9u},
    {0u, 0, 0u},
    {295060u, aot_fast_00048094, 2u},
    {294710u, aot_fast_00047f36, 6u},
    {794072u, aot_fast_000c1dd8, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {711102u, aot_fast_000ad9be, 2u},
    {292960u, aot_fast_00047860, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {289460u, aot_fast_00046ab4, 3u},
    {0u, 0, 0u},
    {600056u, aot_fast_000927f8, 1u},
    {788472u, aot_fast_000c07f8, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {295202u, aot_fast_00048122, 5u},
    {294852u, aot_fast_00047fc4, 6u},
    {794214u, aot_fast_000c1e66, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {293102u, aot_fast_000478ee, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {701652u, aot_fast_000ab4d4, 2u},
    {602998u, aot_fast_00093376, 3u},
    {791414u, aot_fast_000c1376, 2u},
    {0u, 0, 0u},
    {601948u, aot_fast_00092f5c, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {691010u, aot_fast_000a8b42, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {829224u, aot_fast_000ca728, 6u},
    {796106u, aot_fast_000c25ca, 31u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {713136u, aot_fast_000ae1b0, 7u},
    {622674u, aot_fast_00098052, 2u},
    {827824u, aot_fast_000ca1b0, 1u},
    {0u, 0, 0u},
    {826424u, aot_fast_000c9c38, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {792256u, aot_fast_000c16c0, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602790u, aot_fast_000932a6, 1u},
    {700744u, aot_fast_000ab148, 3u},
    {0u, 0, 0u},
    {691852u, aot_fast_000a8e8c, 5u},
    {0u, 0, 0u},
    {789456u, aot_fast_000c0bd0, 2u},
    {600690u, aot_fast_00092a72, 2u},
    {0u, 0, 0u},
    {829366u, aot_fast_000ca7b6, 3u},
    {829016u, aot_fast_000ca658, 6u},
    {296186u, aot_fast_000484fa, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {786656u, aot_fast_000c00e0, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {620716u, aot_fast_000978ac, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602582u, aot_fast_000931d6, 2u},
    {700536u, aot_fast_000ab078, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {829158u, aot_fast_000ca6e6, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {827758u, aot_fast_000ca16e, 2u},
    {0u, 0, 0u},
    {827058u, aot_fast_000c9eb2, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {620508u, aot_fast_000977dc, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700678u, aot_fast_000ab106, 3u},
    {0u, 0, 0u},
    {601674u, aot_fast_00092e4a, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {599924u, aot_fast_00092774, 1u},
    {829300u, aot_fast_000ca774, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {295420u, aot_fast_000481fc, 9u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826150u, aot_fast_000c9b26, 2u},
    {293320u, aot_fast_000479c8, 9u},
    {596074u, aot_fast_0009186a, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602516u, aot_fast_00093194, 1u},
    {700470u, aot_fast_000ab036, 3u},
    {601816u, aot_fast_00092ed8, 1u},
    {790232u, aot_fast_000c0ed8, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {829092u, aot_fast_000ca6a4, 2u},
    {0u, 0, 0u},
    {689128u, aot_fast_000a83e8, 9u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826292u, aot_fast_000c9bb4, 5u},
    {711254u, aot_fast_000ada56, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {701662u, aot_fast_000ab4de, 1u},
    {603008u, aot_fast_00093380, 3u},
    {602658u, aot_fast_00093222, 1u},
    {602308u, aot_fast_000930c4, 2u},
    {791424u, aot_fast_000c1380, 1u},
    {601608u, aot_fast_00092e08, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600208u, aot_fast_00092890, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {827834u, aot_fast_000ca1ba, 3u},
    {827484u, aot_fast_000ca05c, 1u},
    {0u, 0, 0u},
    {294304u, aot_fast_00047da0, 2u},
    {293954u, aot_fast_00047c42, 6u},
    {826784u, aot_fast_000c9da0, 5u},
    {0u, 0, 0u},
    {596008u, aot_fast_00091828, 7u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602800u, aot_fast_000932b0, 1u},
    {709296u, aot_fast_000ad2b0, 6u},
    {290804u, aot_fast_00046ff4, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600000u, aot_fast_000927c0, 2u},
    {829376u, aot_fast_000ca7c0, 2u},
    {599300u, aot_fast_00092504, 1u},
    {713988u, aot_fast_000ae504, 3u},
    {713288u, aot_fast_000ae248, 1u},
    {795908u, aot_fast_000c2504, 4u},
    {827626u, aot_fast_000ca0ea, 3u},
    {294446u, aot_fast_00047e2e, 5u},
    {294096u, aot_fast_00047cd0, 6u},
    {794158u, aot_fast_000c1e2e, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {784216u, aot_fast_000bf758, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601892u, aot_fast_00092f24, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {600142u, aot_fast_0009284e, 2u},
    {599792u, aot_fast_000926f0, 3u},
    {599442u, aot_fast_00092592, 1u},
    {788208u, aot_fast_000c06f0, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826368u, aot_fast_000c9c00, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {792200u, aot_fast_000c1688, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601684u, aot_fast_00092e54, 3u},
    {699988u, aot_fast_000aae54, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {296480u, aot_fast_00048620, 9u},
    {0u, 0, 0u},
    {295780u, aot_fast_00048364, 6u},
    {688996u, aot_fast_000a8364, 1u},
    {713222u, aot_fast_000ae206, 1u},
    {0u, 0, 0u},
    {826860u, aot_fast_000c9dec, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700480u, aot_fast_000ab040, 2u},
    {601826u, aot_fast_00092ee2, 2u},
    {601476u, aot_fast_00092d84, 2u},
    {789542u, aot_fast_000c0c26, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {599376u, aot_fast_00092550, 2u},
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
    {792134u, aot_fast_000c1646, 4u},
    {0u, 0, 0u},
    {791434u, aot_fast_000c138a, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {625844u, aot_fast_00098cb4, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {829244u, aot_fast_000ca73c, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {713156u, aot_fast_000ae1c4, 1u},
    {827844u, aot_fast_000ca1c4, 1u},
    {294664u, aot_fast_00047f08, 9u},
    {826794u, aot_fast_000c9daa, 2u},
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
    {601760u, aot_fast_00092ea0, 3u},
    {0u, 0, 0u},
    {601060u, aot_fast_00092be4, 2u},
    {789476u, aot_fast_000c0be4, 3u},
    {0u, 0, 0u},
    {829386u, aot_fast_000ca7ca, 3u},
    {599660u, aot_fast_0009266c, 3u},
    {599310u, aot_fast_0009250e, 4u},
    {713998u, aot_fast_000ae50e, 2u},
    {828336u, aot_fast_000ca3b0, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826236u, aot_fast_000c9b7c, 5u},
    {0u, 0, 0u},
    {596160u, aot_fast_000918c0, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {603302u, aot_fast_000934a6, 18u},
    {701606u, aot_fast_000ab4a6, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {601552u, aot_fast_00092dd0, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {788218u, aot_fast_000c06fa, 4u},
    {829178u, aot_fast_000ca6fa, 5u},
    {0u, 0, 0u},
    {713440u, aot_fast_000ae2e0, 3u},
    {295298u, aot_fast_00048182, 6u},
    {0u, 0, 0u},
    {827078u, aot_fast_000c9ec6, 2u},
    {0u, 0, 0u},
    {826378u, aot_fast_000c9c0a, 2u},
    {293548u, aot_fast_00047aac, 2u},
    {293198u, aot_fast_0004794e, 6u},
    {595952u, aot_fast_000917f0, 2u},
    {792210u, aot_fast_000c1692, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700698u, aot_fast_000ab11a, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {625920u, aot_fast_00098d00, 1u},
    {625570u, aot_fast_00098ba2, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {599944u, aot_fast_00092788, 5u},
    {0u, 0, 0u},
    {296140u, aot_fast_000484cc, 9u},
    {713932u, aot_fast_000ae4cc, 2u},
    {295440u, aot_fast_00048210, 6u},
    {0u, 0, 0u},
    {827220u, aot_fast_000c9f54, 3u},
    {826870u, aot_fast_000c9df6, 5u},
    {0u, 0, 0u},
    {293690u, aot_fast_00047b3a, 5u},
    {293340u, aot_fast_000479dc, 6u},
    {0u, 0, 0u},
    {784160u, aot_fast_000bf720, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602536u, aot_fast_000931a8, 1u},
    {700490u, aot_fast_000ab04a, 2u},
    {290540u, aot_fast_00046eec, 3u},
    {601486u, aot_fast_00092d8e, 8u},
    {601136u, aot_fast_00092c30, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {829112u, aot_fast_000ca6b8, 2u},
    {795994u, aot_fast_000c255a, 2u},
    {0u, 0, 0u},
    {295582u, aot_fast_0004829e, 5u},
    {713374u, aot_fast_000ae29e, 9u},
    {827362u, aot_fast_000c9fe2, 4u},
    {0u, 0, 0u},
    {826662u, aot_fast_000c9d26, 2u},
    {826312u, aot_fast_000c9bc8, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {784302u, aot_fast_000bf7ae, 2u},
    {792144u, aot_fast_000c1650, 5u},
    {701682u, aot_fast_000ab4f2, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602328u, aot_fast_000930d8, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {625854u, aot_fast_00098cbe, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {829254u, aot_fast_000ca746, 5u},
    {0u, 0, 0u},
    {599178u, aot_fast_0009248a, 3u},
    {0u, 0, 0u},
    {713166u, aot_fast_000ae1ce, 5u},
    {622704u, aot_fast_00098070, 1u},
    {827504u, aot_fast_000ca070, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826104u, aot_fast_000c9af8, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602820u, aot_fast_000932c4, 4u},
    {0u, 0, 0u},
    {700424u, aot_fast_000ab008, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {289424u, aot_fast_00046a90, 3u},
    {0u, 0, 0u},
    {788436u, aot_fast_000c07d4, 3u},
    {829396u, aot_fast_000ca7d4, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {295516u, aot_fast_0004825c, 8u},
    {795228u, aot_fast_000c225c, 5u},
    {827296u, aot_fast_000c9fa0, 3u},
    {794178u, aot_fast_000c1e42, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700566u, aot_fast_000ab096, 2u},
    {692024u, aot_fast_000a8f38, 1u},
    {601562u, aot_fast_00092dda, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {788228u, aot_fast_000c0704, 1u},
    {296358u, aot_fast_000485a6, 6u},
    {795720u, aot_fast_000c2448, 4u},
    {713450u, aot_fast_000ae2ea, 2u},
    {0u, 0, 0u},
    {827438u, aot_fast_000ca02e, 4u},
    {0u, 0, 0u},
    {793970u, aot_fast_000c1d72, 2u},
    {293908u, aot_fast_00047c14, 9u},
    {826038u, aot_fast_000c9ab6, 2u},
    {826388u, aot_fast_000c9c14, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {290408u, aot_fast_00046e68, 3u},
    {0u, 0, 0u},
    {789420u, aot_fast_000c0bac, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {829330u, aot_fast_000ca792, 2u},
    {296500u, aot_fast_00048634, 7u},
    {713942u, aot_fast_000ae4d6, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {711142u, aot_fast_000ad9e6, 1u},
    {620680u, aot_fast_00097888, 2u},
    {0u, 0, 0u},
    {792012u, aot_fast_000c15cc, 1u},
    {701550u, aot_fast_000ab46e, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {691958u, aot_fast_000a8ef6, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {788162u, aot_fast_000c06c2, 4u},
    {599396u, aot_fast_00092564, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {827722u, aot_fast_000ca14a, 2u},
    {294892u, aot_fast_00047fec, 2u},
    {294542u, aot_fast_00047e8e, 6u},
    {0u, 0, 0u},
    {826322u, aot_fast_000c9bd2, 3u},
    {0u, 0, 0u},
    {620822u, aot_fast_00097916, 5u},
    {620472u, aot_fast_000977b8, 5u},
    {784312u, aot_fast_000bf7b8, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602338u, aot_fast_000930e2, 5u},
    {601988u, aot_fast_00092f84, 2u},
    {601638u, aot_fast_00092e26, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {690700u, aot_fast_000a8a0c, 62u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {599188u, aot_fast_00092494, 4u},
    {0u, 0, 0u},
    {713176u, aot_fast_000ae1d8, 5u},
    {295034u, aot_fast_0004807a, 5u},
    {294684u, aot_fast_00047f1c, 6u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {711076u, aot_fast_000ad9a4, 7u},
    {292934u, aot_fast_00047846, 5u},
    {792296u, aot_fast_000c16e8, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {700434u, aot_fast_000ab012, 3u},
    {790196u, aot_fast_000c0eb4, 3u},
    {601430u, aot_fast_00092d56, 4u},
    {601080u, aot_fast_00092bf8, 2u},
    {789496u, aot_fast_000c0bf8, 2u},
    {0u, 0, 0u},
    {788446u, aot_fast_000c07de, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {828356u, aot_fast_000ca3c4, 1u},
    {0u, 0, 0u},
    {786696u, aot_fast_000c0108, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {711218u, aot_fast_000ada32, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {603672u, aot_fast_00093618, 10u},
    {0u, 0, 0u},
    {791388u, aot_fast_000c135c, 5u},
    {0u, 0, 0u},
    {700576u, aot_fast_000ab0a0, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {609064u, aot_fast_00094b28, 7u},
    {0u, 0, 0u},
    {788588u, aot_fast_000c086c, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {296018u, aot_fast_00048452, 6u},
    {0u, 0, 0u},
    {606614u, aot_fast_00094196, 2u},
    {827448u, aot_fast_000ca038, 3u},
    {827098u, aot_fast_000c9eda, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826048u, aot_fast_000c9ac0, 3u},
    {792930u, aot_fast_000c1962, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {290768u, aot_fast_00046fd0, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {690076u, aot_fast_000a879c, 6u},
    {828990u, aot_fast_000ca63e, 2u},
    {296160u, aot_fast_000484e0, 6u},
    {689026u, aot_fast_000a8382, 1u},
    {829340u, aot_fast_000ca79c, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {710452u, aot_fast_000ad734, 5u},
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
    {599406u, aot_fast_0009256e, 2u},
    {828782u, aot_fast_000ca56e, 1u},
    {0u, 0, 0u},
    {295252u, aot_fast_00048154, 9u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {293152u, aot_fast_00047920, 9u},
    {620482u, aot_fast_000977c2, 2u},
    {784322u, aot_fast_000bf7c2, 1u},
    {701702u, aot_fast_000ab506, 3u},
    {792164u, aot_fast_000c1664, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {716336u, aot_fast_000aee30, 5u},
    {0u, 0, 0u},
    {289652u, aot_fast_00046b74, 3u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {829274u, aot_fast_000ca75a, 2u},
    {0u, 0, 0u},
    {795806u, aot_fast_000c249e, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826824u, aot_fast_000c9dc8, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {596048u, aot_fast_00091850, 2u},
    {603890u, aot_fast_000936f2, 6u},
    {792306u, aot_fast_000c16f2, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602490u, aot_fast_0009317a, 7u},
    {0u, 0, 0u},
    {601790u, aot_fast_00092ebe, 5u},
    {601440u, aot_fast_00092d60, 2u},
    {789506u, aot_fast_000c0c02, 1u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {829416u, aot_fast_000ca7e8, 2u},
    {829066u, aot_fast_000ca68a, 4u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {786706u, aot_fast_000c0112, 6u},
    {827316u, aot_fast_000c9fb4, 1u},
    {0u, 0, 0u},
    {294136u, aot_fast_00047cf8, 2u},
    {293786u, aot_fast_00047b9a, 6u},
    {711228u, aot_fast_000ada3c, 1u},
    {826266u, aot_fast_000c9b9a, 1u},
    {0u, 0, 0u},
    {783906u, aot_fast_000bf622, 4u},
    {792098u, aot_fast_000c1622, 1u},
    {701286u, aot_fast_000ab366, 4u},
    {791398u, aot_fast_000c1366, 3u},
    {0u, 0, 0u},
    {601932u, aot_fast_00092f4c, 2u},
    {0u, 0, 0u},
    {699536u, aot_fast_000aac90, 2u},
    {690994u, aot_fast_000a8b32, 6u},
    {690644u, aot_fast_000a89d4, 13u},
    {788598u, aot_fast_000c0876, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {295678u, aot_fast_000482fe, 6u},
    {713120u, aot_fast_000ae1a0, 5u},
    {713470u, aot_fast_000ae2fe, 9u},
    {0u, 0, 0u},
    {294278u, aot_fast_00047d86, 5u},
    {293928u, aot_fast_00047c28, 6u},
    {793990u, aot_fast_000c1d86, 2u},
    {826058u, aot_fast_000c9aca, 2u},
    {595982u, aot_fast_0009180e, 3u},
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
    {689736u, aot_fast_000a8648, 13u},
    {713962u, aot_fast_000ae4ea, 2u},
    {295820u, aot_fast_0004838c, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {826900u, aot_fast_000c9e14, 2u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {602216u, aot_fast_00093068, 3u},
    {691978u, aot_fast_000a8f0a, 2u},
    {601516u, aot_fast_00092dac, 1u},
    {789582u, aot_fast_000c0c4e, 5u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {788182u, aot_fast_000c06d6, 5u},
    {296312u, aot_fast_00048578, 9u},
    {0u, 0, 0u},
    {0u, 0, 0u},
    {0u, 0, 0u},
};
const uint32_t agr_aot_fast_hash_mask = 4095u;
