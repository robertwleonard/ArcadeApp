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

	{
		mAnimationPlayer.Init(App::Singleton().GetBasePath() + "Assets/Pacman_animations.txt");
		mSpriteSheet.Load("PacmanSprites");
		mAnimationPlayer.Play("move_left", true);
	}
}

void ArcadeScene::Update(uint32_t dt)
{
	mAnimationPlayer.Update(dt);
}

void ArcadeScene::Draw(Screen & theScreen)
{
	ButtonOptionsScene::Draw(theScreen);

	AnimationFrame frame = mAnimationPlayer.GetCurrentAnimationFrame();
	Color frameColor = frame.frameColor;
	theScreen.Draw(mSpriteSheet, frame.frame, frame.offset, frameColor);
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