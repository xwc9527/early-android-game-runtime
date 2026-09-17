#include "agr_runtime.h"
#include "../AospLinker/agr_aosp_linker.h"

#include <ctype.h>
#include "agr_elf32.h"
#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef PT_ARM_EXIDX
#define PT_ARM_EXIDX 0x70000001
#endif

#define AGR_MAX_OBJECTS 64
#define AGR_MAX_SYMBOLS 16384
#define AGR_MAX_NEEDED 1024
#define AGR_MAX_RELOCS 131072
#define AGR_MAX_CTORS 8192
#define AGR_MAX_THREADS 128
#define AGR_MAX_TLS_KEYS 256
#define AGR_MAX_MUTEXES 2048
#define AGR_MAX_ONCE 2048
#define AGR_MAX_GUARDS 2048
#define AGR_MAX_ATEXIT 4096
#define AGR_SELF_HANDLE 0xfffffffeu

typedef struct { char *name; uint32_t address; uint32_t object_index; } agr_symbol;
typedef struct { char *name; uint32_t base, min_address, max_address, exidx, exidx_count, refs; agr_aosp_linker_image image; } agr_object;
typedef struct { uint32_t type, address, object_index; char *symbol, *object_name; } agr_reloc;
typedef struct agr_heap_block {
    uint32_t address, span, requested, alignment;
    uint8_t live;
    struct agr_heap_block *prev, *next;
} agr_heap_block;
typedef struct { uint32_t id, errno_address; uint32_t tls[AGR_MAX_TLS_KEYS]; } agr_thread;
typedef struct { uint32_t address, owner, depth, live; } agr_mutex;
typedef struct { uint32_t address, state; } agr_word_state;
typedef struct { uint32_t function, argument, dso; } agr_atexit;

struct agr_runtime {
    agr_callbacks cb;
    char error[512];
    char dlerror[512];
    char library_path[1024];
    uint32_t static_ptr, static_limit, heap_base, heap_limit;
    agr_heap_block *heap_blocks;
    agr_object objects[AGR_MAX_OBJECTS]; uint32_t object_count;
    agr_symbol symbols[AGR_MAX_SYMBOLS]; uint32_t symbol_count;
    char *needed[AGR_MAX_NEEDED]; uint32_t needed_count;
    uint32_t needed_owner[AGR_MAX_NEEDED];
    agr_reloc relocs[AGR_MAX_RELOCS]; uint32_t reloc_count;
    uint32_t constructors[AGR_MAX_CTORS]; uint32_t constructor_count;
    uint32_t constructor_owner[AGR_MAX_CTORS];
    agr_thread threads[AGR_MAX_THREADS]; uint32_t thread_count, current_thread, next_thread;
    uint32_t tls_destructors[AGR_MAX_TLS_KEYS], next_tls_key;
    agr_mutex mutexes[AGR_MAX_MUTEXES]; uint32_t mutex_count;
    agr_word_state once[AGR_MAX_ONCE]; uint32_t once_count;
    agr_word_state guards[AGR_MAX_GUARDS]; uint32_t guard_count;
    agr_atexit atexit[AGR_MAX_ATEXIT]; uint32_t atexit_count;
    uint64_t clock_ns;
    agr_guest_vma_space linker_vma;
    agr_bionic_mmap_context linker_mmap;
};

static char *agr_strdup(const char *s) {
    size_t n = strlen(s) + 1; char *copy = (char *)malloc(n);
    if (copy) memcpy(copy, s, n); return copy;
}
static int fail(agr_runtime *rt, const char *message) {
    snprintf(rt->error, sizeof(rt->error), "%s", message); return -1;
}
static int read_mem(agr_runtime *rt, uint32_t address, void *data, uint32_t size) {
    return rt->cb.read && rt->cb.read(rt->cb.user, address, data, size) == 0;
}
static int write_mem(agr_runtime *rt, uint32_t address, const void *data, uint32_t size) {
    return rt->cb.write && rt->cb.write(rt->cb.user, address, data, size) == 0;
}
static int loader_write_mem(agr_runtime *rt, uint32_t address, const void *data, uint32_t size) {
    agr_write_fn write = rt->cb.loader_write ? rt->cb.loader_write : rt->cb.write;
    return write && write(rt->cb.user, address, data, size) == 0;
}
static int32_t linker_write(void *opaque, uint32_t address, const void *data, uint32_t size) {
    return loader_write_mem((agr_runtime *)opaque, address, data, size) ? 0 : EFAULT;
}
static int32_t linker_protect(void *opaque, uint32_t address, uint32_t size, uint32_t protection) {
    agr_runtime *rt = (agr_runtime *)opaque;
    return rt->cb.protect ? rt->cb.protect(rt->cb.user, address, size, protection) : 0;
}
static uint32_t align_up(uint32_t value, uint32_t alignment) {
    if (!alignment) alignment = 1; return (value + alignment - 1) & ~(alignment - 1);
}
static void write_u32(agr_runtime *rt, uint32_t address, uint32_t value) { write_mem(rt, address, &value, 4); }
static int write_loader_u32(agr_runtime *rt, uint32_t address, uint32_t value) { return loader_write_mem(rt, address, &value, 4); }
static uint32_t read_u32(agr_runtime *rt, uint32_t address) { uint32_t v = 0; read_mem(rt, address, &v, 4); return v; }
static int read_cstr(agr_runtime *rt, uint32_t address, char *out, uint32_t capacity) {
    uint32_t i; if (!address || !capacity) return 0;
    for (i = 0; i + 1 < capacity; ++i) { if (!read_mem(rt, address + i, out + i, 1)) return 0; if (!out[i]) return 1; }
    out[capacity - 1] = 0; return 1;
}

agr_runtime *agr_runtime_create(const agr_callbacks *cb, uint32_t sb, uint32_t sl, uint32_t hb, uint32_t hl) {
    if (!cb || !cb->read || !cb->write || !hb || hb >= hl) return NULL;
    agr_runtime *rt = (agr_runtime *)calloc(1, sizeof(*rt)); if (!rt) return NULL;
    rt->heap_blocks = (agr_heap_block *)calloc(1, sizeof(*rt->heap_blocks));
    if (!rt->heap_blocks) { free(rt); return NULL; }
    rt->heap_blocks->address = hb; rt->heap_blocks->span = hl - hb;
    rt->cb = *cb; rt->static_ptr = sb; rt->static_limit = sl; rt->heap_base = hb; rt->heap_limit = hl;
    if (agr_guest_vma_init(&rt->linker_vma, 4096, 0x10000u, 0x100000000ull)) {
        free(rt->heap_blocks); free(rt); return NULL;
    }
    rt->linker_mmap = (agr_bionic_mmap_context){&rt->linker_vma, rt, linker_write, NULL, linker_protect};
    rt->thread_count = 1; rt->threads[0].id = 1; rt->current_thread = 1; rt->next_thread = 2;
    rt->next_tls_key = 1; rt->clock_ns = 1000000000ULL; return rt;
}
void agr_runtime_destroy(agr_runtime *rt) {
    uint32_t i; if (!rt) return;
    for (agr_heap_block *block=rt->heap_blocks,*next; block; block=next) { next=block->next; free(block); }
    for (i=0;i<rt->object_count;i++) {
        if (rt->objects[i].image.load_size) agr_aosp_linker_unload(&rt->linker_mmap,&rt->objects[i].image,NULL);
        free(rt->objects[i].name);
    }
    for (i=0;i<rt->symbol_count;i++) free(rt->symbols[i].name);
    for (i=0;i<rt->needed_count;i++) free(rt->needed[i]);
    for (i=0;i<rt->reloc_count;i++){free(rt->relocs[i].symbol);free(rt->relocs[i].object_name);}
    agr_guest_vma_destroy(&rt->linker_vma); free(rt);
}
const char *agr_last_error(agr_runtime *rt) { return rt ? rt->error : "runtime is null"; }

