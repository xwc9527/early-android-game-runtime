#include "agr_forensic.h"

#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

static int g_failures = 0;

static void expect(int cond, const char *what) {
    if (!cond) {
        fprintf(stderr, "FAIL %s\n", what);
        g_failures++;
    }
}

static void quiet_watchdog(void) {
    agr_physical_trace_set_watchdog_for_test(60000, 60000, 60000, 60000);
}

static agr_physical_trace_config config_for(const char *dir) {
    agr_physical_trace_config config;
    memset(&config, 0, sizeof(config));
    config.directory = dir;
    config.branch = "test-branch";
    config.commit = "abc123";
    config.tree = "def456";
    config.device_platform = "iphoneos";
    config.architecture = "arm64";
    config.apk_sha256_expected = "57f4735297befc68c0a7aa6cd9e442ecd250b1b2b38104324a12b6c2d4e18569";
    return config;
}

static void note(uint32_t phase, int critical, int has_exec, uint32_t exec, uint64_t host,
                 int locked, uint32_t locks, uint32_t unlocks, uint32_t posts,
                 uint32_t draws, uint32_t pixels, const char *detail) {
    agr_forensic_sample sample;
    memset(&sample, 0, sizeof(sample));
    sample.phase = phase;
    sample.critical = critical;
    sample.has_exec = has_exec;
    sample.exec_id = exec;
    sample.host_thread = host;
    sample.thread_state = 2;
    sample.canvas_locked = locked;
    sample.lock_owner_exec = has_exec ? exec : 0;
    sample.lock_count = locks;
    sample.unlock_count = unlocks;
    sample.post_count = posts;
    sample.draw_bitmap_count = draws;
    sample.pixel_change_count = pixels;
    sample.surface_valid = 1;
    sample.surface_generation = 1;
    if (detail) snprintf(sample.detail, sizeof(sample.detail), "%s", detail);
    agr_physical_trace_event(&sample);
}

static int run_parser(const char *script, const char *dir, const char *out) {
    char cmd[1200];
    snprintf(cmd, sizeof(cmd), "python3 %s --dir %s --summary %s", script, dir, out);
    return system(cmd);
}

static int trylock_probe(void *user) {
    return pthread_mutex_trylock((pthread_mutex_t *)user) != 0;
}

static const char *classification_of(const char *path) {
    static char buf[8192];
    static char value[64];
    FILE *fp = fopen(path, "r");
    char *found;
    size_t n;
    if (!fp) return "";
    n = fread(buf, 1, sizeof(buf) - 1, fp);
    fclose(fp);
    buf[n] = 0;
    found = strstr(buf, "\"classification\":");
    if (!found) return "";
    found = strchr(found + 16, '"');
    if (!found) return "";
    snprintf(value, sizeof(value), "%s", found + 1);
    found = strchr(value, '"');
    if (found) *found = 0;
    return value;
}

static void test_sequence_and_identity(const char *script) {
    const char *dir = "/tmp/agr-phys-seq";
    agr_physical_trace_config config;
    agr_physical_trace_status status;
    char summary[64];
    mkdir(dir, 0755);
    quiet_watchdog();
    config = config_for(dir);
    expect(agr_physical_trace_begin(&config) == 0, "begin");
    note(AGR_PHYS_PHASE_APK_SHA_OK, 1, 1, 0, 11, 0, 0, 0, 0, 0, 0, NULL);
    note(AGR_PHYS_PHASE_APK_OPEN_OK, 1, 1, 0, 11, 0, 0, 0, 0, 0, 0, NULL);
    agr_physical_trace_finish("RUNTIME_ERROR", &status);
    expect(status.event_count >= 4, "event count");
    expect(status.last_seq >= 103, "seq advanced");
    expect(strcmp(status.last_event, "FINALIZE_END") == 0, "last event");
    agr_physical_trace_shutdown();
    snprintf(summary, sizeof(summary), "%s/summary.json", dir);
    expect(run_parser(script, dir, summary) == 0, "parser seq");
    expect(strstr(classification_of(summary), "EVIDENCE_INCOMPLETE") != NULL ||
           strstr(classification_of(summary), "FAIL_") != NULL, "seq class");
    {
        FILE *fp = fopen(summary, "r");
        char body[8192];
        size_t n = fp ? fread(body, 1, sizeof(body) - 1, fp) : 0;
        if (fp) fclose(fp);
        body[n] = 0;
        expect(strstr(body, "\"identity_valid\": true") != NULL, "identity");
        expect(strstr(body, "\"sequence_monotonic\": true") != NULL, "monotonic");
        expect(strstr(body, status.run_id) != NULL, "run id");
    }
}

