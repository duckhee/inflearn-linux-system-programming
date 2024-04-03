cmake_minimum_required(VERSION 3.2.6)

project(ex0404Execve LANGUAGES C)

add_subdirectory(newpgm)

message("example04-04 execve system call")

add_executable(ex0404Execve)

target_sources(ex0404Execve PRIVATE main.c)