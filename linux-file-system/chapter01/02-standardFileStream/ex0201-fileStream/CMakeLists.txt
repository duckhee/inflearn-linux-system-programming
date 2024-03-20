cmake_minimum_required(VERSION 3.2.6)

project(ex0201FileStream LANGUAGES C)

message("ex02-01 standard file stream")

add_executable(ex0201FileStream)

target_sources(ex0201FileStream PRIVATE main.c)

set_target_properties(ex0201FileStream PROPERTIES C_STANDARD 99 C_STANDARD_REQUIRED ON)