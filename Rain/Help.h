#pragma once
#include "Mat3.h"
class Tr
{
public:
	vec2 position;
	vec2 dimension;
	float angle;
	Tr *e_parent;


	Tr(vec2 a_pos = { 0,0 }, vec2 a_dim = { 1,1 }, float a_ang = 0);

	mat3 getLocalTransform() const;
	mat3 getGlobalTransform() const;
};
void DrawTexture(unsigned sprite, const mat3 &t);