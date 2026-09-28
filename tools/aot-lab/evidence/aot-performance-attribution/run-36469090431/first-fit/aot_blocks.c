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
    uint32_t blocks_done = 0, instructions = 0;
    switch (outer->region_entry) {
    case 0u: goto L_00000cdc;
    case 1u: goto L_00000ce0;
    case 2u: goto L_00000cfc;
    case 3u: goto L_00000d08;
    case 4u: goto L_00000d14;
    case 5u: goto L_00000d20;
    case 6u: goto L_00000d2c;
    case 7u: goto L_00000d38;
    case 8u: goto L_00000d44;
    case 9u: goto L_00000d50;
    case 10u: goto L_00000d80;
    case 11u: goto L_00000dc4;
    case 12u: goto L_00000dc8;
    case 13u: goto L_00000ddc;
    case 14u: goto L_00000dec;
    case 15u: goto L_00000df0;
    case 16u: goto L_00000dfe;
    case 17u: goto L_00000e02;
    case 18u: goto L_00000e04;
    case 19u: goto L_00000e12;
    case 20u: goto L_00000e22;
    case 21u: goto L_00000e30;
    case 22u: goto L_00000e32;
    case 23u: goto L_00000e40;
    case 24u: goto L_00000e4e;
    case 25u: goto L_00000e5e;
    case 26u: goto L_00000e60;
    case 27u: goto L_00000e70;
    case 28u: goto L_00000e80;
    case 29u: goto L_00000e90;
    case 30u: goto L_00000e94;
    case 31u: goto L_00000e98;
    case 32u: goto L_00000eae;
    case 33u: goto L_00000ebe;
    case 34u: goto L_00000ecc;
    case 35u: goto L_00000ed8;
    case 36u: goto L_00000ee2;
    case 37u: goto L_00000ef2;
    case 38u: goto L_00000f02;
    case 39u: goto L_00000f08;
    case 40u: goto L_00000f1a;
    case 41u: goto L_00000f1e;
    case 42u: goto L_00000f24;
    case 43u: goto L_00000f2c;
    case 44u: goto L_00000f36;
    case 45u: goto L_00000f3a;
    case 46u: goto L_00000f44;
    case 47u: goto L_00000f4c;
    case 48u: goto L_00000f56;
    case 49u: goto L_00000f5a;
    case 50u: goto L_00000f5e;
    case 51u: goto L_00000f64;
    case 52u: goto L_00000f6a;
    case 53u: goto L_00000f6e;
    case 54u: goto L_00000f72;
    case 55u: goto L_00000f76;
    case 56u: goto L_00000f7a;
    case 57u: goto L_00000f82;
    case 58u: goto L_00000f86;
    case 59u: goto L_00000f8a;
    case 60u: goto L_00000f8c;
    case 61u: goto L_00000f94;
    case 62u: goto L_00000f9c;
    case 63u: goto L_00000fa4;
    default: result = AGR_AOT_MISS; goto L_exit;
    }
L_00000cdc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3292u, s->source_elf + 3292u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { uint32_t addr = s->r[13] - 4u; s->r[13] = addr; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[14]); }
    instructions++;
    regs[15] = s->bias + 3296u;
L_after_00000cdc:
    blocks_done++;
    if (regs[15] == s->bias + 3296u) goto L_00000ce0;
    goto L_exit;
L_00000ce0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3296u, s->source_elf + 3296u, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
    { uint32_t addr = (s->bias + 3304u) + 4u; if ((rc = agr_aot_ldr(s, 14, addr))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000ce0; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_add_imm(s, 14, (s->bias + 3308u), s->r[14]);
    instructions++;
    { uint32_t addr = s->r[14] + 8u; s->r[14] = addr; if ((rc = agr_aot_ldr(s, 15, addr))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000ce0; } result = rc; goto L_exit; } }
    instructions++;
L_after_00000ce0:
    blocks_done++;
    goto L_exit;
L_00000cfc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3324u, s->source_elf + 3324u, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3336u, s->source_elf + 3336u, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3348u, s->source_elf + 3348u, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3360u, s->source_elf + 3360u, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3372u, s->source_elf + 3372u, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3384u, s->source_elf + 3384u, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3396u, s->source_elf + 3396u, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3408u, s->source_elf + 3408u, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3456u, s->source_elf + 3456u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    { uint32_t addr = (s->bias + 3464u) + 4u; if ((rc = agr_aot_ldr(s, 0, addr))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000d80; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_add_imm(s, 0, (s->bias + 3468u), s->r[0]);
    instructions++;
    regs[15] = s->bias + 3464u;
L_after_00000d80:
    blocks_done++;
    goto L_exit;
L_00000dc4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3524u, s->source_elf + 3524u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 20472u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 3528u;
L_after_00000dc4:
    blocks_done++;
    if (regs[15] == s->bias + 3528u) goto L_00000dc8;
    goto L_exit;
L_00000dc8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3528u, s->source_elf + 3528u, 20u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 10, 3);
    instructions++;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000dc8; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 1, 2);
    instructions++;
    agr_aot_mov_reg(s, 8, 2);
    instructions++;
    agr_aot_movs_imm(s, 2, 0u);
    instructions++;
    agr_aot_mov_reg(s, 4, 0);
    instructions++;
    { int rc = agr_aot_ldr(s, 6, s->r[13] + 40u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000dc8; } result = rc; goto L_exit; } }
    instructions++;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000dc8; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_branch_reg(s, s->r[3], (s->bias + 3548u), 1); { instructions++; goto L_after_00000dc8; }
L_after_00000dc8:
    blocks_done++;
    goto L_exit;
L_00000ddc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3548u, s->source_elf + 3548u, 16u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3564u, s->source_elf + 3564u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3568u, s->source_elf + 3568u, 14u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3582u, s->source_elf + 3582u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3586u, s->source_elf + 3586u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3588u, s->source_elf + 3588u, 14u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3602u, s->source_elf + 3602u, 16u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3618u, s->source_elf + 3618u, 14u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3632u, s->source_elf + 3632u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3634u, s->source_elf + 3634u, 14u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3648u, s->source_elf + 3648u, 14u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3662u, s->source_elf + 3662u, 16u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3678u, s->source_elf + 3678u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3680u, s->source_elf + 3680u, 16u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3696u, s->source_elf + 3696u, 16u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3712u, s->source_elf + 3712u, 16u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3728u, s->source_elf + 3728u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    if ((rc = agr_aot_ldmia_sp(s, 36856u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000e90; } result = rc; goto L_exit; }
    instructions++;
L_after_00000e90:
    blocks_done++;
    goto L_exit;
L_00000e94:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3732u, s->source_elf + 3732u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 17400u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 3736u;
L_after_00000e94:
    blocks_done++;
    if (regs[15] == s->bias + 3736u) goto L_00000e98;
    goto L_exit;
L_00000e98:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3736u, s->source_elf + 3736u, 22u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 7, 3);
    instructions++;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000e98; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 8, 2);
    instructions++;
    agr_aot_mov_reg(s, 1, 2);
    instructions++;
    agr_aot_movs_imm(s, 2, 0u);
    instructions++;
    agr_aot_mov_reg(s, 4, 0);
    instructions++;
    agr_aot_movw(s, 9, 5126u);
    instructions++;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 756u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000e98; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_branch_reg(s, s->r[3], (s->bias + 3758u), 1); { instructions++; goto L_after_00000e98; }
L_after_00000e98:
    blocks_done++;
    goto L_exit;
L_00000eae:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3758u, s->source_elf + 3758u, 16u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3774u, s->source_elf + 3774u, 14u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3788u, s->source_elf + 3788u, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3800u, s->source_elf + 3800u, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3810u, s->source_elf + 3810u, 16u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3826u, s->source_elf + 3826u, 16u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3842u, s->source_elf + 3842u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    if ((rc = agr_aot_ldmia_sp(s, 33784u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000f02; } result = rc; goto L_exit; }
    instructions++;
L_after_00000f02:
    blocks_done++;
    goto L_exit;
L_00000f08:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3848u, s->source_elf + 3848u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000f08; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_lsls(s, 2, s->r[3], 1u);
    instructions++;
    agr_aot_set_itstate(s, 76u); s->r[15] = (s->bias + 3854u); { instructions++; goto L_after_00000f08; }
L_after_00000f08:
    blocks_done++;
    goto L_exit;
L_00000f1a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3866u, s->source_elf + 3866u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 20471u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 3870u;
L_after_00000f1a:
    blocks_done++;
    if (regs[15] == s->bias + 3870u) goto L_00000f1e;
    goto L_exit;
L_00000f1e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3870u, s->source_elf + 3870u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 9, 0);
    instructions++;
    agr_aot_mov_reg(s, 6, 2);
    instructions++;
    s->r[15] = !s->r[1] ? (s->bias + 3950u) : (s->bias + 3876u); { instructions++; goto L_after_00000f1e; }
L_after_00000f1e:
    blocks_done++;
    if (regs[15] == s->bias + 3950u) goto L_00000f6e;
    if (regs[15] == s->bias + 3876u) goto L_00000f24;
    goto L_exit;
L_00000f24:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3876u, s->source_elf + 3876u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 8, s->r[1], 1023u);
    instructions++;
    agr_aot_movs_imm(s, 7, 0u);
    instructions++;
    agr_aot_mov_reg(s, 10, 8);
    instructions++;
    regs[15] = s->bias + 3884u;
L_after_00000f24:
    blocks_done++;
    if (regs[15] == s->bias + 3884u) goto L_00000f2c;
    goto L_exit;
L_00000f2c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3884u, s->source_elf + 3884u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 4, s->r[7], s->r[10]);
    instructions++;
    regs[15] = s->bias + 3888u;
L_after_00000f2c:
    blocks_done++;
    goto L_exit;
L_00000f36:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3894u, s->source_elf + 3894u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_lsls(s, 3, s->r[4], 3u);
    instructions++;
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[3]); }
    instructions++;
    regs[15] = s->bias + 3898u;
L_after_00000f36:
    blocks_done++;
    if (regs[15] == s->bias + 3898u) goto L_00000f3a;
    goto L_exit;
L_00000f3a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3898u, s->source_elf + 3898u, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 5, s->r[9], s->r[3]);
    instructions++;
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 3848u) | 1u, (s->bias + 3908u), 1); { instructions++; goto L_after_00000f3a; }
L_after_00000f3a:
    blocks_done++;
    if (regs[15] == s->bias + 3848u) goto L_00000f08;
    goto L_exit;
L_00000f44:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3908u, s->source_elf + 3908u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[4], s->r[8]);
    instructions++;
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 4u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000f44; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 11, 0);
    instructions++;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 3958u) : (s->bias + 3916u); { instructions++; goto L_after_00000f44; }
L_after_00000f44:
    blocks_done++;
    if (regs[15] == s->bias + 3958u) goto L_00000f76;
    if (regs[15] == s->bias + 3916u) goto L_00000f4c;
    goto L_exit;
L_00000f4c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3916u, s->source_elf + 3916u, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 0, s->r[3], 8u);
    instructions++;
    s->r[0] += s->r[9];
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 3848u) | 1u, (s->bias + 3926u), 1); { instructions++; goto L_after_00000f4c; }
L_after_00000f4c:
    blocks_done++;
    if (regs[15] == s->bias + 3848u) goto L_00000f08;
    goto L_exit;
L_00000f56:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3926u, s->source_elf + 3926u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[6], s->r[11]);
    instructions++;
    s->r[15] = agr_aot_condition(s, 2u) ? (s->bias + 3940u) : (s->bias + 3930u); { instructions++; goto L_after_00000f56; }
L_after_00000f56:
    blocks_done++;
    if (regs[15] == s->bias + 3940u) goto L_00000f64;
    if (regs[15] == s->bias + 3930u) goto L_00000f5a;
    goto L_exit;
L_00000f5a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3930u, s->source_elf + 3930u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[4], s->r[7]);
    instructions++;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 3954u) : (s->bias + 3934u); { instructions++; goto L_after_00000f5a; }
L_after_00000f5a:
    blocks_done++;
    if (regs[15] == s->bias + 3954u) goto L_00000f72;
    if (regs[15] == s->bias + 3934u) goto L_00000f5e;
    goto L_exit;
L_00000f5e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3934u, s->source_elf + 3934u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 10, s->r[4], 1023u);
    instructions++;
    s->r[15] = (s->bias + 3884u); { instructions++; goto L_after_00000f5e; }
L_after_00000f5e:
    blocks_done++;
    if (regs[15] == s->bias + 3884u) goto L_00000f2c;
    goto L_exit;
L_00000f64:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3940u, s->source_elf + 3940u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_subs(s, 0, s->r[0], 1u);
    instructions++;
    agr_aot_cmp(s, s->r[6], s->r[0]);
    instructions++;
    s->r[15] = agr_aot_condition(s, 9u) ? (s->bias + 3962u) : (s->bias + 3946u); { instructions++; goto L_after_00000f64; }
L_after_00000f64:
    blocks_done++;
    if (regs[15] == s->bias + 3962u) goto L_00000f7a;
    if (regs[15] == s->bias + 3946u) goto L_00000f6a;
    goto L_exit;
L_00000f6a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3946u, s->source_elf + 3946u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_adds(s, 7, s->r[4], 1u);
    instructions++;
    s->r[15] = (s->bias + 3884u); { instructions++; goto L_after_00000f6a; }
L_after_00000f6a:
    blocks_done++;
    if (regs[15] == s->bias + 3884u) goto L_00000f2c;
    goto L_exit;
L_00000f6e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3950u, s->source_elf + 3950u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3954u, s->source_elf + 3954u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 5, 0u);
    instructions++;
    s->r[15] = (s->bias + 3962u); { instructions++; goto L_after_00000f72; }
L_after_00000f72:
    blocks_done++;
    if (regs[15] == s->bias + 3962u) goto L_00000f7a;
    goto L_exit;
L_00000f76:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3958u, s->source_elf + 3958u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[6], s->r[0]);
    instructions++;
    s->r[15] = agr_aot_condition(s, 3u) ? (s->bias + 3930u) : (s->bias + 3962u); { instructions++; goto L_after_00000f76; }
L_after_00000f76:
    blocks_done++;
    if (regs[15] == s->bias + 3930u) goto L_00000f5a;
    if (regs[15] == s->bias + 3962u) goto L_00000f7a;
    goto L_exit;
L_00000f7a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3962u, s->source_elf + 3962u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    s->r[13] += 12u;
    instructions++;
    if ((rc = agr_aot_ldmia_sp(s, 36848u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000f7a; } result = rc; goto L_exit; }
    instructions++;
L_after_00000f7a:
    blocks_done++;
    goto L_exit;
L_00000f82:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3970u, s->source_elf + 3970u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[0], 1u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 3988u) : (s->bias + 3974u); { instructions++; goto L_after_00000f82; }
L_after_00000f82:
    blocks_done++;
    if (regs[15] == s->bias + 3988u) goto L_00000f94;
    if (regs[15] == s->bias + 3974u) goto L_00000f86;
    goto L_exit;
L_00000f86:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3974u, s->source_elf + 3974u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[0], 2u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 3996u) : (s->bias + 3978u); { instructions++; goto L_after_00000f86; }
L_after_00000f86:
    blocks_done++;
    if (regs[15] == s->bias + 3996u) goto L_00000f9c;
    if (regs[15] == s->bias + 3978u) goto L_00000f8a;
    goto L_exit;
L_00000f8a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3978u, s->source_elf + 3978u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 3980u, s->source_elf + 3980u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 0, (s->bias + 3984u) + 24u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000f8c; } result = rc; goto L_exit; } }
    instructions++;
    s->r[0] += (s->bias + 3986u);
    instructions++;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000f8c; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00000f8c; }
L_after_00000f8c:
    blocks_done++;
    goto L_exit;
L_00000f94:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3988u, s->source_elf + 3988u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 0, (s->bias + 3992u) + 20u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000f94; } result = rc; goto L_exit; } }
    instructions++;
    s->r[0] += (s->bias + 3994u);
    instructions++;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000f94; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00000f94; }
L_after_00000f94:
    blocks_done++;
    goto L_exit;
L_00000f9c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 3996u, s->source_elf + 3996u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 0, (s->bias + 4000u) + 16u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000f9c; } result = rc; goto L_exit; } }
    instructions++;
    s->r[0] += (s->bias + 4002u);
    instructions++;
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000f9c; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00000f9c; }
L_after_00000f9c:
    blocks_done++;
    goto L_exit;
L_00000fa4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4004u, s->source_elf + 4004u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 0u);
    instructions++;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00000fa4; }
L_after_00000fa4:
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
    if (!outer->source_elf) return AGR_AOT_MISS;
    uint32_t regs[16];
    memcpy(regs, outer->r, sizeof(regs));
    uint32_t cpsr = *outer->cpsr;
    AgrAotRegs local = {regs, &cpsr, outer->mem, outer->bias, 0, 0, 0, outer->source_elf, 0};
    AgrAotRegs *s = &local;
    int rc = 0, result = AGR_AOT_BOUNDARY;
    (void)rc;
    uint32_t blocks_done = 0, instructions = 0;
    switch (outer->region_entry) {
    case 0u: goto L_00000fa8;
    case 1u: goto L_00000fb4;
    case 2u: goto L_00000fb8;
    case 3u: goto L_00000fc2;
    case 4u: goto L_00000fca;
    case 5u: goto L_00000fce;
    case 6u: goto L_00000fd0;
    case 7u: goto L_00000fe2;
    case 8u: goto L_00000fe4;
    case 9u: goto L_00000fec;
    case 10u: goto L_00000ff0;
    case 11u: goto L_00000ff2;
    case 12u: goto L_00000ff6;
    case 13u: goto L_00000ffa;
    case 14u: goto L_00001000;
    case 15u: goto L_00001002;
    case 16u: goto L_00001008;
    case 17u: goto L_0000100a;
    case 18u: goto L_00001012;
    case 19u: goto L_00001014;
    case 20u: goto L_00001018;
    case 21u: goto L_0000101c;
    case 22u: goto L_00001020;
    case 23u: goto L_00001024;
    case 24u: goto L_0000102e;
    case 25u: goto L_00001032;
    case 26u: goto L_00001034;
    case 27u: goto L_0000103e;
    case 28u: goto L_00001042;
    case 29u: goto L_00001044;
    case 30u: goto L_00001046;
    case 31u: goto L_00001058;
    case 32u: goto L_0000105c;
    case 33u: goto L_00001066;
    case 34u: goto L_0000106c;
    case 35u: goto L_00001070;
    case 36u: goto L_00001072;
    case 37u: goto L_00001076;
    case 38u: goto L_0000107c;
    case 39u: goto L_00001084;
    case 40u: goto L_0000108a;
    case 41u: goto L_00001092;
    case 42u: goto L_00001098;
    case 43u: goto L_000010a4;
    case 44u: goto L_000010a6;
    case 45u: goto L_000010aa;
    case 46u: goto L_000010ae;
    case 47u: goto L_000010b2;
    case 48u: goto L_000010b6;
    case 49u: goto L_000010b8;
    case 50u: goto L_000010ba;
    case 51u: goto L_000010be;
    case 52u: goto L_000010c6;
    case 53u: goto L_000010ca;
    case 54u: goto L_000010ce;
    case 55u: goto L_000010d8;
    case 56u: goto L_000010dc;
    case 57u: goto L_000010e0;
    case 58u: goto L_000010e4;
    case 59u: goto L_000010ec;
    case 60u: goto L_000010f2;
    case 61u: goto L_000010f6;
    case 62u: goto L_0000110a;
    case 63u: goto L_0000111c;
    default: result = AGR_AOT_MISS; goto L_exit;
    }
L_00000fa8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4008u, s->source_elf + 4008u, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 22u);
    instructions++;
    agr_aot_lsls(s, 0, s->r[0], 0u);
    instructions++;
    agr_aot_movs_imm(s, 0, 18u);
    instructions++;
    agr_aot_lsls(s, 0, s->r[0], 0u);
    instructions++;
    agr_aot_movs_imm(s, 0, 14u);
    instructions++;
    agr_aot_lsls(s, 0, s->r[0], 0u);
    instructions++;
    regs[15] = s->bias + 4020u;
L_after_00000fa8:
    blocks_done++;
    if (regs[15] == s->bias + 4020u) goto L_00000fb4;
    goto L_exit;
