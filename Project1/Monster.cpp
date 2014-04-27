#include "Monster.h"
#include "Timer.h"
#include <math.h>

#include <SDL.h>

Monster::Monster()
{
	tex = std::move(Window::LoadImage("monster1.png"));
	ticksOnCreation = SDL_GetTicks();
	velocity.setY(2.5);
	velocity.setX(0.0);
	SDL_QueryTexture(tex.get(), NULL, NULL, &rect.w, &rect.h);
	rect.x = (rand() / float(RAND_MAX)) * (Window::Box().w - rect.w);
	rect.y = rand() % ((Window::Box().h - rect.h) - ((Window::Box().h / 4) + 40) + 1) + ((Window::Box().h / 4) + 40);
}

Monster::~Monster()
{
}

bool Monster::move()
{
	int animationTicks = 2500;
	int tickCounter = SDL_GetTicks() - ticksOnCreation;
	if (tickCounter > animationTicks)
	{
		velocity.setY(velocity.getY() * -1.0);
		ticksOnCreation = SDL_GetTicks();
	}
	return true;
}