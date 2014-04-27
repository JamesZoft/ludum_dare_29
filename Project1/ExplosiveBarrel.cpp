#include "ExplosiveBarrel.h"
#include <iostream>

ExplosiveBarrel::ExplosiveBarrel()
{
	tex = std::move(Window::LoadImage("explosive_barrel.png"));
	ticksOnCreation = SDL_GetTicks();
	velocity.setY(2.5);
	velocity.setX(0.0);
	SDL_QueryTexture(tex.get(), NULL, NULL, &rect.w, &rect.h);
	rect.x = (rand() / float(RAND_MAX)) * (Window::Box().w - rect.w);
	rect.y = rand() % (((Window::Box().h / 4) - rect.h) + rect.h);
	//rect.y = rand() % ((Window::Box().h - rect.h) - ((Window::Box().h / 4) + 40) + 1) + ((Window::Box().h / 4) + 40);
}

void ExplosiveBarrel::addRectY(int _y)
{
	if (rect.y + _y <= (Window::Box().h - rect.h) && rect.y + _y >= 0)
		rect.y += _y;
}


ExplosiveBarrel::~ExplosiveBarrel()
{
}


bool ExplosiveBarrel::move()
{
	//Make sure we always animate it to at least below the surface
	//int animationTicks = (rand() / float(RAND_MAX)) * ((Window::Box().h - rect.h) - (Window::Box().h / 4) + 1) + (Window::Box().h / 4) + 1000;
	int animationTicks = 6000;
	std::cout << "animticks: " << animationTicks << std::endl;
	int tickCounter = SDL_GetTicks() - ticksOnCreation;
	if (tickCounter > animationTicks)
	{
		velocity.setY(velocity.getY() * -1.0);
		ticksOnCreation = SDL_GetTicks();
	}
	return true;
}