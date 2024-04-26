cmake_minimum_required(VERSION 3.2.6)

project(ex0201MessageQueueClient LANGUAGES C)

message("example02-01 message queue client")

add_executable(ex0201MessageQueueClient)

target_sources(ex0201MessageQueueClient PRIVATE main.c)