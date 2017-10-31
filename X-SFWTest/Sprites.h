#pragma once
#include "Vec2.h"
#include "Transform.h"
#include "sfwdraw.h"
class Sprite
{
public:
	int handle;
	vec2 dim;
	vec2 offset;
	Sprite(int a_handle, int width, int height) : handle(a_handle), dim{ width, height }, offset{ 0,0 }
	{

	}
	void draw(const Transform &t, const mat3 &cam = mat3::identity())
	{
		
		mat3 m = cam * t.getGlobalTransform() * translation(offset) * scale(dim);

		sfw::drawTextureMatrix3(handle, 0, WHITE, m.m);
	}


};
