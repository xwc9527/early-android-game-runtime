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

static int agr_region_00725(AgrAotRegs *outer) {
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
    case 0u: goto L_000b2b32;
    case 1u: goto L_000b2b34;
    case 2u: goto L_000b2b38;
    case 3u: goto L_000b2b3c;
    case 4u: goto L_000b2b40;
    case 5u: goto L_000b2b44;
    case 6u: goto L_000b2b4a;
    case 7u: goto L_000b2b54;
    case 8u: goto L_000b2b5c;
    case 9u: goto L_000b2b60;
    case 10u: goto L_000b2b6c;
    case 11u: goto L_000b2b74;
    case 12u: goto L_000b2b7c;
    case 13u: goto L_000b2b88;
    case 14u: goto L_000b2b98;
    case 15u: goto L_000b2b9e;
    case 16u: goto L_000b2ba6;
    case 17u: goto L_000b2bb0;
    case 18u: goto L_000b2bb4;
    case 19u: goto L_000b2bba;
    case 20u: goto L_000b2bc0;
    case 21u: goto L_000b2bcc;
    case 22u: goto L_000b2bd0;
    case 23u: goto L_000b2be0;
    case 24u: goto L_000b2be2;
    case 25u: goto L_000b2be8;
    case 26u: goto L_000b2bec;
    case 27u: goto L_000b2bee;
    case 28u: goto L_000b2bf4;
    case 29u: goto L_000b2bfc;
    case 30u: goto L_000b2c00;
    case 31u: goto L_000b2c06;
    case 32u: goto L_000b2c0e;
    case 33u: goto L_000b2c16;
    case 34u: goto L_000b2c18;
    case 35u: goto L_000b2c1e;
    case 36u: goto L_000b2c2e;
    case 37u: goto L_000b2c32;
    case 38u: goto L_000b2c3c;
    case 39u: goto L_000b2c3e;
    case 40u: goto L_000b2c40;
    case 41u: goto L_000b2c44;
    case 42u: goto L_000b2c48;
    case 43u: goto L_000b2c4c;
    case 44u: goto L_000b2c52;
    case 45u: goto L_000b2c5e;
    case 46u: goto L_000b2c6a;
    case 47u: goto L_000b2c6c;
    case 48u: goto L_000b2c72;
    case 49u: goto L_000b2c78;
    case 50u: goto L_000b2c82;
    case 51u: goto L_000b2c88;
    case 52u: goto L_000b2c8c;
    case 53u: goto L_000b2c94;
    case 54u: goto L_000b2c9a;
    case 55u: goto L_000b2ca4;
    case 56u: goto L_000b2ca6;
    case 57u: goto L_000b2cac;
    case 58u: goto L_000b2cb2;
    case 59u: goto L_000b2cb8;
    case 60u: goto L_000b2cba;
    case 61u: goto L_000b2cc6;
    case 62u: goto L_000b2cca;
    case 63u: goto L_000b2cec;
    default: result = AGR_AOT_MISS; goto L_exit;
    }
L_000b2b32:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 731954u, s->source_elf + 731954u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 731938u) : (s->bias + 731956u); { instructions++; goto L_after_000b2b32; }
L_after_000b2b32:
    blocks_done++;
    if (regs[15] == s->bias + 731956u) goto L_000b2b34;
    goto L_exit;
L_000b2b34:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 731956u, s->source_elf + 731956u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    if ((rc = agr_aot_ldmia_sp(s, 112u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000b2b34; } result = rc; goto L_exit; }
    instructions++;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_000b2b34; }
L_after_000b2b34:
    blocks_done++;
    goto L_exit;
L_000b2b38:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 731960u, s->source_elf + 731960u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[1], 127u);
    instructions++;
    if (agr_aot_stmdb_sp(s, 16400u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 731964u;
L_after_000b2b38:
    blocks_done++;
    if (regs[15] == s->bias + 731964u) goto L_000b2b3c;
    goto L_exit;
L_000b2b3c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 731964u, s->source_elf + 731964u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 4, 2);
    instructions++;
    s->r[15] = agr_aot_condition(s, 8u) ? (s->bias + 731972u) : (s->bias + 731968u); { instructions++; goto L_after_000b2b3c; }
L_after_000b2b3c:
    blocks_done++;
    if (regs[15] == s->bias + 731972u) goto L_000b2b44;
    if (regs[15] == s->bias + 731968u) goto L_000b2b40;
    goto L_exit;
L_000b2b40:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 731968u, s->source_elf + 731968u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldrb(s, 3, s->r[0] + 12u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000b2b40; } result = rc; goto L_exit; } }
    instructions++;
    s->r[15] = s->r[3] ? (s->bias + 731988u) : (s->bias + 731972u); { instructions++; goto L_after_000b2b40; }
