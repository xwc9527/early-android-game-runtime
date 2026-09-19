#include "../../Runtime/NativeCore/agr_runtime.h"
#include "../../Runtime/Ehabi/agr_ehabi.h"
#include "../../Runtime/NativeCore/agr_elf32.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHECK(x) do { if (!(x)) { fprintf(stderr,"FAIL %s:%d: %s\n",__FILE__,__LINE__,#x); return 1; } } while (0)

enum { ELF_SIZE = 0x4000, STACK_TOP = 0x000fc000, STACK_SIZE = 0x10000 };
#define COMPACT_POP_R4_LR 0x80a8b000u
#define COMPACT_VFPX_D8 0x80b8b000u
#define COMPACT_IWMMXT_WR10 0x80c0b000u

extern void *arm_interp_create(void);
extern uint8_t *arm_interp_memory_base(void *);
extern void arm_interp_destroy(void *);
extern int32_t arm_interp_write(void *, uint32_t, const uint8_t *, uint32_t);
extern int32_t arm_interp_load(void *, uint32_t, const uint8_t *, uint32_t);
extern int32_t arm_interp_read(void *, uint32_t, uint8_t *, uint32_t);
extern int32_t arm_interp_set_page_permissions(void *, uint32_t, uint32_t, uint32_t);
extern int32_t arm_interp_set_reg(void *, uint32_t, uint32_t);
extern uint32_t arm_interp_get_reg(void *, uint32_t);
extern int32_t arm_interp_set_cpsr(void *, uint32_t);
extern uint32_t arm_interp_get_cpsr(void *);
extern int32_t arm_interp_run(void *, uint64_t *, uint32_t *);

typedef struct harness { void *cpu; } harness;
static uint8_t *memory_base(void *o) { return arm_interp_memory_base(((harness *)o)->cpu); }
static int32_t mem_read(void *o, uint32_t a, void *p, uint32_t n) {
    return arm_interp_read(((harness *)o)->cpu, a, (uint8_t *)p, n);
}
static int32_t mem_write(void *o, uint32_t a, const void *p, uint32_t n) {
    return arm_interp_write(((harness *)o)->cpu, a, (const uint8_t *)p, n);
}
static int32_t mem_load(void *o, uint32_t a, const void *p, uint32_t n) {
    return arm_interp_load(((harness *)o)->cpu, a, (const uint8_t *)p, n);
}
static int32_t mem_protect(void *o, uint32_t a, uint32_t n, uint32_t p) {
    return arm_interp_set_page_permissions(((harness *)o)->cpu, a, n, p);
}
static uint32_t host_import(void *o, const char *n, uint32_t t) {
    (void)o; (void)n; (void)t; return 0;
}

static void put_u16(uint8_t *p, uint16_t v) { memcpy(p, &v, 2); }
static void put_u32(uint8_t *p, uint32_t v) { memcpy(p, &v, 4); }
static uint32_t prel31(uint32_t from, uint32_t to) { return (to - from) & 0x7fffffffu; }
static uint32_t arm_bl(uint32_t from, uint32_t to) {
    return 0xeb000000u | (((to - (from + 8u)) >> 2) & 0x00ffffffu);
}
static uint32_t thumb_bl(uint32_t from, uint32_t to) {
    int32_t offset = (int32_t)to - (int32_t)(from + 4u);
    uint32_t s = offset < 0 ? 1u : 0u;
    uint32_t imm11 = ((uint32_t)offset >> 1) & 0x7ffu;
    uint32_t imm10 = ((uint32_t)offset >> 12) & 0x3ffu;
    uint32_t j1 = (~(((uint32_t)offset >> 23) ^ s)) & 1u;
    uint32_t j2 = (~(((uint32_t)offset >> 22) ^ s)) & 1u;
    uint16_t hw1 = (uint16_t)(0xf000u | (s << 10) | imm10);
    uint16_t hw2 = (uint16_t)(0xc000u | (j1 << 13) | (1u << 12) | (j2 << 11) | imm11);
    return (uint32_t)hw1 | ((uint32_t)hw2 << 16);
}

