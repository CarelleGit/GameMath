#include "Shapes.h"
#include <cmath>
//transform:
//	position, rotation, scale
circle operator*(const mat3 & m, const circle & c)
{
	circle ret = c;
	ret.position = (m * vec3{ c.position.x, c.position.y, 1.0f }).xy;
	
	vec2 scale;
	scale.x = mag(m[0].xy);
	scale.y = mag(m[1].xy);

	ret.radius *= fmaxf(scale.x, scale.y);

	return ret;
}

AABB operator*(const mat3 & m, const AABB & b)
{
	vec2 B = b.position + b.extents;
	vec2 C = b.position - b.extents;

}