static void test_truncated_and_missing_final(const char *script) {
    const char *dir = "/tmp/agr-phys-trunc";
    agr_physical_trace_config config;
    char path[256];
    char summary[256];
    FILE *fp;
    mkdir(dir, 0755);
    quiet_watchdog();
    config = config_for(dir);
    expect(agr_physical_trace_begin(&config) == 0, "trunc begin");
    note(AGR_PHYS_PHASE_APK_OPEN_FAIL, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, "apk_open_failed");
    agr_physical_trace_shutdown();
    snprintf(path, sizeof(path), "%s/agr-physical-trace.ndjson", dir);
    fp = fopen(path, "a");
    expect(fp != NULL, "append trunc");
    if (fp) {
        fputs("{\"seq\":999,\"phase\":\"BROKEN\"", fp);
        fclose(fp);
    }
    snprintf(summary, sizeof(summary), "%s/summary.json", dir);
    expect(run_parser(script, dir, summary) == 0, "parser trunc");
    expect(strcmp(classification_of(summary), "FAIL_BEFORE_APK_OPEN") == 0, "missing final class");
    {
        FILE *out = fopen(summary, "r");
        char body[4096];
        size_t n = out ? fread(body, 1, sizeof(body) - 1, out) : 0;
        if (out) fclose(out);
        body[n] = 0;
        expect(strstr(body, "\"truncated_final_line\": true") != NULL, "truncated flag");
        expect(strstr(body, "\"final_json_missing\": true") != NULL, "final missing");
    }
}

static void test_stale_archive(const char *script) {
    const char *dir = "/tmp/agr-phys-stale";
    char path[256];
    FILE *fp;
    agr_physical_trace_config config;
    agr_physical_trace_status status;
    char archived[512];
    mkdir(dir, 0755);
    snprintf(path, sizeof(path), "%s/agr-physical-run.json", dir);
    fp = fopen(path, "w");
    fputs("{\"run_id\":\"OLDID\",\"commit\":\"old\",\"tree\":\"old\"}\n", fp);
    fclose(fp);
    snprintf(path, sizeof(path), "%s/agr-physical-runtime.json", dir);
    fp = fopen(path, "w");
    fputs("{\"commit\":\"old\",\"termination_reason\":\"CONTENT_POSTED\",\"content_posted\":\"YES\","
          "\"lock_count\":1,\"unlock_count\":1,\"post_count\":1,\"draw_bitmap_count\":1,\"pixel_change_count\":1}\n", fp);
    fclose(fp);
    quiet_watchdog();
    config = config_for(dir);
    expect(agr_physical_trace_begin(&config) == 0, "stale begin");
    agr_physical_trace_copy_status(&status);
    expect(strcmp(status.run_id, "OLDID") != 0, "new run id");
    snprintf(archived, sizeof(archived), "%s/previous/OLDID/agr-physical-runtime.json", dir);
    expect(access(archived, F_OK) == 0, "archived final");
    snprintf(path, sizeof(path), "%s/agr-physical-runtime.json", dir);
    expect(access(path, F_OK) != 0, "current final absent");
    agr_physical_trace_shutdown();
    (void)script;
}

