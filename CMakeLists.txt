cmake_minimum_required(VERSION 3.10)

project(arabic-morphological-engine)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build")
file(GLOB SOURCES "src/*.cpp")

add_executable(arabic-morphological-engine ${SOURCES})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)