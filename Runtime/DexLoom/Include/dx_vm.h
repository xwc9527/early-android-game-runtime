#ifndef DX_VM_H
#define DX_VM_H

#include "dx_types.h"
#include "dx_dex.h"
#include <pthread.h>

// Release vs Debug build configuration
#ifdef NDEBUG
#define DX_RELEASE 1
#else
#define DX_RELEASE 0
#endif

// Class status
typedef enum {
    DX_CLASS_NOT_LOADED = 0,
    DX_CLASS_LOADING,
    DX_CLASS_LOADED,
    DX_CLASS_INITIALIZING,
    DX_CLASS_INITIALIZED,
    DX_CLASS_ERROR,
} DxClassStatus;

// Runtime class representation
struct DxClass {
    const char      *descriptor;        // e.g., "Lcom/example/Main;"
    DxClass         *super_class;
    DxClassStatus    status;
    uint32_t         access_flags;

    // Interfaces
    const char     **interfaces;        // interface descriptors this class implements
    uint32_t         interface_count;

    // Fields
    uint32_t         instance_field_count;
    uint32_t         static_field_count;
    struct {
        const char  *name;
        const char  *type;
        uint32_t     flags;
        uint32_t     slot_index;    // precomputed absolute slot in obj->fields[]
        bool         is_volatile;   // ACC_VOLATILE (0x0040) -- memory barrier semantics
    } *field_defs;
    DxValue         *static_fields;     // array[static_field_count]

    // Methods
    DxMethod        *direct_methods;
    uint32_t         direct_method_count;
    DxMethod        *virtual_methods;
    uint32_t         virtual_method_count;

    // VTable (flattened: super virtuals + own virtuals)
    DxMethod       **vtable;
    uint32_t         vtable_size;

    // ITable (interface method dispatch table)
    struct {
        const char *interface_desc;
        DxMethod **methods;
        int method_count;
    } *itable;
    int itable_count;

    // Annotations (with element values)
    DxAnnotationEntry *annotations;
    uint32_t annotation_count;

    // DEX origin
    DxDexFile       *dex_file;          // which DEX file this class came from
    uint32_t         dex_class_def_idx;
    uint8_t          source_dex_idx;    // index into vm->dex_files[] this class came from
    bool             is_framework;      // true for built-in Android stubs
    bool             owns_descriptor;   // true when descriptor was allocated for a synthetic type
};

// Inline cache for monomorphic/polymorphic call site optimization
#define DX_IC_SIZE 4  // max polymorphic cache entries per call site

typedef struct {
    DxClass  *receiver_class;
    DxMethod *resolved_method;
} DxICEntry;

typedef struct {
    DxICEntry entries[DX_IC_SIZE];
    uint8_t   count;       // how many entries populated (0..DX_IC_SIZE)
    uint32_t  hits;        // cache hit count
    uint32_t  misses;      // cache miss count
} DxInlineCache;

// Inline cache table: maps PC offsets to inline caches within a method
#define DX_IC_TABLE_SIZE 32  // hash table slots per method

typedef struct {
    uint32_t       pc;     // PC offset of the invoke instruction (0 = empty)
    DxInlineCache  ic;
} DxICSlot;

typedef struct {
    DxICSlot slots[DX_IC_TABLE_SIZE];
} DxICTable;

// Native method implementation signature
typedef DxResult (*DxNativeMethodFn)(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t arg_count);
typedef DxResult (*DxUnboundNativeMethodFn)(DxVM *vm, DxFrame *frame, DxMethod *method,
                                            DxValue *args, uint32_t arg_count, void *user);

// Runtime method representation
struct DxMethod {
    const char        *name;
    const char        *shorty;          // return+param type chars
    DxClass           *declaring_class;
    uint32_t           access_flags;
    uint32_t           dex_method_idx;

    // Bytecode (NULL for native methods)
    DxDexCodeItem      code;
    bool               has_code;

