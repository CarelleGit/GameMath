#pragma once
#include "Vec2.h"
#include "Mat3.h"
#include "sfwdraw.h"
class Transform
{
public:
	bool movement = true;
	vec2 position;
	vec2 dimentions;
	float angle;
	Transform();
	Transform *e_parent;
	mat3 GetLocalTransform() const;
	mat3 GetGlobalTransform() const;


};
void DrawMatrix(const mat3 &t, float drawing_scale);
void drawTexture(unsigned sprite, const mat3 &t);