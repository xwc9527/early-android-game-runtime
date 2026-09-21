/* Host-side API19 traversal dispatch contract.
   The test is the synthetic host pump: it calls agr_dex_game_choreographer_frame
   and never agr_dex_game_do_traversal on the dispatch game. A second game
   keeps the closed explicit do_traversal ordering. */
#include "game_dex_runner.h"
#include <GLES2/gl2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void glGenTextures(GLsizei n, GLuint *textures) {
    for (GLsizei i = 0; i < n; i++) if (textures) textures[i] = 1;
}
void glBindTexture(GLenum target, GLuint texture) { (void)target; (void)texture; }
void glTexParameteri(GLenum target, GLenum pname, GLint param) {
    (void)target; (void)pname; (void)param;
}
void glDeleteTextures(GLsizei n, const GLuint *textures) { (void)n; (void)textures; }

static int g_failures = 0;

static int reject_relayout(void *user, uint32_t width, uint32_t height, int visibility) {
    (void)user; (void)width; (void)height; (void)visibility;
    return -1;
}

static void expect(int condition, const char *message) {
    if (!condition) {
        fprintf(stderr, "FAIL %s\n", message);
        g_failures++;
    }
}

static int trace_has(const agr_dex_runtime_snapshot *snapshot, const char *event) {
    for (uint32_t i = 0; i < snapshot->framework_event_count; i++)
        if (!strcmp(snapshot->framework_events[i], event)) return 1;
    return 0;
}

static int trace_index(const agr_dex_runtime_snapshot *snapshot, const char *event) {
    for (uint32_t i = 0; i < snapshot->framework_event_count; i++)
        if (!strcmp(snapshot->framework_events[i], event)) return (int)i;
    return -1;
}

static int trace_index_after(const agr_dex_runtime_snapshot *snapshot, int start,
                             const char *event) {
    if (start < 0) return -1;
    for (uint32_t i = (uint32_t)start + 1; i < snapshot->framework_event_count; i++)
        if (!strcmp(snapshot->framework_events[i], event)) return (int)i;
    return -1;
}

