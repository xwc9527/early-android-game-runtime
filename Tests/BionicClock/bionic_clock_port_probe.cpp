#include "../../Runtime/Bionic/agr_bionic_clock.h"
#include "../../Runtime/HostServices/agr_host_services.h"

#include <stdio.h>
#include <unistd.h>

static int sample(agr_host_services *services, int32_t clock_id, const char *name,
                  uint32_t *sec, uint32_t *nsec, int32_t *rc, int32_t *android_errno) {
    *android_errno = 0;
    *rc = agr_bionic_clock_gettime(services, clock_id, 1, sec, nsec, android_errno);
    printf("CLOCK id=%d name=%s rc=%d errno=%d tv_sec=%u tv_nsec=%u\n",
           clock_id, name, *rc, *android_errno, *sec, *nsec);
    return *rc == 0 && *android_errno == 0 && *nsec < 1000000000u;
}

int main(void) {
    agr_host_services services;
    int32_t init = agr_host_services_init_darwin(&services);
    printf("PORT agr_bionic_clock_gettime\n");
    printf("INIT rc=%d\n", init);
    if (init != 0 || !services.clock_ns) return 1;
    uint32_t mono_sec_0 = 0, mono_nsec_0 = 0, real_sec_0 = 0, real_nsec_0 = 0;
    uint32_t mono_sec_1 = 0, mono_nsec_1 = 0, real_sec_1 = 0, real_nsec_1 = 0;
    int32_t mono_rc_0 = 0, real_rc_0 = 0, mono_rc_1 = 0, real_rc_1 = 0;
    int32_t mono_err_0 = 0, real_err_0 = 0, mono_err_1 = 0, real_err_1 = 0;
    int before_ok = sample(&services, 1, "monotonic", &mono_sec_0, &mono_nsec_0, &mono_rc_0, &mono_err_0) &&
                    sample(&services, 0, "realtime", &real_sec_0, &real_nsec_0, &real_rc_0, &real_err_0);
    usleep(300000);
    int after_ok = sample(&services, 1, "monotonic", &mono_sec_1, &mono_nsec_1, &mono_rc_1, &mono_err_1) &&
                   sample(&services, 0, "realtime", &real_sec_1, &real_nsec_1, &real_rc_1, &real_err_1);
    int mono_advanced = mono_sec_1 > mono_sec_0 || (mono_sec_1 == mono_sec_0 && mono_nsec_1 > mono_nsec_0);
    int real_advanced = real_sec_1 > real_sec_0 || (real_sec_1 == real_sec_0 && real_nsec_1 > real_nsec_0);
    int distinct = real_sec_0 != mono_sec_0 || real_nsec_0 != mono_nsec_0;
    printf("ADVANCED monotonic=%d realtime=%d distinct=%d\n", mono_advanced, real_advanced, distinct);
    int ok = before_ok && after_ok && mono_advanced && real_advanced && distinct;
    printf("PROBE_DONE ok=%d\n", ok);
    return ok ? 0 : 1;
}
