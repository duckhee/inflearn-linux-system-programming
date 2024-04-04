cmake_minimum_required(VERSION 3.2.6)

project(ex0401MySystemFunction LANGUAGES C)

message("example04-01 my system call")

add_executable(ex0401MySystemFunction)

target_sources(ex0401MySystemFunction PRIVATE main.c)