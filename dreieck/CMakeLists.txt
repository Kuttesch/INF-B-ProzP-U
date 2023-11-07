cmake_minimum_required(VERSION 3.23)
project(dreieck C)

set(CMAKE_C_STANDARD 99)

add_executable(dreieck mainfile.c)
target_link_libraries(dreieck m)
