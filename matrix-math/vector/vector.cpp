#include "vector.h"

#define VECTOR_SIMD
#ifdef VECTOR_SIMD
#pragma message("Using Vector SIMD Implementation")
#include "vector_simd.h"
#endif

namespace mm {

float operator*(const Vector3& one, const Vector3& two) {
#ifdef VECTOR_SIMD
    return simd::__vectorSIMDDot(one, two);
#else
    return one.x * two.x + one.y * two.y + one.z * two.z;
#endif
}

float norm(const Vector3& vector) { return sqrt(vector * vector); }

Vector3 cross(const Vector3& one, const Vector3& two) {
#ifdef VECTOR_SIMD
    return simd::__vectorSIMDCross(one, two);
#else
    return Vector3{
        one.y * two.z - one.z * two.y,
        one.z * two.x - one.x * two.z,
        one.x * two.y - one.y * two.x,
    };
#endif
}

bool isApprox(const Vector3& one, const Vector3& two, double atol,
              double rtol) {
    return utils::isApprox(one.x, two.x, atol, rtol) and
           utils::isApprox(one.y, two.y, atol, rtol) and
           utils::isApprox(one.z, two.z, atol, rtol);
}

Vector3 operator+(const Vector3& one, const Vector3& two) {
    return Vector3{one.x + two.x, one.y + two.y, one.z + two.z};
}

Vector3 operator-(const Vector3& one, const Vector3& two) {
    return Vector3{one.x - two.x, one.y - two.y, one.z - two.z};
}

bool operator==(const Vector3& one, const Vector3& two) {
    return isApprox(one, two);
}

Vector3 operator*(const float scalar, const Vector3& vector) {
    return Vector3{scalar * vector.x, scalar * vector.y, scalar * vector.z};
}

Vector3 operator/(const float scalar, const Vector3& vector) {
    return Vector3{scalar / vector.x, scalar / vector.y, scalar / vector.z};
}

Vector3 operator+(const float scalar, const Vector3& vector) {
    return Vector3{scalar + vector.x, scalar + vector.y, scalar + vector.z};
}

Vector3 operator-(const float scalar, const Vector3& vector) {
    return Vector3{scalar - vector.x, scalar - vector.y, scalar - vector.z};
}
std::ostream& operator<<(std::ostream& os, const Vector3& vector) {
    os << "[" << vector.x << ", " << vector.y << ", " << vector.z << "]";
    return os;
}

}  // namespace mm