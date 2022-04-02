# Benchmarking 
This is the folder that contains the actual benchmarking of SIMD vs Scalar instructions. 

# Matrix Math

The methodology is to test the Scalar and vectorized code independently. I'll run a million operations and average the execution time of each.

Unfortunately there's not really a difference, because the compiler can pretty easily figure out how to optimize the scalar code to be vectorized. It even appears that my manually tuned vector code is a bit slower!

|             | Cross Product | Dot Product |
|-------------|---------------|-------------|
| Scalar Code | 19.3039ns     | 20.6329ns   |
| Vectorized  | 20.2599ns     | 25.2215ns   |

# Vectorized Loop

# References
1. Tables Generator Project, _Markdown Tables generator - TablesGenerator.com_, https://www.tablesgenerator.com/markdown_tables
2. Chrys Woods, _Efficient Vectorization with C++ - Part 1: Memory Layout_, https://chryswoods.com/vector_c++/memory.html