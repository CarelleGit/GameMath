#include "Vec3.h"
#include <cmath>
#include <cfloat>
#include"Mathutils.h"
float & vec3::operator[](unsigned idx)
{
	return v[idx];
}

float vec3::operator[](unsigned idx) const
{
	return v[idx];
}

vec3 operator+(const vec3 & lhs, const vec3 & rhs)
{
	vec3 res;
	res.x = lhs.x + rhs.x;
	res.y = lhs.y + rhs.y;
	res.z = lhs.z + rhs.z;
	return res;
}

vec3 operator+=(vec3 & lhs, const vec3 & rhs)
{
	lhs = lhs + rhs;
	return lhs;
}

bool operator==(const vec3 & lhs, const vec3 & rhs)
{
	if (abs(lhs.x - rhs.x) < EPSILON && abs(lhs.y - rhs.y) < EPSILON &&abs(lhs.z - rhs.z) < EPSILON)
	{
		return true;
	}
	return false;
}

vec3 operator-(const vec3 & lhs, const vec3 & rhs)
{
	vec3 res;
	res.x = lhs.x - rhs.x;
	res.y = lhs.y - rhs.y;
	res.z = lhs.z - rhs.z;
	return res;
}
vec3 operator*(const vec3 & lhs, const vec3 & rhs)
{
	vec3 res;
	res.x = lhs.x * rhs.x;
	res.y = lhs.y * rhs.x;
	res.z = lhs.z * rhs.x;
	return res;
}
vec3 operator*(const vec3 & lhs, const float rhs)
{
	vec3 res;
	res.x = lhs.x * rhs;
	res.y = lhs.y * rhs;
	res.z = lhs.z * rhs;
	return res;
}

vec3 operator*(const float lhs, const vec3 & rhs)
{
	vec3 res;
	res.x = lhs * rhs.x;
	res.y = lhs * rhs.y;
	res.z = lhs * rhs.z;
	return res;
}

vec3 operator/(const vec3 & lhs, const vec3 & rhs)
{
	vec3 res;
	res.x = lhs.x / rhs.x;
	res.y = lhs.y / rhs.x;
	res.z = lhs.z / rhs.x;
	return res;
}
vec3 operator/(const vec3 & lhs, const float rhs)
{
	vec3 res;
	res.x = lhs.x / rhs;
	res.y = lhs.y / rhs;
	res.z = lhs.z / rhs;
	return res;
}

bool operator!=(const vec3 & lhs, const vec3 rhs)
{
	if (abs(lhs.x - rhs.x) < EPSILON && abs(lhs.y - rhs.y) < EPSILON &&abs(lhs.z - rhs.z) < EPSILON)
	{
		return false;
	}
	return true;
}

vec3 &operator-=(vec3 & lhs, const vec3 & rhs)
{
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;
	lhs.z -= rhs.z;
	return lhs;
}

vec3 & operator*=(vec3 & lhs, const float & rhs)
{
	lhs.x *= rhs;
	lhs.y *= rhs;
	lhs.z *= rhs;
	return lhs;
}

vec3 & operator/=(vec3 & lhs, const float rhs)
{
	lhs.x = lhs.x / rhs;
	lhs.y = lhs.y / rhs;
	lhs.z = lhs.z / rhs;
	return lhs;
}

float mag(const vec3 & v)
{
	float aSqr = v.x * v.x;
	float bSqr = v.y * v.y;
	float cSqr = v.z * v.z;
	return sqrt(aSqr + bSqr + cSqr);
}

vec3 norm(const vec3 & v)
{
	vec3 temp = v;
	float len = mag(v);
	temp /= len;
	return temp;
}

vec3 & Normalize(vec3 & v)
{
	v = norm(v);
	return v;
}

float dot(const vec3 & a, const vec3 & b)
{
	float x = a.x * b.x;
	float y = a.y * b.y;
	float z = a.z * b.z;
	return x+ y +z;
}

float dist(const vec3 & a, const vec3 & b)
{
	float aLen = mag(a);
	float bLen = mag(b);
	return aLen - bLen;
}

vec3 min(const vec3 & a, const vec3 & b)
{
	vec3 retval;
	retval.x = fmin(a.x, b.x);
	retval.y = fmin(a.y, b.y);
	retval.z = fmin(a.z, b.z);
	return retval;
}

vec3 max(const vec3 & a, const vec3 & b)
{
	vec3 retval;
	retval.x = fmax(a.x, b.x);
	retval.y = fmax(a.y, b.y);
	retval.z = fmin(a.z, b.z);
	return retval;
}

vec3 clamp(const vec3 & sMin, const vec3 & v, const vec3 & sMax)
{
	vec3 temp = v;
	temp = min(temp, sMax);
	temp = max(temp, sMin);
	return temp;
}

vec3 cross(const vec3 & a, const vec3 & b)
{
	return vec3 {a.y*b.z - a.z*b.y,
				 a.z*b.x - a.x*b.z,
				 a.x *b.y - a.y*b.x};
}