static const char *trace_last(const agr_dex_runtime_snapshot *snapshot) {
    if (!snapshot->framework_event_count) return "";
    return snapshot->framework_events[snapshot->framework_event_count - 1];
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

static agr_dex_game *open_fixture(const uint8_t *dex, uint32_t size) {
    agr_dex_game *game = agr_dex_game_create_for_launch(dex, size,
        "Ltest/TestActivity;", "Ltest/TestApplication;", "test.activity.launch");
    if (game) agr_dex_game_enable_diagnostics(game, 1);
    return game;
}

int main(int argc, char **argv) {
    const char *dex_path = argc > 1 ? argv[1] : NULL;
    const char *output = argc > 2 ? argv[2] : NULL;
    uint32_t dex_size = 0;
    uint8_t *dex = dex_path ? read_file(dex_path, &dex_size) : NULL;
    expect(dex != NULL, "fixture dex");
    if (!dex) return 1;

    const uint32_t width = 320, height = 480;
    agr_dex_game *game = open_fixture(dex, dex_size);
    expect(game && agr_dex_game_set_host_display(game, width, height) == 0, "host display");
    expect(game && agr_dex_game_start_activity(game) == 0, "start schedules");
    agr_dex_runtime_snapshot started = {0};
    if (game) agr_dex_game_runtime_snapshot(game, &started);
    expect(started.traversal_count == 0 && started.traversal_scheduled &&
           started.draw_count == 0 && !started.surface_valid, "schedule is not execute");
    expect(!strcmp(trace_last(&started), "handoff.viewroot_traversal"),
           "start terminal remains the scheduled handoff");

    int frame1 = game ? agr_dex_game_choreographer_frame(game) : -1;
    agr_dex_runtime_snapshot after1 = {0};
    void *pixels1 = NULL;
    uint32_t w1 = 0, h1 = 0, stride1 = 0, gen1 = 0;
    if (game) agr_dex_game_runtime_snapshot(game, &after1);
    int surface1 = game ? agr_dex_game_root_surface(game, &pixels1, &w1, &h1, &stride1, &gen1) : -1;
    expect(frame1 == 0 && after1.traversal_count == 1 && after1.traversal_scheduled &&
           after1.surface_valid && after1.surface_generation == 1 && after1.draw_count == 0 &&
           surface1 == 0, "first frame consumes once and reschedules without draw");
    expect(!trace_has(&after1, "viewroot.perform_draw") && !trace_has(&after1, "view.draw"),
           "first frame does not enter performDraw");
    int consumed = trace_index(&after1, "viewroot.traversal.consumed");
    int rescheduled = trace_index(&after1, "viewroot.traversal.rescheduled");
    int ready = trace_index(&after1, "handoff.viewroot_surface_ready");
    int callback = trace_index(&after1, "choreographer.traversal.callback");
    expect(callback >= 0 && callback < consumed && consumed < rescheduled && rescheduled < ready,
           "first frame callback order");

    int frame2 = game ? agr_dex_game_choreographer_frame(game) : -1;
    agr_dex_runtime_snapshot after2 = {0};
    void *pixels2 = NULL;
    uint32_t w2 = 0, h2 = 0, stride2 = 0, gen2 = 0;
    if (game) agr_dex_game_runtime_snapshot(game, &after2);
    int surface2 = game ? agr_dex_game_root_surface(game, &pixels2, &w2, &h2, &stride2, &gen2) : -1;
    expect(frame2 == 0 && after2.traversal_count == 2 && !after2.traversal_scheduled &&
           after2.surface_valid && after2.surface_generation == 1 && after2.draw_count == 1 &&
           surface2 == 0 && pixels1 == pixels2 && gen1 == gen2, "second frame keeps Surface and draws");
    int second_consumed = trace_index_after(&after2, rescheduled, "viewroot.traversal.consumed");
    int draw = trace_index_after(&after2, second_consumed, "viewroot.perform_draw");
    int view_draw = trace_index_after(&after2, draw, "view.draw");
    expect(second_consumed >= 0 && draw > second_consumed && view_draw > draw,
           "second frame draw follows the second consume");

    int frame3 = game ? agr_dex_game_choreographer_frame(game) : -1;
    agr_dex_runtime_snapshot after3 = {0};
    if (game) agr_dex_game_runtime_snapshot(game, &after3);
    expect(frame3 == 1 && after3.traversal_count == 2 && after3.draw_count == 1 &&
           trace_has(&after3, "choreographer.traversal.idle"), "idle frame does not recurse");
    if (game) agr_dex_game_destroy(game);

    agr_dex_game *closed = open_fixture(dex, dex_size);
    expect(closed && agr_dex_game_start_activity(closed) == 0, "closed start");
    int explicit1 = closed ? agr_dex_game_do_traversal(closed, width, height) : -1;
    agr_dex_runtime_snapshot closed1 = {0};
    if (closed) agr_dex_game_runtime_snapshot(closed, &closed1);
    expect(explicit1 == 0 && closed1.traversal_count == 1 && closed1.draw_count == 0 &&
           !strcmp(trace_last(&closed1), "handoff.viewroot_surface_ready") &&
           !trace_has(&closed1, "viewroot.perform_draw") &&
           !trace_has(&closed1, "choreographer.frame"),
           "explicit first traversal still ends at the closed handoff");
    int explicit2 = closed ? agr_dex_game_do_traversal(closed, width, height) : -1;
    agr_dex_runtime_snapshot closed2 = {0};
    if (closed) agr_dex_game_runtime_snapshot(closed, &closed2);
    expect(explicit2 == 0 && closed2.traversal_count == 2 && !closed2.traversal_scheduled &&
           closed2.surface_generation == 1 && closed2.draw_count == 1,
           "explicit second traversal retains Surface and enters draw");
    if (closed) agr_dex_game_destroy(closed);

    agr_dex_game *failed = open_fixture(dex, dex_size);
    int failure = -1;
    agr_dex_runtime_snapshot failed_snapshot = {0};
    if (failed && agr_dex_game_set_host_display(failed, width, height) == 0 &&
        agr_dex_game_start_activity(failed) == 0 &&
        agr_dex_game_set_relayout_gate(failed, reject_relayout, NULL) == 0) {
        failure = agr_dex_game_choreographer_frame(failed);
        agr_dex_game_runtime_snapshot(failed, &failed_snapshot);
    }
    expect(failure != 0 && failed_snapshot.traversal_scheduled && !failed_snapshot.surface_valid &&
           failed_snapshot.draw_count == 0 && failed_snapshot.traversal_count == 0,
           "rejected relayout stays scheduled without a Surface");
    if (failed && agr_dex_game_set_relayout_gate(failed, NULL, NULL) == 0) {
        int retry = agr_dex_game_choreographer_frame(failed);
        agr_dex_runtime_snapshot retried = {0};
        agr_dex_game_runtime_snapshot(failed, &retried);
        expect(retry == 0 && retried.traversal_count == 1 && retried.surface_valid &&
               retried.draw_count == 0 && retried.traversal_scheduled,
               "the same frame consumer retries after the host gate clears");
    }
    if (failed) agr_dex_game_destroy(failed);

    agr_dex_game *content = open_fixture(dex, dex_size);
    agr_dex_runtime_snapshot content_before = {0}, content_after = {0}, content_idle = {0};
    int content_set = -1;
    if (content && agr_dex_game_set_host_display(content, width, height) == 0 &&
        agr_dex_game_start_activity(content) == 0) {
        agr_dex_game_runtime_snapshot(content, &content_before);
        content_set = agr_dex_game_set_content_view(content);
        agr_dex_game_runtime_snapshot(content, &content_after);
    }
    expect(content_set == 0 && !content_before.content_view_installed &&
           content_after.content_view_installed &&
           content_after.content_layout_width == -1 &&
           content_after.content_layout_height == -1 &&
           content_after.traversal_count == 0 && content_after.traversal_scheduled &&
           content_after.draw_count == 0 && content_after.viewroot_root_assigned &&
           trace_has(&content_after, "window.set_content_view") &&
           !trace_has(&content_after, "viewroot.traversal.consumed"),
           "setContentView installs the child and does not execute the scheduled traversal");
    int content_frame = content ? agr_dex_game_choreographer_frame(content) : -1;
    if (content) agr_dex_game_runtime_snapshot(content, &content_idle);
    expect(content_frame == 0 && content_idle.traversal_count == 1 &&
           content_idle.content_view_installed && content_idle.draw_count == 0,
           "the already scheduled frame still consumes once after setContentView");
    if (content) agr_dex_game_destroy(content);

    agr_dex_game *late = open_fixture(dex, dex_size);
    int late_set = -1, late_frame = -1;
    agr_dex_runtime_snapshot late_done = {0}, late_posted = {0}, late_ran = {0};
    if (late && agr_dex_game_set_host_display(late, width, height) == 0 &&
        agr_dex_game_start_activity(late) == 0 &&
        agr_dex_game_choreographer_frame(late) == 0 &&
        agr_dex_game_choreographer_frame(late) == 0) {
        agr_dex_game_runtime_snapshot(late, &late_done);
        late_set = agr_dex_game_set_content_view(late);
        agr_dex_game_runtime_snapshot(late, &late_posted);
        late_frame = agr_dex_game_choreographer_frame(late);
        agr_dex_game_runtime_snapshot(late, &late_ran);
    }
    expect(late_set == 0 && late_done.traversal_count == 2 && !late_done.traversal_scheduled &&
           late_posted.traversal_count == 2 && late_posted.traversal_scheduled &&
           late_posted.draw_count == 1 && late_posted.content_view_installed &&
           late_frame == 0 && late_ran.traversal_count == 3 && !late_ran.traversal_scheduled &&
           late_ran.draw_count == 2 && late_ran.surface_generation == 1,
           "a later setContentView posts one more traversal and the next frame draws");
    if (late) agr_dex_game_destroy(late);
    free(dex);

    if (g_failures) {
        fprintf(stderr, "%d dispatch contract failure(s)\n", g_failures);
        return 1;
    }
    if (output) {
        FILE *out = fopen(output, "w");
        if (!out) return 1;
        fprintf(out,
            "{\n"
            "  \"schema\": \"agr.framework-traversal-dispatch.host.v1\",\n"
            "  \"passed\": true,\n"
            "  \"display\": [%u, %u],\n"
            "  \"after_start\": {\"traversal_count\": 0, \"traversal_scheduled\": true, \"draw_count\": 0},\n"
            "  \"frame1\": {\"result\": 0, \"traversal_count\": 1, \"traversal_scheduled\": true,\n"
            "    \"surface_valid\": true, \"surface_generation\": 1, \"draw_count\": 0},\n"
            "  \"frame2\": {\"result\": 0, \"traversal_count\": 2, \"traversal_scheduled\": false,\n"
            "    \"surface_valid\": true, \"surface_generation\": 1, \"draw_count\": 1, \"same_backing\": true},\n"
            "  \"frame3\": {\"result\": 1, \"traversal_count\": 2, \"draw_count\": 1},\n"
            "  \"closed_explicit\": {\"first_terminal\": \"handoff.viewroot_surface_ready\",\n"
            "    \"first_draw_count\": 0, \"second_traversal_count\": 2, \"second_draw_count\": 1},\n"
            "  \"relayout_failure_result\": -1,\n"
            "  \"relayout_failure_scheduled\": true,\n"
            "  \"relayout_failure_surface_valid\": false\n"
            "}\n", width, height);
        fclose(out);
    }
    printf("traversal dispatch host contract: PASS\n");
    return 0;
}
