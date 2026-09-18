#include "agr_runtime.h"
#include "../AospLinker/agr_aosp_linker.h"
#include "../AospLinker/agr_aosp_dynamic.h"
#include "../Bionic/agr_bionic_thread_lifecycle.h"
#include "../Bionic/agr_bionic_tls.h"
#include "../Bionic/agr_bionic_sync.h"
#include "../Bionic/agr_bionic_thread_attr.h"
#include "../Bionic/agr_futex_host.h"
#include "../Bionic/agr_bionic_errno.h"
#include "../HostServices/agr_host_services.h"

#include <ctype.h>
#include "agr_elf32.h"
#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdatomic.h>

#ifndef PT_ARM_EXIDX
#define PT_ARM_EXIDX 0x70000001
#endif

#if !defined(__APPLE__)
#define AGR_MAX_THREADS 128
#define AGR_MAX_TLS_KEYS 256
#define AGR_MAX_MUTEXES 2048
#endif
#define AGR_MAX_ONCE 2048
#define AGR_MAX_GUARDS 2048
#define AGR_MAX_ATEXIT 4096

typedef struct agr_heap_block {
    uint32_t address, span, requested, alignment;
    uint8_t live;
    struct agr_heap_block *prev, *next;
} agr_heap_block;
#if !defined(__APPLE__)
typedef struct { uint32_t id, errno_address; uint32_t tls[AGR_MAX_TLS_KEYS]; } agr_thread;
typedef struct { uint32_t address, owner, depth, live; } agr_mutex;
#endif
typedef struct { uint32_t address, state; } agr_word_state;
typedef struct { uint32_t function, argument, dso; } agr_atexit;

struct agr_runtime {
    agr_callbacks cb;
    char error[512];
    char dlerror[512];
    char library_path[1024];
    uint32_t static_ptr, static_limit, heap_base, heap_limit;
    agr_heap_block *heap_blocks;
    agr_aosp_dynamic *dynamic_linker;
    atomic_uint next_thread;
#if !defined(__APPLE__)
    agr_thread threads[AGR_MAX_THREADS]; uint32_t thread_count, current_thread;
    uint32_t tls_destructors[AGR_MAX_TLS_KEYS], next_tls_key;
    agr_mutex mutexes[AGR_MAX_MUTEXES]; uint32_t mutex_count;
#endif
    agr_word_state once[AGR_MAX_ONCE]; uint32_t once_count;
    agr_word_state guards[AGR_MAX_GUARDS]; uint32_t guard_count;
    agr_atexit atexit[AGR_MAX_ATEXIT]; uint32_t atexit_count;
    uint64_t clock_ns;
    agr_guest_vma_space linker_vma;
    agr_bionic_mmap_context linker_mmap;
    atomic_flag heap_lock;
    atomic_flag static_lock;
    atomic_flag vma_lock;
#if defined(__APPLE__)
    /* Formal API19 pthread production state. Fixed thread/TLS/mutex tables
     * are absent from Apple builds. */
    agr_host_services host_services;
    agr_bionic_thread_lifecycle *thread_lifecycle;
    agr_bionic_tls *bionic_tls;
    agr_futex_host *futex;
    agr_bionic_sync bionic_sync;
#endif
};

static int read_mem(agr_runtime *rt, uint32_t address, void *data, uint32_t size);
static int write_mem(agr_runtime *rt, uint32_t address, const void *data, uint32_t size);

