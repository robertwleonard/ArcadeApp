#include "ArcadeScene.h"
#include "Screen.h"
#include "AARectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Line2D.h"
#include "Color.h"
#include "GameController.h"

ArcadeScene::ArcadeScene()
{
}

void ArcadeScene::Init()
{
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
		std::cout << "Mouse position x: " << mousePosition.xPos << " y: " << mousePosition.yPos << std::endl;
	});
}

void ArcadeScene::Update(uint32_t dt)
{
}

void ArcadeScene::Draw(Screen & theScreen)
{
	Line2D line = { Vec2D(0,0), Vec2D(theScreen.Width(), theScreen.Height()) };
	Triangle triangle = { Vec2D(60, 10), Vec2D(10, 110), Vec2D(110, 110) };
	AARectangle rect = { Vec2D(theScreen.Width() / 2 - 25, theScreen.Height() / 2 - 25), 50, 50 };
	Circle circle = { Vec2D(theScreen.Width() / 2 + 50, theScreen.Height() / 2 + 50), 50 };

	theScreen.Draw(triangle, Color(255, 255, 255, 80), true, Color(255, 255, 255, 80));
	theScreen.Draw(rect, Color::Blue(), true, Color::Blue());
	theScreen.Draw(circle, Color(255, 255, 255, 80), true, Color(0, 255, 0, 80));
	//mScreen.Draw(line, Color::White());
	//mScreen.Draw(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, Color::Yellow());
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