    // Native implementation (for framework stubs)
    DxNativeMethodFn   native_fn;
    bool               is_native;

    // Verification flag (set after bytecode passes structural verification)
    bool               verified;

    // VTable index (-1 if not virtual)
    int32_t            vtable_idx;

    // Inline cache table for invoke-virtual/interface call sites
    DxICTable         *ic_table;     // lazily allocated on first invoke-virtual

    // Method inlining for trivial getters/setters
    uint8_t            inline_type;       // 0=none, 1=getter, 2=setter
    uint16_t           inline_field_idx;  // field index for inlined getter/setter
    bool               analyzed_for_inline; // true after inline analysis performed

    // Profiling: method-level execution time
    uint64_t           total_time_ns;     // accumulated wall-clock time in this method
    uint32_t           call_count;        // number of times this method was invoked

    // Annotations (with element values)
    DxAnnotationEntry *annotations;
    uint32_t           annotation_count;
};

// Runtime object
struct DxObject {
    DxClass   *klass;
    DxValue   *fields;          // array[klass->instance_field_count]
    uint32_t   ref_count;
    uint32_t   heap_idx;        // index in VM heap
    bool       gc_mark;         // used by mark-sweep GC
    uint8_t    generation;      // 0 = young, 1 = old (generational GC)

    // For View objects: link to UI node
    DxUINode  *ui_node;
    /* Lazily created Java monitor. Owned by the VM, not by guest code. */
    void      *monitor;

    // String storage (owned; freed with object)
    char      *string_data;     // UTF-8 C string for java.lang.String / StringBuilder buf

    // Array support
    bool       is_array;
    uint32_t   array_length;
    DxValue   *array_elements;  // array[array_length] for array objects
};

// Interpreter frame (heap-allocated per method call)
struct DxFrame {
    DxMethod  *method;
    DxValue    registers[DX_MAX_REGISTERS];
    uint32_t   pc;              // program counter (in 16-bit code units)
    DxFrame   *caller;
    DxValue    result;          // return value from callee
    bool       has_result;
    DxObject  *exception;       // pending exception for try/catch handling
};

// ── Telemetry (opt-in) ──

typedef struct {
    uint64_t total_instructions_executed;
    uint64_t total_gc_collections;
    uint64_t total_gc_pause_ns;
    uint64_t total_methods_invoked;
    uint32_t classes_loaded;
    uint32_t exceptions_thrown;
    bool     telemetry_enabled;
    /* Bounded guest-method witness. Armed only while a diagnostic window
       is open. Zero means the publisher stays silent. */
    int      draw_witness_armed;
    uint32_t draw_witness_remaining;
} DxTelemetry;

#define DX_DIAGNOSTIC_METHOD_TEXT 160
#define DX_DIAGNOSTIC_METHOD_EVENTS 64

/* One guest invoke observed while telemetry is enabled. */
typedef struct DxInvokeWitness {
    uint32_t exec_id;
    uint32_t pc;
    uint32_t method_idx;
    uint8_t opcode;
    uint8_t resolved;
    uint8_t argc;
    uint8_t ret_tag;
    uint8_t has_ret;
    int32_t arg_i[8];
    uint8_t arg_tag[8];
    int32_t ret_i;
    uint64_t recv_obj;
    char caller[96];
    char target_class[96];
    char target_name[48];
    char shorty[24];
    char recv_class[80];
} DxInvokeWitness;

#define DX_VECTOR_TRACE_CAP 512
#define DX_VECTOR_TALLY_CAP 24

/* One Ljava/util/Vector; invoke. Telemetry only. */
typedef struct DxVectorTrace {
    uint32_t exec_id;
    uint32_t pc;
    uint32_t method_idx;
    uint8_t opcode;
    uint8_t resolved;
    uint8_t argc;
    uint8_t has_ret;
    uint8_t ret_tag;
    char caller[80];
    char method[32];
    char shorty[12];
    char recv_class[80];
    char ret_class[80];
    uint64_t receiver;
    uint64_t arg_obj;
    int32_t arg_int;
    int32_t arg2_int;
    int32_t ret_i;
    uint64_t ret_obj;
} DxVectorTrace;

