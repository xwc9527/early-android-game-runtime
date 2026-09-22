#include "agr_forensic.h"

#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#define TRACE_NAME "agr-physical-trace.ndjson"
#define RUN_NAME "agr-physical-run.json"
#define FINAL_NAME "agr-physical-runtime.json"
#define CRASH_NAME "agr-physical-crash.bin"
#define LINE_CAP 1200
#define DISK_CAP (2u * 1024u * 1024u)
#define SEQ_ORIGIN 100ull

struct crash_image {
    char magic[8];
    uint32_t version;
    int32_t signal_number;
    uint32_t last_phase;
    uint32_t last_exec;
    uint32_t has_exec;
    uint32_t canvas_locked;
    uint32_t lock_owner_exec;
    uint32_t lock_count;
    uint32_t unlock_count;
    uint32_t post_count;
    uint32_t draw_bitmap_count;
    uint32_t pixel_change_count;
    uint32_t surface_generation;
    uint32_t surface_valid;
    uint32_t thread_state;
    uint64_t last_seq;
    uint64_t host_thread;
    uint64_t surface_identity;
} __attribute__((packed));

static pthread_mutex_t g_mu = PTHREAD_MUTEX_INITIALIZER;
static pthread_t g_watchdog;
static int g_watchdog_started = 0;
static int g_stop = 0;
static int g_active = 0;
static int g_trace_fd = -1;
static int g_crash_fd = -1;
static uint64_t g_seq = SEQ_ORIGIN - 1ull;
static uint64_t g_runtime_seq = 0;
static uint64_t g_last_progress_ns = 0;
static uint64_t g_max_gap_ns = 0;
static uint32_t g_event_count = 0;
static uint32_t g_bytes = 0;
static uint32_t g_last_phase = 0;
static uint32_t g_heartbeat_count = 0;
static uint32_t g_no_progress_level = 0;
static uint32_t g_reported_level = 0;
static int g_stalled = 0;
static uint8_t g_phase_synced[96];
static uint32_t g_sync_count = 0;
static int g_finished = 0;
static char g_dir[512];
static char g_run_id[40];
static char g_branch[128];
static char g_commit[80];
static char g_tree[80];
static char g_platform[32];
static char g_arch[32];
static char g_apk_sha[80];
static char g_last_event[64];
static char g_reason[64];
static uint32_t g_root_exec = 0;
static int g_has_root = 0;
static uint32_t g_game_exec = 0;
static int g_has_game = 0;
static uint32_t g_game_state = 0;
static uint64_t g_game_host = 0;
static uint32_t g_poll_ms = AGR_PHYSICAL_WATCHDOG_POLL_MS;
static uint32_t g_gap2_ms = AGR_PHYSICAL_WATCHDOG_GAP_2S_MS;
static uint32_t g_gap5_ms = AGR_PHYSICAL_WATCHDOG_GAP_5S_MS;
static uint32_t g_gap8_ms = AGR_PHYSICAL_WATCHDOG_GAP_8S_MS;
static int (*g_probe)(void *) = NULL;
static void *g_probe_user = NULL;
static struct crash_image g_crash;
static volatile uint32_t g_crash_seq = 0;
static struct sigaction g_old_abrt, g_old_segv, g_old_bus, g_old_ill, g_old_fpe;
static int g_signals_installed = 0;

static uint64_t mono_ns(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint64_t)ts.tv_sec * 1000000000ull + (uint64_t)ts.tv_nsec;
}

static void copy_text(char *dst, size_t cap, const char *src) {
    size_t i = 0;
    if (!src) src = "";
    for (; src[i] && i + 1 < cap; i++) {
        unsigned char c = (unsigned char)src[i];
        if (c < 0x20 || c == '"' || c == '\\') c = '_';
        dst[i] = (char)c;
    }
    dst[i] = 0;
}

