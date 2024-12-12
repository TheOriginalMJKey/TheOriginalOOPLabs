include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(test_memory_resource
    test_memory_resource.cpp
    ../src/fixed_block_memory_resource.cpp
    ../src/custom_container.cpp
)
target_link_libraries(test_memory_resource gtest gtest_main)
add_test(NAME test_memory_resource COMMAND test_memory_resource)
