#include "agr_guest_runtime.h"
#include "agr_jni_methods.h"
#include "agr_runtime.h"
#include "agr_thread_context.h"
#include "agr_service_dispatch.h"
#include "../Ehabi/agr_ehabi.h"
#include "../Bionic/agr_bionic_thread_attr.h"
#include "../AndroidFw/agr_androidfw.h"
#include "../DexLoom/game_dex_runner.h"
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES/gl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdatomic.h>
#include <time.h>
#if defined(__APPLE__)
#include <os/log.h>
#endif

extern void *arm_interp_create(void);
extern void arm_interp_destroy(void *);
extern int32_t arm_interp_write(void *, uint32_t, const uint8_t *, uint32_t);
extern int32_t arm_interp_load(void *, uint32_t, const uint8_t *, uint32_t);
extern int32_t arm_interp_read(void *, uint32_t, uint8_t *, uint32_t);
extern uint8_t *arm_interp_memory_base(void *);
extern int32_t arm_interp_set_page_permissions(void *, uint32_t, uint32_t, uint32_t);
extern int32_t arm_interp_set_reg(void *, uint32_t, uint32_t);
extern uint32_t arm_interp_get_reg(void *, uint32_t);
extern void arm_interp_set_watch_pc(void *, uint32_t);
extern uint32_t arm_interp_watch_hits(void *);
extern uint32_t arm_interp_watch_reg(void *, uint32_t);
extern uint32_t arm_interp_watch_cpsr(void *);
extern void arm_interp_set_thread_tag(void *, uint32_t);
extern uint32_t arm_interp_watch_thread_tag(void *);
extern int32_t arm_interp_watch_trace(void *, uint32_t, uint32_t *, uint32_t *);
extern int32_t arm_interp_set_cpsr(void *, uint32_t);
extern uint32_t arm_interp_get_cpsr(void *);
extern int32_t arm_interp_run(void *, uint64_t *, uint32_t *);

#define JNI_ENV_PTR 0x01000000u
#define JNI_TABLE   0x01000100u
#define JVM_PTR     0x01000500u
#define JVM_TABLE   0x01000600u
#define TRAP_BASE   0x01800000u
#define IMPORT_BASE 0x01802000u
#define STOP_ADDR   0x0180f000u
#define STACK_TOP   0x00a1ff00u
#define MAX_TRAPS 512
#define MAX_ARRAYS 32
#define GUEST_EGL_DISPLAY 0x64000001u
#define GUEST_EGL_CONFIG  0x64000002u
#define GUEST_EGL_SURFACE 0x64000003u
#define GUEST_EGL_CONTEXT 0x64000004u

typedef struct { uint32_t address; char *name; } trap_entry;
typedef struct { uint32_t handle, kind, count, address; } array_entry;
typedef struct { int size; GLenum type; int stride; uint32_t pointer; int active; } client_array;
typedef struct { uint32_t read_fd, write_fd, read_offset, size; uint8_t data[4096]; int live; } virtual_pipe;
typedef struct { uint32_t fd, ident, events, callback, data; } looper_fd;
typedef struct { uint32_t handle; agr_afw_asset *asset; } asset_entry;
typedef struct { uint32_t handle; char *text; } jni_string;
typedef struct { uint32_t handle; char *descriptor; } jni_class;
typedef struct { char *name; uint32_t handle; int32_t jni_version; } java_library;
typedef struct { uint32_t handle, type, action, pointer_count, pointer_id; float x, y; } input_event;

struct agr_process_runtime {
    /* agr_guest is the legacy public name for ProcessRuntime. All guest
     * execution is obtained through the Darwin-TLS current context. */
    void *process_cpu;
    agr_guest_thread_context *main_thread;
    agr_guest_thread_context *thread_registry;
    atomic_flag thread_registry_lock;
    atomic_flag diagnostics_lock;
    atomic_flag jni_lock;
    atomic_flag input_lock;
    uint32_t failure_generation;
    agr_runtime *runtime;
    trap_entry traps[MAX_TRAPS];
    uint32_t trap_count, next_trap;
    array_entry arrays[MAX_ARRAYS];
    uint32_t array_count, next_array_handle;
    client_array vertex, color, texcoord, normal;
    EGLDisplay display;
    EGLConfig config;
    EGLSurface surface;
    EGLContext context;
    int width, height;
    char renderer[256], gl_version[256], error[256], last_log[128];
    _Atomic uint64_t instruction_count;
    _Atomic uint32_t last_guest_pc;
    _Atomic int shutting_down;
    uint64_t run_budget;
    uint32_t call_depth;
    virtual_pipe pipes[8];
    uint32_t looper_handle, looper_fd_count;
    looper_fd looper_fds[16];
    agr_afw_manager *assets;
    asset_entry open_assets[64];
    uint32_t next_asset_handle;
    agr_dex_game *dex_game;
    agr_jni_method_table methods;
    jni_string *strings; uint32_t string_count, string_capacity;
    jni_class *classes; uint32_t class_count, class_capacity;
    java_library *java_libraries; uint32_t java_library_count, java_library_capacity;
    const char *recent_imports[12];
    uint32_t recent_import_index;
    const char *unique_imports[256]; uint32_t unique_import_count;
    uint32_t input_queue_handle, input_ident, input_data;
    input_event input_events[32]; uint32_t input_head, input_count, next_input_handle;
    _Atomic uint32_t input_consumed_count;
    _Atomic uint32_t draw_count, swap_count;
    uint32_t asset_open_count;
    uint32_t egl_owner_thread_id;
    atomic_flag framebuffer_lock;
    uint8_t *framebuffer;
    uint32_t framebuffer_capacity, framebuffer_size;
};

void agr_process_runtime_register_thread(agr_process_runtime *process,
                                         agr_guest_thread_context *context) {
    if (!process || !context) return;
    while (atomic_flag_test_and_set_explicit(&process->thread_registry_lock,memory_order_acquire)) {}
    context->next=process->thread_registry;
    process->thread_registry=context;
    atomic_flag_clear_explicit(&process->thread_registry_lock,memory_order_release);
}
void agr_process_runtime_unregister_thread(agr_process_runtime *process,
                                           agr_guest_thread_context *context) {
    if (!process || !context) return;
    while (atomic_flag_test_and_set_explicit(&process->thread_registry_lock,memory_order_acquire)) {}
    agr_guest_thread_context **at=&process->thread_registry;
    while (*at && *at != context) at=&(*at)->next;
    if (*at) *at=context->next;
    atomic_flag_clear_explicit(&process->thread_registry_lock,memory_order_release);
}

static agr_guest_thread_context *guest_context(agr_guest *g) {
    agr_guest_thread_context *context = agr_guest_thread_context_current();
    return context && context->process == g ? context : NULL;
}
static void *guest_cpu(agr_guest *g) {
    agr_guest_thread_context *context = guest_context(g);
    return context ? context->cpu : NULL;
}

static int32_t call_address(agr_guest *g, uint32_t target, const uint32_t *args,
                            uint32_t count, int32_t *result);
static int run_until_return(agr_guest *g);
static int32_t guest_thread_execute(void *user, uint32_t guest_thread,
                                    uint32_t start, uint32_t argument,
                                    const struct agr_bionic_thread_attr *attr,
                                    uint32_t *return_value);

static uint32_t guest_current_thread_cb(void *user) {
    agr_guest_thread_context *context=guest_context((agr_guest *)user);
    return context ? context->guest_thread_id : 0;
}
static void *guest_current_thread_context_cb(void *user) {
    return guest_context((agr_guest *)user);
}
static int32_t guest_atomic_load_cb(void *user,uint32_t address,uint32_t *value) {
    extern int32_t arm_interp_atomic_load32(void *,uint32_t,uint32_t *);
    return arm_interp_atomic_load32(guest_cpu((agr_guest *)user),address,value);
}
static int32_t guest_atomic_cas_cb(void *user,uint32_t address,uint32_t old,uint32_t next,uint32_t *observed) {
    extern int32_t arm_interp_atomic_compare_exchange32(void *,uint32_t,uint32_t,uint32_t,uint32_t *);
    return arm_interp_atomic_compare_exchange32(guest_cpu((agr_guest *)user),address,old,next,observed);
}
static int32_t guest_atomic_exchange_cb(void *user,uint32_t address,uint32_t next,uint32_t *observed) {
    extern int32_t arm_interp_atomic_exchange32(void *,uint32_t,uint32_t,uint32_t *);
    return arm_interp_atomic_exchange32(guest_cpu((agr_guest *)user),address,next,observed);
}
static int32_t guest_atomic_fetch_sub_cb(void *user,uint32_t address,uint32_t amount,uint32_t *observed) {
    extern int32_t arm_interp_atomic_fetch_sub32(void *,uint32_t,uint32_t,uint32_t *);
    return arm_interp_atomic_fetch_sub32(guest_cpu((agr_guest *)user),address,amount,observed);
}