L_00000fb4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4020u, s->source_elf + 4020u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, (s->bias + 4024u) + 148u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000fb4; } result = rc; goto L_exit; } }
    instructions++;
    if (agr_aot_stmdb_sp(s, 16499u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 4024u;
L_after_00000fb4:
    blocks_done++;
    if (regs[15] == s->bias + 4024u) goto L_00000fb8;
    goto L_exit;
L_00000fb8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4024u, s->source_elf + 4024u, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[3] += (s->bias + 4028u);
    instructions++;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000fb8; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 4, 0);
    instructions++;
    agr_aot_subs(s, 6, s->r[1], 2u);
    instructions++;
    s->r[15] = !s->r[3] ? (s->bias + 4048u) : (s->bias + 4034u); { instructions++; goto L_after_00000fb8; }
L_after_00000fb8:
    blocks_done++;
    if (regs[15] == s->bias + 4048u) goto L_00000fd0;
    if (regs[15] == s->bias + 4034u) goto L_00000fc2;
    goto L_exit;
L_00000fc2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4034u, s->source_elf + 4034u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 4042u, s->source_elf + 4042u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 4046u, s->source_elf + 4046u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 4080u); { instructions++; goto L_after_00000fce; }
L_after_00000fce:
    blocks_done++;
    if (regs[15] == s->bias + 4080u) goto L_00000ff0;
    goto L_exit;
L_00000fd0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4048u, s->source_elf + 4048u, 16u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 5, (s->bias + 4052u) + 124u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000fd0; } result = rc; goto L_exit; } }
    instructions++;
    { int rc = agr_aot_ldr(s, 3, (s->bias + 4052u) + 128u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000fd0; } result = rc; goto L_exit; } }
    instructions++;
    s->r[5] += (s->bias + 4056u);
    instructions++;
    { int rc = agr_aot_ldr(s, 5, s->r[5] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000fd0; } result = rc; goto L_exit; } }
    instructions++;
    s->r[3] += (s->bias + 4060u);
    instructions++;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000fd0; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_subs(s, 5, s->r[5], s->r[3]);
    instructions++;
    agr_aot_mov_reg(s, 0, 3);
    instructions++;
    regs[15] = s->bias + 4064u;
L_after_00000fd0:
    blocks_done++;
    goto L_exit;
L_00000fe2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4066u, s->source_elf + 4066u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[5]); }
    instructions++;
    regs[15] = s->bias + 4068u;
L_after_00000fe2:
    blocks_done++;
    if (regs[15] == s->bias + 4068u) goto L_00000fe4;
    goto L_exit;
L_00000fe4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4068u, s->source_elf + 4068u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 4076u, s->source_elf + 4076u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 5, 0);
    instructions++;
    s->r[15] = s->r[0] ? (s->bias + 4086u) : (s->bias + 4080u); { instructions++; goto L_after_00000fec; }
L_after_00000fec:
    blocks_done++;
    if (regs[15] == s->bias + 4086u) goto L_00000ff6;
    if (regs[15] == s->bias + 4080u) goto L_00000ff0;
    goto L_exit;
L_00000ff0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4080u, s->source_elf + 4080u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[5]); }
    instructions++;
    regs[15] = s->bias + 4082u;
L_after_00000ff0:
    blocks_done++;
    if (regs[15] == s->bias + 4082u) goto L_00000ff2;
    goto L_exit;
L_00000ff2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4082u, s->source_elf + 4082u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 9u);
    instructions++;
    s->r[15] = (s->bias + 4166u); { instructions++; goto L_after_00000ff2; }
L_after_00000ff2:
    blocks_done++;
    if (regs[15] == s->bias + 4166u) goto L_00001046;
    goto L_exit;
L_00000ff6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4086u, s->source_elf + 4086u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 3848u) | 1u, (s->bias + 4090u), 1); { instructions++; goto L_after_00000ff6; }
L_after_00000ff6:
    blocks_done++;
    goto L_exit;
L_00000ffa:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4090u, s->source_elf + 4090u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 4u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00000ffa; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_cmp(s, s->r[3], 1u);
    instructions++;
    { uint32_t addr = s->r[4] + 72u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[0]); }
    instructions++;
    regs[15] = s->bias + 4096u;
L_after_00000ffa:
    blocks_done++;
    if (regs[15] == s->bias + 4096u) goto L_00001000;
    goto L_exit;
L_00001000:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4096u, s->source_elf + 4096u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 4106u) : (s->bias + 4098u); { instructions++; goto L_after_00001000; }
L_after_00001000:
    blocks_done++;
    if (regs[15] == s->bias + 4106u) goto L_0000100a;
    if (regs[15] == s->bias + 4098u) goto L_00001002;
    goto L_exit;
L_00001002:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4098u, s->source_elf + 4098u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 3, 0u);
    instructions++;
    agr_aot_movs_imm(s, 0, 5u);
    instructions++;
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[3]); }
    instructions++;
    regs[15] = s->bias + 4104u;
L_after_00001002:
    blocks_done++;
    if (regs[15] == s->bias + 4104u) goto L_00001008;
    goto L_exit;
L_00001008:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4104u, s->source_elf + 4104u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 4166u); { instructions++; goto L_after_00001008; }
L_after_00001008:
    blocks_done++;
    if (regs[15] == s->bias + 4166u) goto L_00001046;
    goto L_exit;
L_0000100a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4106u, s->source_elf + 4106u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[3], 0u);
    instructions++;
    agr_aot_add_imm(s, 0, s->r[5], 4u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 10u) ? (s->bias + 4120u) : (s->bias + 4114u); { instructions++; goto L_after_0000100a; }
L_after_0000100a:
    blocks_done++;
    if (regs[15] == s->bias + 4120u) goto L_00001018;
    if (regs[15] == s->bias + 4114u) goto L_00001012;
    goto L_exit;
L_00001012:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4114u, s->source_elf + 4114u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    { uint32_t addr = s->r[4] + 76u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[0]); }
    instructions++;
    regs[15] = s->bias + 4116u;
L_after_00001012:
    blocks_done++;
    if (regs[15] == s->bias + 4116u) goto L_00001014;
    goto L_exit;
L_00001014:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4116u, s->source_elf + 4116u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 4120u, s->source_elf + 4120u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 3848u) | 1u, (s->bias + 4124u), 1); { instructions++; goto L_after_00001018; }
L_after_00001018:
    blocks_done++;
    goto L_exit;
L_0000101c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4124u, s->source_elf + 4124u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 3, 0u);
    instructions++;
    { uint32_t addr = s->r[4] + 76u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[0]); }
    instructions++;
    regs[15] = s->bias + 4128u;
L_after_0000101c:
    blocks_done++;
    if (regs[15] == s->bias + 4128u) goto L_00001020;
    goto L_exit;
L_00001020:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4128u, s->source_elf + 4128u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 0, s->r[4] + 76u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001020; } result = rc; goto L_exit; } }
    instructions++;
    { uint32_t addr = s->r[4] + 80u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[3]); }
    instructions++;
    regs[15] = s->bias + 4132u;
L_after_00001020:
    blocks_done++;
    if (regs[15] == s->bias + 4132u) goto L_00001024;
    goto L_exit;
L_00001024:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4132u, s->source_elf + 4132u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001024; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_cmp(s, s->r[3], 0u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 10u) ? (s->bias + 4158u) : (s->bias + 4138u); { instructions++; goto L_after_00001024; }
L_after_00001024:
    blocks_done++;
    if (regs[15] == s->bias + 4158u) goto L_0000103e;
    goto L_exit;
L_0000102e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4142u, s->source_elf + 4142u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 3970u) | 1u, (s->bias + 4146u), 1); { instructions++; goto L_after_0000102e; }
L_after_0000102e:
    blocks_done++;
    goto L_exit;
L_00001032:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4146u, s->source_elf + 4146u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[0]); }
    instructions++;
    regs[15] = s->bias + 4148u;
L_after_00001032:
    blocks_done++;
    if (regs[15] == s->bias + 4148u) goto L_00001034;
    goto L_exit;
L_00001034:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4148u, s->source_elf + 4148u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[0], 0u);
    instructions++;
    agr_aot_set_itstate(s, 12u); s->r[15] = (s->bias + 4152u); { instructions++; goto L_after_00001034; }
L_after_00001034:
    blocks_done++;
    goto L_exit;
L_0000103e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4158u, s->source_elf + 4158u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 3848u) | 1u, (s->bias + 4162u), 1); { instructions++; goto L_after_0000103e; }
L_after_0000103e:
    blocks_done++;
    goto L_exit;
L_00001042:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4162u, s->source_elf + 4162u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    { uint32_t addr = s->r[4] + 16u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[0]); }
    instructions++;
    regs[15] = s->bias + 4164u;
L_after_00001042:
    blocks_done++;
    if (regs[15] == s->bias + 4164u) goto L_00001044;
    goto L_exit;
L_00001044:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4164u, s->source_elf + 4164u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 0u);
    instructions++;
    regs[15] = s->bias + 4166u;
L_after_00001044:
    blocks_done++;
    if (regs[15] == s->bias + 4166u) goto L_00001046;
    goto L_exit;
L_00001046:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4166u, s->source_elf + 4166u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[13] += 8u;
    instructions++;
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001046; } result = rc; goto L_exit; }
    instructions++;
L_after_00001046:
    blocks_done++;
    goto L_exit;
L_00001058:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4184u, s->source_elf + 4184u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001058; } result = rc; goto L_exit; } }
    instructions++;
    if (agr_aot_stmdb_sp(s, 16400u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 4188u;
L_after_00001058:
    blocks_done++;
    if (regs[15] == s->bias + 4188u) goto L_0000105c;
    goto L_exit;
L_0000105c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4188u, s->source_elf + 4188u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 4, 0);
    instructions++;
    agr_aot_lsls(s, 0, s->r[3], 31u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 4u) ? (s->bias + 4214u) : (s->bias + 4194u); { instructions++; goto L_after_0000105c; }
L_after_0000105c:
    blocks_done++;
    if (regs[15] == s->bias + 4214u) goto L_00001076;
    goto L_exit;
L_00001066:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4198u, s->source_elf + 4198u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 0, s->r[4], 72u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 4210u) : (s->bias + 4204u); { instructions++; goto L_after_00001066; }
L_after_00001066:
    blocks_done++;
    if (regs[15] == s->bias + 4210u) goto L_00001072;
    if (regs[15] == s->bias + 4204u) goto L_0000106c;
    goto L_exit;
L_0000106c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4204u, s->source_elf + 4204u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 6260u) | 1u, (s->bias + 4208u), 1); { instructions++; goto L_after_0000106c; }
L_after_0000106c:
    blocks_done++;
    goto L_exit;
L_00001070:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4208u, s->source_elf + 4208u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 4214u); { instructions++; goto L_after_00001070; }
L_after_00001070:
    blocks_done++;
    if (regs[15] == s->bias + 4214u) goto L_00001076;
    goto L_exit;
L_00001072:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4210u, s->source_elf + 4210u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 6244u) | 1u, (s->bias + 4214u), 1); { instructions++; goto L_after_00001072; }
L_after_00001072:
    blocks_done++;
    goto L_exit;
L_00001076:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4214u, s->source_elf + 4214u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001076; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_lsls(s, 1, s->r[3], 29u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 4u) ? (s->bias + 4228u) : (s->bias + 4220u); { instructions++; goto L_after_00001076; }
L_after_00001076:
    blocks_done++;
    if (regs[15] == s->bias + 4228u) goto L_00001084;
    if (regs[15] == s->bias + 4220u) goto L_0000107c;
    goto L_exit;
L_0000107c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4220u, s->source_elf + 4220u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 4228u, s->source_elf + 4228u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001084; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_lsls(s, 2, s->r[3], 28u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 4u) ? (s->bias + 4242u) : (s->bias + 4234u); { instructions++; goto L_after_00001084; }
L_after_00001084:
    blocks_done++;
    if (regs[15] == s->bias + 4242u) goto L_00001092;
    if (regs[15] == s->bias + 4234u) goto L_0000108a;
    goto L_exit;
L_0000108a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4234u, s->source_elf + 4234u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 4242u, s->source_elf + 4242u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001092; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_lsls(s, 3, s->r[3], 27u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 4u) ? (s->bias + 4260u) : (s->bias + 4248u); { instructions++; goto L_after_00001092; }
L_after_00001092:
    blocks_done++;
    if (regs[15] == s->bias + 4260u) goto L_000010a4;
    if (regs[15] == s->bias + 4248u) goto L_00001098;
    goto L_exit;
L_00001098:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4248u, s->source_elf + 4248u, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 4260u, s->source_elf + 4260u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000010a4; } result = rc; goto L_exit; }
    instructions++;
L_after_000010a4:
    blocks_done++;
    goto L_exit;
L_000010a6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4262u, s->source_elf + 4262u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000010a6; } result = rc; goto L_exit; } }
    instructions++;
    s->r[15] = !s->r[3] ? (s->bias + 4270u) : (s->bias + 4266u); { instructions++; goto L_after_000010a6; }
L_after_000010a6:
    blocks_done++;
    if (regs[15] == s->bias + 4270u) goto L_000010ae;
    if (regs[15] == s->bias + 4266u) goto L_000010aa;
    goto L_exit;
L_000010aa:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4266u, s->source_elf + 4266u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 0, s->r[3] + s->r[0]); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000010aa; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_000010aa; }
L_after_000010aa:
    blocks_done++;
    goto L_exit;
L_000010ae:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4270u, s->source_elf + 4270u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 4274u, s->source_elf + 4274u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 4278u, s->source_elf + 4278u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_000010b6; }
L_after_000010b6:
    blocks_done++;
    goto L_exit;
L_000010b8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4280u, s->source_elf + 4280u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16496u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 4282u;
L_after_000010b8:
    blocks_done++;
    if (regs[15] == s->bias + 4282u) goto L_000010ba;
    goto L_exit;
L_000010ba:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4282u, s->source_elf + 4282u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 5, 0);
    instructions++;
    agr_aot_mov_reg(s, 4, 1);
    instructions++;
    regs[15] = s->bias + 4286u;
L_after_000010ba:
    blocks_done++;
    if (regs[15] == s->bias + 4286u) goto L_000010be;
    goto L_exit;
L_000010be:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4286u, s->source_elf + 4286u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 64u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000010be; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4020u) | 1u, (s->bias + 4294u), 1); { instructions++; goto L_after_000010be; }
L_after_000010be:
    blocks_done++;
    if (regs[15] == s->bias + 4020u) goto L_00000fb4;
    goto L_exit;
L_000010c6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4294u, s->source_elf + 4294u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 4298u, s->source_elf + 4298u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 3408u), (s->bias + 4302u), 1); { instructions++; goto L_after_000010ca; }
L_after_000010ca:
    blocks_done++;
    goto L_exit;
L_000010ce:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4302u, s->source_elf + 4302u, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 64u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000010ce; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_movs_imm(s, 0, 1u);
    instructions++;
    agr_aot_mov_reg(s, 1, 5);
    instructions++;
    agr_aot_mov_reg(s, 2, 4);
    instructions++;
    { uint32_t addr = s->r[5] + 20u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[3]); }
    instructions++;
    regs[15] = s->bias + 4312u;
L_after_000010ce:
    blocks_done++;
    if (regs[15] == s->bias + 4312u) goto L_000010d8;
    goto L_exit;
L_000010d8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4312u, s->source_elf + 4312u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 16u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000010d8; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_branch_reg(s, s->r[3], (s->bias + 4316u), 1); { instructions++; goto L_after_000010d8; }
L_after_000010d8:
    blocks_done++;
    goto L_exit;
L_000010dc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4316u, s->source_elf + 4316u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[0], 8u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 4286u) : (s->bias + 4320u); { instructions++; goto L_after_000010dc; }
L_after_000010dc:
    blocks_done++;
    if (regs[15] == s->bias + 4286u) goto L_000010be;
    if (regs[15] == s->bias + 4320u) goto L_000010e0;
    goto L_exit;
L_000010e0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4320u, s->source_elf + 4320u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[0], 7u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 4298u) : (s->bias + 4324u); { instructions++; goto L_after_000010e0; }
L_after_000010e0:
    blocks_done++;
    if (regs[15] == s->bias + 4298u) goto L_000010ca;
    if (regs[15] == s->bias + 4324u) goto L_000010e4;
    goto L_exit;
L_000010e4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4324u, s->source_elf + 4324u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 6);
    instructions++;
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 64u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000010e4; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4278u) | 1u, (s->bias + 4332u), 1); { instructions++; goto L_after_000010e4; }
L_after_000010e4:
    blocks_done++;
    if (regs[15] == s->bias + 4278u) goto L_000010b6;
    goto L_exit;
L_000010ec:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4332u, s->source_elf + 4332u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_adds(s, 0, s->r[4], 4u);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 6220u) | 1u, (s->bias + 4338u), 1); { instructions++; goto L_after_000010ec; }
L_after_000010ec:
    blocks_done++;
    goto L_exit;
L_000010f2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4338u, s->source_elf + 4338u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 20464u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 4342u;
L_after_000010f2:
    blocks_done++;
    if (regs[15] == s->bias + 4342u) goto L_000010f6;
    goto L_exit;
L_000010f6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4342u, s->source_elf + 4342u, 14u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_adds(s, 5, s->r[1], 4u);
    instructions++;
    { int rc = agr_aot_ldr(s, 8, s->r[0] + 12u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000010f6; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 7, 0);
    instructions++;
    { int rc = agr_aot_ldr(s, 9, s->r[0] + 24u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000010f6; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 10, 2);
    instructions++;
    regs[15] = s->bias + 4356u;
L_after_000010f6:
    blocks_done++;
    goto L_exit;
L_0000110a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4362u, s->source_elf + 4362u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 4380u, s->source_elf + 4380u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 5, s->r[13], 488u);
    instructions++;
    if (agr_aot_stm(s, 4u, 15u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 4386u;
L_after_0000111c:
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
    if (!outer->source_elf) return AGR_AOT_MISS;
    uint32_t regs[16];
    memcpy(regs, outer->r, sizeof(regs));
    uint32_t cpsr = *outer->cpsr;
    AgrAotRegs local = {regs, &cpsr, outer->mem, outer->bias, 0, 0, 0, outer->source_elf, 0};
    AgrAotRegs *s = &local;
    int rc = 0, result = AGR_AOT_BOUNDARY;
    (void)rc;
    uint32_t blocks_done = 0, instructions = 0;
    switch (outer->region_entry) {
    case 0u: goto L_00001122;
    case 1u: goto L_00001128;
    case 2u: goto L_00001130;
    case 3u: goto L_000011b4;
    case 4u: goto L_000011b8;
    case 5u: goto L_000011be;
    case 6u: goto L_000011c2;
    case 7u: goto L_000011ca;
    case 8u: goto L_000011dc;
    case 9u: goto L_000011e0;
    case 10u: goto L_000011e6;
    case 11u: goto L_000011f0;
    case 12u: goto L_000011f2;
    case 13u: goto L_000011fa;
    case 14u: goto L_00001200;
    case 15u: goto L_00001206;
    case 16u: goto L_0000120a;
    case 17u: goto L_00001212;
    case 18u: goto L_0000121a;
    case 19u: goto L_0000121c;
    case 20u: goto L_0000121e;
    case 21u: goto L_00001222;
    case 22u: goto L_0000122a;
    case 23u: goto L_0000122e;
    case 24u: goto L_00001232;
    case 25u: goto L_0000123a;
    case 26u: goto L_0000123c;
    case 27u: goto L_00001242;
    case 28u: goto L_00001244;
    case 29u: goto L_0000124e;
    case 30u: goto L_00001252;
    case 31u: goto L_00001256;
    case 32u: goto L_0000125e;
    case 33u: goto L_00001266;
    case 34u: goto L_0000126c;
    case 35u: goto L_00001270;
    case 36u: goto L_00001274;
    case 37u: goto L_00001278;
    case 38u: goto L_0000127c;
    case 39u: goto L_00001280;
    case 40u: goto L_00001282;
    case 41u: goto L_00001284;
    case 42u: goto L_0000128a;
    case 43u: goto L_0000128e;
    case 44u: goto L_00001290;
    case 45u: goto L_00001292;
    case 46u: goto L_0000129a;
    case 47u: goto L_000012b8;
    case 48u: goto L_000012bc;
    case 49u: goto L_000012be;
    case 50u: goto L_000012c6;
    case 51u: goto L_000012cc;
    case 52u: goto L_000012d4;
    case 53u: goto L_000012d6;
    case 54u: goto L_000012de;
    case 55u: goto L_000012fc;
    case 56u: goto L_00001300;
    case 57u: goto L_00001302;
    case 58u: goto L_0000130c;
    case 59u: goto L_00001310;
    case 60u: goto L_00001316;
    case 61u: goto L_0000131a;
    case 62u: goto L_00001320;
    case 63u: goto L_00001324;
    default: result = AGR_AOT_MISS; goto L_exit;
    }
L_00001122:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4386u, s->source_elf + 4386u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 3, 0u);
    instructions++;
    agr_aot_mov_reg(s, 11, 3);
    instructions++;
    { uint32_t addr = s->r[6] + 0u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[3]); }
    instructions++;
    regs[15] = s->bias + 4392u;
L_after_00001122:
    blocks_done++;
    if (regs[15] == s->bias + 4392u) goto L_00001128;
    goto L_exit;
L_00001128:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4392u, s->source_elf + 4392u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 7);
    instructions++;
    { int rc = agr_aot_ldr(s, 1, s->r[6] + 64u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001128; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4020u) | 1u, (s->bias + 4400u), 1); { instructions++; goto L_after_00001128; }
