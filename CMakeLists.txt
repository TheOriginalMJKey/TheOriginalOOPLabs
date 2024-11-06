cmake_minimum_required(VERSION 3.10)
project(BinaryContainer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(binary_container src/main.cpp src/binary.cpp)

enable_testing()
add_subdirectory(tests)
