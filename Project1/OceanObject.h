#pragma once
#include <SDL.h>
#include "Vector2d.h"
#include "Window.h"

class OceanObject
{
public:
	virtual void draw();
	virtual Vector2d getVelocity();
	virtual void addRectX(int);
	virtual void addRectY(int);
	virtual float getRotation();
	virtual void addRotation(float);
	virtual SDL_Rect getRect();
	~OceanObject();
protected:
	OceanObject();
	Vector2d velocity;
	float rotation;
	SDLTexture tex;
	SDL_Rect rect;
};

