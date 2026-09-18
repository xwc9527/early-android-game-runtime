#include "../../Runtime/NativeCore/agr_runtime.h"
#include "../../Runtime/Ehabi/agr_ehabi.h"
#include "../../Runtime/NativeCore/agr_elf32.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { STACK_TOP = 0x000fc000, STACK_SIZE = 0x10000 };
extern void *arm_interp_create(void);
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
static void put_u32(uint8_t *p, uint32_t v) { memcpy(p, &v, 4); }
static void emit_probe_stub(uint8_t *elf, uint32_t size) {
    Elf32_Ehdr eh;
    Elf32_Phdr ph[3];
    Elf32_Dyn dyn[6];
    Elf32_Sym sym[2];
    const char strtab[] = "\0agr_unwind_probe";
    uint32_t hash[6] = {1, 2, 1, 0, 0, 0};
    uint32_t fn = 0x1000, exidx = 0x1c00;
    memset(elf, 0, size);
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
    eh.e_phnum = 3;
    memcpy(elf, &eh, sizeof(eh));
    memset(ph, 0, sizeof(ph));
    ph[0].p_type = PT_LOAD; ph[0].p_filesz = ph[0].p_memsz = size; ph[0].p_flags = 5; ph[0].p_align = 0x1000;
    ph[1].p_type = PT_DYNAMIC; ph[1].p_offset = ph[1].p_vaddr = 0x1800; ph[1].p_filesz = ph[1].p_memsz = sizeof(dyn); ph[1].p_flags = 4; ph[1].p_align = 4;
    ph[2].p_type = PT_ARM_EXIDX; ph[2].p_offset = ph[2].p_vaddr = exidx; ph[2].p_filesz = ph[2].p_memsz = 8; ph[2].p_flags = 4; ph[2].p_align = 4;
    memcpy(elf + sizeof(eh), ph, sizeof(ph));
    put_u32(elf + fn, 0xef000000u);
    put_u32(elf + fn + 4, 0xe12fff1eu);
    memset(sym, 0, sizeof(sym));
    sym[1].st_name = 1;
    sym[1].st_value = fn;
    sym[1].st_info = (STB_GLOBAL << 4) | STT_FUNC;
    sym[1].st_shndx = 1;
    memcpy(elf + 0x1940, sym, sizeof(sym));
    memcpy(elf + 0x1900, strtab, sizeof(strtab));
    memcpy(elf + 0x1a00, hash, sizeof(hash));
    memset(dyn, 0, sizeof(dyn));
    dyn[0].d_tag = DT_HASH; dyn[0].d_un.d_ptr = 0x1a00;
    dyn[1].d_tag = DT_STRTAB; dyn[1].d_un.d_ptr = 0x1900;
    dyn[2].d_tag = DT_SYMTAB; dyn[2].d_un.d_ptr = 0x1940;
    dyn[3].d_tag = DT_NULL;
    memcpy(elf + 0x1800, dyn, sizeof(dyn));
    put_u32(elf + exidx, (fn - exidx) & 0x7fffffffu);
    put_u32(elf + exidx + 4, 1);
}

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
    harness *h = (harness *)o;
    uint32_t address = 0x0700f000u, insn = 0xef000000u;
    (void)t;
    if (strcmp(n, "agr_unwind_probe")) return 0;
    if (arm_interp_load(h->cpu, address, (const uint8_t *)&insn, 4) ||
        arm_interp_set_page_permissions(h->cpu, address & ~0xfffu, 0x1000, 5))
        return 0;
    return address;
}
static void *read_file(const char *path, uint32_t *size) {
    FILE *f = fopen(path, "rb");
    long n;
    void *p;
    if (!f) return NULL;
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    p = malloc((size_t)n);
    if (!p || fread(p, 1, (size_t)n, f) != (size_t)n) { free(p); p = NULL; n = 0; }
    fclose(f);
    *size = (uint32_t)n;
    return p;
}
static int reg(agr_runtime *r, const char *name, const char *path, uint32_t base) {
    uint32_t n = 0;
    void *p = read_file(path, &n);
    int rc = p ? agr_register_elf_source(r, name, p, n, base) : -1;
    free(p);
    return rc;
}

