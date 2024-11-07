cmake_minimum_required(VERSION 3.11)
project(StudentuRusiavimas)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file (GLOB SOURCES "src/*.cpp")
add_executable(StudentuRusiavimas ${SOURCES})
