cmake_minimum_required(VERSION 3.2.6)

project(ex0104FileUID-GID LANGUAGES C)

message("example01-04 get file uid gid ")

add_executable(ex0104FileUID-GID)

target_sources(ex0104FileUID-GID PRIVATE main.c)

target_compile_options(ex0104FileUID-GID PRIVATE "-W -Wall -pedantic-errors")

