cmake_minimum_required(VERSION 3.2.6)

project(ex0302WaitExitAbnormalProcessHandle LANGUAGES C)

message("example03-02 wait exit abnormal process handle")

add_executable(ex0302WaitExitAbnormalProcessHandle)

target_sources(ex0302WaitExitAbnormalProcessHandle PRIVATE main.c)