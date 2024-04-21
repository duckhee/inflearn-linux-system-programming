cmake_minimum_required(VERSION 3.2.6)

project(ex0204SignalProcMaskWait LANGUAGES C)

message("example02-04 signalprocmask wait point")

add_executable(ex0204SignalProcMaskWait)

target_sources(ex0204SignalProcMaskWait PRIVATE main.c)