L_after_00001128:
    blocks_done++;
    goto L_exit;
L_00001130:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4400u, s->source_elf + 4400u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[10], 0u);
    instructions++;
    agr_aot_set_itstate(s, 20u); s->r[15] = (s->bias + 4406u); { instructions++; goto L_after_00001130; }
L_after_00001130:
    blocks_done++;
    goto L_exit;
L_000011b4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4532u, s->source_elf + 4532u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 4536u, s->source_elf + 4536u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[1] + 60u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000011b8; } result = rc; goto L_exit; } }
    instructions++;
    if (agr_aot_stmdb_sp(s, 16880u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 4542u;
L_after_000011b8:
    blocks_done++;
    if (regs[15] == s->bias + 4542u) goto L_000011be;
    goto L_exit;
L_000011be:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4542u, s->source_elf + 4542u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_adds(s, 5, s->r[1], 4u);
    instructions++;
    { uint32_t addr = s->r[1] + 64u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[3]); }
    instructions++;
    regs[15] = s->bias + 4546u;
L_after_000011be:
    blocks_done++;
    if (regs[15] == s->bias + 4546u) goto L_000011c2;
    goto L_exit;
L_000011c2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4546u, s->source_elf + 4546u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 7, 0);
    instructions++;
    agr_aot_mov_reg(s, 6, 1);
    instructions++;
    s->r[13] -= 480u;
    instructions++;
    regs[15] = s->bias + 4552u;
L_after_000011c2:
    blocks_done++;
    goto L_exit;
L_000011ca:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4554u, s->source_elf + 4554u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 4, s->r[13], 4u);
    instructions++;
    agr_aot_mov_reg(s, 8, 13);
    instructions++;
    regs[15] = s->bias + 4558u;
L_after_000011ca:
    blocks_done++;
    goto L_exit;
L_000011dc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4572u, s->source_elf + 4572u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stm(s, 4u, 15u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 4576u;
L_after_000011dc:
    blocks_done++;
    if (regs[15] == s->bias + 4576u) goto L_000011e0;
    goto L_exit;
L_000011e0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4576u, s->source_elf + 4576u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[3] = 4294967295u;
    instructions++;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[3]); }
    instructions++;
    regs[15] = s->bias + 4582u;
L_after_000011e0:
    blocks_done++;
    if (regs[15] == s->bias + 4582u) goto L_000011e6;
    goto L_exit;
L_000011e6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4582u, s->source_elf + 4582u, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 4592u, s->source_elf + 4592u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = s->r[0] ? (s->bias + 4626u) : (s->bias + 4594u); { instructions++; goto L_after_000011f0; }
L_after_000011f0:
    blocks_done++;
    if (regs[15] == s->bias + 4626u) goto L_00001212;
    if (regs[15] == s->bias + 4594u) goto L_000011f2;
    goto L_exit;
L_000011f2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4594u, s->source_elf + 4594u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
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
L_000011fa:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4602u, s->source_elf + 4602u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[0], 8u);
    instructions++;
    agr_aot_mov_reg(s, 4, 0);
    instructions++;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 4582u) : (s->bias + 4608u); { instructions++; goto L_after_000011fa; }
L_after_000011fa:
    blocks_done++;
    if (regs[15] == s->bias + 4582u) goto L_000011e6;
    if (regs[15] == s->bias + 4608u) goto L_00001200;
    goto L_exit;
L_00001200:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4608u, s->source_elf + 4608u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 13);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4184u) | 1u, (s->bias + 4614u), 1); { instructions++; goto L_after_00001200; }
L_after_00001200:
    blocks_done++;
    goto L_exit;
L_00001206:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4614u, s->source_elf + 4614u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[4], 6u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 4626u) : (s->bias + 4618u); { instructions++; goto L_after_00001206; }
L_after_00001206:
    blocks_done++;
    if (regs[15] == s->bias + 4626u) goto L_00001212;
    if (regs[15] == s->bias + 4618u) goto L_0000120a;
    goto L_exit;
L_0000120a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4618u, s->source_elf + 4618u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 4626u, s->source_elf + 4626u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 9u);
    instructions++;
    s->r[13] += 480u;
    instructions++;
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001212; } result = rc; goto L_exit; }
    instructions++;
L_after_00001212:
    blocks_done++;
    goto L_exit;
L_0000121a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4634u, s->source_elf + 4634u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16400u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 4636u;
L_after_0000121a:
    blocks_done++;
    if (regs[15] == s->bias + 4636u) goto L_0000121c;
    goto L_exit;
L_0000121c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4636u, s->source_elf + 4636u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    { uint32_t addr = s->r[0] + 24u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[2]); }
    instructions++;
    regs[15] = s->bias + 4638u;
L_after_0000121c:
    blocks_done++;
    if (regs[15] == s->bias + 4638u) goto L_0000121e;
    goto L_exit;
L_0000121e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4638u, s->source_elf + 4638u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 60u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0000121e; } result = rc; goto L_exit; } }
    instructions++;
    { uint32_t addr = s->r[0] + 12u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[1]); }
    instructions++;
    regs[15] = s->bias + 4642u;
L_after_0000121e:
    blocks_done++;
    if (regs[15] == s->bias + 4642u) goto L_00001222;
    goto L_exit;
L_00001222:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4642u, s->source_elf + 4642u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 1, 3);
    instructions++;
    if ((rc = agr_aot_ldmia_sp(s, 16400u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001222; } result = rc; goto L_exit; }
    instructions++;
    { uint32_t addr = s->r[3] + 64u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[2]); }
    instructions++;
    regs[15] = s->bias + 4650u;
L_after_00001222:
    blocks_done++;
    if (regs[15] == s->bias + 4650u) goto L_0000122a;
    goto L_exit;
L_0000122a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4650u, s->source_elf + 4650u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 4654u, s->source_elf + 4654u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 20u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0000122e; } result = rc; goto L_exit; } }
    instructions++;
    if (agr_aot_stmdb_sp(s, 16496u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 4658u;
L_after_0000122e:
    blocks_done++;
    if (regs[15] == s->bias + 4658u) goto L_00001232;
    goto L_exit;
L_00001232:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4658u, s->source_elf + 4658u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 5, 0);
    instructions++;
    { int rc = agr_aot_ldr(s, 6, s->r[0] + 12u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001232; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 4, 1);
    instructions++;
    { uint32_t addr = s->r[1] + 64u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[3]); }
    instructions++;
    regs[15] = s->bias + 4666u;
L_after_00001232:
    blocks_done++;
    if (regs[15] == s->bias + 4666u) goto L_0000123a;
    goto L_exit;
L_0000123a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4666u, s->source_elf + 4666u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 4668u, s->source_elf + 4668u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 4674u, s->source_elf + 4674u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 4716u); { instructions++; goto L_after_00001242; }
L_after_00001242:
    blocks_done++;
    if (regs[15] == s->bias + 4716u) goto L_0000126c;
    goto L_exit;
L_00001244:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4676u, s->source_elf + 4676u, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
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
L_0000124e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4686u, s->source_elf + 4686u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[0], 7u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 4702u) : (s->bias + 4690u); { instructions++; goto L_after_0000124e; }
L_after_0000124e:
    blocks_done++;
    if (regs[15] == s->bias + 4702u) goto L_0000125e;
    if (regs[15] == s->bias + 4690u) goto L_00001252;
    goto L_exit;
L_00001252:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4690u, s->source_elf + 4690u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[0], 8u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 4716u) : (s->bias + 4694u); { instructions++; goto L_after_00001252; }
L_after_00001252:
    blocks_done++;
    if (regs[15] == s->bias + 4716u) goto L_0000126c;
    if (regs[15] == s->bias + 4694u) goto L_00001256;
    goto L_exit;
L_00001256:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4694u, s->source_elf + 4694u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 4702u, s->source_elf + 4702u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 6);
    instructions++;
    { int rc = agr_aot_ldr(s, 1, s->r[4] + 64u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0000125e; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4278u) | 1u, (s->bias + 4710u), 1); { instructions++; goto L_after_0000125e; }
L_after_0000125e:
    blocks_done++;
    goto L_exit;
L_00001266:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4710u, s->source_elf + 4710u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_adds(s, 0, s->r[4], 4u);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 6220u) | 1u, (s->bias + 4716u), 1); { instructions++; goto L_after_00001266; }
L_after_00001266:
    blocks_done++;
    goto L_exit;
L_0000126c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4716u, s->source_elf + 4716u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 3408u), (s->bias + 4720u), 1); { instructions++; goto L_after_0000126c; }
L_after_0000126c:
    blocks_done++;
    goto L_exit;
L_00001270:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4720u, s->source_elf + 4720u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 4724u, s->source_elf + 4724u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 4536u); { instructions++; goto L_after_00001274; }
L_after_00001274:
    blocks_done++;
    if (regs[15] == s->bias + 4536u) goto L_000011b8;
    goto L_exit;
L_00001278:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4728u, s->source_elf + 4728u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 2, s->r[1] + 60u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001278; } result = rc; goto L_exit; } }
    instructions++;
    { uint32_t addr = s->r[1] + 64u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[2]); }
    instructions++;
    regs[15] = s->bias + 4732u;
L_after_00001278:
    blocks_done++;
    if (regs[15] == s->bias + 4732u) goto L_0000127c;
    goto L_exit;
L_0000127c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4732u, s->source_elf + 4732u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 4736u, s->source_elf + 4736u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00001280; }
L_after_00001280:
    blocks_done++;
    goto L_exit;
L_00001282:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4738u, s->source_elf + 4738u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16392u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 4740u;
L_after_00001282:
    blocks_done++;
    if (regs[15] == s->bias + 4740u) goto L_00001284;
    goto L_exit;
L_00001284:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4740u, s->source_elf + 4740u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 1, 0);
    instructions++;
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 8u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001284; } result = rc; goto L_exit; } }
    instructions++;
    s->r[15] = !s->r[3] ? (s->bias + 4750u) : (s->bias + 4746u); { instructions++; goto L_after_00001284; }
L_after_00001284:
    blocks_done++;
    if (regs[15] == s->bias + 4750u) goto L_0000128e;
    if (regs[15] == s->bias + 4746u) goto L_0000128a;
    goto L_exit;
L_0000128a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4746u, s->source_elf + 4746u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 4750u, s->source_elf + 4750u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0000128e; } result = rc; goto L_exit; }
    instructions++;
L_after_0000128e:
    blocks_done++;
    goto L_exit;
L_00001290:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4752u, s->source_elf + 4752u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16432u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 4754u;
L_after_00001290:
    blocks_done++;
    if (regs[15] == s->bias + 4754u) goto L_00001292;
    goto L_exit;
L_00001292:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4754u, s->source_elf + 4754u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[1], 4u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 8u) ? (s->bias + 4792u) : (s->bias + 4758u); { instructions++; goto L_after_00001292; }
L_after_00001292:
    blocks_done++;
    if (regs[15] == s->bias + 4792u) goto L_000012b8;
    goto L_exit;
L_0000129a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4762u, s->source_elf + 4762u, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_lsls(s, 5, s->r[0], 12u);
    instructions++;
    agr_aot_lsls(s, 7, s->r[1], 12u);
    instructions++;
    agr_aot_lsls(s, 3, s->r[0], 0u);
    instructions++;
    agr_aot_movs_imm(s, 0, 1u);
    instructions++;
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0000129a; } result = rc; goto L_exit; }
    instructions++;
L_after_0000129a:
    blocks_done++;
    goto L_exit;
L_000012b8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4792u, s->source_elf + 4792u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 4796u, s->source_elf + 4796u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16415u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 4798u;
L_after_000012bc:
    blocks_done++;
    if (regs[15] == s->bias + 4798u) goto L_000012be;
    goto L_exit;
L_000012be:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4798u, s->source_elf + 4798u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 2, 1);
    instructions++;
    agr_aot_movs_imm(s, 1, 0u);
    instructions++;
    agr_aot_add_imm(s, 3, s->r[13], 12u);
    instructions++;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[3]); }
    instructions++;
    regs[15] = s->bias + 4806u;
L_after_000012be:
    blocks_done++;
    if (regs[15] == s->bias + 4806u) goto L_000012c6;
    goto L_exit;
L_000012c6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4806u, s->source_elf + 4806u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 4812u, s->source_elf + 4812u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 12u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000012cc; } result = rc; goto L_exit; } }
    instructions++;
    s->r[13] += 20u;
    instructions++;
    { uint32_t addr = s->r[13]; s->r[13] = s->r[13] + 4u; if ((rc = agr_aot_ldr(s, 15, addr))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000012cc; } result = rc; goto L_exit; } }
    instructions++;
L_after_000012cc:
    blocks_done++;
    goto L_exit;
L_000012d4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4820u, s->source_elf + 4820u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16432u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 4822u;
L_after_000012d4:
    blocks_done++;
    if (regs[15] == s->bias + 4822u) goto L_000012d6;
    goto L_exit;
L_000012d6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4822u, s->source_elf + 4822u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[1], 4u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 8u) ? (s->bias + 4860u) : (s->bias + 4826u); { instructions++; goto L_after_000012d6; }
L_after_000012d6:
    blocks_done++;
    if (regs[15] == s->bias + 4860u) goto L_000012fc;
    goto L_exit;
L_000012de:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4830u, s->source_elf + 4830u, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_lsls(s, 5, s->r[0], 12u);
    instructions++;
    agr_aot_lsls(s, 7, s->r[1], 12u);
    instructions++;
    agr_aot_lsls(s, 3, s->r[0], 0u);
    instructions++;
    agr_aot_movs_imm(s, 0, 1u);
    instructions++;
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000012de; } result = rc; goto L_exit; }
    instructions++;
L_after_000012de:
    blocks_done++;
    goto L_exit;
L_000012fc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4860u, s->source_elf + 4860u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 4864u, s->source_elf + 4864u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16415u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 4866u;
L_after_00001300:
    blocks_done++;
    if (regs[15] == s->bias + 4866u) goto L_00001302;
    goto L_exit;
L_00001302:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4866u, s->source_elf + 4866u, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 3, s->r[13], 16u);
    instructions++;
    agr_aot_mov_reg(s, 4, 1);
    instructions++;
    agr_aot_movs_imm(s, 1, 0u);
    instructions++;
    { uint32_t addr = (s->r[3] - 4u); s->r[3] = s->r[3] - 4u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[2]); }
    instructions++;
    regs[15] = s->bias + 4876u;
L_after_00001302:
    blocks_done++;
    if (regs[15] == s->bias + 4876u) goto L_0000130c;
    goto L_exit;
L_0000130c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4876u, s->source_elf + 4876u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 2, 4);
    instructions++;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[3]); }
    instructions++;
    regs[15] = s->bias + 4880u;
L_after_0000130c:
    blocks_done++;
    if (regs[15] == s->bias + 4880u) goto L_00001310;
    goto L_exit;
L_00001310:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4880u, s->source_elf + 4880u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 3, 1);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4820u) | 1u, (s->bias + 4886u), 1); { instructions++; goto L_after_00001310; }
L_after_00001310:
    blocks_done++;
    if (regs[15] == s->bias + 4820u) goto L_000012d4;
    goto L_exit;
L_00001316:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4886u, s->source_elf + 4886u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[13] += 16u;
    instructions++;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001316; } result = rc; goto L_exit; }
    instructions++;
L_after_00001316:
    blocks_done++;
    goto L_exit;
L_0000131a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4890u, s->source_elf + 4890u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[2] + 60u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0000131a; } result = rc; goto L_exit; } }
    instructions++;
    if (agr_aot_stmdb_sp(s, 16880u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 4896u;
L_after_0000131a:
    blocks_done++;
    if (regs[15] == s->bias + 4896u) goto L_00001320;
    goto L_exit;
L_00001320:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4896u, s->source_elf + 4896u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_adds(s, 5, s->r[2], 4u);
    instructions++;
    { uint32_t addr = s->r[2] + 64u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[3]); }
    instructions++;
    regs[15] = s->bias + 4900u;
L_after_00001320:
    blocks_done++;
    if (regs[15] == s->bias + 4900u) goto L_00001324;
    goto L_exit;
L_00001324:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4900u, s->source_elf + 4900u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 7, 0);
    instructions++;
    agr_aot_mov_reg(s, 8, 1);
    instructions++;
    regs[15] = s->bias + 4904u;
L_after_00001324:
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
    if (!outer->source_elf) return AGR_AOT_MISS;
    uint32_t regs[16];
    memcpy(regs, outer->r, sizeof(regs));
    uint32_t cpsr = *outer->cpsr;
    AgrAotRegs local = {regs, &cpsr, outer->mem, outer->bias, 0, 0, 0, outer->source_elf, 0};
    AgrAotRegs *s = &local;
    int rc = 0, result = AGR_AOT_BOUNDARY;
    (void)rc;
    uint32_t blocks_done = 0, instructions = 0;
    switch (outer->region_entry) {
    case 0u: goto L_0000132e;
    case 1u: goto L_00001340;
    case 2u: goto L_00001344;
    case 3u: goto L_0000134c;
    case 4u: goto L_00001354;
    case 5u: goto L_00001356;
    case 6u: goto L_0000135a;
    case 7u: goto L_00001364;
    case 8u: goto L_0000136a;
    case 9u: goto L_0000136e;
    case 10u: goto L_00001378;
    case 11u: goto L_0000137e;
    case 12u: goto L_00001382;
    case 13u: goto L_00001384;
    case 14u: goto L_0000138a;
    case 15u: goto L_00001394;
    case 16u: goto L_00001398;
    case 17u: goto L_000013ae;
    case 18u: goto L_000013b0;
    case 19u: goto L_000013b2;
    case 20u: goto L_000013b8;
    case 21u: goto L_000013ba;
    case 22u: goto L_000013c0;
    case 23u: goto L_000013c2;
    case 24u: goto L_000013c8;
    case 25u: goto L_000013cc;
    case 26u: goto L_000013d0;
    case 27u: goto L_000013dc;
    case 28u: goto L_0000161c;
    case 29u: goto L_00001620;
    case 30u: goto L_00001624;
    case 31u: goto L_00001628;
    case 32u: goto L_0000162c;
    case 33u: goto L_0000163c;
    case 34u: goto L_00001646;
    case 35u: goto L_0000164a;
    case 36u: goto L_0000164c;
    case 37u: goto L_00001652;
    case 38u: goto L_00001654;
    case 39u: goto L_0000165a;
    case 40u: goto L_0000165e;
    case 41u: goto L_00001668;
    case 42u: goto L_0000166c;
    case 43u: goto L_0000166e;
    case 44u: goto L_00001730;
    case 45u: goto L_00001776;
    case 46u: goto L_00001844;
    case 47u: goto L_0000184c;
    case 48u: goto L_00001854;
    case 49u: goto L_00001860;
    case 50u: goto L_00001868;
    case 51u: goto L_00001870;
    case 52u: goto L_00001878;
    case 53u: goto L_00001880;
    case 54u: goto L_00001888;
    case 55u: goto L_00001890;
    case 56u: goto L_000018d4;
    case 57u: goto L_00001918;
    case 58u: goto L_0000192c;
    case 59u: goto L_00001940;
    case 60u: goto L_00001944;
    case 61u: goto L_00001948;
    case 62u: goto L_0000194c;
    case 63u: goto L_00001950;
    default: result = AGR_AOT_MISS; goto L_exit;
    }
