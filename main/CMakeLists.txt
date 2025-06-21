cmake_minimum_required(VERSION 3.11)
project(main)

add_executable(main
  src/main.cpp
)
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR} thirdparty)
target_link_libraries(main PUBLIC Tibonacci)