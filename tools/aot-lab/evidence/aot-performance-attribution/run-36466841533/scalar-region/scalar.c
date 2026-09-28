#include "agr_aot.h"

static inline int agr_scalar_condition(uint32_t cpsr, uint32_t condition) {
    uint32_t n = (cpsr >> 31) & 1u, z = (cpsr >> 30) & 1u;
    uint32_t c = (cpsr >> 29) & 1u, v = (cpsr >> 28) & 1u;
    switch (condition & 15u) {
        case 0: return z; case 1: return !z; case 2: return c; case 3: return !c;
        case 4: return n; case 5: return !n; case 6: return v; case 7: return !v;
        case 8: return c && !z; case 9: return !c || z;
        case 10: return n == v; case 11: return n != v;
        case 12: return !z && n == v; case 13: return z || n != v;
        case 14: return 1; default: return 0;
    }
}

int agr_attribution_scalar(AgrAotRegs *outer) {
    uint8_t *mem = outer->mem;
    uint32_t bias = outer->bias;
    uint32_t cpsr = *outer->cpsr;
    int result = AGR_AOT_BOUNDARY;
    uint32_t r0 = outer->r[0];
    uint32_t r1 = outer->r[1];
    uint32_t r2 = outer->r[2];
    uint32_t r3 = outer->r[3];
    uint32_t r4 = outer->r[4];
    uint32_t r5 = outer->r[5];
    uint32_t r6 = outer->r[6];
    uint32_t r7 = outer->r[7];
    uint32_t r8 = outer->r[8];
    uint32_t r9 = outer->r[9];
    uint32_t r10 = outer->r[10];
    uint32_t r11 = outer->r[11];
    uint32_t r12 = outer->r[12];
    uint32_t r13 = outer->r[13];
    uint32_t r14 = outer->r[14];
    uint32_t r15 = outer->r[15];
    goto L_0009b480;
L_0009b480:
    { uint32_t lhs = r2, rhs = 0u; uint32_t value = lhs - rhs; cpsr = (cpsr & ~0xf0000000u) | ((value >> 31) << 31) | ((value == 0u) << 30) | ((lhs >= rhs) << 29) | (((((lhs ^ rhs) & (lhs ^ value))) >> 31) << 28); }
    r15 = agr_scalar_condition(cpsr, 1u) ? bias + 636022u : bias + 636036u;
    if (r15 == bias + 636036u) goto L_0009b484;
    goto L_exit;
L_0009b484:
    atomic_thread_fence(memory_order_seq_cst);
    { uint32_t addr = r5 + 4u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } memcpy(&r4, mem + addr, 4); }
    { uint32_t addr = r4 + (r6 << 2u); if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } memcpy(&r0, mem + addr, 4); }
    r15 = !r0 ? bias + 636078u : bias + 636048u;
    if (r15 == bias + 636078u) goto L_0009b4ae;
    goto L_exit;
L_0009b4ae:
    { uint32_t addr = r5 + 8u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } memcpy(&r2, mem + addr, 4); }
    { uint32_t addr = r4 + (r6 << 2u); if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } memcpy(mem + addr, &r8, 4); }
    r15 = bias + 636084u;
    if (r15 == bias + 636084u) goto L_0009b4b4;
    goto L_exit;
L_0009b4b4:
    r15 = !r2 ? bias + 636154u : bias + 636086u;
    if (r15 == bias + 636086u) goto L_0009b4b6;
    goto L_exit;
L_0009b4b6:
    r4 = 0u; cpsr = (cpsr & ~0xc0000000u) | ((r4 >> 31) << 31) | ((r4 == 0u) << 30);
    r7 = r4;
    r15 = bias + 636104u;
    if (r15 == bias + 636104u) goto L_0009b4c8;
    goto L_exit;
