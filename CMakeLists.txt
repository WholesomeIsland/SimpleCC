# CMakeList.txt : CMake project for SimpleCToC, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("SimpleCToC")

add_executable (SimpleCToC "SimpleCToC.cpp" "SimpleCToC.h" "keywords.h")
