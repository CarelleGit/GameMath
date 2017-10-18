#pragma once
#include "Vec2.h"
#include "Mat3.h"
class Transform
{
public:
	bool movement = true;
	vec2 position;
	vec2 dimentions;
	float angle;
	Transform();
	Transform *e_parent;
	mat3 getLocalTransform() const;
	mat3 getGlobalTransform() const;
	

};
void drawMatrix(const mat3 &t, float drawing_scale);
