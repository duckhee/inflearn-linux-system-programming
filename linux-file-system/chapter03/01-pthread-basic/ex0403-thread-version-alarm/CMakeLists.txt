cmake_minimum_required(VERSION 3.2.6)

project(ex0403ThreadVersionAlarm LANGUAGES C)

message("example04-03 thread version alarm")

add_executable(ex0403ThreadVersionAlarm)

target_sources(ex0403ThreadVersionAlarm PRIVATE main.c)