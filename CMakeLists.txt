cmake_minimum_required(VERSION 3.13)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(metal_cpp_framework)

project(main_app)

set(APP_BUNDLE_IDENTIFIER "com.vanish87.${PROJECT_NAME}") 
# set(CMAKE_XCODE_ATTRIBUTE_DEVELOPMENT_TEAM KH98AQQ5YQ)

set(COMMON_HEADER_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/define.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/AppDelegate.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/AppViewController.hpp
)

set(APP_SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/AppDelegate.mm
	${CMAKE_CURRENT_SOURCE_DIR}/AppViewController.mm
	${CMAKE_CURRENT_SOURCE_DIR}/main.mm
)

add_subdirectory(iOS)
add_subdirectory(macOS)
