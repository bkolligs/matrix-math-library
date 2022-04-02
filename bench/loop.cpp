#include "loop.h"

namespace loop {

void scalarLoop(float alpha, float beta, float gamma) {
    const int size = 512;
    std::array<float, size> a, b, c;
    for (int i = 0; i < size; i++) {
        a[i] = alpha * (i + 1);
        b[i] = beta * (i + 1);
        c[i] = gamma;
    }

    for (int i = 0; i < size; i++) {
        c[i] = a[i] + b[i];
    }
}

void vectorizedLoop(float alpha, float beta, float gamma) {
    const int size = 512;
    /* Can fit 8 32 bit integers in each of these  */
    std::array<__m256, size / 8> avx_a, avx_b, avx_c;

    for (int i = 0; i < size; i += 8) {
        avx_a[i / 8] = _mm256_set_ps(alpha * (i + 7 + 1), alpha * (i + 6 + 1),
                                     alpha * (i + 5 + 1), alpha * (i + 4 + 1),
                                     alpha * (i + 3 + 1), alpha * (i + 2 + 1),
                                     alpha * (i + 1 + 1), alpha * (i + 0 + 1));
        avx_b[i / 8] = _mm256_set_ps(beta * (i + 7 + 1), beta * (i + 6 + 1),
                                     beta * (i + 5 + 1), beta * (i + 4 + 1),
                                     beta * (i + 3 + 1), beta * (i + 2 + 1),
                                     beta * (i + 1 + 1), beta * (i + 0 + 1));
        avx_c[i / 8] = _mm256_set1_ps(0.0);
    }

    for (int i = 0; i < size/8; i++) {
        avx_c[i] = _mm256_add_ps(avx_a[i], avx_b[i]);
    }
}

}  // namespace loop