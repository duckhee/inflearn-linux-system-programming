cmake_minimum_required(VERSION 3.2.6)

project(ex0201DirectoryBasic LANGUAGES C)

message("example02-01 directory basic")

add_executable(ex0201DirectoryBasic)

target_sources(ex0201DirectoryBasic PRIVATE main.c)