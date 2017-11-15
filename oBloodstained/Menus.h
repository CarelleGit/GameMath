#pragma once
#include "Sprites.h"
#include "Transform.h"
#include "sfwdraw.h"
#include "Entities.h"

class MainMenu
{
public:
	Sprite menu;
	Transform transform;
	bool enable;

	void draw();
};

class Controls
{
public:
	Sprite control;
	Transform transform;
	bool enable;
	void draw();
};

class GameOver
{
public:
	Sprite Over;
	Transform transform;
	bool enable;
	void draw();
};
void update(MainMenu &menu, Controls &control, GameOver &over, Player &player, Karma &karma, NPC &npc, Death &death);
