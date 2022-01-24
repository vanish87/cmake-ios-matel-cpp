
#ifdef(BUILD_IOS)
#import <Availability.h>
#import <UIKit/UIKit.h>
#else
#import <Cocoa/Cocoa.h>
#endif

#ifdef(BUILD_IOS)
int main(int argc, char * argv[])
{
    @autoreleasepool {
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AAPLAppDelegate class]));
    }
}
#else
int main(int argc, const char * argv[])
{
    return NSApplicationMain(argc, argv);
}
#endif