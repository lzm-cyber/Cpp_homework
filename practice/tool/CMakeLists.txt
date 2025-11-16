cmake_minimum_required(VERSION 3.11)

project(PRACTICE)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXXSTANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)

include_directories(include)

add_executable(cmake_practice_1 ../src/main.cpp Calculator.cpp)
