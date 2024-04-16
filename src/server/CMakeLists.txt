cmake_minimum_required(VERSION 3.22)

set(SERVER "server")
add_library(${SERVER} server.c)
target_include_directories(${SERVER}
PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
