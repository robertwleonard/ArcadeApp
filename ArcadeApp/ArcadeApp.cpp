#include <iostream>
#include <SDL.h>
#undef main

#include "Color.h"
#include "Screen.h"
#include "Line2D.h"
#include "Triangle.h"
#include "AARectangle.h"
#include "Circle.h"

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;
const int MAGNIFICATION = 3;

int main(int argc, const char* argv[])
{
	// Initialize the screen, draw to it, then swap the buffers
	Screen theScreen;
	theScreen.Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION);

	Line2D line = {Vec2D(0,0), Vec2D(SCREEN_WIDTH, SCREEN_HEIGHT)};
	Triangle triangle = {Vec2D(60, 10), Vec2D(10, 110), Vec2D(110, 110)};
	AARectangle rect = {Vec2D(SCREEN_WIDTH/2-25, SCREEN_HEIGHT/2-25), 50, 50};
	Circle circle = {Vec2D(SCREEN_WIDTH/2 + 50, SCREEN_HEIGHT/2+50), 50};

	theScreen.Draw(triangle, Color::Red(), true, Color::Red());
	theScreen.Draw(rect, Color::Blue(), true, Color::Blue());
	theScreen.Draw(circle, Color::Green(), true, Color::Green());
	//theScreen.Draw(line, Color::White());
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
