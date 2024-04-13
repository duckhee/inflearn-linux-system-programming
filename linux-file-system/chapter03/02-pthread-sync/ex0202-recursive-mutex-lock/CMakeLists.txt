cmake_minimum_required(VERSION 3.2.6)

find_package (Threads)

project(ex0202RecursiveMutexLock LANGUAGES C)

message("example02-02 recursive mutex lock -> mutex attr")

add_executable(ex0202RecursiveMutexLock)


target_sources(ex0202RecursiveMutexLock PRIVATE main.c)

target_link_libraries(ex0202RecursiveMutexLock LINK_PRIVATE Threads::Threads)