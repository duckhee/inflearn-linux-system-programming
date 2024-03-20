cmake_minimum_required(VERSION 3.2.6)

project(ex0203SystemCallRedirectionReadMode LANGUAGES C)

message("example02-03 system call redirection read mode")

add_executable(ex0203SystemCallRedirectionReadMode)

target_sources(ex0203SystemCallRedirectionReadMode PRIVATE main.c)