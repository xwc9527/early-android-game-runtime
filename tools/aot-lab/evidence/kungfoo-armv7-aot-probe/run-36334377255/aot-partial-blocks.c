#include "agr_aot.h"

static int aot_00046a84(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 289412u) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, 289420u, 0u);
    s->r[15] = 289416u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00046a88(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 289416u) != 3800877729u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, s->r[12], 659456u);
    s->r[15] = 289420u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00046a8c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 289420u) != 3854365380u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { uint32_t addr = s->r[12] + 708u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_00046ab4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 289460u) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, 289468u, 0u);
    s->r[15] = 289464u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00046ab8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 289464u) != 3800877729u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, s->r[12], 659456u);
    s->r[15] = 289468u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00046abc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 289468u) != 3854365348u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { uint32_t addr = s->r[12] + 676u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_00046b38(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 289592u) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, 289600u, 0u);
    s->r[15] = 289596u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00046b3c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 289596u) != 3800877729u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, s->r[12], 659456u);
    s->r[15] = 289600u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00046b40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 289600u) != 3854365260u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { uint32_t addr = s->r[12] + 588u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_00046b74(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 289652u) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, 289660u, 0u);
    s->r[15] = 289656u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00046b78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 289656u) != 3800877729u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, s->r[12], 659456u);
    s->r[15] = 289660u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00046b7c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 289660u) != 3854365220u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { uint32_t addr = s->r[12] + 548u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_00046e68(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 290408u) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, 290416u, 0u);
    s->r[15] = 290412u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00046e6c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 290412u) != 3800877729u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, s->r[12], 659456u);
    s->r[15] = 290416u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00046e70(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 290416u) != 3854364716u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { uint32_t addr = s->r[12] + 44u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_00047024(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 290852u) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, 290860u, 0u);
    s->r[15] = 290856u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047028(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 290856u) != 3800877728u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, s->r[12], 655360u);
    s->r[15] = 290860u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004702c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 290860u) != 3854368516u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { uint32_t addr = s->r[12] + 3844u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_0004709c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 290972u) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, 290980u, 0u);
    s->r[15] = 290976u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000470a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 290976u) != 3800877728u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, s->r[12], 655360u);
    s->r[15] = 290980u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000470a4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 290980u) != 3854368436u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { uint32_t addr = s->r[12] + 3764u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_000471f8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 291320u) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, 291328u, 0u);
    s->r[15] = 291324u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000471fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 291324u) != 3800877728u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, s->r[12], 655360u);
    s->r[15] = 291328u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047200(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 291328u) != 3854368204u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { uint32_t addr = s->r[12] + 3532u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_00047228(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 291368u) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, 291376u, 0u);
    s->r[15] = 291372u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004722c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 291372u) != 3800877728u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, s->r[12], 655360u);
    s->r[15] = 291376u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047230(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 291376u) != 3854368172u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { uint32_t addr = s->r[12] + 3500u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_00047234(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 291380u) != 3801073152u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, 291388u, 0u);
    s->r[15] = 291384u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047238(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 291384u) != 3800877728u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_add_imm(s, 12, s->r[12], 655360u);
    s->r[15] = 291388u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004723c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 291388u) != 3854368164u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { uint32_t addr = s->r[12] + 3492u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) return rc; }
}

static int aot_000477de(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 292830u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 292832u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000477e6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 292838u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 292840u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000477e8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 292840u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 292842u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000477ec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 292844u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 292846u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000477f6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 292854u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 292856u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047800(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 292864u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 292866u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047802(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 292866u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 292868u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047806(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 292870u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 292872u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047832(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 292914u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 292916u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004783a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 292922u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 292924u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004783c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 292924u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 292926u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047840(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 292928u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 292930u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004784a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 292938u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 292940u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047854(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 292948u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 292950u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047856(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 292950u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 292952u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004785a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 292954u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 292956u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047886(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 292998u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 293000u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004788e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293006u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 293008u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047890(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293008u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 293010u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047894(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293012u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 293014u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004789e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293022u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 293024u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000478a8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293032u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 293034u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000478aa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293034u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 293036u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000478ae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293038u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 293040u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000478da(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293082u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 293084u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000478e2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293090u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 293092u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000478e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293092u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 293094u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000478e8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293096u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 293098u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000478f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293106u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 293108u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000478fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293116u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 293118u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000478fe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293118u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 293120u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047902(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293122u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 293124u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004792e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293166u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 293168u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047936(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293174u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 293176u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047938(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293176u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 293178u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004793c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293180u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 293182u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047946(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293190u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 293192u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047950(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293200u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 293202u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047952(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293202u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 293204u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047956(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293206u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 293208u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047982(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293250u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 293252u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004798a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293258u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 293260u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004798c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293260u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 293262u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047990(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293264u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 293266u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004799a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293274u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 293276u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000479a4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293284u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 293286u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000479a6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293286u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 293288u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000479aa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293290u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 293292u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000479d6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293334u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 293336u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000479de(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293342u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 293344u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000479e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293344u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 293346u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000479e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293348u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 293350u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000479ee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293358u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 293360u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000479f8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293368u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 293370u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000479fa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293370u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 293372u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000479fe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293374u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 293376u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047a2a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293418u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 293420u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047a32(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293426u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 293428u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047a34(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293428u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 293430u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047a38(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293432u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 293434u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047a42(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293442u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 293444u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047a4c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293452u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 293454u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047a4e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293454u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 293456u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047a52(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293458u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 293460u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047a7e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293502u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 293504u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047a86(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293510u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 293512u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047a88(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293512u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 293514u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047a8c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293516u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 293518u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047a96(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293526u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 293528u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047aa0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293536u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 293538u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047aa2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293538u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 293540u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047aa6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293542u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 293544u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047ad2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293586u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 293588u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047ada(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293594u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 293596u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047adc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293596u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 293598u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047ae0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293600u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 293602u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047aea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293610u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 293612u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047af4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293620u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 293622u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047af6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293622u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 293624u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047afa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293626u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 293628u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047b26(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293670u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 293672u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047b2e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293678u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 293680u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047b30(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293680u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 293682u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047b34(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293684u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 293686u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047b3e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293694u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 293696u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047b48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293704u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 293706u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047b4a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293706u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 293708u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047b4e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293710u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 293712u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047b7a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293754u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 293756u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047b82(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293762u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 293764u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047b84(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293764u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 293766u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047b88(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293768u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 293770u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047b92(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293778u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 293780u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047b9c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293788u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 293790u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047b9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293790u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 293792u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047ba2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293794u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 293796u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047bce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293838u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 293840u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047bd6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293846u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 293848u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047bd8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293848u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 293850u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047bdc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293852u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 293854u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047be6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293862u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 293864u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047bf0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293872u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 293874u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047bf2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293874u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 293876u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047bf6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293878u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 293880u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047c22(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293922u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 293924u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047c2a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293930u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 293932u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047c2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293932u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 293934u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047c30(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293936u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 293938u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047c3a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293946u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 293948u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047c44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293956u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 293958u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047c46(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293958u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 293960u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047c4a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 293962u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 293964u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047c76(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294006u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 294008u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047c7e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294014u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 294016u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047c80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294016u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 294018u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047c84(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294020u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 294022u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047c8e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294030u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 294032u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047c98(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294040u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 294042u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047c9a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294042u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 294044u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047c9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294046u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 294048u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047cca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294090u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 294092u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047cd2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294098u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 294100u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047cd4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294100u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 294102u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047cd8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294104u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 294106u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047ce2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294114u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 294116u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047cec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294124u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 294126u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047cee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294126u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 294128u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047cf2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294130u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 294132u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047d1e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294174u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 294176u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047d26(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294182u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 294184u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047d28(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294184u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 294186u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047d2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294188u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 294190u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047d36(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294198u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 294200u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047d40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294208u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 294210u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047d42(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294210u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 294212u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047d46(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294214u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 294216u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047d72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294258u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 294260u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047d7a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294266u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 294268u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047d7c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294268u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 294270u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047d80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294272u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 294274u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047d8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294282u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 294284u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047d94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294292u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 294294u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047d96(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294294u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 294296u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047d9a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294298u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 294300u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047dc6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294342u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 294344u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047dce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294350u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 294352u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047dd0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294352u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 294354u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047dd4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294356u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 294358u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047dde(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294366u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 294368u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047de8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294376u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 294378u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047dea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294378u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 294380u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047dee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294382u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 294384u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047e1a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294426u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 294428u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047e22(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294434u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 294436u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047e24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294436u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 294438u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047e28(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294440u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 294442u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047e32(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294450u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 294452u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047e3c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294460u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 294462u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047e3e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294462u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 294464u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047e42(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294466u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 294468u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047e6e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294510u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 294512u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047e76(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294518u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 294520u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047e78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294520u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 294522u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047e7c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294524u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 294526u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047e86(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294534u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 294536u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047e90(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294544u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 294546u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047e92(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294546u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 294548u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047e96(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294550u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 294552u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047ec2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294594u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 294596u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047eca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294602u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 294604u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047ecc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294604u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 294606u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047ed0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294608u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 294610u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047eda(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294618u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 294620u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047ee4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294628u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 294630u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047ee6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294630u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 294632u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047eea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294634u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 294636u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047f16(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294678u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 294680u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047f1e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294686u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 294688u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047f20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294688u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 294690u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047f24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294692u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 294694u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047f2e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294702u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 294704u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047f38(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294712u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 294714u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047f3a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294714u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 294716u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047f3e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294718u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 294720u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047f6a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294762u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 294764u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047f72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294770u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 294772u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047f74(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294772u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 294774u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047f78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294776u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 294778u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047f82(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294786u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 294788u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047f8c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294796u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 294798u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047f8e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294798u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 294800u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047f92(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294802u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 294804u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047fbe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294846u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 294848u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047fc6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294854u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 294856u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047fc8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294856u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 294858u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047fcc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294860u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 294862u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047fd6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294870u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 294872u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047fe0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294880u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 294882u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047fe2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294882u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 294884u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00047fe6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294886u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 294888u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048012(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294930u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 294932u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004801a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294938u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 294940u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004801c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294940u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 294942u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048020(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294944u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 294946u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004802a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294954u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 294956u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048034(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294964u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 294966u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048036(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294966u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 294968u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004803a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 294970u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 294972u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048066(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295014u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 295016u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004806e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295022u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 295024u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048070(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295024u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 295026u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048074(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295028u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 295030u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004807e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295038u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 295040u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048088(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295048u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 295050u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004808a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295050u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 295052u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004808e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295054u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 295056u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000480ba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295098u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 295100u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000480c2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295106u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 295108u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000480c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295108u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 295110u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000480c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295112u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 295114u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000480d2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295122u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 295124u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000480dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295132u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 295134u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000480de(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295134u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 295136u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000480e2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295138u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 295140u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004810e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295182u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 295184u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048116(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295190u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 295192u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048118(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295192u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 295194u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004811c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295196u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 295198u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048126(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295206u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 295208u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048130(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295216u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 295218u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048132(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295218u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 295220u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048136(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295222u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 295224u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048162(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295266u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 295268u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004816a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295274u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 295276u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004816c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295276u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 295278u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048170(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295280u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 295282u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004817a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295290u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 295292u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048184(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295300u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 295302u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048186(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295302u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 295304u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004818a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295306u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 295308u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000481b6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295350u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 295352u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000481be(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295358u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 295360u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000481c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295360u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 295362u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000481c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295364u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 295366u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000481ce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295374u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 295376u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000481d8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295384u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 295386u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000481da(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295386u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 295388u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000481de(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295390u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 295392u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004820a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295434u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 295436u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048212(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295442u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 295444u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048214(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295444u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 295446u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048218(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295448u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 295450u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048222(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295458u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 295460u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004822c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295468u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 295470u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004822e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295470u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 295472u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048232(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295474u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 295476u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048256(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295510u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 295512u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048260(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295520u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 295522u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048264(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295524u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 295526u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048268(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295528u) != 59581u || agr_aot_load16(s, 295530u) != 16400u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    if ((rc = agr_aot_ldmia_sp(s, 16400u))) return rc;
    s->r[15] = 295532u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004828a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295562u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 295564u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048292(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295570u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 295572u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048294(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295572u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 295574u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048298(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295576u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 295578u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000482a2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295586u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 295588u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000482ac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295596u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 295598u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000482ae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295598u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 295600u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000482b2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295602u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 295604u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000482de(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295646u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 295648u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000482e6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295654u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 295656u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000482e8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295656u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 295658u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000482ec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295660u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 295662u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000482f6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295670u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 295672u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048300(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295680u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 295682u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048302(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295682u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 295684u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048306(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295686u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 295688u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004832a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295722u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 295724u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048334(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295732u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 295734u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048338(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295736u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 295738u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004833c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295740u) != 59581u || agr_aot_load16(s, 295742u) != 16400u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    if ((rc = agr_aot_ldmia_sp(s, 16400u))) return rc;
    s->r[15] = 295744u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004835e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295774u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 295776u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048366(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295782u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 295784u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048368(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295784u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 295786u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004836c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295788u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 295790u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048376(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295798u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 295800u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048380(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295808u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 295810u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048382(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295810u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 295812u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048386(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295814u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 295816u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000483b2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295858u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 295860u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000483ba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295866u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 295868u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000483bc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295868u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 295870u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000483c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295872u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 295874u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000483ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295882u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 295884u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000483d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295892u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 295894u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000483d6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295894u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 295896u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000483da(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295898u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 295900u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000483fe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295934u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 295936u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048408(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295944u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 295946u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004840c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295948u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 295950u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048410(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295952u) != 59581u || agr_aot_load16(s, 295954u) != 16400u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    if ((rc = agr_aot_ldmia_sp(s, 16400u))) return rc;
    s->r[15] = 295956u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048432(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295986u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 295988u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004843a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295994u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 295996u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004843c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 295996u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 295998u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048440(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296000u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 296002u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004844a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296010u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 296012u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048454(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296020u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 296022u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048456(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296022u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 296024u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004845a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296026u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 296028u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048486(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296070u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 296072u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004848e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296078u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 296080u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048490(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296080u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 296082u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048494(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296084u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 296086u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004849e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296094u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 296096u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000484a8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296104u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 296106u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000484aa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296106u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 296108u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000484ae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296110u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 296112u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000484da(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296154u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 296156u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000484e2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296162u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 296164u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000484e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296164u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 296166u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000484e8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296168u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 296170u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000484f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296178u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 296180u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000484fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296188u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 296190u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000484fe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296190u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 296192u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048502(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296194u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 296196u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048522(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296226u) != 8704u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 296228u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048526(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296230u) != 26651u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 296232u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048540(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296256u) != 26624u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 296258u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048542(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296258u) != 17954u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 4);
    s->r[15] = 296260u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048546(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296262u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 296264u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048550(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296272u) != 17954u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 4);
    s->r[15] = 296274u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048554(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296276u) != 26624u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 296278u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048558(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296280u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 296282u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004855a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296282u) != 59581u || agr_aot_load16(s, 296284u) != 16400u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    if ((rc = agr_aot_ldmia_sp(s, 16400u))) return rc;
    s->r[15] = 296286u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048586(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296326u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 296328u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004858e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296334u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 296336u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048590(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296336u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 296338u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048594(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296340u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 296342u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004859e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296350u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 296352u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000485a8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296360u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 296362u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000485aa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296362u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 296364u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000485ae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296366u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 296368u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000485da(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296410u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 296412u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000485e2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296418u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 296420u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000485e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296420u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 296422u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000485e8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296424u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 296426u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000485f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296434u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 296436u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000485fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296444u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 296446u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000485fe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296446u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 296448u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048602(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296450u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 296452u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048622(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296482u) != 8960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 296484u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004862c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296492u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 296494u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048630(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296496u) != 63486u || agr_aot_load16(s, 296498u) != 60664u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, 290852u, 296500u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_00048640(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296512u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 296514u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048644(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296516u) != 8960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 296518u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048648(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296520u) != 59581u || agr_aot_load16(s, 296522u) != 16400u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    if ((rc = agr_aot_ldmia_sp(s, 16400u))) return rc;
    s->r[15] = 296524u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048662(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296546u) != 8704u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 296548u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048674(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296564u) != 26650u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 296566u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004867a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296570u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 296572u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048682(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296578u) != 26650u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 296580u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048688(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296584u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 296586u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048690(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296592u) != 26650u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 296594u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048696(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296598u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 296600u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004869e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296606u) != 26650u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 296608u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000486a4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296612u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 296614u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000486ac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296620u) != 26650u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 296622u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000486b2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296626u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 296628u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000486ba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296634u) != 26650u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 296636u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000486c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296640u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 296642u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000486c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296648u) != 26650u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 296650u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000486ce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296654u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 296656u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000486d6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296662u) != 26650u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 296664u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000486dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296668u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 296670u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000486e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296676u) != 26650u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 296678u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000486ea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296682u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 296684u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000486f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296690u) != 26650u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 296692u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000486f8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296696u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 296698u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048700(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296704u) != 26650u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 296706u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048706(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296710u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 296712u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004870e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296718u) != 26650u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 296720u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048714(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296724u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 296726u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048750(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296784u) != 26650u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 296786u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048756(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296790u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 296792u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004875e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296798u) != 26650u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 296800u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048764(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296804u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 296806u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004876c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296812u) != 26650u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 296814u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048772(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296818u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 296820u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004877a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296826u) != 26650u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 296828u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048780(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296832u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 296834u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048788(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296840u) != 26650u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 296842u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004878e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296846u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 296848u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048796(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296854u) != 26650u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 296856u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004879c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296860u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 296862u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000487a4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296868u) != 26650u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 296870u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000487aa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296874u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 296876u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000487b2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296882u) != 26650u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 296884u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000487b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296888u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 296890u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000487c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296896u) != 26650u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 296898u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000487c6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296902u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 296904u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000487ce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296910u) != 26650u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 296912u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000487d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296916u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 296918u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000487dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296924u) != 26650u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 296926u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000487e2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296930u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 296932u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000487ea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296938u) != 26650u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 296940u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000487f0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 296944u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 296946u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048836(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 297014u) != 17944u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 3);
    s->r[15] = 297016u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004883a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 297018u) != 17954u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 4);
    s->r[15] = 297020u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048848(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 297032u) != 17954u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 4);
    s->r[15] = 297034u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00048854(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 297044u) != 17944u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 3);
    s->r[15] = 297046u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0004885a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 297050u) != 59581u || agr_aot_load16(s, 297052u) != 16440u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    if ((rc = agr_aot_ldmia_sp(s, 16440u))) return rc;
    s->r[15] = 297054u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000918ee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 596206u) != 26688u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 4u); if (rc) return rc; }
    s->r[15] = 596208u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000918f6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 596214u) != 26697u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 4u); if (rc) return rc; }
    s->r[15] = 596216u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00091900(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 596224u) != 63413u || agr_aot_load16(s, 596226u) != 59674u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, 289592u, 596228u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_0009190a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 596234u) != 8192u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = 596236u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00091912(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 596242u) != 8193u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = 596244u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000919cc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 596428u) != 59693u || agr_aot_load16(s, 596430u) != 20464u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    if (agr_aot_stmdb_sp(s, 20464u)) return AGR_AOT_FAULT;
    s->r[15] = 596432u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000919d2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 596434u) != 18059u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 11, 1);
    s->r[15] = 596436u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000919d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 596436u) != 39971u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 4, s->r[13] + 140u); if (rc) return rc; }
    s->r[15] = 596438u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000919d8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 596440u) != 63709u || agr_aot_load16(s, 596442u) != 36992u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 9, s->r[13] + 128u); if (rc) return rc; }
    s->r[15] = 596444u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000919dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 596444u) != 26915u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 16u); if (rc) return rc; }
    s->r[15] = 596446u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000919de(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 596446u) != 40738u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 7, s->r[13] + 136u); if (rc) return rc; }
    s->r[15] = 596448u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000919e8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 596456u) != 26755u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = 596458u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000919f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 596466u) != 38925u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 52u); if (rc) return rc; }
    s->r[15] = 596468u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000919f4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 596468u) != 39176u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 32u); if (rc) return rc; }
    s->r[15] = 596470u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00091b5c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 596828u) != 40715u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 7, s->r[13] + 44u); if (rc) return rc; }
    s->r[15] = 596830u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00091b6c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 596844u) != 9984u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 7, 0u);
    s->r[15] = 596846u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00091b70(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 596848u) != 40738u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 7, s->r[13] + 136u); if (rc) return rc; }
    s->r[15] = 596850u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00091b7a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 596858u) != 8961u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 1u);
    s->r[15] = 596860u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00091b7c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 596860u) != 8966u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 6u);
    s->r[15] = 596862u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00091b80(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 596864u) != 38922u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 40u); if (rc) return rc; }
    s->r[15] = 596866u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00091b84(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 596868u) != 59581u || agr_aot_load16(s, 596870u) != 36848u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    if ((rc = agr_aot_ldmia_sp(s, 36848u))) return rc;
}

static int aot_00091ca8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 597160u) != 38925u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 52u); if (rc) return rc; }
    s->r[15] = 597162u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00091caa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 597162u) != 39201u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 132u); if (rc) return rc; }
    s->r[15] = 597164u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00092672(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 599666u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 599668u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00092674(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 599668u) != 9217u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 4, 1u);
    s->r[15] = 599670u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00092678(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 599672u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 599674u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009267c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 599676u) != 63412u || agr_aot_load16(s, 599678u) != 60404u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, 290408u, 599680u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_00092680(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 599680u) != 47440u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = s->r[0] ? 599704u : 599682u; return AGR_AOT_BOUNDARY;
}

static int aot_0009296c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 600428u) != 59693u || agr_aot_load16(s, 600430u) != 20464u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    if (agr_aot_stmdb_sp(s, 20464u)) return AGR_AOT_FAULT;
    s->r[15] = 600432u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00092972(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 600434u) != 18056u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 8, 1);
    s->r[15] = 600436u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00092974(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 600436u) != 17945u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 3);
    s->r[15] = 600438u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00092976(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 600438u) != 17951u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 7, 3);
    s->r[15] = 600440u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00092978(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 600440u) != 18066u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 10, 2);
    s->r[15] = 600442u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009297a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 600442u) != 18051u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 11, 0);
    s->r[15] = 600444u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009297c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 600444u) != 40462u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 6, s->r[13] + 56u); if (rc) return rc; }
    s->r[15] = 600446u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009297e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 600446u) != 63709u || agr_aot_load16(s, 600448u) != 36928u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 9, s->r[13] + 64u); if (rc) return rc; }
    s->r[15] = 600450u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00092982(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 600450u) != 40209u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 5, s->r[13] + 68u); if (rc) return rc; }
    s->r[15] = 600452u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00092988(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 600456u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 600458u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009298a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 600458u) != 45432u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[0] ? 600492u : 600460u; return AGR_AOT_BOUNDARY;
}

static int aot_00092998(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 600472u) != 9216u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 4, 0u);
    s->r[15] = 600474u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009299e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 600478u) != 9729u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 6, 1u);
    s->r[15] = 600480u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000929a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 600480u) != 9734u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 6, 6u);
    s->r[15] = 600482u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000929a2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 600482u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 600484u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000929a8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 600488u) != 59581u || agr_aot_load16(s, 600490u) != 36848u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    if ((rc = agr_aot_ldmia_sp(s, 36848u))) return rc;
}

static int aot_00092d08(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 601352u) != 59693u || agr_aot_load16(s, 601354u) != 17392u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    if (agr_aot_stmdb_sp(s, 17392u)) return AGR_AOT_FAULT;
    s->r[15] = 601356u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00092d0c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 601356u) != 17925u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 601358u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00092d0e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 601358u) != 26630u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 6, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 601360u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00092d12(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 601362u) != 9216u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 4, 0u);
    s->r[15] = 601364u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00092d14(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 601364u) != 18056u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 8, 1);
    s->r[15] = 601366u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00092d1a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 601370u) != 17945u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 3);
    s->r[15] = 601372u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00092d20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 601376u) != 18065u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 9, 2);
    s->r[15] = 601378u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00092d26(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 601382u) != 17951u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 7, 3);
    s->r[15] = 601384u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00092d2a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 601386u) != 17939u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 3, 2);
    s->r[15] = 601388u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00092d2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 601388u) != 26630u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 6, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 601390u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00092d34(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 601396u) != 8710u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 6u);
    s->r[15] = 601398u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00092d46(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 601414u) != 27126u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 6, s->r[6] + 28u); if (rc) return rc; }
    s->r[15] = 601416u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00092d50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 601424u) != 18352u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, s->r[6], 601426u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_00092d52(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 601426u) != 38917u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 20u); if (rc) return rc; }
    s->r[15] = 601428u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00092d54(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 601428u) != 45480u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[0] ? 601474u : 601430u; return AGR_AOT_BOUNDARY;
}

static int aot_00092d56(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 601430u) != 39944u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 4, s->r[13] + 32u); if (rc) return rc; }
    s->r[15] = 601432u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00092d86(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 601478u) != 59581u || agr_aot_load16(s, 601480u) != 33776u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    if ((rc = agr_aot_ldmia_sp(s, 33776u))) return rc;
}

static int aot_000932c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 602820u) != 17923u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 3, 0);
    s->r[15] = 602822u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000932c6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 602822u) != 17928u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 1);
    s->r[15] = 602824u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000932c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 602824u) != 17945u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 3);
    s->r[15] = 602826u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009334c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 602956u) != 59693u || agr_aot_load16(s, 602958u) != 20464u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    if (agr_aot_stmdb_sp(s, 20464u)) return AGR_AOT_FAULT;
    s->r[15] = 602960u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093352(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 602962u) != 63711u || agr_aot_load16(s, 602964u) != 17588u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 4, 602964u + 1204u); if (rc) return rc; }
    s->r[15] = 602966u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093356(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 602966u) != 18051u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 11, 0);
    s->r[15] = 602968u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093358(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 602968u) != 63711u || agr_aot_load16(s, 602970u) != 13488u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 602972u + 1200u); if (rc) return rc; }
    s->r[15] = 602972u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093380(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603008u) != 18008u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 11);
    s->r[15] = 603010u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093384(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603012u) != 59581u || agr_aot_load16(s, 603014u) != 36848u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    if ((rc = agr_aot_ldmia_sp(s, 36848u))) return rc;
}

static int aot_00093388(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603016u) != 63711u || agr_aot_load16(s, 603018u) != 13444u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 603020u + 1156u); if (rc) return rc; }
    s->r[15] = 603020u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009338c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603020u) != 8193u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = 603022u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009338e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603022u) != 63711u || agr_aot_load16(s, 603024u) != 5252u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, 603024u + 1156u); if (rc) return rc; }
    s->r[15] = 603026u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093396(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603030u) != 63711u || agr_aot_load16(s, 603032u) != 9344u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, 603032u + 1152u); if (rc) return rc; }
    s->r[15] = 603034u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000933c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603080u) != 63711u || agr_aot_load16(s, 603082u) != 9296u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, 603084u + 1104u); if (rc) return rc; }
    s->r[15] = 603084u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000933cc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603084u) != 63711u || agr_aot_load16(s, 603086u) != 1104u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, 603088u + 1104u); if (rc) return rc; }
    s->r[15] = 603088u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000933d0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603088u) != 63711u || agr_aot_load16(s, 603090u) != 5200u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, 603092u + 1104u); if (rc) return rc; }
    s->r[15] = 603092u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000933d6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603094u) != 39681u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 4u); if (rc) return rc; }
    s->r[15] = 603096u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093412(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603154u) != 39171u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 12u); if (rc) return rc; }
    s->r[15] = 603156u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093414(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603156u) != 63711u || agr_aot_load16(s, 603158u) != 9232u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, 603160u + 1040u); if (rc) return rc; }
    s->r[15] = 603160u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093418(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603160u) != 39681u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 4u); if (rc) return rc; }
    s->r[15] = 603162u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093446(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603206u) != 38915u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 12u); if (rc) return rc; }
    s->r[15] = 603208u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009345a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603226u) != 18000u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 10);
    s->r[15] = 603228u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093466(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603238u) != 18000u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 10);
    s->r[15] = 603240u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009346c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603244u) != 17993u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 9);
    s->r[15] = 603246u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000934a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603296u) != 17992u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 9);
    s->r[15] = 603298u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000934a8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603304u) != 8960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 603306u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000934b2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603314u) != 17992u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 9);
    s->r[15] = 603316u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000934b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603320u) != 17961u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 5);
    s->r[15] = 603322u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000934ea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603370u) != 17992u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 9);
    s->r[15] = 603372u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000934f8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603384u) != 17992u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 9);
    s->r[15] = 603386u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000934fe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603390u) != 17969u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 6);
    s->r[15] = 603392u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093500(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603392u) != 8960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 603394u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009352a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603434u) != 17944u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 3);
    s->r[15] = 603436u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093530(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603440u) != 39681u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 4u); if (rc) return rc; }
    s->r[15] = 603442u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093536(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603446u) != 17969u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 6);
    s->r[15] = 603448u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093538(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603448u) != 17944u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 3);
    s->r[15] = 603450u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093542(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603458u) != 8960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 603460u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009356a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603498u) != 26923u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 16u); if (rc) return rc; }
    s->r[15] = 603500u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000935a8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603560u) != 39427u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[13] + 12u); if (rc) return rc; }
    s->r[15] = 603562u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000935b2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603570u) != 39681u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 4u); if (rc) return rc; }
    s->r[15] = 603572u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000935ea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603626u) != 38915u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 12u); if (rc) return rc; }
    s->r[15] = 603628u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000935ec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603628u) != 39681u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 4u); if (rc) return rc; }
    s->r[15] = 603630u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009361a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603674u) != 39171u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 12u); if (rc) return rc; }
    s->r[15] = 603676u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009362e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603694u) != 17992u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 9);
    s->r[15] = 603696u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009363a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603706u) != 17992u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 9);
    s->r[15] = 603708u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093640(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603712u) != 17985u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 8);
    s->r[15] = 603714u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093674(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603764u) != 18000u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 10);
    s->r[15] = 603766u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009367c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603772u) != 8960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 603774u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093686(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603782u) != 18000u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 10);
    s->r[15] = 603784u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009368c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603788u) != 17961u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 5);
    s->r[15] = 603790u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000936be(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603838u) != 18000u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 10);
    s->r[15] = 603840u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000936cc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603852u) != 18000u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 10);
    s->r[15] = 603854u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000936d2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603858u) != 17969u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 6);
    s->r[15] = 603860u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000936d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603860u) != 8960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 603862u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000936fe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603902u) != 17944u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 3);
    s->r[15] = 603904u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093704(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603908u) != 39681u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 4u); if (rc) return rc; }
    s->r[15] = 603910u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009370a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603914u) != 17969u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 6);
    s->r[15] = 603916u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009370c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603916u) != 17944u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 3);
    s->r[15] = 603918u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093716(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603926u) != 8960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 603928u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093738(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603960u) != 26923u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 16u); if (rc) return rc; }
    s->r[15] = 603962u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093746(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603974u) != 38914u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 8u); if (rc) return rc; }
    s->r[15] = 603976u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009375a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 603994u) != 18008u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 11);
    s->r[15] = 603996u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093762(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 604002u) != 59581u || agr_aot_load16(s, 604004u) != 36848u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    if ((rc = agr_aot_ldmia_sp(s, 36848u))) return rc;
}

