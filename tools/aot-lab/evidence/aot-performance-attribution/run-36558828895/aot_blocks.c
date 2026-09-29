#include "agr_aot.h"

static int agr_region_00593(AgrAotRegs *outer) {
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
    case 0u: goto L_0009b3b0;
    case 1u: goto L_0009b3ba;
    case 2u: goto L_0009b46e;
    case 3u: goto L_0009b47a;
    case 4u: goto L_0009b480;
    case 5u: goto L_0009b484;
    case 6u: goto L_0009b490;
    case 7u: goto L_0009b49a;
    case 8u: goto L_0009b4a0;
    case 9u: goto L_0009b4a6;
    case 10u: goto L_0009b4ae;
    case 11u: goto L_0009b4b4;
    case 12u: goto L_0009b4b6;
    case 13u: goto L_0009b4bc;
    case 14u: goto L_0009b4c2;
    case 15u: goto L_0009b4c8;
    case 16u: goto L_0009b4d4;
    case 17u: goto L_0009b4de;
    case 18u: goto L_0009b4e4;
    case 19u: goto L_0009b4ea;
    case 20u: goto L_0009b4f2;
    case 21u: goto L_0009b4f8;
    case 22u: goto L_0009b4fa;
    case 23u: goto L_0009b4fe;
    case 24u: goto L_0009b506;
    case 25u: goto L_0009b50c;
    case 26u: goto L_0009b548;
    case 27u: goto L_0009b54a;
    case 28u: goto L_0009b556;
    case 29u: goto L_0009b55e;
    case 30u: goto L_0009b566;
    case 31u: goto L_0009b572;
    case 32u: goto L_0009b57c;
    case 33u: goto L_0009b582;
    case 34u: goto L_0009b58c;
    case 35u: goto L_0009b594;
    case 36u: goto L_0009b59c;
    case 37u: goto L_0009b5a0;
    case 38u: goto L_0009b5a2;
    case 39u: goto L_0009b5b4;
    case 40u: goto L_0009b5be;
    case 41u: goto L_0009b5c0;
    case 42u: goto L_0009b5c4;
    case 43u: goto L_0009b5c8;
    case 44u: goto L_0009b5dc;
    case 45u: goto L_0009b5ec;
    case 46u: goto L_0009b5ee;
    case 47u: goto L_0009b600;
    case 48u: goto L_0009b60a;
    case 49u: goto L_0009b60c;
    case 50u: goto L_0009b610;
    case 51u: goto L_0009b614;
    case 52u: goto L_0009b61a;
    case 53u: goto L_0009b630;
    case 54u: goto L_0009b640;
    case 55u: goto L_0009b642;
    case 56u: goto L_0009b654;
    case 57u: goto L_0009b65e;
    case 58u: goto L_0009b660;
    case 59u: goto L_0009b664;
    case 60u: goto L_0009b668;
    case 61u: goto L_0009b67c;
    case 62u: goto L_0009b68c;
    case 63u: goto L_0009b68e;
    default: result = AGR_AOT_MISS; goto L_exit;
    }
L_0009b3b0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 635824u, s->source_elf + 635824u, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 8u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b3b0; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_subs(s, 3, s->r[3], 1u);
    instructions++;
    agr_aot_cmp(s, s->r[0], s->r[3]);
    instructions++;
    agr_aot_mov_reg(s, 6, 0);
    instructions++;
    s->r[15] = agr_aot_condition(s, 9u) ? (s->bias + 636014u) : (s->bias + 635834u); { instructions++; goto L_after_0009b3b0; }
L_after_0009b3b0:
    blocks_done++;
    if (regs[15] == s->bias + 636014u) goto L_0009b46e;
    if (regs[15] == s->bias + 635834u) goto L_0009b3ba;
    goto L_exit;
L_0009b3ba:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 635834u, s->source_elf + 635834u, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_adds(s, 7, s->r[0], 4u);
    instructions++;
    { int rc = agr_aot_ldr(s, 9, s->r[5] + 4u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b3ba; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_cmp(s, s->r[7], 532676608u);
    instructions++;
    agr_aot_set_itstate(s, 148u); s->r[15] = (s->bias + 635846u); { instructions++; goto L_after_0009b3ba; }
L_after_0009b3ba:
    blocks_done++;
    goto L_exit;
L_0009b46e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636014u, s->source_elf + 636014u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 3, s->r[8], 4u);
    instructions++;
    atomic_thread_fence(memory_order_seq_cst);
    instructions++;
    regs[15] = s->bias + 636022u;
L_after_0009b46e:
    blocks_done++;
    goto L_exit;
L_0009b47a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636026u, s->source_elf + 636026u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_adds(s, 1, s->r[1], 1u);
    instructions++;
    regs[15] = s->bias + 636028u;
L_after_0009b47a:
    blocks_done++;
    goto L_exit;
L_0009b480:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636032u, s->source_elf + 636032u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[2], 0u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 636022u) : (s->bias + 636036u); { instructions++; goto L_after_0009b480; }
L_after_0009b480:
    blocks_done++;
    if (regs[15] == s->bias + 636036u) goto L_0009b484;
    goto L_exit;
