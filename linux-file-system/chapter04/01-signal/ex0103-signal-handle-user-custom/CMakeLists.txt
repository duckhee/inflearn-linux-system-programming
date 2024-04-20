cmake_minimum_required(VERSION 3.2.6)

find_package(Threads)

project(ex0103SignalHandleUserCustom LANGUAGES C)

message("example01-03 signal handling user custom")

add_executable(ex0103SignalHandleUserCustom)

target_sources(ex0103SignalHandleUserCustom PRIVATE main.c)

target_link_libraries(ex0103SignalHandleUserCustom PRIVATE Threads::Threads)