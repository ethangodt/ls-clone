cmake_minimum_required(VERSION 3.25)
project(ls_clone C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(src)

add_executable(ls_clone
        src/main.c)
