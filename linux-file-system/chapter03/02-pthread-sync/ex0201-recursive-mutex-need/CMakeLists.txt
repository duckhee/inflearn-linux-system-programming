cmake_minimum_required(VERSION 3.2.6)

project(ex0201RecursiveMutexNeedToCode LANGUAGES C)

message("example02-01 recursive mutex need to code -> dead lock make")

add_executable(ex0201RecursiveMutexNeedToCode)

target_sources(ex0201RecursiveMutexNeedToCode PRIVATE main.c)