L_0000132e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4910u, s->source_elf + 4910u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 4, s->r[13], 92u);
    instructions++;
    agr_aot_add_imm(s, 6, s->r[13], 88u);
    instructions++;
    regs[15] = s->bias + 4914u;
L_after_0000132e:
    blocks_done++;
    goto L_exit;
L_00001340:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4928u, s->source_elf + 4928u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stm(s, 4u, 15u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 4932u;
L_after_00001340:
    blocks_done++;
    if (regs[15] == s->bias + 4932u) goto L_00001344;
    goto L_exit;
L_00001344:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4932u, s->source_elf + 4932u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 4, 13);
    instructions++;
    s->r[3] = 4294967295u;
    instructions++;
    { uint32_t addr = s->r[6] + 0u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[3]); }
    instructions++;
    regs[15] = s->bias + 4940u;
L_after_00001344:
    blocks_done++;
    if (regs[15] == s->bias + 4940u) goto L_0000134c;
    goto L_exit;
L_0000134c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4940u, s->source_elf + 4940u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 4948u, s->source_elf + 4948u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 4950u, s->source_elf + 4950u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 4954u, s->source_elf + 4954u, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 6);
    instructions++;
    agr_aot_movs_imm(s, 1, 12u);
    instructions++;
    agr_aot_mov_reg(s, 2, 13);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4864u) | 1u, (s->bias + 4964u), 1); { instructions++; goto L_after_0000135a; }
L_after_0000135a:
    blocks_done++;
    goto L_exit;
L_00001364:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4964u, s->source_elf + 4964u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 6);
    instructions++;
    agr_aot_mov_reg(s, 1, 8);
    instructions++;
    agr_aot_branch_reg(s, s->r[7], (s->bias + 4970u), 1); { instructions++; goto L_after_00001364; }
L_after_00001364:
    blocks_done++;
    goto L_exit;
L_0000136a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4970u, s->source_elf + 4970u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[0], 0u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 4950u) : (s->bias + 4974u); { instructions++; goto L_after_0000136a; }
L_after_0000136a:
    blocks_done++;
    if (regs[15] == s->bias + 4950u) goto L_00001356;
    if (regs[15] == s->bias + 4974u) goto L_0000136e;
    goto L_exit;
L_0000136e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4974u, s->source_elf + 4974u, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
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
L_00001378:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4984u, s->source_elf + 4984u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[0], 5u);
    instructions++;
    agr_aot_mov_reg(s, 5, 0);
    instructions++;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 4996u) : (s->bias + 4990u); { instructions++; goto L_after_00001378; }
L_after_00001378:
    blocks_done++;
    if (regs[15] == s->bias + 4996u) goto L_00001384;
    if (regs[15] == s->bias + 4990u) goto L_0000137e;
    goto L_exit;
L_0000137e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4990u, s->source_elf + 4990u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[0], 9u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 4940u) : (s->bias + 4994u); { instructions++; goto L_after_0000137e; }
L_after_0000137e:
    blocks_done++;
    if (regs[15] == s->bias + 4940u) goto L_0000134c;
    if (regs[15] == s->bias + 4994u) goto L_00001382;
    goto L_exit;
L_00001382:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4994u, s->source_elf + 4994u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 4950u); { instructions++; goto L_after_00001382; }
L_after_00001382:
    blocks_done++;
    if (regs[15] == s->bias + 4950u) goto L_00001356;
    goto L_exit;
L_00001384:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 4996u, s->source_elf + 4996u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 5002u, s->source_elf + 5002u, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 5012u, s->source_elf + 5012u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 20464u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 5016u;
L_after_00001394:
    blocks_done++;
    if (regs[15] == s->bias + 5016u) goto L_00001398;
    goto L_exit;
L_00001398:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 5016u, s->source_elf + 5016u, 22u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 6, 2);
    instructions++;
    { int rc = agr_aot_ldr(s, 2, s->r[1] + 76u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001398; } result = rc; goto L_exit; } }
    instructions++;
    s->r[13] -= 36u;
    instructions++;
    agr_aot_mov_reg(s, 11, 0);
    instructions++;
    agr_aot_mov_reg(s, 4, 1);
    instructions++;
    agr_aot_adds(s, 5, s->r[2], 4u);
    instructions++;
    s->r[10] = s->r[0] & 3u;
    instructions++;
    { int rc = agr_aot_ldr(s, 2, s->r[2] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001398; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 7, 3);
    instructions++;
    { uint32_t addr = s->r[13] + 24u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[5]); }
    instructions++;
    regs[15] = s->bias + 5038u;
L_after_00001398:
    blocks_done++;
    if (regs[15] == s->bias + 5038u) goto L_000013ae;
    goto L_exit;
L_000013ae:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 5038u, s->source_elf + 5038u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    { uint32_t addr = s->r[13] + 20u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[2]); }
    instructions++;
    regs[15] = s->bias + 5040u;
L_after_000013ae:
    blocks_done++;
    if (regs[15] == s->bias + 5040u) goto L_000013b0;
    goto L_exit;
L_000013b0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 5040u, s->source_elf + 5040u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = s->r[3] ? (s->bias + 5058u) : (s->bias + 5042u); { instructions++; goto L_after_000013b0; }
L_after_000013b0:
    blocks_done++;
    if (regs[15] == s->bias + 5058u) goto L_000013c2;
    if (regs[15] == s->bias + 5042u) goto L_000013b2;
    goto L_exit;
L_000013b2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 5042u, s->source_elf + 5042u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_lsls(s, 2, s->r[2], 8u);
    instructions++;
    { uint32_t addr = s->r[13] + 29u; if (agr_aot_fault8(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store8(s, addr, s->r[3]); }
    instructions++;
    regs[15] = s->bias + 5048u;
L_after_000013b2:
    blocks_done++;
    if (regs[15] == s->bias + 5048u) goto L_000013b8;
    goto L_exit;
L_000013b8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 5048u, s->source_elf + 5048u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    { uint32_t addr = s->r[13] + 20u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[2]); }
    instructions++;
    regs[15] = s->bias + 5050u;
L_after_000013b8:
    blocks_done++;
    if (regs[15] == s->bias + 5050u) goto L_000013ba;
    goto L_exit;
L_000013ba:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 5050u, s->source_elf + 5050u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 3, 3u);
    instructions++;
    { uint32_t addr = s->r[13] + 28u; if (agr_aot_fault8(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store8(s, addr, s->r[3]); }
    instructions++;
    regs[15] = s->bias + 5056u;
L_after_000013ba:
    blocks_done++;
    if (regs[15] == s->bias + 5056u) goto L_000013c0;
    goto L_exit;
L_000013c0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 5056u, s->source_elf + 5056u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 5084u); { instructions++; goto L_after_000013c0; }
L_after_000013c0:
    blocks_done++;
    if (regs[15] == s->bias + 5084u) goto L_000013dc;
    goto L_exit;
L_000013c2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 5058u, s->source_elf + 5058u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[3], 2u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 12u) ? (s->bias + 5084u) : (s->bias + 5062u); { instructions++; goto L_after_000013c2; }
L_after_000013c2:
    blocks_done++;
    if (regs[15] == s->bias + 5084u) goto L_000013dc;
    goto L_exit;
L_000013c8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 5064u, s->source_elf + 5064u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { uint32_t addr = s->r[13] + 29u; if (agr_aot_fault8(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store8(s, addr, s->r[3]); }
    instructions++;
    regs[15] = s->bias + 5068u;
L_after_000013c8:
    blocks_done++;
    if (regs[15] == s->bias + 5068u) goto L_000013cc;
    goto L_exit;
L_000013cc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 5068u, s->source_elf + 5068u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_lsls(s, 2, s->r[2], 16u);
    instructions++;
    { uint32_t addr = s->r[13] + 20u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[2]); }
    instructions++;
    regs[15] = s->bias + 5072u;
L_after_000013cc:
    blocks_done++;
    if (regs[15] == s->bias + 5072u) goto L_000013d0;
    goto L_exit;
L_000013d0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 5072u, s->source_elf + 5072u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[3] = s->r[3] & 0xffu;
    instructions++;
    agr_aot_movs_imm(s, 2, 2u);
    instructions++;
    { uint32_t addr = s->r[13] + 28u; if (agr_aot_fault8(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store8(s, addr, s->r[2]); }
    instructions++;
    regs[15] = s->bias + 5080u;
L_after_000013d0:
    blocks_done++;
    goto L_exit;
L_000013dc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 5084u, s->source_elf + 5084u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[10], 2u);
    instructions++;
    { int rc = agr_aot_ldr(s, 3, s->r[4] + 80u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000013dc; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_set_itstate(s, 8u); s->r[15] = (s->bias + 5092u); { instructions++; goto L_after_000013dc; }
L_after_000013dc:
    blocks_done++;
    goto L_exit;
L_0000161c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 5660u, s->source_elf + 5660u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 5664u, s->source_elf + 5664u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 5668u, s->source_elf + 5668u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 5672u, s->source_elf + 5672u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16880u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 5676u;
L_after_00001628:
    blocks_done++;
    if (regs[15] == s->bias + 5676u) goto L_0000162c;
    goto L_exit;
L_0000162c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 5676u, s->source_elf + 5676u, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 4, 0);
    instructions++;
    s->r[13] -= 264u;
    instructions++;
    agr_aot_mov_reg(s, 7, 2);
    instructions++;
    agr_aot_mov_reg(s, 5, 3);
    instructions++;
    agr_aot_cmp(s, s->r[1], 4u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 8u) ? (s->bias + 5936u) : (s->bias + 5688u); { instructions++; goto L_after_0000162c; }
L_after_0000162c:
    blocks_done++;
    if (regs[15] == s->bias + 5936u) goto L_00001730;
    goto L_exit;
L_0000163c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 5692u, s->source_elf + 5692u, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_subs(s, 3, s->r[0], s->r[0]);
    instructions++;
    agr_aot_cmp(s, s->r[0], 122u);
    instructions++;
    agr_aot_lsls(s, 2, s->r[2], 1u);
    instructions++;
    agr_aot_cmp(s, s->r[5], 0u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 5936u) : (s->bias + 5702u); { instructions++; goto L_after_0000163c; }
L_after_0000163c:
    blocks_done++;
    if (regs[15] == s->bias + 5936u) goto L_00001730;
    if (regs[15] == s->bias + 5702u) goto L_00001646;
    goto L_exit;
L_00001646:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 5702u, s->source_elf + 5702u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 5706u, s->source_elf + 5706u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 1u);
    instructions++;
    regs[15] = s->bias + 5708u;
L_after_0000164a:
    blocks_done++;
    if (regs[15] == s->bias + 5708u) goto L_0000164c;
    goto L_exit;
L_0000164c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 5708u, s->source_elf + 5708u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_lsls_reg(s, 2, s->r[0], s->r[5]);
    instructions++;
    regs[15] = s->bias + 5712u;
L_after_0000164c:
    blocks_done++;
    goto L_exit;
L_00001652:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 5714u, s->source_elf + 5714u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 5726u) : (s->bias + 5716u); { instructions++; goto L_after_00001652; }
L_after_00001652:
    blocks_done++;
    if (regs[15] == s->bias + 5726u) goto L_0000165e;
    if (regs[15] == s->bias + 5716u) goto L_00001654;
    goto L_exit;
L_00001654:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 5716u, s->source_elf + 5716u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001654; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 5718u;
L_after_00001654:
    blocks_done++;
    goto L_exit;
L_0000165a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 5722u, s->source_elf + 5722u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_adds(s, 3, s->r[3], 4u);
    instructions++;
    { uint32_t addr = s->r[6] + 4u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[2]); }
    instructions++;
    regs[15] = s->bias + 5726u;
L_after_0000165a:
    blocks_done++;
    if (regs[15] == s->bias + 5726u) goto L_0000165e;
    goto L_exit;
L_0000165e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 5726u, s->source_elf + 5726u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_adds(s, 5, s->r[5], 1u);
    instructions++;
    agr_aot_cmp(s, s->r[5], 16u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 5708u) : (s->bias + 5732u); { instructions++; goto L_after_0000165e; }
L_after_0000165e:
    blocks_done++;
    if (regs[15] == s->bias + 5708u) goto L_0000164c;
    goto L_exit;
L_00001668:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 5736u, s->source_elf + 5736u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6006u) : (s->bias + 5740u); { instructions++; goto L_after_00001668; }
L_after_00001668:
    blocks_done++;
    if (regs[15] == s->bias + 6006u) goto L_00001776;
    if (regs[15] == s->bias + 5740u) goto L_0000166c;
    goto L_exit;
L_0000166c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 5740u, s->source_elf + 5740u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    { uint32_t addr = s->r[4] + 56u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[3]); }
    instructions++;
    regs[15] = s->bias + 5742u;
L_after_0000166c:
    blocks_done++;
    if (regs[15] == s->bias + 5742u) goto L_0000166e;
    goto L_exit;
L_0000166e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 5742u, s->source_elf + 5742u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 6212u); { instructions++; goto L_after_0000166e; }
L_after_0000166e:
    blocks_done++;
    if (regs[15] == s->bias + 6212u) goto L_00001844;
    goto L_exit;
L_00001730:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 5936u, s->source_elf + 5936u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 2u);
    instructions++;
    s->r[15] = (s->bias + 6212u); { instructions++; goto L_after_00001730; }
L_after_00001730:
    blocks_done++;
    if (regs[15] == s->bias + 6212u) goto L_00001844;
    goto L_exit;
L_00001776:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6006u, s->source_elf + 6006u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 0u);
    instructions++;
    s->r[15] = (s->bias + 6212u); { instructions++; goto L_after_00001776; }
L_after_00001776:
    blocks_done++;
    if (regs[15] == s->bias + 6212u) goto L_00001844;
    goto L_exit;
L_00001844:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6212u, s->source_elf + 6212u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[13] += 264u;
    instructions++;
    if ((rc = agr_aot_ldmia_sp(s, 33264u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001844; } result = rc; goto L_exit; }
    instructions++;
L_after_00001844:
    blocks_done++;
    goto L_exit;
L_0000184c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6220u, s->source_elf + 6220u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 6228u, s->source_elf + 6228u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 12, 3);
    instructions++;
    agr_aot_mov_reg(s, 14, 4);
    instructions++;
    { uint32_t addr = (s->r[12] - 4u); s->r[12] = s->r[12] - 4u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[5]); }
    instructions++;
    regs[15] = s->bias + 6236u;
L_after_00001854:
    blocks_done++;
    goto L_exit;
L_00001860:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6240u, s->source_elf + 6240u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 6248u, s->source_elf + 6248u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00001868; }
L_after_00001868:
    blocks_done++;
    goto L_exit;
L_00001870:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6256u, s->source_elf + 6256u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00001870; }
L_after_00001870:
    blocks_done++;
    goto L_exit;
L_00001878:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6264u, s->source_elf + 6264u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00001878; }
L_after_00001878:
    blocks_done++;
    goto L_exit;
L_00001880:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6272u, s->source_elf + 6272u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00001880; }
L_after_00001880:
    blocks_done++;
    goto L_exit;
L_00001888:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6280u, s->source_elf + 6280u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00001888; }
L_after_00001888:
    blocks_done++;
    goto L_exit;
L_00001890:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6288u, s->source_elf + 6288u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00001890; }
L_after_00001890:
    blocks_done++;
    goto L_exit;
L_000018d4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6356u, s->source_elf + 6356u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_000018d4; }
L_after_000018d4:
    blocks_done++;
    goto L_exit;
L_00001918:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6424u, s->source_elf + 6424u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00001918; }
L_after_00001918:
    blocks_done++;
    goto L_exit;
L_0000192c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6444u, s->source_elf + 6444u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_0000192c; }
L_after_0000192c:
    blocks_done++;
    goto L_exit;
L_00001940:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6464u, s->source_elf + 6464u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00001940; }
L_after_00001940:
    blocks_done++;
    goto L_exit;
L_00001944:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6468u, s->source_elf + 6468u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 12, 13);
    instructions++;
    if (agr_aot_stmdb_sp(s, 16384u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 6472u;
L_after_00001944:
    blocks_done++;
    if (regs[15] == s->bias + 6472u) goto L_00001948;
    goto L_exit;
L_00001948:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6472u, s->source_elf + 6472u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 20480u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 6476u;
L_after_00001948:
    blocks_done++;
    if (regs[15] == s->bias + 6476u) goto L_0000194c;
    goto L_exit;
L_0000194c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6476u, s->source_elf + 6476u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 8191u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 6480u;
L_after_0000194c:
    blocks_done++;
    if (regs[15] == s->bias + 6480u) goto L_00001950;
    goto L_exit;
L_00001950:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6480u, s->source_elf + 6480u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[3] = 0u;
    instructions++;
    if (agr_aot_stmdb_sp(s, 12u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 6488u;
L_after_00001950:
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
    if (!outer->source_elf) return AGR_AOT_MISS;
    uint32_t regs[16];
    memcpy(regs, outer->r, sizeof(regs));
    uint32_t cpsr = *outer->cpsr;
    AgrAotRegs local = {regs, &cpsr, outer->mem, outer->bias, 0, 0, 0, outer->source_elf, 0};
    AgrAotRegs *s = &local;
    int rc = 0, result = AGR_AOT_BOUNDARY;
    (void)rc;
    uint32_t blocks_done = 0, instructions = 0;
    switch (outer->region_entry) {
    case 0u: goto L_00001958;
    case 1u: goto L_0000195e;
    case 2u: goto L_00001968;
    case 3u: goto L_0000196c;
    case 4u: goto L_00001970;
    case 5u: goto L_00001974;
    case 6u: goto L_0000197c;
    case 7u: goto L_00001982;
    case 8u: goto L_0000198c;
    case 9u: goto L_00001990;
    case 10u: goto L_00001994;
    case 11u: goto L_00001998;
    case 12u: goto L_000019a0;
    case 13u: goto L_000019a6;
    case 14u: goto L_000019b0;
    case 15u: goto L_000019b4;
    case 16u: goto L_000019b8;
    case 17u: goto L_000019bc;
    case 18u: goto L_000019c4;
    case 19u: goto L_000019ca;
    case 20u: goto L_000019d4;
    case 21u: goto L_000019d8;
    case 22u: goto L_000019dc;
    case 23u: goto L_000019e0;
    case 24u: goto L_000019e8;
    case 25u: goto L_000019ee;
    case 26u: goto L_000019f8;
    case 27u: goto L_000019fc;
    case 28u: goto L_00001a00;
    case 29u: goto L_00001a04;
    case 30u: goto L_00001a0a;
    case 31u: goto L_00001a0e;
    case 32u: goto L_00001a12;
    case 33u: goto L_00001a14;
    case 34u: goto L_00001a16;
    case 35u: goto L_00001a1e;
    case 36u: goto L_00001a20;
    case 37u: goto L_00001a24;
    case 38u: goto L_00001a26;
    case 39u: goto L_00001a2e;
    case 40u: goto L_00001a34;
    case 41u: goto L_00001a3c;
    case 42u: goto L_00001a3e;
    case 43u: goto L_00001a42;
    case 44u: goto L_00001a50;
    case 45u: goto L_00001a56;
    case 46u: goto L_00001a5c;
    case 47u: goto L_00001a62;
    case 48u: goto L_00001a6a;
    case 49u: goto L_00001a72;
    case 50u: goto L_00001a74;
    case 51u: goto L_00001a80;
    case 52u: goto L_00001a8a;
    case 53u: goto L_00001a90;
    case 54u: goto L_00001a96;
    case 55u: goto L_00001a9e;
    case 56u: goto L_00001aa2;
    case 57u: goto L_00001aac;
    case 58u: goto L_00001ab8;
    case 59u: goto L_00001ac0;
    case 60u: goto L_00001aca;
    case 61u: goto L_00001ad0;
    case 62u: goto L_00001ad4;
    case 63u: goto L_00001ade;
    default: result = AGR_AOT_MISS; goto L_exit;
    }
L_00001958:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6488u, s->source_elf + 6488u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4536u) | 1u, (s->bias + 6494u), 1); { instructions++; goto L_after_00001958; }
L_after_00001958:
    blocks_done++;
    goto L_exit;
L_0000195e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6494u, s->source_elf + 6494u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0000195e; } result = rc; goto L_exit; } }
    instructions++;
    s->r[13] += 72u;
    instructions++;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_0000195e; }
