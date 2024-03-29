cmake_minimum_required(VERSION 3.2.6)

project(ex0101ProcessFork LANGUAGES C)

message("example01-01 process fork")

add_executable(ex0101ProcessFork)

target_sources(ex0101ProcessFork PRIVATE main.c)