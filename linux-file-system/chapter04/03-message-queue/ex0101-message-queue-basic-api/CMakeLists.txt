cmake_minimum_required(VERSION 3.2.6)

project(ex0101MessageQueueBasicApi LANGUAGES C)

message("example01-01 message queue basic api")

add_executable(ex0101MessageQueueBasicApi)

target_sources(ex0101MessageQueueBasicApi PRIVATE main.c)