L_after_000b2b40:
    blocks_done++;
    if (regs[15] == s->bias + 731988u) goto L_000b2b54;
    if (regs[15] == s->bias + 731972u) goto L_000b2b44;
    goto L_exit;
L_000b2b44:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 731972u, s->source_elf + 731972u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 1);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 225832u), (s->bias + 731978u), 1); { instructions++; goto L_after_000b2b44; }
L_after_000b2b44:
    blocks_done++;
    goto L_exit;
L_000b2b4a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 731978u, s->source_elf + 731978u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_adds(s, 3, s->r[0], 1u);
    instructions++;
    agr_aot_set_itstate(s, 20u); s->r[15] = (s->bias + 731982u); { instructions++; goto L_after_000b2b4a; }
L_after_000b2b4a:
    blocks_done++;
    goto L_exit;
L_000b2b54:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 731988u, s->source_elf + 731988u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[1] += s->r[0];
    instructions++;
    { int rc = agr_aot_ldrb(s, 0, s->r[1] + 13u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000b2b54; } result = rc; goto L_exit; } }
    instructions++;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000b2b54; } result = rc; goto L_exit; }
    instructions++;
L_after_000b2b54:
    blocks_done++;
    goto L_exit;
L_000b2b5c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 731996u, s->source_elf + 731996u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 18416u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 732000u;
L_after_000b2b5c:
    blocks_done++;
    if (regs[15] == s->bias + 732000u) goto L_000b2b60;
    goto L_exit;
L_000b2b60:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732000u, s->source_elf + 732000u, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 9, 0);
    instructions++;
    { int rc = agr_aot_ldrb(s, 0, s->r[0] + 12u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000b2b60; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 7, 2);
    instructions++;
    agr_aot_mov_reg(s, 8, 3);
    instructions++;
    { int rc = agr_aot_ldr(s, 4, s->r[13] + 32u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000b2b60; } result = rc; goto L_exit; } }
    instructions++;
    s->r[15] = s->r[0] ? (s->bias + 732062u) : (s->bias + 732012u); { instructions++; goto L_after_000b2b60; }
L_after_000b2b60:
    blocks_done++;
    if (regs[15] == s->bias + 732062u) goto L_000b2b9e;
    if (regs[15] == s->bias + 732012u) goto L_000b2b6c;
    goto L_exit;
L_000b2b6c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732012u, s->source_elf + 732012u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[1], s->r[2]);
    instructions++;
    s->r[15] = agr_aot_condition(s, 2u) ? (s->bias + 732056u) : (s->bias + 732016u); { instructions++; goto L_after_000b2b6c; }
L_after_000b2b6c:
    blocks_done++;
    if (regs[15] == s->bias + 732056u) goto L_000b2b98;
    goto L_exit;
L_000b2b74:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732020u, s->source_elf + 732020u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[9] += s->r[2];
    instructions++;
    agr_aot_subs(s, 6, s->r[1], 4u);
    instructions++;
    regs[15] = s->bias + 732024u;
L_after_000b2b74:
    blocks_done++;
    goto L_exit;
L_000b2b7c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732028u, s->source_elf + 732028u, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 9, s->r[9], 1u);
    instructions++;
    { uint32_t addr = (s->r[6] + 4u); s->r[6] = s->r[6] + 4u; if ((rc = agr_aot_ldr(s, 0, addr))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000b2b7c; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 225832u), (s->bias + 732040u), 1); { instructions++; goto L_after_000b2b7c; }
L_after_000b2b7c:
    blocks_done++;
    goto L_exit;
L_000b2b88:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732040u, s->source_elf + 732040u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_adds(s, 3, s->r[0], 1u);
    instructions++;
    s->r[5] = s->r[0] & 0xffu;
    instructions++;
    agr_aot_set_itstate(s, 8u); s->r[15] = (s->bias + 732046u); { instructions++; goto L_after_000b2b88; }
L_after_000b2b88:
    blocks_done++;
    goto L_exit;
