#pragma once
#define VECTOR_SIMD

#include <chrono>
#include <eigen3/Eigen/Core>
#include <fstream>
#include <glm/glm.hpp>
#include <iostream>
#include <string>
#include <unordered_map>
#include "matrix_math.h"
#include "loop.h"

namespace bench {

/* These are globals in this namespace */
std::unordered_map<std::string, std::vector<long>> TimeResults;
std::unordered_map<std::string, std::vector<uint>> TimerIDs;
/* Timers start at 0 */
uint TimerID = 0;

/**
 * This timer class starts timing when it is brought into scope, and stops when
 * it is destroyed. It outputs results to the file stream passed to the
 * constructor
 */
class Timer {
    private:
        bool verbose_;
        std::string timerName_;
        uint timerID_;
        std::ofstream& outFile_;
        std::chrono::time_point<std::chrono::high_resolution_clock> startPoint_;
        std::chrono::time_point<std::chrono::high_resolution_clock> endPoint_;

    public:
        Timer(std::ofstream& out, const std::string& name, bool verbose = false)
            : outFile_{out}, timerName_{name}, verbose_{verbose} {
            /* Add this timer to the global storage */
            timerID_ = TimerID++;
            TimerIDs[name].push_back(timerID_);
            startPoint_ = std::chrono::high_resolution_clock::now();
        }
        ~Timer() {
            endPoint_ = std::chrono::high_resolution_clock::now();
            /* Now convert the time of the endpoint into microseconds, and  get
             * the integer time since epoch*/
            auto start = std::chrono::time_point_cast<std::chrono::nanoseconds>(
                             startPoint_)
                             .time_since_epoch()
                             .count();
            auto end = std::chrono::time_point_cast<std::chrono::nanoseconds>(
                           endPoint_)
                           .time_since_epoch()
                           .count();

            /* Output duration in milliseconds */
            long duration       = (end - start);
            double milliseconds = duration * 1E-6;

            /* Store the result in the vector */
            TimeResults[timerName_].push_back(duration);

            if (verbose_) {
                outFile_ << "[" << timerName_ << ":" << timerID_ << "] "
                         << "\n\tStart: " << start << "\n\tEnd: " << end
                         << "\n\tDuration: " << duration << "ns ("
                         << milliseconds << "ms)" << std::endl;
            }
        }
};
}  // namespace bench