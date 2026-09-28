#include "agr_aot.h"

static int agr_region_00000(AgrAotRegs *outer) {
    uint32_t regs[16];
    memcpy(regs, outer->r, sizeof(regs));
    uint32_t cpsr = *outer->cpsr;
    AgrAotRegs local = {regs, &cpsr, outer->mem, outer->bias, 0, 0, 0};
    AgrAotRegs *s = &local;
    uint32_t blocks_done = 0, instructions = 0;
    int rc = 0, result = AGR_AOT_BOUNDARY;
    (void)rc;
    switch (regs[15] - s->bias) {
    case 3296u: goto L_00000ce0;
    case 3304u: goto L_00000ce8;
    case 3324u: goto L_00000cfc;
    case 3336u: goto L_00000d08;
    case 3348u: goto L_00000d14;
    case 3360u: goto L_00000d20;
    case 3372u: goto L_00000d2c;
    case 3384u: goto L_00000d38;
    case 3396u: goto L_00000d44;
    case 3408u: goto L_00000d50;
    case 3456u: goto L_00000d80;
    case 3524u: goto L_00000dc4;
    case 3548u: goto L_00000ddc;
    case 3564u: goto L_00000dec;
    case 3568u: goto L_00000df0;
    case 3582u: goto L_00000dfe;
    case 3586u: goto L_00000e02;
    case 3588u: goto L_00000e04;
    case 3602u: goto L_00000e12;
    case 3618u: goto L_00000e22;
    case 3632u: goto L_00000e30;
    case 3634u: goto L_00000e32;
    case 3648u: goto L_00000e40;
    case 3662u: goto L_00000e4e;
    case 3678u: goto L_00000e5e;
    case 3680u: goto L_00000e60;
    case 3696u: goto L_00000e70;
    case 3712u: goto L_00000e80;
    case 3728u: goto L_00000e90;
    case 3732u: goto L_00000e94;
    case 3758u: goto L_00000eae;
    case 3774u: goto L_00000ebe;
    case 3788u: goto L_00000ecc;
    case 3800u: goto L_00000ed8;
    case 3810u: goto L_00000ee2;
    case 3826u: goto L_00000ef2;
    case 3842u: goto L_00000f02;
    case 3848u: goto L_00000f08;
    case 3866u: goto L_00000f1a;
    case 3876u: goto L_00000f24;
    case 3902u: goto L_00000f3e;
    case 3910u: goto L_00000f46;
    case 3916u: goto L_00000f4c;
    case 3922u: goto L_00000f52;
    case 3934u: goto L_00000f5e;
    case 3948u: goto L_00000f6c;
    case 3950u: goto L_00000f6e;
    case 3954u: goto L_00000f72;
    case 3962u: goto L_00000f7a;
    case 3966u: goto L_00000f7e;
    case 3978u: goto L_00000f8a;
    case 3980u: goto L_00000f8c;
    case 3984u: goto L_00000f90;
    case 3988u: goto L_00000f94;
    case 3992u: goto L_00000f98;
    case 3996u: goto L_00000f9c;
    case 4000u: goto L_00000fa0;
    case 4004u: goto L_00000fa4;
    case 4008u: goto L_00000fa8;
    case 4012u: goto L_00000fac;
    case 4016u: goto L_00000fb0;
    case 4020u: goto L_00000fb4;
    case 4026u: goto L_00000fba;
    case 4032u: goto L_00000fc0;
    default: result = AGR_AOT_MISS; goto L_exit;
    }
L_00000ce0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load32(s, (s->bias + 3296u)) != 3852460036u) { result = AGR_AOT_MISS; goto L_exit; }
    { uint32_t addr = (s->bias + 3304u) + 4u; if ((rc = agr_aot_ldr(s, 14, addr))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000ce0; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 3300u;
L_after_00000ce0:
    blocks_done++;
    goto L_exit;
L_00000ce8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load32(s, (s->bias + 3304u)) != 3854495752u) { result = AGR_AOT_MISS; goto L_exit; }
    { uint32_t addr = s->r[14] + 8u; s->r[14] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000ce8; } result = rc; goto L_exit; } }
    instructions++;
L_after_00000ce8:
    blocks_done++;
    goto L_exit;
L_00000cfc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000cfc[] = {0x00, 0xc6, 0x8f, 0xe2, 0x02, 0xca, 0x8c, 0xe2, 0xd0, 0xf2, 0xbc, 0xe5};
    if (memcmp(s->mem + s->bias + 3324u, expected_00000cfc, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 12, (s->bias + 3332u), 0u);
    instructions++;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    instructions++;
    { uint32_t addr = s->r[12] + 720u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000cfc; } result = rc; goto L_exit; } }
    instructions++;
L_after_00000cfc:
    blocks_done++;
    goto L_exit;
L_00000d08:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000d08[] = {0x00, 0xc6, 0x8f, 0xe2, 0x02, 0xca, 0x8c, 0xe2, 0xc8, 0xf2, 0xbc, 0xe5};
    if (memcmp(s->mem + s->bias + 3336u, expected_00000d08, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 12, (s->bias + 3344u), 0u);
    instructions++;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    instructions++;
    { uint32_t addr = s->r[12] + 712u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000d08; } result = rc; goto L_exit; } }
    instructions++;
L_after_00000d08:
    blocks_done++;
    goto L_exit;
L_00000d14:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000d14[] = {0x00, 0xc6, 0x8f, 0xe2, 0x02, 0xca, 0x8c, 0xe2, 0xc0, 0xf2, 0xbc, 0xe5};
    if (memcmp(s->mem + s->bias + 3348u, expected_00000d14, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 12, (s->bias + 3356u), 0u);
    instructions++;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    instructions++;
    { uint32_t addr = s->r[12] + 704u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000d14; } result = rc; goto L_exit; } }
    instructions++;
L_after_00000d14:
    blocks_done++;
    goto L_exit;
L_00000d20:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000d20[] = {0x00, 0xc6, 0x8f, 0xe2, 0x02, 0xca, 0x8c, 0xe2, 0xb8, 0xf2, 0xbc, 0xe5};
    if (memcmp(s->mem + s->bias + 3360u, expected_00000d20, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 12, (s->bias + 3368u), 0u);
    instructions++;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    instructions++;
    { uint32_t addr = s->r[12] + 696u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000d20; } result = rc; goto L_exit; } }
    instructions++;
L_after_00000d20:
    blocks_done++;
    goto L_exit;
L_00000d2c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000d2c[] = {0x00, 0xc6, 0x8f, 0xe2, 0x02, 0xca, 0x8c, 0xe2, 0xb0, 0xf2, 0xbc, 0xe5};
    if (memcmp(s->mem + s->bias + 3372u, expected_00000d2c, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 12, (s->bias + 3380u), 0u);
    instructions++;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    instructions++;
    { uint32_t addr = s->r[12] + 688u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000d2c; } result = rc; goto L_exit; } }
    instructions++;
L_after_00000d2c:
    blocks_done++;
    goto L_exit;
L_00000d38:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000d38[] = {0x00, 0xc6, 0x8f, 0xe2, 0x02, 0xca, 0x8c, 0xe2, 0xa8, 0xf2, 0xbc, 0xe5};
    if (memcmp(s->mem + s->bias + 3384u, expected_00000d38, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 12, (s->bias + 3392u), 0u);
    instructions++;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    instructions++;
    { uint32_t addr = s->r[12] + 680u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000d38; } result = rc; goto L_exit; } }
    instructions++;
L_after_00000d38:
    blocks_done++;
    goto L_exit;
L_00000d44:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000d44[] = {0x00, 0xc6, 0x8f, 0xe2, 0x02, 0xca, 0x8c, 0xe2, 0xa0, 0xf2, 0xbc, 0xe5};
    if (memcmp(s->mem + s->bias + 3396u, expected_00000d44, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 12, (s->bias + 3404u), 0u);
    instructions++;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    instructions++;
    { uint32_t addr = s->r[12] + 672u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000d44; } result = rc; goto L_exit; } }
    instructions++;
L_after_00000d44:
    blocks_done++;
    goto L_exit;
L_00000d50:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000d50[] = {0x00, 0xc6, 0x8f, 0xe2, 0x02, 0xca, 0x8c, 0xe2, 0x98, 0xf2, 0xbc, 0xe5};
    if (memcmp(s->mem + s->bias + 3408u, expected_00000d50, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 12, (s->bias + 3416u), 0u);
    instructions++;
    agr_aot_add_imm(s, 12, s->r[12], 8192u);
    instructions++;
    { uint32_t addr = s->r[12] + 664u; s->r[12] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000d50; } result = rc; goto L_exit; } }
    instructions++;
L_after_00000d50:
    blocks_done++;
    goto L_exit;
L_00000d80:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load32(s, (s->bias + 3456u)) != 3852402692u) { result = AGR_AOT_MISS; goto L_exit; }
    { uint32_t addr = (s->bias + 3464u) + 4u; if ((rc = agr_aot_ldr(s, 0, addr))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000d80; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 3460u;
L_after_00000d80:
    blocks_done++;
    goto L_exit;
L_00000dc4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 3524u)) != 59693u || agr_aot_load16(s, (s->bias + 3526u)) != 20472u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 20472u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 3528u)) != 18074u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 10, 3);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 3530u)) != 26627u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000dc4; } result = rc; goto L_exit; } }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 3532u)) != 17937u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 1, 2);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 3534u)) != 18064u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 8, 2);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 3536u)) != 8704u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 2, 0u);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 3538u)) != 17924u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 4, 0);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 3540u)) != 40458u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 6, s->r[13] + 40u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000dc4; } result = rc; goto L_exit; } }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 3542u)) != 63699u || agr_aot_load16(s, (s->bias + 3544u)) != 13044u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000dc4; } result = rc; goto L_exit; } }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 3546u)) != 18328u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[3], (s->bias + 3548u), 1); { instructions++; goto L_after_00000dc4; }
L_after_00000dc4:
    blocks_done++;
    goto L_exit;
L_00000ddc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000ddc[] = {0x23, 0x68, 0x51, 0x46, 0x00, 0x22, 0xd3, 0xf8, 0xf4, 0x32, 0x07, 0x46, 0x20, 0x46, 0x98, 0x47};
    if (memcmp(s->mem + s->bias + 3548u, expected_00000ddc, 16u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000ddc; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 1, 10);
    instructions++;
    agr_aot_movs_imm(s, 2, 0u);
    instructions++;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000ddc; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 7, 0);
    instructions++;
    agr_aot_mov_reg(s, 0, 4);
    instructions++;
    agr_aot_branch_reg(s, s->r[3], (s->bias + 3564u), 1); { instructions++; goto L_after_00000ddc; }
L_after_00000ddc:
    blocks_done++;
    goto L_exit;
L_00000dec:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000dec[] = {0x81, 0x46, 0x46, 0xb1};
    if (memcmp(s->mem + s->bias + 3564u, expected_00000dec, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 9, 0);
    instructions++;
    s->r[15] = !s->r[6] ? (s->bias + 3586u) : (s->bias + 3568u); { instructions++; goto L_after_00000dec; }
L_after_00000dec:
    blocks_done++;
    if (regs[15] == s->bias + 3586u) goto L_00000e02;
    if (regs[15] == s->bias + 3568u) goto L_00000df0;
    goto L_exit;
L_00000df0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000df0[] = {0x23, 0x68, 0x20, 0x46, 0x31, 0x46, 0x00, 0x22, 0xd3, 0xf8, 0xec, 0x32, 0x98, 0x47};
    if (memcmp(s->mem + s->bias + 3568u, expected_00000df0, 14u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000df0; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 0, 4);
    instructions++;
    agr_aot_mov_reg(s, 1, 6);
    instructions++;
    agr_aot_movs_imm(s, 2, 0u);
    instructions++;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 748u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000df0; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_branch_reg(s, s->r[3], (s->bias + 3582u), 1); { instructions++; goto L_after_00000df0; }
L_after_00000df0:
    blocks_done++;
    goto L_exit;
L_00000dfe:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000dfe[] = {0x05, 0x46, 0x00, 0xe0};
    if (memcmp(s->mem + s->bias + 3582u, expected_00000dfe, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 5, 0);
    instructions++;
    s->r[15] = (s->bias + 3588u); { instructions++; goto L_after_00000dfe; }
L_after_00000dfe:
    blocks_done++;
    if (regs[15] == s->bias + 3588u) goto L_00000e04;
    goto L_exit;
L_00000e02:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 3586u)) != 17973u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 5, 6);
    instructions++;
    regs[15] = s->bias + 3588u;
L_after_00000e02:
    blocks_done++;
    if (regs[15] == s->bias + 3588u) goto L_00000e04;
    goto L_exit;
L_00000e04:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000e04[] = {0x23, 0x68, 0x00, 0x22, 0x0b, 0x99, 0x20, 0x46, 0xd3, 0xf8, 0xe8, 0x32, 0x98, 0x47};
    if (memcmp(s->mem + s->bias + 3588u, expected_00000e04, 14u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000e04; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_movs_imm(s, 2, 0u);
    instructions++;
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 44u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000e04; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 0, 4);
    instructions++;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 744u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000e04; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_branch_reg(s, s->r[3], (s->bias + 3602u), 1); { instructions++; goto L_after_00000e04; }
L_after_00000e04:
    blocks_done++;
    goto L_exit;
L_00000e12:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000e12[] = {0x41, 0xf2, 0x06, 0x41, 0x00, 0x22, 0x3b, 0x46, 0x83, 0x46, 0x03, 0x20, 0xff, 0xf7, 0x74, 0xef};
    if (memcmp(s->mem + s->bias + 3602u, expected_00000e12, 16u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movw(s, 1, 5126u);
    instructions++;
    agr_aot_movs_imm(s, 2, 0u);
    instructions++;
    agr_aot_mov_reg(s, 3, 7);
    instructions++;
    agr_aot_mov_reg(s, 11, 0);
    instructions++;
    agr_aot_movs_imm(s, 0, 3u);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 3336u), (s->bias + 3618u), 1); { instructions++; goto L_after_00000e12; }
L_after_00000e12:
    blocks_done++;
    if (regs[15] == s->bias + 3336u) goto L_00000d08;
    goto L_exit;
L_00000e22:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000e22[] = {0x04, 0x20, 0x41, 0xf2, 0x06, 0x41, 0x00, 0x22, 0x4b, 0x46, 0xff, 0xf7, 0x72, 0xef};
    if (memcmp(s->mem + s->bias + 3618u, expected_00000e22, 14u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 4u);
    instructions++;
    agr_aot_movw(s, 1, 5126u);
    instructions++;
    agr_aot_movs_imm(s, 2, 0u);
    instructions++;
    agr_aot_mov_reg(s, 3, 9);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 3348u), (s->bias + 3632u), 1); { instructions++; goto L_after_00000e22; }
L_after_00000e22:
    blocks_done++;
    if (regs[15] == s->bias + 3348u) goto L_00000d14;
    goto L_exit;
L_00000e30:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 3632u)) != 45365u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = !s->r[5] ? (s->bias + 3648u) : (s->bias + 3634u); { instructions++; goto L_after_00000e30; }
L_after_00000e30:
    blocks_done++;
    if (regs[15] == s->bias + 3648u) goto L_00000e40;
    if (regs[15] == s->bias + 3634u) goto L_00000e32;
    goto L_exit;
L_00000e32:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000e32[] = {0x02, 0x20, 0x41, 0xf2, 0x0c, 0x41, 0x00, 0x22, 0x2b, 0x46, 0xff, 0xf7, 0x70, 0xef};
    if (memcmp(s->mem + s->bias + 3634u, expected_00000e32, 14u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 2u);
    instructions++;
    agr_aot_movw(s, 1, 5132u);
    instructions++;
    agr_aot_movs_imm(s, 2, 0u);
    instructions++;
    agr_aot_mov_reg(s, 3, 5);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 3360u), (s->bias + 3648u), 1); { instructions++; goto L_after_00000e32; }
L_after_00000e32:
    blocks_done++;
    if (regs[15] == s->bias + 3360u) goto L_00000d20;
    goto L_exit;
L_00000e40:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000e40[] = {0x04, 0x20, 0x0c, 0x99, 0x41, 0xf2, 0x03, 0x42, 0x5b, 0x46, 0xff, 0xf7, 0x70, 0xef};
    if (memcmp(s->mem + s->bias + 3648u, expected_00000e40, 14u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 4u);
    instructions++;
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 48u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000e40; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_movw(s, 2, 5123u);
    instructions++;
    agr_aot_mov_reg(s, 3, 11);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 3372u), (s->bias + 3662u), 1); { instructions++; goto L_after_00000e40; }
L_after_00000e40:
    blocks_done++;
    if (regs[15] == s->bias + 3372u) goto L_00000d2c;
    goto L_exit;
L_00000e4e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000e4e[] = {0x23, 0x68, 0x20, 0x46, 0x0b, 0x99, 0x5a, 0x46, 0xd3, 0xf8, 0x08, 0xc3, 0x00, 0x23, 0xe0, 0x47};
    if (memcmp(s->mem + s->bias + 3662u, expected_00000e4e, 16u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000e4e; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 0, 4);
    instructions++;
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 44u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000e4e; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 2, 11);
    instructions++;
    { int rc = agr_aot_ldr(s, 12, s->r[3] + 776u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000e4e; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_movs_imm(s, 3, 0u);
    instructions++;
    agr_aot_branch_reg(s, s->r[12], (s->bias + 3678u), 1); { instructions++; goto L_after_00000e4e; }
L_after_00000e4e:
    blocks_done++;
    goto L_exit;
L_00000e5e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 3678u)) != 45373u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = !s->r[5] ? (s->bias + 3696u) : (s->bias + 3680u); { instructions++; goto L_after_00000e5e; }
L_after_00000e5e:
    blocks_done++;
    if (regs[15] == s->bias + 3696u) goto L_00000e70;
    if (regs[15] == s->bias + 3680u) goto L_00000e60;
    goto L_exit;
