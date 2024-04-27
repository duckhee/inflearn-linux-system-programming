cmake_minimum_required(VERSION 3.2.6)

project(ex0101SharedMemoryBasic LANGUAGES C)

message("example01-01 shared memory basic")

add_executable(ex0101SharedMemoryBasic)

target_sources(ex0101SharedMemoryBasic PRIVATE main.c)