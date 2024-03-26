cmake_minimum_required(VERSION 3.2.6)

project(ex0204DirectoryLsUtilitySplit LANGUAGES C)

message("example02-04 directory ls utility split search and print")

add_executable(ex0204DirectoryLsUtilitySplit)

target_sources(ex0204DirectoryLsUtilitySplit PRIVATE main.c)