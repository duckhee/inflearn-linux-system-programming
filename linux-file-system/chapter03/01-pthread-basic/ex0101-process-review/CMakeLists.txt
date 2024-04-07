cmake_minimum_required(VERSION 3.2.6)

project(ex0101ProcessReview LANGUAGES C)

message("example01-01 pthread before process review")

add_executable(ex0101ProcessReview)

target_sources(ex0101ProcessReview PRIVATE main.c)