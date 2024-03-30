cmake_minimum_required(VERSION 3.2.6)

project(ex0102ForkBasic LANGUAGES C)

message("example01-02 fork function study")

add_executable(ex0102ForkBasic)

target_sources(ex0102ForkBasic PRIVATE main.c)

set_target_properties(ex0102ForkBasic PROPERTIES C_STANDARD 99 C_STANDARD_REQUIRED ON)