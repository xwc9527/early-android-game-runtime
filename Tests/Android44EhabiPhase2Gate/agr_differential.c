#include "../../Runtime/NativeCore/agr_runtime.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { TRAP_BASE=0x0e000000u, STOP_ADDR=0x0ef00000u, STACK_BASE=0x0ee00000u,
       MAX_TRAPS=512, MAX_TRACE=1024 };

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

typedef struct trap { uint32_t address; char name[96]; } trap;
typedef struct trace_event { uint32_t pc, r0, r1, lr, sp; char symbol[48]; } trace_event;
typedef struct harness {
    void *cpu;
    agr_runtime *runtime;
    trap traps[MAX_TRAPS]; uint32_t trap_count, next_trap;
    trace_event trace[MAX_TRACE]; uint32_t trace_count;
    uint32_t watched[16]; const char *watched_names[16]; uint32_t watched_count;
    char error[512];
} harness;

static int32_t mem_read(void*o,uint32_t a,void*p,uint32_t n){return arm_interp_read(((harness*)o)->cpu,a,(uint8_t*)p,n);}
static int32_t mem_write(void*o,uint32_t a,const void*p,uint32_t n){return arm_interp_write(((harness*)o)->cpu,a,(const uint8_t*)p,n);}
static int32_t mem_load(void*o,uint32_t a,const void*p,uint32_t n){return arm_interp_load(((harness*)o)->cpu,a,(const uint8_t*)p,n);}
static int32_t mem_protect(void*o,uint32_t a,uint32_t n,uint32_t p){return arm_interp_set_page_permissions(((harness*)o)->cpu,a,n,p);}
static void write_u32(harness*h,uint32_t a,uint32_t v){(void)arm_interp_write(h->cpu,a,(const uint8_t*)&v,4);}

static const char *const forbidden_host[] = {
    "_Unwind_RaiseException","_Unwind_Resume","__gxx_personality_v0",
    "__aeabi_unwind_cpp_pr0","__aeabi_unwind_cpp_pr1","__aeabi_unwind_cpp_pr2",
    "__cxa_throw","__cxa_type_match","__cxa_begin_cleanup","__cxa_end_cleanup",NULL
};
static int forbidden(const char*n){for(uint32_t i=0;forbidden_host[i];i++)if(!strcmp(n,forbidden_host[i]))return 1;return 0;}

static uint32_t host_import(void*o,const char*n,uint32_t type){
    harness*h=(harness*)o;
    if(forbidden(n)){snprintf(h->error,sizeof(h->error),"forbidden exception host import: %s",n);return 0;}
    if(type==1||type==6){uint8_t z[32]={0};return agr_alloc_static(h->runtime,z,sizeof(z),8);}
    for(uint32_t i=0;i<h->trap_count;i++)if(!strcmp(h->traps[i].name,n))return h->traps[i].address;
    if(h->trap_count>=MAX_TRAPS)return 0;
    uint32_t address=h->next_trap;h->next_trap+=4;
    uint32_t svc=0xef000000u|(h->trap_count&0x00ffffffu);
    if(arm_interp_load(h->cpu,address,(const uint8_t*)&svc,4)||arm_interp_set_page_permissions(h->cpu,address&~0xfffu,0x1000,5))return 0;
    h->traps[h->trap_count].address=address;
    snprintf(h->traps[h->trap_count].name,sizeof(h->traps[h->trap_count].name),"%s",n);
    h->trap_count++;
    return address;
}
static const char*trap_name(harness*h,uint32_t a){for(uint32_t i=0;i<h->trap_count;i++)if(h->traps[i].address==a)return h->traps[i].name;return NULL;}
static void guest_return(harness*h,uint32_t r0,uint32_t r1){uint32_t lr=arm_interp_get_reg(h->cpu,14),c=arm_interp_get_cpsr(h->cpu);arm_interp_set_reg(h->cpu,0,r0);arm_interp_set_reg(h->cpu,1,r1);arm_interp_set_cpsr(h->cpu,(lr&1)?(c|0x20u):(c&~0x20u));arm_interp_set_reg(h->cpu,15,lr&~1u);}