L_00000e60:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000e60[] = {0x23, 0x68, 0x20, 0x46, 0x31, 0x46, 0x2a, 0x46, 0xd3, 0xf8, 0x0c, 0xc3, 0x00, 0x23, 0xe0, 0x47};
    if (memcmp(s->mem + s->bias + 3680u, expected_00000e60, 16u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000e60; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 0, 4);
    instructions++;
    agr_aot_mov_reg(s, 1, 6);
    instructions++;
    agr_aot_mov_reg(s, 2, 5);
    instructions++;
    { int rc = agr_aot_ldr(s, 12, s->r[3] + 780u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000e60; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_movs_imm(s, 3, 0u);
    instructions++;
    agr_aot_branch_reg(s, s->r[12], (s->bias + 3696u), 1); { instructions++; goto L_after_00000e60; }
L_after_00000e60:
    blocks_done++;
    goto L_exit;
L_00000e70:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000e70[] = {0x23, 0x68, 0x20, 0x46, 0x51, 0x46, 0x4a, 0x46, 0xd3, 0xf8, 0x14, 0x53, 0x00, 0x23, 0xa8, 0x47};
    if (memcmp(s->mem + s->bias + 3696u, expected_00000e70, 16u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000e70; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 0, 4);
    instructions++;
    agr_aot_mov_reg(s, 1, 10);
    instructions++;
    agr_aot_mov_reg(s, 2, 9);
    instructions++;
    { int rc = agr_aot_ldr(s, 5, s->r[3] + 788u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000e70; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_movs_imm(s, 3, 0u);
    instructions++;
    agr_aot_branch_reg(s, s->r[5], (s->bias + 3712u), 1); { instructions++; goto L_after_00000e70; }
L_after_00000e70:
    blocks_done++;
    goto L_exit;
L_00000e80:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000e80[] = {0x23, 0x68, 0x20, 0x46, 0x41, 0x46, 0x3a, 0x46, 0xd3, 0xf8, 0x14, 0x53, 0x00, 0x23, 0xa8, 0x47};
    if (memcmp(s->mem + s->bias + 3712u, expected_00000e80, 16u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000e80; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 0, 4);
    instructions++;
    agr_aot_mov_reg(s, 1, 8);
    instructions++;
    agr_aot_mov_reg(s, 2, 7);
    instructions++;
    { int rc = agr_aot_ldr(s, 5, s->r[3] + 788u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000e80; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_movs_imm(s, 3, 0u);
    instructions++;
    agr_aot_branch_reg(s, s->r[5], (s->bias + 3728u), 1); { instructions++; goto L_after_00000e80; }
L_after_00000e80:
    blocks_done++;
    goto L_exit;
L_00000e90:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 3728u)) != 59581u || agr_aot_load16(s, (s->bias + 3730u)) != 36856u) { result = AGR_AOT_MISS; goto L_exit; }
    if ((rc = agr_aot_ldmia_sp(s, 36856u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000e90; } result = rc; goto L_exit; }
    instructions++;
L_after_00000e90:
    blocks_done++;
    goto L_exit;
L_00000e94:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 3732u)) != 59693u || agr_aot_load16(s, (s->bias + 3734u)) != 17400u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 17400u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 3736u)) != 17951u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 7, 3);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 3738u)) != 26627u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000e94; } result = rc; goto L_exit; } }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 3740u)) != 18064u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 8, 2);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 3742u)) != 17937u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 1, 2);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 3744u)) != 8704u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 2, 0u);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 3746u)) != 17924u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 4, 0);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 3748u)) != 62017u || agr_aot_load16(s, (s->bias + 3750u)) != 18694u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movw(s, 9, 5126u);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 3752u)) != 63699u || agr_aot_load16(s, (s->bias + 3754u)) != 13044u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000e94; } result = rc; goto L_exit; } }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 3756u)) != 18328u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[3], (s->bias + 3758u), 1); { instructions++; goto L_after_00000e94; }
L_after_00000e94:
    blocks_done++;
    goto L_exit;
L_00000eae:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000eae[] = {0x23, 0x68, 0x39, 0x46, 0x00, 0x22, 0xd3, 0xf8, 0xf4, 0x32, 0x05, 0x46, 0x20, 0x46, 0x98, 0x47};
    if (memcmp(s->mem + s->bias + 3758u, expected_00000eae, 16u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000eae; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 1, 7);
    instructions++;
    agr_aot_movs_imm(s, 2, 0u);
    instructions++;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000eae; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 5, 0);
    instructions++;
    agr_aot_mov_reg(s, 0, 4);
    instructions++;
    agr_aot_branch_reg(s, s->r[3], (s->bias + 3774u), 1); { instructions++; goto L_after_00000eae; }
L_after_00000eae:
    blocks_done++;
    goto L_exit;
L_00000ebe:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000ebe[] = {0x49, 0x46, 0x2b, 0x46, 0x00, 0x22, 0x06, 0x46, 0x02, 0x20, 0xff, 0xf7, 0x1e, 0xef};
    if (memcmp(s->mem + s->bias + 3774u, expected_00000ebe, 14u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 1, 9);
    instructions++;
    agr_aot_mov_reg(s, 3, 5);
    instructions++;
    agr_aot_movs_imm(s, 2, 0u);
    instructions++;
    agr_aot_mov_reg(s, 6, 0);
    instructions++;
    agr_aot_movs_imm(s, 0, 2u);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 3336u), (s->bias + 3788u), 1); { instructions++; goto L_after_00000ebe; }
L_after_00000ebe:
    blocks_done++;
    if (regs[15] == s->bias + 3336u) goto L_00000d08;
    goto L_exit;
L_00000ecc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000ecc[] = {0x33, 0x46, 0x49, 0x46, 0x04, 0x20, 0x00, 0x22, 0xff, 0xf7, 0x1e, 0xef};
    if (memcmp(s->mem + s->bias + 3788u, expected_00000ecc, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 3, 6);
    instructions++;
    agr_aot_mov_reg(s, 1, 9);
    instructions++;
    agr_aot_movs_imm(s, 0, 4u);
    instructions++;
    agr_aot_movs_imm(s, 2, 0u);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 3348u), (s->bias + 3800u), 1); { instructions++; goto L_after_00000ecc; }
L_after_00000ecc:
    blocks_done++;
    if (regs[15] == s->bias + 3348u) goto L_00000d14;
    goto L_exit;
L_00000ed8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000ed8[] = {0x08, 0x9a, 0x01, 0x20, 0x00, 0x21, 0xff, 0xf7, 0x2c, 0xef};
    if (memcmp(s->mem + s->bias + 3800u, expected_00000ed8, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 2, s->r[13] + 32u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000ed8; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_movs_imm(s, 0, 1u);
    instructions++;
    agr_aot_movs_imm(s, 1, 0u);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 3384u), (s->bias + 3810u), 1); { instructions++; goto L_after_00000ed8; }
L_after_00000ed8:
    blocks_done++;
    if (regs[15] == s->bias + 3384u) goto L_00000d38;
    goto L_exit;
L_00000ee2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000ee2[] = {0x23, 0x68, 0x20, 0x46, 0x39, 0x46, 0x32, 0x46, 0xd3, 0xf8, 0x14, 0xc3, 0x00, 0x23, 0xe0, 0x47};
    if (memcmp(s->mem + s->bias + 3810u, expected_00000ee2, 16u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000ee2; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 0, 4);
    instructions++;
    agr_aot_mov_reg(s, 1, 7);
    instructions++;
    agr_aot_mov_reg(s, 2, 6);
    instructions++;
    { int rc = agr_aot_ldr(s, 12, s->r[3] + 788u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000ee2; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_movs_imm(s, 3, 0u);
    instructions++;
    agr_aot_branch_reg(s, s->r[12], (s->bias + 3826u), 1); { instructions++; goto L_after_00000ee2; }
L_after_00000ee2:
    blocks_done++;
    goto L_exit;
L_00000ef2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000ef2[] = {0x23, 0x68, 0x20, 0x46, 0x41, 0x46, 0x2a, 0x46, 0xd3, 0xf8, 0x14, 0x63, 0x00, 0x23, 0xb0, 0x47};
    if (memcmp(s->mem + s->bias + 3826u, expected_00000ef2, 16u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000ef2; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 0, 4);
    instructions++;
    agr_aot_mov_reg(s, 1, 8);
    instructions++;
    agr_aot_mov_reg(s, 2, 5);
    instructions++;
    { int rc = agr_aot_ldr(s, 6, s->r[3] + 788u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000ef2; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_movs_imm(s, 3, 0u);
    instructions++;
    agr_aot_branch_reg(s, s->r[6], (s->bias + 3842u), 1); { instructions++; goto L_after_00000ef2; }
L_after_00000ef2:
    blocks_done++;
    goto L_exit;
L_00000f02:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 3842u)) != 59581u || agr_aot_load16(s, (s->bias + 3844u)) != 33784u) { result = AGR_AOT_MISS; goto L_exit; }
    if ((rc = agr_aot_ldmia_sp(s, 33784u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000f02; } result = rc; goto L_exit; }
    instructions++;
L_after_00000f02:
    blocks_done++;
    goto L_exit;
L_00000f08:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 3848u)) != 26627u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000f08; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 3850u;
L_after_00000f08:
    blocks_done++;
    goto L_exit;
L_00000f1a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 3866u)) != 59693u || agr_aot_load16(s, (s->bias + 3868u)) != 20471u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 20471u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 3870u)) != 18049u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 9, 0);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 3872u)) != 17942u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 6, 2);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 3874u)) != 45857u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = !s->r[1] ? (s->bias + 3950u) : (s->bias + 3876u); { instructions++; goto L_after_00000f1a; }
L_after_00000f1a:
    blocks_done++;
    if (regs[15] == s->bias + 3950u) goto L_00000f6e;
    if (regs[15] == s->bias + 3876u) goto L_00000f24;
    goto L_exit;
L_00000f24:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000f24[] = {0x01, 0xf1, 0xff, 0x38, 0x00, 0x27, 0xc2, 0x46};
    if (memcmp(s->mem + s->bias + 3876u, expected_00000f24, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 8, s->r[1], 1023u);
    instructions++;
    agr_aot_movs_imm(s, 7, 0u);
    instructions++;
    agr_aot_mov_reg(s, 10, 8);
    instructions++;
    regs[15] = s->bias + 3884u;
L_after_00000f24:
    blocks_done++;
    goto L_exit;
L_00000f3e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000f3e[] = {0x28, 0x46, 0xff, 0xf7, 0xe2, 0xff};
    if (memcmp(s->mem + s->bias + 3902u, expected_00000f3e, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 3848u) | 1u, (s->bias + 3908u), 1); { instructions++; goto L_after_00000f3e; }
L_after_00000f3e:
    blocks_done++;
    if (regs[15] == s->bias + 3848u) goto L_00000f08;
    goto L_exit;
L_00000f46:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000f46[] = {0x01, 0x9b, 0x83, 0x46};
    if (memcmp(s->mem + s->bias + 3910u, expected_00000f46, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 4u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000f46; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 11, 0);
    instructions++;
    regs[15] = s->bias + 3914u;
L_after_00000f46:
    blocks_done++;
    goto L_exit;
L_00000f4c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 3916u)) != 61699u || agr_aot_load16(s, (s->bias + 3918u)) != 8u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 0, s->r[3], 8u);
    instructions++;
    regs[15] = s->bias + 3920u;
L_after_00000f4c:
    blocks_done++;
    goto L_exit;
L_00000f52:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 3922u)) != 63487u || agr_aot_load16(s, (s->bias + 3924u)) != 65497u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 3848u) | 1u, (s->bias + 3926u), 1); { instructions++; goto L_after_00000f52; }
L_after_00000f52:
    blocks_done++;
    if (regs[15] == s->bias + 3848u) goto L_00000f08;
    goto L_exit;
L_00000f5e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000f5e[] = {0x04, 0xf1, 0xff, 0x3a, 0xe3, 0xe7};
    if (memcmp(s->mem + s->bias + 3934u, expected_00000f5e, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 10, s->r[4], 1023u);
    instructions++;
    s->r[15] = (s->bias + 3884u); { instructions++; goto L_after_00000f5e; }
L_after_00000f5e:
    blocks_done++;
    goto L_exit;
L_00000f6c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 3948u)) != 59358u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 3884u); { instructions++; goto L_after_00000f6c; }
L_after_00000f6c:
    blocks_done++;
    goto L_exit;
L_00000f6e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000f6e[] = {0x0d, 0x46, 0x03, 0xe0};
    if (memcmp(s->mem + s->bias + 3950u, expected_00000f6e, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 5, 1);
    instructions++;
    s->r[15] = (s->bias + 3962u); { instructions++; goto L_after_00000f6e; }
L_after_00000f6e:
    blocks_done++;
    if (regs[15] == s->bias + 3962u) goto L_00000f7a;
    goto L_exit;
L_00000f72:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000f72[] = {0x00, 0x25, 0x01, 0xe0};
    if (memcmp(s->mem + s->bias + 3954u, expected_00000f72, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 5, 0u);
    instructions++;
    s->r[15] = (s->bias + 3962u); { instructions++; goto L_after_00000f72; }
L_after_00000f72:
    blocks_done++;
    if (regs[15] == s->bias + 3962u) goto L_00000f7a;
    goto L_exit;
L_00000f7a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 3962u)) != 17960u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    regs[15] = s->bias + 3964u;
L_after_00000f7a:
    blocks_done++;
    goto L_exit;
L_00000f7e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 3966u)) != 59581u || agr_aot_load16(s, (s->bias + 3968u)) != 36848u) { result = AGR_AOT_MISS; goto L_exit; }
    if ((rc = agr_aot_ldmia_sp(s, 36848u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000f7e; } result = rc; goto L_exit; }
    instructions++;
L_after_00000f7e:
    blocks_done++;
    goto L_exit;
L_00000f8a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 3978u)) != 47448u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = s->r[0] ? (s->bias + 4004u) : (s->bias + 3980u); { instructions++; goto L_after_00000f8a; }
L_after_00000f8a:
    blocks_done++;
    if (regs[15] == s->bias + 4004u) goto L_00000fa4;
    if (regs[15] == s->bias + 3980u) goto L_00000f8c;
    goto L_exit;
L_00000f8c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 3980u)) != 18438u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 0, (s->bias + 3984u) + 24u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000f8c; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 3982u;
L_after_00000f8c:
    blocks_done++;
    goto L_exit;
L_00000f90:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000f90[] = {0x00, 0x68, 0x70, 0x47};
    if (memcmp(s->mem + s->bias + 3984u, expected_00000f90, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000f90; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00000f90; }
L_after_00000f90:
    blocks_done++;
    goto L_exit;
L_00000f94:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 3988u)) != 18437u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 0, (s->bias + 3992u) + 20u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000f94; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 3990u;
L_after_00000f94:
    blocks_done++;
    goto L_exit;
L_00000f98:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000f98[] = {0x00, 0x68, 0x70, 0x47};
    if (memcmp(s->mem + s->bias + 3992u, expected_00000f98, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000f98; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00000f98; }
L_after_00000f98:
    blocks_done++;
    goto L_exit;
L_00000f9c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 3996u)) != 18436u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 0, (s->bias + 4000u) + 16u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000f9c; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 3998u;
L_after_00000f9c:
    blocks_done++;
    goto L_exit;
L_00000fa0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000fa0[] = {0x00, 0x68, 0x70, 0x47};
    if (memcmp(s->mem + s->bias + 4000u, expected_00000fa0, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000fa0; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00000fa0; }
L_after_00000fa0:
    blocks_done++;
    goto L_exit;
L_00000fa4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000fa4[] = {0x00, 0x20, 0x70, 0x47};
    if (memcmp(s->mem + s->bias + 4004u, expected_00000fa4, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 0u);
    instructions++;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00000fa4; }
L_after_00000fa4:
    blocks_done++;
    goto L_exit;
L_00000fa8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4008u)) != 8214u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 22u);
    instructions++;
    regs[15] = s->bias + 4010u;
L_after_00000fa8:
    blocks_done++;
    goto L_exit;
L_00000fac:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4012u)) != 8210u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 18u);
    instructions++;
    regs[15] = s->bias + 4014u;
L_after_00000fac:
    blocks_done++;
    goto L_exit;
L_00000fb0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4016u)) != 8206u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 14u);
    instructions++;
    regs[15] = s->bias + 4018u;
L_after_00000fb0:
    blocks_done++;
    goto L_exit;
L_00000fb4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4020u)) != 19237u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, (s->bias + 4024u) + 148u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000fb4; } result = rc; goto L_exit; } }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 4022u)) != 46451u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16499u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 4024u;
L_after_00000fb4:
    blocks_done++;
    goto L_exit;
L_00000fba:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000fba[] = {0x1b, 0x68, 0x04, 0x46};
    if (memcmp(s->mem + s->bias + 4026u, expected_00000fba, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000fba; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 4, 0);
    instructions++;
    regs[15] = s->bias + 4030u;
L_after_00000fba:
    blocks_done++;
    goto L_exit;
L_00000fc0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4032u)) != 45363u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = !s->r[3] ? (s->bias + 4048u) : (s->bias + 4034u); { instructions++; goto L_after_00000fc0; }
L_after_00000fc0:
    blocks_done++;
    goto L_exit;
L_exit:
    memcpy(outer->r, regs, sizeof(regs));
    *outer->cpsr = cpsr;
    outer->region_blocks = blocks_done;
    outer->region_instructions = instructions;
    return result;
}

static int agr_region_00001(AgrAotRegs *outer) {
    uint32_t regs[16];
    memcpy(regs, outer->r, sizeof(regs));
    uint32_t cpsr = *outer->cpsr;
    AgrAotRegs local = {regs, &cpsr, outer->mem, outer->bias, 0, 0, 0};
    AgrAotRegs *s = &local;
    uint32_t blocks_done = 0, instructions = 0;
    int rc = 0, result = AGR_AOT_BOUNDARY;
    (void)rc;
    switch (regs[15] - s->bias) {
    case 4034u: goto L_00000fc2;
    case 4042u: goto L_00000fca;
    case 4046u: goto L_00000fce;
    case 4048u: goto L_00000fd0;
    case 4054u: goto L_00000fd6;
    case 4058u: goto L_00000fda;
    case 4062u: goto L_00000fde;
    case 4068u: goto L_00000fe4;
    case 4076u: goto L_00000fec;
    case 4082u: goto L_00000ff2;
    case 4086u: goto L_00000ff6;
    case 4090u: goto L_00000ffa;
    case 4098u: goto L_00001002;
    case 4104u: goto L_00001008;
    case 4108u: goto L_0000100c;
    case 4116u: goto L_00001014;
    case 4120u: goto L_00001018;
    case 4124u: goto L_0000101c;
    case 4128u: goto L_00001020;
    case 4132u: goto L_00001024;
    case 4142u: goto L_0000102e;
    case 4158u: goto L_0000103e;
    case 4164u: goto L_00001044;
    case 4168u: goto L_00001048;
    case 4184u: goto L_00001058;
    case 4198u: goto L_00001066;
    case 4204u: goto L_0000106c;
    case 4208u: goto L_00001070;
    case 4210u: goto L_00001072;
    case 4214u: goto L_00001076;
    case 4220u: goto L_0000107c;
    case 4228u: goto L_00001084;
    case 4234u: goto L_0000108a;
    case 4242u: goto L_00001092;
    case 4248u: goto L_00001098;
    case 4260u: goto L_000010a4;
    case 4262u: goto L_000010a6;
    case 4268u: goto L_000010ac;
    case 4270u: goto L_000010ae;
    case 4274u: goto L_000010b2;
    case 4278u: goto L_000010b6;
    case 4280u: goto L_000010b8;
    case 4286u: goto L_000010be;
    case 4294u: goto L_000010c6;
    case 4298u: goto L_000010ca;
    case 4302u: goto L_000010ce;
    case 4312u: goto L_000010d8;
    case 4324u: goto L_000010e4;
    case 4334u: goto L_000010ee;
    case 4338u: goto L_000010f2;
    case 4344u: goto L_000010f8;
    case 4362u: goto L_0000110a;
    case 4380u: goto L_0000111c;
    case 4386u: goto L_00001122;
    case 4392u: goto L_00001128;
    case 4532u: goto L_000011b4;
    case 4536u: goto L_000011b8;
    case 4546u: goto L_000011c2;
    case 4554u: goto L_000011ca;
    case 4576u: goto L_000011e0;
    case 4582u: goto L_000011e6;
    case 4592u: goto L_000011f0;
    case 4594u: goto L_000011f2;
    case 4604u: goto L_000011fc;
    default: result = AGR_AOT_MISS; goto L_exit;
    }
L_00000fc2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000fc2[] = {0x30, 0x46, 0x01, 0xa9, 0xff, 0xf7, 0xbe, 0xee};
    if (memcmp(s->mem + s->bias + 4034u, expected_00000fc2, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 6);
    instructions++;
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 3396u), (s->bias + 4042u), 1); { instructions++; goto L_after_00000fc2; }
L_after_00000fc2:
    blocks_done++;
    goto L_exit;
