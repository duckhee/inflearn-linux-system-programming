cmake_minimum_required(VERSION 3.2.6)

find_package(Threads)

project(ex0201PthreadStrtokReEntry LANGUAGES C)

message("example02-01 strtok re entry")

add_executable(ex0201PthreadStrtokReEntry)

target_link_libraries(ex0201PthreadStrtokReEntry PRIVATE Threads::Threads)

target_sources(ex0201PthreadStrtokReEntry PRIVATE main.c)