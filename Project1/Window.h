#pragma once
#include <SDL.h>
#include <string>
#include <memory>	

namespace detail
{
	struct SDLDeleter
	{
		inline void operator() (SDL_Texture *tex)
		{
			SDL_DestroyTexture(tex);
		}

		inline void operator() (SDL_Window *window)
		{
			SDL_DestroyWindow(window);
		}

		//etc
	};
}

typedef std::unique_ptr<SDL_Texture, detail::SDLDeleter> SDLTexture;


class Window
{
public:
	Window();
	~Window();
	/**
	*  Initialize SDL, setup the window and renderer
	*  @param title The window title
	*  @param width The window width
	*  @param height The window height
	*/
	static void Init(int, int, std::string title = "Window");
	//Quit SDL and TTF
	static void Quit();
	//Draw an SDL_Texture
	/**
	*  Draw a SDL_Texture to the screen at dstRect with various other options
	*  @param tex The SDL_Texture to draw
	*  @param dstRect The destination position and width/height to draw the texture with
	*  @param clip The clip to apply to the image, if desired
	*  @param angle The rotation angle to apply to the texture, default is 0
	*  @param xPivot The x coordinate of the pivot, relative to (0, 0) being center of dstRect
	*  @param yPivot The y coordinate of the pivot, relative to (0, 0) being center of dstRect
	*  @param flip The flip to apply to the image, default is none
	*/
	static void Draw(SDL_Texture *tex, SDL_Rect &dstRect, SDL_Rect *clip = NULL,
		float angle = 0.0, int xPivot = 0, int yPivot = 0,
		SDL_RendererFlip flip = SDL_FLIP_NONE);

	/**
	* Overloaded version of Draw that calculates the rect given an x and y
	* @param tex The SDL_Texture to draw
	* @param x The x coordinate of the rect to draw
	* @param y The y coordinate of the rect to draw
	*/
	static void Draw(SDL_Texture *tex, int x, int y);
	/**
	*  Loads an image directly to texture using SDL_image's
	*  built in function IMG_LoadTexture
	*  @param file The image file to load
	*  @return SDL_Texture* to the loaded texture
	*/
	static SDLTexture LoadImage(const std::string &file);
	/**
	*  Generate a texture containing the message we want to display
	*  @param message The message we want to display
	*  @param fontFile The font we want to use to render the text
	*  @param color The color we want the text to be
	*  @param fontSize The size we want the font to be
	*  @return An SDL_Texture* to the rendered message
	*/
	static SDLTexture RenderText(const std::string &message, const std::string &fontFile,
		SDL_Color color, int fontSize);
	//Clear window
	static void Clear();
	//Present renderer
	static void Present();
	//Get the window's box
	static SDL_Rect Box();

	static bool sdlRectsIntersect(SDL_Rect, SDL_Rect);
	static bool basicSdlRectsIntersect(SDL_Rect, SDL_Rect);

private:
	static std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> mWindow;
	static std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> mRenderer;
	static SDL_Rect mBox;
};