L_after_0000195e:
    blocks_done++;
    goto L_exit;
L_00001968:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6504u, s->source_elf + 6504u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 12, 13);
    instructions++;
    if (agr_aot_stmdb_sp(s, 16384u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 6508u;
L_after_00001968:
    blocks_done++;
    if (regs[15] == s->bias + 6508u) goto L_0000196c;
    goto L_exit;
L_0000196c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6508u, s->source_elf + 6508u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 20480u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 6512u;
L_after_0000196c:
    blocks_done++;
    if (regs[15] == s->bias + 6512u) goto L_00001970;
    goto L_exit;
L_00001970:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6512u, s->source_elf + 6512u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 8191u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 6516u;
L_after_00001970:
    blocks_done++;
    if (regs[15] == s->bias + 6516u) goto L_00001974;
    goto L_exit;
L_00001974:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6516u, s->source_elf + 6516u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[3] = 0u;
    instructions++;
    if (agr_aot_stmdb_sp(s, 12u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 6524u;
L_after_00001974:
    blocks_done++;
    if (regs[15] == s->bias + 6524u) goto L_0000197c;
    goto L_exit;
L_0000197c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6524u, s->source_elf + 6524u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4654u) | 1u, (s->bias + 6530u), 1); { instructions++; goto L_after_0000197c; }
L_after_0000197c:
    blocks_done++;
    goto L_exit;
L_00001982:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6530u, s->source_elf + 6530u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001982; } result = rc; goto L_exit; } }
    instructions++;
    s->r[13] += 72u;
    instructions++;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00001982; }
L_after_00001982:
    blocks_done++;
    goto L_exit;
L_0000198c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6540u, s->source_elf + 6540u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 12, 13);
    instructions++;
    if (agr_aot_stmdb_sp(s, 16384u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 6544u;
L_after_0000198c:
    blocks_done++;
    if (regs[15] == s->bias + 6544u) goto L_00001990;
    goto L_exit;
L_00001990:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6544u, s->source_elf + 6544u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 20480u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 6548u;
L_after_00001990:
    blocks_done++;
    if (regs[15] == s->bias + 6548u) goto L_00001994;
    goto L_exit;
L_00001994:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6548u, s->source_elf + 6548u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 8191u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 6552u;
L_after_00001994:
    blocks_done++;
    if (regs[15] == s->bias + 6552u) goto L_00001998;
    goto L_exit;
L_00001998:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6552u, s->source_elf + 6552u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[3] = 0u;
    instructions++;
    if (agr_aot_stmdb_sp(s, 12u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 6560u;
L_after_00001998:
    blocks_done++;
    if (regs[15] == s->bias + 6560u) goto L_000019a0;
    goto L_exit;
L_000019a0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6560u, s->source_elf + 6560u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4720u) | 1u, (s->bias + 6566u), 1); { instructions++; goto L_after_000019a0; }
L_after_000019a0:
    blocks_done++;
    goto L_exit;
L_000019a6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6566u, s->source_elf + 6566u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000019a6; } result = rc; goto L_exit; } }
    instructions++;
    s->r[13] += 72u;
    instructions++;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_000019a6; }
L_after_000019a6:
    blocks_done++;
    goto L_exit;
L_000019b0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6576u, s->source_elf + 6576u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 12, 13);
    instructions++;
    if (agr_aot_stmdb_sp(s, 16384u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 6580u;
L_after_000019b0:
    blocks_done++;
    if (regs[15] == s->bias + 6580u) goto L_000019b4;
    goto L_exit;
L_000019b4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6580u, s->source_elf + 6580u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 20480u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 6584u;
L_after_000019b4:
    blocks_done++;
    if (regs[15] == s->bias + 6584u) goto L_000019b8;
    goto L_exit;
L_000019b8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6584u, s->source_elf + 6584u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 8191u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 6588u;
L_after_000019b8:
    blocks_done++;
    if (regs[15] == s->bias + 6588u) goto L_000019bc;
    goto L_exit;
L_000019bc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6588u, s->source_elf + 6588u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[3] = 0u;
    instructions++;
    if (agr_aot_stmdb_sp(s, 12u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 6596u;
L_after_000019bc:
    blocks_done++;
    if (regs[15] == s->bias + 6596u) goto L_000019c4;
    goto L_exit;
L_000019c4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6596u, s->source_elf + 6596u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 3, s->r[13], 4u);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4634u) | 1u, (s->bias + 6602u), 1); { instructions++; goto L_after_000019c4; }
L_after_000019c4:
    blocks_done++;
    goto L_exit;
L_000019ca:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6602u, s->source_elf + 6602u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000019ca; } result = rc; goto L_exit; } }
    instructions++;
    s->r[13] += 72u;
    instructions++;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_000019ca; }
L_after_000019ca:
    blocks_done++;
    goto L_exit;
L_000019d4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6612u, s->source_elf + 6612u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 12, 13);
    instructions++;
    if (agr_aot_stmdb_sp(s, 16384u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 6616u;
L_after_000019d4:
    blocks_done++;
    if (regs[15] == s->bias + 6616u) goto L_000019d8;
    goto L_exit;
L_000019d8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6616u, s->source_elf + 6616u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 20480u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 6620u;
L_after_000019d8:
    blocks_done++;
    if (regs[15] == s->bias + 6620u) goto L_000019dc;
    goto L_exit;
L_000019dc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6620u, s->source_elf + 6620u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 8191u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 6624u;
L_after_000019dc:
    blocks_done++;
    if (regs[15] == s->bias + 6624u) goto L_000019e0;
    goto L_exit;
L_000019e0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6624u, s->source_elf + 6624u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[3] = 0u;
    instructions++;
    if (agr_aot_stmdb_sp(s, 12u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 6632u;
L_after_000019e0:
    blocks_done++;
    if (regs[15] == s->bias + 6632u) goto L_000019e8;
    goto L_exit;
L_000019e8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6632u, s->source_elf + 6632u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 2, s->r[13], 4u);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4890u) | 1u, (s->bias + 6638u), 1); { instructions++; goto L_after_000019e8; }
L_after_000019e8:
    blocks_done++;
    goto L_exit;
L_000019ee:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6638u, s->source_elf + 6638u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 14, s->r[13] + 64u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000019ee; } result = rc; goto L_exit; } }
    instructions++;
    s->r[13] += 72u;
    instructions++;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_000019ee; }
L_after_000019ee:
    blocks_done++;
    goto L_exit;
L_000019f8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6648u, s->source_elf + 6648u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 8u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000019f8; } result = rc; goto L_exit; } }
    instructions++;
    s->r[15] = s->r[3] ? (s->bias + 6674u) : (s->bias + 6652u); { instructions++; goto L_after_000019f8; }
L_after_000019f8:
    blocks_done++;
    if (regs[15] == s->bias + 6674u) goto L_00001a12;
    if (regs[15] == s->bias + 6652u) goto L_000019fc;
    goto L_exit;
L_000019fc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6652u, s->source_elf + 6652u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 9u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000019fc; } result = rc; goto L_exit; } }
    instructions++;
    s->r[15] = !s->r[3] ? (s->bias + 6688u) : (s->bias + 6656u); { instructions++; goto L_after_000019fc; }
L_after_000019fc:
    blocks_done++;
    if (regs[15] == s->bias + 6688u) goto L_00001a20;
    if (regs[15] == s->bias + 6656u) goto L_00001a00;
    goto L_exit;
L_00001a00:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6656u, s->source_elf + 6656u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_subs(s, 3, s->r[3], 1u);
    instructions++;
    { uint32_t addr = s->r[0] + 9u; if (agr_aot_fault8(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store8(s, addr, s->r[3]); }
    instructions++;
    regs[15] = s->bias + 6660u;
L_after_00001a00:
    blocks_done++;
    if (regs[15] == s->bias + 6660u) goto L_00001a04;
    goto L_exit;
L_00001a04:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6660u, s->source_elf + 6660u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 4u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001a04; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_adds(s, 2, s->r[3], 4u);
    instructions++;
    { uint32_t addr = s->r[0] + 4u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[2]); }
    instructions++;
    regs[15] = s->bias + 6666u;
L_after_00001a04:
    blocks_done++;
    if (regs[15] == s->bias + 6666u) goto L_00001a0a;
    goto L_exit;
L_00001a0a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6666u, s->source_elf + 6666u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001a0a; } result = rc; goto L_exit; } }
    instructions++;
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[3]); }
    instructions++;
    regs[15] = s->bias + 6670u;
L_after_00001a0a:
    blocks_done++;
    if (regs[15] == s->bias + 6670u) goto L_00001a0e;
    goto L_exit;
L_00001a0e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6670u, s->source_elf + 6670u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 3, 3u);
    instructions++;
    s->r[15] = (s->bias + 6676u); { instructions++; goto L_after_00001a0e; }
L_after_00001a0e:
    blocks_done++;
    if (regs[15] == s->bias + 6676u) goto L_00001a14;
    goto L_exit;
L_00001a12:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6674u, s->source_elf + 6674u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_subs(s, 3, s->r[3], 1u);
    instructions++;
    regs[15] = s->bias + 6676u;
L_after_00001a12:
    blocks_done++;
    if (regs[15] == s->bias + 6676u) goto L_00001a14;
    goto L_exit;
L_00001a14:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6676u, s->source_elf + 6676u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    { uint32_t addr = s->r[0] + 8u; if (agr_aot_fault8(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store8(s, addr, s->r[3]); }
    instructions++;
    regs[15] = s->bias + 6678u;
L_after_00001a14:
    blocks_done++;
    if (regs[15] == s->bias + 6678u) goto L_00001a16;
    goto L_exit;
L_00001a16:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6678u, s->source_elf + 6678u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001a16; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_lsls(s, 2, s->r[3], 8u);
    instructions++;
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[2]); }
    instructions++;
    regs[15] = s->bias + 6684u;
L_after_00001a16:
    blocks_done++;
    goto L_exit;
L_00001a1e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6686u, s->source_elf + 6686u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_00001a1e; }
L_after_00001a1e:
    blocks_done++;
    goto L_exit;
L_00001a20:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6688u, s->source_elf + 6688u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 6692u, s->source_elf + 6692u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16415u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 6694u;
L_after_00001a24:
    blocks_done++;
    if (regs[15] == s->bias + 6694u) goto L_00001a26;
    goto L_exit;
L_00001a26:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6694u, s->source_elf + 6694u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 1, 0u);
    instructions++;
    agr_aot_add_imm(s, 3, s->r[13], 12u);
    instructions++;
    agr_aot_movs_imm(s, 2, 12u);
    instructions++;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[3]); }
    instructions++;
    regs[15] = s->bias + 6702u;
L_after_00001a26:
    blocks_done++;
    if (regs[15] == s->bias + 6702u) goto L_00001a2e;
    goto L_exit;
L_00001a2e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6702u, s->source_elf + 6702u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 6708u, s->source_elf + 6708u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 0, s->r[13] + 12u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001a34; } result = rc; goto L_exit; } }
    instructions++;
    s->r[13] += 20u;
    instructions++;
    { uint32_t addr = s->r[13]; s->r[13] = s->r[13] + 4u; if ((rc = agr_aot_ldr(s, 15, addr))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001a34; } result = rc; goto L_exit; } }
    instructions++;
L_after_00001a34:
    blocks_done++;
    goto L_exit;
L_00001a3c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6716u, s->source_elf + 6716u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 6692u); { instructions++; goto L_after_00001a3c; }
L_after_00001a3c:
    blocks_done++;
    if (regs[15] == s->bias + 6692u) goto L_00001a24;
    goto L_exit;
L_00001a3e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6718u, s->source_elf + 6718u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 18431u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 6722u;
L_after_00001a3e:
    blocks_done++;
    if (regs[15] == s->bias + 6722u) goto L_00001a42;
    goto L_exit;
L_00001a42:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6722u, s->source_elf + 6722u, 14u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 5, 0);
    instructions++;
    agr_aot_mov_reg(s, 6, 1);
    instructions++;
    agr_aot_movs_imm(s, 7, 0u);
    instructions++;
    agr_aot_add_imm(s, 8, s->r[13], 12u);
    instructions++;
    s->r[9] = 4080u;
    instructions++;
    regs[15] = s->bias + 6736u;
L_after_00001a42:
    blocks_done++;
    if (regs[15] == s->bias + 6736u) goto L_00001a50;
    goto L_exit;
L_00001a50:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6736u, s->source_elf + 6736u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 6);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 6742u), 1); { instructions++; goto L_after_00001a50; }
L_after_00001a50:
    blocks_done++;
    if (regs[15] == s->bias + 6648u) goto L_000019f8;
    goto L_exit;
L_00001a56:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6742u, s->source_elf + 6742u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[0], 176u);
    instructions++;
    agr_aot_mov_reg(s, 4, 0);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6786u) : (s->bias + 6748u); { instructions++; goto L_after_00001a56; }
L_after_00001a56:
    blocks_done++;
    if (regs[15] == s->bias + 6748u) goto L_00001a5c;
    goto L_exit;
L_00001a5c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6748u, s->source_elf + 6748u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[7], 0u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7316u) : (s->bias + 6754u); { instructions++; goto L_after_00001a5c; }
L_after_00001a5c:
    blocks_done++;
    if (regs[15] == s->bias + 6754u) goto L_00001a62;
    goto L_exit;
L_00001a62:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6754u, s->source_elf + 6754u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 4, s->r[13], 12u);
    instructions++;
    agr_aot_mov_reg(s, 1, 7);
    instructions++;
    agr_aot_mov_reg(s, 3, 7);
    instructions++;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[4]); }
    instructions++;
    regs[15] = s->bias + 6762u;
L_after_00001a62:
    blocks_done++;
    if (regs[15] == s->bias + 6762u) goto L_00001a6a;
    goto L_exit;
L_00001a6a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6762u, s->source_elf + 6762u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    agr_aot_movs_imm(s, 2, 14u);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4752u) | 1u, (s->bias + 6770u), 1); { instructions++; goto L_after_00001a6a; }
L_after_00001a6a:
    blocks_done++;
    goto L_exit;
L_00001a72:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6770u, s->source_elf + 6770u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[4]); }
    instructions++;
    regs[15] = s->bias + 6772u;
L_after_00001a72:
    blocks_done++;
    if (regs[15] == s->bias + 6772u) goto L_00001a74;
    goto L_exit;
L_00001a74:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6772u, s->source_elf + 6772u, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 6784u, s->source_elf + 6784u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 7316u); { instructions++; goto L_after_00001a80; }
L_after_00001a80:
    blocks_done++;
    goto L_exit;
L_00001a8a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6794u, s->source_elf + 6794u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6840u) : (s->bias + 6796u); { instructions++; goto L_after_00001a8a; }
L_after_00001a8a:
    blocks_done++;
    if (regs[15] == s->bias + 6840u) goto L_00001ab8;
    goto L_exit;
L_00001a90:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6800u, s->source_elf + 6800u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 3, 1);
    instructions++;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[8]); }
    instructions++;
    regs[15] = s->bias + 6806u;
L_after_00001a90:
    blocks_done++;
    if (regs[15] == s->bias + 6806u) goto L_00001a96;
    goto L_exit;
L_00001a96:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6806u, s->source_elf + 6806u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 6814u, s->source_elf + 6814u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 4752u) | 1u, (s->bias + 6818u), 1); { instructions++; goto L_after_00001a9e; }
L_after_00001a9e:
    blocks_done++;
    goto L_exit;
L_00001aa2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6818u, s->source_elf + 6818u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 12u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001aa2; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_add_imm(s, 10, s->r[10], 4u);
    instructions++;
    regs[15] = s->bias + 6824u;
L_after_00001aa2:
    blocks_done++;
    goto L_exit;
L_00001aac:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6828u, s->source_elf + 6828u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_set_itstate(s, 20u); s->r[15] = (s->bias + 6830u); { instructions++; goto L_after_00001aac; }
L_after_00001aac:
    blocks_done++;
    goto L_exit;
L_00001ab8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6840u, s->source_elf + 6840u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[3] = s->r[0] & 240u;
    instructions++;
    agr_aot_cmp(s, s->r[3], 128u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6896u) : (s->bias + 6848u); { instructions++; goto L_after_00001ab8; }
L_after_00001ab8:
    blocks_done++;
    if (regs[15] == s->bias + 6848u) goto L_00001ac0;
    goto L_exit;
L_00001ac0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6848u, s->source_elf + 6848u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_lsls(s, 4, s->r[0], 8u);
    instructions++;
    agr_aot_mov_reg(s, 0, 6);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 6856u), 1); { instructions++; goto L_after_00001ac0; }
L_after_00001ac0:
    blocks_done++;
    if (regs[15] == s->bias + 6648u) goto L_000019f8;
    goto L_exit;
L_00001aca:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6858u, s->source_elf + 6858u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[0], 32768u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6868u) : (s->bias + 6864u); { instructions++; goto L_after_00001aca; }
L_after_00001aca:
    blocks_done++;
    if (regs[15] == s->bias + 6868u) goto L_00001ad4;
    if (regs[15] == s->bias + 6864u) goto L_00001ad0;
    goto L_exit;
L_00001ad0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6864u, s->source_elf + 6864u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 9u);
    instructions++;
    s->r[15] = (s->bias + 7318u); { instructions++; goto L_after_00001ad0; }
L_after_00001ad0:
    blocks_done++;
    goto L_exit;
L_00001ad4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6868u, s->source_elf + 6868u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_lsls(s, 4, s->r[0], 4u);
    instructions++;
    agr_aot_movs_imm(s, 1, 0u);
    instructions++;
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    agr_aot_mov_reg(s, 3, 1);
    instructions++;
    regs[15] = s->bias + 6876u;
L_after_00001ad4:
    blocks_done++;
    goto L_exit;
L_00001ade:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6878u, s->source_elf + 6878u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 5672u) | 1u, (s->bias + 6882u), 1); { instructions++; goto L_after_00001ade; }
L_after_00001ade:
    blocks_done++;
    goto L_exit;
L_exit:
    memcpy(outer->r, regs, sizeof(regs));
    *outer->cpsr = cpsr;
    outer->region_blocks = blocks_done;
    outer->region_instructions = instructions;
    return result;
}

static int agr_region_00005(AgrAotRegs *outer) {
    if (!outer->source_elf) return AGR_AOT_MISS;
    uint32_t regs[16];
    memcpy(regs, outer->r, sizeof(regs));
    uint32_t cpsr = *outer->cpsr;
    AgrAotRegs local = {regs, &cpsr, outer->mem, outer->bias, 0, 0, 0, outer->source_elf, 0};
    AgrAotRegs *s = &local;
    int rc = 0, result = AGR_AOT_BOUNDARY;
    (void)rc;
    uint32_t blocks_done = 0, instructions = 0;
    switch (outer->region_entry) {
    case 0u: goto L_00001ae2;
    case 1u: goto L_00001aea;
    case 2u: goto L_00001af0;
    case 3u: goto L_00001af4;
    case 4u: goto L_00001afc;
    case 5u: goto L_00001b02;
    case 6u: goto L_00001b0e;
    case 7u: goto L_00001b16;
    case 8u: goto L_00001b1e;
    case 9u: goto L_00001b20;
    case 10u: goto L_00001b26;
    case 11u: goto L_00001b2e;
    case 12u: goto L_00001b40;
    case 13u: goto L_00001b44;
    case 14u: goto L_00001b48;
    case 15u: goto L_00001b4e;
    case 16u: goto L_00001b58;
    case 17u: goto L_00001b5a;
    case 18u: goto L_00001b5c;
    case 19u: goto L_00001b60;
    case 20u: goto L_00001b64;
    case 21u: goto L_00001b6e;
    case 22u: goto L_00001b76;
    case 23u: goto L_00001b80;
    case 24u: goto L_00001b8a;
    case 25u: goto L_00001b92;
    case 26u: goto L_00001b96;
    case 27u: goto L_00001b98;
    case 28u: goto L_00001b9e;
    case 29u: goto L_00001ba4;
    case 30u: goto L_00001ba6;
    case 31u: goto L_00001baa;
    case 32u: goto L_00001bae;
    case 33u: goto L_00001bb4;
    case 34u: goto L_00001bc4;
    case 35u: goto L_00001bcc;
    case 36u: goto L_00001bdc;
    case 37u: goto L_00001be0;
    case 38u: goto L_00001be4;
    case 39u: goto L_00001bea;
    case 40u: goto L_00001bfc;
    case 41u: goto L_00001bfe;
    case 42u: goto L_00001c02;
    case 43u: goto L_00001c08;
    case 44u: goto L_00001c14;
    case 45u: goto L_00001c18;
    case 46u: goto L_00001c1e;
    case 47u: goto L_00001c26;
    case 48u: goto L_00001c36;
    case 49u: goto L_00001c3a;
    case 50u: goto L_00001c40;
    case 51u: goto L_00001c4e;
    case 52u: goto L_00001c54;
    case 53u: goto L_00001c5a;
    case 54u: goto L_00001c64;
    case 55u: goto L_00001c6c;
    case 56u: goto L_00001c6e;
    case 57u: goto L_00001c78;
    case 58u: goto L_00001c86;
    case 59u: goto L_00001c88;
    case 60u: goto L_00001c8c;
    case 61u: goto L_00001c92;
    case 62u: goto L_00001c94;
    case 63u: goto L_00001c96;
    default: result = AGR_AOT_MISS; goto L_exit;
    }
L_00001ae2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6882u, s->source_elf + 6882u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[0], 0u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6864u) : (s->bias + 6886u); { instructions++; goto L_after_00001ae2; }
L_after_00001ae2:
    blocks_done++;
    goto L_exit;