static void set_error(agr_guest *g, const char *text) {
    while (atomic_flag_test_and_set_explicit(&g->diagnostics_lock,memory_order_acquire)) {}
    snprintf(g->error, sizeof(g->error), "%s", text ? text : "unknown error");
    g->failure_generation++;
    atomic_flag_clear_explicit(&g->diagnostics_lock,memory_order_release);
}
static void guest_log_cb(void *user, uint32_t priority, const char *tag, const char *format) {
    agr_guest *g = (agr_guest *)user;
    while (atomic_flag_test_and_set_explicit(&g->diagnostics_lock,memory_order_acquire)) {}
    if (format && !strcmp(format,"%s") && g->last_log[0]) {
        atomic_flag_clear_explicit(&g->diagnostics_lock,memory_order_release); return;
    }
    snprintf(g->last_log, sizeof(g->last_log), "%u:%s:%s", priority,
             tag ? tag : "", format ? format : "");
    atomic_flag_clear_explicit(&g->diagnostics_lock,memory_order_release);
}
static void record_process_import(agr_guest *g, const char *name) {
    while (atomic_flag_test_and_set_explicit(&g->diagnostics_lock,memory_order_acquire)) {}
    g->recent_imports[g->recent_import_index++ % 12u]=name;
    uint32_t found=0;
    for (uint32_t i=0;i<g->unique_import_count;i++)
        if (!strcmp(g->unique_imports[i],name)) { found=1; break; }
    if (!found && g->unique_import_count < 256u)
        g->unique_imports[g->unique_import_count++]=name;
    atomic_flag_clear_explicit(&g->diagnostics_lock,memory_order_release);
}
static asset_entry *find_asset(agr_guest *g, uint32_t handle) {
    for (uint32_t i = 0; i < 64; i++) if (g->open_assets[i].handle == handle && g->open_assets[i].asset) return &g->open_assets[i];
    return NULL;
}
static char *copy_string(const char *s) {
    size_t n = strlen(s) + 1; char *p = (char *)malloc(n); if (p) memcpy(p, s, n); return p;
}
static int32_t mem_read_cb(void *user, uint32_t address, void *data, uint32_t size) {
    return arm_interp_read(guest_cpu((agr_guest *)user), address, (uint8_t *)data, size);
}
static int32_t mem_write_cb(void *user, uint32_t address, const void *data, uint32_t size) {
    return arm_interp_write(guest_cpu((agr_guest *)user), address, (const uint8_t *)data, size);
}
static int32_t mem_loader_write_cb(void *user, uint32_t address, const void *data, uint32_t size) {
    return arm_interp_load(guest_cpu((agr_guest *)user), address, (const uint8_t *)data, size);
}
static int32_t mem_protect_cb(void *user, uint32_t address, uint32_t size, uint32_t protection) {
    return arm_interp_set_page_permissions(guest_cpu((agr_guest *)user), address, size, protection);
}
static uint8_t *mem_base_cb(void *user) {
    return arm_interp_memory_base(((agr_guest *)user)->process_cpu);
}
static virtual_pipe *find_pipe(agr_guest *g, uint32_t fd) {
    for (uint32_t i = 0; i < 8; i++) if (g->pipes[i].live && (g->pipes[i].read_fd == fd || g->pipes[i].write_fd == fd)) return &g->pipes[i];
    return NULL;
}
static int32_t pipe_create_cb(void *user, uint32_t *read_fd, uint32_t *write_fd) {
    agr_guest *g = (agr_guest *)user;
    for (uint32_t i = 0; i < 8; i++) if (!g->pipes[i].live) {
        virtual_pipe *p = &g->pipes[i]; memset(p, 0, sizeof(*p)); p->live = 1;
        p->read_fd = 100 + i * 2; p->write_fd = p->read_fd + 1;
        *read_fd = p->read_fd; *write_fd = p->write_fd; return 0;
    }
    return -1;
}
static uint32_t fd_read_cb(void *user, uint32_t fd, void *data, uint32_t size) {
    virtual_pipe *p = find_pipe((agr_guest *)user, fd); if (!p || fd != p->read_fd) return 0;
    uint32_t available = p->size - p->read_offset, count = size < available ? size : available;
    if (count) memcpy(data, p->data + p->read_offset, count); p->read_offset += count;
    if (p->read_offset == p->size) p->read_offset = p->size = 0; return count;
}
static uint32_t fd_write_cb(void *user, uint32_t fd, const void *data, uint32_t size) {
    virtual_pipe *p = find_pipe((agr_guest *)user, fd); if (!p || fd != p->write_fd) return 0;
    if (p->read_offset) { memmove(p->data, p->data + p->read_offset, p->size - p->read_offset); p->size -= p->read_offset; p->read_offset = 0; }
    uint32_t room = (uint32_t)sizeof(p->data) - p->size, count = size < room ? size : room;
    if (count) memcpy(p->data + p->size, data, count); p->size += count; return count;
}
static int32_t fd_close_cb(void *user, uint32_t fd) {
    virtual_pipe *p = find_pipe((agr_guest *)user, fd); if (!p) return -1; p->live = 0; return 0;
}
static void write_u32(agr_guest *g, uint32_t address, uint32_t value) {
    arm_interp_write(guest_cpu(g), address, (const uint8_t *)&value, 4);
}
static uint32_t read_u32(agr_guest *g, uint32_t address) {
    uint32_t value = 0; arm_interp_read(guest_cpu(g), address, (uint8_t *)&value, 4); return value;
}
static int read_guest_string(agr_guest *g, uint32_t address, char *text, uint32_t capacity) {
    if (!address || !capacity) return -1;
    for (uint32_t i=0; i<capacity; i++) {
        if (arm_interp_read(guest_cpu(g),address+i,(uint8_t *)&text[i],1)) return -1;
        if (!text[i]) return 0;
    }
    text[capacity-1]=0; return -1;
}
static uint32_t argument(agr_guest *g, uint32_t index) {
    if (index < 4) return arm_interp_get_reg(guest_cpu(g), index);
    return read_u32(g, arm_interp_get_reg(guest_cpu(g), 13) + (index - 4) * 4);
}
static uint32_t add_trap(agr_guest *g, const char *name) {
    for (uint32_t i = 0; i < g->trap_count; i++)
        if (!strcmp(g->traps[i].name, name)) return g->traps[i].address;
    if (g->trap_count >= MAX_TRAPS || g->next_trap >= STOP_ADDR) return 0;
    uint32_t address = g->next_trap; g->next_trap += 4;
    uint32_t svc = 0xef000000u | ((address - TRAP_BASE) / 4);
    write_u32(g, address, svc);
    g->traps[g->trap_count].address = address;
    g->traps[g->trap_count].name = copy_string(name);
    g->trap_count++;
    return address;
}
static uint32_t resolve_import_cb(void *user, const char *name, uint32_t symbol_type) {
    agr_guest *g = (agr_guest *)user;
    if (symbol_type == 1 || symbol_type == 6) {
        if (!strcmp(name, "_ctype_")) {
            uint8_t table[257] = {0};
            for (uint32_t value = 0; value < 256; value++) {
                uint8_t flags = 0;
                if (value >= 'A' && value <= 'Z') flags |= 0x01;
                if (value >= 'a' && value <= 'z') flags |= 0x02;
                if (value >= '0' && value <= '9') flags |= 0x04;
                if (value == ' ' || value == '\t' || value == '\r' || value == '\n' || value == '\v' || value == '\f') flags |= 0x08;
                if (value >= 32 && value <= 126 && !(flags & 0x0f)) flags |= 0x10;
                if (value < 32 || value == 127) flags |= 0x20;
                if ((value >= '0' && value <= '9') || (value >= 'a' && value <= 'f') || (value >= 'A' && value <= 'F')) flags |= 0x40;
                if (value == ' ' || value == '\t') flags |= 0x80;
                table[value + 1] = flags;
            }
            uint32_t address = agr_alloc_static(g->runtime, table, sizeof(table), 1);
            return agr_alloc_static(g->runtime, &address, sizeof(address), 4);
        }
        if (!strcmp(name, "__stack_chk_guard")) {
            uint32_t guard = 0xa5c39e71u;
            return agr_alloc_static(g->runtime, &guard, sizeof(guard), 4);
        }
        uint8_t zero[16] = {0};
        return agr_alloc_static(g->runtime, zero, sizeof(zero), 4);
    }
    return add_trap(g, name);
}
static const char *trap_name(agr_guest *g, uint32_t address) {
    for (uint32_t i = 0; i < g->trap_count; i++)
        if (g->traps[i].address == address) return g->traps[i].name;
    return NULL;
}
static void guest_return(agr_guest *g, uint32_t value, uint32_t value_r1) {
    uint32_t target = arm_interp_get_reg(guest_cpu(g), 14);
    uint32_t cpsr = arm_interp_get_cpsr(guest_cpu(g));
    arm_interp_set_reg(guest_cpu(g), 0, value);
    arm_interp_set_reg(guest_cpu(g), 1, value_r1);
    arm_interp_set_cpsr(guest_cpu(g), (target & 1) ? (cpsr | 0x20) : (cpsr & ~0x20));
    arm_interp_set_reg(guest_cpu(g), 15, target & ~1u);
}
static array_entry *find_array(agr_guest *g, uint32_t handle) {
    for (uint32_t i = 0; i < g->array_count; i++) if (g->arrays[i].handle == handle) return &g->arrays[i];
    return NULL;
}
static uint32_t jni_class_handle(agr_guest *g,const char *descriptor) {
    if(!g||!descriptor)return 0;
    for(uint32_t i=0;i<g->class_count;i++)if(!strcmp(g->classes[i].descriptor,descriptor))return g->classes[i].handle;
    if(g->class_count==g->class_capacity) {
        uint32_t next=g->class_capacity?g->class_capacity*2:16;
        jni_class *grown=realloc(g->classes,(size_t)next*sizeof(*grown));
        if(!grown)return 0;g->classes=grown;g->class_capacity=next;
    }
    char *copy=copy_string(descriptor);if(!copy)return 0;
    uint32_t handle=0x64000000u+g->class_count*4u;
    g->classes[g->class_count++]=(jni_class){handle,copy};return handle;
}
static const char *jni_class_descriptor(agr_guest *g,uint32_t handle) {
    for(uint32_t i=0;g&&i<g->class_count;i++)if(g->classes[i].handle==handle)return g->classes[i].descriptor;
    return NULL;
}
static uint32_t jni_string_handle(agr_guest *g,const char *text) {
    if(!g||!text)return 0;
    if(g->string_count==g->string_capacity) {
        uint32_t next=g->string_capacity?g->string_capacity*2:16;
        jni_string *grown=realloc(g->strings,(size_t)next*sizeof(*grown));
        if(!grown)return 0;g->strings=grown;g->string_capacity=next;
    }
    char *copy=copy_string(text);if(!copy)return 0;
    uint32_t handle=0x66000000u+g->string_count*4u;
    g->strings[g->string_count++]=(jni_string){handle,copy};return handle;
}
static const char *jni_string_text(agr_guest *g,uint32_t handle) {
    for(uint32_t i=0;g&&i<g->string_count;i++)if(g->strings[i].handle==handle)return g->strings[i].text;
    return NULL;
}
static char *jni_mangle(const char *text,int descriptor) {
    if(!text)return NULL;
    const char *start=text,*end=text+strlen(text);
    if(descriptor&&start<end&&*start=='L')start++;
    if(descriptor&&end>start&&end[-1]==';')end--;
    size_t capacity=(size_t)(end-start)*6+1;char *out=malloc(capacity);if(!out)return NULL;char *at=out;
    static const char hex[]="0123456789abcdef";
    for(const unsigned char *p=(const unsigned char *)start;p<(const unsigned char *)end;p++) {
        unsigned char c=*p;
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9'))*at++=(char)c;
        else if(c=='/'||c=='.')*at++='_';
        else if(c=='_'){*at++='_';*at++='1';}
        else if(c==';'){*at++='_';*at++='2';}
        else if(c=='['){*at++='_';*at++='3';}
        else {*at++='_';*at++='0';*at++='0';*at++='0';*at++=hex[c>>4];*at++=hex[c&15];}
    }
    *at=0;return out;
}
static uint32_t resolve_native_method(agr_guest *g,const char *class_descriptor,
                                      const char *name,const char *signature) {
    uint32_t class_handle=jni_class_handle(g,class_descriptor);
    uint32_t address=agr_jni_method_native_address(&g->methods,class_handle,name,signature);
    if(address)return address;
    char *cls=jni_mangle(class_descriptor,1),*method=jni_mangle(name,0);
    if(!cls||!method){free(cls);free(method);return 0;}
    size_t short_size=strlen(cls)+strlen(method)+7;
    char *short_name=malloc(short_size);if(short_name)snprintf(short_name,short_size,"Java_%s_%s",cls,method);
    address=short_name?agr_find_symbol(g->runtime,short_name):0;
    if(!address&&signature) {
        const char *begin=strchr(signature,'('),*end=begin?strchr(begin,')'):NULL;
        if(begin&&end) {
            size_t n=(size_t)(end-begin-1);char *params=malloc(n+1);
            if(params){memcpy(params,begin+1,n);params[n]=0;char *encoded=jni_mangle(params,0);free(params);
                if(encoded){size_t long_size=short_size+strlen(encoded)+2;char *long_name=malloc(long_size);
                    if(long_name){snprintf(long_name,long_size,"%s__%s",short_name,encoded);address=agr_find_symbol(g->runtime,long_name);free(long_name);}free(encoded);}}
        }
    }
    free(short_name);free(cls);free(method);return address;
}
static int32_t dex_native_bridge(void *user,const char *class_descriptor,
                                 const char *method_name,const char *signature,int is_static,
                                 const agr_dex_argument *arguments,uint32_t argument_count,
                                 agr_dex_argument *result) {
    agr_guest *g=(agr_guest *)user;
    uint32_t target=resolve_native_method(g,class_descriptor,method_name,signature);
    if(!target){snprintf(g->error,sizeof(g->error),"missing native binding %.80s",method_name);return -1;}
    uint32_t argv[18]={JNI_ENV_PTR,is_static?jni_class_handle(g,class_descriptor):0x60001000u};
    if(argument_count>16)return -1;
    uint32_t start=is_static?0:1;
    for(uint32_t i=start;i<argument_count;i++) {
        const agr_dex_argument *arg=&arguments[i];uint32_t value=0;
        if(arg->kind==AGR_DEX_ARG_INT)value=(uint32_t)arg->value.i;
        else if(arg->kind==AGR_DEX_ARG_FLOAT)memcpy(&value,&arg->value.f,4);
        else if(arg->kind==AGR_DEX_ARG_STRING)value=jni_string_handle(g,arg->value.string);
        else if(arg->kind==AGR_DEX_ARG_OBJECT)value=arg->value.object;
        argv[2+i-start]=value;
    }
    int32_t native_result=0;
    if(call_address(g,target,argv,2+argument_count-start,&native_result))return -1;
    if(result){result->kind=AGR_DEX_ARG_INT;result->value.i=native_result;}
    return 0;
}
static int32_t dex_load_library(void *user,const char *name) {
    return agr_guest_load_java_library((agr_guest *)user,name,NULL);
}
static int dispatch_jni_impl(agr_guest *g, uint32_t address) {
    record_process_import(g,"JNI");
    agr_guest_thread_context_record_call(guest_context(g),"JNI",
        arm_interp_get_reg(guest_cpu(g),15));
    if (address >= TRAP_BASE + 0x800 && address < TRAP_BASE + 0x900) {
        uint32_t slot = (address - TRAP_BASE - 0x800) / 4;
        if (slot == 4 || slot == 6) {
            uint32_t out = argument(g, 1); if (out) write_u32(g, out, JNI_ENV_PTR);
            guest_return(g, 0, 0); return 1;
        }
        if (slot == 5) { guest_return(g, 0, 0); return 1; }
        snprintf(g->error, sizeof(g->error), "unhandled JavaVM slot %u", slot); return -1;
    }
    if (address < TRAP_BASE + 16 || address >= TRAP_BASE + 233 * 4) return 0;
    uint32_t slot = (address - TRAP_BASE) / 4;
    if(slot==6) {
        char name[512];if(read_guest_string(g,argument(g,1),name,sizeof(name))){set_error(g,"JNI FindClass invalid name");return -1;}
        char descriptor[516];
        if(name[0]=='['||name[0]=='L')snprintf(descriptor,sizeof(descriptor),"%s",name);
        else snprintf(descriptor,sizeof(descriptor),"L%s;",name);
        if(!g->dex_game||agr_dex_game_resolve_class(g->dex_game,descriptor)){
            guest_return(g,0,0);return 1;
        }
        uint32_t handle=jni_class_handle(g,descriptor);
        if(!handle){set_error(g,"JNI FindClass allocation failed");return -1;}
        guest_return(g,handle,0);return 1;
    }
    if (slot == 31) {
        const char *activity=agr_dex_game_activity_descriptor(g->dex_game);
        uint32_t handle=jni_class_handle(g,activity?activity:"Ljava/lang/Object;");
        guest_return(g,handle,0); return 1;
    }
    if (slot == 33 || slot == 113) {
        char name[256], signature[256];
        if (read_guest_string(g,argument(g,2),name,sizeof(name)) ||
            read_guest_string(g,argument(g,3),signature,sizeof(signature))) {
            set_error(g,"JNI GetMethodID invalid strings"); return -1;
        }
        const char *descriptor=jni_class_descriptor(g,argument(g,1));
        if(!descriptor||!g->dex_game||agr_dex_game_resolve_method(g->dex_game,descriptor,name,signature,slot==113)) {
            guest_return(g,0,0);return 1;
        }
        uint32_t handle=0;
        if (agr_jni_method_id(&g->methods,argument(g,1),name,signature,&handle)) {
            set_error(g,"JNI GetMethodID registry allocation failed"); return -1;
        }
        guest_return(g,handle,0); return 1;
    }
    if (slot == 167) {
        char text[512]; if (read_guest_string(g,argument(g,1),text,sizeof(text))) {
            set_error(g,"JNI NewStringUTF invalid string"); return -1;
        }
        uint32_t handle=jni_string_handle(g,text);
        if(!handle){set_error(g,"JNI NewStringUTF allocation failed");return -1;}
        guest_return(g,handle,0); return 1;
    }
    if(slot==168){const char *text=jni_string_text(g,argument(g,1));guest_return(g,text?(uint32_t)strlen(text):0,0);return 1;}
    if(slot==169){const char *text=jni_string_text(g,argument(g,1));if(!text){set_error(g,"JNI GetStringUTFChars invalid string");return -1;}uint32_t p=agr_alloc_static(g->runtime,text,(uint32_t)strlen(text)+1,1);if(argument(g,2)){uint8_t copy=1;arm_interp_write(guest_cpu(g),argument(g,2),&copy,1);}guest_return(g,p,0);return p?1:-1;}
    if(slot==170){guest_return(g,0,0);return 1;}
    if(slot==215) {
        uint32_t class_handle=argument(g,1),methods=argument(g,2),count=argument(g,3);
        if(!jni_class_descriptor(g,class_handle)||count>4096){set_error(g,"JNI RegisterNatives invalid class/count");return -1;}
        for(uint32_t i=0;i<count;i++) {
            uint32_t name_ptr=read_u32(g,methods+i*12),sig_ptr=read_u32(g,methods+i*12+4),fn=read_u32(g,methods+i*12+8);
            char name[256],signature[512];
            if(read_guest_string(g,name_ptr,name,sizeof(name))||read_guest_string(g,sig_ptr,signature,sizeof(signature))||
               agr_dex_game_resolve_method(g->dex_game,jni_class_descriptor(g,class_handle),name,signature,-1)||
               agr_jni_method_bind(&g->methods,class_handle,name,signature,fn)) {
                set_error(g,"JNI RegisterNatives invalid method");return -1;
            }
        }
        guest_return(g,0,0);return 1;
    }
    if (slot == 21 || slot == 23 || slot == 22) {
        guest_return(g,slot==21 ? argument(g,1) : 0,0); return 1;
    }
    if (slot >= 49 && slot <= 51) {
        uint32_t method_handle=argument(g,2);
        const agr_jni_method *method=agr_jni_method_lookup(&g->methods,method_handle);
        if (!method) { set_error(g,"JNI CallIntMethod unknown method"); return -1; }
        agr_dex_argument dex_args[8]; uint32_t dex_count=0, word=0;
        const char *at=strchr(method->signature,'(');
        uint32_t argv=argument(g,3);
        if (!at) { set_error(g,"JNI method signature invalid"); return -1; }
        for (at++;*at && *at!=')' && dex_count<8;dex_count++) {
            uint32_t bits=slot==49?argument(g,3+word):read_u32(g,argv+(slot==51?word*8:word*4));
            if (*at=='F') { float value=0;memcpy(&value,&bits,4);dex_args[dex_count].kind=AGR_DEX_ARG_FLOAT;dex_args[dex_count].value.f=value;at++;word++; }
            else if (*at=='I'||*at=='Z'||*at=='B'||*at=='C'||*at=='S') { dex_args[dex_count].kind=AGR_DEX_ARG_INT;dex_args[dex_count].value.i=(int32_t)bits;at++;word++; }
            else if (*at=='L'||*at=='[') {
                const char *text=NULL;
                text=jni_string_text(g,bits);
                if (text) { dex_args[dex_count].kind=AGR_DEX_ARG_STRING;dex_args[dex_count].value.string=text; }
                else dex_args[dex_count].kind=AGR_DEX_ARG_NULL;
                if (*at=='L') { while(*at&&*at!=';')at++;if(*at==';')at++; } else { while(*at=='[')at++;if(*at=='L'){while(*at&&*at!=';')at++;if(*at==';')at++;}else if(*at)at++; }
                word++;
            } else { set_error(g,"JNI CallIntMethod unsupported argument type");return -1; }
        }
        int32_t value=0;
        if (!g->dex_game || agr_dex_game_invoke_int(g->dex_game,method->name,method->signature,
                                                     dex_args,dex_count,&value)) {
            snprintf(g->error,sizeof(g->error),"JNI generic DEX invocation failed %.80s",method->name);return -1;
        }
        guest_return(g,(uint32_t)value,0); return 1;
    }
    if (slot >= 61 && slot <= 63) { guest_return(g,0,0); return 1; }
    uint32_t handle = argument(g, 1);
    array_entry *array = find_array(g, handle);
    if (slot == 171) { guest_return(g, array ? array->count : 0, 0); return 1; }
    if (slot == 186 || slot == 187 || slot == 189 || slot == 222) {
        if (!array) { set_error(g, "JNI primitive array handle not found"); return -1; }
        if (argument(g, 2)) { uint8_t one = 1; arm_interp_write(guest_cpu(g), argument(g, 2), &one, 1); }
        guest_return(g, array->address, 0); return 1;
    }
    if (slot == 194 || slot == 195 || slot == 197 || slot == 223) {
        guest_return(g, 0, 0); return 1;
    }
    snprintf(g->error, sizeof(g->error), "unhandled JNI slot %u", slot);
    return -1;
}
static int dispatch_jni(agr_guest *g,uint32_t address) {
    agr_guest_thread_context *context=guest_context(g);
    if (!context) return -1;
    const int outer=context->jni_dispatch_depth++==0;
    if (outer) while (atomic_flag_test_and_set_explicit(&g->jni_lock,memory_order_acquire)) {}
    int result=dispatch_jni_impl(g,address);
    if (outer) atomic_flag_clear_explicit(&g->jni_lock,memory_order_release);
    context->jni_dispatch_depth--;
    return result;
}
static size_t gl_type_size(GLenum type) {
    switch (type) { case GL_BYTE: case GL_UNSIGNED_BYTE: return 1; case GL_SHORT: case GL_UNSIGNED_SHORT: return 2; case GL_FLOAT: case GL_FIXED: return 4; default: return 0; }
}
static GLfloat float_argument(agr_guest *g, uint32_t index) {
    uint32_t bits=argument(g,index); GLfloat value; memcpy(&value,&bits,4); return value;
}
static void apply_client_array(agr_guest *g, client_array *a, uint32_t vertices,
                               void (*setter)(GLint, GLenum, GLsizei, const void *), void **owned) {
    if (!a->active) return;
    size_t stride = a->stride ? (size_t)a->stride : (size_t)a->size * gl_type_size(a->type);
    size_t size = stride * vertices;
    void *buffer = malloc(size ? size : 1);
    if (size) arm_interp_read(guest_cpu(g), a->pointer, (uint8_t *)buffer, (uint32_t)size);
    setter(a->size, a->type, a->stride, buffer); *owned = buffer;
}
static void set_normal_pointer(GLint size, GLenum type, GLsizei stride, const void *pointer) {
    (void)size;
    glNormalPointer(type, stride, pointer);
}
static int dispatch_egl(agr_guest *g, const char *name) {
    if (strncmp(name,"egl",3) != 0) return 0;
    const uint32_t thread_id=guest_context(g)->guest_thread_id;
    if (!g->egl_owner_thread_id) g->egl_owner_thread_id=thread_id;
    if (g->egl_owner_thread_id != thread_id) {
        set_error(g,"EGL call executed outside EGLContextOwner");
        return -1;
    }
    if (!strcmp(name, "eglGetDisplay")) {
        if (!g->display) {
            PFNEGLGETPLATFORMDISPLAYEXTPROC get = (PFNEGLGETPLATFORMDISPLAYEXTPROC)eglGetProcAddress("eglGetPlatformDisplayEXT");
            EGLint attributes[] = {EGL_PLATFORM_ANGLE_TYPE_ANGLE,
#ifdef _WIN32
                EGL_PLATFORM_ANGLE_TYPE_D3D11_ANGLE,
#else
                EGL_PLATFORM_ANGLE_TYPE_METAL_ANGLE,
#endif
                EGL_NONE};
            g->display = get ? get(EGL_PLATFORM_ANGLE_ANGLE,EGL_DEFAULT_DISPLAY,attributes) : EGL_NO_DISPLAY;
        }
        guest_return(g,g->display ? GUEST_EGL_DISPLAY : 0,0); return 1;
    }
    if (!strcmp(name, "eglInitialize")) {
        EGLint major=0,minor=0; EGLBoolean ok = g->display && eglInitialize(g->display,&major,&minor);
        if (ok && argument(g,1)) write_u32(g,argument(g,1),(uint32_t)major);
        if (ok && argument(g,2)) write_u32(g,argument(g,2),(uint32_t)minor);
        guest_return(g,ok,0); return 1;
    }
    if (!strcmp(name, "eglChooseConfig")) {
        EGLint attrs[64], n=0, found=0;
        uint32_t pointer=argument(g,1);
        do { attrs[n]=(EGLint)read_u32(g,pointer+n*4); n++; } while (n<64 && attrs[n-1]!=EGL_NONE);
        if (n==64 && attrs[63]!=EGL_NONE) { set_error(g,"EGL attribute list exceeds 64 values"); return -1; }
        for (EGLint i=0; i+1<n && attrs[i]!=EGL_NONE; i+=2)
            if (attrs[i]==EGL_SURFACE_TYPE && (attrs[i+1]&EGL_WINDOW_BIT))
                attrs[i+1]=(attrs[i+1]&~EGL_WINDOW_BIT)|EGL_PBUFFER_BIT;
        EGLBoolean ok=eglChooseConfig(g->display,attrs,&g->config,1,&found);
        if (ok && found && argument(g,2)) write_u32(g,argument(g,2),GUEST_EGL_CONFIG);
        if (argument(g,4)) write_u32(g,argument(g,4),found);
        guest_return(g,ok,0); return 1;
    }
    if (!strcmp(name, "eglGetConfigAttrib")) {
        EGLint value=0; EGLBoolean ok=eglGetConfigAttrib(g->display,g->config,(EGLint)argument(g,2),&value);
        if (ok && argument(g,3)) write_u32(g,argument(g,3),(uint32_t)value);
        guest_return(g,ok,0); return 1;
    }
    if (!strcmp(name, "eglCreateWindowSurface")) {
        if (!g->width) g->width=320;
        if (!g->height) g->height=480;
        EGLint attrs[]={EGL_WIDTH,g->width,EGL_HEIGHT,g->height,EGL_NONE};
        g->surface=eglCreatePbufferSurface(g->display,g->config,attrs);
        guest_return(g,g->surface ? GUEST_EGL_SURFACE : 0,0); return 1;
    }
    if (!strcmp(name, "eglCreateContext")) {
        EGLint attrs[32],n=0; uint32_t pointer=argument(g,3);
        if (pointer) do { attrs[n]=(EGLint)read_u32(g,pointer+n*4); n++; } while(n<32 && attrs[n-1]!=EGL_NONE);
        else attrs[n++]=EGL_NONE;
        g->context=eglCreateContext(g->display,g->config,EGL_NO_CONTEXT,attrs);
        guest_return(g,g->context ? GUEST_EGL_CONTEXT : 0,0); return 1;
    }
    if (!strcmp(name, "eglMakeCurrent")) {
        EGLBoolean ok=eglMakeCurrent(g->display,g->surface,g->surface,g->context);
        if (ok) { const GLubyte *renderer=glGetString(GL_RENDERER); if (renderer) snprintf(g->renderer,sizeof(g->renderer),"%s",renderer); }
        guest_return(g,ok,0); return 1;
    }
    if (!strcmp(name, "eglQuerySurface")) {
        EGLint value=0; EGLBoolean ok=eglQuerySurface(g->display,g->surface,(EGLint)argument(g,2),&value);
        if (ok && argument(g,3)) write_u32(g,argument(g,3),(uint32_t)value);
        guest_return(g,ok,0); return 1;
    }
    if (!strcmp(name, "eglSwapBuffers")) {
        uint32_t needed=(uint32_t)(g->width*g->height*4);
        while (atomic_flag_test_and_set_explicit(&g->framebuffer_lock,memory_order_acquire)) {}
        if (needed>g->framebuffer_capacity) {
            uint8_t *replacement=(uint8_t *)realloc(g->framebuffer,needed);
            if (replacement) { g->framebuffer=replacement; g->framebuffer_capacity=needed; }
        }
        if (g->framebuffer && g->framebuffer_capacity>=needed) {
            glFinish(); glReadPixels(0,0,g->width,g->height,GL_RGBA,GL_UNSIGNED_BYTE,g->framebuffer);
            g->framebuffer_size=glGetError()==GL_NO_ERROR?needed:0;
        }
        atomic_flag_clear_explicit(&g->framebuffer_lock,memory_order_release);
        atomic_fetch_add_explicit(&g->swap_count,1u,memory_order_release);
        guest_return(g,eglSwapBuffers(g->display,g->surface),0);
        return 1;
    }
    return 0;
}
static int dispatch_graphics(agr_guest *g, const char *name) {
    if (!strncmp(name,"gl",2)) {
        const uint32_t thread_id=guest_context(g)->guest_thread_id;
        if (!g->egl_owner_thread_id) g->egl_owner_thread_id=thread_id;
        if (g->egl_owner_thread_id != thread_id) {
            set_error(g,"GLES call executed outside EGLContextOwner");
            return -1;
        }
    }
    if (!strcmp(name,"glEnable")) { glEnable(argument(g,0)); guest_return(g,0,0); return 1; }
    if (!strcmp(name,"glDisable")) { glDisable(argument(g,0)); guest_return(g,0,0); return 1; }
    if (!strcmp(name,"glEnableClientState")) { glEnableClientState(argument(g,0)); guest_return(g,0,0); return 1; }
    if (!strcmp(name,"glDisableClientState")) { glDisableClientState(argument(g,0)); guest_return(g,0,0); return 1; }
    if (!strcmp(name,"glGetError")) { guest_return(g,glGetError(),0); return 1; }
    if (!strcmp(name,"glDepthFunc")) { glDepthFunc(argument(g,0)); guest_return(g,0,0); return 1; }
    if (!strcmp(name,"glDepthMask")) { glDepthMask(argument(g,0)); guest_return(g,0,0); return 1; }
    if (!strcmp(name,"glHint")) { glHint(argument(g,0),argument(g,1)); guest_return(g,0,0); return 1; }
    if (!strcmp(name,"glBlendFunc")) { glBlendFunc(argument(g,0),argument(g,1)); guest_return(g,0,0); return 1; }
    if (!strcmp(name,"glClearColor")) { glClearColor(float_argument(g,0),float_argument(g,1),float_argument(g,2),float_argument(g,3)); guest_return(g,0,0); return 1; }
    if (!strcmp(name,"glColor4f")) { glColor4f(float_argument(g,0),float_argument(g,1),float_argument(g,2),float_argument(g,3)); guest_return(g,0,0); return 1; }
    if (!strcmp(name,"glViewport")) { glViewport((GLint)argument(g,0),(GLint)argument(g,1),(GLsizei)argument(g,2),(GLsizei)argument(g,3)); guest_return(g,0,0); return 1; }
    if (!strcmp(name,"glClear")) { glClear(argument(g,0)); guest_return(g,0,0); return 1; }
    if (!strcmp(name,"glMatrixMode")) { glMatrixMode(argument(g,0)); guest_return(g,0,0); return 1; }
    if (!strcmp(name,"glLoadIdentity")) { glLoadIdentity(); guest_return(g,0,0); return 1; }
    if (!strcmp(name,"glMultMatrixf")) { GLfloat values[16]; arm_interp_read(guest_cpu(g),argument(g,0),(uint8_t *)values,sizeof(values)); glMultMatrixf(values); guest_return(g,0,0); return 1; }
    if (!strcmp(name,"glTranslatef")) { glTranslatef(float_argument(g,0),float_argument(g,1),float_argument(g,2)); guest_return(g,0,0); return 1; }
    if (!strcmp(name,"glBindTexture")) { glBindTexture(argument(g,0),argument(g,1)); guest_return(g,0,0); return 1; }
    if (!strcmp(name,"glTexParameteri")) { glTexParameteri(argument(g,0),argument(g,1),(GLint)argument(g,2)); guest_return(g,0,0); return 1; }
    if (!strcmp(name, "glVertexPointer") || !strcmp(name, "glColorPointer") || !strcmp(name, "glTexCoordPointer")) {
        client_array *a = !strcmp(name, "glVertexPointer") ? &g->vertex : (!strcmp(name, "glColorPointer") ? &g->color : &g->texcoord);
        a->size = (int32_t)argument(g, 0); a->type = argument(g, 1); a->stride = (int32_t)argument(g, 2); a->pointer = argument(g, 3); a->active = 1;
        guest_return(g, 0, 0); return 1;
    }
    if (!strcmp(name, "glNormalPointer")) {
        g->normal.size = 3; g->normal.type = argument(g, 0);
        g->normal.stride = (int32_t)argument(g, 1);
        g->normal.pointer = argument(g, 2); g->normal.active = 1;
        guest_return(g, 0, 0); return 1;
    }
    if (!strcmp(name, "glDrawArrays") || !strcmp(name, "glDrawElements")) {
        GLenum mode = argument(g, 0); uint32_t count, first = 0, vertices = 0; GLenum index_type = 0; void *indices = NULL;
        if (!strcmp(name, "glDrawArrays")) { first = argument(g, 1); count = argument(g, 2); vertices = first + count; }
        else {
            count = argument(g, 1); index_type = argument(g, 2); size_t isz = gl_type_size(index_type);
            indices = malloc(count * isz); arm_interp_read(guest_cpu(g), argument(g, 3), (uint8_t *)indices, (uint32_t)(count * isz));
            for (uint32_t i = 0; i < count; i++) { uint32_t v = isz == 2 ? ((uint16_t *)indices)[i] : ((uint8_t *)indices)[i]; if (v + 1 > vertices) vertices = v + 1; }
        }
        void *vb = NULL, *cb = NULL, *tb = NULL, *nb = NULL;
        apply_client_array(g, &g->vertex, vertices, glVertexPointer, &vb);
        apply_client_array(g, &g->color, vertices, glColorPointer, &cb);
        apply_client_array(g, &g->texcoord, vertices, glTexCoordPointer, &tb);
        apply_client_array(g, &g->normal, vertices, set_normal_pointer, &nb);
        if (!strcmp(name, "glDrawArrays")) glDrawArrays(mode, (GLint)first, (GLsizei)count);
        else glDrawElements(mode, (GLsizei)count, index_type, indices);
        atomic_fetch_add_explicit(&g->draw_count,1u,memory_order_relaxed);
        free(vb); free(cb); free(tb); free(nb); free(indices);
        guest_return(g, 0, 0); return 1;
    }
    return 0;
}
static int dispatch_import(agr_guest *g, const char *name) {
    if (!guest_context(g)) { set_error(g,"guest import has no current GuestThreadContext"); return -1; }
    agr_guest_thread_context_record_call(guest_context(g),name,
        arm_interp_get_reg(guest_cpu(g),15));
    record_process_import(g,name);
    if (!strcmp(name,"__android_log_print")) {
        uint32_t fmt_address=argument(g,2), value_address=argument(g,3);
        char fmt[12]={0}, value[104]={0};
        for(uint32_t i=0;i<sizeof(fmt)-1;i++) {
            if(arm_interp_read(guest_cpu(g),fmt_address+i,(uint8_t *)&fmt[i],1)||!fmt[i])break;
        }
        if(!strcmp(fmt,"%s")) {
            for(uint32_t i=0;i<sizeof(value)-1;i++) {
                if(arm_interp_read(guest_cpu(g),value_address+i,(uint8_t *)&value[i],1)||!value[i])break;
            }
            snprintf(g->last_log,sizeof(g->last_log),"%s",value);
        }
    }
    if (!strcmp(name,"ANativeWindow_setBuffersGeometry")) {
        int32_t width=(int32_t)argument(g,1), height=(int32_t)argument(g,2);
        g->width=width>0?width:320; g->height=height>0?height:480;
        guest_return(g,0,0); return 1;
    }
    int egl = dispatch_egl(g,name); if (egl) return egl;
    int graphics=dispatch_graphics(g,name); if (graphics) return graphics;
    if (!strcmp(name, "AConfiguration_new")) { guest_return(g, agr_malloc(g->runtime, 64), 0); return 1; }
    if (!strcmp(name, "AConfiguration_delete")) { agr_free(g->runtime, argument(g, 0)); guest_return(g, 0, 0); return 1; }
    if (!strcmp(name, "AConfiguration_fromAssetManager")) { guest_return(g, 0, 0); return 1; }
    if (!strcmp(name, "AConfiguration_getLanguage") || !strcmp(name, "AConfiguration_getCountry")) {
        const char *value = !strcmp(name, "AConfiguration_getLanguage") ? "en" : "US";
        arm_interp_write(guest_cpu(g), argument(g, 1), (const uint8_t *)value, 2);
        guest_return(g, 0, 0); return 1;
    }
    if (!strcmp(name, "ALooper_prepare")) {
        if (!g->looper_handle) g->looper_handle = agr_malloc(g->runtime, 32);
        guest_return(g, g->looper_handle, 0); return 1;
    }
    if (!strcmp(name, "ALooper_addFd")) {
        if (argument(g, 0) != g->looper_handle || g->looper_fd_count >= 16) {
            set_error(g, "ALooper_addFd invalid looper or fd table full"); return -1;
        }
        looper_fd *fd = &g->looper_fds[g->looper_fd_count++];
        fd->fd = argument(g, 1); fd->ident = argument(g, 2); fd->events = argument(g, 3);
        fd->callback = argument(g, 4); fd->data = argument(g, 5);
        guest_return(g, 1, 0); return 1;
    }
    if (!strcmp(name, "ALooper_pollAll")) {
        uint32_t result = 0xffffffffu;
        while (atomic_flag_test_and_set_explicit(&g->input_lock,memory_order_acquire)) {}
        if (g->input_count && g->input_ident) {
            if (argument(g,1)) write_u32(g,argument(g,1),0xffffffffu);
            if (argument(g,2)) write_u32(g,argument(g,2),1);
            if (argument(g,3)) write_u32(g,argument(g,3),g->input_data);
            result=g->input_ident;
        }
        atomic_flag_clear_explicit(&g->input_lock,memory_order_release);
        for (uint32_t i = 0; result==0xffffffffu && i < g->looper_fd_count; i++) {
            looper_fd *fd = &g->looper_fds[i]; virtual_pipe *pipe = find_pipe(g, fd->fd);
            if (!pipe || pipe->size == pipe->read_offset) continue;
            if (argument(g, 1)) write_u32(g, argument(g, 1), fd->fd);
            if (argument(g, 2)) write_u32(g, argument(g, 2), fd->events);
            if (argument(g, 3)) write_u32(g, argument(g, 3), fd->data);
            result = fd->ident; break;
        }
        guest_return(g, result, 0);
        return 1;
    }
    if (!strcmp(name,"AInputQueue_attachLooper")) {
        if (argument(g,0)!=g->input_queue_handle) { set_error(g,"AInputQueue_attachLooper invalid queue"); return -1; }
        g->looper_handle=argument(g,1); g->input_ident=argument(g,2); g->input_data=argument(g,4);
        guest_return(g,0,0); return 1;
    }
    if (!strcmp(name,"AInputQueue_detachLooper")) { g->input_ident=g->input_data=0; guest_return(g,0,0); return 1; }
    if (!strcmp(name,"AInputQueue_getEvent")) {
        while (atomic_flag_test_and_set_explicit(&g->input_lock,memory_order_acquire)) {}
        if (argument(g,0)!=g->input_queue_handle || !g->input_count) {
            atomic_flag_clear_explicit(&g->input_lock,memory_order_release);
            guest_return(g,0xffffffffu,0); return 1;
        }
        uint32_t handle=g->input_events[g->input_head%32].handle;
        atomic_flag_clear_explicit(&g->input_lock,memory_order_release);
        write_u32(g,argument(g,1),handle);
        guest_return(g,0,0); return 1;
    }
    if (!strcmp(name,"AInputQueue_preDispatchEvent")) { guest_return(g,0,0); return 1; }
    if (!strcmp(name,"AInputQueue_finishEvent")) {
        while (atomic_flag_test_and_set_explicit(&g->input_lock,memory_order_acquire)) {}
        if (g->input_count && g->input_events[g->input_head%32].handle==argument(g,1)) {
            g->input_head++; g->input_count--; atomic_fetch_add_explicit(&g->input_consumed_count,1u,memory_order_relaxed);
        }
        atomic_flag_clear_explicit(&g->input_lock,memory_order_release);
        guest_return(g,0,0); return 1;
    }
    input_event event_value={0}; input_event *event=NULL; uint32_t event_handle=argument(g,0);
    while (atomic_flag_test_and_set_explicit(&g->input_lock,memory_order_acquire)) {}
    for(uint32_t i=0;i<g->input_count;i++){ input_event *candidate=&g->input_events[(g->input_head+i)%32]; if(candidate->handle==event_handle){event_value=*candidate;event=&event_value;break;} }
    atomic_flag_clear_explicit(&g->input_lock,memory_order_release);
    if (!strcmp(name,"AInputEvent_getType")) { guest_return(g,event?event->type:0,0); return 1; }
    if (!strcmp(name,"AMotionEvent_getAction")) { guest_return(g,event?event->action:0,0); return 1; }
    if (!strcmp(name,"AMotionEvent_getPointerCount")) { guest_return(g,event?event->pointer_count:0,0); return 1; }
    if (!strcmp(name,"AMotionEvent_getPointerId")) { guest_return(g,event?event->pointer_id:0,0); return 1; }
    if (!strcmp(name,"AMotionEvent_getX") || !strcmp(name,"AMotionEvent_getY")) {
        float value=event?(!strcmp(name,"AMotionEvent_getX")?event->x:event->y):0.0f; uint32_t bits=0; memcpy(&bits,&value,4);
        guest_return(g,bits,0); return 1;
    }
    if (!strcmp(name, "AAssetManager_open")) {
        char path[1024]; uint32_t address = argument(g, 1), i = 0;
        do { if (i + 1 >= sizeof(path) || arm_interp_read(guest_cpu(g), address+i, (uint8_t *)&path[i], 1)) {
            set_error(g, "AAssetManager_open invalid guest path"); return -1;
        } } while (path[i++]);
        agr_afw_asset *asset = g->assets ? agr_afw_open(g->assets, path, (int)argument(g, 2)) : NULL;
        uint32_t handle = 0;
        if (asset) for (uint32_t slot = 0; slot < 64; slot++) if (!g->open_assets[slot].asset) {
            handle = g->next_asset_handle; g->next_asset_handle += 4;
            g->open_assets[slot] = (asset_entry){handle,asset}; break;
        }
        if (handle) g->asset_open_count++;
        if (asset && !handle) agr_afw_close(asset);
        guest_return(g, handle, 0); return 1;
    }
    if (!strcmp(name, "AAsset_read") || !strcmp(name, "AAsset_close") ||
        !strcmp(name, "AAsset_getLength") || !strcmp(name, "AAsset_seek")) {
        asset_entry *entry = find_asset(g, argument(g, 0));
        if (!entry) { guest_return(g, 0xffffffffu, 0); return 1; }
        if (!strcmp(name, "AAsset_close")) {
            agr_afw_close(entry->asset); entry->asset = NULL; guest_return(g, 0, 0); return 1;
        }
        if (!strcmp(name, "AAsset_getLength")) {
            guest_return(g, (uint32_t)agr_afw_length(entry->asset), 0); return 1;
        }
        if (!strcmp(name, "AAsset_seek")) {
            guest_return(g, (uint32_t)agr_afw_seek(entry->asset,(int32_t)argument(g, 1),(int)argument(g, 2)), 0); return 1;
        }
        uint32_t count = argument(g, 2); uint8_t buffer[4096]; uint32_t done = 0;
        while (done < count) {
            size_t size = count-done < sizeof(buffer) ? count-done : sizeof(buffer);
            int64_t got = agr_afw_read(entry->asset,buffer,size);
            if (got < 0) { guest_return(g, 0xffffffffu, 0); return 1; }
            if (!got) break;
            if (arm_interp_write(guest_cpu(g),argument(g, 1)+done,buffer,(uint32_t)got)) {
                set_error(g, "AAsset_read invalid guest buffer"); return -1;
            }
            done += (uint32_t)got; if ((size_t)got < size) break;
        }
        guest_return(g, done, 0); return 1;
    }
    uint32_t regs[4] = { argument(g, 0), argument(g, 1), argument(g, 2), argument(g, 3) };
    agr_dispatch_result out = {0};
    if (agr_dispatch_system(g->runtime, name, regs, arm_interp_get_reg(guest_cpu(g), 13), &out) == 0 && out.handled) {
        if (out.action == AGR_ACTION_ABORT) {
            snprintf(g->error, sizeof(g->error), "guest aborted in %s lr=%08x r0=%08x last_log=%.110s",
                     name, arm_interp_get_reg(guest_cpu(g), 14), argument(g, 0), g->last_log);
            return -1;
        }
        if (out.action == AGR_ACTION_THREAD_EXIT) {
            agr_guest_thread_context *context=guest_context(g);
            context->exit_result=out.action_arg0;
            context->lifecycle=AGR_GUEST_THREAD_EXITED;
            return 3;
        }
        if (out.action == AGR_ACTION_CALL_ONCE) {
            uint32_t saved[16], saved_cpsr = arm_interp_get_cpsr(guest_cpu(g));
            for (uint32_t i = 0; i < 16; i++) saved[i] = arm_interp_get_reg(guest_cpu(g), i);
            if (call_address(g, out.action_arg0, NULL, 0, NULL)) return -1;
            for (uint32_t i = 0; i < 16; i++) arm_interp_set_reg(guest_cpu(g), i, saved[i]);
            arm_interp_set_cpsr(guest_cpu(g), saved_cpsr);
            agr_complete_once(g->runtime, out.action_arg1);
        } else if (out.action != AGR_ACTION_NONE) {
            snprintf(g->error, sizeof(g->error), "unsupported nested system action %u in %s", out.action, name); return -1;
        }
        guest_return(g, out.value, out.value_r1); return 1;
    }
    snprintf(g->error, sizeof(g->error), "unhandled guest import %s", name); return -1;
}
static int run_until_return(agr_guest *g) {
    for (;;) {
        if (atomic_load_explicit(&g->shutting_down,memory_order_acquire)) return -1;
        uint64_t budget = g->run_budget; uint32_t svc = 0;
        arm_interp_set_thread_tag(guest_cpu(g), agr_current_thread(g->runtime));
        int32_t state = arm_interp_run(guest_cpu(g), &budget, &svc);
        uint32_t observed_pc=arm_interp_get_reg(guest_cpu(g),15);
        guest_context(g)->current_guest_pc=observed_pc;
        atomic_store_explicit(&g->last_guest_pc,observed_pc,memory_order_release);
        atomic_fetch_add_explicit(&g->instruction_count,g->run_budget-budget,memory_order_relaxed);
        if (state != 1) {
            uint32_t pc = arm_interp_get_reg(guest_cpu(g), 15), cpsr = arm_interp_get_cpsr(guest_cpu(g));
            uint8_t code[12] = {0}; arm_interp_read(guest_cpu(g), pc-8, code, sizeof(code));
            snprintf(g->error, sizeof(g->error),
                     "%s state=%d pc=%08x cpsr=%08x r0=%08x r1=%08x r2=%08x r3=%08x r4=%08x r5=%08x sp=%08x code[-8]=%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
                     state == 0 ? "ARM instruction budget exhausted" :
                     state == -2 ? "ARM guest memory fault" : "ARM interpreter error",
                     state, pc, cpsr,arm_interp_get_reg(guest_cpu(g),0),arm_interp_get_reg(guest_cpu(g),1),
                     arm_interp_get_reg(guest_cpu(g),2),arm_interp_get_reg(guest_cpu(g),3),
                     arm_interp_get_reg(guest_cpu(g),4),arm_interp_get_reg(guest_cpu(g),5),arm_interp_get_reg(guest_cpu(g),13),
                     code[0],code[1],code[2],code[3],code[4],code[5],code[6],code[7],
                     code[8],code[9],code[10],code[11]);
            return -1;
        }
        uint32_t address = arm_interp_get_reg(guest_cpu(g), 15) - 4;
        if (address == STOP_ADDR) return 0;
        int jni = dispatch_jni(g, address); if (jni < 0) return -1; if (jni > 0) continue;
        const char *name = trap_name(g, address);
        int imported = name ? dispatch_import(g, name) : -1;
        if (imported < 0) { if (!name) snprintf(g->error, sizeof(g->error), "unknown SVC trap 0x%x", address); return -1; }
        if (imported == 3) return 2;
    }
}

