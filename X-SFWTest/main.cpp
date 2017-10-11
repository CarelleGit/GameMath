#include "sfwdraw.h"
#include "Player.h"
int main()
{
	sfw::initContext(800,600);
	sfw::setBackgroundColor(BLACK);
	Player Cal;
	Cal.pos = { 400,300 };
	Cal.speed = 10;
	Cal.baseSpeed = 3;
	while (sfw::stepContext())
	{
		Cal.draw();
		Cal.update();
	}
	sfw::termContext();


}