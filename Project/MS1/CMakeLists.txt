cmake_minimum_required(VERSION 3.15)
project(MS1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MS1
        Inventory1.dat
        Inventory2.dat
        Item.cpp
        Item.h
        ms1.cpp
        Utilities.cpp
        Utilities.h)
