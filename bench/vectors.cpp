#include "vectors.h"

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
                << "\n\tAverage duration: " << mean << "us" << std::endl;
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

    analyzeResults(outfile);

    return 0;
}
