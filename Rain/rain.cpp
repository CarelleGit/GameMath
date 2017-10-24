#include "rain.h"
#include "sfwdraw.h"
void FObject::draw()
{
	//sfw::drawTexture(textureID, oX, oY, 20, 20);
	sfw::drawCircle(oX, oY, 10, 12, GREEN);

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
