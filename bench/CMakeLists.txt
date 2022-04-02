add_library(loop
	loop.cpp
)
target_compile_options(loop PUBLIC -mavx2 -O2)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC
	matrix-math
	loop
)