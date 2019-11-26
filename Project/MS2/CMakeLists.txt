cmake_minimum_required(VERSION 3.15)
project(MS2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MS2
        CustomerOrders.dat
        Item.cpp
        Item.h
        ms2.cpp
        Utilities.cpp
        Utilities.h CustomerOrder.h CustomerOrder.cpp)
