#include "agr_guest_fd.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>

static int ensure_capacity(agr_guest_fd_table *table, size_t required) {
    if (required <= table->capacity) return 0;
    size_t capacity = table->capacity ? table->capacity : 16u;
    while (capacity < required) {
        if (capacity > SIZE_MAX / 2u) return ENOMEM;
        capacity *= 2u;
    }
    if (capacity > SIZE_MAX / sizeof(*table->entries)) return ENOMEM;
    void *grown = realloc(table->entries, capacity * sizeof(*table->entries));
    if (!grown) return ENOMEM;
    table->entries = (agr_guest_fd_entry *)grown;
    memset(table->entries + table->capacity, 0,
           (capacity - table->capacity) * sizeof(*table->entries));
    table->capacity = capacity;
    return 0;
}

int agr_guest_fd_table_init(agr_guest_fd_table *table, agr_host_services *host) {
    if (!table || !host || !host->file_open || !host->file_read ||
        !host->file_write || !host->file_seek || !host->file_close) return EINVAL;
    if (!host->file_dup) return EINVAL;
    *table = (agr_guest_fd_table){ .host = host };
    return 0;
}

void agr_guest_fd_table_destroy(agr_guest_fd_table *table) {
    if (!table) return;
    if (table->host && table->host->file_close) {
        for (size_t index = 0; index < table->capacity; ++index) {
            if (table->entries[index].occupied) {
                table->host->file_close(table->host->context,
                                         table->entries[index].host_fd);
            }
        }
    }
    free(table->entries);
    memset(table, 0, sizeof(*table));
}

int32_t agr_guest_fd_adopt(agr_guest_fd_table *table, int32_t host_fd,
                           uint32_t minimum_guest_fd, int close_on_exec) {
    if (!table || !table->host || host_fd < 0 || minimum_guest_fd > INT32_MAX) {
        return -EINVAL;
    }
    size_t index = minimum_guest_fd;
    while (index < table->capacity && table->entries[index].occupied) ++index;
    int result = ensure_capacity(table, index + 1u);
    if (result) return -result;
    table->entries[index] = (agr_guest_fd_entry){
        .host_fd = host_fd,
        .occupied = 1,
        .close_on_exec = close_on_exec ? 1 : 0,
    };
    return (int32_t)index;
}

int32_t agr_guest_fd_open_host(agr_guest_fd_table *table, const char *host_path,
                               int host_flags, int mode, int close_on_exec) {
    if (!table || !table->host || !host_path) return -EINVAL;
    int32_t host_fd = table->host->file_open(table->host->context, host_path,
                                             host_flags, mode);
    if (host_fd < 0) return host_fd;
    int32_t guest_fd = agr_guest_fd_adopt(table, host_fd, 0, close_on_exec);
    if (guest_fd < 0) table->host->file_close(table->host->context, host_fd);
    return guest_fd;
}

static agr_guest_fd_entry *entry_for(agr_guest_fd_table *table,
                                     int32_t guest_fd) {
    if (!table || guest_fd < 0 || (size_t)guest_fd >= table->capacity ||
        !table->entries[guest_fd].occupied) return NULL;
    return &table->entries[guest_fd];
}

int32_t agr_guest_fd_close(agr_guest_fd_table *table, int32_t guest_fd) {
    agr_guest_fd_entry *entry = entry_for(table, guest_fd);
    if (!entry) return -EBADF;
    int32_t host_fd = entry->host_fd;
    *entry = (agr_guest_fd_entry){0};
    int32_t result = table->host->file_close(table->host->context, host_fd);
    return result ? -result : 0;
}

int64_t agr_guest_fd_read(agr_guest_fd_table *table, int32_t guest_fd,
                          void *data, uint64_t size) {
    agr_guest_fd_entry *entry = entry_for(table, guest_fd);
    return entry ? table->host->file_read(table->host->context, entry->host_fd,
                                          data, size) : -EBADF;
}

int64_t agr_guest_fd_write(agr_guest_fd_table *table, int32_t guest_fd,
                           const void *data, uint64_t size) {
    agr_guest_fd_entry *entry = entry_for(table, guest_fd);
    return entry ? table->host->file_write(table->host->context, entry->host_fd,
                                           data, size) : -EBADF;
}

int64_t agr_guest_fd_seek(agr_guest_fd_table *table, int32_t guest_fd,
                          int64_t offset, int whence) {
    agr_guest_fd_entry *entry = entry_for(table, guest_fd);
    return entry ? table->host->file_seek(table->host->context, entry->host_fd,
                                          offset, whence) : -EBADF;
}

int32_t agr_guest_fd_dup(agr_guest_fd_table *table, int32_t guest_fd,
                         uint32_t minimum_guest_fd, int close_on_exec) {
    agr_guest_fd_entry *entry = entry_for(table, guest_fd);
    if (!entry) return -EBADF;
    int32_t duplicated = table->host->file_dup(table->host->context,
                                               entry->host_fd);
    if (duplicated < 0) return duplicated;
    int32_t result = agr_guest_fd_adopt(table, duplicated, minimum_guest_fd,
                                        close_on_exec);
    if (result < 0) table->host->file_close(table->host->context, duplicated);
    return result;
}

size_t agr_guest_fd_live_count(const agr_guest_fd_table *table) {
    if (!table) return 0;
    size_t count = 0;
    for (size_t index = 0; index < table->capacity; ++index) {
        if (table->entries[index].occupied) ++count;
    }
    return count;
}
