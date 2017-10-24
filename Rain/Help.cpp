#include "Help.h"
#include "sfwdraw.h"
void DrawTexture(unsigned sprite, const mat3 & t)
{
	sfw::drawTextureMatrix3(sprite, 0, WHITE, t.m);
}

Tr::Tr(vec2 a_pos, vec2 a_dim, float a_ang)
{
	position = a_pos; //vec2{ 0,0 };
	dimension = a_dim;//  vec2{ 0,0 };
	angle = a_ang; // 0;
	e_parent = nullptr;
}

mat3 Tr::getLocalTransform() const
{
	return translation(position) * scale(dimension) * rotate(angle);
}

mat3 Tr::getGlobalTransform() const
{
	if (e_parent != nullptr)
	{
		return e_parent->getGlobalTransform() * getLocalTransform();
	}
	else
	{
		return getLocalTransform();
	}
}