static void init_ehdr(uint8_t *elf, uint16_t phnum) {
    Elf32_Ehdr eh;
    memset(&eh, 0, sizeof(eh));
    memcpy(eh.e_ident, ELFMAG, SELFMAG);
    eh.e_ident[EI_CLASS] = ELFCLASS32;
    eh.e_ident[5] = 1;
    eh.e_type = 3;
    eh.e_machine = EM_ARM;
    eh.e_version = 1;
    eh.e_ehsize = sizeof(eh);
    eh.e_phoff = sizeof(eh);
    eh.e_phentsize = sizeof(Elf32_Phdr);
    eh.e_phnum = phnum;
    memcpy(elf, &eh, sizeof(eh));
}

static void write_phdr(uint8_t *elf, int index, Elf32_Phdr ph) {
    memcpy(elf + sizeof(Elf32_Ehdr) + (size_t)index * sizeof(ph), &ph, sizeof(ph));
}

static void write_dyn(uint8_t *elf, uint32_t at, uint32_t *off, int32_t tag, uint32_t value) {
    Elf32_Dyn d;
    d.d_tag = tag;
    d.d_un.d_val = value;
    memcpy(elf + at + *off, &d, sizeof(d));
    *off += sizeof(d);
}

static void write_sym(uint8_t *elf, uint32_t at, uint32_t name, uint32_t value) {
    Elf32_Sym s;
    memset(&s, 0, sizeof(s));
    s.st_name = name;
    s.st_value = value;
    s.st_info = (STB_GLOBAL << 4) | STT_FUNC;
    s.st_shndx = 1;
    memcpy(elf + at, &s, sizeof(s));
}

static void emit_min_dynamic(uint8_t *elf, uint32_t dyn, uint32_t str, uint32_t sym, uint32_t hash,
                             const char *strtab, uint32_t str_size, uint32_t nchain,
                             const uint32_t *sym_name, const uint32_t *sym_value, uint32_t nsym,
                             uint32_t rel, uint32_t rel_count) {
    uint32_t off = 0, i;
    memcpy(elf + str, strtab, str_size);
    memset(elf + sym, 0, sizeof(Elf32_Sym));
    for (i = 0; i < nsym; i++) write_sym(elf, sym + (i + 1) * sizeof(Elf32_Sym), sym_name[i], sym_value[i]);
    put_u32(elf + hash, 1);
    put_u32(elf + hash + 4, nchain);
    put_u32(elf + hash + 8, nsym ? 1 : 0);
    for (i = 1; i < nchain; i++) put_u32(elf + hash + 8 + 4 + i * 4, i + 1 < nchain ? i + 1 : 0);
    write_dyn(elf, dyn, &off, DT_HASH, hash);
    write_dyn(elf, dyn, &off, DT_STRTAB, str);
    write_dyn(elf, dyn, &off, DT_SYMTAB, sym);
    write_dyn(elf, dyn, &off, DT_STRSZ, str_size);
    write_dyn(elf, dyn, &off, DT_SYMENT, sizeof(Elf32_Sym));
    if (rel_count) {
        write_dyn(elf, dyn, &off, DT_REL, rel);
        write_dyn(elf, dyn, &off, DT_RELSZ, rel_count * sizeof(Elf32_Rel));
        write_dyn(elf, dyn, &off, DT_RELENT, sizeof(Elf32_Rel));
    }
    write_dyn(elf, dyn, &off, DT_NULL, 0);
}

static void emit_exidx(uint8_t *elf, uint32_t exidx, const uint32_t *fn, const uint32_t *insn, uint32_t count) {
    uint32_t i;
    for (i = 0; i < count; i++) {
        put_u32(elf + exidx + i * 8, prel31(exidx + i * 8, fn[i]));
        put_u32(elf + exidx + i * 8 + 4, insn[i]);
    }
}

