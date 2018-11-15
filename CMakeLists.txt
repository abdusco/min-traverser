cmake_minimum_required(VERSION 3.8)
project(project3)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp
        Node.h Node.cpp
        Tarjan.h Tarjan.cpp
        InputParser.cpp InputParser.h
        )

add_executable(project3 ${SOURCE_FILES})