typedef struct DxVectorTally {
    char method[32];
    char shorty[12];
    uint32_t count;
    uint8_t resolved;
} DxVectorTally;

typedef struct {
    uint64_t sequence;
    uint32_t depth;
    uint8_t is_native;
    char method[DX_DIAGNOSTIC_METHOD_TEXT];
} DxDiagnosticMethodEvent;

#define DX_FRAME_POOL_SIZE 64
#define DX_MAX_EXEC_CONTEXTS 8
#define DX_UNRESOLVED_TRACE_CAP 16

typedef enum {
    DX_JAVA_THREAD_NEW = 0,
    DX_JAVA_THREAD_STARTING = 1,
    DX_JAVA_THREAD_RUNNING = 2,
    DX_JAVA_THREAD_TERMINATED = 3
} DxJavaThreadState;

/* One HOST-DEX execution context. This is not a guest pthread. */
typedef struct DxExecutionContext {
    uint32_t id;
    struct DxVM *vm;
    pthread_t host_thread;
    int has_host_thread;
    int joinable;
    DxObject *java_thread;
    DxJavaThreadState state;
    volatile int stop_requested;
    volatile int at_safepoint;
    volatile int waiting_for_vm_lock;
    int in_vm;
    int vm_lock_depth;
    pthread_mutex_t life_mu;
    pthread_cond_t done_cv;

    DxFrame *current_frame;
    uint32_t stack_depth;
    DxObject *pending_exception;
    uint64_t insn_count;
    uint64_t insn_limit;
    uint64_t watchdog_start_time;
    int watchdog_triggered;
    char error_msg[256];
    int trace_depth;

    char diagnostic_last_method[DX_DIAGNOSTIC_METHOD_TEXT];
    DxDiagnosticMethodEvent diagnostic_method_events[DX_DIAGNOSTIC_METHOD_EVENTS];
    uint64_t diagnostic_method_sequence;
    uint32_t diagnostic_method_event_count;

    /* Unresolved-invoke diagnostics for this context only. The owning thread
       publishes count with a release store after the slot is complete. */
    DxInvokeWitness unresolved_trace[DX_UNRESOLVED_TRACE_CAP];
    uint32_t unresolved_count;
    uint32_t unresolved_dropped;

    DxFrame *frame_pool[DX_FRAME_POOL_SIZE];
    uint32_t frame_pool_count;
} DxExecutionContext;

// VM state
#define DX_MAX_DEX_FILES 8

// Forward declaration for missing feature tracker (full definition below)
#define DX_MAX_MISSING_FEATURES 32
typedef struct {
    char features[DX_MAX_MISSING_FEATURES][128];
    uint32_t count;
} DxMissingFeatures;

struct DxVM {
    DxContext  *ctx;
    DxDexFile *dex;              // primary DEX (for backwards compat)
    DxDexFile *dex_files[DX_MAX_DEX_FILES];
    uint32_t   dex_count;
    /* Host runtime boundary used only when a DEX-declared native method has
       no framework-native implementation inside DexLoom. */
    DxUnboundNativeMethodFn unbound_native_fn;
    void                   *unbound_native_user;
    int32_t               (*load_library_fn)(void *user, const char *name);
    void                   *load_library_user;
    /* Per-process Framework owner for host-side Activity/Window callbacks. */
    void                   *framework_user;

    // Per-DEX class cache: maps class_def_index -> already-loaded DxClass*
    // Avoids re-parsing the same class_def on repeated load_class calls
    DxClass  **class_def_cache[DX_MAX_DEX_FILES];  // lazily allocated per DEX
    uint32_t   class_def_cache_size[DX_MAX_DEX_FILES];

