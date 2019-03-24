#pragma once
#include "Vec2D.h"
#include <vector>

class Shape
{
public:
	Shape();
	virtual ~Shape();

	virtual Vec2D GetCenterPoint() const =0;
	inline virtual std::vector<Vec2D> GetPoints() const {return mPoints;}
	void MoveBy(const Vec2D& deltaOffset);

protected:
	std::vector<Vec2D> mPoints;
};

