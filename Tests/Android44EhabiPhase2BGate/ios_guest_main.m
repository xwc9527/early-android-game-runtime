#import <UIKit/UIKit.h>
#include "../../Runtime/GuestRuntime/agr_guest_runtime.h"

static int load_fixture(agr_guest *guest, NSBundle *bundle, NSString *stem,
                        const char *soname, uint32_t base, uint32_t *handle) {
    NSString *path = [bundle pathForResource:stem ofType:@"so"];
    NSData *data = path ? [NSData dataWithContentsOfFile:path] : nil;
    if (!data) return -1;
    return agr_guest_load_elf_handle(guest, soname, data.bytes, (uint32_t)data.length, base, handle);
}

static int call(agr_guest *guest, uint32_t handle, const char *symbol, int32_t *value) {
    uint32_t address=agr_guest_dlsym(guest,handle,symbol);
    return address?agr_guest_call_address(guest,address,NULL,0,value):-1;
}
static int call_arg(agr_guest *guest, uint32_t handle, const char *symbol, uint32_t argument, int32_t *value) {
    uint32_t address=agr_guest_dlsym(guest,handle,symbol);
    return address?agr_guest_call_address(guest,address,&argument,1,value):-1;
}
static int read_events(agr_guest *guest,uint32_t probe,NSMutableArray *events) {
    int32_t count=0,value=0;
    if(call(guest,probe,"agr_eh2b_count",&count)||count<0||count>64)return -1;
    for(uint32_t i=0;i<(uint32_t)count;i++){
        if(call_arg(guest,probe,"agr_eh2b_get",i,&value))return -1;
        [events addObject:@(value)];
    }
    return 0;
}

@interface AGRPhase2BDelegate : UIResponder <UIApplicationDelegate>
@property(nonatomic,strong) UIWindow *window;
@end