#if defined(__APPLE__)
static int32_t bionic_tls_read(void *opaque, uint32_t address, uint32_t *value) {
    return read_mem((agr_runtime *)opaque, address, value, 4) ? 0 : AGR_ANDROID_EFAULT;
}
static int32_t bionic_tls_write(void *opaque, uint32_t address, uint32_t value) {
    return write_mem((agr_runtime *)opaque, address, &value, 4) ? 0 : AGR_ANDROID_EFAULT;
}
static int32_t bionic_tls_invoke(void *opaque, uint32_t thread_id,
                                 uint32_t destructor, uint32_t value) {
    (void)thread_id;
    agr_runtime *rt = (agr_runtime *)opaque;
    /* Destructor execution is a same-thread guest callback. GuestRuntime
     * supplies it after its context is bound; this source-port boundary must
     * never create a synthetic scheduler frame. */
    uint32_t args[1] = {value};
    if (!rt->cb.invoke_guest_args) return AGR_ANDROID_ENOSYS;
    return rt->cb.invoke_guest_args(rt->cb.user, destructor,args,1) == 0 ? 0 : AGR_ANDROID_EFAULT;
}
static int32_t bionic_futex_read(void *opaque, uint32_t address, uint32_t *value) {
    return bionic_tls_read(opaque, address, value);
}
static int32_t bionic_sync_load(void *opaque, uint32_t address, uint32_t *value) {
    agr_runtime *rt = (agr_runtime *)opaque;
    return rt->cb.atomic_load ? (rt->cb.atomic_load)(rt->cb.user, address, value) : AGR_ANDROID_ENOSYS;
}
static int32_t bionic_sync_cas(void *opaque, uint32_t address, uint32_t old,
                               uint32_t next, uint32_t *observed) {
    agr_runtime *rt = (agr_runtime *)opaque;
    return rt->cb.atomic_cas ? rt->cb.atomic_cas(rt->cb.user,address,old,next,observed) : AGR_ANDROID_ENOSYS;
}
static int32_t bionic_sync_exchange(void *opaque, uint32_t address, uint32_t next,
                                    uint32_t *observed) {
    agr_runtime *rt = (agr_runtime *)opaque;
    return rt->cb.atomic_exchange ? (rt->cb.atomic_exchange)(rt->cb.user,address,next,observed) : AGR_ANDROID_ENOSYS;
}
static int32_t bionic_sync_fetch_sub(void *opaque, uint32_t address, uint32_t amount,
                                     uint32_t *observed) {
    agr_runtime *rt = (agr_runtime *)opaque;
    return rt->cb.atomic_fetch_sub ? (rt->cb.atomic_fetch_sub)(rt->cb.user,address,amount,observed) : AGR_ANDROID_ENOSYS;
}
static int32_t bionic_sync_wait(void *opaque, uint32_t address, uint32_t expected,
                                uint64_t timeout_ns) {
    agr_runtime *rt = (agr_runtime *)opaque;
    return agr_futex_host_wait(rt->futex, address, expected, timeout_ns);
}
static int32_t bionic_sync_wake(void *opaque, uint32_t address, uint32_t count) {
    agr_runtime *rt = (agr_runtime *)opaque;
    return agr_futex_host_wake(rt->futex, address, count);
}
static uint32_t bionic_sync_current_tid(void *opaque) {
    agr_runtime *rt = (agr_runtime *)opaque;
    return rt->cb.current_thread ? rt->cb.current_thread(rt->cb.user) : 0;
}
static int32_t bionic_sync_once(void *opaque, uint32_t function) {
    agr_runtime *rt = (agr_runtime *)opaque;
    return rt->cb.invoke_guest && rt->cb.invoke_guest(rt->cb.user,function) == 0 ? 0 : AGR_ANDROID_EFAULT;
}
static int32_t bionic_thread_execute(void *opaque, uint32_t guest_thread,
                                     uint32_t start, uint32_t argument,
                                     const agr_bionic_thread_attr *attr,
                                     uint32_t *return_value) {
    agr_runtime *rt = (agr_runtime *)opaque;
    return rt->cb.execute_thread ? rt->cb.execute_thread(rt->cb.user,guest_thread,start,argument,attr,return_value) : AGR_ANDROID_ENOSYS;
}
#endif

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
static int32_t dynamic_read(void *opaque, uint32_t address, void *data, uint32_t size) {
    return read_mem((agr_runtime *)opaque,address,data,size) ? 0 : EFAULT;
}
static uint32_t dynamic_import(void *opaque,const char *name,uint32_t type) {
    agr_runtime *rt=(agr_runtime*)opaque;
    return rt->cb.resolve_import ? rt->cb.resolve_import(rt->cb.user,name,type) : 0;
}
static void runtime_lock(atomic_flag *lock) {
    while (atomic_flag_test_and_set_explicit(lock,memory_order_acquire)) {}
}
static void runtime_unlock(atomic_flag *lock) {
    atomic_flag_clear_explicit(lock,memory_order_release);
}
static int32_t dynamic_invoke(void *opaque,uint32_t function) {
    agr_runtime *rt=(agr_runtime*)opaque;
    return rt->cb.invoke_guest ? rt->cb.invoke_guest(rt->cb.user,function) : 1;
}
static int32_t linker_protect(void *opaque, uint32_t address, uint32_t size, uint32_t protection) {
    agr_runtime *rt = (agr_runtime *)opaque;
    return rt->cb.protect ? rt->cb.protect(rt->cb.user, address, size, protection) : 0;
}
static uint32_t align_up(uint32_t value, uint32_t alignment) {
    if (!alignment) alignment = 1; return (value + alignment - 1) & ~(alignment - 1);
}
static void write_u32(agr_runtime *rt, uint32_t address, uint32_t value) { write_mem(rt, address, &value, 4); }
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
    atomic_flag_clear_explicit(&rt->heap_lock,memory_order_release);
    atomic_flag_clear_explicit(&rt->static_lock,memory_order_release);
    atomic_flag_clear_explicit(&rt->vma_lock,memory_order_release);
    rt->cb = *cb; rt->static_ptr = sb; rt->static_limit = sl; rt->heap_base = hb; rt->heap_limit = hl;
    if (agr_guest_vma_init(&rt->linker_vma, 4096, 0x10000u, 0x100000000ull)) {
        free(rt->heap_blocks); free(rt); return NULL;
    }
    rt->linker_mmap = (agr_bionic_mmap_context){&rt->linker_vma, rt, linker_write, NULL, linker_protect};
    agr_aosp_dynamic_callbacks dynamic_cb={rt,dynamic_read,linker_write,dynamic_import,NULL};
    if(cb->invoke_guest)dynamic_cb.invoke_guest_function=dynamic_invoke;
    rt->dynamic_linker=agr_aosp_dynamic_create(&rt->linker_mmap,&dynamic_cb);
    if(!rt->dynamic_linker){agr_guest_vma_destroy(&rt->linker_vma);free(rt->heap_blocks);free(rt);return NULL;}
#if !defined(__APPLE__)
    rt->thread_count = 1; rt->threads[0].id = 1; rt->current_thread = 1;
#endif
    atomic_init(&rt->next_thread,2u);
#if defined(__APPLE__)
    if (agr_host_services_init_darwin(&rt->host_services) != 0) {
        agr_aosp_dynamic_destroy(rt->dynamic_linker); agr_guest_vma_destroy(&rt->linker_vma); free(rt->heap_blocks); free(rt); return NULL;
    }
    rt->bionic_tls = agr_bionic_tls_create(rt,bionic_tls_read,bionic_tls_write,bionic_tls_invoke);
    rt->futex = agr_futex_host_create(rt,bionic_futex_read);
    rt->bionic_sync = (agr_bionic_sync){rt,bionic_sync_load,bionic_tls_write,bionic_sync_cas,
        bionic_sync_exchange,bionic_sync_fetch_sub,bionic_sync_wait,bionic_sync_wake,
        bionic_sync_current_tid,bionic_sync_once};
    rt->thread_lifecycle = agr_bionic_thread_lifecycle_create(&rt->host_services,rt,bionic_thread_execute);
    if (!rt->bionic_tls || !rt->futex || !rt->thread_lifecycle) {
        agr_bionic_thread_lifecycle_destroy(rt->thread_lifecycle); agr_futex_host_destroy(rt->futex);
        agr_bionic_tls_destroy(rt->bionic_tls); agr_aosp_dynamic_destroy(rt->dynamic_linker);
        agr_guest_vma_destroy(&rt->linker_vma); free(rt->heap_blocks); free(rt); return NULL;
    }
