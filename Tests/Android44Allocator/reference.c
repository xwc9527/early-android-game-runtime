#include <dlfcn.h>
#include <errno.h>
#include <malloc.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { int ok; uint32_t seed; } worker_state;

static uint32_t random_word(uint32_t *state) {
  *state ^= *state << 13; *state ^= *state >> 17; *state ^= *state << 5;
  return *state;
}

static void *worker(void *opaque) {
  worker_state *state=(worker_state *)opaque; void *slots[64]={0};
  size_t sizes[64]={0}; state->ok=1;
  for (unsigned i=0;i<50000;i++) {
    unsigned slot=random_word(&state->seed)&63u;
    if (slots[slot]) { free(slots[slot]); slots[slot]=0; }
    else {
      size_t size=1u+(random_word(&state->seed)%2048u);
      slots[slot]=malloc(size); sizes[slot]=size;
      if (!slots[slot]) { state->ok=0; break; }
      ((unsigned char *)slots[slot])[0]=(unsigned char)slot;
      ((unsigned char *)slots[slot])[sizes[slot]-1]=(unsigned char)slot;
    }
  }
  for (unsigned i=0;i<64;i++) free(slots[i]);
  return 0;
}

int main(int argc,char **argv) {
  if (argc==2 && !strcmp(argv[1],"invalid-free")) {
    void *p=malloc(32); free((char *)p+1); return 99;
  }
  if (argc==2 && !strcmp(argv[1],"double-free")) {
    void *p=malloc(32); free(p); free(p); return 99;
  }

  int malloc0=malloc(0)!=0,align8=0,calloc_zero=1,overflow_null=0;
  int overflow_errno=0,realloc_null=0,grow_preserve=1,shrink_preserve=1;
  int realloc_zero_null=0,memalign64=0,valloc_page=0,pvalloc_page=0,posix_valid=0,reuse=0,coalesce=0;
  int not_forced_zero=0,churn=1,threads_ok=1,mallinfo_balanced=0,mallinfo_call=1;
  int mallinfo_export=dlsym(RTLD_DEFAULT,"mallinfo")!=0;
  int usable_export=dlsym(RTLD_DEFAULT,"malloc_usable_size")!=0;
  void *p=malloc(37); align8=p&&(((uintptr_t)p&7u)==0);
  size_t usable=p?malloc_usable_size(p):0; free(p);

  p=calloc(33,7); if(!p)calloc_zero=0; else {
    for(unsigned i=0;i<231;i++)if(((unsigned char*)p)[i])calloc_zero=0;
  } free(p);
  errno=0; volatile size_t huge=(size_t)-1;
  p=calloc(huge,8); overflow_null=p==0; overflow_errno=errno==ENOMEM; free(p);

  p=realloc(0,73); realloc_null=p!=0; if(p)memset(p,0x5a,73);
  void *grown=realloc(p,513); if(!grown)grow_preserve=0; else
    for(unsigned i=0;i<73;i++)if(((unsigned char*)grown)[i]!=0x5a)grow_preserve=0;
  void *shrunk=realloc(grown,29); if(!shrunk)shrink_preserve=0; else
    for(unsigned i=0;i<29;i++)if(((unsigned char*)shrunk)[i]!=0x5a)shrink_preserve=0;
  realloc_zero_null=realloc(shrunk,0)==0;

  p=memalign(64,91); memalign64=p&&(((uintptr_t)p&63u)==0); free(p);
  p=valloc(17); valloc_page=p&&(((uintptr_t)p&4095u)==0); free(p);
  p=pvalloc(17); pvalloc_page=p&&(((uintptr_t)p&4095u)==0)&&malloc_usable_size(p)>=4096; free(p);
  void *aligned=(void *)(uintptr_t)0x1234; int posix_bad=posix_memalign(&aligned,3,20);
  aligned=0; int posix_good=posix_memalign(&aligned,128,47);
  posix_valid=posix_good==0&&aligned&&(((uintptr_t)aligned&127u)==0); free(aligned);

  void *a=malloc(256),*b=malloc(512),*c=malloc(256);
  uintptr_t a_address=(uintptr_t)a,b_address=(uintptr_t)b; free(b);
  void *x=malloc(64); reuse=(uintptr_t)x==b_address; free(x); free(a); free(c);
  void *merged=malloc(1024); coalesce=(uintptr_t)merged==a_address; free(merged);

  p=malloc(96); memset(p,0xa5,96); free(p); void *again=malloc(96);
  if(again==p)for(unsigned i=16;i<96;i++)if(((unsigned char*)again)[i]){not_forced_zero=1;break;}
  free(again);

  struct mallinfo before=mallinfo();
  for(unsigned i=0;i<1000000;i++){void*q=malloc(1+i%97);if(!q){churn=0;break;}free(q);}
  pthread_t tids[4]; worker_state states[4];
  for(unsigned i=0;i<4;i++){states[i].seed=0x12345678u+i*0x11111111u;states[i].ok=0;if(pthread_create(&tids[i],0,worker,&states[i]))threads_ok=0;}
  for(unsigned i=0;i<4;i++){if(pthread_join(tids[i],0)||!states[i].ok)threads_ok=0;}
  struct mallinfo after=mallinfo(); mallinfo_balanced=after.uordblks<=before.uordblks+4096;

  errno=0; p=malloc(huge); int oom_null=p==0,oom_errno=errno==ENOMEM; free(p);
  printf("{\"malloc0\":%d,\"align8\":%d,\"usable37\":%u,\"calloc_zero\":%d,"
         "\"overflow_null\":%d,\"overflow_errno\":%d,\"realloc_null\":%d,"
         "\"grow_preserve\":%d,\"shrink_preserve\":%d,\"realloc_zero_null\":%d,"
         "\"memalign64\":%d,\"valloc_page\":%d,\"pvalloc_page\":%d,\"posix_bad\":%d,\"posix_valid\":%d,\"reuse\":%d,"
         "\"coalesce\":%d,\"not_forced_zero\":%d,\"churn\":%d,\"threads\":%d,"
         "\"mallinfo_balanced\":%d,\"mallinfo_call\":%d,\"mallinfo_export\":%d,\"usable_export\":%d,"
         "\"oom_null\":%d,\"oom_errno\":%d}\n",
         malloc0,align8,(unsigned)usable,calloc_zero,overflow_null,overflow_errno,
         realloc_null,grow_preserve,shrink_preserve,realloc_zero_null,memalign64,valloc_page,pvalloc_page,posix_bad,
         posix_valid,reuse,coalesce,not_forced_zero,churn,threads_ok,mallinfo_balanced,mallinfo_call,
         mallinfo_export,usable_export,oom_null,oom_errno);
  return 0;
}