L_00001aea:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6890u, s->source_elf + 6890u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_set_itstate(s, 24u); s->r[15] = (s->bias + 6892u); { instructions++; goto L_after_00001aea; }
L_after_00001aea:
    blocks_done++;
    goto L_exit;
L_00001af0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6896u, s->source_elf + 6896u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[3], 144u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6944u) : (s->bias + 6900u); { instructions++; goto L_after_00001af0; }
L_after_00001af0:
    blocks_done++;
    if (regs[15] == s->bias + 6944u) goto L_00001b20;
    if (regs[15] == s->bias + 6900u) goto L_00001af4;
    goto L_exit;
L_00001af4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6900u, s->source_elf + 6900u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[3] = s->r[0] & 13u;
    instructions++;
    agr_aot_cmp(s, s->r[3], 13u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 6864u) : (s->bias + 6908u); { instructions++; goto L_after_00001af4; }
L_after_00001af4:
    blocks_done++;
    if (regs[15] == s->bias + 6908u) goto L_00001afc;
    goto L_exit;
L_00001afc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6908u, s->source_elf + 6908u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 1, 0u);
    instructions++;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[8]); }
    instructions++;
    regs[15] = s->bias + 6914u;
L_after_00001afc:
    blocks_done++;
    if (regs[15] == s->bias + 6914u) goto L_00001b02;
    goto L_exit;
L_00001b02:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6914u, s->source_elf + 6914u, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    s->r[2] = s->r[4] & 15u;
    instructions++;
    agr_aot_mov_reg(s, 3, 1);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 4752u) | 1u, (s->bias + 6926u), 1); { instructions++; goto L_after_00001b02; }
L_after_00001b02:
    blocks_done++;
    goto L_exit;
L_00001b0e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6926u, s->source_elf + 6926u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    agr_aot_movs_imm(s, 1, 0u);
    instructions++;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[8]); }
    instructions++;
    regs[15] = s->bias + 6934u;
L_after_00001b0e:
    blocks_done++;
    if (regs[15] == s->bias + 6934u) goto L_00001b16;
    goto L_exit;
L_00001b16:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6934u, s->source_elf + 6934u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 6942u, s->source_elf + 6942u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 6736u); { instructions++; goto L_after_00001b1e; }
L_after_00001b1e:
    blocks_done++;
    goto L_exit;
L_00001b20:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6944u, s->source_elf + 6944u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[3], 160u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6976u) : (s->bias + 6948u); { instructions++; goto L_after_00001b20; }
L_after_00001b20:
    blocks_done++;
    if (regs[15] == s->bias + 6976u) goto L_00001b40;
    goto L_exit;
L_00001b26:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6950u, s->source_elf + 6950u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[2] = s->r[2] & 7u;
    instructions++;
    regs[15] = s->bias + 6954u;
L_after_00001b26:
    blocks_done++;
    goto L_exit;
L_00001b2e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6958u, s->source_elf + 6958u, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_lsls(s, 3, s->r[0], 28u);
    instructions++;
    s->r[2] = s->r[2] & 4080u;
    instructions++;
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    agr_aot_set_itstate(s, 72u); s->r[15] = (s->bias + 6968u); { instructions++; goto L_after_00001b2e; }
L_after_00001b2e:
    blocks_done++;
    goto L_exit;
L_00001b40:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6976u, s->source_elf + 6976u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[3], 176u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7132u) : (s->bias + 6980u); { instructions++; goto L_after_00001b40; }
L_after_00001b40:
    blocks_done++;
    if (regs[15] == s->bias + 7132u) goto L_00001bdc;
    if (regs[15] == s->bias + 6980u) goto L_00001b44;
    goto L_exit;
L_00001b44:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6980u, s->source_elf + 6980u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[0], 177u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7008u) : (s->bias + 6984u); { instructions++; goto L_after_00001b44; }
L_after_00001b44:
    blocks_done++;
    if (regs[15] == s->bias + 7008u) goto L_00001b60;
    if (regs[15] == s->bias + 6984u) goto L_00001b48;
    goto L_exit;
L_00001b48:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 6984u, s->source_elf + 6984u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 6990u, s->source_elf + 6990u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 2, 0);
    instructions++;
    agr_aot_cmp(s, s->r[0], 0u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 6864u) : (s->bias + 6996u); { instructions++; goto L_after_00001b4e; }
L_after_00001b4e:
    blocks_done++;
    goto L_exit;
L_00001b58:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7000u, s->source_elf + 7000u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6864u) : (s->bias + 7002u); { instructions++; goto L_after_00001b58; }
L_after_00001b58:
    blocks_done++;
    if (regs[15] == s->bias + 7002u) goto L_00001b5a;
    goto L_exit;
L_00001b5a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7002u, s->source_elf + 7002u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 7004u, s->source_elf + 7004u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 3, 1);
    instructions++;
    s->r[15] = (s->bias + 7304u); { instructions++; goto L_after_00001b5c; }
L_after_00001b5c:
    blocks_done++;
    if (regs[15] == s->bias + 7304u) goto L_00001c88;
    goto L_exit;
L_00001b60:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7008u, s->source_elf + 7008u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[0], 178u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7082u) : (s->bias + 7012u); { instructions++; goto L_after_00001b60; }
L_after_00001b60:
    blocks_done++;
    if (regs[15] == s->bias + 7082u) goto L_00001baa;
    if (regs[15] == s->bias + 7012u) goto L_00001b64;
    goto L_exit;
L_00001b64:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7012u, s->source_elf + 7012u, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 1, 0u);
    instructions++;
    agr_aot_movs_imm(s, 2, 13u);
    instructions++;
    agr_aot_mov_reg(s, 3, 1);
    instructions++;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[8]); }
    instructions++;
    regs[15] = s->bias + 7022u;
L_after_00001b64:
    blocks_done++;
    if (regs[15] == s->bias + 7022u) goto L_00001b6e;
    goto L_exit;
L_00001b6e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7022u, s->source_elf + 7022u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 7030u, s->source_elf + 7030u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 7040u, s->source_elf + 7040u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[13] + 12u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001b80; } result = rc; goto L_exit; } }
    instructions++;
    s->r[0] = s->r[0] & 127u;
    instructions++;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 7064u) : (s->bias + 7048u); { instructions++; goto L_after_00001b80; }
L_after_00001b80:
    blocks_done++;
    if (regs[15] == s->bias + 7064u) goto L_00001b98;
    goto L_exit;
L_00001b8a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7050u, s->source_elf + 7050u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_adds(s, 4, s->r[4], 7u);
    instructions++;
    s->r[3] += s->r[0];
    instructions++;
    agr_aot_mov_reg(s, 0, 6);
    instructions++;
    { uint32_t addr = s->r[13] + 12u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[3]); }
    instructions++;
    regs[15] = s->bias + 7058u;
L_after_00001b8a:
    blocks_done++;
    if (regs[15] == s->bias + 7058u) goto L_00001b92;
    goto L_exit;
L_00001b92:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7058u, s->source_elf + 7058u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 7062u), 1); { instructions++; goto L_after_00001b92; }
L_after_00001b92:
    blocks_done++;
    goto L_exit;
L_00001b96:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7062u, s->source_elf + 7062u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 7036u); { instructions++; goto L_after_00001b96; }
L_after_00001b96:
    blocks_done++;
    goto L_exit;
L_00001b98:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7064u, s->source_elf + 7064u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 3, s->r[3], 3841u);
    instructions++;
    regs[15] = s->bias + 7068u;
L_after_00001b98:
    blocks_done++;
    goto L_exit;
L_00001b9e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7070u, s->source_elf + 7070u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[0] += s->r[3];
    instructions++;
    { uint32_t addr = s->r[13] + 0u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[8]); }
    instructions++;
    regs[15] = s->bias + 7076u;
L_after_00001b9e:
    blocks_done++;
    if (regs[15] == s->bias + 7076u) goto L_00001ba4;
    goto L_exit;
L_00001ba4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7076u, s->source_elf + 7076u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    { uint32_t addr = s->r[13] + 12u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[0]); }
    instructions++;
    regs[15] = s->bias + 7078u;
L_after_00001ba4:
    blocks_done++;
    if (regs[15] == s->bias + 7078u) goto L_00001ba6;
    goto L_exit;
L_00001ba6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7078u, s->source_elf + 7078u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    s->r[15] = (s->bias + 6934u); { instructions++; goto L_after_00001ba6; }
L_after_00001ba6:
    blocks_done++;
    if (regs[15] == s->bias + 6934u) goto L_00001b16;
    goto L_exit;
L_00001baa:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7082u, s->source_elf + 7082u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[0], 179u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7108u) : (s->bias + 7086u); { instructions++; goto L_after_00001baa; }
L_after_00001baa:
    blocks_done++;
    if (regs[15] == s->bias + 7108u) goto L_00001bc4;
    if (regs[15] == s->bias + 7086u) goto L_00001bae;
    goto L_exit;
L_00001bae:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7086u, s->source_elf + 7086u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 7092u, s->source_elf + 7092u, 16u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 1, 1u);
    instructions++;
    s->r[3] = s->r[0] & 15u;
    instructions++;
    s->r[2] = s->r[0] & 240u;
    instructions++;
    agr_aot_adds(s, 3, s->r[3], 1u);
    instructions++;
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    s->r[15] = (s->bias + 7160u); { instructions++; goto L_after_00001bb4; }
L_after_00001bb4:
    blocks_done++;
    goto L_exit;
L_00001bc4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7108u, s->source_elf + 7108u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[3] = s->r[0] & 252u;
    instructions++;
    agr_aot_cmp(s, s->r[3], 180u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 6864u) : (s->bias + 7116u); { instructions++; goto L_after_00001bc4; }
L_after_00001bc4:
    blocks_done++;
    if (regs[15] == s->bias + 7116u) goto L_00001bcc;
    goto L_exit;
L_00001bcc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7116u, s->source_elf + 7116u, 16u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[4] = s->r[0] & 7u;
    instructions++;
    agr_aot_movs_imm(s, 1, 1u);
    instructions++;
    agr_aot_adds(s, 2, s->r[4], 1u);
    instructions++;
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    s->r[2] = s->r[2] | 524288u;
    instructions++;
    s->r[15] = (s->bias + 7004u); { instructions++; goto L_after_00001bcc; }
L_after_00001bcc:
    blocks_done++;
    if (regs[15] == s->bias + 7004u) goto L_00001b5c;
    goto L_exit;
L_00001bdc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7132u, s->source_elf + 7132u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[3], 192u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7278u) : (s->bias + 7136u); { instructions++; goto L_after_00001bdc; }
L_after_00001bdc:
    blocks_done++;
    if (regs[15] == s->bias + 7278u) goto L_00001c6e;
    if (regs[15] == s->bias + 7136u) goto L_00001be0;
    goto L_exit;
L_00001be0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7136u, s->source_elf + 7136u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[0], 198u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7166u) : (s->bias + 7140u); { instructions++; goto L_after_00001be0; }
L_after_00001be0:
    blocks_done++;
    if (regs[15] == s->bias + 7166u) goto L_00001bfe;
    if (regs[15] == s->bias + 7140u) goto L_00001be4;
    goto L_exit;
L_00001be4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7140u, s->source_elf + 7140u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 7146u, s->source_elf + 7146u, 14u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 1, 3u);
    instructions++;
    s->r[3] = s->r[0] & 15u;
    instructions++;
    s->r[2] = s->r[0] & 240u;
    instructions++;
    agr_aot_adds(s, 3, s->r[3], 1u);
    instructions++;
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    regs[15] = s->bias + 7160u;
L_after_00001bea:
    blocks_done++;
    goto L_exit;
L_00001bfc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7164u, s->source_elf + 7164u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 7004u); { instructions++; goto L_after_00001bfc; }
L_after_00001bfc:
    blocks_done++;
    if (regs[15] == s->bias + 7004u) goto L_00001b5c;
    goto L_exit;
L_00001bfe:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7166u, s->source_elf + 7166u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[0], 199u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7198u) : (s->bias + 7170u); { instructions++; goto L_after_00001bfe; }
L_after_00001bfe:
    blocks_done++;
    if (regs[15] == s->bias + 7198u) goto L_00001c1e;
    if (regs[15] == s->bias + 7170u) goto L_00001c02;
    goto L_exit;
L_00001c02:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7170u, s->source_elf + 7170u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 7176u, s->source_elf + 7176u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 2, 0);
    instructions++;
    agr_aot_cmp(s, s->r[0], 0u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 6864u) : (s->bias + 7184u); { instructions++; goto L_after_00001c08; }
L_after_00001c08:
    blocks_done++;
    goto L_exit;
L_00001c14:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7188u, s->source_elf + 7188u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6864u) : (s->bias + 7192u); { instructions++; goto L_after_00001c14; }
L_after_00001c14:
    blocks_done++;
    if (regs[15] == s->bias + 7192u) goto L_00001c18;
    goto L_exit;
L_00001c18:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7192u, s->source_elf + 7192u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    agr_aot_movs_imm(s, 1, 4u);
    instructions++;
    s->r[15] = (s->bias + 7304u); { instructions++; goto L_after_00001c18; }
L_after_00001c18:
    blocks_done++;
    if (regs[15] == s->bias + 7304u) goto L_00001c88;
    goto L_exit;
L_00001c1e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7198u, s->source_elf + 7198u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[3] = s->r[0] & 248u;
    instructions++;
    agr_aot_cmp(s, s->r[3], 192u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7222u) : (s->bias + 7206u); { instructions++; goto L_after_00001c1e; }
L_after_00001c1e:
    blocks_done++;
    if (regs[15] == s->bias + 7222u) goto L_00001c36;
    if (regs[15] == s->bias + 7206u) goto L_00001c26;
    goto L_exit;
L_00001c26:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7206u, s->source_elf + 7206u, 16u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[4] = s->r[0] & 15u;
    instructions++;
    agr_aot_movs_imm(s, 1, 3u);
    instructions++;
    agr_aot_adds(s, 2, s->r[4], 1u);
    instructions++;
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    s->r[2] = s->r[2] | 655360u;
    instructions++;
    s->r[15] = (s->bias + 7004u); { instructions++; goto L_after_00001c26; }
L_after_00001c26:
    blocks_done++;
    if (regs[15] == s->bias + 7004u) goto L_00001b5c;
    goto L_exit;
L_00001c36:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7222u, s->source_elf + 7222u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[0], 200u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 7246u) : (s->bias + 7226u); { instructions++; goto L_after_00001c36; }
L_after_00001c36:
    blocks_done++;
    if (regs[15] == s->bias + 7246u) goto L_00001c4e;
    if (regs[15] == s->bias + 7226u) goto L_00001c3a;
    goto L_exit;
L_00001c3a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7226u, s->source_elf + 7226u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 6);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 7232u), 1); { instructions++; goto L_after_00001c3a; }
L_after_00001c3a:
    blocks_done++;
    goto L_exit;
L_00001c40:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7232u, s->source_elf + 7232u, 14u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[2] = s->r[0] & 240u;
    instructions++;
    s->r[0] = s->r[0] & 15u;
    instructions++;
    agr_aot_adds(s, 2, s->r[2], 16u);
    instructions++;
    agr_aot_adds(s, 3, s->r[0], 1u);
    instructions++;
    s->r[15] = (s->bias + 7268u); { instructions++; goto L_after_00001c40; }
L_after_00001c40:
    blocks_done++;
    if (regs[15] == s->bias + 7268u) goto L_00001c64;
    goto L_exit;
L_00001c4e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7246u, s->source_elf + 7246u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[0], 201u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6864u) : (s->bias + 7252u); { instructions++; goto L_after_00001c4e; }
L_after_00001c4e:
    blocks_done++;
    if (regs[15] == s->bias + 7252u) goto L_00001c54;
    goto L_exit;
L_00001c54:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7252u, s->source_elf + 7252u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 6);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 6648u) | 1u, (s->bias + 7258u), 1); { instructions++; goto L_after_00001c54; }
L_after_00001c54:
    blocks_done++;
    goto L_exit;
L_00001c5a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7258u, s->source_elf + 7258u, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[3] = s->r[0] & 15u;
    instructions++;
    s->r[2] = s->r[0] & 240u;
    instructions++;
    agr_aot_adds(s, 3, s->r[3], 1u);
    instructions++;
    regs[15] = s->bias + 7268u;
L_after_00001c5a:
    blocks_done++;
    if (regs[15] == s->bias + 7268u) goto L_00001c64;
    goto L_exit;
L_00001c64:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7268u, s->source_elf + 7268u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 7276u, s->source_elf + 7276u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 7302u); { instructions++; goto L_after_00001c6c; }
L_after_00001c6c:
    blocks_done++;
    if (regs[15] == s->bias + 7302u) goto L_00001c86;
    goto L_exit;
L_00001c6e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7278u, s->source_elf + 7278u, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[3] = s->r[0] & 248u;
    instructions++;
    agr_aot_cmp(s, s->r[3], 208u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6864u) : (s->bias + 7288u); { instructions++; goto L_after_00001c6e; }
L_after_00001c6e:
    blocks_done++;
    if (regs[15] == s->bias + 7288u) goto L_00001c78;
    goto L_exit;
L_00001c78:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7288u, s->source_elf + 7288u, 14u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[4] = s->r[0] & 7u;
    instructions++;
    agr_aot_movs_imm(s, 1, 1u);
    instructions++;
    agr_aot_adds(s, 2, s->r[4], 1u);
    instructions++;
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    s->r[2] = s->r[2] | 524288u;
    instructions++;
    regs[15] = s->bias + 7302u;
L_after_00001c78:
    blocks_done++;
    if (regs[15] == s->bias + 7302u) goto L_00001c86;
    goto L_exit;
L_00001c86:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7302u, s->source_elf + 7302u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 7304u, s->source_elf + 7304u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 5672u) | 1u, (s->bias + 7308u), 1); { instructions++; goto L_after_00001c88; }
L_after_00001c88:
    blocks_done++;
    goto L_exit;
L_00001c8c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7308u, s->source_elf + 7308u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[0], 0u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 6864u) : (s->bias + 7314u); { instructions++; goto L_after_00001c8c; }
L_after_00001c8c:
    blocks_done++;
    if (regs[15] == s->bias + 7314u) goto L_00001c92;
    goto L_exit;
L_00001c92:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7314u, s->source_elf + 7314u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 6736u); { instructions++; goto L_after_00001c92; }
L_after_00001c92:
    blocks_done++;
    goto L_exit;
L_00001c94:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7316u, s->source_elf + 7316u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 0, 0u);
    instructions++;
    regs[15] = s->bias + 7318u;
L_after_00001c94:
    blocks_done++;
    if (regs[15] == s->bias + 7318u) goto L_00001c96;
    goto L_exit;
