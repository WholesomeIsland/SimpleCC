cmake_minimum_required(VERSION 3.8)  # CMake version check
project(scc)               # Create project scc

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES scc.cpp SimpleCToC.h keywords.h libscc.h ArgParser.h)
add_executable(scc ${SOURCE_FILES})

set_property(TARGET scc PROPERTY CXX_STANDARD 17)