    // Class table
    DxClass   *classes[DX_MAX_CLASSES];
    uint32_t   class_count;

    // Class hash table for O(1) lookup
    #define DX_CLASS_HASH_SIZE 4096
    struct {
        const char *descriptor;  // key (points to DxClass->descriptor)
        DxClass    *cls;         // value
    } class_hash[DX_CLASS_HASH_SIZE];

    // Heap
    DxObject  *heap[DX_MAX_HEAP_OBJECTS];
    uint32_t   heap_count;

    /* Process-global shared-state lock. Never held across a Java thread's run. */
    pthread_mutex_t shared_mu;
    int shared_ready;
    pthread_mutex_t safepoint_mu;
    pthread_cond_t safepoint_cv;
    volatile int safepoint_requested;
    int safepoint_depth;
    DxExecutionContext *root_exec;
    DxExecutionContext *execs[DX_MAX_EXEC_CONTEXTS];
    uint32_t exec_count;
    uint32_t next_exec_id;

    // Framework classes (pre-registered)
    DxClass   *class_object;        // java/lang/Object
    DxClass   *class_string;        // java/lang/String
    DxClass   *class_activity;      // android/app/Activity
    DxClass   *class_view;          // android/view/View
    DxClass   *class_textview;      // android/widget/TextView
    DxClass   *class_button;        // android/widget/Button
    DxClass   *class_viewgroup;     // android/view/ViewGroup
    DxClass   *class_linearlayout;  // android/widget/LinearLayout
    DxClass   *class_context;       // android/content/Context
    DxClass   *class_bundle;        // android/os/Bundle
    DxClass   *class_resources;     // android/content/res/Resources
    DxClass   *class_onclick;       // android/view/View$OnClickListener
    DxClass   *class_appcompat;     // androidx/.../AppCompatActivity
    DxClass   *class_edittext;      // android/widget/EditText
    DxClass   *class_imageview;     // android/widget/ImageView
    DxClass   *class_toast;         // android/widget/Toast
    DxClass   *class_log;           // android/util/Log
    DxClass   *class_intent;        // android/content/Intent
    DxClass   *class_shared_prefs;  // android/content/SharedPreferences
    DxClass   *class_inflater;      // android/view/LayoutInflater
    DxClass   *class_arraylist;     // java/util/ArrayList
    DxClass   *class_hashmap;       // java/util/HashMap

    // Current activity instance
    DxObject  *activity_instance;
    // Process launch roots corresponding to LoadedApk.mApplication and the
    // ContextImpl objects retained by the application process.
    DxObject  *application_instance;
    DxObject  *application_context;
    DxObject  *activity_context;
    DxObject  *launch_intent;

    // Activity back-stack for startActivityForResult / finish
    #define DX_MAX_ACTIVITY_STACK 16
    struct {
        DxObject   *activity;     // the Activity object
        const char *class_name;   // class descriptor of the activity
        DxObject   *intent;       // Intent that launched it
        int32_t     request_code; // -1 if plain startActivity
        DxObject   *saved_state;  // Bundle from onSaveInstanceState (NULL if none)
    } activity_stack[DX_MAX_ACTIVITY_STACK];
    uint32_t activity_stack_depth;

    // Per-activity result state (set via setResult before finish)
    int32_t   activity_result_code;    // RESULT_CANCELED=0 by default
    DxObject *activity_result_data;    // optional Intent

    // String intern table
    #define DX_MAX_INTERNED_STRINGS 8192
    struct { char *value; DxObject *obj; } interned_strings[DX_MAX_INTERNED_STRINGS];
    uint32_t   interned_count;

    // Execution state. Instruction count, frames, and exceptions live on
    // DxExecutionContext. insn_total is process-wide statistics.
    bool       running;
    DxResult   last_error;
    uint64_t   insn_total;
    uint32_t   watchdog_timeout_ms;   // policy copied into each top-level call

