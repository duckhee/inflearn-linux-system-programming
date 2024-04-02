cmake_minimum_required(VERSION 3.2.6)

project(ex0402Execl LANGUAGES C)

message("example04-02 exec system call")

add_executable(ex0402Execl)

target_sources(ex0402Execl PRIVATE main.c)