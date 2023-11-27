cmake_minimum_required(VERSION 3.23)
project(prime-numbers C)

set(CMAKE_C_STANDARD 99)

add_executable(prime-numbers main.c prime.c vectors.c)
target_link_libraries(prime-numbers m)