#include "../../Runtime/NativeCore/agr_runtime.h"
#include <errno.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEAP_BASE 0x00100000u
#define HEAP_LIMIT 0x02000000u
typedef struct { uint8_t *bytes; uint32_t size; } memory;
typedef struct { agr_runtime *runtime; int ok; uint32_t seed; } worker_state;

static int32_t read_guest(void *opaque,uint32_t address,void *out,uint32_t size){
  memory*m=opaque;if(address>m->size||size>m->size-address)return-1;memcpy(out,m->bytes+address,size);return 0;
}
static int32_t write_guest(void *opaque,uint32_t address,const void*src,uint32_t size){
  memory*m=opaque;if(address>m->size||size>m->size-address)return-1;memcpy(m->bytes+address,src,size);return 0;
}
static uint8_t*memory_base(void*opaque){return((memory*)opaque)->bytes;}
static uint32_t random_word(uint32_t*s){*s^=*s<<13;*s^=*s>>17;*s^=*s<<5;return*s;}
static int dispatch(agr_runtime*rt,const char*name,uint32_t a,uint32_t b,uint32_t c,agr_dispatch_result*out){
  uint32_t args[4]={a,b,c,0};return agr_dispatch_system(rt,name,args,0,out);
}
static void*worker(void*opaque){worker_state*s=opaque;uint32_t slots[64]={0};s->ok=1;
  for(unsigned i=0;i<50000;i++){unsigned n=random_word(&s->seed)&63u;if(slots[n]){agr_free(s->runtime,slots[n]);slots[n]=0;}else{slots[n]=agr_malloc(s->runtime,1+random_word(&s->seed)%2048u);if(!slots[n]){s->ok=0;break;}}}
  for(unsigned i=0;i<64;i++)agr_free(s->runtime,slots[i]);return 0;
}

