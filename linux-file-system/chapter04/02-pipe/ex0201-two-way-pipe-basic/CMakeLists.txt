cmake_minimum_required(VERSION 3.2.6)

project(ex0201TwoWayPipeBasic LANGUAGES C)

message("example02-01 two way pipe basic")

add_executable(ex0201TwoWayPipeBasic)

target_sources(ex0201TwoWayPipeBasic PRIVATE main.c)