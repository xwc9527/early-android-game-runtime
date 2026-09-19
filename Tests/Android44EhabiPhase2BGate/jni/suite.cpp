#include "types.hpp"
#include <pthread.h>

extern "C" void agr_eh2b_reset(void);
extern "C" void agr_eh2b_event(int);
extern "C" void agr_eh2b_set(int, int);

struct Life {
    int tag;
    static volatile int live;
    explicit Life(int value) : tag(value) { ++live; agr_eh2b_event(300 + tag); }
    Life(const Life& other) : tag(other.tag) { ++live; agr_eh2b_event(400 + tag); }
    ~Life() { agr_eh2b_event(500 + tag); --live; }
};
volatile int Life::live;

static __attribute__((noinline)) void throw_derived(int seed) { throw Derived(seed); }
static __attribute__((noinline)) void throw_life(int tag) { throw Life(tag); }

extern "C" __attribute__((noinline)) int agr_eh2b_typed(void) {
    agr_eh2b_reset(); int result = 0;
    try { throw_derived(10); }
    catch (Wrong&) { result = -1; }
    catch (Derived& value) { result = value.base == 11 && value.derived == 14 ? 1 : -2; }
    try { throw 77; }
    catch (Wrong&) { result = -3; }
    catch (...) { if (result == 1) result = 2; }
    return result;
}

extern "C" __attribute__((noinline)) int agr_eh2b_inheritance(void) {
    try { throw_derived(20); }
    catch (Base& value) { return value.base == 21 ? 21 : -1; }
    return -2;
}

extern "C" __attribute__((noinline)) int agr_eh2b_multiple(void) {
    try { throw_derived(30); }
    catch (Right& value) {
        Derived *derived = dynamic_cast<Derived*>(&value);
        if (!derived || value.right != 33 || derived->derived != 34) return -1;
        return (reinterpret_cast<char*>(&value) - reinterpret_cast<char*>(derived)) > 0 ? 33 : -2;
    }
    return -3;
}

extern "C" __attribute__((noinline)) int agr_eh2b_pointer(void) {
    Derived object(40); Derived *source = &object;
    try { throw source; }
    catch (Wrong*) { return -1; }
    catch (Right *value) {
        if (!value || value->right != 43) return -2;
        return reinterpret_cast<void*>(value) != reinterpret_cast<void*>(source) ? 43 : -3;
    }
    return -4;
}

extern "C" __attribute__((noinline)) int agr_eh2b_rethrow(void) {
    const void *inner = 0; const void *outer = 0;
    try {
        try { throw_derived(50); }
        catch (Base& value) { inner = &value; agr_eh2b_event(610); throw; }
    } catch (Derived& value) {
        outer = &value; agr_eh2b_event(611);
        return inner == outer && value.derived == 54 ? 54 : -1;
    }
    return -2;
}

extern "C" __attribute__((noinline)) int agr_eh2b_lifetime_ref(void) {
    agr_eh2b_reset(); Life::live = 0;
    try { throw_life(1); }
    catch (const Life& value) { agr_eh2b_event(601); if (value.tag != 1) return -1; }
    agr_eh2b_event(701 + Life::live); return Life::live;
}

extern "C" __attribute__((noinline)) int agr_eh2b_lifetime_value(void) {
    agr_eh2b_reset(); Life::live = 0;
    try { throw_life(2); }
    catch (Life value) { agr_eh2b_event(602); if (value.tag != 2) return -1; }
    agr_eh2b_event(702 + Life::live); return Life::live;
}

extern "C" __attribute__((noinline)) int agr_eh2b_lifetime_rethrow(void) {
    agr_eh2b_reset(); Life::live = 0;
    try {
        try { throw_life(3); }
        catch (const Life&) { agr_eh2b_event(603); throw; }
    } catch (const Life& value) { agr_eh2b_event(604); if (value.tag != 3) return -1; }
    agr_eh2b_event(703 + Life::live); return Life::live;
}

extern "C" __attribute__((noinline)) int agr_eh2b_nested(void) {
    int outer = 0, inner = 0;
    try { throw Derived(60); }
    catch (Base& base) {
        outer = base.base;
        try { throw Wrong(99); }
        catch (Wrong& wrong) { inner = wrong.value; }
        if (base.base != outer) return -1;
    }
    return outer == 61 && inner == 99 ? 6199 : -2;
}

extern "C" void *__cxa_get_globals(void);
struct ThreadArg { int id; int result; unsigned long self, globals_before, globals_after; };
static pthread_mutex_t thread_gate_lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t thread_gate_cond = PTHREAD_COND_INITIALIZER;
static int thread_gate_ready;
static void *thread_body(void *opaque) {
    ThreadArg *arg = static_cast<ThreadArg*>(opaque); int total = 0;
    arg->self = static_cast<unsigned long>(pthread_self());
    arg->globals_before = reinterpret_cast<unsigned long>(__cxa_get_globals());
    pthread_mutex_lock(&thread_gate_lock);
    ++thread_gate_ready;
    if (thread_gate_ready == 2) pthread_cond_broadcast(&thread_gate_cond);
    while (thread_gate_ready < 2) pthread_cond_wait(&thread_gate_cond, &thread_gate_lock);
    pthread_mutex_unlock(&thread_gate_lock);
    for (int i = 0; i < 8; ++i) {
        try {
            try { throw Derived(arg->id * 100 + i); }
            catch (Base& base) { total += base.base; if ((i & 1) == 0) throw; }
        } catch (Derived& value) { total += value.derived; }
    }
    arg->globals_after = reinterpret_cast<unsigned long>(__cxa_get_globals());
    arg->result = total;
    return reinterpret_cast<void*>(static_cast<unsigned long>(total));
}

extern "C" __attribute__((noinline)) int agr_eh2b_threads(void) {
    ThreadArg one = {1, 0, 0, 0, 0}, two = {2, 0, 0, 0, 0}; pthread_t a, b; void *ra = 0, *rb = 0;
    thread_gate_ready = 0;
    if (pthread_create(&a, 0, thread_body, &one) != 0) return -1;
    if (pthread_create(&b, 0, thread_body, &two) != 0) return -2;
    if (pthread_join(a, &ra) != 0 || pthread_join(b, &rb) != 0) return -3;
    agr_eh2b_set(20, one.result); agr_eh2b_set(21, two.result);
    agr_eh2b_set(22, static_cast<int>(reinterpret_cast<unsigned long>(ra)));
    agr_eh2b_set(23, static_cast<int>(reinterpret_cast<unsigned long>(rb)));
    agr_eh2b_set(24, static_cast<int>(one.self)); agr_eh2b_set(25, static_cast<int>(two.self));
    agr_eh2b_set(26, static_cast<int>(one.globals_before)); agr_eh2b_set(27, static_cast<int>(two.globals_before));
    agr_eh2b_set(28, static_cast<int>(one.globals_after)); agr_eh2b_set(29, static_cast<int>(two.globals_after));
    return one.result > 0 && two.result > one.result &&
           one.result == static_cast<int>(reinterpret_cast<unsigned long>(ra)) &&
           two.result == static_cast<int>(reinterpret_cast<unsigned long>(rb)) &&
           one.self && two.self && one.self != two.self && one.globals_before &&
           two.globals_before && one.globals_before != two.globals_before &&
           one.globals_before == one.globals_after && two.globals_before == two.globals_after;
}
