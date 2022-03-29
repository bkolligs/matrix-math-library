find_package(GTest REQUIRED)

add_executable(test_vector test_vector.cpp)
target_link_libraries(test_vector ${GTEST_LIBRARIES} pthread matrix-math)

gtest_discover_tests(test_vector)