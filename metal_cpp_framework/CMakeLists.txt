# build metal cpp from apple dev
add_subdirectory(metal_cpp)

# build render that uses metal cpp
# and make it as Framework
project(render_framework)

add_library(${PROJECT_NAME} render.cpp)
add_library(engine::render ALIAS ${PROJECT_NAME})

include(GenerateExportHeader)
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
    # PUBLIC ${metal_cpp_SOURCE_DIR}/SingleHeader/include
)

target_link_libraries( ${PROJECT_NAME}
    engine::metal_cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES
  FRAMEWORK TRUE
  # https://developer.apple.com/library/archive/documentation/MacOSX/Conceptual/BPFrameworks/Concepts/VersionInformation.html
  # as Major verison
  FRAMEWORK_VERSION A
  MACOSX_FRAMEWORK_IDENTIFIER com.cmake.dynamicFramework
  MACOSX_FRAMEWORK_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/framework.plist.in
  # "current version" in semantic format in Mach-O binary file
  VERSION 16.4.0
  # "compatibility version" in semantic format in Mach-O binary file
  SOVERSION 1.0.0
  PUBLIC_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/render.h
  XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "iPhone Developer"
)
