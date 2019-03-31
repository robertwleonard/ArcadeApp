#include "ArcadeScene.h"
#include "Screen.h"
#include "GameScene.h"
#include "BreakOut.h"
#include "GameController.h"
#include "App.h"
#include "NotImplementedScene.h"

ArcadeScene::ArcadeScene()
	: ButtonOptionsScene({"Tetris", "Break Out", "Asteroids", "!Pac-man"}, Color::Cyan())
{
}

void ArcadeScene::Init()
{
	std::vector<Button::ButtonAction> actions;

	actions.push_back([this] {
		App::Singleton().PushScene(GetScene(TETRIS));
	});

	actions.push_back([this] {
		App::Singleton().PushScene(GetScene(BREAKOUT));
	});

	actions.push_back([this] {
		App::Singleton().PushScene(GetScene(ASTEROIDS));
	});

	actions.push_back([this] {
		App::Singleton().PushScene(GetScene(PACMAN));
	});

	SetButtonActions(actions);

	ButtonOptionsScene::Init();
}

void ArcadeScene::Update(uint32_t dt)
{
}

void ArcadeScene::Draw(Screen & theScreen)
{
	ButtonOptionsScene::Draw(theScreen);
}

const std::string & ArcadeScene::GetSceneName() const
{
	static std::string sceneName = "Aarchade";
	return sceneName;
}

std::unique_ptr<Scene> ArcadeScene::GetScene(eGame game)
{
	switch (game)
	{
		case TETRIS:
		{

		}
		break;

		case BREAKOUT:
		{
			std::unique_ptr<BreakOut> breakoutGame = std::make_unique<BreakOut>();
			std::unique_ptr<GameScene> breakoutScene = std::make_unique<GameScene>(std::move(breakoutGame));
			return breakoutScene;
		}
		break;

		case ASTEROIDS:
		{

		}
		break;

		case PACMAN:
		{

		}
		break;
	}

	std::unique_ptr<Scene> notImplementedScene = std::make_unique<NotImplementedScene>();

	return notImplementedScene;
}