static void observe(harness*h){
    uint32_t pc=arm_interp_get_reg(h->cpu,15), canonical=pc&~1u;
    for(uint32_t i=0;i<h->watched_count;i++)if(canonical==(h->watched[i]&~1u)&&h->trace_count<MAX_TRACE){
        trace_event*e=&h->trace[h->trace_count++];e->pc=canonical;e->r0=arm_interp_get_reg(h->cpu,0);e->r1=arm_interp_get_reg(h->cpu,1);e->sp=arm_interp_get_reg(h->cpu,13);e->lr=arm_interp_get_reg(h->cpu,14);snprintf(e->symbol,sizeof(e->symbol),"%s",h->watched_names[i]);break;
    }
}

static int call_guest(harness*,uint32_t,const uint32_t*,uint32_t,int32_t*);
static int32_t invoke_guest(void*o,uint32_t fn){return call_guest((harness*)o,fn,NULL,0,NULL);}

static int dispatch_trap(harness*h,const char*name){
    uint32_t regs[4];for(uint32_t i=0;i<4;i++)regs[i]=arm_interp_get_reg(h->cpu,i);
    agr_dispatch_result out={0};
    if(agr_dispatch_system(h->runtime,name,regs,arm_interp_get_reg(h->cpu,13),&out)||!out.handled){snprintf(h->error,sizeof(h->error),"unhandled host import %s: %s",name,agr_last_error(h->runtime));return -1;}
    if(out.action==AGR_ACTION_ABORT){snprintf(h->error,sizeof(h->error),"guest abort via %s",name);return -1;}
    if(out.action==AGR_ACTION_FINALIZE&&out.action_arg0){uint32_t a[1]={out.action_arg1};if(call_guest(h,out.action_arg0,a,1,NULL))return -1;}
    else if(out.action==AGR_ACTION_CALL_ONCE&&out.action_arg0){if(call_guest(h,out.action_arg0,NULL,0,NULL))return -1;agr_complete_once(h->runtime,out.action_arg1);}
    else if(out.action!=AGR_ACTION_NONE&&out.action!=AGR_ACTION_FINALIZE){snprintf(h->error,sizeof(h->error),"unsupported action %u for %s",out.action,name);return -1;}
    guest_return(h,out.value,out.value_r1);return 0;
}

static int call_guest(harness*h,uint32_t target,const uint32_t*args,uint32_t count,int32_t*result){
    uint32_t stop=0xef000000u;
    if(arm_interp_load(h->cpu,STOP_ADDR,(const uint8_t*)&stop,4)||arm_interp_set_page_permissions(h->cpu,STOP_ADDR,0x1000,5)||arm_interp_set_page_permissions(h->cpu,STACK_BASE,0x10000,3))return -1;
    for(uint32_t i=0;i<4;i++)arm_interp_set_reg(h->cpu,i,i<count?args[i]:0);
    for(uint32_t i=4;i<count;i++)write_u32(h,STACK_BASE+0xff00u+(i-4)*4,args[i]);
    arm_interp_set_cpsr(h->cpu,(target&1)?0x20u:0);arm_interp_set_reg(h->cpu,13,STACK_BASE+0xff00u);arm_interp_set_reg(h->cpu,14,STOP_ADDR);arm_interp_set_reg(h->cpu,15,target&~1u);
    uint64_t total=0;
    for(;;){
        observe(h);uint64_t budget=1;uint32_t svc=0;int32_t state=arm_interp_run(h->cpu,&budget,&svc);total++;
        if(total>100000000u){snprintf(h->error,sizeof(h->error),"instruction budget exhausted");return -1;}
        if(state==0)continue;
        if(state!=1){snprintf(h->error,sizeof(h->error),"guest fault state=%d pc=%08x cpsr=%08x",state,arm_interp_get_reg(h->cpu,15),arm_interp_get_cpsr(h->cpu));return -1;}
        uint32_t address=arm_interp_get_reg(h->cpu,15)-4;
        if(address==STOP_ADDR){if(result)*result=(int32_t)arm_interp_get_reg(h->cpu,0);return 0;}
        const char*name=trap_name(h,address);if(!name||dispatch_trap(h,name))return -1;
    }
}

