#include "App.h"
#include <SDL.h>
#undef main
#include <iostream>
#include "ArcadeScene.h"
#include <cassert>

App & App::Singleton()
{
	static App theApp;
	return theApp;
}

bool App::Init(uint32_t width, uint32_t height, uint32_t mag)
{
	mnoptrWindow = mScreen.Init(width, height, mag);
	std::unique_ptr<ArcadeScene> arcadeScene = std::make_unique<ArcadeScene>();
	PushScene(std::move(arcadeScene));
	return mnoptrWindow != nullptr;
}

void App::Run()
{
	if (mnoptrWindow)
	{
		// Set up the game loop
		SDL_Event sdlEvent;
		bool running = true;


		uint32_t lastTick = SDL_GetTicks();
		uint32_t currentTick = lastTick;

		uint32_t dt = 10;
		uint32_t accumulator = 0;

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

			Scene* topScene = App::TopScene();
			assert(topScene && "Why don't we have a scene?");
			if (topScene)
			{
				// Update
				while (accumulator >= dt)
				{
					// Update current scene by DT
					topScene->Update(dt);
					std::cout << "Delta time step: " << dt << std::endl;
					accumulator -= dt;
				}

				// Render
				topScene->Draw(mScreen);
			}

			
			mScreen.SwapScreens();
		}
	}
}

void App::PushScene(std::unique_ptr<Scene> scene)
{
	assert(scene && "Don't push nullptr");
	if (scene)
	{
		scene->Init();
		mSceneStack.emplace_back(std::move(scene));
		SDL_SetWindowTitle(mnoptrWindow, TopScene()->GetSceneName().c_str());
	}
}

void App::PopScene()
{
	if (mSceneStack.size() > 1)
		mSceneStack.pop_back();

	if (TopScene())
	{
		SDL_SetWindowTitle(mnoptrWindow, TopScene()->GetSceneName().c_str());
	}
}

Scene * App::TopScene()
{
	if (mSceneStack.empty())
		return nullptr;

	return mSceneStack.back().get();
}


