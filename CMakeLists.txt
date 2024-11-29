cmake_minimum_required(VERSION 3.10)

# Project Name
project(Miniistagram)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Compiler Flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color=always -g")

# Add Executable
add_executable(Miniistagram main.cpp user.cpp validations.cpp insta.cpp friendrequest.cpp)
