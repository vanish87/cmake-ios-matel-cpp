cmake_minimum_required(VERSION 3.13)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
set(CMAKE_CXX_STANDARD 17)

# set(CMAKE_SYSTEM_NAME iOS)
option(BUILD_IOS "BUILD_IOS" ON)

if (BUILD_IOS)
  set(CMAKE_OSX_SYSROOT iphoneos)
  set(OS_PREFIX iOS)
else()
  set(OS_PREFIX macOS)
endif()

set(CMAKE_XCODE_ATTRIBUTE_DEVELOPMENT_TEAM KH98AQQ5YQ)


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
  ${OS_PREFIX}/Main.storyboard
  # LaunchScreen.storyboard
)

project(main_app)

add_executable(${PROJECT_NAME} 
	MACOSX_BUNDLE
	${APP_HEADER_FILES}
	${APP_SOURCE_FILES}
	${RESOURCES}
)

find_library(UIKIT_LIB UIKit)
find_library(FOUNDATION_LIB Foundation)
find_library(APPKIT_LIB AppKit)

# target_link_libraries(${PROJECT_NAME} "-framework render_framework")
target_link_libraries(${PROJECT_NAME} ${FOUNDATION_LIB})
if(BUILD_IOS)
  target_link_libraries(${PROJECT_NAME} ${UIKIT_LIB})
else()
  target_link_libraries(${PROJECT_NAME} ${APPKIT_LIB})
endif()

message("${CMAKE_OSX_SYSROOT}")

target_link_libraries(${PROJECT_NAME} engine::render)

# message(("${metal_cpp_framework_SOURCE_DIR}"))
target_include_directories(${PROJECT_NAME}
    PUBLIC ${metal_cpp_framework_SOURCE_DIR}
    # PUBLIC ${metal_cpp_SOURCE_DIR}/SingleHeader/include
)

set_target_properties(${PROJECT_NAME} PROPERTIES
                    #   XCODE_ATTRIBUTE_DEBUG_INFORMATION_FORMAT "dwarf-with-dsym"
                    #   XCODE_ATTRIBUTE_GCC_PREFIX_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/Prefix.pch"
                      RESOURCE "${RESOURCES}"
                    #   XCODE_ATTRIBUTE_GCC_PRECOMPILE_PREFIX_HEADER "YES"
                    #   XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET ${DEPLOYMENT_TARGET}
                    #   XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY ${CODE_SIGN_IDENTITY}
                    #   XCODE_ATTRIBUTE_DEVELOPMENT_TEAM ${DEVELOPMENT_TEAM_ID}
                    #   XCODE_ATTRIBUTE_TARGETED_DEVICE_FAMILY ${DEVICE_FAMILY}
                    MACOSX_BUNDLE_GUI_IDENTIFIER com.vanish87.main_app
                      MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/${OS_PREFIX}/plist.in
                    #   XCODE_ATTRIBUTE_CLANG_ENABLE_OBJC_ARC YES
                    #   XCODE_ATTRIBUTE_COMBINE_HIDPI_IMAGES NO
                    #   XCODE_ATTRIBUTE_INSTALL_PATH "$(LOCAL_APPS_DIR)"
                    #   XCODE_ATTRIBUTE_ENABLE_TESTABILITY YES
                    #   XCODE_ATTRIBUTE_GCC_SYMBOLS_PRIVATE_EXTERN YES
)

# endif()
