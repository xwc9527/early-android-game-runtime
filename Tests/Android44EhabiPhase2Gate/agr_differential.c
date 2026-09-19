#include "../../Runtime/NativeCore/agr_runtime.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { TRAP_BASE=0x0e000000u, STOP_ADDR=0x0ef00000u, STACK_BASE=0x0ee00000u,
       MAX_TRAPS=512, MAX_TRACE=1024, MAX_PENDING=32, MAX_EXIDX=1024 };

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
typedef struct trace_event { uint32_t pc, r0, r1, lr, sp, result; uint8_t has_result; char symbol[48]; } trace_event;
typedef struct pending_return { uint32_t return_pc, trace_index; } pending_return;
typedef struct exidx_event {
    uint32_t pc, result, count, expected, expected_count;
    char module[96];
} exidx_event;
typedef struct host_call_event {
    uint32_t pc, lr, sp, regs[4];
    char symbol[64];
} host_call_event;
typedef struct harness {
    void *cpu;
    agr_runtime *runtime;
    trap traps[MAX_TRAPS]; uint32_t trap_count, next_trap;
    trace_event trace[MAX_TRACE]; uint32_t trace_count;
    uint32_t watched[24]; const char *watched_names[24]; uint32_t watched_count;
    pending_return pending[MAX_PENDING]; uint32_t pending_count;
    exidx_event exidx[MAX_EXIDX]; uint32_t exidx_count, exidx_mismatches;
    host_call_event recent_calls[64]; uint32_t recent_call_count;
    char error[512];
} harness;

static int32_t mem_read(void*o,uint32_t a,void*p,uint32_t n){return arm_interp_read(((harness*)o)->cpu,a,(uint8_t*)p,n);}
static int32_t mem_write(void*o,uint32_t a,const void*p,uint32_t n){return arm_interp_write(((harness*)o)->cpu,a,(const uint8_t*)p,n);}
static int32_t mem_load(void*o,uint32_t a,const void*p,uint32_t n){return arm_interp_load(((harness*)o)->cpu,a,(const uint8_t*)p,n);}
static int32_t mem_protect(void*o,uint32_t a,uint32_t n,uint32_t p){return arm_interp_set_page_permissions(((harness*)o)->cpu,a,n,p);}
static uint32_t current_thread(void*o){(void)o;return 1u;}
static void* current_thread_context(void*o){return o;}
static void write_u32(harness*h,uint32_t a,uint32_t v){(void)arm_interp_write(h->cpu,a,(const uint8_t*)&v,4);}
static uint32_t read_u32(harness*h,uint32_t a){uint32_t v=0;(void)arm_interp_read(h->cpu,a,(uint8_t*)&v,4);return v;}

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
    for(uint32_t i=h->pending_count;i>0;i--){pending_return*p=&h->pending[i-1];if(canonical==(p->return_pc&~1u)){h->trace[p->trace_index].result=arm_interp_get_reg(h->cpu,0);h->trace[p->trace_index].has_result=1;memmove(p,p+1,(h->pending_count-i)*sizeof(*p));h->pending_count--;break;}}
    for(uint32_t i=0;i<h->watched_count;i++)if(canonical==(h->watched[i]&~1u)&&h->trace_count<MAX_TRACE){
        uint32_t r0=arm_interp_get_reg(h->cpu,0),lr=arm_interp_get_reg(h->cpu,14),sp=arm_interp_get_reg(h->cpu,13);
        if(h->trace_count){trace_event*last=&h->trace[h->trace_count-1];if(last->pc==canonical&&last->r0==r0&&last->lr==lr&&last->sp==sp&&!strcmp(last->symbol,h->watched_names[i]))break;}
        trace_event*e=&h->trace[h->trace_count];e->pc=canonical;e->r0=r0;e->r1=arm_interp_get_reg(h->cpu,1);e->sp=sp;e->lr=lr;
        if(!strcmp(h->watched_names[i],"agr_eh2_event")&&r0==12)snprintf(e->symbol,sizeof(e->symbol),"cleanup_landing_pad");
        else if(!strcmp(h->watched_names[i],"agr_eh2_event")&&r0==13)snprintf(e->symbol,sizeof(e->symbol),"handler_landing_pad");
        else snprintf(e->symbol,sizeof(e->symbol),"%s",h->watched_names[i]);
        if((strstr(e->symbol,"personality")||strstr(e->symbol,"unwind_cpp_pr"))&&h->pending_count<MAX_PENDING){h->pending[h->pending_count++]=(pending_return){lr,h->trace_count};}
        h->trace_count++;break;
    }
}