uint32_t agr_alloc_static(agr_runtime *rt, const void *data, uint32_t size, uint32_t alignment) {
    uint32_t address = align_up(rt->static_ptr, alignment ? alignment : 8), end = address + size;
    if (end < address || end > rt->static_limit) { fail(rt, "static arena exhausted"); return 0; }
    rt->static_ptr = end; if (size && !write_mem(rt, address, data, size)) { fail(rt, "static write failed"); return 0; } return address;
}
static int heap_alignment_valid(uint32_t alignment) {
    return alignment >= 4 && (alignment & (alignment - 1)) == 0;
}
static agr_heap_block *heap_find_live(agr_runtime *rt, uint32_t address) {
    if (!rt || !address) return NULL;
    for (agr_heap_block *b=rt->heap_blocks; b; b=b->next)
        if (b->live && b->address == address) return b;
    return NULL;
}
static void heap_insert_after(agr_heap_block *at, agr_heap_block *node) {
    node->prev=at; node->next=at->next;
    if (node->next) node->next->prev=node;
    at->next=node;
}
static void heap_remove(agr_runtime *rt, agr_heap_block *node) {
    if (node->prev) node->prev->next=node->next; else rt->heap_blocks=node->next;
    if (node->next) node->next->prev=node->prev;
    free(node);
}
static agr_heap_block *heap_coalesce(agr_runtime *rt, agr_heap_block *b) {
    if (b->prev && !b->prev->live) {
        agr_heap_block *prior=b->prev;
        prior->span+=b->span; heap_remove(rt,b); b=prior;
    }
    if (b->next && !b->next->live) {
        agr_heap_block *next=b->next;
        b->span+=next->span; heap_remove(rt,next);
    }
    return b;
}
static int heap_clear(agr_runtime *rt, uint32_t address, uint32_t size) {
    static const unsigned char zeros[256] = {0};
    for (uint32_t at=address,left=size; left;) {
        uint32_t n=left>sizeof(zeros)?sizeof(zeros):left;
        if (!write_mem(rt,at,zeros,n)) return 0;
        at+=n; left-=n;
    }
    return 1;
}
uint32_t agr_malloc_aligned(agr_runtime *rt, uint32_t size, uint32_t alignment) {
    if (!rt || !heap_alignment_valid(alignment)) return 0;
    if (alignment < 8) alignment=8;
    uint32_t requested=size?size:1;
    uint64_t rounded=((uint64_t)requested+7u)&~7ull;
    if (rounded>UINT32_MAX) return 0;
    uint32_t span=(uint32_t)rounded;
    for (agr_heap_block *b=rt->heap_blocks; b; b=b->next) {
        if (b->live) continue;
        uint64_t aligned=((uint64_t)b->address+alignment-1u)&~(uint64_t)(alignment-1u);
        uint64_t end=aligned+span, block_end=(uint64_t)b->address+b->span;
        if (aligned>UINT32_MAX || end>block_end) continue;
        uint32_t prefix=(uint32_t)(aligned-b->address), suffix=(uint32_t)(block_end-end);
        agr_heap_block *allocated=prefix?(agr_heap_block *)calloc(1,sizeof(*allocated)):b;
        if (!allocated) return 0;
        agr_heap_block *tail=suffix?(agr_heap_block *)calloc(1,sizeof(*tail)):NULL;
        if (suffix && !tail) { if(prefix)free(allocated); return 0; }
        if (!heap_clear(rt,(uint32_t)aligned,span)) {
            if (prefix) free(allocated); free(tail); return 0;
        }
        if (prefix) { b->span=prefix; heap_insert_after(b,allocated); }
        allocated->address=(uint32_t)aligned; allocated->span=span;
        allocated->requested=requested; allocated->alignment=alignment; allocated->live=1;
        if (tail) { tail->address=(uint32_t)end; tail->span=suffix; heap_insert_after(allocated,tail); }
        return allocated->address;
    }
    return 0;
}
uint32_t agr_malloc(agr_runtime *rt, uint32_t size) { return agr_malloc_aligned(rt,size,8); }
uint32_t agr_calloc(agr_runtime *rt, uint32_t count, uint32_t size) {
    uint64_t total=(uint64_t)count*size;
    return total>UINT32_MAX?0:agr_malloc(rt,(uint32_t)total);
}
void agr_free(agr_runtime *rt, uint32_t address) {
    agr_heap_block *b=heap_find_live(rt,address);
    if (!b) return; /* free(NULL), invalid and repeated frees cannot corrupt the heap. */
    b->live=0; b->requested=0; b->alignment=0;
    heap_coalesce(rt,b);
}
uint32_t agr_allocation_size(agr_runtime *rt,uint32_t address) {
    agr_heap_block *b=heap_find_live(rt,address);
    return b?b->requested:0;
}
void agr_heap_diagnostics(agr_runtime *rt,uint32_t out[5]) {
    if (!out) return; memset(out,0,5*sizeof(*out)); if (!rt) return;
    out[0]=rt->heap_base; out[1]=rt->heap_limit;
    for (agr_heap_block *b=rt->heap_blocks; b; b=b->next) {
        out[2]++;
        if (b->live) { out[3]++; out[4]+=b->requested; out[0]=b->address+b->span; }
    }
}
uint32_t agr_realloc(agr_runtime *rt,uint32_t address,uint32_t size) {
    if (!address) return agr_malloc(rt,size);
    agr_heap_block *b=heap_find_live(rt,address);
    if (!b) return 0;
    if (!size) { agr_free(rt,address); return 0; }
    uint64_t rounded=((uint64_t)size+7u)&~7ull;
    if (rounded>UINT32_MAX) return 0;
    uint32_t new_span=(uint32_t)rounded, old_size=b->requested;
    if (new_span<=b->span) {
        uint32_t spare=b->span-new_span;
        if (spare>=8) {
            agr_heap_block *tail=(agr_heap_block *)calloc(1,sizeof(*tail));
            if (tail) {
                tail->address=b->address+new_span;tail->span=spare;b->span=new_span;
                heap_insert_after(b,tail);heap_coalesce(rt,tail);
            }
        }
        b->requested=size;return address;
    }
    if (b->next && !b->next->live && b->next->span>=new_span-b->span) {
        if (!heap_clear(rt,address+old_size,size-old_size)) return 0;
        agr_heap_block *next=b->next;
        uint32_t take=new_span-b->span;
        b->span=new_span;b->requested=size;
        next->address+=take;next->span-=take;
        if (!next->span) heap_remove(rt,next);
        return address;
    }
    uint32_t replacement=agr_malloc_aligned(rt,size,b->alignment);
    if (!replacement) return 0;
    unsigned char buffer[256];
    for (uint32_t at=0;at<old_size;) {
        uint32_t n=old_size-at>sizeof(buffer)?sizeof(buffer):old_size-at;
        if (!read_mem(rt,address+at,buffer,n) || !write_mem(rt,replacement+at,buffer,n)) {
            agr_free(rt,replacement);return 0;
        }
        at+=n;
    }
    agr_free(rt,address);return replacement;
}