L_0009b484:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636036u, s->source_elf + 636036u, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
    atomic_thread_fence(memory_order_seq_cst);
    instructions++;
    { int rc = agr_aot_ldr(s, 4, s->r[5] + 4u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b484; } result = rc; goto L_exit; } }
    instructions++;
    { int rc = agr_aot_ldr(s, 0, s->r[4] + (s->r[6] << 2u)); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b484; } result = rc; goto L_exit; } }
    instructions++;
    s->r[15] = !s->r[0] ? (s->bias + 636078u) : (s->bias + 636048u); { instructions++; goto L_after_0009b484; }
L_after_0009b484:
    blocks_done++;
    if (regs[15] == s->bias + 636078u) goto L_0009b4ae;
    if (regs[15] == s->bias + 636048u) goto L_0009b490;
    goto L_exit;
L_0009b490:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636048u, s->source_elf + 636048u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_adds(s, 3, s->r[0], 4u);
    instructions++;
    atomic_thread_fence(memory_order_seq_cst);
    instructions++;
    regs[15] = s->bias + 636054u;
L_after_0009b490:
    blocks_done++;
    goto L_exit;
L_0009b49a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636058u, s->source_elf + 636058u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_subs(s, 7, s->r[2], 1u);
    instructions++;
    regs[15] = s->bias + 636060u;
L_after_0009b49a:
    blocks_done++;
    goto L_exit;
L_0009b4a0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636064u, s->source_elf + 636064u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[12], 0u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 636054u) : (s->bias + 636070u); { instructions++; goto L_after_0009b4a0; }
L_after_0009b4a0:
    blocks_done++;
    if (regs[15] == s->bias + 636070u) goto L_0009b4a6;
    goto L_exit;
L_0009b4a6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636070u, s->source_elf + 636070u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[2], 1u);
    instructions++;
    atomic_thread_fence(memory_order_seq_cst);
    instructions++;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 636166u) : (s->bias + 636078u); { instructions++; goto L_after_0009b4a6; }
L_after_0009b4a6:
    blocks_done++;
    if (regs[15] == s->bias + 636166u) goto L_0009b506;
    if (regs[15] == s->bias + 636078u) goto L_0009b4ae;
    goto L_exit;
L_0009b4ae:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636078u, s->source_elf + 636078u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 2, s->r[5] + 8u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b4ae; } result = rc; goto L_exit; } }
    instructions++;
    { uint32_t addr = s->r[4] + (s->r[6] << 2u); if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[8]); }
    instructions++;
    regs[15] = s->bias + 636084u;
L_after_0009b4ae:
    blocks_done++;
    if (regs[15] == s->bias + 636084u) goto L_0009b4b4;
    goto L_exit;
L_0009b4b4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636084u, s->source_elf + 636084u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = !s->r[2] ? (s->bias + 636154u) : (s->bias + 636086u); { instructions++; goto L_after_0009b4b4; }
L_after_0009b4b4:
    blocks_done++;
    if (regs[15] == s->bias + 636154u) goto L_0009b4fa;
    if (regs[15] == s->bias + 636086u) goto L_0009b4b6;
    goto L_exit;
L_0009b4b6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636086u, s->source_elf + 636086u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 4, 0u);
    instructions++;
    agr_aot_mov_reg(s, 7, 4);
    instructions++;
    s->r[15] = (s->bias + 636104u); { instructions++; goto L_after_0009b4b6; }
L_after_0009b4b6:
    blocks_done++;
    if (regs[15] == s->bias + 636104u) goto L_0009b4c8;
    goto L_exit;
L_0009b4bc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636092u, s->source_elf + 636092u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 12u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b4bc; } result = rc; goto L_exit; } }
    instructions++;
    { int rc = agr_aot_ldr(s, 2, s->r[5] + 8u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b4bc; } result = rc; goto L_exit; } }
    instructions++;
    { uint32_t addr = s->r[3] + s->r[6]; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[7]); }
    instructions++;
    regs[15] = s->bias + 636098u;
L_after_0009b4bc:
    blocks_done++;
    if (regs[15] == s->bias + 636098u) goto L_0009b4c2;
    goto L_exit;
