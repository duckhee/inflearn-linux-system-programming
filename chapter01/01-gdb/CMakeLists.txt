cmake_minimum_required(VERSION 3.27)

project(ex01GDB LANGUAGES C)

target_sources(ex01GDB PRIVATE main.c)

set_target_properties(ex01GDB PROPERTIES C_STANDARD 11 C_STANDARD_REQUIRED ON)