static const void *range(const unsigned char *data,uint32_t size,uint32_t offset,uint32_t need){return offset<=size&&need<=size-offset?data+offset:NULL;}
static const void *vaddr_ptr(const unsigned char *data,uint32_t size,const Elf32_Phdr *ph,uint32_t phnum,uint32_t vaddr,uint32_t need){
    for(uint32_t i=0;i<phnum;i++)if(ph[i].p_type==PT_LOAD&&vaddr>=ph[i].p_vaddr&&vaddr-ph[i].p_vaddr<=ph[i].p_filesz&&need<=ph[i].p_filesz-(vaddr-ph[i].p_vaddr))return range(data,size,ph[i].p_offset+(vaddr-ph[i].p_vaddr),need);return NULL;
}
static uint32_t symbol_lookup(agr_runtime *rt,const char *name){for(uint32_t i=rt->symbol_count;i>0;i--)if(!strcmp(rt->symbols[i-1].name,name))return rt->symbols[i-1].address;return 0;}
uint32_t agr_find_symbol(agr_runtime *rt,const char *name){return symbol_lookup(rt,name);}

static int32_t load_elf_inner(agr_runtime *rt,const char *name,const void *bytes,uint32_t size,uint32_t base,agr_load_result *out){
    const unsigned char *data=(const unsigned char*)bytes;const Elf32_Ehdr *eh=(const Elf32_Ehdr*)range(data,size,0,sizeof(Elf32_Ehdr));
    if(!eh||memcmp(eh->e_ident,ELFMAG,SELFMAG)||eh->e_ident[EI_CLASS]!=ELFCLASS32||eh->e_machine!=EM_ARM)return fail(rt,"not an ARM32 ELF");
    const Elf32_Phdr *ph=(const Elf32_Phdr*)range(data,size,eh->e_phoff,(uint32_t)eh->e_phnum*sizeof(Elf32_Phdr));if(!ph)return fail(rt,"invalid program headers");
    uint32_t oi=0;while(oi<rt->object_count&&rt->objects[oi].name)oi++;
    if(oi==AGR_MAX_OBJECTS)return fail(rt,"object table full");uint32_t min=0xffffffffu,max=0,exidx=0,excount=0;
    agr_aosp_linker_image image={0};int32_t map_errno=0;
    if(agr_aosp_linker_map(&rt->linker_mmap,bytes,size,base,&image,&map_errno)){snprintf(rt->error,sizeof(rt->error),"AOSP linker segment mapping failed: errno %d",map_errno);return -1;}
    base=image.load_bias;
    for(uint32_t i=0;i<eh->e_phnum;i++){if(ph[i].p_type==PT_LOAD){uint32_t a=base+ph[i].p_vaddr,b=a+ph[i].p_memsz;if(a<min)min=a;if(b>max)max=b;}else if(ph[i].p_type==PT_ARM_EXIDX){exidx=base+ph[i].p_vaddr;excount=ph[i].p_memsz/8;}}
    char *object_name=agr_strdup(name);
    if(!object_name){agr_aosp_linker_unload(&rt->linker_mmap,&image,NULL);return fail(rt,"object name allocation failed");}
    rt->objects[oi]=(agr_object){object_name,base,min,max,exidx,excount,1,image};if(oi==rt->object_count)rt->object_count++;
    uint32_t strtab=0,symtab=0,hash=0,rel=0,relsz=0,jmprel=0,pltrelsz=0,init=0,initsz=0,needed_idx[128],needed_n=0;
    for(uint32_t i=0;i<eh->e_phnum;i++)if(ph[i].p_type==PT_DYNAMIC){const Elf32_Dyn *d=(const Elf32_Dyn*)range(data,size,ph[i].p_offset,ph[i].p_filesz);if(!d)return fail(rt,"invalid PT_DYNAMIC");for(uint32_t j=0;j<ph[i].p_filesz/sizeof(*d)&&d[j].d_tag!=DT_NULL;j++){uint32_t v=d[j].d_un.d_val;switch(d[j].d_tag){case DT_STRTAB:strtab=v;break;case DT_SYMTAB:symtab=v;break;case DT_HASH:hash=v;break;case DT_REL:rel=v;break;case DT_RELSZ:relsz=v;break;case DT_JMPREL:jmprel=v;break;case DT_PLTRELSZ:pltrelsz=v;break;case DT_INIT_ARRAY:init=v;break;case DT_INIT_ARRAYSZ:initsz=v;break;case DT_NEEDED:if(needed_n<128)needed_idx[needed_n++]=v;break;}}}
    const char *str=(const char*)vaddr_ptr(data,size,ph,eh->e_phnum,strtab,1);const Elf32_Sym *syms=(const Elf32_Sym*)vaddr_ptr(data,size,ph,eh->e_phnum,symtab,sizeof(Elf32_Sym));if(!str||!syms)return fail(rt,"missing dynamic string/symbol table");
    uint32_t symcount=0;if(hash){const uint32_t *h=(const uint32_t*)vaddr_ptr(data,size,ph,eh->e_phnum,hash,8);if(h)symcount=h[1];}
    if(!symcount&&eh->e_shoff){const Elf32_Shdr *sh=(const Elf32_Shdr*)range(data,size,eh->e_shoff,(uint32_t)eh->e_shnum*sizeof(Elf32_Shdr));if(sh)for(uint32_t i=0;i<eh->e_shnum;i++)if(sh[i].sh_type==SHT_DYNSYM){symcount=sh[i].sh_size/sizeof(Elf32_Sym);break;}}
    if(!symcount)return fail(rt,"cannot determine dynamic symbol count");
    uint32_t symbol_start=rt->symbol_count,needed_start=rt->needed_count,reloc_start=rt->reloc_count,ctor_start=rt->constructor_count;
    for(uint32_t i=0;i<symcount;i++)if(syms[i].st_name&&syms[i].st_shndx!=SHN_UNDEF&&(ELF32_ST_BIND(syms[i].st_info)==STB_GLOBAL||ELF32_ST_BIND(syms[i].st_info)==STB_WEAK)){if(rt->symbol_count>=AGR_MAX_SYMBOLS)return fail(rt,"symbol table full");rt->symbols[rt->symbol_count++]=(agr_symbol){agr_strdup(str+syms[i].st_name),base+syms[i].st_value,oi};}
    for(uint32_t i=0;i<needed_n;i++){if(rt->needed_count>=AGR_MAX_NEEDED)return fail(rt,"needed table full");rt->needed_owner[rt->needed_count]=oi;rt->needed[rt->needed_count++]=agr_strdup(str+needed_idx[i]);}
    uint32_t tables[2][2]={{rel,relsz},{jmprel,pltrelsz}};for(uint32_t t=0;t<2;t++){if(!tables[t][0])continue;const Elf32_Rel *rs=(const Elf32_Rel*)vaddr_ptr(data,size,ph,eh->e_phnum,tables[t][0],tables[t][1]);if(!rs)return fail(rt,"invalid relocation table");for(uint32_t i=0;i<tables[t][1]/sizeof(*rs);i++){uint32_t type=ELF32_R_TYPE(rs[i].r_info),si=ELF32_R_SYM(rs[i].r_info),where=base+rs[i].r_offset,add=read_u32(rt,where),resolved=0;const char *sn="";if(si){sn=str+syms[si].st_name;if(syms[si].st_shndx==SHN_UNDEF){resolved=symbol_lookup(rt,sn);if(!resolved&&rt->cb.resolve_import)resolved=rt->cb.resolve_import(rt->cb.user,sn,ELF32_ST_TYPE(syms[si].st_info));}else resolved=base+syms[si].st_value;}uint32_t value;if(type==R_ARM_RELATIVE)value=base+add;else if(type==R_ARM_GLOB_DAT||type==R_ARM_JUMP_SLOT)value=resolved;else if(type==R_ARM_ABS32)value=resolved+add;else if(type==R_ARM_REL32)value=resolved+add-where;else{snprintf(rt->error,sizeof(rt->error),"unsupported ARM relocation %u for %s",type,sn);return -1;}if(!write_loader_u32(rt,where,value))return fail(rt,"relocation write failed");if(rt->reloc_count>=AGR_MAX_RELOCS)return fail(rt,"relocation table full");rt->relocs[rt->reloc_count++]=(agr_reloc){type,where,oi,agr_strdup(sn),agr_strdup(name)};}}
    if(init&&initsz){const uint32_t *ctors=(const uint32_t*)vaddr_ptr(data,size,ph,eh->e_phnum,init,initsz);if(!ctors)return fail(rt,"invalid init array");for(uint32_t i=0;i<initsz/4;i++)if(ctors[i]){if(rt->constructor_count>=AGR_MAX_CTORS)return fail(rt,"constructor table full");rt->constructor_owner[rt->constructor_count]=oi;rt->constructors[rt->constructor_count++]=base+ctors[i];}}
    if(agr_aosp_linker_finalize(&rt->linker_mmap,bytes,size,&rt->objects[oi].image,&map_errno)){snprintf(rt->error,sizeof(rt->error),"AOSP linker protection/RELRO failed: errno %d",map_errno);return -1;}
    if(out)*out=(agr_load_result){base,needed_start,rt->needed_count-needed_start,reloc_start,rt->reloc_count-reloc_start,ctor_start,rt->constructor_count-ctor_start,symbol_start,rt->symbol_count-symbol_start};return 0;
}