static void test_watchdog_and_probe(void) {
    const char *dir = "/tmp/agr-phys-watch";
    agr_physical_trace_config config;
    agr_physical_trace_status status;
    pthread_mutex_t mu = PTHREAD_MUTEX_INITIALIZER;
    char path[256];
    FILE *fp;
    char body[65536];
    size_t n;
    mkdir(dir, 0755);
    agr_physical_trace_set_watchdog_for_test(20, 40, 80, 120);
    config = config_for(dir);
    expect(agr_physical_trace_begin(&config) == 0, "watch begin");
    usleep(400000);
    agr_physical_trace_copy_status(&status);
    expect(status.heartbeat_count > 0, "heartbeat");
    expect(status.no_progress_level == 8, "no progress level");
    expect(status.watchdog_stalled == 1, "stalled");
    agr_physical_trace_shutdown();
    snprintf(path, sizeof(path), "%s/agr-physical-trace.ndjson", dir);
    fp = fopen(path, "r");
    n = fp ? fread(body, 1, sizeof(body) - 1, fp) : 0;
    if (fp) fclose(fp);
    body[n] = 0;
    expect(strstr(body, "WATCHDOG_NO_PROGRESS_2S") != NULL, "gap 2");
    expect(strstr(body, "WATCHDOG_NO_PROGRESS_5S") != NULL, "gap 5");
    expect(strstr(body, "WATCHDOG_STALL") != NULL, "stall event");

    mkdir(dir, 0755);
    agr_physical_trace_set_watchdog_for_test(20, 100000, 100000, 100000);
    config = config_for(dir);
    expect(agr_physical_trace_begin(&config) == 0, "probe begin");
    pthread_mutex_lock(&mu);
    agr_physical_trace_set_lock_probe(trylock_probe, &mu);
    usleep(120000);
    fp = fopen(path, "r");
    n = fp ? fread(body, 1, sizeof(body) - 1, fp) : 0;
    if (fp) fclose(fp);
    body[n] = 0;
    expect(strstr(body, "SNAPSHOT_UNAVAILABLE") != NULL, "lock probe");
    expect(strstr(body, "snapshot_unavailable_due_to_lock") != NULL, "lock detail");
    pthread_mutex_unlock(&mu);
    agr_physical_trace_shutdown();
}

static int span_has(const char *start, const char *end, const char *needle) {
    size_t n = strlen(needle);
    size_t len = (size_t)(end - start);
    size_t i;
    if (n == 0 || n > len) return 0;
    for (i = 0; i + n <= len; i++) {
        if (memcmp(start + i, needle, n) == 0) return 1;
    }
    return 0;
}

static int line_contains(const char *body, const char *phase, const char *detail) {
    const char *cursor = body;
    char phase_key[96];
    char detail_key[160];
    snprintf(phase_key, sizeof(phase_key), "\"phase\":\"%s\"", phase);
    snprintf(detail_key, sizeof(detail_key), "\"detail\":\"%s\"", detail);
    while ((cursor = strstr(cursor, phase_key)) != NULL) {
        const char *line = cursor;
        const char *end;
        while (line > body && line[-1] != '\n') line--;
        end = strchr(cursor, '\n');
        if (!end) end = cursor + strlen(cursor);
        if (span_has(line, end, detail_key)) return 1;
        cursor += strlen(phase_key);
    }
    return 0;
}