static int aot_00093d22(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 605474u) != 17925u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 605476u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093d24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 605476u) != 17928u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 1);
    s->r[15] = 605478u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093d26(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 605478u) != 17932u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 1);
    s->r[15] = 605480u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093d2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 605484u) != 45488u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[0] ? 605532u : 605486u; return AGR_AOT_BOUNDARY;
}

static int aot_00093d2e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 605486u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 605488u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093d36(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 605494u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 605496u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093d3c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 605500u) != 45464u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[0] ? 605542u : 605502u; return AGR_AOT_BOUNDARY;
}

static int aot_00093d3e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 605502u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 605504u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093d48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 605512u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 605514u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093d4e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 605518u) != 45368u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[0] ? 605536u : 605520u; return AGR_AOT_BOUNDARY;
}

static int aot_00093d50(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 605520u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 605522u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093dde(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 605662u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 605664u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093de0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 605664u) != 17933u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 5, 1);
    s->r[15] = 605666u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093de6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 605670u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 605672u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00093e00(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 605696u) != 9472u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 5, 0u);
    s->r[15] = 605698u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009414e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 606542u) != 17925u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 606544u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00094150(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 606544u) != 17928u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 1);
    s->r[15] = 606546u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00094152(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 606546u) != 17932u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 1);
    s->r[15] = 606548u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00094158(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 606552u) != 45496u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[0] ? 606602u : 606554u; return AGR_AOT_BOUNDARY;
}

static int aot_0009415a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 606554u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 606556u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00094164(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 606564u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 606566u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009416a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 606570u) != 45472u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[0] ? 606614u : 606572u; return AGR_AOT_BOUNDARY;
}

static int aot_0009416c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 606572u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 606574u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00094176(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 606582u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 606584u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009417c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 606588u) != 45376u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[0] ? 606608u : 606590u; return AGR_AOT_BOUNDARY;
}

static int aot_0009417e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 606590u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 606592u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009420e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 606734u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 606736u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00094210(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 606736u) != 17933u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 5, 1);
    s->r[15] = 606738u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00094216(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 606742u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 606744u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009422e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 606766u) != 9472u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 5, 0u);
    s->r[15] = 606768u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000957ea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 612330u) != 8448u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = 612332u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000957ee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 612334u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 612336u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000957fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 612348u) != 17930u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 1);
    s->r[15] = 612350u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00095822(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 612386u) != 17944u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 3);
    s->r[15] = 612388u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00095824(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 612388u) != 8968u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 8u);
    s->r[15] = 612390u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009582c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 612396u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 612398u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000970c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 618688u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 618690u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000970c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 618696u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 618698u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000970ce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 618702u) != 8448u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = 618704u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000970d2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 618706u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 618708u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000970d8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 618712u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 618714u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00097542(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 619842u) != 8449u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = 619844u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00097548(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 619848u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 619850u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00097552(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 619858u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 619860u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000977ac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 620460u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 620462u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000977ae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 620462u) != 17944u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 3);
    s->r[15] = 620464u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000977b2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 620466u) != 26624u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 620468u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000977b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 620472u) != 26659u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 620474u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000977ba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 620474u) != 26777u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[3] + 8u); if (rc) return rc; }
    s->r[15] = 620476u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000977bc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 620476u) != 26715u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) return rc; }
    s->r[15] = 620478u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000977c6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 620486u) != 45392u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[0] ? 620510u : 620488u; return AGR_AOT_BOUNDARY;
}

static int aot_000977ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 620490u) != 8960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 620492u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000977d0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 620496u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 620498u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000977d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 620500u) != 26642u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[2] + 0u); if (rc) return rc; }
    s->r[15] = 620502u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000977da(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 620506u) != 45328u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[0] ? 620514u : 620508u; return AGR_AOT_BOUNDARY;
}

static int aot_0009803e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 622654u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 622656u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00098048(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 622664u) != 26659u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 622666u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009804a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 622666u) != 26777u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[3] + 8u); if (rc) return rc; }
    s->r[15] = 622668u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009804c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 622668u) != 26715u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) return rc; }
    s->r[15] = 622670u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00098056(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 622678u) != 45384u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[0] ? 622700u : 622680u; return AGR_AOT_BOUNDARY;
}