L_000b2b98:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732056u, s->source_elf + 732056u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 7);
    instructions++;
    if ((rc = agr_aot_ldmia_sp(s, 34800u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000b2b98; } result = rc; goto L_exit; }
    instructions++;
L_after_000b2b98:
    blocks_done++;
    goto L_exit;
L_000b2b9e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732062u, s->source_elf + 732062u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[1], s->r[2]);
    instructions++;
    s->r[15] = agr_aot_condition(s, 2u) ? (s->bias + 732056u) : (s->bias + 732066u); { instructions++; goto L_after_000b2b9e; }
L_after_000b2b9e:
    blocks_done++;
    if (regs[15] == s->bias + 732056u) goto L_000b2b98;
    goto L_exit;
L_000b2ba6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732070u, s->source_elf + 732070u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[10] += s->r[2];
    instructions++;
    agr_aot_adds(s, 3, s->r[4], 2u);
    instructions++;
    agr_aot_subs(s, 6, s->r[1], 4u);
    instructions++;
    regs[15] = s->bias + 732076u;
L_after_000b2ba6:
    blocks_done++;
    goto L_exit;
L_000b2bb0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732080u, s->source_elf + 732080u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_adds(s, 4, s->r[4], 1u);
    instructions++;
    s->r[15] = (s->bias + 732096u); { instructions++; goto L_after_000b2bb0; }
L_after_000b2bb0:
    blocks_done++;
    if (regs[15] == s->bias + 732096u) goto L_000b2bc0;
    goto L_exit;
L_000b2bb4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732084u, s->source_elf + 732084u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldrb(s, 3, s->r[3] + 13u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000b2bb4; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 732086u;
L_after_000b2bb4:
    blocks_done++;
    goto L_exit;
L_000b2bba:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732090u, s->source_elf + 732090u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_adds(s, 4, s->r[4], 1u);
    instructions++;
    agr_aot_cmp(s, s->r[4], s->r[10]);
    instructions++;
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 732056u) : (s->bias + 732096u); { instructions++; goto L_after_000b2bba; }
L_after_000b2bba:
    blocks_done++;
    if (regs[15] == s->bias + 732056u) goto L_000b2b98;
    if (regs[15] == s->bias + 732096u) goto L_000b2bc0;
    goto L_exit;
L_000b2bc0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732096u, s->source_elf + 732096u, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
    { uint32_t addr = (s->r[6] + 4u); s->r[6] = s->r[6] + 4u; if ((rc = agr_aot_ldr(s, 0, addr))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000b2bc0; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_cmp(s, s->r[0], 127u);
    instructions++;
    agr_aot_add_imm(s, 3, s->r[9], s->r[0]);
    instructions++;
    s->r[15] = agr_aot_condition(s, 9u) ? (s->bias + 732084u) : (s->bias + 732108u); { instructions++; goto L_after_000b2bc0; }
L_after_000b2bc0:
    blocks_done++;
    if (regs[15] == s->bias + 732084u) goto L_000b2bb4;
    if (regs[15] == s->bias + 732108u) goto L_000b2bcc;
    goto L_exit;
L_000b2bcc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732108u, s->source_elf + 732108u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 225832u), (s->bias + 732112u), 1); { instructions++; goto L_after_000b2bcc; }
L_after_000b2bcc:
    blocks_done++;
    goto L_exit;
L_000b2bd0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732112u, s->source_elf + 732112u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_adds(s, 2, s->r[0], 1u);
    instructions++;
    s->r[0] = s->r[0] & 0xffu;
    instructions++;
    agr_aot_set_itstate(s, 8u); s->r[15] = (s->bias + 732118u); { instructions++; goto L_after_000b2bd0; }
L_after_000b2bd0:
    blocks_done++;
    goto L_exit;
L_000b2be0:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732128u, s->source_elf + 732128u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16632u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 732130u;
L_after_000b2be0:
    blocks_done++;
    if (regs[15] == s->bias + 732130u) goto L_000b2be2;
    goto L_exit;
L_000b2be2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732130u, s->source_elf + 732130u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 6, 0);
    instructions++;
    agr_aot_movs_imm(s, 4, 0u);
    instructions++;
    s->r[15] = (s->bias + 732142u); { instructions++; goto L_after_000b2be2; }
L_after_000b2be2:
    blocks_done++;
    if (regs[15] == s->bias + 732142u) goto L_000b2bee;
    goto L_exit;
