#ifndef AGR_FORENSIC_H
#define AGR_FORENSIC_H
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

/* Physical-device forensic channel. Guest code is never called from here.
   Phase ids are stable for agr-physical-crash.bin. */

#define AGR_PHYSICAL_TRACE_SCHEMA "agr.physical-trace.v1"
#define AGR_PHYSICAL_RUN_SCHEMA "agr.physical-run.v1"
#define AGR_PHYSICAL_CRASH_MAGIC "AGRCRSH1"
#define AGR_PHYSICAL_CRASH_VERSION 1u

/* Production watchdog. Tests may compress these intervals.
   Poll 500 ms. No-progress markers at 2s, 5s, and 8s.
   The 8s marker records WATCHDOG_STALL and does not kill the process.
   Heartbeats do not count as Runtime progress. */
#define AGR_PHYSICAL_WATCHDOG_POLL_MS 500u
#define AGR_PHYSICAL_WATCHDOG_GAP_2S_MS 2000u
#define AGR_PHYSICAL_WATCHDOG_GAP_5S_MS 5000u
#define AGR_PHYSICAL_WATCHDOG_GAP_8S_MS 8000u

enum {
    AGR_PHYS_PHASE_NONE = 0,
    AGR_PHYS_PHASE_APP_LAUNCH_BEGIN = 1,
    AGR_PHYS_PHASE_TRACE_READY = 2,
    AGR_PHYS_PHASE_APK_LOCATE_BEGIN = 3,
    AGR_PHYS_PHASE_APK_LOCATE_OK = 4,
    AGR_PHYS_PHASE_APK_LOCATE_FAIL = 5,
    AGR_PHYS_PHASE_APK_SHA_BEGIN = 6,
    AGR_PHYS_PHASE_APK_SHA_OK = 7,
    AGR_PHYS_PHASE_APK_SHA_FAIL = 8,
    AGR_PHYS_PHASE_APK_OPEN_BEGIN = 9,
    AGR_PHYS_PHASE_APK_OPEN_OK = 10,
    AGR_PHYS_PHASE_APK_OPEN_FAIL = 11,
    AGR_PHYS_PHASE_GAME_CREATE_BEGIN = 12,
    AGR_PHYS_PHASE_GAME_CREATE_OK = 13,
    AGR_PHYS_PHASE_GAME_CREATE_FAIL = 14,
    AGR_PHYS_PHASE_DIAGNOSTICS_ENABLED = 15,
    AGR_PHYS_PHASE_HOST_DISPLAY_SET_BEGIN = 16,
    AGR_PHYS_PHASE_HOST_DISPLAY_SET_OK = 17,
    AGR_PHYS_PHASE_HOST_DISPLAY_SET_FAIL = 18,
    AGR_PHYS_PHASE_ACTIVITY_START_BEGIN = 19,
    AGR_PHYS_PHASE_ACTIVITY_START_OK = 20,
    AGR_PHYS_PHASE_ACTIVITY_START_FAIL = 21,
    AGR_PHYS_PHASE_CADISPLAYLINK_CREATED = 22,
    AGR_PHYS_PHASE_CADISPLAYLINK_STARTED = 23,
    AGR_PHYS_PHASE_PHYSICAL_FRAME_BEGIN = 24,
    AGR_PHYS_PHASE_PHYSICAL_FRAME_END = 25,
    AGR_PHYS_PHASE_ACTIVITY_STAGE = 26,
    AGR_PHYS_PHASE_VIEWROOT_ATTACH = 27,
    AGR_PHYS_PHASE_TRAVERSAL_SCHEDULED = 28,
    AGR_PHYS_PHASE_TRAVERSAL_BEGIN = 29,
    AGR_PHYS_PHASE_TRAVERSAL_END = 30,
    AGR_PHYS_PHASE_SURFACE_CREATED = 31,
    AGR_PHYS_PHASE_SURFACE_CHANGED = 32,
    AGR_PHYS_PHASE_THREAD_START = 33,
    AGR_PHYS_PHASE_THREAD_RUN_ENTER = 34,
    AGR_PHYS_PHASE_THREAD_RUN_EXIT = 35,
    AGR_PHYS_PHASE_EXEC_PUBLISHED = 36,
    AGR_PHYS_PHASE_VECTOR_SIZE = 37,
    AGR_PHYS_PHASE_VECTOR_ELEMENT = 38,
    AGR_PHYS_PHASE_CANVAS_LOCK_BEGIN = 39,
    AGR_PHYS_PHASE_CANVAS_LOCK_ACQUIRED = 40,
    AGR_PHYS_PHASE_CANVAS_LOCK_FAILED = 41,
    AGR_PHYS_PHASE_DRAW_BITMAP_BEGIN = 42,
    AGR_PHYS_PHASE_DRAW_BITMAP_END = 43,
    AGR_PHYS_PHASE_PIXEL_MUTATION = 44,
    AGR_PHYS_PHASE_CANVAS_POST_BEGIN = 45,
    AGR_PHYS_PHASE_CANVAS_POST_END = 46,
    AGR_PHYS_PHASE_PENGUIN_SPRITE_PAINT_WITNESS = 47,
    AGR_PHYS_PHASE_RUNTIME_ERROR = 48,
    AGR_PHYS_PHASE_WATCHDOG_HEARTBEAT = 49,
    AGR_PHYS_PHASE_WATCHDOG_NO_PROGRESS_2S = 50,
    AGR_PHYS_PHASE_WATCHDOG_NO_PROGRESS_5S = 51,
    AGR_PHYS_PHASE_WATCHDOG_NO_PROGRESS_8S = 52,
    AGR_PHYS_PHASE_WATCHDOG_STALL = 53,
    AGR_PHYS_PHASE_SNAPSHOT_UNAVAILABLE = 54,
    AGR_PHYS_PHASE_FINALIZE_BEGIN = 55,
    AGR_PHYS_PHASE_FINALIZE_END = 56,
    AGR_PHYS_PHASE_SURFACE_CALLBACK_BEGIN = 57,
    AGR_PHYS_PHASE_SURFACE_CALLBACK_OK = 58,
    AGR_PHYS_PHASE_SURFACE_CALLBACK_THROW = 59,
    AGR_PHYS_PHASE_SURFACE_CALLBACK_EXEC_ERROR = 60,
    AGR_PHYS_PHASE_BITMAP_SCALE_BEGIN = 61,
    AGR_PHYS_PHASE_BITMAP_SCALE_END = 62,
    AGR_PHYS_PHASE_BITMAP_SCALE_FAIL = 63,
    AGR_PHYS_PHASE_GUEST_METHOD_ENTER = 64,
    AGR_PHYS_PHASE_GUEST_METHOD_EXIT = 65
};

