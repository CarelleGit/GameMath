#pragma once
#include "Vec2.h"
#include "Rigidbody.h"
#include "Transform.h"
#include "Collider.h"
#include "Controller.h"
#include "Sprites.h"

class Player
{
public:
	Transform trans;
	Rigidbody rgdb;
	Collider collider;
	Controller controller;
	Sprite sprite;

};
class Wall
{
public:
	Transform trans;
	Collider coll;
	Sprite sprite;
};
