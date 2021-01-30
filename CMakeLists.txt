cmake_minimum_required(VERSION 3.8)  # CMake version check
project(scc)               # Create project scc

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES scc.cpp SimpleCToC.h keywords.h)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(scc ${SOURCE_FILES})