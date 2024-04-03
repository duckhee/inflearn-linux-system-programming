cmake_minimum_required(VERSION 3.2.6)

project(ex0303WaitExitAbnormalProcessHandleCoreDump LANGUAGES C)

message("example03-03 wait exit abnormal handle core dump")

add_executable(ex0303WaitExitAbnormalProcessHandleCoreDump)

target_sources(ex0303WaitExitAbnormalProcessHandleCoreDump PRIVATE main.c)