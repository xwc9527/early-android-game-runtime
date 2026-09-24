/* Surface callback outcome. The harness starts the Activity and pumps frames.
   It does not call lockCanvas, drawBitmap, or the callbacks itself. */
#include "game_dex_runner.h"
#include "agr_forensic.h"
#include "dx_log.h"
#include <GLES2/gl2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
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
    long length;
    uint8_t *bytes;
    if (!file) return NULL;
    if (fseek(file, 0, SEEK_END) != 0) { fclose(file); return NULL; }
    length = ftell(file);
    if (length <= 0) { fclose(file); return NULL; }
    rewind(file);
    bytes = malloc((size_t)length);
    if (!bytes || fread(bytes, 1, (size_t)length, file) != (size_t)length) {
        free(bytes);
        fclose(file);
        return NULL;
    }
    fclose(file);
    *size = (uint32_t)length;
    return bytes;
}

static char *trace_text(const char *dir) {
    char path[512];
    FILE *fp;
    long length;
    char *text;
    snprintf(path, sizeof(path), "%s/agr-current-trace.ndjson", dir);
    fp = fopen(path, "rb");
    if (!fp) return NULL;
    if (fseek(fp, 0, SEEK_END) != 0) { fclose(fp); return NULL; }
    length = ftell(fp);
    if (length < 0) { fclose(fp); return NULL; }
    rewind(fp);
    text = malloc((size_t)length + 1);
    if (!text) { fclose(fp); return NULL; }
    if (fread(text, 1, (size_t)length, fp) != (size_t)length) {
        free(text);
        fclose(fp);
        return NULL;
    }
    fclose(fp);
    text[length] = 0;
    return text;
}

static int pump(agr_dex_game *game, const uint8_t *xml, uint32_t xml_size, uint32_t layout_id,
                agr_dex_runtime_snapshot *snap) {
    int frame2;
    if (!game || agr_dex_game_start_activity(game) != 0) return -1;
    if (agr_dex_game_provide_layout(game, layout_id, xml, xml_size) != 0) return -1;
    if (agr_dex_game_set_content_layout(game, layout_id) != 0) return -1;
    if (agr_dex_game_choreographer_frame(game) != 0) return -1;
    frame2 = agr_dex_game_choreographer_frame(game);
    if (agr_dex_game_runtime_snapshot(game, snap) != 0) return -1;
    return frame2;
}

static void begin_trace(const char *dir) {
    agr_physical_trace_config config;
    mkdir(dir, 0755);
    memset(&config, 0, sizeof(config));
    config.directory = dir;
    config.branch = "test-branch";
    config.commit = "abc123";
    config.tree = "def456";
    config.device_platform = "linux";
    config.architecture = "host";
    config.apk_sha256_expected = "none";
    agr_physical_trace_set_watchdog_for_test(50, 60000, 60000, 60000);
    expect(agr_physical_trace_begin(&config) == 0, "trace begin");
}

static agr_dex_game *open_game(const uint8_t *dex, uint32_t dex_size) {
    agr_dex_game *game = agr_dex_game_create_for_launch(
        dex, dex_size, "Ltest/OutcomeActivity;", "Ltest/OutcomeApplication;", "test.outcome");
    if (!game) return NULL;
    agr_dex_game_enable_diagnostics(game, 1);
    if (agr_dex_game_set_host_display(game, 320, 480) != 0) {
        agr_dex_game_destroy(game);
        return NULL;
    }
    return game;
}

