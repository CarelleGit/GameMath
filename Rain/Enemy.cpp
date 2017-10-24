#include "Enemy.h"
#include "sfwdraw.h"
#include <random>
#include <ctime>

void enemy::Update(const mat3 & t)
{

	if (position.x <= -2)
	{
		float ran = rand() % 700 + 600;
		position.x = ran;
	}
	position.x -= 3;
}

void enemy::Draw(const mat3 & t, float drawing_scale)
{
	sfw::drawCircle(position.x, position.y, 20);
}
enemy::enemy()
{
	position = vec2{ 0,0 };
	dimentions = vec2{ 0,0 };
	angle = 0;
	e_parent = nullptr;
}
mat3 enemy::getLocalTransform() const
{
	return  translation(position) * scale(dimentions) * rotate(angle);

}

mat3 enemy::getGlobalTransform() const
{
	if (e_parent != nullptr)
	{
		return e_parent->getGlobalTransform()*getLocalTransform();
	}
	else
	{
		return getLocalTransform();
	}
}
