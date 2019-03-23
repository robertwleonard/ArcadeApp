#include <iostream>
#include <SDL.h>
#undef main

#include "Color.h"
#include "Screen.h"
#include "Line2D.h"

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;
const int MAGNIFICATION = 3;

int main(int argc, const char* argv[])
{
	// Initialize the screen, draw to it, then swap the buffers
	Screen theScreen;
	theScreen.Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION);

	Line2D line = {Vec2D(0,0), Vec2D(SCREEN_WIDTH, SCREEN_HEIGHT)};
	theScreen.Draw(line, Color::White());
	//theScreen.Draw(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, Color::Yellow());

	theScreen.SwapScreens();

	// Set up the game loop
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
}
