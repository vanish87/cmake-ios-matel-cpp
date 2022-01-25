cmake_minimum_required(VERSION 3.13)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

# if(APPLE)
add_subdirectory(metal_cpp_framework)

set(APP_HEADER_FILES
	define.hpp
	AppDelegate.hpp
	AppViewController.hpp
)

set(APP_SOURCE_FILES
	AppDelegate.mm
	AppViewController.mm
	main.mm
)

set(RESOURCES
  Main.storyboard
  LaunchScreen.storyboard
)

project(main_app)

add_executable(${PROJECT_NAME} 
	MACOSX_BUNDLE
	${APP_HEADER_FILES}
	${APP_SOURCE_FILES}
	${RESOURCES}
)

find_library(UIKIT UIKit)
find_library(FOUNDATION Foundation)

# target_link_libraries(${PROJECT_NAME} "-framework render_framework")
target_link_libraries(${PROJECT_NAME} ${UIKit})
target_link_libraries(${PROJECT_NAME} ${FOUNDATION})

set_target_properties(${PROJECT_NAME} PROPERTIES
                    #   XCODE_ATTRIBUTE_DEBUG_INFORMATION_FORMAT "dwarf-with-dsym"
                    #   XCODE_ATTRIBUTE_GCC_PREFIX_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/Prefix.pch"
                      RESOURCE "${RESOURCES}"
                    #   XCODE_ATTRIBUTE_GCC_PRECOMPILE_PREFIX_HEADER "YES"
                    #   XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET ${DEPLOYMENT_TARGET}
                    #   XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY ${CODE_SIGN_IDENTITY}
                    #   XCODE_ATTRIBUTE_DEVELOPMENT_TEAM ${DEVELOPMENT_TEAM_ID}
                    #   XCODE_ATTRIBUTE_TARGETED_DEVICE_FAMILY ${DEVICE_FAMILY}
                      MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/plist.in
                    #   XCODE_ATTRIBUTE_CLANG_ENABLE_OBJC_ARC YES
                    #   XCODE_ATTRIBUTE_COMBINE_HIDPI_IMAGES NO
                    #   XCODE_ATTRIBUTE_INSTALL_PATH "$(LOCAL_APPS_DIR)"
                    #   XCODE_ATTRIBUTE_ENABLE_TESTABILITY YES
                    #   XCODE_ATTRIBUTE_GCC_SYMBOLS_PRIVATE_EXTERN YES
)

# endif()
