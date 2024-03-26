cmake_minimum_required(VERSION 3.2.6)

project(ex0202DirectoryStructure LANGUAGES C)

message("example02-02 directory structure")

add_executable(ex0202DirectoryStructure)

target_sources(ex0202DirectoryStructure PRIVATE main.c)