cmake_minimum_required(VERSION 3.2.6)

project(ex0201ProcessErrorHandling LANGUAGES C)

message("example02-01 process error handling")

add_executable(ex0201ProcessErrorHandling)

target_sources(ex0201ProcessErrorHandling PRIVATE main.c)