#include "../../Runtime/NativeCore/agr_runtime.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { STOP_ADDR=0x000fd000, STACK_TOP=0x000fc000 };
extern void* arm_interp_create(void);
extern void arm_interp_destroy(void*);
extern int32_t arm_interp_write(void*,uint32_t,const uint8_t*,uint32_t);
extern int32_t arm_interp_load(void*,uint32_t,const uint8_t*,uint32_t);
extern int32_t arm_interp_read(void*,uint32_t,uint8_t*,uint32_t);
extern int32_t arm_interp_set_page_permissions(void*,uint32_t,uint32_t,uint32_t);
extern int32_t arm_interp_set_reg(void*,uint32_t,uint32_t);
extern uint32_t arm_interp_get_reg(void*,uint32_t);
extern int32_t arm_interp_set_cpsr(void*,uint32_t);
extern uint32_t arm_interp_get_cpsr(void*);
extern int32_t arm_interp_run(void*,uint64_t*,uint32_t*);
typedef struct harness { void*cpu; } harness;
static int32_t mem_read(void*o,uint32_t a,void*p,uint32_t n){return arm_interp_read(((harness*)o)->cpu,a,(uint8_t*)p,n);}
static int32_t mem_write(void*o,uint32_t a,const void*p,uint32_t n){return arm_interp_write(((harness*)o)->cpu,a,(const uint8_t*)p,n);}
static int32_t mem_load(void*o,uint32_t a,const void*p,uint32_t n){return arm_interp_load(((harness*)o)->cpu,a,(const uint8_t*)p,n);}
static int32_t mem_protect(void*o,uint32_t a,uint32_t n,uint32_t p){return arm_interp_set_page_permissions(((harness*)o)->cpu,a,n,p);}
static uint32_t host_import(void*o,const char*n,uint32_t t){uint32_t h=2166136261u;(void)o;(void)t;if(strstr(n,"_entry")||strstr(n,"_ctor")||strstr(n,"_fini")||strstr(n,"_dt_init")||strstr(n,"_dt_fini")||!strcmp(n,"c_func")||!strcmp(n,"b_func")||!strcmp(n,"c_data")||!strcmp(n,"a_data_pointer")||!strcmp(n,"a_weak_pointer")||!strcmp(n,"a_weak_value")||!strcmp(n,"optional_value")||!strcmp(n,"trace_event")||!strcmp(n,"trace_reset")||!strcmp(n,"trace_events")||!strcmp(n,"definitely_missing_symbol")||!strcmp(n,"missing_dependency"))return 0;while(*n){h^=(unsigned char)*n++;h*=16777619u;}return 0x07000000u|(h&0x000ffffcu);}
static void*read_file(const char*path,uint32_t*size){FILE*f=fopen(path,"rb");long n;void*p;if(!f)return NULL;fseek(f,0,SEEK_END);n=ftell(f);fseek(f,0,SEEK_SET);p=malloc((size_t)n);if(!p||fread(p,1,(size_t)n,f)!=(size_t)n){free(p);p=NULL;n=0;}fclose(f);*size=(uint32_t)n;return p;}
static int reg(agr_runtime*r,const char*name,const char*path,uint32_t base){uint32_t n=0;void*p=read_file(path,&n);int rc=p?agr_register_elf_source(r,name,p,n,base):-1;free(p);return rc;}
static const char*kind(const char*e){if(!e)return "none";if(strstr(e,"not found")||strstr(e,"could not load"))return "missing_dependency";if(strstr(e,"cannot locate")||strstr(e,"undefined symbol"))return "missing_symbol";return "other";}
static int32_t call_guest(harness*h,uint32_t target,const uint32_t*args,uint32_t count,int32_t*result){
  uint32_t stop=0xef000000u,cpsr=arm_interp_get_cpsr(h->cpu);uint64_t budget=1000000;uint32_t svc=0;
  if(arm_interp_load(h->cpu,STOP_ADDR,(const uint8_t*)&stop,4)||arm_interp_set_page_permissions(h->cpu,STOP_ADDR,0x1000,5)||arm_interp_set_page_permissions(h->cpu,STACK_TOP-0x10000,0x10000,3))return -1;
  for(uint32_t i=0;i<4;i++)arm_interp_set_reg(h->cpu,i,i<count?args[i]:0);
  for(uint32_t i=4;i<count;i++)if(arm_interp_write(h->cpu,STACK_TOP+(i-4)*4,(const uint8_t*)&args[i],4))return -1;
  arm_interp_set_cpsr(h->cpu,(target&1)?(cpsr|0x20u):(cpsr&~0x20u));arm_interp_set_reg(h->cpu,13,STACK_TOP);arm_interp_set_reg(h->cpu,14,STOP_ADDR);arm_interp_set_reg(h->cpu,15,target&~1u);
  if(arm_interp_run(h->cpu,&budget,&svc)!=1||arm_interp_get_reg(h->cpu,15)-4!=STOP_ADDR)return -1;
  if(result)*result=(int32_t)arm_interp_get_reg(h->cpu,0);return 0;
}
static int32_t invoke_guest(void*o,uint32_t target){return call_guest((harness*)o,target,NULL,0,NULL);}
static int read_guest_cstr(harness*h,uint32_t address,char*out,size_t capacity){for(size_t i=0;i<capacity;i++){if(mem_read(h,address+(uint32_t)i,out+i,1))return -1;if(!out[i])return 0;}out[capacity-1]=0;return -1;}
static int read_events(agr_runtime*r,harness*h,char*out,size_t capacity){uint32_t fn=agr_find_symbol(r,"trace_events");int32_t address=0;return !fn||call_guest(h,fn,NULL,0,&address)||!address? -1:read_guest_cstr(h,(uint32_t)address,out,capacity);}

