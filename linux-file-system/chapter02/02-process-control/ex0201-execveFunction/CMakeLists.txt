cmake_minimum_required(VERSION 3.2.6)

project(ex0201Execve LANGUAGES C)

message("example02-01 execve system call")

add_executable(ex0201Execve)

target_sources(ex0201Execve PRIVATE main.c)