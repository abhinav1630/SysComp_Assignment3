cmake_minimum_required(VERSION 3.23)
project(SysComp_Assignment3)

set(CMAKE_CXX_STANDARD 14)

add_executable(SysComp_Assignment3 Option.h Option.cpp Pricing_Method.h Option_Price.h Option_Price.cpp main.cpp)