    // Cancellation: set from another thread to stop execution gracefully
    volatile bool cancel_requested; // checked every 10000 instructions alongside watchdog

    // Missing feature tracker
    DxMissingFeatures missing_features;

    // Debug tracing
    struct {
        bool bytecode_trace;      // Log each instruction
        bool class_load_trace;    // Log class loads
        bool method_call_trace;   // Log method entry/exit
        const char *trace_method_filter; // NULL = all, else prefix match
        int trace_depth;          // Current call depth (for indentation)
    } debug;

    // Diagnostic info captured on error
    struct {
        bool     has_error;
        char     method_name[128];    // "Lcom/example/Foo;.bar"
        uint32_t pc;                  // program counter at error
        uint8_t  opcode;              // opcode at error
        char     opcode_name[32];     // human-readable opcode name
        uint32_t reg_count;           // number of registers to show
        DxValue  registers[16];       // snapshot of first 16 registers
        char     stack_trace[2048];   // formatted call chain
    } diag;

    // SharedPreferences in-memory store (simple key-value)
    #define DX_MAX_PREFS_ENTRIES 256
    struct {
        char    *key;
        DxValue  value;
    } prefs[DX_MAX_PREFS_ENTRIES];
    uint32_t prefs_count;

    // Incremental GC state
    enum { DX_GC_IDLE = 0, DX_GC_MARKING, DX_GC_SWEEPING } gc_phase;
    #define DX_GC_MARK_STACK_SIZE 4096
    DxObject  *gc_mark_stack[DX_GC_MARK_STACK_SIZE];
    uint32_t   gc_mark_stack_top;
    uint32_t   gc_sweep_cursor;       // current position in heap during incremental sweep

    // Generational GC state
    uint32_t   young_gen_count;      // number of young (generation 0) objects in heap
    uint32_t   young_gen_threshold;  // minor GC trigger threshold (default 256)
    uint32_t   gc_cycle_count;       // total GC cycles (used to schedule major GC)

    // Singleton ClassLoader object (returned by Class.getClassLoader())
    DxObject  *singleton_classloader;

    // ── Profiling ──
    bool       profiling_enabled;

    // Opcode frequency histogram (256 Dalvik opcodes)
    uint64_t   opcode_histogram[256];

    // GC pause time measurement
    uint64_t   last_gc_pause_ns;
    uint64_t   total_gc_pause_ns;

    // Heap allocation profiling
    uint64_t   total_allocations;
    uint64_t   total_bytes_allocated;

    // ── Telemetry (opt-in counters) ──
    DxTelemetry telemetry;

    /* Opt-in invoke witness. Written only while telemetry is enabled.
       Fixed capacity. Does not change guest-visible results. */
    DxInvokeWitness witness_fordigit[8];
    uint32_t witness_fordigit_count;
    DxInvokeWitness witness_continuation;
    int witness_continuation_set;
    DxInvokeWitness witness_unresolved_after[6];
    uint32_t witness_unresolved_after_count;
    int witness_want_continuation;
    /* Invoke site of the native call currently running. Telemetry only. */
    uint32_t invoke_site_pc;
    uint8_t invoke_site_opcode;
    uint32_t invoke_site_method_idx;
    int invoke_site_valid;

    /* Opt-in Ljava/util/Vector; invoke trace. Does not change guest results. */
    DxVectorTrace *vector_trace;
    uint32_t vector_trace_count;
    uint32_t vector_trace_dropped;
    uint32_t vector_addelement_stored;
    DxVectorTally vector_tally[DX_VECTOR_TALLY_CAP];
    uint32_t vector_tally_count;
    /* Next guest invoke after a Vector.elementAt that returned an object. */
    DxInvokeWitness vector_after_element[8];
    uint32_t vector_after_element_count;
    int vector_after_element_armed;
    int vector_seen_element_at;
    DxInvokeWitness vector_next_unresolved;
    int vector_next_unresolved_set;
};

