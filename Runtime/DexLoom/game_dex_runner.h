#ifndef AGR_GAME_DEX_RUNNER_H
#define AGR_GAME_DEX_RUNNER_H
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
typedef struct agr_dex_game agr_dex_game;
agr_dex_game *agr_dex_game_create(const char *dex_path);
void agr_dex_game_destroy(agr_dex_game *game);
int agr_dex_game_load_image(agr_dex_game *game, const char *path, int32_t *texture);
int agr_dex_game_play_sound(agr_dex_game *game, const char *path, float direction, int32_t *play_id);
void agr_dex_set_upload_callback(int32_t (*callback)(void *, const char *), void *user);
#ifdef __cplusplus
}
#endif
#endif
