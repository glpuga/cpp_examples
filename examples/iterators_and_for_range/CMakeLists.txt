cmake_minimum_required(VERSION 3.0)

project(
  iterators_and_for_range
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

set(SRCS example.cpp)

add_executable(${PROJECT_NAME}_example ${SRCS})

target_compile_options(${PROJECT_NAME}_example PRIVATE)
