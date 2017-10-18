#include "Transform.h"
#include "sfwdraw.h"
Transform::Transform()
{
	position = vec2{ 0,0 };
	dimentions = vec2{ 0,0 };
	angle = 0;
}

mat3 Transform::getLocalTransform() const
{
	return  translation(position) * scale(dimentions) * rotate(angle);
}

void drawMatrix(const mat3 & t, float drawing_scale)
{
	vec2 pos = t[2].xy;
	vec2 right_ep = pos + t[0].xy * drawing_scale;
	vec2 up_ep = pos + t[1].xy * drawing_scale;

	sfw::drawLine(pos.x, pos.y, right_ep.x, right_ep.y, RED);
	sfw::drawLine(pos.x, pos.y, up_ep.x, up_ep.y, GREEN);

	sfw::drawCircle(pos.x, pos.y, drawing_scale / 4);
}
