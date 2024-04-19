cmake_minimum_required(VERSION 3.2.6)

find_package(Threads)

project(ex0301ReadLineClient LANGUAGES C)

message("example03-01 read line client")

add_executable(ex0301ReadLineClient)

target_link_libraries(ex0301ReadLineClient LINK_PRIVATE Threads::Threads)

target_sources(ex0301ReadLineClient PRIVATE main.c)

