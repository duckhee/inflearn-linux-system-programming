cmake_minimum_required(VERSION 3.2.6)

project(ex0205SignalPendingBasic LANGUAGES C)

message("example02-05 signal pending basic")

add_executable(ex0205SignalPendingBasic)

target_sources(ex0205SignalPendingBasic PRIVATE main.c)