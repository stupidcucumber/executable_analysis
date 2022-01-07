cmake_minimum_required(VERSION 3.21)
project(executable_analysis)

set(CMAKE_CXX_STANDARD 17)

add_executable(executable_analysis main.cpp Functions.h Arithmetic.cpp Arithmetic.h)
