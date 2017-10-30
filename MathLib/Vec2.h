#pragma once

union vec2
{
	float v[2];
	struct { float x, y; };

	float &operator[](unsigned idx);
	float operator[](unsigned idx) const;
};

vec2 operator+(const vec2 &lhs, const vec2 &rhs);
vec2 &operator+=(vec2 &lhs, const vec2 &rhs);
bool operator == (const vec2 &lhs, const vec2 rhs);
vec2 operator-(const vec2 &lhs, const vec2 &rhs);
vec2 operator*(const vec2 &lhs, const vec2 &rhs);
vec2 operator*(const vec2 &lhs, const float rhs);
vec2 operator*(const float lhs, const vec2 &rhs);
vec2 operator/(const vec2 &lhs, const vec2 &rhs);
vec2 operator/(const vec2 & lhs, const float rhs);
vec2 operator-( vec2 &rhs);
bool operator != (const vec2 &lhs, const vec2 rhs);
vec2 &operator-=(vec2 &lhs, const vec2 &rhs);
vec2 &operator*=(vec2 &lhs, const float &rhs);
vec2 &operator/=(vec2 &lhs, const float rhs);
float mag(const vec2 &v);
vec2 norm(const vec2 &V);
vec2 &Normalize(vec2 &v);
float dot(const vec2 &a, const vec2 &b);
float dist(const vec2 &a, const vec2 &b);
vec2 prep(const vec2 &v);
vec2 lerp(const vec2 &s, const vec2 &e, float a);
vec2 min(const vec2 &a, const vec2 &b);
vec2 max(const vec2 &a, const vec2 &b);


