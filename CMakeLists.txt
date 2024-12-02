cmake_minimum_required(VERSION 3.10)
project(BalagurFate3Editor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(BalagurFate3Editor
    src/main.cpp
    src/npc.cpp
    src/game.cpp
)

enable_testing()
add_subdirectory(tests)
