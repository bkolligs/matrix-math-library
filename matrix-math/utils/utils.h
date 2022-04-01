#pragma once
#include <math.h>
#include <algorithm>

namespace mm {

namespace utils {

double norm(double x);
bool isApprox(double x, double y, double atol, double rtol);

}  // namespace utils

}  // namespace mm