int32_t agr_load_elf(agr_runtime *rt,const char *name,const void *bytes,uint32_t size,uint32_t base,agr_load_result *out){
    uint64_t before=0;
    for(uint32_t i=0;i<rt->object_count;i++)if(rt->objects[i].name)before|=1ull<<i;
    int32_t result=load_elf_inner(rt,name,bytes,size,base,out);
    if(result==0)return 0;
    for(uint32_t i=0;i<rt->object_count;i++)if(rt->objects[i].name&&!(before&(1ull<<i))){
        agr_dlclose(rt,rt->objects[i].base);break;
    }
    return result;
}

uint32_t agr_symbol_count(agr_runtime*rt){return rt->symbol_count;}const char*agr_symbol_name(agr_runtime*rt,uint32_t i){return i<rt->symbol_count?rt->symbols[i].name:NULL;}uint32_t agr_symbol_address(agr_runtime*rt,uint32_t i){return i<rt->symbol_count?rt->symbols[i].address:0;}
uint32_t agr_needed_count(agr_runtime*rt){return rt->needed_count;}const char*agr_needed_name(agr_runtime*rt,uint32_t i){return i<rt->needed_count?rt->needed[i]:NULL;}uint32_t agr_constructor_count(agr_runtime*rt){return rt->constructor_count;}uint32_t agr_constructor_address(agr_runtime*rt,uint32_t i){return i<rt->constructor_count?rt->constructors[i]:0;}uint32_t agr_relocation_count(agr_runtime*rt){return rt->reloc_count;}
int32_t agr_relocation(agr_runtime*rt,uint32_t i,agr_relocation_info*out){if(i>=rt->reloc_count||!out)return -1;*out=(agr_relocation_info){rt->relocs[i].type,rt->relocs[i].address,rt->relocs[i].symbol,rt->relocs[i].object_name};return 0;}
uint32_t agr_dlopen(agr_runtime*rt,const char*name){
    if(!name){for(uint32_t i=0;i<rt->object_count;i++)if(rt->objects[i].name){rt->dlerror[0]=0;return AGR_SELF_HANDLE;}return 0;}
    for(uint32_t i=0;i<rt->object_count;i++)if(rt->objects[i].name&&!strcmp(rt->objects[i].name,name)){
        rt->objects[i].refs++;rt->dlerror[0]=0;return rt->objects[i].base;
    }
    snprintf(rt->dlerror,sizeof(rt->dlerror),"library not loaded: %s",name);return 0;
}
uint32_t agr_dlsym(agr_runtime*rt,uint32_t handle,const char*name){
    uint32_t a=0;
    if(handle==0||handle==0xffffffffu||handle==AGR_SELF_HANDLE)a=symbol_lookup(rt,name);
    else for(uint32_t i=0;i<rt->symbol_count;i++){
        uint32_t oi=rt->symbols[i].object_index;
        if(rt->objects[oi].name&&rt->objects[oi].base==handle&&!strcmp(rt->symbols[i].name,name)){
            a=rt->symbols[i].address;break;
        }
    }
    if(!a)snprintf(rt->dlerror,sizeof(rt->dlerror),"undefined symbol: %s",name);else rt->dlerror[0]=0;
    return a;
}
uint32_t agr_dlclose(agr_runtime*rt,uint32_t handle){
    if(handle==AGR_SELF_HANDLE){rt->dlerror[0]=0;return 0;}
    for(uint32_t oi=0;oi<rt->object_count;oi++){
        agr_object *object=&rt->objects[oi];
        if(!object->name||object->base!=handle)continue;
        if(object->refs>1){object->refs--;rt->dlerror[0]=0;return 0;}
        int32_t guest_errno=0;
        if(agr_aosp_linker_unload(&rt->linker_mmap,&object->image,&guest_errno)){
            snprintf(rt->dlerror,sizeof(rt->dlerror),"image unmap failed: errno %d",guest_errno);
            return 0xffffffffu;
        }
        uint32_t write=0;
        for(uint32_t read=0,count=rt->symbol_count;read<count;read++){
            if(rt->symbols[read].object_index==oi){free(rt->symbols[read].name);continue;}
            rt->symbols[write++]=rt->symbols[read];
        }
        rt->symbol_count=write;write=0;
        for(uint32_t read=0,count=rt->needed_count;read<count;read++){
            if(rt->needed_owner[read]==oi){free(rt->needed[read]);continue;}
            rt->needed[write]=rt->needed[read];rt->needed_owner[write++]=rt->needed_owner[read];
        }
        rt->needed_count=write;write=0;
        for(uint32_t read=0,count=rt->reloc_count;read<count;read++){
            if(rt->relocs[read].object_index==oi){free(rt->relocs[read].symbol);free(rt->relocs[read].object_name);continue;}
            rt->relocs[write++]=rt->relocs[read];
        }
        rt->reloc_count=write;write=0;
        for(uint32_t read=0,count=rt->constructor_count;read<count;read++){
            if(rt->constructor_owner[read]==oi)continue;
            rt->constructors[write]=rt->constructors[read];
            rt->constructor_owner[write++]=rt->constructor_owner[read];
        }
        rt->constructor_count=write;
        free(object->name);memset(object,0,sizeof(*object));
        rt->dlerror[0]=0;return 0;
    }
    snprintf(rt->dlerror,sizeof(rt->dlerror),"invalid library handle");return 0xffffffffu;
}
const char*agr_dlerror(agr_runtime*rt){if(!rt->dlerror[0])return NULL;static char out[512];snprintf(out,sizeof(out),"%s",rt->dlerror);rt->dlerror[0]=0;return out;}
uint32_t agr_find_exidx(agr_runtime*rt,uint32_t pc,uint32_t*count){for(uint32_t i=0;i<rt->object_count;i++)if(pc>=rt->objects[i].min_address&&pc<rt->objects[i].max_address){if(count)*count=rt->objects[i].exidx_count;return rt->objects[i].exidx;}if(count)*count=0;return 0;}