static int aot_0009805a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 622682u) != 8960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 622684u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00098060(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 622688u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 622690u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00098068(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 622696u) != 45328u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[0] ? 622704u : 622698u; return AGR_AOT_BOUNDARY;
}

static int aot_00098082(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 622722u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 622724u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009808c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 622732u) != 26659u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 622734u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009808e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 622734u) != 26777u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[3] + 8u); if (rc) return rc; }
    s->r[15] = 622736u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00098090(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 622736u) != 26715u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) return rc; }
    s->r[15] = 622738u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009809a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 622746u) != 45384u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[0] ? 622768u : 622748u; return AGR_AOT_BOUNDARY;
}

static int aot_0009809e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 622750u) != 8960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 622752u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000980a4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 622756u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 622758u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000980ac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 622764u) != 45328u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[0] ? 622772u : 622766u; return AGR_AOT_BOUNDARY;
}

static int aot_00098b6c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 625516u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 625518u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00098b6e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 625518u) != 17944u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 3);
    s->r[15] = 625520u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00098b72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 625522u) != 26624u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 625524u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00098b78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 625528u) != 26659u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 625530u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00098b7a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 625530u) != 26777u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[3] + 8u); if (rc) return rc; }
    s->r[15] = 625532u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00098b7c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 625532u) != 26715u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) return rc; }
    s->r[15] = 625534u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00098b86(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 625542u) != 45416u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[0] ? 625572u : 625544u; return AGR_AOT_BOUNDARY;
}

static int aot_00098b8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 625546u) != 8960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 625548u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00098b90(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 625552u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 625554u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00098b94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 625556u) != 26642u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[2] + 0u); if (rc) return rc; }
    s->r[15] = 625558u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00098b9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 625566u) != 8193u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = 625568u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00098c8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 625802u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 625804u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00098c94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 625812u) != 26659u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 625814u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00098c96(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 625814u) != 26777u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[3] + 8u); if (rc) return rc; }
    s->r[15] = 625816u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00098c98(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 625816u) != 26715u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) return rc; }
    s->r[15] = 625818u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00098ca2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 625826u) != 45408u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[0] ? 625854u : 625828u; return AGR_AOT_BOUNDARY;
}

static int aot_00098ca6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 625830u) != 8960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 625832u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00098cac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 625836u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 625838u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00098cb8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 625848u) != 8193u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = 625850u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00098cce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 625870u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 625872u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00098cd8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 625880u) != 26659u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 625882u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00098cda(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 625882u) != 26777u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[3] + 8u); if (rc) return rc; }
    s->r[15] = 625884u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00098cdc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 625884u) != 26715u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) return rc; }
    s->r[15] = 625886u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00098ce6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 625894u) != 45408u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[0] ? 625922u : 625896u; return AGR_AOT_BOUNDARY;
}

static int aot_00098cea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 625898u) != 8960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 625900u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00098cf0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 625904u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 625906u;
    return AGR_AOT_BOUNDARY;
}

static int aot_00098cfc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 625916u) != 8193u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = 625918u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009ff96(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 655254u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 655256u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009ff9c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 655260u) != 8449u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = 655262u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009ffa8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 655272u) != 26669u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 5, s->r[5] + 0u); if (rc) return rc; }
    s->r[15] = 655274u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009ffb0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 655280u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 655282u;
    return AGR_AOT_BOUNDARY;
}

static int aot_0009fffe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 655358u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 655360u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a0004(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 655364u) != 8449u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = 655366u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a0010(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 655376u) != 26669u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 5, s->r[5] + 0u); if (rc) return rc; }
    s->r[15] = 655378u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a0018(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 655384u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 655386u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a77f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 686066u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 686068u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a77f4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 686068u) != 8704u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 686070u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a77f6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 686070u) != 8966u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 6u);
    s->r[15] = 686072u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a77fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 686076u) != 62017u || agr_aot_load16(s, 686078u) != 770u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movw(s, 3, 4098u);
    s->r[15] = 686080u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7800(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 686080u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 686082u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7808(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 686088u) != 17961u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 5);
    s->r[15] = 686090u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7812(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 686098u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 686100u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7b22(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 686882u) != 17923u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 3, 0);
    s->r[15] = 686884u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7b24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 686884u) != 17928u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 1);
    s->r[15] = 686886u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7b28(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 686888u) != 8704u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 686890u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7b2e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 686894u) != 63391u || agr_aot_load16(s, 686896u) != 59396u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, 289592u, 686898u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_000a7b32(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 686898u) != 47360u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = s->r[0] ? 686902u : 686900u; return AGR_AOT_BOUNDARY;
}

static int aot_000a7bcc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687052u) != 59693u || agr_aot_load16(s, 687054u) != 20472u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    if (agr_aot_stmdb_sp(s, 20472u)) return AGR_AOT_FAULT;
    s->r[15] = 687056u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7bd0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687056u) != 17925u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 687058u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7bd2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687058u) != 26756u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 4, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = 687060u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7bda(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687066u) != 63711u || agr_aot_load16(s, 687068u) != 45580u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 11, 687068u + 524u); if (rc) return rc; }
    s->r[15] = 687070u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7bde(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687070u) != 63711u || agr_aot_load16(s, 687072u) != 41484u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 10, 687072u + 524u); if (rc) return rc; }
    s->r[15] = 687074u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7be4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687076u) != 63711u || agr_aot_load16(s, 687078u) != 37384u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 9, 687080u + 520u); if (rc) return rc; }
    s->r[15] = 687080u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7bf4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687092u) != 63711u || agr_aot_load16(s, 687094u) != 33276u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 8, 687096u + 508u); if (rc) return rc; }
    s->r[15] = 687096u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7bfa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687098u) != 63711u || agr_aot_load16(s, 687100u) != 45568u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 11, 687100u + 512u); if (rc) return rc; }
    s->r[15] = 687102u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7c22(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687138u) != 63711u || agr_aot_load16(s, 687140u) != 49628u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 12, 687140u + 476u); if (rc) return rc; }
    s->r[15] = 687142u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7c3c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687164u) != 63711u || agr_aot_load16(s, 687166u) != 41436u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 10, 687168u + 476u); if (rc) return rc; }
    s->r[15] = 687168u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7c42(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687170u) != 63711u || agr_aot_load16(s, 687172u) != 37340u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 9, 687172u + 476u); if (rc) return rc; }
    s->r[15] = 687174u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7c48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687176u) != 63711u || agr_aot_load16(s, 687178u) != 33240u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 8, 687180u + 472u); if (rc) return rc; }
    s->r[15] = 687180u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7c52(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687186u) != 63711u || agr_aot_load16(s, 687188u) != 45528u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 11, 687188u + 472u); if (rc) return rc; }
    s->r[15] = 687190u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7c7e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687230u) != 63711u || agr_aot_load16(s, 687232u) != 49584u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 12, 687232u + 432u); if (rc) return rc; }
    s->r[15] = 687234u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7c9c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687260u) != 63711u || agr_aot_load16(s, 687262u) != 45488u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 11, 687264u + 432u); if (rc) return rc; }
    s->r[15] = 687264u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7ca2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687266u) != 63711u || agr_aot_load16(s, 687268u) != 41392u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 10, 687268u + 432u); if (rc) return rc; }
    s->r[15] = 687270u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7ca8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687272u) != 63711u || agr_aot_load16(s, 687274u) != 37292u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 9, 687276u + 428u); if (rc) return rc; }
    s->r[15] = 687276u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7cae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687278u) != 63711u || agr_aot_load16(s, 687280u) != 33196u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 8, 687280u + 428u); if (rc) return rc; }
    s->r[15] = 687282u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7cd6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687318u) != 63711u || agr_aot_load16(s, 687320u) != 49544u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 12, 687320u + 392u); if (rc) return rc; }
    s->r[15] = 687322u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7cf4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687348u) != 63711u || agr_aot_load16(s, 687350u) != 33156u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 8, 687352u + 388u); if (rc) return rc; }
    s->r[15] = 687352u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7cfa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687354u) != 63711u || agr_aot_load16(s, 687356u) != 45444u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 11, 687356u + 388u); if (rc) return rc; }
    s->r[15] = 687358u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7d00(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687360u) != 63711u || agr_aot_load16(s, 687362u) != 41344u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 10, 687364u + 384u); if (rc) return rc; }
    s->r[15] = 687364u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7d06(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687366u) != 63711u || agr_aot_load16(s, 687368u) != 37248u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 9, 687368u + 384u); if (rc) return rc; }
    s->r[15] = 687370u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7d48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687432u) != 59581u || agr_aot_load16(s, 687434u) != 36856u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    if ((rc = agr_aot_ldmia_sp(s, 36856u))) return rc;
}

static int aot_000a7f1c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687900u) != 59693u || agr_aot_load16(s, 687902u) != 20472u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    if (agr_aot_stmdb_sp(s, 20472u)) return AGR_AOT_FAULT;
    s->r[15] = 687904u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7f20(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687904u) != 17925u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 687906u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7f22(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687906u) != 26756u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 4, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = 687908u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7f2a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687914u) != 63711u || agr_aot_load16(s, 687916u) != 45580u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 11, 687916u + 524u); if (rc) return rc; }
    s->r[15] = 687918u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7f2e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687918u) != 63711u || agr_aot_load16(s, 687920u) != 41484u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 10, 687920u + 524u); if (rc) return rc; }
    s->r[15] = 687922u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7f34(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687924u) != 63711u || agr_aot_load16(s, 687926u) != 37384u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 9, 687928u + 520u); if (rc) return rc; }
    s->r[15] = 687928u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7f44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687940u) != 63711u || agr_aot_load16(s, 687942u) != 33276u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 8, 687944u + 508u); if (rc) return rc; }
    s->r[15] = 687944u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7f4a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687946u) != 63711u || agr_aot_load16(s, 687948u) != 45568u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 11, 687948u + 512u); if (rc) return rc; }
    s->r[15] = 687950u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7f72(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 687986u) != 63711u || agr_aot_load16(s, 687988u) != 49628u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 12, 687988u + 476u); if (rc) return rc; }
    s->r[15] = 687990u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7f8c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 688012u) != 63711u || agr_aot_load16(s, 688014u) != 41436u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 10, 688016u + 476u); if (rc) return rc; }
    s->r[15] = 688016u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7f92(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 688018u) != 63711u || agr_aot_load16(s, 688020u) != 37340u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 9, 688020u + 476u); if (rc) return rc; }
    s->r[15] = 688022u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7f98(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 688024u) != 63711u || agr_aot_load16(s, 688026u) != 33240u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 8, 688028u + 472u); if (rc) return rc; }
    s->r[15] = 688028u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7fa2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 688034u) != 63711u || agr_aot_load16(s, 688036u) != 45528u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 11, 688036u + 472u); if (rc) return rc; }
    s->r[15] = 688038u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7fce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 688078u) != 63711u || agr_aot_load16(s, 688080u) != 49584u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 12, 688080u + 432u); if (rc) return rc; }
    s->r[15] = 688082u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7fec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 688108u) != 63711u || agr_aot_load16(s, 688110u) != 45488u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 11, 688112u + 432u); if (rc) return rc; }
    s->r[15] = 688112u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7ff2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 688114u) != 63711u || agr_aot_load16(s, 688116u) != 41392u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 10, 688116u + 432u); if (rc) return rc; }
    s->r[15] = 688118u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7ff8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 688120u) != 63711u || agr_aot_load16(s, 688122u) != 37292u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 9, 688124u + 428u); if (rc) return rc; }
    s->r[15] = 688124u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a7ffe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 688126u) != 63711u || agr_aot_load16(s, 688128u) != 33196u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 8, 688128u + 428u); if (rc) return rc; }
    s->r[15] = 688130u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8026(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 688166u) != 63711u || agr_aot_load16(s, 688168u) != 49544u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 12, 688168u + 392u); if (rc) return rc; }
    s->r[15] = 688170u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8044(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 688196u) != 63711u || agr_aot_load16(s, 688198u) != 33156u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 8, 688200u + 388u); if (rc) return rc; }
    s->r[15] = 688200u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a804a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 688202u) != 63711u || agr_aot_load16(s, 688204u) != 45444u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 11, 688204u + 388u); if (rc) return rc; }
    s->r[15] = 688206u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8050(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 688208u) != 63711u || agr_aot_load16(s, 688210u) != 41344u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 10, 688212u + 384u); if (rc) return rc; }
    s->r[15] = 688212u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8056(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 688214u) != 63711u || agr_aot_load16(s, 688216u) != 37248u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 9, 688216u + 384u); if (rc) return rc; }
    s->r[15] = 688218u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8098(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 688280u) != 59581u || agr_aot_load16(s, 688282u) != 36856u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    if ((rc = agr_aot_ldmia_sp(s, 36856u))) return rc;
}

static int aot_000a8390(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689040u) != 59693u || agr_aot_load16(s, 689042u) != 20464u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    if (agr_aot_stmdb_sp(s, 20464u)) return AGR_AOT_FAULT;
    s->r[15] = 689044u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8394(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689044u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 689046u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8396(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689046u) != 63711u || agr_aot_load16(s, 689048u) != 26792u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 6, 689048u + 2216u); if (rc) return rc; }
    s->r[15] = 689050u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a839a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689050u) != 9472u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 5, 0u);
    s->r[15] = 689052u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a839c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689052u) != 63711u || agr_aot_load16(s, 689054u) != 30884u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 7, 689056u + 2212u); if (rc) return rc; }
    s->r[15] = 689056u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a83a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689056u) != 17963u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 3, 5);
    s->r[15] = 689058u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a83a4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689060u) != 17962u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 5);
    s->r[15] = 689062u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a83aa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689066u) != 63711u || agr_aot_load16(s, 689068u) != 22684u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 5, 689068u + 2204u); if (rc) return rc; }
    s->r[15] = 689070u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a83b6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689078u) != 17968u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 689080u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a83b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689080u) != 17977u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 7);
    s->r[15] = 689082u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a83c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689092u) != 57345u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = 689098u; return AGR_AOT_BOUNDARY;
}

