#pragma once
#include "sfwdraw.h"
#include "Rigidbody.h"
class Controller
{
public:


	void poll(Rigidbody &rb, const Transform &t)
	{
		if (sfw::getKey('W')) rb.force += t.getGlobalTransform()[1].xy * 10;
		if (sfw::getKey('A')) rb.torgue += 3600;
		if (sfw::getKey('D')) rb.torgue += -3600;
		if (sfw::getKey(' '))
		{
			rb.force += -rb.velocity * 20;
			rb.torgue += -rb.aVeloc * 20;
		}
	}
};