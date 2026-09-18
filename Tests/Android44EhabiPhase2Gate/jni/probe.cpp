extern "C" {

static volatile int events[32];
static volatile int event_count;

void agr_eh2_reset(void) { event_count = 0; }

void agr_eh2_event(int value) {
    int index = event_count;
    if (index >= 0 && index < 32) events[index] = value;
    event_count = index + 1;
}

int agr_eh2_count(void) { return event_count; }

int agr_eh2_get(int index) {
    return index >= 0 && index < event_count && index < 32 ? events[index] : -1;
}

}

