cmake_minimum_required(VERSION 3.2.6)

project(ex0101SemaphoreBasic LANGUAGES C)

message("example01-01 semaphore basic")

add_executable(ex0101SemaphoreBasic)

target_sources(ex0101SemaphoreBasic PRIVATE main.c)