static agr_thread*thread(agr_runtime*rt){for(uint32_t i=0;i<rt->thread_count;i++)if(rt->threads[i].id==rt->current_thread)return&rt->threads[i];return&rt->threads[0];}
void agr_set_current_thread(agr_runtime*rt,uint32_t id){for(uint32_t i=0;i<rt->thread_count;i++)if(rt->threads[i].id==id){rt->current_thread=id;return;}}uint32_t agr_current_thread(agr_runtime*rt){return rt->current_thread;}uint32_t agr_create_thread_state(agr_runtime*rt){if(rt->thread_count>=AGR_MAX_THREADS)return 0;uint32_t id=rt->next_thread++;rt->threads[rt->thread_count++].id=id;return id;}
static agr_word_state*word_state(agr_word_state*a,uint32_t*n,uint32_t cap,uint32_t address){for(uint32_t i=0;i<*n;i++)if(a[i].address==address)return&a[i];if(*n>=cap)return NULL;a[*n]=(agr_word_state){address,0};return&a[(*n)++];}
static agr_mutex*mutex_state(agr_runtime*rt,uint32_t address){for(uint32_t i=0;i<rt->mutex_count;i++)if(rt->mutexes[i].address==address)return&rt->mutexes[i];if(rt->mutex_count>=AGR_MAX_MUTEXES)return NULL;rt->mutexes[rt->mutex_count]=(agr_mutex){address,0,0,1};return&rt->mutexes[rt->mutex_count++];}
uint32_t agr_mutex_owner(agr_runtime*rt,uint32_t address){agr_mutex*m=mutex_state(rt,address);return m?m->owner:0;}
void agr_complete_once(agr_runtime*rt,uint32_t control){agr_word_state*s=word_state(rt->once,&rt->once_count,AGR_MAX_ONCE,control);if(s){s->state=1;write_u32(rt,control,1);}}

static uint32_t append_text(char *output,uint32_t capacity,uint32_t length,const char *text){
    uint32_t n=(uint32_t)strlen(text);if(length<capacity){uint32_t copy=n<capacity-1-length?n:capacity-1-length;memcpy(output+length,text,copy);}return length+n;
}
static int guest_vformat(agr_runtime*rt,uint32_t format_address,uint32_t args_address,char*output,uint32_t capacity){
    char format[4096],piece[1024],spec[64];uint32_t length=0,cursor=args_address;if(!read_cstr(rt,format_address,format,sizeof(format)))return -1;
    for(uint32_t i=0;format[i];){if(format[i]!='%'){char one[2]={format[i++],0};length=append_text(output,capacity,length,one);continue;}uint32_t start=i++;if(format[i]=='%'){length=append_text(output,capacity,length,"%");i++;continue;}
        uint32_t si=0;spec[si++]='%';while(format[i]&&strchr("-+ #0",format[i])&&si+1<sizeof(spec))spec[si++]=format[i++];
        if(format[i]=='*'){char number[16];snprintf(number,sizeof(number),"%d",(int32_t)read_u32(rt,cursor));cursor+=4;for(uint32_t k=0;number[k]&&si+1<sizeof(spec);k++)spec[si++]=number[k];}else while(isdigit((unsigned char)format[i])&&si+1<sizeof(spec))spec[si++]=format[i++];
        if(format[i]=='.'){spec[si++]=format[i++];if(format[i]=='*'){char number[16];snprintf(number,sizeof(number),"%d",(int32_t)read_u32(rt,cursor));cursor+=4;for(uint32_t k=0;number[k]&&si+1<sizeof(spec);k++)spec[si++]=number[k];}else while(isdigit((unsigned char)format[i])&&si+1<sizeof(spec))spec[si++]=format[i++];}
        char length_char=0;if(strchr("hlLzjt",format[i])){length_char=format[i];spec[si++]=format[i++];if(format[i]==length_char&&si+1<sizeof(spec))spec[si++]=format[i++];}
        char conversion=format[i]?format[i++]:0;if(!conversion){for(uint32_t k=start;format[k];k++){char one[2]={format[k],0};length=append_text(output,capacity,length,one);}break;}spec[si++]=conversion;spec[si]=0;piece[0]=0;
        if(strchr("fFeEgGaA",conversion)){cursor=align_up(cursor,8);uint32_t bits[2]={read_u32(rt,cursor),read_u32(rt,cursor+4)};double value;memcpy(&value,bits,8);cursor+=8;snprintf(piece,sizeof(piece),spec,value);}
        else {uint32_t raw=read_u32(rt,cursor);cursor+=4;if(conversion=='s'){char string_value[4096];if(raw&&read_cstr(rt,raw,string_value,sizeof(string_value)))snprintf(piece,sizeof(piece),spec,string_value);else snprintf(piece,sizeof(piece),spec,"(null)");}
            else if(conversion=='c')snprintf(piece,sizeof(piece),spec,(int)(raw&255));else if(conversion=='p')snprintf(piece,sizeof(piece),"0x%x",raw);else if(conversion=='d'||conversion=='i')snprintf(piece,sizeof(piece),spec,(int32_t)raw);else snprintf(piece,sizeof(piece),spec,raw);}
        length=append_text(output,capacity,length,piece);
    }
    if(capacity)output[length<capacity?length:capacity-1]=0;return (int)length;
}