// VM lifecycle
DxVM    *dx_vm_create(DxContext *ctx);
void     dx_vm_destroy(DxVM *vm);
DxResult dx_vm_load_dex(DxVM *vm, DxDexFile *dex);
DxResult dx_vm_register_framework_classes(DxVM *vm);

// Class operations
DxResult dx_vm_load_class(DxVM *vm, const char *descriptor, DxClass **out);
DxResult dx_vm_init_class(DxVM *vm, DxClass *cls);
DxClass *dx_vm_find_class(DxVM *vm, const char *descriptor);
void     dx_vm_class_hash_insert(DxVM *vm, DxClass *cls);
DxResult dx_vm_unload_class(DxVM *vm, const char *descriptor);

// Framework class registration (called by dx_vm_register_framework_classes)
DxResult dx_register_java_lang(DxVM *vm);
DxResult dx_register_android_framework(DxVM *vm);

// Garbage collection
DxResult  dx_vm_gc(DxVM *vm);
DxResult  dx_vm_gc_minor(DxVM *vm);  // minor GC: only collect young generation objects
void      dx_vm_gc_step(DxVM *vm);   // incremental GC step (processes up to 256 objects)

// Object operations
DxObject *dx_vm_alloc_object(DxVM *vm, DxClass *cls);
DxObject *dx_vm_alloc_array(DxVM *vm, uint32_t length);
/* Resolve a class, array, or primitive descriptor. Array classes are created
   on demand so check-cast can match their descriptor. */
DxClass  *dx_vm_resolve_type(DxVM *vm, const char *descriptor);
/* Class object whose klass is the resolved type (same convention as Class.forName). */
DxObject *dx_vm_box_class(DxVM *vm, const char *descriptor);
void      dx_vm_release_object(DxVM *vm, DxObject *obj);
DxResult  dx_vm_set_field(DxObject *obj, const char *name, DxValue value);
DxResult  dx_vm_get_field(DxObject *obj, const char *name, DxValue *out);

// Exception creation
DxObject *dx_vm_create_exception(DxVM *vm, const char *class_descriptor, const char *message);

// String operations
DxObject *dx_vm_create_string(DxVM *vm, const char *utf8);
DxObject *dx_vm_intern_string(DxVM *vm, const char *utf8);
const char *dx_vm_get_string_value(DxObject *str_obj);

// Method resolution
DxMethod *dx_vm_resolve_method(DxVM *vm, uint32_t dex_method_idx);
DxMethod *dx_vm_find_method(DxClass *cls, const char *name, const char *shorty);
/* Passive discovery record. It does not select the callee. */
void dx_vm_trace_virtual_invoke(DxFrame *frame, uint32_t pc, uint8_t opcode,
                                uint32_t method_idx, DxMethod *resolved,
                                DxClass *receiver, DxMethod *slot);
DxMethod *dx_vm_find_interface_method(DxVM *vm, DxClass *cls, const char *name, const char *shorty);

// Frame pool
DxFrame *dx_vm_alloc_frame(DxVM *vm);
void     dx_vm_free_frame(DxVM *vm, DxFrame *frame);

/* Active DEX execution context for this host thread. */
DxExecutionContext *dx_vm_current_exec(DxVM *vm);
void dx_vm_shared_lock(DxVM *vm);
void dx_vm_shared_unlock(DxVM *vm);
void dx_vm_shared_lock_current(void);
void dx_vm_shared_unlock_current(void);
void dx_exec_vm_init(DxVM *vm);
void dx_exec_vm_shutdown(DxVM *vm);
void dx_exec_vm_fini(DxVM *vm);
DxResult dx_vm_monitor_enter(DxVM *vm, DxObject *obj);
DxResult dx_vm_monitor_exit(DxVM *vm, DxObject *obj);
DxResult dx_vm_exec_poll(DxVM *vm);
void dx_exec_enter(DxExecutionContext *exec);
void dx_exec_leave(DxExecutionContext *exec);
void dx_exec_gc_begin(DxVM *vm);
void dx_exec_gc_end(DxVM *vm);

