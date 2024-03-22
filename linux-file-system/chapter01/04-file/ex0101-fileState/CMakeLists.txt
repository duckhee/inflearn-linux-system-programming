cmake_minimum_required(VERSION 3.2.6)

project(ex0101FileState LANGUAGES C)

message("example0101 file state -> ls -l")

add_executable(ex0101FileState)

target_sources(ex0101FileState PRIVATE main.c)