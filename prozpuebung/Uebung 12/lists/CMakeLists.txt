cmake_minimum_required(VERSION 3.23)
project(data_structures C)

set(CMAKE_C_STANDARD 99)

add_executable(lists list.c tester.c util.c)

link_libraries(data_structures m)
