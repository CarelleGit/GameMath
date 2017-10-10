#include "Vec2.h"
#include <climits>
#include <cmath>
#include <cfloat>
vec2 operator+(const vec2 & lhs, const vec2 & rhs)
{
	vec2 res;
	res.x = lhs.x + rhs.x;
	res.y = lhs.y + rhs.y;
	return res;
}

vec2 & operator+=(vec2 & lhs, const vec2 & rhs)
{
	lhs.x += rhs.x;
	lhs.y += rhs.y;
	return lhs;
}

bool operator==(const vec2 & lhs, const vec2 rhs)
{
	if (abs(lhs.x - rhs.x) < FLT_EPSILON && abs(lhs.y - rhs.y) < FLT_EPSILON)
	{
		return true;
	}
	return false;
}

vec2 operator-(const vec2 & lhs, const vec2 & rhs)
{
	vec2 res;
	res.x = lhs.x - rhs.x;
	res.y = lhs.y - rhs.y;
	return res;
}

vec2 operator*(const vec2 & lhs, const vec2 & rhs)
{
	vec2 res;
	res.x = lhs.x * rhs.x;
	res.y = lhs.y * rhs.x;
	return res;
}

vec2 operator/(const vec2 & lhs, const vec2 & rhs)
{
	vec2 res;
	res.x = lhs.x / rhs.x;
	res.y = lhs.y / rhs.x;
	return res;
	return res;
}

vec2 operator|(const vec2 & lhs, const vec2 & rhs)
{
	vec2 res;
	res.x = -rhs.x;
	res.y = -rhs.y;
	return res;
}

bool operator!=(const vec2 & lhs, const vec2 rhs)
{
	if (abs(lhs.x - rhs.x) < FLT_EPSILON && abs(lhs.y - rhs.y) < FLT_EPSILON)
	{
		return false;
	}
	return true;
}

vec2 & operator-=(vec2 & lhs, const vec2 & rhs)
{
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;
	return lhs;
}

vec2 & operator*=(vec2 & lhs, const vec2 & rhs)
{
	lhs.x *= rhs.x;
	lhs.y *= rhs.x;
	return lhs;
}

vec2 & operator/=(vec2 & lhs, const vec2 & rhs)
{
	lhs.x /= rhs.x;
	lhs.y /= rhs.x;
	return lhs;
}
