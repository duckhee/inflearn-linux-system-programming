cmake_minimum_required(VERSION 3.2.6)

project(ex0203CustomErrorHandling LANGUAGES C)

message("example02-03 custom error handling")

add_executable(ex0203CustomErrorHandling)

target_sources(ex0203CustomErrorHandling PRIVATE customerrors.h main.c)