static void emit_headers(uint8_t *elf, uint32_t dyn, uint32_t dyn_size, uint32_t exidx, uint32_t exidx_size) {
    Elf32_Phdr load = {PT_LOAD, 0, 0, 0, ELF_SIZE, ELF_SIZE, 5, 0x1000};
    Elf32_Phdr dynamic = {PT_DYNAMIC, dyn, dyn, dyn, dyn_size, dyn_size, 4, 4};
    Elf32_Phdr armex = {PT_ARM_EXIDX, exidx, exidx, exidx, exidx_size, exidx_size, 4, 4};
    init_ehdr(elf, 3);
    write_phdr(elf, 0, load);
    write_phdr(elf, 1, dynamic);
    write_phdr(elf, 2, armex);
}

static void emit_arm_chain(uint8_t *elf) {
    const char strtab[] = "\0A\0B\0C\0probe";
    const uint32_t names[] = {1, 3, 5, 7};
    const uint32_t values[] = {0x1000, 0x1014, 0x1028, 0x1038};
    uint32_t fn[] = {0x1000, 0x1014, 0x1028, 0x1038};
    uint32_t insn[] = {COMPACT_POP_R4_LR, COMPACT_POP_R4_LR, COMPACT_POP_R4_LR, EXIDX_CANTUNWIND};
    memset(elf, 0, ELF_SIZE);
    put_u32(elf + 0x1000, 0xe92d4010u);
    put_u32(elf + 0x1004, arm_bl(0x1004, 0x1014));
    put_u32(elf + 0x1008, 0xe8bd8010u);
    put_u32(elf + 0x100c, 0xe1a00000u);
    put_u32(elf + 0x1010, 0xe1a00000u);
    put_u32(elf + 0x1014, 0xe92d4010u);
    put_u32(elf + 0x1018, arm_bl(0x1018, 0x1028));
    put_u32(elf + 0x101c, 0xe8bd8010u);
    put_u32(elf + 0x1020, 0xe1a00000u);
    put_u32(elf + 0x1024, 0xe1a00000u);
    put_u32(elf + 0x1028, 0xe92d4010u);
    put_u32(elf + 0x102c, arm_bl(0x102c, 0x1038));
    put_u32(elf + 0x1030, 0xe8bd8010u);
    put_u32(elf + 0x1034, 0xe1a00000u);
    put_u32(elf + 0x1038, 0xef000000u);
    put_u32(elf + 0x103c, 0xe12fff1eu);
    emit_min_dynamic(elf, 0x1800, 0x1900, 0x1940, 0x1a00, strtab, sizeof(strtab), 5, names, values, 4, 0, 0);
    emit_exidx(elf, 0x1c00, fn, insn, 4);
    emit_headers(elf, 0x1800, 8 * sizeof(Elf32_Dyn), 0x1c00, 32);
}

static void emit_thumb_chain(uint8_t *elf) {
    const char strtab[] = "\0A\0B\0C\0probe";
    const uint32_t names[] = {1, 3, 5, 7};
    const uint32_t values[] = {0x1001, 0x100d, 0x1019, 0x1025};
    uint32_t fn[] = {0x1000, 0x100c, 0x1018, 0x1024};
    uint32_t insn[] = {COMPACT_POP_R4_LR, COMPACT_POP_R4_LR, COMPACT_POP_R4_LR, EXIDX_CANTUNWIND};
    uint32_t bl;
    memset(elf, 0, ELF_SIZE);
    put_u16(elf + 0x1000, 0xb510);
    bl = thumb_bl(0x1002, 0x100c);
    put_u16(elf + 0x1002, (uint16_t)bl);
    put_u16(elf + 0x1004, (uint16_t)(bl >> 16));
    put_u16(elf + 0x1006, 0xbd10);
    put_u16(elf + 0x1008, 0x46c0);
    put_u16(elf + 0x100a, 0x46c0);
    put_u16(elf + 0x100c, 0xb510);
    bl = thumb_bl(0x100e, 0x1018);
    put_u16(elf + 0x100e, (uint16_t)bl);
    put_u16(elf + 0x1010, (uint16_t)(bl >> 16));
    put_u16(elf + 0x1012, 0xbd10);
    put_u16(elf + 0x1014, 0x46c0);
    put_u16(elf + 0x1016, 0x46c0);
    put_u16(elf + 0x1018, 0xb510);
    bl = thumb_bl(0x101a, 0x1024);
    put_u16(elf + 0x101a, (uint16_t)bl);
    put_u16(elf + 0x101c, (uint16_t)(bl >> 16));
    put_u16(elf + 0x101e, 0xbd10);
    put_u16(elf + 0x1020, 0x46c0);
    put_u16(elf + 0x1022, 0x46c0);
    put_u16(elf + 0x1024, 0xdf00);
    put_u16(elf + 0x1026, 0x4770);
    emit_min_dynamic(elf, 0x1800, 0x1900, 0x1940, 0x1a00, strtab, sizeof(strtab), 5, names, values, 4, 0, 0);
    emit_exidx(elf, 0x1c00, fn, insn, 4);
    emit_headers(elf, 0x1800, 8 * sizeof(Elf32_Dyn), 0x1c00, 32);
}

