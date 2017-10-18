#include "Player.h"
#include "sfwdraw.h"


mat3 Player::getLocalTransform() const
{
	return  translation(position) * scale(dimentions) * rotate(angle);
}

void Player::Update()
{
}

void Player::Draw(const mat3 &t, float drawing_scale)
{
	vec2 pos = t[2].xy;
	vec2 right_ep = pos + t[0].xy * drawing_scale;
	vec2 up_ep = pos + t[1].xy * drawing_scale;
	float halfX = pos.x / 2.0f;
	float halfY = pos.y / 2.0f;

	//left
	sfw::drawLine(pos.x - halfX,pos.y - halfY, pos.x - halfX, pos.y + halfY);
	//right
	sfw::drawLine(pos.x + halfX, pos.y - halfY, pos.x + halfX, pos.y + halfY);
	//top
	sfw::drawLine(pos.x - halfX, pos.y + halfY, pos.x + halfX, pos.y + halfY);
	//bottom
	sfw::drawLine(pos.x - halfX, pos.y - halfY, pos.x + halfX, pos.y - halfY);
}
