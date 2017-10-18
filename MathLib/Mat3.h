#pragma once
#include "Vec3.h"
union mat3
{
	vec3 c[3];
	float m[9];
	float mm[3][3];
	vec3 &operator[](size_t idx); 
	const vec3 &operator[](size_t idx) const;
	static mat3 identity();
	static mat3 zero() { return mat3{0, 0, 0, 0, 0, 0, 0, 0, 0}; };
};
bool operator==(const mat3 &a, mat3 &b);
mat3 operator+(const mat3 &a, const mat3 &b);
mat3 operator-(const mat3 &a, const mat3 &b);
mat3 operator*(const mat3 &a, const mat3 &b);
vec3 operator*(const mat3 &a, const vec3 &b);
mat3 transpose(const mat3 &a);
float determinant(const mat3 &a);
mat3 inverse(const mat3 &a);
mat3 translation(const vec2 &t);
mat3 scale(const vec2 &s);
mat3 rotate(float deg);