L_0009b4c2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636098u, s->source_elf + 636098u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_adds(s, 4, s->r[4], 1u);
    instructions++;
    agr_aot_cmp(s, s->r[2], s->r[4]);
    instructions++;
    s->r[15] = agr_aot_condition(s, 9u) ? (s->bias + 636158u) : (s->bias + 636104u); { instructions++; goto L_after_0009b4c2; }
L_after_0009b4c2:
    blocks_done++;
    if (regs[15] == s->bias + 636158u) goto L_0009b4fe;
    if (regs[15] == s->bias + 636104u) goto L_0009b4c8;
    goto L_exit;
L_0009b4c8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636104u, s->source_elf + 636104u, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[5] + 12u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b4c8; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_lsls(s, 6, s->r[4], 2u);
    instructions++;
    { int rc = agr_aot_ldr(s, 0, s->r[3] + (s->r[4] << 2u)); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b4c8; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_cmp(s, s->r[0], 0u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 636098u) : (s->bias + 636116u); { instructions++; goto L_after_0009b4c8; }
L_after_0009b4c8:
    blocks_done++;
    if (regs[15] == s->bias + 636098u) goto L_0009b4c2;
    if (regs[15] == s->bias + 636116u) goto L_0009b4d4;
    goto L_exit;
L_0009b4d4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636116u, s->source_elf + 636116u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_adds(s, 3, s->r[0], 4u);
    instructions++;
    atomic_thread_fence(memory_order_seq_cst);
    instructions++;
    regs[15] = s->bias + 636122u;
L_after_0009b4d4:
    blocks_done++;
    goto L_exit;
L_0009b4de:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636126u, s->source_elf + 636126u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_subs(s, 1, s->r[2], 1u);
    instructions++;
    regs[15] = s->bias + 636128u;
L_after_0009b4de:
    blocks_done++;
    goto L_exit;
L_0009b4e4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636132u, s->source_elf + 636132u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[12], 0u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 636122u) : (s->bias + 636138u); { instructions++; goto L_after_0009b4e4; }
L_after_0009b4e4:
    blocks_done++;
    if (regs[15] == s->bias + 636138u) goto L_0009b4ea;
    goto L_exit;
L_0009b4ea:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636138u, s->source_elf + 636138u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[2], 1u);
    instructions++;
    atomic_thread_fence(memory_order_seq_cst);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 636092u) : (s->bias + 636146u); { instructions++; goto L_after_0009b4ea; }
L_after_0009b4ea:
    blocks_done++;
    if (regs[15] == s->bias + 636092u) goto L_0009b4bc;
    if (regs[15] == s->bias + 636146u) goto L_0009b4f2;
    goto L_exit;
L_0009b4f2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636146u, s->source_elf + 636146u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b4f2; } result = rc; goto L_exit; } }
    instructions++;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b4f2; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_branch_reg(s, s->r[3], (s->bias + 636152u), 1); { instructions++; goto L_after_0009b4f2; }
L_after_0009b4f2:
    blocks_done++;
    goto L_exit;
L_0009b4f8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636152u, s->source_elf + 636152u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 636092u); { instructions++; goto L_after_0009b4f8; }
L_after_0009b4f8:
    blocks_done++;
    if (regs[15] == s->bias + 636092u) goto L_0009b4bc;
    goto L_exit;
L_0009b4fa:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636154u, s->source_elf + 636154u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    if ((rc = agr_aot_ldmia_sp(s, 34800u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b4fa; } result = rc; goto L_exit; }
    instructions++;
L_after_0009b4fa:
    blocks_done++;
    goto L_exit;
L_0009b4fe:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636158u, s->source_elf + 636158u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    if ((rc = agr_aot_ldmia_sp(s, 34800u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b4fe; } result = rc; goto L_exit; }
    instructions++;
L_after_0009b4fe:
    blocks_done++;
    goto L_exit;
L_0009b506:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636166u, s->source_elf + 636166u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 3, s->r[0] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b506; } result = rc; goto L_exit; } }
    instructions++;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 4u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b506; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_branch_reg(s, s->r[3], (s->bias + 636172u), 1); { instructions++; goto L_after_0009b506; }
L_after_0009b506:
    blocks_done++;
    goto L_exit;
L_0009b50c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636172u, s->source_elf + 636172u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 636078u); { instructions++; goto L_after_0009b50c; }
L_after_0009b50c:
    blocks_done++;
    if (regs[15] == s->bias + 636078u) goto L_0009b4ae;
    goto L_exit;
