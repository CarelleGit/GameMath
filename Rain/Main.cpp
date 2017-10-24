#include "sfwdraw.h"
#include "Player.h"
#include "Emitter.h"
#include "Help.h"
#include "Score.h"
#include "Collision.h"
#include "Enemy.h"

int main()
{
	bool quit = false;

	sfw::initContext(800, 600, "Rain");
	sfw::setBackgroundColor(BLACK);

	unsigned background = sfw::loadTextureMap("res/Background.png");
	unsigned Ground = sfw::loadTextureMap("res/Ground.png");
	Tr tran_background = { { 400,113 },{ 1600,700 }, 0 };

	Collision col;

	Player Cal;
	Cal.position = vec2{ 40,63 };
	Cal.position.x = 400;
	Cal.gravityForce = 6.26f;

	enemy Acidic;
	Acidic.position = vec2{ 650,50 };

	Emitter emitter;
	emitter.spawnInterval = 0.4f;

	Score score;
	score.sTime = 0;
	score.enable = true;

	while (sfw::stepContext())
	{
	
		vec2 target = Cal.getLocalTransform()[2].xy;

		target = max(vec2{ 0,0 }, min(target, vec2{ 600,400 }));
		mat3 proj = translation({ 400,300 });
		mat3 view = inverse(translation(target));

		mat3 cam = proj * view;
		DrawTexture(background, cam * tran_background.getGlobalTransform());
		score.draw();
		//score
		if (score.enable == true)
		{
			score.update();
		
		}
		//emitter
		if (emitter.enable == true)
		{
			emitter.draw();
			emitter.update();
		}
		//collision
		for (int i = 0; i < 100; i++)
		{
			if (emitter.rock[i].enabled)//(rock[i].enabled)
			{
				if (col.collide(Cal.position.x, Cal.position.y + 20, emitter.rock[i].oX, emitter.rock[i].oY, 20, 10) || col.collide(Cal.position.x, Cal.position.y + 20, Acidic.position.x, Acidic.position.y, 20, 20))
				{
					Cal.enable = false;
					score.enable = false;
					score.sTime = 0;
					emitter.enable = false;

				}
				if (sfw::getKey('R') && Cal.enable == false)
				{
					Cal.position.x = 400;
					emitter.enable = true;
					score.enable = true;
					Cal.enable = true;
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
		}
		//player
		if (Cal.enable == true)
		{
			Cal.Draw(Cal.getLocalTransform(), 100);
			Cal.Update(Cal.getLocalTransform());
		}
		sfw::drawTexture(Ground, 400, 5, 1600, 24);
		Acidic.Draw(Acidic.getGlobalTransform(),100);
		Acidic.Update(Acidic.getGlobalTransform());
		
	}
	sfw::termContext();
}