cmake_minimum_required(VERSION 3.2.6)

project(ex0202ThreadErrorHandling LANGUAGES C)

message("example02-02 thread error handling")

add_executable(ex0202ThreadErrorHandling)

target_sources(ex0202ThreadErrorHandling PRIVATE main.c)