#import <UIKit/UIKit.h>
#include "../../Runtime/GuestRuntime/agr_guest_runtime.h"

static int load_fixture(agr_guest *guest, NSBundle *bundle, NSString *stem,
                        const char *soname, uint32_t base) {
    NSString *path = [bundle pathForResource:stem ofType:@"so"];
    NSData *data = path ? [NSData dataWithContentsOfFile:path] : nil;
    if (!data) return -1;
    return agr_guest_load_elf(guest, soname, data.bytes, (uint32_t)data.length, base);
}

static int call(agr_guest *guest, const char *symbol, int32_t *value) {
    return agr_guest_call_symbol(guest, symbol, NULL, 0, value);
}
static int call_arg(agr_guest *guest, const char *symbol, uint32_t argument, int32_t *value) {
    return agr_guest_call_symbol(guest, symbol, &argument, 1, value);
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
        if (!status && (load_fixture(guest,NSBundle.mainBundle,@"libgnustl_shared","libgnustl_shared.so",0x08000000)||
            load_fixture(guest,NSBundle.mainBundle,@"libagr_eh2b_probe","libagr_eh2b_probe.so",0x09000000)||
            load_fixture(guest,NSBundle.mainBundle,@"libagr_eh2b_types","libagr_eh2b_types.so",0x0a000000)||
            load_fixture(guest,NSBundle.mainBundle,@"libagr_eh2b_suite","libagr_eh2b_suite.so",0x0b000000))) status=3;
        const char *symbols[]={"agr_eh2b_typed","agr_eh2b_inheritance","agr_eh2b_multiple","agr_eh2b_pointer","agr_eh2b_rethrow","agr_eh2b_lifetime_ref","agr_eh2b_lifetime_value","agr_eh2b_lifetime_rethrow","agr_eh2b_nested","agr_eh2b_threads"};
        int32_t values[10]={0};
        if (!status) for (int i=0;i<10;i++) if (call(guest,symbols[i],&values[i])) { status=10+i; break; }
        int32_t thread_values[10]={0};
        if (!status) for (int i=0;i<10;i++) if (call_arg(guest,"agr_eh2b_value",20u+(uint32_t)i,&thread_values[i])) { status=30+i; break; }
        NSMutableArray *imports=[NSMutableArray array];
        if (guest) for(uint32_t i=0;i<agr_guest_unique_import_count(guest);i++) {
            const char *name=agr_guest_unique_import(guest,i); if(name)[imports addObject:[NSString stringWithUTF8String:name]];
        }
        NSDictionary *json=@{@"status":@(status),@"typed":@(values[0]),@"inheritance":@(values[1]),@"multiple":@(values[2]),@"pointer":@(values[3]),@"rethrow":@(values[4]),@"lifetime_ref":@(values[5]),@"lifetime_value":@(values[6]),@"lifetime_rethrow":@(values[7]),@"nested":@(values[8]),@"threads":@(values[9]),@"thread_one":@(thread_values[0]),@"thread_two":@(thread_values[1]),@"thread_ret_one":@(thread_values[2]),@"thread_ret_two":@(thread_values[3]),@"thread_id_one":@(thread_values[4]),@"thread_id_two":@(thread_values[5]),@"globals_one":@(thread_values[6]),@"globals_two":@(thread_values[7]),@"globals_after_one":@(thread_values[8]),@"globals_after_two":@(thread_values[9]),@"error":guest?[NSString stringWithUTF8String:agr_guest_last_error(guest)]:@"create failed",@"imports":imports};
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
