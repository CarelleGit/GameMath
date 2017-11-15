#pragma once
#include "Rigidbody.h"
#include "Transform.h"
#include "Controller.h"
#include "Collider.h"
#include "Sprites.h"


class ground
{
public:
	bool isGrounded = true;
	Transform transform;
	Sprite sprite;
	Collider collider;
};
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
	void update(ground &Ground);
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
	
	float time = 10;
	int health = 15;
	void move(Player &player, Transform t);
	void speedClamp();
	void respawn();

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
	bool directrion = true; //true to right false to the left
	Sprite sprite;
	Rigidbody rgdb;
	Collider collider;
	int health = 15;
	void move(Player &player, Transform t);
};
class Shop
{
public:
	Transform transform;
	Sprite sprite;
	Collider collider;
};

bool collision(Player &player, Karma &karma, Death &death, NPC &npc, Shop &shop, ground &Ground);
void leveling(Karma &karma, Player &player,NPC &npc);