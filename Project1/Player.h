#pragma once
#include <SDL.h>
#include "Window.h"
#include "OceanObject.h"
#include "Vector2d.h"

class Player : public OceanObject
{
public:
	Player();
	~Player();
	bool move(SDL_Keycode, bool);
};
