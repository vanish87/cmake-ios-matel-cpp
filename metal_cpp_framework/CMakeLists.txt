
add_subdirectory(metal_cpp)

project(render)

add_library(${PROJECT_NAME} render.cpp)
add_library(engine::render ALIAS ${PROJECT_NAME})

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}
    PUBLIC ${metal_cpp_SOURCE_DIR}/SingleHeader/include
)

target_link_libraries( ${PROJECT_NAME}
    engine::metal_cpp
)