static void emit_leaf(uint8_t *elf, uint32_t unwind_word, int thumb) {
    const char strtab[] = "\0leaf";
    const uint32_t names[] = {1};
    const uint32_t values[] = {thumb ? 0x1001u : 0x1000u};
    uint32_t fn[] = {0x1000};
    uint32_t insn[] = {unwind_word};
    memset(elf, 0, ELF_SIZE);
    if (thumb) {
        put_u16(elf + 0x1000, 0x4770);
    } else {
        put_u32(elf + 0x1000, 0xe12fff1eu);
    }
    emit_min_dynamic(elf, 0x1800, 0x1900, 0x1940, 0x1a00, strtab, sizeof(strtab), 2, names, values, 1, 0, 0);
    emit_exidx(elf, 0x1c00, fn, insn, 1);
    emit_headers(elf, 0x1800, 8 * sizeof(Elf32_Dyn), 0x1c00, 8);
}

static void emit_arm_callee(uint8_t *elf, const char *self_sym, const char *needed_so,
                            const char *import_sym, int terminal_probe) {
    char strtab[64];
    uint32_t self_off = 1, needed_off = 0, import_off = 0, str_size, dyn_off = 0;
    uint32_t fn[2], insn[2];
    uint32_t code = 0x1000;
    memset(elf, 0, ELF_SIZE);
    strtab[0] = 0;
    memcpy(strtab + self_off, self_sym, strlen(self_sym) + 1);
    str_size = self_off + (uint32_t)strlen(self_sym) + 1;
    if (needed_so) {
        needed_off = str_size;
        memcpy(strtab + needed_off, needed_so, strlen(needed_so) + 1);
        str_size += (uint32_t)strlen(needed_so) + 1;
    }
    if (import_sym) {
        import_off = str_size;
        memcpy(strtab + import_off, import_sym, strlen(import_sym) + 1);
        str_size += (uint32_t)strlen(import_sym) + 1;
    }
    memcpy(elf + 0x1900, strtab, str_size);
    memset(elf + 0x1940, 0, sizeof(Elf32_Sym));
    write_sym(elf, 0x1940 + sizeof(Elf32_Sym), self_off, code);
    put_u32(elf + code, 0xe92d4010u);
    if (terminal_probe) {
        put_u32(elf + code + 4, arm_bl(code + 4, code + 16));
        put_u32(elf + code + 8, 0xe8bd8010u);
        put_u32(elf + code + 12, 0xe1a00000u);
        put_u32(elf + code + 16, 0xef000000u);
        put_u32(elf + code + 20, 0xe12fff1eu);
        fn[0] = code;
        fn[1] = code + 16;
        insn[0] = COMPACT_POP_R4_LR;
        insn[1] = EXIDX_CANTUNWIND;
        put_u32(elf + 0x1a00, 1);
        put_u32(elf + 0x1a00 + 4, 2);
        put_u32(elf + 0x1a00 + 8, 1);
        put_u32(elf + 0x1a00 + 8 + 4 + 4, 0);
        write_dyn(elf, 0x1800, &dyn_off, DT_HASH, 0x1a00);
        write_dyn(elf, 0x1800, &dyn_off, DT_STRTAB, 0x1900);
        write_dyn(elf, 0x1800, &dyn_off, DT_SYMTAB, 0x1940);
        write_dyn(elf, 0x1800, &dyn_off, DT_NULL, 0);
        emit_exidx(elf, 0x1c00, fn, insn, 2);
        emit_headers(elf, 0x1800, dyn_off, 0x1c00, 16);
        return;
    }
    {
        Elf32_Sym import;
        Elf32_Rel rel;
        memset(&import, 0, sizeof(import));
        import.st_name = import_off;
        import.st_info = (STB_GLOBAL << 4) | STT_FUNC;
        memcpy(elf + 0x1940 + 2 * sizeof(Elf32_Sym), &import, sizeof(import));
        put_u32(elf + code + 4, 0xe59f3004u);
        put_u32(elf + code + 8, 0xe12fff33u);
        put_u32(elf + code + 12, 0xe8bd8010u);
        put_u32(elf + code + 16, 0);
        rel.r_offset = code + 16;
        rel.r_info = (2u << 8) | R_ARM_ABS32;
        memcpy(elf + 0x1b00, &rel, sizeof(rel));
        put_u32(elf + 0x1a00, 1);
        put_u32(elf + 0x1a00 + 4, 3);
        put_u32(elf + 0x1a00 + 8, 1);
        put_u32(elf + 0x1a00 + 8 + 4 + 4, 2);
        put_u32(elf + 0x1a00 + 8 + 4 + 8, 0);
        write_dyn(elf, 0x1800, &dyn_off, DT_HASH, 0x1a00);
        write_dyn(elf, 0x1800, &dyn_off, DT_STRTAB, 0x1900);
        write_dyn(elf, 0x1800, &dyn_off, DT_SYMTAB, 0x1940);
        write_dyn(elf, 0x1800, &dyn_off, DT_REL, 0x1b00);
        write_dyn(elf, 0x1800, &dyn_off, DT_RELSZ, sizeof(Elf32_Rel));
        write_dyn(elf, 0x1800, &dyn_off, DT_RELENT, sizeof(Elf32_Rel));
        write_dyn(elf, 0x1800, &dyn_off, DT_NEEDED, needed_off);
        write_dyn(elf, 0x1800, &dyn_off, DT_NULL, 0);
        fn[0] = code;
        insn[0] = COMPACT_POP_R4_LR;
        emit_exidx(elf, 0x1c00, fn, insn, 1);
        emit_headers(elf, 0x1800, dyn_off, 0x1c00, 8);
    }
}

