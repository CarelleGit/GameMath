#pragma once
#include "Vec2.h"
#include "Mat3.h"
class Player //: public Collision
{
public:
	//rendering
	int TextureID;
	int LtextureID;
	int RtextureID;
	bool forward = true;
	//Drawing player
	vec2 position;
	vec2 dimentions;
	float angle;
	float dimX;
	float dimY;
	//misc
	bool enable = true;
	float gravityForce;
	bool isJump = false;
	bool isFalling = false;

	mat3 getLocalTransform() const;
	
	void Update();
	void Draw(const mat3 &t, float drawing_scale);
};