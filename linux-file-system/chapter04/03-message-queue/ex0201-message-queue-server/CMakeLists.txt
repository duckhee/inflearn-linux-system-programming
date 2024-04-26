cmake_minimum_required(VERSION 3.2.6)

project(ex0201MessageQueueServer LANGUAGES C)

message("example02-01 message queue server")

add_executable(ex0201MessageQueueServer)

target_sources(ex0201MessageQueueServer PRIVATE main.c)