static void test_frame_sync_policy(void) {
    const char *dir = "/tmp/agr-phys-sync";
    agr_physical_trace_config config;
    uint32_t base;
    uint32_t after_bounds;
    uint32_t after_frames;
    uint32_t after_repeat;
    uint32_t after_fail;
    int frame;
    mkdir(dir, 0755);
    quiet_watchdog();
    config = config_for(dir);
    expect(agr_physical_trace_begin(&config) == 0, "sync begin");
    base = agr_physical_trace_sync_count();
    note(AGR_PHYS_PHASE_THREAD_RUN_ENTER, 1, 1, 7, 99, 0, 0, 0, 0, 0, 0, NULL);
    note(AGR_PHYS_PHASE_SURFACE_CREATED, 1, 1, 7, 99, 0, 0, 0, 0, 0, 0, NULL);
    note(AGR_PHYS_PHASE_SURFACE_CHANGED, 1, 1, 7, 99, 0, 0, 0, 0, 0, 0, NULL);
    note(AGR_PHYS_PHASE_PENGUIN_SPRITE_PAINT_WITNESS, 1, 1, 7, 99, 0, 0, 0, 0, 0, 0, NULL);
    after_bounds = agr_physical_trace_sync_count();
    expect(after_bounds == base + 4, "first responsibility boundaries");
    note(AGR_PHYS_PHASE_THREAD_RUN_ENTER, 1, 1, 7, 99, 0, 0, 0, 0, 0, 0, NULL);
    note(AGR_PHYS_PHASE_SURFACE_CREATED, 1, 1, 7, 99, 0, 0, 0, 0, 0, 0, NULL);
    note(AGR_PHYS_PHASE_SURFACE_CHANGED, 1, 1, 7, 99, 0, 0, 0, 0, 0, 0, NULL);
    note(AGR_PHYS_PHASE_PENGUIN_SPRITE_PAINT_WITNESS, 1, 1, 7, 99, 0, 0, 0, 0, 0, 0, NULL);
    expect(agr_physical_trace_sync_count() == after_bounds, "repeat boundaries stay cached");
    for (frame = 0; frame < 4; frame++) {
        note(AGR_PHYS_PHASE_CANVAS_LOCK_ACQUIRED, 1, 1, 7, 99, 1, frame + 1, frame, frame, frame, 0, NULL);
        note(AGR_PHYS_PHASE_DRAW_BITMAP_END, 1, 1, 7, 99, 1, frame + 1, frame, frame, frame + 1, 8, NULL);
        note(AGR_PHYS_PHASE_CANVAS_POST_BEGIN, 1, 1, 7, 99, 1, frame + 1, frame, frame, frame + 1, 8, NULL);
        note(AGR_PHYS_PHASE_CANVAS_POST_END, 1, 1, 7, 99, 0, frame + 1, frame + 1, frame + 1, frame + 1, 8, NULL);
        note(AGR_PHYS_PHASE_CANVAS_LOCK_BEGIN, 1, 1, 7, 99, 0, frame + 1, frame, frame, frame, 0, NULL);
        note(AGR_PHYS_PHASE_DRAW_BITMAP_BEGIN, 1, 1, 7, 99, 1, frame + 1, frame, frame, frame, 0, NULL);
        note(AGR_PHYS_PHASE_PIXEL_MUTATION, 1, 1, 7, 99, 1, frame + 1, frame, frame, frame, 8, NULL);
        note(AGR_PHYS_PHASE_PHYSICAL_FRAME_BEGIN, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, NULL);
        note(AGR_PHYS_PHASE_PHYSICAL_FRAME_END, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, NULL);
    }
    after_frames = agr_physical_trace_sync_count();
    expect(after_frames == after_bounds + 3, "first lock draw post only");
    note(AGR_PHYS_PHASE_CANVAS_LOCK_ACQUIRED, 1, 1, 7, 99, 1, 5, 4, 4, 4, 8, NULL);
    note(AGR_PHYS_PHASE_DRAW_BITMAP_END, 1, 1, 7, 99, 1, 5, 4, 4, 5, 8, NULL);
    note(AGR_PHYS_PHASE_CANVAS_POST_BEGIN, 1, 1, 7, 99, 1, 5, 4, 4, 5, 8, NULL);
    note(AGR_PHYS_PHASE_CANVAS_POST_END, 1, 1, 7, 99, 0, 5, 5, 5, 5, 8, NULL);
    after_repeat = agr_physical_trace_sync_count();
    expect(after_repeat == after_frames, "later frames do not fsync");
    note(AGR_PHYS_PHASE_CANVAS_LOCK_FAILED, 1, 1, 7, 99, 0, 5, 5, 5, 5, 8, "lock_failed");
    note(AGR_PHYS_PHASE_CANVAS_LOCK_FAILED, 1, 1, 7, 99, 0, 5, 5, 5, 5, 8, "lock_failed");
    note(AGR_PHYS_PHASE_RUNTIME_ERROR, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, "runtime");
    note(AGR_PHYS_PHASE_WATCHDOG_NO_PROGRESS_8S, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, "age_ms=8000");
    note(AGR_PHYS_PHASE_WATCHDOG_STALL, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, "WATCHDOG_STALL");
    after_fail = agr_physical_trace_sync_count();
    expect(after_fail == after_repeat + 5, "failures stay durable");
    agr_physical_trace_finish("RUNTIME_ERROR", NULL);
    expect(agr_physical_trace_sync_count() == after_fail + 2, "finalize stays durable");
    agr_physical_trace_shutdown();
}

