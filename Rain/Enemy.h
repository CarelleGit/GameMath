#pragma once
#include "Vec2.h"
#include "Mat3.h"
#include "sfwdraw.h"
#include "Player.h"

class enemy : public Player
{
public:
	//Texture
	int eTextureID = sfw::loadTextureMap("res/Enemy.png");
	int eTextureID2 = sfw::loadTextureMap("res/Enemy1.png");
	int eTextureID3 = sfw::loadTextureMap("res/Enemy2.png");
	int eTextureID4 = sfw::loadTextureMap("res/Enemy3.png");
	int sprites[4];
	//draw
	bool enable = true;
	vec2 position;
	vec2 dimentions;
	float angle;
	float animTime =1;
	int animSlot = 0;
	enemy();
	enemy *e_parent;
	mat3 getLocalTransform() const;
	mat3 getGlobalTransform() const;


	void Update(const mat3 &t, Player &player);
	void Draw(const mat3 &t, float drawing_scale);


};
