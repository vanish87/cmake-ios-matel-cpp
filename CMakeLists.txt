cmake_minimum_required(VERSION 3.13)

add_subdirectory(metal_cpp_framework)

project(main_app)
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} engine::render)
