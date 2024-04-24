cmake_minimum_required(VERSION 3.2.6)

project(ex0102PipeExample LANGUAGES C)

message("example01-02 pipe example")

add_executable(ex0102PipeExample)

target_sources(ex0102PipeExample PRIVATE main.c)