L_0009b548:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636232u, s->source_elf + 636232u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16496u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 636234u;
L_after_0009b548:
    blocks_done++;
    if (regs[15] == s->bias + 636234u) goto L_0009b54a;
    goto L_exit;
L_0009b54a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636234u, s->source_elf + 636234u, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 6, 0);
    instructions++;
    agr_aot_mov_reg(s, 0, 2);
    instructions++;
    agr_aot_mov_reg(s, 4, 2);
    instructions++;
    agr_aot_mov_reg(s, 5, 1);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 635744u) | 1u, (s->bias + 636246u), 1); { instructions++; goto L_after_0009b54a; }
L_after_0009b54a:
    blocks_done++;
    goto L_exit;
L_0009b556:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636246u, s->source_elf + 636246u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 2, s->r[5] + 8u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b556; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_subs(s, 2, s->r[2], 1u);
    instructions++;
    agr_aot_cmp(s, s->r[0], s->r[2]);
    instructions++;
    s->r[15] = agr_aot_condition(s, 8u) ? (s->bias + 636274u) : (s->bias + 636254u); { instructions++; goto L_after_0009b556; }
L_after_0009b556:
    blocks_done++;
    if (regs[15] == s->bias + 636274u) goto L_0009b572;
    if (regs[15] == s->bias + 636254u) goto L_0009b55e;
    goto L_exit;
L_0009b55e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636254u, s->source_elf + 636254u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 2, s->r[5] + 4u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b55e; } result = rc; goto L_exit; } }
    instructions++;
    { int rc = agr_aot_ldr(s, 2, s->r[2] + (s->r[0] << 2u)); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b55e; } result = rc; goto L_exit; } }
    instructions++;
    s->r[15] = !s->r[2] ? (s->bias + 636274u) : (s->bias + 636262u); { instructions++; goto L_after_0009b55e; }
L_after_0009b55e:
    blocks_done++;
    if (regs[15] == s->bias + 636274u) goto L_0009b572;
    if (regs[15] == s->bias + 636262u) goto L_0009b566;
    goto L_exit;
L_0009b566:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636262u, s->source_elf + 636262u, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 6);
    instructions++;
    agr_aot_mov_reg(s, 1, 4);
    instructions++;
    if ((rc = agr_aot_ldmia_sp(s, 16496u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b566; } result = rc; goto L_exit; }
    instructions++;
    s->r[15] = (s->bias + 635804u); { instructions++; goto L_after_0009b566; }
L_after_0009b566:
    blocks_done++;
    goto L_exit;
L_0009b572:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636274u, s->source_elf + 636274u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 0, (s->bias + 636276u) + 8u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b572; } result = rc; goto L_exit; } }
    instructions++;
    s->r[0] += (s->bias + 636280u);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 718796u) | 1u, (s->bias + 636282u), 1); { instructions++; goto L_after_0009b572; }
L_after_0009b572:
    blocks_done++;
    goto L_exit;
L_0009b57c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636284u, s->source_elf + 636284u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_adds(s, 0, s->r[5], 7u);
    instructions++;
    agr_aot_lsls(s, 3, s->r[0], 0u);
    instructions++;
    if (agr_aot_stmdb_sp(s, 16496u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 636290u;
L_after_0009b57c:
    blocks_done++;
    if (regs[15] == s->bias + 636290u) goto L_0009b582;
    goto L_exit;
L_0009b582:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636290u, s->source_elf + 636290u, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 4, 2);
    instructions++;
    { int rc = agr_aot_ldr(s, 2, s->r[2] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b582; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 5, 0);
    instructions++;
    agr_aot_mov_reg(s, 6, 1);
    instructions++;
    s->r[15] = !s->r[2] ? (s->bias + 636316u) : (s->bias + 636300u); { instructions++; goto L_after_0009b582; }
L_after_0009b582:
    blocks_done++;
    if (regs[15] == s->bias + 636316u) goto L_0009b59c;
    if (regs[15] == s->bias + 636300u) goto L_0009b58c;
    goto L_exit;
L_0009b58c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636300u, s->source_elf + 636300u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 5);
    instructions++;
    agr_aot_mov_reg(s, 1, 6);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 636232u) | 1u, (s->bias + 636308u), 1); { instructions++; goto L_after_0009b58c; }
L_after_0009b58c:
    blocks_done++;
    if (regs[15] == s->bias + 636232u) goto L_0009b548;
    goto L_exit;
