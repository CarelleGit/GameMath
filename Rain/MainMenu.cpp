#include "MainMenu.h"
#include "sfwdraw.h"

void menu::mUpdate()
{
	
}

void menu::mDraw()
{
	sfw::drawTexture(mainPic, 400, 300, 800, 600);

	
	//sfw::drawTexture(mainPic, 400, 300, 800, 600);
}

void start::update()
{
	if (sfw::getKey('S'))
	{
		enable = false;
	}
	
}

int start::quit()
{
	if (sfw::getKey('Q'))
	{
		exit = true;
		
	}
	while (exit == true)
	{
		return -1;
	}
}

void start::draw()
{
	sfw::drawString(font, "[S]tart", 560, 90, 30, 30,0,'\000',GREEN);
}


