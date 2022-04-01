#include "utils.h"
namespace mm {

namespace utils {

double norm(double x) { return sqrt(x * x); }

bool isApprox(double x, double y, double atol, double rtol) {
    return norm(x - y) <= std::max(atol, rtol * std::max(norm(x), norm(y)));
}
}  // namespace utils

}  // namespace mm