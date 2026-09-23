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

/* Implemented by the iOS host with CommonCrypto. Linux contract tests may
   omit it; their export verifier computes the digest independently. */
extern int agr_physical_sha256_file(const char *, char *, size_t) __attribute__((weak));

#define TRACE_NAME "agr-current-trace.ndjson"
#define RUN_NAME "agr-current-run.json"
#define FINAL_NAME "agr-current-runtime.json"
#define CRASH_NAME "agr-current-crash.bin"
#define LEGACY_TRACE_NAME "agr-physical-trace.ndjson"
#define LEGACY_RUN_NAME "agr-physical-run.json"
#define LEGACY_FINAL_NAME "agr-physical-runtime.json"
#define LEGACY_CRASH_NAME "agr-physical-crash.bin"
#define PREVIOUS_TRACE_NAME "agr-prev-trace.ndjson"
#define PREVIOUS_RUN_NAME "agr-prev-run.json"
#define PREVIOUS_FINAL_NAME "agr-prev-runtime.json"
#define PREVIOUS_CRASH_NAME "agr-prev-crash.bin"
#define CURRENT_MANIFEST_NAME "agr-current-manifest.json"
#define ARCHIVE_MANIFEST_NAME "manifest.json"
#define ARCHIVE_INDEX_NAME "index.jsonl"
#define ARCHIVE_PENDING_NAME "archive.pending"
#define PASSIVE_RING_CAP 128u
#define LINE_CAP 4096
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
static uint8_t g_phase_synced[128];
static volatile uint32_t g_passive_dropped = 0;
static pthread_mutex_t g_passive_mu = PTHREAD_MUTEX_INITIALIZER;
static agr_forensic_sample g_passive_ring[PASSIVE_RING_CAP];
static uint32_t g_passive_head = 0, g_passive_tail = 0, g_passive_count = 0;
static uint64_t g_passive_order = 0;
static volatile int g_passive_enabled = 0;
static uint32_t g_sync_count = 0;
static int g_finished = 0;
static char g_dir[512];
static char g_run_id[40];
static char g_launch_id[40];
static char g_state[64];
static char g_env_json[12288];
static char g_env_end_json[12288];
static char g_env_changes_json[4096];
static int g_env_set = 0;
static int g_env_end_set = 0;
static int g_env_changed = 0;
static pid_t g_pid = 0;
static char g_process_start_wall[40];
static uint64_t g_process_start_mono_ns = 0;
static char g_life[32];
static int g_foreground = 0;
static int g_app_active = 0;
static char g_apk_actual[80];
static char g_boundary[80];
static char g_last_error[96];
static uint64_t g_obs_start = 0;
static uint64_t g_obs_deadline = 0;
static uint64_t g_obs_end = 0;
static uint32_t g_obs_frames = 0;
static char g_obs_reason[64];
#define BIN_CAP 4
static struct {
    char role[24];
    char uuid[48];
    char sha[80];
} g_bin[BIN_CAP];
static int g_bin_count = 0;
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

