#pragma once
#include <stdint.h>

#include "Screen.h"

struct SDL_Window;

class App
{
public:
	App();
	bool Init(uint32_t width, uint32_t height, uint32_t mag);

	inline uint32_t Width() const {return mScreen.Width();}
	inline uint32_t Height() const {return mScreen.Height(); }

	void Run();
	static App& Singleton();

private:
	Screen mScreen;
	SDL_Window* mnoptrWindow;
};