typedef struct DxExecSnapshot {
    uint32_t id;
    uint32_t stack_depth;
    uint64_t insn_count;
    uint64_t insn_limit;
    int32_t state;
    int alive;
    int has_exception;
    unsigned long host_thread;
    char method[128];
} DxExecSnapshot;

uint32_t dx_vm_exec_snapshot_count(DxVM *vm);
int dx_vm_copy_exec_snapshot(DxVM *vm, uint32_t index, DxExecSnapshot *out);

DxResult native_thread_start(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t arg_count);
DxResult native_thread_join(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t arg_count);
DxResult native_thread_isalive(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t arg_count);
DxResult native_thread_current(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t arg_count);
DxResult native_thread_sleep(DxVM *vm, DxFrame *frame, DxValue *args, uint32_t arg_count);

// Bytecode verification (called automatically before first execution)
DxResult dx_verify_method(DxDexFile *dex, DxMethod *method);

// Execution
DxResult dx_vm_execute_method(DxVM *vm, DxMethod *method, DxValue *args, uint32_t arg_count, DxValue *result);
DxResult dx_vm_run_main_activity(DxVM *vm, const char *activity_class);

// invoke-custom (lambda / string concat)
DxResult dx_vm_invoke_custom(DxVM *vm, DxFrame *frame, uint32_t call_site_idx,
                              DxValue *args, uint32_t arg_count);

// invoke-polymorphic (MethodHandle.invoke / invokeExact dispatch)
DxResult dx_vm_invoke_method_handle(DxVM *vm, DxObject *handle_obj, DxValue *args, int argc, DxValue *result);

// Annotation lookup on class/method
const DxAnnotationEntry *dx_class_get_annotation(DxClass *cls, const char *type_desc);
const DxAnnotationEntry *dx_method_get_annotation(DxMethod *method, const char *type_desc);

// Garbage collection — force a full mark-sweep cycle (e.g. on memory pressure)
DxResult dx_vm_gc_collect(DxVM *vm);

// Diagnostics
char *dx_vm_heap_stats(DxVM *vm);
char *dx_vm_get_last_error_detail(DxVM *vm);

// Missing feature tracking
void        dx_vm_report_missing_feature(DxVM *vm, const char *feature);
const char *dx_vm_get_missing_features(DxVM *vm);

// Crash isolation (signal-based recovery)
#include <setjmp.h>
#ifdef _WIN32
typedef jmp_buf sigjmp_buf;
#endif
void        dx_crash_install_handlers(DxVM *vm);
void        dx_crash_uninstall_handlers(void);
int         dx_crash_get_signal(void);
sigjmp_buf *dx_crash_get_jmpbuf(void);

// Debug tracing configuration
void dx_vm_set_trace(DxVM *vm, bool bytecode, bool class_load, bool method_call);
void dx_vm_set_trace_filter(DxVM *vm, const char *method_filter);

// Inline cache operations
DxInlineCache *dx_vm_ic_get(DxMethod *method, uint32_t pc);
DxMethod      *dx_vm_ic_lookup(DxInlineCache *ic, DxClass *receiver_class);
void           dx_vm_ic_insert(DxInlineCache *ic, DxClass *receiver_class, DxMethod *resolved);
void           dx_vm_ic_stats(DxVM *vm);

// Method inlining constants
#define DX_INLINE_NONE   0
#define DX_INLINE_GETTER 1
#define DX_INLINE_SETTER 2

// Analyze a method for trivial getter/setter inlining
void dx_method_analyze_inline(DxMethod *method);

// Profiling
void dx_vm_set_profiling(DxVM *vm, bool enabled);
void dx_vm_dump_opcode_stats(DxVM *vm);
void dx_vm_dump_hot_methods(DxVM *vm, int top_n);

