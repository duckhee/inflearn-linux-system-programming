cmake_minimum_required(VERSION 3.2.6)

project(ex0202AlarmReturnValue LANGUAGES C)

message("example02-02 alarm return value remind time")

add_executable(ex0202AlarmReturnValue)

target_sources(ex0202AlarmReturnValue PRIVATE main.c)