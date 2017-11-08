#pragma once
#include <random>
#include <ctime>
class Controller
{
public:

	void poll(Rigidbody &rb, const Transform &t)
	{
		
		if (sfw::getKey('A'))
		{
			rb.force -= vec2{ 1000,0 };
			
		}
		if (sfw::getKey('D'))
		{
			rb.force += vec2{ 1000,0 };
		}
		if (sfw::getKey(MOUSE_BUTTON_LEFT))
		{
			
		}
		
	}
};
