cmake_minimum_required(VERSION 3.15)
project(in_lab)

set(CMAKE_CXX_STANDARD 14)

add_executable(in_lab
        sample_output.txt
        songs.txt
        w7_lab.cpp SongCollection.h SongCollection.cpp)
