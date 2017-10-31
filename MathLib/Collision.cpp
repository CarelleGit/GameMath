#include "Collision.h"
#include "Shapes.h"
#include "Mathutils.h"
#include "Vec2.h"
#include <cmath>
Collision intersect_1D(float aMin, float aMax, float bMin, float bMax)
{
	Collision ret;
	float lPD = bMax - aMin;
	float rPD = aMax - bMin;

	ret.penetrationDepth = min(lPD, rPD);
	ret.handedness = copysign(1, rPD - lPD);

	return ret;
}

Collision intersect_AABB(const AABB & a, const AABB & b)
{
	Collision xres = intersect_1D(a.min().x, a.max().x, b.min().x, b.max().x);
	Collision yres = intersect_1D(a.min().y, a.max().y, b.min().y, b.max().y);

	xres.axis = vec2{ 1,0 };
	yres.axis = vec2{ 0,1 };

	return xres.penetrationDepth < yres.penetrationDepth? xres : yres;
}

Collision intersect_AABB_circle(const AABB & a, const circle & c)
{
	vec2 p;
	return Collision();
}

Collision intersect_circle(const circle & a, const circle & b)
{
	Collision ret;
	ret.axis = norm(b.position - a.position);
	ret.handedness = -1;
	float p1 = dot(ret.axis, a.position);
	float p2 = dot(ret.axis, b.position);

	float Amin = p1 - a.radius;
	float Amax = p1 + a.radius;

	float Bmin = p2 - b.radius;
	float Bmax = p2 + b.radius;
	ret.penetrationDepth = intersect_1D(Amin, Amax, Bmin, Bmax).penetrationDepth;

	return ret;
}
