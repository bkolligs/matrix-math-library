add_library(timer
	timer.cpp
)

add_executable(loop loop.cpp)
target_compile_options(loop PUBLIC -mavx2 -O2)
target_link_libraries(loop PUBLIC timer)

add_executable(vectors vectors.cpp)
target_link_libraries(vectors PUBLIC
	matrix-math
	timer
)