#pragma once
#include "Vec2.h"
#include "Mat3.h"
#include "Collision.h"
#include "sfwdraw.h"
class Player : public Collision
{
public:
	//rendering
	int pTextureID = sfw::loadTextureMap("res/Player.png");
	int LtextureID = sfw::loadTextureMap("res/LPlayer.png");
	int RtextureID = sfw::loadTextureMap("res/RPlayer.png");
	int font = sfw::loadTextureMap("res/fontmap.png", 16, 16);
	bool forward = true;
	//Drawing player
	float Speed;
	vec2 position;
	vec2 dimentions;
	float Angle;
	float dimX;
	float dimY;
	//misc
	bool isjumping = false;
	bool isfalling = false;
	int health = 3;
	int jumpHeight = 0;
	bool enable = true;
	float gravityForce;

	mat3 getLocalTransform() const;
	
	void Update();
	void Draw();
};