static int aot_000a83c6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689094u) != 26720u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, s->r[4] + 4u); if (rc) return rc; }
    s->r[15] = 689096u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a83c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689096u) != 26849u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 12u); if (rc) return rc; }
    s->r[15] = 689098u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a83d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689108u) != 63711u || agr_aot_load16(s, 689110u) != 26740u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 6, 689112u + 2164u); if (rc) return rc; }
    s->r[15] = 689112u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a83d8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689112u) != 63711u || agr_aot_load16(s, 689114u) != 30836u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 7, 689116u + 2164u); if (rc) return rc; }
    s->r[15] = 689116u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a83e8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689128u) != 8964u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 4u);
    s->r[15] = 689130u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a83ea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689130u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 689132u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a83ec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689132u) != 8448u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = 689134u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a83fa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689146u) != 26914u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[4] + 16u); if (rc) return rc; }
    s->r[15] = 689148u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8404(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689156u) != 63711u || agr_aot_load16(s, 689158u) != 2124u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, 689160u + 2124u); if (rc) return rc; }
    s->r[15] = 689160u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8408(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689160u) != 8448u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = 689162u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a840a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689162u) != 17930u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 1);
    s->r[15] = 689164u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a840c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689164u) != 8961u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 1u);
    s->r[15] = 689166u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8414(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689172u) != 63711u || agr_aot_load16(s, 689174u) != 14400u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 689176u + 2112u); if (rc) return rc; }
    s->r[15] = 689176u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8418(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689176u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 689178u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a841a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689178u) != 63711u || agr_aot_load16(s, 689180u) != 10304u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, 689180u + 2112u); if (rc) return rc; }
    s->r[15] = 689182u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8426(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689190u) != 63711u || agr_aot_load16(s, 689192u) != 2104u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, 689192u + 2104u); if (rc) return rc; }
    s->r[15] = 689194u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a842a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689194u) != 8449u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = 689196u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8432(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689202u) != 63711u || agr_aot_load16(s, 689204u) != 14384u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 689204u + 2096u); if (rc) return rc; }
    s->r[15] = 689206u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8436(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689206u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 689208u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8438(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689208u) != 63711u || agr_aot_load16(s, 689210u) != 10284u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, 689212u + 2092u); if (rc) return rc; }
    s->r[15] = 689212u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8444(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689220u) != 63711u || agr_aot_load16(s, 689222u) != 14372u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 689224u + 2084u); if (rc) return rc; }
    s->r[15] = 689224u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8448(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689224u) != 9985u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 7, 1u);
    s->r[15] = 689226u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a844a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689226u) != 63711u || agr_aot_load16(s, 689228u) != 2084u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, 689228u + 2084u); if (rc) return rc; }
    s->r[15] = 689230u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a844e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689230u) != 8704u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 689232u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8452(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689234u) != 63711u || agr_aot_load16(s, 689236u) != 26656u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 6, 689236u + 2080u); if (rc) return rc; }
    s->r[15] = 689238u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8456(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689238u) != 63711u || agr_aot_load16(s, 689240u) != 51232u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 12, 689240u + 2080u); if (rc) return rc; }
    s->r[15] = 689242u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a845a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689242u) != 17937u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 2);
    s->r[15] = 689244u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8468(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689256u) != 17968u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 689258u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a846a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689258u) != 40705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 7, s->r[13] + 4u); if (rc) return rc; }
    s->r[15] = 689260u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a849a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689306u) != 63711u || agr_aot_load16(s, 689308u) != 14304u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 689308u + 2016u); if (rc) return rc; }
    s->r[15] = 689310u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a849e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689310u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 689312u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a84a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689312u) != 63711u || agr_aot_load16(s, 689314u) != 10204u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, 689316u + 2012u); if (rc) return rc; }
    s->r[15] = 689316u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a84aa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689322u) != 18001u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 10);
    s->r[15] = 689324u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a84b0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689328u) != 63711u || agr_aot_load16(s, 689330u) != 14288u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 689332u + 2000u); if (rc) return rc; }
    s->r[15] = 689332u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a84b4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689332u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 689334u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a84b6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689334u) != 63711u || agr_aot_load16(s, 689336u) != 6096u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, 689336u + 2000u); if (rc) return rc; }
    s->r[15] = 689338u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a84ba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689338u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 689340u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a84be(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689342u) != 63711u || agr_aot_load16(s, 689344u) != 26572u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 6, 689344u + 1996u); if (rc) return rc; }
    s->r[15] = 689346u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a84c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689348u) != 17946u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 3);
    s->r[15] = 689350u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a84d2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689362u) != 63711u || agr_aot_load16(s, 689364u) != 14268u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 689364u + 1980u); if (rc) return rc; }
    s->r[15] = 689366u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a84d6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689366u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 689368u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a84d8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689368u) != 63711u || agr_aot_load16(s, 689370u) != 6072u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, 689372u + 1976u); if (rc) return rc; }
    s->r[15] = 689372u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a84dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689372u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 689374u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a84e0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689376u) != 63711u || agr_aot_load16(s, 689378u) != 26548u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 6, 689380u + 1972u); if (rc) return rc; }
    s->r[15] = 689380u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a84e6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689382u) != 17946u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 3);
    s->r[15] = 689384u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a84f4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689396u) != 63711u || agr_aot_load16(s, 689398u) != 14244u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 689400u + 1956u); if (rc) return rc; }
    s->r[15] = 689400u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a84f8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689400u) != 8449u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = 689402u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a84fa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689402u) != 63711u || agr_aot_load16(s, 689404u) != 10148u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, 689404u + 1956u); if (rc) return rc; }
    s->r[15] = 689406u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a850c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689420u) != 63711u || agr_aot_load16(s, 689422u) != 10132u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, 689424u + 1940u); if (rc) return rc; }
    s->r[15] = 689424u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8510(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689424u) != 63711u || agr_aot_load16(s, 689426u) != 14228u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 689428u + 1940u); if (rc) return rc; }
    s->r[15] = 689428u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8518(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689432u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 689434u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8520(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689440u) != 63711u || agr_aot_load16(s, 689442u) != 14216u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 689444u + 1928u); if (rc) return rc; }
    s->r[15] = 689444u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8524(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689444u) != 9729u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 6, 1u);
    s->r[15] = 689446u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8526(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689446u) != 63711u || agr_aot_load16(s, 689448u) != 1928u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, 689448u + 1928u); if (rc) return rc; }
    s->r[15] = 689450u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a852a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689450u) != 9984u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 7, 0u);
    s->r[15] = 689452u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a852e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689454u) != 63711u || agr_aot_load16(s, 689456u) != 59268u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 14, 689456u + 1924u); if (rc) return rc; }
    s->r[15] = 689458u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8532(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689458u) != 63711u || agr_aot_load16(s, 689460u) != 34692u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 8, 689460u + 1924u); if (rc) return rc; }
    s->r[15] = 689462u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8536(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689462u) != 17977u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 7);
    s->r[15] = 689464u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a853e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689470u) != 17978u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 7);
    s->r[15] = 689472u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8548(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689480u) != 18032u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 14);
    s->r[15] = 689482u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a854a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689482u) != 40449u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 6, s->r[13] + 4u); if (rc) return rc; }
    s->r[15] = 689484u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a85a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689568u) != 63711u || agr_aot_load16(s, 689570u) != 14104u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 689572u + 1816u); if (rc) return rc; }
    s->r[15] = 689572u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a85a4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689572u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 689574u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a85a6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689574u) != 63711u || agr_aot_load16(s, 689576u) != 10008u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, 689576u + 1816u); if (rc) return rc; }
    s->r[15] = 689578u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a85b0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689584u) != 17993u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 9);
    s->r[15] = 689586u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a85b6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689590u) != 63711u || agr_aot_load16(s, 689592u) != 26380u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 6, 689592u + 1804u); if (rc) return rc; }
    s->r[15] = 689594u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a85be(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689598u) != 63711u || agr_aot_load16(s, 689600u) != 14088u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 689600u + 1800u); if (rc) return rc; }
    s->r[15] = 689602u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a85c2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689602u) != 9984u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 7, 0u);
    s->r[15] = 689604u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a85c6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689606u) != 63711u || agr_aot_load16(s, 689608u) != 59140u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 14, 689608u + 1796u); if (rc) return rc; }
    s->r[15] = 689610u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a85ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689610u) != 63711u || agr_aot_load16(s, 689612u) != 34564u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 8, 689612u + 1796u); if (rc) return rc; }
    s->r[15] = 689614u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a85ce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689614u) != 17977u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 7);
    s->r[15] = 689616u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a85d8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689624u) != 17978u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 7);
    s->r[15] = 689626u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a85de(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689630u) != 18032u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 14);
    s->r[15] = 689632u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8632(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689714u) != 63711u || agr_aot_load16(s, 689716u) != 13984u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 689716u + 1696u); if (rc) return rc; }
    s->r[15] = 689718u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8636(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689718u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 689720u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8638(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689720u) != 63711u || agr_aot_load16(s, 689722u) != 9884u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, 689724u + 1692u); if (rc) return rc; }
    s->r[15] = 689724u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8642(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689730u) != 17985u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 8);
    s->r[15] = 689732u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8648(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689736u) != 63711u || agr_aot_load16(s, 689738u) != 13968u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 689740u + 1680u); if (rc) return rc; }
    s->r[15] = 689740u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a864c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689740u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 689742u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a864e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689742u) != 63711u || agr_aot_load16(s, 689744u) != 5776u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, 689744u + 1680u); if (rc) return rc; }
    s->r[15] = 689746u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8652(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689746u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 689748u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8656(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689750u) != 63711u || agr_aot_load16(s, 689752u) != 26252u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 6, 689752u + 1676u); if (rc) return rc; }
    s->r[15] = 689754u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a865c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689756u) != 17946u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 3);
    s->r[15] = 689758u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a866a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689770u) != 63711u || agr_aot_load16(s, 689772u) != 13948u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 689772u + 1660u); if (rc) return rc; }
    s->r[15] = 689774u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a866e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689774u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 689776u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8670(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689776u) != 63711u || agr_aot_load16(s, 689778u) != 5752u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, 689780u + 1656u); if (rc) return rc; }
    s->r[15] = 689780u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8674(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689780u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 689782u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8678(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689784u) != 63711u || agr_aot_load16(s, 689786u) != 26228u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 6, 689788u + 1652u); if (rc) return rc; }
    s->r[15] = 689788u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a867e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689790u) != 17946u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 3);
    s->r[15] = 689792u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a868c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689804u) != 63711u || agr_aot_load16(s, 689806u) != 26212u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 6, 689808u + 1636u); if (rc) return rc; }
    s->r[15] = 689808u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8690(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689808u) != 8961u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 1u);
    s->r[15] = 689810u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8692(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689810u) != 63711u || agr_aot_load16(s, 689812u) != 58980u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 14, 689812u + 1636u); if (rc) return rc; }
    s->r[15] = 689814u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8696(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689814u) != 17946u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 3);
    s->r[15] = 689816u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a869a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689818u) != 63711u || agr_aot_load16(s, 689820u) != 1632u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, 689820u + 1632u); if (rc) return rc; }
    s->r[15] = 689822u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a869e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689822u) != 9984u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 7, 0u);
    s->r[15] = 689824u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a86a8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689832u) != 17969u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 6);
    s->r[15] = 689834u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8736(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689974u) != 63711u || agr_aot_load16(s, 689976u) != 13768u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 689976u + 1480u); if (rc) return rc; }
    s->r[15] = 689978u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a873a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689978u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 689980u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a873c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689980u) != 63711u || agr_aot_load16(s, 689982u) != 9668u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, 689984u + 1476u); if (rc) return rc; }
    s->r[15] = 689984u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8744(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689988u) != 17945u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 3);
    s->r[15] = 689990u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a874c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 689996u) != 63711u || agr_aot_load16(s, 689998u) != 13752u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 690000u + 1464u); if (rc) return rc; }
    s->r[15] = 690000u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8750(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690000u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 690002u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8752(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690002u) != 63711u || agr_aot_load16(s, 690004u) != 5560u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, 690004u + 1464u); if (rc) return rc; }
    s->r[15] = 690006u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8756(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690006u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 690008u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a875a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690010u) != 63711u || agr_aot_load16(s, 690012u) != 30132u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 7, 690012u + 1460u); if (rc) return rc; }
    s->r[15] = 690014u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8760(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690016u) != 17946u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 3);
    s->r[15] = 690018u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a876e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690030u) != 63711u || agr_aot_load16(s, 690032u) != 13732u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 690032u + 1444u); if (rc) return rc; }
    s->r[15] = 690034u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8772(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690034u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 690036u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8774(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690036u) != 63711u || agr_aot_load16(s, 690038u) != 5536u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, 690040u + 1440u); if (rc) return rc; }
    s->r[15] = 690040u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8778(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690040u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 690042u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a877c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690044u) != 63711u || agr_aot_load16(s, 690046u) != 30108u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 7, 690048u + 1436u); if (rc) return rc; }
    s->r[15] = 690048u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8782(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690050u) != 17946u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 3);
    s->r[15] = 690052u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8790(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690064u) != 63711u || agr_aot_load16(s, 690066u) != 1420u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, 690068u + 1420u); if (rc) return rc; }
    s->r[15] = 690068u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8794(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690068u) != 8449u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = 690070u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a879c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690076u) != 63711u || agr_aot_load16(s, 690078u) != 13700u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 690080u + 1412u); if (rc) return rc; }
    s->r[15] = 690080u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a87a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690080u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 690082u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a87a2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690082u) != 63711u || agr_aot_load16(s, 690084u) != 9604u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, 690084u + 1412u); if (rc) return rc; }
    s->r[15] = 690086u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a87ae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690094u) != 63711u || agr_aot_load16(s, 690096u) != 1404u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, 690096u + 1404u); if (rc) return rc; }
    s->r[15] = 690098u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a87b2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690098u) != 8449u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = 690100u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a87ba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690106u) != 63711u || agr_aot_load16(s, 690108u) != 13684u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 690108u + 1396u); if (rc) return rc; }
    s->r[15] = 690110u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a87be(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690110u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 690112u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a87c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690112u) != 63711u || agr_aot_load16(s, 690114u) != 9584u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, 690116u + 1392u); if (rc) return rc; }
    s->r[15] = 690116u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a87cc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690124u) != 63711u || agr_aot_load16(s, 690126u) != 1384u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, 690128u + 1384u); if (rc) return rc; }
    s->r[15] = 690128u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a87d0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690128u) != 8449u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = 690130u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a87d8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690136u) != 63711u || agr_aot_load16(s, 690138u) != 13664u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 690140u + 1376u); if (rc) return rc; }
    s->r[15] = 690140u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a87dc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690140u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 690142u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a87de(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690142u) != 63711u || agr_aot_load16(s, 690144u) != 9568u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, 690144u + 1376u); if (rc) return rc; }
    s->r[15] = 690146u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a87ea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690154u) != 63711u || agr_aot_load16(s, 690156u) != 13656u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 690156u + 1368u); if (rc) return rc; }
    s->r[15] = 690158u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a87ee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690158u) != 9729u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 6, 1u);
    s->r[15] = 690160u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a87f0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690160u) != 63711u || agr_aot_load16(s, 690162u) != 9556u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, 690164u + 1364u); if (rc) return rc; }
    s->r[15] = 690164u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a87f4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690164u) != 9984u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 7, 0u);
    s->r[15] = 690166u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a87f8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690168u) != 63711u || agr_aot_load16(s, 690170u) != 58704u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 14, 690172u + 1360u); if (rc) return rc; }
    s->r[15] = 690172u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a87fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690172u) != 63711u || agr_aot_load16(s, 690174u) != 46416u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 11, 690176u + 1360u); if (rc) return rc; }
    s->r[15] = 690176u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8800(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690176u) != 17977u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 7);
    s->r[15] = 690178u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a880c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690188u) != 18032u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 14);
    s->r[15] = 690190u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a883a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690234u) != 63711u || agr_aot_load16(s, 690236u) != 13592u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 690236u + 1304u); if (rc) return rc; }
    s->r[15] = 690238u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a883e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690238u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 690240u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8840(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690240u) != 63711u || agr_aot_load16(s, 690242u) != 9492u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, 690244u + 1300u); if (rc) return rc; }
    s->r[15] = 690244u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8848(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690248u) != 17945u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 3);
    s->r[15] = 690250u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8850(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690256u) != 63711u || agr_aot_load16(s, 690258u) != 13576u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 690260u + 1288u); if (rc) return rc; }
    s->r[15] = 690260u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8854(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690260u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 690262u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8856(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690262u) != 63711u || agr_aot_load16(s, 690264u) != 5384u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, 690264u + 1288u); if (rc) return rc; }
    s->r[15] = 690266u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a885a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690266u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 690268u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a885e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690270u) != 63711u || agr_aot_load16(s, 690272u) != 29956u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 7, 690272u + 1284u); if (rc) return rc; }
    s->r[15] = 690274u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8864(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690276u) != 17946u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 3);
    s->r[15] = 690278u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8872(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690290u) != 63711u || agr_aot_load16(s, 690292u) != 13556u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 690292u + 1268u); if (rc) return rc; }
    s->r[15] = 690294u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8876(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690294u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 690296u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8878(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690296u) != 63711u || agr_aot_load16(s, 690298u) != 5360u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, 690300u + 1264u); if (rc) return rc; }
    s->r[15] = 690300u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a887c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690300u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 690302u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8880(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690304u) != 63711u || agr_aot_load16(s, 690306u) != 29932u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 7, 690308u + 1260u); if (rc) return rc; }
    s->r[15] = 690308u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8886(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690310u) != 17946u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 3);
    s->r[15] = 690312u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8894(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690324u) != 63711u || agr_aot_load16(s, 690326u) != 13532u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 690328u + 1244u); if (rc) return rc; }
    s->r[15] = 690328u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8898(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690328u) != 8449u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = 690330u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a889a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690330u) != 63711u || agr_aot_load16(s, 690332u) != 9436u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, 690332u + 1244u); if (rc) return rc; }
    s->r[15] = 690334u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a88ac(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690348u) != 63711u || agr_aot_load16(s, 690350u) != 9420u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, 690352u + 1228u); if (rc) return rc; }
    s->r[15] = 690352u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a88b0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690352u) != 63711u || agr_aot_load16(s, 690354u) != 13516u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 690356u + 1228u); if (rc) return rc; }
    s->r[15] = 690356u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a88b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690360u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 690362u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a88c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690368u) != 63711u || agr_aot_load16(s, 690370u) != 29888u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 7, 690372u + 1216u); if (rc) return rc; }
    s->r[15] = 690372u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a88c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690372u) != 8193u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = 690374u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a88c6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690374u) != 63711u || agr_aot_load16(s, 690376u) != 9408u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, 690376u + 1216u); if (rc) return rc; }
    s->r[15] = 690378u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a88ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690378u) != 8960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 690380u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a88ce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690382u) != 63711u || agr_aot_load16(s, 690384u) != 58556u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 14, 690384u + 1212u); if (rc) return rc; }
    s->r[15] = 690386u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a88d2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690386u) != 63711u || agr_aot_load16(s, 690388u) != 50364u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 12, 690388u + 1212u); if (rc) return rc; }
    s->r[15] = 690390u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a88d6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690390u) != 17945u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 3);
    s->r[15] = 690392u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a88e2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690402u) != 18032u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 14);
    s->r[15] = 690404u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a88ea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690410u) != 17946u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 3);
    s->r[15] = 690412u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8938(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690488u) != 63711u || agr_aot_load16(s, 690490u) != 13400u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 690492u + 1112u); if (rc) return rc; }
    s->r[15] = 690492u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a893c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690492u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 690494u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a893e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690494u) != 63711u || agr_aot_load16(s, 690496u) != 9304u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, 690496u + 1112u); if (rc) return rc; }
    s->r[15] = 690498u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8946(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690502u) != 17945u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 3);
    s->r[15] = 690504u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a894e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690510u) != 63711u || agr_aot_load16(s, 690512u) != 13388u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, 690512u + 1100u); if (rc) return rc; }
    s->r[15] = 690514u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8952(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690514u) != 9729u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 6, 1u);
    s->r[15] = 690516u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8954(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690516u) != 63711u || agr_aot_load16(s, 690518u) != 1096u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, 690520u + 1096u); if (rc) return rc; }
    s->r[15] = 690520u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8958(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690520u) != 8704u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 690522u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a895c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690524u) != 63711u || agr_aot_load16(s, 690526u) != 58436u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 14, 690528u + 1092u); if (rc) return rc; }
    s->r[15] = 690528u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8960(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690528u) != 63711u || agr_aot_load16(s, 690530u) != 29764u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 7, 690532u + 1092u); if (rc) return rc; }
    s->r[15] = 690532u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8964(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690532u) != 17937u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 2);
    s->r[15] = 690534u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8976(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690550u) != 18032u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 14);
    s->r[15] = 690552u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a89c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690628u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 690630u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a89ce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690638u) != 18009u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 11);
    s->r[15] = 690640u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a89d6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690646u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 690648u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a89da(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690650u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 690652u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a89e2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690658u) != 17946u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 3);
    s->r[15] = 690660u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a89f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690674u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 690676u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a89f6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690678u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 690680u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a89fe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690686u) != 17946u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 3);
    s->r[15] = 690688u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8a0e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690702u) != 8961u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 1u);
    s->r[15] = 690704u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8a10(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690704u) != 63711u || agr_aot_load16(s, 690706u) != 58300u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 14, 690708u + 956u); if (rc) return rc; }
    s->r[15] = 690708u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8a14(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690708u) != 17946u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 3);
    s->r[15] = 690710u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8a1a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690714u) != 9728u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 6, 0u);
    s->r[15] = 690716u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8a24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690724u) != 17977u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 7);
    s->r[15] = 690726u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8ab4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690868u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 690870u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8abc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690876u) != 17977u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 7);
    s->r[15] = 690878u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8ac4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690884u) != 8449u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = 690886u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8ac8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690888u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 690890u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8acc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690892u) != 63711u || agr_aot_load16(s, 690894u) != 58136u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 14, 690896u + 792u); if (rc) return rc; }
    s->r[15] = 690896u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8ad4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690900u) != 17946u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 3);
    s->r[15] = 690902u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8ae4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690916u) != 8449u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = 690918u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8ae8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690920u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 690922u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8aec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690924u) != 63711u || agr_aot_load16(s, 690926u) != 58116u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 14, 690928u + 772u); if (rc) return rc; }
    s->r[15] = 690928u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8af4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690932u) != 17946u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 3);
    s->r[15] = 690934u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8b04(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690948u) != 8449u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = 690950u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8b0e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690958u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 690960u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8b1a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690970u) != 18000u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 10);
    s->r[15] = 690972u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8b1c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690972u) != 26853u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 5, s->r[4] + 12u); if (rc) return rc; }
    s->r[15] = 690974u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8b2a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690986u) != 17992u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 9);
    s->r[15] = 690988u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8b2c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 690988u) != 26853u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 5, s->r[4] + 12u); if (rc) return rc; }
    s->r[15] = 690990u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8b3a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 691002u) != 17984u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 8);
    s->r[15] = 691004u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8b3c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 691004u) != 26853u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 5, s->r[4] + 12u); if (rc) return rc; }
    s->r[15] = 691006u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8b4a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 691018u) != 38915u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 12u); if (rc) return rc; }
    s->r[15] = 691020u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8b4c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 691020u) != 26853u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 5, s->r[4] + 12u); if (rc) return rc; }
    s->r[15] = 691022u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8b5a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 691034u) != 38914u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 8u); if (rc) return rc; }
    s->r[15] = 691036u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8b5c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 691036u) != 26853u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 5, s->r[4] + 12u); if (rc) return rc; }
    s->r[15] = 691038u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8b6a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 691050u) != 38913u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 4u); if (rc) return rc; }
    s->r[15] = 691052u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8b6c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 691052u) != 26853u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 5, s->r[4] + 12u); if (rc) return rc; }
    s->r[15] = 691054u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8b7a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 691066u) != 18008u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 11);
    s->r[15] = 691068u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8b7c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 691068u) != 26853u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 5, s->r[4] + 12u); if (rc) return rc; }
    s->r[15] = 691070u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8b8a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 691082u) != 17976u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 7);
    s->r[15] = 691084u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8b8c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 691084u) != 26853u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 5, s->r[4] + 12u); if (rc) return rc; }
    s->r[15] = 691086u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8b9a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 691098u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 691100u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8b9e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 691102u) != 59581u || agr_aot_load16(s, 691104u) != 36848u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    if ((rc = agr_aot_ldmia_sp(s, 36848u))) return rc;
}

