#include <stdexcept>
#include <string>
#include <sstream>
#include <iostream>
#include "Player.h"
#include <math.h>

#if defined(_MSC_VER)
#include <SDL.h>
#elif defined(__clang__)
#include <SDL2/SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "window.h"
#include "timer.h"

int main(int argc, char** argv){
	//Start our window
	try {
		Window::Init(1300, 960, "Lesson 8");
	}
	catch (const std::runtime_error &e){
		std::cout << e.what() << std::endl;
		Window::Quit();
		return -1;
	}
	SDLTexture wave = std::move(Window::LoadImage("wave.png"));
	
	//SDLTexture texture(IMG_LoadTexture(...), SDL_DestroyTexture); // to initialise it immediately
	//Our timer:
	Timer timer;
	//Rects for the text
	SDL_Rect waveBox;

	waveBox.x = 0;
	waveBox.y = Window::Box().h / 4;
	SDL_QueryTexture(wave.get(), NULL, NULL, &waveBox.w, &waveBox.h);

	std::cout << Window::Box().w/waveBox.w << std::endl;

	//Our event structure
	SDL_Event e;
	//For tracking if we want to quit
	bool quit = false;
	float waveCounter = 0;

	Player *player = new Player();

	while (!quit){
		//Event Polling
		while (SDL_PollEvent(&e)){
			//If user closes he window
			if (e.type == SDL_QUIT)
				quit = true;
			if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_w:
				case SDLK_a:
				case SDLK_s:
				case SDLK_d:
					player->move(e.key.keysym.sym, (e.type == SDL_KEYDOWN));
					break;
				default:
					break;
				}
			}
			//If user presses any key
		}

		//RENDERING
		Window::Clear();
		player->addRectX(cosf(player->getRotation())*player->getVelocity().getY());
		player->addRectY(sinf(player->getRotation())*player->getVelocity().getY());
		player->addRotation(player->getVelocity().getX() * 0.1f);
		player->draw();

		for (int x = 0; x < Window::Box().w; x += waveBox.w)
		{
			Window::Draw(wave.get(), waveBox);
			waveBox.x = x + (waveCounter - 1) * waveBox.w;
		}
		waveCounter += 0.1f; 
		if (waveCounter > 1)
			waveCounter = 0;
		Window::Present();
	}
	Window::Quit();

	return 0;
}