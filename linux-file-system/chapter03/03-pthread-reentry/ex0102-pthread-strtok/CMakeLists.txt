cmake_minimum_required(VERSION 3.2.6)

find_package(Threads)

project(ex0102PthreadStrtok LANGUAGES C)

message("example01-02 pthread strtok")

add_executable(ex0102PthreadStrtok)

target_sources(ex0102PthreadStrtok PRIVATE main.c)

target_link_libraries(ex0102PthreadStrtok PRIVATE Threads::Threads)