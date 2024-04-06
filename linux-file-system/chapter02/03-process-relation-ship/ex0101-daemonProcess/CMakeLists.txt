cmake_minimum_required(VERSION 3.2.6)

project(ex0101DaemonProcess LANGUAGES C)

message("example01-01 daemon process basic")

add_executable(ex0101DaemonProcess)

target_sources(ex0101DaemonProcess PRIVATE main.c)