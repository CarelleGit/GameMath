#include "sfwdraw.h"
#include "Player.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "DrawShapes.h"
#include "Shapes.h"
#include "Collision.h"
#include <cmath>

int main()
{
	sfw::initContext(800, 600);
	sfw::setBackgroundColor(BLACK);
	Transform transform;
	Rigidbody rigi;
	transform.position = { 0,0 };
	transform.dimentions = { 100,150 };
	circle circ2 = { { 400,300 }, 50 };

	circle circ = { { 0,0 }, 1 };

	AABB a = { {0,0},{1,1} };
	AABB box{ {400,300}, {160,160} };
	box.MinCorner = box.min();
	box.MaxCorner = box.max();
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
		drawCircle(circ2);
		//drawAABB(transform.getGlobalTransform() * a, BLUE);
		Collision res = intersect_circle(transform.getGlobalTransform() * circ, circ2);
		//Collision res = intersect_AABB(transform.getGlobalTransform() * a, box);

		//unsigned color = res.penetrationDepth < 0 ? WHITE : RED;

		//drawAABB(box, color);

		if (res.penetrationDepth >= 0)
		{
			transform.position += res.axis * res.handedness * res.penetrationDepth;
		}

		//drawMatrix(transform.getGlobalTransform(), 1);
		float dt = sfw::getDeltaTime();
		//rigi.force = { 0,-10 };
		
		rigi.intergrate(transform, dt);


		drawMatrix(transform.getGlobalTransform(), 1);
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