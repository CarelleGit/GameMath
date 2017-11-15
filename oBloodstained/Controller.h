#pragma once

class Controller
{
public:
	bool grounded = false;
	vec2 appliedForceL;
	vec2 appliedForceR;
	void poll(Rigidbody &rb, const Transform &t)
	{
		if (!grounded)
		{
			rb.force = vec2{ 0,-350 };
			//rb.drag = 20;
			//rb.mass = 5;
		}
		else
		{
			if (sfw::getKey('A'))
			{
				//rb.force += vec2{ -1000,0 };
				appliedForceR = { 0,0 };
				appliedForceL += {50, 0};
				
				appliedForceL = clamp(vec2{	50,0 }, appliedForceL, vec2{ 800,0 });
				rb.force -= appliedForceL;
			}
			if (sfw::getKey('D'))
			{
				//rb.force += vec2{ 1000,0 };
				appliedForceL = { 0,0 };
				appliedForceR += {50, 0};
				appliedForceR = clamp(vec2{ 50,0 }, appliedForceR, vec2{ 800,0 });
				rb.force += appliedForceR;
			}
			
		}
		//else { rb.mass = 1; }
		
	
	}
};
