# Matrix Math Library
An academic project for myself to understand how SIMD instructions work, and benchmarking against libraries like Eigen, and GLM


## Dependencies
1. Eigen Math Library [ [source](https://gitlab.com/libeigen/eigen)]
```bash
sudo apt install libeigen3-dev
```

2. GLM Math Library [ [source](https://github.com/g-truc/glm)]
```bash
sudo apt install libglm-dev
```

3. Compiler Intrinsics Header `immintrin.h`

## Building
Navigate to the top level of this repo and execute:
```bash
mkdir build
cd build && cmake ..
make
```	

## Sources
1. [ Intrinsic Functions - Vector Processing Extensions, David Barr aka javidx9 @OneLoneCoder ](https://www.youtube.com/watch?v=x9Scb5Mku1g&list=WL&index=14)
2. https://github.com/OneLoneCoder/olcPixelGameEngine/blob/master/Videos/OneLoneCoder_VIDEO_IntrinsicFunctions.cpp
3. [ Adventures in SIMD Thinking, Bob Steagall ](https://www.youtube.com/watch?v=qejTqnxQRcw&t=649s)
4. [ GLM SIMD Implementation ](https://github.com/g-truc/glm/tree/master/glm/simd)
5. [Microsoft Documentation for x86 Intrinsics](https://docs.microsoft.com/en-us/cpp/intrinsics/x86-intrinsics-list?view=msvc-170)
6. [Intel Intrinsics Guide](https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html#)