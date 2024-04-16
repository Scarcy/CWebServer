cmake_minimum_required(VERSION 3.22)
# Library Name
set(THREADPOOL "threadpool")

add_library(${THREADPOOL} tpool.c)
target_link_libraries(${THREADPOOL} PRIVATE ellefsen_debug)
target_include_directories(
  ${THREADPOOL}
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