static void test_stall_reason_agreement(const char *script) {
    const char *dir = "/tmp/agr-phys-reason";
    agr_physical_trace_config config;
    agr_physical_trace_status status;
    char path[256];
    char summary[256];
    char body[65536];
    FILE *fp;
    size_t n;
    mkdir(dir, 0755);
    agr_physical_trace_set_watchdog_for_test(20, 40, 80, 120);
    config = config_for(dir);
    expect(agr_physical_trace_begin(&config) == 0, "reason begin");
    note(AGR_PHYS_PHASE_CANVAS_LOCK_ACQUIRED, 1, 1, 7, 99, 1, 1, 0, 0, 0, 0, NULL);
    usleep(400000);
    agr_physical_trace_copy_status(&status);
    expect(status.watchdog_stalled == 1, "reason stalled");
    expect(agr_physical_trace_finish("OBSERVATION_TIMEOUT", &status) == 0, "reason finish");
    expect(strcmp(status.termination_reason, "WATCHDOG_STALL") == 0, "status reason");
    snprintf(path, sizeof(path), "%s/agr-physical-run.json", dir);
    fp = fopen(path, "r");
    n = fp ? fread(body, 1, sizeof(body) - 1, fp) : 0;
    if (fp) fclose(fp);
    body[n] = 0;
    expect(strstr(body, "\"state\": \"WATCHDOG_STALL\"") != NULL, "run state");
    snprintf(path, sizeof(path), "%s/agr-physical-trace.ndjson", dir);
    fp = fopen(path, "r");
    n = fp ? fread(body, 1, sizeof(body) - 1, fp) : 0;
    if (fp) fclose(fp);
    body[n] = 0;
    expect(line_contains(body, "FINALIZE_BEGIN", "WATCHDOG_STALL"), "finalize begin reason");
    expect(line_contains(body, "FINALIZE_END", "WATCHDOG_STALL"), "finalize end reason");
    expect(strstr(body, "OBSERVATION_TIMEOUT") == NULL, "caller reason absent");
    snprintf(path, sizeof(path), "%s/agr-physical-runtime.json", dir);
    fp = fopen(path, "w");
    expect(fp != NULL, "runtime json");
    if (fp) {
        fprintf(fp,
                "{\"termination_reason\":\"%s\",\"final_state\":\"%s\",\"content_posted\":\"NO\","
                "\"lock_count\":1,\"unlock_count\":0,\"post_count\":0,\"draw_bitmap_count\":0,"
                "\"pixel_change_count\":0}\n",
                status.termination_reason, status.termination_reason);
        fclose(fp);
    }
    agr_physical_trace_shutdown();
    snprintf(summary, sizeof(summary), "%s/summary.json", dir);
    expect(run_parser(script, dir, summary) == 0, "reason parser");
    fp = fopen(summary, "r");
    n = fp ? fread(body, 1, sizeof(body) - 1, fp) : 0;
    if (fp) fclose(fp);
    body[n] = 0;
    expect(strstr(body, "\"termination_reason\": \"WATCHDOG_STALL\"") != NULL, "summary reason");
    expect(strstr(body, "\"run_state\": \"WATCHDOG_STALL\"") != NULL, "summary run");
    expect(strstr(body, "\"finalize_reason\": \"WATCHDOG_STALL\"") != NULL, "summary finalize");
    expect(strstr(body, "\"termination_consistent\": true") != NULL, "summary consistent");
    quiet_watchdog();
}

static void test_root_exec_attribution(void) {
    const char *dir = "/tmp/agr-phys-root";
    agr_physical_trace_config config;
    agr_physical_trace_status status;
    mkdir(dir, 0755);
    quiet_watchdog();
    config = config_for(dir);
    expect(agr_physical_trace_begin(&config) == 0, "root begin");
    note(AGR_PHYS_PHASE_THREAD_START, 1, 1, 1, 77, 0, 0, 0, 0, 0, 0, NULL);
    note(AGR_PHYS_PHASE_EXEC_PUBLISHED, 0, 1, 1, 77, 0, 0, 0, 0, 0, 0, "");
    agr_physical_trace_copy_status(&status);
    expect(status.has_root_exec == 0, "worker publish is not root");
    expect(status.has_game_exec == 1 && status.game_exec == 1, "worker is the game exec");
    note(AGR_PHYS_PHASE_ACTIVITY_START_OK, 1, 1, 0, 11, 0, 0, 0, 0, 0, 0, NULL);
    note(AGR_PHYS_PHASE_EXEC_PUBLISHED, 0, 1, 0, 11, 0, 0, 0, 0, 0, 0, "root");
    agr_physical_trace_copy_status(&status);
    expect(status.has_root_exec == 1 && status.root_exec == 0, "activity start owns root");
    expect(status.game_exec == 1, "game exec stays the worker");
    agr_physical_trace_shutdown();
}

