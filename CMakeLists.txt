cmake_minimum_required(VERSION 3.10)
project(MemoryResource)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(memory_resource src/main.cpp src/fixed_block_memory_resource.cpp src/custom_container.cpp)

enable_testing()
add_subdirectory(tests)
