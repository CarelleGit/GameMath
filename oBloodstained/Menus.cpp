#include "Menus.h"
#include <ctime>
void update(MainMenu & menu, Controls & control, GameOver & over, Player &player, Karma &karma, NPC &npc, Death &death)
{
	srand(time(NULL));
	if (menu.enable == true)
	{
		
		if (sfw::getKey('S'))
		{
			menu.enable = false;
			if (menu.enable == false)
			{
				player.health = 20;
				player.transform.position = vec2{ 450,50 };
				karma.transform.position = vec2{ 600,60 };
				npc.transform.position.x = rand() % 1 + 1000;
			}
		}
		if (sfw::getKey('C'))
		{
			control.enable = true;

		}
	}
	if (control.enable == true)
	{
		if (sfw::getKey('B'))
		{
			control.enable = false;
		}
	}
	if (player.health <= 0 && menu.enable == false)
	{
		over.enable = true;
		if (sfw::getKey('M'))
		{
			menu.enable = true;
			over.enable = false;
		}
	}

}

void MainMenu::draw()
{
	menu = sfw::loadTextureMap("res/Main.png");
	
	transform.position.x = 500;
	transform.position.y = 400;
	transform.dimentions = vec2{ 1000, 800 };
	menu.draw(transform);
}

void Controls::draw()
{
	control = sfw::loadTextureMap("res/Controls.png");
	transform.position.x = 500;
	transform.position.y = 400;
	transform.dimentions = vec2{ 1000, 800 };
	control.draw(transform);
}

void GameOver::draw()
{
	Over = sfw::loadTextureMap("res/Gameover.png");
	transform.position.x = 500;
	transform.position.y = 400;
	transform.dimentions = vec2{ 1000, 800 };
	Over.draw(transform);
}
