add_subdirectory(metal_cpp)

include(GenerateExportHeader)
project(render)

add_library(${PROJECT_NAME} render.cpp)
add_library(engine::render ALIAS ${PROJECT_NAME})

set(HEADER_NAME ${PROJECT_NAME})
string(TOUPPER ${HEADER_NAME} HEADER_NAME)

GENERATE_EXPORT_HEADER( ${PROJECT_NAME}
             BASE_NAME ${HEADER_NAME}
             EXPORT_MACRO_NAME ${HEADER_NAME}_API
             EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/${HEADER_NAME}_API.h
             STATIC_DEFINE ${HEADER_NAME}_BUILT_AS_STATIC
)

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}
    PUBLIC ${metal_cpp_SOURCE_DIR}/SingleHeader/include
)

target_link_libraries( ${PROJECT_NAME}
    engine::metal_cpp
)