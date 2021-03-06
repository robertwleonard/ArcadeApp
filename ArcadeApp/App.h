#pragma once
#include <stdint.h>
#include <vector>
#include <memory>

#include "Screen.h"
#include "Scene.h"
#include "InputController.h"
#include "BitmapFont.h"

struct SDL_Window;

class App
{
public:
	bool Init(uint32_t width, uint32_t height, uint32_t mag);
	void Run();
	static App& Singleton();

	inline uint32_t Width() const {return mScreen.Width();}
	inline uint32_t Height() const {return mScreen.Height(); }

	void PushScene(std::unique_ptr<Scene> scene);
	void PopScene();
	Scene* TopScene();

	static const std::string& GetBasePath();
	inline const BitmapFont& GetFont() const { return mFont; }

private:
	Screen mScreen;
	SDL_Window* mnoptrWindow;

	std::vector<std::unique_ptr<Scene>> mSceneStack;
	InputController mInputController;
	BitmapFont mFont;
};

