#include "Screen.h"
#include "Vec2D.h"
#include <SDL.h>
#include <cassert>

Screen::Screen() : mWidth(0), mHeight(0), moptrWindow(nullptr)
{
}

Screen::~Screen()
{
	// Don't forget to destruct the window
	if (moptrWindow)
	{
		SDL_DestroyWindow(moptrWindow);
		moptrWindow = nullptr;
	}

	SDL_Quit();
}

SDL_Window* Screen::Init(uint32_t w, uint32_t h, uint32_t mag)
{
	// Make sure the initialization is valid
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		std::cout << "Error SDL_Init Failed" << std::endl;
		return nullptr;
	}

	mWidth = w;
	mHeight = h;

	// Create our window on the heap (must be destructed)
	moptrWindow = SDL_CreateWindow("Aarcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mWidth * mag, mHeight * mag, 0);

	// If the window set up correctly, initialize the values
	if (moptrWindow)
	{
		mnoptrWindowSurface = SDL_GetWindowSurface(moptrWindow);
		SDL_PixelFormat* pixelFormat = mnoptrWindowSurface->format;
		Color::InitColorFormat(pixelFormat);
		mClearColor = Color::Black();
		mBackBuffer.Init(pixelFormat->format, mWidth, mHeight);
		mBackBuffer.Clear(mClearColor);
	}

	return moptrWindow;
}

// Used in double buffering. Fill in mBackBuffer, then swap it to the front
void Screen::SwapScreens()
{
	assert(moptrWindow);
	if (moptrWindow)
	{
		ClearScreen();
		// Swap the back buffer to the surface
		SDL_BlitScaled(mBackBuffer.GetSurface(), nullptr, mnoptrWindowSurface, nullptr);
		// Update the window surface
		SDL_UpdateWindowSurface(moptrWindow);
		// Clear the back buffer for the next update
		mBackBuffer.Clear(mClearColor);
	}
}

// Draw at coordinates
void Screen::Draw(int x, int y, const Color & color)
{
	assert(moptrWindow);
	if (moptrWindow)
		mBackBuffer.SetPixel(color, x, y);
}

// Draw a vector
void Screen::Draw(const Vec2D & point, const Color & color)
{
	assert(moptrWindow);
	if (moptrWindow)
		mBackBuffer.SetPixel(color, point.GetX(), point.GetY());
}

Screen & Screen::operator=(const Screen & screen)
{
	return *this;
}

void Screen::ClearScreen()
{
	assert(moptrWindow);
	if (moptrWindow)
		SDL_FillRect(mnoptrWindowSurface, nullptr, mClearColor.GetPixelColor());
}
