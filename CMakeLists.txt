cmake_minimum_required(VERSION 3.10)

project(arabic-morphological-engine)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build")

add_executable(arabic-morphological-engine ./src/main.cpp)