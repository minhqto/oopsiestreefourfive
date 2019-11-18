cmake_minimum_required(VERSION 3.15)
project(in_lab)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(in_lab
        BadPrices.dat
        Descriptions.dat
        Element.h
        List.h
        Prices.dat
        sample_output
        Utilities.cpp
        Utilities.h
        w8_lab.cpp)
