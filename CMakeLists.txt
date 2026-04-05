cmake_minimum_required(VERSION 4.0)
project(ErrorHandling)

set(CMAKE_CXX_STANDARD 20)

add_executable(ErrorHandling main.cpp
        FileUtils.cpp
        FileUtils.h
        GeometryUtils.cpp
        GeometryUtils.h
        Exceptions.cpp
        Exceptions.h)
