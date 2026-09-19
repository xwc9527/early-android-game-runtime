#import <UIKit/UIKit.h>

#include <stdio.h>

extern int agr_ehabi2_run(int argc, char **argv);

@interface AGRPhase2ADelegate : UIResponder <UIApplicationDelegate>
@property(nonatomic, strong) UIWindow *window;
@end

@implementation AGRPhase2ADelegate
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)options {
    (void)application;
    (void)options;
    self.window = [[UIWindow alloc] initWithFrame:UIScreen.mainScreen.bounds];
    UIViewController *controller = [UIViewController new];
    controller.view.backgroundColor = UIColor.blackColor;
    self.window.rootViewController = controller;
    [self.window makeKeyAndVisible];
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{
        NSBundle *bundle = NSBundle.mainBundle;
        NSString *documents = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"];
        NSString *output = [documents stringByAppendingPathComponent:@"ehabi2-simulator.json"];
        NSString *status = [documents stringByAppendingPathComponent:@"ehabi2-exit.txt"];
        const char *paths[] = {
            "agr-ehabi2-simulator",
            [[bundle pathForResource:@"libgnustl_shared" ofType:@"so"] fileSystemRepresentation],
            [[bundle pathForResource:@"libagr_eh2_probe" ofType:@"so"] fileSystemRepresentation],
            [[bundle pathForResource:@"libagr_eh2_same" ofType:@"so"] fileSystemRepresentation],
            [[bundle pathForResource:@"libagr_eh2_C" ofType:@"so"] fileSystemRepresentation],
            [[bundle pathForResource:@"libagr_eh2_B" ofType:@"so"] fileSystemRepresentation],
            [[bundle pathForResource:@"libagr_eh2_A" ofType:@"so"] fileSystemRepresentation],
        };
        FILE *stream = freopen(output.fileSystemRepresentation, "w", stdout);
        int rc = stream ? agr_ehabi2_run(7, (char **)paths) : 125;
        fflush(stdout);
        fclose(stdout);
        [[NSString stringWithFormat:@"%d\n", rc] writeToFile:status
                                                       atomically:YES
                                                         encoding:NSUTF8StringEncoding
                                                            error:nil];
    });
    return YES;
}
@end

int main(int argc, char **argv) {
    @autoreleasepool {
        return UIApplicationMain(argc, argv, nil, NSStringFromClass(AGRPhase2ADelegate.class));
    }
}
