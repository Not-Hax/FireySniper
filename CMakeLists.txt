cmake_minimum_required(VERSION 3.16)

project(FireySniper VERSION 1.00 LANGUAGES CXX)

if (WIN32)
    add_definitions(-D_ITERATOR_DEBUG_LEVEL=0)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(VENDOR_DIR "${CMAKE_SOURCE_DIR}/vendor")
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(APP_DIR "${CMAKE_SOURCE_DIR}/app")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory(${VENDOR_DIR})
add_subdirectory(${SRC_DIR})
add_subdirectory(${APP_DIR})