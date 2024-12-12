cmake_minimum_required(VERSION 3.10)
project(BalagurFate3Editor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(BalagurFate3Editor
    src/main.cpp
    src/npc.cpp
    src/npc_factory.cpp
    src/npc_visitor.cpp
    src/observer.cpp
    src/battle_manager.cpp
    src/file_manager.cpp
)

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTests
    tests/test_npc.cpp
    tests/test_npc_factory.cpp
    tests/test_observer.cpp
    tests/test_file_manager.cpp
    src/npc.cpp
    src/npc_factory.cpp
    src/npc_visitor.cpp
    src/observer.cpp
    src/battle_manager.cpp
    src/file_manager.cpp
)

target_link_libraries(runTests ${GTEST_LIBRARIES} pthread gtest_main)
