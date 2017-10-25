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
	/*int LtextureID = sfw::loadTextureMap("LPlayer.png");
	int RtextureID = sfw::loadTextureMap("RPlayer.png");*/
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
	int jumpHeight = 0;
	bool enable = true;
	float gravityForce;
	//bool isJump = false;
	//bool isFalling = false;

	mat3 getLocalTransform() const;
	
	void Update(const mat3 &t);
	void Draw(const mat3 &t, float drawing_scale);
};