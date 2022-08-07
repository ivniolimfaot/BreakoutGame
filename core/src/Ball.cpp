#pragma once
#include "Ball.h"


void Ball::draw(std::array<std::array<int, breakoutConstants::screenWidth>, breakoutConstants::screenHeight>& visibleMatrix)
{
	visibleMatrix[y][x] = 5;
}

void Ball::move(std::array<std::array<int, breakoutConstants::screenWidth>, breakoutConstants::screenHeight>& visibleMatrix,
	std::array<std::array<int, breakoutConstants::blocksWidth>, breakoutConstants::blocksHeight>& blocks,
	bool& decreLife, int& lifes, size_t& score)
{
	if (dir == 0 && !collision(visibleMatrix, blocks, decreLife, lifes, score, x - speed, y - speed))
	{
		x -= speed;
		y -= speed;
	}
	else if (dir == 1 && !collision(visibleMatrix, blocks, decreLife, lifes, score, x + speed, y - speed))
	{
		x += speed;
		y -= speed;
	}
	else if (dir == 2 && !collision(visibleMatrix, blocks, decreLife, lifes, score, x - speed, y + speed))
	{
		x -= speed;
		y += speed;
	}
	else if (dir == 3 && !collision(visibleMatrix, blocks, decreLife, lifes, score, x + speed, y + speed))
	{
		x += speed;
		y += speed;
	}
}

void Ball::collisionReact(std::array<std::array<int, breakoutConstants::screenWidth>, breakoutConstants::screenHeight>& visibleMatrix,
	std::array<std::array<int, breakoutConstants::blocksWidth>, breakoutConstants::blocksHeight>& blocks,
	size_t& score, int fx, int fy, int x, int y, int collised, int collisedProd)
{
	if (visibleMatrix[fy][fx] == collised)
	{
		blocks[fy - 2][fx - 6] = collisedProd;
		score += 10;
	}
	if (visibleMatrix[y][fx] == collised)
	{
		blocks[y - 2][fx - 6] = collisedProd;
		score += 10;
	}
	if (visibleMatrix[fy][x] == collised)
	{
		blocks[fy - 2][x - 6] = collisedProd;
		score += 10;
	}
	return;
}

bool Ball::collision(std::array<std::array<int, breakoutConstants::screenWidth>, breakoutConstants::screenHeight>& visibleMatrix,
	std::array<std::array<int, breakoutConstants::blocksWidth>, breakoutConstants::blocksHeight>& blocks,
	bool& decreLife, int& lifes, size_t& score, int fx, int fy)
{
	if (visibleMatrix[fy][x] == 8)
	{
		decreLife = true;
		x = breakoutConstants::screenWidth / 2;
		y = breakoutConstants::screenHeight - breakoutConstants::screenHeight / 4 - 3;
		dir = 4;
		lifes--;
	}
	else if (visibleMatrix[fy][fx] != 0 || visibleMatrix[y][fx] != 0 || visibleMatrix[fy][x] != 0 ||
		visibleMatrix[fy][fx] == 10 || visibleMatrix[y][fx] == 10 || visibleMatrix[fy][x] == 10 ||
		visibleMatrix[fy][fx] == 11 || visibleMatrix[y][fx] == 11 || visibleMatrix[fy][x] == 11 ||
		visibleMatrix[fy][fx] == 12 || visibleMatrix[y][fx] == 12 || visibleMatrix[fy][x] == 12)
	{
		collisionReact(visibleMatrix, blocks, score, fx, fy, x, y, 10, 0);
		collisionReact(visibleMatrix, blocks, score, fx, fy, x, y, 11, 10);
		collisionReact(visibleMatrix, blocks, score, fx, fy, x, y, 12, 11);

		if (visibleMatrix[y][fx] != 0) bounce(fx, y);
		else if (visibleMatrix[fy][x] != 0) bounce(x, fy);
		else if (visibleMatrix[fy][fx] != 0) bounce(fx, fy);

		return true;
	}
	return false;
}

void Ball::setDirection(int direct)
{
	this->dir = direct;
}

int Ball::getDirection()
{
	return this->dir;
}

void Ball::bounce(int fx, int fy)
{
	if (dir == 0)
	{
		if (fx < x)
			dir = 1;
		else if (fy < y)
			dir = 2;
	}
	else if (dir == 1)
	{
		if (fx > x) 
			dir = 0;
		else if (fy < y) 
			dir = 3;
	}
	else if (dir == 2)
	{
		if (fx < x) 
			dir = 3;
		else if (fy > y) 
			dir = 0;
	}
	else if (dir == 3) 
	{
		if (fx > x) 
			dir = 2;
		else if (fy > y) 
			dir = 1;
	}
}