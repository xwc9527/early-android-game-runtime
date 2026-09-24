#ifndef AGR_GAME_DEX_RUNNER_H
#define AGR_GAME_DEX_RUNNER_H
#include <stdint.h>
#include <stddef.h>
#ifdef __cplusplus
extern "C" {
#endif
typedef struct agr_dex_game agr_dex_game;
typedef struct agr_apk_package agr_apk_package;
/* A host-owned copy of one completed SurfaceHolder post. The producer keeps
   drawing in its own buffer; the consumer never reads a live Canvas target. */
typedef struct {
    void *pixels;
    size_t bytes;
    uint32_t width, height, row_bytes;
    uint32_t generation, post_count;
    uint64_t surface_identity, pixel_hash;
} agr_dex_posted_surface;
typedef enum {
    AGR_ACTIVITY_LAUNCH_NONE = 0,
    AGR_ACTIVITY_LAUNCH_CLASS_RESOLVED,
    AGR_ACTIVITY_LAUNCH_ACTIVITY_INSTANTIATED,
    AGR_ACTIVITY_LAUNCH_APPLICATION_CREATED,
    AGR_ACTIVITY_LAUNCH_CONTEXT_ATTACHED,
    AGR_ACTIVITY_LAUNCH_ACTIVITY_ATTACHED,
    AGR_ACTIVITY_LAUNCH_ON_CREATE_ENTERED,
    AGR_ACTIVITY_LAUNCH_ON_CREATE_RETURNED,
    AGR_ACTIVITY_LAUNCH_STARTED,
    AGR_ACTIVITY_LAUNCH_RESUMED,
} agr_activity_launch_stage;
typedef enum {
    AGR_DEX_ARG_INT = 1,
    AGR_DEX_ARG_FLOAT = 2,
    AGR_DEX_ARG_STRING = 3,
    AGR_DEX_ARG_NULL = 4,
    AGR_DEX_ARG_OBJECT = 5,
} agr_dex_arg_kind;
typedef struct {
    uint64_t sequence;
    uint32_t depth;
    int is_native;
    char method[160];
} agr_dex_method_event;
#define AGR_DEX_METHOD_TRACE_CAPACITY 64
#define AGR_DEX_FRAMEWORK_TRACE_CAPACITY 256
#define AGR_FEATURE_EVENT_CAP 8
#define AGR_INTENT_EVENT_CAP 4
typedef struct {
    agr_dex_arg_kind kind;
    union { int32_t i; float f; const char *string; uint32_t object; } value;
} agr_dex_argument;
typedef int32_t (*agr_dex_native_callback)(void *user, const char *class_descriptor,
                                           const char *method_name, const char *signature,
                                           int is_static, const agr_dex_argument *arguments,
                                           uint32_t argument_count, agr_dex_argument *result);
typedef struct {
    uint64_t methods_invoked;
    uint64_t instructions_executed;
    uint32_t stack_depth;
    int vm_running;
    int pending_exception;
    int post_resume_completed;
    int window_attached;
    int window_added;
    int window_visible;
    int idle_handler_scheduled;
    int viewroot_handoff;
    int viewroot_created;
    int viewroot_root_assigned;
    int traversal_scheduled;
    int window_session_attached;
    int view_parent_assigned;
    int viewroot_attach_completed;
    int hierarchy_attached;
    int traversal_phase;
    uint32_t traversal_count;
    int measured_width;
    int measured_height;
    int frame_left;
    int frame_top;
    int frame_right;
    int frame_bottom;
    int layout_complete;
    int surface_valid;
    uint32_t surface_generation;
    uint32_t draw_count;
    int content_view_installed;
    uint32_t touch_dispatched;
    uint32_t touch_consumed;
    int touch_down_active;
    int content_layout_width;
    int content_layout_height;
    int content_child_count;
    int content_first_child_id;
    int content_surface_valid;
    uint32_t content_surface_generation;
    int content_surface_width;
    int content_surface_height;
    int content_surface_format;
    uint32_t content_surface_callback_count;
    uint32_t content_surface_created_count;
    uint32_t content_surface_changed_count;
    uint64_t content_surface_identity;
    uint64_t root_surface_identity;
    int32_t content_surface_owner_id;
    uint32_t canvas_lock_count;
    uint32_t canvas_unlock_count;
    uint32_t canvas_post_count;
    int canvas_locked;
    uint32_t canvas_lock_owner_exec;
    uint32_t canvas_locked_generation;
    uint32_t canvas_last_post_generation;
    int canvas_row_bytes;
    uint64_t canvas_buffer_hash_before;
    uint64_t canvas_buffer_hash_after;
    uint32_t canvas_pixel_change_count;
    uint32_t canvas_draw_bitmap_count;
    uint64_t canvas_identity;
    uint64_t canvas_lock_owner_host;
    uint64_t bitmap_guest_identity;
    uint64_t bitmap_host_identity;
    int bitmap_width;
    int bitmap_height;
    char bitmap_path[160];
    char bitmap_encoding[16];
    char content_surface_exception[160];
    char last_method[160];
    char exception_class[160];
    char error[256];
    uint32_t method_event_count;
    agr_dex_method_event method_events[AGR_DEX_METHOD_TRACE_CAPACITY];
    uint32_t framework_event_count;
    char framework_events[AGR_DEX_FRAMEWORK_TRACE_CAPACITY][96];
    uint32_t feature_event_count;
    char feature_events[AGR_FEATURE_EVENT_CAP][96];
    uint32_t intent_event_count;
    char intent_events[AGR_INTENT_EVENT_CAP][160];
} agr_dex_runtime_snapshot;

agr_apk_package *agr_apk_package_open(const char *apk_path);
void agr_apk_package_close(agr_apk_package *package);
const char *agr_apk_package_name(const agr_apk_package *package);
const char *agr_apk_launch_activity(const agr_apk_package *package);
const char *agr_apk_native_library(const agr_apk_package *package);
int32_t agr_apk_min_sdk(const agr_apk_package *package);
int32_t agr_apk_target_sdk(const agr_apk_package *package);
const void *agr_apk_dex_bytes(const agr_apk_package *package, uint32_t *size);
uint32_t agr_apk_native_library_count(const agr_apk_package *package);
const char *agr_apk_native_library_name(const agr_apk_package *package, uint32_t index);
const void *agr_apk_native_library_bytes(const agr_apk_package *package, uint32_t index,
                                         uint32_t *size);

agr_dex_game *agr_dex_game_create(const char *dex_path);
agr_dex_game *agr_dex_game_create_for_launch(const void *dex_bytes, uint32_t dex_size,
                                              const char *activity_descriptor,
                                              const char *application_descriptor,
                                              const char *package_name);
agr_dex_game *agr_dex_game_create_from_apk(const agr_apk_package *package);
void agr_dex_game_destroy(agr_dex_game *game);
const char *agr_dex_game_activity_descriptor(const agr_dex_game *game);
int agr_dex_game_resolve_class(agr_dex_game *game, const char *descriptor);
int agr_dex_game_resolve_method(agr_dex_game *game, const char *class_descriptor,
                                const char *name, const char *signature, int is_static);
int agr_dex_game_start_activity(agr_dex_game *game);
void agr_dex_game_enable_diagnostics(agr_dex_game *game, int enabled);
struct DxVM *agr_dex_game_vm(const agr_dex_game *game);
int agr_dex_game_runtime_snapshot(const agr_dex_game *game, agr_dex_runtime_snapshot *snapshot);
uint32_t agr_dex_game_content_surface_count(const agr_dex_game *game);
/* 0: new post copied; 1: no newer post; -1: invalid surface or allocation
   failure. Caller releases pixels with agr_dex_posted_surface_release. */
int agr_dex_game_copy_posted_surface(const agr_dex_game *game, uint32_t index,
                                    uint32_t after_post_count, agr_dex_posted_surface *out);
void agr_dex_posted_surface_release(agr_dex_posted_surface *frame);
/* Try the existing content-surface mutex and release it immediately.
   Returns non-zero only when that mutex is already locked. No guest call,
   no draw, and no blocking lock. */
int agr_dex_game_diagnostic_content_lock_busy(const agr_dex_game *game);
int agr_dex_game_post_resume_completed(const agr_dex_game *game);
int agr_dex_game_viewroot_contract(agr_dex_game *game);
int agr_dex_game_do_traversal(agr_dex_game *game, uint32_t display_width_pixels,
                              uint32_t display_height_pixels);
/* Host display fact supplied by UIKit. It does not run a traversal. */
int agr_dex_game_set_host_display(agr_dex_game *game, uint32_t display_width_pixels,
                                  uint32_t display_height_pixels);
/* One host vsync. Returns 0 when a posted traversal ran, 1 when none was
   due, and -1 on error. Never runs the reschedule in the same call. */
int agr_dex_game_choreographer_frame(agr_dex_game *game);
/* API19 Activity -> Window -> View dispatch for one touchscreen pointer.
   Returns 1 when guest View consumes it, 0 when unhandled, -1 on Runtime error. */
int agr_dex_game_dispatch_touch(agr_dex_game *game, int action, float x, float y,
                                uint64_t event_time_ms);
/* Activity.setContentView(View) for a newly allocated content View.
   MATCH_PARENT params. Schedules a traversal only when the decor is already
   attached, and does not execute it. */
int agr_dex_game_set_content_view(agr_dex_game *game);
/* Compiled layout XML addressed by resource id. APK open installs these from
   resources.arsc. setContentView(int) inflates one and does not execute a
   scheduled traversal. */
int agr_dex_game_provide_layout(agr_dex_game *game, uint32_t layout_id,
                                const void *xml, uint32_t size);
int agr_dex_game_set_content_layout(agr_dex_game *game, uint32_t layout_id);
int agr_dex_game_set_surface_allocator(agr_dex_game *game,
                                       void *(*allocate)(void *user, size_t bytes),
                                       void (*release)(void *user, void *pixels), void *user);
/* Child SurfaceView buffer only. The root WindowSession allocator is unchanged. */
int agr_dex_game_set_content_surface_allocator(agr_dex_game *game,
                                              void *(*allocate)(void *user, size_t bytes),
                                              void (*release)(void *user, void *pixels),
                                              void *user);
int agr_dex_game_set_relayout_gate(agr_dex_game *game,
                                   int (*gate)(void *user, uint32_t width,
                                               uint32_t height, int visibility),
                                   void *user);
int agr_dex_game_root_surface(agr_dex_game *game, void **pixels,
                              uint32_t *width, uint32_t *height,
                              uint32_t *stride, uint32_t *generation);
agr_activity_launch_stage agr_dex_game_launch_stage(const agr_dex_game *game);
const char *agr_dex_game_launch_error(const agr_dex_game *game);
int agr_dex_game_application_gc_contract(agr_dex_game *game);
int agr_dex_game_static_int(agr_dex_game *game, const char *class_descriptor,
                            const char *field_name, int32_t *value);
/* Locked content Surface observations for the Canvas state contract.
   These do not draw and do not call guest code. */
void *agr_dex_game_content_holder(const agr_dex_game *game);
int agr_dex_game_content_clip(const agr_dex_game *game, int *left, int *top,
                              int *right, int *bottom, int *save_count);
int agr_dex_game_content_pixel(const agr_dex_game *game, int x, int y, uint32_t *pixel);
#define AGR_CANVAS_TRACE_CAP 96
typedef struct {
    uint32_t exec_id;
    uint32_t pc;
    uint32_t method_idx;
    uint8_t opcode;
    char kind[16];
    char caller[96];
    int32_t save_flags;
    int32_t save_returned;
    int32_t save_count_after;
    int clip_before[4];
    int clip_after[4];
    float left, top, right, bottom;
    int32_t op_native;
    int op_null;
    uint64_t op_identity;
    char op_class[96];
    int bool_result;
    int wrote;
    int write_left, write_top, write_right, write_bottom;
    int has_write;
} agr_canvas_trace;
uint32_t agr_dex_game_canvas_trace_count(const agr_dex_game *game);
int agr_dex_game_copy_canvas_trace(const agr_dex_game *game, uint32_t index,
                                   agr_canvas_trace *out);
void agr_dex_game_set_native_callback(agr_dex_game *game,
                                      agr_dex_native_callback callback, void *user);
void agr_dex_game_set_load_library_callback(agr_dex_game *game,
                                            int32_t (*callback)(void *, const char *),
                                            void *user);
int agr_dex_game_invoke_int(agr_dex_game *game, const char *name, const char *signature,
                            const agr_dex_argument *arguments, uint32_t argument_count,
                            int32_t *result);
int agr_dex_game_load_image(agr_dex_game *game, const char *path, int32_t *texture);
int agr_dex_game_play_sound(agr_dex_game *game, const char *path, float direction, int32_t *play_id);
int agr_dex_game_activity_gc_contract(agr_dex_game *game);
void agr_dex_set_upload_callback(int32_t (*callback)(void *, const char *), void *user);
#ifdef __cplusplus
}
#endif
#endif
