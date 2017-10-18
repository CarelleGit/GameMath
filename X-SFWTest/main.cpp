#include "sfwdraw.h"
#include "Player.h"
#include "Transform.h"
#include <cmath>
int main()
{
	sfw::initContext(800,600);
	sfw::setBackgroundColor(BLACK);
	Transform myTransform;
	myTransform.position = vec2{ 400,300 };
	myTransform.dimentions = vec2{ 1,1 };
	myTransform.angle = 20;
	myTransform.movement = true;

	Transform myBaby;
	myBaby.position = vec2{ 50,50 };
	myBaby.dimentions = vec2{ 1,1 };
	myBaby.angle = 0;
	myBaby.e_parent = &myTransform;
	myBaby.movement = false;
	/*Player Cal;
	Cal.pos = { 400,300 };
	Cal.speed = 10;
	Cal.baseSpeed = 3;*/
	while (sfw::stepContext())
	{
		float t = sfw::getTime();
		/*Cal.draw();
		Cal.update();*/
		myTransform.dimentions = vec2{ sinf(t) + 5, sinf(t) + 2 };
		myBaby.dimentions = vec2{ sinf(t) + 5, sinf(t) + 2 };
		myTransform.angle -= sfw::getDeltaTime() * 100;
		myBaby.angle += sfw::getDeltaTime() * 100;

		drawMatrix(myTransform.getGlobalTransform(), 40);
		drawMatrix(myBaby.getGlobalTransform(), 30);
	}
	sfw::termContext();


}