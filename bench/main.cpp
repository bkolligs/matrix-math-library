#include "main.h"

/**
 * Print out the results to a file
 */
void analyzeResults(std::ofstream& outfile) {
    std::cout << "Analyzing Results" << std::endl;
    outfile << "\nOverall Results\n------------------------------------"
            << std::endl;
    for (auto item : bench::TimeResults) {
        double mean = 0.0;
        /* Accumulate the times from this timer operation */
        for (int time : item.second) {
            mean += time;
        }
        /* Calculate the mean */
        mean /= item.second.size();

        /* Print out mean with the name*/
        outfile << "[" << item.first << "]"
                << "\n\tAverage duration: " << mean << "ns" << std::endl;
    }

    std::cout << "Finished!" << std::endl;
}

void manualVectorTests(std::ofstream& outfile, int numberOfTests) {
    /* Set up the vectors */
    mm::Vector3 v1{-0.9, 0.2, 3.0};
    mm::Vector3 v2{5.1, -1.0, 8.0};
    /* Test the Dot product multiple times */
    std::cout << "Starting Dot Product Tests" << std::endl;
    for (int i = 0; i < numberOfTests; i++) {
        bench::Timer timer(outfile, "Custom Dot Product");
        float v3 = v1 * v2;
    }
    std::cout << "Starting Cross Product Tests" << std::endl;
    /* Test the Cross product multiple times */
    for (int i = 0; i < numberOfTests; i++) {
        bench::Timer timer(outfile, "Custom Cross Product");
        mm::Vector3 v3 = mm::cross(v1, v2);
    }
}

void loopTests(std::ofstream& outfile, int numberOfTests) {
    std::cout << "Starting Scalar Loop Tests" << std::endl;
    float alpha    = 1.0;
    float beta     = 2.5;
    float gamma    = 0.0;
    const int size = 512;
    std::array<float, size> a, b, c;
    for (int j = 0; j < size; j++) {
        a[j] = alpha * (j + 1);
        b[j] = beta * (j + 1);
        c[j] = gamma;
    }

    {
        bench::Timer timer(outfile, "Scalar Loop");
        for (int i = 0; i < numberOfTests; i++) {
            for (int i = 0; i < size; i++) {
                c[i] = a[i] + b[i];
            }
        }
    }

    std::cout << "Starting Vectorized Loop Tests" << std::endl;
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

    {
        bench::Timer inner(outfile, "Vectorized Loop");
        for (int i = 0; i < numberOfTests; i++) {
            for (int i = 0; i < size / 8; i++) {
                avx_c[i] = _mm256_add_ps(avx_a[i], avx_b[i]);
            }
        }
    }
}

int main(int argc, char const* argv[]) {
    /* Pass build type to the executable */
    bool scalarCode   = false;
    int numberOfTests = 1000000;
    if (argc > 1) scalarCode = true;
    std::cout << "Benchmarking Tests for "
              << (scalarCode ? "scalar" : "vectorized") << " code" << std::endl;

    /* Output data to a file */
    std::ofstream outfile(
        scalarCode ? "../logs/bench-scalar.txt" : "../logs/bench-vector.txt",
        std::ofstream::out);

    /* Time the whole cycle */
    bench::Timer timer(outfile, "Entire Test Cycle");

    manualVectorTests(outfile, 100);
    loopTests(outfile, numberOfTests);

    analyzeResults(outfile);

    return 0;
}
