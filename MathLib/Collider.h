#pragma once
#include "Shapes.h"
#include "Collision.h"
#include "transform"

class Collider
{
public:
	AABB box;
	AABB getGlobalBox(const Transform &t) const;


};
Collision collides(const transform &aT, const Collider &aC, const transform &bT, const Collider &bC);