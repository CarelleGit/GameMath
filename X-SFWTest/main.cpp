#include "sfwdraw.h"
#include "Player.h"
#include "DrawShapes.h"

int main()
{
	sfw::initContext(800, 600);
	sfw::setBackgroundColor(BLACK);
	Player player;
	player.sprite = sfw::loadTextureMap("res/Player.png");
	player.trans.dimentions = vec2{ 100,100 };
	player.trans.position = vec2{ 400,300 };

	Wall wall[4];
	wall[0].sprite = sfw::loadTextureMap("res/LPlayer.png");
	wall[0].trans.dimentions = vec2{ 50,700 };
	wall[0].trans.position = vec2{ 800,350 };

	wall[1].sprite = sfw::loadTextureMap("res/LPlayer.png");
	wall[1].trans.dimentions = vec2{ 700,50 };
	wall[1].trans.position = vec2{ 400,600 };

	wall[2].sprite = sfw::loadTextureMap("res/LPlayer.png");
	wall[2].trans.dimentions = vec2{ 50,700 };
	wall[2].trans.position = vec2{ 0,350 };

	wall[3].sprite = sfw::loadTextureMap("res/LPlayer.png");
	wall[3].trans.dimentions = vec2{ 700,50 };
	wall[3].trans.position = vec2{ 400,0 };
	
	while (sfw::stepContext())
	{
		/*if (player.trans.position.x <= 800);
		{
			player.trans.position.x = 800;
		}
		if (player.trans.position.x >= 0);
		{
			player.trans.position.x = 0;
		}
		if (player.trans.position.y <= 600);
		{
			player.trans.position.x = 600;
		}
		if (player.trans.position.x >= 0);
		{
			player.trans.position.x = 0;
		}*/
		float dt = sfw::getDeltaTime();
		for (int i = 0; i < 4; i++)
		{
			wall[i].sprite.draw(wall[i].trans);
		}
		

		player.controller.poll(player.rgdb, player.trans);
		player.rgdb.intergrate(player.trans, dt);
		player.sprite.draw(player.trans);
		drawAABB(player.collider.getGlobalBox(player.trans), BLUE);
		for (int i = 0; i < 4; i++)
		{
			doCollision(player, wall[i]);
		}
		

		//Collision res = intersect_AABB(player.trans.getGlobalTransform() * player.collider.box, wall.trans.getGlobalTransform() * wall.coll.box);
		
	}
	sfw::termContext();


}