static int aot_000a8e46(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 691782u) != 8450u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 1, 2u);
    s->r[15] = 691784u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8e4c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 691788u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 691790u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8e58(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 691800u) != 26642u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[2] + 0u); if (rc) return rc; }
    s->r[15] = 691802u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8e5c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 691804u) != 26651u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 691806u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8e78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 691832u) != 26624u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 691834u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8e7e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 691838u) != 63390u || agr_aot_load16(s, 691840u) != 59662u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, 290972u, 691842u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_000a8e84(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 691844u) != 26660u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 4, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 691846u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8e86(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 691846u) != 26659u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 691848u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8e88(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 691848u) != 45315u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[3] ? 691852u : 691850u; return AGR_AOT_BOUNDARY;
}

static int aot_000a8eba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 691898u) != 8960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 691900u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8ebe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 691902u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 691904u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8eca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 691914u) != 26669u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 5, s->r[5] + 0u); if (rc) return rc; }
    s->r[15] = 691916u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8ece(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 691918u) != 26651u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 691920u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8ed0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 691920u) != 26666u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[5] + 0u); if (rc) return rc; }
    s->r[15] = 691922u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8ed4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 691924u) != 26651u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 691926u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000a8f24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 692004u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 692006u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aa52a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 697642u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 697644u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aa530(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 697648u) != 8449u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = 697650u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aa53c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 697660u) != 26669u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 5, s->r[5] + 0u); if (rc) return rc; }
    s->r[15] = 697662u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aa544(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 697668u) != 8960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 697670u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aa546(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 697670u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 697672u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aa54e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 697678u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 697680u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aac5e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 699486u) != 8704u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 699488u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aafd2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 700370u) != 63388u || agr_aot_load16(s, 700372u) != 59492u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, 290972u, 700374u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_000aafda(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 700378u) != 26648u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 700380u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ab0d6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 700630u) != 17934u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 6, 1);
    s->r[15] = 700632u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ab0d8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 700632u) != 26635u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 700634u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ab0de(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 700638u) != 17925u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 700640u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ab0f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 700658u) != 26668u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 4, s->r[5] + 0u); if (rc) return rc; }
    s->r[15] = 700660u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ab10e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 700686u) != 26675u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[6] + 0u); if (rc) return rc; }
    s->r[15] = 700688u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ab110(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 700688u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 700690u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ab132(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 700722u) != 17925u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 700724u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ab134(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 700724u) != 26628u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 4, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 700726u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ab150(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 700752u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 700754u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ab360(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 701280u) != 26627u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 701282u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ab364(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 701284u) != 45347u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[3] ? 701296u : 701286u; return AGR_AOT_BOUNDARY;
}

static int aot_000ab366(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 701286u) != 17944u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 3);
    s->r[15] = 701288u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ab392(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 701330u) != 17944u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 3);
    s->r[15] = 701332u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ab39c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 701340u) != 59693u || agr_aot_load16(s, 701342u) != 18416u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    if (agr_aot_stmdb_sp(s, 18416u)) return AGR_AOT_FAULT;
    s->r[15] = 701344u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ab3a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 701344u) != 17925u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 701346u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ab3a2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 701346u) != 18064u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 8, 2);
    s->r[15] = 701348u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ab3aa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 701354u) != 17928u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 1);
    s->r[15] = 701356u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ab3b0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 701360u) != 26795u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 8u); if (rc) return rc; }
    s->r[15] = 701362u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ab3b6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 701366u) != 17926u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 6, 0);
    s->r[15] = 701368u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ab488(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 701576u) != 26732u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 4, s->r[5] + 4u); if (rc) return rc; }
    s->r[15] = 701578u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ab48e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 701582u) != 45424u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[0] ? 701614u : 701584u; return AGR_AOT_BOUNDARY;
}

static int aot_000ab4ae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 701614u) != 26794u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[5] + 8u); if (rc) return rc; }
    s->r[15] = 701616u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ab4b4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 701620u) != 45834u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[2] ? 701690u : 701622u; return AGR_AOT_BOUNDARY;
}

static int aot_000ab4b6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 701622u) != 9216u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 4, 0u);
    s->r[15] = 701624u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ab4b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 701624u) != 17959u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 7, 4);
    s->r[15] = 701626u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ab4ba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 701626u) != 57349u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = 701640u; return AGR_AOT_BOUNDARY;
}

static int aot_000ab4c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 701640u) != 26859u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 12u); if (rc) return rc; }
    s->r[15] = 701642u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ab4fe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 701694u) != 59581u || agr_aot_load16(s, 701696u) != 34800u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    if ((rc = agr_aot_ldmia_sp(s, 34800u))) return rc;
}

static int aot_000abc6a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 703594u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 703596u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000abc6e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 703598u) != 8961u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 1u);
    s->r[15] = 703600u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000abc74(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 703604u) != 26669u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 5, s->r[5] + 0u); if (rc) return rc; }
    s->r[15] = 703606u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000abc78(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 703608u) != 8704u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 703610u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000abc94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 703636u) != 8448u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = 703638u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000abc96(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 703638u) != 17933u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 5, 1);
    s->r[15] = 703640u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000abca0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 703648u) != 63386u || agr_aot_load16(s, 703650u) != 61192u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, 289460u, 703652u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_000abca6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 703654u) != 17961u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 1, 5);
    s->r[15] = 703656u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000abcb0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 703664u) != 63386u || agr_aot_load16(s, 703666u) != 61184u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, 289460u, 703668u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_000abcb8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 703672u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 703674u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000abcc0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 703680u) != 26651u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 703682u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000abcc2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 703682u) != 26649u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 703684u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000abcc6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 703686u) != 59364u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = 703634u; return AGR_AOT_BOUNDARY;
}

static int aot_000ad2bc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 709308u) != 8705u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 1u);
    s->r[15] = 709310u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ad2c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 709316u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 709318u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ad2ca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 709322u) != 8448u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = 709324u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ad2ce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 709326u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 709328u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ad2d4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 709332u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 709334u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ad73e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 710462u) != 8449u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 1, 1u);
    s->r[15] = 710464u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ad744(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 710468u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 710470u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ad74e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 710478u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 710480u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ad9a8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 711080u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 711082u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ad9aa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 711082u) != 17944u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 3);
    s->r[15] = 711084u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ad9ae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 711086u) != 26624u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 711088u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ad9b4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 711092u) != 26659u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 711094u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ad9b6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 711094u) != 26777u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[3] + 8u); if (rc) return rc; }
    s->r[15] = 711096u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ad9b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 711096u) != 26715u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) return rc; }
    s->r[15] = 711098u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ad9c2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 711106u) != 45392u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[0] ? 711130u : 711108u; return AGR_AOT_BOUNDARY;
}

static int aot_000ad9c6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 711110u) != 8960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 711112u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ad9cc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 711116u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 711118u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ad9d0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 711120u) != 26642u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[2] + 0u); if (rc) return rc; }
    s->r[15] = 711122u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ad9d6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 711126u) != 45328u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[0] ? 711134u : 711128u; return AGR_AOT_BOUNDARY;
}

static int aot_000ae196(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 713110u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 713112u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ae1a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 713120u) != 26659u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 713122u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ae1a2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 713122u) != 26777u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[3] + 8u); if (rc) return rc; }
    s->r[15] = 713124u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ae1a4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 713124u) != 26715u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) return rc; }
    s->r[15] = 713126u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ae1ae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 713134u) != 45384u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[0] ? 713156u : 713136u; return AGR_AOT_BOUNDARY;
}

static int aot_000ae1b2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 713138u) != 8960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 713140u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ae1b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 713144u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 713146u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ae1c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 713152u) != 45328u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[0] ? 713160u : 713154u; return AGR_AOT_BOUNDARY;
}

static int aot_000ae1da(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 713178u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 713180u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ae1e4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 713188u) != 26659u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 713190u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ae1e6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 713190u) != 26777u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[3] + 8u); if (rc) return rc; }
    s->r[15] = 713192u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ae1e8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 713192u) != 26715u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) return rc; }
    s->r[15] = 713194u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ae1f2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 713202u) != 45384u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[0] ? 713224u : 713204u; return AGR_AOT_BOUNDARY;
}

static int aot_000ae1f6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 713206u) != 8960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 713208u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ae1fc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 713212u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 713214u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000ae204(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 713220u) != 45328u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[0] ? 713228u : 713222u; return AGR_AOT_BOUNDARY;
}

static int aot_000aecc4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 715972u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 715974u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aecc6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 715974u) != 17944u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 3);
    s->r[15] = 715976u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aecca(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 715978u) != 26624u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 715980u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aecd0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 715984u) != 26659u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 715986u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aecd2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 715986u) != 26777u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[3] + 8u); if (rc) return rc; }
    s->r[15] = 715988u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aecd4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 715988u) != 26715u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) return rc; }
    s->r[15] = 715990u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aecde(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 715998u) != 45416u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[0] ? 716028u : 716000u; return AGR_AOT_BOUNDARY;
}

static int aot_000aece2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 716002u) != 8960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 716004u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aece8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 716008u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 716010u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aecec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 716012u) != 26642u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[2] + 0u); if (rc) return rc; }
    s->r[15] = 716014u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aecf6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 716022u) != 8193u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = 716024u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aede2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 716258u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 716260u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aedec(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 716268u) != 26659u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 716270u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aedee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 716270u) != 26777u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[3] + 8u); if (rc) return rc; }
    s->r[15] = 716272u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aedf0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 716272u) != 26715u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) return rc; }
    s->r[15] = 716274u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aedfa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 716282u) != 45408u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[0] ? 716310u : 716284u; return AGR_AOT_BOUNDARY;
}

static int aot_000aedfe(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 716286u) != 8960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 716288u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aee04(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 716292u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 716294u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aee10(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 716304u) != 8193u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = 716306u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aee26(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 716326u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 716328u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aee30(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 716336u) != 26659u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) return rc; }
    s->r[15] = 716338u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aee32(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 716338u) != 26777u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[3] + 8u); if (rc) return rc; }
    s->r[15] = 716340u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aee34(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 716340u) != 26715u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) return rc; }
    s->r[15] = 716342u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aee3e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 716350u) != 45408u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[0] ? 716378u : 716352u; return AGR_AOT_BOUNDARY;
}

static int aot_000aee42(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 716354u) != 8960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 716356u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aee48(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 716360u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 716362u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000aee54(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 716372u) != 8193u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = 716374u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c0678(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 788088u) != 63055u || agr_aot_load16(s, 788090u) != 29692u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movw(s, 3, 65532u);
    s->r[15] = 788092u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c0684(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 788100u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 788102u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c0692(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 788114u) != 17940u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 2);
    s->r[15] = 788116u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c069e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 788126u) != 8192u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = 788128u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c06a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 788128u) != 8193u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 0, 1u);
    s->r[15] = 788130u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c06a6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 788134u) != 8192u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = 788136u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c06a8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 788136u) != 45368u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[0] ? 788154u : 788138u; return AGR_AOT_BOUNDARY;
}

static int aot_000c06c2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 788162u) != 8704u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 788164u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c168a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 792202u) != 17931u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = 792204u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c168e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 792206u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 792208u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c1692(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 792210u) != 45880u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[0] ? 792292u : 792212u; return AGR_AOT_BOUNDARY;
}

static int aot_000c1696(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 792214u) != 8448u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = 792216u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c1698(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 792216u) != 17968u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 792218u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c16a0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 792224u) != 17925u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 792226u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c16ae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 792238u) != 17944u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 3);
    s->r[15] = 792240u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c16b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 792248u) != 8704u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 792250u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c194e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 792910u) != 17932u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 1);
    s->r[15] = 792912u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c1950(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 792912u) != 17925u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 792914u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c1952(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 792914u) != 17942u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 6, 2);
    s->r[15] = 792916u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c1958(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 792920u) != 45340u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[4] ? 792930u : 792922u; return AGR_AOT_BOUNDARY;
}

static int aot_000c195a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 792922u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 792924u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c195c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 792924u) != 63365u || agr_aot_load16(s, 792926u) != 59658u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, 289652u, 792928u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_000c1962(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 792930u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 792932u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c1964(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 792932u) != 17970u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 6);
    s->r[15] = 792934u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c1970(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 792944u) != 17960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 5);
    s->r[15] = 792946u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2176(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 794998u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 795000u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2178(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795000u) != 26757u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 5, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = 795002u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2180(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795008u) != 9006u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 46u);
    s->r[15] = 795010u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2186(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795014u) != 8704u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 795016u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2188(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795016u) != 26790u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 6, s->r[4] + 8u); if (rc) return rc; }
    s->r[15] = 795018u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c218c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795020u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 795022u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2190(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795024u) != 17939u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 3, 2);
    s->r[15] = 795026u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2192(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795026u) != 26632u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 795028u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2194(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795028u) != 8492u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 1, 44u);
    s->r[15] = 795030u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c21a2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795042u) != 26786u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[4] + 8u); if (rc) return rc; }
    s->r[15] = 795044u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c21b4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795060u) != 8960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 795062u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c21b8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795064u) != 26642u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[2] + 0u); if (rc) return rc; }
    s->r[15] = 795066u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c21ba(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795066u) != 26640u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, s->r[2] + 0u); if (rc) return rc; }
    s->r[15] = 795068u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c21bc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795068u) != 26786u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[4] + 8u); if (rc) return rc; }
    s->r[15] = 795070u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c21cc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795084u) != 26787u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 8u); if (rc) return rc; }
    s->r[15] = 795086u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c21ce(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795086u) != 8709u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 5u);
    s->r[15] = 795088u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c21d2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795090u) != 9220u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 4, 4u);
    s->r[15] = 795092u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2232(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795186u) != 17925u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 795188u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2234(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795188u) != 26756u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 4, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = 795190u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c223c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795196u) != 8448u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = 795198u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2240(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795200u) != 17954u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 2, 4);
    s->r[15] = 795202u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2244(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795204u) != 26624u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 795206u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2246(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795206u) != 17931u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = 795208u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c224c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795212u) != 26624u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) return rc; }
    s->r[15] = 795214u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c224e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795214u) != 9774u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 6, 46u);
    s->r[15] = 795216u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2250(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795216u) != 9516u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 5, 44u);
    s->r[15] = 795218u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c226e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795246u) != 8960u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 0u);
    s->r[15] = 795248u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2272(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795250u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 795252u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2274(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795252u) != 26632u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 795254u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2284(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795268u) != 8196u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 0, 4u);
    s->r[15] = 795270u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2288(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795272u) != 8965u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 5u);
    s->r[15] = 795274u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c244a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795722u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 795724u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c244c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795724u) != 26757u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 5, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = 795726u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c244e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795726u) != 45877u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[5] ? 795806u : 795728u; return AGR_AOT_BOUNDARY;
}

