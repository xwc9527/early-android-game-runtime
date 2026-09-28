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
    goto L_00000e94;
L_00000e94:
    { uint32_t addr = r13 - 32u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } memcpy(mem + addr + 0u, &r3, 4); memcpy(mem + addr + 4u, &r4, 4); memcpy(mem + addr + 8u, &r5, 4); memcpy(mem + addr + 12u, &r6, 4); memcpy(mem + addr + 16u, &r7, 4); memcpy(mem + addr + 20u, &r8, 4); memcpy(mem + addr + 24u, &r9, 4); memcpy(mem + addr + 28u, &r14, 4); r13 -= 32u; }
    r15 = bias + 3736u;
    if (r15 == bias + 3736u) goto L_00000e98;
    goto L_exit;
L_00000e98:
    r7 = r3;
    { uint32_t addr = r0 + 0u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } memcpy(&r3, mem + addr, 4); }
    r8 = r2;
    r1 = r2;
    r2 = 0u; cpsr = (cpsr & ~0xc0000000u) | ((r2 >> 31) << 31) | ((r2 == 0u) << 30);
    r4 = r0;
    r9 = 5126u & 0xffffu;
    { uint32_t addr = r3 + 756u; if (agr_aot_fault(addr)) { result = AGR_AOT_FAULT; goto L_exit; } memcpy(&r3, mem + addr, 4); }
    { uint32_t target = r3; r14 = (bias + 3758u) | 1u; cpsr = (target & 1u) ? (cpsr | 0x20u) : (cpsr & ~0x20u); r15 = target & ~1u; }
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
