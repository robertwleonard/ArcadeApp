#include <iostream>
#include <SDL.h>
#undef main

#include "Color.h"

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;

void SetPixel(SDL_Surface* noptrWindowSurface, uint32_t color, int x, int  y);
size_t GetIndex(SDL_Surface*, int r, int c);

int main(int argc, const char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		std::cout << "Error SDL_Init Failed" << std::endl;
		return 1;
	}

	SDL_Window* optrWindow = SDL_CreateWindow("Aarcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	
	if (optrWindow == nullptr)
	{
		std::cout << "Could not create window, got error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Surface* noptrWindowSurface = SDL_GetWindowSurface(optrWindow);
	SDL_PixelFormat* pixelFormat = noptrWindowSurface->format;
	std::cout << "The window pixel format is: " << SDL_GetPixelFormatName(pixelFormat->format);
	
	Color::InitColorFormat(pixelFormat);

	SetPixel(noptrWindowSurface, Color::Orange().GetPixelColor(), SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
	SDL_UpdateWindowSurface(optrWindow);

	SDL_Event sdlEvent;
	bool running = true;

	while (running)
	{
		while (SDL_PollEvent(&sdlEvent))
		{
			switch (sdlEvent.type)
			{
				case SDL_QUIT:
					running = false;
					break;
			}
		}
	}

	SDL_DestroyWindow(optrWindow);
	SDL_Quit();
}

void SetPixel(SDL_Surface* noptrWindowSurface, uint32_t color, int x, int  y)
{
	SDL_LockSurface(noptrWindowSurface);

	uint32_t* pixels = (uint32_t*)noptrWindowSurface->pixels;

	size_t index = GetIndex(noptrWindowSurface, y, x);
	pixels[index] = color;
	
	SDL_UnlockSurface(noptrWindowSurface);
}

size_t GetIndex(SDL_Surface* noptrWindowSurface, int r, int c)
{
	return r * noptrWindowSurface->w + c;
}