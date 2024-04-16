cmake_minimum_required(VERSION 3.22)


project(
  EllefsenWebServer
  VERSION 0.0.1
  LANGUAGES C
  DESCRIPTION "A Low level WebServer made in C."
)

add_executable(${CMAKE_PROJECT_NAME} main.c)

add_subdirectory(threadpool)
add_subdirectory(server)

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC threadpool)
