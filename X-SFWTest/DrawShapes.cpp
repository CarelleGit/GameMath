#include "DrawShapes.h"
#include "sfwdraw.h"
void drawCircle(const circle & c)
{
	sfw::drawCircle(c.position.x, c.position.y, c.radius);
}

void drawAABB(const AABB & a, int color)
{
	sfw::drawLine(a.MaxCorner.x, a.MaxCorner.y, a.MaxCorner.x, a.MinCorner.y, color);
	sfw::drawLine(a.MaxCorner.x, a.MinCorner.y, a.MinCorner.x, a.MinCorner.y,color);
	sfw::drawLine(a.MinCorner.x, a.MinCorner.y, a.MinCorner.x, a.MaxCorner.y,color);
	sfw::drawLine(a.MinCorner.x, a.MaxCorner.y, a.MaxCorner.x, a.MaxCorner.y,color);
}
