#pragma once
#include "rain.h"

class Collision
{
public:
	bool collide(float x, float y, float x2, float y2, float r1, float r2);
	float coll;
};