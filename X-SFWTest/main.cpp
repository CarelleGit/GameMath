#include "sfwdraw.h"
#include "Player.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "DrawShapes.h"
#include "Shapes.h"
#include <cmath>
int main()
{
	sfw::initContext(800,600);
	sfw::setBackgroundColor(BLACK);
	Transform transform;
	Rigidbody rigi;
	transform.position = { 600,800 };
	transform.dimentions = { 100,150 };

	circle circ = { { 0,0 }, 1 };

	//rigi.velocity = 50 * norm(vec2{ 800,600 });
	/*Transform myTransform;
	myTransform.position = vec2{ 400,300 };
	myTransform.dimentions = vec2{ 1,1 };
	myTransform.angle = 20;
	myTransform.movement = true;

	Transform myBaby;
	myBaby.position = vec2{ 50,50 };
	myBaby.dimentions = vec2{ 1,1 };
	myBaby.angle = 0;
	myBaby.e_parent = &myTransform;
	myBaby.movement = false;*/
	/*Player Cal;
	Cal.pos = { 400,300 };
	Cal.speed = 10;
	Cal.baseSpeed = 3;*/
	while (sfw::stepContext())
	{
		drawCircle(transform.getGlobalTransform() * circ);
		drawMatrix(transform.getGlobalTransform(), 1);
		float dt = sfw::getDeltaTime();
		rigi.force = { 0,-10 };
		if (sfw::getKey('W'))rigi.force += transform.getGlobalTransform()[1].xy * 100;
		if (sfw::getKey('A')) rigi.torgue += 360;
		if (sfw::getKey('D')) rigi.torgue += -360;
		if (sfw::getKey('Q')) rigi.impulse += -transform.getGlobalTransform()[1].xy * 10;
		if (sfw::getKey(' '))
		{
			rigi.force += -rigi.velocity * 20;
			rigi.torgue += -rigi.aVeloc * 20;
		}
		rigi.intergrate(transform, dt);


		drawMatrix(transform.getGlobalTransform(), 12);
		//float t = sfw::getTime();
		///*Cal.draw();
		//Cal.update();*/
		//myTransform.dimentions = vec2{ sinf(t) + 5, sinf(t) + 2 };
		//myBaby.dimentions = vec2{ sinf(t) + 5, sinf(t) + 2 };
		//myTransform.angle -= sfw::getDeltaTime() * 100;
		//myBaby.angle += sfw::getDeltaTime() * 100;

		//drawMatrix(myTransform.getGlobalTransform(), 40);
		//drawMatrix(myBaby.getGlobalTransform(), 30);
	}
	sfw::termContext();


}