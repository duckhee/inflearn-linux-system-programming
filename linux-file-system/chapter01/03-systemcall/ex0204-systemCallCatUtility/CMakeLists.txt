cmake_minimum_required(VERSION 3.2.6)

project(ex0204SystemCallCatUtility LANGUAGES C)

message("example02-04 system call utility")

add_executable(ex0204SystemCallCatUtility)

target_sources(ex0204SystemCallCatUtility PRIVATE main.c)