static agr_runtime *make_runtime(harness *h) {
    agr_callbacks cb = {0};
    cb.user = h;
    cb.read = mem_read;
    cb.write = mem_write;
    cb.loader_write = mem_load;
    cb.protect = mem_protect;
    cb.resolve_import = host_import;
    cb.memory_base = memory_base;
    return agr_runtime_create(&cb, 0x00100000, 0x00200000, 0x00200000, 0x00800000);
}

static int run_to_probe(harness *h, uint32_t target, int thumb) {
    uint64_t budget = 100000;
    uint32_t svc = 0;
    CHECK(!arm_interp_set_page_permissions(h->cpu, STACK_TOP - STACK_SIZE, STACK_SIZE, 3));
    CHECK(!arm_interp_set_cpsr(h->cpu, thumb ? 0x20u : 0u));
    CHECK(!arm_interp_set_reg(h->cpu, 13, STACK_TOP));
    CHECK(!arm_interp_set_reg(h->cpu, 14, 0));
    CHECK(!arm_interp_set_reg(h->cpu, 15, target & ~1u));
    CHECK(arm_interp_run(h->cpu, &budget, &svc) == 1);
    return 0;
}

static int capture(agr_runtime *rt, harness *h, agr_guest_unwind_frame *frames,
                   uint32_t *count, agr_ehabi_stop *stop) {
    agr_guest_unwind_context ctx;
    uint32_t regs[16];
    uint32_t i;
    agr_ehabi_env env;
    for (i = 0; i < 16; i++) regs[i] = arm_interp_get_reg(h->cpu, i);
    agr_ehabi_context_init(&ctx, NULL, regs, arm_interp_get_cpsr(h->cpu),
                           STACK_TOP - STACK_SIZE, STACK_SIZE);
    agr_ehabi_env_from_runtime(&env, rt);
    agr_ehabi_backtrace(&ctx, &env, frames, 8, count);
    *stop = ctx.stop;
    return 0;
}

