#pragma once
#include "sfwdraw.h"
class FObject
{
public:
	int otextureID = sfw::loadTextureMap("res/Rain.png");
	float oX;
	float oY;
	int rad;
	float life;
	float aTime;
	float gravity;
	bool enabled;

	virtual void draw();
	virtual void update();

};