L_00000fca:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000fca[] = {0x05, 0x46, 0x55, 0xb9};
    if (memcmp(s->mem + s->bias + 4042u, expected_00000fca, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 5, 0);
    instructions++;
    s->r[15] = s->r[5] ? (s->bias + 4068u) : (s->bias + 4046u); { instructions++; goto L_after_00000fca; }
L_after_00000fca:
    blocks_done++;
    if (regs[15] == s->bias + 4068u) goto L_00000fe4;
    if (regs[15] == s->bias + 4046u) goto L_00000fce;
    goto L_exit;
L_00000fce:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4046u)) != 57359u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 4080u); { instructions++; goto L_after_00000fce; }
L_after_00000fce:
    blocks_done++;
    goto L_exit;
L_00000fd0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000fd0[] = {0x1f, 0x4d, 0x20, 0x4b};
    if (memcmp(s->mem + s->bias + 4048u, expected_00000fd0, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 5, (s->bias + 4052u) + 124u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000fd0; } result = rc; goto L_exit; } }
    instructions++;
    { int rc = agr_aot_ldr(s, 3, (s->bias + 4052u) + 128u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000fd0; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 4052u;
L_after_00000fd0:
    blocks_done++;
    goto L_exit;
L_00000fd6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4054u)) != 26669u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 5, s->r[5] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000fd6; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 4056u;
L_after_00000fd6:
    blocks_done++;
    goto L_exit;
L_00000fda:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4058u)) != 26651u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000fda; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 4060u;
L_after_00000fda:
    blocks_done++;
    goto L_exit;
L_00000fde:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4062u)) != 17944u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 3);
    instructions++;
    regs[15] = s->bias + 4064u;
L_after_00000fde:
    blocks_done++;
    goto L_exit;
L_00000fe4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000fe4[] = {0x01, 0x99, 0x32, 0x46, 0xff, 0xf7, 0x97, 0xff};
    if (memcmp(s->mem + s->bias + 4068u, expected_00000fe4, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 1, s->r[13] + 4u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000fe4; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 2, 6);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 3866u) | 1u, (s->bias + 4076u), 1); { instructions++; goto L_after_00000fe4; }
L_after_00000fe4:
    blocks_done++;
    goto L_exit;
L_00000fec:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000fec[] = {0x05, 0x46, 0x10, 0xb9};
    if (memcmp(s->mem + s->bias + 4076u, expected_00000fec, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 5, 0);
    instructions++;
    s->r[15] = s->r[0] ? (s->bias + 4086u) : (s->bias + 4080u); { instructions++; goto L_after_00000fec; }
L_after_00000fec:
    blocks_done++;
    if (regs[15] == s->bias + 4086u) goto L_00000ff6;
    goto L_exit;
L_00000ff2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00000ff2[] = {0x09, 0x20, 0x27, 0xe0};
    if (memcmp(s->mem + s->bias + 4082u, expected_00000ff2, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 9u);
    instructions++;
    s->r[15] = (s->bias + 4166u); { instructions++; goto L_after_00000ff2; }
L_after_00000ff2:
    blocks_done++;
    goto L_exit;
L_00000ff6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4086u)) != 63487u || agr_aot_load16(s, (s->bias + 4088u)) != 65415u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 3848u) | 1u, (s->bias + 4090u), 1); { instructions++; goto L_after_00000ff6; }
L_after_00000ff6:
    blocks_done++;
    goto L_exit;
L_00000ffa:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4090u)) != 26731u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 4u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000ffa; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 4092u;
L_after_00000ffa:
    blocks_done++;
    goto L_exit;
L_00001002:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001002[] = {0x00, 0x23, 0x05, 0x20};
    if (memcmp(s->mem + s->bias + 4098u, expected_00001002, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 3, 0u);
    instructions++;
    agr_aot_movs_imm(s, 0, 5u);
    instructions++;
    regs[15] = s->bias + 4102u;
L_after_00001002:
    blocks_done++;
    goto L_exit;
L_00001008:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4104u)) != 57373u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 4166u); { instructions++; goto L_after_00001008; }
L_after_00001008:
    blocks_done++;
    goto L_exit;
L_0000100c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4108u)) != 61701u || agr_aot_load16(s, (s->bias + 4110u)) != 4u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 0, s->r[5], 4u);
    instructions++;
    regs[15] = s->bias + 4112u;
L_after_0000100c:
    blocks_done++;
    goto L_exit;
L_00001014:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001014[] = {0x01, 0x23, 0x03, 0xe0};
    if (memcmp(s->mem + s->bias + 4116u, expected_00001014, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 3, 1u);
    instructions++;
    s->r[15] = (s->bias + 4128u); { instructions++; goto L_after_00001014; }
L_after_00001014:
    blocks_done++;
    if (regs[15] == s->bias + 4128u) goto L_00001020;
    goto L_exit;
L_00001018:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4120u)) != 63487u || agr_aot_load16(s, (s->bias + 4122u)) != 65398u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 3848u) | 1u, (s->bias + 4124u), 1); { instructions++; goto L_after_00001018; }
L_after_00001018:
    blocks_done++;
    goto L_exit;
L_0000101c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4124u)) != 8960u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 3, 0u);
    instructions++;
    regs[15] = s->bias + 4126u;
L_after_0000101c:
    blocks_done++;
    goto L_exit;
L_00001020:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4128u)) != 27872u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 0, s->r[4] + 76u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001020; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 4130u;
L_after_00001020:
    blocks_done++;
    goto L_exit;
L_00001024:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4132u)) != 26627u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001024; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 4134u;
L_after_00001024:
    blocks_done++;
    goto L_exit;
L_0000102e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4142u)) != 63487u || agr_aot_load16(s, (s->bias + 4144u)) != 65448u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 3970u) | 1u, (s->bias + 4146u), 1); { instructions++; goto L_after_0000102e; }
L_after_0000102e:
    blocks_done++;
    goto L_exit;
L_0000103e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4158u)) != 63487u || agr_aot_load16(s, (s->bias + 4160u)) != 65379u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 3848u) | 1u, (s->bias + 4162u), 1); { instructions++; goto L_after_0000103e; }
L_after_0000103e:
    blocks_done++;
    goto L_exit;
L_00001044:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4164u)) != 8192u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 0u);
    instructions++;
    regs[15] = s->bias + 4166u;
L_after_00001044:
    blocks_done++;
    goto L_exit;
L_00001048:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4168u)) != 48496u) { result = AGR_AOT_MISS; goto L_exit; }
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001048; } result = rc; goto L_exit; }
    instructions++;
L_after_00001048:
    blocks_done++;
    goto L_exit;
L_00001058:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4184u)) != 26627u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001058; } result = rc; goto L_exit; } }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 4186u)) != 46352u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16400u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 4188u)) != 17924u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 4, 0);
    instructions++;
    regs[15] = s->bias + 4190u;
L_after_00001058:
    blocks_done++;
    goto L_exit;
L_00001066:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4198u)) != 61700u || agr_aot_load16(s, (s->bias + 4200u)) != 72u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 0, s->r[4], 72u);
    instructions++;
    regs[15] = s->bias + 4202u;
L_after_00001066:
    blocks_done++;
    goto L_exit;
L_0000106c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4204u)) != 61440u || agr_aot_load16(s, (s->bias + 4206u)) != 64514u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 6260u) | 1u, (s->bias + 4208u), 1); { instructions++; goto L_after_0000106c; }
L_after_0000106c:
    blocks_done++;
    goto L_exit;
L_00001070:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4208u)) != 57345u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 4214u); { instructions++; goto L_after_00001070; }
L_after_00001070:
    blocks_done++;
    if (regs[15] == s->bias + 4214u) goto L_00001076;
    goto L_exit;
L_00001072:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4210u)) != 61440u || agr_aot_load16(s, (s->bias + 4212u)) != 64503u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 6244u) | 1u, (s->bias + 4214u), 1); { instructions++; goto L_after_00001072; }
L_after_00001072:
    blocks_done++;
    goto L_exit;
L_00001076:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4214u)) != 26659u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001076; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 4216u;
L_after_00001076:
    blocks_done++;
    goto L_exit;
L_0000107c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_0000107c[] = {0x04, 0xf1, 0xd0, 0x00, 0x00, 0xf0, 0x00, 0xfc};
    if (memcmp(s->mem + s->bias + 4220u, expected_0000107c, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 0, s->r[4], 208u);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 6276u) | 1u, (s->bias + 4228u), 1); { instructions++; goto L_after_0000107c; }
L_after_0000107c:
    blocks_done++;
    goto L_exit;
L_00001084:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4228u)) != 26659u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001084; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 4230u;
L_after_00001084:
    blocks_done++;
    goto L_exit;
L_0000108a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_0000108a[] = {0x04, 0xf5, 0xa8, 0x70, 0x00, 0xf0, 0x01, 0xfc};
    if (memcmp(s->mem + s->bias + 4234u, expected_0000108a, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 0, s->r[4], 4008u);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 6292u) | 1u, (s->bias + 4242u), 1); { instructions++; goto L_after_0000108a; }
L_after_0000108a:
    blocks_done++;
    goto L_exit;
L_00001092:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4242u)) != 26659u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001092; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 4244u;
L_after_00001092:
    blocks_done++;
    goto L_exit;
L_00001098:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001098[] = {0x04, 0xf5, 0xe8, 0x70, 0xbd, 0xe8, 0x10, 0x40, 0x00, 0xf0, 0x3c, 0xbc};
    if (memcmp(s->mem + s->bias + 4248u, expected_00001098, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 0, s->r[4], 4072u);
    instructions++;
    if ((rc = agr_aot_ldmia_sp(s, 16400u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001098; } result = rc; goto L_exit; }
    instructions++;
    s->r[15] = (s->bias + 6428u); { instructions++; goto L_after_00001098; }
L_after_00001098:
    blocks_done++;
    goto L_exit;
L_000010a4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4260u)) != 48400u) { result = AGR_AOT_MISS; goto L_exit; }
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000010a4; } result = rc; goto L_exit; }
    instructions++;
L_after_000010a4:
    blocks_done++;
    goto L_exit;
L_000010a6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_000010a6[] = {0x03, 0x68, 0x0b, 0xb1};
    if (memcmp(s->mem + s->bias + 4262u, expected_000010a6, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000010a6; } result = rc; goto L_exit; } }
    instructions++;
    s->r[15] = !s->r[3] ? (s->bias + 4270u) : (s->bias + 4266u); { instructions++; goto L_after_000010a6; }
L_after_000010a6:
    blocks_done++;
    if (regs[15] == s->bias + 4270u) goto L_000010ae;
    goto L_exit;
L_000010ac:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4268u)) != 18288u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_000010ac; }
L_after_000010ac:
    blocks_done++;
    goto L_exit;
L_000010ae:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_000010ae[] = {0x18, 0x46, 0x70, 0x47};
    if (memcmp(s->mem + s->bias + 4270u, expected_000010ae, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 3);
    instructions++;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_000010ae; }
L_after_000010ae:
    blocks_done++;
    goto L_exit;
L_000010b2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_000010b2[] = {0x09, 0x20, 0x70, 0x47};
    if (memcmp(s->mem + s->bias + 4274u, expected_000010b2, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 9u);
    instructions++;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_000010b2; }
L_after_000010b2:
    blocks_done++;
    goto L_exit;
L_000010b6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4278u)) != 18288u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_000010b6; }
L_after_000010b6:
    blocks_done++;
    goto L_exit;
L_000010b8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4280u)) != 46448u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16496u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 4282u)) != 17925u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 5, 0);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 4284u)) != 17932u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 4, 1);
    instructions++;
    regs[15] = s->bias + 4286u;
L_after_000010b8:
    blocks_done++;
    if (regs[15] == s->bias + 4286u) goto L_000010be;
    goto L_exit;
L_000010be:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_000010be[] = {0x28, 0x46, 0x21, 0x6c, 0xff, 0xf7, 0x77, 0xff};
    if (memcmp(s->mem + s->bias + 4286u, expected_000010be, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 64u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000010be; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4020u) | 1u, (s->bias + 4294u), 1); { instructions++; goto L_after_000010be; }
L_after_000010be:
    blocks_done++;
    goto L_exit;
L_000010c6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_000010c6[] = {0x06, 0x46, 0x08, 0xb1};
    if (memcmp(s->mem + s->bias + 4294u, expected_000010c6, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 6, 0);
    instructions++;
    s->r[15] = !s->r[0] ? (s->bias + 4302u) : (s->bias + 4298u); { instructions++; goto L_after_000010c6; }
L_after_000010c6:
    blocks_done++;
    if (regs[15] == s->bias + 4302u) goto L_000010ce;
    if (regs[15] == s->bias + 4298u) goto L_000010ca;
    goto L_exit;
L_000010ca:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4298u)) != 63487u || agr_aot_load16(s, (s->bias + 4300u)) != 60994u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 3408u), (s->bias + 4302u), 1); { instructions++; goto L_after_000010ca; }
L_after_000010ca:
    blocks_done++;
    goto L_exit;
L_000010ce:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_000010ce[] = {0x23, 0x6c, 0x01, 0x20, 0x29, 0x46, 0x22, 0x46};
    if (memcmp(s->mem + s->bias + 4302u, expected_000010ce, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 64u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000010ce; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_movs_imm(s, 0, 1u);
    instructions++;
    agr_aot_mov_reg(s, 1, 5);
    instructions++;
    agr_aot_mov_reg(s, 2, 4);
    instructions++;
    regs[15] = s->bias + 4310u;
L_after_000010ce:
    blocks_done++;
    goto L_exit;
L_000010d8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_000010d8[] = {0x2b, 0x69, 0x98, 0x47};
    if (memcmp(s->mem + s->bias + 4312u, expected_000010d8, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 16u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000010d8; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_branch_reg(s, s->r[3], (s->bias + 4316u), 1); { instructions++; goto L_after_000010d8; }
L_after_000010d8:
    blocks_done++;
    goto L_exit;
L_000010e4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_000010e4[] = {0x30, 0x46, 0x21, 0x6c, 0xff, 0xf7, 0xe5, 0xff};
    if (memcmp(s->mem + s->bias + 4324u, expected_000010e4, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 6);
    instructions++;
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 64u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000010e4; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4278u) | 1u, (s->bias + 4332u), 1); { instructions++; goto L_after_000010e4; }
L_after_000010e4:
    blocks_done++;
    if (regs[15] == s->bias + 4278u) goto L_000010b6;
    goto L_exit;
L_000010ee:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4334u)) != 61440u || agr_aot_load16(s, (s->bias + 4336u)) != 64429u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 6220u) | 1u, (s->bias + 4338u), 1); { instructions++; goto L_after_000010ee; }
L_after_000010ee:
    blocks_done++;
    goto L_exit;
L_000010f2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4338u)) != 59693u || agr_aot_load16(s, (s->bias + 4340u)) != 20464u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 20464u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 4342u;
L_after_000010f2:
    blocks_done++;
    goto L_exit;
L_000010f8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_000010f8[] = {0xd0, 0xf8, 0x0c, 0x80, 0x07, 0x46, 0xd0, 0xf8, 0x18, 0x90, 0x92, 0x46};
    if (memcmp(s->mem + s->bias + 4344u, expected_000010f8, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 8, s->r[0] + 12u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000010f8; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 7, 0);
    instructions++;
    { int rc = agr_aot_ldr(s, 9, s->r[0] + 24u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000010f8; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 10, 2);
    instructions++;
    regs[15] = s->bias + 4356u;
L_after_000010f8:
    blocks_done++;
    goto L_exit;
L_0000110a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_0000110a[] = {0x03, 0xac, 0x02, 0xae};
    if (memcmp(s->mem + s->bias + 4362u, expected_0000110a, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 4, s->r[13], 12u);
    instructions++;
    agr_aot_add_imm(s, 6, s->r[13], 8u);
    instructions++;
    regs[15] = s->bias + 4366u;
L_after_0000110a:
    blocks_done++;
    goto L_exit;
L_0000111c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4380u)) != 44410u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 5, s->r[13], 488u);
    instructions++;
    regs[15] = s->bias + 4382u;
L_after_0000111c:
    blocks_done++;
    goto L_exit;
L_00001122:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001122[] = {0x00, 0x23, 0x9b, 0x46};
    if (memcmp(s->mem + s->bias + 4386u, expected_00001122, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 3, 0u);
    instructions++;
    agr_aot_mov_reg(s, 11, 3);
    instructions++;
    regs[15] = s->bias + 4390u;
L_after_00001122:
    blocks_done++;
    goto L_exit;
L_00001128:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001128[] = {0x38, 0x46, 0x31, 0x6c, 0xff, 0xf7, 0x42, 0xff};
    if (memcmp(s->mem + s->bias + 4392u, expected_00001128, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 7);
    instructions++;
    { int rc = agr_aot_ldr(s, 1, s->r[6] + 64u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001128; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4020u) | 1u, (s->bias + 4400u), 1); { instructions++; goto L_after_00001128; }
L_after_00001128:
    blocks_done++;
    goto L_exit;
L_000011b4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_000011b4[] = {0x40, 0x6c, 0x70, 0x47};
    if (memcmp(s->mem + s->bias + 4532u, expected_000011b4, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 68u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000011b4; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_000011b4; }
L_after_000011b4:
    blocks_done++;
    goto L_exit;
L_000011b8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4536u)) != 27595u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[1] + 60u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000011b8; } result = rc; goto L_exit; } }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 4538u)) != 59693u || agr_aot_load16(s, (s->bias + 4540u)) != 16880u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16880u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 4542u;
L_after_000011b8:
    blocks_done++;
    goto L_exit;