const char *agr_physical_phase_name(uint32_t phase) {
    switch (phase) {
    case AGR_PHYS_PHASE_APP_LAUNCH_BEGIN: return "APP_LAUNCH_BEGIN";
    case AGR_PHYS_PHASE_TRACE_READY: return "TRACE_READY";
    case AGR_PHYS_PHASE_APK_LOCATE_BEGIN: return "APK_LOCATE_BEGIN";
    case AGR_PHYS_PHASE_APK_LOCATE_OK: return "APK_LOCATE_OK";
    case AGR_PHYS_PHASE_APK_LOCATE_FAIL: return "APK_LOCATE_FAIL";
    case AGR_PHYS_PHASE_APK_SHA_BEGIN: return "APK_SHA_BEGIN";
    case AGR_PHYS_PHASE_APK_SHA_OK: return "APK_SHA_OK";
    case AGR_PHYS_PHASE_APK_SHA_FAIL: return "APK_SHA_FAIL";
    case AGR_PHYS_PHASE_APK_OPEN_BEGIN: return "APK_OPEN_BEGIN";
    case AGR_PHYS_PHASE_APK_OPEN_OK: return "APK_OPEN_OK";
    case AGR_PHYS_PHASE_APK_OPEN_FAIL: return "APK_OPEN_FAIL";
    case AGR_PHYS_PHASE_GAME_CREATE_BEGIN: return "GAME_CREATE_BEGIN";
    case AGR_PHYS_PHASE_GAME_CREATE_OK: return "GAME_CREATE_OK";
    case AGR_PHYS_PHASE_GAME_CREATE_FAIL: return "GAME_CREATE_FAIL";
    case AGR_PHYS_PHASE_DIAGNOSTICS_ENABLED: return "DIAGNOSTICS_ENABLED";
    case AGR_PHYS_PHASE_HOST_DISPLAY_SET_BEGIN: return "HOST_DISPLAY_SET_BEGIN";
    case AGR_PHYS_PHASE_HOST_DISPLAY_SET_OK: return "HOST_DISPLAY_SET_OK";
    case AGR_PHYS_PHASE_HOST_DISPLAY_SET_FAIL: return "HOST_DISPLAY_SET_FAIL";
    case AGR_PHYS_PHASE_ACTIVITY_START_BEGIN: return "ACTIVITY_START_BEGIN";
    case AGR_PHYS_PHASE_ACTIVITY_START_OK: return "ACTIVITY_START_OK";
    case AGR_PHYS_PHASE_ACTIVITY_START_FAIL: return "ACTIVITY_START_FAIL";
    case AGR_PHYS_PHASE_CADISPLAYLINK_CREATED: return "CADISPLAYLINK_CREATED";
    case AGR_PHYS_PHASE_CADISPLAYLINK_STARTED: return "CADISPLAYLINK_STARTED";
    case AGR_PHYS_PHASE_PHYSICAL_FRAME_BEGIN: return "PHYSICAL_FRAME_BEGIN";
    case AGR_PHYS_PHASE_PHYSICAL_FRAME_END: return "PHYSICAL_FRAME_END";
    case AGR_PHYS_PHASE_ACTIVITY_STAGE: return "ACTIVITY_STAGE";
    case AGR_PHYS_PHASE_VIEWROOT_ATTACH: return "VIEWROOT_ATTACH";
    case AGR_PHYS_PHASE_TRAVERSAL_SCHEDULED: return "TRAVERSAL_SCHEDULED";
    case AGR_PHYS_PHASE_TRAVERSAL_BEGIN: return "TRAVERSAL_BEGIN";
    case AGR_PHYS_PHASE_TRAVERSAL_END: return "TRAVERSAL_END";
    case AGR_PHYS_PHASE_SURFACE_CREATED: return "SURFACE_CREATED";
    case AGR_PHYS_PHASE_SURFACE_CHANGED: return "SURFACE_CHANGED";
    case AGR_PHYS_PHASE_THREAD_START: return "THREAD_START";
    case AGR_PHYS_PHASE_THREAD_RUN_ENTER: return "THREAD_RUN_ENTER";
    case AGR_PHYS_PHASE_THREAD_RUN_EXIT: return "THREAD_RUN_EXIT";
    case AGR_PHYS_PHASE_EXEC_PUBLISHED: return "EXEC_PUBLISHED";
    case AGR_PHYS_PHASE_VECTOR_SIZE: return "VECTOR_SIZE";
    case AGR_PHYS_PHASE_VECTOR_ELEMENT: return "VECTOR_ELEMENT";
    case AGR_PHYS_PHASE_CANVAS_LOCK_BEGIN: return "CANVAS_LOCK_BEGIN";
    case AGR_PHYS_PHASE_CANVAS_LOCK_ACQUIRED: return "CANVAS_LOCK_ACQUIRED";
    case AGR_PHYS_PHASE_CANVAS_LOCK_FAILED: return "CANVAS_LOCK_FAILED";
    case AGR_PHYS_PHASE_DRAW_BITMAP_BEGIN: return "DRAW_BITMAP_BEGIN";
    case AGR_PHYS_PHASE_DRAW_BITMAP_END: return "DRAW_BITMAP_END";
    case AGR_PHYS_PHASE_PIXEL_MUTATION: return "PIXEL_MUTATION";
    case AGR_PHYS_PHASE_CANVAS_POST_BEGIN: return "CANVAS_POST_BEGIN";
    case AGR_PHYS_PHASE_CANVAS_POST_END: return "CANVAS_POST_END";
    case AGR_PHYS_PHASE_PENGUIN_SPRITE_PAINT_WITNESS: return "PENGUIN_SPRITE_PAINT_WITNESS";
    case AGR_PHYS_PHASE_RUNTIME_ERROR: return "RUNTIME_ERROR";
    case AGR_PHYS_PHASE_WATCHDOG_HEARTBEAT: return "WATCHDOG_HEARTBEAT";
    case AGR_PHYS_PHASE_WATCHDOG_NO_PROGRESS_2S: return "WATCHDOG_NO_PROGRESS_2S";
    case AGR_PHYS_PHASE_WATCHDOG_NO_PROGRESS_5S: return "WATCHDOG_NO_PROGRESS_5S";
    case AGR_PHYS_PHASE_WATCHDOG_NO_PROGRESS_8S: return "WATCHDOG_NO_PROGRESS_8S";
    case AGR_PHYS_PHASE_WATCHDOG_STALL: return "WATCHDOG_STALL";
    case AGR_PHYS_PHASE_SNAPSHOT_UNAVAILABLE: return "SNAPSHOT_UNAVAILABLE";
    case AGR_PHYS_PHASE_FINALIZE_BEGIN: return "FINALIZE_BEGIN";
    case AGR_PHYS_PHASE_FINALIZE_END: return "FINALIZE_END";
    case AGR_PHYS_PHASE_SURFACE_CALLBACK_BEGIN: return "SURFACE_CALLBACK_BEGIN";
    case AGR_PHYS_PHASE_SURFACE_CALLBACK_OK: return "SURFACE_CALLBACK_OK";
    case AGR_PHYS_PHASE_SURFACE_CALLBACK_THROW: return "SURFACE_CALLBACK_THROW";
    case AGR_PHYS_PHASE_SURFACE_CALLBACK_EXEC_ERROR: return "SURFACE_CALLBACK_EXEC_ERROR";
    case AGR_PHYS_PHASE_BITMAP_SCALE_BEGIN: return "BITMAP_SCALE_BEGIN";
    case AGR_PHYS_PHASE_BITMAP_SCALE_END: return "BITMAP_SCALE_END";
    case AGR_PHYS_PHASE_BITMAP_SCALE_FAIL: return "BITMAP_SCALE_FAIL";
    case AGR_PHYS_PHASE_GUEST_METHOD_ENTER: return "GUEST_METHOD_ENTER";
    case AGR_PHYS_PHASE_GUEST_METHOD_EXIT: return "GUEST_METHOD_EXIT";
    default: return "NONE";
    }
}