L_00001c96:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7318u, s->source_elf + 7318u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[13] += 16u;
    instructions++;
    if ((rc = agr_aot_ldmia_sp(s, 34800u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001c96; } result = rc; goto L_exit; }
    instructions++;
L_after_00001c96:
    blocks_done++;
    goto L_exit;
L_exit:
    memcpy(outer->r, regs, sizeof(regs));
    *outer->cpsr = cpsr;
    outer->region_blocks = blocks_done;
    outer->region_instructions = instructions;
    return result;
}

static int agr_region_00006(AgrAotRegs *outer) {
    if (!outer->source_elf) return AGR_AOT_MISS;
    uint32_t regs[16];
    memcpy(regs, outer->r, sizeof(regs));
    uint32_t cpsr = *outer->cpsr;
    AgrAotRegs local = {regs, &cpsr, outer->mem, outer->bias, 0, 0, 0, outer->source_elf, 0};
    AgrAotRegs *s = &local;
    int rc = 0, result = AGR_AOT_BOUNDARY;
    (void)rc;
    uint32_t blocks_done = 0, instructions = 0;
    switch (outer->region_entry) {
    case 0u: goto L_00001c9c;
    case 1u: goto L_00001c9e;
    case 2u: goto L_00001caa;
    case 3u: goto L_00001cb0;
    case 4u: goto L_00001cb6;
    case 5u: goto L_00001cbc;
    case 6u: goto L_00001cc0;
    case 7u: goto L_00001cc6;
    case 8u: goto L_00001cc8;
    case 9u: goto L_00001ccc;
    case 10u: goto L_00001cd0;
    case 11u: goto L_00001cd2;
    case 12u: goto L_00001cd6;
    case 13u: goto L_00001cde;
    case 14u: goto L_00001ce2;
    case 15u: goto L_00001ce4;
    case 16u: goto L_00001ce8;
    case 17u: goto L_00001cea;
    default: result = AGR_AOT_MISS; goto L_exit;
    }
L_00001c9c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7324u, s->source_elf + 7324u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16415u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 7326u;
L_after_00001c9c:
    blocks_done++;
    if (regs[15] == s->bias + 7326u) goto L_00001c9e;
    goto L_exit;
L_00001c9e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7326u, s->source_elf + 7326u, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 76u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001c9e; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 0, 1);
    instructions++;
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    instructions++;
    { int rc = agr_aot_ldr(s, 2, s->r[3] + 4u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001c9e; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_lsls(s, 2, s->r[2], 8u);
    instructions++;
    { uint32_t addr = s->r[13] + 4u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[2]); }
    instructions++;
    regs[15] = s->bias + 7338u;
L_after_00001c9e:
    blocks_done++;
    if (regs[15] == s->bias + 7338u) goto L_00001caa;
    goto L_exit;
L_00001caa:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7338u, s->source_elf + 7338u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 2, s->r[3], 8u);
    instructions++;
    { uint32_t addr = s->r[13] + 8u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[2]); }
    instructions++;
    regs[15] = s->bias + 7344u;
L_after_00001caa:
    blocks_done++;
    if (regs[15] == s->bias + 7344u) goto L_00001cb0;
    goto L_exit;
L_00001cb0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7344u, s->source_elf + 7344u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 2, 3u);
    instructions++;
    { uint32_t addr = s->r[13] + 12u; if (agr_aot_fault8(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store8(s, addr, s->r[2]); }
    instructions++;
    regs[15] = s->bias + 7350u;
L_after_00001cb0:
    blocks_done++;
    if (regs[15] == s->bias + 7350u) goto L_00001cb6;
    goto L_exit;
L_00001cb6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7350u, s->source_elf + 7350u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldrb(s, 3, s->r[3] + 7u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001cb6; } result = rc; goto L_exit; } }
    instructions++;
    { uint32_t addr = s->r[13] + 13u; if (agr_aot_fault8(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store8(s, addr, s->r[3]); }
    instructions++;
    regs[15] = s->bias + 7356u;
L_after_00001cb6:
    blocks_done++;
    if (regs[15] == s->bias + 7356u) goto L_00001cbc;
    goto L_exit;
L_00001cbc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7356u, s->source_elf + 7356u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 6718u) | 1u, (s->bias + 7360u), 1); { instructions++; goto L_after_00001cbc; }
L_after_00001cbc:
    blocks_done++;
    goto L_exit;
L_00001cc0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7360u, s->source_elf + 7360u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[13] += 20u;
    instructions++;
    { uint32_t addr = s->r[13]; s->r[13] = s->r[13] + 4u; if ((rc = agr_aot_ldr(s, 15, addr))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001cc0; } result = rc; goto L_exit; } }
    instructions++;
L_after_00001cc0:
    blocks_done++;
    goto L_exit;
L_00001cc6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7366u, s->source_elf + 7366u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16392u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 7368u;
L_after_00001cc6:
    blocks_done++;
    if (regs[15] == s->bias + 7368u) goto L_00001cc8;
    goto L_exit;
L_00001cc8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7368u, s->source_elf + 7368u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 6716u) | 1u, (s->bias + 7372u), 1); { instructions++; goto L_after_00001cc8; }
L_after_00001cc8:
    blocks_done++;
    goto L_exit;
L_00001ccc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7372u, s->source_elf + 7372u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
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
    if (memcmp(s->mem + s->bias + 7376u, s->source_elf + 7376u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16392u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 7378u;
L_after_00001cd0:
    blocks_done++;
    if (regs[15] == s->bias + 7378u) goto L_00001cd2;
    goto L_exit;
L_00001cd2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7378u, s->source_elf + 7378u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 6716u) | 1u, (s->bias + 7382u), 1); { instructions++; goto L_after_00001cd2; }
L_after_00001cd2:
    blocks_done++;
    goto L_exit;
