#include "Player.h"
#include <SDL.h>
#include "Window.h"
#include "Vector2d.h"

Player::Player()
{
	tex = std::move(Window::LoadImage("player_ship.png"));
	rect.x = Window::Box().w / 2;
	rect.y = Window::Box().h / 2;
	SDL_QueryTexture(tex.get(), NULL, NULL, &rect.w, &rect.h);
}

Player::~Player()
{
}

bool Player::move(SDL_Keycode code, bool keyDownUp)
{
	bool success = true;
	switch (code)
	{
	case SDLK_w:
		if (keyDownUp)
			velocity.setY(-5.0);
		else
			velocity.setY(0);
		break;
	case SDLK_s:
		if (keyDownUp)
			velocity.setY(5.0);
		else
			velocity.setY(0);
		break;
	case SDLK_a:
		if (keyDownUp)
			velocity.setX(-1.0);
		else
			velocity.setX(0);
		break;
	case SDLK_d:
		if (keyDownUp)
			velocity.setX(1.0);
		else
			velocity.setX(0);
		break;
	default:
		success = false; //Keycode given that this function doesn't understand
		break;
	}
	return success;
}