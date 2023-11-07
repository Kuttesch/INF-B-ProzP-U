cmake_minimum_required(VERSION 3.23)
project(zahltab C)

set(CMAKE_C_STANDARD 99)

add_executable(zahltab zahltab.c)
target_link_libraries(zahltab m)