L_000011c2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_000011c2[] = {0x07, 0x46, 0x0e, 0x46};
    if (memcmp(s->mem + s->bias + 4546u, expected_000011c2, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 7, 0);
    instructions++;
    agr_aot_mov_reg(s, 6, 1);
    instructions++;
    regs[15] = s->bias + 4550u;
L_after_000011c2:
    blocks_done++;
    goto L_exit;
L_000011ca:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_000011ca[] = {0x01, 0xac, 0xe8, 0x46};
    if (memcmp(s->mem + s->bias + 4554u, expected_000011ca, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 4, s->r[13], 4u);
    instructions++;
    agr_aot_mov_reg(s, 8, 13);
    instructions++;
    regs[15] = s->bias + 4558u;
L_after_000011ca:
    blocks_done++;
    goto L_exit;
L_000011e0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4576u)) != 61519u || agr_aot_load16(s, (s->bias + 4578u)) != 13311u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[3] = 4294967295u;
    instructions++;
    regs[15] = s->bias + 4580u;
L_after_000011e0:
    blocks_done++;
    goto L_exit;
L_000011e6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_000011e6[] = {0x38, 0x46, 0xd8, 0xf8, 0x40, 0x10, 0xff, 0xf7, 0xe2, 0xfe};
    if (memcmp(s->mem + s->bias + 4582u, expected_000011e6, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 7);
    instructions++;
    { int rc = agr_aot_ldr(s, 1, s->r[8] + 64u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000011e6; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4020u) | 1u, (s->bias + 4592u), 1); { instructions++; goto L_after_000011e6; }
L_after_000011e6:
    blocks_done++;
    goto L_exit;
L_000011f0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4592u)) != 47480u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = s->r[0] ? (s->bias + 4626u) : (s->bias + 4594u); { instructions++; goto L_after_000011f0; }
L_after_000011f0:
    blocks_done++;
    if (regs[15] == s->bias + 4594u) goto L_000011f2;
    goto L_exit;
L_000011f2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_000011f2[] = {0x3b, 0x69, 0x39, 0x46, 0x6a, 0x46, 0x98, 0x47};
    if (memcmp(s->mem + s->bias + 4594u, expected_000011f2, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[7] + 16u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000011f2; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 1, 7);
    instructions++;
    agr_aot_mov_reg(s, 2, 13);
    instructions++;
    agr_aot_branch_reg(s, s->r[3], (s->bias + 4602u), 1); { instructions++; goto L_after_000011f2; }
L_after_000011f2:
    blocks_done++;
    goto L_exit;
L_000011fc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4604u)) != 17924u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 4, 0);
    instructions++;
    regs[15] = s->bias + 4606u;
L_after_000011fc:
    blocks_done++;
    goto L_exit;
L_exit:
    memcpy(outer->r, regs, sizeof(regs));
    *outer->cpsr = cpsr;
    outer->region_blocks = blocks_done;
    outer->region_instructions = instructions;
    return result;
}

static int agr_region_00002(AgrAotRegs *outer) {
    uint32_t regs[16];
    memcpy(regs, outer->r, sizeof(regs));
    uint32_t cpsr = *outer->cpsr;
    AgrAotRegs local = {regs, &cpsr, outer->mem, outer->bias, 0, 0, 0};
    AgrAotRegs *s = &local;
    uint32_t blocks_done = 0, instructions = 0;
    int rc = 0, result = AGR_AOT_BOUNDARY;
    (void)rc;
    switch (regs[15] - s->bias) {
    case 4608u: goto L_00001200;
    case 4618u: goto L_0000120a;
    case 4626u: goto L_00001212;
    case 4630u: goto L_00001216;
    case 4634u: goto L_0000121a;
    case 4638u: goto L_0000121e;
    case 4642u: goto L_00001222;
    case 4650u: goto L_0000122a;
    case 4654u: goto L_0000122e;
    case 4666u: goto L_0000123a;
    case 4668u: goto L_0000123c;
    case 4674u: goto L_00001242;
    case 4676u: goto L_00001244;
    case 4694u: goto L_00001256;
    case 4702u: goto L_0000125e;
    case 4712u: goto L_00001268;
    case 4716u: goto L_0000126c;
    case 4720u: goto L_00001270;
    case 4724u: goto L_00001274;
    case 4728u: goto L_00001278;
    case 4732u: goto L_0000127c;
    case 4736u: goto L_00001280;
    case 4738u: goto L_00001282;
    case 4746u: goto L_0000128a;
    case 4750u: goto L_0000128e;
    case 4752u: goto L_00001290;
    case 4768u: goto L_000012a0;
    case 4792u: goto L_000012b8;
    case 4796u: goto L_000012bc;
    case 4806u: goto L_000012c6;
    case 4812u: goto L_000012cc;
    case 4820u: goto L_000012d4;
    case 4836u: goto L_000012e4;
    case 4860u: goto L_000012fc;
    case 4864u: goto L_00001300;
    case 4876u: goto L_0000130c;
    case 4880u: goto L_00001310;
    case 4888u: goto L_00001318;
    case 4890u: goto L_0000131a;
    case 4900u: goto L_00001324;
    case 4910u: goto L_0000132e;
    case 4932u: goto L_00001344;
    case 4940u: goto L_0000134c;
    case 4948u: goto L_00001354;
    case 4950u: goto L_00001356;
    case 4954u: goto L_0000135a;
    case 4964u: goto L_00001364;
    case 4974u: goto L_0000136e;
    case 4986u: goto L_0000137a;
    case 4994u: goto L_00001382;
    case 4996u: goto L_00001384;
    case 5002u: goto L_0000138a;
    case 5012u: goto L_00001394;
    case 5022u: goto L_0000139e;
    case 5032u: goto L_000013a8;
    case 5040u: goto L_000013b0;
    case 5050u: goto L_000013ba;
    case 5056u: goto L_000013c0;
    case 5074u: goto L_000013d2;
    case 5088u: goto L_000013e0;
    case 5660u: goto L_0000161c;
    case 5664u: goto L_00001620;
    case 5668u: goto L_00001624;
    case 5672u: goto L_00001628;
    default: result = AGR_AOT_MISS; goto L_exit;
    }
L_00001200:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001200[] = {0x68, 0x46, 0xff, 0xf7, 0x29, 0xff};
    if (memcmp(s->mem + s->bias + 4608u, expected_00001200, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 13);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4184u) | 1u, (s->bias + 4614u), 1); { instructions++; goto L_after_00001200; }
L_after_00001200:
    blocks_done++;
    goto L_exit;
L_0000120a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_0000120a[] = {0x38, 0x46, 0x31, 0x46, 0xff, 0xf7, 0x53, 0xff};
    if (memcmp(s->mem + s->bias + 4618u, expected_0000120a, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 7);
    instructions++;
    agr_aot_mov_reg(s, 1, 6);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4280u) | 1u, (s->bias + 4626u), 1); { instructions++; goto L_after_0000120a; }
L_after_0000120a:
    blocks_done++;
    goto L_exit;
L_00001212:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4626u)) != 8201u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 9u);
    instructions++;
    regs[15] = s->bias + 4628u;
L_after_00001212:
    blocks_done++;
    goto L_exit;
L_00001216:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4630u)) != 59581u || agr_aot_load16(s, (s->bias + 4632u)) != 33264u) { result = AGR_AOT_MISS; goto L_exit; }
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001216; } result = rc; goto L_exit; }
    instructions++;
L_after_00001216:
    blocks_done++;
    goto L_exit;
L_0000121a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4634u)) != 46352u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16400u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 4636u;
L_after_0000121a:
    blocks_done++;
    goto L_exit;
L_0000121e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4638u)) != 27610u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 60u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0000121e; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 4640u;
L_after_0000121e:
    blocks_done++;
    goto L_exit;
L_00001222:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001222[] = {0x19, 0x46, 0xbd, 0xe8, 0x10, 0x40};
    if (memcmp(s->mem + s->bias + 4642u, expected_00001222, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 1, 3);
    instructions++;
    if ((rc = agr_aot_ldmia_sp(s, 16400u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001222; } result = rc; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 4648u;
L_after_00001222:
    blocks_done++;
    goto L_exit;
L_0000122a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_0000122a[] = {0x00, 0x22, 0x61, 0xe7};
    if (memcmp(s->mem + s->bias + 4650u, expected_0000122a, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 2, 0u);
    instructions++;
    s->r[15] = (s->bias + 4338u); { instructions++; goto L_after_0000122a; }
L_after_0000122a:
    blocks_done++;
    goto L_exit;
L_0000122e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4654u)) != 26947u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 20u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0000122e; } result = rc; goto L_exit; } }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 4656u)) != 46448u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16496u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 4658u)) != 17925u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 5, 0);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 4660u)) != 26822u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 6, s->r[0] + 12u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0000122e; } result = rc; goto L_exit; } }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 4662u)) != 17932u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 4, 1);
    instructions++;
    regs[15] = s->bias + 4664u;
L_after_0000122e:
    blocks_done++;
    goto L_exit;
L_0000123a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4666u)) != 45342u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = !s->r[6] ? (s->bias + 4676u) : (s->bias + 4668u); { instructions++; goto L_after_0000123a; }
L_after_0000123a:
    blocks_done++;
    if (regs[15] == s->bias + 4676u) goto L_00001244;
    if (regs[15] == s->bias + 4668u) goto L_0000123c;
    goto L_exit;
L_0000123c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_0000123c[] = {0x01, 0x22, 0xff, 0xf7, 0x58, 0xff};
    if (memcmp(s->mem + s->bias + 4668u, expected_0000123c, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 2, 1u);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4338u) | 1u, (s->bias + 4674u), 1); { instructions++; goto L_after_0000123c; }
L_after_0000123c:
    blocks_done++;
    goto L_exit;
L_00001242:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4674u)) != 57363u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 4716u); { instructions++; goto L_after_00001242; }
L_after_00001242:
    blocks_done++;
    if (regs[15] == s->bias + 4716u) goto L_0000126c;
    goto L_exit;
L_00001244:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001244[] = {0x03, 0x69, 0x29, 0x46, 0x02, 0x20, 0x22, 0x46, 0x98, 0x47};
    if (memcmp(s->mem + s->bias + 4676u, expected_00001244, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 16u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001244; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 1, 5);
    instructions++;
    agr_aot_movs_imm(s, 0, 2u);
    instructions++;
    agr_aot_mov_reg(s, 2, 4);
    instructions++;
    agr_aot_branch_reg(s, s->r[3], (s->bias + 4686u), 1); { instructions++; goto L_after_00001244; }
L_after_00001244:
    blocks_done++;
    goto L_exit;
L_00001256:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001256[] = {0x28, 0x46, 0x21, 0x46, 0xff, 0xf7, 0x2d, 0xff};
    if (memcmp(s->mem + s->bias + 4694u, expected_00001256, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    agr_aot_mov_reg(s, 1, 4);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4280u) | 1u, (s->bias + 4702u), 1); { instructions++; goto L_after_00001256; }
L_after_00001256:
    blocks_done++;
    goto L_exit;
L_0000125e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_0000125e[] = {0x30, 0x46, 0x21, 0x6c, 0xff, 0xf7, 0x28, 0xff};
    if (memcmp(s->mem + s->bias + 4702u, expected_0000125e, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 6);
    instructions++;
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 64u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0000125e; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4278u) | 1u, (s->bias + 4710u), 1); { instructions++; goto L_after_0000125e; }
L_after_0000125e:
    blocks_done++;
    goto L_exit;
L_00001268:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4712u)) != 61440u || agr_aot_load16(s, (s->bias + 4714u)) != 64240u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 6220u) | 1u, (s->bias + 4716u), 1); { instructions++; goto L_after_00001268; }
L_after_00001268:
    blocks_done++;
    goto L_exit;
L_0000126c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4716u)) != 63487u || agr_aot_load16(s, (s->bias + 4718u)) != 60784u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 3408u), (s->bias + 4720u), 1); { instructions++; goto L_after_0000126c; }
L_after_0000126c:
    blocks_done++;
    goto L_exit;
L_00001270:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001270[] = {0xc2, 0x68, 0x0a, 0xb9};
    if (memcmp(s->mem + s->bias + 4720u, expected_00001270, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 2, s->r[0] + 12u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001270; } result = rc; goto L_exit; } }
    instructions++;
    s->r[15] = s->r[2] ? (s->bias + 4728u) : (s->bias + 4724u); { instructions++; goto L_after_00001270; }
L_after_00001270:
    blocks_done++;
    if (regs[15] == s->bias + 4728u) goto L_00001278;
    if (regs[15] == s->bias + 4724u) goto L_00001274;
    goto L_exit;
L_00001274:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4724u)) != 63487u || agr_aot_load16(s, (s->bias + 4726u)) != 49056u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 4536u); { instructions++; goto L_after_00001274; }
L_after_00001274:
    blocks_done++;
    goto L_exit;
L_00001278:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4728u)) != 27594u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 2, s->r[1] + 60u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001278; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 4730u;
L_after_00001278:
    blocks_done++;
    goto L_exit;
L_0000127c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_0000127c[] = {0x00, 0x22, 0x38, 0xe7};
    if (memcmp(s->mem + s->bias + 4732u, expected_0000127c, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 2, 0u);
    instructions++;
    s->r[15] = (s->bias + 4338u); { instructions++; goto L_after_0000127c; }
L_after_0000127c:
    blocks_done++;
    goto L_exit;
L_00001280:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4736u)) != 18288u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00001280; }
L_after_00001280:
    blocks_done++;
    goto L_exit;
L_00001282:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4738u)) != 46344u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16392u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 4740u)) != 17921u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 1, 0);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 4742u)) != 26755u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 8u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001282; } result = rc; goto L_exit; } }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 4744u)) != 45323u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = !s->r[3] ? (s->bias + 4750u) : (s->bias + 4746u); { instructions++; goto L_after_00001282; }
L_after_00001282:
    blocks_done++;
    if (regs[15] == s->bias + 4750u) goto L_0000128e;
    if (regs[15] == s->bias + 4746u) goto L_0000128a;
    goto L_exit;
L_0000128a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_0000128a[] = {0x01, 0x20, 0x98, 0x47};
    if (memcmp(s->mem + s->bias + 4746u, expected_0000128a, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 1u);
    instructions++;
    agr_aot_branch_reg(s, s->r[3], (s->bias + 4750u), 1); { instructions++; goto L_after_0000128a; }
L_after_0000128a:
    blocks_done++;
    goto L_exit;
L_0000128e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4750u)) != 48392u) { result = AGR_AOT_MISS; goto L_exit; }
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0000128e; } result = rc; goto L_exit; }
    instructions++;
L_after_0000128e:
    blocks_done++;
    goto L_exit;
L_00001290:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4752u)) != 46384u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16432u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 4754u;
L_after_00001290:
    blocks_done++;
    goto L_exit;
L_000012a0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_000012a0[] = {0x01, 0x20, 0x30, 0xbd};
    if (memcmp(s->mem + s->bias + 4768u, expected_000012a0, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 1u);
    instructions++;
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000012a0; } result = rc; goto L_exit; }
    instructions++;
L_after_000012a0:
    blocks_done++;
    goto L_exit;
L_000012b8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_000012b8[] = {0x02, 0x20, 0x30, 0xbd};
    if (memcmp(s->mem + s->bias + 4792u, expected_000012b8, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 2u);
    instructions++;
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000012b8; } result = rc; goto L_exit; }
    instructions++;
L_after_000012b8:
    blocks_done++;
    goto L_exit;
L_000012bc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4796u)) != 46367u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16415u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 4798u)) != 17930u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 2, 1);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 4800u)) != 8448u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 1, 0u);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 4802u)) != 43779u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 3, s->r[13], 12u);
    instructions++;
    regs[15] = s->bias + 4804u;
L_after_000012bc:
    blocks_done++;
    goto L_exit;
L_000012c6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_000012c6[] = {0x0b, 0x46, 0xff, 0xf7, 0xe2, 0xff};
    if (memcmp(s->mem + s->bias + 4806u, expected_000012c6, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 3, 1);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4752u) | 1u, (s->bias + 4812u), 1); { instructions++; goto L_after_000012c6; }
L_after_000012c6:
    blocks_done++;
    if (regs[15] == s->bias + 4752u) goto L_00001290;
    goto L_exit;
L_000012cc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4812u)) != 38915u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 12u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000012cc; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 4814u;
L_after_000012cc:
    blocks_done++;
    goto L_exit;
L_000012d4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4820u)) != 46384u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16432u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 4822u;
L_after_000012d4:
    blocks_done++;
    goto L_exit;
L_000012e4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_000012e4[] = {0x01, 0x20, 0x30, 0xbd};
    if (memcmp(s->mem + s->bias + 4836u, expected_000012e4, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 1u);
    instructions++;
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000012e4; } result = rc; goto L_exit; }
    instructions++;
L_after_000012e4:
    blocks_done++;
    goto L_exit;
L_000012fc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_000012fc[] = {0x02, 0x20, 0x30, 0xbd};
    if (memcmp(s->mem + s->bias + 4860u, expected_000012fc, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 2u);
    instructions++;
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000012fc; } result = rc; goto L_exit; }
    instructions++;
L_after_000012fc:
    blocks_done++;
    goto L_exit;
L_00001300:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4864u)) != 46367u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16415u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 4866u)) != 43780u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 3, s->r[13], 16u);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 4868u)) != 17932u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 4, 1);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 4870u)) != 8448u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 1, 0u);
    instructions++;
    regs[15] = s->bias + 4872u;
L_after_00001300:
    blocks_done++;
    goto L_exit;
L_0000130c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4876u)) != 17954u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 2, 4);
    instructions++;
    regs[15] = s->bias + 4878u;
L_after_0000130c:
    blocks_done++;
    goto L_exit;
L_00001310:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001310[] = {0x0b, 0x46, 0xff, 0xf7, 0xdf, 0xff};
    if (memcmp(s->mem + s->bias + 4880u, expected_00001310, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 3, 1);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4820u) | 1u, (s->bias + 4886u), 1); { instructions++; goto L_after_00001310; }
L_after_00001310:
    blocks_done++;
    if (regs[15] == s->bias + 4820u) goto L_000012d4;
    goto L_exit;
L_00001318:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4888u)) != 48400u) { result = AGR_AOT_MISS; goto L_exit; }
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001318; } result = rc; goto L_exit; }
    instructions++;
L_after_00001318:
    blocks_done++;
    goto L_exit;
