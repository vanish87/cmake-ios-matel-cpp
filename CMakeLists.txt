cmake_minimum_required(VERSION 3.13)

add_subdirectory(metal_cpp_framework)

project(main_app)
add_executable(${PROJECT_NAME} main.cpp)

message(${metal_cpp_SOURCE_DIR})

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${metal_cpp_SOURCE_DIR}/SingleHeader/include
)
target_link_libraries(${PROJECT_NAME} engine::metal_cpp)
