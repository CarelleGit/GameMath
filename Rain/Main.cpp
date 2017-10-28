#include "sfwdraw.h"
#include "Player.h"
#include "Emitter.h"
#include "Help.h"
#include "Score.h"
#include "Collision.h"
#include "Enemy.h"
#include "MainMenu.h"
#include <iostream>

int main()
{



	bool quit = false;

	sfw::initContext(800, 600, "Rain");
	sfw::setBackgroundColor(BLACK);

	unsigned background = sfw::loadTextureMap("res/Background.png");
	unsigned Ground = sfw::loadTextureMap("res/Ground.png");
	unsigned cloud = sfw::loadTextureMap("res/Cloud.png");

	Tr tran_background = { { 400,113 },{ 1600,700 }, 0 };
	Tr tranCould = { {400,350},{1600,400},0 };
	Collision col;

	Player Cal;
	Cal.position = vec2{ 40,63 };
	Cal.position.x = 400;
	Cal.gravityForce = 6.26f;

	enemy Acidic;
	Acidic.position = vec2{ 650,35 };

	Emitter emitter;
	emitter.spawnInterval = 0.7f;

	Emitter emit;
	emit.spawnInterval = 0.1f;

	Score score;
	score.sTime = 0;
	score.enable = true;

	controls con;
	death screen;
	menu main1;
	start button1;

	while (sfw::stepContext())
	{

		if (button1.enable == true)
		{
			emit.draw();
			emit.update();
			main1.mDraw();
			button1.draw();
			button1.update();
			con.update();
			if (con.enable == true)
			{
				con.draw();
			}
		}
		if (button1.enable == false)
		{
			emit.enable = false;
			vec2 target = Cal.getLocalTransform()[2].xy;

			target = max(vec2{ 0,0 }, min(target, vec2{ 600,400 }));
			mat3 proj = translation({ 400,300 });
			mat3 view = inverse(translation(target));

			mat3 cam = proj * view;
			//main menu


			DrawTexture(background, cam * tran_background.getGlobalTransform());
			
			//score
				

			//emitter
			if (emitter.enable == true)
			{
				emitter.draw();
				emitter.update();
			}
			DrawTexture(cloud, cam * tranCould.getGlobalTransform());
			score.draw();
			if (score.enable == true)
			{
				score.update(Cal);
			}
			//collision
			for (int i = 0; i < 100; i++)
			{
				if (emitter.rock[i].enabled)
				{
					if (col.collide(Cal.position.x, Cal.position.y + 20, emitter.rock[i].oX, emitter.rock[i].oY, 20, 10) || col.collide(Cal.position.x, Cal.position.y + 20, Acidic.position.x, Acidic.position.y, 20, 30))
					{
						Acidic.position.x = Cal.position.x + 100;
						Cal.health = Cal.health - 1;
						
					}
					if (Cal.enable == false)
					{
						score.enable = false;
						score.sTime = 0;
						Acidic.enable = false;
						screen.draw();
					}
					if (sfw::getKey('R') && Cal.enable == false)
					{
						Acidic.position.x = rand() % 800 + 700;
						Cal.health = 3;
						Acidic.enable = true;
						
						Cal.position.x = 400;
						score.enable = true;
						Cal.enable = true;
					}

				}
			}

			//player
			
			//sfw::drawTexture(cloud, 400, 600, 1600, 400);
			
			if (Cal.enable == true)
			{
				sfw::drawTexture(Ground, 400, 5, 1600, 24);
				Cal.Draw();
				Cal.Update();
			}

			//enemy
			if (Acidic.enable == true)
			{
				Acidic.Draw(Acidic.getGlobalTransform(), 100);
				Acidic.Update(Acidic.getGlobalTransform(),Cal);
			}
		}
		if (sfw::getKey(KEY_ESCAPE))
		{
			quit = true;
			while (quit == true)
			{
				return -1;
			}
		}
	}
	sfw::termContext();
}