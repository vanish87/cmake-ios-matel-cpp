project(metal_cpp)

# header only lib
# add_library(${PROJECT_NAME} INTERFACE)
# add_library(engine::metal_cpp ALIAS ${PROJECT_NAME})
# set(single_header_file_dir ${CMAKE_CURRENT_SOURCE_DIR}/SingleHeader/include)
# target_include_directories(${PROJECT_NAME} INTERFACE ${single_header_file_dir})

# metal.cpp contains implementation
# compiled as static/dynamic lib
add_library(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/SingleHeader/metal.cpp)
add_library(engine::metal_cpp ALIAS ${PROJECT_NAME})

# find_library(UIKIT UIKit)
find_library(FOUNDATION_LIB Foundation)
find_library(METAL_LIB Metal)

# target_link_libraries(${PROJECT_NAME} ${UIKit})
target_link_libraries(${PROJECT_NAME} ${FOUNDATION_LIB})
target_link_libraries(${PROJECT_NAME} ${METAL_LIB})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/SingleHeader/include)
