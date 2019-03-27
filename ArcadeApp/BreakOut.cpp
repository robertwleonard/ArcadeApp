#include "BreakOut.h"
#include <iostream>

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
	std::cout << "Break Out init()" << std::endl;
}

void BreakOut::Update(uint32_t dt)
{
	std::cout << "Break Out update()" << std::endl;
}

void BreakOut::Draw(Screen & screen)
{
	std::cout << "Break Out Draw()" << std::endl;
}

std::string BreakOut::GetName() const
{
	return "Break Out!";
}
