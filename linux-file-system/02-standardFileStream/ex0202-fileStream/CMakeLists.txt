cmake_minimum_required(VERSION 3.2.6)

project(ex0202FileStream LANGUAGES C)

message("example02-02 standard file stream stderr")

add_executable(ex0202FileStream)

target_sources(ex0202FileStream PRIVATE main.c)

set_target_properties(ex0202FileStream PROPERTIES C_STANDARD 99 C_STANDARD_REQUIRED ON)