#pragma once
#include "BreakoutConstants.h"
#include <array>

class Paddle 
{
	int delay;
	char dir;
	int speed;
public:
	int x;
	int y;
	
	
	void draw(std::array<std::array<int, breakoutConstants::screenWidth>, breakoutConstants::screenHeight>& visibleMatrix);
	void setDelay(int);
	void move(bool& decre_life);
	void setSpeed(int newSpeed);
	void setDirection(char newDirection);
};