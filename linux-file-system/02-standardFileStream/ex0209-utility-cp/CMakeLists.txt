cmake_minimum_required(VERSION 3.2.6)

project(ex0209CP LANGUAGES C)

message("example02-09 copy utility")

add_executable(ex0209CP)

target_sources(ex0209CP PRIVATE main.c)