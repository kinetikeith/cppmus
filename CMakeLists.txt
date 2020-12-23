cmake_minimum_required(VERSION 3.19)

project(cppmus VERSION 0.0.1)

add_subdirectory(rtaudio)

include_directories(include rtaudio)
add_subdirectory(src)

set(TARGET cppmus-test)

add_executable(${TARGET} src/main.cpp)

target_link_libraries(${TARGET} cppmus-core rtaudio)

