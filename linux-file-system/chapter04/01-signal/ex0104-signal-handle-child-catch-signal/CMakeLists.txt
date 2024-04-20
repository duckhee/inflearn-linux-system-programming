cmake_minimum_required(VERSION 3.2.6)

project(ex0104SignalHandleChildProcess LANGUAGES C)

message("example01-04 signal child process")

add_executable(ex0104SignalHandleChildProcess)

target_sources(ex0104SignalHandleChildProcess PRIVATE main.c)