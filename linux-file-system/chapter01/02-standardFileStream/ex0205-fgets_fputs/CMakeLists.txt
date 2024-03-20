cmake_minimum_required(VERSION 3.2.6)

project(ex0205fgets_fputs LANGUAGES C)

message("example02-05 fgets fputs")

add_executable(ex0205fgets_fputs)

target_sources(ex0205fgets_fputs PRIVATE main.c)

set_target_properties(ex0205fgets_fputs PROPERTIES C_STANDARD 99 C_STANDARD_REQUIRED ON)