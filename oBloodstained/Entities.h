#pragma once
#include "Rigidbody.h"
#include "Transform.h"
#include "Controller.h"
#include "Collider.h"
#include "Sprites.h"


class Player : public Controller 
{
public:
	int weaponType = 0;
	int level = 0;
	int damage;
	int xp = 0;


	Collider right;
	Collider left;

	Transform transform;
	Rigidbody rgdb;
	Controller control;
	Collider collider;
	Sprite sprite;
	int health = 20;
	void speedClamp();
	int collisionResolution();

};
class Karma
{
public:
	
	Transform transform;
	Collider collider;
	Sprite sprite;
	Rigidbody rgdb;
	
	bool directrion = true; //true to right false to the left
	
	int health = 15;
	void move(Player &player, Transform t);
	void speedClamp();
};
class Death
{
public:
	Transform transform;
	Collider collider;

	bool directrion = true; //true to right false to the left

	Sprite sprite;
	Rigidbody rgdb;
	void move(Player &player, Transform t);
};
class NPC
{
public:
	Transform transform;




};
bool collision(Player &player, Karma &karma);
bool collision(Player &player, Death &death);
void leveling(Karma &karma, Player &player);