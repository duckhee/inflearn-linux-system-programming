cmake_minimum_required(VERSION 3.2.6)

project(ex0104SystemCallFileOffsetVersion2 LANGUAGES C)

message("example01-04 system call file offset")

add_executable(ex0104SystemCallFileOffsetVersion2)

target_sources(ex0104SystemCallFileOffsetVersion2 PRIVATE main.c)