#include "ArcadeScene.h"
#include "Screen.h"
#include "AARectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Line2D.h"
#include "Color.h"
#include "GameController.h"
#include "App.h"

ArcadeScene::ArcadeScene()
{
}

void ArcadeScene::Init()
{
	mTempSS.Load("ArcadeFont");

	ButtonAction action;
	action.key = GameController::ActionKey();
	action.action = [](uint32_t dt, InputState state) 
	{
		if (GameController::IsPressed(state))
		{
			std::cout << "Action button was pressed!" << std::endl;
		}
	};

	mGameController.AddInputActionForKey(action);

	MouseButtonAction mouseAction;
	mouseAction.mouseButton = GameController::LeftMouseButton();
	mouseAction.mouseInputAction = [](InputState state, const MousePosition& position)
	{
		if (GameController::IsPressed(state))
		{
			std::cout << "Left Mouse button pressed!" << std::endl;
		}
	};

	mGameController.AddMouseButtonAction(mouseAction);

	mGameController.SetMouseMovedAction([](const MousePosition& mousePosition)
	{
		//std::cout << "Mouse position x: " << mousePosition.xPos << " y: " << mousePosition.yPos << std::endl;
	});
}

void ArcadeScene::Update(uint32_t dt)
{
}

void ArcadeScene::Draw(Screen & theScreen)
{
	theScreen.Draw(mTempSS, "9", Vec2D::Zero);
}

const std::string & ArcadeScene::GetSceneName() const
{
	static std::string sceneName = "Aarchade Scene";
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
		
		default:
		{

		}
		break;
	}

	return nullptr;
}