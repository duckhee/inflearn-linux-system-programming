cmake_minimum_required(VERSION 3.2.6)

project(ex0301WaitExitProcessHandle LANGUAGES C)

message("example03-01 wait exit process handle")

add_executable(ex0301WaitExitProcessHandle)

target_sources(ex0301WaitExitProcessHandle PRIVATE main.c)