L_000b2be8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732136u, s->source_elf + 732136u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[4], 128u);
    instructions++;
    { uint32_t addr = s->r[3] + 13u; if (agr_aot_fault8(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store8(s, addr, s->r[0]); }
    instructions++;
    regs[15] = s->bias + 732140u;
L_after_000b2be8:
    blocks_done++;
    if (regs[15] == s->bias + 732140u) goto L_000b2bec;
    goto L_exit;
L_000b2bec:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732140u, s->source_elf + 732140u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = agr_aot_condition(s, 0u) ? (s->bias + 732224u) : (s->bias + 732142u); { instructions++; goto L_after_000b2bec; }
L_after_000b2bec:
    blocks_done++;
    if (regs[15] == s->bias + 732224u) goto L_000b2c40;
    if (regs[15] == s->bias + 732142u) goto L_000b2bee;
    goto L_exit;
L_000b2bee:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732142u, s->source_elf + 732142u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 4);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 225832u), (s->bias + 732148u), 1); { instructions++; goto L_after_000b2bee; }
L_after_000b2bee:
    blocks_done++;
    goto L_exit;
L_000b2bf4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732148u, s->source_elf + 732148u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_adds(s, 3, s->r[6], s->r[4]);
    instructions++;
    agr_aot_adds(s, 4, s->r[4], 1u);
    instructions++;
    agr_aot_adds(s, 2, s->r[0], 1u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 732136u) : (s->bias + 732156u); { instructions++; goto L_after_000b2bf4; }
L_after_000b2bf4:
    blocks_done++;
    if (regs[15] == s->bias + 732136u) goto L_000b2be8;
    if (regs[15] == s->bias + 732156u) goto L_000b2bfc;
    goto L_exit;
L_000b2bfc:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732156u, s->source_elf + 732156u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 3, 0u);
    instructions++;
    { uint32_t addr = s->r[6] + 12u; if (agr_aot_fault8(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store8(s, addr, s->r[3]); }
    instructions++;
    regs[15] = s->bias + 732160u;
L_after_000b2bfc:
    blocks_done++;
    if (regs[15] == s->bias + 732160u) goto L_000b2c00;
    goto L_exit;
L_000b2c00:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732160u, s->source_elf + 732160u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 5, s->r[6], 140u);
    instructions++;
    agr_aot_movs_imm(s, 4, 0u);
    instructions++;
    regs[15] = s->bias + 732166u;
L_after_000b2c00:
    blocks_done++;
    if (regs[15] == s->bias + 732166u) goto L_000b2c06;
    goto L_exit;
L_000b2c06:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732166u, s->source_elf + 732166u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 4);
    instructions++;
    agr_aot_adds(s, 4, s->r[4], 1u);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 225844u), (s->bias + 732174u), 1); { instructions++; goto L_after_000b2c06; }
L_after_000b2c06:
    blocks_done++;
    goto L_exit;
L_000b2c0e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732174u, s->source_elf + 732174u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[4], 256u);
    instructions++;
    { uint32_t addr = (s->r[5] + 4u); s->r[5] = s->r[5] + 4u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[0]); }
    instructions++;
    regs[15] = s->bias + 732182u;
L_after_000b2c0e:
    blocks_done++;
    if (regs[15] == s->bias + 732182u) goto L_000b2c16;
    goto L_exit;
L_000b2c16:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732182u, s->source_elf + 732182u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 732166u) : (s->bias + 732184u); { instructions++; goto L_after_000b2c16; }
L_after_000b2c16:
    blocks_done++;
    if (regs[15] == s->bias + 732166u) goto L_000b2c06;
    if (regs[15] == s->bias + 732184u) goto L_000b2c18;
    goto L_exit;
L_000b2c18:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732184u, s->source_elf + 732184u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 5, 6);
    instructions++;
    agr_aot_movs_imm(s, 4, 0u);
    instructions++;
    agr_aot_movs_imm(s, 7, 1u);
    instructions++;
    regs[15] = s->bias + 732190u;
L_after_000b2c18:
    blocks_done++;
    if (regs[15] == s->bias + 732190u) goto L_000b2c1e;
    goto L_exit;
L_000b2c1e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732190u, s->source_elf + 732190u, 16u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_adds(s, 3, s->r[6], s->r[4]);
    instructions++;
    agr_aot_lsls_reg(s, 1, s->r[7], s->r[4]);
    instructions++;
    agr_aot_mov_reg(s, 0, 6);
    instructions++;
    agr_aot_adds(s, 4, s->r[4], 1u);
    instructions++;
    s->r[1] = s->r[1] & 0xffu;
    instructions++;
    { uint32_t addr = s->r[3] + 1168u; if (agr_aot_fault8(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store8(s, addr, s->r[1]); }
    instructions++;
    regs[15] = s->bias + 732206u;
L_after_000b2c1e:
    blocks_done++;
    if (regs[15] == s->bias + 732206u) goto L_000b2c2e;
    goto L_exit;
L_000b2c2e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732206u, s->source_elf + 732206u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 731368u) | 1u, (s->bias + 732210u), 1); { instructions++; goto L_after_000b2c2e; }
L_after_000b2c2e:
    blocks_done++;
    goto L_exit;
