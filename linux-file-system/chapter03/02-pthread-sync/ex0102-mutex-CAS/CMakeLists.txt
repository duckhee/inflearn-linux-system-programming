cmake_minimum_required(VERSION 3.2.6)

project(ex0102MutexCAS LANGUAGES C)

message("example01-02 mutex compare and set using assemble code")

add_executable(ex0102MutexCAS)

target_sources(ex0102MutexCAS PRIVATE main.c)