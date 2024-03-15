cmake_minimum_required(VERSION 3.2.6)

project(ex0204fgetc_fputc LANGUAGES C)

message("example02-04 fgetc fputc")

add_executable(ex0204fgetc_fputc)

target_sources(ex0204fgetc_fputc PRIVATE main.c)

set_target_properties(ex0204fgetc_fputc PROPERTIES C_STANDARD 99 C_STANDARD_REQUIRED ON)