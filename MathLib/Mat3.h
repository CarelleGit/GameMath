#pragma once
#include "Vec3.h"
union mat3
{
	float m[9];
	float mm[3][3];
	vec3 c[3];
	vec3 &operator[](size_t idx);
	const vec3 &operator[](size_t idx) const;
};
mat3 operator+(const mat3 &a, const mat3 &b);
mat3 operator-(const mat3 &a, const mat3 &b);
mat3 operator*(const mat3 &a, const mat3 &b);
mat3 operator*(const mat3 &a, const vec3 &b);
mat3 transpose(const mat3 &a);
float determinant(const mat3 &a);
mat3 inverse(const mat3 &a);