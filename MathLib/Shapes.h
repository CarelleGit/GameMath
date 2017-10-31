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

};

circle operator*(const mat3 &m, const circle &c);

AABB operator*(const mat3 &m, const AABB &b);