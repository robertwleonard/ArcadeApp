#pragma once
#include <iostream>

class Vec2D
{

public:
	static const Vec2D Zero;

	Vec2D();
	Vec2D(float x, float y);
	~Vec2D();

	inline void SetX(float x);
	inline void SetY(float y);
	inline float GetX() const;
	inline float GetY() const;

	friend std::ostream& operator<<(std::ostream& consoleOut, const Vec2D& vec);

	bool operator==(const Vec2D& vec2) const;
	bool operator!=(const Vec2D& vec2) const;

	Vec2D operator-() const;

private:
	float mX;
	float mY;
};

