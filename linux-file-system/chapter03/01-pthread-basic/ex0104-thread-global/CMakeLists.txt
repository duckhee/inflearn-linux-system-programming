cmake_minimum_required(VERSION 3.2.6)

project(ex0104ThreadGlobalAccess LANGUAGES C)

message("example01-04 thread global value access")

add_executable(ex0104ThreadGlobalAccess)

target_sources(ex0104ThreadGlobalAccess PRIVATE main.c)