static int aot_000c2452(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795730u) != 8750u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 46u);
    s->r[15] = 795732u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2456(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795734u) != 9772u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 6, 44u);
    s->r[15] = 795736u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2458(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795736u) != 26786u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[4] + 8u); if (rc) return rc; }
    s->r[15] = 795738u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c245c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795740u) != 26651u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 795742u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2460(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795744u) != 8448u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = 795746u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2462(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795746u) != 26648u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 795748u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2464(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795748u) != 17931u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = 795750u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c246a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795754u) != 26669u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 5, s->r[5] + 0u); if (rc) return rc; }
    s->r[15] = 795756u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c246c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795756u) != 26786u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[4] + 8u); if (rc) return rc; }
    s->r[15] = 795758u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c246e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795758u) != 26669u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 5, s->r[5] + 0u); if (rc) return rc; }
    s->r[15] = 795760u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2474(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795764u) != 26791u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 7, s->r[4] + 8u); if (rc) return rc; }
    s->r[15] = 795766u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c248c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795788u) != 26786u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[4] + 8u); if (rc) return rc; }
    s->r[15] = 795790u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2506(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795910u) != 17924u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 4, 0);
    s->r[15] = 795912u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2508(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795912u) != 26757u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 5, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = 795914u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c250a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795914u) != 45877u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[5] ? 795994u : 795916u; return AGR_AOT_BOUNDARY;
}

static int aot_000c250e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795918u) != 8750u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 46u);
    s->r[15] = 795920u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2512(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795922u) != 9772u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 6, 44u);
    s->r[15] = 795924u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2514(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795924u) != 26786u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[4] + 8u); if (rc) return rc; }
    s->r[15] = 795926u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2518(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795928u) != 26651u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 795930u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c251c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795932u) != 8448u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 1, 0u);
    s->r[15] = 795934u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c251e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795934u) != 26648u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 795936u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2520(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795936u) != 17931u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 3, 1);
    s->r[15] = 795938u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2526(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795942u) != 26669u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 5, s->r[5] + 0u); if (rc) return rc; }
    s->r[15] = 795944u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2528(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795944u) != 26786u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[4] + 8u); if (rc) return rc; }
    s->r[15] = 795946u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c252a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795946u) != 26669u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 5, s->r[5] + 0u); if (rc) return rc; }
    s->r[15] = 795948u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2530(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795952u) != 26791u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 7, s->r[4] + 8u); if (rc) return rc; }
    s->r[15] = 795954u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2548(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 795976u) != 26786u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[4] + 8u); if (rc) return rc; }
    s->r[15] = 795978u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c25c0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 796096u) != 59693u || agr_aot_load16(s, 796098u) != 16880u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    if (agr_aot_stmdb_sp(s, 16880u)) return AGR_AOT_FAULT;
    s->r[15] = 796100u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c25c4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 796100u) != 17925u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 796102u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c25c6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 796102u) != 26756u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 4, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = 796104u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c25c8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 796104u) != 45916u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[4] ? 796194u : 796106u; return AGR_AOT_BOUNDARY;
}

static int aot_000c25cc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 796108u) != 8704u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 796110u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c25d6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 796118u) != 26651u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 796120u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c25de(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 796126u) != 26648u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 796128u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c25e2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 796130u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 796132u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c25ea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 796138u) != 17939u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 3, 2);
    s->r[15] = 796140u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c25f0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 796144u) != 26799u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 7, s->r[5] + 8u); if (rc) return rc; }
    s->r[15] = 796146u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c260c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 796172u) != 26636u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 4, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 796174u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c260e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 796174u) != 26794u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[5] + 8u); if (rc) return rc; }
    s->r[15] = 796176u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c261e(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 796190u) != 59581u || agr_aot_load16(s, 796192u) != 33264u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) return rc;
}

static int aot_000c268c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 796300u) != 59693u || agr_aot_load16(s, 796302u) != 16880u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    if (agr_aot_stmdb_sp(s, 16880u)) return AGR_AOT_FAULT;
    s->r[15] = 796304u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2690(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 796304u) != 17925u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 5, 0);
    s->r[15] = 796306u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2692(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 796306u) != 26756u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 4, s->r[0] + 8u); if (rc) return rc; }
    s->r[15] = 796308u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2694(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 796308u) != 45916u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = !s->r[4] ? 796398u : 796310u; return AGR_AOT_BOUNDARY;
}

static int aot_000c2698(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 796312u) != 8704u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 2, 0u);
    s->r[15] = 796314u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c26a2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 796322u) != 26651u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 796324u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c26aa(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 796330u) != 26648u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 0, s->r[3] + 0u); if (rc) return rc; }
    s->r[15] = 796332u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c26ae(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 796334u) != 26633u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 1, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 796336u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c26b6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 796342u) != 17939u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 3, 2);
    s->r[15] = 796344u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c26bc(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 796348u) != 26799u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 7, s->r[5] + 8u); if (rc) return rc; }
    s->r[15] = 796350u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c26d8(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 796376u) != 26636u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 4, s->r[1] + 0u); if (rc) return rc; }
    s->r[15] = 796378u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c26da(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 796378u) != 26794u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { int rc = agr_aot_ldr(s, 2, s->r[5] + 8u); if (rc) return rc; }
    s->r[15] = 796380u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c26ea(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 796394u) != 59581u || agr_aot_load16(s, 796396u) != 33264u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) return rc;
}

static int aot_000c294a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 797002u) != 8192u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 0, 0u);
    s->r[15] = 797004u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2be2(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 797666u) != 17926u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 6, 0);
    s->r[15] = 797668u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2be4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 797668u) != 9216u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 4, 0u);
    s->r[15] = 797670u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2be6(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 797670u) != 57346u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = 797678u; return AGR_AOT_BOUNDARY;
}

static int aot_000c2bee(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 797678u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 797680u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2bf0(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 797680u) != 63364u || agr_aot_load16(s, 797682u) != 60186u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, 291368u, 797684u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_000c2c04(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 797700u) != 9216u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 4, 0u);
    s->r[15] = 797702u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2c06(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 797702u) != 17952u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 4);
    s->r[15] = 797704u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2c0a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 797706u) != 63364u || agr_aot_load16(s, 797708u) != 60180u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_branch_reg(s, 291380u, 797710u, 1); return AGR_AOT_BOUNDARY;
}

