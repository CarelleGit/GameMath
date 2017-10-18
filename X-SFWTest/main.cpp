#include "sfwdraw.h"
#include "Player.h"
#include "Transform.h"
#include <cmath>
int main()
{
	sfw::initContext(800,600);
	sfw::setBackgroundColor(BLACK);
	Transform myTransform;
	myTransform.position = vec2{ 300,400 };
	myTransform.dimentions = vec2{ 1,1 };
	/*Player Cal;
	Cal.pos = { 400,300 };
	Cal.speed = 10;
	Cal.baseSpeed = 3;*/
	while (sfw::stepContext())
	{
		float t = sfw::getTime();
		/*Cal.draw();
		Cal.update();*/
		myTransform.dimentions = vec2{ sinf(t) + 2, sinf(t) + 2 };
		myTransform.angle -= sfw::getDeltaTime() * 100;
		drawMatrix(myTransform.getLocalTransform(), 40);
	}
	sfw::termContext();


}