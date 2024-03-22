cmake_minimum_required(VERSION 3.2.6)

project(ex0102FilePermission LANGUAGES C)

message("example01-02 file permission")

add_executable(ex0102FilePermission)

target_sources(ex0102FilePermission PRIVATE main.c)

