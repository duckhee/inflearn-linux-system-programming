cmake_minimum_required(VERSION 3.2.6)

find_package(Threads)

project(ex0101PipeBasic LANGUAGES C)

message("example01-01 pipe basic code")

add_executable(ex0101PipeBasic)

target_sources(ex0101PipeBasic PRIVATE main.c)

target_link_libraries(ex0101PipeBasic PRIVATE Threads::Threads)