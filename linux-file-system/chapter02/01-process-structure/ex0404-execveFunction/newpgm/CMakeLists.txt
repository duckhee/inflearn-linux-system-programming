cmake_minimum_required(VERSION 3.2.6)

project(newpgm LANGUAGES C)

message("example04-04 execve system call")

add_executable(newpgm)

target_sources(newpgm PRIVATE main.c)