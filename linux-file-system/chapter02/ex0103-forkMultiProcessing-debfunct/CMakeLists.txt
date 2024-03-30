cmake_minimum_required(VERSION 3.2.6)

project(ex0103ForkMultiProcessing LANGUAGES C)

message("example01-03 fork multi processing")

add_executable(ex0103ForkMultiProcessing)

target_sources(ex0103ForkMultiProcessing PRIVATE main.c)

set_target_properties(ex0103ForkMultiProcessing PROPERTIES C_STANDARD 99 C_STANDARD_REQUIRED ON)

