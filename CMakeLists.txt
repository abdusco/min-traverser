cmake_minimum_required(VERSION 3.8)
project(project3)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2")

set(SOURCE_FILES
        main.cpp
        models/InputParser.cpp models/InputParser.h
        models/Node.cpp models/Node.h
        models/TraverseMinimizer.cpp models/TraverseMinimizer.h
        )

add_executable(project3 ${SOURCE_FILES})