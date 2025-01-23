cmake_minimum_required(VERSION 3.10)

project(infotecs)

set(CMAKE_CXX_STANDARD 11)

add_library(lib SHARED src/lib.cpp)

add_executable(main src/main.cpp)

add_dependencies(main lib)

target_link_libraries(main lib)

target_include_directories(lib PUBLIC include)
target_compile_definitions(lib PRIVATE _LIBRARY_BUILD)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_ARCHIVE_OUTPUT)