L_0009b4c2:
    { uint32_t lhs = r4, rhs = 1u; uint32_t value = lhs + rhs; r4 = value; cpsr = (cpsr & ~0xf0000000u) | ((value >> 31) << 31) | ((value == 0u) << 30) | (((uint32_t)(((uint64_t)lhs + rhs) >> 32)) << 29) | (((((~(lhs ^ rhs)) & (lhs ^ value))) >> 31) << 28); }
    { uint32_t lhs = r2, rhs = r4; uint32_t value = lhs - rhs; cpsr = (cpsr & ~0xf0000000u) | ((value >> 31) << 31) | ((value == 0u) << 30) | ((lhs >= rhs) << 29) | (((((lhs ^ rhs) & (lhs ^ value))) >> 31) << 28); }
    r15 = agr_scalar_condition(cpsr, 9u) ? bias + 636158u : bias + 636104u;
    if (r15 == bias + 636158u) goto L_0009b4fe;
    if (r15 == bias + 636104u) goto L_0009b4c8;
    goto L_exit;
L_0009b4c8:
    { uint32_t addr = r5 + 12u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } memcpy(&r3, mem + addr, 4); }
    { uint32_t value = r4; r6 = value << 2u; uint32_t carry = 2u ? ((value >> (32u - 2u)) & 1u) : ((cpsr >> 29) & 1u); cpsr = (cpsr & ~0xe0000000u) | ((r6 >> 31) << 31) | ((r6 == 0u) << 30) | (carry << 29); }
    { uint32_t addr = r3 + (r4 << 2u); if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } memcpy(&r0, mem + addr, 4); }
    { uint32_t lhs = r0, rhs = 0u; uint32_t value = lhs - rhs; cpsr = (cpsr & ~0xf0000000u) | ((value >> 31) << 31) | ((value == 0u) << 30) | ((lhs >= rhs) << 29) | (((((lhs ^ rhs) & (lhs ^ value))) >> 31) << 28); }
    r15 = agr_scalar_condition(cpsr, 0u) ? bias + 636098u : bias + 636116u;
    if (r15 == bias + 636098u) goto L_0009b4c2;
    goto L_exit;
L_0009b4fe:
    { uint32_t addr = r13; if (agr_aot_fault(addr + 0u)) { result = AGR_AOT_FAULT; goto L_exit; } uint32_t loaded_4; memcpy(&loaded_4, mem + addr + 0u, 4); if (agr_aot_fault(addr + 4u)) { result = AGR_AOT_FAULT; goto L_exit; } uint32_t loaded_5; memcpy(&loaded_5, mem + addr + 4u, 4); if (agr_aot_fault(addr + 8u)) { result = AGR_AOT_FAULT; goto L_exit; } uint32_t loaded_6; memcpy(&loaded_6, mem + addr + 8u, 4); if (agr_aot_fault(addr + 12u)) { result = AGR_AOT_FAULT; goto L_exit; } uint32_t loaded_7; memcpy(&loaded_7, mem + addr + 12u, 4); if (agr_aot_fault(addr + 16u)) { result = AGR_AOT_FAULT; goto L_exit; } uint32_t loaded_8; memcpy(&loaded_8, mem + addr + 16u, 4); if (agr_aot_fault(addr + 20u)) { result = AGR_AOT_FAULT; goto L_exit; } uint32_t loaded_9; memcpy(&loaded_9, mem + addr + 20u, 4); if (agr_aot_fault(addr + 24u)) { result = AGR_AOT_FAULT; goto L_exit; } uint32_t loaded_10; memcpy(&loaded_10, mem + addr + 24u, 4); if (agr_aot_fault(addr + 28u)) { result = AGR_AOT_FAULT; goto L_exit; } uint32_t loaded_15; memcpy(&loaded_15, mem + addr + 28u, 4); r13 += 32u; r4 = loaded_4; r5 = loaded_5; r6 = loaded_6; r7 = loaded_7; r8 = loaded_8; r9 = loaded_9; r10 = loaded_10; r15 = loaded_15; cpsr = (r15 & 1u) ? (cpsr | 0x20u) : (cpsr & ~0x20u); r15 &= ~1u; }
    goto L_exit;
L_exit:
    outer->r[0] = r0;
    outer->r[1] = r1;
    outer->r[2] = r2;
    outer->r[3] = r3;
    outer->r[4] = r4;
    outer->r[5] = r5;
    outer->r[6] = r6;
    outer->r[7] = r7;
    outer->r[8] = r8;
    outer->r[9] = r9;
    outer->r[10] = r10;
    outer->r[11] = r11;
    outer->r[12] = r12;
    outer->r[13] = r13;
    outer->r[14] = r14;
    outer->r[15] = r15;
    *outer->cpsr = cpsr;
    return result;
}