static int test_arm_frames(void) {
    uint8_t elf[ELF_SIZE];
    harness h;
    agr_runtime *rt;
    agr_guest_unwind_frame frames[8];
    uint32_t count = 0, a;
    agr_ehabi_stop stop = AGR_EHABI_FAILURE;
    emit_arm_chain(elf);
    h.cpu = arm_interp_create();
    CHECK(h.cpu);
    rt = make_runtime(&h);
    CHECK(rt);
    CHECK(!agr_load_elf(rt, "libagr_unwind.so", elf, ELF_SIZE, 0x02000000, NULL));
    a = agr_find_symbol(rt, "A");
    CHECK(a == 0x02001000);
    CHECK(!run_to_probe(&h, a, 0));
    CHECK(!capture(rt, &h, frames, &count, &stop));
    CHECK(count == 3);
    CHECK(!strcmp(frames[0].dso, "libagr_unwind.so"));
    CHECK(!strcmp(frames[1].dso, "libagr_unwind.so"));
    CHECK(!strcmp(frames[2].dso, "libagr_unwind.so"));
    CHECK(frames[0].thumb == 0 && frames[1].thumb == 0 && frames[2].thumb == 0);
    CHECK(frames[0].relative_pc >= 0x1028 && frames[0].relative_pc < 0x1038);
    CHECK(frames[1].relative_pc >= 0x1014 && frames[1].relative_pc < 0x1028);
    CHECK(frames[2].relative_pc >= 0x1000 && frames[2].relative_pc < 0x1014);
    CHECK(frames[0].sp < frames[1].sp && frames[1].sp < frames[2].sp);
    CHECK(stop == AGR_EHABI_INVALID_PC);
    agr_runtime_destroy(rt);
    arm_interp_destroy(h.cpu);
    return 0;
}

static int test_thumb_frames(void) {
    uint8_t elf[ELF_SIZE];
    harness h;
    agr_runtime *rt;
    agr_guest_unwind_frame frames[8];
    uint32_t count = 0, a;
    agr_ehabi_stop stop = AGR_EHABI_FAILURE;
    emit_thumb_chain(elf);
    h.cpu = arm_interp_create();
    CHECK(h.cpu);
    rt = make_runtime(&h);
    CHECK(rt);
    CHECK(!agr_load_elf(rt, "libagr_unwind.so", elf, ELF_SIZE, 0x03000000, NULL));
    a = agr_find_symbol(rt, "A");
    CHECK(a == 0x03001001);
    CHECK(!run_to_probe(&h, a, 1));
    CHECK(!capture(rt, &h, frames, &count, &stop));
    CHECK(count == 3);
    CHECK(frames[0].thumb == 1 && frames[1].thumb == 1 && frames[2].thumb == 1);
    CHECK(frames[0].relative_pc >= 0x1018 && frames[0].relative_pc < 0x1024);
    CHECK(frames[1].relative_pc >= 0x100c && frames[1].relative_pc < 0x1018);
    CHECK(frames[2].relative_pc >= 0x1000 && frames[2].relative_pc < 0x100c);
    CHECK(frames[0].sp < frames[1].sp && frames[1].sp < frames[2].sp);
    agr_runtime_destroy(rt);
    arm_interp_destroy(h.cpu);
    return 0;
}

