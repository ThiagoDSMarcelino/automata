cmake_minimum_required(VERSION 3.16)
project(automata CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(automata src/main.cpp)
target_include_directories(automata PRIVATE include)
target_compile_options(automata PRIVATE -Wall -Wextra -Wpedantic)
