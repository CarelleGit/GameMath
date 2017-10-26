#include "Player.h"
#include "sfwdraw.h"

mat3 Player::getLocalTransform() const
{
	return  translation(position) * scale(dimentions) * rotate(Angle);
	
}

void Player::Update()
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
	if (health <= 0)
	{
		enable = false;
	}
}

void Player::Draw()
{
	vec2 pos = position;

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
	sfw::drawString(font, "Health:", 500, 500, 20, 20);
	if (health == 1)
	{
		sfw::drawString(font, "1", 650, 500, 20, 20);
	}
	if (health == 2)
	{
		sfw::drawString(font, "2", 650, 500, 20, 20);
	}
	if (health == 3)
	{
		sfw::drawString(font, "3", 650, 500, 20, 20);
	}
	//left
	
}
