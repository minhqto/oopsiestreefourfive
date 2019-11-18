cmake_minimum_required(VERSION 3.15)
project(at_home)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(at_home
        sample_output.txt
        SongCollection.cpp
        SongCollection.h
        songs.txt
        w7_home.cpp)
