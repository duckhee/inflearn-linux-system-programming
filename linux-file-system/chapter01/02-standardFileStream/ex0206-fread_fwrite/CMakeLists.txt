cmake_minimum_required(VERSION 3.2.6)

project(ex0206fread_fwrite LANGUAGES C)

message("example02-06 standard file input output fread fwrite")

add_executable(ex0206fread_fwrite)

target_sources(ex0206fread_fwrite PRIVATE main.c)

