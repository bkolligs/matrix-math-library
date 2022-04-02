#include "vector.h"
#include <immintrin.h>

/**
 * Big Endian or Little Endian
 */
#define MM_ENDIAN_LITTLE


namespace mm {

namespace simd {

float __vectorSIMDDot(const Vector3& one, const Vector3& two);
Vector3 __vectorSIMDCross(const Vector3& one, const Vector3& two); 

}  // namespace simd

}  // namespace mm
