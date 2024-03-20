cmake_minimum_required(VERSION 3.2.6)

project(ex0201SystemCallDuplicated LANGUAGES C)

message("example02-01 system call duplicated")

add_executable(ex0201SystemCallDuplicated)

target_sources(ex0201SystemCallDuplicated PRIVATE main.c)
