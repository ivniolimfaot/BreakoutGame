#pragma once
#include <array>
#include "BreakoutConstants.h"

class Ball 
{
	void collisionReact(std::array<std::array<int, breakoutConstants::screenWidth>, breakoutConstants::screenHeight>& visibleMatrix,
		std::array<std::array<int, breakoutConstants::blocksWidth>, breakoutConstants::blocksHeight>& blocks,
		size_t& score, int fx, int fy, int x, int y, int collised, int collisedProd);

	int dir;
public:
	int x;
	int y;
	int speed;
	

	void draw(std::array<std::array<int, breakoutConstants::screenWidth>, breakoutConstants::screenHeight>& visibleMatrix);
	void move(std::array<std::array<int, breakoutConstants::screenWidth>, breakoutConstants::screenHeight>& visibleMatrix,
		std::array<std::array<int, breakoutConstants::blocksWidth>, breakoutConstants::blocksHeight>& blocks,
		bool& decreLife, int& lifes, size_t& score);

	bool collision(std::array<std::array<int, breakoutConstants::screenWidth>, breakoutConstants::screenHeight>& visibleMatrix,
		std::array<std::array<int, breakoutConstants::blocksWidth>, breakoutConstants::blocksHeight>& blocks,
		bool& decreLife, int& lifes, size_t& score, int fx, int fy);

	void bounce(int fx, int fy);

	void setDirection(int direct);
	int getDirection();

};