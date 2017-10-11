#include "Player.h"
#include "sfwdraw.h"
#include <iostream>
#include <random>
void Player::update()
{
	vec2 move = { 0,0 };
	if (sfw::getKey('F'))
	{
		speed = 6;
	}
	else
	{
		speed = 1;
	}
	if (sfw::getKey('W'))
	{
		move.y += 1;
	}
	if (sfw::getKey('S'))
	{
		move.y -= 1;
	}
	if (sfw::getKey('A'))
	{
		move.x -= 1;
	}
	if (sfw::getKey('D'))
	{
		move.x += 1;
	}
	if (sfw::getKey(' '))
	{
		pos.x = rand() % 780 + 20;
		pos.y = rand() % 550 + 10;
		std::cout << move.x << " " << move.y << std::endl;
	}
	(move *= baseSpeed) *= speed;
	pos += move;
	
}

void Player::draw()
{
	sfw::drawCircle(pos.x, pos.y, 30.f);
}
