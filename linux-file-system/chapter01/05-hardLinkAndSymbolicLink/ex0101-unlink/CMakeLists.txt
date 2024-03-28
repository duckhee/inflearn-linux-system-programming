cmake_minimum_required(VERSION 3.2.6)

project(ex0101Unlink LANGUAGES C)

message("example01-01 unlink")

add_executable(ex0101Unlink)

target_sources(ex0101Unlink PRIVATE main.c)