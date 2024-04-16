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

# Sets a compiler flag for when in debug mode
# Can then check for debug mode with a macro
target_compile_definitions(${CMAKE_PROJECT_NAME}
PRIVATE $<$<CONFIG:Debug>:DEBUG_ENABLE=1>)

add_subdirectory(src)

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC threadpool)
