cmake_minimum_required(VERSION 3.16)
project(trilang_text_analyzer LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(text_analyzer_c c/text_analyzer.c)
add_executable(text_analyzer_cpp cpp/text_analyzer.cpp)
