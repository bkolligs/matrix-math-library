cmake_minimum_required(VERSION 3.16)
project(MATRIX_MATH)
set(CMAKE_CXX_STANDARD 17)
enable_testing()

add_subdirectory(matrix-math)
add_subdirectory(bench)
add_subdirectory(tests)
