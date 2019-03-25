#include "App.h"
#include <SDL.h>
#undef main
#include <iostream>
#include "Line2D.h"
#include "AARectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Color.h"

void App::Run()
{
	if (mnoptrWindow)
	{
		// Initialize the screen, draw to it, then swap the buffers
		Line2D line = { Vec2D(0,0), Vec2D(mScreen.Width(), mScreen.Height()) };
		Triangle triangle = { Vec2D(60, 10), Vec2D(10, 110), Vec2D(110, 110) };
		AARectangle rect = { Vec2D(mScreen.Width() / 2 - 25, mScreen.Height() / 2 - 25), 50, 50 };
		Circle circle = { Vec2D(mScreen.Width() / 2 + 50, mScreen.Height() / 2 + 50), 50 };

		mScreen.SwapScreens();

		// Set up the game loop
		SDL_Event sdlEvent;
		uint32_t lastTick = SDL_GetTicks();
		uint32_t currentTick = lastTick;

		uint32_t dt = 10;
		uint32_t accumulator = 0;

		bool running = true;
		while (running)
		{
			currentTick = SDL_GetTicks();
			uint32_t frameTime = currentTick - lastTick;

			if (frameTime > 300)
				frameTime = 300;

			lastTick = currentTick;
			accumulator += frameTime;

			// Input
			while (SDL_PollEvent(&sdlEvent))
			{
				switch (sdlEvent.type)
				{
				case SDL_QUIT:
					running = false;
					break;
				}
			}

			// Update
			while (accumulator >= dt)
			{
				// Update current scene by DT
				std::cout << "Delta time step: " << dt << std::endl;
				accumulator -= dt;
			}

			// Render
			mScreen.Draw(triangle, Color(255, 255, 255, 80), true, Color(255, 255, 255, 80));
			mScreen.Draw(rect, Color::Blue(), true, Color::Blue());
			mScreen.Draw(circle, Color(255, 255, 255, 80), true, Color(0, 255, 0, 80));
			//mScreen.Draw(line, Color::White());
			//mScreen.Draw(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, Color::Yellow());

			mScreen.SwapScreens();
		}
	}
}

App & App::Singleton()
{
	static App theApp;
	return theApp;
}

App::App()
{
}

bool App::Init(uint32_t width, uint32_t height, uint32_t mag)
{
	mnoptrWindow = mScreen.Init(width, height, mag);
	return mnoptrWindow != nullptr;
}
