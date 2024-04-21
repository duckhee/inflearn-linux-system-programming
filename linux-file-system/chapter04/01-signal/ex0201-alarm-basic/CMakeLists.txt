cmake_minimum_required(VERSION 3.2.6)

project(ex0201BasicAlarm LANGUAGES C)

message("example02-01 basic alarm")

add_executable(ex0201BasicAlarm)

target_sources(ex0201BasicAlarm PRIVATE main.c)