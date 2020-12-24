cmake_minimum_required(VERSION 3.19)

project(cppmus VERSION 0.0.1)

option(BUILD_TEST "Build the test program" OFF)

if(BUILD_TEST)
    add_subdirectory(rtaudio)

include_directories(include rtaudio)
add_subdirectory(src)

set(TARGET cppmus-test)

if(BUILD_TEST)
    
    add_executable(${TARGET} src/test.cpp)

    target_link_libraries(
        ${TARGET}
        cppmus-core
        cppmus-play
        rtaudio
        )
    
endif()
