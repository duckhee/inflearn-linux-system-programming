cmake_minimum_required(VERSION 3.2.6)

project(ex0304WaitExitAbnormalProcessHandle LANGUAGES C)

message("example03-04 wait exit abnormal handle core dump")

add_executable(ex0304WaitExitAbnormalProcessHandle)

target_sources(ex0304WaitExitAbnormalProcessHandle PRIVATE main.c)