static int phase_is_watchdog(uint32_t phase) {
    return phase == AGR_PHYS_PHASE_WATCHDOG_HEARTBEAT ||
           phase == AGR_PHYS_PHASE_WATCHDOG_NO_PROGRESS_2S ||
           phase == AGR_PHYS_PHASE_WATCHDOG_NO_PROGRESS_5S ||
           phase == AGR_PHYS_PHASE_WATCHDOG_NO_PROGRESS_8S ||
           phase == AGR_PHYS_PHASE_WATCHDOG_STALL ||
           phase == AGR_PHYS_PHASE_SNAPSHOT_UNAVAILABLE;
}

static void path_join(char *out, size_t cap, const char *name) {
    snprintf(out, cap, "%s/%s", g_dir, name);
}

static void write_run_file(const char *state) {
    char path[640];
    char body[1400];
    int fd;
    int n;
    path_join(path, sizeof(path), RUN_NAME);
    n = snprintf(body, sizeof(body),
                 "{\n"
                 "  \"schema\": \"%s\",\n"
                 "  \"run_id\": \"%s\",\n"
                 "  \"branch\": \"%s\",\n"
                 "  \"commit\": \"%s\",\n"
                 "  \"tree\": \"%s\",\n"
                 "  \"device_platform\": \"%s\",\n"
                 "  \"architecture\": \"%s\",\n"
                 "  \"apk_sha256_expected\": \"%s\",\n"
                 "  \"state\": \"%s\",\n"
                 "  \"trace_file\": \"%s\",\n"
                 "  \"final_report_file\": \"%s\",\n"
                 "  \"crash_file\": \"%s\"\n"
                 "}\n",
                 AGR_PHYSICAL_RUN_SCHEMA, g_run_id, g_branch, g_commit, g_tree,
                 g_platform, g_arch, g_apk_sha, state ? state : "RUNNING",
                 TRACE_NAME, FINAL_NAME, CRASH_NAME);
    if (n < 0 || (size_t)n >= sizeof(body)) return;
    fd = open(path, O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if (fd < 0) return;
    if (write(fd, body, (size_t)n) == n) fsync(fd);
    close(fd);
}

static void update_crash_image(uint64_t seq, const agr_forensic_sample *sample) {
    uint32_t odd = __atomic_add_fetch(&g_crash_seq, 1, __ATOMIC_ACQ_REL);
    (void)odd;
    g_crash.last_seq = seq;
    g_crash.last_phase = sample->phase;
    g_crash.last_exec = sample->has_exec ? sample->exec_id : 0;
    g_crash.has_exec = sample->has_exec ? 1u : 0u;
    g_crash.canvas_locked = sample->canvas_locked ? 1u : 0u;
    g_crash.lock_owner_exec = sample->lock_owner_exec;
    g_crash.lock_count = sample->lock_count;
    g_crash.unlock_count = sample->unlock_count;
    g_crash.post_count = sample->post_count;
    g_crash.draw_bitmap_count = sample->draw_bitmap_count;
    g_crash.pixel_change_count = sample->pixel_change_count;
    g_crash.surface_generation = sample->surface_generation;
    g_crash.surface_valid = sample->surface_valid ? 1u : 0u;
    g_crash.thread_state = sample->thread_state;
    g_crash.host_thread = sample->host_thread;
    g_crash.surface_identity = sample->surface_identity;
    __atomic_add_fetch(&g_crash_seq, 1, __ATOMIC_RELEASE);
}

static void remember_exec(const agr_forensic_sample *sample) {
    if (!sample->has_exec) return;
    if (sample->phase == AGR_PHYS_PHASE_THREAD_START ||
        sample->phase == AGR_PHYS_PHASE_THREAD_RUN_ENTER ||
        sample->phase == AGR_PHYS_PHASE_THREAD_RUN_EXIT ||
        sample->phase == AGR_PHYS_PHASE_CANVAS_LOCK_ACQUIRED) {
        g_game_exec = sample->exec_id;
        g_has_game = 1;
        g_game_state = sample->thread_state;
        g_game_host = sample->host_thread;
    }
    /* Activity start owns the root context. A worker Thread.start publishes
       EXEC_PUBLISHED before main notes the root, so the first publish must
       not win. Only the explicit root detail, or ACTIVITY_START_OK, sets it. */
    if (sample->phase == AGR_PHYS_PHASE_ACTIVITY_START_OK ||
        (sample->phase == AGR_PHYS_PHASE_EXEC_PUBLISHED &&
         strcmp(sample->detail, "root") == 0)) {
        g_root_exec = sample->exec_id;
        g_has_root = 1;
    }
}

static int phase_always_sync(uint32_t phase) {
    switch (phase) {
    case AGR_PHYS_PHASE_APK_LOCATE_FAIL:
    case AGR_PHYS_PHASE_APK_SHA_FAIL:
    case AGR_PHYS_PHASE_APK_OPEN_FAIL:
    case AGR_PHYS_PHASE_GAME_CREATE_FAIL:
    case AGR_PHYS_PHASE_HOST_DISPLAY_SET_FAIL:
    case AGR_PHYS_PHASE_ACTIVITY_START_FAIL:
    case AGR_PHYS_PHASE_CANVAS_LOCK_FAILED:
    case AGR_PHYS_PHASE_SURFACE_CALLBACK_THROW:
    case AGR_PHYS_PHASE_SURFACE_CALLBACK_EXEC_ERROR:
    case AGR_PHYS_PHASE_BITMAP_SCALE_FAIL:
    case AGR_PHYS_PHASE_RUNTIME_ERROR:
    case AGR_PHYS_PHASE_WATCHDOG_NO_PROGRESS_8S:
    case AGR_PHYS_PHASE_WATCHDOG_STALL:
    case AGR_PHYS_PHASE_FINALIZE_BEGIN:
    case AGR_PHYS_PHASE_FINALIZE_END:
        return 1;
    default:
        return 0;
    }
}

static int phase_never_sync(uint32_t phase) {
    switch (phase) {
    case AGR_PHYS_PHASE_DRAW_BITMAP_BEGIN:
    case AGR_PHYS_PHASE_PIXEL_MUTATION:
    case AGR_PHYS_PHASE_WATCHDOG_HEARTBEAT:
    case AGR_PHYS_PHASE_WATCHDOG_NO_PROGRESS_2S:
    case AGR_PHYS_PHASE_WATCHDOG_NO_PROGRESS_5S:
    case AGR_PHYS_PHASE_CANVAS_LOCK_BEGIN:
    case AGR_PHYS_PHASE_CANVAS_POST_BEGIN:
    case AGR_PHYS_PHASE_PHYSICAL_FRAME_BEGIN:
    case AGR_PHYS_PHASE_PHYSICAL_FRAME_END:
    case AGR_PHYS_PHASE_SNAPSHOT_UNAVAILABLE:
    case AGR_PHYS_PHASE_SURFACE_CALLBACK_BEGIN:
    case AGR_PHYS_PHASE_SURFACE_CALLBACK_OK:
    case AGR_PHYS_PHASE_BITMAP_SCALE_BEGIN:
    case AGR_PHYS_PHASE_BITMAP_SCALE_END:
    case AGR_PHYS_PHASE_GUEST_METHOD_ENTER:
    case AGR_PHYS_PHASE_GUEST_METHOD_EXIT:
        return 1;
    default:
        return 0;
    }
}

/* First arrival of a responsibility boundary. Later repeats only append. */
static int phase_first_sync(uint32_t phase) {
    switch (phase) {
    case AGR_PHYS_PHASE_THREAD_RUN_ENTER:
    case AGR_PHYS_PHASE_SURFACE_CREATED:
    case AGR_PHYS_PHASE_SURFACE_CHANGED:
    case AGR_PHYS_PHASE_CANVAS_LOCK_ACQUIRED:
    case AGR_PHYS_PHASE_DRAW_BITMAP_END:
    case AGR_PHYS_PHASE_CANVAS_POST_END:
    case AGR_PHYS_PHASE_PENGUIN_SPRITE_PAINT_WITNESS:
        return 1;
    default:
        return 0;
    }
}

static int want_fsync(const agr_forensic_sample *sample) {
    uint32_t phase = sample->phase;
    if (phase >= sizeof(g_phase_synced)) return 0;
    if (phase_always_sync(phase)) return 1;
    if (phase_never_sync(phase)) return 0;
    if (phase_first_sync(phase) || sample->critical) {
        if (g_phase_synced[phase]) return 0;
        g_phase_synced[phase] = 1;
        return 1;
    }
    return 0;
}

/* Caller holds g_mu. write() lands in the kernel cache. fsync is reserved
   for critical checkpoints so per-draw recording does not stall the guest. */
static void commit_line_fixed(const agr_forensic_sample *sample) {
    char line[LINE_CAP];
    int n;
    uint64_t seq;
    uint64_t now;
    const char *name;
    int sync;
    if (!g_active || g_trace_fd < 0 || g_bytes >= DISK_CAP) return;
    seq = ++g_seq;
    now = mono_ns();
    name = agr_physical_phase_name(sample->phase);
    copy_text(g_last_event, sizeof(g_last_event), name);
    g_last_phase = sample->phase;
    sync = want_fsync(sample);
    if (sample->has_exec) {
        n = snprintf(line, sizeof(line),
                     "{\"schema\":\"%s\",\"run_id\":\"%s\",\"seq\":%llu,\"monotonic_ns\":%llu,"
                     "\"event\":\"%s\",\"phase\":\"%s\",\"commit\":\"%s\",\"tree\":\"%s\","
                     "\"exec_id\":%u,\"host_thread_id\":%llu,\"thread_state\":%u,"
                     "\"class\":\"%s\",\"method\":\"%s\",\"detail\":\"%s\","
                     "\"activity_stage\":\"%s\",\"surface_identity\":%llu,\"generation\":%u,"
                     "\"surface_valid\":%s,\"canvas_locked\":%s,\"lock_owner_exec\":%u,"
                     "\"lock_count\":%u,\"unlock_count\":%u,\"post_count\":%u,"
                     "\"draw_bitmap_count\":%u,\"pixel_change_count\":%u,"
                     "\"counter_before\":%u,\"counter_after\":%u,\"has_counters\":%s,"
                     "\"created_count\":%u,\"changed_count\":%u}\n",
                     AGR_PHYSICAL_TRACE_SCHEMA, g_run_id,
                     (unsigned long long)seq, (unsigned long long)now,
                     name, name, g_commit, g_tree, sample->exec_id,
                     (unsigned long long)sample->host_thread, sample->thread_state,
                     sample->class_name, sample->method_name, sample->detail,
                     sample->phase == AGR_PHYS_PHASE_ACTIVITY_STAGE ? sample->detail : "",
                     (unsigned long long)sample->surface_identity, sample->surface_generation,
                     sample->surface_valid ? "true" : "false",
                     sample->canvas_locked ? "true" : "false",
                     sample->lock_owner_exec, sample->lock_count, sample->unlock_count,
                     sample->post_count, sample->draw_bitmap_count, sample->pixel_change_count,
                     sample->counter_before, sample->counter_after,
                     sample->has_counters ? "true" : "false",
                     sample->created_count, sample->changed_count);
    } else {
        n = snprintf(line, sizeof(line),
                     "{\"schema\":\"%s\",\"run_id\":\"%s\",\"seq\":%llu,\"monotonic_ns\":%llu,"
                     "\"event\":\"%s\",\"phase\":\"%s\",\"commit\":\"%s\",\"tree\":\"%s\","
                     "\"exec_id\":null,\"host_thread_id\":%llu,\"thread_state\":%u,"
                     "\"class\":\"%s\",\"method\":\"%s\",\"detail\":\"%s\","
                     "\"activity_stage\":\"%s\",\"surface_identity\":%llu,\"generation\":%u,"
                     "\"surface_valid\":%s,\"canvas_locked\":%s,\"lock_owner_exec\":%u,"
                     "\"lock_count\":%u,\"unlock_count\":%u,\"post_count\":%u,"
                     "\"draw_bitmap_count\":%u,\"pixel_change_count\":%u,"
                     "\"counter_before\":%u,\"counter_after\":%u,\"has_counters\":%s,"
                     "\"created_count\":%u,\"changed_count\":%u}\n",
                     AGR_PHYSICAL_TRACE_SCHEMA, g_run_id,
                     (unsigned long long)seq, (unsigned long long)now,
                     name, name, g_commit, g_tree,
                     (unsigned long long)sample->host_thread, sample->thread_state,
                     sample->class_name, sample->method_name, sample->detail,
                     sample->phase == AGR_PHYS_PHASE_ACTIVITY_STAGE ? sample->detail : "",
                     (unsigned long long)sample->surface_identity, sample->surface_generation,
                     sample->surface_valid ? "true" : "false",
                     sample->canvas_locked ? "true" : "false",
                     sample->lock_owner_exec, sample->lock_count, sample->unlock_count,
                     sample->post_count, sample->draw_bitmap_count, sample->pixel_change_count,
                     sample->counter_before, sample->counter_after,
                     sample->has_counters ? "true" : "false",
                     sample->created_count, sample->changed_count);
    }
    if (n < 0 || (size_t)n >= sizeof(line)) return;
    if (write(g_trace_fd, line, (size_t)n) != n) return;
    if (sync) {
        fsync(g_trace_fd);
        g_sync_count++;
    }
    g_bytes += (uint32_t)n;
    g_event_count++;
    update_crash_image(seq, sample);
    remember_exec(sample);
    if (!phase_is_watchdog(sample->phase)) {
        uint64_t gap = g_last_progress_ns ? now - g_last_progress_ns : 0;
        if (gap > g_max_gap_ns) g_max_gap_ns = gap;
        g_last_progress_ns = now;
        g_runtime_seq = seq;
    }
}

static agr_forensic_sample g_own;
static int g_has_own = 0;

static void store_ownership(const agr_forensic_sample *sample) {
    g_own = *sample;
    g_has_own = 1;
}

static void fill_status(agr_physical_trace_status *out) {
    uint64_t now;
    if (!out) return;
    memset(out, 0, sizeof(*out));
    copy_text(out->run_id, sizeof(out->run_id), g_run_id);
    out->last_seq = g_seq >= SEQ_ORIGIN ? g_seq : 0;
    out->event_count = g_event_count;
    copy_text(out->last_event, sizeof(out->last_event), g_last_event);
    out->last_phase = g_last_phase;
    out->heartbeat_count = g_heartbeat_count;
    out->no_progress_level = g_no_progress_level;
    out->max_progress_gap_ms = g_max_gap_ns / 1000000ull;
    now = mono_ns();
    out->progress_age_ms = g_last_progress_ns ? (now - g_last_progress_ns) / 1000000ull : 0;
    out->crash_marker_present = 0;
    out->watchdog_stalled = g_stalled;
    copy_text(out->watchdog_state, sizeof(out->watchdog_state),
              g_stalled ? "STALLED" : (g_watchdog_started && !g_stop ? "RUNNING" : "STOPPED"));
    copy_text(out->trace_file, sizeof(out->trace_file), TRACE_NAME);
    out->root_exec = g_root_exec;
    out->has_root_exec = g_has_root;
    out->game_exec = g_game_exec;
    out->has_game_exec = g_has_game;
    out->game_thread_state = g_game_state;
    out->game_host_thread = g_game_host;
    copy_text(out->termination_reason, sizeof(out->termination_reason), g_reason);
    if (g_crash_fd >= 0) {
        struct stat st;
        char path[640];
        path_join(path, sizeof(path), CRASH_NAME);
        if (stat(path, &st) == 0 && st.st_size >= (off_t)sizeof(struct crash_image))
            out->crash_marker_present = 1;
    }
}

static void restore_signals(void) {
    if (!g_signals_installed) return;
    sigaction(SIGABRT, &g_old_abrt, NULL);
    sigaction(SIGSEGV, &g_old_segv, NULL);
    sigaction(SIGBUS, &g_old_bus, NULL);
    sigaction(SIGILL, &g_old_ill, NULL);
    sigaction(SIGFPE, &g_old_fpe, NULL);
    g_signals_installed = 0;
}

static void fatal_signal(int sig) {
    struct crash_image local;
    uint32_t s1;
    uint32_t s2;
    int spins = 0;
    memset(&local, 0, sizeof(local));
    do {
        s1 = __atomic_load_n(&g_crash_seq, __ATOMIC_ACQUIRE);
        if (s1 & 1u) {
            if (++spins > 8) break;
            continue;
        }
        local = g_crash;
        s2 = __atomic_load_n(&g_crash_seq, __ATOMIC_ACQUIRE);
        if (s1 == s2 && (s2 & 1u) == 0) break;
    } while (++spins <= 8);
    memcpy(local.magic, AGR_PHYSICAL_CRASH_MAGIC, 8);
    local.version = AGR_PHYSICAL_CRASH_VERSION;
    local.signal_number = sig;
    if (g_crash_fd >= 0) {
        ssize_t w = write(g_crash_fd, &local, sizeof(local));
        (void)w;
    }
    signal(sig, SIG_DFL);
    raise(sig);
}

static void install_signals(void) {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = fatal_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESETHAND;
    sigaction(SIGABRT, &sa, &g_old_abrt);
    sigaction(SIGSEGV, &sa, &g_old_segv);
    sigaction(SIGBUS, &sa, &g_old_bus);
    sigaction(SIGILL, &sa, &g_old_ill);
    sigaction(SIGFPE, &sa, &g_old_fpe);
    g_signals_installed = 1;
}

static void note_unlocked(const agr_forensic_sample *sample) {
    agr_forensic_sample clean = *sample;
    clean.class_name[sizeof(clean.class_name) - 1] = 0;
    clean.method_name[sizeof(clean.method_name) - 1] = 0;
    clean.detail[sizeof(clean.detail) - 1] = 0;
    copy_text(clean.class_name, sizeof(clean.class_name), sample->class_name);
    copy_text(clean.method_name, sizeof(clean.method_name), sample->method_name);
    copy_text(clean.detail, sizeof(clean.detail), sample->detail);
    store_ownership(&clean);
    commit_line_fixed(&clean);
}

static void *watchdog_main(void *arg) {
    (void)arg;
    for (;;) {
        uint32_t poll;
        uint32_t gap2, gap5, gap8;
        agr_forensic_sample own;
        int stop;
        uint64_t age_ms;
        uint32_t level;
        int (*probe)(void *);
        void *user;
        struct timespec ts;
        pthread_mutex_lock(&g_mu);
        stop = g_stop || !g_active;
        poll = g_poll_ms ? g_poll_ms : AGR_PHYSICAL_WATCHDOG_POLL_MS;
        gap2 = g_gap2_ms;
        gap5 = g_gap5_ms;
        gap8 = g_gap8_ms;
        own = g_own;
        probe = g_probe;
        user = g_probe_user;
        pthread_mutex_unlock(&g_mu);
        if (stop) break;
        ts.tv_sec = poll / 1000u;
        ts.tv_nsec = (long)(poll % 1000u) * 1000000L;
        nanosleep(&ts, NULL);
        if (probe && probe(user)) {
            pthread_mutex_lock(&g_mu);
            if (g_active && !g_stop) {
                agr_forensic_sample denied = g_has_own ? g_own : own;
                denied.phase = AGR_PHYS_PHASE_SNAPSHOT_UNAVAILABLE;
                denied.critical = 0;
                copy_text(denied.detail, sizeof(denied.detail), "snapshot_unavailable_due_to_lock");
                note_unlocked(&denied);
            }
            pthread_mutex_unlock(&g_mu);
        }
        pthread_mutex_lock(&g_mu);
        if (g_stop || !g_active) {
            pthread_mutex_unlock(&g_mu);
            break;
        }
        age_ms = g_last_progress_ns ? (mono_ns() - g_last_progress_ns) / 1000000ull : 0;
        level = 0;
        if (age_ms >= gap8) level = 8;
        else if (age_ms >= gap5) level = 5;
        else if (age_ms >= gap2) level = 2;
        if (level > g_no_progress_level) g_no_progress_level = level;
        {
            agr_forensic_sample beat = g_has_own ? g_own : own;
            beat.phase = AGR_PHYS_PHASE_WATCHDOG_HEARTBEAT;
            beat.critical = 0;
            snprintf(beat.detail, sizeof(beat.detail), "age_ms=%llu", (unsigned long long)age_ms);
            note_unlocked(&beat);
            g_heartbeat_count++;
        }
        if (age_ms >= gap2 && g_reported_level < 2) {
            agr_forensic_sample stall = g_has_own ? g_own : own;
            stall.phase = AGR_PHYS_PHASE_WATCHDOG_NO_PROGRESS_2S;
            stall.critical = 0;
            snprintf(stall.detail, sizeof(stall.detail), "age_ms=%llu", (unsigned long long)age_ms);
            note_unlocked(&stall);
            g_reported_level = 2;
        }
        if (age_ms >= gap5 && g_reported_level < 5) {
            agr_forensic_sample stall = g_has_own ? g_own : own;
            stall.phase = AGR_PHYS_PHASE_WATCHDOG_NO_PROGRESS_5S;
            stall.critical = 0;
            snprintf(stall.detail, sizeof(stall.detail), "age_ms=%llu", (unsigned long long)age_ms);
            note_unlocked(&stall);
            g_reported_level = 5;
        }
        if (age_ms >= gap8 && g_reported_level < 8) {
            agr_forensic_sample stall = g_has_own ? g_own : own;
            stall.phase = AGR_PHYS_PHASE_WATCHDOG_NO_PROGRESS_8S;
            stall.critical = 1;
            snprintf(stall.detail, sizeof(stall.detail), "age_ms=%llu", (unsigned long long)age_ms);
            note_unlocked(&stall);
            stall.phase = AGR_PHYS_PHASE_WATCHDOG_STALL;
            copy_text(stall.detail, sizeof(stall.detail), "WATCHDOG_STALL");
            note_unlocked(&stall);
            g_reported_level = 8;
            g_no_progress_level = 8;
            g_stalled = 1;
            copy_text(g_reason, sizeof(g_reason), "WATCHDOG_STALL");
            write_run_file("WATCHDOG_STALL");
        }
        pthread_mutex_unlock(&g_mu);
    }
    return NULL;
}

static int read_run_id(const char *path, char *out, size_t cap) {
    FILE *fp = fopen(path, "r");
    char buf[2048];
    char *key;
    char *q1;
    char *q2;
    size_t n;
    if (!fp) return -1;
    n = fread(buf, 1, sizeof(buf) - 1, fp);
    fclose(fp);
    buf[n] = 0;
    key = strstr(buf, "\"run_id\"");
    if (!key) return -1;
    q1 = strchr(key + 8, '"');
    if (!q1) return -1;
    q2 = strchr(q1 + 1, '"');
    if (!q2 || (size_t)(q2 - q1) >= cap) return -1;
    memcpy(out, q1 + 1, (size_t)(q2 - q1 - 1));
    out[q2 - q1 - 1] = 0;
    return out[0] ? 0 : -1;
}

static void archive_previous(void) {
    char prev[640];
    char run_path[640];
    char id[40];
    char dest[768];
    static const char *names[] = {RUN_NAME, TRACE_NAME, FINAL_NAME, CRASH_NAME};
    size_t i;
    snprintf(prev, sizeof(prev), "%s/previous", g_dir);
    mkdir(prev, 0755);
    snprintf(run_path, sizeof(run_path), "%s/%s", g_dir, RUN_NAME);
    if (read_run_id(run_path, id, sizeof(id)) != 0)
        snprintf(id, sizeof(id), "unreadable-%d-%llu", (int)getpid(),
                 (unsigned long long)mono_ns());
    snprintf(dest, sizeof(dest), "%s/%s", prev, id);
    if (mkdir(dest, 0755) != 0)
        snprintf(dest, sizeof(dest), "%s/%s-%llu", prev, id, (unsigned long long)mono_ns());
    mkdir(dest, 0755);
    for (i = 0; i < sizeof(names) / sizeof(names[0]); i++) {
        char from[640];
        char to[800];
        snprintf(from, sizeof(from), "%s/%s", g_dir, names[i]);
        snprintf(to, sizeof(to), "%s/%s", dest, names[i]);
        if (access(from, F_OK) == 0) rename(from, to);
    }
}

static void make_run_id(void) {
    uint64_t a = mono_ns();
    uint64_t b = ((uint64_t)getpid() << 32) ^ (uint64_t)time(NULL);
    snprintf(g_run_id, sizeof(g_run_id), "%016llx%016llx",
             (unsigned long long)a, (unsigned long long)b);
}

void agr_physical_trace_set_watchdog_for_test(uint32_t poll_ms, uint32_t gap2_ms,
                                               uint32_t gap5_ms, uint32_t gap8_ms) {
    pthread_mutex_lock(&g_mu);
    if (poll_ms) g_poll_ms = poll_ms;
    if (gap2_ms) g_gap2_ms = gap2_ms;
    if (gap5_ms) g_gap5_ms = gap5_ms;
    if (gap8_ms) g_gap8_ms = gap8_ms;
    pthread_mutex_unlock(&g_mu);
}

void agr_physical_trace_set_lock_probe(int (*probe)(void *user), void *user) {
    pthread_mutex_lock(&g_mu);
    g_probe = probe;
    g_probe_user = user;
    pthread_mutex_unlock(&g_mu);
}

uint32_t agr_physical_trace_sync_count(void) {
    uint32_t count;
    pthread_mutex_lock(&g_mu);
    count = g_sync_count;
    pthread_mutex_unlock(&g_mu);
    return count;
}

int agr_physical_trace_begin(const agr_physical_trace_config *config) {
    char path[640];
    agr_forensic_sample launch;
    if (!config || !config->directory || !config->commit || !config->tree) return -1;
    agr_physical_trace_shutdown();
    pthread_mutex_lock(&g_mu);
    memset(g_dir, 0, sizeof(g_dir));
    copy_text(g_dir, sizeof(g_dir), config->directory);
    /* copy_text strips punctuation. Directory paths contain '/'. Restore. */
    snprintf(g_dir, sizeof(g_dir), "%s", config->directory);
    copy_text(g_branch, sizeof(g_branch), config->branch ? config->branch : "");
    copy_text(g_commit, sizeof(g_commit), config->commit);
    copy_text(g_tree, sizeof(g_tree), config->tree);
    copy_text(g_platform, sizeof(g_platform), config->device_platform ? config->device_platform : "");
    copy_text(g_arch, sizeof(g_arch), config->architecture ? config->architecture : "");
    copy_text(g_apk_sha, sizeof(g_apk_sha), config->apk_sha256_expected ? config->apk_sha256_expected : "");
    mkdir(g_dir, 0755);
    archive_previous();
    make_run_id();
    g_seq = SEQ_ORIGIN - 1ull;
    g_runtime_seq = 0;
    g_last_progress_ns = mono_ns();
    g_max_gap_ns = 0;
    g_event_count = 0;
    g_bytes = 0;
    g_last_phase = 0;
    g_heartbeat_count = 0;
    g_no_progress_level = 0;
    g_reported_level = 0;
    g_stalled = 0;
    memset(g_phase_synced, 0, sizeof(g_phase_synced));
    g_sync_count = 0;
    g_finished = 0;
    g_stop = 0;
    g_has_own = 0;
    g_has_root = 0;
    g_has_game = 0;
    g_last_event[0] = 0;
    g_reason[0] = 0;
    memset(&g_crash, 0, sizeof(g_crash));
    memcpy(g_crash.magic, AGR_PHYSICAL_CRASH_MAGIC, 8);
    g_crash.version = AGR_PHYSICAL_CRASH_VERSION;
    g_crash_seq = 0;
    write_run_file("RUNNING");
    path_join(path, sizeof(path), TRACE_NAME);
    g_trace_fd = open(path, O_CREAT | O_TRUNC | O_WRONLY, 0644);
    path_join(path, sizeof(path), CRASH_NAME);
    g_crash_fd = open(path, O_CREAT | O_TRUNC | O_RDWR, 0644);
    if (g_trace_fd < 0) {
        g_active = 0;
        pthread_mutex_unlock(&g_mu);
        return -1;
    }
    g_active = 1;
    memset(&launch, 0, sizeof(launch));
    launch.phase = AGR_PHYS_PHASE_APP_LAUNCH_BEGIN;
    launch.critical = 1;
    launch.host_thread = (uint64_t)pthread_self();
    note_unlocked(&launch);
    launch.phase = AGR_PHYS_PHASE_TRACE_READY;
    launch.critical = 1;
    note_unlocked(&launch);
    pthread_mutex_unlock(&g_mu);
    install_signals();
    if (pthread_create(&g_watchdog, NULL, watchdog_main, NULL) == 0)
        g_watchdog_started = 1;
    return 0;
}

void agr_forensic_publish(const agr_forensic_sample *sample) {
    if (!sample) return;
    pthread_mutex_lock(&g_mu);
    if (g_active && !g_finished) note_unlocked(sample);
    pthread_mutex_unlock(&g_mu);
}

void agr_physical_trace_event(const agr_forensic_sample *sample) {
    agr_forensic_publish(sample);
}

void agr_physical_trace_publish_ownership(const agr_forensic_sample *sample) {
    if (!sample) return;
    pthread_mutex_lock(&g_mu);
    if (g_active) store_ownership(sample);
    pthread_mutex_unlock(&g_mu);
}

void agr_physical_trace_copy_status(agr_physical_trace_status *out) {
    pthread_mutex_lock(&g_mu);
    fill_status(out);
    pthread_mutex_unlock(&g_mu);
}

int agr_physical_trace_finish(const char *termination_reason, agr_physical_trace_status *out) {
    agr_forensic_sample sample;
    int started = 0;
    pthread_mutex_lock(&g_mu);
    if (!g_active) {
        pthread_mutex_unlock(&g_mu);
        return -1;
    }
    if (!g_finished) {
        const char *reason = termination_reason && termination_reason[0] ? termination_reason : "RUNTIME_ERROR";
        if (g_stalled && strcmp(reason, "CONTENT_POSTED") != 0)
            reason = "WATCHDOG_STALL";
        copy_text(g_reason, sizeof(g_reason), reason);
        memset(&sample, 0, sizeof(sample));
        if (g_has_own) sample = g_own;
        sample.phase = AGR_PHYS_PHASE_FINALIZE_BEGIN;
        sample.critical = 1;
        copy_text(sample.detail, sizeof(sample.detail), g_reason);
        sample.host_thread = (uint64_t)pthread_self();
        note_unlocked(&sample);
        sample.phase = AGR_PHYS_PHASE_FINALIZE_END;
        note_unlocked(&sample);
        write_run_file(g_reason);
        g_finished = 1;
        g_stop = 1;
        started = g_watchdog_started;
        g_watchdog_started = 0;
    }
    fill_status(out);
    if (out) copy_text(out->watchdog_state, sizeof(out->watchdog_state), "STOPPED");
    pthread_mutex_unlock(&g_mu);
    if (started) pthread_join(g_watchdog, NULL);
    return 0;
}

void agr_physical_trace_note_writer_error(const char *detail) {
    agr_forensic_sample sample;
    pthread_mutex_lock(&g_mu);
    if (!g_active) {
        pthread_mutex_unlock(&g_mu);
        return;
    }
    memset(&sample, 0, sizeof(sample));
    sample.phase = AGR_PHYS_PHASE_RUNTIME_ERROR;
    sample.critical = 1;
    copy_text(sample.detail, sizeof(sample.detail), detail ? detail : "EVIDENCE_WRITER_ERROR");
    sample.host_thread = (uint64_t)pthread_self();
    g_finished = 0;
    note_unlocked(&sample);
    g_finished = 1;
    copy_text(g_reason, sizeof(g_reason), "EVIDENCE_WRITER_ERROR");
    write_run_file("EVIDENCE_WRITER_ERROR");
    pthread_mutex_unlock(&g_mu);
}

void agr_physical_trace_shutdown(void) {
    int started;
    pthread_mutex_lock(&g_mu);
    g_stop = 1;
    started = g_watchdog_started;
    g_watchdog_started = 0;
    pthread_mutex_unlock(&g_mu);
    if (started) pthread_join(g_watchdog, NULL);
    pthread_mutex_lock(&g_mu);
    if (g_trace_fd >= 0) {
        fsync(g_trace_fd);
        close(g_trace_fd);
        g_trace_fd = -1;
    }
    if (g_crash_fd >= 0) {
        close(g_crash_fd);
        g_crash_fd = -1;
    }
    g_active = 0;
    pthread_mutex_unlock(&g_mu);
    restore_signals();
}
