/*
 * Host-native port of Android 4.4.4_r2 Bionic dlmalloc.
 *
 * The algorithm below is the pinned upstream dlmalloc 2.8.6 source. Its
 * persistent pointers and size fields are adapted to the API19 ARM32 layout:
 * every pointer stored in guest allocator state/chunks is a 32-bit guest
 * address. Host pointers exist only transiently while this translation unit is
 * executing and are derived from the interpreter's stable guest-memory base.
 * Linux mmap/sbrk and pthread lock boundaries are replaced by AGR callbacks.
 */
#include "agr_bionic_allocator.h"

#include <errno.h>
#include <setjmp.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <mutex>

typedef uint32_t agr_dl_size_t;
typedef int32_t agr_dl_ptrdiff_t;
typedef uint32_t agr_guest_address_t;

struct agr_bionic_allocator {
    agr_bionic_mmap_context *mmap_context;
    uint8_t *memory_base;
    uint32_t heap_base, heap_limit;
    uint32_t state_address, state_size;
    uint32_t brk_base, current_brk, mapped_brk;
    void *errno_opaque;
    agr_allocator_errno_fn set_errno;
    std::recursive_mutex lock;
    alignas(16) unsigned char params[64];
    uint32_t fatal;
};

static thread_local agr_bionic_allocator *agr_dl_context;
static thread_local jmp_buf *agr_dl_fatal_target;

static uint8_t *agr_dl_guest_base(void) { return agr_dl_context->memory_base; }
static uint32_t agr_dl_host_to_guest(const void *pointer) {
    if (!pointer) return 0;
    uintptr_t base=(uintptr_t)agr_dl_guest_base(), value=(uintptr_t)pointer;
    if(value>=base&&value-base<=UINT32_MAX)return (uint32_t)(value-base);
    return value<=UINT32_MAX?(uint32_t)value:0;
}
static void *agr_dl_align_host_pointer(void *pointer,uint32_t alignment) {
    uint32_t address=agr_dl_host_to_guest(pointer);
    address=(address+alignment-1u)&~(alignment-1u);
    return agr_dl_guest_base()+address;
}

template <typename T> struct agr_guest_ptr {
    uint32_t address;
    agr_guest_ptr() : address(0) {}
    agr_guest_ptr(int value) : address(value ? (uint32_t)value : 0) {}
    agr_guest_ptr(uint32_t value) : address(value) {}
    template <typename U> agr_guest_ptr(U *pointer) : address(agr_dl_host_to_guest(pointer)) {}
    template <typename U> agr_guest_ptr(const agr_guest_ptr<U>& other) : address(other.address) {}
    T *get() const { return address ? reinterpret_cast<T *>(agr_dl_guest_base()+address) : nullptr; }
    operator T *() const { return get(); }
    T *operator->() const { return get(); }
    agr_guest_ptr& operator=(int value) { address=value?(uint32_t)value:0; return *this; }
    agr_guest_ptr& operator=(uint32_t value) { address=value; return *this; }
    template <typename U> agr_guest_ptr& operator=(U *pointer) { address=agr_dl_host_to_guest(pointer); return *this; }
    template <typename U> agr_guest_ptr& operator=(const agr_guest_ptr<U>& other) { address=other.address; return *this; }
    explicit operator bool() const { return address!=0; }
};
template <typename T, typename U> static inline bool operator==(agr_guest_ptr<T> a, agr_guest_ptr<U> b){return a.address==b.address;}
template <typename T> static inline bool operator==(agr_guest_ptr<T> a, int b){return b==0 && a.address==0;}
template <typename T> static inline bool operator==(int a, agr_guest_ptr<T> b){return b==a;}
template <typename T, typename U> static inline bool operator!=(agr_guest_ptr<T> a, agr_guest_ptr<U> b){return !(a==b);}
template <typename T> static inline bool operator!=(agr_guest_ptr<T> a, int b){return !(a==b);}
template <typename T> static inline bool operator!=(int a, agr_guest_ptr<T> b){return !(b==a);}
template <typename T, typename U> static inline bool operator<(agr_guest_ptr<T> a, agr_guest_ptr<U> b){return a.address<b.address;}
template <typename T, typename U> static inline bool operator<=(agr_guest_ptr<T> a, agr_guest_ptr<U> b){return a.address<=b.address;}
template <typename T, typename U> static inline bool operator>(agr_guest_ptr<T> a, agr_guest_ptr<U> b){return a.address>b.address;}
template <typename T, typename U> static inline bool operator>=(agr_guest_ptr<T> a, agr_guest_ptr<U> b){return a.address>=b.address;}

