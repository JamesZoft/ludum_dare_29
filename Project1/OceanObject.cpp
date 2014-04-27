#include "OceanObject.h"

OceanObject::OceanObject()
{
}


OceanObject::~OceanObject()
{
}




Vector2d OceanObject::getVelocity()
{
	return velocity;
}

void OceanObject::addRectX(int _x)
{
	if (rect.x + _x <= (Window::Box().w - rect.w) && rect.x + _x >= 0)
		rect.x += _x;
}

void OceanObject::addRectY(int _y)
{
	if (rect.y + _y <= (Window::Box().h - rect.h) && rect.y + _y >= ((Window::Box().h / 4) + 40))
		rect.y += _y;
}

float OceanObject::getRotation()
{
	return rotation;
}

void OceanObject::addRotation(float _rotation)
{
	rotation += _rotation;
}

void OceanObject::draw()
{
	Window::Draw(tex.get(), rect, NULL, (rotation * (180.0f / 3.1415926f) - 90.0f));
}

SDL_Rect OceanObject::getRect()
{
	return rect;
}