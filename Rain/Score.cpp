#include "Score.h"
#include "sfwdraw.h"
#include <cmath>
#include <iostream>
void Score::update()
{
	if (enable == false)
	{
		sTime = 0.0f;
	}
	else
	{
		sTime += sfw::getDeltaTime();
		min = sTime / 60;
		sec = fmod((sTime - min), 60);
	}
}

void Score::draw()
{
	Smin = std::to_string(min);
	Ssec = std::to_string(sec);

	sfw::drawString(font, "Esc to exit", 30, 476, 12, 12);
	sfw::drawString(font, "R to restart", 30, 489, 12, 12);
	sfw::drawString(font, "Clock ", 30, 510, 12, 12);
	sfw::drawString(font, Smin.c_str(), 100, 510, 12, 12);
	sfw::drawString(font, ":", 111, 510, 12, 12);
	sfw::drawString(font, Ssec.c_str(), 122, 510, 12, 12);
}
