cmake_minimum_required(VERSION 3.2.6)

project(ex0203SignalProcMaskBasic LANGUAGES C)

message("example02-03 signalprocmask function basic")

add_executable(ex0203SignalProcMaskBasic)

target_sources(ex0203SignalProcMaskBasic PRIVATE main.c)

