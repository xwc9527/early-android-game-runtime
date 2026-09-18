#include "agr_host_services.h"

#if !defined(__APPLE__)
#error "agr_host_services_darwin.c is only for Apple hosts"
#endif

#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <time.h>
#include <unistd.h>

static int32_t host_clock_ns(void *context, agr_host_clock clock, uint64_t *value) {
    (void)context;
    if (!value) return EINVAL;
    clockid_t source;
    if (clock == AGR_HOST_CLOCK_MONOTONIC) source = CLOCK_MONOTONIC;
    else if (clock == AGR_HOST_CLOCK_REALTIME) source = CLOCK_REALTIME;
    else return EINVAL;
    struct timespec now;
    if (clock_gettime(source, &now)) return errno;
    *value = (uint64_t)now.tv_sec * 1000000000ull + (uint64_t)now.tv_nsec;
    return 0;
}

static int32_t host_vm_reserve(void *context, uint64_t size, void **base) {
    (void)context;
    if (!base || !size || size > SIZE_MAX) return EINVAL;
    void *result = mmap(NULL, (size_t)size, PROT_NONE,
                        MAP_PRIVATE | MAP_ANON, -1, 0);
    if (result == MAP_FAILED) return errno;
    *base = result;
    return 0;
}

static int native_protection(uint32_t protection, int *result) {
    if (!result || (protection & ~(AGR_HOST_VM_READ | AGR_HOST_VM_WRITE |
                                   AGR_HOST_VM_EXEC))) return EINVAL;
    int value = PROT_NONE;
    if (protection & AGR_HOST_VM_READ) value |= PROT_READ;
    if (protection & AGR_HOST_VM_WRITE) value |= PROT_WRITE;
    if (protection & AGR_HOST_VM_EXEC) value |= PROT_EXEC;
    *result = value;
    return 0;
}

static int32_t host_vm_protect(void *context, void *base, uint64_t size,
                               uint32_t protection) {
    (void)context;
    int native = 0, invalid = native_protection(protection, &native);
    if (invalid) return invalid;
    if (!base || !size || size > SIZE_MAX) return EINVAL;
    return mprotect(base, (size_t)size, native) ? errno : 0;
}

static int32_t host_vm_release(void *context, void *base, uint64_t size) {
    (void)context;
    if (!base || !size || size > SIZE_MAX) return EINVAL;
    return munmap(base, (size_t)size) ? errno : 0;
}

static int32_t host_file_open(void *context, const char *path, int flags, int mode) {
    (void)context;
    if (!path) return -EINVAL;
    int fd = open(path, flags, mode);
    return fd < 0 ? -errno : fd;
}

static int64_t host_file_read(void *context, int fd, void *data, uint64_t size) {
    (void)context;
    if ((!data && size) || size > SSIZE_MAX) return -EINVAL;
    ssize_t result;
    do result = read(fd, data, (size_t)size); while (result < 0 && errno == EINTR);
    return result < 0 ? -errno : (int64_t)result;
}

static int64_t host_file_write(void *context, int fd, const void *data, uint64_t size) {
    (void)context;
    if ((!data && size) || size > SSIZE_MAX) return -EINVAL;
    ssize_t result;
    do result = write(fd, data, (size_t)size); while (result < 0 && errno == EINTR);
    return result < 0 ? -errno : (int64_t)result;
}

static int64_t host_file_seek(void *context, int fd, int64_t offset, int whence) {
    (void)context;
    off_t result = lseek(fd, (off_t)offset, whence);
    return result < 0 ? -errno : (int64_t)result;
}

static int32_t host_file_dup(void *context, int fd) {
    (void)context;
    int result = fcntl(fd, F_DUPFD, 0);
    return result < 0 ? -errno : result;
}

static int32_t host_file_close(void *context, int fd) {
    (void)context;
    int result = close(fd);
    return result ? errno : 0;
}

typedef struct host_thread_handle { pthread_t value; } host_thread_handle;
static _Thread_local void *bound_guest_thread;

static int32_t host_thread_create(void *context, void *(*entry)(void *),
                                  void *arg, void **handle) {
    (void)context;
    if (!entry || !handle) return EINVAL;
    host_thread_handle *thread = calloc(1, sizeof(*thread));
    if (!thread) return ENOMEM;
    int result = pthread_create(&thread->value, NULL, entry, arg);
    if (result) { free(thread); return result; }
    *handle = thread;
    return 0;
}
static int32_t host_thread_join(void *context, void *handle, void **return_value) {
    (void)context;
    if (!handle) return EINVAL;
    host_thread_handle *thread = handle;
    int result = pthread_join(thread->value, return_value);
    if (!result) free(thread);
    return result;
}
static int32_t host_thread_detach(void *context, void *handle) {
    (void)context;
    if (!handle) return EINVAL;
    host_thread_handle *thread = handle;
    int result = pthread_detach(thread->value);
    if (!result) free(thread);
    return result;
}
static void host_thread_bind_guest(void *context, void *guest_thread) {
    (void)context;
    bound_guest_thread = guest_thread;
}
static void *host_thread_guest_binding(void *context) {
    (void)context;
    return bound_guest_thread;
}

int32_t agr_host_services_init_darwin(agr_host_services *services) {
    if (!services) return EINVAL;
    long page = sysconf(_SC_PAGESIZE);
    if (page <= 0 || (unsigned long)page > UINT32_MAX) return EINVAL;
    *services = (agr_host_services){
        .context = NULL,
        .page_size = (uint32_t)page,
        .clock_ns = host_clock_ns,
        .vm_reserve = host_vm_reserve,
        .vm_protect = host_vm_protect,
        .vm_release = host_vm_release,
        .file_open = host_file_open,
        .file_read = host_file_read,
        .file_write = host_file_write,
        .file_seek = host_file_seek,
        .file_dup = host_file_dup,
        .file_close = host_file_close,
        .thread_create = host_thread_create,
        .thread_join = host_thread_join,
        .thread_detach = host_thread_detach,
        .thread_bind_guest = host_thread_bind_guest,
        .thread_guest_binding = host_thread_guest_binding,
    };
    return 0;
}
