
add_library(ellefsen_debug INTERFACE)
target_include_directories(ellefsen_debug
INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
