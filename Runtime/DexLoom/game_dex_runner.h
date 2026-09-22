#ifndef AGR_GAME_DEX_RUNNER_H
#define AGR_GAME_DEX_RUNNER_H
#include <stdint.h>
#include <stddef.h>
#ifdef __cplusplus
extern "C" {
#endif
typedef struct agr_dex_game agr_dex_game;
typedef struct agr_apk_package agr_apk_package;
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
#define AGR_DEX_FRAMEWORK_TRACE_CAPACITY 96
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
    int content_layout_width;
    int content_layout_height;
    int content_child_count;
    int content_first_child_id;
    char last_method[160];
    char exception_class[160];
    char error[256];
    uint32_t method_event_count;
    agr_dex_method_event method_events[AGR_DEX_METHOD_TRACE_CAPACITY];
    uint32_t framework_event_count;
    char framework_events[AGR_DEX_FRAMEWORK_TRACE_CAPACITY][96];
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
int agr_dex_game_runtime_snapshot(const agr_dex_game *game, agr_dex_runtime_snapshot *snapshot);
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
