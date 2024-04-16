cmake_minimum_required(VERSION 3.22)


project(
  EllefsenWebServer
  VERSION 0.0.1
  LANGUAGES C
  DESCRIPTION "A Low level WebServer made in C."
)
# Generate compile_commands.json so that the LSP can find the libraries
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${CMAKE_PROJECT_NAME} main.c)

add_subdirectory(src)

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC threadpool)
