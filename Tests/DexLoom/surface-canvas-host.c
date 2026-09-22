/* SurfaceHolder lockCanvas / unlockCanvasAndPost contract.
   Guest surfaceCreated performs the locks. This harness does not. */
#include "game_dex_runner.h"
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

static int g_failures = 0;

static void expect(int condition, const char *message) {
    if (condition) {
        printf("PASS %s\n", message);
        return;
    }
    printf("FAIL %s\n", message);
    g_failures++;
}

static uint8_t *read_file(const char *path, uint32_t *size) {
    FILE *file = fopen(path, "rb");
    if (!file) return NULL;
    if (fseek(file, 0, SEEK_END) != 0) { fclose(file); return NULL; }
    long length = ftell(file);
    if (length <= 0) { fclose(file); return NULL; }
    rewind(file);
    uint8_t *bytes = malloc((size_t)length);
    if (!bytes || fread(bytes, 1, (size_t)length, file) != (size_t)length) {
        free(bytes);
        fclose(file);
        return NULL;
    }
    fclose(file);
    *size = (uint32_t)length;
    return bytes;
}

static int32_t field_of(agr_dex_game *game, const char *name) {
    int32_t value = -1;
    if (agr_dex_game_static_int(game, "Ltest/CanvasView;", name, &value) != 0) return -1;
    return value;
}

