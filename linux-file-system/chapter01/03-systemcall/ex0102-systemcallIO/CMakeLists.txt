cmake_minimum_required(VERSION 3.2.6)

project(ex0102SystemCall LANGUAGES C)

message("example01-02 system call")

add_executable(ex0102SystemCall)


target_sources(ex0102SystemCall PRIVATE main.c)


