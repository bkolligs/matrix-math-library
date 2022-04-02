#include "loop.h"

int main() {
    const int size = 512;

    std::array<float, size> a, b, c;

    std::array<__m256, size / 8> avx_a, avx_b, avx_c;

    for (int i = 0; i < size; ++i) {
        a[i] = 1.0 * (i + 1);
        b[i] = 2.5 * (i + 1);
        c[i] = 0.0;
    }

    for (int i = 0; i < size; i += 8) {
        avx_a[i / 8] = _mm256_set_ps(1.0 * (i + 7 + 1), 1.0 * (i + 6 + 1),
                                     1.0 * (i + 5 + 1), 1.0 * (i + 4 + 1),
                                     1.0 * (i + 3 + 1), 1.0 * (i + 2 + 1),
                                     1.0 * (i + 1 + 1), 1.0 * (i + 0 + 1));

        avx_b[i / 8] = _mm256_set_ps(2.5 * (i + 7 + 1), 2.5 * (i + 6 + 1),
                                     2.5 * (i + 5 + 1), 2.5 * (i + 4 + 1),
                                     2.5 * (i + 3 + 1), 2.5 * (i + 2 + 1),
                                     2.5 * (i + 1 + 1), 2.5 * (i + 0 + 1));

        avx_c[i / 8] = _mm256_set1_ps(0.0);
    }

    std::ofstream outfile("../logs/bench-loops.txt", std::ofstream::out);
    uint numberOfTests = 2E6;
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

    start = std::chrono::high_resolution_clock::now();
    for (int j = 0; j < numberOfTests; ++j) {
        for (int i = 0; i < size; ++i) {
            c[i] = a[i] + b[i];
        }
    }
    end = std::chrono::high_resolution_clock::now();

    auto firstDuration = end - start;

    start = std::chrono::high_resolution_clock::now();
    for (int j = 0; j < numberOfTests; ++j) {
        for (int i = 0; i < size / 8; ++i) {
            avx_c[i] = _mm256_add_ps(avx_a[i], avx_b[i]);
        }
    }
    end = std::chrono::high_resolution_clock::now();
    auto secondDuration = end - start;
    firstDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(firstDuration);
    secondDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(secondDuration);

    std::cout << "Two times: " << firstDuration.count() << ", Second: " << secondDuration.count() << std::endl;

    return 0;
}
