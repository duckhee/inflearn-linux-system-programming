cmake_minimum_required(VERSION 3.2.6)

project(ex0207CountUtility LANGUAGES C)

message("example02-07 wc utility")

add_executable(ex0207CountUtility)

target_sources(ex0207CountUtility PRIVATE main.c)