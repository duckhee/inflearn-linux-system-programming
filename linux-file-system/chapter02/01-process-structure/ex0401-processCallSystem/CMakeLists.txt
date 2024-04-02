cmake_minimum_required(VERSION 3.2.6)

project(ex0301ProcessSystemCall LANGUAGES C)

message("example03-01 system call by process")

add_executable(ex0301ProcessSystemCall)

target_sources(ex0301ProcessSystemCall PRIVATE main.c)