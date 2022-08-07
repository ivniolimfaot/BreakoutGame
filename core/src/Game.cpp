#include "Game.h"

#include <random>
#include <conio.h>

void Game::generateBlocks()
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist3(1, 3);


	for (int i = 0; i < breakoutConstants::blocksHeight; i++)
	{
		for (int y = 0; y < breakoutConstants::blocksWidth; y++)
		{
			int randomNum = dist3(rng);
			if (randomNum == 1)
			{
				blocks[i][y] = 10;
			}
			else if (randomNum == 2)
			{
				blocks[i][y] = 11;
			}
			else if (randomNum == 3)
			{
				blocks[i][y] = 12;
			}
		}
	}
}

void Game::Init()
{
	srand(time(NULL));
	decreLife = false;
	life = 3;
	paddle.x = breakoutConstants::screenWidth / 2 - 5;
	paddle.y = breakoutConstants::screenHeight - breakoutConstants::screenHeight / 7 - 1;
	paddle.setSpeed(1);
	paddle.setDelay(1);
	ball.x = breakoutConstants::screenWidth / 2;
	ball.y = breakoutConstants::screenHeight - breakoutConstants::screenHeight / 4 - 3;
	ball.speed = 1;
	ball.setDirection(rand() % 4);
	ballDelay = breakoutConstants::standardBallDelay;
	this->generateBlocks();
}

void Game::reduceTimer() { this->timer -= 0.02; }
int& Game::lifesCount() { return life; }
size_t& Game::getScore() { return score; }
double& Game::getTimerValue() { return timer; }
Paddle& Game::getGamePaddle() { return this->paddle; }
Ball& Game::getGameBall() { return this->ball; }
bool& Game::getDecreLife() { return this->decreLife; }

void Game::getUserInput()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'A':
		case 'a':
		case 75:
			paddle.setDirection('L');
			break;
		case 'd':
		case 'D':
		case 77:
			paddle.setDirection('R');
			break;
		}
		if (ball.getDirection() == 4) ball.setDirection(rand() % 2);
	}
}

std::array<std::array<int, breakoutConstants::blocksWidth>, breakoutConstants::blocksHeight>& Game::getBlocksMatrix() { return this->blocks; };


int& Game::getBallDelay() { return this->ballDelay; };

bool Game::isGameWin()
{
	for(int i = 0; i < this->blocks.size(); i++)
	{
		for(int j = 0; j < this->blocks[i].size(); j++)
		{
			if (blocks[i][j] != 0)
				return false;
		}
	}
	return true;
}

time_t& Game::getTimeStart()
{
	return this->start;
}

void Game::refreshCurentGameTime() 
{
	time_t currentTime;
	time(&currentTime);
	this->currentGameTime= difftime(currentTime, this->start);
}

double& Game::getCurrentGameTime()
{
	return this->currentGameTime;
}