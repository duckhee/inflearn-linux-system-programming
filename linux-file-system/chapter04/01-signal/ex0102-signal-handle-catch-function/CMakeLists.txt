cmake_minimum_required(VERSION 3.2.6)

find_package(Threads)

project(ex0102SignalHandleCatchFunction LANGUAGES C)

message("example01-02 signal handling catch function")

add_executable(ex0102SignalHandleCatchFunction)

target_sources(ex0102SignalHandleCatchFunction PRIVATE main.c)

target_link_libraries(ex0102SignalHandleCatchFunction PRIVATE Threads::Threads)