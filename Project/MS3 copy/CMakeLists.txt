cmake_minimum_required(VERSION 3.15)
project(MS3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MS3
        AssemblyLine.dat
        CustomerOrder.cpp
        CustomerOrder.h
        CustomerOrders.dat
        Inventory1.dat
        Inventory2.dat
        Item.cpp
        Item.h
        ms3.cpp
        Utilities.cpp
        Utilities.h Task.h Task.cpp LineManager.h LineManager.cpp)