static void test_posted_without_draw(const char *script) {
    const char *dir = "/tmp/agr-phys-nodraw";
    agr_physical_trace_config config;
    char summary[256];
    FILE *fp;
    mkdir(dir, 0755);
    quiet_watchdog();
    config = config_for(dir);
    expect(agr_physical_trace_begin(&config) == 0, "nodraw begin");
    note(AGR_PHYS_PHASE_ACTIVITY_START_OK, 1, 1, 0, 3, 0, 0, 0, 0, 0, 0, NULL);
    note(AGR_PHYS_PHASE_CANVAS_LOCK_ACQUIRED, 1, 1, 7, 99, 1, 119, 119, 119, 0, 0, NULL);
    note(AGR_PHYS_PHASE_CANVAS_POST_END, 1, 1, 7, 99, 0, 119, 119, 119, 0, 0, NULL);
    agr_physical_trace_finish("CONTENT_POSTED", NULL);
    agr_physical_trace_shutdown();
    fp = fopen("/tmp/agr-phys-nodraw/agr-physical-runtime.json", "w");
    expect(fp != NULL, "nodraw runtime");
    if (fp) {
        fputs("{\"termination_reason\":\"CONTENT_POSTED\",\"content_posted\":\"YES\","
              "\"lock_count\":119,\"unlock_count\":119,\"post_count\":119,"
              "\"draw_bitmap_count\":0,\"pixel_change_count\":0}\n", fp);
        fclose(fp);
    }
    snprintf(summary, sizeof(summary), "%s/summary.json", dir);
    expect(run_parser(script, dir, summary) == 0, "nodraw parser");
    expect(strcmp(classification_of(summary), "CONTENT_POSTED_WITHOUT_DRAW") == 0,
           "posted without draw");
}

static void test_canvas_and_pass(const char *script) {
    const char *stall_dir = "/tmp/agr-phys-stall";
    const char *pass_dir = "/tmp/agr-phys-pass";
    agr_physical_trace_config config;
    char summary[256];
    FILE *fp;
    mkdir(stall_dir, 0755);
    quiet_watchdog();
    config = config_for(stall_dir);
    expect(agr_physical_trace_begin(&config) == 0, "stall begin");
    note(AGR_PHYS_PHASE_ACTIVITY_START_OK, 1, 1, 0, 3, 0, 0, 0, 0, 0, 0, NULL);
    note(AGR_PHYS_PHASE_THREAD_RUN_ENTER, 1, 1, 7, 99, 0, 0, 0, 0, 0, 0, NULL);
    note(AGR_PHYS_PHASE_CANVAS_LOCK_ACQUIRED, 1, 1, 7, 99, 1, 1, 0, 0, 0, 0, NULL);
    note(AGR_PHYS_PHASE_DRAW_BITMAP_END, 1, 1, 7, 99, 1, 1, 0, 0, 1, 4, NULL);
    note(AGR_PHYS_PHASE_WATCHDOG_STALL, 1, 1, 7, 99, 1, 1, 0, 0, 1, 4, "WATCHDOG_STALL");
    agr_physical_trace_shutdown();
    snprintf(summary, sizeof(summary), "%s/summary.json", stall_dir);
    expect(run_parser(script, stall_dir, summary) == 0, "stall parser");
    expect(strcmp(classification_of(summary), "STALL_CANVAS_LOCKED") == 0, "canvas class");

    mkdir(pass_dir, 0755);
    quiet_watchdog();
    config = config_for(pass_dir);
    expect(agr_physical_trace_begin(&config) == 0, "pass begin");
    note(AGR_PHYS_PHASE_ACTIVITY_START_OK, 1, 1, 0, 3, 0, 0, 0, 0, 0, 0, NULL);
    note(AGR_PHYS_PHASE_SURFACE_CREATED, 1, 1, 0, 3, 0, 0, 0, 0, 0, 0, NULL);
    note(AGR_PHYS_PHASE_SURFACE_CHANGED, 1, 1, 0, 3, 0, 0, 0, 0, 0, 0, NULL);
    note(AGR_PHYS_PHASE_THREAD_RUN_ENTER, 1, 1, 7, 99, 0, 0, 0, 0, 0, 0, NULL);
    note(AGR_PHYS_PHASE_CANVAS_LOCK_ACQUIRED, 1, 1, 7, 99, 1, 1, 0, 0, 0, 0, NULL);
    note(AGR_PHYS_PHASE_DRAW_BITMAP_END, 1, 1, 7, 99, 1, 1, 0, 0, 1, 8, NULL);
    note(AGR_PHYS_PHASE_CANVAS_POST_END, 1, 1, 7, 99, 0, 1, 1, 1, 1, 8, NULL);
    agr_physical_trace_finish("CONTENT_POSTED", NULL);
    agr_physical_trace_shutdown();
    fp = fopen("/tmp/agr-phys-pass/agr-physical-runtime.json", "w");
    fputs("{\"termination_reason\":\"CONTENT_POSTED\",\"content_posted\":\"YES\","
          "\"lock_count\":1,\"unlock_count\":1,\"post_count\":1,\"draw_bitmap_count\":1,"
          "\"pixel_change_count\":8}\n", fp);
    fclose(fp);
    snprintf(summary, sizeof(summary), "%s/summary.json", pass_dir);
    expect(run_parser(script, pass_dir, summary) == 0, "pass parser");
    expect(strcmp(classification_of(summary), "PHYSICAL_PASS") == 0, "pass class");
}

