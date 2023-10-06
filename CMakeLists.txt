cmake_minimum_required(VERSION 3.26)
project(Image_Processing)

set(CMAKE_CXX_STANDARD 20)

add_executable(Image_Processing main.cpp
        Functions.cpp
        Functions.h)
include_directories(D:/GitHub/Image_Processing)
add_library(ImageToBitMap STATIC D:/GitHub/Image_Processing/bmplib.cpp)