L_0009b594:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636308u, s->source_elf + 636308u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    { uint32_t addr = (s->r[4] + 4u); s->r[4] = s->r[4] + 4u; if ((rc = agr_aot_ldr(s, 2, addr))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b594; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_cmp(s, s->r[2], 0u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 636300u) : (s->bias + 636316u); { instructions++; goto L_after_0009b594; }
L_after_0009b594:
    blocks_done++;
    if (regs[15] == s->bias + 636300u) goto L_0009b58c;
    if (regs[15] == s->bias + 636316u) goto L_0009b59c;
    goto L_exit;
L_0009b59c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636316u, s->source_elf + 636316u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    if ((rc = agr_aot_ldmia_sp(s, 32880u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b59c; } result = rc; goto L_exit; }
    instructions++;
L_after_0009b59c:
    blocks_done++;
    goto L_exit;
L_0009b5a0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636320u, s->source_elf + 636320u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16440u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 636322u;
L_after_0009b5a0:
    blocks_done++;
    if (regs[15] == s->bias + 636322u) goto L_0009b5a2;
    goto L_exit;
L_0009b5a2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636322u, s->source_elf + 636322u, 18u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 4, 0);
    instructions++;
    { int rc = agr_aot_ldr(s, 3, (s->bias + 636328u) + 36u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b5a2; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_movs_imm(s, 1, 0u);
    instructions++;
    { int rc = agr_aot_ldr(s, 5, (s->bias + 636332u) + 36u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b5a2; } result = rc; goto L_exit; } }
    instructions++;
    { int rc = agr_aot_ldr(s, 2, (s->bias + 636332u) + 40u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b5a2; } result = rc; goto L_exit; } }
    instructions++;
    s->r[3] += (s->bias + 636336u);
    instructions++;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b5a2; } result = rc; goto L_exit; } }
    instructions++;
    s->r[5] += (s->bias + 636340u);
    instructions++;
    { uint32_t addr = s->r[4] + 4u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[1]); }
    instructions++;
    regs[15] = s->bias + 636340u;
L_after_0009b5a2:
    blocks_done++;
    if (regs[15] == s->bias + 636340u) goto L_0009b5b4;
    goto L_exit;
L_0009b5b4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636340u, s->source_elf + 636340u, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[2] += (s->bias + 636344u);
    instructions++;
    agr_aot_adds(s, 3, s->r[3], 8u);
    instructions++;
    agr_aot_adds(s, 2, s->r[2], 12u);
    instructions++;
    agr_aot_adds(s, 5, s->r[5], 12u);
    instructions++;
    { uint32_t addr = s->r[4] + 0u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[2]); }
    instructions++;
    regs[15] = s->bias + 636350u;
L_after_0009b5b4:
    blocks_done++;
    if (regs[15] == s->bias + 636350u) goto L_0009b5be;
    goto L_exit;
L_0009b5be:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636350u, s->source_elf + 636350u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    { uint32_t addr = s->r[4] + 8u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[5]); }
    instructions++;
    regs[15] = s->bias + 636352u;
L_after_0009b5be:
    blocks_done++;
    if (regs[15] == s->bias + 636352u) goto L_0009b5c0;
    goto L_exit;
L_0009b5c0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636352u, s->source_elf + 636352u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { uint32_t addr = (s->r[0] + 12u); s->r[0] = s->r[0] + 12u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[3]); }
    instructions++;
    regs[15] = s->bias + 636356u;
L_after_0009b5c0:
    blocks_done++;
    if (regs[15] == s->bias + 636356u) goto L_0009b5c4;
    goto L_exit;
L_0009b5c4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636356u, s->source_elf + 636356u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 547332u) | 1u, (s->bias + 636360u), 1); { instructions++; goto L_after_0009b5c4; }
L_after_0009b5c4:
    blocks_done++;
    goto L_exit;
L_0009b5c8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636360u, s->source_elf + 636360u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 4);
    instructions++;
    if ((rc = agr_aot_ldmia_sp(s, 32824u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b5c8; } result = rc; goto L_exit; }
    instructions++;
L_after_0009b5c8:
    blocks_done++;
    goto L_exit;
L_0009b5dc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636380u, s->source_elf + 636380u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 636320u); { instructions++; goto L_after_0009b5dc; }
L_after_0009b5dc:
    blocks_done++;
    if (regs[15] == s->bias + 636320u) goto L_0009b5a0;
    goto L_exit;
L_0009b5ec:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636396u, s->source_elf + 636396u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16440u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 636398u;
L_after_0009b5ec:
    blocks_done++;
    if (regs[15] == s->bias + 636398u) goto L_0009b5ee;
    goto L_exit;
