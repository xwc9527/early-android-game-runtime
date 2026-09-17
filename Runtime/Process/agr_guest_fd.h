#ifndef AGR_GUEST_FD_H
#define AGR_GUEST_FD_H

#include "../HostServices/agr_host_services.h"

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct agr_guest_fd_entry {
    int32_t host_fd;
    uint8_t occupied;
    uint8_t close_on_exec;
} agr_guest_fd_entry;

typedef struct agr_guest_fd_table {
    agr_host_services *host;
    agr_guest_fd_entry *entries;
    size_t capacity;
} agr_guest_fd_table;

int agr_guest_fd_table_init(agr_guest_fd_table *table, agr_host_services *host);
void agr_guest_fd_table_destroy(agr_guest_fd_table *table);

/* These functions use host flags only. Android flag translation belongs above. */
int32_t agr_guest_fd_open_host(agr_guest_fd_table *table, const char *host_path,
                               int host_flags, int mode, int close_on_exec);
int32_t agr_guest_fd_adopt(agr_guest_fd_table *table, int32_t host_fd,
                           uint32_t minimum_guest_fd, int close_on_exec);
int32_t agr_guest_fd_close(agr_guest_fd_table *table, int32_t guest_fd);
int64_t agr_guest_fd_read(agr_guest_fd_table *table, int32_t guest_fd,
                          void *data, uint64_t size);
int64_t agr_guest_fd_write(agr_guest_fd_table *table, int32_t guest_fd,
                           const void *data, uint64_t size);
int64_t agr_guest_fd_seek(agr_guest_fd_table *table, int32_t guest_fd,
                          int64_t offset, int whence);
int32_t agr_guest_fd_dup(agr_guest_fd_table *table, int32_t guest_fd,
                         uint32_t minimum_guest_fd, int close_on_exec);

size_t agr_guest_fd_live_count(const agr_guest_fd_table *table);

#ifdef __cplusplus
}
#endif
#endif
