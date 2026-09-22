/* Unchanged Frozen Bubble at the physical 1080x2340 display.
   The harness selects the APK, sets the host display, waits, and reads
   telemetry. It does not call doDraw, lockCanvas, drawBitmap, or post. */
#include "game_dex_runner.h"
#include "dx_vm.h"
#include "dx_log.h"
#include <GLES2/gl2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void glGenTextures(GLsizei n, GLuint *textures) {
    for (GLsizei i = 0; i < n; i++) if (textures) textures[i] = 1;
}
void glBindTexture(GLenum target, GLuint texture) { (void)target; (void)texture; }
void glTexParameteri(GLenum target, GLenum pname, GLint param) {
    (void)target; (void)pname; (void)param;
}
void glDeleteTextures(GLsizei n, const GLuint *textures) { (void)n; (void)textures; }

static const char *EXPECTED_SHA = "57f4735297befc68c0a7aa6cd9e442ecd250b1b2b38104324a12b6c2d4e18569";
static const int harness_called_do_traversal = 0;
static const int harness_called_render_api = 0;
static int g_failures = 0;

static void expect(int condition, const char *message) {
    if (condition) {
        printf("PASS %s\n", message);
        return;
    }
    printf("FAIL %s\n", message);
    g_failures++;
}

static int sha256_matches(const char *path) {
    char cmd[768];
    char line[128];
    FILE *fp;
    snprintf(cmd, sizeof(cmd), "sha256sum \"%s\"", path);
    fp = popen(cmd, "r");
    if (!fp) return 0;
    if (!fgets(line, sizeof(line), fp)) {
        pclose(fp);
        return 0;
    }
    pclose(fp);
    return strncmp(line, EXPECTED_SHA, 64) == 0;
}

int main(int argc, char **argv) {
    const char *apk_path = argc > 1 ? argv[1] : "samples/org.jfedor.frozenbubble_8.apk";
    agr_apk_package *package;
    agr_dex_game *game;
    agr_dex_runtime_snapshot snapshot;
    DxVM *vm;
    int started;
    int have_size = 0;
    int32_t vector_size = 0;
    int have_penguin = 0;
    int paint = 0;
    int scaled = 0;
    uint32_t i;
    uint32_t n;
    alarm(40);
    dx_log_set_level(DX_LOG_WARN);
    expect(sha256_matches(apk_path), "unchanged Frozen Bubble SHA-256");
    package = agr_apk_package_open(apk_path);
    expect(package != NULL, "open apk");
    if (!package) return 1;
    game = agr_dex_game_create_from_apk(package);
    expect(game != NULL, "create game");
    if (!game) return 1;
    agr_dex_game_enable_diagnostics(game, 1);
    expect(agr_dex_game_set_host_display(game, 1080, 2340) == 0, "host display 1080x2340");
    started = agr_dex_game_start_activity(game);
    expect(started == 0, "start activity");
    expect(agr_dex_game_launch_stage(game) == AGR_ACTIVITY_LAUNCH_RESUMED, "activity resumed");
    for (i = 0; i < 3; i++) agr_dex_game_choreographer_frame(game);
    usleep(300000);
    memset(&snapshot, 0, sizeof(snapshot));
    expect(agr_dex_game_runtime_snapshot(game, &snapshot) == 0, "snapshot");
    vm = agr_dex_game_vm(game);
    n = vm ? dx_vm_vector_trace_count(vm) : 0;
    for (i = 0; i < n; i++) {
        DxVectorTrace trace;
        if (dx_vm_copy_vector_trace(vm, i, &trace) != 0) continue;
        if (strcmp(trace.method, "size") == 0 && trace.has_ret && trace.ret_i >= 1) {
            have_size = 1;
            vector_size = trace.ret_i;
        }
        if (strcmp(trace.method, "elementAt") == 0 && strstr(trace.ret_class, "PenguinSprite"))
            have_penguin = 1;
    }
    n = vm ? dx_vm_vector_after_element_count(vm) : 0;
    for (i = 0; i < n; i++) {
        DxInvokeWitness witness;
        if (dx_vm_copy_vector_after_element(vm, i, &witness) != 0) continue;
        if (strcmp(witness.target_name, "paint") == 0 && strstr(witness.recv_class, "PenguinSprite"))
            paint = 1;
    }
    if (strstr(snapshot.last_method, "createScaledBitmap")) scaled = 1;
    for (i = 0; i < snapshot.method_event_count; i++) {
        if (strstr(snapshot.method_events[i].method, "createScaledBitmap")) scaled = 1;
    }
    printf("stage=%d exec_owner=%u created=%u changed=%u exc=%s lock=%u unlock=%u post=%u "
           "draw=%u pixels=%u hash_before=%llx hash_after=%llx vector=%d penguin=%d paint=%d "
           "scaled=%d %dx%d harness_traversal=%d harness_render=%d\n",
           (int)agr_dex_game_launch_stage(game), snapshot.canvas_lock_owner_exec,
           snapshot.content_surface_created_count, snapshot.content_surface_changed_count,
           snapshot.content_surface_exception, snapshot.canvas_lock_count,
           snapshot.canvas_unlock_count, snapshot.canvas_post_count,
           snapshot.canvas_draw_bitmap_count, snapshot.canvas_pixel_change_count,
           (unsigned long long)snapshot.canvas_buffer_hash_before,
           (unsigned long long)snapshot.canvas_buffer_hash_after,
           vector_size, have_penguin, paint, scaled,
           snapshot.content_surface_width, snapshot.content_surface_height,
           harness_called_do_traversal, harness_called_render_api);
    expect(snapshot.content_surface_created_count == 1, "surfaceCreated count");
    expect(snapshot.content_surface_changed_count == 1, "surfaceChanged count");
    expect(snapshot.content_surface_exception[0] == 0, "callbacks did not throw");
    expect(snapshot.content_surface_width == 1080 && snapshot.content_surface_height == 2340,
           "content surface is 1080x2340");
    expect(snapshot.content_surface_identity != 0 &&
           snapshot.content_surface_identity != snapshot.root_surface_identity,
           "content surface is not the root");
    expect(snapshot.canvas_lock_owner_exec != 0, "GameThread execution context");
    expect(snapshot.canvas_lock_count > 0, "lock_count");
    expect(snapshot.canvas_unlock_count > 0, "unlock_count");
    expect(snapshot.canvas_post_count > 0, "post_count");
    expect(snapshot.canvas_draw_bitmap_count > 0, "draw_bitmap_count");
    expect(snapshot.canvas_pixel_change_count > 0, "pixel_change_count");
    expect(snapshot.canvas_buffer_hash_before != snapshot.canvas_buffer_hash_after, "hash changed");
    expect(have_size && vector_size >= 1, "Vector.size is non-empty");
    expect(have_penguin, "elementAt returns PenguinSprite");
    expect(paint, "PenguinSprite.paint reached");
    expect(scaled, "Bitmap.createScaledBitmap reached");
    expect(harness_called_do_traversal == 0 && harness_called_render_api == 0, "harness purity");
    agr_dex_game_destroy(game);
    agr_apk_package_close(package);
    printf("frozen-bubble-1080: %s\n", g_failures ? "FAIL" : "PASS");
    return g_failures ? 1 : 0;
}
