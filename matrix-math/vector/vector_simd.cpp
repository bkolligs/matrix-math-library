#include "vector_simd.h"

namespace mm
{

namespace simd
{

float __vectorSIMDDot(const Vector3& one, const Vector3& two) {
	/* These registers can hold four floats */
	__m256d _one, _two, _a;
	/* Populate the vectors */
	_one = _mm256_set_pd(one.x, one.y, one.z, 0.0);
	_two = _mm256_set_pd(two.x, two.y, two.z, 0.0);

	/* multiply the vectors together */
	_a = _mm256_mul_pd(_one, _two);

	#ifdef __linux__
		return _a[0] + _a[1] + _a[2] + _a[3];
	#endif

}

Vector3 __vectorSIMDCross(const Vector3& one, const Vector3& two) {
	__m256d _one, _two, _a, _b, _c;
	/* Populate the vectors */
	_one = _mm256_set_pd(one.y, one.z, one.x, 0.0);
	_two = _mm256_set_pd(two.z, two.x, two.y, 0.0);

	/* multiply the vectors together */
	_a = _mm256_mul_pd(_one, _two);

	_one = _mm256_set_pd(one.z, one.x, one.y, 0.0);
	_two = _mm256_set_pd(two.y, two.z, two.x, 0.0);

	_b =_mm256_mul_pd(_one, _two);

	_c = _mm256_sub_pd(_a, _b);

	#if defined(MM_ENDIAN_LITTLE) and defined(__linux__)
		return Vector3{_c[3], _c[2], _c[1]};
	#elif defined(__linux__)
		return Vector3{_c[0], _c[1], _c[2]};
	#endif

}
	
} // namespace simd
	
	
} // namespace mm
