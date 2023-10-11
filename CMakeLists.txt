cmake_minimum_required(VERSION 3.26)
project(Image_Processing)

set(CMAKE_CXX_STANDARD 20)

add_executable(Image_Processing CS213-2023-20220510-20220533-20220141-A1-Part1.cpp
        Functions.cpp
        Functions.h
        bmplib.cpp bmplib.h
        RGB.h
        RGB.cpp)
include_directories(D:/GitHub/Image_Processing)
add_library(ImageToBitMap STATIC D:/GitHub/Image_Processing/bmplib.cpp)