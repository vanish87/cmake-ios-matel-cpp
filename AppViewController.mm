
#import "AppViewController.hpp"
#import <render.hpp>


@implementation AppViewController
{
    // MTK::View* view_;
	// MTL::Device* device_;
}

- (void)CreateViewControllerManully
{
	NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    
    RenderFunction();

	// UIWindow* window = [[UIWindow alloc] initWithFrame: [UIScreen mainScreen].bounds];
	// window.rootViewController = [[AppViewController alloc] init];;
	// [window makeKeyAndVisible];

	[pool release];
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    [self CreateViewControllerManully];

    // self.device_ = MTL::CreateSystemDefaultDevice();

    // NSAssert(device_, @"Metal is not supported on this device");

    // // Set the view to use the default device
    // MTKView *mtkView = (MTKView *)self.view;

    // mtkView.delegate = self;

    // view_ = new MTK::View(mtkView, *device_);

	// add new view controller if needs
	// [self addChildViewController:self.contentViewController];
    // [self.view addSubview:self.contentViewController.view];
}
- (void)dealloc
{
    [super dealloc];
    // delete device_;
    // device_ = nullptr;

}

- (void)mtkView:(nonnull MTKView *)view drawableSizeWillChange:(CGSize)size
{
    // MTL::Size newSize = MTL::SizeMake(size.width, size.height, 0);
    // _renderer->drawableSizeWillChange(*view_, newSize);
}

- (void)drawInMTKView:(nonnull MTKView *)view
{
    // _renderer->drawInView(*view_);
}

//- (void)keyDown:(NSEvent *)event
//{
//}

- (BOOL)acceptsFirstResponder
{
    return YES;
}


@end
