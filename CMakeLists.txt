cmake_minimum_required(VERSION 3.16)
project(automatapp CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE AUTOMATA_SOURCES CONFIGURE_DEPENDS src/*.cpp)
add_executable(automatapp ${AUTOMATA_SOURCES})

target_include_directories(automatapp PRIVATE include)
target_compile_options(automatapp PRIVATE -Wall -Wextra -Wpedantic -Wshadow)