L_000b2c32:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732210u, s->source_elf + 732210u, 10u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[4], 16u);
    instructions++;
    agr_aot_add_imm(s, 5, s->r[5], 4u);
    instructions++;
    { uint32_t addr = s->r[5] + 1180u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[0]); }
    instructions++;
    regs[15] = s->bias + 732220u;
L_after_000b2c32:
    blocks_done++;
    if (regs[15] == s->bias + 732220u) goto L_000b2c3c;
    goto L_exit;
L_000b2c3c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732220u, s->source_elf + 732220u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 732190u) : (s->bias + 732222u); { instructions++; goto L_after_000b2c3c; }
L_after_000b2c3c:
    blocks_done++;
    if (regs[15] == s->bias + 732190u) goto L_000b2c1e;
    if (regs[15] == s->bias + 732222u) goto L_000b2c3e;
    goto L_exit;
L_000b2c3e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732222u, s->source_elf + 732222u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    if ((rc = agr_aot_ldmia_sp(s, 33016u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000b2c3e; } result = rc; goto L_exit; }
    instructions++;
L_after_000b2c3e:
    blocks_done++;
    goto L_exit;
L_000b2c40:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732224u, s->source_elf + 732224u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 3, 1u);
    instructions++;
    { uint32_t addr = s->r[6] + 12u; if (agr_aot_fault8(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store8(s, addr, s->r[3]); }
    instructions++;
    regs[15] = s->bias + 732228u;
L_after_000b2c40:
    blocks_done++;
    if (regs[15] == s->bias + 732228u) goto L_000b2c44;
    goto L_exit;
L_000b2c44:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732228u, s->source_elf + 732228u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 732160u); { instructions++; goto L_after_000b2c44; }
L_after_000b2c44:
    blocks_done++;
    if (regs[15] == s->bias + 732160u) goto L_000b2c00;
    goto L_exit;
L_000b2c48:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732232u, s->source_elf + 732232u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 0, s->r[0] + 4u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000b2c48; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_branch_reg(s, s->r[14], 0u, 0); { instructions++; goto L_after_000b2c48; }
L_after_000b2c48:
    blocks_done++;
    goto L_exit;
L_000b2c4c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732236u, s->source_elf + 732236u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    { int rc = agr_aot_ldr(s, 2, s->r[0] + 4u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000b2c4c; } result = rc; goto L_exit; } }
    instructions++;
    { int rc = agr_aot_ldr(s, 3, (s->bias + 732240u) + 76u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000b2c4c; } result = rc; goto L_exit; } }
    instructions++;
    if (agr_aot_stmdb_sp(s, 16432u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 732242u;
L_after_000b2c4c:
    blocks_done++;
    if (regs[15] == s->bias + 732242u) goto L_000b2c52;
    goto L_exit;
L_000b2c52:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732242u, s->source_elf + 732242u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[3] += (s->bias + 732246u);
    instructions++;
    { int rc = agr_aot_ldr(s, 3, s->r[3] + 0u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000b2c52; } result = rc; goto L_exit; } }
    instructions++;
    agr_aot_mov_reg(s, 4, 0);
    instructions++;
    { int rc = agr_aot_ldr(s, 1, (s->bias + 732252u) + 68u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000b2c52; } result = rc; goto L_exit; } }
    instructions++;
    regs[15] = s->bias + 732250u;
L_after_000b2c52:
    blocks_done++;
    goto L_exit;
L_000b2c5e:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732254u, s->source_elf + 732254u, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[13] -= 12u;
    instructions++;
    agr_aot_cmp(s, s->r[0], s->r[3]);
    instructions++;
    s->r[1] += (s->bias + 732262u);
    instructions++;
    agr_aot_add_imm(s, 1, s->r[1], 8u);
    instructions++;
    { uint32_t addr = s->r[4] + 0u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[1]); }
    instructions++;
    regs[15] = s->bias + 732266u;