struct malloc_params;
static struct malloc_params *agr_dl_current_params(void) {
    return reinterpret_cast<struct malloc_params *>(agr_dl_context->params);
}
static uint32_t agr_dl_current_gm_address(void) { return agr_dl_context->state_address; }
static void agr_dl_set_failure(void) {
    if (agr_dl_context->set_errno) agr_dl_context->set_errno(agr_dl_context->errno_opaque, ENOMEM);
}
[[noreturn]] static void agr_dl_fail(uint32_t kind) {
    agr_dl_context->fatal=kind;
    if (agr_dl_fatal_target) longjmp(*agr_dl_fatal_target,1);
    abort();
}
static int agr_dl_lock(uint32_t *) { agr_dl_context->lock.lock(); return 0; }
static int agr_dl_unlock(uint32_t *) { agr_dl_context->lock.unlock(); return 0; }
static int agr_dl_try_lock(uint32_t *) { return agr_dl_context->lock.try_lock(); }
static int agr_dl_init_lock(uint32_t *word) { *word=0; return 0; }
static int agr_dl_destroy_lock(uint32_t *) { return 0; }
static void *agr_dl_mmap(agr_dl_size_t size);
static int agr_dl_munmap(void *address, agr_dl_size_t size);
static void *agr_dl_morecore(agr_dl_ptrdiff_t increment);
static int agr_dl_getpagesize(void) { return 4096; }

#define ANDROID_CHANGES 1
#define HAVE_GETPAGESIZE 1
#define getpagesize agr_dl_getpagesize
#define MALLOC_ALIGNMENT 8U
#define MALLOC_INSPECT_ALL 1
#define MSPACES 0
#define REALLOC_ZERO_BYTES_FREES 1
#define USE_DL_PREFIX 1
#define USE_LOCKS 2
#define USE_RECURSIVE_LOCKS 0
#define USE_SPIN_LOCKS 0
#define DEFAULT_MMAP_THRESHOLD (64U * 1024U)
#define MLOCK_T uint32_t
#define INITIAL_LOCK(lk) agr_dl_init_lock(lk)
#define DESTROY_LOCK(lk) agr_dl_destroy_lock(lk)
#define ACQUIRE_LOCK(lk) agr_dl_lock(lk)
#define RELEASE_LOCK(lk) agr_dl_unlock(lk)
#define TRY_LOCK(lk) agr_dl_try_lock(lk)
static MLOCK_T malloc_global_mutex=0;
#define MMAP(s) agr_dl_mmap(s)
#define DIRECT_MMAP(s) agr_dl_mmap(s)
#define MUNMAP(a,s) agr_dl_munmap(a,s)
#define MORECORE(s) agr_dl_morecore(s)
#define HAVE_MORECORE 1
#define HAVE_MMAP 1
#define HAVE_MREMAP 0
#define MALLOC_FAILURE_ACTION agr_dl_set_failure()
#define CORRUPTION_ERROR_ACTION(m) agr_dl_fail(AGR_ALLOCATOR_FATAL_CORRUPTION)
#define USAGE_ERROR_ACTION(m,p) agr_dl_fail(AGR_ALLOCATOR_FATAL_USAGE)
#define agr_dl_current_gm() mstate(agr_dl_current_gm_address())

#include "agr_api19_dlmalloc_source.inc"

static_assert(sizeof(agr_guest_ptr<void>)==4,"guest pointer must remain ARM32");
static_assert(sizeof(mchunk)==16,"API19 malloc chunk layout drifted");
static_assert(sizeof(tchunk)==32,"API19 tree chunk layout drifted");
static_assert(sizeof(msegment)==16,"API19 segment layout drifted");

