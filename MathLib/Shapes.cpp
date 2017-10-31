#include "Shapes.h"
#include <cmath>
//transform:
//	position, rotation, scale
circle operator*(const mat3 & m, const circle & c)
{
	circle ret = c;
	ret.position = (m * vec3{ c.position.x, c.position.y, 1.f }).xy;
	
	vec2 scale;
	scale.x = mag(m[0].xy);
	scale.y = mag(m[1].xy);

	ret.radius *= fmaxf(scale.x, scale.y);

	return ret;
}

AABB operator*(const mat3 & m, const AABB & b)
{
	
	AABB retval;
	vec2 TR = b.position + b.extents; // B
	vec2 BL = b.position - b.extents; //C
	vec2 BR = { b.position.x + b.extents.x, b.position.y - b.extents.y };//D
	vec2 TL = { b.position.x - b.extents.x, b.position.y + b.extents.y };  // A

	TR = (m * vec3{ TR.x, TR.y, 1 }).xy;
	BL = (m * vec3{ BL.x,BL.y,1 }).xy;
    TL = (m * vec3{ TL.x,TL.y,1 }).xy;
	BR = (m * vec3{ BR.x,BR.y,1 }).xy;

	 retval.MinCorner = min(TR, min(BL, min(TL, BR)));
	 retval.MaxCorner = max(TR, max(BL, max(TL,BR)));

	retval.position = (retval.MaxCorner + retval.MinCorner) / 2;
	retval.extents = (retval.MaxCorner - retval.MinCorner) / 2;

	return retval;
}
