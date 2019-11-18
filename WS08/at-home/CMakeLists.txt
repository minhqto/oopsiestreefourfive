cmake_minimum_required(VERSION 3.15)
project(at_home)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(at_home
        BadPrices.dat
        Descriptions.dat
        Element.h
        List.h
        Prices.dat
        sample_output
        Utilities.cpp
        Utilities.h
        w8_home.cpp)