static int test_lifecycle_and_errors(void) {
    uint8_t elf[ELF_SIZE], bad[ELF_SIZE], cant[ELF_SIZE];
    harness h;
    agr_runtime *rt;
    agr_module_info module;
    uint32_t count = 0, handle, exidx_count = 0;
    agr_guest_unwind_frame frames[4];
    agr_guest_unwind_context ctx;
    uint32_t regs[16];
    agr_ehabi_env env;
    emit_arm_chain(elf);
    emit_leaf(cant, EXIDX_CANTUNWIND, 0);
    emit_leaf(bad, 0x8f000000u, 0);
    h.cpu = arm_interp_create();
    CHECK(h.cpu);
    rt = make_runtime(&h);
    CHECK(rt);
    CHECK(!agr_load_elf(rt, "libagr_unwind.so", elf, ELF_SIZE, 0x04000000, NULL));
    CHECK(!agr_find_module(rt, 0x04001004, &module));
    CHECK(module.exidx && module.exidx_count == 4);
    CHECK(agr_find_exidx(rt, 0x04001004, &exidx_count) == module.exidx);
    handle = agr_dlopen(rt, "libagr_unwind.so");
    CHECK(handle);
    CHECK(!agr_dlclose(rt, handle));
    CHECK(agr_find_module(rt, 0x04001004, &module) == 0);
    CHECK(!agr_dlclose(rt, handle));
    CHECK(agr_find_module(rt, 0x04001004, &module) != 0);
    CHECK(agr_find_exidx(rt, 0x04001004, &exidx_count) == 0);
    CHECK(!agr_load_elf(rt, "libagr_unwind.so", elf, ELF_SIZE, 0x04000000, NULL));
    CHECK(!agr_find_module(rt, 0x04001004, &module));

    memset(regs, 0, sizeof(regs));
    agr_ehabi_env_from_runtime(&env, rt);
    agr_ehabi_context_init(&ctx, NULL, regs, 0, STACK_TOP - STACK_SIZE, STACK_SIZE);
    CHECK(agr_ehabi_backtrace(&ctx, &env, frames, 4, &count) != 0);
    CHECK(ctx.stop == AGR_EHABI_INVALID_PC);

    regs[14] = 0x11111110;
    regs[15] = 0x11111110;
    agr_ehabi_context_init(&ctx, NULL, regs, 0, STACK_TOP - STACK_SIZE, STACK_SIZE);
    CHECK(agr_ehabi_backtrace(&ctx, &env, frames, 4, &count) != 0);
    CHECK(ctx.stop == AGR_EHABI_NO_MODULE);

    CHECK(!agr_load_elf(rt, "libcant.so", cant, ELF_SIZE, 0x05000000, NULL));
    regs[14] = 0x05001004;
    regs[15] = 0x05001004;
    agr_ehabi_context_init(&ctx, NULL, regs, 0, STACK_TOP - STACK_SIZE, STACK_SIZE);
    agr_ehabi_backtrace(&ctx, &env, frames, 4, &count);
    CHECK(count == 0);
    CHECK(ctx.stop == AGR_EHABI_CANTUNWIND);

    CHECK(!agr_load_elf(rt, "libbad.so", bad, ELF_SIZE, 0x06000000, NULL));
    regs[14] = 0x06001004;
    regs[15] = 0x06001004;
    agr_ehabi_context_init(&ctx, NULL, regs, 0, STACK_TOP - STACK_SIZE, STACK_SIZE);
    agr_ehabi_backtrace(&ctx, &env, frames, 4, &count);
    CHECK(count == 0);
    CHECK(ctx.stop == AGR_EHABI_UNSUPPORTED_ENCODING);

    {
        uint8_t iwmmxt[ELF_SIZE], vfp[ELF_SIZE];
        uint32_t stack[4];
        uint32_t stack_addr = STACK_TOP - 64;
        emit_leaf(iwmmxt, COMPACT_IWMMXT_WR10, 0);
        CHECK(!agr_load_elf(rt, "libiwmmxt.so", iwmmxt, ELF_SIZE, 0x07000000, NULL));
        memset(regs, 0, sizeof(regs));
        regs[13] = stack_addr;
        regs[14] = 0x07001004;
        regs[15] = 0x07001004;
        agr_ehabi_context_init(&ctx, NULL, regs, 0, STACK_TOP - STACK_SIZE, STACK_SIZE);
        agr_ehabi_context_begin_backtrace(&ctx);
        CHECK(agr_ehabi_unwind_step(&ctx, &env) != 0);
        CHECK(ctx.stop == AGR_EHABI_UNSUPPORTED_ENCODING);

        emit_leaf(vfp, COMPACT_VFPX_D8, 0);
        CHECK(!agr_load_elf(rt, "libvfp.so", vfp, ELF_SIZE, 0x08000000, NULL));
        CHECK(!arm_interp_set_page_permissions(h.cpu, STACK_TOP - STACK_SIZE, STACK_SIZE, 3));
        stack[0] = 0x11111111u;
        stack[1] = 0x22222222u;
        stack[2] = 0xdeadbeefu;
        stack[3] = 0;
        CHECK(!arm_interp_load(h.cpu, stack_addr, (const uint8_t *)stack, sizeof(stack)));
        memset(regs, 0, sizeof(regs));
        regs[13] = stack_addr;
        regs[14] = 0x08001004;
        regs[15] = 0x08001004;
        agr_ehabi_context_init(&ctx, NULL, regs, 0, STACK_TOP - STACK_SIZE, STACK_SIZE);
        agr_ehabi_context_begin_backtrace(&ctx);
        CHECK(!agr_ehabi_unwind_step(&ctx, &env));
        CHECK(ctx.vfp_d[8] == (((uint64_t)0x22222222u << 32) | 0x11111111u));
        CHECK(ctx.r[13] == stack_addr + 12);
    }

    agr_runtime_destroy(rt);
    arm_interp_destroy(h.cpu);
    return 0;
}

