#include "Enemy.h"
#include "sfwdraw.h"
#include <random>
#include <ctime>

void enemy::Update(const mat3 & t, Player &player)
{
	if (player.position.x < position.x)
	{
		position.x -= 1.5f;
	}
	if (player.position.x > position.x)
	{
		position.x += 1.5f;
	}
	if(player.position.x == position.x)
	{
		position.x == position.x;
	}
	/*if (position.x <= -2)
	{
		float ran = rand() % 700 + 600;
		position.x = ran;
	}
	position.x -= 3;*/
}

void enemy::Draw(const mat3 & t, float drawing_scale)
{
	animTime -= sfw::getDeltaTime();
	if (animTime < 0)
	{
		animTime = 1;
		animSlot++;
		if (animSlot > 3)
		{
			animSlot = 0;
		}
	}
	sfw::drawTexture(sprites[animSlot], position.x, position.y, 40, 40);
}
enemy::enemy()
{
	position = vec2{ 0,0 };
	dimentions = vec2{ 0,0 };
	angle = 0;
	e_parent = nullptr;
	sprites[0] = eTextureID;
	sprites[1] = eTextureID2;
	sprites[2] = eTextureID3;
	sprites[3] = eTextureID4;
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
