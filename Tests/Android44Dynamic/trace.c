static char events[128];
static int event_count;
void trace_reset(void){event_count=0;events[0]=0;}
void trace_event(char value){if(event_count<(int)sizeof(events)-1){events[event_count++]=value;events[event_count]=0;}}
const char* trace_events(void){return events;}
