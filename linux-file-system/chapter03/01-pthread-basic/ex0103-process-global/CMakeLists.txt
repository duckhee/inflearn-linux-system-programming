cmake_minimum_required(VERSION 3.2.6)

project(ex0103ProcessGlobalAccess LANGUAGES C)

message("example01-03 process global access child process -> copy on write")

add_executable(ex0103ProcessGlobalAccess)

target_sources(ex0103ProcessGlobalAccess PRIVATE main.c)