cmake_minimum_required(VERSION 3.2.6)

project(ex0103FileLinkedListNumber LANGUAGES C)

message("example01-03 file ls command utility")

add_executable(ex0103FileLinkedListNumber)

target_sources(ex0103FileLinkedListNumber PRIVATE main.c)
