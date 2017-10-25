#pragma once
#include "Vec2.h"
#include "Mat3.h"

class enemy
{
public:
	//Texture
	int TextureID;
	//draw
	bool enable = false;
	vec2 position;
	vec2 dimentions;
	float angle;
	enemy();
	enemy *e_parent;
	mat3 getLocalTransform() const;
	mat3 getGlobalTransform() const;


	void Update(const mat3 &t);
	void Draw(const mat3 &t, float drawing_scale);


};
