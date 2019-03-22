#include "Vec2D.h"
#include "Utils.h"
#include <cassert>
#include <cmath>

const Vec2D Vec2D::Zero;

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

Vec2D Vec2D::operator*(float scale) const
{
	return Vec2D(scale *mX, scale * mY);
}

Vec2D Vec2D::operator/(float scale) const
{
	assert(fabs(scale) > EPSILON);
	return Vec2D(scale / mX, scale / mY);
}

Vec2D & Vec2D::operator*=(float scale)
{
	*this = *this * scale;
	return *this;
}

Vec2D & Vec2D::operator/=(float scale)
{
	*this = *this / scale;
	return *this;
}

Vec2D Vec2D::operator+(const Vec2D & vec) const
{
	return Vec2D(mX + vec.mX, mY + vec.mY);
}

Vec2D Vec2D::operator-(const Vec2D & vec) const
{
	return Vec2D(mX - vec.mX, mY - vec.mY);
}

Vec2D & Vec2D::operator+=(const Vec2D & vec)
{
	*this = *this + vec;
	return *this;
}

Vec2D & Vec2D::operator-=(const Vec2D & vec)
{
	*this = *this - vec;
	return *this;
}

float Vec2D::Mag2() const
{
	return mX * mX + mY * mY;
}

float Vec2D::Mag() const
{
	return sqrt(Mag2());
}

Vec2D Vec2D::GetUnitVec() const
{
	float mag = Mag();

	if (mag > EPSILON)
		return *this / mag;

	return Vec2D::Zero;
}

Vec2D & Vec2D::Normalize()
{
	float mag = Mag();
	if (mag > EPSILON)
		*this /= mag;

	return *this;
}

std::ostream& operator<<(std::ostream & consoleOut, const Vec2D& vec)
{
	consoleOut << "X: " << vec.mX << " Y: " << vec.mY << std::endl;
	return consoleOut;
}

Vec2D operator*(float scalar, const Vec2D & vec)
{
	return vec * scalar;
}
