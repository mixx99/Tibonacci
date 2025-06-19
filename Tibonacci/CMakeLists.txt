cmake_minimum_required(VERSION 3.11)
project(Tibonacci)

add_library(Tibonacci STATIC
    Tibonacci.cpp
)
target_include_directories(
    Tibonacci PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)