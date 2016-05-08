cmake_minimum_required(VERSION 3.5)
project(Project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    CandidateList.cpp
    CandidateList.h
    CandidateType.cpp
    CandidateType.h
    InputHandler.h
    Main.cpp
    PersonType.cpp
    PersonType.h)

add_executable(Project ${SOURCE_FILES})