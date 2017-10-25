#include "Player.h"
#include "sfwdraw.h"

mat3 Player::getLocalTransform() const
{
	return  translation(position) * scale(dimentions) * rotate(Angle);
	
}

void Player::Update(const mat3 &t)
{
	

	if (sfw::getKey('D'))
	{
		position.x += 5;
	}
	if (sfw::getKey('A'))
	{
		position.x -= 5;
	}
	if (sfw::getKey(' ') && isjumping == false && isfalling != true)
	{
		isjumping = true;
	}
	if (isjumping == true)
	{
		jumpHeight += 5;
		position.y += 5;
		if (jumpHeight > 60)
		{
			isjumping = false;
			isfalling = true;
		}
		
	}
	if (isfalling == true)
	{
		jumpHeight -= 5;
		position.y -= 5;
		if (jumpHeight <= 4)
		{
			isfalling = false;
		}
	}
	if (position.x <= 0)
	{
		position.x = 0;
	}
	if (position.x >= 800)
	{
		position.x = 800;
	}
}

void Player::Draw(const mat3 &t, float drawing_scale)
{
	vec2 pos = t[2].xy;
	vec2 right_ep = pos + t[0].xy * drawing_scale;
	vec2 up_ep = pos + t[1].xy * drawing_scale;
	float halfX = pos.x / 2.0f;
	float halfY = pos.y / 2.0f;

	if (!sfw::getKey('D') && !sfw::getKey('A'))
	{
		sfw::drawTexture(pTextureID, pos.x, pos.y, 50, 100);
	}
	else if (sfw::getKey('A'))
	{
		sfw::drawTexture(LtextureID, pos.x, pos.y, 50, 100);
	}
	else if (sfw::getKey('D'))
	{
		sfw::drawTexture(RtextureID, pos.x, pos.y, 50, 100);
	}
	
	//left
	
}
