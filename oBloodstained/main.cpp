#include "sfwdraw.h"
#include "Entities.h"
#include "Menus.h"
#include "ctime"
#include <iostream>

int main()
{
	sfw::initContext(1000, 800, "Bloodstained");
	sfw::setBackgroundColor(BLACK);

	

	bool quit = false;
	
	int back;
	back = sfw::loadTextureMap("res/Background.png");
	int info;
	info = sfw::loadTextureMap("res/Level.png");

	/*MainMenu menu;
	menu.enable = true;
	Controls control;
	control.enable = false;
	GameOver over;
	over.enable = false;*/

	Player Kel;
	Kel.sprite = sfw::loadTextureMap("res/Player.png");
	Kel.transform.dimentions = vec2{ 50,100 };
	Kel.collider.box.extents = vec2{ 0.5,.5 };
	Kel.transform.position = vec2{ 450,800 };
	Kel.rgdb.drag = 5.5f;

		

	Karma kar;
	kar.sprite = sfw::loadTextureMap("res/Karma.png");
	kar.transform.dimentions = vec2{ 50,100 };
	kar.collider.box.extents = { vec2 {.5f,.5f} };
	kar.transform.position = vec2{ 600,60 };
	kar.rgdb.drag = 5.5f;

	Death death;

	NPC victom[4];
	for (int i = 0; i < 4; i++)
	{
		victom[i].sprite = sfw::loadTextureMap("res/NPC.png");
		victom[i].transform.dimentions = vec2{ 50,100 };
		victom[i].collider.box.extents = { vec2{ .5f,.5f } };
		victom[i].transform.position.x = rand() % 1000 + 1;
		victom[i].transform.position.y = 60;
		victom[i].rgdb.drag = 5.5f;
	}



	ground Ground;
	Ground.sprite = sfw::loadTextureMap("res/green-line.png");
	Ground.transform.position = vec2{ 500,1 };
	Ground.transform.dimentions = vec2{ 1000,20 };
	Ground.collider.box.extents = vec2{ .5f,.5f };

	while (sfw::stepContext())
	{
		
		sfw::drawTexture(back,500,400,1000,800);
		sfw::drawTexture(info, 900, 750, 294, 128);
		sfw::drawString(Kel.text, "Health:", 770, 740, 20, 20);
		// std::cout << sfw::getDeltaTime() << std::endl;
		sfw::setCursorVisible(true);
		sfw::getCursorVisible;
		//update(menu, control, over, Kel,kar, victom[4],death);
		float dt = sfw::getDeltaTime();
		if (Kel.health >= 0)
		{
			for (int i = 0; i < 4; i++)
			{
				collision(Kel, kar, death, victom[i], Ground);
			}
			
		}
		if (Kel.health >= 0)
		{
			Kel.control.poll(Kel.rgdb, Kel.transform);

			Kel.rgdb.intergrate(Kel.transform, dt);

			Kel.sprite.draw(Kel.transform);

			Kel.update(Ground);
			if (sfw::getMouseButton(MOUSE_BUTTON_RIGHT))
			{
				Kel.right.drawBox(Kel.transform);
			}
			if (sfw::getMouseButton(MOUSE_BUTTON_LEFT))
			{
				Kel.left.drawBox(Kel.transform);
			}
			leveling(kar, Kel, victom[0]);
		}

		if (kar.health >= 0)
		{
			kar.move(Kel, kar.transform);
			kar.rgdb.intergrate(kar.transform, dt);
   			kar.sprite.draw(kar.transform);
			
		}
		kar.respawn();
		for (int i = 0; i < 4; i++)
		{
			if (victom[i].health >= 0)
			{

				victom[i].move(Kel, victom[i].transform);
				victom[i].rgdb.intergrate(victom[i].transform, dt);
				victom[i].sprite.draw(victom[i].transform);
			}
			victom[i].respawn();
		}

		Ground.sprite.draw(Ground.transform);

		if (sfw::getKey(KEY_ESCAPE))
		{
			quit = true;
		}
		if (quit == true)
		{
			return -1;
		}
	/*	if (menu.enable == true)
		{
			menu.draw();
		}
		if (control.enable == true)
		{
			control.draw();
		}
		if (over.enable == true)
		{
			over.draw();
		}*/
	}
	sfw::termContext();
}