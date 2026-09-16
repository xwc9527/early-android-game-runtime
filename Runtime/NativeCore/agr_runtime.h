#ifndef AGR_RUNTIME_H
#define AGR_RUNTIME_H

#include <stddef.h>
#include <stdint.h>

#if defined(_WIN32)
#define AGR_API __declspec(dllexport)
#else
#define AGR_API __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef int32_t (*agr_read_fn)(void *user, uint32_t address, void *data, uint32_t size);
typedef int32_t (*agr_write_fn)(void *user, uint32_t address, const void *data, uint32_t size);
typedef uint32_t (*agr_import_fn)(void *user, const char *name, uint32_t symbol_type);
typedef uint32_t (*agr_file_open_fn)(void *user, const char *path, const char *mode);
typedef int32_t (*agr_file_close_fn)(void *user, uint32_t handle);
typedef uint32_t (*agr_file_read_fn)(void *user, uint32_t handle, void *data, uint32_t size);
typedef uint32_t (*agr_file_write_fn)(void *user, uint32_t handle, const void *data, uint32_t size);
typedef int32_t (*agr_file_seek_fn)(void *user, uint32_t handle, int32_t offset, uint32_t whence);
typedef int32_t (*agr_file_tell_fn)(void *user, uint32_t handle);
typedef int32_t (*agr_pipe_fn)(void *user, uint32_t *read_fd, uint32_t *write_fd);
typedef uint32_t (*agr_fd_read_fn)(void *user, uint32_t fd, void *data, uint32_t size);
typedef uint32_t (*agr_fd_write_fn)(void *user, uint32_t fd, const void *data, uint32_t size);
typedef int32_t (*agr_fd_close_fn)(void *user, uint32_t fd);
typedef void (*agr_log_fn)(void *user, uint32_t priority, const char *tag, const char *format);

typedef struct agr_callbacks {
    void *user;
    agr_read_fn read;
    agr_write_fn write;
    agr_import_fn resolve_import;
    agr_file_open_fn file_open;
    agr_file_close_fn file_close;
    agr_file_read_fn file_read;
    agr_file_write_fn file_write;
    agr_file_seek_fn file_seek;
    agr_file_tell_fn file_tell;
    agr_pipe_fn pipe_create;
    agr_fd_read_fn fd_read;
    agr_fd_write_fn fd_write;
    agr_fd_close_fn fd_close;
    agr_log_fn log;
} agr_callbacks;

typedef struct agr_runtime agr_runtime;

typedef struct agr_load_result {
    uint32_t object_handle;
    uint32_t needed_start, needed_count;
    uint32_t relocation_start, relocation_count;
    uint32_t constructor_start, constructor_count;
    uint32_t symbol_start, symbol_count;
} agr_load_result;

typedef struct agr_relocation_info {
    uint32_t type;
    uint32_t address;
    const char *symbol;
    const char *object_name;
} agr_relocation_info;

typedef struct agr_dispatch_result {
    uint32_t handled;
    uint32_t value;
    uint32_t value_r1;
    uint32_t action;
    uint32_t action_arg0;
    uint32_t action_arg1;
} agr_dispatch_result;

enum {
    AGR_ACTION_NONE = 0,
    AGR_ACTION_CALL_ONCE = 1,
    AGR_ACTION_RUN_THREAD = 2,
    AGR_ACTION_COND_WAIT = 3,
    AGR_ACTION_COND_BROADCAST = 4,
    AGR_ACTION_FINALIZE = 5,
    AGR_ACTION_ABORT = 6,
};

AGR_API agr_runtime *agr_runtime_create(const agr_callbacks *callbacks,
                                        uint32_t static_base, uint32_t static_limit,
                                        uint32_t heap_base, uint32_t heap_limit);
AGR_API void agr_runtime_destroy(agr_runtime *runtime);
AGR_API const char *agr_last_error(agr_runtime *runtime);

AGR_API uint32_t agr_alloc_static(agr_runtime *runtime, const void *data, uint32_t size, uint32_t alignment);
AGR_API uint32_t agr_malloc(agr_runtime *runtime, uint32_t size);
AGR_API void agr_free(agr_runtime *runtime, uint32_t address);
AGR_API uint32_t agr_realloc(agr_runtime *runtime, uint32_t address, uint32_t size);
AGR_API uint32_t agr_allocation_size(agr_runtime *runtime, uint32_t address);

AGR_API int32_t agr_load_elf(agr_runtime *runtime, const char *name,
                             const void *data, uint32_t size, uint32_t base,
                             agr_load_result *result);
AGR_API uint32_t agr_find_symbol(agr_runtime *runtime, const char *name);
AGR_API uint32_t agr_symbol_count(agr_runtime *runtime);
AGR_API const char *agr_symbol_name(agr_runtime *runtime, uint32_t index);
AGR_API uint32_t agr_symbol_address(agr_runtime *runtime, uint32_t index);
AGR_API uint32_t agr_needed_count(agr_runtime *runtime);
AGR_API const char *agr_needed_name(agr_runtime *runtime, uint32_t index);
AGR_API uint32_t agr_constructor_count(agr_runtime *runtime);
AGR_API uint32_t agr_constructor_address(agr_runtime *runtime, uint32_t index);
AGR_API uint32_t agr_relocation_count(agr_runtime *runtime);
AGR_API int32_t agr_relocation(agr_runtime *runtime, uint32_t index, agr_relocation_info *info);

AGR_API uint32_t agr_dlopen(agr_runtime *runtime, const char *name);
AGR_API uint32_t agr_dlsym(agr_runtime *runtime, uint32_t handle, const char *name);
AGR_API uint32_t agr_dlclose(agr_runtime *runtime, uint32_t handle);
AGR_API const char *agr_dlerror(agr_runtime *runtime);
AGR_API uint32_t agr_find_exidx(agr_runtime *runtime, uint32_t pc, uint32_t *count);

AGR_API void agr_set_current_thread(agr_runtime *runtime, uint32_t thread_id);
AGR_API uint32_t agr_current_thread(agr_runtime *runtime);
AGR_API uint32_t agr_create_thread_state(agr_runtime *runtime);
AGR_API int32_t agr_dispatch_system(agr_runtime *runtime, const char *name,
                                    const uint32_t regs[4], uint32_t sp,
                                    agr_dispatch_result *result);
AGR_API void agr_complete_once(agr_runtime *runtime, uint32_t control);
AGR_API uint32_t agr_mutex_owner(agr_runtime *runtime, uint32_t address);

#ifdef __cplusplus
}
#endif
#endif