L_0000131a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4890u)) != 27603u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[2] + 60u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0000131a; } result = rc; goto L_exit; } }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 4892u)) != 59693u || agr_aot_load16(s, (s->bias + 4894u)) != 16880u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16880u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 4896u;
L_after_0000131a:
    blocks_done++;
    goto L_exit;
L_00001324:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001324[] = {0x07, 0x46, 0x88, 0x46};
    if (memcmp(s->mem + s->bias + 4900u, expected_00001324, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 7, 0);
    instructions++;
    agr_aot_mov_reg(s, 8, 1);
    instructions++;
    regs[15] = s->bias + 4904u;
L_after_00001324:
    blocks_done++;
    goto L_exit;
L_0000132e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_0000132e[] = {0x17, 0xac, 0x16, 0xae};
    if (memcmp(s->mem + s->bias + 4910u, expected_0000132e, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 4, s->r[13], 92u);
    instructions++;
    agr_aot_add_imm(s, 6, s->r[13], 88u);
    instructions++;
    regs[15] = s->bias + 4914u;
L_after_0000132e:
    blocks_done++;
    goto L_exit;
L_00001344:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001344[] = {0x6c, 0x46, 0x4f, 0xf0, 0xff, 0x33};
    if (memcmp(s->mem + s->bias + 4932u, expected_00001344, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 4, 13);
    instructions++;
    s->r[3] = 4294967295u;
    instructions++;
    regs[15] = s->bias + 4938u;
L_after_00001344:
    blocks_done++;
    goto L_exit;
L_0000134c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_0000134c[] = {0x68, 0x46, 0x31, 0x6c, 0xff, 0xf7, 0x30, 0xfe};
    if (memcmp(s->mem + s->bias + 4940u, expected_0000134c, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 13);
    instructions++;
    { int rc = agr_aot_ldr(s, 1, s->r[6] + 64u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0000134c; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4020u) | 1u, (s->bias + 4948u), 1); { instructions++; goto L_after_0000134c; }
L_after_0000134c:
    blocks_done++;
    goto L_exit;
L_00001354:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4948u)) != 45320u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = !s->r[0] ? (s->bias + 4954u) : (s->bias + 4950u); { instructions++; goto L_after_00001354; }
L_after_00001354:
    blocks_done++;
    if (regs[15] == s->bias + 4954u) goto L_0000135a;
    if (regs[15] == s->bias + 4950u) goto L_00001356;
    goto L_exit;
L_00001356:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001356[] = {0x09, 0x25, 0x14, 0xe0};
    if (memcmp(s->mem + s->bias + 4950u, expected_00001356, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 5, 9u);
    instructions++;
    s->r[15] = (s->bias + 4996u); { instructions++; goto L_after_00001356; }
L_after_00001356:
    blocks_done++;
    if (regs[15] == s->bias + 4996u) goto L_00001384;
    goto L_exit;
L_0000135a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_0000135a[] = {0x30, 0x46, 0x0c, 0x21, 0x6a, 0x46, 0xff, 0xf7, 0xce, 0xff};
    if (memcmp(s->mem + s->bias + 4954u, expected_0000135a, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 6);
    instructions++;
    agr_aot_movs_imm(s, 1, 12u);
    instructions++;
    agr_aot_mov_reg(s, 2, 13);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4864u) | 1u, (s->bias + 4964u), 1); { instructions++; goto L_after_0000135a; }
L_after_0000135a:
    blocks_done++;
    if (regs[15] == s->bias + 4864u) goto L_00001300;
    goto L_exit;
L_00001364:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001364[] = {0x30, 0x46, 0x41, 0x46, 0xb8, 0x47};
    if (memcmp(s->mem + s->bias + 4964u, expected_00001364, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 6);
    instructions++;
    agr_aot_mov_reg(s, 1, 8);
    instructions++;
    agr_aot_branch_reg(s, s->r[7], (s->bias + 4970u), 1); { instructions++; goto L_after_00001364; }
L_after_00001364:
    blocks_done++;
    goto L_exit;
L_0000136e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_0000136e[] = {0x23, 0x69, 0x08, 0x20, 0x69, 0x46, 0x32, 0x46, 0x98, 0x47};
    if (memcmp(s->mem + s->bias + 4974u, expected_0000136e, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 16u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0000136e; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_movs_imm(s, 0, 8u);
    instructions++;
    agr_aot_mov_reg(s, 1, 13);
    instructions++;
    agr_aot_mov_reg(s, 2, 6);
    instructions++;
    agr_aot_branch_reg(s, s->r[3], (s->bias + 4984u), 1); { instructions++; goto L_after_0000136e; }
L_after_0000136e:
    blocks_done++;
    goto L_exit;
L_0000137a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4986u)) != 17925u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 5, 0);
    instructions++;
    regs[15] = s->bias + 4988u;
L_after_0000137a:
    blocks_done++;
    goto L_exit;
L_00001382:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 4994u)) != 59368u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 4950u); { instructions++; goto L_after_00001382; }
L_after_00001382:
    blocks_done++;
    if (regs[15] == s->bias + 4950u) goto L_00001356;
    goto L_exit;
L_00001384:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001384[] = {0x30, 0x46, 0xff, 0xf7, 0x67, 0xfe};
    if (memcmp(s->mem + s->bias + 4996u, expected_00001384, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 6);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4184u) | 1u, (s->bias + 5002u), 1); { instructions++; goto L_after_00001384; }
L_after_00001384:
    blocks_done++;
    goto L_exit;
L_0000138a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_0000138a[] = {0x28, 0x46, 0x0d, 0xf5, 0x0e, 0x7d, 0xbd, 0xe8, 0xf0, 0x81};
    if (memcmp(s->mem + s->bias + 5002u, expected_0000138a, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    agr_aot_add_imm(s, 13, s->r[13], 3854u);
    instructions++;
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0000138a; } result = rc; goto L_exit; }
    instructions++;
L_after_0000138a:
    blocks_done++;
    goto L_exit;
L_00001394:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 5012u)) != 59693u || agr_aot_load16(s, (s->bias + 5014u)) != 20464u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 20464u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 5016u)) != 17942u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 6, 2);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 5018u)) != 27850u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 2, s->r[1] + 76u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001394; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 5020u;
L_after_00001394:
    blocks_done++;
    goto L_exit;
L_0000139e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_0000139e[] = {0x83, 0x46, 0x0c, 0x46};
    if (memcmp(s->mem + s->bias + 5022u, expected_0000139e, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 11, 0);
    instructions++;
    agr_aot_mov_reg(s, 4, 1);
    instructions++;
    regs[15] = s->bias + 5026u;
L_after_0000139e:
    blocks_done++;
    goto L_exit;
L_000013a8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_000013a8[] = {0x12, 0x68, 0x1f, 0x46};
    if (memcmp(s->mem + s->bias + 5032u, expected_000013a8, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 2, s->r[2] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000013a8; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 7, 3);
    instructions++;
    regs[15] = s->bias + 5036u;
L_after_000013a8:
    blocks_done++;
    goto L_exit;
L_000013b0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 5040u)) != 47419u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = s->r[3] ? (s->bias + 5058u) : (s->bias + 5042u); { instructions++; goto L_after_000013b0; }
L_after_000013b0:
    blocks_done++;
    goto L_exit;
L_000013ba:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 5050u)) != 8963u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 3, 3u);
    instructions++;
    regs[15] = s->bias + 5052u;
L_after_000013ba:
    blocks_done++;
    goto L_exit;
L_000013c0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 5056u)) != 57356u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 5084u); { instructions++; goto L_after_000013c0; }
L_after_000013c0:
    blocks_done++;
    goto L_exit;
L_000013d2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 5074u)) != 8706u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 2, 2u);
    instructions++;
    regs[15] = s->bias + 5076u;
L_after_000013d2:
    blocks_done++;
    goto L_exit;
L_000013e0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 5088u)) != 27939u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 80u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000013e0; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 5090u;
L_after_000013e0:
    blocks_done++;
    goto L_exit;
L_0000161c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_0000161c[] = {0x00, 0x23, 0xb9, 0xe6};
    if (memcmp(s->mem + s->bias + 5660u, expected_0000161c, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 3, 0u);
    instructions++;
    s->r[15] = (s->bias + 5012u); { instructions++; goto L_after_0000161c; }
L_after_0000161c:
    blocks_done++;
    if (regs[15] == s->bias + 5012u) goto L_00001394;
    goto L_exit;
L_00001620:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001620[] = {0x01, 0x23, 0xb7, 0xe6};
    if (memcmp(s->mem + s->bias + 5664u, expected_00001620, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 3, 1u);
    instructions++;
    s->r[15] = (s->bias + 5012u); { instructions++; goto L_after_00001620; }
L_after_00001620:
    blocks_done++;
    if (regs[15] == s->bias + 5012u) goto L_00001394;
    goto L_exit;
L_00001624:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001624[] = {0x02, 0x23, 0xb5, 0xe6};
    if (memcmp(s->mem + s->bias + 5668u, expected_00001624, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 3, 2u);
    instructions++;
    s->r[15] = (s->bias + 5012u); { instructions++; goto L_after_00001624; }
L_after_00001624:
    blocks_done++;
    if (regs[15] == s->bias + 5012u) goto L_00001394;
    goto L_exit;
L_00001628:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 5672u)) != 59693u || agr_aot_load16(s, (s->bias + 5674u)) != 16880u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16880u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 5676u)) != 17924u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 4, 0);
    instructions++;
    regs[15] = s->bias + 5678u;
L_after_00001628:
    blocks_done++;
    goto L_exit;
L_exit:
    memcpy(outer->r, regs, sizeof(regs));
    *outer->cpsr = cpsr;
    outer->region_blocks = blocks_done;
    outer->region_instructions = instructions;
    return result;
}

static int agr_region_00003(AgrAotRegs *outer) {
    uint32_t regs[16];
    memcpy(regs, outer->r, sizeof(regs));
    uint32_t cpsr = *outer->cpsr;
    AgrAotRegs local = {regs, &cpsr, outer->mem, outer->bias, 0, 0, 0};
    AgrAotRegs *s = &local;
    uint32_t blocks_done = 0, instructions = 0;
    int rc = 0, result = AGR_AOT_BOUNDARY;
    (void)rc;
    switch (regs[15] - s->bias) {
    case 5680u: goto L_00001630;
    case 5702u: goto L_00001646;
    case 5706u: goto L_0000164a;
    case 5716u: goto L_00001654;
    case 5742u: goto L_0000166e;
    case 5936u: goto L_00001730;
    case 6006u: goto L_00001776;
    case 6214u: goto L_00001846;
    case 6220u: goto L_0000184c;
    case 6228u: goto L_00001854;
    case 6240u: goto L_00001860;
    case 6248u: goto L_00001868;
    case 6256u: goto L_00001870;
    case 6264u: goto L_00001878;
    case 6272u: goto L_00001880;
    case 6280u: goto L_00001888;
    case 6288u: goto L_00001890;
    case 6356u: goto L_000018d4;
    case 6424u: goto L_00001918;
    case 6444u: goto L_0000192c;
    case 6464u: goto L_00001940;
    case 6468u: goto L_00001944;
    case 6494u: goto L_0000195e;
    case 6500u: goto L_00001964;
    case 6504u: goto L_00001968;
    case 6530u: goto L_00001982;
    case 6536u: goto L_00001988;
    case 6540u: goto L_0000198c;
    case 6566u: goto L_000019a6;
    case 6572u: goto L_000019ac;
    case 6576u: goto L_000019b0;
    case 6602u: goto L_000019ca;
    case 6608u: goto L_000019d0;
    case 6612u: goto L_000019d4;
    case 6638u: goto L_000019ee;
    case 6644u: goto L_000019f4;
    case 6650u: goto L_000019fa;
    case 6654u: goto L_000019fe;
    case 6660u: goto L_00001a04;
    case 6666u: goto L_00001a0a;
    case 6670u: goto L_00001a0e;
    case 6678u: goto L_00001a16;
    case 6686u: goto L_00001a1e;
    case 6688u: goto L_00001a20;
    case 6692u: goto L_00001a24;
    case 6702u: goto L_00001a2e;
    case 6708u: goto L_00001a34;
    case 6716u: goto L_00001a3c;
    case 6718u: goto L_00001a3e;
    case 6736u: goto L_00001a50;
    case 6744u: goto L_00001a58;
    case 6754u: goto L_00001a62;
    case 6762u: goto L_00001a6a;
    case 6772u: goto L_00001a74;
    case 6784u: goto L_00001a80;
    case 6800u: goto L_00001a90;
    case 6806u: goto L_00001a96;
    case 6814u: goto L_00001a9e;
    case 6818u: goto L_00001aa2;
    case 6850u: goto L_00001ac2;
    case 6864u: goto L_00001ad0;
    case 6870u: goto L_00001ad6;
    case 6878u: goto L_00001ade;
    case 6908u: goto L_00001afc;
    default: result = AGR_AOT_MISS; goto L_exit;
    }
L_00001630:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001630[] = {0x17, 0x46, 0x1d, 0x46};
    if (memcmp(s->mem + s->bias + 5680u, expected_00001630, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 7, 2);
    instructions++;
    agr_aot_mov_reg(s, 5, 3);
    instructions++;
    regs[15] = s->bias + 5684u;
L_after_00001630:
    blocks_done++;
    goto L_exit;
L_00001646:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 5702u)) != 27523u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 56u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001646; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 5704u;
L_after_00001646:
    blocks_done++;
    goto L_exit;
L_0000164a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 5706u)) != 8193u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 1u);
    instructions++;
    regs[15] = s->bias + 5708u;
L_after_0000164a:
    blocks_done++;
    goto L_exit;
L_00001654:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 5716u)) != 26650u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001654; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 5718u;
L_after_00001654:
    blocks_done++;
    goto L_exit;
L_0000166e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 5742u)) != 57577u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 6212u); { instructions++; goto L_after_0000166e; }
L_after_0000166e:
    blocks_done++;
    goto L_exit;
L_00001730:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001730[] = {0x02, 0x20, 0x87, 0xe0};
    if (memcmp(s->mem + s->bias + 5936u, expected_00001730, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 2u);
    instructions++;
    s->r[15] = (s->bias + 6212u); { instructions++; goto L_after_00001730; }
L_after_00001730:
    blocks_done++;
    goto L_exit;
L_00001776:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001776[] = {0x00, 0x20, 0x64, 0xe0};
    if (memcmp(s->mem + s->bias + 6006u, expected_00001776, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 0u);
    instructions++;
    s->r[15] = (s->bias + 6212u); { instructions++; goto L_after_00001776; }
L_after_00001776:
    blocks_done++;
    goto L_exit;
L_00001846:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6214u)) != 59581u || agr_aot_load16(s, (s->bias + 6216u)) != 33264u) { result = AGR_AOT_MISS; goto L_exit; }
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001846; } result = rc; goto L_exit; }
    instructions++;
L_after_00001846:
    blocks_done++;
    goto L_exit;
L_0000184c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6220u)) != 61696u || agr_aot_load16(s, (s->bias + 6222u)) != 308u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 1, s->r[0], 52u);
    instructions++;
    regs[15] = s->bias + 6224u;
L_after_0000184c:
    blocks_done++;
    goto L_exit;
L_00001854:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001854[] = {0x9c, 0x46, 0xa6, 0x46};
    if (memcmp(s->mem + s->bias + 6228u, expected_00001854, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 12, 3);
    instructions++;
    agr_aot_mov_reg(s, 14, 4);
    instructions++;
    regs[15] = s->bias + 6232u;
L_after_00001854:
    blocks_done++;
    goto L_exit;
L_00001860:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001860[] = {0xe5, 0x46, 0x00, 0xbd};
    if (memcmp(s->mem + s->bias + 6240u, expected_00001860, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 13, 12);
    instructions++;
    if ((rc = agr_aot_ldmia_sp(s, 32768u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001860; } result = rc; goto L_exit; }
    instructions++;
L_after_00001860:
    blocks_done++;
    goto L_exit;
L_00001868:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6248u)) != 18288u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00001868; }
L_after_00001868:
    blocks_done++;
    goto L_exit;
L_00001870:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6256u)) != 18288u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00001870; }
L_after_00001870:
    blocks_done++;
    goto L_exit;
L_00001878:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6264u)) != 18288u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00001878; }
L_after_00001878:
    blocks_done++;
    goto L_exit;
L_00001880:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6272u)) != 18288u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00001880; }
L_after_00001880:
    blocks_done++;
    goto L_exit;
L_00001888:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6280u)) != 18288u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00001888; }
L_after_00001888:
    blocks_done++;
    goto L_exit;
L_00001890:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6288u)) != 18288u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00001890; }
L_after_00001890:
    blocks_done++;
    goto L_exit;
L_000018d4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6356u)) != 18288u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_000018d4; }
L_after_000018d4:
    blocks_done++;
    goto L_exit;
L_00001918:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6424u)) != 18288u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00001918; }
L_after_00001918:
    blocks_done++;
    goto L_exit;
L_0000192c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6444u)) != 18288u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_0000192c; }
L_after_0000192c:
    blocks_done++;
    goto L_exit;
L_00001940:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6464u)) != 18288u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00001940; }
L_after_00001940:
    blocks_done++;
    goto L_exit;
L_00001944:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6468u)) != 18156u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 12, 13);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6470u)) != 46336u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16384u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6472u)) != 59693u || agr_aot_load16(s, (s->bias + 6474u)) != 20480u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 20480u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6476u)) != 59693u || agr_aot_load16(s, (s->bias + 6478u)) != 8191u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 8191u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6480u)) != 61519u || agr_aot_load16(s, (s->bias + 6482u)) != 768u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[3] = 0u;
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6484u)) != 59693u || agr_aot_load16(s, (s->bias + 6486u)) != 12u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 12u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6488u)) != 43265u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6490u)) != 63487u || agr_aot_load16(s, (s->bias + 6492u)) != 64557u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 4536u) | 1u, (s->bias + 6494u), 1); { instructions++; goto L_after_00001944; }
L_after_00001944:
    blocks_done++;
    goto L_exit;
L_0000195e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6494u)) != 63709u || agr_aot_load16(s, (s->bias + 6496u)) != 57408u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0000195e; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 6498u;
L_after_0000195e:
    blocks_done++;
    goto L_exit;
L_00001964:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6500u)) != 18288u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00001964; }
L_after_00001964:
    blocks_done++;
    goto L_exit;
L_00001968:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6504u)) != 18156u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 12, 13);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6506u)) != 46336u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16384u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6508u)) != 59693u || agr_aot_load16(s, (s->bias + 6510u)) != 20480u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 20480u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6512u)) != 59693u || agr_aot_load16(s, (s->bias + 6514u)) != 8191u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 8191u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6516u)) != 61519u || agr_aot_load16(s, (s->bias + 6518u)) != 768u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[3] = 0u;
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6520u)) != 59693u || agr_aot_load16(s, (s->bias + 6522u)) != 12u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 12u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6524u)) != 43265u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6526u)) != 63487u || agr_aot_load16(s, (s->bias + 6528u)) != 64598u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 4654u) | 1u, (s->bias + 6530u), 1); { instructions++; goto L_after_00001968; }
L_after_00001968:
    blocks_done++;
    goto L_exit;
