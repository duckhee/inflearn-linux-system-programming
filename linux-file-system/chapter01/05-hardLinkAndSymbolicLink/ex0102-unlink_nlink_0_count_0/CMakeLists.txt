cmake_minimum_required(VERSION 3.2.6)

project(ex0102Unlink LANGUAGES C)

message("example01-02 unlink file point of view nlink 0, count 0")

add_executable(ex0102Unlink)

target_sources(ex0102Unlink PRIVATE main.c)