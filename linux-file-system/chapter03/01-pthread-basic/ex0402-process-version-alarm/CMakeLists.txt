cmake_minimum_required(VERSION 3.2.6)

project(ex0402ProcessVersionAlarm LANGUAGES C)

message("example04-02 process version alarm")

add_executable(ex0402ProcessVersionAlarm)

target_sources(ex0402ProcessVersionAlarm PRIVATE main.c)