@implementation AGRPhase2BDelegate
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)options {
    (void)application; (void)options;
    self.window=[[UIWindow alloc] initWithFrame:UIScreen.mainScreen.bounds];
    self.window.rootViewController=[UIViewController new];
    [self.window makeKeyAndVisible];
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED,0), ^{
        NSString *docs=[NSHomeDirectory() stringByAppendingPathComponent:@"Documents"];
        NSString *resultPath=[docs stringByAppendingPathComponent:@"ehabi2b-guest.json"];
        NSString *statusPath=[docs stringByAppendingPathComponent:@"ehabi2b-guest-exit.txt"];
        NSString *diagnosticPath=[docs stringByAppendingPathComponent:@"ehabi2b-guest-error.txt"];
        agr_guest *guest=agr_guest_create(); int status=guest?0:2;
        uint32_t gnustl=0,probe=0,types=0,suite=0,c=0,b=0,a=0;
        if (!status && (load_fixture(guest,NSBundle.mainBundle,@"libgnustl_shared","libgnustl_shared.so",0x08000000,&gnustl)||
            load_fixture(guest,NSBundle.mainBundle,@"libagr_eh2b_probe","libagr_eh2b_probe.so",0x09000000,&probe)||
            load_fixture(guest,NSBundle.mainBundle,@"libagr_eh2b_types","libagr_eh2b_types.so",0x0a000000,&types)||
            load_fixture(guest,NSBundle.mainBundle,@"libagr_eh2b_suite","libagr_eh2b_suite.so",0x0b000000,&suite)||
            load_fixture(guest,NSBundle.mainBundle,@"libagr_eh2b_C","libagr_eh2b_C.so",0x0c000000,&c)||
            load_fixture(guest,NSBundle.mainBundle,@"libagr_eh2b_B","libagr_eh2b_B.so",0x0d000000,&b)||
            load_fixture(guest,NSBundle.mainBundle,@"libagr_eh2b_A","libagr_eh2b_A.so",0x0e000000,&a))) status=3;
        const char *symbols[]={"agr_eh2b_typed","agr_eh2b_inheritance","agr_eh2b_multiple","agr_eh2b_pointer","agr_eh2b_rethrow","agr_eh2b_lifetime_ref","agr_eh2b_lifetime_value","agr_eh2b_lifetime_rethrow","agr_eh2b_nested","agr_eh2b_threads"};
        int32_t values[10]={0};
        NSMutableArray *lifetimeRefEvents=[NSMutableArray array],*lifetimeValueEvents=[NSMutableArray array],*lifetimeRethrowEvents=[NSMutableArray array];
        if (!status) for (int i=0;i<10;i++) {
            if (call(guest,suite,symbols[i],&values[i])) { status=10+i; break; }
            NSMutableArray *events=i==5?lifetimeRefEvents:(i==6?lifetimeValueEvents:(i==7?lifetimeRethrowEvents:nil));
            if(events&&read_events(guest,probe,events)){status=20+i;break;}
        }
        int32_t thread_values[10]={0};
        if (!status) for (int i=0;i<10;i++) if (call_arg(guest,probe,"agr_eh2b_value",20u+(uint32_t)i,&thread_values[i])) { status=30+i; break; }
        NSMutableArray *crossEvents=[NSMutableArray array]; int32_t cross=0,crossBase=0,crossDerived=0,reloadCross=0;
        if (!status && (call(guest,a,"agr_eh2b_cross",&cross)||read_events(guest,probe,crossEvents))) status=40;
        if (!status && (call_arg(guest,probe,"agr_eh2b_value",10,&crossBase)||call_arg(guest,probe,"agr_eh2b_value",11,&crossDerived))) status=40;
        if (!status && (agr_guest_dlclose(guest,a)||agr_guest_dlclose(guest,b)||agr_guest_dlclose(guest,c))) status=41;
        if (!status) {
            a=agr_guest_dlopen(guest,"libagr_eh2b_A.so");
            if(!a||call(guest,a,"agr_eh2b_cross",&reloadCross))status=42;
        }
        NSMutableArray *imports=[NSMutableArray array];
        if (guest) for(uint32_t i=0;i<agr_guest_unique_import_count(guest);i++) {
            const char *name=agr_guest_unique_import(guest,i); if(name)[imports addObject:[NSString stringWithUTF8String:name]];
        }
        NSDictionary *json=@{@"status":@(status),@"typed":@(values[0]),@"inheritance":@(values[1]),@"multiple":@(values[2]),@"pointer":@(values[3]),@"rethrow":@(values[4]),@"lifetime_ref":@(values[5]),@"lifetime_ref_events":lifetimeRefEvents,@"lifetime_value":@(values[6]),@"lifetime_value_events":lifetimeValueEvents,@"lifetime_rethrow":@(values[7]),@"lifetime_rethrow_events":lifetimeRethrowEvents,@"nested":@(values[8]),@"threads":@(values[9]),@"thread_one":@(thread_values[0]),@"thread_two":@(thread_values[1]),@"thread_ret_one":@(thread_values[2]),@"thread_ret_two":@(thread_values[3]),@"thread_id_one":@(thread_values[4]),@"thread_id_two":@(thread_values[5]),@"globals_one":@(thread_values[6]),@"globals_two":@(thread_values[7]),@"globals_after_one":@(thread_values[8]),@"globals_after_two":@(thread_values[9]),@"cross":@(cross),@"cross_events":crossEvents,@"cross_base":@(crossBase),@"cross_derived":@(crossDerived),@"reload_cross":@(reloadCross),@"error":guest?[NSString stringWithUTF8String:agr_guest_last_error(guest)]:@"create failed",@"imports":imports};
        NSData *encoded=[NSJSONSerialization dataWithJSONObject:json options:0 error:nil];
        [encoded writeToFile:resultPath atomically:YES];
        [[NSString stringWithFormat:@"%d\n",status] writeToFile:statusPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
        [[NSString stringWithFormat:@"%s\n",guest?agr_guest_last_error(guest):"create failed"] writeToFile:diagnosticPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
        if (guest) agr_guest_destroy(guest);
    });
    return YES;
}
@end

int main(int argc,char **argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass(AGRPhase2BDelegate.class));}}
