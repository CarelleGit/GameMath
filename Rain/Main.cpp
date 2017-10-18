#include "sfwdraw.h"
#include "Player.h"


int main()
{
	sfw::initContext(800, 600, "Rain");
	sfw::setBackgroundColor(BLACK);
	Player Cal;
	Cal.position = vec2{ 40,63 };
	Cal.dimX = 50;
	Cal.dimY = 100;
	Cal.gravityForce = 6.26f;

	while (sfw::stepContext())
	{
		Cal.Draw(Cal.getLocalTransform(),100);
	}
	sfw::termContext();
}