project(metal_cpp)

# aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/Foundation foundation_source)
# aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/Metal metal_source)
# aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/QuartzCore quartz_core_source)

# add_library(${PROJECT_NAME} INTERFACE)
# add_library(engine::metal_cpp ALIAS ${PROJECT_NAME})

# set(single_header_file_dir ${CMAKE_CURRENT_SOURCE_DIR}/SingleHeader/include)
# target_include_directories(${PROJECT_NAME} INTERFACE ${single_header_file_dir})

add_library(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/SingleHeader/metal.cpp)
add_library(engine::metal_cpp ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/SingleHeader/include)
