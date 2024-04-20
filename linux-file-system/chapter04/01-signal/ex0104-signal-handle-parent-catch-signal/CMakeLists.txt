cmake_minimum_required(VERSION 3.2.6)

project(ex0104SignalHandlingParent LANGUAGES C)

message("example01-04 signal parent process handle")

add_executable(ex0104SignalHandlingParent)

target_sources(ex0104SignalHandlingParent PRIVATE main.c)