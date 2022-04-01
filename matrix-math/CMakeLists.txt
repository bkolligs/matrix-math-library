add_library(matrix-math
	matrix/matrix.cpp
	vector/vector.cpp
	utils/utils.cpp
)

target_include_directories(matrix-math PUBLIC
	.
	matrix
	utils
	vector
)