L_after_000b2c5e:
    blocks_done++;
    if (regs[15] == s->bias + 732266u) goto L_000b2c6a;
    goto L_exit;
L_000b2c6a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732266u, s->source_elf + 732266u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 732280u) : (s->bias + 732268u); { instructions++; goto L_after_000b2c6a; }
L_after_000b2c6a:
    blocks_done++;
    if (regs[15] == s->bias + 732280u) goto L_000b2c78;
    if (regs[15] == s->bias + 732268u) goto L_000b2c6c;
    goto L_exit;
L_000b2c6c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732268u, s->source_elf + 732268u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 4);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 535636u) | 1u, (s->bias + 732274u), 1); { instructions++; goto L_after_000b2c6c; }
L_after_000b2c6c:
    blocks_done++;
    goto L_exit;
L_000b2c72:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732274u, s->source_elf + 732274u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 4);
    instructions++;
    s->r[13] += 12u;
    instructions++;
    if ((rc = agr_aot_ldmia_sp(s, 32816u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000b2c72; } result = rc; goto L_exit; }
    instructions++;
L_after_000b2c72:
    blocks_done++;
    goto L_exit;
L_000b2c78:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732280u, s->source_elf + 732280u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_subs(s, 2, s->r[2], 4u);
    instructions++;
    atomic_thread_fence(memory_order_seq_cst);
    instructions++;
    regs[15] = s->bias + 732286u;
L_after_000b2c78:
    blocks_done++;
    goto L_exit;
L_000b2c82:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732290u, s->source_elf + 732290u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_subs(s, 1, s->r[3], 1u);
    instructions++;
    regs[15] = s->bias + 732292u;
L_after_000b2c82:
    blocks_done++;
    goto L_exit;
L_000b2c88:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732296u, s->source_elf + 732296u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[5], 0u);
    instructions++;
    s->r[15] = agr_aot_condition(s, 1u) ? (s->bias + 732286u) : (s->bias + 732300u); { instructions++; goto L_after_000b2c88; }
L_after_000b2c88:
    blocks_done++;
    if (regs[15] == s->bias + 732300u) goto L_000b2c8c;
    goto L_exit;
L_000b2c8c:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732300u, s->source_elf + 732300u, 8u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_cmp(s, s->r[3], 0u);
    instructions++;
    atomic_thread_fence(memory_order_seq_cst);
    instructions++;
    s->r[15] = agr_aot_condition(s, 12u) ? (s->bias + 732268u) : (s->bias + 732308u); { instructions++; goto L_after_000b2c8c; }
L_after_000b2c8c:
    blocks_done++;
    if (regs[15] == s->bias + 732268u) goto L_000b2c6c;
    if (regs[15] == s->bias + 732308u) goto L_000b2c94;
    goto L_exit;
L_000b2c94:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732308u, s->source_elf + 732308u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_add_imm(s, 1, s->r[13], 4u);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 722772u) | 1u, (s->bias + 732314u), 1); { instructions++; goto L_after_000b2c94; }
L_after_000b2c94:
    blocks_done++;
    goto L_exit;
L_000b2c9a:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732314u, s->source_elf + 732314u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    s->r[15] = (s->bias + 732268u); { instructions++; goto L_after_000b2c9a; }
L_after_000b2c9a:
    blocks_done++;
    if (regs[15] == s->bias + 732268u) goto L_000b2c6c;
    goto L_exit;
L_000b2ca4:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732324u, s->source_elf + 732324u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16400u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 732326u;
L_after_000b2ca4:
    blocks_done++;
    if (regs[15] == s->bias + 732326u) goto L_000b2ca6;
    goto L_exit;
L_000b2ca6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732326u, s->source_elf + 732326u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 4, 0);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 732236u) | 1u, (s->bias + 732332u), 1); { instructions++; goto L_after_000b2ca6; }
L_after_000b2ca6:
    blocks_done++;
    if (regs[15] == s->bias + 732236u) goto L_000b2c4c;
    goto L_exit;
L_000b2cac:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732332u, s->source_elf + 732332u, 6u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 4);
    instructions++;
    agr_aot_branch_reg(s, (s->bias + 535980u) | 1u, (s->bias + 732338u), 1); { instructions++; goto L_after_000b2cac; }
L_after_000b2cac:
    blocks_done++;
    goto L_exit;
