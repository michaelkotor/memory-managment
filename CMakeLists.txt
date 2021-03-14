cmake_minimum_required(VERSION 3.17)
project(memory_management)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_VERBOSE_MAKEFILE ON)

enable_testing()

include(ExternalProject)

ExternalProject_Add(
        googletest
        GIT_REPOSITORY "https://github.com/google/googletest"
        GIT_TAG "release-1.10.0"
        PREFIX "${CMAKE_BINARY_DIR}/googletest"
        INSTALL_DIR "${CMAKE_BINARY_DIR}"
        CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}"
)

add_executable(memory_management
        main.cpp
        include/storage.h
        src/storage.cpp
        include/item.h
        include/process.h
        )

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(test)