static int test_multi_dso(void) {
    uint8_t aelf[ELF_SIZE], belf[ELF_SIZE], celf[ELF_SIZE];
    harness h;
    agr_runtime *rt;
    agr_guest_unwind_frame frames[8];
    uint32_t count = 0, entry;
    agr_ehabi_stop stop = AGR_EHABI_FAILURE;
    emit_arm_callee(celf, "C", NULL, NULL, 1);
    emit_arm_callee(belf, "B", "libC.so", "C", 0);
    emit_arm_callee(aelf, "A", "libB.so", "B", 0);
    h.cpu = arm_interp_create();
    CHECK(h.cpu);
    rt = make_runtime(&h);
    CHECK(rt);
    CHECK(!agr_register_elf_source(rt, "libC.so", celf, ELF_SIZE, 0x02000000));
    CHECK(!agr_register_elf_source(rt, "libB.so", belf, ELF_SIZE, 0x03000000));
    CHECK(!agr_register_elf_source(rt, "libA.so", aelf, ELF_SIZE, 0x04000000));
    CHECK(agr_dlopen(rt, "libA.so"));
    entry = agr_find_symbol(rt, "A");
    CHECK(entry);
    CHECK(!run_to_probe(&h, entry, 0));
    CHECK(!capture(rt, &h, frames, &count, &stop));
    CHECK(count == 3);
    CHECK(!strcmp(frames[0].dso, "libC.so"));
    CHECK(!strcmp(frames[1].dso, "libB.so"));
    CHECK(!strcmp(frames[2].dso, "libA.so"));
    CHECK(frames[0].sp < frames[1].sp && frames[1].sp < frames[2].sp);
    agr_runtime_destroy(rt);
    arm_interp_destroy(h.cpu);
    return 0;
}

int main(void) {
    CHECK(!test_arm_frames());
    CHECK(!test_thumb_frames());
    CHECK(!test_lifecycle_and_errors());
    CHECK(!test_multi_dso());
    puts("PASS ARM EHABI Phase 1 unwind foundation");
    return 0;
}
