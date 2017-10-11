#pragma once
#include "Vec2.h"


class Player
{
public:
	vec2 pos;
	float baseSpeed;
	float speed;
	void update();
	void draw();
};
