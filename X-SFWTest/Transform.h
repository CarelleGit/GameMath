#pragma once
#include "Vec2.h"
#include "Mat3.h"
class Transform
{
public:
	vec2 position;
	vec2 dimentions;
	float angle;
	Transform();
	mat3 getLocalTransform() const;

};
void drawMatrix(const mat3 &t, float drawing_scale);
