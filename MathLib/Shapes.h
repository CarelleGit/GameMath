#pragma once
#include "Vec2.h"
#include "Mat3.h"

struct circle
{
	vec2 position;
	float radius;

};

//Axis aligned bounding box
//a rectangle without rotation
struct AABB
{
	vec2 position;
	vec2 extents;

	vec2 MinCorner;
	vec2 MaxCorner;
	vec2 min() const { return position - extents; }
	vec2 max() const { return position + extents; }
};

circle operator*(const mat3 &m, const circle &c);

AABB operator*(const mat3 &m, const AABB &b);