#endif
#if !defined(__APPLE__)
    rt->next_tls_key = 1;
#endif
    rt->clock_ns = 1000000000ULL; return rt;
}
void agr_runtime_destroy(agr_runtime *rt) {
    uint32_t i; if (!rt) return;
    agr_runtime_shutdown_workers(rt);
    for (agr_heap_block *block=rt->heap_blocks,*next; block; block=next) { next=block->next; free(block); }
    (void)i;
#if defined(__APPLE__)
    agr_bionic_thread_lifecycle_destroy(rt->thread_lifecycle);
    agr_futex_host_destroy(rt->futex);
    agr_bionic_tls_destroy(rt->bionic_tls);
#endif
    agr_aosp_dynamic_destroy(rt->dynamic_linker);
    agr_guest_vma_destroy(&rt->linker_vma); free(rt);
}
const char *agr_last_error(agr_runtime *rt) { return rt ? rt->error : "runtime is null"; }

uint32_t agr_alloc_static(agr_runtime *rt, const void *data, uint32_t size, uint32_t alignment) {
    if (!rt) return 0;
    runtime_lock(&rt->static_lock);
    uint32_t address = align_up(rt->static_ptr, alignment ? alignment : 8), end = address + size;
    if (end < address || end > rt->static_limit) { fail(rt, "static arena exhausted"); runtime_unlock(&rt->static_lock); return 0; }
    rt->static_ptr = end;
    if (size && !write_mem(rt, address, data, size)) { fail(rt, "static write failed"); runtime_unlock(&rt->static_lock); return 0; }
    runtime_unlock(&rt->static_lock); return address;
}
void agr_runtime_shutdown_workers(agr_runtime *rt) {
#if defined(__APPLE__)
    if (!rt) return;
    agr_futex_host_cancel_all(rt->futex);
    agr_bionic_thread_lifecycle_shutdown(rt->thread_lifecycle);
#else
    (void)rt;
#endif
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
    uint32_t result=0;
    runtime_lock(&rt->heap_lock);
    for (agr_heap_block *b=rt->heap_blocks; b; b=b->next) {
        if (b->live) continue;
        uint64_t aligned=((uint64_t)b->address+alignment-1u)&~(uint64_t)(alignment-1u);
        uint64_t end=aligned+span, block_end=(uint64_t)b->address+b->span;
        if (aligned>UINT32_MAX || end>block_end) continue;
        uint32_t prefix=(uint32_t)(aligned-b->address), suffix=(uint32_t)(block_end-end);
        agr_heap_block *allocated=prefix?(agr_heap_block *)calloc(1,sizeof(*allocated)):b;
        if (!allocated) break;
        agr_heap_block *tail=suffix?(agr_heap_block *)calloc(1,sizeof(*tail)):NULL;
        if (suffix && !tail) { if(prefix)free(allocated); break; }
        if (!heap_clear(rt,(uint32_t)aligned,span)) {
            if (prefix) free(allocated); free(tail); break;
        }
        if (prefix) { b->span=prefix; heap_insert_after(b,allocated); }
        allocated->address=(uint32_t)aligned; allocated->span=span;
        allocated->requested=requested; allocated->alignment=alignment; allocated->live=1;
        if (tail) { tail->address=(uint32_t)end; tail->span=suffix; heap_insert_after(allocated,tail); }
        result=allocated->address; break;
    }
    runtime_unlock(&rt->heap_lock);
    return result;
}
uint32_t agr_malloc(agr_runtime *rt, uint32_t size) { return agr_malloc_aligned(rt,size,8); }
uint32_t agr_calloc(agr_runtime *rt, uint32_t count, uint32_t size) {
    uint64_t total=(uint64_t)count*size;
    return total>UINT32_MAX?0:agr_malloc(rt,(uint32_t)total);
}
void agr_free(agr_runtime *rt, uint32_t address) {
    if (!rt) return;
    runtime_lock(&rt->heap_lock);
    agr_heap_block *b=heap_find_live(rt,address);
    if (b) { /* free(NULL), invalid and repeated frees cannot corrupt the heap. */
        b->live=0; b->requested=0; b->alignment=0;
        heap_coalesce(rt,b);
    }
    runtime_unlock(&rt->heap_lock);
}
uint32_t agr_allocation_size(agr_runtime *rt,uint32_t address) {
    if (!rt) return 0;
    runtime_lock(&rt->heap_lock);
    agr_heap_block *b=heap_find_live(rt,address);
    uint32_t size=b?b->requested:0;
    runtime_unlock(&rt->heap_lock);
    return size;
}
void agr_heap_diagnostics(agr_runtime *rt,uint32_t out[5]) {
    if (!out) return; memset(out,0,5*sizeof(*out)); if (!rt) return;
    runtime_lock(&rt->heap_lock);
    out[0]=rt->heap_base; out[1]=rt->heap_limit;
    for (agr_heap_block *b=rt->heap_blocks; b; b=b->next) {
        out[2]++;
        if (b->live) { out[3]++; out[4]+=b->requested; out[0]=b->address+b->span; }
    }
    runtime_unlock(&rt->heap_lock);
}
uint32_t agr_realloc(agr_runtime *rt,uint32_t address,uint32_t size) {
    if (!address) return agr_malloc(rt,size);
    if (!rt) return 0;
    runtime_lock(&rt->heap_lock);
    agr_heap_block *b=heap_find_live(rt,address);
    if (!b) { runtime_unlock(&rt->heap_lock); return 0; }
    if (!size) {
        b->live=0; b->requested=0; b->alignment=0; heap_coalesce(rt,b);
        runtime_unlock(&rt->heap_lock); return 0;
    }
    uint64_t rounded=((uint64_t)size+7u)&~7ull;
    if (rounded>UINT32_MAX) { runtime_unlock(&rt->heap_lock); return 0; }
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
        b->requested=size;runtime_unlock(&rt->heap_lock);return address;
    }
    if (b->next && !b->next->live && b->next->span>=new_span-b->span) {
        if (!heap_clear(rt,address+old_size,size-old_size)) { runtime_unlock(&rt->heap_lock); return 0; }
        agr_heap_block *next=b->next;
        uint32_t take=new_span-b->span;
        b->span=new_span;b->requested=size;
        next->address+=take;next->span-=take;
        if (!next->span) heap_remove(rt,next);
        runtime_unlock(&rt->heap_lock); return address;
    }
    uint32_t alignment=b->alignment;
    runtime_unlock(&rt->heap_lock);
    uint32_t replacement=agr_malloc_aligned(rt,size,alignment);
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