static uint32_t round_page(uint32_t value) { return (value+4095u)&~4095u; }
static bool range_is_free(const agr_bionic_allocator *a,uint32_t address,uint32_t size) {
    uint64_t end=(uint64_t)address+size;
    if(end>UINT32_MAX+1ull)return false;
    const agr_guest_vma_space *vma=a->mmap_context->vma;
    for(size_t i=0;i<vma->count;i++)
        if((uint64_t)address<vma->regions[i].end&&end>vma->regions[i].start)return false;
    return true;
}
static void bind(agr_bionic_allocator *allocator) { agr_dl_context=allocator; }
static void *host_pointer(uint32_t address) {
    return address?agr_dl_context->memory_base+address:nullptr;
}
static uint32_t guest_pointer(const void *pointer) { return agr_dl_host_to_guest(pointer); }

static void *agr_dl_mmap(agr_dl_size_t requested) {
    agr_bionic_allocator *a=agr_dl_context;
    uint32_t size=round_page(requested);
    if(!size||size> a->heap_limit-a->heap_base)return (void*)(uintptr_t)UINT32_MAX;
    uint32_t candidate=a->heap_limit;
    while(candidate>=a->brk_base+size){
        candidate=(candidate-size)&~4095u;
        if(candidate<a->mapped_brk)break;
        if(!range_is_free(a,candidate,size)){candidate-=4096u;continue;}
        uint32_t mapped=0;int32_t error=0;
        if(!agr_bionic_mmap(a->mmap_context,candidate,size,AGR_PROT_READ|AGR_PROT_WRITE,
                            AGR_MAP_PRIVATE|AGR_MAP_ANONYMOUS|AGR_MAP_FIXED,-1,0,&mapped,&error)){
            return host_pointer(mapped);
        }
        candidate-=4096u;
    }
    agr_dl_set_failure();
    return (void*)(uintptr_t)UINT32_MAX;
}
static int agr_dl_munmap(void *pointer, agr_dl_size_t size) {
    uint32_t address=guest_pointer(pointer);int32_t error=0;
    return address?agr_bionic_munmap(agr_dl_context->mmap_context,address,size,&error):-1;
}
static void *agr_dl_morecore(agr_dl_ptrdiff_t increment) {
    agr_bionic_allocator *a=agr_dl_context;
    uint32_t old=a->current_brk;
    if(!increment)return host_pointer(old);
    int64_t next=(int64_t)old+increment;
    if(next<(int64_t)a->brk_base||next>(int64_t)a->heap_limit){agr_dl_set_failure();return (void*)(uintptr_t)UINT32_MAX;}
    uint32_t new_brk=(uint32_t)next;
    uint32_t needed=round_page(new_brk);
    if(needed>a->mapped_brk){
        if(!range_is_free(a,a->mapped_brk,needed-a->mapped_brk)){agr_dl_set_failure();return (void*)(uintptr_t)UINT32_MAX;}
        uint32_t mapped=0;int32_t error=0;
        if(agr_bionic_mmap(a->mmap_context,a->mapped_brk,needed-a->mapped_brk,
                           AGR_PROT_READ|AGR_PROT_WRITE,
                           AGR_MAP_PRIVATE|AGR_MAP_ANONYMOUS|AGR_MAP_FIXED,-1,0,&mapped,&error)){
            agr_dl_set_failure();return (void*)(uintptr_t)UINT32_MAX;
        }
        a->mapped_brk=needed;
    } else if(needed<a->mapped_brk){
        int32_t error=0;
        if(agr_bionic_munmap(a->mmap_context,needed,a->mapped_brk-needed,&error))return (void*)(uintptr_t)UINT32_MAX;
        a->mapped_brk=needed;
    }
    a->current_brk=new_brk;
    return host_pointer(old);
}

template <typename F, typename R> static R invoke(agr_bionic_allocator *a,R failure,F function){
    if(!a)return failure;bind(a);a->fatal=0;jmp_buf target;agr_dl_fatal_target=&target;
    if(setjmp(target)){agr_dl_fatal_target=nullptr;return failure;}
    R result=function();agr_dl_fatal_target=nullptr;return result;
}

