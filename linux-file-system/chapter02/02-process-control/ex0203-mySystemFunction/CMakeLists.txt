cmake_minimum_required(VERSION 3.2.6)

project(ex0203MySystemFunction LANGUAGES C)

message("example02-03 make my system function")

add_executable(ex0203MySystemFunction)

target_sources(ex0203MySystemFunction PRIVATE main.c)