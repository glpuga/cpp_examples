cmake_minimum_required(VERSION 3.0)

project(
  parenthesis_vs_braces
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

set(SRCS example.cpp)

add_executable(${PROJECT_NAME}_example ${SRCS})

