/* Host-side API19 traversal dispatch contract.
   The test is the synthetic host pump: it calls agr_dex_game_choreographer_frame
   and never agr_dex_game_do_traversal on the dispatch game. A second game
   keeps the closed explicit do_traversal ordering. */
#include "game_dex_runner.h"
#include "layout-content-fixture.inc"
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

static void *fail_content_alloc(void *user, size_t bytes) {
    (void)user;
    (void)bytes;
    return NULL;
}

static void fail_content_free(void *user, void *pixels) {
    (void)user;
    (void)pixels;
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

static int pump_surface(agr_dex_game *game, const uint8_t *xml, uint32_t xml_size,
                        uint32_t layout_id, agr_dex_runtime_snapshot *frame1,
                        agr_dex_runtime_snapshot *frame2) {
    if (!game || agr_dex_game_start_activity(game) != 0) return -1;
    if (agr_dex_game_provide_layout(game, layout_id, xml, xml_size) != 0) return -1;
    if (agr_dex_game_set_content_layout(game, layout_id) != 0) return -1;
    if (agr_dex_game_choreographer_frame(game) != 0) return -1;
    agr_dex_game_runtime_snapshot(game, frame1);
    if (agr_dex_game_choreographer_frame(game) != 0) return -1;
    agr_dex_game_runtime_snapshot(game, frame2);
    return 0;
}

int main(int argc, char **argv) {
    const char *dex_path = argc > 1 ? argv[1] : NULL;
    const char *output = argc > 2 ? argv[2] : NULL;
    const char *surface_dex_path = argc > 3 ? argv[3] : NULL;
    const char *layout_dir = argc > 4 ? argv[4] : NULL;
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

    agr_dex_game *layout = open_fixture(dex, dex_size);
    int layout_ready = -1, layout_set = -1;
    agr_dex_runtime_snapshot layout_before = {0}, layout_after = {0};
    if (layout && agr_dex_game_set_host_display(layout, width, height) == 0 &&
        agr_dex_game_start_activity(layout) == 0) {
        layout_ready = agr_dex_game_provide_layout(layout, 0x7f030000, k_layout_xml,
                                                   (uint32_t)sizeof(k_layout_xml));
        agr_dex_game_runtime_snapshot(layout, &layout_before);
        layout_set = agr_dex_game_set_content_layout(layout, 0x7f030000);
        agr_dex_game_runtime_snapshot(layout, &layout_after);
    }
    expect(layout_ready == 0 && layout_set == 0 &&
           !layout_before.content_view_installed && layout_before.traversal_count == 0 &&
           layout_before.traversal_scheduled &&
           layout_after.content_view_installed && layout_after.content_child_count == 1 &&
           layout_after.content_first_child_id == 0x7f060001 &&
           layout_after.content_layout_width == -1 && layout_after.content_layout_height == -1 &&
           layout_after.traversal_count == 0 && layout_after.traversal_scheduled &&
           layout_after.draw_count == 0 &&
           trace_has(&layout_after, "window.set_content_view") &&
           !trace_has(&layout_after, "viewroot.traversal.consumed"),
           "setContentView(int) inflates one MATCH_PARENT child and does not consume the traversal");
    if (layout) agr_dex_game_destroy(layout);

    uint32_t surface_dex_size = 0;
    uint8_t *surface_dex = surface_dex_path ? read_file(surface_dex_path, &surface_dex_size) : NULL;
    char layout_path[512];
    uint32_t callback_xml_size = 0, hidden_xml_size = 0, zero_xml_size = 0, removed_xml_size = 0;
    uint8_t *callback_xml = NULL, *hidden_xml = NULL, *zero_xml = NULL, *removed_xml = NULL;
    agr_dex_runtime_snapshot callback1 = {0}, callback2 = {0}, callback3 = {0};
    agr_dex_runtime_snapshot hidden2 = {0}, zero2 = {0}, removed2 = {0}, failed2 = {0};
    int32_t callback_created = -1, callback_changed = -1, callback_format = -1;
    int32_t callback_width = -1, callback_height = -1;
    int callback_pump = -1, hidden_pump = -1, zero_pump = -1, removed_pump = -1, failed_pump = -1;
    int callback_frame3 = -1;
    expect(surface_dex != NULL && layout_dir != NULL, "surface fixture");
    if (surface_dex && layout_dir) {
        snprintf(layout_path, sizeof(layout_path), "%s/callback.xml", layout_dir);
        callback_xml = read_file(layout_path, &callback_xml_size);
        snprintf(layout_path, sizeof(layout_path), "%s/hidden.xml", layout_dir);
        hidden_xml = read_file(layout_path, &hidden_xml_size);
        snprintf(layout_path, sizeof(layout_path), "%s/zero.xml", layout_dir);
        zero_xml = read_file(layout_path, &zero_xml_size);
        snprintf(layout_path, sizeof(layout_path), "%s/removed.xml", layout_dir);
        removed_xml = read_file(layout_path, &removed_xml_size);
    }
    expect(callback_xml && hidden_xml && zero_xml && removed_xml, "surface layouts");

    agr_dex_game *surface_game = surface_dex ? agr_dex_game_create_for_launch(surface_dex, surface_dex_size,
        "Ltest/SurfaceActivity;", "Ltest/SurfaceApplication;", "test.surface") : NULL;
    if (surface_game) {
        agr_dex_game_enable_diagnostics(surface_game, 1);
        agr_dex_game_set_host_display(surface_game, width, height);
    }
    callback_pump = surface_game && callback_xml ? pump_surface(surface_game, callback_xml, callback_xml_size,
                                                                0x7f030010, &callback1, &callback2) : -1;
    callback_frame3 = callback_pump == 0 ? agr_dex_game_choreographer_frame(surface_game) : -1;
    if (surface_game && callback_frame3 == 0) agr_dex_game_runtime_snapshot(surface_game, &callback3);
    if (surface_game) {
        agr_dex_game_static_int(surface_game, "Ltest/CallbackView;", "created", &callback_created);
        agr_dex_game_static_int(surface_game, "Ltest/CallbackView;", "changed", &callback_changed);
        agr_dex_game_static_int(surface_game, "Ltest/CallbackView;", "format", &callback_format);
        agr_dex_game_static_int(surface_game, "Ltest/CallbackView;", "width", &callback_width);
        agr_dex_game_static_int(surface_game, "Ltest/CallbackView;", "height", &callback_height);
    }
    expect(callback_pump == 0 && callback1.content_surface_created_count == 0 &&
           callback1.traversal_count == 1 && callback1.draw_count == 0 &&
           !trace_has(&callback1, "surface_view.child_surface_created"),
           "the first host frame does not create the child surface");
    expect(callback2.content_surface_valid && callback2.content_surface_created_count == 1 &&
           callback2.content_surface_changed_count == 1 &&
           callback2.content_surface_callback_count == 1 &&
           callback2.content_surface_generation == 1 &&
           callback2.content_surface_width == (int)width &&
           callback2.content_surface_height == (int)height &&
           callback2.content_surface_format == 4 &&
           callback2.content_surface_owner_id == 0x7f060010 &&
           callback2.content_surface_identity != 0 &&
           callback2.content_surface_identity != callback2.root_surface_identity &&
           callback_created == 1 && callback_changed == 1 && callback_format == 4 &&
           callback_width == (int32_t)width && callback_height == (int32_t)height &&
           callback2.traversal_count == 2 && callback2.draw_count == 1 &&
           callback2.surface_generation == 1,
           "draw traversal creates one child surface and delivers surfaceCreated then surfaceChanged");
    expect(trace_index(&callback2, "surface_view.child_surface_created") >= 0 &&
           trace_index(&callback2, "surface_view.child_surface_created") <
               trace_index(&callback2, "surface_holder.surface_created") &&
           trace_index(&callback2, "surface_holder.surface_created") <
               trace_index(&callback2, "surface_holder.surface_changed") &&
           trace_index(&callback2, "surface_holder.surface_changed") <
               trace_index(&callback2, "viewroot.perform_draw"),
           "holder callbacks precede performDraw");
    expect(callback_frame3 == 0 && callback3.traversal_count == 3 && callback3.draw_count == 2 &&
           callback3.content_surface_created_count == 1 &&
           callback3.content_surface_changed_count == 1 &&
           callback3.content_surface_generation == 1 &&
           callback3.content_surface_identity == callback2.content_surface_identity &&
           !callback3.traversal_scheduled,
           "a later traversal does not repeat surfaceCreated");
    if (surface_game) agr_dex_game_destroy(surface_game);

    agr_dex_game *hidden = surface_dex ? agr_dex_game_create_for_launch(surface_dex, surface_dex_size,
        "Ltest/SurfaceActivity;", "Ltest/SurfaceApplication;", "test.surface") : NULL;
    if (hidden) {
        agr_dex_game_enable_diagnostics(hidden, 1);
        agr_dex_game_set_host_display(hidden, width, height);
        hidden_pump = hidden_xml ? pump_surface(hidden, hidden_xml, hidden_xml_size,
                                                0x7f030011, &callback1, &hidden2) : -1;
    }
    expect(hidden_pump == 0 && hidden2.content_surface_callback_count == 1 &&
           !hidden2.content_surface_valid && hidden2.content_surface_created_count == 0 &&
           hidden2.content_surface_changed_count == 0 && hidden2.draw_count == 1,
           "an invisible SurfaceView keeps its callback and does not create a surface");
    if (hidden) agr_dex_game_destroy(hidden);

    agr_dex_game *zero = surface_dex ? agr_dex_game_create_for_launch(surface_dex, surface_dex_size,
        "Ltest/SurfaceActivity;", "Ltest/SurfaceApplication;", "test.surface") : NULL;
    if (zero) {
        agr_dex_game_enable_diagnostics(zero, 1);
        agr_dex_game_set_host_display(zero, width, height);
        zero_pump = zero_xml ? pump_surface(zero, zero_xml, zero_xml_size,
                                            0x7f030012, &callback1, &zero2) : -1;
    }
    expect(zero_pump == 0 && zero2.content_surface_callback_count == 1 &&
           !zero2.content_surface_valid && zero2.content_surface_created_count == 0 &&
           zero2.draw_count == 1,
           "a zero-size SurfaceView does not create a surface");
    if (zero) agr_dex_game_destroy(zero);

    agr_dex_game *removed = surface_dex ? agr_dex_game_create_for_launch(surface_dex, surface_dex_size,
        "Ltest/SurfaceActivity;", "Ltest/SurfaceApplication;", "test.surface") : NULL;
    if (removed) {
        agr_dex_game_enable_diagnostics(removed, 1);
        agr_dex_game_set_host_display(removed, width, height);
        removed_pump = removed_xml ? pump_surface(removed, removed_xml, removed_xml_size,
                                                  0x7f030013, &callback1, &removed2) : -1;
    }
    expect(removed_pump == 0 && removed2.content_surface_callback_count == 0 &&
           removed2.content_surface_valid && removed2.content_surface_created_count == 0 &&
           removed2.content_surface_changed_count == 0 &&
           removed2.content_surface_generation == 1 &&
           removed2.content_surface_identity != 0 &&
           removed2.content_surface_identity != removed2.root_surface_identity,
           "removing the callback still creates the child surface without a callback");
    if (removed) agr_dex_game_destroy(removed);

    agr_dex_game *alloc_fail = surface_dex ? agr_dex_game_create_for_launch(surface_dex, surface_dex_size,
        "Ltest/SurfaceActivity;", "Ltest/SurfaceApplication;", "test.surface") : NULL;
    if (alloc_fail) {
        agr_dex_game_enable_diagnostics(alloc_fail, 1);
        agr_dex_game_set_host_display(alloc_fail, width, height);
        expect(agr_dex_game_set_content_surface_allocator(alloc_fail, fail_content_alloc,
                                                         fail_content_free, NULL) == 0,
               "content surface allocator");
        failed_pump = callback_xml ? pump_surface(alloc_fail, callback_xml, callback_xml_size,
                                                  0x7f030010, &callback1, &failed2) : -1;
    }
    expect(failed_pump == 0 && !failed2.content_surface_valid &&
           failed2.content_surface_created_count == 0 && failed2.surface_valid &&
           failed2.draw_count == 1 && trace_has(&failed2, "surface_view.allocation_failed"),
           "child surface allocation failure does not invent a callback or replace the root surface");
    if (alloc_fail) agr_dex_game_destroy(alloc_fail);

    free(callback_xml);
    free(hidden_xml);
    free(zero_xml);
    free(removed_xml);
    free(surface_dex);
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
            "  \"relayout_failure_surface_valid\": false,\n"
            "  \"layout_install\": {\"content_view_installed\": true, \"content_child_count\": %d,\n"
            "    \"content_first_child_id\": %d, \"content_layout_width\": %d,\n"
            "    \"content_layout_height\": %d, \"traversal_count\": %u, \"traversal_scheduled\": true,\n"
            "    \"draw_count\": %u},\n"
            "  \"surface_callback\": {\"created_count\": %u, \"changed_count\": %u,\n"
            "    \"callback_count\": %u, \"generation\": %u, \"width\": %d, \"height\": %d,\n"
            "    \"format\": %d, \"valid\": true, \"owner_id\": %d,\n"
            "    \"identity_differs_from_root\": true, \"repeat_created_count\": %u,\n"
            "    \"static_created\": %d, \"static_changed\": %d, \"static_format\": %d,\n"
            "    \"static_width\": %d, \"static_height\": %d},\n"
            "  \"surface_hidden\": {\"valid\": false, \"created_count\": %u, \"callback_count\": %u},\n"
            "  \"surface_zero\": {\"valid\": false, \"created_count\": %u, \"callback_count\": %u},\n"
            "  \"surface_removed\": {\"valid\": true, \"created_count\": %u, \"callback_count\": %u,\n"
            "    \"generation\": %u},\n"
            "  \"surface_alloc_failed\": {\"valid\": false, \"created_count\": %u, \"root_valid\": true}\n"
            "}\n", width, height,
            layout_after.content_child_count, layout_after.content_first_child_id,
            layout_after.content_layout_width, layout_after.content_layout_height,
            layout_after.traversal_count, layout_after.draw_count,
            callback2.content_surface_created_count, callback2.content_surface_changed_count,
            callback2.content_surface_callback_count, callback2.content_surface_generation,
            callback2.content_surface_width, callback2.content_surface_height,
            callback2.content_surface_format, callback2.content_surface_owner_id,
            callback3.content_surface_created_count, callback_created, callback_changed,
            callback_format, callback_width, callback_height,
            hidden2.content_surface_created_count, hidden2.content_surface_callback_count,
            zero2.content_surface_created_count, zero2.content_surface_callback_count,
            removed2.content_surface_created_count, removed2.content_surface_callback_count,
            removed2.content_surface_generation,
            failed2.content_surface_created_count);
        fclose(out);
    }
    printf("traversal dispatch host contract: PASS\n");
    return 0;
}
