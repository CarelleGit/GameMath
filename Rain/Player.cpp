#include "Player.h"
#include "sfwdraw.h"

mat3 Player::getLocalTransform() const
{
	return  translation(position) * scale(dimentions) * rotate(Angle);
	
}

void Player::Update(const mat3 &t)
{
	//RtextureID = sfw::loadTextureMap("RPlayer.png");
	TextureID = sfw::loadTextureMap("res/Player.png");
	//LtextureID = sfw::loadTextureMap("LPlayer.png");

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
	sfw::drawCircle(0, 0, 20);
	vec2 pos = t[2].xy;
	vec2 right_ep = pos + t[0].xy * drawing_scale;
	vec2 up_ep = pos + t[1].xy * drawing_scale;
	float halfX = pos.x / 2.0f;
	float halfY = pos.y / 2.0f;
	/*if (forward == true)
	{
		sfw::drawTexture(TextureID, pos.x, pos.y, 50, 100);
	}

	if (sfw::getKey('A'))
	{
		sfw::drawTexture(LtextureID, pos.x, pos.y, 50, 100);
	}
	if (sfw::getKey('D'));
	{
		sfw::drawTexture(RtextureID, pos.x, pos.y, 50, 100);
	}
	if (!sfw::getKey('D') || !sfw::getKey('D'))
	{
		forward = true;
	}*/

	//RtextureID = sfw::loadTextureMap("RPlayer.png");
	sfw::drawTexture(TextureID, pos.x, pos.y, 50, 100);
	//LtextureID = sfw::loadTextureMap("LPlayer.png");

	//left
	
}
