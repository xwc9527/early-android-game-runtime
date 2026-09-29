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
};
const uint32_t agr_aot_fast_block_count = 64u;
const AgrAotEntry agr_aot_fast_hash[] = {{0, 0, 0}};
const uint32_t agr_aot_fast_hash_mask = 0u;
const uint32_t agr_aot_fast_direct_base = 3292u;
const uint32_t agr_aot_fast_direct_count = 357u;
const uint32_t agr_aot_fast_direct[357] = {
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
};
const uint32_t agr_aot_fast_relocatable = 1u;
const uint64_t agr_aot_input_elf_fnv64 = 13986468843527641119ull;
const uint32_t agr_aot_input_elf_bytes = 9376u;
