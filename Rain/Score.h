#pragma once
#include "sfwdraw.h"
#include <string>

class Score
{
public:
	float sTime = 0.0f;
	bool enable = true;
	int font = sfw::loadTextureMap("res/fontmap.png", 16, 16);
	float hTime = 0.0f;
	int min = 0;
	int sec = 0;
	std::string Smin;
	std::string Ssec;
	std::string hSec;
	std::string hMin;
	std::string PrintedTime = "";
	void update();
	void draw();


};