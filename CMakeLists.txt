cmake_minimum_required(VERSION 3.10)
project(ChocolateSplitter)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(chocolate_splitter src/main.cpp src/chocolate.cpp)

enable_testing()
add_subdirectory(tests)
