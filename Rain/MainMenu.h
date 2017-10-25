#pragma once
#include <string>
#include "sfwdraw.h"
class menu
{
private:
	int mainPic;
	//mainPic = sfw::loadTextureMap("res/Player.png");
	int font = sfw::loadTextureMap("res/fontmap.png", 16, 16);
public:
	bool enable = true;
	
	//std::string PrintedTime = "";
	void mDraw();
	void mUpdate();

	
};

class start
{
public:
	bool exit = false;
	bool enable = true;
	int quit();
	void draw();
	void update();

};


