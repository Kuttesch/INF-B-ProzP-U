cmake_minimum_required(VERSION 3.23)
project(polygons C)

set(CMAKE_C_STANDARD 99)

add_executable(polygons main.c funktionen.c)
target_link_libraries(polygons m)