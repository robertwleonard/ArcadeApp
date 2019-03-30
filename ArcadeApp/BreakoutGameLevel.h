#pragma once
#include "Block.h"
#include <vector>
#include <stdint.h>

class Screen;
class Ball;
class AARectangle;

class BreakoutGameLevel
{
public:
	BreakoutGameLevel();
	void Init(const AARectangle& boundary);
	void Load(const std::vector<Block>& blocks);
	void Update(uint32_t dt, Ball& ball);
	void Draw(Screen& screen);
	
	bool IsLevelComplete() const;

	static std::vector<BreakoutGameLevel> LoadLevelsFromFile(const std::string& filePath);

private:
	static const unsigned int BLOCK_WIDTH = 16;
	static const unsigned int BLOCK_HEIGHT = 8;
	void CreateDefaultLevel(const AARectangle& boundary);
	std::vector<Block> mBlocks;
};