int main(int argc, char **argv) {
    alarm(30);
    dx_log_set_level(DX_LOG_WARN);
    const char *dex_path = argc > 1 ? argv[1] : "/tmp/surface-canvas.dex";
    const char *layout_path = argc > 2 ? argv[2] : "/tmp/surface-canvas-layouts/canvas.xml";
    uint32_t dex_size = 0, xml_size = 0;
    uint8_t *dex = read_file(dex_path, &dex_size);
    uint8_t *xml = read_file(layout_path, &xml_size);
    expect(dex && xml, "fixture dex and layout");
    if (!dex || !xml) return 1;

    agr_dex_game *game = agr_dex_game_create_for_launch(
        dex, dex_size, "Ltest/CanvasActivity;", "Ltest/CanvasApplication;", "test.canvas");
    expect(game != NULL, "create game");
    if (!game) return 1;
    agr_dex_game_enable_diagnostics(game, 1);
    expect(agr_dex_game_set_host_display(game, 320, 480) == 0, "host display");
    expect(agr_dex_game_start_activity(game) == 0, "start activity");
    expect(agr_dex_game_provide_layout(game, 0x7f030020, xml, xml_size) == 0, "provide layout");
    expect(agr_dex_game_set_content_layout(game, 0x7f030020) == 0, "set content layout");

    int frame1 = agr_dex_game_choreographer_frame(game);
    agr_dex_runtime_snapshot after1;
    memset(&after1, 0, sizeof(after1));
    agr_dex_game_runtime_snapshot(game, &after1);
    expect(frame1 == 0 && after1.content_surface_created_count == 0, "frame 1 does not create the child");

    int frame2 = agr_dex_game_choreographer_frame(game);
    agr_dex_runtime_snapshot snap;
    memset(&snap, 0, sizeof(snap));
    agr_dex_game_runtime_snapshot(game, &snap);
    printf("frame2=%d created=%u changed=%u format=%d %dx%d row=%d gen=%u "
           "lock=%u unlock=%u post=%u locked=%d owner=%u locked_gen=%u post_gen=%u "
           "hash_before=%llx hash_after=%llx pixels=%u content=%llu root=%llu exc=%s\n",
           frame2, snap.content_surface_created_count, snap.content_surface_changed_count,
           snap.content_surface_format, snap.content_surface_width, snap.content_surface_height,
           snap.canvas_row_bytes, snap.content_surface_generation,
           snap.canvas_lock_count, snap.canvas_unlock_count, snap.canvas_post_count,
           snap.canvas_locked, snap.canvas_lock_owner_exec, snap.canvas_locked_generation,
           snap.canvas_last_post_generation,
           (unsigned long long)snap.canvas_buffer_hash_before,
           (unsigned long long)snap.canvas_buffer_hash_after,
           snap.canvas_pixel_change_count,
           (unsigned long long)snap.content_surface_identity,
           (unsigned long long)snap.root_surface_identity,
           snap.exception_class);
    printf("flags width=%d height=%d gen=%d row=%d format=%d locked=%d reentry=%d "
           "blocked=%d lockOk=%d relock=%d acquired=%d waiting=%d changed=%d\n",
           field_of(game, "canvasWidth"), field_of(game, "canvasHeight"),
           field_of(game, "canvasGeneration"), field_of(game, "canvasRowBytes"),
           field_of(game, "canvasFormat"), field_of(game, "canvasLocked"),
           field_of(game, "reentryNull"), field_of(game, "waiterBlocked"),
           field_of(game, "lockOk"), field_of(game, "relockOk"),
           field_of(game, "acquired"), field_of(game, "waiting"), field_of(game, "changed"));

    expect(frame2 == 0, "frame 2 runs surfaceCreated");
    expect(snap.content_surface_created_count == 1 && snap.content_surface_changed_count == 1,
           "one surfaceCreated and one surfaceChanged");
    expect(snap.content_surface_valid && snap.content_surface_format == 4 &&
           snap.content_surface_width == 320 && snap.content_surface_height == 480,
           "content surface is 320x480 format 4");
    expect(snap.canvas_row_bytes == 320 * 4, "row bytes follow the 4-byte host backing");
    expect(snap.content_surface_identity != 0 && snap.root_surface_identity != 0 &&
           snap.content_surface_identity != snap.root_surface_identity,
           "canvas target is the child surface");
    expect(field_of(game, "canvasWidth") == 320 && field_of(game, "canvasHeight") == 480 &&
           field_of(game, "canvasRowBytes") == 320 * 4 && field_of(game, "canvasFormat") == 4 &&
           field_of(game, "canvasLocked") == 1 &&
           field_of(game, "canvasGeneration") == (int32_t)snap.content_surface_generation,
           "locked canvas matches the content surface");
    expect(field_of(game, "reentryNull") == 1, "same-context second lock returns null");
    expect(field_of(game, "waiterBlocked") == 1 && field_of(game, "acquired") == 1 &&
           field_of(game, "lockOk") == 1, "other context does not write while locked");
    expect(field_of(game, "relockOk") == 1, "no-arg lockCanvas succeeds after unlock");
    expect(snap.canvas_lock_count >= 3 && snap.canvas_unlock_count >= 3 && snap.canvas_post_count >= 3,
           "three lock and post cycles");
    expect(snap.canvas_locked == 0, "holder is unlocked after the protocol");
    expect(snap.canvas_buffer_hash_before != 0 &&
           snap.canvas_buffer_hash_before == snap.canvas_buffer_hash_after &&
           snap.canvas_pixel_change_count == 0,
           "post without a draw leaves the buffer unchanged");
    expect(snap.exception_class[0] == 0 && snap.content_surface_exception[0] == 0,
           "surfaceCreated did not throw");

    int32_t probe = -1;
    int probe_rc = agr_dex_game_invoke_int(game, "probeFailures", "()I", NULL, 0, &probe);
    agr_dex_runtime_snapshot after_probe;
    memset(&after_probe, 0, sizeof(after_probe));
    agr_dex_game_runtime_snapshot(game, &after_probe);
    printf("probe_rc=%d probe=%d wrong=%d notLocked=%d exc=%s\n",
           probe_rc, probe, field_of(game, "wrongCanvas"), field_of(game, "notLocked"),
           after_probe.exception_class);
    expect(probe_rc == 0 && probe == 1, "failure probe returns");
    expect(field_of(game, "wrongCanvas") == 1, "unlock of a different Canvas throws");
    expect(field_of(game, "notLocked") == 1, "unlock without a lock throws");
    expect(after_probe.canvas_locked == 0 && after_probe.canvas_post_count == snap.canvas_post_count,
           "failure probe does not post");

    agr_dex_game_destroy(game);
    free(dex);
    free(xml);
    printf("surface canvas contract: %s\n", g_failures ? "FAIL" : "PASS");
    return g_failures ? 1 : 0;
}
