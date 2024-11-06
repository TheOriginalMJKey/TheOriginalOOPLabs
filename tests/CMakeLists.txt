add_executable(test_binary test_binary.cpp)
target_link_libraries(test_binary gtest gtest_main)
add_test(NAME test_binary COMMAND test_binary)
