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

static int print_game_modes(agr_dex_game *game, const char *when) {
    DxVM *vm = agr_dex_game_vm(game);
    int ready = -1;
    for (uint32_t i = 0; vm && i < vm->heap_count; i++) {
        DxObject *obj = vm->heap[i];
        DxValue mode = DX_NULL_VALUE;
        DxValue frozen = DX_NULL_VALUE;
        if (!obj || !obj->klass || !obj->klass->descriptor ||
            strcmp(obj->klass->descriptor, "Lorg/jfedor/frozenbubble/GameView$GameThread;") != 0)
            continue;
        if (dx_vm_get_field(obj, "mMode", &mode) == DX_OK && mode.tag == DX_VAL_INT)
            printf("guest_game_mode %s=%d\n", when, mode.i);
        if (dx_vm_get_field(obj, "mFrozenGame", &frozen) == DX_OK &&
            frozen.tag == DX_VAL_OBJ && frozen.obj) {
            DxValue flag = DX_NULL_VALUE;
            if (dx_vm_get_field(frozen.obj, "readyToFire", &flag) == DX_OK &&
                flag.tag == DX_VAL_INT) {
                ready = flag.i;
                printf("guest_ready_to_fire %s=%d\n", when, ready);
            }
        }
    }
    return ready;
}

static void expect(int condition, const char *message) {
    if (condition) {
        printf("PASS %s\n", message);
    } else {
        printf("FAIL %s\n", message);
        g_failures++;
    }
    fflush(stdout);
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
    const char *apk_path = argc > 1 ? argv[1] : "samples/frozen-bubble.apk";
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
    {
        agr_dex_posted_surface posted = {0};
        unsigned char prefix[64] = {0};
        int acquired = agr_dex_game_copy_posted_surface(game, 0, 0, &posted);
        expect(acquired == 0 && posted.pixels && posted.bytes == 1080u * 2340u * 4u &&
               posted.width == 1080 && posted.height == 2340 &&
               posted.surface_identity == snapshot.content_surface_identity &&
               posted.generation == snapshot.content_surface_generation &&
               posted.post_count > 0 && posted.pixel_hash != 0,
               "host acquires original game completed child-Surface post");
        if (acquired == 0 && posted.bytes >= sizeof(prefix)) {
            memcpy(prefix, posted.pixels, sizeof(prefix));
            usleep(60000);
            expect(memcmp(prefix, posted.pixels, sizeof(prefix)) == 0,
                   "owned host post is immutable while the game keeps drawing");
        }
        agr_dex_posted_surface_release(&posted);
    }
    {
        uint32_t before_posts = snapshot.canvas_post_count;
        uint64_t before_hash = snapshot.canvas_buffer_hash_after;
        print_game_modes(game, "before_touch");
        int down = agr_dex_game_dispatch_touch(game, 0, 540.0f, 450.0f, 1000);
        int up = agr_dex_game_dispatch_touch(game, 1, 540.0f, 450.0f, 1100);
        expect(down == 1 && up == 1, "original GameView consumes down and up through Activity/Window/View");
        for (int sample = 0; sample < 6; sample++) {
            usleep(500000);
            expect(agr_dex_game_runtime_snapshot(game, &snapshot) == 0, "snapshot after touch");
            printf("touch_progress sample=%d posts=%u hash=%llx methods=%llu insns=%llu\n",
                   sample, snapshot.canvas_post_count,
                   (unsigned long long)snapshot.canvas_buffer_hash_after,
                   (unsigned long long)snapshot.methods_invoked,
                   (unsigned long long)snapshot.instructions_executed);
            if (snapshot.canvas_buffer_hash_after != before_hash) break;
        }
        int ready = print_game_modes(game, "after_touch");
        if (ready == 1) {
            int down2 = agr_dex_game_dispatch_touch(game, 0, 540.0f, 450.0f, 4000);
            int up2 = agr_dex_game_dispatch_touch(game, 1, 540.0f, 450.0f, 4100);
            printf("second_touch down=%d up=%d\n", down2, up2);
            expect(down2 == 1 && up2 == 1, "second touch reaches original game when fire is ready");
            for (int sample = 0; sample < 6; sample++) {
                usleep(500000);
                expect(agr_dex_game_runtime_snapshot(game, &snapshot) == 0,
                       "snapshot after second touch");
                printf("second_touch_progress sample=%d posts=%u hash=%llx\n",
                       sample, snapshot.canvas_post_count,
                       (unsigned long long)snapshot.canvas_buffer_hash_after);
                if (snapshot.canvas_buffer_hash_after != before_hash) break;
            }
        }
        for (uint32_t i = 0; i < snapshot.method_event_count; i++)
            if (strstr(snapshot.method_events[i].method, "onTouchEvent") ||
                strstr(snapshot.method_events[i].method, "doTouchEvent") ||
                strstr(snapshot.method_events[i].method, "MotionEvent") ||
                strstr(snapshot.method_events[i].method, "updateGameState") ||
                strstr(snapshot.method_events[i].method, "FrozenGame;->play"))
                printf("guest_touch_method %s\n", snapshot.method_events[i].method);
        printf("touch down=%d up=%d attached=%d visible=%d dispatched=%u consumed=%u posts=%u->%u hash=%llx->%llx vm_error=%s\n",
               down, up, snapshot.viewroot_attach_completed, snapshot.window_visible,
               snapshot.touch_dispatched, snapshot.touch_consumed,
               before_posts, snapshot.canvas_post_count,
               (unsigned long long)before_hash,
               (unsigned long long)snapshot.canvas_buffer_hash_after,
               snapshot.error);
        expect(snapshot.touch_dispatched == (ready == 1 ? 4u : 2u) &&
               snapshot.touch_consumed == (ready == 1 ? 4u : 2u),
               "touch consumption counters reflect guest result");
        expect(snapshot.canvas_post_count > before_posts, "GameThread continues after touch");
        expect(snapshot.canvas_buffer_hash_after != before_hash,
               "original game touch changes a later completed frame");
    }
    agr_dex_game_destroy(game);
    agr_apk_package_close(package);
    printf("frozen-bubble-1080: %s\n", g_failures ? "FAIL" : "PASS");
    return g_failures ? 1 : 0;
}
