cmake_minimum_required(VERSION 3.16)
project(MATH_LIBRARY)

add_subdirectory(eigen)
add_subdirectory(glm)
add_subdirectory(intrinsics)

add_executable(main src/main.cpp)