L_000b2cb2:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732338u, s->source_elf + 732338u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 4);
    instructions++;
    if ((rc = agr_aot_ldmia_sp(s, 32784u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000b2cb2; } result = rc; goto L_exit; }
    instructions++;
L_after_000b2cb2:
    blocks_done++;
    goto L_exit;
L_000b2cb8:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732344u, s->source_elf + 732344u, 2u)) { result = AGR_AOT_MISS; goto L_exit; }
    if (agr_aot_stmdb_sp(s, 16440u)) { result = AGR_AOT_FAULT; goto L_exit; }
    instructions++;
    regs[15] = s->bias + 732346u;
L_after_000b2cb8:
    blocks_done++;
    if (regs[15] == s->bias + 732346u) goto L_000b2cba;
    goto L_exit;
L_000b2cba:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732346u, s->source_elf + 732346u, 12u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 4, 0);
    instructions++;
    { int rc = agr_aot_ldr(s, 3, (s->bias + 732352u) + 40u); if (rc) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000b2cba; } result = rc; goto L_exit; } }
    instructions++;
    s->r[3] += (s->bias + 732354u);
    instructions++;
    agr_aot_adds(s, 3, s->r[3], 8u);
    instructions++;
    { uint32_t addr = s->r[0]; s->r[0] = s->r[0] + 4u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[3]); }
    instructions++;
    regs[15] = s->bias + 732358u;
L_after_000b2cba:
    blocks_done++;
    if (regs[15] == s->bias + 732358u) goto L_000b2cc6;
    goto L_exit;
L_000b2cc6:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732358u, s->source_elf + 732358u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_branch_reg(s, (s->bias + 725824u) | 1u, (s->bias + 732362u), 1); { instructions++; goto L_after_000b2cc6; }
L_after_000b2cc6:
    blocks_done++;
    goto L_exit;
L_000b2cca:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732362u, s->source_elf + 732362u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_mov_reg(s, 0, 4);
    instructions++;
    if ((rc = agr_aot_ldmia_sp(s, 32824u))) { if (rc == AGR_AOT_BOUNDARY) { instructions++; goto L_after_000b2cca; } result = rc; goto L_exit; }
    instructions++;
L_after_000b2cca:
    blocks_done++;
    goto L_exit;
L_000b2cec:
    if (blocks_done >= outer->region_budget) goto L_exit;
    if (cpsr & 0x0600fc00u) goto L_exit;
    if ((cpsr & 0x20u) != 0x20u) { result = AGR_AOT_MODE_MISS; goto L_exit; }
    if (memcmp(s->mem + s->bias + 732396u, s->source_elf + 732396u, 4u)) { result = AGR_AOT_MISS; goto L_exit; }
    agr_aot_movs_imm(s, 2, 0u);
    instructions++;
    { uint32_t addr = s->r[0] + 0u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } agr_aot_store32(s, addr, s->r[2]); }
    instructions++;
    regs[15] = s->bias + 732400u;
