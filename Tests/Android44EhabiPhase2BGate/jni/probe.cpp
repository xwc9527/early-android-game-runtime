extern "C" {
static volatile int events[256];
static volatile int event_count;
static volatile int values[64];

void agr_eh2b_reset(void) {
    event_count = 0;
    for (int i = 0; i < 64; ++i) values[i] = 0;
}
void agr_eh2b_event(int value) {
    int index = event_count;
    if (index >= 0 && index < 256) events[index] = value;
    event_count = index + 1;
}
int agr_eh2b_count(void) { return event_count; }
int agr_eh2b_get(int index) {
    return index >= 0 && index < event_count && index < 256 ? events[index] : -1;
}
void agr_eh2b_set(int index, int value) {
    if (index >= 0 && index < 64) values[index] = value;
}
int agr_eh2b_value(int index) {
    return index >= 0 && index < 64 ? values[index] : -1;
}
}
