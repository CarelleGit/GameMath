#include "Vec2.h"
#include <climits>
#include "Mathutils.h"
#include <cmath>
#include <cfloat>
vec2 operator+(const vec2 & lhs, const vec2 & rhs)
{
	vec2 res;
	res.x = lhs.x + rhs.x;
	res.y = lhs.y + rhs.y;
	return res;
}

vec2 &operator+=(vec2 & lhs, const vec2 & rhs)
{
	lhs.x += rhs.x;
	lhs.y += rhs.y;
	return lhs;
}

bool operator==(const vec2 & lhs, const vec2 rhs)
{
	if (abs(lhs.x - rhs.x) < EPSILON && abs(lhs.y - rhs.y) < EPSILON)
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

vec2 operator*(const vec2 & lhs, const float rhs)
{
	vec2 res;
	res.x = lhs.x * rhs;
	res.y = lhs.y * rhs;
	return res;
}

vec2 operator*(const float lhs, const vec2 & rhs)
{
	vec2 res;
	res.x = lhs * rhs.x;
	res.y = lhs * rhs.x;
	return res;
}

vec2 operator/(const vec2 & lhs, const vec2 & rhs)
{
	vec2 res;
	res.x = lhs.x / rhs.x;
	res.y = lhs.y / rhs.x;
	return res;
}

vec2 operator/(const vec2 & lhs, const float rhs)
{
	vec2 res;
	res.x = lhs.x / rhs;
	res.y = lhs.y / rhs;
	return res;
}

vec2 operator-( vec2 & rhs)
{
	vec2 res;
	res.x = -rhs.x;
	res.y = -rhs.y;
	return res;
}

bool operator!=(const vec2 & lhs, const vec2 rhs)
{
	if (abs(lhs.x - rhs.x) < EPSILON && abs(lhs.y - rhs.y) < EPSILON)
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

vec2 & operator*=(vec2 & lhs, const float & rhs)
{
	lhs.x *= rhs;
	lhs.y *= rhs;
	return lhs;
}

vec2 &operator/=( vec2 & lhs, const float rhs)
{
	//lhs.x = lhs.x / rhs;
	lhs.x = lhs.x / rhs;
	lhs.y = lhs.y / rhs;
	return lhs;
}

float mag(const vec2 & v)
{
	float aSqr = v.x * v.x;
	float bSqr = v.y * v.y;
	return sqrt(aSqr + bSqr);
}

vec2 norm(const vec2 &V)
{
	vec2 temp = V;
	float len = mag(V);
	temp /= len;
	return temp;
}

vec2 &Normalize(vec2 & v)
{
	v = norm(v);
	return v;
}

float dot(const vec2 & a, const vec2 & b)
{

	return a.x * b.x + a.y * b.y;
}

float dist(const vec2 & a, const vec2 & b)
{
	return mag(b - a);
}

vec2 prep(const vec2 & v)
{
	return vec2{v.y, -v.x};
}

vec2 lerp(const vec2 & s, const vec2 & e, float a)
{
	return s + a * (e - s);
}

vec2 min(const vec2 & a, const vec2 & b)
{
	vec2 retval;
	retval.x = fmin(a.x, b.x);
	retval.y = fmin(a.y, b.y);
	return retval;
}

vec2 max(const vec2 & a, const vec2 & b)
{
	vec2 retval;
	retval.x = fmax(a.x, b.x);
	retval.y = fmax(a.y, b.y);
	return retval;
}

vec2 projection(const vec2 & v, const vec2 & axis)
{
	return dot(v,axis) * axis;
}

vec2 reflect(const vec2 & v, const vec2 & axis)
{
	vec2 displacment = projection(v, axis) - v;
	return displacment + projection(v, axis);
}



float &vec2::operator[](unsigned idx)
{
	
	return v[idx];
}

float vec2::operator[](unsigned idx) const
{
	return v[idx];
}