static void test_crash(const char *script) {
    const char *dir = "/tmp/agr-phys-crash";
    pid_t pid;
    int status = 0;
    char summary[256];
    mkdir(dir, 0755);
    pid = fork();
    expect(pid >= 0, "fork");
    if (pid == 0) {
        agr_physical_trace_config config;
        quiet_watchdog();
        config = config_for(dir);
        if (agr_physical_trace_begin(&config) != 0) _exit(2);
        note(AGR_PHYS_PHASE_ACTIVITY_START_OK, 1, 1, 4, 8, 0, 0, 0, 0, 0, 0, NULL);
        abort();
    }
    if (pid > 0) {
        waitpid(pid, &status, 0);
        expect(WIFSIGNALED(status) && WTERMSIG(status) == SIGABRT, "child sigabrt");
        snprintf(summary, sizeof(summary), "%s/summary.json", dir);
        expect(run_parser(script, dir, summary) == 0, "crash parser");
        expect(strcmp(classification_of(summary), "NATIVE_CRASH") == 0, "crash class");
        {
            FILE *fp = fopen(summary, "r");
            char body[8192];
            size_t n = fp ? fread(body, 1, sizeof(body) - 1, fp) : 0;
            if (fp) fclose(fp);
            body[n] = 0;
            expect(strstr(body, "\"signal\": 6") != NULL, "signal");
            expect(strstr(body, "ACTIVITY_START_OK") != NULL, "pre crash event");
        }
    }
}