L_0009b5ee:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636398u, s->source_elf + 636398u, 18u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 4, 0);
    instructions++;
    { int rc = agr_aot_ldr(s, 3, (s->bias + 636404u) + 44u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b5ee; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_movs_imm(s, 1, 0u);
    instructions++;
    { int rc = agr_aot_ldr(s, 5, (s->bias + 636408u) + 44u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b5ee; } result = rc; goto L_exit; } }
    instructions++;
    { int rc = agr_aot_ldr(s, 2, (s->bias + 636408u) + 48u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b5ee; } result = rc; goto L_exit; } }
    instructions++;
    s->r[3] += (s->bias + 636412u);
    instructions++;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b5ee; } result = rc; goto L_exit; } }
    instructions++;
    s->r[5] += (s->bias + 636416u);
    instructions++;
    { uint32_t addr = s->r[4] + 4u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[1]); }
    instructions++;
    regs[15] = s->bias + 636416u;
L_after_0009b5ee:
    blocks_done++;
    if (regs[15] == s->bias + 636416u) goto L_0009b600;
    goto L_exit;
L_0009b600:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636416u, s->source_elf + 636416u, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[2] += (s->bias + 636420u);
    instructions++;
    agr_aot_adds(s, 3, s->r[3], 8u);
    instructions++;
    agr_aot_adds(s, 2, s->r[2], 12u);
    instructions++;
    agr_aot_adds(s, 5, s->r[5], 12u);
    instructions++;
    { uint32_t addr = s->r[4] + 0u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[2]); }
    instructions++;
    regs[15] = s->bias + 636426u;
L_after_0009b600:
    blocks_done++;
    if (regs[15] == s->bias + 636426u) goto L_0009b60a;
    goto L_exit;
L_0009b60a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636426u, s->source_elf + 636426u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    { uint32_t addr = s->r[4] + 8u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[5]); }
    instructions++;
    regs[15] = s->bias + 636428u;
L_after_0009b60a:
    blocks_done++;
    if (regs[15] == s->bias + 636428u) goto L_0009b60c;
    goto L_exit;
L_0009b60c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636428u, s->source_elf + 636428u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { uint32_t addr = (s->r[0] + 12u); s->r[0] = s->r[0] + 12u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[3]); }
    instructions++;
    regs[15] = s->bias + 636432u;
L_after_0009b60c:
    blocks_done++;
    if (regs[15] == s->bias + 636432u) goto L_0009b610;
    goto L_exit;
L_0009b610:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636432u, s->source_elf + 636432u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 547332u) | 1u, (s->bias + 636436u), 1); { instructions++; goto L_after_0009b610; }
L_after_0009b610:
    blocks_done++;
    goto L_exit;
L_0009b614:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636436u, s->source_elf + 636436u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 4);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 535980u) | 1u, (s->bias + 636442u), 1); { instructions++; goto L_after_0009b614; }
L_after_0009b614:
    blocks_done++;
    goto L_exit;
L_0009b61a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636442u, s->source_elf + 636442u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 4);
    instructions++;
    if ((rc = agr_aot_ldmia_sp(s, 32824u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b61a; } result = rc; goto L_exit; }
    instructions++;
L_after_0009b61a:
    blocks_done++;
    goto L_exit;
L_0009b630:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636464u, s->source_elf + 636464u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 636396u); { instructions++; goto L_after_0009b630; }
L_after_0009b630:
    blocks_done++;
    if (regs[15] == s->bias + 636396u) goto L_0009b5ec;
    goto L_exit;
L_0009b640:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636480u, s->source_elf + 636480u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16440u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 636482u;
L_after_0009b640:
    blocks_done++;
    if (regs[15] == s->bias + 636482u) goto L_0009b642;
    goto L_exit;
L_0009b642:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636482u, s->source_elf + 636482u, 18u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 4, 0);
    instructions++;
    { int rc = agr_aot_ldr(s, 3, (s->bias + 636488u) + 36u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b642; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_movs_imm(s, 1, 0u);
    instructions++;
    { int rc = agr_aot_ldr(s, 5, (s->bias + 636492u) + 36u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b642; } result = rc; goto L_exit; } }
    instructions++;
    { int rc = agr_aot_ldr(s, 2, (s->bias + 636492u) + 40u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b642; } result = rc; goto L_exit; } }
    instructions++;
    s->r[3] += (s->bias + 636496u);
    instructions++;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b642; } result = rc; goto L_exit; } }
    instructions++;
    s->r[5] += (s->bias + 636500u);
    instructions++;
    { uint32_t addr = s->r[4] + 4u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[1]); }
    instructions++;
    regs[15] = s->bias + 636500u;
L_after_0009b642:
    blocks_done++;
    if (regs[15] == s->bias + 636500u) goto L_0009b654;
    goto L_exit;
