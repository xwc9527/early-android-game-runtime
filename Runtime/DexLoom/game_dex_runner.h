#ifndef AGR_GAME_DEX_RUNNER_H
#define AGR_GAME_DEX_RUNNER_H
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
typedef struct agr_dex_game agr_dex_game;
typedef struct agr_apk_package agr_apk_package;
typedef enum {
    AGR_DEX_ARG_INT = 1,
    AGR_DEX_ARG_FLOAT = 2,
    AGR_DEX_ARG_STRING = 3,
    AGR_DEX_ARG_NULL = 4,
    AGR_DEX_ARG_OBJECT = 5,
} agr_dex_arg_kind;
typedef struct {
    agr_dex_arg_kind kind;
    union { int32_t i; float f; const char *string; uint32_t object; } value;
} agr_dex_argument;
typedef int32_t (*agr_dex_native_callback)(void *user, const char *class_descriptor,
                                           const char *method_name, const char *signature,
                                           int is_static, const agr_dex_argument *arguments,
                                           uint32_t argument_count, agr_dex_argument *result);

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
agr_dex_game *agr_dex_game_create_from_apk(const agr_apk_package *package);
void agr_dex_game_destroy(agr_dex_game *game);
const char *agr_dex_game_activity_descriptor(const agr_dex_game *game);
int agr_dex_game_resolve_class(agr_dex_game *game, const char *descriptor);
int agr_dex_game_resolve_method(agr_dex_game *game, const char *class_descriptor,
                                const char *name, const char *signature, int is_static);
int agr_dex_game_start_activity(agr_dex_game *game);
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
