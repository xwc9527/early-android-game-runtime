#include "../../Runtime/NativeCore/agr_runtime.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEAP_BASE 0x00100000u
#define HEAP_LIMIT 0x00800000u
#define CHECK(expr) do { if (!(expr)) { fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #expr); return 1; } } while (0)

typedef struct { uint8_t *bytes; uint32_t size; } memory;
static int32_t read_guest(void *context, uint32_t address, void *out, uint32_t size) {
    memory *m = context;
    if (address > m->size || size > m->size - address) return -1;
    memcpy(out, m->bytes + address, size);
    return 0;
}
static int32_t write_guest(void *context, uint32_t address, const void *src, uint32_t size) {
    memory *m = context;
    if (address > m->size || size > m->size - address) return -1;
    memcpy(m->bytes + address, src, size);
    return 0;
}
static uint8_t *memory_base(void *context) { return ((memory *)context)->bytes; }
static agr_runtime *make_runtime(memory *m) {
    agr_callbacks cb = {0};
    cb.user = m; cb.read = read_guest; cb.write = write_guest; cb.memory_base = memory_base;
    return agr_runtime_create(&cb, 0x1000, 0x10000, HEAP_BASE, HEAP_LIMIT);
}
static uint32_t random_word(uint32_t *state) {
    *state ^= *state << 13; *state ^= *state >> 17; *state ^= *state << 5;
    return *state;
}
static int dispatch(agr_runtime *rt, const char *name,
                    uint32_t a, uint32_t b, uint32_t c, uint32_t d,
                    agr_dispatch_result *out) {
    uint32_t args[4] = {a,b,c,d};
    return agr_dispatch_system(rt,name,args,0,out);
}

int main(void) {
    memory m = {calloc(1, HEAP_LIMIT), HEAP_LIMIT};
    CHECK(m.bytes != NULL);
    agr_runtime *rt = make_runtime(&m);
    CHECK(rt != NULL);
    uint32_t stats[5] = {0};

    /* Fixed live set, unbounded history: the old 8192-entry table fails here. */
    for (uint32_t i = 0; i < 1000000; ++i) {
        uint32_t p = agr_malloc(rt, 1 + i % 97);
        CHECK(p >= HEAP_BASE && (p & 7u) == 0);
        agr_free(rt,p);
    }
    agr_heap_diagnostics(rt,stats);
    CHECK(stats[2] <= 2 && stats[3] == 0 && stats[4] == 0);
    printf("PASS 1M malloc/free; metadata=%u live=%u\n",stats[2],stats[3]);

    /* A free block is split and then coalesced with both neighbours. */
    uint32_t a=agr_malloc(rt,256), b=agr_malloc(rt,512), c=agr_malloc(rt,256);
    CHECK(a && b && c && a < b && b < c);
    agr_free(rt,b);
    uint32_t x=agr_malloc(rt,64), y=agr_malloc(rt,64);
    CHECK(x==b && y>x && y<c);
    agr_free(rt,x); agr_free(rt,y); agr_free(rt,a); agr_free(rt,c);
    uint32_t merged=agr_malloc(rt,1024);
    CHECK(merged==a);
    agr_free(rt,merged);

    uint32_t p=agr_malloc(rt,100);
    CHECK(p != 0);
    memset(m.bytes+p,0x5a,100);
    uint32_t grown=agr_realloc(rt,p,300);
    CHECK(grown != 0);
    for(uint32_t i=0;i<100;i++)CHECK(m.bytes[grown+i]==0x5a);
    uint32_t shrunk=agr_realloc(rt,grown,40);
    CHECK(shrunk==grown);
    for(uint32_t i=0;i<40;i++)CHECK(m.bytes[shrunk+i]==0x5a);
    CHECK(agr_allocation_size(rt,shrunk)==40);
    CHECK(agr_realloc(rt,shrunk,0)==0);
    CHECK(agr_allocation_size(rt,shrunk)==0);

    uint32_t guard=agr_malloc(rt,64), moving=agr_malloc(rt,64), blocker=agr_malloc(rt,64);
    CHECK(guard && moving && blocker);
    memset(m.bytes+moving,0xa5,64);
    uint32_t moved=agr_realloc(rt,moving,4096);
    CHECK(moved && moved!=moving);
    for(uint32_t i=0;i<64;i++)CHECK(m.bytes[moved+i]==0xa5);
    CHECK(agr_allocation_size(rt,moving)==0);
    agr_free(rt,guard);agr_free(rt,blocker);agr_free(rt,moved);

    agr_dispatch_result out={0};
    CHECK(dispatch(rt,"calloc",32,9,0,0,&out)==0 && out.handled && out.value);
    for(uint32_t i=0;i<288;i++)CHECK(m.bytes[out.value+i]==0);
    agr_free(rt,out.value);
    CHECK(dispatch(rt,"calloc",0xffffffffu,8,0,0,&out)==0 && out.handled && out.value==0);
    uint32_t zero_size=agr_malloc(rt,0);CHECK(zero_size!=0);agr_free(rt,zero_size);
    uint32_t aligned=agr_malloc_aligned(rt,35,64);
    CHECK(aligned && (aligned & 63u)==0);
    agr_free(rt,aligned);
    CHECK(dispatch(rt,"posix_memalign",0x200,64,35,0,&out)==0 && out.handled && out.value==0);
    uint32_t aligned_dispatch=0;memcpy(&aligned_dispatch,m.bytes+0x200,4);
    CHECK(aligned_dispatch && (aligned_dispatch & 63u)==0);
    agr_free(rt,aligned_dispatch);

    /* Invalid/double free and invalid realloc may not destroy a live block. */
    uint32_t valid=agr_malloc(rt,32);
    CHECK(valid);
    agr_free(rt,valid+1);agr_free(rt,valid+128);
    CHECK(agr_allocation_size(rt,valid)==32);
    CHECK(agr_realloc(rt,valid+1,64)==0);
    CHECK(agr_allocation_size(rt,valid)==32);
    agr_free(rt,valid);agr_free(rt,valid);
    CHECK(agr_allocation_size(rt,valid)==0);

    /* Repeated random-size allocation and release with content verification. */
    uint32_t slots[256]={0},sizes[256]={0},seed=0x7ab91d43u;
    for(uint32_t i=0;i<200000;i++) {
        uint32_t idx=random_word(&seed)&255u;
        if(slots[idx]) {
            CHECK(m.bytes[slots[idx]]==(uint8_t)idx);
            CHECK(m.bytes[slots[idx]+sizes[idx]-1]==(uint8_t)idx);
            agr_free(rt,slots[idx]);slots[idx]=0;
        } else {
            uint32_t size=1+(random_word(&seed)%4096u);
            uint32_t addr=agr_malloc(rt,size);CHECK(addr);
            slots[idx]=addr;sizes[idx]=size;
            m.bytes[addr]=(uint8_t)idx;m.bytes[addr+size-1]=(uint8_t)idx;
        }
    }
    for(uint32_t i=0;i<256;i++)if(slots[i])agr_free(rt,slots[i]);
    agr_heap_diagnostics(rt,stats);
    CHECK(stats[3]==0 && stats[2]<=2);
    uint32_t large=agr_malloc(rt,HEAP_LIMIT-HEAP_BASE-4096u);
    CHECK(large==HEAP_BASE);
    CHECK(agr_malloc(rt,HEAP_LIMIT)==0);
    agr_free(rt,large);
    printf("PASS split/coalesce, realloc, calloc, alignment, invalid pointers, random fragmentation; metadata=%u\n",stats[2]);
    agr_runtime_destroy(rt);free(m.bytes);
    return 0;
}
