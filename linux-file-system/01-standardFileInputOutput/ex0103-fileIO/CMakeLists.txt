cmake_minimum_required(VERSION 3.2.6)

project(ex0103FileIO LANGUAGES C)

message("example01-03 standard file io")

add_executable(ex0103FileIO)

target_sources(ex0103FileIO PRIVATE main.c)