L_0009b654:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636500u, s->source_elf + 636500u, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[2] += (s->bias + 636504u);
    instructions++;
    agr_aot_adds(s, 3, s->r[3], 8u);
    instructions++;
    agr_aot_adds(s, 2, s->r[2], 12u);
    instructions++;
    agr_aot_adds(s, 5, s->r[5], 12u);
    instructions++;
    { uint32_t addr = s->r[4] + 0u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[2]); }
    instructions++;
    regs[15] = s->bias + 636510u;
L_after_0009b654:
    blocks_done++;
    if (regs[15] == s->bias + 636510u) goto L_0009b65e;
    goto L_exit;
L_0009b65e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636510u, s->source_elf + 636510u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    { uint32_t addr = s->r[4] + 8u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[5]); }
    instructions++;
    regs[15] = s->bias + 636512u;
L_after_0009b65e:
    blocks_done++;
    if (regs[15] == s->bias + 636512u) goto L_0009b660;
    goto L_exit;
L_0009b660:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636512u, s->source_elf + 636512u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { uint32_t addr = (s->r[0] + 12u); s->r[0] = s->r[0] + 12u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[3]); }
    instructions++;
    regs[15] = s->bias + 636516u;
L_after_0009b660:
    blocks_done++;
    if (regs[15] == s->bias + 636516u) goto L_0009b664;
    goto L_exit;
L_0009b664:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636516u, s->source_elf + 636516u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 547332u) | 1u, (s->bias + 636520u), 1); { instructions++; goto L_after_0009b664; }
L_after_0009b664:
    blocks_done++;
    goto L_exit;
L_0009b668:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636520u, s->source_elf + 636520u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 4);
    instructions++;
    if ((rc = agr_aot_ldmia_sp(s, 32824u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b668; } result = rc; goto L_exit; }
    instructions++;
L_after_0009b668:
    blocks_done++;
    goto L_exit;
L_0009b67c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636540u, s->source_elf + 636540u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 636480u); { instructions++; goto L_after_0009b67c; }
L_after_0009b67c:
    blocks_done++;
    if (regs[15] == s->bias + 636480u) goto L_0009b640;
    goto L_exit;
L_0009b68c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636556u, s->source_elf + 636556u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16440u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 636558u;
L_after_0009b68c:
    blocks_done++;
    if (regs[15] == s->bias + 636558u) goto L_0009b68e;
    goto L_exit;
L_0009b68e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 636558u, s->source_elf + 636558u, 18u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 4, 0);
    instructions++;
    { int rc = agr_aot_ldr(s, 3, (s->bias + 636564u) + 44u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b68e; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_movs_imm(s, 1, 0u);
    instructions++;
    { int rc = agr_aot_ldr(s, 5, (s->bias + 636568u) + 44u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b68e; } result = rc; goto L_exit; } }
    instructions++;
    { int rc = agr_aot_ldr(s, 2, (s->bias + 636568u) + 48u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b68e; } result = rc; goto L_exit; } }
    instructions++;
    s->r[3] += (s->bias + 636572u);
    instructions++;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_0009b68e; } result = rc; goto L_exit; } }
    instructions++;
    s->r[5] += (s->bias + 636576u);
    instructions++;
    { uint32_t addr = s->r[4] + 4u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[1]); }
    instructions++;
    regs[15] = s->bias + 636576u;