static int32_t call_address(agr_guest *g, uint32_t target, const uint32_t *args, uint32_t count, int32_t *result);
static int32_t invoke_linker_function(void *opaque,uint32_t function) {
    agr_guest *g=(agr_guest *)opaque;
    agr_guest_thread_context *context=guest_context(g);
    if (!context || !context->cpu) return -1;
    uint32_t saved[16];
    uint32_t cpsr=arm_interp_get_cpsr(context->cpu);
    for (uint32_t i=0;i<16;i++) saved[i]=arm_interp_get_reg(context->cpu,i);
    int32_t rc=call_address(g,function,NULL,0,NULL);
    for (uint32_t i=0;i<16;i++) arm_interp_set_reg(context->cpu,i,saved[i]);
    arm_interp_set_cpsr(context->cpu,cpsr);
    return rc;
}
static int32_t invoke_guest_args(void *opaque,uint32_t function,const uint32_t *args,uint32_t count) {
    return call_address((agr_guest *)opaque,function,args,count,NULL);
}

agr_guest *agr_guest_create(void) {
    agr_guest *g = (agr_guest *)calloc(1, sizeof(*g)); if (!g) return NULL;
    atomic_flag_clear_explicit(&g->thread_registry_lock,memory_order_release);
    atomic_flag_clear_explicit(&g->diagnostics_lock,memory_order_release);
    atomic_flag_clear_explicit(&g->jni_lock,memory_order_release);
    atomic_flag_clear_explicit(&g->input_lock,memory_order_release);
    atomic_flag_clear_explicit(&g->framebuffer_lock,memory_order_release);
    g->process_cpu = arm_interp_create(); g->run_budget = 1000000; g->next_trap = IMPORT_BASE; g->next_array_handle = 0x61000000u;
    g->next_asset_handle = 0x62010000u; g->input_queue_handle=0x67000000u; g->next_input_handle=0x67000100u;
    if (!g->process_cpu) { free(g); return NULL; }
    g->main_thread=agr_guest_thread_context_create_main(g,g->process_cpu,1,0,0,0);
    if (!g->main_thread) { arm_interp_destroy(g->process_cpu); free(g); return NULL; }
    agr_guest_thread_context_bind(g->main_thread);
    agr_callbacks cb = {0}; cb.user = g; cb.read = mem_read_cb; cb.write = mem_write_cb; cb.loader_write = mem_loader_write_cb; cb.protect = mem_protect_cb; cb.resolve_import = resolve_import_cb;
    cb.log = guest_log_cb;
    cb.invoke_guest = invoke_linker_function;
    cb.invoke_guest_args = invoke_guest_args;
    cb.execute_thread=guest_thread_execute; cb.current_thread=guest_current_thread_cb;
    cb.current_thread_context=guest_current_thread_context_cb;
    cb.atomic_load=guest_atomic_load_cb; cb.atomic_cas=guest_atomic_cas_cb;
    cb.atomic_exchange=guest_atomic_exchange_cb; cb.atomic_fetch_sub=guest_atomic_fetch_sub_cb;
    cb.memory_base=mem_base_cb;
    cb.pipe_create = pipe_create_cb; cb.fd_read = fd_read_cb; cb.fd_write = fd_write_cb; cb.fd_close = fd_close_cb;
    g->runtime = agr_runtime_create(&cb, 0x01008000, 0x01020000, 0x01900000, 0x02000000);
    if (!g->runtime) { agr_guest_thread_context_destroy(g->main_thread); arm_interp_destroy(g->process_cpu); free(g); return NULL; }
    g->main_thread->guest_stack_base=agr_malloc(g->runtime,0x40000u);
    g->main_thread->guest_stack_size=g->main_thread->guest_stack_base?0x40000u:0;
    g->main_thread->guest_tls_base=g->main_thread->guest_stack_base+0x40000u-560u;
    if (!g->main_thread->guest_stack_base || agr_runtime_attach_current_thread(g->runtime,1,1,g->main_thread->guest_tls_base)) {
        agr_runtime_destroy(g->runtime); agr_guest_thread_context_destroy(g->main_thread); arm_interp_destroy(g->process_cpu); free(g); return NULL;
    }
    g->main_thread->guest_errno_address=agr_runtime_errno_address(g->runtime,1);
    g->main_thread->pthread_handle=agr_runtime_current_pthread(g->runtime);
    g->main_thread->jni_env_handle=JNI_ENV_PTR;
    write_u32(g, JNI_ENV_PTR, JNI_TABLE);
    for (uint32_t slot = 4; slot < 233; slot++) { uint32_t trap = TRAP_BASE + slot * 4; write_u32(g, JNI_TABLE + slot * 4, trap); write_u32(g, trap, 0xef000000u | slot); }
    write_u32(g, JVM_PTR, JVM_TABLE);
    for (uint32_t slot = 4; slot <= 6; slot++) { uint32_t trap = TRAP_BASE + 0x800 + slot * 4; write_u32(g, JVM_TABLE + slot * 4, trap); write_u32(g, trap, 0xef000000u | ((trap - TRAP_BASE) / 4)); }
    write_u32(g, STOP_ADDR, 0xef000000u | ((STOP_ADDR - TRAP_BASE) / 4));
    return g;
}
void agr_guest_destroy(agr_guest *g) {
    if (!g) return;
    atomic_store_explicit(&g->shutting_down,1,memory_order_release);
    agr_runtime_shutdown_workers(g->runtime);
    for (uint32_t i = 0; i < 64; i++) if (g->open_assets[i].asset) agr_afw_close(g->open_assets[i].asset);
    if (g->assets) agr_afw_destroy(g->assets);
    if (g->dex_game) agr_dex_game_destroy(g->dex_game);
    agr_jni_method_table_destroy(&g->methods);
    for (uint32_t i=0; i<g->string_count; i++) free(g->strings[i].text);
    free(g->strings);
    for (uint32_t i=0; i<g->class_count; i++) free(g->classes[i].descriptor);
    free(g->classes);
    for (uint32_t i=0; i<g->java_library_count; i++) free(g->java_libraries[i].name);
    free(g->java_libraries);
    if (g->display != EGL_NO_DISPLAY && g->egl_owner_thread_id==g->main_thread->guest_thread_id) {
        eglMakeCurrent(g->display,EGL_NO_SURFACE,EGL_NO_SURFACE,EGL_NO_CONTEXT);
        if (g->context) eglDestroyContext(g->display,g->context);
        if (g->surface) eglDestroySurface(g->display,g->surface);
        eglTerminate(g->display);
    }
    for (uint32_t i = 0; i < g->trap_count; i++) free(g->traps[i].name);
    free(g->framebuffer);
    agr_runtime_detach_current_thread(g->runtime,1);
    agr_runtime_destroy(g->runtime); agr_guest_thread_context_destroy(g->main_thread); arm_interp_destroy(g->process_cpu); free(g);
}
const char *agr_guest_last_error(agr_guest *g) { return g ? g->error : "guest create failed"; }
const char *agr_guest_last_android_log(agr_guest *g) { return g ? g->last_log : ""; }
uint32_t agr_guest_program_counter(agr_guest *g) { return g ? atomic_load_explicit(&g->last_guest_pc,memory_order_acquire) : 0; }
int32_t agr_guest_load_elf(agr_guest *g, const char *name, const void *bytes, uint32_t size, uint32_t base) {
    return agr_guest_load_elf_handle(g,name,bytes,size,base,NULL);
}
int32_t agr_guest_load_elf_handle(agr_guest *g, const char *name, const void *bytes,
                                  uint32_t size, uint32_t base, uint32_t *object_handle) {
    if (!g) return -1;
    agr_load_result out = {0}; int32_t rc = agr_load_elf(g->runtime, name, bytes, size, base, &out);
    if (rc) { set_error(g, agr_last_error(g->runtime)); return rc; }
    if (object_handle) *object_handle=out.object_handle;
    return 0;
}
int32_t agr_guest_register_elf_source(agr_guest *g, const char *name,
                                      const void *bytes, uint32_t size) {
    if (!g || !name || !bytes || !size) return -1;
    int32_t rc=agr_register_elf_source(g->runtime,name,bytes,size,0);
    if (rc) set_error(g,"formal linker source registration failed");
    return rc;
}
uint32_t agr_guest_dlopen(agr_guest *g, const char *name) {
    uint32_t handle=g&&name?agr_dlopen(g->runtime,name):0;
    if (!handle && g) { const char *error=agr_dlerror(g->runtime); set_error(g,error?error:"dlopen failed"); }
    return handle;
}
uint32_t agr_guest_dlsym(agr_guest *g, uint32_t object_handle, const char *symbol) {
    uint32_t address=g&&symbol?agr_dlsym(g->runtime,object_handle,symbol):0;
    if (!address && g) { const char *error=agr_dlerror(g->runtime); set_error(g,error?error:"dlsym failed"); }
    return address;
}
int32_t agr_guest_dlclose(agr_guest *g, uint32_t object_handle) {
    int32_t rc=g?(int32_t)agr_dlclose(g->runtime,object_handle):-1;
    if (rc && g) { const char *error=agr_dlerror(g->runtime); set_error(g,error?error:"dlclose failed"); }
    return rc;
}
uint32_t agr_guest_find_symbol(agr_guest *g, const char *symbol) {
    return g && symbol ? agr_find_symbol(g->runtime, symbol) : 0;
}
void agr_guest_set_watch_pc(agr_guest *g, uint32_t pc) {
    if (g) arm_interp_set_watch_pc(guest_cpu(g), pc & ~1u);
}
uint32_t agr_guest_watch_hits(agr_guest *g) { return g ? arm_interp_watch_hits(guest_cpu(g)) : 0; }
uint32_t agr_guest_watch_reg(agr_guest *g, uint32_t reg) { return g ? arm_interp_watch_reg(guest_cpu(g),reg) : 0; }
uint32_t agr_guest_watch_cpsr(agr_guest *g) { return g ? arm_interp_watch_cpsr(guest_cpu(g)) : 0; }
int32_t agr_guest_watch_trace(agr_guest *g, uint32_t index, uint32_t *pc, uint32_t *instruction) {
    return g ? arm_interp_watch_trace(guest_cpu(g),index,pc,instruction) : -1;
}
uint32_t agr_guest_current_thread_id(agr_guest *g) { return g ? arm_interp_watch_thread_tag(guest_cpu(g)) : 0; }
void agr_guest_heap_diagnostics(agr_guest *g, uint32_t out[5]) {
    if(out)agr_heap_diagnostics(g?g->runtime:NULL,out);
}
uint32_t agr_guest_new_primitive_array(agr_guest *g, uint32_t kind, const void *bytes, uint32_t count) {
    if (!g || g->array_count >= MAX_ARRAYS) return 0;
    uint32_t element = kind == AGR_ARRAY_SHORT ? 2 : 4;
    uint32_t address = agr_alloc_static(g->runtime, bytes, count * element, 4); if (!address) return 0;
    array_entry *a = &g->arrays[g->array_count++]; a->handle = g->next_array_handle; g->next_array_handle += 4; a->kind = kind; a->count = count; a->address = address; return a->handle;
}
static int32_t call_address(agr_guest *g, uint32_t target, const uint32_t *args, uint32_t count, int32_t *result) {
    agr_guest_thread_context *context=guest_context(g);
    if (context->callback_depth >= 16) { set_error(g, "guest nested call depth exceeded"); return -1; }
    uint32_t initial_stack=context->guest_stack_size ?
        context->guest_tls_base-0x100u : STACK_TOP;
    uint32_t stack_top = initial_stack - context->callback_depth * 0x4000u;
    for (uint32_t i = 4; i < count; i++) write_u32(g, stack_top + (i - 4) * 4, args[i]);
    for (uint32_t i = 0; i < 4; i++) arm_interp_set_reg(guest_cpu(g), i, i < count ? args[i] : 0);
    arm_interp_set_cpsr(guest_cpu(g), (target & 1) ? 0x20u : 0u);
    arm_interp_set_reg(guest_cpu(g), 13, stack_top); arm_interp_set_reg(guest_cpu(g), 14, STOP_ADDR); arm_interp_set_reg(guest_cpu(g), 15, target & ~1u);
    context->callback_depth++;
    int rc = run_until_return(g);
    context->callback_depth--;
    if (rc < 0) return -1; if (result) *result = (int32_t)arm_interp_get_reg(guest_cpu(g), 0); return 0;
}
static int32_t guest_thread_execute(void *user, uint32_t guest_thread,
                                    uint32_t start, uint32_t argument,
                                    const struct agr_bionic_thread_attr *attr,
                                    uint32_t *return_value) {
    agr_guest *g=(agr_guest *)user;
    /* Worker CPU registers and stack/TLS are private. process_cpu remains the
     * shared ARM address-space anchor, therefore no guest pointer crosses a
     * Darwin ABI boundary. */
    agr_bionic_thread_attr default_attr;
    if (!attr) { agr_bionic_thread_attr_init(&default_attr); attr=&default_attr; }
    /* The Bionic mmap adapter reaches guest memory through the current
     * GuestThreadContext. Bind the worker before asking it to map its stack;
     * its CPU shares the process address space with the main guest CPU. */
    agr_guest_thread_context *context=agr_guest_thread_context_create(
        g,g->process_cpu,guest_thread,0,0,0);
    if (!context) return -1;
    agr_guest_thread_context_bind(context);
    uint32_t size=(attr->stack_size+4095u)&~4095u;
    uint32_t stack=attr->stack_base;
    if (!stack && agr_runtime_map_thread_stack(g->runtime,size,
                                               (attr->guard_size+4095u)&~4095u,
                                               &stack)) {
#if defined(__APPLE__)
        os_log_error(OS_LOG_DEFAULT,"AGR_THREAD stack_map_failed tid=%u size=%u guard=%u",guest_thread,size,attr->guard_size);
#endif
        agr_guest_thread_context_destroy(context);
        return -1;
    }
    agr_bionic_thread_stack_layout layout;
    if (agr_bionic_thread_compute_stack_layout(attr,stack,&layout)) {
#if defined(__APPLE__)
        os_log_error(OS_LOG_DEFAULT,"AGR_THREAD stack_layout_failed tid=%u stack=%08x",guest_thread,stack);
#endif
        if (!attr->stack_base) agr_runtime_unmap_thread_stack(g->runtime,stack,size);
        agr_guest_thread_context_destroy(context);
        return -1;
    }
    context->guest_stack_base=layout.base;
    context->guest_stack_size=layout.size;
    context->guest_tls_base=layout.tls_base;
    if (agr_runtime_attach_current_thread(g->runtime,guest_thread,0,context->guest_tls_base)) {
#if defined(__APPLE__)
        os_log_error(OS_LOG_DEFAULT,"AGR_THREAD attach_failed tid=%u",guest_thread);
#endif
        if (!layout.user_stack) {
            agr_runtime_unmap_thread_stack(g->runtime,stack,layout.size);
        }
        agr_guest_thread_context_destroy(context);
        return -1;
    }
    context->guest_errno_address=agr_runtime_errno_address(g->runtime,guest_thread);
    context->pthread_handle=agr_runtime_current_pthread(g->runtime);
    context->jni_env_handle=JNI_ENV_PTR;
    uint32_t args[1]={argument}; int32_t result=0;
    int32_t rc=call_address(g,start,args,1,&result);
#if defined(__APPLE__)
    if (rc) os_log_error(OS_LOG_DEFAULT,"AGR_THREAD guest_call_failed tid=%u pc=%08x error=%{public}s",guest_thread,arm_interp_get_reg(guest_cpu(g),15),g->error);
#endif
    if (context->lifecycle == AGR_GUEST_THREAD_EXITED) result=(int32_t)context->exit_result;
    context->exit_result=(uint32_t)result;
    context->lifecycle=AGR_GUEST_THREAD_EXITED;
    if (g->egl_owner_thread_id==guest_thread && g->display!=EGL_NO_DISPLAY) {
        eglMakeCurrent(g->display,EGL_NO_SURFACE,EGL_NO_SURFACE,EGL_NO_CONTEXT);
        if (g->context) eglDestroyContext(g->display,g->context);
        if (g->surface) eglDestroySurface(g->display,g->surface);
        eglTerminate(g->display);
        g->context=EGL_NO_CONTEXT; g->surface=EGL_NO_SURFACE;
        g->display=EGL_NO_DISPLAY; g->egl_owner_thread_id=0;
    }
    (void)agr_runtime_detach_current_thread(g->runtime,guest_thread);
    if (return_value) *return_value=(uint32_t)result;
    if (!layout.user_stack) {
        agr_runtime_unmap_thread_stack(g->runtime,stack,layout.size);
    }
    agr_guest_thread_context_destroy(context);
    return rc;
}
int32_t agr_guest_call_symbol(agr_guest *g, const char *symbol, const uint32_t *args, uint32_t count, int32_t *result) {
    uint32_t target = agr_find_symbol(g->runtime, symbol); if (!target) { snprintf(g->error, sizeof(g->error), "missing symbol %s", symbol); return -1; }
    return call_address(g, target, args, count, result);
}
int32_t agr_guest_call_address(agr_guest *g, uint32_t address, const uint32_t *args, uint32_t count, int32_t *result) {
    if (!g || !address) return -1;
    return call_address(g, address, args, count, result);
}
int32_t agr_guest_run_constructors_limit(agr_guest *g, uint32_t limit, uint32_t *executed) {
    if (!g) return -1;
    /* The KitKat linker invokes constructors during dlopen. This legacy
       entrypoint reports those calls without executing them again. */
    uint32_t total = agr_constructor_count(g->runtime);
    if (executed) *executed = total < limit ? total : limit;
    return 0;
}
int32_t agr_guest_run_constructors(agr_guest *g, uint32_t *executed) {
    return agr_guest_run_constructors_limit(g,UINT32_MAX,executed);
}
void agr_guest_set_instruction_budget(agr_guest *g, uint64_t instructions) {
    if (g) g->run_budget = instructions ? instructions : 1;
}
uint32_t agr_guest_alloc(agr_guest *g, const void *bytes, uint32_t size, uint32_t alignment) {
    return g ? agr_alloc_static(g->runtime, bytes, size, alignment ? alignment : 1) : 0;
}
int32_t agr_guest_read(agr_guest *g, uint32_t address, void *bytes, uint32_t size) {
    return g ? arm_interp_read(guest_cpu(g), address, (uint8_t *)bytes, size) : -1;
}
int32_t agr_guest_write(agr_guest *g, uint32_t address, const void *bytes, uint32_t size) {
    return g ? arm_interp_write(guest_cpu(g), address, (const uint8_t *)bytes, size) : -1;
}
uint32_t agr_guest_jni_env(agr_guest *g) { return g ? JNI_ENV_PTR : 0; }
uint32_t agr_guest_java_vm(agr_guest *g) { return g ? JVM_PTR : 0; }
int32_t agr_guest_mount_apk(agr_guest *g, const char *path) {
    if (!g || !path) return -1;
    if (!g->assets) g->assets = agr_afw_create();
    return g->assets ? agr_afw_add_apk(g->assets,path) : -1;
}
int32_t agr_guest_load_dex(agr_guest *g, const char *path) {
    if (!g || !path) return -1;
    if (g->dex_game) agr_dex_game_destroy(g->dex_game);
    g->dex_game=agr_dex_game_create(path);
    if (!g->dex_game) { set_error(g,"original DEX Runtime creation failed"); return -1; }
    return 0;
}
int32_t agr_guest_load_java_library(agr_guest *g,const char *name,int32_t *jni_version) {
    if(!g||!name||!*name)return -1;
    char soname[512];size_t n=strlen(name);
    if(n>6&&!strncmp(name,"lib",3)&&!strcmp(name+n-3,".so"))snprintf(soname,sizeof(soname),"%s",name);
    else snprintf(soname,sizeof(soname),"lib%s.so",name);
    for(uint32_t i=0;i<g->java_library_count;i++)if(!strcmp(g->java_libraries[i].name,soname)) {
        if(jni_version)*jni_version=g->java_libraries[i].jni_version;return 0;
    }
    uint32_t handle=agr_guest_dlopen(g,soname);if(!handle)return -1;
    int32_t version=0;uint32_t on_load=agr_dlsym(g->runtime,handle,"JNI_OnLoad");
    if(on_load){uint32_t args[2]={JVM_PTR,0};if(call_address(g,on_load,args,2,&version)){agr_guest_dlclose(g,handle);return -1;}}
    if(g->java_library_count==g->java_library_capacity){uint32_t next=g->java_library_capacity?g->java_library_capacity*2:8;java_library *grown=realloc(g->java_libraries,(size_t)next*sizeof(*grown));if(!grown){agr_guest_dlclose(g,handle);return -1;}g->java_libraries=grown;g->java_library_capacity=next;}
    char *copy=copy_string(soname);if(!copy){agr_guest_dlclose(g,handle);return -1;}
    g->java_libraries[g->java_library_count++]=(java_library){copy,handle,version};
    if(jni_version)*jni_version=version;return 0;
}
int32_t agr_guest_load_dex_package(agr_guest *g, const agr_apk_package *package) {
    if (!g || !package) return -1;
    if (g->dex_game) agr_dex_game_destroy(g->dex_game);
    g->dex_game=agr_dex_game_create_from_apk(package);
    if (!g->dex_game) { set_error(g,"APK-derived DEX Runtime creation failed"); return -1; }
    agr_dex_game_set_native_callback(g->dex_game,dex_native_bridge,g);
    agr_dex_game_set_load_library_callback(g->dex_game,dex_load_library,g);
    return 0;
}
int32_t agr_guest_start_dex_activity(agr_guest *g) {
    if (!g || !g->dex_game || agr_dex_game_start_activity(g->dex_game)) {
        if (g) set_error(g,"APK-derived Activity DEX startup failed");
        return -1;
    }
    return 0;
}
int32_t agr_guest_wait_for_swap(agr_guest *g, uint32_t previous, uint32_t timeout_ms) {
    if (!g) return -1;
    struct timespec delay={0,1000000};
    for (uint32_t elapsed=0; elapsed<timeout_ms; ++elapsed) {
        if (atomic_load_explicit(&g->swap_count,memory_order_acquire)>previous) return 0;
        if (g->error[0] || atomic_load_explicit(&g->shutting_down,memory_order_acquire)) return -1;
        nanosleep(&delay,NULL);
    }
    return 1;
}
int32_t agr_guest_create_gles1_pbuffer(agr_guest *g, int width, int height) {
    PFNEGLGETPLATFORMDISPLAYEXTPROC getPlatformDisplay = (PFNEGLGETPLATFORMDISPLAYEXTPROC)eglGetProcAddress("eglGetPlatformDisplayEXT");
    EGLint da[] = {EGL_PLATFORM_ANGLE_TYPE_ANGLE,
#ifdef _WIN32
        EGL_PLATFORM_ANGLE_TYPE_D3D11_ANGLE,
#else
        EGL_PLATFORM_ANGLE_TYPE_METAL_ANGLE,
#endif
        EGL_NONE};
    g->display = getPlatformDisplay ? getPlatformDisplay(EGL_PLATFORM_ANGLE_ANGLE, EGL_DEFAULT_DISPLAY, da) : EGL_NO_DISPLAY;
    EGLint major, minor; if (!g->display || !eglInitialize(g->display, &major, &minor)) { set_error(g, "ANGLE eglInitialize failed"); return -1; }
    eglBindAPI(EGL_OPENGL_ES_API);
    EGLint ca[] = {EGL_SURFACE_TYPE,EGL_PBUFFER_BIT,EGL_RENDERABLE_TYPE,EGL_OPENGL_ES_BIT,EGL_RED_SIZE,8,EGL_GREEN_SIZE,8,EGL_BLUE_SIZE,8,EGL_ALPHA_SIZE,8,EGL_NONE};
    EGLConfig config; EGLint n; if (!eglChooseConfig(g->display, ca, &config, 1, &n) || !n) { set_error(g, "ANGLE has no GLES1 pbuffer config"); return -1; }
    EGLint pa[] = {EGL_WIDTH,width,EGL_HEIGHT,height,EGL_NONE}; EGLint xa[] = {EGL_CONTEXT_CLIENT_VERSION,1,EGL_NONE};
    g->surface = eglCreatePbufferSurface(g->display, config, pa); g->context = eglCreateContext(g->display, config, EGL_NO_CONTEXT, xa);
    if (!g->surface || !g->context || !eglMakeCurrent(g->display, g->surface, g->surface, g->context)) { set_error(g, "ANGLE GLES1 context creation failed"); return -1; }
    g->width = width; g->height = height;
    snprintf(g->renderer, sizeof(g->renderer), "%s", glGetString(GL_RENDERER)); snprintf(g->gl_version, sizeof(g->gl_version), "%s", glGetString(GL_VERSION));
    return 0;
}
void agr_guest_setup_gles1_frame(agr_guest *g) {
    glViewport(0,0,g->width,g->height); glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT); glMatrixMode(GL_PROJECTION); glLoadIdentity(); glMatrixMode(GL_MODELVIEW); glLoadIdentity(); glEnableClientState(GL_VERTEX_ARRAY); glEnableClientState(GL_COLOR_ARRAY);
}
int32_t agr_guest_read_rgba(agr_guest *g, void *pixels, uint32_t capacity) {
    if (!g || !pixels) return -1;
    /* A direct GLES fixture can read its own current context without a guest
     * eglSwapBuffers. A different thread (notably the UIKit observer of a
     * NativeActivity worker) must use the completed swap snapshot below. */
    uint32_t direct_size=(uint32_t)(g->width*g->height*4);
    agr_guest_thread_context *current=guest_context(g);
    if (direct_size && capacity>=direct_size && current &&
        g->egl_owner_thread_id==current->guest_thread_id &&
        eglGetCurrentContext()==g->context) {
        glFinish();
        glReadPixels(0,0,g->width,g->height,GL_RGBA,GL_UNSIGNED_BYTE,pixels);
        return glGetError()==GL_NO_ERROR ? (int32_t)direct_size : -1;
    }
    while (atomic_flag_test_and_set_explicit(&g->framebuffer_lock,memory_order_acquire)) {}
    uint32_t size=g->framebuffer_size;
    if (!size || capacity<size) { atomic_flag_clear_explicit(&g->framebuffer_lock,memory_order_release); return -1; }
    memcpy(pixels,g->framebuffer,size);
    atomic_flag_clear_explicit(&g->framebuffer_lock,memory_order_release);
    return (int32_t)size;
}
const char *agr_guest_gl_renderer(agr_guest *g) { return g->renderer; }
const char *agr_guest_gl_version(agr_guest *g) { return g->gl_version; }
uint64_t agr_guest_instruction_count(agr_guest *g) { return g ? atomic_load_explicit(&g->instruction_count,memory_order_relaxed) : 0; }
uint32_t agr_guest_draw_count(agr_guest *g) { return g ? atomic_load_explicit(&g->draw_count,memory_order_relaxed) : 0; }
uint32_t agr_guest_swap_count(agr_guest *g) { return g ? atomic_load_explicit(&g->swap_count,memory_order_acquire) : 0; }
uint32_t agr_guest_asset_open_count(agr_guest *g) { return g ? g->asset_open_count : 0; }
int32_t agr_guest_inject_motion(agr_guest *g, int32_t action, float x, float y) {
    if(!g) return -1;
    while (atomic_flag_test_and_set_explicit(&g->input_lock,memory_order_acquire)) {}
    if(g->input_count>=32) { atomic_flag_clear_explicit(&g->input_lock,memory_order_release); return -1; }
    input_event *e=&g->input_events[(g->input_head+g->input_count)%32];
    *e=(input_event){g->next_input_handle,2u,(uint32_t)action,1u,0u,x,y};
    g->next_input_handle+=4; g->input_count++;
    atomic_flag_clear_explicit(&g->input_lock,memory_order_release);
    return 0;
}
uint32_t agr_guest_input_queue(agr_guest *g) { return g ? g->input_queue_handle : 0; }
uint32_t agr_guest_input_consumed_count(agr_guest *g) { return g ? atomic_load_explicit(&g->input_consumed_count,memory_order_relaxed) : 0; }
uint32_t agr_guest_unique_import_count(agr_guest *g) { return g ? g->unique_import_count : 0; }
const char *agr_guest_unique_import(agr_guest *g,uint32_t index) { return g && index<g->unique_import_count ? g->unique_imports[index] : NULL; }
uint32_t agr_guest_recent_call_count(agr_guest *g) { return g ? (g->recent_import_index < 12 ? g->recent_import_index : 12) : 0; }
const char *agr_guest_recent_call(agr_guest *g,uint32_t index) {
    if (!g) return NULL;
    uint32_t count=agr_guest_recent_call_count(g); if(index>=count)return NULL;
    uint32_t start=g->recent_import_index>12 ? g->recent_import_index%12 : 0;
    return g->recent_imports[(start+index)%12];
}
uint32_t agr_guest_loaded_module_count(agr_guest *g){return g?agr_loaded_module_count(g->runtime):0;}
const char *agr_guest_loaded_module(agr_guest *g,uint32_t index){return g?agr_loaded_module_name(g->runtime,index):NULL;}

__attribute__((used))
int32_t agr_guest_unwind_backtrace(agr_guest *g, agr_guest_unwind_frame *frames,
                                   uint32_t max_frames, uint32_t *count,
                                   const char **stop_reason) {
    agr_guest_thread_context *context;
    agr_guest_unwind_context unwind;
    uint32_t regs[16];
    uint32_t i;
    int32_t rc;
    if (count) *count = 0;
    if (stop_reason) *stop_reason = "failure";
    if (!g || !frames || !max_frames) return -1;
    context = guest_context(g);
    if (!context || !context->cpu || !g->runtime) {
        if (stop_reason) *stop_reason = "invalid_pc";
        return -1;
    }
    for (i = 0; i < 16; i++) regs[i] = arm_interp_get_reg(context->cpu, i);
    agr_ehabi_context_init(&unwind, context, regs, arm_interp_get_cpsr(context->cpu),
                           context->guest_stack_base, context->guest_stack_size);
    rc = agr_ehabi_backtrace_runtime(g->runtime, &unwind, frames, max_frames, count);
    if (stop_reason) *stop_reason = agr_ehabi_stop_name(unwind.stop);
    return rc;
}
