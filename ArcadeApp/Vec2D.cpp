#include "Vec2D.h"
#include "Utils.h"

Vec2D::Vec2D() : Vec2D(0, 0)
{
}

Vec2D::Vec2D(float x, float y) : mX(x), mY(y)
{

}

Vec2D::~Vec2D()
{
}

const Vec2D Vec2D::Zero;

inline void Vec2D::SetX(float x)
{
	mX = x;
}

inline void Vec2D::SetY(float y)
{
	mY = y;
}

inline float Vec2D::GetX() const
{
	return mX;
}

inline float Vec2D::GetY() const
{
	return mY;
}

bool Vec2D::operator==(const Vec2D & vec2) const
{
	return IsEqual(mX, vec2.mX) && IsEqual(mY, vec2.mY);
}

bool Vec2D::operator!=(const Vec2D & vec2) const
{
	return !(*this == vec2);
}

Vec2D Vec2D::operator-() const
{
	return Vec2D(-mX, -mY);
}

std::ostream& operator<<(std::ostream & consoleOut, const Vec2D& vec)
{
	consoleOut << "X: " << vec.mX << " Y: " << vec.mY << std::endl;
	return consoleOut;
}