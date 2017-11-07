#include "Collider.h"
#include "sfwdraw.h"
Collision Collides(const Transform & aT, const Collider & aC, const Transform & bT, const Collider & bC)
{
		return intersect_AABB(aC.getGlobalBox(aT), bC.getGlobalBox(bT));
}


void drawVec(const vec2 &a, const vec2 &b)
{
	sfw::drawLine(a.x, a.y, b.x, b.y, MAGENTA);
}

void Collider::drawBox()
{
	drawVec(box.min(), box.max());
}
