cmake_minimum_required(VERSION 3.2.6)

project(ex0103PipeProcess LANGUAGES C)

message("example01-03 pipe process")

add_executable(ex0103PipeProcess)

target_sources(ex0103PipeProcess PRIVATE main.c)