cmake_minimum_required(VERSION 3.2.6)

project(ex0302ThreadConditionVariable LANGUAGES C)

message("example03-02 thread condition variable")

add_executable(ex0302ThreadConditionVariable)

target_sources(ex0302ThreadConditionVariable PRIVATE main.c)
