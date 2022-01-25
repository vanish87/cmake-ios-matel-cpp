cmake_minimum_required(VERSION 3.13)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

# if(APPLE)
add_subdirectory(metal_cpp_framework)

project(main_app)
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} engine::render)
# endif()
