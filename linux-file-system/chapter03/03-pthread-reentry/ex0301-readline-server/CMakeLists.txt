cmake_minimum_required(VERSION 3.2.6)

find_package(Threads)

project(ex0301ReadLineServer LANGUAGES C)

message("example03-01 read line server")

add_executable(ex0301ReadLineServer)

target_link_libraries(ex0301ReadLineServer PRIVATE Threads::Threads)

target_sources(ex0301ReadLineServer PRIVATE main.c)