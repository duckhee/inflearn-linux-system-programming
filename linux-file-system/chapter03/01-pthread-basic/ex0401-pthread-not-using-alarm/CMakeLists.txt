cmake_minimum_required(VERSION 3.2.6)

project(ex0401NotUsingThreadAlarm LANGUAGES C)

message("example04-01 thread not using alarm")

add_executable(ex0401NotUsingThreadAlarm)

target_sources(ex0401NotUsingThreadAlarm PRIVATE main.c)