int main(int argc, char **argv) {
    const char *dex_path = argc > 1 ? argv[1] : "/tmp/surface-callback-outcome.dex";
    const char *layout_dir = argc > 2 ? argv[2] : "/tmp/surface-callback-outcome-layouts";
    uint32_t dex_size = 0;
    uint8_t *dex = read_file(dex_path, &dex_size);
    char layout_path[512];
    uint32_t ok_size = 0, created_size = 0, changed_size = 0;
    uint8_t *ok_xml;
    uint8_t *created_xml;
    uint8_t *changed_xml;
    alarm(30);
    dx_log_set_level(DX_LOG_WARN);
    expect(dex != NULL, "outcome dex");
    if (!dex) return 1;
    snprintf(layout_path, sizeof(layout_path), "%s/ok.xml", layout_dir);
    ok_xml = read_file(layout_path, &ok_size);
    snprintf(layout_path, sizeof(layout_path), "%s/throw-created.xml", layout_dir);
    created_xml = read_file(layout_path, &created_size);
    snprintf(layout_path, sizeof(layout_path), "%s/throw-changed.xml", layout_dir);
    changed_xml = read_file(layout_path, &changed_size);
    expect(ok_xml && created_xml && changed_xml, "outcome layouts");
    if (!ok_xml || !created_xml || !changed_xml) return 1;

    {
        agr_dex_game *game = open_game(dex, dex_size);
        agr_dex_runtime_snapshot snap;
        char *text;
        int frame;
        memset(&snap, 0, sizeof(snap));
        begin_trace("/tmp/agr-callback-ok");
        frame = game ? pump(game, ok_xml, ok_size, 0x7f030020, &snap) : -1;
        agr_physical_trace_finish("OBSERVATION", NULL);
        agr_physical_trace_shutdown();
        text = trace_text("/tmp/agr-callback-ok");
        printf("ok frame=%d created=%u changed=%u exc=%s\n",
               frame, snap.content_surface_created_count, snap.content_surface_changed_count,
               snap.content_surface_exception);
        expect(frame == 0, "success frame");
        expect(snap.content_surface_created_count == 1, "surfaceCreated success count");
        expect(snap.content_surface_changed_count == 1, "surfaceChanged success count");
        expect(snap.content_surface_exception[0] == 0, "success leaves no exception");
        expect(text && strstr(text, "\"event\":\"SURFACE_CALLBACK_OK\"") != NULL, "SURFACE_CALLBACK_OK");
        expect(text && strstr(text, "CALLBACK_OK") != NULL, "CALLBACK_OK token");
        free(text);
        if (game) agr_dex_game_destroy(game);
    }
    {
        agr_dex_game *game = open_game(dex, dex_size);
        agr_dex_runtime_snapshot snap;
        char *text;
        memset(&snap, 0, sizeof(snap));
        begin_trace("/tmp/agr-callback-throw-created");
        if (game) pump(game, created_xml, created_size, 0x7f030021, &snap);
        agr_physical_trace_finish("OBSERVATION", NULL);
        agr_physical_trace_shutdown();
        text = trace_text("/tmp/agr-callback-throw-created");
        printf("throw-created created=%u changed=%u exc=%s pending=%d class=%s\n",
               snap.content_surface_created_count, snap.content_surface_changed_count,
               snap.content_surface_exception, snap.pending_exception, snap.exception_class);
        expect(snap.content_surface_created_count == 0, "throw does not increment created_count");
        expect(snap.content_surface_changed_count == 0, "throw skips surfaceChanged");
        expect(strstr(snap.content_surface_exception, "Ljava/lang/RuntimeException;") != NULL,
               "created throw preserves RuntimeException");
        expect(text && strstr(text, "\"event\":\"SURFACE_CALLBACK_THROW\"") != NULL,
               "SURFACE_CALLBACK_THROW");
        expect(text && strstr(text, "Ljava/lang/RuntimeException;") != NULL,
               "throw trace keeps the exception class");
        expect(!text || strstr(text, "\"event\":\"SURFACE_CALLBACK_OK\"") == NULL,
               "a throw is not CALLBACK_OK");
        free(text);
        if (game) agr_dex_game_destroy(game);
    }
    {
        agr_dex_game *game = open_game(dex, dex_size);
        agr_dex_runtime_snapshot snap;
        char *text;
        memset(&snap, 0, sizeof(snap));
        begin_trace("/tmp/agr-callback-throw-changed");
        if (game) pump(game, changed_xml, changed_size, 0x7f030022, &snap);
        agr_physical_trace_finish("OBSERVATION", NULL);
        agr_physical_trace_shutdown();
        text = trace_text("/tmp/agr-callback-throw-changed");
        printf("throw-changed created=%u changed=%u exc=%s\n",
               snap.content_surface_created_count, snap.content_surface_changed_count,
               snap.content_surface_exception);
        expect(snap.content_surface_created_count == 1, "surfaceCreated still counts when it returns");
        expect(snap.content_surface_changed_count == 0, "throw does not increment changed_count");
        expect(strstr(snap.content_surface_exception, "Ljava/lang/RuntimeException;") != NULL,
               "changed throw preserves RuntimeException");
        expect(text && strstr(text, "\"event\":\"SURFACE_CALLBACK_THROW\"") != NULL,
               "changed SURFACE_CALLBACK_THROW");
        expect(text && strstr(text, "surfaceChanged") != NULL, "changed callback name");
        free(text);
        if (game) agr_dex_game_destroy(game);
    }

    free(dex);
    free(ok_xml);
    free(created_xml);
    free(changed_xml);
    printf("surface callback outcome: %s\n", g_failures ? "FAIL" : "PASS");
    return g_failures ? 1 : 0;
}
