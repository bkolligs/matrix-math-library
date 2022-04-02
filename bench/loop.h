#pragma once
#ifdef __AVX2__
    #include <immintrin.h>
#else
    #warning AVX not supported! This code will not compile
#endif

#include <array>

namespace loop {

void scalarLoop(float alpha, float beta, float gamma);
/**
 * Vectorized a loop by performing "unrolling"
 */
void vectorizedLoop(float alpha, float beta, float gamma);

}  // namespace loop