L_after_0009b68e:
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
    {635824u, agr_region_00593, 5u, 0u},
    {635834u, agr_region_00593, 4u, 1u},
    {636014u, agr_region_00593, 2u, 2u},
    {636026u, agr_region_00593, 1u, 3u},
    {636032u, agr_region_00593, 2u, 4u},
    {636036u, agr_region_00593, 4u, 5u},
    {636048u, agr_region_00593, 2u, 6u},
    {636058u, agr_region_00593, 1u, 7u},
    {636064u, agr_region_00593, 2u, 8u},
    {636070u, agr_region_00593, 3u, 9u},
    {636078u, agr_region_00593, 2u, 10u},
    {636084u, agr_region_00593, 1u, 11u},
    {636086u, agr_region_00593, 3u, 12u},
    {636092u, agr_region_00593, 3u, 13u},
    {636098u, agr_region_00593, 3u, 14u},
    {636104u, agr_region_00593, 5u, 15u},
    {636116u, agr_region_00593, 2u, 16u},
    {636126u, agr_region_00593, 1u, 17u},
    {636132u, agr_region_00593, 2u, 18u},
    {636138u, agr_region_00593, 3u, 19u},
    {636146u, agr_region_00593, 3u, 20u},
    {636152u, agr_region_00593, 1u, 21u},
    {636154u, agr_region_00593, 1u, 22u},
    {636158u, agr_region_00593, 1u, 23u},
    {636166u, agr_region_00593, 3u, 24u},
    {636172u, agr_region_00593, 1u, 25u},
    {636232u, agr_region_00593, 1u, 26u},
    {636234u, agr_region_00593, 5u, 27u},
    {636246u, agr_region_00593, 4u, 28u},
    {636254u, agr_region_00593, 3u, 29u},
    {636262u, agr_region_00593, 4u, 30u},
    {636274u, agr_region_00593, 3u, 31u},
    {636284u, agr_region_00593, 3u, 32u},
    {636290u, agr_region_00593, 5u, 33u},
    {636300u, agr_region_00593, 3u, 34u},
    {636308u, agr_region_00593, 3u, 35u},
    {636316u, agr_region_00593, 1u, 36u},
    {636320u, agr_region_00593, 1u, 37u},
    {636322u, agr_region_00593, 9u, 38u},
    {636340u, agr_region_00593, 5u, 39u},
    {636350u, agr_region_00593, 1u, 40u},
    {636352u, agr_region_00593, 1u, 41u},
    {636356u, agr_region_00593, 1u, 42u},
    {636360u, agr_region_00593, 2u, 43u},
    {636380u, agr_region_00593, 1u, 44u},
    {636396u, agr_region_00593, 1u, 45u},
    {636398u, agr_region_00593, 9u, 46u},
    {636416u, agr_region_00593, 5u, 47u},
    {636426u, agr_region_00593, 1u, 48u},
    {636428u, agr_region_00593, 1u, 49u},
    {636432u, agr_region_00593, 1u, 50u},
    {636436u, agr_region_00593, 2u, 51u},
    {636442u, agr_region_00593, 2u, 52u},
    {636464u, agr_region_00593, 1u, 53u},
    {636480u, agr_region_00593, 1u, 54u},
    {636482u, agr_region_00593, 9u, 55u},
    {636500u, agr_region_00593, 5u, 56u},
    {636510u, agr_region_00593, 1u, 57u},
    {636512u, agr_region_00593, 1u, 58u},
    {636516u, agr_region_00593, 1u, 59u},
    {636520u, agr_region_00593, 2u, 60u},
    {636540u, agr_region_00593, 1u, 61u},
    {636556u, agr_region_00593, 1u, 62u},
    {636558u, agr_region_00593, 9u, 63u},
};
const uint32_t agr_aot_fast_block_count = 64u;
const AgrAotEntry agr_aot_fast_hash[] = {{0, 0, 0}};
const uint32_t agr_aot_fast_hash_mask = 0u;
const uint32_t agr_aot_fast_direct_base = 635824u;
const uint32_t agr_aot_fast_direct_count = 368u;
const uint32_t agr_aot_fast_direct[368] = {
    [0] = 1u,
    [5] = 2u,
    [95] = 3u,
    [101] = 4u,
    [104] = 5u,
    [106] = 6u,
    [112] = 7u,
    [117] = 8u,
    [120] = 9u,
    [123] = 10u,
    [127] = 11u,
    [130] = 12u,
    [131] = 13u,
    [134] = 14u,
    [137] = 15u,
    [140] = 16u,
    [146] = 17u,
    [151] = 18u,
    [154] = 19u,
    [157] = 20u,
    [161] = 21u,
    [164] = 22u,
    [165] = 23u,
    [167] = 24u,
    [171] = 25u,
    [174] = 26u,
    [204] = 27u,
    [205] = 28u,
    [211] = 29u,
    [215] = 30u,
    [219] = 31u,
    [225] = 32u,
    [230] = 33u,
    [233] = 34u,
    [238] = 35u,
    [242] = 36u,
    [246] = 37u,
    [248] = 38u,
    [249] = 39u,
    [258] = 40u,
    [263] = 41u,
    [264] = 42u,
    [266] = 43u,
    [268] = 44u,
    [278] = 45u,
    [286] = 46u,
    [287] = 47u,
    [296] = 48u,
    [301] = 49u,
    [302] = 50u,
    [304] = 51u,
    [306] = 52u,
    [309] = 53u,
    [320] = 54u,
    [328] = 55u,
    [329] = 56u,
    [338] = 57u,
    [343] = 58u,
    [344] = 59u,
    [346] = 60u,
    [348] = 61u,
    [358] = 62u,
    [366] = 63u,
    [367] = 64u,
};
const uint32_t agr_aot_fast_relocatable = 1u;
const uint64_t agr_aot_input_elf_fnv64 = 1641235115063234436ull;
const uint32_t agr_aot_input_elf_bytes = 882136u;