/* thread_state: 0 none, 1 STARTING, 2 RUNNING, 3 WAITING, 4 TERMINATED */
typedef struct agr_forensic_sample {
    uint32_t phase;
    int has_exec;
    uint32_t exec_id;
    uint64_t host_thread;
    uint32_t thread_state;
    int canvas_locked;
    uint32_t lock_owner_exec;
    uint32_t lock_count;
    uint32_t unlock_count;
    uint32_t post_count;
    uint32_t draw_bitmap_count;
    uint32_t pixel_change_count;
    uint32_t surface_generation;
    uint64_t surface_identity;
    int surface_valid;
    uint32_t created_count;
    uint32_t changed_count;
    uint32_t counter_before;
    uint32_t counter_after;
    int has_counters;
    char class_name[96];
    char method_name[64];
    char detail[96];
    int critical;
} agr_forensic_sample;

/* Strong definition lives in the physical recorder. VM objects declare it
   weak and skip the call when the recorder is not linked. */
void agr_forensic_publish(const agr_forensic_sample *sample);

typedef struct agr_physical_trace_config {
    const char *directory;
    const char *branch;
    const char *commit;
    const char *tree;
    const char *device_platform;
    const char *architecture;
    const char *apk_sha256_expected;
} agr_physical_trace_config;

typedef struct agr_physical_trace_status {
    char run_id[40];
    uint64_t last_seq;
    uint32_t event_count;
    char last_event[64];
    uint32_t last_phase;
    uint32_t heartbeat_count;
    uint32_t no_progress_level;
    uint64_t max_progress_gap_ms;
    uint64_t progress_age_ms;
    int crash_marker_present;
    int watchdog_stalled;
    char watchdog_state[24];
    char trace_file[64];
    uint32_t root_exec;
    int has_root_exec;
    uint32_t game_exec;
    int has_game_exec;
    uint32_t game_thread_state;
    uint64_t game_host_thread;
    /* Authoritative finish reason. WATCHDOG_STALL replaces a later caller
       reason except CONTENT_POSTED. */
    char termination_reason[64];
} agr_physical_trace_status;

int agr_physical_trace_begin(const agr_physical_trace_config *config);
void agr_physical_trace_event(const agr_forensic_sample *sample);
void agr_physical_trace_publish_ownership(const agr_forensic_sample *sample);
void agr_physical_trace_set_watchdog_for_test(uint32_t poll_ms, uint32_t gap2_ms,
                                               uint32_t gap5_ms, uint32_t gap8_ms);
/* Non-zero means a Runtime lock is busy. The probe must not block, take a
   guest callback, or run Java. Production passes
   agr_dex_game_diagnostic_content_lock_busy. */
void agr_physical_trace_set_lock_probe(int (*probe)(void *user), void *user);
/* Number of trace fsync calls since begin. Repeating render events do not
   increment it after the first checkpoint of that phase. */
uint32_t agr_physical_trace_sync_count(void);
int agr_physical_trace_finish(const char *termination_reason, agr_physical_trace_status *out);
void agr_physical_trace_note_writer_error(const char *detail);
void agr_physical_trace_copy_status(agr_physical_trace_status *out);
void agr_physical_trace_shutdown(void);
const char *agr_physical_phase_name(uint32_t phase);

#ifdef __cplusplus
}
#endif
#endif