L_00001982:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6530u)) != 63709u || agr_aot_load16(s, (s->bias + 6532u)) != 57408u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001982; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 6534u;
L_after_00001982:
    blocks_done++;
    goto L_exit;
L_00001988:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6536u)) != 18288u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00001988; }
L_after_00001988:
    blocks_done++;
    goto L_exit;
L_0000198c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6540u)) != 18156u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 12, 13);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6542u)) != 46336u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16384u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6544u)) != 59693u || agr_aot_load16(s, (s->bias + 6546u)) != 20480u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 20480u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6548u)) != 59693u || agr_aot_load16(s, (s->bias + 6550u)) != 8191u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 8191u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6552u)) != 61519u || agr_aot_load16(s, (s->bias + 6554u)) != 768u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[3] = 0u;
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6556u)) != 59693u || agr_aot_load16(s, (s->bias + 6558u)) != 12u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 12u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6560u)) != 43265u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6562u)) != 63487u || agr_aot_load16(s, (s->bias + 6564u)) != 64613u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 4720u) | 1u, (s->bias + 6566u), 1); { instructions++; goto L_after_0000198c; }
L_after_0000198c:
    blocks_done++;
    goto L_exit;
L_000019a6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6566u)) != 63709u || agr_aot_load16(s, (s->bias + 6568u)) != 57408u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000019a6; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 6570u;
L_after_000019a6:
    blocks_done++;
    goto L_exit;
L_000019ac:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6572u)) != 18288u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_000019ac; }
L_after_000019ac:
    blocks_done++;
    goto L_exit;
L_000019b0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6576u)) != 18156u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 12, 13);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6578u)) != 46336u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16384u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6580u)) != 59693u || agr_aot_load16(s, (s->bias + 6582u)) != 20480u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 20480u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6584u)) != 59693u || agr_aot_load16(s, (s->bias + 6586u)) != 8191u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 8191u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6588u)) != 61519u || agr_aot_load16(s, (s->bias + 6590u)) != 768u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[3] = 0u;
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6592u)) != 59693u || agr_aot_load16(s, (s->bias + 6594u)) != 12u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 12u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6596u)) != 43777u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 3, s->r[13], 4u);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6598u)) != 63487u || agr_aot_load16(s, (s->bias + 6600u)) != 64552u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 4634u) | 1u, (s->bias + 6602u), 1); { instructions++; goto L_after_000019b0; }
L_after_000019b0:
    blocks_done++;
    goto L_exit;
L_000019ca:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6602u)) != 63709u || agr_aot_load16(s, (s->bias + 6604u)) != 57408u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000019ca; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 6606u;
L_after_000019ca:
    blocks_done++;
    goto L_exit;
L_000019d0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6608u)) != 18288u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_000019d0; }
L_after_000019d0:
    blocks_done++;
    goto L_exit;
L_000019d4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6612u)) != 18156u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 12, 13);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6614u)) != 46336u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16384u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6616u)) != 59693u || agr_aot_load16(s, (s->bias + 6618u)) != 20480u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 20480u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6620u)) != 59693u || agr_aot_load16(s, (s->bias + 6622u)) != 8191u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 8191u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6624u)) != 61519u || agr_aot_load16(s, (s->bias + 6626u)) != 768u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[3] = 0u;
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6628u)) != 59693u || agr_aot_load16(s, (s->bias + 6630u)) != 12u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 12u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6632u)) != 43521u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6634u)) != 63487u || agr_aot_load16(s, (s->bias + 6636u)) != 64662u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 4890u) | 1u, (s->bias + 6638u), 1); { instructions++; goto L_after_000019d4; }
L_after_000019d4:
    blocks_done++;
    goto L_exit;
L_000019ee:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6638u)) != 63709u || agr_aot_load16(s, (s->bias + 6640u)) != 57408u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000019ee; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 6642u;
L_after_000019ee:
    blocks_done++;
    goto L_exit;
L_000019f4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6644u)) != 18288u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_000019f4; }
L_after_000019f4:
    blocks_done++;
    goto L_exit;
L_000019fa:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6650u)) != 47443u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = s->r[3] ? (s->bias + 6674u) : (s->bias + 6652u); { instructions++; goto L_after_000019fa; }
L_after_000019fa:
    blocks_done++;
    goto L_exit;
L_000019fe:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6654u)) != 45435u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = !s->r[3] ? (s->bias + 6688u) : (s->bias + 6656u); { instructions++; goto L_after_000019fe; }
L_after_000019fe:
    blocks_done++;
    if (regs[15] == s->bias + 6688u) goto L_00001a20;
    goto L_exit;
L_00001a04:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6660u)) != 26691u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 4u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001a04; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 6662u;
L_after_00001a04:
    blocks_done++;
    goto L_exit;
L_00001a0a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6666u)) != 26651u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001a0a; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 6668u;
L_after_00001a0a:
    blocks_done++;
    goto L_exit;
L_00001a0e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001a0e[] = {0x03, 0x23, 0x00, 0xe0};
    if (memcmp(s->mem + s->bias + 6670u, expected_00001a0e, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 3, 3u);
    instructions++;
    s->r[15] = (s->bias + 6676u); { instructions++; goto L_after_00001a0e; }
L_after_00001a0e:
    blocks_done++;
    goto L_exit;
L_00001a16:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6678u)) != 26627u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001a16; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 6680u;
L_after_00001a16:
    blocks_done++;
    goto L_exit;
L_00001a1e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6686u)) != 18288u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00001a1e; }
L_after_00001a1e:
    blocks_done++;
    goto L_exit;
L_00001a20:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001a20[] = {0xb0, 0x20, 0x70, 0x47};
    if (memcmp(s->mem + s->bias + 6688u, expected_00001a20, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 176u);
    instructions++;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00001a20; }
L_after_00001a20:
    blocks_done++;
    goto L_exit;
L_00001a24:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6692u)) != 46367u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16415u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6694u)) != 8448u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 1, 0u);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6696u)) != 43779u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 3, s->r[13], 12u);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6698u)) != 8716u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 2, 12u);
    instructions++;
    regs[15] = s->bias + 6700u;
L_after_00001a24:
    blocks_done++;
    goto L_exit;
L_00001a2e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001a2e[] = {0x0b, 0x46, 0xff, 0xf7, 0x2e, 0xfc};
    if (memcmp(s->mem + s->bias + 6702u, expected_00001a2e, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 3, 1);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4752u) | 1u, (s->bias + 6708u), 1); { instructions++; goto L_after_00001a2e; }
L_after_00001a2e:
    blocks_done++;
    goto L_exit;
L_00001a34:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6708u)) != 38915u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 12u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001a34; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 6710u;
L_after_00001a34:
    blocks_done++;
    goto L_exit;
L_00001a3c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6716u)) != 59378u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 6692u); { instructions++; goto L_after_00001a3c; }
L_after_00001a3c:
    blocks_done++;
    if (regs[15] == s->bias + 6692u) goto L_00001a24;
    goto L_exit;
L_00001a3e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6718u)) != 59693u || agr_aot_load16(s, (s->bias + 6720u)) != 18431u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 18431u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6722u)) != 17925u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 5, 0);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6724u)) != 17934u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 6, 1);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6726u)) != 9984u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 7, 0u);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6728u)) != 61709u || agr_aot_load16(s, (s->bias + 6730u)) != 2060u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 8, s->r[13], 12u);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 6732u)) != 62543u || agr_aot_load16(s, (s->bias + 6734u)) != 27007u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[9] = 4080u;
    instructions++;
    regs[15] = s->bias + 6736u;
L_after_00001a3e:
    blocks_done++;
    if (regs[15] == s->bias + 6736u) goto L_00001a50;
    goto L_exit;
L_00001a50:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001a50[] = {0x30, 0x46, 0xff, 0xf7, 0xd1, 0xff};
    if (memcmp(s->mem + s->bias + 6736u, expected_00001a50, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 6);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 6742u), 1); { instructions++; goto L_after_00001a50; }
L_after_00001a50:
    blocks_done++;
    goto L_exit;
L_00001a58:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6744u)) != 17924u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 4, 0);
    instructions++;
    regs[15] = s->bias + 6746u;
L_after_00001a58:
    blocks_done++;
    goto L_exit;
L_00001a62:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001a62[] = {0x03, 0xac, 0x39, 0x46, 0x3b, 0x46};
    if (memcmp(s->mem + s->bias + 6754u, expected_00001a62, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 4, s->r[13], 12u);
    instructions++;
    agr_aot_mov_reg(s, 1, 7);
    instructions++;
    agr_aot_mov_reg(s, 3, 7);
    instructions++;
    regs[15] = s->bias + 6760u;
L_after_00001a62:
    blocks_done++;
    goto L_exit;
L_00001a6a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001a6a[] = {0x28, 0x46, 0x0e, 0x22, 0xff, 0xf7, 0x0f, 0xfc};
    if (memcmp(s->mem + s->bias + 6762u, expected_00001a6a, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    agr_aot_movs_imm(s, 2, 14u);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4752u) | 1u, (s->bias + 6770u), 1); { instructions++; goto L_after_00001a6a; }
L_after_00001a6a:
    blocks_done++;
    goto L_exit;
L_00001a74:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001a74[] = {0x28, 0x46, 0x39, 0x46, 0x0f, 0x22, 0x3b, 0x46, 0xff, 0xf7, 0x2a, 0xfc};
    if (memcmp(s->mem + s->bias + 6772u, expected_00001a74, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    agr_aot_mov_reg(s, 1, 7);
    instructions++;
    agr_aot_movs_imm(s, 2, 15u);
    instructions++;
    agr_aot_mov_reg(s, 3, 7);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4820u) | 1u, (s->bias + 6784u), 1); { instructions++; goto L_after_00001a74; }
L_after_00001a74:
    blocks_done++;
    goto L_exit;
L_00001a80:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6784u)) != 57608u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 7316u); { instructions++; goto L_after_00001a80; }
L_after_00001a80:
    blocks_done++;
    goto L_exit;
L_00001a90:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6800u)) != 17931u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 3, 1);
    instructions++;
    regs[15] = s->bias + 6802u;
L_after_00001a90:
    blocks_done++;
    goto L_exit;
L_00001a96:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001a96[] = {0x28, 0x46, 0x0d, 0x22};
    if (memcmp(s->mem + s->bias + 6806u, expected_00001a96, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    agr_aot_movs_imm(s, 2, 13u);
    instructions++;
    regs[15] = s->bias + 6810u;
L_after_00001a96:
    blocks_done++;
    goto L_exit;
L_00001a9e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6814u)) != 63487u || agr_aot_load16(s, (s->bias + 6816u)) != 64503u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 4752u) | 1u, (s->bias + 6818u), 1); { instructions++; goto L_after_00001a9e; }
L_after_00001a9e:
    blocks_done++;
    goto L_exit;
L_00001aa2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001aa2[] = {0x03, 0x9b, 0x0a, 0xf1, 0x04, 0x0a};
    if (memcmp(s->mem + s->bias + 6818u, expected_00001aa2, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 12u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001aa2; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_add_imm(s, 10, s->r[10], 4u);
    instructions++;
    regs[15] = s->bias + 6824u;
L_after_00001aa2:
    blocks_done++;
    goto L_exit;
L_00001ac2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001ac2[] = {0x30, 0x46, 0xff, 0xf7, 0x98, 0xff};
    if (memcmp(s->mem + s->bias + 6850u, expected_00001ac2, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 6);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 6856u), 1); { instructions++; goto L_after_00001ac2; }
L_after_00001ac2:
    blocks_done++;
    goto L_exit;
L_00001ad0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001ad0[] = {0x09, 0x20, 0xe0, 0xe0};
    if (memcmp(s->mem + s->bias + 6864u, expected_00001ad0, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 9u);
    instructions++;
    s->r[15] = (s->bias + 7318u); { instructions++; goto L_after_00001ad0; }
L_after_00001ad0:
    blocks_done++;
    goto L_exit;
L_00001ad6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001ad6[] = {0x00, 0x21, 0x28, 0x46, 0x0b, 0x46};
    if (memcmp(s->mem + s->bias + 6870u, expected_00001ad6, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 1, 0u);
    instructions++;
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    agr_aot_mov_reg(s, 3, 1);
    instructions++;
    regs[15] = s->bias + 6876u;
L_after_00001ad6:
    blocks_done++;
    goto L_exit;
L_00001ade:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6878u)) != 63487u || agr_aot_load16(s, (s->bias + 6880u)) != 64931u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 5672u) | 1u, (s->bias + 6882u), 1); { instructions++; goto L_after_00001ade; }
L_after_00001ade:
    blocks_done++;
    goto L_exit;
L_00001afc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6908u)) != 8448u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 1, 0u);
    instructions++;
    regs[15] = s->bias + 6910u;
L_after_00001afc:
    blocks_done++;
    goto L_exit;
L_exit:
    memcpy(outer->r, regs, sizeof(regs));
    *outer->cpsr = cpsr;
    outer->region_blocks = blocks_done;
    outer->region_instructions = instructions;
    return result;
}

static int agr_region_00004(AgrAotRegs *outer) {
    uint32_t regs[16];
    memcpy(regs, outer->r, sizeof(regs));
    uint32_t cpsr = *outer->cpsr;
    AgrAotRegs local = {regs, &cpsr, outer->mem, outer->bias, 0, 0, 0};
    AgrAotRegs *s = &local;
    uint32_t blocks_done = 0, instructions = 0;
    int rc = 0, result = AGR_AOT_BOUNDARY;
    (void)rc;
    switch (regs[15] - s->bias) {
    case 6914u: goto L_00001b02;
    case 6920u: goto L_00001b08;
    case 6926u: goto L_00001b0e;
    case 6934u: goto L_00001b16;
    case 6942u: goto L_00001b1e;
    case 6964u: goto L_00001b34;
    case 6984u: goto L_00001b48;
    case 6990u: goto L_00001b4e;
    case 7002u: goto L_00001b5a;
    case 7004u: goto L_00001b5c;
    case 7012u: goto L_00001b64;
    case 7022u: goto L_00001b6e;
    case 7030u: goto L_00001b76;
    case 7040u: goto L_00001b80;
    case 7054u: goto L_00001b8e;
    case 7058u: goto L_00001b92;
    case 7062u: goto L_00001b96;
    case 7064u: goto L_00001b98;
    case 7078u: goto L_00001ba6;
    case 7086u: goto L_00001bae;
    case 7092u: goto L_00001bb4;
    case 7104u: goto L_00001bc0;
    case 7120u: goto L_00001bd0;
    case 7124u: goto L_00001bd4;
    case 7130u: goto L_00001bda;
    case 7140u: goto L_00001be4;
    case 7146u: goto L_00001bea;
    case 7158u: goto L_00001bf6;
    case 7164u: goto L_00001bfc;
    case 7170u: goto L_00001c02;
    case 7176u: goto L_00001c08;
    case 7192u: goto L_00001c18;
    case 7210u: goto L_00001c2a;
    case 7214u: goto L_00001c2e;
    case 7220u: goto L_00001c34;
    case 7226u: goto L_00001c3a;
    case 7244u: goto L_00001c4c;
    case 7252u: goto L_00001c54;
    case 7268u: goto L_00001c64;
    case 7276u: goto L_00001c6c;
    case 7292u: goto L_00001c7c;
    case 7296u: goto L_00001c80;
    case 7302u: goto L_00001c86;
    case 7304u: goto L_00001c88;
    case 7314u: goto L_00001c92;
    case 7316u: goto L_00001c94;
    case 7320u: goto L_00001c98;
    case 7324u: goto L_00001c9c;
    case 7338u: goto L_00001caa;
    case 7344u: goto L_00001cb0;
    case 7356u: goto L_00001cbc;
    case 7366u: goto L_00001cc6;
    case 7372u: goto L_00001ccc;
    case 7376u: goto L_00001cd0;
    case 7382u: goto L_00001cd6;
    case 7392u: goto L_00001ce0;
    case 7394u: goto L_00001ce2;
    case 7400u: goto L_00001ce8;
    default: result = AGR_AOT_MISS; goto L_exit;
    }
L_00001b02:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6914u)) != 17960u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    regs[15] = s->bias + 6916u;
L_after_00001b02:
    blocks_done++;
    goto L_exit;
L_00001b08:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001b08[] = {0x0b, 0x46, 0xff, 0xf7, 0xc1, 0xfb};
    if (memcmp(s->mem + s->bias + 6920u, expected_00001b08, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 3, 1);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4752u) | 1u, (s->bias + 6926u), 1); { instructions++; goto L_after_00001b08; }
L_after_00001b08:
    blocks_done++;
    goto L_exit;
L_00001b0e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001b0e[] = {0x28, 0x46, 0x00, 0x21};
    if (memcmp(s->mem + s->bias + 6926u, expected_00001b0e, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    agr_aot_movs_imm(s, 1, 0u);
    instructions++;
    regs[15] = s->bias + 6930u;
L_after_00001b0e:
    blocks_done++;
    goto L_exit;
L_00001b16:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001b16[] = {0x0d, 0x22, 0x0b, 0x46, 0xff, 0xf7, 0xdb, 0xfb};
    if (memcmp(s->mem + s->bias + 6934u, expected_00001b16, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 2, 13u);
    instructions++;
    agr_aot_mov_reg(s, 3, 1);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4820u) | 1u, (s->bias + 6942u), 1); { instructions++; goto L_after_00001b16; }
L_after_00001b16:
    blocks_done++;
    goto L_exit;
L_00001b1e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6942u)) != 59287u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 6736u); { instructions++; goto L_after_00001b1e; }
L_after_00001b1e:
    blocks_done++;
    goto L_exit;
L_00001b34:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6964u)) != 17960u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    regs[15] = s->bias + 6966u;
L_after_00001b34:
    blocks_done++;
    goto L_exit;
L_00001b48:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001b48[] = {0x30, 0x46, 0xff, 0xf7, 0x55, 0xff};
    if (memcmp(s->mem + s->bias + 6984u, expected_00001b48, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 6);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 6990u), 1); { instructions++; goto L_after_00001b48; }
L_after_00001b48:
    blocks_done++;
    goto L_exit;
L_00001b4e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 6990u)) != 17922u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 2, 0);
    instructions++;
    regs[15] = s->bias + 6992u;
L_after_00001b4e:
    blocks_done++;
    goto L_exit;
L_00001b5a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7002u)) != 17960u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    regs[15] = s->bias + 7004u;
L_after_00001b5a:
    blocks_done++;
    if (regs[15] == s->bias + 7004u) goto L_00001b5c;
    goto L_exit;
