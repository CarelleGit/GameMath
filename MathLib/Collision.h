#pragma once
#include "Vec2.h"
#include "Shapes.h"
struct Collision
{
	float penetrationDepth;
	float handedness; 
	vec2 axis;
};
Collision intersect_1D(float aMin, float aMax, float bMin, float bMax);
Collision intersect_AABB(const AABB &a, const AABB &b);
Collision intersect_circle(const circle &a, const circle &b);
Collision intersect_AABB_circle(const AABB &a, const circle &c);