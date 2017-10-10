#pragma once

union vec2
{
	struct { float x, y; };
};

vec2 operator+(const vec2 &lhs, const vec2 &rhs);
vec2 &operator+=(vec2 &lhs, const vec2 &rhs);
bool operator == (const vec2 &lhs, const vec2 rhs);
vec2 operator-(const vec2 &lhs, const vec2 &rhs);
vec2 operator*(const vec2 &lhs, const vec2 &rhs);
vec2 operator/(const vec2 &lhs, const vec2 &rhs);
vec2 operator|(const vec2 &lhs, const vec2 &rhs);
bool operator != (const vec2 &lhs, const vec2 rhs);