L_after_000b2cec:
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
    {731954u, agr_region_00725, 1u, 0u},
    {731956u, agr_region_00725, 2u, 1u},
    {731960u, agr_region_00725, 2u, 2u},
    {731964u, agr_region_00725, 2u, 3u},
    {731968u, agr_region_00725, 2u, 4u},
    {731972u, agr_region_00725, 2u, 5u},
    {731978u, agr_region_00725, 2u, 6u},
    {731988u, agr_region_00725, 3u, 7u},
    {731996u, agr_region_00725, 1u, 8u},
    {732000u, agr_region_00725, 6u, 9u},
    {732012u, agr_region_00725, 2u, 10u},
    {732020u, agr_region_00725, 2u, 11u},
    {732028u, agr_region_00725, 3u, 12u},
    {732040u, agr_region_00725, 3u, 13u},
    {732056u, agr_region_00725, 2u, 14u},
    {732062u, agr_region_00725, 2u, 15u},
    {732070u, agr_region_00725, 3u, 16u},
    {732080u, agr_region_00725, 2u, 17u},
    {732084u, agr_region_00725, 1u, 18u},
    {732090u, agr_region_00725, 3u, 19u},
    {732096u, agr_region_00725, 4u, 20u},
    {732108u, agr_region_00725, 1u, 21u},
    {732112u, agr_region_00725, 3u, 22u},
    {732128u, agr_region_00725, 1u, 23u},
    {732130u, agr_region_00725, 3u, 24u},
    {732136u, agr_region_00725, 2u, 25u},
    {732140u, agr_region_00725, 1u, 26u},
    {732142u, agr_region_00725, 2u, 27u},
    {732148u, agr_region_00725, 4u, 28u},
    {732156u, agr_region_00725, 2u, 29u},
    {732160u, agr_region_00725, 2u, 30u},
    {732166u, agr_region_00725, 3u, 31u},
    {732174u, agr_region_00725, 2u, 32u},
    {732182u, agr_region_00725, 1u, 33u},
    {732184u, agr_region_00725, 3u, 34u},
    {732190u, agr_region_00725, 6u, 35u},
    {732206u, agr_region_00725, 1u, 36u},
    {732210u, agr_region_00725, 3u, 37u},
    {732220u, agr_region_00725, 1u, 38u},
    {732222u, agr_region_00725, 1u, 39u},
    {732224u, agr_region_00725, 2u, 40u},
    {732228u, agr_region_00725, 1u, 41u},
    {732232u, agr_region_00725, 2u, 42u},
    {732236u, agr_region_00725, 3u, 43u},
    {732242u, agr_region_00725, 4u, 44u},
    {732254u, agr_region_00725, 5u, 45u},
    {732266u, agr_region_00725, 1u, 46u},
    {732268u, agr_region_00725, 2u, 47u},
    {732274u, agr_region_00725, 3u, 48u},
    {732280u, agr_region_00725, 2u, 49u},
    {732290u, agr_region_00725, 1u, 50u},
    {732296u, agr_region_00725, 2u, 51u},
    {732300u, agr_region_00725, 3u, 52u},
    {732308u, agr_region_00725, 2u, 53u},
    {732314u, agr_region_00725, 1u, 54u},
    {732324u, agr_region_00725, 1u, 55u},
    {732326u, agr_region_00725, 2u, 56u},
    {732332u, agr_region_00725, 2u, 57u},
    {732338u, agr_region_00725, 2u, 58u},
    {732344u, agr_region_00725, 1u, 59u},
    {732346u, agr_region_00725, 5u, 60u},
    {732358u, agr_region_00725, 1u, 61u},
    {732362u, agr_region_00725, 2u, 62u},
    {732396u, agr_region_00725, 2u, 63u},
};
const uint32_t agr_aot_fast_block_count = 128u;
const AgrAotEntry agr_aot_fast_hash[] = {{0, 0, 0}};
const uint32_t agr_aot_fast_hash_mask = 0u;
const uint32_t agr_aot_fast_direct_base = 635824u;
const uint32_t agr_aot_fast_direct_count = 48287u;
const uint32_t agr_aot_fast_direct[48287] = {
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
    [48065] = 65u,
    [48066] = 66u,
    [48068] = 67u,
    [48070] = 68u,
    [48072] = 69u,
    [48074] = 70u,
    [48077] = 71u,
    [48082] = 72u,
    [48086] = 73u,
    [48088] = 74u,
    [48094] = 75u,
    [48098] = 76u,
    [48102] = 77u,
    [48108] = 78u,
    [48116] = 79u,
    [48119] = 80u,
    [48123] = 81u,
    [48128] = 82u,
    [48130] = 83u,
    [48133] = 84u,
    [48136] = 85u,
    [48142] = 86u,
    [48144] = 87u,
    [48152] = 88u,
    [48153] = 89u,
    [48156] = 90u,
    [48158] = 91u,
    [48159] = 92u,
    [48162] = 93u,
    [48166] = 94u,
    [48168] = 95u,
    [48171] = 96u,
    [48175] = 97u,
    [48179] = 98u,
    [48180] = 99u,
    [48183] = 100u,
    [48191] = 101u,
    [48193] = 102u,
    [48198] = 103u,
    [48199] = 104u,
    [48200] = 105u,
    [48202] = 106u,
    [48204] = 107u,
    [48206] = 108u,
    [48209] = 109u,
    [48215] = 110u,
    [48221] = 111u,
    [48222] = 112u,
    [48225] = 113u,
    [48228] = 114u,
    [48233] = 115u,
    [48236] = 116u,
    [48238] = 117u,
    [48242] = 118u,
    [48245] = 119u,
    [48250] = 120u,
    [48251] = 121u,
    [48254] = 122u,
    [48257] = 123u,
    [48260] = 124u,
    [48261] = 125u,
    [48267] = 126u,
    [48269] = 127u,
    [48286] = 128u,
};
const uint32_t agr_aot_fast_relocatable = 1u;
const uint64_t agr_aot_input_elf_fnv64 = 1641235115063234436ull;
const uint32_t agr_aot_input_elf_bytes = 882136u;
