cmake_minimum_required(VERSION 3.2.6)

project(ex0203DirectoryLsUtility LANGUAGES C)

message("example02-03 directory ls utility")

add_executable(ex0203DirectoryLsUtility)

target_sources(ex0203DirectoryLsUtility PRIVATE main.c)