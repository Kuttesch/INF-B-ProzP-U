cmake_minimum_required(VERSION 3.23)
project(eurotest C)

set(CMAKE_C_STANDARD 99)

add_executable(eurotest main.c serial.c)