static void capture_process_identity(void) {
    struct timespec wall;
    struct tm utc;
    time_t seconds;
    size_t timestamp_len;
    unsigned milliseconds;
    g_pid = getpid();
    g_process_start_mono_ns = mono_ns();
    memset(&wall, 0, sizeof(wall));
    memset(&utc, 0, sizeof(utc));
    if (clock_gettime(CLOCK_REALTIME, &wall) != 0) {
        g_process_start_wall[0] = 0;
        return;
    }
    seconds = wall.tv_sec;
    gmtime_r(&seconds, &utc);
    timestamp_len = strftime(g_process_start_wall, sizeof(g_process_start_wall),
                              "%Y-%m-%dT%H:%M:%S", &utc);
    if (timestamp_len == 0 || timestamp_len + 5 >= sizeof(g_process_start_wall)) {
        g_process_start_wall[0] = 0;
        return;
    }
    milliseconds = wall.tv_nsec >= 0 && wall.tv_nsec < 1000000000L
                       ? (unsigned)(wall.tv_nsec / 1000000L)
                       : 0;
    g_process_start_wall[timestamp_len++] = '.';
    g_process_start_wall[timestamp_len++] = (char)('0' + milliseconds / 100);
    g_process_start_wall[timestamp_len++] = (char)('0' + (milliseconds / 10) % 10);
    g_process_start_wall[timestamp_len++] = (char)('0' + milliseconds % 10);
    g_process_start_wall[timestamp_len++] = 'Z';
    g_process_start_wall[timestamp_len] = 0;
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
    case AGR_PHYS_PHASE_EVIDENCE_RESET_BEGIN: return "EVIDENCE_RESET_BEGIN";
    case AGR_PHYS_PHASE_EVIDENCE_RESET_OK: return "EVIDENCE_RESET_OK";
    case AGR_PHYS_PHASE_RUN_ID_CREATED: return "RUN_ID_CREATED";
    case AGR_PHYS_PHASE_RUN_FILE_WRITTEN: return "RUN_FILE_WRITTEN";
    case AGR_PHYS_PHASE_TRACE_OPENED: return "TRACE_OPENED";
    case AGR_PHYS_PHASE_ENVIRONMENT_CAPTURE_BEGIN: return "ENVIRONMENT_CAPTURE_BEGIN";
    case AGR_PHYS_PHASE_ENVIRONMENT_CAPTURE_OK: return "ENVIRONMENT_CAPTURE_OK";
    case AGR_PHYS_PHASE_ENVIRONMENT_CAPTURE_PARTIAL: return "ENVIRONMENT_CAPTURE_PARTIAL";
    case AGR_PHYS_PHASE_ENVIRONMENT_CAPTURE_FAIL: return "ENVIRONMENT_CAPTURE_FAIL";
    case AGR_PHYS_PHASE_EVIDENCE_CHANNEL_FAILED: return "EVIDENCE_CHANNEL_FAILED";
    case AGR_PHYS_PHASE_APP_DID_FINISH_LAUNCHING: return "APP_DID_FINISH_LAUNCHING";
    case AGR_PHYS_PHASE_APP_DID_BECOME_ACTIVE: return "APP_DID_BECOME_ACTIVE";
    case AGR_PHYS_PHASE_APP_WILL_RESIGN_ACTIVE: return "APP_WILL_RESIGN_ACTIVE";
    case AGR_PHYS_PHASE_APP_DID_ENTER_BACKGROUND: return "APP_DID_ENTER_BACKGROUND";
    case AGR_PHYS_PHASE_APP_WILL_ENTER_FOREGROUND: return "APP_WILL_ENTER_FOREGROUND";
    case AGR_PHYS_PHASE_APP_WILL_TERMINATE: return "APP_WILL_TERMINATE";
    case AGR_PHYS_PHASE_SCENE_DID_BECOME_ACTIVE: return "SCENE_DID_BECOME_ACTIVE";
    case AGR_PHYS_PHASE_SCENE_WILL_RESIGN_ACTIVE: return "SCENE_WILL_RESIGN_ACTIVE";
    case AGR_PHYS_PHASE_ENVIRONMENT_CHANGED: return "ENVIRONMENT_CHANGED";
    case AGR_PHYS_PHASE_CADISPLAYLINK_FRAME: return "CADISPLAYLINK_FRAME";
    case AGR_PHYS_PHASE_GUEST_EXEC_SNAPSHOT: return "GUEST_EXEC_SNAPSHOT";
    case AGR_PHYS_PHASE_DIAGNOSTIC_FIELD_WITNESS: return "DIAGNOSTIC_FIELD_WITNESS";
    case AGR_PHYS_PHASE_OBSERVATION_WINDOW: return "OBSERVATION_WINDOW";
    case AGR_PHYS_PHASE_MEMORY_WARNING: return "MEMORY_WARNING";
    case AGR_PHYS_PHASE_THERMAL_CHANGED: return "THERMAL_CHANGED";
    case AGR_PHYS_PHASE_LOW_POWER_CHANGED: return "LOW_POWER_CHANGED";
    case AGR_PHYS_PHASE_PROTECTED_DATA_CHANGED: return "PROTECTED_DATA_CHANGED";
    case AGR_PHYS_PHASE_BINARY_FINGERPRINT: return "BINARY_FINGERPRINT";
    case AGR_PHYS_PHASE_BITMAP_DECODE_WITNESS: return "BITMAP_DECODE_WITNESS";
    case AGR_PHYS_PHASE_BITMAP_REFERENCE_WITNESS: return "BITMAP_REFERENCE_WITNESS";
    case AGR_PHYS_PHASE_BITMAP_FIELD_WITNESS: return "BITMAP_FIELD_WITNESS";
    case AGR_PHYS_PHASE_HOST_SURFACE_ACQUIRED: return "HOST_SURFACE_ACQUIRED";
    case AGR_PHYS_PHASE_HOST_SURFACE_SUBMITTED: return "HOST_SURFACE_SUBMITTED";
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

static void format_binaries(char *out, size_t cap) {
    size_t used = 0;
    int i;
    int n;
    if (cap == 0) return;
    n = snprintf(out, cap, "[");
    if (n < 0 || (size_t)n >= cap) {
        out[0] = 0;
        return;
    }
    used = (size_t)n;
    for (i = 0; i < g_bin_count; i++) {
        n = snprintf(out + used, cap - used,
                     "%s{\"role\":\"%s\",\"uuid\":\"%s\",\"sha256\":\"%s\"}",
                     i ? "," : "", g_bin[i].role, g_bin[i].uuid, g_bin[i].sha);
        if (n < 0 || (size_t)n >= cap - used) {
            out[0] = 0;
            return;
        }
        used += (size_t)n;
    }
    snprintf(out + used, cap - used, "]");
}

static void write_run_file(const char *state) {
    char path[640];
    char binaries[2048];
    char *body;
    int fd;
    int n;
    const char *env;
    const char *env_end;
    const char *env_changes;
    if (state && state[0]) copy_text(g_state, sizeof(g_state), state);
    path_join(path, sizeof(path), RUN_NAME);
    format_binaries(binaries, sizeof(binaries));
    if (!binaries[0]) snprintf(binaries, sizeof(binaries), "[]");
    env = g_env_set && g_env_json[0] == '{' ? g_env_json : "null";
    env_end = g_env_end_set && g_env_end_json[0] == '{' ? g_env_end_json : "null";
    env_changes = g_env_changed && g_env_changes_json[0] == '[' ? g_env_changes_json : "[]";
    body = (char *)malloc(65536);
    if (!body) return;
    n = snprintf(body, 65536,
                 "{\n"
                 "  \"schema\": \"%s\",\n"
                 "  \"run_id\": \"%s\",\n"
                 "  \"process_launch_id\": \"%s\",\n"
                 "  \"launch_kind\": \"NEW_PROCESS\",\n"
                 "  \"pid\": %ld,\n"
                 "  \"process_start_wall_time\": \"%s\",\n"
                 "  \"process_start_monotonic_ns\": %llu,\n"
                 "  \"branch\": \"%s\",\n"
                 "  \"commit\": \"%s\",\n"
                 "  \"tree\": \"%s\",\n"
                 "  \"device_platform\": \"%s\",\n"
                 "  \"architecture\": \"%s\",\n"
                 "  \"apk_sha256_expected\": \"%s\",\n"
                 "  \"apk_sha256_actual\": \"%s\",\n"
                 "  \"state\": \"%s\",\n"
                 "  \"termination_reason\": \"%s\",\n"
                 "  \"lifecycle_state\": \"%s\",\n"
                 "  \"foreground\": %s,\n"
                 "  \"active\": %s,\n"
                 "  \"last_seq\": %llu,\n"
                 "  \"last_phase\": \"%s\",\n"
                 "  \"last_exec\": %u,\n"
                 "  \"last_confirmed_boundary\": \"%s\",\n"
                 "  \"last_error\": \"%s\",\n"
                 "  \"observation_start_monotonic\": %llu,\n"
                 "  \"observation_deadline\": %llu,\n"
                 "  \"observation_end\": %llu,\n"
                 "  \"frames_observed\": %u,\n"
                 "  \"stop_reason\": \"%s\",\n"
                 "  \"binaries\": %s,\n"
                 "  \"environment\": ",
                 AGR_PHYSICAL_RUN_SCHEMA, g_run_id, g_launch_id, (long)g_pid, g_process_start_wall,
                 (unsigned long long)g_process_start_mono_ns, g_branch, g_commit, g_tree,
                 g_platform, g_arch, g_apk_sha, g_apk_actual,
                 g_state[0] ? g_state : "PROCESS_STARTED", g_reason,
                 g_life[0] ? g_life : "UNKNOWN",
                 g_foreground ? "true" : "false",
                 g_app_active ? "true" : "false",
                 (unsigned long long)(g_seq >= SEQ_ORIGIN ? g_seq : 0),
                 g_last_event, g_has_game ? g_game_exec : 0,
                 g_boundary, g_last_error,
                 (unsigned long long)g_obs_start, (unsigned long long)g_obs_deadline,
                 (unsigned long long)g_obs_end, g_obs_frames, g_obs_reason,
                 binaries);
    if (n > 0 && (size_t)n < 65536) {
        size_t env_len = strlen(env);
        char suffix[24576];
        int suffix_len = snprintf(suffix, sizeof(suffix),
            ",\n  \"environment_start\": %s,\n"
            "  \"environment_end\": %s,\n"
            "  \"environment_changed\": %s,\n"
            "  \"file_size_is_not_identity\": true,\n"
            "  \"trace_file\": \"%s\",\n"
            "  \"final_report_file\": \"%s\",\n"
            "  \"crash_file\": \"%s\"\n}\n",
            env, env_end, env_changes, TRACE_NAME, FINAL_NAME, CRASH_NAME);
        if ((size_t)n + env_len + (suffix_len > 0 ? (size_t)suffix_len : 65536u) < 65536u &&
            suffix_len > 0 && (size_t)suffix_len < sizeof(suffix)) {
            memcpy(body + n, env, env_len);
            memcpy(body + n + env_len, suffix, (size_t)suffix_len + 1u);
            n = n + (int)env_len + suffix_len;
        } else {
            n = -1;
        }
    }
    if (n > 0 && (size_t)n < 65536) {
        fd = open(path, O_CREAT | O_TRUNC | O_WRONLY, 0644);
        if (fd >= 0) {
            if (write(fd, body, (size_t)n) == n) fsync(fd);
            close(fd);
        }
    }
    free(body);
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
    case AGR_PHYS_PHASE_EVIDENCE_RESET_BEGIN:
    case AGR_PHYS_PHASE_EVIDENCE_RESET_OK:
    case AGR_PHYS_PHASE_RUN_ID_CREATED:
    case AGR_PHYS_PHASE_RUN_FILE_WRITTEN:
    case AGR_PHYS_PHASE_TRACE_OPENED:
    case AGR_PHYS_PHASE_ENVIRONMENT_CAPTURE_OK:
    case AGR_PHYS_PHASE_ENVIRONMENT_CAPTURE_PARTIAL:
    case AGR_PHYS_PHASE_ENVIRONMENT_CAPTURE_FAIL:
    case AGR_PHYS_PHASE_EVIDENCE_CHANNEL_FAILED:
    case AGR_PHYS_PHASE_MEMORY_WARNING:
    case AGR_PHYS_PHASE_THERMAL_CHANGED:
    case AGR_PHYS_PHASE_LOW_POWER_CHANGED:
    case AGR_PHYS_PHASE_PROTECTED_DATA_CHANGED:
    case AGR_PHYS_PHASE_BINARY_FINGERPRINT:
    case AGR_PHYS_PHASE_OBSERVATION_WINDOW:
    case AGR_PHYS_PHASE_ENVIRONMENT_CHANGED:
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
    case AGR_PHYS_PHASE_CADISPLAYLINK_FRAME:
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
    case AGR_PHYS_PHASE_GUEST_EXEC_SNAPSHOT:
    case AGR_PHYS_PHASE_DIAGNOSTIC_FIELD_WITNESS:
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
                     "{\"schema\":\"%s\",\"run_id\":\"%s\",\"process_launch_id\":\"%s\",\"seq\":%llu,\"monotonic_ns\":%llu,"
                     "\"event\":\"%s\",\"phase\":\"%s\",\"commit\":\"%s\",\"tree\":\"%s\","
                     "\"exec_id\":%u,\"host_thread_id\":%llu,\"thread_state\":%u,"
                     "\"class\":\"%s\",\"method\":\"%s\",\"detail\":\"%s\","
                     "\"activity_stage\":\"%s\",\"surface_identity\":%llu,\"generation\":%u,"
                     "\"surface_valid\":%s,\"canvas_locked\":%s,\"lock_owner_exec\":%u,"
                     "\"lock_count\":%u,\"unlock_count\":%u,\"post_count\":%u,"
                     "\"draw_bitmap_count\":%u,\"pixel_change_count\":%u,"
                     "\"counter_before\":%u,\"counter_after\":%u,\"has_counters\":%s,"
                     "\"created_count\":%u,\"changed_count\":%u,\"guest_pc\":%u,\"has_guest_pc\":%s,"
                     "\"object_identity\":%llu,\"related_identity\":%llu,\"backing_owner_identity\":%llu,\"backing_identity\":%llu,\"passive_order\":%llu,"
                     "\"resource_id\":%d,\"width\":%d,\"height\":%d,\"value0\":%d,\"value1\":%d,"
                     "\"witness_flags\":%u,\"witness_status\":%u,\"timing_sensitive\":%s}\n",
                     AGR_PHYSICAL_TRACE_SCHEMA, g_run_id, g_launch_id,
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
                     sample->created_count, sample->changed_count, sample->guest_pc,
                     sample->has_guest_pc ? "true" : "false",
                     (unsigned long long)sample->object_identity,
                     (unsigned long long)sample->related_identity,
                     (unsigned long long)sample->backing_owner_identity,
                     (unsigned long long)sample->backing_identity,
                     (unsigned long long)sample->passive_order,
                     sample->resource_id, sample->width, sample->height,
                     sample->value0, sample->value1, sample->witness_flags,
                     sample->witness_status, sample->timing_sensitive ? "true" : "false");
    } else {
        n = snprintf(line, sizeof(line),
                     "{\"schema\":\"%s\",\"run_id\":\"%s\",\"process_launch_id\":\"%s\",\"seq\":%llu,\"monotonic_ns\":%llu,"
                     "\"event\":\"%s\",\"phase\":\"%s\",\"commit\":\"%s\",\"tree\":\"%s\","
                     "\"exec_id\":null,\"host_thread_id\":%llu,\"thread_state\":%u,"
                     "\"class\":\"%s\",\"method\":\"%s\",\"detail\":\"%s\","
                     "\"activity_stage\":\"%s\",\"surface_identity\":%llu,\"generation\":%u,"
                     "\"surface_valid\":%s,\"canvas_locked\":%s,\"lock_owner_exec\":%u,"
                     "\"lock_count\":%u,\"unlock_count\":%u,\"post_count\":%u,"
                     "\"draw_bitmap_count\":%u,\"pixel_change_count\":%u,"
                     "\"counter_before\":%u,\"counter_after\":%u,\"has_counters\":%s,"
                     "\"created_count\":%u,\"changed_count\":%u,\"guest_pc\":%u,\"has_guest_pc\":%s,"
                     "\"object_identity\":%llu,\"related_identity\":%llu,\"backing_owner_identity\":%llu,\"backing_identity\":%llu,\"passive_order\":%llu,"
                     "\"resource_id\":%d,\"width\":%d,\"height\":%d,\"value0\":%d,\"value1\":%d,"
                     "\"witness_flags\":%u,\"witness_status\":%u,\"timing_sensitive\":%s}\n",
                     AGR_PHYSICAL_TRACE_SCHEMA, g_run_id, g_launch_id,
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
                     sample->created_count, sample->changed_count, sample->guest_pc,
                     sample->has_guest_pc ? "true" : "false",
                     (unsigned long long)sample->object_identity,
                     (unsigned long long)sample->related_identity,
                     (unsigned long long)sample->backing_owner_identity,
                     (unsigned long long)sample->backing_identity,
                     (unsigned long long)sample->passive_order,
                     sample->resource_id, sample->width, sample->height,
                     sample->value0, sample->value1, sample->witness_flags,
                     sample->witness_status, sample->timing_sensitive ? "true" : "false");
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
    if (sample->phase == AGR_PHYS_PHASE_APK_OPEN_OK ||
        sample->phase == AGR_PHYS_PHASE_ACTIVITY_START_OK ||
        sample->phase == AGR_PHYS_PHASE_SURFACE_CREATED ||
        sample->phase == AGR_PHYS_PHASE_SURFACE_CHANGED ||
        sample->phase == AGR_PHYS_PHASE_SURFACE_CALLBACK_OK ||
        sample->phase == AGR_PHYS_PHASE_THREAD_RUN_ENTER ||
        sample->phase == AGR_PHYS_PHASE_CANVAS_LOCK_ACQUIRED ||
        sample->phase == AGR_PHYS_PHASE_DRAW_BITMAP_END ||
        sample->phase == AGR_PHYS_PHASE_CANVAS_POST_END ||
        sample->phase == AGR_PHYS_PHASE_GUEST_METHOD_ENTER) {
        copy_text(g_boundary, sizeof(g_boundary), name);
    }
    if (sample->detail[0] &&
        (sample->phase == AGR_PHYS_PHASE_RUNTIME_ERROR ||
         sample->phase == AGR_PHYS_PHASE_WATCHDOG_STALL ||
         sample->phase == AGR_PHYS_PHASE_EVIDENCE_CHANNEL_FAILED ||
         sample->phase == AGR_PHYS_PHASE_SURFACE_CALLBACK_THROW ||
         sample->phase == AGR_PHYS_PHASE_BITMAP_SCALE_FAIL ||
         sample->phase == AGR_PHYS_PHASE_APK_OPEN_FAIL ||
         sample->phase == AGR_PHYS_PHASE_APK_SHA_FAIL))
        copy_text(g_last_error, sizeof(g_last_error), sample->detail);
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
    copy_text(out->process_launch_id, sizeof(out->process_launch_id), g_launch_id);
    out->pid = (long)g_pid;
    copy_text(out->process_start_wall_time, sizeof(out->process_start_wall_time), g_process_start_wall);
    out->process_start_monotonic_ns = g_process_start_mono_ns;
    out->last_seq = g_seq >= SEQ_ORIGIN ? g_seq : 0;
    out->event_count = g_event_count;
    out->passive_dropped_count = __atomic_load_n(&g_passive_dropped, __ATOMIC_RELAXED);
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

static const char *state_for_sample(const agr_forensic_sample *sample) {
    switch (sample->phase) {
    case AGR_PHYS_PHASE_ENVIRONMENT_CAPTURE_OK:
    case AGR_PHYS_PHASE_ENVIRONMENT_CAPTURE_PARTIAL: return "ENVIRONMENT_CAPTURED";
    case AGR_PHYS_PHASE_APK_LOCATE_BEGIN: return "APK_LOCATING";
    case AGR_PHYS_PHASE_APK_OPEN_OK: return "APK_OPENED";
    case AGR_PHYS_PHASE_ACTIVITY_STAGE:
        if (strstr(sample->detail, "RESUMED") || strstr(sample->detail, "resumed"))
            return "ACTIVITY_RESUMED";
        break;
    case AGR_PHYS_PHASE_SURFACE_CHANGED:
        if (sample->created_count > 0 && sample->changed_count > 0) return "SURFACE_READY";
        break;
    case AGR_PHYS_PHASE_THREAD_RUN_ENTER: return "GAME_THREAD_RUNNING";
    case AGR_PHYS_PHASE_CANVAS_LOCK_BEGIN:
    case AGR_PHYS_PHASE_CANVAS_LOCK_ACQUIRED: return "DRAW_OBSERVING";
    case AGR_PHYS_PHASE_DRAW_BITMAP_END:
    case AGR_PHYS_PHASE_PIXEL_MUTATION: return "CONTENT_PRODUCED";
    case AGR_PHYS_PHASE_CANVAS_POST_END: return "CONTENT_POSTED";
    case AGR_PHYS_PHASE_RUNTIME_ERROR: return "RUNTIME_ERROR";
    case AGR_PHYS_PHASE_WATCHDOG_STALL:
    case AGR_PHYS_PHASE_WATCHDOG_NO_PROGRESS_8S: return "WATCHDOG_STALL";
    case AGR_PHYS_PHASE_EVIDENCE_CHANNEL_FAILED: return "EVIDENCE_CHANNEL_FAILED";
    case AGR_PHYS_PHASE_FINALIZE_END:
        if (strcmp(sample->detail, "WATCHDOG_STALL") == 0) return "WATCHDOG_STALL";
        if (strcmp(sample->detail, "RUNTIME_ERROR") == 0) return "RUNTIME_ERROR";
        if (strcmp(sample->detail, "NATIVE_SIGNAL_CRASH") == 0) return "NATIVE_SIGNAL_CRASH";
        if (strcmp(sample->detail, "EVIDENCE_CHANNEL_FAILED") == 0) return "EVIDENCE_CHANNEL_FAILED";
        return "FINALIZED";
    default: break;
    }
    return NULL;
}

static void note_unlocked(const agr_forensic_sample *sample) {
    agr_forensic_sample clean = *sample;
    const char *state;
    clean.class_name[sizeof(clean.class_name) - 1] = 0;
    clean.method_name[sizeof(clean.method_name) - 1] = 0;
    clean.detail[sizeof(clean.detail) - 1] = 0;
    copy_text(clean.class_name, sizeof(clean.class_name), sample->class_name);
    copy_text(clean.method_name, sizeof(clean.method_name), sample->method_name);
    copy_text(clean.detail, sizeof(clean.detail), sample->detail);
    store_ownership(&clean);
    commit_line_fixed(&clean);
    state = state_for_sample(&clean);
    if (state && strcmp(state, g_state) != 0) write_run_file(state);
}

/* Drain the bounded passive queue only on recorder-owned paths. Producers
   never wait for the main recorder lock and never perform file I/O. */
static void drain_passive_unlocked(void) {
    for (;;) {
        agr_forensic_sample sample;
        pthread_mutex_lock(&g_passive_mu);
        if (g_passive_count == 0) {
            pthread_mutex_unlock(&g_passive_mu);
            break;
        }
        sample = g_passive_ring[g_passive_head];
        g_passive_head = (g_passive_head + 1u) % PASSIVE_RING_CAP;
        g_passive_count--;
        pthread_mutex_unlock(&g_passive_mu);
        if (g_active && !g_finished) note_unlocked(&sample);
    }
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
        drain_passive_unlocked();
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

static int file_contains(const char *path, const char *needle) {
    FILE *fp;
    char buf[4096];
    size_t nlen;
    size_t keep = 0;
    if (!path || !needle || !needle[0]) return 0;
    fp = fopen(path, "r");
    if (!fp) return 0;
    nlen = strlen(needle);
    while (keep < sizeof(buf)) {
        size_t n = fread(buf + keep, 1, sizeof(buf) - 1 - keep, fp);
        if (n == 0) break;
        keep += n;
        buf[keep] = 0;
        if (strstr(buf, needle)) {
            fclose(fp);
            return 1;
        }
        if (keep > nlen) {
            memmove(buf, buf + keep - nlen, nlen);
            keep = nlen;
        }
    }
    fclose(fp);
    return 0;
}

static int crash_marker_valid(const char *path) {
    FILE *fp;
    struct crash_image image;
    fp = fopen(path, "rb");
    if (!fp) return 0;
    if (fread(&image, 1, sizeof(image), fp) != sizeof(image)) {
        fclose(fp);
        return 0;
    }
    fclose(fp);
    return memcmp(image.magic, AGR_PHYSICAL_CRASH_MAGIC, 8) == 0 && image.signal_number != 0;
}

/* Return the earliest observed public failure in the append-only trace.
   Later empty posts or finalization state must not erase the first fault. */
static const char *first_trace_failure(const char *path) {
    FILE *fp = fopen(path, "rb");
    char line[LINE_CAP];
    if (!fp) return NULL;
    while (fgets(line, sizeof(line), fp)) {
        const char *phase = strstr(line, "\"phase\":\"");
        if (!phase) continue;
        phase += strlen("\"phase\":\"");
        if (strncmp(phase, "BITMAP_SCALE_FAIL\"", 18) == 0) { fclose(fp); return "BITMAP_SCALE_FAIL"; }
        if (strncmp(phase, "SURFACE_CALLBACK_THROW\"", 23) == 0) { fclose(fp); return "CALLBACK_THROW"; }
        if (strncmp(phase, "SURFACE_CALLBACK_EXEC_ERROR\"", 28) == 0) { fclose(fp); return "CALLBACK_EXEC_ERROR"; }
        if (strncmp(phase, "EVIDENCE_CHANNEL_FAILED\"", 24) == 0) { fclose(fp); return "EVIDENCE_CHANNEL_FAILED"; }
        if (strncmp(phase, "WATCHDOG_STALL\"", 15) == 0 ||
            strncmp(phase, "WATCHDOG_NO_PROGRESS_8S\"", 24) == 0) { fclose(fp); return "WATCHDOG_STALL"; }
        if (strncmp(phase, "RUNTIME_ERROR\"", 14) == 0) { fclose(fp); return "RUNTIME_ERROR"; }
        if (strncmp(phase, "ARM_FAULT\"", 10) == 0) { fclose(fp); return "ARM_FAULT"; }
        if (strncmp(phase, "JNI_EXCEPTION\"", 14) == 0) { fclose(fp); return "JNI_EXCEPTION"; }
    }
    fclose(fp);
    return NULL;
}

static int path_exists(const char *path) { return path && access(path, F_OK) == 0; }

static int read_json_string(const char *path, const char *key_name, char *out, size_t cap) {
    FILE *fp;
    char buf[65536];
    char key[96];
    char *p, *q;
    size_t n;
    if (!path || !key_name || !out || cap == 0) return -1;
    out[0] = 0;
    fp = fopen(path, "rb");
    if (!fp) return -1;
    n = fread(buf, 1, sizeof(buf) - 1, fp);
    fclose(fp);
    buf[n] = 0;
    snprintf(key, sizeof(key), "\"%s\"", key_name);
    p = strstr(buf, key);
    if (!p || !(p = strchr(p + strlen(key), ':'))) return -1;
    while (*++p == ' ' || *p == '\t' || *p == '\r' || *p == '\n') {}
    if (*p != '"') return -1;
    q = ++p;
    while (*q && (*q != '"' || (q > p && q[-1] == '\\'))) q++;
    if (*q != '"' || (size_t)(q - p) >= cap) return -1;
    memcpy(out, p, (size_t)(q - p));
    out[q - p] = 0;
    return 0;
}

static int safe_archive_id(const char *id) {
    size_t i;
    if (!id || !id[0] || strlen(id) >= 80) return 0;
    for (i = 0; id[i]; i++) {
        unsigned char c = (unsigned char)id[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
              (c >= '0' && c <= '9') || c == '-' || c == '_')) return 0;
    }
    return 1;
}

static int write_atomic_text(const char *path, const char *text) {
    char temp[900];
    int fd;
    size_t n = text ? strlen(text) : 0;
    snprintf(temp, sizeof(temp), "%s.tmp-%d", path, (int)getpid());
    fd = open(temp, O_CREAT | O_EXCL | O_WRONLY, 0600);
    if (fd < 0) return -1;
    if (write(fd, text, n) != (ssize_t)n || fsync(fd) != 0) {
        close(fd); unlink(temp); return -1;
    }
    if (close(fd) != 0 || rename(temp, path) != 0) { unlink(temp); return -1; }
    return 0;
}

static int files_equal(const char *a, const char *b) {
    FILE *fa = fopen(a, "rb"), *fb = fopen(b, "rb");
    unsigned char ba[8192], bb[8192];
    int equal = 1;
    if (!fa || !fb) { if (fa) fclose(fa); if (fb) fclose(fb); return 0; }
    for (;;) {
        size_t na = fread(ba, 1, sizeof(ba), fa), nb = fread(bb, 1, sizeof(bb), fb);
        if (na != nb || memcmp(ba, bb, na) != 0) { equal = 0; break; }
        if (na == 0) break;
    }
    if (ferror(fa) || ferror(fb)) equal = 0;
    fclose(fa); fclose(fb);
    return equal;
}

static int identity_matches_if_present(const char *path, const char *key, const char *expected) {
    char value[160];
    if (!expected || !expected[0] || !path_exists(path)) return 1;
    if (read_json_string(path, key, value, sizeof(value)) != 0) return 1;
    return strcmp(value, expected) == 0;
}

static int source_identities_consistent(const char *dir, int current, const char *run_id) {
    const char *names[4] = {
        current ? RUN_NAME : LEGACY_RUN_NAME,
        current ? TRACE_NAME : LEGACY_TRACE_NAME,
        current ? FINAL_NAME : LEGACY_FINAL_NAME,
        current ? CRASH_NAME : LEGACY_CRASH_NAME
    };
    char paths[4][700];
    char launch[160] = "", commit[160] = "", tree[160] = "", apk[160] = "";
    size_t i;
    for (i = 0; i < 4; i++) snprintf(paths[i], sizeof(paths[i]), "%s/%s", dir, names[i]);
    if (read_json_string(paths[0], "process_launch_id", launch, sizeof(launch)) != 0) launch[0] = 0;
    if (read_json_string(paths[0], "commit", commit, sizeof(commit)) != 0) commit[0] = 0;
    if (read_json_string(paths[0], "tree", tree, sizeof(tree)) != 0) tree[0] = 0;
    if (read_json_string(paths[0], "apk_sha256_expected", apk, sizeof(apk)) != 0) apk[0] = 0;
    for (i = 0; i < 4; i++) {
        if (!identity_matches_if_present(paths[i], "run_id", run_id) ||
            !identity_matches_if_present(paths[i], "process_launch_id", launch) ||
            !identity_matches_if_present(paths[i], "commit", commit) ||
            !identity_matches_if_present(paths[i], "tree", tree)) return 0;
        if (i != 0 && !identity_matches_if_present(paths[i], "apk_sha256", apk) &&
            !identity_matches_if_present(paths[i], "apk_sha256_expected", apk)) return 0;
    }
    return 1;
}

static int write_archive_manifest(const char *dest, const char *id, const char *family,
                                  const char *state, const char *classification,
                                  const char *run_name, const char *trace_name,
                                  const char *final_name, const char *crash_name) {
    char path[900], run_path[900], final_path[900], body[4096], run_json[112], termination[96] = "";
    char termination_json[112];
    char launch[96] = "", commit[96] = "", tree[96] = "", apk[96] = "";
    const char *names[4] = {PREVIOUS_RUN_NAME, PREVIOUS_TRACE_NAME, PREVIOUS_FINAL_NAME, PREVIOUS_CRASH_NAME};
    char states[4][16];
    char hash_json[4][80];
    char hash[65];
    long long sizes[4] = {0, 0, 0, 0};
    struct stat st;
    size_t i;
    (void)trace_name; (void)final_name; (void)crash_name;
    if (strncmp(id, "unidentified-", 13) == 0) snprintf(run_json, sizeof(run_json), "null");
    else snprintf(run_json, sizeof(run_json), "\"%s\"", id);
    snprintf(run_path, sizeof(run_path), "%s/%s", dest, PREVIOUS_RUN_NAME);
    if (!path_exists(run_path)) snprintf(run_path, sizeof(run_path), "%s/%s", dest, run_name);
    snprintf(final_path, sizeof(final_path), "%s/%s", dest, PREVIOUS_FINAL_NAME);
    if (read_json_string(final_path, "termination_reason", termination, sizeof(termination)) != 0 || !termination[0]) {
        if (read_json_string(run_path, "termination_reason", termination, sizeof(termination)) != 0)
            termination[0] = 0;
    }
    if (termination[0]) snprintf(termination_json, sizeof(termination_json), "\"%s\"", termination);
    else snprintf(termination_json, sizeof(termination_json), "null");
    (void)read_json_string(run_path, "process_launch_id", launch, sizeof(launch));
    (void)read_json_string(run_path, "commit", commit, sizeof(commit));
    (void)read_json_string(run_path, "tree", tree, sizeof(tree));
    (void)read_json_string(run_path, "apk_sha256_expected", apk, sizeof(apk));
    for (i = 0; i < 4; i++) {
        snprintf(path, sizeof(path), "%s/%s", dest, names[i]);
        if (stat(path, &st) == 0) {
            snprintf(states[i], sizeof(states[i]), "present");
            sizes[i] = (long long)st.st_size;
            snprintf(hash_json[i], sizeof(hash_json[i]), "null");
            if (agr_physical_sha256_file && agr_physical_sha256_file(path, hash, sizeof(hash)) == 0)
                snprintf(hash_json[i], sizeof(hash_json[i]), "\"%s\"", hash);
        } else {
            snprintf(states[i], sizeof(states[i]), "missing");
            snprintf(hash_json[i], sizeof(hash_json[i]), "null");
        }
    }
    snprintf(body, sizeof(body),
        "{\"schema\":\"agr.physical-manifest.v1\",\"archive_id\":\"%s\",\"run_id\":%s,\"process_launch_id\":\"%s\","
        "\"commit\":\"%s\",\"tree\":\"%s\",\"apk_sha256\":\"%s\",\"source_family\":\"%s\","
        "\"archive_state\":\"%s\",\"classification\":\"%s\",\"termination_reason\":%s,\"files\":{"
        "\"run\":{\"name\":\"%s\",\"state\":\"%s\",\"size\":%lld,\"sha256\":%s},"
        "\"trace\":{\"name\":\"%s\",\"state\":\"%s\",\"size\":%lld,\"sha256\":%s},"
        "\"runtime\":{\"name\":\"%s\",\"state\":\"%s\",\"size\":%lld,\"sha256\":%s},"
        "\"crash\":{\"name\":\"%s\",\"state\":\"%s\",\"size\":%lld,\"sha256\":%s}}}\n",
        id, run_json, launch, commit, tree, apk, family, state, classification, termination_json,
        PREVIOUS_RUN_NAME, states[0], sizes[0], hash_json[0],
        PREVIOUS_TRACE_NAME, states[1], sizes[1], hash_json[1],
        PREVIOUS_FINAL_NAME, states[2], sizes[2], hash_json[2],
        PREVIOUS_CRASH_NAME, states[3], sizes[3], hash_json[3]);
    snprintf(path, sizeof(path), "%s/%s", dest, ARCHIVE_MANIFEST_NAME);
    return write_atomic_text(path, body);
}

static int archive_previous(void) {
    static const char *current_src[] = {RUN_NAME, TRACE_NAME, FINAL_NAME, CRASH_NAME};
    static const char *legacy_src[] = {LEGACY_RUN_NAME, LEGACY_TRACE_NAME, LEGACY_FINAL_NAME, LEGACY_CRASH_NAME};
    static const char *dst_names[] = {PREVIOUS_RUN_NAME, PREVIOUS_TRACE_NAME, PREVIOUS_FINAL_NAME, PREVIOUS_CRASH_NAME};
    char prev[640], pending[640], pending_body[160], id[96] = "", family[16] = "";
    char run_path[640], dest[800], manifest_path[900], index_path[900], index_line[256];
    int has_current = 0, has_legacy = 0, use_current, i;
    snprintf(prev, sizeof(prev), "%s/previous", g_dir);
    snprintf(pending, sizeof(pending), "%s/%s", g_dir, ARCHIVE_PENDING_NAME);
    mkdir(prev, 0755);
    if (path_exists(pending)) {
        FILE *fp = fopen(pending, "r");
        if (!fp || fscanf(fp, "%95s %15s", id, family) != 2) { if (fp) fclose(fp); return -1; }
        fclose(fp);
        if (!safe_archive_id(id) || (strcmp(family, "current") && strcmp(family, "legacy"))) return -1;
        use_current = strcmp(family, "current") == 0;
    } else {
        for (i = 0; i < 4; i++) {
            char p[640];
            snprintf(p, sizeof(p), "%s/%s", g_dir, current_src[i]); has_current |= path_exists(p);
            snprintf(p, sizeof(p), "%s/%s", g_dir, legacy_src[i]); has_legacy |= path_exists(p);
        }
        {
            char p[640];
            snprintf(p, sizeof(p), "%s/%s", g_dir, CURRENT_MANIFEST_NAME);
            has_current |= path_exists(p);
        }
        if (!has_current && !has_legacy) return 0;
        if (has_current && has_legacy) return -1; /* Never mix generations. */
        use_current = has_current;
        snprintf(family, sizeof(family), "%s", use_current ? "current" : "legacy");
        snprintf(run_path, sizeof(run_path), "%s/%s", g_dir,
                 use_current ? current_src[0] : legacy_src[0]);
        if (read_run_id(run_path, id, sizeof(id)) != 0)
            snprintf(id, sizeof(id), "unidentified-%d-%llu", (int)getpid(),
                     (unsigned long long)mono_ns());
        if (!safe_archive_id(id)) return -1;
        if (!source_identities_consistent(g_dir, use_current, id)) return -1;
        snprintf(pending_body, sizeof(pending_body), "%s %s\n", id, family);
        if (write_atomic_text(pending, pending_body) != 0) return -1;
    }
    snprintf(family, sizeof(family), "%s", use_current ? "current" : "legacy");
    snprintf(dest, sizeof(dest), "%s/%s", prev, id);
    if (!path_exists(dest)) {
        if (mkdir(dest, 0755) != 0) return -1;
        if (write_archive_manifest(dest, id, family, "IN_PROGRESS", "UNCLASSIFIED",
                                   use_current ? current_src[0] : legacy_src[0],
                                   use_current ? current_src[1] : legacy_src[1],
                                   use_current ? current_src[2] : legacy_src[2],
                                   use_current ? current_src[3] : legacy_src[3]) != 0) return -1;
    } else {
        snprintf(manifest_path, sizeof(manifest_path), "%s/%s", dest, ARCHIVE_MANIFEST_NAME);
        if (!path_exists(manifest_path)) return -1;
        if (file_contains(manifest_path, "\"archive_state\":\"ARCHIVED\"")) {
            snprintf(index_path, sizeof(index_path), "%s/%s", prev, ARCHIVE_INDEX_NAME);
            if (!file_contains(index_path, id)) {
                int fd;
                if (strncmp(id, "unidentified-", 13) == 0)
                    snprintf(index_line, sizeof(index_line), "{\"run_id\":null,\"archive_id\":\"%s\",\"state\":\"ARCHIVED\"}\n", id);
                else
                    snprintf(index_line, sizeof(index_line), "{\"run_id\":\"%s\",\"archive_id\":\"%s\",\"state\":\"ARCHIVED\"}\n", id, id);
                fd = open(index_path, O_CREAT | O_APPEND | O_WRONLY, 0600);
                if (fd < 0) return -1;
                if (write(fd, index_line, strlen(index_line)) != (ssize_t)strlen(index_line) || fsync(fd) != 0) { close(fd); return -1; }
                close(fd);
            }
            return unlink(pending) == 0 ? 0 : -1;
        }
        if (!file_contains(manifest_path, "\"archive_state\":\"IN_PROGRESS\"")) return -1;
    }
    for (i = 1; i < 4; i++) { /* Keep the identity-bearing run file until last. */
        char from[700], to[900];
        const char *src = use_current ? current_src[i] : legacy_src[i];
        snprintf(from, sizeof(from), "%s/%s", g_dir, src);
        snprintf(to, sizeof(to), "%s/%s", dest, dst_names[i]);
        if (!path_exists(from)) continue;
        if (path_exists(to)) {
            if (!files_equal(from, to) || unlink(from) != 0) return -1;
        } else if (rename(from, to) != 0) return -1;
    }
    {
        char from[700], to[900];
        snprintf(from, sizeof(from), "%s/%s", g_dir, use_current ? current_src[0] : legacy_src[0]);
        snprintf(to, sizeof(to), "%s/%s", dest, dst_names[0]);
        if (path_exists(from)) {
            if (path_exists(to)) {
                if (!files_equal(from, to) || unlink(from) != 0) return -1;
            } else if (rename(from, to) != 0) return -1;
        }
    }
    {
        char from[700], to[900];
        snprintf(from, sizeof(from), "%s/%s", g_dir, CURRENT_MANIFEST_NAME);
        snprintf(to, sizeof(to), "%s/agr-prev-manifest.json", dest);
        if (path_exists(from)) {
            if (path_exists(to)) {
                if (!files_equal(from, to) || unlink(from) != 0) return -1;
            } else if (rename(from, to) != 0) return -1;
        }
    }
    {
        char trace_path[900], crash_path[900], final_path[900], run_dest[900];
        char classification[96] = "ABRUPT_TERMINATION", reason[96] = "";
        const char *first_failure;
        snprintf(trace_path, sizeof(trace_path), "%s/%s", dest, PREVIOUS_TRACE_NAME);
        snprintf(crash_path, sizeof(crash_path), "%s/%s", dest, PREVIOUS_CRASH_NAME);
        snprintf(final_path, sizeof(final_path), "%s/%s", dest, PREVIOUS_FINAL_NAME);
        snprintf(run_dest, sizeof(run_dest), "%s/%s", dest, PREVIOUS_RUN_NAME);
        first_failure = first_trace_failure(trace_path);
        if (first_failure) copy_text(classification, sizeof(classification), first_failure);
        else if (crash_marker_valid(crash_path)) snprintf(classification, sizeof(classification), "NATIVE_SIGNAL_CRASH");
        else if (file_contains(trace_path, "WATCHDOG_STALL")) snprintf(classification, sizeof(classification), "WATCHDOG_STALL");
        else if (read_json_string(final_path, "termination_reason", reason, sizeof(reason)) == 0 && reason[0])
            copy_text(classification, sizeof(classification), reason);
        else if (read_json_string(run_dest, "termination_reason", reason, sizeof(reason)) == 0 && reason[0])
            copy_text(classification, sizeof(classification), reason);
        if (write_archive_manifest(dest, id, family, "ARCHIVED", classification,
                                   use_current ? current_src[0] : legacy_src[0],
                                   use_current ? current_src[1] : legacy_src[1],
                                   use_current ? current_src[2] : legacy_src[2],
                                   use_current ? current_src[3] : legacy_src[3]) != 0) return -1;
    }
    snprintf(index_path, sizeof(index_path), "%s/%s", prev, ARCHIVE_INDEX_NAME);
    if (!file_contains(index_path, id)) {
        int fd;
        if (strncmp(id, "unidentified-", 13) == 0)
            snprintf(index_line, sizeof(index_line), "{\"run_id\":null,\"archive_id\":\"%s\",\"state\":\"ARCHIVED\"}\n", id);
        else
            snprintf(index_line, sizeof(index_line), "{\"run_id\":\"%s\",\"archive_id\":\"%s\",\"state\":\"ARCHIVED\"}\n", id, id);
        fd = open(index_path, O_CREAT | O_APPEND | O_WRONLY, 0600);
        if (fd < 0) return -1;
        if (write(fd, index_line, strlen(index_line)) != (ssize_t)strlen(index_line) || fsync(fd) != 0) { close(fd); return -1; }
        close(fd);
    }
    if (unlink(pending) != 0) return -1;
    return 0;
}

static int write_current_manifest(void) {
    const char *names[4] = {RUN_NAME, TRACE_NAME, FINAL_NAME, CRASH_NAME};
    const char *keys[4] = {"run", "trace", "runtime", "crash"};
    char body[4096], path[800], run_path[800], launch[96] = "";
    char hashes[4][80], states[4][24], hash[65];
    long long sizes[4] = {0, 0, 0, 0};
    struct stat st;
    size_t i;
    int n;
    int complete;
    snprintf(run_path, sizeof(run_path), "%s/%s", g_dir, RUN_NAME);
    (void)read_json_string(run_path, "process_launch_id", launch, sizeof(launch));
    for (i = 0; i < 4; i++) {
        snprintf(path, sizeof(path), "%s/%s", g_dir, names[i]);
        hashes[i][0] = 0;
        if (stat(path, &st) == 0) {
            sizes[i] = (long long)st.st_size;
            snprintf(states[i], sizeof(states[i]), (i <= 1 || i == 3) && g_active && !g_finished
                     ? "WRITING" : "PRESENT");
            snprintf(hashes[i], sizeof(hashes[i]), "null");
            if (agr_physical_sha256_file && agr_physical_sha256_file(path, hash, sizeof(hash)) == 0)
                snprintf(hashes[i], sizeof(hashes[i]), "\"%s\"", hash);
        } else {
            snprintf(states[i], sizeof(states[i]), i == 3 ? "OPTIONAL_ABSENT" : "NOT_GENERATED");
            snprintf(hashes[i], sizeof(hashes[i]), "null");
        }
    }
    complete = strcmp(states[0], "PRESENT") == 0 && strcmp(states[1], "PRESENT") == 0 &&
               strcmp(states[2], "PRESENT") == 0;
    n = snprintf(body, sizeof(body),
        "{\"schema\":\"agr.physical-manifest.v1\",\"run_id\":\"%s\",\"process_launch_id\":\"%s\","
        "\"commit\":\"%s\",\"tree\":\"%s\",\"apk_sha256\":\"%s\",\"archive_state\":\"CURRENT\",\"evidence_complete\":%s,\"files\":{"
        "\"%s\":{\"name\":\"%s\",\"state\":\"%s\",\"size\":%lld,\"sha256\":%s},"
        "\"%s\":{\"name\":\"%s\",\"state\":\"%s\",\"size\":%lld,\"sha256\":%s},"
        "\"%s\":{\"name\":\"%s\",\"state\":\"%s\",\"size\":%lld,\"sha256\":%s},"
        "\"%s\":{\"name\":\"%s\",\"state\":\"%s\",\"size\":%lld,\"sha256\":%s}}}\n",
        g_run_id, launch, g_commit, g_tree, g_apk_actual[0] ? g_apk_actual : g_apk_sha,
        complete ? "true" : "false",
        keys[0], names[0], states[0], sizes[0], hashes[0],
        keys[1], names[1], states[1], sizes[1], hashes[1],
        keys[2], names[2], states[2], sizes[2], hashes[2],
        keys[3], names[3], states[3], sizes[3], hashes[3]);
    if (n < 0 || (size_t)n >= sizeof(body)) return -1;
    snprintf(path, sizeof(path), "%s/%s", g_dir, CURRENT_MANIFEST_NAME);
    return write_atomic_text(path, body);
}

static void make_run_id(void) {
    uint64_t a = mono_ns();
    uint64_t b = ((uint64_t)getpid() << 32) ^ (uint64_t)time(NULL);
    snprintf(g_run_id, sizeof(g_run_id), "%016llx%016llx",
             (unsigned long long)a, (unsigned long long)b);
    snprintf(g_launch_id, sizeof(g_launch_id), "p%u-%016llx",
             (unsigned)getpid(), (unsigned long long)(a ^ 0xA6A6A6A6A6A6A6A6ull));
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
    if (archive_previous() != 0) {
        pthread_mutex_unlock(&g_mu);
        return -1;
    }
    path_join(path, sizeof(path), FINAL_NAME);
    unlink(path);
    make_run_id();
    g_seq = SEQ_ORIGIN - 1ull;
    g_runtime_seq = 0;
    g_last_progress_ns = mono_ns();
    g_max_gap_ns = 0;
    g_event_count = 0;
    g_passive_dropped = 0;
    __atomic_store_n(&g_passive_enabled, 0, __ATOMIC_RELEASE);
    pthread_mutex_lock(&g_passive_mu);
    g_passive_head = g_passive_tail = g_passive_count = 0;
    g_passive_order = 0;
    pthread_mutex_unlock(&g_passive_mu);
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
    g_env_set = 0;
    g_env_json[0] = 0;
    g_env_end_set = 0;
    g_env_end_json[0] = 0;
    g_env_changed = 0;
    g_env_changes_json[0] = 0;
    capture_process_identity();
    g_life[0] = 0;
    g_foreground = 0;
    g_app_active = 0;
    g_apk_actual[0] = 0;
    g_boundary[0] = 0;
    g_last_error[0] = 0;
    g_obs_start = 0;
    g_obs_deadline = 0;
    g_obs_end = 0;
    g_obs_frames = 0;
    g_obs_reason[0] = 0;
    g_bin_count = 0;
    memset(&g_crash, 0, sizeof(g_crash));
    memcpy(g_crash.magic, AGR_PHYSICAL_CRASH_MAGIC, 8);
    g_crash.version = AGR_PHYSICAL_CRASH_VERSION;
    g_crash_seq = 0;
    write_run_file("PROCESS_STARTED");
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
    __atomic_store_n(&g_passive_enabled, 1, __ATOMIC_RELEASE);
    memset(&launch, 0, sizeof(launch));
    launch.critical = 1;
    launch.host_thread = (uint64_t)pthread_self();
    launch.phase = AGR_PHYS_PHASE_EVIDENCE_RESET_BEGIN;
    note_unlocked(&launch);
    launch.phase = AGR_PHYS_PHASE_EVIDENCE_RESET_OK;
    note_unlocked(&launch);
    launch.phase = AGR_PHYS_PHASE_RUN_ID_CREATED;
    note_unlocked(&launch);
    launch.phase = AGR_PHYS_PHASE_RUN_FILE_WRITTEN;
    note_unlocked(&launch);
    launch.phase = AGR_PHYS_PHASE_TRACE_OPENED;
    note_unlocked(&launch);
    launch.phase = AGR_PHYS_PHASE_APP_LAUNCH_BEGIN;
    note_unlocked(&launch);
    launch.phase = AGR_PHYS_PHASE_TRACE_READY;
    note_unlocked(&launch);
    write_run_file("EVIDENCE_READY");
    if (write_current_manifest() != 0) {
        g_active = 0;
        pthread_mutex_unlock(&g_mu);
        return -1;
    }
    pthread_mutex_unlock(&g_mu);
    install_signals();
    if (pthread_create(&g_watchdog, NULL, watchdog_main, NULL) == 0)
        g_watchdog_started = 1;
    return 0;
}

void agr_forensic_publish(const agr_forensic_sample *sample) {
    if (!sample) return;
    pthread_mutex_lock(&g_mu);
    if (g_active && !g_finished) {
        drain_passive_unlocked();
        note_unlocked(sample);
    }
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

int agr_physical_trace_refresh_manifest(void) {
    int rc;
    pthread_mutex_lock(&g_mu);
    rc = write_current_manifest();
    pthread_mutex_unlock(&g_mu);
    return rc;
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
        __atomic_store_n(&g_passive_enabled, 0, __ATOMIC_RELEASE);
        drain_passive_unlocked();
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
        if (strcmp(g_reason, "RUNTIME_ERROR") == 0 ||
            strcmp(g_reason, "WATCHDOG_STALL") == 0 ||
            strcmp(g_reason, "NATIVE_SIGNAL_CRASH") == 0 ||
            strcmp(g_reason, "EVIDENCE_CHANNEL_FAILED") == 0)
            write_run_file(g_reason);
        else
            write_run_file("FINALIZED");
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

int agr_physical_trace_set_environment_json(const char *json) {
    size_t n;
    int rc = 0;
    pthread_mutex_lock(&g_mu);
    if (!json || json[0] != '{') {
        g_env_set = 0;
        g_env_json[0] = 0;
        rc = -1;
    } else {
        n = strlen(json);
        if (n + 1 >= sizeof(g_env_json)) {
            rc = -1;
        } else {
            memcpy(g_env_json, json, n + 1);
            g_env_set = 1;
        }
    }
    if (g_active && !g_finished) write_run_file(g_state[0] ? g_state : "ENVIRONMENT_CAPTURED");
    pthread_mutex_unlock(&g_mu);
    return rc;
}

void agr_forensic_publish_passive(const agr_forensic_sample *sample) {
    agr_forensic_sample queued;
    if (!sample) return;
    if (!__atomic_load_n(&g_passive_enabled, __ATOMIC_ACQUIRE)) return;
    if (pthread_mutex_trylock(&g_passive_mu) != 0) {
        __atomic_add_fetch(&g_passive_dropped, 1, __ATOMIC_RELAXED);
        return;
    }
    if (!__atomic_load_n(&g_passive_enabled, __ATOMIC_ACQUIRE) ||
        g_passive_count >= PASSIVE_RING_CAP) {
        pthread_mutex_unlock(&g_passive_mu);
        __atomic_add_fetch(&g_passive_dropped, 1, __ATOMIC_RELAXED);
        return;
    }
    queued = *sample;
    queued.passive_order = ++g_passive_order;
    g_passive_ring[g_passive_tail] = queued;
    g_passive_tail = (g_passive_tail + 1u) % PASSIVE_RING_CAP;
    g_passive_count++;
    pthread_mutex_unlock(&g_passive_mu);
}

int agr_physical_trace_set_environment_end_json(const char *json, const char *changes_json) {
    size_t n;
    size_t changes_n;
    int rc = 0;
    pthread_mutex_lock(&g_mu);
    if (!json || json[0] != '{') {
        g_env_end_set = 0;
        g_env_end_json[0] = 0;
        rc = -1;
    } else {
        n = strlen(json);
        if (n + 1 >= sizeof(g_env_end_json)) rc = -1;
        else {
            memcpy(g_env_end_json, json, n + 1);
            g_env_end_set = 1;
        }
    }
    changes_n = changes_json ? strlen(changes_json) : 0;
    if (changes_n > 1 && changes_json[0] == '[' && changes_json[changes_n - 1] == ']' &&
        changes_n < sizeof(g_env_changes_json)) {
        memcpy(g_env_changes_json, changes_json, changes_n + 1);
        g_env_changed = strcmp(g_env_changes_json, "[]") != 0;
    } else {
        memcpy(g_env_changes_json, "[]", 3);
        g_env_changed = 0;
    }
    if (g_active && !g_finished) write_run_file(g_state[0] ? g_state : "ENVIRONMENT_CAPTURED");
    pthread_mutex_unlock(&g_mu);
    return rc;
}

void agr_physical_trace_set_lifecycle(const char *state, int foreground, int active) {
    pthread_mutex_lock(&g_mu);
    copy_text(g_life, sizeof(g_life), state ? state : "UNKNOWN");
    g_foreground = foreground ? 1 : 0;
    g_app_active = active ? 1 : 0;
    if (g_active && !g_finished) write_run_file(g_state[0] ? g_state : "EVIDENCE_READY");
    pthread_mutex_unlock(&g_mu);
}

void agr_physical_trace_set_apk_sha_actual(const char *sha256) {
    pthread_mutex_lock(&g_mu);
    copy_text(g_apk_actual, sizeof(g_apk_actual), sha256 ? sha256 : "");
    if (g_active && !g_finished) write_run_file(g_state[0] ? g_state : "APK_OPENED");
    pthread_mutex_unlock(&g_mu);
}

void agr_physical_trace_set_observation(uint64_t start_monotonic, uint64_t deadline,
                                        uint64_t end_monotonic, uint32_t frames,
                                        const char *stop_reason) {
    pthread_mutex_lock(&g_mu);
    g_obs_start = start_monotonic;
    g_obs_deadline = deadline;
    g_obs_end = end_monotonic;
    g_obs_frames = frames;
    copy_text(g_obs_reason, sizeof(g_obs_reason), stop_reason ? stop_reason : "");
    if (g_active && !g_finished) write_run_file(g_state[0] ? g_state : "DRAW_OBSERVING");
    pthread_mutex_unlock(&g_mu);
}

void agr_physical_trace_add_binary(const char *role, const char *uuid, const char *sha256) {
    int i;
    pthread_mutex_lock(&g_mu);
    for (i = 0; i < g_bin_count; i++) {
        if (strcmp(g_bin[i].role, role ? role : "") == 0) break;
    }
    if (i >= BIN_CAP) {
        pthread_mutex_unlock(&g_mu);
        return;
    }
    if (i == g_bin_count) g_bin_count++;
    copy_text(g_bin[i].role, sizeof(g_bin[i].role), role ? role : "");
    copy_text(g_bin[i].uuid, sizeof(g_bin[i].uuid), uuid ? uuid : "");
    copy_text(g_bin[i].sha, sizeof(g_bin[i].sha), sha256 ? sha256 : "");
    if (g_active && !g_finished) write_run_file(g_state[0] ? g_state : "EVIDENCE_READY");
    pthread_mutex_unlock(&g_mu);
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
    sample.phase = AGR_PHYS_PHASE_EVIDENCE_CHANNEL_FAILED;
    note_unlocked(&sample);
    copy_text(g_reason, sizeof(g_reason), "EVIDENCE_CHANNEL_FAILED");
    write_run_file("EVIDENCE_CHANNEL_FAILED");
    pthread_mutex_unlock(&g_mu);
}

void agr_physical_trace_shutdown(void) {
    int started;
    pthread_mutex_lock(&g_mu);
    __atomic_store_n(&g_passive_enabled, 0, __ATOMIC_RELEASE);
    drain_passive_unlocked();
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
