#include "GameAttributeManager.h"
#include "Window.h"
#include <SDL.h>
#include <sstream>

GameAttributeManager::GameAttributeManager()
{
	textColor = { 255, 255, 255 };
}


GameAttributeManager::~GameAttributeManager()
{
}

void GameAttributeManager::updateScore()
{
	score++;
	std::stringstream ssScore;
	ssScore << score;
	scoreTex = Window::RenderText(ssScore.str(), ttfFontFileName, textColor, 30);
}

void GameAttributeManager::updateTimeElapsed()
{
	timeElapsed++;
	std::stringstream ssTime;
	ssTime << timeElapsed/60;
	timeTex = Window::RenderText(ssTime.str(), ttfFontFileName, textColor, 30);
}

SDL_Texture* GameAttributeManager::getScoreTex()
{
	return scoreTex.get();
}

SDL_Texture* GameAttributeManager::getTimeTex()
{
	return timeTex.get();
}

SDL_Color GameAttributeManager::getTextColor()
{
	return textColor;
}

std::string GameAttributeManager::getTtfFontFileName()
{
	return ttfFontFileName;
}