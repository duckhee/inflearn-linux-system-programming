cmake_minimum_required(VERSION 3.2.6)

project(ex0202SystemCallRedirection LANGUAGES C)

message("example02-02 system call redirection utility")

add_executable(ex0202SystemCallRedirection)

target_sources(ex0202SystemCallRedirection PRIVATE main.c)