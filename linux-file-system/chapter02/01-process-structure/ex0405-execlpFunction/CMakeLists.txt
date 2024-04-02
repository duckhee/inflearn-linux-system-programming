cmake_minimum_required(VERSION 3.2.6)

project(ex0405Execlp LANGUAGES C)

message("example04-05 execlp system call")

add_executable(ex0405Execlp)

target_sources(ex0405Execlp PRIVATE main.c)