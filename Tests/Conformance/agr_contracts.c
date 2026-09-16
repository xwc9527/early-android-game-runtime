#include "agr_contracts.h"
#include "../../Runtime/NativeCore/agr_runtime.h"
#include <stdlib.h>
#include <string.h>

/* Small deterministic cases adapted from API 19 Bionic string, pthread,
 * errno, time and linker tests. No host libc result is used as an oracle. */
typedef struct { unsigned char *bytes; uint32_t size; } test_memory;
static int32_t mem_read(void *user,uint32_t address,void *out,uint32_t size){
    test_memory *m=user; if(address>m->size||size>m->size-address)return -1;
    memcpy(out,m->bytes+address,size);return 0;
}
static int32_t mem_write(void *user,uint32_t address,const void *src,uint32_t size){
    test_memory *m=user; if(address>m->size||size>m->size-address)return -1;
    memcpy(m->bytes+address,src,size);return 0;
}
static uint32_t word(test_memory *m,uint32_t address){uint32_t v=0;memcpy(&v,m->bytes+address,4);return v;}
static uint32_t run(agr_runtime *rt,const char *name,uint32_t a,uint32_t b,uint32_t c,uint32_t d,agr_dispatch_result *out){
    uint32_t regs[4]={a,b,c,d}; return (uint32_t)agr_dispatch_system(rt,name,regs,0,out);
}
#define EMIT(ID,MOD,SOURCE,ACTUAL,EXPECTED) do { \
    uint32_t observed=(uint32_t)(ACTUAL),expected=(uint32_t)(EXPECTED); \
    if(n<capacity)results[n]=(agr_contract_result){ID,MOD,SOURCE,observed==expected,observed,expected}; n++; \
} while(0)
uint32_t agr_run_contracts(agr_contract_result *results,uint32_t capacity){
    uint32_t n=0; test_memory m={calloc(1,1u<<20),1u<<20}; if(!m.bytes)return 0;
    agr_callbacks cb={0};cb.user=&m;cb.read=mem_read;cb.write=mem_write;
    agr_runtime *rt=agr_runtime_create(&cb,0x1000,0x10000,0x20000,0xe0000);
    if(!rt){free(m.bytes);return 0;}
    agr_dispatch_result out={0};
    memcpy(m.bytes+0x100,"hello",6);
    run(rt,"strlen",0x100,0,0,0,&out);
    EMIT("libc.strlen","libc","bionic/tests/string_test.cpp",out.value,5);
    memcpy(m.bytes+0x200,"abcdefgh",9);
    run(rt,"memmove",0x202,0x200,6,0,&out);
    EMIT("libc.memmove.overlap","libc","bionic/tests/string_test.cpp",memcmp(m.bytes+0x200,"ababcdef",8)==0,1);
    unsigned char original[2048];for(uint32_t i=0;i<2048;i++)original[i]=(unsigned char)(i%251);
    memcpy(m.bytes+0x1000,original,2048);
    run(rt,"memmove",0x1001,0x1000,2048,0,&out);
    EMIT("libc.memmove.chunk_overlap","libc","bionic/tests/string_test.cpp",memcmp(m.bytes+0x1001,original,2048)==0,1);
    run(rt,"memchr",0x200,'d',8,0,&out);
    EMIT("libc.memchr.pointer","libc","bionic/tests/string_test.cpp",out.value,0x205);
    run(rt,"__errno",0,0,0,0,&out);uint32_t errno_main=out.value;
    uint32_t other=agr_create_thread_state(rt);agr_set_current_thread(rt,other);
    run(rt,"__errno",0,0,0,0,&out);uint32_t errno_other=out.value;
    EMIT("tls.errno.isolation","pthread_tls","bionic/libc/bionic/__errno.c",errno_main!=errno_other,1);
    agr_set_current_thread(rt,1);
    run(rt,"pthread_key_create",0x300,0,0,0,&out);uint32_t key=word(&m,0x300);
    run(rt,"pthread_setspecific",key,0x12345678,0,0,&out);
    agr_set_current_thread(rt,other);run(rt,"pthread_getspecific",key,0,0,0,&out);
    EMIT("tls.key.isolation","pthread_tls","bionic/tests/pthread_test.cpp",out.value,0);
    agr_set_current_thread(rt,1);run(rt,"pthread_getspecific",key,0,0,0,&out);
    EMIT("tls.key.recover","pthread_tls","bionic/tests/pthread_test.cpp",out.value,0x12345678);
    run(rt,"pthread_mutex_init",0x400,0,0,0,&out);
    run(rt,"pthread_mutex_lock",0x400,0,0,0,&out);
    EMIT("pthread.mutex.owner","pthread_tls","bionic/tests/pthread_test.cpp",agr_mutex_owner(rt,0x400),1);
    run(rt,"pthread_mutex_unlock",0x400,0,0,0,&out);
    EMIT("pthread.mutex.release","pthread_tls","bionic/tests/pthread_test.cpp",agr_mutex_owner(rt,0x400),0);
    memcpy(m.bytes+0x500,"missing.so",11);
    run(rt,"dlopen",0x500,0,0,0,&out);
    const char *first=agr_dlerror(rt),*second=agr_dlerror(rt);
    EMIT("libdl.dlerror.clear","linker_libdl","bionic/tests/dlfcn_test.cpp",first!=NULL&&second==NULL,1);
    run(rt,"clock_gettime",0,0x600,0,0,&out);uint32_t sec1=word(&m,0x600),ns1=word(&m,0x604);
    run(rt,"clock_gettime",0,0x608,0,0,&out);uint32_t sec2=word(&m,0x608),ns2=word(&m,0x60c);
    EMIT("time.clock.monotonic","time","bionic/tests/pthread_test.cpp + clock_gettime.S",sec2>sec1||(sec2==sec1&&ns2>ns1),1);
    EMIT("time.clock.nsec.range","time","bionic/tests/pthread_test.cpp + clock_gettime.S",ns2<1000000000u,1);
    agr_runtime_destroy(rt);free(m.bytes);return n<capacity?n:capacity;
}
