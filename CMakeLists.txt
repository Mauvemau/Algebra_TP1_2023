cmake_minimum_required(VERSION 3.25)
project(TP4)

file(GLOB_RECURSE SOURCES "Algebra_TP1/src/*.cpp")

include_directories(src)
add_executable(TP4 ${SOURCES})

find_package(raylib 4.5.0 REQUIRED)

target_link_libraries(TP4 PRIVATE raylib)
