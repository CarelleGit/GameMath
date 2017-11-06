#pragma once
#include "Vec2.h"
#include "Transform.h"

class Rigidbody
{
public:
	float mass;

	vec2 velocity, //speed * direction
		accerlation,// A = f/m
		force,
		impulse{ 0,0 };//continuous force
	float drag;
	float aAccel;
	float aVeloc;
	float torgue;
	float aDrag;

	Rigidbody() : velocity{ 0,0 }, accerlation{ 0,0 }, force{ 0,0 }, mass(1), impulse{ 0,0 }, drag(0.25), aVeloc(0), aAccel(0), torgue(0), aDrag(0.25)
	{

	}

	void intergrate(Transform &t, float dt)
	{
		//linear montion
		accerlation = force / mass;
		velocity += accerlation * dt + impulse / mass;
		t.position += velocity * dt;
		impulse = { 0,0 };
		force = -velocity * drag;
		//angular montion (kind of)
		aAccel = torgue / mass;
		aVeloc = aAccel * dt;
		t.angle += aVeloc * dt;

		torgue = aVeloc * aDrag;
	}

};