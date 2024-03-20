cmake_minimum_required(VERSION 3.2.6)

project(ex0210UtilityMergeVersion1 LANGUAGES C)

message("example02-10 file merge utility version 1")

add_executable(ex0210UtilityMergeVersion1)

target_sources(ex0210UtilityMergeVersion1 PRIVATE main.c)