int32_t agr_register_elf_source(agr_runtime *rt,const char *name,const void *bytes,uint32_t size,uint32_t base){
    return rt&&rt->dynamic_linker?agr_aosp_dynamic_register(rt->dynamic_linker,name,bytes,size,base):-1;
}
int32_t agr_load_elf(agr_runtime *rt,const char *name,const void *bytes,uint32_t size,uint32_t base,agr_load_result *out){
    agr_aosp_dynamic_load_result result={0};
    int32_t rc=rt&&rt->dynamic_linker?agr_aosp_dynamic_load(rt->dynamic_linker,name,bytes,size,base,&result):-1;
    if(rc){const char *e=agr_aosp_dynamic_dlerror(rt?rt->dynamic_linker:NULL);if(rt)snprintf(rt->error,sizeof(rt->error),"%s",e?e:"AOSP dynamic linker load failed");return -1;}
    if(out)memcpy(out,&result,sizeof(result));return 0;
}
uint32_t agr_find_symbol(agr_runtime *rt,const char *name){return rt?agr_aosp_dynamic_find_symbol(rt->dynamic_linker,name):0;}
uint32_t agr_symbol_count(agr_runtime*rt){return rt?agr_aosp_dynamic_symbol_count(rt->dynamic_linker):0;}
const char*agr_symbol_name(agr_runtime*rt,uint32_t i){return rt?agr_aosp_dynamic_symbol_name(rt->dynamic_linker,i):NULL;}
uint32_t agr_symbol_address(agr_runtime*rt,uint32_t i){return rt?agr_aosp_dynamic_symbol_address(rt->dynamic_linker,i):0;}
uint32_t agr_needed_count(agr_runtime*rt){return rt?agr_aosp_dynamic_needed_count(rt->dynamic_linker):0;}
const char*agr_needed_name(agr_runtime*rt,uint32_t i){return rt?agr_aosp_dynamic_needed_name(rt->dynamic_linker,i):NULL;}
uint32_t agr_constructor_count(agr_runtime*rt){return rt?agr_aosp_dynamic_constructor_count(rt->dynamic_linker):0;}
uint32_t agr_constructor_address(agr_runtime*rt,uint32_t i){return rt?agr_aosp_dynamic_constructor_address(rt->dynamic_linker,i):0;}
uint32_t agr_finalizer_count(agr_runtime*rt){return rt?agr_aosp_dynamic_finalizer_count(rt->dynamic_linker):0;}
uint32_t agr_finalizer_address(agr_runtime*rt,uint32_t i){return rt?agr_aosp_dynamic_finalizer_address(rt->dynamic_linker,i):0;}
uint32_t agr_relocation_count(agr_runtime*rt){return rt?agr_aosp_dynamic_relocation_count(rt->dynamic_linker):0;}
int32_t agr_relocation(agr_runtime*rt,uint32_t i,agr_relocation_info*out){agr_aosp_dynamic_relocation r;if(!rt||!out||agr_aosp_dynamic_relocation_at(rt->dynamic_linker,i,&r))return -1;*out=(agr_relocation_info){r.type,r.address,r.symbol,r.object_name};return 0;}
uint32_t agr_dlopen(agr_runtime*rt,const char*name){return rt?agr_aosp_dynamic_dlopen(rt->dynamic_linker,name,2):0;}
uint32_t agr_dlopen_flags(agr_runtime*rt,const char*name,uint32_t flags){return rt?agr_aosp_dynamic_dlopen(rt->dynamic_linker,name,(int)flags):0;}
uint32_t agr_dlsym(agr_runtime*rt,uint32_t handle,const char*name){return rt?agr_aosp_dynamic_dlsym(rt->dynamic_linker,handle,name):0;}
uint32_t agr_dlclose(agr_runtime*rt,uint32_t handle){return rt?(uint32_t)agr_aosp_dynamic_dlclose(rt->dynamic_linker,handle):0xffffffffu;}
const char*agr_dlerror(agr_runtime*rt){return rt?agr_aosp_dynamic_dlerror(rt->dynamic_linker):NULL;}
uint32_t agr_find_exidx(agr_runtime*rt,uint32_t pc,uint32_t*count){return rt?agr_aosp_dynamic_find_exidx(rt->dynamic_linker,pc,count):0;}

