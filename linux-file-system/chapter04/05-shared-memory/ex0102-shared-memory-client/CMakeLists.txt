cmake_minimum_required(VERSION 3.2.6)

project(ex0102SharedMemoryClient LANGUAGES C)

message("example01-02 shared memory client")

add_executable(ex0102SharedMemoryClient)

target_sources(ex0102SharedMemoryClient PRIVATE main.c)