L_00001b5c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001b5c[] = {0x0b, 0x46, 0x93, 0xe0};
    if (memcmp(s->mem + s->bias + 7004u, expected_00001b5c, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 3, 1);
    instructions++;
    s->r[15] = (s->bias + 7304u); { instructions++; goto L_after_00001b5c; }
L_after_00001b5c:
    blocks_done++;
    if (regs[15] == s->bias + 7304u) goto L_00001c88;
    goto L_exit;
L_00001b64:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001b64[] = {0x00, 0x21, 0x0d, 0x22, 0x0b, 0x46};
    if (memcmp(s->mem + s->bias + 7012u, expected_00001b64, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 1, 0u);
    instructions++;
    agr_aot_movs_imm(s, 2, 13u);
    instructions++;
    agr_aot_mov_reg(s, 3, 1);
    instructions++;
    regs[15] = s->bias + 7018u;
L_after_00001b64:
    blocks_done++;
    goto L_exit;
L_00001b6e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001b6e[] = {0x28, 0x46, 0x02, 0x24, 0xff, 0xf7, 0x8d, 0xfb};
    if (memcmp(s->mem + s->bias + 7022u, expected_00001b6e, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    agr_aot_movs_imm(s, 4, 2u);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4752u) | 1u, (s->bias + 7030u), 1); { instructions++; goto L_after_00001b6e; }
L_after_00001b6e:
    blocks_done++;
    goto L_exit;
L_00001b76:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001b76[] = {0x30, 0x46, 0xff, 0xf7, 0x3e, 0xff};
    if (memcmp(s->mem + s->bias + 7030u, expected_00001b76, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 6);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 7036u), 1); { instructions++; goto L_after_00001b76; }
L_after_00001b76:
    blocks_done++;
    goto L_exit;
L_00001b80:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7040u)) != 39683u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 12u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001b80; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 7042u;
L_after_00001b80:
    blocks_done++;
    goto L_exit;
L_00001b8e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7054u)) != 17968u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 6);
    instructions++;
    regs[15] = s->bias + 7056u;
L_after_00001b8e:
    blocks_done++;
    goto L_exit;
L_00001b92:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7058u)) != 63487u || agr_aot_load16(s, (s->bias + 7060u)) != 65329u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 7062u), 1); { instructions++; goto L_after_00001b92; }
L_after_00001b92:
    blocks_done++;
    goto L_exit;
L_00001b96:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7062u)) != 59377u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 7036u); { instructions++; goto L_after_00001b96; }
L_after_00001b96:
    blocks_done++;
    goto L_exit;
L_00001b98:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7064u)) != 62723u || agr_aot_load16(s, (s->bias + 7066u)) != 29441u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 3, s->r[3], 3841u);
    instructions++;
    regs[15] = s->bias + 7068u;
L_after_00001b98:
    blocks_done++;
    goto L_exit;
L_00001ba6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001ba6[] = {0x28, 0x46, 0xb5, 0xe7};
    if (memcmp(s->mem + s->bias + 7078u, expected_00001ba6, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    s->r[15] = (s->bias + 6934u); { instructions++; goto L_after_00001ba6; }
L_after_00001ba6:
    blocks_done++;
    if (regs[15] == s->bias + 6934u) goto L_00001b16;
    goto L_exit;
L_00001bae:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001bae[] = {0x30, 0x46, 0xff, 0xf7, 0x22, 0xff};
    if (memcmp(s->mem + s->bias + 7086u, expected_00001bae, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 6);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 7092u), 1); { instructions++; goto L_after_00001bae; }
L_after_00001bae:
    blocks_done++;
    goto L_exit;
L_00001bb4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7092u)) != 8449u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 1, 1u);
    instructions++;
    regs[15] = s->bias + 7094u;
L_after_00001bb4:
    blocks_done++;
    goto L_exit;
L_00001bc0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001bc0[] = {0x28, 0x46, 0x19, 0xe0};
    if (memcmp(s->mem + s->bias + 7104u, expected_00001bc0, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    s->r[15] = (s->bias + 7160u); { instructions++; goto L_after_00001bc0; }
L_after_00001bc0:
    blocks_done++;
    goto L_exit;
L_00001bd0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7120u)) != 8449u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 1, 1u);
    instructions++;
    regs[15] = s->bias + 7122u;
L_after_00001bd0:
    blocks_done++;
    goto L_exit;
L_00001bd4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7124u)) != 17960u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    regs[15] = s->bias + 7126u;
L_after_00001bd4:
    blocks_done++;
    goto L_exit;
L_00001bda:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7130u)) != 59327u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 7004u); { instructions++; goto L_after_00001bda; }
L_after_00001bda:
    blocks_done++;
    if (regs[15] == s->bias + 7004u) goto L_00001b5c;
    goto L_exit;
L_00001be4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001be4[] = {0x30, 0x46, 0xff, 0xf7, 0x07, 0xff};
    if (memcmp(s->mem + s->bias + 7140u, expected_00001be4, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 6);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 7146u), 1); { instructions++; goto L_after_00001be4; }
L_after_00001be4:
    blocks_done++;
    goto L_exit;
L_00001bea:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7146u)) != 8451u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 1, 3u);
    instructions++;
    regs[15] = s->bias + 7148u;
L_after_00001bea:
    blocks_done++;
    goto L_exit;
L_00001bf6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7158u)) != 17960u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    regs[15] = s->bias + 7160u;
L_after_00001bf6:
    blocks_done++;
    goto L_exit;
L_00001bfc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7164u)) != 59310u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 7004u); { instructions++; goto L_after_00001bfc; }
L_after_00001bfc:
    blocks_done++;
    if (regs[15] == s->bias + 7004u) goto L_00001b5c;
    goto L_exit;
L_00001c02:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001c02[] = {0x30, 0x46, 0xff, 0xf7, 0xf8, 0xfe};
    if (memcmp(s->mem + s->bias + 7170u, expected_00001c02, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 6);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 7176u), 1); { instructions++; goto L_after_00001c02; }
L_after_00001c02:
    blocks_done++;
    goto L_exit;
L_00001c08:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7176u)) != 17922u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 2, 0);
    instructions++;
    regs[15] = s->bias + 7178u;
L_after_00001c08:
    blocks_done++;
    goto L_exit;
L_00001c18:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001c18[] = {0x28, 0x46, 0x04, 0x21, 0x34, 0xe0};
    if (memcmp(s->mem + s->bias + 7192u, expected_00001c18, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    agr_aot_movs_imm(s, 1, 4u);
    instructions++;
    s->r[15] = (s->bias + 7304u); { instructions++; goto L_after_00001c18; }
L_after_00001c18:
    blocks_done++;
    if (regs[15] == s->bias + 7304u) goto L_00001c88;
    goto L_exit;
L_00001c2a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7210u)) != 8451u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 1, 3u);
    instructions++;
    regs[15] = s->bias + 7212u;
L_after_00001c2a:
    blocks_done++;
    goto L_exit;
L_00001c2e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7214u)) != 17960u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    regs[15] = s->bias + 7216u;
L_after_00001c2e:
    blocks_done++;
    goto L_exit;
L_00001c34:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7220u)) != 59282u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 7004u); { instructions++; goto L_after_00001c34; }
L_after_00001c34:
    blocks_done++;
    if (regs[15] == s->bias + 7004u) goto L_00001b5c;
    goto L_exit;
L_00001c3a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001c3a[] = {0x30, 0x46, 0xff, 0xf7, 0xdc, 0xfe};
    if (memcmp(s->mem + s->bias + 7226u, expected_00001c3a, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 6);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 7232u), 1); { instructions++; goto L_after_00001c3a; }
L_after_00001c3a:
    blocks_done++;
    goto L_exit;
L_00001c4c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7244u)) != 57354u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 7268u); { instructions++; goto L_after_00001c4c; }
L_after_00001c4c:
    blocks_done++;
    if (regs[15] == s->bias + 7268u) goto L_00001c64;
    goto L_exit;
L_00001c54:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001c54[] = {0x30, 0x46, 0xff, 0xf7, 0xcf, 0xfe};
    if (memcmp(s->mem + s->bias + 7252u, expected_00001c54, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 6);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 7258u), 1); { instructions++; goto L_after_00001c54; }
L_after_00001c54:
    blocks_done++;
    goto L_exit;
L_00001c64:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001c64[] = {0x28, 0x46, 0x01, 0x21};
    if (memcmp(s->mem + s->bias + 7268u, expected_00001c64, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    agr_aot_movs_imm(s, 1, 1u);
    instructions++;
    regs[15] = s->bias + 7272u;
L_after_00001c64:
    blocks_done++;
    goto L_exit;
L_00001c6c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7276u)) != 57355u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 7302u); { instructions++; goto L_after_00001c6c; }
L_after_00001c6c:
    blocks_done++;
    if (regs[15] == s->bias + 7302u) goto L_00001c86;
    goto L_exit;
L_00001c7c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7292u)) != 8449u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 1, 1u);
    instructions++;
    regs[15] = s->bias + 7294u;
L_after_00001c7c:
    blocks_done++;
    goto L_exit;
L_00001c80:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7296u)) != 17960u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    regs[15] = s->bias + 7298u;
L_after_00001c80:
    blocks_done++;
    goto L_exit;
L_00001c86:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7302u)) != 8965u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 3, 5u);
    instructions++;
    regs[15] = s->bias + 7304u;
L_after_00001c86:
    blocks_done++;
    if (regs[15] == s->bias + 7304u) goto L_00001c88;
    goto L_exit;
L_00001c88:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7304u)) != 63487u || agr_aot_load16(s, (s->bias + 7306u)) != 64718u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 5672u) | 1u, (s->bias + 7308u), 1); { instructions++; goto L_after_00001c88; }
L_after_00001c88:
    blocks_done++;
    goto L_exit;
L_00001c92:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7314u)) != 59101u) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 6736u); { instructions++; goto L_after_00001c92; }
L_after_00001c92:
    blocks_done++;
    goto L_exit;
L_00001c94:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7316u)) != 8192u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 0u);
    instructions++;
    regs[15] = s->bias + 7318u;
L_after_00001c94:
    blocks_done++;
    goto L_exit;
L_00001c98:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7320u)) != 59581u || agr_aot_load16(s, (s->bias + 7322u)) != 34800u) { result = AGR_AOT_MISS; goto L_exit; }
    if ((rc = agr_aot_ldmia_sp(s, 34800u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001c98; } result = rc; goto L_exit; }
    instructions++;
L_after_00001c98:
    blocks_done++;
    goto L_exit;
L_00001c9c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7324u)) != 46367u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16415u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 7326u)) != 27843u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 76u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001c9c; } result = rc; goto L_exit; } }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 7328u)) != 17928u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 1);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 7330u)) != 43265u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    instructions++;
    if (agr_aot_load16(s, (s->bias + 7332u)) != 26714u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 4u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001c9c; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 7334u;
L_after_00001c9c:
    blocks_done++;
    goto L_exit;
L_00001caa:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7338u)) != 61699u || agr_aot_load16(s, (s->bias + 7340u)) != 520u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 2, s->r[3], 8u);
    instructions++;
    regs[15] = s->bias + 7342u;
L_after_00001caa:
    blocks_done++;
    goto L_exit;
L_00001cb0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7344u)) != 8707u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 2, 3u);
    instructions++;
    regs[15] = s->bias + 7346u;
L_after_00001cb0:
    blocks_done++;
    goto L_exit;
L_00001cbc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7356u)) != 63487u || agr_aot_load16(s, (s->bias + 7358u)) != 65215u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 6718u) | 1u, (s->bias + 7360u), 1); { instructions++; goto L_after_00001cbc; }
L_after_00001cbc:
    blocks_done++;
    goto L_exit;
L_00001cc6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7366u)) != 46344u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16392u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 7368u)) != 63487u || agr_aot_load16(s, (s->bias + 7370u)) != 65208u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 6716u) | 1u, (s->bias + 7372u), 1); { instructions++; goto L_after_00001cc6; }
L_after_00001cc6:
    blocks_done++;
    goto L_exit;
L_00001ccc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    static const uint8_t expected_00001ccc[] = {0x80, 0x6c, 0x08, 0xbd};
    if (memcmp(s->mem + s->bias + 7372u, expected_00001ccc, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 72u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001ccc; } result = rc; goto L_exit; } }
    instructions++;
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001ccc; } result = rc; goto L_exit; }
    instructions++;
L_after_00001ccc:
    blocks_done++;
    goto L_exit;
L_00001cd0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7376u)) != 46344u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16392u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 7378u)) != 63487u || agr_aot_load16(s, (s->bias + 7380u)) != 65203u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 6716u) | 1u, (s->bias + 7382u), 1); { instructions++; goto L_after_00001cd0; }
L_after_00001cd0:
    blocks_done++;
    goto L_exit;
L_00001cd6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7382u)) != 27843u) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 76u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001cd6; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 7384u;
L_after_00001cd6:
    blocks_done++;
    goto L_exit;
L_00001ce0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7392u)) != 48392u) { result = AGR_AOT_MISS; goto L_exit; }
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001ce0; } result = rc; goto L_exit; }
    instructions++;
L_after_00001ce0:
    blocks_done++;
    goto L_exit;
L_00001ce2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7394u)) != 46344u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16392u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 7396u)) != 63487u || agr_aot_load16(s, (s->bias + 7398u)) != 59444u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 3408u), (s->bias + 7400u), 1); { instructions++; goto L_after_00001ce2; }
L_after_00001ce2:
    blocks_done++;
    goto L_exit;
L_00001ce8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (agr_aot_load16(s, (s->bias + 7400u)) != 46344u) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16392u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    if (agr_aot_load16(s, (s->bias + 7402u)) != 63487u || agr_aot_load16(s, (s->bias + 7404u)) != 59442u) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 3408u), (s->bias + 7406u), 1); { instructions++; goto L_after_00001ce8; }
L_after_00001ce8:
    blocks_done++;
    goto L_exit;
