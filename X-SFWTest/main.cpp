#include "sfwdraw.h"
#include "Player.h"
#include "DrawShapes.h"

int main()
{
	sfw::initContext(800, 600);
	sfw::setBackgroundColor(BLACK);
	Player player;
	player.sprite = sfw::loadTextureMap("res/Player.png");
	player.trans.dimentions = vec2{ 50,100 };
	player.trans.position = vec2{ 400,300 };

	Wall wall;
	wall.sprite = sfw::loadTextureMap("res/LPlayer.png");
	wall.trans.dimentions = vec2{ 100,700 };
	wall.trans.position = vec2{ 800,350 };
	
	while (sfw::stepContext())
	{
		float dt = sfw::getDeltaTime();

		wall.coll;
		wall.sprite.draw(wall.trans);

		player.controller.poll(player.rgdb, player.trans);
		player.rgdb.intergrate(player.trans, dt);
		player.sprite.draw(player.trans);
		drawAABB(player.collider.getGlobalBox(player.trans), BLUE);
	}
	sfw::termContext();


}