cmake_minimum_required(VERSION 3.2.6)

project(ex0210UtilityExtractVersion1 LANGUAGES C)

message("example02-11 file extract utility")

add_executable(ex0210UtilityExtractVersion1)

target_sources(ex0210UtilityExtractVersion1 PRIVATE main.c)