L_00001cd6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7382u, s->source_elf + 7382u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 76u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001cd6; } result = rc; goto L_exit; } }
    instructions++;
    { int rc = agr_aot_ldrb(s, 2, s->r[3] + 7u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001cd6; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 7386u;
L_after_00001cd6:
    blocks_done++;
    goto L_exit;
L_00001cde:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7390u, s->source_elf + 7390u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_adds(s, 0, s->r[0], 8u);
    instructions++;
    if ((rc = agr_aot_ldmia_sp(s, 32776u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_00001cde; } result = rc; goto L_exit; }
    instructions++;
L_after_00001cde:
    blocks_done++;
    goto L_exit;
L_00001ce2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7394u, s->source_elf + 7394u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16392u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 7396u;
L_after_00001ce2:
    blocks_done++;
    if (regs[15] == s->bias + 7396u) goto L_00001ce4;
    goto L_exit;
L_00001ce4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7396u, s->source_elf + 7396u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 3408u), (s->bias + 7400u), 1); { instructions++; goto L_after_00001ce4; }
L_after_00001ce4:
    blocks_done++;
    goto L_exit;
L_00001ce8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7400u, s->source_elf + 7400u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16392u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 7402u;
L_after_00001ce8:
    blocks_done++;
    if (regs[15] == s->bias + 7402u) goto L_00001cea;
    goto L_exit;
L_00001cea:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 7402u, s->source_elf + 7402u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 3408u), (s->bias + 7406u), 1); { instructions++; goto L_after_00001cea; }
L_after_00001cea:
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
    {3292u, agr_region_00000, 1u, 0u},
    {3296u, agr_region_00000, 3u, 1u},
    {3324u, agr_region_00000, 3u, 2u},
    {3336u, agr_region_00000, 3u, 3u},
    {3348u, agr_region_00000, 3u, 4u},
    {3360u, agr_region_00000, 3u, 5u},
    {3372u, agr_region_00000, 3u, 6u},
    {3384u, agr_region_00000, 3u, 7u},
    {3396u, agr_region_00000, 3u, 8u},
    {3408u, agr_region_00000, 3u, 9u},
    {3456u, agr_region_00000, 2u, 10u},
    {3524u, agr_region_00000, 1u, 11u},
    {3528u, agr_region_00000, 9u, 12u},
    {3548u, agr_region_00000, 7u, 13u},
    {3564u, agr_region_00000, 2u, 14u},
    {3568u, agr_region_00000, 6u, 15u},
    {3582u, agr_region_00000, 2u, 16u},
    {3586u, agr_region_00000, 1u, 17u},
    {3588u, agr_region_00000, 6u, 18u},
    {3602u, agr_region_00000, 6u, 19u},
    {3618u, agr_region_00000, 5u, 20u},
    {3632u, agr_region_00000, 1u, 21u},
    {3634u, agr_region_00000, 5u, 22u},
    {3648u, agr_region_00000, 5u, 23u},
    {3662u, agr_region_00000, 7u, 24u},
    {3678u, agr_region_00000, 1u, 25u},
    {3680u, agr_region_00000, 7u, 26u},
    {3696u, agr_region_00000, 7u, 27u},
    {3712u, agr_region_00000, 7u, 28u},
    {3728u, agr_region_00000, 1u, 29u},
    {3732u, agr_region_00000, 1u, 30u},
    {3736u, agr_region_00000, 9u, 31u},
    {3758u, agr_region_00000, 7u, 32u},
    {3774u, agr_region_00000, 6u, 33u},
    {3788u, agr_region_00000, 5u, 34u},
    {3800u, agr_region_00000, 4u, 35u},
    {3810u, agr_region_00000, 7u, 36u},
    {3826u, agr_region_00000, 7u, 37u},
    {3842u, agr_region_00000, 1u, 38u},
    {3848u, agr_region_00000, 3u, 39u},
    {3866u, agr_region_00000, 1u, 40u},
    {3870u, agr_region_00000, 3u, 41u},
    {3876u, agr_region_00000, 3u, 42u},
    {3884u, agr_region_00000, 1u, 43u},
    {3894u, agr_region_00000, 2u, 44u},
    {3898u, agr_region_00000, 3u, 45u},
    {3908u, agr_region_00000, 4u, 46u},
    {3916u, agr_region_00000, 3u, 47u},
    {3926u, agr_region_00000, 2u, 48u},
    {3930u, agr_region_00000, 2u, 49u},
    {3934u, agr_region_00000, 2u, 50u},
    {3940u, agr_region_00000, 3u, 51u},
    {3946u, agr_region_00000, 2u, 52u},
    {3950u, agr_region_00000, 2u, 53u},
    {3954u, agr_region_00000, 2u, 54u},
    {3958u, agr_region_00000, 2u, 55u},
    {3962u, agr_region_00000, 3u, 56u},
    {3970u, agr_region_00000, 2u, 57u},
    {3974u, agr_region_00000, 2u, 58u},
    {3978u, agr_region_00000, 1u, 59u},
    {3980u, agr_region_00000, 4u, 60u},
    {3988u, agr_region_00000, 4u, 61u},
    {3996u, agr_region_00000, 4u, 62u},
    {4004u, agr_region_00000, 2u, 63u},
    {4008u, agr_region_00001, 6u, 0u},
    {4020u, agr_region_00001, 2u, 1u},
    {4024u, agr_region_00001, 5u, 2u},
    {4034u, agr_region_00001, 3u, 3u},
    {4042u, agr_region_00001, 2u, 4u},
    {4046u, agr_region_00001, 1u, 5u},
    {4048u, agr_region_00001, 8u, 6u},
    {4066u, agr_region_00001, 1u, 7u},
    {4068u, agr_region_00001, 3u, 8u},
    {4076u, agr_region_00001, 2u, 9u},
    {4080u, agr_region_00001, 1u, 10u},
    {4082u, agr_region_00001, 2u, 11u},
    {4086u, agr_region_00001, 1u, 12u},
    {4090u, agr_region_00001, 3u, 13u},
    {4096u, agr_region_00001, 1u, 14u},
    {4098u, agr_region_00001, 3u, 15u},
    {4104u, agr_region_00001, 1u, 16u},
    {4106u, agr_region_00001, 3u, 17u},
    {4114u, agr_region_00001, 1u, 18u},
    {4116u, agr_region_00001, 2u, 19u},
    {4120u, agr_region_00001, 1u, 20u},
    {4124u, agr_region_00001, 2u, 21u},
    {4128u, agr_region_00001, 2u, 22u},
    {4132u, agr_region_00001, 3u, 23u},
    {4142u, agr_region_00001, 1u, 24u},
    {4146u, agr_region_00001, 1u, 25u},
    {4148u, agr_region_00001, 2u, 26u},
    {4158u, agr_region_00001, 1u, 27u},
    {4162u, agr_region_00001, 1u, 28u},
    {4164u, agr_region_00001, 1u, 29u},
    {4166u, agr_region_00001, 2u, 30u},
    {4184u, agr_region_00001, 2u, 31u},
    {4188u, agr_region_00001, 3u, 32u},
    {4198u, agr_region_00001, 2u, 33u},
    {4204u, agr_region_00001, 1u, 34u},
    {4208u, agr_region_00001, 1u, 35u},
    {4210u, agr_region_00001, 1u, 36u},
    {4214u, agr_region_00001, 3u, 37u},
    {4220u, agr_region_00001, 2u, 38u},
    {4228u, agr_region_00001, 3u, 39u},
    {4234u, agr_region_00001, 2u, 40u},
    {4242u, agr_region_00001, 3u, 41u},
    {4248u, agr_region_00001, 3u, 42u},
    {4260u, agr_region_00001, 1u, 43u},
    {4262u, agr_region_00001, 2u, 44u},
    {4266u, agr_region_00001, 2u, 45u},
    {4270u, agr_region_00001, 2u, 46u},
    {4274u, agr_region_00001, 2u, 47u},
    {4278u, agr_region_00001, 1u, 48u},
    {4280u, agr_region_00001, 1u, 49u},
    {4282u, agr_region_00001, 2u, 50u},
    {4286u, agr_region_00001, 3u, 51u},
    {4294u, agr_region_00001, 2u, 52u},
    {4298u, agr_region_00001, 1u, 53u},
    {4302u, agr_region_00001, 5u, 54u},
    {4312u, agr_region_00001, 2u, 55u},
    {4316u, agr_region_00001, 2u, 56u},
    {4320u, agr_region_00001, 2u, 57u},
    {4324u, agr_region_00001, 3u, 58u},
    {4332u, agr_region_00001, 2u, 59u},
    {4338u, agr_region_00001, 1u, 60u},
    {4342u, agr_region_00001, 5u, 61u},
    {4362u, agr_region_00001, 2u, 62u},
    {4380u, agr_region_00001, 2u, 63u},
    {4386u, agr_region_00002, 3u, 0u},
    {4392u, agr_region_00002, 3u, 1u},
    {4400u, agr_region_00002, 2u, 2u},
    {4532u, agr_region_00002, 2u, 3u},
    {4536u, agr_region_00002, 2u, 4u},
    {4542u, agr_region_00002, 2u, 5u},
    {4546u, agr_region_00002, 3u, 6u},
    {4554u, agr_region_00002, 2u, 7u},
    {4572u, agr_region_00002, 1u, 8u},
    {4576u, agr_region_00002, 2u, 9u},
    {4582u, agr_region_00002, 3u, 10u},
    {4592u, agr_region_00002, 1u, 11u},
    {4594u, agr_region_00002, 4u, 12u},
    {4602u, agr_region_00002, 3u, 13u},
    {4608u, agr_region_00002, 2u, 14u},
    {4614u, agr_region_00002, 2u, 15u},
    {4618u, agr_region_00002, 3u, 16u},
    {4626u, agr_region_00002, 3u, 17u},
    {4634u, agr_region_00002, 1u, 18u},
    {4636u, agr_region_00002, 1u, 19u},
    {4638u, agr_region_00002, 2u, 20u},
    {4642u, agr_region_00002, 3u, 21u},
    {4650u, agr_region_00002, 2u, 22u},
    {4654u, agr_region_00002, 2u, 23u},
    {4658u, agr_region_00002, 4u, 24u},
    {4666u, agr_region_00002, 1u, 25u},
    {4668u, agr_region_00002, 2u, 26u},
    {4674u, agr_region_00002, 1u, 27u},
    {4676u, agr_region_00002, 5u, 28u},
    {4686u, agr_region_00002, 2u, 29u},
    {4690u, agr_region_00002, 2u, 30u},
    {4694u, agr_region_00002, 3u, 31u},
    {4702u, agr_region_00002, 3u, 32u},
    {4710u, agr_region_00002, 2u, 33u},
    {4716u, agr_region_00002, 1u, 34u},
    {4720u, agr_region_00002, 2u, 35u},
    {4724u, agr_region_00002, 1u, 36u},
    {4728u, agr_region_00002, 2u, 37u},
    {4732u, agr_region_00002, 2u, 38u},
    {4736u, agr_region_00002, 1u, 39u},
    {4738u, agr_region_00002, 1u, 40u},
    {4740u, agr_region_00002, 3u, 41u},
    {4746u, agr_region_00002, 2u, 42u},
    {4750u, agr_region_00002, 1u, 43u},
    {4752u, agr_region_00002, 1u, 44u},
    {4754u, agr_region_00002, 2u, 45u},
    {4762u, agr_region_00002, 5u, 46u},
    {4792u, agr_region_00002, 2u, 47u},
    {4796u, agr_region_00002, 1u, 48u},
    {4798u, agr_region_00002, 4u, 49u},
    {4806u, agr_region_00002, 2u, 50u},
    {4812u, agr_region_00002, 3u, 51u},
    {4820u, agr_region_00002, 1u, 52u},
    {4822u, agr_region_00002, 2u, 53u},
    {4830u, agr_region_00002, 5u, 54u},
    {4860u, agr_region_00002, 2u, 55u},
    {4864u, agr_region_00002, 1u, 56u},
    {4866u, agr_region_00002, 4u, 57u},
    {4876u, agr_region_00002, 2u, 58u},
    {4880u, agr_region_00002, 2u, 59u},
    {4886u, agr_region_00002, 2u, 60u},
    {4890u, agr_region_00002, 2u, 61u},
    {4896u, agr_region_00002, 2u, 62u},
    {4900u, agr_region_00002, 2u, 63u},
    {4910u, agr_region_00003, 2u, 0u},
    {4928u, agr_region_00003, 1u, 1u},
    {4932u, agr_region_00003, 3u, 2u},
    {4940u, agr_region_00003, 3u, 3u},
    {4948u, agr_region_00003, 1u, 4u},
    {4950u, agr_region_00003, 2u, 5u},
    {4954u, agr_region_00003, 4u, 6u},
    {4964u, agr_region_00003, 3u, 7u},
    {4970u, agr_region_00003, 2u, 8u},
    {4974u, agr_region_00003, 5u, 9u},
    {4984u, agr_region_00003, 3u, 10u},
    {4990u, agr_region_00003, 2u, 11u},
    {4994u, agr_region_00003, 1u, 12u},
    {4996u, agr_region_00003, 2u, 13u},
    {5002u, agr_region_00003, 3u, 14u},
    {5012u, agr_region_00003, 1u, 15u},
    {5016u, agr_region_00003, 10u, 16u},
    {5038u, agr_region_00003, 1u, 17u},
    {5040u, agr_region_00003, 1u, 18u},
    {5042u, agr_region_00003, 2u, 19u},
    {5048u, agr_region_00003, 1u, 20u},
    {5050u, agr_region_00003, 2u, 21u},
    {5056u, agr_region_00003, 1u, 22u},
    {5058u, agr_region_00003, 2u, 23u},
    {5064u, agr_region_00003, 1u, 24u},
    {5068u, agr_region_00003, 2u, 25u},
    {5072u, agr_region_00003, 3u, 26u},
    {5084u, agr_region_00003, 3u, 27u},
    {5660u, agr_region_00003, 2u, 28u},
    {5664u, agr_region_00003, 2u, 29u},
    {5668u, agr_region_00003, 2u, 30u},
    {5672u, agr_region_00003, 1u, 31u},
    {5676u, agr_region_00003, 6u, 32u},
    {5692u, agr_region_00003, 5u, 33u},
    {5702u, agr_region_00003, 1u, 34u},
    {5706u, agr_region_00003, 1u, 35u},
    {5708u, agr_region_00003, 1u, 36u},
    {5714u, agr_region_00003, 1u, 37u},
    {5716u, agr_region_00003, 1u, 38u},
    {5722u, agr_region_00003, 2u, 39u},
    {5726u, agr_region_00003, 3u, 40u},
    {5736u, agr_region_00003, 1u, 41u},
    {5740u, agr_region_00003, 1u, 42u},
    {5742u, agr_region_00003, 1u, 43u},
    {5936u, agr_region_00003, 2u, 44u},
    {6006u, agr_region_00003, 2u, 45u},
    {6212u, agr_region_00003, 2u, 46u},
    {6220u, agr_region_00003, 1u, 47u},
    {6228u, agr_region_00003, 3u, 48u},
    {6240u, agr_region_00003, 2u, 49u},
    {6248u, agr_region_00003, 1u, 50u},
    {6256u, agr_region_00003, 1u, 51u},
    {6264u, agr_region_00003, 1u, 52u},
    {6272u, agr_region_00003, 1u, 53u},
    {6280u, agr_region_00003, 1u, 54u},
    {6288u, agr_region_00003, 1u, 55u},
    {6356u, agr_region_00003, 1u, 56u},
    {6424u, agr_region_00003, 1u, 57u},
    {6444u, agr_region_00003, 1u, 58u},
    {6464u, agr_region_00003, 1u, 59u},
    {6468u, agr_region_00003, 2u, 60u},
    {6472u, agr_region_00003, 1u, 61u},
    {6476u, agr_region_00003, 1u, 62u},
    {6480u, agr_region_00003, 2u, 63u},
    {6488u, agr_region_00004, 2u, 0u},
    {6494u, agr_region_00004, 3u, 1u},
    {6504u, agr_region_00004, 2u, 2u},
    {6508u, agr_region_00004, 1u, 3u},
    {6512u, agr_region_00004, 1u, 4u},
    {6516u, agr_region_00004, 2u, 5u},
    {6524u, agr_region_00004, 2u, 6u},
    {6530u, agr_region_00004, 3u, 7u},
    {6540u, agr_region_00004, 2u, 8u},
    {6544u, agr_region_00004, 1u, 9u},
    {6548u, agr_region_00004, 1u, 10u},
    {6552u, agr_region_00004, 2u, 11u},
    {6560u, agr_region_00004, 2u, 12u},
    {6566u, agr_region_00004, 3u, 13u},
    {6576u, agr_region_00004, 2u, 14u},
    {6580u, agr_region_00004, 1u, 15u},
    {6584u, agr_region_00004, 1u, 16u},
    {6588u, agr_region_00004, 2u, 17u},
    {6596u, agr_region_00004, 2u, 18u},
    {6602u, agr_region_00004, 3u, 19u},
    {6612u, agr_region_00004, 2u, 20u},
    {6616u, agr_region_00004, 1u, 21u},
    {6620u, agr_region_00004, 1u, 22u},
    {6624u, agr_region_00004, 2u, 23u},
    {6632u, agr_region_00004, 2u, 24u},
    {6638u, agr_region_00004, 3u, 25u},
    {6648u, agr_region_00004, 2u, 26u},
    {6652u, agr_region_00004, 2u, 27u},
    {6656u, agr_region_00004, 2u, 28u},
    {6660u, agr_region_00004, 3u, 29u},
    {6666u, agr_region_00004, 2u, 30u},
    {6670u, agr_region_00004, 2u, 31u},
    {6674u, agr_region_00004, 1u, 32u},
    {6676u, agr_region_00004, 1u, 33u},
    {6678u, agr_region_00004, 3u, 34u},
    {6686u, agr_region_00004, 1u, 35u},
    {6688u, agr_region_00004, 2u, 36u},
    {6692u, agr_region_00004, 1u, 37u},
    {6694u, agr_region_00004, 4u, 38u},
    {6702u, agr_region_00004, 2u, 39u},
    {6708u, agr_region_00004, 3u, 40u},
    {6716u, agr_region_00004, 1u, 41u},
    {6718u, agr_region_00004, 1u, 42u},
    {6722u, agr_region_00004, 5u, 43u},
    {6736u, agr_region_00004, 2u, 44u},
    {6742u, agr_region_00004, 3u, 45u},
    {6748u, agr_region_00004, 2u, 46u},
    {6754u, agr_region_00004, 4u, 47u},
    {6762u, agr_region_00004, 3u, 48u},
    {6770u, agr_region_00004, 1u, 49u},
    {6772u, agr_region_00004, 5u, 50u},
    {6784u, agr_region_00004, 1u, 51u},
    {6794u, agr_region_00004, 1u, 52u},
    {6800u, agr_region_00004, 2u, 53u},
    {6806u, agr_region_00004, 2u, 54u},
    {6814u, agr_region_00004, 1u, 55u},
    {6818u, agr_region_00004, 2u, 56u},
    {6828u, agr_region_00004, 1u, 57u},
    {6840u, agr_region_00004, 3u, 58u},
    {6848u, agr_region_00004, 3u, 59u},
    {6858u, agr_region_00004, 2u, 60u},
    {6864u, agr_region_00004, 2u, 61u},
    {6868u, agr_region_00004, 4u, 62u},
    {6878u, agr_region_00004, 1u, 63u},
    {6882u, agr_region_00005, 2u, 0u},
    {6890u, agr_region_00005, 1u, 1u},
    {6896u, agr_region_00005, 2u, 2u},
    {6900u, agr_region_00005, 3u, 3u},
    {6908u, agr_region_00005, 2u, 4u},
    {6914u, agr_region_00005, 4u, 5u},
    {6926u, agr_region_00005, 3u, 6u},
    {6934u, agr_region_00005, 3u, 7u},
    {6942u, agr_region_00005, 1u, 8u},
    {6944u, agr_region_00005, 2u, 9u},
    {6950u, agr_region_00005, 1u, 10u},
    {6958u, agr_region_00005, 4u, 11u},
    {6976u, agr_region_00005, 2u, 12u},
    {6980u, agr_region_00005, 2u, 13u},
    {6984u, agr_region_00005, 2u, 14u},
    {6990u, agr_region_00005, 3u, 15u},
    {7000u, agr_region_00005, 1u, 16u},
    {7002u, agr_region_00005, 1u, 17u},
    {7004u, agr_region_00005, 2u, 18u},
    {7008u, agr_region_00005, 2u, 19u},
    {7012u, agr_region_00005, 4u, 20u},
    {7022u, agr_region_00005, 3u, 21u},
    {7030u, agr_region_00005, 2u, 22u},
    {7040u, agr_region_00005, 3u, 23u},
    {7050u, agr_region_00005, 4u, 24u},
    {7058u, agr_region_00005, 1u, 25u},
    {7062u, agr_region_00005, 1u, 26u},
    {7064u, agr_region_00005, 1u, 27u},
    {7070u, agr_region_00005, 2u, 28u},
    {7076u, agr_region_00005, 1u, 29u},
    {7078u, agr_region_00005, 2u, 30u},
    {7082u, agr_region_00005, 2u, 31u},
    {7086u, agr_region_00005, 2u, 32u},
    {7092u, agr_region_00005, 6u, 33u},
    {7108u, agr_region_00005, 3u, 34u},
    {7116u, agr_region_00005, 6u, 35u},
    {7132u, agr_region_00005, 2u, 36u},
    {7136u, agr_region_00005, 2u, 37u},
    {7140u, agr_region_00005, 2u, 38u},
    {7146u, agr_region_00005, 5u, 39u},
    {7164u, agr_region_00005, 1u, 40u},
    {7166u, agr_region_00005, 2u, 41u},
    {7170u, agr_region_00005, 2u, 42u},
    {7176u, agr_region_00005, 3u, 43u},
    {7188u, agr_region_00005, 1u, 44u},
    {7192u, agr_region_00005, 3u, 45u},
    {7198u, agr_region_00005, 3u, 46u},
    {7206u, agr_region_00005, 6u, 47u},
    {7222u, agr_region_00005, 2u, 48u},
    {7226u, agr_region_00005, 2u, 49u},
    {7232u, agr_region_00005, 5u, 50u},
    {7246u, agr_region_00005, 2u, 51u},
    {7252u, agr_region_00005, 2u, 52u},
    {7258u, agr_region_00005, 3u, 53u},
    {7268u, agr_region_00005, 2u, 54u},
    {7276u, agr_region_00005, 1u, 55u},
    {7278u, agr_region_00005, 3u, 56u},
    {7288u, agr_region_00005, 5u, 57u},
    {7302u, agr_region_00005, 1u, 58u},
    {7304u, agr_region_00005, 1u, 59u},
    {7308u, agr_region_00005, 2u, 60u},
    {7314u, agr_region_00005, 1u, 61u},
    {7316u, agr_region_00005, 1u, 62u},
    {7318u, agr_region_00005, 2u, 63u},
    {7324u, agr_region_00006, 1u, 0u},
    {7326u, agr_region_00006, 6u, 1u},
    {7338u, agr_region_00006, 2u, 2u},
    {7344u, agr_region_00006, 2u, 3u},
    {7350u, agr_region_00006, 2u, 4u},
    {7356u, agr_region_00006, 1u, 5u},
    {7360u, agr_region_00006, 2u, 6u},
    {7366u, agr_region_00006, 1u, 7u},
    {7368u, agr_region_00006, 1u, 8u},
    {7372u, agr_region_00006, 2u, 9u},
    {7376u, agr_region_00006, 1u, 10u},
    {7378u, agr_region_00006, 1u, 11u},
    {7382u, agr_region_00006, 2u, 12u},
    {7390u, agr_region_00006, 2u, 13u},
    {7394u, agr_region_00006, 1u, 14u},
    {7396u, agr_region_00006, 1u, 15u},
    {7400u, agr_region_00006, 1u, 16u},
    {7402u, agr_region_00006, 1u, 17u},
};
const uint32_t agr_aot_fast_block_count = 402u;
const AgrAotEntry agr_aot_fast_hash[] = {{0, 0, 0}};
const uint32_t agr_aot_fast_hash_mask = 0u;
const uint32_t agr_aot_fast_direct_base = 3292u;
const uint32_t agr_aot_fast_direct_count = 2056u;
const uint32_t agr_aot_fast_direct[2056] = {
    [0] = 1u,
    [2] = 2u,
    [16] = 3u,
    [22] = 4u,
    [28] = 5u,
    [34] = 6u,
    [40] = 7u,
    [46] = 8u,
    [52] = 9u,
    [58] = 10u,
    [82] = 11u,
    [116] = 12u,
    [118] = 13u,
    [128] = 14u,
    [136] = 15u,
    [138] = 16u,
    [145] = 17u,
    [147] = 18u,
    [148] = 19u,
    [155] = 20u,
    [163] = 21u,
    [170] = 22u,
    [171] = 23u,
    [178] = 24u,
    [185] = 25u,
    [193] = 26u,
    [194] = 27u,
    [202] = 28u,
    [210] = 29u,
    [218] = 30u,
    [220] = 31u,
    [222] = 32u,
    [233] = 33u,
    [241] = 34u,
    [248] = 35u,
    [254] = 36u,
    [259] = 37u,
    [267] = 38u,
    [275] = 39u,
    [278] = 40u,
    [287] = 41u,
    [289] = 42u,
    [292] = 43u,
    [296] = 44u,
    [301] = 45u,
    [303] = 46u,
    [308] = 47u,
    [312] = 48u,
    [317] = 49u,
    [319] = 50u,
    [321] = 51u,
    [324] = 52u,
    [327] = 53u,
    [329] = 54u,
    [331] = 55u,
    [333] = 56u,
    [335] = 57u,
    [339] = 58u,
    [341] = 59u,
    [343] = 60u,
    [344] = 61u,
    [348] = 62u,
    [352] = 63u,
    [356] = 64u,
    [358] = 65u,
    [364] = 66u,
    [366] = 67u,
    [371] = 68u,
    [375] = 69u,
    [377] = 70u,
    [378] = 71u,
    [387] = 72u,
    [388] = 73u,
    [392] = 74u,
    [394] = 75u,
    [395] = 76u,
    [397] = 77u,
    [399] = 78u,
    [402] = 79u,
    [403] = 80u,
    [406] = 81u,
    [407] = 82u,
    [411] = 83u,
    [412] = 84u,
    [414] = 85u,
    [416] = 86u,
    [418] = 87u,
    [420] = 88u,
    [425] = 89u,
    [427] = 90u,
    [428] = 91u,
    [433] = 92u,
    [435] = 93u,
    [436] = 94u,
    [437] = 95u,
    [446] = 96u,
    [448] = 97u,
    [453] = 98u,
    [456] = 99u,
    [458] = 100u,
    [459] = 101u,
    [461] = 102u,
    [464] = 103u,
    [468] = 104u,
    [471] = 105u,
    [475] = 106u,
    [478] = 107u,
    [484] = 108u,
    [485] = 109u,
    [487] = 110u,
    [489] = 111u,
    [491] = 112u,
    [493] = 113u,
    [494] = 114u,
    [495] = 115u,
    [497] = 116u,
    [501] = 117u,
    [503] = 118u,
    [505] = 119u,
    [510] = 120u,
    [512] = 121u,
    [514] = 122u,
    [516] = 123u,
    [520] = 124u,
    [523] = 125u,
    [525] = 126u,
    [535] = 127u,
    [544] = 128u,
    [547] = 129u,
    [550] = 130u,
    [554] = 131u,
    [620] = 132u,
    [622] = 133u,
    [625] = 134u,
    [627] = 135u,
    [631] = 136u,
    [640] = 137u,
    [642] = 138u,
    [645] = 139u,
    [650] = 140u,
    [651] = 141u,
    [655] = 142u,
    [658] = 143u,
    [661] = 144u,
    [663] = 145u,
    [667] = 146u,
    [671] = 147u,
    [672] = 148u,
    [673] = 149u,
    [675] = 150u,
    [679] = 151u,
    [681] = 152u,
    [683] = 153u,
    [687] = 154u,
    [688] = 155u,
    [691] = 156u,
    [692] = 157u,
    [697] = 158u,
    [699] = 159u,
    [701] = 160u,
    [705] = 161u,
    [709] = 162u,
    [712] = 163u,
    [714] = 164u,
    [716] = 165u,
    [718] = 166u,
    [720] = 167u,
    [722] = 168u,
    [723] = 169u,
    [724] = 170u,
    [727] = 171u,
    [729] = 172u,
    [730] = 173u,
    [731] = 174u,
    [735] = 175u,
    [750] = 176u,
    [752] = 177u,
    [753] = 178u,
    [757] = 179u,
    [760] = 180u,
    [764] = 181u,
    [765] = 182u,
    [769] = 183u,
    [784] = 184u,
    [786] = 185u,
    [787] = 186u,
    [792] = 187u,
    [794] = 188u,
    [797] = 189u,
    [799] = 190u,
    [802] = 191u,
    [804] = 192u,
    [809] = 193u,
    [818] = 194u,
    [820] = 195u,
    [824] = 196u,
    [828] = 197u,
    [829] = 198u,
    [831] = 199u,
    [836] = 200u,
    [839] = 201u,
    [841] = 202u,
    [846] = 203u,
    [849] = 204u,
    [851] = 205u,
    [852] = 206u,
    [855] = 207u,
    [860] = 208u,
    [862] = 209u,
    [873] = 210u,
    [874] = 211u,
    [875] = 212u,
    [878] = 213u,
    [879] = 214u,
    [882] = 215u,
    [883] = 216u,
    [886] = 217u,
    [888] = 218u,
    [890] = 219u,
    [896] = 220u,
    [1184] = 221u,
    [1186] = 222u,
    [1188] = 223u,
    [1190] = 224u,
    [1192] = 225u,
    [1200] = 226u,
    [1205] = 227u,
    [1207] = 228u,
    [1208] = 229u,
    [1211] = 230u,
    [1212] = 231u,
    [1215] = 232u,
    [1217] = 233u,
    [1222] = 234u,
    [1224] = 235u,
    [1225] = 236u,
    [1322] = 237u,
    [1357] = 238u,
    [1460] = 239u,
    [1464] = 240u,
    [1468] = 241u,
    [1474] = 242u,
    [1478] = 243u,
    [1482] = 244u,
    [1486] = 245u,
    [1490] = 246u,
    [1494] = 247u,
    [1498] = 248u,
    [1532] = 249u,
    [1566] = 250u,
    [1576] = 251u,
    [1586] = 252u,
    [1588] = 253u,
    [1590] = 254u,
    [1592] = 255u,
    [1594] = 256u,
    [1598] = 257u,
    [1601] = 258u,
    [1606] = 259u,
    [1608] = 260u,
    [1610] = 261u,
    [1612] = 262u,
    [1616] = 263u,
    [1619] = 264u,
    [1624] = 265u,
    [1626] = 266u,
    [1628] = 267u,
    [1630] = 268u,
    [1634] = 269u,
    [1637] = 270u,
    [1642] = 271u,
    [1644] = 272u,
    [1646] = 273u,
    [1648] = 274u,
    [1652] = 275u,
    [1655] = 276u,
    [1660] = 277u,
    [1662] = 278u,
    [1664] = 279u,
    [1666] = 280u,
    [1670] = 281u,
    [1673] = 282u,
    [1678] = 283u,
    [1680] = 284u,
    [1682] = 285u,
    [1684] = 286u,
    [1687] = 287u,
    [1689] = 288u,
    [1691] = 289u,
    [1692] = 290u,
    [1693] = 291u,
    [1697] = 292u,
    [1698] = 293u,
    [1700] = 294u,
    [1701] = 295u,
    [1705] = 296u,
    [1708] = 297u,
    [1712] = 298u,
    [1713] = 299u,
    [1715] = 300u,
    [1722] = 301u,
    [1725] = 302u,
    [1728] = 303u,
    [1731] = 304u,
    [1735] = 305u,
    [1739] = 306u,
    [1740] = 307u,
    [1746] = 308u,
    [1751] = 309u,
    [1754] = 310u,
    [1757] = 311u,
    [1761] = 312u,
    [1763] = 313u,
    [1768] = 314u,
    [1774] = 315u,
    [1778] = 316u,
    [1783] = 317u,
    [1786] = 318u,
    [1788] = 319u,
    [1793] = 320u,
    [1795] = 321u,
    [1799] = 322u,
    [1802] = 323u,
    [1804] = 324u,
    [1808] = 325u,
    [1811] = 326u,
    [1817] = 327u,
    [1821] = 328u,
    [1825] = 329u,
    [1826] = 330u,
    [1829] = 331u,
    [1833] = 332u,
    [1842] = 333u,
    [1844] = 334u,
    [1846] = 335u,
    [1849] = 336u,
    [1854] = 337u,
    [1855] = 338u,
    [1856] = 339u,
    [1858] = 340u,
    [1860] = 341u,
    [1865] = 342u,
    [1869] = 343u,
    [1874] = 344u,
    [1879] = 345u,
    [1883] = 346u,
    [1885] = 347u,
    [1886] = 348u,
    [1889] = 349u,
    [1892] = 350u,
    [1893] = 351u,
    [1895] = 352u,
    [1897] = 353u,
    [1900] = 354u,
    [1908] = 355u,
    [1912] = 356u,
    [1920] = 357u,
    [1922] = 358u,
    [1924] = 359u,
    [1927] = 360u,
    [1936] = 361u,
    [1937] = 362u,
    [1939] = 363u,
    [1942] = 364u,
    [1948] = 365u,
    [1950] = 366u,
    [1953] = 367u,
    [1957] = 368u,
    [1965] = 369u,
    [1967] = 370u,
    [1970] = 371u,
    [1977] = 372u,
    [1980] = 373u,
    [1983] = 374u,
    [1988] = 375u,
    [1992] = 376u,
    [1993] = 377u,
    [1998] = 378u,
    [2005] = 379u,
    [2006] = 380u,
    [2008] = 381u,
    [2011] = 382u,
    [2012] = 383u,
    [2013] = 384u,
    [2016] = 385u,
    [2017] = 386u,
    [2023] = 387u,
    [2026] = 388u,
    [2029] = 389u,
    [2032] = 390u,
    [2034] = 391u,
    [2037] = 392u,
    [2038] = 393u,
    [2040] = 394u,
    [2042] = 395u,
    [2043] = 396u,
    [2045] = 397u,
    [2049] = 398u,
    [2051] = 399u,
    [2052] = 400u,
    [2054] = 401u,
    [2055] = 402u,
};
const uint32_t agr_aot_fast_relocatable = 1u;
const uint64_t agr_aot_input_elf_fnv64 = 13986468843527641119ull;
const uint32_t agr_aot_input_elf_bytes = 9376u;
