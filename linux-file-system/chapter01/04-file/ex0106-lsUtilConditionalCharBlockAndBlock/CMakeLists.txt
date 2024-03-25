cmake_minimum_required(VERSION 3.2.6)

project(ex0106LsUtilConditionalCharBlockAndBlock LANGUAGES C)

message("example01-06 ls utility create")

add_executable(ex0106LsUtilConditionalCharBlockAndBlock)

target_sources(ex0106LsUtilConditionalCharBlockAndBlock PRIVATE main.c)