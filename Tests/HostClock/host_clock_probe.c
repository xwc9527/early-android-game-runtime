#include "agr_host_services.h"

#include <stdio.h>
#include <unistd.h>

/* Calls the existing HostServices realtime and monotonic primitives.
 * It does not accept a Linux clock id. */
int main(void) {
    agr_host_services services;
    int32_t init = agr_host_services_init_darwin(&services);
    printf("INIT rc=%d\n", init);
    if (init != 0 || !services.clock_ns) return 1;
    uint64_t monotonic_before = 0, realtime_before = 0;
    uint64_t monotonic_after = 0, realtime_after = 0;
    int32_t monotonic_before_rc = services.clock_ns(
        services.context, AGR_HOST_CLOCK_MONOTONIC, &monotonic_before);
    int32_t realtime_before_rc = services.clock_ns(
        services.context, AGR_HOST_CLOCK_REALTIME, &realtime_before);
    printf("BEFORE monotonic rc=%d ns=%llu\n",
           monotonic_before_rc, (unsigned long long)monotonic_before);
    printf("BEFORE realtime rc=%d ns=%llu\n",
           realtime_before_rc, (unsigned long long)realtime_before);
    usleep(300000);
    int32_t monotonic_after_rc = services.clock_ns(
        services.context, AGR_HOST_CLOCK_MONOTONIC, &monotonic_after);
    int32_t realtime_after_rc = services.clock_ns(
        services.context, AGR_HOST_CLOCK_REALTIME, &realtime_after);
    printf("AFTER monotonic rc=%d ns=%llu\n",
           monotonic_after_rc, (unsigned long long)monotonic_after);
    printf("AFTER realtime rc=%d ns=%llu\n",
           realtime_after_rc, (unsigned long long)realtime_after);
    int monotonic_advanced = monotonic_after > monotonic_before;
    int realtime_advanced = realtime_after > realtime_before;
    printf("ADVANCED monotonic=%d realtime=%d\n",
           monotonic_advanced, realtime_advanced);
    int ok = monotonic_before_rc == 0 && realtime_before_rc == 0 &&
             monotonic_after_rc == 0 && realtime_after_rc == 0 &&
             monotonic_advanced && realtime_advanced;
    printf("PROBE_DONE ok=%d\n", ok);
    return ok ? 0 : 1;
}
