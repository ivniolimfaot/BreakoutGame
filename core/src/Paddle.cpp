#pragma once
#include "Paddle.h"

void Paddle::draw(std::array<std::array<int, breakoutConstants::screenWidth>, breakoutConstants::screenHeight>& visibleMatrix) 
{
	for (int i = 0; i < 9; i++)
		visibleMatrix[y][x + i] = 1;
}

void Paddle::move(bool& decre_life)
{
	if (dir == 'L' && x - speed > 0)
	{
		x -= speed;
	}
	else if (dir == 'R' && x + speed < breakoutConstants::screenWidth - 9)
	{
		x += speed;
	}
	if (decre_life)
	{
		dir = 'S';
		x = breakoutConstants::screenWidth / 2 - 5;
		y = breakoutConstants::screenHeight - breakoutConstants::screenHeight / 7 - 1;
		decre_life = false;
	}
}

void Paddle::setDelay(int newDelay)
{
	this->delay = newDelay;
}

void Paddle::setSpeed(int newSpeed)
{
	this->speed = newSpeed;
}

void Paddle::setDirection(char newDirection)
{
	this->dir = newDirection;
}