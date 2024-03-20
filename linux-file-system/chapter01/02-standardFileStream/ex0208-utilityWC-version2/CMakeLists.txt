cmake_minimum_required(VERSION 3.2.6)

project(ex0208CountUtility LANGUAGES C)

message("example02-08 wc utility")

add_executable(ex0208CountUtility)

target_sources(ex0208CountUtility PRIVATE main.c)