int main(int argc,char**argv){
  memory mem={calloc(1,HEAP_LIMIT),HEAP_LIMIT};agr_callbacks cb={0};cb.user=&mem;cb.read=read_guest;cb.write=write_guest;cb.memory_base=memory_base;
  agr_runtime*rt=agr_runtime_create(&cb,0x1000,0x10000,HEAP_BASE,HEAP_LIMIT);if(!rt)return 2;
  if(argc==2){agr_dispatch_result out={0};uint32_t p=agr_malloc(rt,32);if(!strcmp(argv[1],"double-free"))agr_free(rt,p);else p=HEAP_BASE+3;
    if(dispatch(rt,"free",p,0,0,&out)||out.action!=AGR_ACTION_ABORT)return 3;return 0;}
  int malloc0=agr_malloc(rt,0)!=0,align8=0,calloc_zero=1,overflow_null=0,overflow_errno=0;
  int realloc_null=0,grow_preserve=1,shrink_preserve=1,realloc_zero_null=0,memalign64=0,valloc_page=0,pvalloc_page=0,posix_valid=0;
  int reuse=0,coalesce=0,not_forced_zero=0,churn=1,threads_ok=1,mallinfo_balanced=0,mallinfo_call=0;
  uint32_t p=agr_malloc(rt,37);align8=p&&!(p&7u);uint32_t usable=agr_allocation_size(rt,p);agr_free(rt,p);
  p=agr_calloc(rt,33,7);if(!p)calloc_zero=0;else for(unsigned i=0;i<231;i++)if(mem.bytes[p+i])calloc_zero=0;agr_free(rt,p);
  agr_dispatch_result out={0};dispatch(rt,"__errno",0,0,0,&out);uint32_t errno_addr=out.value;int32_t zero=0;write_guest(&mem,errno_addr,&zero,4);
  p=agr_calloc(rt,0xffffffffu,8);overflow_null=p==0;int32_t error=0;read_guest(&mem,errno_addr,&error,4);overflow_errno=error==ENOMEM;
  p=agr_realloc(rt,0,73);realloc_null=p!=0;if(p)memset(mem.bytes+p,0x5a,73);uint32_t grown=agr_realloc(rt,p,513);
  if(!grown)grow_preserve=0;else for(unsigned i=0;i<73;i++)if(mem.bytes[grown+i]!=0x5a)grow_preserve=0;
  uint32_t shrunk=agr_realloc(rt,grown,29);if(!shrunk)shrink_preserve=0;else for(unsigned i=0;i<29;i++)if(mem.bytes[shrunk+i]!=0x5a)shrink_preserve=0;
  realloc_zero_null=agr_realloc(rt,shrunk,0)==0;p=agr_malloc_aligned(rt,91,64);memalign64=p&&!(p&63u);agr_free(rt,p);
  dispatch(rt,"valloc",17,0,0,&out);p=out.value;valloc_page=p&&!(p&4095u);agr_free(rt,p);
  dispatch(rt,"pvalloc",17,0,0,&out);p=out.value;pvalloc_page=p&&!(p&4095u)&&agr_allocation_size(rt,p)>=4096;agr_free(rt,p);
  uint32_t slot=0x200,sentinel=0x1234;write_guest(&mem,slot,&sentinel,4);dispatch(rt,"posix_memalign",slot,3,20,&out);int posix_bad=(int)out.value;
  dispatch(rt,"posix_memalign",slot,128,47,&out);uint32_t aligned=0;read_guest(&mem,slot,&aligned,4);posix_valid=!out.value&&aligned&&!(aligned&127u);agr_free(rt,aligned);
  uint32_t a=agr_malloc(rt,256),b=agr_malloc(rt,512),c=agr_malloc(rt,256);agr_free(rt,b);uint32_t x=agr_malloc(rt,64);reuse=x==b;agr_free(rt,x);agr_free(rt,a);agr_free(rt,c);uint32_t merged=agr_malloc(rt,1024);coalesce=merged==a;agr_free(rt,merged);
  p=agr_malloc(rt,96);memset(mem.bytes+p,0xa5,96);agr_free(rt,p);uint32_t again=agr_malloc(rt,96);if(again==p)for(unsigned i=16;i<96;i++)if(mem.bytes[again+i]){not_forced_zero=1;break;}agr_free(rt,again);
  uint32_t before[5],after[5];agr_heap_diagnostics(rt,before);for(unsigned i=0;i<1000000;i++){uint32_t q=agr_malloc(rt,1+i%97);if(!q){churn=0;break;}agr_free(rt,q);}
  pthread_t tids[4];worker_state states[4];for(unsigned i=0;i<4;i++){states[i]=(worker_state){rt,0,0x12345678u+i*0x11111111u};if(pthread_create(&tids[i],0,worker,&states[i]))threads_ok=0;}
  for(unsigned i=0;i<4;i++)if(pthread_join(tids[i],0)||!states[i].ok)threads_ok=0;agr_heap_diagnostics(rt,after);mallinfo_balanced=after[3]<=before[3]+4096;
  memset(&out,0,sizeof(out));dispatch(rt,"mallinfo",0x300,0,0,&out);
  uint32_t guest_mallinfo[10]={0};read_guest(&mem,0x300,guest_mallinfo,sizeof(guest_mallinfo));
  mallinfo_call=out.value==0x300&&guest_mallinfo[7]==after[3];
  write_guest(&mem,errno_addr,&zero,4);p=agr_malloc(rt,0xffffffffu);int oom_null=p==0;read_guest(&mem,errno_addr,&error,4);int oom_errno=error==ENOMEM;
  printf("{\"malloc0\":%d,\"align8\":%d,\"usable37\":%u,\"calloc_zero\":%d,\"overflow_null\":%d,\"overflow_errno\":%d,\"realloc_null\":%d,\"grow_preserve\":%d,\"shrink_preserve\":%d,\"realloc_zero_null\":%d,\"memalign64\":%d,\"valloc_page\":%d,\"pvalloc_page\":%d,\"posix_bad\":%d,\"posix_valid\":%d,\"reuse\":%d,\"coalesce\":%d,\"not_forced_zero\":%d,\"churn\":%d,\"threads\":%d,\"mallinfo_balanced\":%d,\"mallinfo_call\":%d,\"mallinfo_export\":1,\"usable_export\":1,\"oom_null\":%d,\"oom_errno\":%d}\n",malloc0,align8,usable,calloc_zero,overflow_null,overflow_errno,realloc_null,grow_preserve,shrink_preserve,realloc_zero_null,memalign64,valloc_page,pvalloc_page,posix_bad,posix_valid,reuse,coalesce,not_forced_zero,churn,threads_ok,mallinfo_balanced,mallinfo_call,oom_null,oom_errno);
  agr_runtime_destroy(rt);free(mem.bytes);return 0;
}
