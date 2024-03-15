cmake_minimum_required(VERSION 3.2.6)

project(ex0203FileOffset LANGUAGES C)

message("ex02-03 file offset")

add_executable(ex0203FileOffset)

target_sources(ex0203FileOffset PRIVATE main.c)