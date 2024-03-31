cmake_minimum_required(VERSION 3.2.6)

project(ex0203MultiChildProcessSignalProblem LANGUAGES C)

message("example02-03 multi child process problem in signal function")

add_executable(ex0203MultiChildProcessSignalProblem)

target_sources(ex0203MultiChildProcessSignalProblem PRIVATE main.c)