static void*read_file(const char*path,uint32_t*size){FILE*f=fopen(path,"rb");long n;void*p;if(!f)return NULL;fseek(f,0,SEEK_END);n=ftell(f);fseek(f,0,SEEK_SET);p=malloc((size_t)n);if(!p||fread(p,1,(size_t)n,f)!=(size_t)n){free(p);p=NULL;n=0;}fclose(f);*size=(uint32_t)n;return p;}
static int load(harness*h,const char*name,const char*path,uint32_t base){uint32_t n=0;void*p=read_file(path,&n);int rc=p?agr_load_elf(h->runtime,name,p,n,base,NULL):-1;free(p);if(rc)snprintf(h->error,sizeof(h->error),"load %s: %s",name,agr_last_error(h->runtime));return rc;}
static void watch(harness*h,const char*name){uint32_t a=agr_find_symbol(h->runtime,name);if(a&&h->watched_count<16){h->watched[h->watched_count]=a;h->watched_names[h->watched_count++]=name;}}
static int read_events(harness*h,int*out,uint32_t cap){uint32_t c=agr_find_symbol(h->runtime,"agr_eh2_count"),g=agr_find_symbol(h->runtime,"agr_eh2_get");int32_t n=0;if(!c||!g||call_guest(h,c,NULL,0,&n)||n<0||(uint32_t)n>cap)return -1;for(int32_t i=0;i<n;i++){uint32_t a=(uint32_t)i;int32_t v;if(call_guest(h,g,&a,1,&v))return -1;out[i]=v;}return n;}
static void print_events(const int*v,int n){putchar('[');for(int i=0;i<n;i++)printf("%s%d",i?",":"",v[i]);putchar(']');}
static void print_trace(harness*h){putchar('[');for(uint32_t i=0;i<h->trace_count;i++){trace_event*e=&h->trace[i];printf("%s{\"symbol\":\"%s\",\"pc\":%u,\"state\":%u,\"result\":%u,\"sp\":%u,\"lr\":%u}",i?",":"",e->symbol,e->pc,e->r0,e->r0,e->sp,e->lr);}putchar(']');}

int main(int argc,char**argv){
    if(argc!=7){fprintf(stderr,"usage: %s gnustl probe same C B A\n",argv[0]);return 2;}
    harness h={0};h.cpu=arm_interp_create();h.next_trap=TRAP_BASE;if(!h.cpu)return 3;
    agr_callbacks cb={0};cb.user=&h;cb.read=mem_read;cb.write=mem_write;cb.loader_write=mem_load;cb.protect=mem_protect;cb.resolve_import=host_import;cb.invoke_guest=invoke_guest;
    h.runtime=agr_runtime_create(&cb,0x0c000000,0x0c100000,0x0d000000,0x0df00000);if(!h.runtime)return 4;
    if(load(&h,"libgnustl_shared.so",argv[1],0x01000000)||load(&h,"libagr_eh2_probe.so",argv[2],0x03000000)||load(&h,"libagr_eh2_same.so",argv[3],0x04000000)||load(&h,"libagr_eh2_C.so",argv[4],0x05000000)||load(&h,"libagr_eh2_B.so",argv[5],0x06000000)||load(&h,"libagr_eh2_A.so",argv[6],0x07000000)){fprintf(stderr,"%s\n",h.error);return 5;}
    const char*names[]={"__cxa_throw","_Unwind_RaiseException","__gxx_personality_v0","__aeabi_unwind_cpp_pr0","__aeabi_unwind_cpp_pr1","__aeabi_unwind_cpp_pr2","_Unwind_Resume",NULL};for(uint32_t i=0;names[i];i++)watch(&h,names[i]);
    int same[32],cross[32],same_n,cross_n,same_ok=0,cross_ok=0;
    uint32_t before=h.trace_count;
    uint32_t same_fn=agr_find_symbol(h.runtime,"agr_eh2_same_run");if(!same_fn||call_guest(&h,same_fn,NULL,0,&same_ok)||(same_n=read_events(&h,same,32))<0){fprintf(stderr,"same: %s\n",h.error);return 6;}
    uint32_t same_trace_end=h.trace_count,cross_fn=agr_find_symbol(h.runtime,"agr_eh2_cross_run");if(!cross_fn||call_guest(&h,cross_fn,NULL,0,&cross_ok)||(cross_n=read_events(&h,cross,32))<0){fprintf(stderr,"cross: %s\n",h.error);return 7;}
    printf("{\"same\":");print_events(same,same_n);printf(",\"cross\":");print_events(cross,cross_n);printf(",\"same_ok\":%d,\"cross_ok\":%d,\"trace_split\":[%u,%u,%u],\"trace\":",same_ok,cross_ok,before,same_trace_end,h.trace_count);print_trace(&h);printf("}\n");
    agr_runtime_destroy(h.runtime);arm_interp_destroy(h.cpu);return 0;
}
