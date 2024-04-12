cmake_minimum_required(VERSION 3.2.6)

project(ex0101MutexConcept LANGUAGES C)

message("example01-01 mutex concept")

add_executable(ex0101MutexConcept)

target_sources(ex0101MutexConcept PRIVATE main.c customerror.h)