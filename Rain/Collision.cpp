#include "Collision.h"
#include <cmath>

bool Collision::collide(float x, float y, float x2, float y2, float r1, float r2)
{
	float sum = r1 + r2;
	coll = sqrt(pow(x - x2, 2) + pow(y - y2, 2));
	if (coll <= sum)
	{
		return true;
	}
	else
	{
		return false;
	}
}
