cmake_minimum_required(VERSION 3.5)

project(Bhaskara VERSION 0.1.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

include_directories(${CMAKE_BINARY_DIR})

find_package(Qt5 COMPONENTS Widgets REQUIRED)

configure_file(version.h.in version.h)

add_subdirectory(src)