static int aot_000c2c18(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 797720u) != 17973u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 5, 6);
    s->r[15] = 797722u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2c1a(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 797722u) != 9216u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 4, 0u);
    s->r[15] = 797724u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2c1c(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 797724u) != 9985u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 7, 1u);
    s->r[15] = 797726u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2c24(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 797732u) != 17968u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_mov_reg(s, 0, 6);
    s->r[15] = 797734u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2c40(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 797760u) != 8961u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    agr_aot_movs_imm(s, 3, 1u);
    s->r[15] = 797762u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000c2c44(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if (!(*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load16(s, 797764u) != 59356u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    s->r[15] = 797696u; return AGR_AOT_BOUNDARY;
}

static int aot_000caeb4(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 831156u) != 3852451840u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { uint32_t addr = (831164u) + 0u; if ((rc = agr_aot_ldr(s, 12, addr))) return rc; }
    s->r[15] = 831160u;
    return AGR_AOT_BOUNDARY;
}

static int aot_000caf94(AgrAotRegs *s) {
    int rc = 0;
    (void)rc;
    if ((*s->cpsr & 0x20u)) return AGR_AOT_MISS;
    if (agr_aot_load32(s, 831380u) != 3852451840u) return AGR_AOT_MISS;
    agr_aot_count_instruction();
    { uint32_t addr = (831388u) + 0u; if ((rc = agr_aot_ldr(s, 12, addr))) return rc; }
    s->r[15] = 831384u;
    return AGR_AOT_BOUNDARY;
}

const AgrAotEntry agr_aot_blocks[] = {
    {289412u, aot_00046a84},
    {289416u, aot_00046a88},
    {289420u, aot_00046a8c},
    {289460u, aot_00046ab4},
    {289464u, aot_00046ab8},
    {289468u, aot_00046abc},
    {289592u, aot_00046b38},
    {289596u, aot_00046b3c},
    {289600u, aot_00046b40},
    {289652u, aot_00046b74},
    {289656u, aot_00046b78},
    {289660u, aot_00046b7c},
    {290408u, aot_00046e68},
    {290412u, aot_00046e6c},
    {290416u, aot_00046e70},
    {290852u, aot_00047024},
    {290856u, aot_00047028},
    {290860u, aot_0004702c},
    {290972u, aot_0004709c},
    {290976u, aot_000470a0},
    {290980u, aot_000470a4},
    {291320u, aot_000471f8},
    {291324u, aot_000471fc},
    {291328u, aot_00047200},
    {291368u, aot_00047228},
    {291372u, aot_0004722c},
    {291376u, aot_00047230},
    {291380u, aot_00047234},
    {291384u, aot_00047238},
    {291388u, aot_0004723c},
    {292830u, aot_000477de},
    {292838u, aot_000477e6},
    {292840u, aot_000477e8},
    {292844u, aot_000477ec},
    {292854u, aot_000477f6},
    {292864u, aot_00047800},
    {292866u, aot_00047802},
    {292870u, aot_00047806},
    {292914u, aot_00047832},
    {292922u, aot_0004783a},
    {292924u, aot_0004783c},
    {292928u, aot_00047840},
    {292938u, aot_0004784a},
    {292948u, aot_00047854},
    {292950u, aot_00047856},
    {292954u, aot_0004785a},
    {292998u, aot_00047886},
    {293006u, aot_0004788e},
    {293008u, aot_00047890},
    {293012u, aot_00047894},
    {293022u, aot_0004789e},
    {293032u, aot_000478a8},
    {293034u, aot_000478aa},
    {293038u, aot_000478ae},
    {293082u, aot_000478da},
    {293090u, aot_000478e2},
    {293092u, aot_000478e4},
    {293096u, aot_000478e8},
    {293106u, aot_000478f2},
    {293116u, aot_000478fc},
    {293118u, aot_000478fe},
    {293122u, aot_00047902},
    {293166u, aot_0004792e},
    {293174u, aot_00047936},
    {293176u, aot_00047938},
    {293180u, aot_0004793c},
    {293190u, aot_00047946},
    {293200u, aot_00047950},
    {293202u, aot_00047952},
    {293206u, aot_00047956},
    {293250u, aot_00047982},
    {293258u, aot_0004798a},
    {293260u, aot_0004798c},
    {293264u, aot_00047990},
    {293274u, aot_0004799a},
    {293284u, aot_000479a4},
    {293286u, aot_000479a6},
    {293290u, aot_000479aa},
    {293334u, aot_000479d6},
    {293342u, aot_000479de},
    {293344u, aot_000479e0},
    {293348u, aot_000479e4},
    {293358u, aot_000479ee},
    {293368u, aot_000479f8},
    {293370u, aot_000479fa},
    {293374u, aot_000479fe},
    {293418u, aot_00047a2a},
    {293426u, aot_00047a32},
    {293428u, aot_00047a34},
    {293432u, aot_00047a38},
    {293442u, aot_00047a42},
    {293452u, aot_00047a4c},
    {293454u, aot_00047a4e},
    {293458u, aot_00047a52},
    {293502u, aot_00047a7e},
    {293510u, aot_00047a86},
    {293512u, aot_00047a88},
    {293516u, aot_00047a8c},
    {293526u, aot_00047a96},
    {293536u, aot_00047aa0},
    {293538u, aot_00047aa2},
    {293542u, aot_00047aa6},
    {293586u, aot_00047ad2},
    {293594u, aot_00047ada},
    {293596u, aot_00047adc},
    {293600u, aot_00047ae0},
    {293610u, aot_00047aea},
    {293620u, aot_00047af4},
    {293622u, aot_00047af6},
    {293626u, aot_00047afa},
    {293670u, aot_00047b26},
    {293678u, aot_00047b2e},
    {293680u, aot_00047b30},
    {293684u, aot_00047b34},
    {293694u, aot_00047b3e},
    {293704u, aot_00047b48},
    {293706u, aot_00047b4a},
    {293710u, aot_00047b4e},
    {293754u, aot_00047b7a},
    {293762u, aot_00047b82},
    {293764u, aot_00047b84},
    {293768u, aot_00047b88},
    {293778u, aot_00047b92},
    {293788u, aot_00047b9c},
    {293790u, aot_00047b9e},
    {293794u, aot_00047ba2},
    {293838u, aot_00047bce},
    {293846u, aot_00047bd6},
    {293848u, aot_00047bd8},
    {293852u, aot_00047bdc},
    {293862u, aot_00047be6},
    {293872u, aot_00047bf0},
    {293874u, aot_00047bf2},
    {293878u, aot_00047bf6},
    {293922u, aot_00047c22},
    {293930u, aot_00047c2a},
    {293932u, aot_00047c2c},
    {293936u, aot_00047c30},
    {293946u, aot_00047c3a},
    {293956u, aot_00047c44},
    {293958u, aot_00047c46},
    {293962u, aot_00047c4a},
    {294006u, aot_00047c76},
    {294014u, aot_00047c7e},
    {294016u, aot_00047c80},
    {294020u, aot_00047c84},
    {294030u, aot_00047c8e},
    {294040u, aot_00047c98},
    {294042u, aot_00047c9a},
    {294046u, aot_00047c9e},
    {294090u, aot_00047cca},
    {294098u, aot_00047cd2},
    {294100u, aot_00047cd4},
    {294104u, aot_00047cd8},
    {294114u, aot_00047ce2},
    {294124u, aot_00047cec},
    {294126u, aot_00047cee},
    {294130u, aot_00047cf2},
    {294174u, aot_00047d1e},
    {294182u, aot_00047d26},
    {294184u, aot_00047d28},
    {294188u, aot_00047d2c},
    {294198u, aot_00047d36},
    {294208u, aot_00047d40},
    {294210u, aot_00047d42},
    {294214u, aot_00047d46},
    {294258u, aot_00047d72},
    {294266u, aot_00047d7a},
    {294268u, aot_00047d7c},
    {294272u, aot_00047d80},
    {294282u, aot_00047d8a},
    {294292u, aot_00047d94},
    {294294u, aot_00047d96},
    {294298u, aot_00047d9a},
    {294342u, aot_00047dc6},
    {294350u, aot_00047dce},
    {294352u, aot_00047dd0},
    {294356u, aot_00047dd4},
    {294366u, aot_00047dde},
    {294376u, aot_00047de8},
    {294378u, aot_00047dea},
    {294382u, aot_00047dee},
    {294426u, aot_00047e1a},
    {294434u, aot_00047e22},
    {294436u, aot_00047e24},
    {294440u, aot_00047e28},
    {294450u, aot_00047e32},
    {294460u, aot_00047e3c},
    {294462u, aot_00047e3e},
    {294466u, aot_00047e42},
    {294510u, aot_00047e6e},
    {294518u, aot_00047e76},
    {294520u, aot_00047e78},
    {294524u, aot_00047e7c},
    {294534u, aot_00047e86},
    {294544u, aot_00047e90},
    {294546u, aot_00047e92},
    {294550u, aot_00047e96},
    {294594u, aot_00047ec2},
    {294602u, aot_00047eca},
    {294604u, aot_00047ecc},
    {294608u, aot_00047ed0},
    {294618u, aot_00047eda},
    {294628u, aot_00047ee4},
    {294630u, aot_00047ee6},
    {294634u, aot_00047eea},
    {294678u, aot_00047f16},
    {294686u, aot_00047f1e},
    {294688u, aot_00047f20},
    {294692u, aot_00047f24},
    {294702u, aot_00047f2e},
    {294712u, aot_00047f38},
    {294714u, aot_00047f3a},
    {294718u, aot_00047f3e},
    {294762u, aot_00047f6a},
    {294770u, aot_00047f72},
    {294772u, aot_00047f74},
    {294776u, aot_00047f78},
    {294786u, aot_00047f82},
    {294796u, aot_00047f8c},
    {294798u, aot_00047f8e},
    {294802u, aot_00047f92},
    {294846u, aot_00047fbe},
    {294854u, aot_00047fc6},
    {294856u, aot_00047fc8},
    {294860u, aot_00047fcc},
    {294870u, aot_00047fd6},
    {294880u, aot_00047fe0},
    {294882u, aot_00047fe2},
    {294886u, aot_00047fe6},
    {294930u, aot_00048012},
    {294938u, aot_0004801a},
    {294940u, aot_0004801c},
    {294944u, aot_00048020},
    {294954u, aot_0004802a},
    {294964u, aot_00048034},
    {294966u, aot_00048036},
    {294970u, aot_0004803a},
    {295014u, aot_00048066},
    {295022u, aot_0004806e},
    {295024u, aot_00048070},
    {295028u, aot_00048074},
    {295038u, aot_0004807e},
    {295048u, aot_00048088},
    {295050u, aot_0004808a},
    {295054u, aot_0004808e},
    {295098u, aot_000480ba},
    {295106u, aot_000480c2},
    {295108u, aot_000480c4},
    {295112u, aot_000480c8},
    {295122u, aot_000480d2},
    {295132u, aot_000480dc},
    {295134u, aot_000480de},
    {295138u, aot_000480e2},
    {295182u, aot_0004810e},
    {295190u, aot_00048116},
    {295192u, aot_00048118},
    {295196u, aot_0004811c},
    {295206u, aot_00048126},
    {295216u, aot_00048130},
    {295218u, aot_00048132},
    {295222u, aot_00048136},
    {295266u, aot_00048162},
    {295274u, aot_0004816a},
    {295276u, aot_0004816c},
    {295280u, aot_00048170},
    {295290u, aot_0004817a},
    {295300u, aot_00048184},
    {295302u, aot_00048186},
    {295306u, aot_0004818a},
    {295350u, aot_000481b6},
    {295358u, aot_000481be},
    {295360u, aot_000481c0},
    {295364u, aot_000481c4},
    {295374u, aot_000481ce},
    {295384u, aot_000481d8},
    {295386u, aot_000481da},
    {295390u, aot_000481de},
    {295434u, aot_0004820a},
    {295442u, aot_00048212},
    {295444u, aot_00048214},
    {295448u, aot_00048218},
    {295458u, aot_00048222},
    {295468u, aot_0004822c},
    {295470u, aot_0004822e},
    {295474u, aot_00048232},
    {295510u, aot_00048256},
    {295520u, aot_00048260},
    {295524u, aot_00048264},
    {295528u, aot_00048268},
    {295562u, aot_0004828a},
    {295570u, aot_00048292},
    {295572u, aot_00048294},
    {295576u, aot_00048298},
    {295586u, aot_000482a2},
    {295596u, aot_000482ac},
    {295598u, aot_000482ae},
    {295602u, aot_000482b2},
    {295646u, aot_000482de},
    {295654u, aot_000482e6},
    {295656u, aot_000482e8},
    {295660u, aot_000482ec},
    {295670u, aot_000482f6},
    {295680u, aot_00048300},
    {295682u, aot_00048302},
    {295686u, aot_00048306},
    {295722u, aot_0004832a},
    {295732u, aot_00048334},
    {295736u, aot_00048338},
    {295740u, aot_0004833c},
    {295774u, aot_0004835e},
    {295782u, aot_00048366},
    {295784u, aot_00048368},
    {295788u, aot_0004836c},
    {295798u, aot_00048376},
    {295808u, aot_00048380},
    {295810u, aot_00048382},
    {295814u, aot_00048386},
    {295858u, aot_000483b2},
    {295866u, aot_000483ba},
    {295868u, aot_000483bc},
    {295872u, aot_000483c0},
    {295882u, aot_000483ca},
    {295892u, aot_000483d4},
    {295894u, aot_000483d6},
    {295898u, aot_000483da},
    {295934u, aot_000483fe},
    {295944u, aot_00048408},
    {295948u, aot_0004840c},
    {295952u, aot_00048410},
    {295986u, aot_00048432},
    {295994u, aot_0004843a},
    {295996u, aot_0004843c},
    {296000u, aot_00048440},
    {296010u, aot_0004844a},
    {296020u, aot_00048454},
    {296022u, aot_00048456},
    {296026u, aot_0004845a},
    {296070u, aot_00048486},
    {296078u, aot_0004848e},
    {296080u, aot_00048490},
    {296084u, aot_00048494},
    {296094u, aot_0004849e},
    {296104u, aot_000484a8},
    {296106u, aot_000484aa},
    {296110u, aot_000484ae},
    {296154u, aot_000484da},
    {296162u, aot_000484e2},
    {296164u, aot_000484e4},
    {296168u, aot_000484e8},
    {296178u, aot_000484f2},
    {296188u, aot_000484fc},
    {296190u, aot_000484fe},
    {296194u, aot_00048502},
    {296226u, aot_00048522},
    {296230u, aot_00048526},
    {296256u, aot_00048540},
    {296258u, aot_00048542},
    {296262u, aot_00048546},
    {296272u, aot_00048550},
    {296276u, aot_00048554},
    {296280u, aot_00048558},
    {296282u, aot_0004855a},
    {296326u, aot_00048586},
    {296334u, aot_0004858e},
    {296336u, aot_00048590},
    {296340u, aot_00048594},
    {296350u, aot_0004859e},
    {296360u, aot_000485a8},
    {296362u, aot_000485aa},
    {296366u, aot_000485ae},
    {296410u, aot_000485da},
    {296418u, aot_000485e2},
    {296420u, aot_000485e4},
    {296424u, aot_000485e8},
    {296434u, aot_000485f2},
    {296444u, aot_000485fc},
    {296446u, aot_000485fe},
    {296450u, aot_00048602},
    {296482u, aot_00048622},
    {296492u, aot_0004862c},
    {296496u, aot_00048630},
    {296512u, aot_00048640},
    {296516u, aot_00048644},
    {296520u, aot_00048648},
    {296546u, aot_00048662},
    {296564u, aot_00048674},
    {296570u, aot_0004867a},
    {296578u, aot_00048682},
    {296584u, aot_00048688},
    {296592u, aot_00048690},
    {296598u, aot_00048696},
    {296606u, aot_0004869e},
    {296612u, aot_000486a4},
    {296620u, aot_000486ac},
    {296626u, aot_000486b2},
    {296634u, aot_000486ba},
    {296640u, aot_000486c0},
    {296648u, aot_000486c8},
    {296654u, aot_000486ce},
    {296662u, aot_000486d6},
    {296668u, aot_000486dc},
    {296676u, aot_000486e4},
    {296682u, aot_000486ea},
    {296690u, aot_000486f2},
    {296696u, aot_000486f8},
    {296704u, aot_00048700},
    {296710u, aot_00048706},
    {296718u, aot_0004870e},
    {296724u, aot_00048714},
    {296784u, aot_00048750},
    {296790u, aot_00048756},
    {296798u, aot_0004875e},
    {296804u, aot_00048764},
    {296812u, aot_0004876c},
    {296818u, aot_00048772},
    {296826u, aot_0004877a},
    {296832u, aot_00048780},
    {296840u, aot_00048788},
    {296846u, aot_0004878e},
    {296854u, aot_00048796},
    {296860u, aot_0004879c},
    {296868u, aot_000487a4},
    {296874u, aot_000487aa},
    {296882u, aot_000487b2},
    {296888u, aot_000487b8},
    {296896u, aot_000487c0},
    {296902u, aot_000487c6},
    {296910u, aot_000487ce},
    {296916u, aot_000487d4},
    {296924u, aot_000487dc},
    {296930u, aot_000487e2},
    {296938u, aot_000487ea},
    {296944u, aot_000487f0},
    {297014u, aot_00048836},
    {297018u, aot_0004883a},
    {297032u, aot_00048848},
    {297044u, aot_00048854},
    {297050u, aot_0004885a},
    {596206u, aot_000918ee},
    {596214u, aot_000918f6},
    {596224u, aot_00091900},
    {596234u, aot_0009190a},
    {596242u, aot_00091912},
    {596428u, aot_000919cc},
    {596434u, aot_000919d2},
    {596436u, aot_000919d4},
    {596440u, aot_000919d8},
    {596444u, aot_000919dc},
    {596446u, aot_000919de},
    {596456u, aot_000919e8},
    {596466u, aot_000919f2},
    {596468u, aot_000919f4},
    {596828u, aot_00091b5c},
    {596844u, aot_00091b6c},
    {596848u, aot_00091b70},
    {596858u, aot_00091b7a},
    {596860u, aot_00091b7c},
    {596864u, aot_00091b80},
    {596868u, aot_00091b84},
    {597160u, aot_00091ca8},
    {597162u, aot_00091caa},
    {599666u, aot_00092672},
    {599668u, aot_00092674},
    {599672u, aot_00092678},
    {599676u, aot_0009267c},
    {599680u, aot_00092680},
    {600428u, aot_0009296c},
    {600434u, aot_00092972},
    {600436u, aot_00092974},
    {600438u, aot_00092976},
    {600440u, aot_00092978},
    {600442u, aot_0009297a},
    {600444u, aot_0009297c},
    {600446u, aot_0009297e},
    {600450u, aot_00092982},
    {600456u, aot_00092988},
    {600458u, aot_0009298a},
    {600472u, aot_00092998},
    {600478u, aot_0009299e},
    {600480u, aot_000929a0},
    {600482u, aot_000929a2},
    {600488u, aot_000929a8},
    {601352u, aot_00092d08},
    {601356u, aot_00092d0c},
    {601358u, aot_00092d0e},
    {601362u, aot_00092d12},
    {601364u, aot_00092d14},
    {601370u, aot_00092d1a},
    {601376u, aot_00092d20},
    {601382u, aot_00092d26},
    {601386u, aot_00092d2a},
    {601388u, aot_00092d2c},
    {601396u, aot_00092d34},
    {601414u, aot_00092d46},
    {601424u, aot_00092d50},
    {601426u, aot_00092d52},
    {601428u, aot_00092d54},
    {601430u, aot_00092d56},
    {601478u, aot_00092d86},
    {602820u, aot_000932c4},
    {602822u, aot_000932c6},
    {602824u, aot_000932c8},
    {602956u, aot_0009334c},
    {602962u, aot_00093352},
    {602966u, aot_00093356},
    {602968u, aot_00093358},
    {603008u, aot_00093380},
    {603012u, aot_00093384},
    {603016u, aot_00093388},
    {603020u, aot_0009338c},
    {603022u, aot_0009338e},
    {603030u, aot_00093396},
    {603080u, aot_000933c8},
    {603084u, aot_000933cc},
    {603088u, aot_000933d0},
    {603094u, aot_000933d6},
    {603154u, aot_00093412},
    {603156u, aot_00093414},
    {603160u, aot_00093418},
    {603206u, aot_00093446},
    {603226u, aot_0009345a},
    {603238u, aot_00093466},
    {603244u, aot_0009346c},
    {603296u, aot_000934a0},
    {603304u, aot_000934a8},
    {603314u, aot_000934b2},
    {603320u, aot_000934b8},
    {603370u, aot_000934ea},
    {603384u, aot_000934f8},
    {603390u, aot_000934fe},
    {603392u, aot_00093500},
    {603434u, aot_0009352a},
    {603440u, aot_00093530},
    {603446u, aot_00093536},
    {603448u, aot_00093538},
    {603458u, aot_00093542},
    {603498u, aot_0009356a},
    {603560u, aot_000935a8},
    {603570u, aot_000935b2},
    {603626u, aot_000935ea},
    {603628u, aot_000935ec},
    {603674u, aot_0009361a},
    {603694u, aot_0009362e},
    {603706u, aot_0009363a},
    {603712u, aot_00093640},
    {603764u, aot_00093674},
    {603772u, aot_0009367c},
    {603782u, aot_00093686},
    {603788u, aot_0009368c},
    {603838u, aot_000936be},
    {603852u, aot_000936cc},
    {603858u, aot_000936d2},
    {603860u, aot_000936d4},
    {603902u, aot_000936fe},
    {603908u, aot_00093704},
    {603914u, aot_0009370a},
    {603916u, aot_0009370c},
    {603926u, aot_00093716},
    {603960u, aot_00093738},
    {603974u, aot_00093746},
    {603994u, aot_0009375a},
    {604002u, aot_00093762},
    {605474u, aot_00093d22},
    {605476u, aot_00093d24},
    {605478u, aot_00093d26},
    {605484u, aot_00093d2c},
    {605486u, aot_00093d2e},
    {605494u, aot_00093d36},
    {605500u, aot_00093d3c},
    {605502u, aot_00093d3e},
    {605512u, aot_00093d48},
    {605518u, aot_00093d4e},
    {605520u, aot_00093d50},
    {605662u, aot_00093dde},
    {605664u, aot_00093de0},
    {605670u, aot_00093de6},
    {605696u, aot_00093e00},
    {606542u, aot_0009414e},
    {606544u, aot_00094150},
    {606546u, aot_00094152},
    {606552u, aot_00094158},
    {606554u, aot_0009415a},
    {606564u, aot_00094164},
    {606570u, aot_0009416a},
    {606572u, aot_0009416c},
    {606582u, aot_00094176},
    {606588u, aot_0009417c},
    {606590u, aot_0009417e},
    {606734u, aot_0009420e},
    {606736u, aot_00094210},
    {606742u, aot_00094216},
    {606766u, aot_0009422e},
    {612330u, aot_000957ea},
    {612334u, aot_000957ee},
    {612348u, aot_000957fc},
    {612386u, aot_00095822},
    {612388u, aot_00095824},
    {612396u, aot_0009582c},
    {618688u, aot_000970c0},
    {618696u, aot_000970c8},
    {618702u, aot_000970ce},
    {618706u, aot_000970d2},
    {618712u, aot_000970d8},
    {619842u, aot_00097542},
    {619848u, aot_00097548},
    {619858u, aot_00097552},
    {620460u, aot_000977ac},
    {620462u, aot_000977ae},
    {620466u, aot_000977b2},
    {620472u, aot_000977b8},
    {620474u, aot_000977ba},
    {620476u, aot_000977bc},
    {620486u, aot_000977c6},
    {620490u, aot_000977ca},
    {620496u, aot_000977d0},
    {620500u, aot_000977d4},
    {620506u, aot_000977da},
    {622654u, aot_0009803e},
    {622664u, aot_00098048},
    {622666u, aot_0009804a},
    {622668u, aot_0009804c},
    {622678u, aot_00098056},
    {622682u, aot_0009805a},
    {622688u, aot_00098060},
    {622696u, aot_00098068},
    {622722u, aot_00098082},
    {622732u, aot_0009808c},
    {622734u, aot_0009808e},
    {622736u, aot_00098090},
    {622746u, aot_0009809a},
    {622750u, aot_0009809e},
    {622756u, aot_000980a4},
    {622764u, aot_000980ac},
    {625516u, aot_00098b6c},
    {625518u, aot_00098b6e},
    {625522u, aot_00098b72},
    {625528u, aot_00098b78},
    {625530u, aot_00098b7a},
    {625532u, aot_00098b7c},
    {625542u, aot_00098b86},
    {625546u, aot_00098b8a},
    {625552u, aot_00098b90},
    {625556u, aot_00098b94},
    {625566u, aot_00098b9e},
    {625802u, aot_00098c8a},
    {625812u, aot_00098c94},
    {625814u, aot_00098c96},
    {625816u, aot_00098c98},
    {625826u, aot_00098ca2},
    {625830u, aot_00098ca6},
    {625836u, aot_00098cac},
    {625848u, aot_00098cb8},
    {625870u, aot_00098cce},
    {625880u, aot_00098cd8},
    {625882u, aot_00098cda},
    {625884u, aot_00098cdc},
    {625894u, aot_00098ce6},
    {625898u, aot_00098cea},
    {625904u, aot_00098cf0},
    {625916u, aot_00098cfc},
    {655254u, aot_0009ff96},
    {655260u, aot_0009ff9c},
    {655272u, aot_0009ffa8},
    {655280u, aot_0009ffb0},
    {655358u, aot_0009fffe},
    {655364u, aot_000a0004},
    {655376u, aot_000a0010},
    {655384u, aot_000a0018},
    {686066u, aot_000a77f2},
    {686068u, aot_000a77f4},
    {686070u, aot_000a77f6},
    {686076u, aot_000a77fc},
    {686080u, aot_000a7800},
    {686088u, aot_000a7808},
    {686098u, aot_000a7812},
    {686882u, aot_000a7b22},
    {686884u, aot_000a7b24},
    {686888u, aot_000a7b28},
    {686894u, aot_000a7b2e},
    {686898u, aot_000a7b32},
    {687052u, aot_000a7bcc},
    {687056u, aot_000a7bd0},
    {687058u, aot_000a7bd2},
    {687066u, aot_000a7bda},
    {687070u, aot_000a7bde},
    {687076u, aot_000a7be4},
    {687092u, aot_000a7bf4},
    {687098u, aot_000a7bfa},
    {687138u, aot_000a7c22},
    {687164u, aot_000a7c3c},
    {687170u, aot_000a7c42},
    {687176u, aot_000a7c48},
    {687186u, aot_000a7c52},
    {687230u, aot_000a7c7e},
    {687260u, aot_000a7c9c},
    {687266u, aot_000a7ca2},
    {687272u, aot_000a7ca8},
    {687278u, aot_000a7cae},
    {687318u, aot_000a7cd6},
    {687348u, aot_000a7cf4},
    {687354u, aot_000a7cfa},
    {687360u, aot_000a7d00},
    {687366u, aot_000a7d06},
    {687432u, aot_000a7d48},
    {687900u, aot_000a7f1c},
    {687904u, aot_000a7f20},
    {687906u, aot_000a7f22},
    {687914u, aot_000a7f2a},
    {687918u, aot_000a7f2e},
    {687924u, aot_000a7f34},
    {687940u, aot_000a7f44},
    {687946u, aot_000a7f4a},
    {687986u, aot_000a7f72},
    {688012u, aot_000a7f8c},
    {688018u, aot_000a7f92},
    {688024u, aot_000a7f98},
    {688034u, aot_000a7fa2},
    {688078u, aot_000a7fce},
    {688108u, aot_000a7fec},
    {688114u, aot_000a7ff2},
    {688120u, aot_000a7ff8},
    {688126u, aot_000a7ffe},
    {688166u, aot_000a8026},
    {688196u, aot_000a8044},
    {688202u, aot_000a804a},
    {688208u, aot_000a8050},
    {688214u, aot_000a8056},
    {688280u, aot_000a8098},
    {689040u, aot_000a8390},
    {689044u, aot_000a8394},
    {689046u, aot_000a8396},
    {689050u, aot_000a839a},
    {689052u, aot_000a839c},
    {689056u, aot_000a83a0},
    {689060u, aot_000a83a4},
    {689066u, aot_000a83aa},
    {689078u, aot_000a83b6},
    {689080u, aot_000a83b8},
    {689092u, aot_000a83c4},
    {689094u, aot_000a83c6},
    {689096u, aot_000a83c8},
    {689108u, aot_000a83d4},
    {689112u, aot_000a83d8},
    {689128u, aot_000a83e8},
    {689130u, aot_000a83ea},
    {689132u, aot_000a83ec},
    {689146u, aot_000a83fa},
    {689156u, aot_000a8404},
    {689160u, aot_000a8408},
    {689162u, aot_000a840a},
    {689164u, aot_000a840c},
    {689172u, aot_000a8414},
    {689176u, aot_000a8418},
    {689178u, aot_000a841a},
    {689190u, aot_000a8426},
    {689194u, aot_000a842a},
    {689202u, aot_000a8432},
    {689206u, aot_000a8436},
    {689208u, aot_000a8438},
    {689220u, aot_000a8444},
    {689224u, aot_000a8448},
    {689226u, aot_000a844a},
    {689230u, aot_000a844e},
    {689234u, aot_000a8452},
    {689238u, aot_000a8456},
    {689242u, aot_000a845a},
    {689256u, aot_000a8468},
    {689258u, aot_000a846a},
    {689306u, aot_000a849a},
    {689310u, aot_000a849e},
    {689312u, aot_000a84a0},
    {689322u, aot_000a84aa},
    {689328u, aot_000a84b0},
    {689332u, aot_000a84b4},
    {689334u, aot_000a84b6},
    {689338u, aot_000a84ba},
    {689342u, aot_000a84be},
    {689348u, aot_000a84c4},
    {689362u, aot_000a84d2},
    {689366u, aot_000a84d6},
    {689368u, aot_000a84d8},
    {689372u, aot_000a84dc},
    {689376u, aot_000a84e0},
    {689382u, aot_000a84e6},
    {689396u, aot_000a84f4},
    {689400u, aot_000a84f8},
    {689402u, aot_000a84fa},
    {689420u, aot_000a850c},
    {689424u, aot_000a8510},
    {689432u, aot_000a8518},
    {689440u, aot_000a8520},
    {689444u, aot_000a8524},
    {689446u, aot_000a8526},
    {689450u, aot_000a852a},
    {689454u, aot_000a852e},
    {689458u, aot_000a8532},
    {689462u, aot_000a8536},
    {689470u, aot_000a853e},
    {689480u, aot_000a8548},
    {689482u, aot_000a854a},
    {689568u, aot_000a85a0},
    {689572u, aot_000a85a4},
    {689574u, aot_000a85a6},
    {689584u, aot_000a85b0},
    {689590u, aot_000a85b6},
    {689598u, aot_000a85be},
    {689602u, aot_000a85c2},
    {689606u, aot_000a85c6},
    {689610u, aot_000a85ca},
    {689614u, aot_000a85ce},
    {689624u, aot_000a85d8},
    {689630u, aot_000a85de},
    {689714u, aot_000a8632},
    {689718u, aot_000a8636},
    {689720u, aot_000a8638},
    {689730u, aot_000a8642},
    {689736u, aot_000a8648},
    {689740u, aot_000a864c},
    {689742u, aot_000a864e},
    {689746u, aot_000a8652},
    {689750u, aot_000a8656},
    {689756u, aot_000a865c},
    {689770u, aot_000a866a},
    {689774u, aot_000a866e},
    {689776u, aot_000a8670},
    {689780u, aot_000a8674},
    {689784u, aot_000a8678},
    {689790u, aot_000a867e},
    {689804u, aot_000a868c},
    {689808u, aot_000a8690},
    {689810u, aot_000a8692},
    {689814u, aot_000a8696},
    {689818u, aot_000a869a},
    {689822u, aot_000a869e},
    {689832u, aot_000a86a8},
    {689974u, aot_000a8736},
    {689978u, aot_000a873a},
    {689980u, aot_000a873c},
    {689988u, aot_000a8744},
    {689996u, aot_000a874c},
    {690000u, aot_000a8750},
    {690002u, aot_000a8752},
    {690006u, aot_000a8756},
    {690010u, aot_000a875a},
    {690016u, aot_000a8760},
    {690030u, aot_000a876e},
    {690034u, aot_000a8772},
    {690036u, aot_000a8774},
    {690040u, aot_000a8778},
    {690044u, aot_000a877c},
    {690050u, aot_000a8782},
    {690064u, aot_000a8790},
    {690068u, aot_000a8794},
    {690076u, aot_000a879c},
    {690080u, aot_000a87a0},
    {690082u, aot_000a87a2},
    {690094u, aot_000a87ae},
    {690098u, aot_000a87b2},
    {690106u, aot_000a87ba},
    {690110u, aot_000a87be},
    {690112u, aot_000a87c0},
    {690124u, aot_000a87cc},
    {690128u, aot_000a87d0},
    {690136u, aot_000a87d8},
    {690140u, aot_000a87dc},
    {690142u, aot_000a87de},
    {690154u, aot_000a87ea},
    {690158u, aot_000a87ee},
    {690160u, aot_000a87f0},
    {690164u, aot_000a87f4},
    {690168u, aot_000a87f8},
    {690172u, aot_000a87fc},
    {690176u, aot_000a8800},
    {690188u, aot_000a880c},
    {690234u, aot_000a883a},
    {690238u, aot_000a883e},
    {690240u, aot_000a8840},
    {690248u, aot_000a8848},
    {690256u, aot_000a8850},
    {690260u, aot_000a8854},
    {690262u, aot_000a8856},
    {690266u, aot_000a885a},
    {690270u, aot_000a885e},
    {690276u, aot_000a8864},
    {690290u, aot_000a8872},
    {690294u, aot_000a8876},
    {690296u, aot_000a8878},
    {690300u, aot_000a887c},
    {690304u, aot_000a8880},
    {690310u, aot_000a8886},
    {690324u, aot_000a8894},
    {690328u, aot_000a8898},
    {690330u, aot_000a889a},
    {690348u, aot_000a88ac},
    {690352u, aot_000a88b0},
    {690360u, aot_000a88b8},
    {690368u, aot_000a88c0},
    {690372u, aot_000a88c4},
    {690374u, aot_000a88c6},
    {690378u, aot_000a88ca},
    {690382u, aot_000a88ce},
    {690386u, aot_000a88d2},
    {690390u, aot_000a88d6},
    {690402u, aot_000a88e2},
    {690410u, aot_000a88ea},
    {690488u, aot_000a8938},
    {690492u, aot_000a893c},
    {690494u, aot_000a893e},
    {690502u, aot_000a8946},
    {690510u, aot_000a894e},
    {690514u, aot_000a8952},
    {690516u, aot_000a8954},
    {690520u, aot_000a8958},
    {690524u, aot_000a895c},
    {690528u, aot_000a8960},
    {690532u, aot_000a8964},
    {690550u, aot_000a8976},
    {690628u, aot_000a89c4},
    {690638u, aot_000a89ce},
    {690646u, aot_000a89d6},
    {690650u, aot_000a89da},
    {690658u, aot_000a89e2},
    {690674u, aot_000a89f2},
    {690678u, aot_000a89f6},
    {690686u, aot_000a89fe},
    {690702u, aot_000a8a0e},
    {690704u, aot_000a8a10},
    {690708u, aot_000a8a14},
    {690714u, aot_000a8a1a},
    {690724u, aot_000a8a24},
    {690868u, aot_000a8ab4},
    {690876u, aot_000a8abc},
    {690884u, aot_000a8ac4},
    {690888u, aot_000a8ac8},
    {690892u, aot_000a8acc},
    {690900u, aot_000a8ad4},
    {690916u, aot_000a8ae4},
    {690920u, aot_000a8ae8},
    {690924u, aot_000a8aec},
    {690932u, aot_000a8af4},
    {690948u, aot_000a8b04},
    {690958u, aot_000a8b0e},
    {690970u, aot_000a8b1a},
    {690972u, aot_000a8b1c},
    {690986u, aot_000a8b2a},
    {690988u, aot_000a8b2c},
    {691002u, aot_000a8b3a},
    {691004u, aot_000a8b3c},
    {691018u, aot_000a8b4a},
    {691020u, aot_000a8b4c},
    {691034u, aot_000a8b5a},
    {691036u, aot_000a8b5c},
    {691050u, aot_000a8b6a},
    {691052u, aot_000a8b6c},
    {691066u, aot_000a8b7a},
    {691068u, aot_000a8b7c},
    {691082u, aot_000a8b8a},
    {691084u, aot_000a8b8c},
    {691098u, aot_000a8b9a},
    {691102u, aot_000a8b9e},
    {691782u, aot_000a8e46},
    {691788u, aot_000a8e4c},
    {691800u, aot_000a8e58},
    {691804u, aot_000a8e5c},
    {691832u, aot_000a8e78},
    {691838u, aot_000a8e7e},
    {691844u, aot_000a8e84},
    {691846u, aot_000a8e86},
    {691848u, aot_000a8e88},
    {691898u, aot_000a8eba},
    {691902u, aot_000a8ebe},
    {691914u, aot_000a8eca},
    {691918u, aot_000a8ece},
    {691920u, aot_000a8ed0},
    {691924u, aot_000a8ed4},
    {692004u, aot_000a8f24},
    {697642u, aot_000aa52a},
    {697648u, aot_000aa530},
    {697660u, aot_000aa53c},
    {697668u, aot_000aa544},
    {697670u, aot_000aa546},
    {697678u, aot_000aa54e},
    {699486u, aot_000aac5e},
    {700370u, aot_000aafd2},
    {700378u, aot_000aafda},
    {700630u, aot_000ab0d6},
    {700632u, aot_000ab0d8},
    {700638u, aot_000ab0de},
    {700658u, aot_000ab0f2},
    {700686u, aot_000ab10e},
    {700688u, aot_000ab110},
    {700722u, aot_000ab132},
    {700724u, aot_000ab134},
    {700752u, aot_000ab150},
    {701280u, aot_000ab360},
    {701284u, aot_000ab364},
    {701286u, aot_000ab366},
    {701330u, aot_000ab392},
    {701340u, aot_000ab39c},
    {701344u, aot_000ab3a0},
    {701346u, aot_000ab3a2},
    {701354u, aot_000ab3aa},
    {701360u, aot_000ab3b0},
    {701366u, aot_000ab3b6},
    {701576u, aot_000ab488},
    {701582u, aot_000ab48e},
    {701614u, aot_000ab4ae},
    {701620u, aot_000ab4b4},
    {701622u, aot_000ab4b6},
    {701624u, aot_000ab4b8},
    {701626u, aot_000ab4ba},
    {701640u, aot_000ab4c8},
    {701694u, aot_000ab4fe},
    {703594u, aot_000abc6a},
    {703598u, aot_000abc6e},
    {703604u, aot_000abc74},
    {703608u, aot_000abc78},
    {703636u, aot_000abc94},
    {703638u, aot_000abc96},
    {703648u, aot_000abca0},
    {703654u, aot_000abca6},
    {703664u, aot_000abcb0},
    {703672u, aot_000abcb8},
    {703680u, aot_000abcc0},
    {703682u, aot_000abcc2},
    {703686u, aot_000abcc6},
    {709308u, aot_000ad2bc},
    {709316u, aot_000ad2c4},
    {709322u, aot_000ad2ca},
    {709326u, aot_000ad2ce},
    {709332u, aot_000ad2d4},
    {710462u, aot_000ad73e},
    {710468u, aot_000ad744},
    {710478u, aot_000ad74e},
    {711080u, aot_000ad9a8},
    {711082u, aot_000ad9aa},
    {711086u, aot_000ad9ae},
    {711092u, aot_000ad9b4},
    {711094u, aot_000ad9b6},
    {711096u, aot_000ad9b8},
    {711106u, aot_000ad9c2},
    {711110u, aot_000ad9c6},
    {711116u, aot_000ad9cc},
    {711120u, aot_000ad9d0},
    {711126u, aot_000ad9d6},
    {713110u, aot_000ae196},
    {713120u, aot_000ae1a0},
    {713122u, aot_000ae1a2},
    {713124u, aot_000ae1a4},
    {713134u, aot_000ae1ae},
    {713138u, aot_000ae1b2},
    {713144u, aot_000ae1b8},
    {713152u, aot_000ae1c0},
    {713178u, aot_000ae1da},
    {713188u, aot_000ae1e4},
    {713190u, aot_000ae1e6},
    {713192u, aot_000ae1e8},
    {713202u, aot_000ae1f2},
    {713206u, aot_000ae1f6},
    {713212u, aot_000ae1fc},
    {713220u, aot_000ae204},
    {715972u, aot_000aecc4},
    {715974u, aot_000aecc6},
    {715978u, aot_000aecca},
    {715984u, aot_000aecd0},
    {715986u, aot_000aecd2},
    {715988u, aot_000aecd4},
    {715998u, aot_000aecde},
    {716002u, aot_000aece2},
    {716008u, aot_000aece8},
    {716012u, aot_000aecec},
    {716022u, aot_000aecf6},
    {716258u, aot_000aede2},
    {716268u, aot_000aedec},
    {716270u, aot_000aedee},
    {716272u, aot_000aedf0},
    {716282u, aot_000aedfa},
    {716286u, aot_000aedfe},
    {716292u, aot_000aee04},
    {716304u, aot_000aee10},
    {716326u, aot_000aee26},
    {716336u, aot_000aee30},
    {716338u, aot_000aee32},
    {716340u, aot_000aee34},
    {716350u, aot_000aee3e},
    {716354u, aot_000aee42},
    {716360u, aot_000aee48},
    {716372u, aot_000aee54},
    {788088u, aot_000c0678},
    {788100u, aot_000c0684},
    {788114u, aot_000c0692},
    {788126u, aot_000c069e},
    {788128u, aot_000c06a0},
    {788134u, aot_000c06a6},
    {788136u, aot_000c06a8},
    {788162u, aot_000c06c2},
    {792202u, aot_000c168a},
    {792206u, aot_000c168e},
    {792210u, aot_000c1692},
    {792214u, aot_000c1696},
    {792216u, aot_000c1698},
    {792224u, aot_000c16a0},
    {792238u, aot_000c16ae},
    {792248u, aot_000c16b8},
    {792910u, aot_000c194e},
    {792912u, aot_000c1950},
    {792914u, aot_000c1952},
    {792920u, aot_000c1958},
    {792922u, aot_000c195a},
    {792924u, aot_000c195c},
    {792930u, aot_000c1962},
    {792932u, aot_000c1964},
    {792944u, aot_000c1970},
    {794998u, aot_000c2176},
    {795000u, aot_000c2178},
    {795008u, aot_000c2180},
    {795014u, aot_000c2186},
    {795016u, aot_000c2188},
    {795020u, aot_000c218c},
    {795024u, aot_000c2190},
    {795026u, aot_000c2192},
    {795028u, aot_000c2194},
    {795042u, aot_000c21a2},
    {795060u, aot_000c21b4},
    {795064u, aot_000c21b8},
    {795066u, aot_000c21ba},
    {795068u, aot_000c21bc},
    {795084u, aot_000c21cc},
    {795086u, aot_000c21ce},
    {795090u, aot_000c21d2},
    {795186u, aot_000c2232},
    {795188u, aot_000c2234},
    {795196u, aot_000c223c},
    {795200u, aot_000c2240},
    {795204u, aot_000c2244},
    {795206u, aot_000c2246},
    {795212u, aot_000c224c},
    {795214u, aot_000c224e},
    {795216u, aot_000c2250},
    {795246u, aot_000c226e},
    {795250u, aot_000c2272},
    {795252u, aot_000c2274},
    {795268u, aot_000c2284},
    {795272u, aot_000c2288},
    {795722u, aot_000c244a},
    {795724u, aot_000c244c},
    {795726u, aot_000c244e},
    {795730u, aot_000c2452},
    {795734u, aot_000c2456},
    {795736u, aot_000c2458},
    {795740u, aot_000c245c},
    {795744u, aot_000c2460},
    {795746u, aot_000c2462},
    {795748u, aot_000c2464},
    {795754u, aot_000c246a},
    {795756u, aot_000c246c},
    {795758u, aot_000c246e},
    {795764u, aot_000c2474},
    {795788u, aot_000c248c},
    {795910u, aot_000c2506},
    {795912u, aot_000c2508},
    {795914u, aot_000c250a},
    {795918u, aot_000c250e},
    {795922u, aot_000c2512},
    {795924u, aot_000c2514},
    {795928u, aot_000c2518},
    {795932u, aot_000c251c},
    {795934u, aot_000c251e},
    {795936u, aot_000c2520},
    {795942u, aot_000c2526},
    {795944u, aot_000c2528},
    {795946u, aot_000c252a},
    {795952u, aot_000c2530},
    {795976u, aot_000c2548},
    {796096u, aot_000c25c0},
    {796100u, aot_000c25c4},
    {796102u, aot_000c25c6},
    {796104u, aot_000c25c8},
    {796108u, aot_000c25cc},
    {796118u, aot_000c25d6},
    {796126u, aot_000c25de},
    {796130u, aot_000c25e2},
    {796138u, aot_000c25ea},
    {796144u, aot_000c25f0},
    {796172u, aot_000c260c},
    {796174u, aot_000c260e},
    {796190u, aot_000c261e},
    {796300u, aot_000c268c},
    {796304u, aot_000c2690},
    {796306u, aot_000c2692},
    {796308u, aot_000c2694},
    {796312u, aot_000c2698},
    {796322u, aot_000c26a2},
    {796330u, aot_000c26aa},
    {796334u, aot_000c26ae},
    {796342u, aot_000c26b6},
    {796348u, aot_000c26bc},
    {796376u, aot_000c26d8},
    {796378u, aot_000c26da},
    {796394u, aot_000c26ea},
    {797002u, aot_000c294a},
    {797666u, aot_000c2be2},
    {797668u, aot_000c2be4},
    {797670u, aot_000c2be6},
    {797678u, aot_000c2bee},
    {797680u, aot_000c2bf0},
    {797700u, aot_000c2c04},
    {797702u, aot_000c2c06},
    {797706u, aot_000c2c0a},
    {797720u, aot_000c2c18},
    {797722u, aot_000c2c1a},
    {797724u, aot_000c2c1c},
    {797732u, aot_000c2c24},
    {797760u, aot_000c2c40},
    {797764u, aot_000c2c44},
    {831156u, aot_000caeb4},
    {831380u, aot_000caf94},
};
const uint32_t agr_aot_block_count = 1218u;
