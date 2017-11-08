#include "Collider.h"
#include "sfwdraw.h"
Collision Collides(const Transform & aT, const Collider & aC, const Transform & bT, const Collider & bC)
{
		return intersect_AABB(aC.getGlobalBox(aT), bC.getGlobalBox(bT));
}


void drawVec(const vec2 &a, const vec2 &b)
{
	sfw::drawLine(a.x, a.y, b.x, b.y, CYAN);
}

void Collider::drawBox(const Transform &t)
{
	AABB box1 = getGlobalBox(t);
	vec2 TR = box1.position + box1.extents;
	vec2 BL = box1.position - box1.extents;
	vec2 TL = { box1.position.x - box1.extents.x, box1.position.y + box1.extents.y };
	vec2 BR = { TR.x, BL.y };

	drawVec(TR, TL);
	drawVec(TL, BL);
	drawVec(BL, BR);
	drawVec(BR, TR);

	//(box.min(), box.max());
}
