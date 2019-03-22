#include <iostream>
#include <string>
#include "Vec2D.h"

int main(int argc, const char* argv[])
{
	Vec2D aVec(3,7);

	std::cout << aVec << std::endl;

	Vec2D resultVec = aVec *3;

	std::cout << resultVec << std::endl;

	resultVec = 3*aVec;

	std::cout << resultVec << std::endl;


	return 0;
}