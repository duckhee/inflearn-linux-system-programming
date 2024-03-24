cmake_minimum_required(VERSION 3.2.6)

project(ex0105LsUtilityGetFileTime LANGUAGES C)

message("example01-05 ls utility file get file mtime")

add_executable(ex0105LsUtilityGetFileTime)

target_sources(ex0105LsUtilityGetFileTime PRIVATE main.c)