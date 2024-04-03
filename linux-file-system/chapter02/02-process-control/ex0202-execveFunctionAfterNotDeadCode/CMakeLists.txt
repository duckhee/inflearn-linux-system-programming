cmake_minimum_required(VERSION 3.2.6)

project(ex0202ExecveAfterNotDeadCode LANGUAGES C)

message("example02-02 execve after not dead code")

add_executable(ex0202ExecveAfterNotDeadCode)

target_sources(ex0202ExecveAfterNotDeadCode PRIVATE main.c)