#include "sfwdraw.h"
#include "Entities.h"
#include <iostream>

int main()
{
	sfw::initContext(1000, 800, "Bloodstained");
	sfw::setBackgroundColor(BLACK);

	bool quit = false;

	Player Kel;
	Kel.sprite = sfw::loadTextureMap("res/Adorable-Cat-PNG.png");
	Kel.transform.dimentions = vec2{ 100,100 };
	Kel.collider.box.extents = vec2{ 0.5,.5 };
	Kel.transform.position = vec2{ 400,300 };
	Kel.rgdb.drag = 5.5f;

		

	Karma kar;
	kar.sprite = sfw::loadTextureMap("res/Adorable-Cat-PNG.png");
	kar.transform.dimentions = vec2{ 80,50 };
	kar.collider.box.extents = { vec2 {.5f,.5f} };
	kar.transform.position = vec2{ 0,300 };
	kar.rgdb.drag = 5.5f;

	Death death;

	NPC victom;
	victom.sprite = sfw::loadTextureMap("res/Adorable-Cat-PNG.png");
	victom.transform.dimentions = vec2{ 80,50 };
	victom.collider.box.extents = { vec2{ .5f,.5f } };
	victom.transform.position = vec2{ 0,300 };
	victom.rgdb.drag = 5.5f; 

	Shop shop;
	shop.transform.position = vec2{ 0,300 };
	shop.transform.dimentions = vec2{ 100,100 };
	shop.collider.box.extents = vec2{ .5f,.5f };
	shop.sprite = sfw::loadTextureMap("res/Square.png");

	ground Ground;
	Ground.sprite = sfw::loadTextureMap("res/green-line.png");
	Ground.transform.position = vec2{ 500,1 };
	Ground.transform.dimentions = vec2{ 1000,20 };
	Ground.collider.box.extents = vec2{ .5f,.5f };

	while (sfw::stepContext())
	{
		std::cout << sfw::getDeltaTime() << std::endl;

		sfw::setCursorVisible(true);
		sfw::getCursorVisible;
		
		float dt = sfw::getDeltaTime();
		if (Kel.health >= 0)
		{
			collision(Kel, kar, death, victom, shop, Ground);
		}
		if (Kel.health >= 0)
		{
			Kel.control.poll(Kel.rgdb, Kel.transform);

			Kel.rgdb.intergrate(Kel.transform, dt);

			Kel.sprite.draw(Kel.transform);

			Kel.collider.drawBox(Kel.transform);
			Kel.update();
			if (sfw::getMouseButton(MOUSE_BUTTON_RIGHT))
			{
				Kel.right.drawBox(Kel.transform);
			}
			if (sfw::getMouseButton(MOUSE_BUTTON_LEFT))
			{
				Kel.left.drawBox(Kel.transform);
			}
			leveling(kar, Kel,victom);
		}

		if (kar.health >= 0)
		{
			kar.collider.drawBox(kar.transform);
			kar.move(Kel, kar.transform);
			kar.rgdb.intergrate(kar.transform, dt);
   			kar.sprite.draw(kar.transform);
			
		}
		kar.respawn();
		if (victom.health >= 0)
		{
			victom.collider.drawBox(victom.transform);
			victom.move(Kel, victom.transform);
			victom.rgdb.intergrate(victom.transform, dt);
			victom.sprite.draw(victom.transform);
		}
		shop.collider.drawBox(shop.transform);
		shop.sprite.draw(shop.transform);

		Ground.collider.drawBox(Ground.transform);
		Ground.sprite.draw(Ground.transform);

		if (sfw::getKey(KEY_ESCAPE))
		{
			quit = true;
		}
		if (quit == true)
		{
			return -1;
		}
	}
	sfw::termContext();
}