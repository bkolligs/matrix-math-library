#pragma once
#include <math.h>
#include <iostream>
#include "core.h"
#include "utils.h"

namespace mm {

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

float norm(const Vector3& vector);
Vector3 cross(const Vector3& one, const Vector3& two);
bool isApprox(const Vector3&one, const Vector3& two, double atol=0, double rtol=std::numeric_limits<double>::epsilon());

std::ostream& operator<<(std::ostream& os, const Vector3& vector);
/* Dot product is overloading here, not element wise */
float operator*(const Vector3& one, const Vector3& two);
Vector3 operator+(const Vector3& one, const Vector3& two);
Vector3 operator-(const Vector3& one, const Vector3& two);
bool operator==(const Vector3&one, const Vector3& two);

/* Operations with scalars */
Vector3 operator*(const float scalar, const Vector3& vector);
Vector3 operator/(const float scalar, const Vector3& vector);
Vector3 operator+(const float scalar, const Vector3& vector);
Vector3 operator-(const float scalar, const Vector3& vector);

}  // namespace mm