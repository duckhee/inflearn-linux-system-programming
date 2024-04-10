cmake_minimum_required(VERSION 3.2.6)

project(ex0301ThreadMutex LANGUAGES C)

message("example03-01 thread mutex")

add_executable(ex0301ThreadMutex)

target_sources(ex0301ThreadMutex PRIVATE main.c)