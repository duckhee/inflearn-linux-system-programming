cmake_minimum_required(VERSION 3.2.6)

find_package(Threads)

project(ex0101Strtok LANGUAGES C)

message("example01-01 strtok basic")

add_executable(ex0101Strtok)

target_sources(ex0101Strtok PRIVATE main.c)

target_link_libraries(ex0101Strtok PRIVATE Threads::Threads)