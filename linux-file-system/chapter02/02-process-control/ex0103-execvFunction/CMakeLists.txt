cmake_minimum_required(VERSION 3.2.6)

project(ex0403Execv LANGUAGES C)

message("example04-03 execv system call")

add_executable(ex0403Execv)

target_sources(ex0403Execv PRIVATE main.c)