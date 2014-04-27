#include <stdexcept>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h> 

#include "Player.h"
#include "Monster.h"
#include "MonsterController.h"
#include "GameAttributeManager.h"

#if defined(_MSC_VER)
#include <SDL.h>
#include <SDL_ttf.h>
#elif defined(__clang__)
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#endif

#include "window.h"
#include "timer.h"
#include <vector>


int main(int argc, char** argv){
	srand(time(NULL));
	rand();
	rand();
	rand();
	//Start our window
	int horizPix = 1920;
	int vertPix = 1080;
	try {
		Window::Init(horizPix, vertPix, "");
	}
	catch (const std::runtime_error &e){
		std::cout << e.what() << std::endl;
		Window::Quit();
		return -1;
	}
	SDLTexture wave = std::move(Window::LoadImage("wave.png"));
	SDLTexture blueSquareOcean = std::move(Window::LoadImage("blue_square_ocean.png"));


	//Our timer:
	Timer timer;
	//Rects for the text
	SDL_Rect waveBox;

	waveBox.x = 0;
	waveBox.y = Window::Box().h / 4;
	SDL_QueryTexture(wave.get(), NULL, NULL, &waveBox.w, &waveBox.h);

	int blueSquareOceanBoxW, blueSquareOceanBoxH;
	SDL_QueryTexture(blueSquareOcean.get(), NULL, NULL, &blueSquareOceanBoxW, &blueSquareOceanBoxH);
	

	std::cout << Window::Box().w/waveBox.w << std::endl;

	//Our event structure
	SDL_Event e;
	//For tracking if we want to quit
	bool quit = false;
	float waveCounter = 0;

	Player player;
	MonsterController mController;

	int score = 0;
	int timeElapsed = 0;
	std::stringstream ssScore;
	ssScore << score;
	std::stringstream ssTime;
	ssTime << timeElapsed;

	GameAttributeManager gameAttrMan;
	SDLTexture staticScoreText = Window::RenderText("Score: ", gameAttrMan.getTtfFontFileName(), gameAttrMan.getTextColor(), 30);
	SDLTexture staticTimeText = Window::RenderText("Time Elapsed: ", gameAttrMan.getTtfFontFileName(), gameAttrMan.getTextColor(), 30);
	SDLTexture staticLoseText = Window::RenderText("You lose!", gameAttrMan.getTtfFontFileName(), gameAttrMan.getTextColor(), 100);
	
	

	while (!quit){
		gameAttrMan.updateTimeElapsed();
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
					player.move(e.key.keysym.sym, (e.type == SDL_KEYDOWN));
					break;
				default:
					break;
				}
			}
			//If user presses any key
		}

		//RENDERING
		Window::Clear();
		

		//Make the waves
		for (int x = (-waveBox.w); (x + waveCounter - 1) <= Window::Box().w; x += waveBox.w)
		{
			waveBox.x = x + (waveCounter - 1) * waveBox.w;
			Window::Draw(wave.get(), waveBox);
			
		}
		//Make the ocean
		for (int x = 0; x < Window::Box().w; x += blueSquareOceanBoxW)
		{
			for (int y = ((Window::Box().h / 4) + waveBox.h); y < Window::Box().h; y += blueSquareOceanBoxH)
			{
				Window::Draw(blueSquareOcean.get(), x, y);
			}
		}
		player.addRectX(cosf(player.getRotation()) * player.getVelocity().getY());
		player.addRectY(sinf(player.getRotation()) * player.getVelocity().getY());
		player.addRotation(player.getVelocity().getX() * 0.1f);
		player.draw();
		mController.checkDestroyMonsters(player.getRect(), gameAttrMan);
		mController.createMonsters();
		mController.moveAndDrawMonsters();
		if (mController.checkDestroyBarrels(player.getRect(), gameAttrMan) == -1)
		{
			Window::Draw(staticLoseText.get(), Window::Box().w / 2, Window::Box().h / 2);
			Window::Present();
			SDL_Delay(5000);
			quit = true;
		}
		mController.createBarrels();
		mController.moveAndDrawBarrels();
		Window::Draw(staticScoreText.get(), 0, 0);
		Window::Draw(gameAttrMan.getScoreTex(), 200, 0);
		Window::Draw(staticTimeText.get(), 0, 60);
		Window::Draw(gameAttrMan.getTimeTex(), 200, 60);
		waveCounter += 0.1f; 
		if (waveCounter > 1)
			waveCounter = 0;
		Window::Present();
	}
	Window::Quit();

	return 0;
}
