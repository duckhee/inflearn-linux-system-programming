cmake_minimum_required(VERSION 3.2.6)

project(ex0102PthreadBasic LANGUAGES C)

message("example01-02 pthread basic")

add_executable(ex0102PthreadBasic)

target_sources(ex0102PthreadBasic PRIVATE main.c)