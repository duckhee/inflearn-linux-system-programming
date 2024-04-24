cmake_minimum_required(VERSION 3.2.6)

project(ex0104PipeDup2Process LANGUAGES C)

message("example01-04 pipe dup2 process")

add_executable(ex0104PipeDup2Process)

target_sources(ex0104PipeDup2Process PRIVATE main.c)