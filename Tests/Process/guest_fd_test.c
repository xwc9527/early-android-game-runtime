#include "../../Runtime/Process/agr_guest_fd.h"

#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CHECK(condition) do { if (!(condition)) { \
    fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #condition); return 1; \
} } while (0)

int main(void) {
    agr_host_services host;
    CHECK(agr_host_services_init_darwin(&host) == 0);
    agr_guest_fd_table table;
    CHECK(agr_guest_fd_table_init(&table, &host) == 0);

    char path[] = "/tmp/agr-guest-fd-XXXXXX";
    int seed = mkstemp(path);
    CHECK(seed >= 0);
    close(seed);

    int32_t fd = agr_guest_fd_open_host(&table, path, O_RDWR | O_TRUNC, 0600, 1);
    CHECK(fd == 0 && table.entries[fd].close_on_exec == 1);
    const char value[] = "guest-fd-contract";
    CHECK(agr_guest_fd_write(&table, fd, value, sizeof(value)) == (int64_t)sizeof(value));
    CHECK(agr_guest_fd_seek(&table, fd, 0, SEEK_SET) == 0);
    char copy[sizeof(value)] = {0};
    CHECK(agr_guest_fd_read(&table, fd, copy, sizeof(copy)) == (int64_t)sizeof(copy));
    CHECK(memcmp(value, copy, sizeof(value)) == 0);

    int32_t duplicate = agr_guest_fd_dup(&table, fd, 100, 0);
    CHECK(duplicate == 100 && agr_guest_fd_live_count(&table) == 2);
    CHECK(agr_guest_fd_close(&table, duplicate) == 0);
    CHECK(agr_guest_fd_close(&table, duplicate) == -EBADF);
    CHECK(agr_guest_fd_read(&table, duplicate, copy, 1) == -EBADF);

    CHECK(agr_guest_fd_close(&table, fd) == 0);
    CHECK(agr_guest_fd_live_count(&table) == 0);
    size_t stable_capacity = table.capacity;
    for (size_t iteration = 0; iteration < 100000; ++iteration) {
        fd = agr_guest_fd_open_host(&table, path, O_RDONLY, 0, 0);
        CHECK(fd == 0);
        CHECK(agr_guest_fd_close(&table, fd) == 0);
    }
    CHECK(table.capacity == stable_capacity);

    agr_guest_fd_table_destroy(&table);
    unlink(path);
    puts("PASS guest fd reuse/dup/error/100k lifecycle contracts");
    return 0;
}
