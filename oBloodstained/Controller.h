#pragma once
class Controller
{
public:

	void poll(Rigidbody &rb, const Transform &t)
	{
		if (t.position.y >= 75)
		{
			rb.force = vec2{ 0,-20 };
		}
		if (sfw::getKey('A'))
		{
			rb.force -= vec2{ 1000,0 };
			
		}
		if (sfw::getKey('D'))
		{
			rb.force += vec2{ 1000,0 };
		}
		
	}
};
