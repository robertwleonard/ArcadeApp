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
	Vec2D operator*(float scale) const;
	Vec2D operator/(float scale) const;
	Vec2D& operator*=(float scale);
	Vec2D& operator/=(float scale);

	Vec2D operator+(const Vec2D& vec) const;
	Vec2D operator-(const Vec2D& vec) const;
	Vec2D& operator+=(const Vec2D& vec);
	Vec2D& operator-=(const Vec2D& vec);

	float Mag2() const;
	float Mag() const;

	Vec2D GetUnitVec() const;
	Vec2D& Normalize();

	float Distance(const Vec2D& vec) const;
	float Dot(const Vec2D& vec) const;

	Vec2D ProjectOnto(const Vec2D& vec2) const;
	
	float AngleBetween(const Vec2D& vec2) const;

	Vec2D Reflect(const Vec2D& normal) const;

	void Rotate(float angle, const Vec2D& aroundPoint);
	Vec2D RotationResult(float angle, const Vec2D& aroundPoint) const;

	friend Vec2D operator*(float scalar, const Vec2D& vec);

private:
	float mX;
	float mY;
};

