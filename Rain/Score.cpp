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

	sfw::drawString(font, "Esc to exit", 30, 466, 20, 20);
	sfw::drawString(font, "R to restart", 30, 489, 20, 20);
	sfw::drawString(font, "Clock ", 30, 520, 20, 20);
	sfw::drawString(font, Smin.c_str(), 130, 520, 20, 20);
	sfw::drawString(font, ":", 142, 520, 20, 20);
	sfw::drawString(font, Ssec.c_str(), 155, 520, 20, 20);
}
