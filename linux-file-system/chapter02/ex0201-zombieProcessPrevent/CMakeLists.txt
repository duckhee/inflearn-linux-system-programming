cmake_minimum_required(VERSION 3.2.6)

project(ex0201ZombieProcessPrevent LANGUAGES C)

message("example02-01 zombie process prevent -> parent call wait")

add_executable(ex0201ZombieProcessPrevent)

target_sources(ex0201ZombieProcessPrevent PRIVATE main.c)