/// Get a snapshot of the current telemetry counters.
DxTelemetry dx_vm_get_telemetry(DxVM *vm);

/// Enable or disable telemetry collection.
void dx_vm_set_telemetry_enabled(DxVM *vm, bool enabled);
/* budget 0 disarms. A positive budget arms a fixed number of ENTER/EXIT
   publishes. This does not change method results. */
void dx_vm_set_draw_witness(DxVM *vm, uint32_t budget);
void dx_vm_witness_unresolved(DxVM *vm, DxFrame *frame, uint32_t pc, uint8_t opcode,
                              uint32_t method_idx, const DxValue *args, uint8_t argc);
void dx_vm_witness_resolved(DxVM *vm, DxFrame *frame, uint32_t pc, uint8_t opcode,
                            uint32_t method_idx, DxMethod *target, const DxValue *args,
                            uint8_t argc, const DxValue *result, int has_result);
uint32_t dx_vm_witness_fordigit_count(const DxVM *vm);
int dx_vm_copy_witness_fordigit(const DxVM *vm, uint32_t index, DxInvokeWitness *out);
int dx_vm_copy_witness_continuation(const DxVM *vm, DxInvokeWitness *out);
uint32_t dx_vm_witness_unresolved_after_count(const DxVM *vm);
int dx_vm_copy_witness_unresolved_after(const DxVM *vm, uint32_t index, DxInvokeWitness *out);
void dx_vm_note_vector(DxVM *vm, DxFrame *frame, uint32_t pc, uint8_t opcode,
                       uint32_t method_idx, const char *name, const char *shorty,
                       const DxValue *args, uint8_t argc, int resolved,
                       const DxValue *result, int has_result);
uint32_t dx_vm_vector_trace_count(const DxVM *vm);
uint32_t dx_vm_vector_trace_dropped(const DxVM *vm);
int dx_vm_copy_vector_trace(const DxVM *vm, uint32_t index, DxVectorTrace *out);
uint32_t dx_vm_vector_tally_count(const DxVM *vm);
int dx_vm_copy_vector_tally(const DxVM *vm, uint32_t index, DxVectorTally *out);
void dx_vm_note_vector_follow(DxVM *vm, DxFrame *frame, uint32_t pc, uint8_t opcode,
                              uint32_t method_idx, const char *cls, const char *name,
                              const char *shorty, const DxValue *args, uint8_t argc,
                              int resolved, const DxValue *result, int has_result);
uint32_t dx_vm_vector_after_element_count(const DxVM *vm);
int dx_vm_copy_vector_after_element(const DxVM *vm, uint32_t index, DxInvokeWitness *out);
int dx_vm_copy_vector_next_unresolved(const DxVM *vm, DxInvokeWitness *out);
void dx_vm_note_post_vector_unresolved(DxVM *vm, DxFrame *frame, uint32_t pc, uint8_t opcode,
                                       uint32_t method_idx, const char *cls, const char *name,
                                       const char *shorty, const DxValue *args, uint8_t argc);
void dx_vm_note_unresolved_seen(DxVM *vm, DxFrame *frame, uint32_t pc, uint8_t opcode,
                                uint32_t method_idx, const char *cls, const char *name,
                                const char *shorty, const DxValue *args, uint8_t argc);
typedef struct DxUnresolvedContextInfo {
    uint32_t exec_id;
    uint32_t count;
    uint32_t dropped;
} DxUnresolvedContextInfo;
uint32_t dx_vm_unresolved_context_count(const DxVM *vm);
int dx_vm_copy_unresolved_context(const DxVM *vm, uint32_t index, DxUnresolvedContextInfo *out);
int dx_vm_copy_unresolved_event(const DxVM *vm, uint32_t context_index, uint32_t event_index,
                                DxInvokeWitness *out);

#endif // DX_VM_H