int main(int argc, char **argv) {
    harness h;
    agr_callbacks cb = {0};
    agr_runtime *rt;
    agr_guest_unwind_context ctx;
    agr_guest_unwind_frame frames[8];
    agr_ehabi_env env;
    uint8_t probe[0x4000];
    uint32_t regs[16], count = 0, i, entry, handle, a_pc;
    agr_module_info module;
    if (argc != 4) {
        fprintf(stderr, "usage: %s libagr_unwind_C.so libagr_unwind_B.so libagr_unwind_A.so\n", argv[0]);
        return 2;
    }
    h.cpu = arm_interp_create();
    if (!h.cpu) return 3;
    cb.user = &h;
    cb.read = mem_read;
    cb.write = mem_write;
    cb.loader_write = mem_load;
    cb.protect = mem_protect;
    cb.resolve_import = host_import;
    rt = agr_runtime_create(&cb, 0x00100000, 0x00200000, 0x00200000, 0x00800000);
    if (!rt) return 4;
    emit_probe_stub(probe, sizeof(probe));
    if (agr_register_elf_source(rt, "libagr_unwind_probe.so", probe, sizeof(probe), 0x01000000) ||
        reg(rt, "libagr_unwind_C.so", argv[1], 0x02000000) ||
        reg(rt, "libagr_unwind_B.so", argv[2], 0x03000000) ||
        reg(rt, "libagr_unwind_A.so", argv[3], 0x04000000))
        return 5;
    handle = agr_dlopen(rt, "libagr_unwind_A.so");
    if (!handle) { fprintf(stderr, "dlopen A: %s\n", agr_dlerror(rt)); return 6; }
    entry = agr_dlsym(rt, handle, "A");
    a_pc = entry;
    if (!entry) return 7;
    if (arm_interp_set_page_permissions(h.cpu, STACK_TOP - STACK_SIZE, STACK_SIZE, 3)) return 8;
    arm_interp_set_cpsr(h.cpu, entry & 1u ? 0x20u : 0u);
    arm_interp_set_reg(h.cpu, 13, STACK_TOP);
    arm_interp_set_reg(h.cpu, 14, 0x00001000u);
    arm_interp_set_reg(h.cpu, 15, entry & ~1u);
    {
        uint64_t budget = 1000000;
        uint32_t svc = 0;
        if (arm_interp_run(h.cpu, &budget, &svc) != 1) {
            fprintf(stderr, "probe svc not reached pc=%08x cpsr=%08x\n",
                    arm_interp_get_reg(h.cpu, 15), arm_interp_get_cpsr(h.cpu));
            return 9;
        }
    }
    for (i = 0; i < 16; i++) regs[i] = arm_interp_get_reg(h.cpu, i);
    agr_ehabi_context_init(&ctx, NULL, regs, arm_interp_get_cpsr(h.cpu),
                           STACK_TOP - STACK_SIZE, STACK_SIZE);
    agr_ehabi_env_from_runtime(&env, rt);
    agr_ehabi_backtrace(&ctx, &env, frames, 8, &count);
    printf("{\"frames\":[");
    for (i = 0; i < count; i++) {
        printf("%s{\"dso\":\"%s\",\"relative_pc\":%u,\"sp_delta\":%u,\"thumb\":%s}",
               i ? "," : "", frames[i].dso, frames[i].relative_pc,
               frames[i].sp - frames[0].sp, frames[i].thumb ? "true" : "false");
    }
    printf("],\"stop\":\"no_module\"}\n");
    if (count != 3) {
        fprintf(stderr, "expected C,B,A got %u stop=%s\n", count, agr_ehabi_stop_name(ctx.stop));
        return 10;
    }
    if (agr_dlclose(rt, handle)) return 12;
    if (agr_find_module(rt, a_pc, &module) == 0) {
        fprintf(stderr, "stale exidx after dlclose\n");
        return 13;
    }
    handle = agr_dlopen(rt, "libagr_unwind_A.so");
    if (!handle || agr_find_module(rt, agr_dlsym(rt, handle, "A"), &module) != 0) return 14;
    agr_dlclose(rt, handle);
    agr_runtime_destroy(rt);
    arm_interp_destroy(h.cpu);
    return 0;
}
