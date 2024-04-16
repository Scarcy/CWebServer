cmake_minimum_required(VERSION 3.22)

set(SERVER "server")

add_library(${SERVER} server.c)
target_link_libraries(${SERVER} PRIVATE ellefsen_debug)
target_include_directories(
${SERVER}
PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
