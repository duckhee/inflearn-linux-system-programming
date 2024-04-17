cmake_minimum_required(VERSION 3.2.6)

find_package(Threads)

project(ex0203PthreadReEntryPthreadKey LANGUAGES C)

message("example02-03 pthread re entry pthread key")

add_executable(ex0203PthreadReEntryPthreadKey)

target_link_libraries(ex0203PthreadReEntryPthreadKey LINK_PRIVATE Threads::Threads)

target_sources(ex0203PthreadReEntryPthreadKey PRIVATE main.c)