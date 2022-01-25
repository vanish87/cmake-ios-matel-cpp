#ifndef _DEFINE_HPP
#define _DEFINE_HPP

#include <TargetConditionals.h>

//build system is darwin
#define APP_PLATFORM_BUILD_DARWIN

//target(running) system is darwin or iOS/Simulator
#if defined(TARGET_OS_IPHONE) || defined(TARGET_IPHONE_SIMULATOR)
	#define APP_PLATFORM_TARGET_IOS
#else
	#define APP_PLATFORM_TARGET_DARWIN
#endif

#if defined(TARGET_IPHONE_SIMULATOR)
	#define APP_PLATFORM_TARGET_IOS_SIMULATOR
#endif

#endif /* _DEFINE_HPP */