static int call_guest(harness*,uint32_t,const uint32_t*,uint32_t,int32_t*);
static int32_t invoke_guest(void*o,uint32_t fn){return call_guest((harness*)o,fn,NULL,0,NULL);}

static int dispatch_trap(harness*h,const char*name){
    uint32_t regs[4];for(uint32_t i=0;i<4;i++)regs[i]=arm_interp_get_reg(h->cpu,i);
    host_call_event *call=&h->recent_calls[h->recent_call_count++%64u];
    call->pc=arm_interp_get_reg(h->cpu,15)-4u;call->lr=arm_interp_get_reg(h->cpu,14);call->sp=arm_interp_get_reg(h->cpu,13);
    memcpy(call->regs,regs,sizeof(regs));snprintf(call->symbol,sizeof(call->symbol),"%s",name);
    agr_dispatch_result out={0};
    if(agr_dispatch_system(h->runtime,name,regs,arm_interp_get_reg(h->cpu,13),&out)||!out.handled){snprintf(h->error,sizeof(h->error),"unhandled host import %s: %s",name,agr_last_error(h->runtime));return -1;}
    if(out.action==AGR_ACTION_ABORT){snprintf(h->error,sizeof(h->error),"guest abort via %s",name);return -1;}
    if((!strcmp(name,"__gnu_Unwind_Find_exidx")||!strcmp(name,"dl_unwind_find_exidx"))&&h->exidx_count<MAX_EXIDX){
        agr_module_info module={0};exidx_event*e=&h->exidx[h->exidx_count++];e->pc=regs[0];e->result=out.value;e->count=regs[1]?read_u32(h,regs[1]):0;
        if(agr_find_module(h->runtime,regs[0],&module)==0){e->expected=module.exidx;e->expected_count=module.exidx_count;snprintf(e->module,sizeof(e->module),"%s",module.name?module.name:"");}
        if(!e->module[0]||e->result!=e->expected||e->count!=e->expected_count)h->exidx_mismatches++;
    }
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
static int load(harness*h,const char*name,const char*path,uint32_t base,uint32_t*handle){uint32_t n=0;void*p=read_file(path,&n);agr_load_result result={0};int rc=p?agr_load_elf(h->runtime,name,p,n,base,&result):-1;free(p);if(rc){snprintf(h->error,sizeof(h->error),"load %s: %s",name,agr_last_error(h->runtime));return rc;}*handle=result.object_handle;if(!*handle){snprintf(h->error,sizeof(h->error),"load %s returned no object handle",name);return -1;}return 0;}
static void watch_addr(harness*h,uint32_t handle,const char*name,const char*label){uint32_t a=agr_dlsym(h->runtime,handle,name);if(a&&h->watched_count<24){h->watched[h->watched_count]=a;h->watched_names[h->watched_count++]=label;}}
static int read_events(harness*h,uint32_t probe,int*out,uint32_t cap){uint32_t c=agr_dlsym(h->runtime,probe,"agr_eh2_count"),g=agr_dlsym(h->runtime,probe,"agr_eh2_get");int32_t n=0;if(!c||!g||call_guest(h,c,NULL,0,&n)||n<0||(uint32_t)n>cap)return -1;for(int32_t i=0;i<n;i++){uint32_t a=(uint32_t)i;int32_t v;if(call_guest(h,g,&a,1,&v))return -1;out[i]=v;}return n;}
static void print_events(const int*v,int n){putchar('[');for(int i=0;i<n;i++)printf("%s%d",i?",":"",v[i]);putchar(']');}
static void print_trace(harness*h){putchar('[');for(uint32_t i=0;i<h->trace_count;i++){trace_event*e=&h->trace[i];printf("%s{\"symbol\":\"%s\",\"pc\":%u,\"state\":%u,\"result\":",i?",":"",e->symbol,e->pc,e->r0);if(e->has_result)printf("%u",e->result);else printf("null");printf(",\"sp\":%u,\"lr\":%u}",e->sp,e->lr);}putchar(']');}
static void print_exidx(harness*h){putchar('[');for(uint32_t i=0;i<h->exidx_count;i++){exidx_event*e=&h->exidx[i];printf("%s{\"pc\":%u,\"module\":\"%s\",\"result\":%u,\"count\":%u,\"expected\":%u,\"expected_count\":%u}",i?",":"",e->pc,e->module,e->result,e->count,e->expected,e->expected_count);}putchar(']');}
static void dump_failure(harness*h,const char*stage){
    fprintf(stderr,"EHABI2_FAILURE stage=%s error=%s pc=%08x lr=%08x sp=%08x cpsr=%08x\n",stage,h->error,
            arm_interp_get_reg(h->cpu,15),arm_interp_get_reg(h->cpu,14),arm_interp_get_reg(h->cpu,13),arm_interp_get_cpsr(h->cpu));
    for(uint32_t i=0;i<h->trace_count;i++){trace_event*e=&h->trace[i];fprintf(stderr,"TRACE %u symbol=%s pc=%08x state=%u result=%s%u sp=%08x lr=%08x\n",i,e->symbol,e->pc,e->r0,e->has_result?"":"unset:",e->result,e->sp,e->lr);}
    for(uint32_t i=0;i<h->exidx_count;i++){exidx_event*e=&h->exidx[i];fprintf(stderr,"EXIDX %u pc=%08x module=%s result=%08x count=%u expected=%08x expected_count=%u\n",i,e->pc,e->module,e->result,e->count,e->expected,e->expected_count);}
    uint32_t first=h->recent_call_count>64u?h->recent_call_count-64u:0u;
    for(uint32_t i=first;i<h->recent_call_count;i++){host_call_event*e=&h->recent_calls[i%64u];fprintf(stderr,"HOSTCALL %u symbol=%s pc=%08x lr=%08x sp=%08x r0=%08x r1=%08x r2=%08x r3=%08x\n",i,e->symbol,e->pc,e->lr,e->sp,e->regs[0],e->regs[1],e->regs[2],e->regs[3]);}
}

int agr_ehabi2_run(int argc,char**argv){
    if(argc!=7){fprintf(stderr,"usage: %s gnustl probe same C B A\n",argv[0]);return 2;}
    harness h={0};h.cpu=arm_interp_create();h.next_trap=TRAP_BASE;if(!h.cpu)return 3;
    agr_callbacks cb={0};cb.user=&h;cb.read=mem_read;cb.write=mem_write;cb.loader_write=mem_load;cb.protect=mem_protect;cb.resolve_import=host_import;cb.invoke_guest=invoke_guest;cb.current_thread=current_thread;cb.current_thread_context=current_thread_context;
    h.runtime=agr_runtime_create(&cb,0x0c000000,0x0c100000,0x0d000000,0x0df00000);if(!h.runtime)return 4;
    uint32_t main_thread_storage=agr_malloc(h.runtime,0x1000u);
    if(!main_thread_storage||agr_runtime_attach_current_thread(h.runtime,1,1,main_thread_storage+0x1000u-560u)){snprintf(h.error,sizeof(h.error),"attach main guest thread failed: %s",agr_last_error(h.runtime));fprintf(stderr,"%s\n",h.error);return 4;}
    uint32_t gnustl=0,probe=0,same_h=0,c_h=0,b_h=0,a_h=0;
    if(load(&h,"libgnustl_shared.so",argv[1],0x01000000,&gnustl)||load(&h,"libagr_eh2_probe.so",argv[2],0x03000000,&probe)||load(&h,"libagr_eh2_same.so",argv[3],0x04000000,&same_h)||load(&h,"libagr_eh2_C.so",argv[4],0x05000000,&c_h)||load(&h,"libagr_eh2_B.so",argv[5],0x06000000,&b_h)||load(&h,"libagr_eh2_A.so",argv[6],0x07000000,&a_h)){fprintf(stderr,"%s\n",h.error);return 5;}
    watch_addr(&h,gnustl,"__cxa_throw","__cxa_throw");watch_addr(&h,gnustl,"_Unwind_RaiseException","_Unwind_RaiseException");watch_addr(&h,gnustl,"__gxx_personality_v0","__gxx_personality_v0");watch_addr(&h,gnustl,"__aeabi_unwind_cpp_pr0","__aeabi_unwind_cpp_pr0");watch_addr(&h,gnustl,"__aeabi_unwind_cpp_pr1","__aeabi_unwind_cpp_pr1");watch_addr(&h,gnustl,"__aeabi_unwind_cpp_pr2","__aeabi_unwind_cpp_pr2");watch_addr(&h,gnustl,"_Unwind_Resume","_Unwind_Resume");
    watch_addr(&h,same_h,"_Unwind_RaiseException","same:_Unwind_RaiseException");watch_addr(&h,same_h,"_Unwind_Resume","same:_Unwind_Resume");watch_addr(&h,b_h,"_Unwind_Resume","B:_Unwind_Resume");watch_addr(&h,c_h,"_Unwind_RaiseException","C:_Unwind_RaiseException");watch_addr(&h,probe,"agr_eh2_event","agr_eh2_event");
    int same[32],cross[32],reload_cross[32],same_n,cross_n,reload_n,same_ok=0,cross_ok=0,reload_ok=0;
    uint32_t before=h.trace_count;
    uint32_t same_fn=agr_dlsym(h.runtime,same_h,"agr_eh2_same_run");if(!same_fn||call_guest(&h,same_fn,NULL,0,&same_ok)||(same_n=read_events(&h,probe,same,32))<0){fprintf(stderr,"same: %s\n",h.error);dump_failure(&h,"same");return 6;}
    uint32_t same_trace_end=h.trace_count,cross_fn=agr_dlsym(h.runtime,a_h,"agr_eh2_cross_run");if(!cross_fn||call_guest(&h,cross_fn,NULL,0,&cross_ok)||(cross_n=read_events(&h,probe,cross,32))<0){fprintf(stderr,"cross: %s\n",h.error);return 7;}
    uint32_t first_cross_end=h.trace_count,c_pc=agr_dlsym(h.runtime,c_h,"agr_eh2_C_throw"),b_pc=agr_dlsym(h.runtime,b_h,"agr_eh2_B_call"),a_pc=cross_fn;
    if(h.exidx_mismatches){fprintf(stderr,"formal linker exidx ownership mismatches: %u\n",h.exidx_mismatches);return 8;}
    if(agr_dlclose(h.runtime,a_h)||agr_dlclose(h.runtime,b_h)||agr_dlclose(h.runtime,c_h)||agr_dlclose(h.runtime,same_h)){fprintf(stderr,"unload: %s\n",agr_dlerror(h.runtime));return 9;}
    agr_module_info stale={0};uint32_t stale_count=0;stale_count+=(agr_find_module(h.runtime,a_pc,&stale)==0);stale_count+=(agr_find_module(h.runtime,b_pc,&stale)==0);stale_count+=(agr_find_module(h.runtime,c_pc,&stale)==0);
    if(stale_count){fprintf(stderr,"stale formal exidx ownership after unload: %u\n",stale_count);return 10;}
    a_h=agr_dlopen(h.runtime,"libagr_eh2_A.so");if(!a_h){fprintf(stderr,"reload A: %s\n",agr_dlerror(h.runtime));return 11;}
    cross_fn=agr_dlsym(h.runtime,a_h,"agr_eh2_cross_run");if(!cross_fn||call_guest(&h,cross_fn,NULL,0,&reload_ok)||(reload_n=read_events(&h,probe,reload_cross,32))<0){fprintf(stderr,"reload cross: %s\n",h.error);return 12;}
    agr_module_info reloaded={0};uint32_t reload_owned=(agr_find_module(h.runtime,cross_fn,&reloaded)==0&&reloaded.exidx&&reloaded.exidx_count);
    if(!reload_owned||h.exidx_mismatches){fprintf(stderr,"reload exidx ownership invalid\n");return 13;}
    printf("{\"same\":");print_events(same,same_n);printf(",\"cross\":");print_events(cross,cross_n);printf(",\"reload_cross\":");print_events(reload_cross,reload_n);printf(",\"same_ok\":%d,\"cross_ok\":%d,\"reload_ok\":%d,\"unload_stale\":%u,\"reload_owned\":%u,\"exidx_mismatches\":%u,\"trace_split\":[%u,%u,%u,%u],\"trace\":",same_ok,cross_ok,reload_ok,stale_count,reload_owned,h.exidx_mismatches,before,same_trace_end,first_cross_end,h.trace_count);print_trace(&h);printf(",\"exidx\":");print_exidx(&h);printf("}\n");
    agr_runtime_destroy(h.runtime);arm_interp_destroy(h.cpu);return 0;
}

#if !defined(AGR_EHABI2_EMBEDDED)
int main(int argc,char**argv){return agr_ehabi2_run(argc,argv);}
#endif
