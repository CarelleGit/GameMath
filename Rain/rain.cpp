#include "rain.h"
#include "sfwdraw.h"
void FObject::draw()
{
	sfw::drawTexture(otextureID, oX, oY, 20, 20);

}

void FObject::update()
{
	oY -= gravity;
	aTime += sfw::getDeltaTime();
	if (aTime > life)
	{
		enabled = false;
	}
}
