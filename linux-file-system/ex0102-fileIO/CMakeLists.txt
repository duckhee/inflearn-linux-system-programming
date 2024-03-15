cmake_minimum_required(VERSION 3.2.6)

project(ex0102FileIO LANGUAGES C)

message("example01-02 standard file io")

add_executable(ex0102FileIO)

target_sources(ex0102FileIO PRIVATE main.c)

