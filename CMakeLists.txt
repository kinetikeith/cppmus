cmake_minimum_required(VERSION 3.19)

project(cppmus VERSION 0.0.1)

include_directories(include)
add_subdirectory(src)

set(TARGET cppmus-test)

add_executable(${TARGET})

target_link_libraries(cppmus-test cppmus-core)

