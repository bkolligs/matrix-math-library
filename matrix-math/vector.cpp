#include "vector.h"

namespace mm
{
	

std::ostream& operator<<(std::ostream& os, const Vector3& vector) {
	os << "[" << vector.x << ", " << vector.y << ", " << vector.z << "]";
	return os;
}

} // namespace mm