int32_t agr_dispatch_system(agr_runtime*rt,const char*name,const uint32_t r[4],uint32_t sp,agr_dispatch_result*out){
    (void)sp;memset(out,0,sizeof(*out));uint32_t a=r[0],b=r[1],c=r[2],d=r[3];char x[4096],y[4096];out->handled=1;
    if(!strcmp(name,"strlen")){if(!read_cstr(rt,a,x,sizeof(x)))return fail(rt,"strlen read");out->value=(uint32_t)strlen(x);}
    else if(!strcmp(name,"strcmp")||!strcmp(name,"strncmp")){if(!read_cstr(rt,a,x,sizeof(x))||!read_cstr(rt,b,y,sizeof(y)))return fail(rt,"string read");int v=!strcmp(name,"strcmp")?strcmp(x,y):strncmp(x,y,c);out->value=(uint32_t)(int32_t)v;}
    else if(!strcmp(name,"memcpy")||!strcmp(name,"memmove")){
        unsigned char buf[1024];
        if(!strcmp(name,"memmove")&&a>b&&a-b<c){
            for(uint32_t remaining=c;remaining;){uint32_t n=remaining>sizeof(buf)?sizeof(buf):remaining;remaining-=n;
                if(!read_mem(rt,b+remaining,buf,n)||!write_mem(rt,a+remaining,buf,n))return fail(rt,"memory move");}
        }else for(uint32_t off=0;off<c;){uint32_t n=c-off>sizeof(buf)?sizeof(buf):c-off;
            if(!read_mem(rt,b+off,buf,n)||!write_mem(rt,a+off,buf,n))return fail(rt,"memory copy");off+=n;}
        out->value=a;
    }
    else if(!strcmp(name,"memset")){unsigned char buf[512];memset(buf,b&255,sizeof(buf));for(uint32_t off=0;off<c;){uint32_t n=c-off>sizeof(buf)?sizeof(buf):c-off;if(!write_mem(rt,a+off,buf,n))return fail(rt,"memset");off+=n;}out->value=a;}
    else if(!strcmp(name,"memcmp")){unsigned char p[256],q[256];int v=0;for(uint32_t off=0;off<c&&!v;){uint32_t n=c-off>sizeof(p)?sizeof(p):c-off;if(!read_mem(rt,a+off,p,n)||!read_mem(rt,b+off,q,n))return fail(rt,"memcmp");v=memcmp(p,q,n);off+=n;}out->value=(uint32_t)(int32_t)v;}
    else if(!strcmp(name,"memchr")){unsigned char p[256];uint32_t found=0;for(uint32_t off=0;off<c&&!found;){uint32_t n=c-off>sizeof(p)?sizeof(p):c-off;if(!read_mem(rt,a+off,p,n))return fail(rt,"memchr");void*q=memchr(p,b&255,n);if(q)found=a+off+(uint32_t)((unsigned char*)q-p);off+=n;}out->value=found;}
    else if(!strcmp(name,"strchr")){if(!read_cstr(rt,a,x,sizeof(x)))return fail(rt,"strchr read");char*q=strchr(x,b&255);out->value=q?a+(uint32_t)(q-x):0;}
    else if(!strcmp(name,"strerror")){const char*message=strerror((int)a);out->value=agr_alloc_static(rt,message,(uint32_t)strlen(message)+1,1);}
    else if(!strcmp(name,"strtod")){if(!read_cstr(rt,a,x,sizeof(x)))return fail(rt,"strtod read");char*end=NULL;double v=strtod(x,&end);if(b)write_u32(rt,b,a+(uint32_t)(end-x));uint32_t bits[2];memcpy(bits,&v,8);out->value=bits[0];out->value_r1=bits[1];}
    else if(!strcmp(name,"sinf")||!strcmp(name,"cosf")||!strcmp(name,"ceilf")||!strcmp(name,"floorf")||!strcmp(name,"sqrtf")||!strcmp(name,"logf")){float v;memcpy(&v,&a,4);if(!strcmp(name,"sinf"))v=sinf(v);else if(!strcmp(name,"cosf"))v=cosf(v);else if(!strcmp(name,"ceilf"))v=ceilf(v);else if(!strcmp(name,"floorf"))v=floorf(v);else if(!strcmp(name,"sqrtf"))v=sqrtf(v);else v=logf(v);memcpy(&out->value,&v,4);}
    else if(!strcmp(name,"sin")||!strcmp(name,"cos")||!strcmp(name,"ceil")||!strcmp(name,"floor")||!strcmp(name,"sqrt")||!strcmp(name,"acos")){uint32_t bits[2]={a,b};double v;memcpy(&v,bits,8);if(!strcmp(name,"sin"))v=sin(v);else if(!strcmp(name,"cos"))v=cos(v);else if(!strcmp(name,"ceil"))v=ceil(v);else if(!strcmp(name,"floor"))v=floor(v);else if(!strcmp(name,"sqrt"))v=sqrt(v);else v=acos(v);memcpy(bits,&v,8);out->value=bits[0];out->value_r1=bits[1];}
    else if(!strcmp(name,"wctob")||!strcmp(name,"btowc"))out->value=a<=0x7f?a:0xffffffffu;
    else if(!strcmp(name,"towlower"))out->value=a<=255?(uint32_t)tolower((int)a):a;
    else if(!strcmp(name,"towupper"))out->value=a<=255?(uint32_t)toupper((int)a):a;
    else if(!strcmp(name,"setlocale")){const char*locale="C";if(b&&read_cstr(rt,b,x,sizeof(x))&&x[0]&&strcmp(x,"POSIX"))locale=x;out->value=agr_alloc_static(rt,locale,(uint32_t)strlen(locale)+1,1);}
    else if(!strcmp(name,"wctype")){if(!read_cstr(rt,a,x,sizeof(x)))return fail(rt,"wctype read");static const char*names[]={"alnum","alpha","blank","cntrl","digit","graph","lower","print","punct","space","upper","xdigit"};for(uint32_t i=0;i<12;i++)if(!strcmp(x,names[i])){out->value=i+1;break;}}
    else if(!strcmp(name,"iswctype")){int ch=(int)a;switch(b){case 1:out->value=isalnum(ch);break;case 2:out->value=isalpha(ch);break;case 3:out->value=ch==' '||ch=='\t';break;case 4:out->value=iscntrl(ch);break;case 5:out->value=isdigit(ch);break;case 6:out->value=isgraph(ch);break;case 7:out->value=islower(ch);break;case 8:out->value=isprint(ch);break;case 9:out->value=ispunct(ch);break;case 10:out->value=isspace(ch);break;case 11:out->value=isupper(ch);break;case 12:out->value=isxdigit(ch);break;default:out->value=0;}}
    else if(!strcmp(name,"pipe")){uint32_t rf=0,wf=0;if(!rt->cb.pipe_create||rt->cb.pipe_create(rt->cb.user,&rf,&wf)!=0)out->value=0xffffffffu;else{write_u32(rt,a,rf);write_u32(rt,a+4,wf);}}
    else if(!strcmp(name,"read")||!strcmp(name,"write")){unsigned char buffer[1024];uint32_t done=0;for(uint32_t off=0;off<c;){uint32_t n=c-off>sizeof(buffer)?sizeof(buffer):c-off,k;if(!strcmp(name,"read")){k=rt->cb.fd_read?rt->cb.fd_read(rt->cb.user,a,buffer,n):0;if(k&&!write_mem(rt,b+off,buffer,k))return fail(rt,"read guest write");}else{if(!read_mem(rt,b+off,buffer,n))return fail(rt,"write guest read");k=rt->cb.fd_write?rt->cb.fd_write(rt->cb.user,a,buffer,n):0;}done+=k;off+=k;if(k<n)break;}out->value=done;}
    else if(!strcmp(name,"close")){out->value=rt->cb.fd_close?(uint32_t)rt->cb.fd_close(rt->cb.user,a):0xffffffffu;}
    else if(!strcmp(name,"vsprintf")||!strcmp(name,"vsnprintf")){uint32_t destination=a,capacity,format,args;if(!strcmp(name,"vsprintf")){capacity=8192;format=b;args=c;}else{capacity=b;format=c;args=d;}char rendered[8192];int length=guest_vformat(rt,format,args,rendered,sizeof(rendered));if(length<0)return fail(rt,"guest printf format read");uint32_t write_size=capacity?(uint32_t)length<capacity?(uint32_t)length+1:capacity:0;if(destination&&write_size&&!write_mem(rt,destination,rendered,write_size))return fail(rt,"guest printf write");out->value=(uint32_t)length;}
    else if(!strcmp(name,"__android_log_print")){if(!read_cstr(rt,b,x,sizeof(x))||!read_cstr(rt,c,y,sizeof(y)))return fail(rt,"android log strings");if(rt->cb.log)rt->cb.log(rt->cb.user,a,x,y);out->value=1;}
    else if(!strcmp(name,"fopen")){if(!read_cstr(rt,a,x,sizeof(x))||!read_cstr(rt,b,y,sizeof(y)))return fail(rt,"fopen path");out->value=rt->cb.file_open?rt->cb.file_open(rt->cb.user,x,y):0;}
    else if(!strcmp(name,"fclose")){out->value=rt->cb.file_close?(uint32_t)rt->cb.file_close(rt->cb.user,a):0xffffffffu;}
    else if(!strcmp(name,"fread")||!strcmp(name,"fwrite")){uint32_t total=b*c,done=0;unsigned char buffer[1024];if(!b){out->value=0;}else{for(uint32_t off=0;off<total;){uint32_t n=total-off>sizeof(buffer)?sizeof(buffer):total-off,k;if(!strcmp(name,"fread")){k=rt->cb.file_read?rt->cb.file_read(rt->cb.user,d,buffer,n):0;if(k&&!write_mem(rt,a+off,buffer,k))return fail(rt,"fread guest write");}else{if(!read_mem(rt,a+off,buffer,n))return fail(rt,"fwrite guest read");k=rt->cb.file_write?rt->cb.file_write(rt->cb.user,d,buffer,n):0;}done+=k;off+=k;if(k<n)break;}out->value=done/b;}}
    else if(!strcmp(name,"fseek")){out->value=rt->cb.file_seek?(uint32_t)rt->cb.file_seek(rt->cb.user,a,(int32_t)b,c):0xffffffffu;}
    else if(!strcmp(name,"ftell")){out->value=rt->cb.file_tell?(uint32_t)rt->cb.file_tell(rt->cb.user,a):0xffffffffu;}
    else if(!strcmp(name,"malloc"))out->value=agr_malloc(rt,a);
    else if(!strcmp(name,"calloc"))out->value=agr_calloc(rt,a,b);
    else if(!strcmp(name,"free"))agr_free(rt,a);
    else if(!strcmp(name,"realloc"))out->value=agr_realloc(rt,a,b);
    else if(!strcmp(name,"memalign"))out->value=agr_malloc_aligned(rt,b,a);
    else if(!strcmp(name,"aligned_alloc"))out->value=(a&&b%a==0)?agr_malloc_aligned(rt,b,a):0;
    else if(!strcmp(name,"posix_memalign")){
        if(!heap_alignment_valid(b)){out->value=EINVAL;}
        else {uint32_t aligned=agr_malloc_aligned(rt,c,b);
            if(!aligned)out->value=ENOMEM;
            else if(!write_mem(rt,a,&aligned,4)){agr_free(rt,aligned);out->value=EINVAL;}
        }
    }
    else if(!strcmp(name,"__errno")){agr_thread*t=thread(rt);if(!t->errno_address)t->errno_address=agr_malloc(rt,4);out->value=t->errno_address;}
    else if(!strcmp(name,"clock_gettime")){rt->clock_ns+=16666667ULL;uint32_t v[2]={(uint32_t)(rt->clock_ns/1000000000ULL),(uint32_t)(rt->clock_ns%1000000000ULL)};write_mem(rt,b,v,8);}
    else if(!strcmp(name,"gettimeofday")){rt->clock_ns+=16666667ULL;uint32_t v[2]={(uint32_t)(rt->clock_ns/1000000000ULL),(uint32_t)((rt->clock_ns%1000000000ULL)/1000)};write_mem(rt,a,v,8);}
    else if(!strcmp(name,"pthread_key_create")){uint32_t k=rt->next_tls_key++;if(k>=AGR_MAX_TLS_KEYS)return fail(rt,"TLS key table full");rt->tls_destructors[k]=b;write_u32(rt,a,k);}
    else if(!strcmp(name,"pthread_key_delete")){if(a<AGR_MAX_TLS_KEYS){rt->tls_destructors[a]=0;for(uint32_t i=0;i<rt->thread_count;i++)rt->threads[i].tls[a]=0;}}
    else if(!strcmp(name,"pthread_setspecific")){if(a>=AGR_MAX_TLS_KEYS)return fail(rt,"invalid TLS key");thread(rt)->tls[a]=b;}
    else if(!strcmp(name,"pthread_getspecific")){out->value=a<AGR_MAX_TLS_KEYS?thread(rt)->tls[a]:0;}
    else if(!strcmp(name,"pthread_once")){agr_word_state*s=word_state(rt->once,&rt->once_count,AGR_MAX_ONCE,a);if(!s)return fail(rt,"once table full");if(!s->state){s->state=2;out->action=AGR_ACTION_CALL_ONCE;out->action_arg0=b;out->action_arg1=a;}}
    else if(!strcmp(name,"pthread_mutex_init")){agr_mutex*m=mutex_state(rt,a);if(!m)return fail(rt,"mutex table full");m->owner=m->depth=0;write_u32(rt,a,0);}
    else if(!strcmp(name,"pthread_mutex_destroy")){agr_mutex*m=mutex_state(rt,a);if(m)m->live=0;}
    else if(!strcmp(name,"pthread_mutex_lock")){agr_mutex*m=mutex_state(rt,a);if(!m)return fail(rt,"mutex table full");if(m->owner&&m->owner!=rt->current_thread)return fail(rt,"contended mutex requires scheduler");m->owner=rt->current_thread;m->depth++;}
    else if(!strcmp(name,"pthread_mutex_unlock")){agr_mutex*m=mutex_state(rt,a);if(!m||m->owner!=rt->current_thread)return fail(rt,"mutex unlock by non-owner");if(--m->depth==0)m->owner=0;}
    else if(!strcmp(name,"pthread_create")){uint32_t id=agr_create_thread_state(rt);if(!id)return fail(rt,"thread table full");write_u32(rt,a,id);out->action=AGR_ACTION_RUN_THREAD;out->action_arg0=c;out->action_arg1=d;out->value=id;}
    else if(!strcmp(name,"pthread_cond_wait")){agr_mutex*m=mutex_state(rt,b);if(m&&m->owner==rt->current_thread){m->owner=0;m->depth=0;}out->action=AGR_ACTION_COND_WAIT;out->action_arg0=a;out->action_arg1=b;}
    else if(!strcmp(name,"pthread_cond_broadcast")||!strcmp(name,"pthread_cond_signal")){out->action=AGR_ACTION_COND_BROADCAST;out->action_arg0=a;}
    else if(!strcmp(name,"pthread_cond_init")||!strcmp(name,"pthread_cond_destroy")||!strcmp(name,"pthread_attr_setdetachstate")){}
    else if(!strcmp(name,"pthread_attr_init")){unsigned char z[16]={0};write_mem(rt,a,z,16);}
    else if(!strcmp(name,"dlopen")){if(a&&!read_cstr(rt,a,x,sizeof(x)))return fail(rt,"dlopen name");out->value=agr_dlopen(rt,a?x:NULL);}
    else if(!strcmp(name,"dlsym")){if(!read_cstr(rt,b,x,sizeof(x)))return fail(rt,"dlsym name");out->value=agr_dlsym(rt,a,x);}
    else if(!strcmp(name,"dlclose"))out->value=agr_dlclose(rt,a);
    else if(!strcmp(name,"dlerror")){const char*e=agr_dlerror(rt);out->value=e?agr_alloc_static(rt,e,(uint32_t)strlen(e)+1,1):0;}
    else if(!strcmp(name,"android_update_LD_LIBRARY_PATH")){if(a&&read_cstr(rt,a,rt->library_path,sizeof(rt->library_path))==0)return fail(rt,"library path read");if(!a)rt->library_path[0]=0;}
    else if(!strcmp(name,"dladdr")){agr_object*object=NULL;uint32_t object_index=0;for(uint32_t i=0;i<rt->object_count;i++)if(a>=rt->objects[i].min_address&&a<rt->objects[i].max_address){object=&rt->objects[i];object_index=i;break;}if(!object)out->value=0;else{uint32_t file_name=agr_alloc_static(rt,object->name,(uint32_t)strlen(object->name)+1,1),symbol_name=0,symbol_address=0;const char*nearest=NULL;for(uint32_t i=0;i<rt->symbol_count;i++)if(rt->symbols[i].object_index==object_index&&rt->symbols[i].address<=a&&rt->symbols[i].address>=symbol_address){symbol_address=rt->symbols[i].address;nearest=rt->symbols[i].name;}if(nearest)symbol_name=agr_alloc_static(rt,nearest,(uint32_t)strlen(nearest)+1,1);write_u32(rt,b,file_name);write_u32(rt,b+4,object->base);write_u32(rt,b+8,symbol_name);write_u32(rt,b+12,symbol_address);out->value=1;}}
    else if(!strcmp(name,"dl_unwind_find_exidx")||!strcmp(name,"__gnu_Unwind_Find_exidx")){uint32_t count;out->value=agr_find_exidx(rt,a,&count);if(b)write_u32(rt,b,count);}
    else if(!strcmp(name,"__cxa_guard_acquire")){agr_word_state*s=word_state(rt->guards,&rt->guard_count,AGR_MAX_GUARDS,a);if(!s)return fail(rt,"guard table full");out->value=s->state==1?0:1;if(!s->state)s->state=2;}
    else if(!strcmp(name,"__cxa_guard_release")||!strcmp(name,"__cxa_guard_abort")){agr_word_state*s=word_state(rt->guards,&rt->guard_count,AGR_MAX_GUARDS,a);if(s){s->state=!strcmp(name,"__cxa_guard_release")?1:0;write_u32(rt,a,s->state);}}
    else if(!strcmp(name,"__cxa_atexit")){if(rt->atexit_count>=AGR_MAX_ATEXIT)return fail(rt,"atexit table full");rt->atexit[rt->atexit_count++]=(agr_atexit){a,b,c};}
    else if(!strcmp(name,"__cxa_finalize")){for(uint32_t i=rt->atexit_count;i>0;i--){agr_atexit item=rt->atexit[i-1];if(!a||item.dso==a){out->action=AGR_ACTION_FINALIZE;out->action_arg0=item.function;out->action_arg1=item.argument;memmove(&rt->atexit[i-1],&rt->atexit[i],(rt->atexit_count-i)*sizeof(rt->atexit[0]));rt->atexit_count--;break;}}}
    else if(!strcmp(name,"abort")||!strcmp(name,"__stack_chk_fail")||!strcmp(name,"__cxa_pure_virtual")){out->action=AGR_ACTION_ABORT;}
    else {out->handled=0;}
    return 0;
}