L_exit:
    memcpy(outer->r, regs, sizeof(regs));
    *outer->cpsr = cpsr;
    outer->region_blocks = blocks_done;
    outer->region_instructions = instructions;
    return result;
}
const AgrAotEntry agr_aot_debug_blocks[] = {{0, 0, 0}};
const uint32_t agr_aot_debug_block_count = 0u;
const AgrAotEntry agr_aot_fast_blocks[] = {
    {3296u, agr_region_00000, 1u},
    {3304u, agr_region_00000, 1u},
    {3324u, agr_region_00000, 3u},
    {3336u, agr_region_00000, 3u},
    {3348u, agr_region_00000, 3u},
    {3360u, agr_region_00000, 3u},
    {3372u, agr_region_00000, 3u},
    {3384u, agr_region_00000, 3u},
    {3396u, agr_region_00000, 3u},
    {3408u, agr_region_00000, 3u},
    {3456u, agr_region_00000, 1u},
    {3524u, agr_region_00000, 10u},
    {3548u, agr_region_00000, 7u},
    {3564u, agr_region_00000, 2u},
    {3568u, agr_region_00000, 6u},
    {3582u, agr_region_00000, 2u},
    {3586u, agr_region_00000, 1u},
    {3588u, agr_region_00000, 6u},
    {3602u, agr_region_00000, 6u},
    {3618u, agr_region_00000, 5u},
    {3632u, agr_region_00000, 1u},
    {3634u, agr_region_00000, 5u},
    {3648u, agr_region_00000, 5u},
    {3662u, agr_region_00000, 7u},
    {3678u, agr_region_00000, 1u},
    {3680u, agr_region_00000, 7u},
    {3696u, agr_region_00000, 7u},
    {3712u, agr_region_00000, 7u},
    {3728u, agr_region_00000, 1u},
    {3732u, agr_region_00000, 10u},
    {3758u, agr_region_00000, 7u},
    {3774u, agr_region_00000, 6u},
    {3788u, agr_region_00000, 5u},
    {3800u, agr_region_00000, 4u},
    {3810u, agr_region_00000, 7u},
    {3826u, agr_region_00000, 7u},
    {3842u, agr_region_00000, 1u},
    {3848u, agr_region_00000, 1u},
    {3866u, agr_region_00000, 4u},
    {3876u, agr_region_00000, 3u},
    {3902u, agr_region_00000, 2u},
    {3910u, agr_region_00000, 2u},
    {3916u, agr_region_00000, 1u},
    {3922u, agr_region_00000, 1u},
    {3934u, agr_region_00000, 2u},
    {3948u, agr_region_00000, 1u},
    {3950u, agr_region_00000, 2u},
    {3954u, agr_region_00000, 2u},
    {3962u, agr_region_00000, 1u},
    {3966u, agr_region_00000, 1u},
    {3978u, agr_region_00000, 1u},
    {3980u, agr_region_00000, 1u},
    {3984u, agr_region_00000, 2u},
    {3988u, agr_region_00000, 1u},
    {3992u, agr_region_00000, 2u},
    {3996u, agr_region_00000, 1u},
    {4000u, agr_region_00000, 2u},
    {4004u, agr_region_00000, 2u},
    {4008u, agr_region_00000, 1u},
    {4012u, agr_region_00000, 1u},
    {4016u, agr_region_00000, 1u},
    {4020u, agr_region_00000, 2u},
    {4026u, agr_region_00000, 2u},
    {4032u, agr_region_00000, 1u},
    {4034u, agr_region_00001, 3u},
    {4042u, agr_region_00001, 2u},
    {4046u, agr_region_00001, 1u},
    {4048u, agr_region_00001, 2u},
    {4054u, agr_region_00001, 1u},
    {4058u, agr_region_00001, 1u},
    {4062u, agr_region_00001, 1u},
    {4068u, agr_region_00001, 3u},
    {4076u, agr_region_00001, 2u},
    {4082u, agr_region_00001, 2u},
    {4086u, agr_region_00001, 1u},
    {4090u, agr_region_00001, 1u},
    {4098u, agr_region_00001, 2u},
    {4104u, agr_region_00001, 1u},
    {4108u, agr_region_00001, 1u},
    {4116u, agr_region_00001, 2u},
    {4120u, agr_region_00001, 1u},
    {4124u, agr_region_00001, 1u},
    {4128u, agr_region_00001, 1u},
    {4132u, agr_region_00001, 1u},
    {4142u, agr_region_00001, 1u},
    {4158u, agr_region_00001, 1u},
    {4164u, agr_region_00001, 1u},
    {4168u, agr_region_00001, 1u},
    {4184u, agr_region_00001, 3u},
    {4198u, agr_region_00001, 1u},
    {4204u, agr_region_00001, 1u},
    {4208u, agr_region_00001, 1u},
    {4210u, agr_region_00001, 1u},
    {4214u, agr_region_00001, 1u},
    {4220u, agr_region_00001, 2u},
    {4228u, agr_region_00001, 1u},
    {4234u, agr_region_00001, 2u},
    {4242u, agr_region_00001, 1u},
    {4248u, agr_region_00001, 3u},
    {4260u, agr_region_00001, 1u},
    {4262u, agr_region_00001, 2u},
    {4268u, agr_region_00001, 1u},
    {4270u, agr_region_00001, 2u},
    {4274u, agr_region_00001, 2u},
    {4278u, agr_region_00001, 1u},
    {4280u, agr_region_00001, 3u},
    {4286u, agr_region_00001, 3u},
    {4294u, agr_region_00001, 2u},
    {4298u, agr_region_00001, 1u},
    {4302u, agr_region_00001, 4u},
    {4312u, agr_region_00001, 2u},
    {4324u, agr_region_00001, 3u},
    {4334u, agr_region_00001, 1u},
    {4338u, agr_region_00001, 1u},
    {4344u, agr_region_00001, 4u},
    {4362u, agr_region_00001, 2u},
    {4380u, agr_region_00001, 1u},
    {4386u, agr_region_00001, 2u},
    {4392u, agr_region_00001, 3u},
    {4532u, agr_region_00001, 2u},
    {4536u, agr_region_00001, 2u},
    {4546u, agr_region_00001, 2u},
    {4554u, agr_region_00001, 2u},
    {4576u, agr_region_00001, 1u},
    {4582u, agr_region_00001, 3u},
    {4592u, agr_region_00001, 1u},
    {4594u, agr_region_00001, 4u},
    {4604u, agr_region_00001, 1u},
    {4608u, agr_region_00002, 2u},
    {4618u, agr_region_00002, 3u},
    {4626u, agr_region_00002, 1u},
    {4630u, agr_region_00002, 1u},
    {4634u, agr_region_00002, 1u},
    {4638u, agr_region_00002, 1u},
    {4642u, agr_region_00002, 2u},
    {4650u, agr_region_00002, 2u},
    {4654u, agr_region_00002, 5u},
    {4666u, agr_region_00002, 1u},
    {4668u, agr_region_00002, 2u},
    {4674u, agr_region_00002, 1u},
    {4676u, agr_region_00002, 5u},
    {4694u, agr_region_00002, 3u},
    {4702u, agr_region_00002, 3u},
    {4712u, agr_region_00002, 1u},
    {4716u, agr_region_00002, 1u},
    {4720u, agr_region_00002, 2u},
    {4724u, agr_region_00002, 1u},
    {4728u, agr_region_00002, 1u},
    {4732u, agr_region_00002, 2u},
    {4736u, agr_region_00002, 1u},
    {4738u, agr_region_00002, 4u},
    {4746u, agr_region_00002, 2u},
    {4750u, agr_region_00002, 1u},
    {4752u, agr_region_00002, 1u},
    {4768u, agr_region_00002, 2u},
    {4792u, agr_region_00002, 2u},
    {4796u, agr_region_00002, 4u},
    {4806u, agr_region_00002, 2u},
    {4812u, agr_region_00002, 1u},
    {4820u, agr_region_00002, 1u},
    {4836u, agr_region_00002, 2u},
    {4860u, agr_region_00002, 2u},
    {4864u, agr_region_00002, 4u},
    {4876u, agr_region_00002, 1u},
    {4880u, agr_region_00002, 2u},
    {4888u, agr_region_00002, 1u},
    {4890u, agr_region_00002, 2u},
    {4900u, agr_region_00002, 2u},
    {4910u, agr_region_00002, 2u},
    {4932u, agr_region_00002, 2u},
    {4940u, agr_region_00002, 3u},
    {4948u, agr_region_00002, 1u},
    {4950u, agr_region_00002, 2u},
    {4954u, agr_region_00002, 4u},
    {4964u, agr_region_00002, 3u},
    {4974u, agr_region_00002, 5u},
    {4986u, agr_region_00002, 1u},
    {4994u, agr_region_00002, 1u},
    {4996u, agr_region_00002, 2u},
    {5002u, agr_region_00002, 3u},
    {5012u, agr_region_00002, 3u},
    {5022u, agr_region_00002, 2u},
    {5032u, agr_region_00002, 2u},
    {5040u, agr_region_00002, 1u},
    {5050u, agr_region_00002, 1u},
    {5056u, agr_region_00002, 1u},
    {5074u, agr_region_00002, 1u},
    {5088u, agr_region_00002, 1u},
    {5660u, agr_region_00002, 2u},
    {5664u, agr_region_00002, 2u},
    {5668u, agr_region_00002, 2u},
    {5672u, agr_region_00002, 2u},
    {5680u, agr_region_00003, 2u},
    {5702u, agr_region_00003, 1u},
    {5706u, agr_region_00003, 1u},
    {5716u, agr_region_00003, 1u},
    {5742u, agr_region_00003, 1u},
    {5936u, agr_region_00003, 2u},
    {6006u, agr_region_00003, 2u},
    {6214u, agr_region_00003, 1u},
    {6220u, agr_region_00003, 1u},
    {6228u, agr_region_00003, 2u},
    {6240u, agr_region_00003, 2u},
    {6248u, agr_region_00003, 1u},
    {6256u, agr_region_00003, 1u},
    {6264u, agr_region_00003, 1u},
    {6272u, agr_region_00003, 1u},
    {6280u, agr_region_00003, 1u},
    {6288u, agr_region_00003, 1u},
    {6356u, agr_region_00003, 1u},
    {6424u, agr_region_00003, 1u},
    {6444u, agr_region_00003, 1u},
    {6464u, agr_region_00003, 1u},
    {6468u, agr_region_00003, 8u},
    {6494u, agr_region_00003, 1u},
    {6500u, agr_region_00003, 1u},
    {6504u, agr_region_00003, 8u},
    {6530u, agr_region_00003, 1u},
    {6536u, agr_region_00003, 1u},
    {6540u, agr_region_00003, 8u},
    {6566u, agr_region_00003, 1u},
    {6572u, agr_region_00003, 1u},
    {6576u, agr_region_00003, 8u},
    {6602u, agr_region_00003, 1u},
    {6608u, agr_region_00003, 1u},
    {6612u, agr_region_00003, 8u},
    {6638u, agr_region_00003, 1u},
    {6644u, agr_region_00003, 1u},
    {6650u, agr_region_00003, 1u},
    {6654u, agr_region_00003, 1u},
    {6660u, agr_region_00003, 1u},
    {6666u, agr_region_00003, 1u},
    {6670u, agr_region_00003, 2u},
    {6678u, agr_region_00003, 1u},
    {6686u, agr_region_00003, 1u},
    {6688u, agr_region_00003, 2u},
    {6692u, agr_region_00003, 4u},
    {6702u, agr_region_00003, 2u},
    {6708u, agr_region_00003, 1u},
    {6716u, agr_region_00003, 1u},
    {6718u, agr_region_00003, 6u},
    {6736u, agr_region_00003, 2u},
    {6744u, agr_region_00003, 1u},
    {6754u, agr_region_00003, 3u},
    {6762u, agr_region_00003, 3u},
    {6772u, agr_region_00003, 5u},
    {6784u, agr_region_00003, 1u},
    {6800u, agr_region_00003, 1u},
    {6806u, agr_region_00003, 2u},
    {6814u, agr_region_00003, 1u},
    {6818u, agr_region_00003, 2u},
    {6850u, agr_region_00003, 2u},
    {6864u, agr_region_00003, 2u},
    {6870u, agr_region_00003, 3u},
    {6878u, agr_region_00003, 1u},
    {6908u, agr_region_00003, 1u},
    {6914u, agr_region_00004, 1u},
    {6920u, agr_region_00004, 2u},
    {6926u, agr_region_00004, 2u},
    {6934u, agr_region_00004, 3u},
    {6942u, agr_region_00004, 1u},
    {6964u, agr_region_00004, 1u},
    {6984u, agr_region_00004, 2u},
    {6990u, agr_region_00004, 1u},
    {7002u, agr_region_00004, 1u},
    {7004u, agr_region_00004, 2u},
    {7012u, agr_region_00004, 3u},
    {7022u, agr_region_00004, 3u},
    {7030u, agr_region_00004, 2u},
    {7040u, agr_region_00004, 1u},
    {7054u, agr_region_00004, 1u},
    {7058u, agr_region_00004, 1u},
    {7062u, agr_region_00004, 1u},
    {7064u, agr_region_00004, 1u},
    {7078u, agr_region_00004, 2u},
    {7086u, agr_region_00004, 2u},
    {7092u, agr_region_00004, 1u},
    {7104u, agr_region_00004, 2u},
    {7120u, agr_region_00004, 1u},
    {7124u, agr_region_00004, 1u},
    {7130u, agr_region_00004, 1u},
    {7140u, agr_region_00004, 2u},
    {7146u, agr_region_00004, 1u},
    {7158u, agr_region_00004, 1u},
    {7164u, agr_region_00004, 1u},
    {7170u, agr_region_00004, 2u},
    {7176u, agr_region_00004, 1u},
    {7192u, agr_region_00004, 3u},
    {7210u, agr_region_00004, 1u},
    {7214u, agr_region_00004, 1u},
    {7220u, agr_region_00004, 1u},
    {7226u, agr_region_00004, 2u},
    {7244u, agr_region_00004, 1u},
    {7252u, agr_region_00004, 2u},
    {7268u, agr_region_00004, 2u},
    {7276u, agr_region_00004, 1u},
    {7292u, agr_region_00004, 1u},
    {7296u, agr_region_00004, 1u},
    {7302u, agr_region_00004, 1u},
    {7304u, agr_region_00004, 1u},
    {7314u, agr_region_00004, 1u},
    {7316u, agr_region_00004, 1u},
    {7320u, agr_region_00004, 1u},
    {7324u, agr_region_00004, 5u},
    {7338u, agr_region_00004, 1u},
    {7344u, agr_region_00004, 1u},
    {7356u, agr_region_00004, 1u},
    {7366u, agr_region_00004, 2u},
    {7372u, agr_region_00004, 2u},
    {7376u, agr_region_00004, 2u},
    {7382u, agr_region_00004, 1u},
    {7392u, agr_region_00004, 1u},
    {7394u, agr_region_00004, 2u},
    {7400u, agr_region_00004, 2u},
};
const uint32_t agr_aot_fast_block_count = 314u;
const AgrAotEntry agr_aot_fast_hash[] = {{0, 0, 0}};
const uint32_t agr_aot_fast_hash_mask = 0u;
const uint32_t agr_aot_fast_direct_base = 3296u;
const uint32_t agr_aot_fast_direct_count = 2053u;
const uint32_t agr_aot_fast_direct[2053] = {
    [0] = 1u,
    [4] = 2u,
    [14] = 3u,
    [20] = 4u,
    [26] = 5u,
    [32] = 6u,
    [38] = 7u,
    [44] = 8u,
    [50] = 9u,
    [56] = 10u,
    [80] = 11u,
    [114] = 12u,
    [126] = 13u,
    [134] = 14u,
    [136] = 15u,
    [143] = 16u,
    [145] = 17u,
    [146] = 18u,
    [153] = 19u,
    [161] = 20u,
    [168] = 21u,
    [169] = 22u,
    [176] = 23u,
    [183] = 24u,
    [191] = 25u,
    [192] = 26u,
    [200] = 27u,
    [208] = 28u,
    [216] = 29u,
    [218] = 30u,
    [231] = 31u,
    [239] = 32u,
    [246] = 33u,
    [252] = 34u,
    [257] = 35u,
    [265] = 36u,
    [273] = 37u,
    [276] = 38u,
    [285] = 39u,
    [290] = 40u,
    [303] = 41u,
    [307] = 42u,
    [310] = 43u,
    [313] = 44u,
    [319] = 45u,
    [326] = 46u,
    [327] = 47u,
    [329] = 48u,
    [333] = 49u,
    [335] = 50u,
    [341] = 51u,
    [342] = 52u,
    [344] = 53u,
    [346] = 54u,
    [348] = 55u,
    [350] = 56u,
    [352] = 57u,
    [354] = 58u,
    [356] = 59u,
    [358] = 60u,
    [360] = 61u,
    [362] = 62u,
    [365] = 63u,
    [368] = 64u,
    [369] = 65u,
    [373] = 66u,
    [375] = 67u,
    [376] = 68u,
    [379] = 69u,
    [381] = 70u,
    [383] = 71u,
    [386] = 72u,
    [390] = 73u,
    [393] = 74u,
    [395] = 75u,
    [397] = 76u,
    [401] = 77u,
    [404] = 78u,
    [406] = 79u,
    [410] = 80u,
    [412] = 81u,
    [414] = 82u,
    [416] = 83u,
    [418] = 84u,
    [423] = 85u,
    [431] = 86u,
    [434] = 87u,
    [436] = 88u,
    [444] = 89u,
    [451] = 90u,
    [454] = 91u,
    [456] = 92u,
    [457] = 93u,
    [459] = 94u,
    [462] = 95u,
    [466] = 96u,
    [469] = 97u,
    [473] = 98u,
    [476] = 99u,
    [482] = 100u,
    [483] = 101u,
    [486] = 102u,
    [487] = 103u,
    [489] = 104u,
    [491] = 105u,
    [492] = 106u,
    [495] = 107u,
    [499] = 108u,
    [501] = 109u,
    [503] = 110u,
    [508] = 111u,
    [514] = 112u,
    [519] = 113u,
    [521] = 114u,
    [524] = 115u,
    [533] = 116u,
    [542] = 117u,
    [545] = 118u,
    [548] = 119u,
    [618] = 120u,
    [620] = 121u,
    [625] = 122u,
    [629] = 123u,
    [640] = 124u,
    [643] = 125u,
    [648] = 126u,
    [649] = 127u,
    [654] = 128u,
    [656] = 129u,
    [661] = 130u,
    [665] = 131u,
    [667] = 132u,
    [669] = 133u,
    [671] = 134u,
    [673] = 135u,
    [677] = 136u,
    [679] = 137u,
    [685] = 138u,
    [686] = 139u,
    [689] = 140u,
    [690] = 141u,
    [699] = 142u,
    [703] = 143u,
    [708] = 144u,
    [710] = 145u,
    [712] = 146u,
    [714] = 147u,
    [716] = 148u,
    [718] = 149u,
    [720] = 150u,
    [721] = 151u,
    [725] = 152u,
    [727] = 153u,
    [728] = 154u,
    [736] = 155u,
    [748] = 156u,
    [750] = 157u,
    [755] = 158u,
    [758] = 159u,
    [762] = 160u,
    [770] = 161u,
    [782] = 162u,
    [784] = 163u,
    [790] = 164u,
    [792] = 165u,
    [796] = 166u,
    [797] = 167u,
    [802] = 168u,
    [807] = 169u,
    [818] = 170u,
    [822] = 171u,
    [826] = 172u,
    [827] = 173u,
    [829] = 174u,
    [834] = 175u,
    [839] = 176u,
    [845] = 177u,
    [849] = 178u,
    [850] = 179u,
    [853] = 180u,
    [858] = 181u,
    [863] = 182u,
    [868] = 183u,
    [872] = 184u,
    [877] = 185u,
    [880] = 186u,
    [889] = 187u,
    [896] = 188u,
    [1182] = 189u,
    [1184] = 190u,
    [1186] = 191u,
    [1188] = 192u,
    [1192] = 193u,
    [1203] = 194u,
    [1205] = 195u,
    [1210] = 196u,
    [1223] = 197u,
    [1320] = 198u,
    [1355] = 199u,
    [1459] = 200u,
    [1462] = 201u,
    [1466] = 202u,
    [1472] = 203u,
    [1476] = 204u,
    [1480] = 205u,
    [1484] = 206u,
    [1488] = 207u,
    [1492] = 208u,
    [1496] = 209u,
    [1530] = 210u,
    [1564] = 211u,
    [1574] = 212u,
    [1584] = 213u,
    [1586] = 214u,
    [1599] = 215u,
    [1602] = 216u,
    [1604] = 217u,
    [1617] = 218u,
    [1620] = 219u,
    [1622] = 220u,
    [1635] = 221u,
    [1638] = 222u,
    [1640] = 223u,
    [1653] = 224u,
    [1656] = 225u,
    [1658] = 226u,
    [1671] = 227u,
    [1674] = 228u,
    [1677] = 229u,
    [1679] = 230u,
    [1682] = 231u,
    [1685] = 232u,
    [1687] = 233u,
    [1691] = 234u,
    [1695] = 235u,
    [1696] = 236u,
    [1698] = 237u,
    [1703] = 238u,
    [1706] = 239u,
    [1710] = 240u,
    [1711] = 241u,
    [1720] = 242u,
    [1724] = 243u,
    [1729] = 244u,
    [1733] = 245u,
    [1738] = 246u,
    [1744] = 247u,
    [1752] = 248u,
    [1755] = 249u,
    [1759] = 250u,
    [1761] = 251u,
    [1777] = 252u,
    [1784] = 253u,
    [1787] = 254u,
    [1791] = 255u,
    [1806] = 256u,
    [1809] = 257u,
    [1812] = 258u,
    [1815] = 259u,
    [1819] = 260u,
    [1823] = 261u,
    [1834] = 262u,
    [1844] = 263u,
    [1847] = 264u,
    [1853] = 265u,
    [1854] = 266u,
    [1858] = 267u,
    [1863] = 268u,
    [1867] = 269u,
    [1872] = 270u,
    [1879] = 271u,
    [1881] = 272u,
    [1883] = 273u,
    [1884] = 274u,
    [1891] = 275u,
    [1895] = 276u,
    [1898] = 277u,
    [1904] = 278u,
    [1912] = 279u,
    [1914] = 280u,
    [1917] = 281u,
    [1922] = 282u,
    [1925] = 283u,
    [1931] = 284u,
    [1934] = 285u,
    [1937] = 286u,
    [1940] = 287u,
    [1948] = 288u,
    [1957] = 289u,
    [1959] = 290u,
    [1962] = 291u,
    [1965] = 292u,
    [1974] = 293u,
    [1978] = 294u,
    [1986] = 295u,
    [1990] = 296u,
    [1998] = 297u,
    [2000] = 298u,
    [2003] = 299u,
    [2004] = 300u,
    [2009] = 301u,
    [2010] = 302u,
    [2012] = 303u,
    [2014] = 304u,
    [2021] = 305u,
    [2024] = 306u,
    [2030] = 307u,
    [2035] = 308u,
    [2038] = 309u,
    [2040] = 310u,
    [2043] = 311u,
    [2048] = 312u,
    [2049] = 313u,
    [2052] = 314u,
};
const uint32_t agr_aot_fast_relocatable = 1u;
const uint64_t agr_aot_input_elf_fnv64 = 13986468843527641119ull;
const uint32_t agr_aot_input_elf_bytes = 9376u;
