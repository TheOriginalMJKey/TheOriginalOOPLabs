find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTests
    test_npc.cpp
    test_npc_factory.cpp
    test_npc_visitor.cpp
    test_observer.cpp
    test_battle_manager.cpp
    test_file_manager.cpp
)

target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
