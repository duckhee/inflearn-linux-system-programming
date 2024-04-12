cmake_minimum_required(VERSION 3.2.6)

project(ex0103FutexSleepLock LANGUAGES C)

message("example01-03 mutex futex sleep lock")

add_executable(ex0103FutexSleepLock)

target_sources(ex0103FutexSleepLock PRIVATE main.c)

