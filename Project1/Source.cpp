#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdexcept>
#include <iostream>
#include <stdexcept>
#include <string>
#include <iostream>
/*
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;

SDL_Texture* LoadImage(std::string file){
	SDL_Texture* tex = nullptr;
	tex = IMG_LoadTexture(renderer, file.c_str());
	if (tex == nullptr)
		throw std::runtime_error("Failed to load image: " + file + IMG_GetError());
	return tex;
}


SDL_Texture* RenderText(std::string message, std::string fontFile,
	SDL_Color color, int fontSize)
{
	//Open the font
	TTF_Font *font = nullptr;
	font = TTF_OpenFont(fontFile.c_str(), fontSize);
	if (font == nullptr)
		throw std::runtime_error("Failed to load font: " + fontFile + TTF_GetError());

	//Render the message to an SDL_Surface, as that's what TTF_RenderText_X returns
	SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
	//Clean up unneeded stuff
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);

	return texture;
}

void ApplySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend, SDL_Rect *clip = NULL){
SDL_Rect pos;
pos.x = x;
pos.y = y;
//Detect if we should use clip width settings or texture width
if (clip != NULL){
pos.w = clip->w;
pos.h = clip->h;
}
else {
SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
}
SDL_RenderCopy(rend, tex, clip, &pos);
}

int main(int argc, char** argv){
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1){
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}

	if (TTF_Init() == -1){
		std::cout << TTF_GetError() << std::endl;
		return 2;
	}

	window = SDL_CreateWindow("Lesson 2", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr){
		std::cout << SDL_GetError() << std::endl;
		return 2;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED
		| SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr){
		std::cout << SDL_GetError() << std::endl;
		return 3;
	}

	SDL_Texture *image = nullptr;
	try {
		SDL_Color color = { 255, 255, 255 };
		image = RenderText("T blahqwedfg", "ASMAN.TTF",
			color, 64);
	}
	catch (const std::runtime_error &e){
		std::cout << e.what() << std::endl;
		return 4;
	}
	std::cout << SDL_GetError() << std::endl;
	//iW and iH are the desired clip width and height
	int iW = 100, iH = 100;
	
	int x = SCREEN_WIDTH / 2 - iW / 2;
	int y = SCREEN_HEIGHT / 2 - iH / 2;

	SDL_Event e;

	bool quit = false;
	
	
	while (!quit){
		//Event polling
		while (SDL_PollEvent(&e)){
			//If user closes he window
			if (e.type == SDL_QUIT)
				quit = true;
			//If user clicks the mouse
			if (e.type == SDL_MOUSEBUTTONDOWN)
				quit = true;
		}
		SDL_RenderClear(renderer);
		ApplySurface(x, y, image, renderer, NULL);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	
	return 0;
}
*/