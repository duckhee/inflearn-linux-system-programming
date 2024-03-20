cmake_minimum_required(VERSION 3.2.6)

project(ex0101StandardIO LANGUAGES C)

message("example01-01 standard library vs system call standardIO")

add_executable(ex0101StandardIO)

target_sources(ex0101StandardIO PRIVATE main.c)