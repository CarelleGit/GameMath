#pragma once
#include "Shapes.h"
#include "Collision.h"
#include "Transform.h"

class Collider
{
public:
	AABB box;
	AABB getGlobalBox(const Transform &t) const
	{
		return t.getGlobalTransform()*box;
	}
	Collider(const AABB &a_box = { {0,0},{1,1} }) : box(a_box)
	{

	}
};
Collision collides(const Transform &aT, const Collider &aC, const Transform &bT, const Collider &bC);