int main(int argc,char**argv){
  if(argc!=8){fprintf(stderr,"usage: %s trace C B A bad-needed bad-symbol missing\n",argv[0]);return 2;}
  harness h;h.cpu=arm_interp_create();if(!h.cpu)return 3;agr_callbacks cb={0};cb.user=&h;cb.read=mem_read;cb.write=mem_write;cb.loader_write=mem_load;cb.protect=mem_protect;cb.resolve_import=host_import;cb.invoke_guest=invoke_guest;
  agr_runtime*r=agr_runtime_create(&cb,0x00100000,0x00200000,0x00200000,0x00800000);if(!r)return 4;
  if(reg(r,"libagr_trace.so",argv[1],0x01000000)||reg(r,"libagr_C.so",argv[2],0x02000000)||reg(r,"libagr_B.so",argv[3],0x03000000)||reg(r,"libagr_A.so",argv[4],0x04000000)||reg(r,"libagr_bad_needed.so",argv[5],0x05000000)||reg(r,"libagr_bad_symbol.so",argv[6],0x06000000)){fprintf(stderr,"register failed\n");return 5;}
  uint32_t trace=agr_dlopen(r,"libagr_trace.so");uint32_t reset=agr_dlsym(r,trace,"trace_reset");if(!trace||!reset||call_guest(&h,reset,NULL,0,NULL)){fprintf(stderr,"trace init failed\n");return 10;}
  uint32_t a1=agr_dlopen(r,"libagr_A.so"),a2=agr_dlopen(r,"libagr_A.so");if(!a1||a1!=a2){fprintf(stderr,"A load: %s\n",agr_dlerror(r));return 6;}
  char ctor[64]="";if(read_events(r,&h,ctor,sizeof(ctor))){fprintf(stderr,"constructor trace read failed\n");return 11;}
  uint32_t entry=agr_dlsym(r,a1,"a_entry"),weak=agr_dlsym(r,a1,"a_weak_value");
  uint32_t data_pointer=agr_dlsym(r,a1,"a_data_pointer"),weak_pointer=agr_dlsym(r,a1,"a_weak_pointer"),c_data=agr_find_symbol(r,"c_data");
  uint32_t relocated_data=0,relocated_weak=1;
  if(!data_pointer||mem_read(&h,data_pointer,&relocated_data,4)||!weak_pointer||mem_read(&h,weak_pointer,&relocated_weak,4)){fprintf(stderr,"relocated data read failed\n");return 9;}
  uint32_t arg=5;int32_t result=-1,weak_result=-1;if(!entry||call_guest(&h,entry,&arg,1,&result)||!weak||call_guest(&h,weak,NULL,0,&weak_result)){fprintf(stderr,"guest cross-DSO call failed\n");return 12;}
  agr_dlsym(r,a1,"not_exported_anywhere");const char*missing_kind=kind(agr_dlerror(r));
  agr_dlclose(r,a1);uint32_t after_one_symbol=agr_dlsym(r,a2,"a_entry");arg=6;int32_t after_one=-1;if(!after_one_symbol||call_guest(&h,after_one_symbol,&arg,1,&after_one)){fprintf(stderr,"post-refcount call failed\n");return 13;}char after_one_trace[64];if(read_events(r,&h,after_one_trace,sizeof(after_one_trace)))return 13;
  agr_dlclose(r,a2);char unload_trace[64];if(read_events(r,&h,unload_trace,sizeof(unload_trace)))return 14;uint32_t f0=agr_find_symbol(r,"a_entry");
  uint32_t bad_needed=agr_dlopen(r,"libagr_bad_needed.so");const char*bad_needed_kind=kind(agr_dlerror(r));
  uint32_t bad_symbol=agr_dlopen(r,"libagr_bad_symbol.so");const char*bad_symbol_kind=kind(agr_dlerror(r));
  uint32_t reload=agr_dlopen(r,"libagr_A.so");char reload_trace[64];if(read_events(r,&h,reload_trace,sizeof(reload_trace)))return 15;
  printf("{\"dependency_order\":\"%s\",\"cross_result\":%d,\"cross_data_relocated\":%s,\"weak_result\":%d,\"weak_relocated_zero\":%s,\"missing_dlsym\":\"%s\",\"after_one_close\":%d,\"after_one_trace\":\"%s\",\"after_unload\":\"%s\",\"bad_needed\":\"%s\",\"bad_symbol\":\"%s\",\"after_reload\":\"%s\",\"reloaded\":%s,\"entry_visible_after_unload\":%s}\n",
    ctor,result,relocated_data==c_data?"true":"false",weak_result,relocated_weak==0?"true":"false",missing_kind,after_one,after_one_trace,unload_trace,bad_needed?"loaded":bad_needed_kind,bad_symbol?"loaded":bad_symbol_kind,reload_trace,reload?"true":"false",f0?"true":"false");
  if(reload)agr_dlclose(r,reload);
  for(int i=0;i<1000;i++){uint32_t stress=agr_dlopen(r,"libagr_A.so");if(!stress||stress!=a1||agr_dlclose(r,stress)){fprintf(stderr,"load/unload stress failed at %d: %s\n",i,agr_dlerror(r));return 8;}}
  agr_dlclose(r,trace);agr_runtime_destroy(r);arm_interp_destroy(h.cpu);return entry?0:7;
}
