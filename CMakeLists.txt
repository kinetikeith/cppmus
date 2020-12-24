cmake_minimum_required(VERSION 3.19)

project(cppmus VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(BUILD_CORE "Build core library" ON)
option(BUILD_PLAY "Build play library" OFF)
option(BUILD_TEST "Build the test program" OFF)

if(BUILD_PLAY)

    add_subdirectory(rtaudio)
    
endif()
    
include_directories(include rtaudio)
add_subdirectory(src)
