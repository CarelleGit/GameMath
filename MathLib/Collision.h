#pragma once
#include "Vec2.h"
#include "mathutils.h"
#include "shapes.h"
#include <cmath>
struct Collision
{
	float penetrationDepth;
	float handedness; 
	vec2 axis;
};
Collision intersect_1D(float aMin, float aMax, float bMin, float bMax);
Collision intersect_AABB(const AABB &a, const AABB &b);
Collision intersect_circle(const circle &a, const circle &b);

void static_resolution(vec2 &pos, vec2 &vel, const Collision &hit, float elasticity);

void dynamic_resolution(vec2 &aPos, vec2 &aVel, float aMass, vec2 &bPos, vec2 bVel, float bMass, const Collision &hit, float elasticity = 1.0f);