#include "Collider.h"

Collision Collides(const Transform & aT, const Collider & aC, const Transform & bT, const Collider & bC)
{
		return intersect_AABB(aC.getGlobalBox(aT), bC.getGlobalBox(bT));
}