#if !defined(__APPLE__)
static agr_thread*thread(agr_runtime*rt){for(uint32_t i=0;i<rt->thread_count;i++)if(rt->threads[i].id==rt->current_thread)return&rt->threads[i];return&rt->threads[0];}
void agr_set_current_thread(agr_runtime*rt,uint32_t id){for(uint32_t i=0;i<rt->thread_count;i++)if(rt->threads[i].id==id){rt->current_thread=id;return;}}
#endif
uint32_t agr_current_thread(agr_runtime*rt){
#if defined(__APPLE__)
    if (rt && rt->cb.current_thread) return rt->cb.current_thread(rt->cb.user);
    return 0;
#else
    return rt ? rt->current_thread : 0;
#endif
}
uint32_t agr_runtime_current_pthread(agr_runtime *rt) {
#if defined(__APPLE__)
    return rt ? agr_bionic_thread_lifecycle_self(rt->thread_lifecycle) : 0;
#else
    return rt ? rt->current_thread : 0;
#endif
}
int32_t agr_runtime_map_thread_stack(agr_runtime *rt,uint32_t size,
                                     uint32_t guard,uint32_t *base) {
    if (!rt || !base || !size || guard>=size) return AGR_ANDROID_EINVAL;
    int32_t guest_errno=0;
    runtime_lock(&rt->vma_lock);
    if (agr_bionic_mmap(&rt->linker_mmap,0,size,AGR_PROT_READ|AGR_PROT_WRITE,
                        AGR_MAP_PRIVATE|AGR_MAP_ANONYMOUS|AGR_MAP_NORESERVE,
                        -1,0,base,&guest_errno)) {
        runtime_unlock(&rt->vma_lock);
        return guest_errno ? guest_errno : AGR_ANDROID_ENOMEM;
    }
    if (guard && agr_bionic_mprotect(&rt->linker_mmap,*base,guard,
                                     AGR_PROT_NONE,&guest_errno)) {
        int32_t ignored=0;
        agr_bionic_munmap(&rt->linker_mmap,*base,size,&ignored);
        runtime_unlock(&rt->vma_lock);
        return guest_errno ? guest_errno : AGR_ANDROID_EINVAL;
    }
    runtime_unlock(&rt->vma_lock);
    return 0;
}
void agr_runtime_unmap_thread_stack(agr_runtime *rt,uint32_t base,uint32_t size) {
    int32_t ignored=0;
    if (rt && base && size) {
        runtime_lock(&rt->vma_lock);
        agr_bionic_munmap(&rt->linker_mmap,base,size,&ignored);
        runtime_unlock(&rt->vma_lock);
    }
}
#if !defined(__APPLE__)
uint32_t agr_create_thread_state(agr_runtime*rt){if(rt->thread_count>=AGR_MAX_THREADS)return 0;uint32_t id=atomic_fetch_add_explicit(&rt->next_thread,1u,memory_order_relaxed);rt->threads[rt->thread_count++].id=id;return id;}
#endif
int32_t agr_runtime_attach_current_thread(agr_runtime *rt, uint32_t guest_thread,
                                          uint32_t pthread_handle, uint32_t tls_base) {
#if defined(__APPLE__)
    if (!rt || !guest_thread || !tls_base) return AGR_ANDROID_EINVAL;
    void *context = rt->cb.current_thread_context ?
        rt->cb.current_thread_context(rt->cb.user) : NULL;
    if (!context) return AGR_ANDROID_EINVAL;
    int32_t rc;
    if (guest_thread == 1u) {
        rc = agr_bionic_thread_lifecycle_register_current(rt->thread_lifecycle,
            guest_thread,pthread_handle,context);
    } else {
        rc = agr_bionic_thread_lifecycle_bind_current(rt->thread_lifecycle,guest_thread,context);
        if (!rc) pthread_handle=agr_bionic_thread_lifecycle_self(rt->thread_lifecycle);
    }
    if (rc) return rc;
    return agr_bionic_tls_register_thread(rt->bionic_tls,guest_thread,tls_base,pthread_handle);
#else
    (void)rt; (void)guest_thread; (void)pthread_handle; (void)tls_base;
    return 0;
#endif
}
int32_t agr_runtime_detach_current_thread(agr_runtime *rt, uint32_t guest_thread) {
#if defined(__APPLE__)
    if (!rt) return AGR_ANDROID_EINVAL;
    int32_t rc = agr_bionic_tls_cleanup_thread(rt->bionic_tls,guest_thread);
    if (rc && rc != AGR_ANDROID_ESRCH) return rc;
    rc = agr_bionic_tls_unregister_thread(rt->bionic_tls,guest_thread);
    return rc == AGR_ANDROID_ESRCH ? 0 : rc;
#else
    (void)rt; (void)guest_thread; return 0;
#endif
}
uint32_t agr_runtime_errno_address(agr_runtime *rt, uint32_t guest_thread) {
#if defined(__APPLE__)
    return rt ? agr_bionic_tls_errno_address(rt->bionic_tls,guest_thread) : 0;
#else
    (void)guest_thread; return 0;
#endif
}
static agr_word_state*word_state(agr_word_state*a,uint32_t*n,uint32_t cap,uint32_t address){for(uint32_t i=0;i<*n;i++)if(a[i].address==address)return&a[i];if(*n>=cap)return NULL;a[*n]=(agr_word_state){address,0};return&a[(*n)++];}
#if !defined(__APPLE__)
static agr_mutex*mutex_state(agr_runtime*rt,uint32_t address){for(uint32_t i=0;i<rt->mutex_count;i++)if(rt->mutexes[i].address==address)return&rt->mutexes[i];if(rt->mutex_count>=AGR_MAX_MUTEXES)return NULL;rt->mutexes[rt->mutex_count]=(agr_mutex){address,0,0,1};return&rt->mutexes[rt->mutex_count++];}
uint32_t agr_mutex_owner(agr_runtime*rt,uint32_t address){agr_mutex*m=mutex_state(rt,address);return m?m->owner:0;}
#endif
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
    else if(!strcmp(name,"__errno")){
#if defined(__APPLE__)
        out->value=agr_bionic_tls_errno_address(rt->bionic_tls,agr_current_thread(rt));
        if (!out->value) return fail(rt,"current GuestThreadContext has no Bionic TLS");
#else
        agr_thread*t=thread(rt);if(!t->errno_address)t->errno_address=agr_malloc(rt,4);out->value=t->errno_address;
#endif
    }
    else if(!strcmp(name,"clock_gettime")){rt->clock_ns+=16666667ULL;uint32_t v[2]={(uint32_t)(rt->clock_ns/1000000000ULL),(uint32_t)(rt->clock_ns%1000000000ULL)};write_mem(rt,b,v,8);}
    else if(!strcmp(name,"gettimeofday")){rt->clock_ns+=16666667ULL;uint32_t v[2]={(uint32_t)(rt->clock_ns/1000000000ULL),(uint32_t)((rt->clock_ns%1000000000ULL)/1000)};write_mem(rt,a,v,8);}
    else if(!strcmp(name,"pthread_key_create")){
#if defined(__APPLE__)
        uint32_t key=0; int32_t rc=agr_bionic_tls_key_create(rt->bionic_tls,b,&key);
        if(rc)out->value=(uint32_t)rc; else if(!write_mem(rt,a,&key,4))return fail(rt,"pthread_key_create write");
#else
        uint32_t k=rt->next_tls_key++;if(k>=AGR_MAX_TLS_KEYS)return fail(rt,"TLS key table full");rt->tls_destructors[k]=b;write_u32(rt,a,k);
#endif
    }
    else if(!strcmp(name,"pthread_key_delete")){
#if defined(__APPLE__)
        out->value=(uint32_t)agr_bionic_tls_key_delete(rt->bionic_tls,a);
#else
        if(a<AGR_MAX_TLS_KEYS){rt->tls_destructors[a]=0;for(uint32_t i=0;i<rt->thread_count;i++)rt->threads[i].tls[a]=0;}
#endif
    }
    else if(!strcmp(name,"pthread_setspecific")){
#if defined(__APPLE__)
        out->value=(uint32_t)agr_bionic_tls_setspecific(rt->bionic_tls,agr_current_thread(rt),a,b);
#else
        if(a>=AGR_MAX_TLS_KEYS)return fail(rt,"invalid TLS key");thread(rt)->tls[a]=b;
#endif
    }
    else if(!strcmp(name,"pthread_getspecific")){
#if defined(__APPLE__)
        uint32_t value=0; int32_t rc=agr_bionic_tls_getspecific(rt->bionic_tls,agr_current_thread(rt),a,&value);out->value=rc?0:value;
#else
        out->value=a<AGR_MAX_TLS_KEYS?thread(rt)->tls[a]:0;
#endif
    }
    else if(!strcmp(name,"pthread_once")){
#if defined(__APPLE__)
        out->value=(uint32_t)agr_bionic_once(&rt->bionic_sync,a,b);
#else
        agr_word_state*s=word_state(rt->once,&rt->once_count,AGR_MAX_ONCE,a);if(!s)return fail(rt,"once table full");if(!s->state){s->state=2;out->action=AGR_ACTION_CALL_ONCE;out->action_arg0=b;out->action_arg1=a;}
#endif
    }
    else if(!strcmp(name,"pthread_mutex_init")){
#if defined(__APPLE__)
        uint32_t attr=0;
        if (b && !read_mem(rt,b,&attr,4))return fail(rt,"pthread_mutex_init attr read");
        out->value=(uint32_t)agr_bionic_mutex_init(&rt->bionic_sync,a,(int32_t)attr);
#else
        agr_mutex*m=mutex_state(rt,a);if(!m)return fail(rt,"mutex table full");m->owner=m->depth=0;write_u32(rt,a,0);
#endif
    }
    else if(!strcmp(name,"pthread_mutex_destroy")){
#if defined(__APPLE__)
        out->value=(uint32_t)agr_bionic_mutex_destroy(&rt->bionic_sync,a);
#else
        agr_mutex*m=mutex_state(rt,a);if(m)m->live=0;
#endif
    }
    else if(!strcmp(name,"pthread_mutex_lock")){
#if defined(__APPLE__)
        out->value=(uint32_t)agr_bionic_mutex_lock(&rt->bionic_sync,a);
#else
        agr_mutex*m=mutex_state(rt,a);if(!m)return fail(rt,"mutex table full");if(m->owner&&m->owner!=rt->current_thread)return fail(rt,"contended mutex requires scheduler");m->owner=rt->current_thread;m->depth++;
#endif
    }
    else if(!strcmp(name,"pthread_mutex_unlock")){
#if defined(__APPLE__)
        out->value=(uint32_t)agr_bionic_mutex_unlock(&rt->bionic_sync,a);
#else
        agr_mutex*m=mutex_state(rt,a);if(!m||m->owner!=rt->current_thread)return fail(rt,"mutex unlock by non-owner");if(--m->depth==0)m->owner=0;
#endif
    }
    else if(!strcmp(name,"pthread_create")){
#if defined(__APPLE__)
        uint32_t guest_thread=atomic_fetch_add_explicit(&rt->next_thread,1u,memory_order_relaxed), handle=0;
        agr_bionic_thread_attr attr;
        if (b) { if(!read_mem(rt,b,&attr,sizeof(attr)))return fail(rt,"pthread_create attr read"); }
        else agr_bionic_thread_attr_init(&attr);
        if (attr.flags & ~3u || attr.stack_size < 8192u) { out->value=AGR_ANDROID_EINVAL; return 0; }
        int32_t rc=agr_bionic_thread_lifecycle_create_thread(rt->thread_lifecycle,guest_thread,c,d,&attr,&handle);
        if(rc)out->value=(uint32_t)rc; else if(!write_mem(rt,a,&handle,4))return fail(rt,"pthread_create write");
#else
        uint32_t id=agr_create_thread_state(rt);if(!id)return fail(rt,"thread table full");write_u32(rt,a,id);out->action=AGR_ACTION_RUN_THREAD;out->action_arg0=c;out->action_arg1=d;out->value=id;
#endif
    }
    else if(!strcmp(name,"pthread_join")){
#if defined(__APPLE__)
        uint32_t value=0; int32_t rc=agr_bionic_thread_lifecycle_join(rt->thread_lifecycle,a,&value); if(!rc&&b&&!write_mem(rt,b,&value,4))return fail(rt,"pthread_join write");out->value=(uint32_t)rc;
#else
        out->handled=0;
#endif
    }
    else if(!strcmp(name,"pthread_detach")){
#if defined(__APPLE__)
        out->value=(uint32_t)agr_bionic_thread_lifecycle_detach(rt->thread_lifecycle,a);
#else
        out->handled=0;
#endif
    }
    else if(!strcmp(name,"pthread_self")){
#if defined(__APPLE__)
        out->value=agr_bionic_thread_lifecycle_self(rt->thread_lifecycle);
#else
        out->value=agr_current_thread(rt);
#endif
    }
    else if(!strcmp(name,"pthread_equal")){out->value=a==b?1:0;}
    else if(!strcmp(name,"pthread_exit")){out->action=AGR_ACTION_THREAD_EXIT;out->action_arg0=a;}
    else if(!strcmp(name,"pthread_mutex_trylock")){
#if defined(__APPLE__)
        out->value=(uint32_t)agr_bionic_mutex_trylock(&rt->bionic_sync,a);
#else
        out->handled=0;
#endif
    }
    else if(!strcmp(name,"pthread_cond_init")){
#if defined(__APPLE__)
        uint32_t attr=0;
        if (b && !read_mem(rt,b,&attr,4))return fail(rt,"pthread_cond_init attr read");
        out->value=(uint32_t)agr_bionic_cond_init(&rt->bionic_sync,a,(int32_t)attr);
#else
        out->handled=0;
#endif
    }
    else if(!strcmp(name,"pthread_cond_destroy")){
#if defined(__APPLE__)
        out->value=(uint32_t)agr_bionic_cond_destroy(&rt->bionic_sync,a);
#else
        out->handled=0;
#endif
    }
    else if(!strcmp(name,"pthread_cond_wait")){
#if defined(__APPLE__)
        out->value=(uint32_t)agr_bionic_cond_wait_relative(&rt->bionic_sync,a,b,UINT64_MAX);
#else
        agr_mutex*m=mutex_state(rt,b);if(m&&m->owner==rt->current_thread){m->owner=0;m->depth=0;}out->action=AGR_ACTION_COND_WAIT;out->action_arg0=a;out->action_arg1=b;
#endif
    }
    else if(!strcmp(name,"pthread_cond_timedwait_relative_np")){
#if defined(__APPLE__)
        uint32_t ts[2]={0,0}; if(!read_mem(rt,c,ts,8))return fail(rt,"pthread_cond_timedwait_relative_np timespec");
        uint64_t ns=(uint64_t)ts[0]*1000000000ull+ts[1]; out->value=(uint32_t)agr_bionic_cond_wait_relative(&rt->bionic_sync,a,b,ns);
#else
        out->handled=0;
#endif
    }
    else if(!strcmp(name,"pthread_cond_broadcast")||!strcmp(name,"pthread_cond_signal")){
#if defined(__APPLE__)
        out->value=(uint32_t)(!strcmp(name,"pthread_cond_signal")?agr_bionic_cond_signal(&rt->bionic_sync,a):agr_bionic_cond_broadcast(&rt->bionic_sync,a));
#else
        out->action=AGR_ACTION_COND_BROADCAST;out->action_arg0=a;
#endif
    }
    else if(!strcmp(name,"pthread_mutexattr_init")||!strcmp(name,"pthread_mutexattr_destroy")||
            !strcmp(name,"pthread_mutexattr_settype")||!strcmp(name,"pthread_mutexattr_setpshared")||
            !strcmp(name,"pthread_condattr_init")||!strcmp(name,"pthread_condattr_destroy")||
            !strcmp(name,"pthread_condattr_setpshared")){
#if defined(__APPLE__)
        if (!strcmp(name,"pthread_mutexattr_init"))out->value=(uint32_t)agr_bionic_mutexattr_init(&rt->bionic_sync,a);
        else if (!strcmp(name,"pthread_mutexattr_destroy"))out->value=(uint32_t)agr_bionic_mutexattr_destroy(&rt->bionic_sync,a);
        else if (!strcmp(name,"pthread_mutexattr_settype"))out->value=(uint32_t)agr_bionic_mutexattr_settype(&rt->bionic_sync,a,(int32_t)b);
        else if (!strcmp(name,"pthread_mutexattr_setpshared"))out->value=(uint32_t)agr_bionic_mutexattr_setpshared(&rt->bionic_sync,a,(int32_t)b);
        else if (!strcmp(name,"pthread_condattr_init"))out->value=(uint32_t)agr_bionic_condattr_init(&rt->bionic_sync,a);
        else if (!strcmp(name,"pthread_condattr_destroy"))out->value=(uint32_t)agr_bionic_condattr_destroy(&rt->bionic_sync,a);
        else out->value=(uint32_t)agr_bionic_condattr_setpshared(&rt->bionic_sync,a,(int32_t)b);
#else
        out->handled=0;
#endif
    }
    else if(!strcmp(name,"pthread_attr_init")||!strcmp(name,"pthread_attr_destroy")||
            !strcmp(name,"pthread_attr_setdetachstate")||!strcmp(name,"pthread_attr_setstacksize")||
            !strcmp(name,"pthread_attr_setstack")||!strcmp(name,"pthread_attr_setguardsize")){
#if defined(__APPLE__)
        agr_bionic_thread_attr attr;
        if (!a || (!strcmp(name,"pthread_attr_init") ? 0 : !read_mem(rt,a,&attr,sizeof(attr))))
            { out->value=AGR_ANDROID_EINVAL; return 0; }
        int32_t rc=0;
        if (!strcmp(name,"pthread_attr_init")) rc=agr_bionic_thread_attr_init(&attr);
        else if (!strcmp(name,"pthread_attr_destroy")) rc=agr_bionic_thread_attr_destroy(&attr);
        else if (!strcmp(name,"pthread_attr_setdetachstate")) rc=agr_bionic_thread_attr_setdetachstate(&attr,(int32_t)b);
        else if (!strcmp(name,"pthread_attr_setstacksize")) rc=agr_bionic_thread_attr_setstacksize(&attr,b);
        else if (!strcmp(name,"pthread_attr_setstack")) rc=agr_bionic_thread_attr_setstack(&attr,b,c);
        else rc=agr_bionic_thread_attr_setguardsize(&attr,b);
        if (!rc && !write_mem(rt,a,&attr,sizeof(attr)))return fail(rt,"pthread_attr write");
        out->value=(uint32_t)rc;
#else
        out->handled=0;
#endif
    }
    else if(!strcmp(name,"dlopen")){if(a&&!read_cstr(rt,a,x,sizeof(x)))return fail(rt,"dlopen name");out->value=agr_dlopen_flags(rt,a?x:NULL,b);}
    else if(!strcmp(name,"dlsym")){if(!read_cstr(rt,b,x,sizeof(x)))return fail(rt,"dlsym name");out->value=agr_dlsym(rt,a,x);}
    else if(!strcmp(name,"dlclose"))out->value=agr_dlclose(rt,a);
    else if(!strcmp(name,"dlerror")){const char*e=agr_dlerror(rt);out->value=e?agr_alloc_static(rt,e,(uint32_t)strlen(e)+1,1):0;}
    else if(!strcmp(name,"android_update_LD_LIBRARY_PATH")){if(a&&read_cstr(rt,a,rt->library_path,sizeof(rt->library_path))==0)return fail(rt,"library path read");if(!a)rt->library_path[0]=0;}
    else if(!strcmp(name,"dladdr")){char object_name[256]={0},symbol_name[256]={0};uint32_t object_base=0,symbol_address=0;if(!agr_aosp_dynamic_dladdr(rt->dynamic_linker,a,object_name,sizeof(object_name),&object_base,symbol_name,sizeof(symbol_name),&symbol_address))out->value=0;else{uint32_t file_name=agr_alloc_static(rt,object_name,(uint32_t)strlen(object_name)+1,1),symbol_handle=symbol_name[0]?agr_alloc_static(rt,symbol_name,(uint32_t)strlen(symbol_name)+1,1):0;write_u32(rt,b,file_name);write_u32(rt,b+4,object_base);write_u32(rt,b+8,symbol_handle);write_u32(rt,b+12,symbol_address);out->value=1;}}
    else if(!strcmp(name,"dl_unwind_find_exidx")||!strcmp(name,"__gnu_Unwind_Find_exidx")){uint32_t count;out->value=agr_find_exidx(rt,a,&count);if(b)write_u32(rt,b,count);}
    else if(!strcmp(name,"__cxa_guard_acquire")){agr_word_state*s=word_state(rt->guards,&rt->guard_count,AGR_MAX_GUARDS,a);if(!s)return fail(rt,"guard table full");out->value=s->state==1?0:1;if(!s->state)s->state=2;}
    else if(!strcmp(name,"__cxa_guard_release")||!strcmp(name,"__cxa_guard_abort")){agr_word_state*s=word_state(rt->guards,&rt->guard_count,AGR_MAX_GUARDS,a);if(s){s->state=!strcmp(name,"__cxa_guard_release")?1:0;write_u32(rt,a,s->state);}}
    else if(!strcmp(name,"__cxa_atexit")){if(rt->atexit_count>=AGR_MAX_ATEXIT)return fail(rt,"atexit table full");rt->atexit[rt->atexit_count++]=(agr_atexit){a,b,c};}
    else if(!strcmp(name,"__cxa_finalize")){for(uint32_t i=rt->atexit_count;i>0;i--){agr_atexit item=rt->atexit[i-1];if(!a||item.dso==a){out->action=AGR_ACTION_FINALIZE;out->action_arg0=item.function;out->action_arg1=item.argument;memmove(&rt->atexit[i-1],&rt->atexit[i],(rt->atexit_count-i)*sizeof(rt->atexit[0]));rt->atexit_count--;break;}}}
    else if(!strcmp(name,"abort")||!strcmp(name,"__stack_chk_fail")||!strcmp(name,"__cxa_pure_virtual")){out->action=AGR_ACTION_ABORT;}
    else {out->handled=0;}
    return 0;
}