extern "C" agr_bionic_allocator *agr_bionic_allocator_create(
    agr_bionic_mmap_context *mmap_context,uint8_t *memory,uint32_t heap_base,
    uint32_t heap_limit,void *errno_opaque,agr_allocator_errno_fn set_errno){
    if(!mmap_context||!memory||heap_base>=heap_limit||(heap_base&4095u)||(heap_limit&4095u))return nullptr;
    agr_bionic_allocator *a=new agr_bionic_allocator{};a->mmap_context=mmap_context;a->memory_base=memory;
    a->heap_base=heap_base;a->heap_limit=heap_limit;a->errno_opaque=errno_opaque;a->set_errno=set_errno;
    a->state_address=heap_base;a->state_size=round_page((uint32_t)sizeof(malloc_state));
    a->brk_base=a->current_brk=a->mapped_brk=heap_base+a->state_size;
    bind(a);uint32_t mapped=0;int32_t error=0;
    if(agr_bionic_mmap(mmap_context,a->state_address,a->state_size,AGR_PROT_READ|AGR_PROT_WRITE,
                       AGR_MAP_PRIVATE|AGR_MAP_ANONYMOUS|AGR_MAP_FIXED,-1,0,&mapped,&error)){
        delete a;return nullptr;
    }
    memset(memory+a->state_address,0,a->state_size);memset(a->params,0,sizeof(a->params));return a;
}
extern "C" void agr_bionic_allocator_destroy(agr_bionic_allocator *a){
    if(!a)return;bind(a);int32_t error=0;
    if(a->mapped_brk>a->brk_base)agr_bionic_munmap(a->mmap_context,a->brk_base,a->mapped_brk-a->brk_base,&error);
    agr_bionic_munmap(a->mmap_context,a->state_address,a->state_size,&error);delete a;
}
extern "C" uint32_t agr_bionic_allocator_malloc(agr_bionic_allocator*a,uint32_t n){return invoke(a,0u,[&]{return guest_pointer(dlmalloc(n));});}
extern "C" uint32_t agr_bionic_allocator_calloc(agr_bionic_allocator*a,uint32_t n,uint32_t s){return invoke(a,0u,[&]{return guest_pointer(dlcalloc(n,s));});}
extern "C" uint32_t agr_bionic_allocator_realloc(agr_bionic_allocator*a,uint32_t p,uint32_t n){return invoke(a,0u,[&]{return guest_pointer(dlrealloc(host_pointer(p),n));});}
extern "C" void agr_bionic_allocator_free(agr_bionic_allocator*a,uint32_t p){(void)invoke(a,0,[&]{dlfree(host_pointer(p));return 0;});}
extern "C" uint32_t agr_bionic_allocator_memalign(agr_bionic_allocator*a,uint32_t al,uint32_t n){return invoke(a,0u,[&]{return guest_pointer(dlmemalign(al,n));});}
extern "C" int32_t agr_bionic_allocator_posix_memalign(agr_bionic_allocator*a,uint32_t*out,uint32_t al,uint32_t n){
    if(!out)return EINVAL;return invoke(a,EINVAL,[&]{void*p=nullptr;int rc=dlposix_memalign(&p,al,n);*out=guest_pointer(p);return rc;});
}
extern "C" uint32_t agr_bionic_allocator_usable_size(agr_bionic_allocator*a,uint32_t p){return invoke(a,0u,[&]{return dlmalloc_usable_size(host_pointer(p));});}
extern "C" int32_t agr_bionic_allocator_mallinfo(agr_bionic_allocator*a,agr_allocator_mallinfo*out){
    if(!out)return EINVAL;return invoke(a,-1,[&]{struct mallinfo m=dlmallinfo();memcpy(out,&m,sizeof(*out));return 0;});
}
extern "C" int32_t agr_bionic_allocator_mallopt(agr_bionic_allocator*a,int32_t p,int32_t v){return invoke(a,0,[&]{return dlmallopt(p,v);});}
extern "C" uint32_t agr_bionic_allocator_fatal(const agr_bionic_allocator*a){return a?a->fatal:0;}
extern "C" void agr_bionic_allocator_clear_fatal(agr_bionic_allocator*a){if(a)a->fatal=0;}
