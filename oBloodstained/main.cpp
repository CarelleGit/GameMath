#include "sfwdraw.h"
#include "Entities.h"

int main()
{
	sfw::initContext(800, 600, "Bloodstained");
	sfw::setBackgroundColor(BLACK);

	Player Kel;
	Kel.sprite = sfw::loadTextureMap("res/Adorable-Cat-PNG.png");
	Kel.transform.dimentions = vec2{ 100,100 };
	Kel.transform.position = vec2{ 400,300 };
	Kel.rgdb.drag = 5.5f;

	Karma kar;
	kar.sprite = sfw::loadTextureMap("res/Adorable-Cat-PNG.png");
	kar.transform.dimentions = vec2{ 50,50 };
	kar.transform.position = vec2{ 0,300 };
	kar.rgdb.drag = 5.5f;

	while (sfw::stepContext())
	{
		float dt = sfw::getDeltaTime();
		collision(Kel, kar);
		if (Kel.health >= 0)
		{
			Kel.control.poll(Kel.rgdb, Kel.transform);
			Kel.rgdb.intergrate(Kel.transform, dt);
			Kel.sprite.draw(Kel.transform);
		}

		kar.move(Kel, kar.transform);
		kar.rgdb.intergrate(kar.transform, dt);
		kar.sprite.draw(kar.transform);
	}
	sfw::termContext();

}