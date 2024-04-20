cmake_minimum_required(VERSION 3.2.6)

find_package(Threads)

project(ex0101SignalHandlerBasic LANGUAGES C)

message("example01-01 signal handling basic")

add_executable(ex0101SignalHandlerBasic)

target_sources(ex0101SignalHandlerBasic PRIVATE main.c)

target_link_libraries(ex0101SignalHandlerBasic PRIVATE Threads::Threads)