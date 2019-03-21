#include "Utils.h"
#include <cmath>

static const float EPSILON = 0.0001f;

bool IsEqual(float x, float y)
{
	return fabsf(x-y) < EPSILON;
}

bool IsGreaterThanOrEqual(float x, float y)
{
	return x > y || IsEqual(x, y);
}

bool IsLessThanOrEqual(float x, float y)
{
	return x < y || IsEqual(x, y);
}
