#pragma once
#include <string>
#include "sfwdraw.h"
class menu
{
private:
	int mainPic = sfw::loadTextureMap("res/mainMenu.png");
	//mainPic = sfw::loadTextureMap("res/Player.png");
	
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
	int font = sfw::loadTextureMap("res/fontmap.png", 16, 16);
};

class death
{
public:
	bool enable;
	int GameOver = sfw::loadTextureMap("res/GameOver.jpeg");
	void draw();
};


