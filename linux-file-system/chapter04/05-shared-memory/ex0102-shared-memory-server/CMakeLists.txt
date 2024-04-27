cmake_minimum_required(VERSION 3.2.6)

project(ex0102SharedMemoryServer LANGUAGES C)

message("example01-02 shared memory server")

add_executable(ex0102SharedMemoryServer)

target_sources(ex0102SharedMemoryServer PRIVATE main.c)