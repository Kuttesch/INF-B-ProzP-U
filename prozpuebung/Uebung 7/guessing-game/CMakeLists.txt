cmake_minimum_required(VERSION 3.23)

project(guessing-game C)

set(CMAKE_C_STANDARD 99)

add_executable(guessing-game main.c game.c)