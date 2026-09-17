#include "../../Runtime/HostServices/agr_host_services.h"

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
    CHECK(host.page_size >= 4096 && (host.page_size & (host.page_size - 1)) == 0);

    uint64_t first = 0, second = 0, realtime = 0;
    CHECK(host.clock_ns(host.context, AGR_HOST_CLOCK_MONOTONIC, &first) == 0);
    CHECK(host.clock_ns(host.context, AGR_HOST_CLOCK_MONOTONIC, &second) == 0);
    CHECK(host.clock_ns(host.context, AGR_HOST_CLOCK_REALTIME, &realtime) == 0);
    CHECK(second >= first && realtime != 0);

    void *mapping = NULL;
    CHECK(host.vm_reserve(host.context, host.page_size * 2u, &mapping) == 0);
    CHECK(mapping != NULL);
    CHECK(host.vm_protect(host.context, mapping, host.page_size,
                          AGR_HOST_VM_READ | AGR_HOST_VM_WRITE) == 0);
    memset(mapping, 0x5a, host.page_size);
    CHECK(((uint8_t *)mapping)[host.page_size - 1] == 0x5a);
    CHECK(host.vm_protect(host.context, mapping, host.page_size, AGR_HOST_VM_READ) == 0);
    CHECK(host.vm_release(host.context, mapping, host.page_size * 2u) == 0);

    char path[] = "/tmp/agr-host-contract-XXXXXX";
    int seed = mkstemp(path);
    CHECK(seed >= 0);
    close(seed);
    int fd = host.file_open(host.context, path, O_RDWR | O_TRUNC, 0600);
    CHECK(fd >= 0);
    const char payload[] = "api19-host-boundary";
    CHECK(host.file_write(host.context, fd, payload, sizeof(payload)) == (int64_t)sizeof(payload));
    CHECK(host.file_seek(host.context, fd, 0, SEEK_SET) == 0);
    char copy[sizeof(payload)] = {0};
    CHECK(host.file_read(host.context, fd, copy, sizeof(copy)) == (int64_t)sizeof(copy));
    CHECK(memcmp(copy, payload, sizeof(payload)) == 0);
    CHECK(host.file_close(host.context, fd) == 0);
    unlink(path);

    puts("PASS Darwin host-service memory/time/file contracts");
    return 0;
}
