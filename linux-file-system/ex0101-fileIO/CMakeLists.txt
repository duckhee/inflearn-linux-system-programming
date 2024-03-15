cmake_minimum_required(VERSION 3.2.6)

project(ex0101FileIO LANGUAGES C)

message("example01-01 standard file io")

add_executable(ex0101FileIO)

target_sources(ex0101FileIO PRIVATE main.c)

