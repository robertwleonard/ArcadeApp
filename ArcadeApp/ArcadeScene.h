#pragma once
#include "ButtonOptionsScene.h"
#include "AnimationPlayer.h"
#include <memory>

class Screen;

enum eGame
{
	TETRIS = 0,
	BREAKOUT,
	ASTEROIDS,
	PACMAN,
	NUM_GAMES
};

class ArcadeScene :
	public ButtonOptionsScene
{
public:
	ArcadeScene();
	virtual void Init() override;
	virtual void Update(uint32_t dt) override;
	virtual void Draw(Screen& theScreen) override;
	virtual const std::string& GetSceneName() const override;

private:
	std::unique_ptr<Scene> GetScene(eGame game);

	AnimationPlayer mAnimationPlayer;
	SpriteSheet mSpriteSheet;
};

