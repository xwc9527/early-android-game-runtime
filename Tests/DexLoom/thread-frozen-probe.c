/* Local unchanged-APK probe. Not a CI target: the APK is not in the repository. */
#include "game_dex_runner.h"
#include "dx_log.h"
#include <GLES2/gl2.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void glGenTextures(GLsizei n, GLuint *textures) {
    for (GLsizei i = 0; i < n; i++) if (textures) textures[i] = 1;
}
void glBindTexture(GLenum target, GLuint texture) { (void)target; (void)texture; }
void glTexParameteri(GLenum target, GLenum pname, GLint param) {
    (void)target; (void)pname; (void)param;
}
void glDeleteTextures(GLsizei n, const GLuint *textures) { (void)n; (void)textures; }

static void print_snapshot(const char *label, const agr_dex_runtime_snapshot *snapshot) {
    printf("%s stage_fields last=%s exception=%s error=%s created=%u changed=%u "
           "content=%llu root=%llu draw=%u stack=%u "
           "lock=%u unlock=%u post=%u locked=%d owner=%u locked_gen=%u post_gen=%u "
           "row=%d hash_before=%llx hash_after=%llx pixels=%u draws=%u format=%d %dx%d gen=%u\n",
           label,
           snapshot->last_method,
           snapshot->exception_class,
           snapshot->error,
           snapshot->content_surface_created_count,
           snapshot->content_surface_changed_count,
           (unsigned long long)snapshot->content_surface_identity,
           (unsigned long long)snapshot->root_surface_identity,
           snapshot->draw_count,
           snapshot->stack_depth,
           snapshot->canvas_lock_count,
           snapshot->canvas_unlock_count,
           snapshot->canvas_post_count,
           snapshot->canvas_locked,
           snapshot->canvas_lock_owner_exec,
           snapshot->canvas_locked_generation,
           snapshot->canvas_last_post_generation,
           snapshot->canvas_row_bytes,
           (unsigned long long)snapshot->canvas_buffer_hash_before,
           (unsigned long long)snapshot->canvas_buffer_hash_after,
           snapshot->canvas_pixel_change_count,
           snapshot->canvas_draw_bitmap_count,
           snapshot->content_surface_format,
           snapshot->content_surface_width,
           snapshot->content_surface_height,
           snapshot->content_surface_generation);
    if (snapshot->method_event_count) {
        const agr_dex_method_event *event = &snapshot->method_events[snapshot->method_event_count - 1];
        printf("%s last_event %s depth=%u\n", label, event->method, event->depth);
    }
}

int main(int argc, char **argv) {
    alarm(25);
    dx_log_set_level(DX_LOG_WARN);
    const char *apk_path = argc > 1 ? argv[1] : "/tmp/frozen.apk";
    agr_apk_package *package = agr_apk_package_open(apk_path);
    if (!package) {
        fprintf(stderr, "open failed %s\n", apk_path);
        return 1;
    }
    agr_dex_game *game = agr_dex_game_create_from_apk(package);
    if (!game) {
        fprintf(stderr, "create failed\n");
        return 1;
    }
    agr_dex_game_enable_diagnostics(game, 1);
    if (agr_dex_game_set_host_display(game, 320, 480) != 0) return 1;
    int started = agr_dex_game_start_activity(game);
    agr_activity_launch_stage stage = agr_dex_game_launch_stage(game);
    printf("start_activity=%d launch_stage=%d launch_error=%s\n",
           started, (int)stage, agr_dex_game_launch_error(game));
    agr_dex_runtime_snapshot snapshot;
    if (agr_dex_game_runtime_snapshot(game, &snapshot) == 0)
        print_snapshot("after_start", &snapshot);
    for (int frame = 0; frame < 3; frame++) {
        int frame_rc = agr_dex_game_choreographer_frame(game);
        printf("frame%d=%d\n", frame, frame_rc);
    }
    if (agr_dex_game_runtime_snapshot(game, &snapshot) == 0)
        print_snapshot("after_frames", &snapshot);
    /* The game loop sleeps 40ms per turn. Let it pass the first sleeps
       before teardown so the next guest stop is visible. */
    usleep(300000);
    if (agr_dex_game_runtime_snapshot(game, &snapshot) == 0)
        print_snapshot("after_wait", &snapshot);
    agr_dex_game_destroy(game);
    agr_apk_package_close(package);
    printf("frozen probe: destroyed\n");
    return started == 0 ? 0 : 2;
}
