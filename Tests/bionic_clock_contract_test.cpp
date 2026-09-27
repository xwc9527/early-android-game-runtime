#include "../Runtime/Bionic/agr_bionic_clock.h"
#include "../Runtime/Bionic/agr_bionic_errno.h"

#include <cassert>
#include <cerrno>
#include <cstdint>
#include <cstring>

struct StubClock {
    int calls = 0;
    agr_host_clock seen[4] = {};
    int32_t host_error = 0;
    uint64_t nanoseconds = 0;
    uint64_t step = 0;
};

static int32_t stub_clock_ns(void *context, agr_host_clock clock, uint64_t *value) {
    StubClock *stub = static_cast<StubClock *>(context);
    if (stub->calls < 4) stub->seen[stub->calls] = clock;
    stub->calls += 1;
    if (stub->host_error != 0) return stub->host_error;
    if (!value) return EINVAL;
    *value = stub->nanoseconds;
    stub->nanoseconds += stub->step;
    return 0;
}

static agr_host_services services_for(StubClock *stub) {
    agr_host_services services;
    std::memset(&services, 0, sizeof(services));
    services.context = stub;
    services.clock_ns = stub_clock_ns;
    return services;
}

int main() {
    StubClock stub;
    stub.nanoseconds = 1790442016ull * 1000000000ull + 123ull;
    agr_host_services services = services_for(&stub);
    uint32_t sec = 9, nsec = 9;
    int32_t android_errno = 7;
    assert(agr_bionic_clock_gettime(&services, 0, 0x600, &sec, &nsec, &android_errno) == 0);
    assert(stub.calls == 1);
    assert(stub.seen[0] == AGR_HOST_CLOCK_REALTIME);
    assert(sec == 1790442016u);
    assert(nsec == 123u);

    stub.nanoseconds = 530925793000ull;
    assert(agr_bionic_clock_gettime(&services, 1, 0x608, &sec, &nsec, &android_errno) == 0);
    assert(stub.calls == 2);
    assert(stub.seen[1] == AGR_HOST_CLOCK_MONOTONIC);
    assert(sec == 530u);
    assert(nsec == 925793000u);

    stub.step = 307891000ull;
    uint32_t before_sec = 0, before_nsec = 0, after_sec = 0, after_nsec = 0;
    stub.nanoseconds = 69ull * 1000000000ull + 69878590ull;
    assert(agr_bionic_clock_gettime(&services, 1, 1, &before_sec, &before_nsec, &android_errno) == 0);
    assert(agr_bionic_clock_gettime(&services, 1, 1, &after_sec, &after_nsec, &android_errno) == 0);
    assert(after_sec > before_sec || (after_sec == before_sec && after_nsec > before_nsec));
    assert(before_nsec < 1000000000u && after_nsec < 1000000000u);

    stub.host_error = EINVAL;
    sec = 4;
    nsec = 4;
    android_errno = 0;
    int calls = stub.calls;
    assert(agr_bionic_clock_gettime(&services, 0, 1, &sec, &nsec, &android_errno) == -1);
    assert(android_errno == AGR_ANDROID_EINVAL);
    assert(sec == 4 && nsec == 4);
    assert(stub.calls == calls + 1);

    stub.host_error = 99999;
    assert(agr_bionic_clock_gettime(&services, 1, 1, &sec, &nsec, &android_errno) == -1);
    assert(android_errno == AGR_ANDROID_EIO);

    stub.host_error = 0;
    calls = stub.calls;
    android_errno = 0;
    assert(agr_bionic_clock_gettime(&services, 0, 0, &sec, &nsec, &android_errno) == -1);
    assert(android_errno == AGR_ANDROID_EFAULT);
    assert(stub.calls == calls);

    calls = stub.calls;
    android_errno = 11;
    assert(agr_bionic_clock_gettime(&services, 2, 1, &sec, &nsec, &android_errno) == 1);
    assert(android_errno == 11);
    assert(stub.calls == calls);

    services.clock_ns = nullptr;
    assert(agr_bionic_clock_gettime(&services, 1, 1, &sec, &nsec, &android_errno) == -1);
    assert(android_errno == AGR_ANDROID_ENOSYS);

    stub.host_error = 0;
    stub.nanoseconds = ~0ull;
    services = services_for(&stub);
    sec = 6;
    nsec = 6;
    assert(agr_bionic_clock_gettime(&services, 0, 1, &sec, &nsec, &android_errno) == -1);
    assert(android_errno == AGR_ANDROID_EIO);
    assert(sec == 6 && nsec == 6);
    return 0;
}
