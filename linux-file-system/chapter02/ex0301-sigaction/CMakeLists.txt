cmake_minimum_required(VERSION 3.2.6)

project(ex0301Sigaction LANGUAGES C)

message("example03-01 sigaction")

add_executable(ex0301Sigaction)

target_sources(ex0301Sigaction PRIVATE main.c)