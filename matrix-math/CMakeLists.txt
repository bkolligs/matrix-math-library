add_library(matrix-math
	matrix/matrix.cpp
	vector/vector.cpp
	vector/vector_simd.cpp
	utils/utils.cpp
)

target_include_directories(matrix-math PUBLIC
	.
	matrix
	utils
	vector
)

# can use the flag -fopt-info to print out optimizations
target_compile_options(matrix-math PUBLIC -mavx2)