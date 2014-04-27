#pragma once
#include "Window.h"
#include <SDL.h>

class GameAttributeManager
{
public:
	GameAttributeManager();
	~GameAttributeManager();
	void GameAttributeManager::updateScore();
	void GameAttributeManager::updateTimeElapsed();
	SDL_Color getTextColor();
	SDL_Texture* getScoreTex();
	SDL_Texture* getTimeTex();
	std::string getTtfFontFileName();
private:
	SDL_Color textColor;
	std::string ttfFontFileName = "BabelSans.ttf";
	SDLTexture scoreTex;
	SDLTexture timeTex;
	int score;
	int timeElapsed;
};

