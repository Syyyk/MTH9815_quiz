cmake_minimum_required(VERSION 3.10)

project(TEST)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES "code/*.cpp")
add_executable(myapp ${SOURCES})
