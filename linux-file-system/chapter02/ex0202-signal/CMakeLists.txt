cmake_minimum_required(VERSION 3.2.6)

project(ex0202SignalSendProcess LANGUAGES C)

message("example02-02 process send signal")

add_executable(ex0202SignalSendProcess)

target_sources(ex0202SignalSendProcess PRIVATE main.c)

set_target_properties(ex0202SignalSendProcess PROPERTIES C_STANDARD 99 C_STANDARD_REQUIRED ON)