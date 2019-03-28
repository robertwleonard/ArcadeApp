#include "BreakOut.h"
#include <iostream>
#include "GameController.h"
#include "App.h"

/*
	Paddle
		- Can move side to side by user
		- Stops at edges of screen
		- Width and height
		- Bounces the ball
			- Bounces differently based on position that hit the paddle

	Ball
		- Bounces off walls and paddle
		- Width and height
		- Velocity
		- Can break blocks

	Block
		- Part of the level
		- HP - One hit by the ball is -1 HP
		- Color, position, width, and height (AARectangle)
		- Bounces the ball

	Level
		- Container that holds all blocks
		- Load level from the levels.txt file
		- Handle collisions of the block
		- Contains the walls/edges of the screen
		- Reset the level

	Game
		- Contains all the objects (paddle, ball, levels)
		- Player which has 3 lives
		- States - serve, in game, game over
		- Reset the game
*/

void BreakOut::Init(GameController & controller)
{
	controller.ClearAll();
	ResetGame();

	ButtonAction leftKeyAction;
	leftKeyAction.key = GameController::LeftKey();
	leftKeyAction.action = [this](uint32_t dt, InputState state)
	{
		if (GameController::IsPressed(state))
		{
			mPaddle.SetMovementDirection(PaddleDirection::LEFT);
		}
		else
		{
			mPaddle.UnsetMovementDirection(PaddleDirection::LEFT);
		}
	};

	controller.AddInputActionForKey(leftKeyAction);

	ButtonAction rightKeyAction;
	rightKeyAction.key = GameController::RightKey();
	rightKeyAction.action = [this](uint32_t dt, InputState state)
	{
		if (GameController::IsPressed(state))
		{
			mPaddle.SetMovementDirection(PaddleDirection::RIGHT);
		}
		else
		{
			mPaddle.UnsetMovementDirection(PaddleDirection::RIGHT);
		}
	};

	controller.AddInputActionForKey(rightKeyAction);
}

void BreakOut::Update(uint32_t dt)
{
	mPaddle.Update(dt);
}

void BreakOut::Draw(Screen & screen)
{
	mPaddle.Draw(screen);
}

std::string BreakOut::GetName() const
{
	return "Break Out!";
}

void BreakOut::ResetGame()
{
	AARectangle paddleRect = { Vec2D(App::Singleton().Width() / 2 - Paddle::PADDLE_WIDTH / 2, 
		App::Singleton().Height() - 3 * Paddle::PADDLE_HEIGHT), Paddle::PADDLE_WIDTH, Paddle::PADDLE_HEIGHT };
	AARectangle levelBoundary = {Vec2D::Zero, App::Singleton().Width(), App::Singleton().Height()};
	mPaddle.Init(paddleRect, levelBoundary);
}
