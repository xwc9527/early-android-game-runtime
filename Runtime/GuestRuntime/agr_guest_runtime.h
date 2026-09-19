#ifndef AGR_GUEST_RUNTIME_H
#define AGR_GUEST_RUNTIME_H

#include <stddef.h>
#include <stdint.h>
#include "../Ehabi/agr_ehabi.h"

#ifdef __cplusplus
extern "C" {
#endif

/* agr_guest remains the public ABI spelling. The owned object is formally a
 * ProcessRuntime; every GuestThreadContext refers back to this instance. */
typedef struct agr_process_runtime agr_process_runtime;
typedef agr_process_runtime agr_guest;
typedef struct agr_apk_package agr_apk_package;

enum {
    AGR_ARRAY_SHORT = 1,
    AGR_ARRAY_INT = 2,
    AGR_ARRAY_FLOAT = 3,
};

agr_guest *agr_guest_create(void);
void agr_guest_destroy(agr_guest *guest);
const char *agr_guest_last_error(agr_guest *guest);
const char *agr_guest_last_android_log(agr_guest *guest);
uint32_t agr_guest_program_counter(agr_guest *guest);

int32_t agr_guest_load_elf(agr_guest *guest, const char *name,
                           const void *bytes, uint32_t size, uint32_t base);
int32_t agr_guest_load_elf_handle(agr_guest *guest, const char *name,
                                  const void *bytes, uint32_t size, uint32_t base,
                                  uint32_t *object_handle);
int32_t agr_guest_register_elf_source(agr_guest *guest, const char *name,
                                      const void *bytes, uint32_t size);
uint32_t agr_guest_dlopen(agr_guest *guest, const char *name);
int32_t agr_guest_load_java_library(agr_guest *guest, const char *name,
                                    int32_t *jni_version);
uint32_t agr_guest_dlsym(agr_guest *guest, uint32_t object_handle,
                         const char *symbol);
int32_t agr_guest_dlclose(agr_guest *guest, uint32_t object_handle);
uint32_t agr_guest_find_symbol(agr_guest *guest, const char *symbol);
void agr_guest_set_watch_pc(agr_guest *guest, uint32_t pc);
uint32_t agr_guest_watch_hits(agr_guest *guest);
uint32_t agr_guest_watch_reg(agr_guest *guest, uint32_t reg);
uint32_t agr_guest_watch_cpsr(agr_guest *guest);
int32_t agr_guest_watch_trace(agr_guest *guest, uint32_t index,
                              uint32_t *pc, uint32_t *instruction);
uint32_t agr_guest_current_thread_id(agr_guest *guest);
void agr_guest_heap_diagnostics(agr_guest *guest, uint32_t out_values[5]);
uint32_t agr_guest_new_primitive_array(agr_guest *guest, uint32_t kind,
                                       const void *bytes, uint32_t count);
int32_t agr_guest_call_symbol(agr_guest *guest, const char *symbol,
                              const uint32_t *arguments, uint32_t argument_count,
                              int32_t *result);
int32_t agr_guest_call_address(agr_guest *guest, uint32_t address,
                               const uint32_t *arguments, uint32_t argument_count,
                               int32_t *result);
int32_t agr_guest_run_constructors(agr_guest *guest, uint32_t *executed);
int32_t agr_guest_run_constructors_limit(agr_guest *guest, uint32_t limit, uint32_t *executed);
void agr_guest_set_instruction_budget(agr_guest *guest, uint64_t instructions);
uint32_t agr_guest_alloc(agr_guest *guest, const void *bytes, uint32_t size, uint32_t alignment);
int32_t agr_guest_read(agr_guest *guest, uint32_t address, void *bytes, uint32_t size);
int32_t agr_guest_write(agr_guest *guest, uint32_t address, const void *bytes, uint32_t size);
uint32_t agr_guest_jni_env(agr_guest *guest);
uint32_t agr_guest_java_vm(agr_guest *guest);
int32_t agr_guest_mount_apk(agr_guest *guest, const char *path);
int32_t agr_guest_load_dex(agr_guest *guest, const char *path);
int32_t agr_guest_load_dex_package(agr_guest *guest, const agr_apk_package *package);
int32_t agr_guest_start_dex_activity(agr_guest *guest);
int32_t agr_guest_wait_for_swap(agr_guest *guest, uint32_t previous_swap,
                                uint32_t timeout_ms);

int32_t agr_guest_create_gles1_pbuffer(agr_guest *guest, int width, int height);
void agr_guest_setup_gles1_frame(agr_guest *guest);
int32_t agr_guest_read_rgba(agr_guest *guest, void *pixels, uint32_t capacity);
const char *agr_guest_gl_renderer(agr_guest *guest);
const char *agr_guest_gl_version(agr_guest *guest);
uint64_t agr_guest_instruction_count(agr_guest *guest);
uint32_t agr_guest_draw_count(agr_guest *guest);
uint32_t agr_guest_swap_count(agr_guest *guest);
uint32_t agr_guest_asset_open_count(agr_guest *guest);
int32_t agr_guest_inject_motion(agr_guest *guest, int32_t action, float x, float y);
uint32_t agr_guest_input_queue(agr_guest *guest);
uint32_t agr_guest_input_consumed_count(agr_guest *guest);
uint32_t agr_guest_unique_import_count(agr_guest *guest);
const char *agr_guest_unique_import(agr_guest *guest, uint32_t index);
uint32_t agr_guest_recent_call_count(agr_guest *guest);
const char *agr_guest_recent_call(agr_guest *guest, uint32_t index);
uint32_t agr_guest_loaded_module_count(agr_guest *guest);
const char *agr_guest_loaded_module(agr_guest *guest, uint32_t index);

int32_t agr_guest_unwind_backtrace(agr_guest *guest,
                                   agr_guest_unwind_frame *frames,
                                   uint32_t max_frames, uint32_t *count,
                                   const char **stop_reason);

#ifdef __cplusplus
}
#endif
#endif
