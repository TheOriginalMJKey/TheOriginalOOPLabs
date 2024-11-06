add_executable(test_chocolate test_chocolate.cpp ../src/chocolate.cpp)
target_link_libraries(test_chocolate gtest gtest_main)
add_test(NAME test_chocolate COMMAND test_chocolate --gtest_color=yes --gtest_output=xml:test_results.xml)
