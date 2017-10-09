#include "Mathutils.h"
#include <cmath>
#include <iostream>
using std::cout;

//float sqr(float v)
//{
//	return v * v;
//}

float dbl(float v)
{
	return v * 2;
}

float cube(float v)
{
	return v * v * v;
}

float degToRad(float deg)
{
	return deg * 3.14 / 180;
}

float radToDeg(float rad)
{
	return rad * 180 / 3.14;
}

float quad(float q)
{
	return q * q + 2*q - 7;
}

float L(float s, float e, float t)
{
	return s + t * (e - s);
}

float D(float pX, float pY, float p2X, float p2Y)
{
	float x = (p2X - pX) * (p2X - pX);
	float y = (p2Y - pY) * (p2Y - pY);
	float add = x + y;
	float res = sqrt(add);
	return res;
}

