cmake_minimum_required(VERSION 3.2.6)

project(ex0202PopenPipeBasic LANGUAGES C)

message("example02-02 popen function using pipe create")

add_executable(ex0202PopenPipeBasic)

target_sources(ex0202PopenPipeBasic PRIVATE main.c)