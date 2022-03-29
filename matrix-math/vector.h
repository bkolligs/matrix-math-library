#pragma once
#include "core.h"
#include <iostream>

namespace mm
{
	
struct Vector3 {
	/* Alias the 3 members to access the same data with a different name*/
	union {
		float x, r, u, s;
	};
	union {
		float y, g, v, t;
	};
	union {
		float z, b, w, q;
	};
};

std::ostream& operator<<(std::ostream& os, const Vector3& vector);

} // namespace mm