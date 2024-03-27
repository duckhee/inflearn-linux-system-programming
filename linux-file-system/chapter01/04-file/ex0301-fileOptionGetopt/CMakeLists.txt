cmake_minimum_required(VERSION 3.2.6)

project(ex0301FileOptionGetOpt LANGUAGES C)

message("example03-01 file get option using function getopt")

add_executable(ex0301FileOptionGetOpt)

target_sources(ex0301FileOptionGetOpt PRIVATE main.c)