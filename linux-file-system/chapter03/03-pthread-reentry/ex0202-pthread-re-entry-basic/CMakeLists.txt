cmake_minimum_required(VERSION 3.2.6)

find_package(Threads)

project(ex0202PthreadReEntryBasic LANGUAGES C)

message("example02-02 pthread re entry function make")

add_executable(ex0202PthreadReEntryBasic)

target_link_libraries(ex0202PthreadReEntryBasic PRIVATE Threads::Threads)

target_sources(ex0202PthreadReEntryBasic PRIVATE main.c)