static void test_current_root_and_environment(const char *script) {
    const char *dir = "/tmp/agr-phys-root";
    const char *abrupt = "/tmp/agr-phys-abrupt";
    const char *mixed = "/tmp/agr-phys-mixed";
    agr_physical_trace_config config;
    agr_physical_trace_status first;
    agr_physical_trace_status second;
    char summary[256];
    char body[16384];
    FILE *fp;
    size_t n;
    const char *env =
        "{\"schema\":\"agr.physical-environment.v1\",\"target_type\":\"physical_device\","
        "\"os\":{\"system_version\":\"18.6\"},\"hardware\":{\"hw_machine\":\"iPhone14,6\"},"
        "\"display\":{\"logical_width\":390,\"native_width\":1170,\"runtime_host_width\":1170,"
        "\"runtime_host_height\":2532,\"maximum_fps\":60}}";
    mkdir(dir, 0755);
    quiet_watchdog();
    config = config_for(dir);
    expect(agr_physical_trace_begin(&config) == 0, "root first begin");
    agr_physical_trace_copy_status(&first);
    agr_physical_trace_shutdown();
    expect(agr_physical_trace_begin(&config) == 0, "root second begin");
    agr_physical_trace_copy_status(&second);
    expect(strcmp(first.run_id, second.run_id) != 0, "consecutive run ids differ");
    expect(strcmp(first.process_launch_id, second.process_launch_id) != 0, "consecutive launch ids differ");
    expect(agr_physical_trace_set_environment_json(env) == 0, "environment stored");
    agr_physical_trace_add_binary("executable", "00112233-4455-6677-8899-AABBCCDDEEFF",
                                  "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef");
    agr_physical_trace_add_binary("libEGL", "11112233-4455-6677-8899-AABBCCDDEEFF",
                                  "1123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef");
    agr_physical_trace_add_binary("libGLESv2", "22112233-4455-6677-8899-AABBCCDDEEFF",
                                  "2123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef");
    agr_physical_trace_set_observation(10, 20, 15, 4, "OBSERVATION_DEADLINE");
    agr_physical_trace_set_lifecycle("ACTIVE", 1, 1);
    agr_physical_trace_shutdown();
    fp = fopen("/tmp/agr-phys-root/agr-physical-run.json", "r");
    expect(fp != NULL, "run file");
    n = fp ? fread(body, 1, sizeof(body) - 1, fp) : 0;
    if (fp) fclose(fp);
    body[n] = 0;
    expect(strstr(body, second.run_id) != NULL, "current run id");
    expect(strstr(body, "\"process_launch_id\"") != NULL, "launch id field");
    expect(strstr(body, "iPhone14,6") != NULL, "hw.machine");
    expect(strstr(body, "\"system_version\":\"18.6\"") != NULL, "system version");
    expect(strstr(body, "libGLESv2") != NULL, "framework fingerprint");
    expect(strstr(body, "\"stop_reason\": \"OBSERVATION_DEADLINE\"") != NULL, "stop reason");
    expect(strstr(body, "\"file_size_is_not_identity\": true") != NULL, "identity rule");
    expect(access("/tmp/agr-phys-root/agr-physical-runtime.json", F_OK) != 0, "runtime absent until finalize");

    mkdir(abrupt, 0755);
    fp = fopen("/tmp/agr-phys-abrupt/agr-physical-run.json", "w");
    fputs("{\"run_id\":\"KEEPME\",\"state\":\"RUNNING\",\"commit\":\"abc123\",\"tree\":\"def456\"}\n", fp);
    fclose(fp);
    config = config_for(abrupt);
    expect(agr_physical_trace_begin(&config) == 0, "abrupt begin");
    agr_physical_trace_shutdown();
    fp = fopen("/tmp/agr-phys-abrupt/previous/KEEPME/agr-physical-run.json", "r");
    expect(fp != NULL, "abrupt archive");
    n = fp ? fread(body, 1, sizeof(body) - 1, fp) : 0;
    if (fp) fclose(fp);
    body[n] = 0;
    expect(strstr(body, "ABRUPT_TERMINATION") != NULL, "abrupt reclass");

    mkdir(mixed, 0755);
    fp = fopen("/tmp/agr-phys-mixed/agr-physical-run.json", "w");
    fputs("{\"schema\":\"agr.physical-run.v2\",\"run_id\":\"RUN-A\",\"process_launch_id\":\"L1\","
          "\"commit\":\"abc123\",\"tree\":\"def456\",\"state\":\"FINALIZED\"}\n", fp);
    fclose(fp);
    fp = fopen("/tmp/agr-phys-mixed/agr-physical-trace.ndjson", "w");
    fputs("{\"schema\":\"agr.physical-trace.v2\",\"run_id\":\"RUN-B\",\"process_launch_id\":\"L1\","
          "\"seq\":100,\"commit\":\"abc123\",\"tree\":\"def456\",\"event\":\"TRACE_READY\",\"phase\":\"TRACE_READY\"}\n",
          fp);
    fclose(fp);
    snprintf(summary, sizeof(summary), "%s/summary.json", mixed);
    expect(run_parser(script, mixed, summary) == 0, "mixed parser");
    expect(strcmp(classification_of(summary), "STALE_OR_MIXED_EVIDENCE") == 0, "stale class");
}

int main(int argc, char **argv) {
    const char *script = argc > 1 ? argv[1] : "ci/physical-runtime-evidence.py";
    test_sequence_and_identity(script);
    test_truncated_and_missing_final(script);
    test_stale_archive(script);
    test_watchdog_and_probe();
    test_frame_sync_policy();
    test_stall_reason_agreement(script);
    test_root_exec_attribution();
    test_posted_without_draw(script);
    test_canvas_and_pass(script);
    test_crash(script);
    test_current_root_and_environment(script);
    if (g_failures) {
        fprintf(stderr, "physical trace host failures %d\n", g_failures);
        return 1;
    }
    printf("physical-trace-host PASS\n");
    return 0;
}
