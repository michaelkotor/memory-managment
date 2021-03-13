cmake_minimum_required(VERSION 3.17)
project(memory_management)

set(CMAKE_CXX_STANDARD 20)

add_executable(memory_management main.cpp include/storage.h src/storage.cpp include/item.h include/process.h)