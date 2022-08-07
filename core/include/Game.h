#pragma once
#include "Paddle.h"
#include "Ball.h"

class Game
{
	size_t score;
	Paddle paddle;
	Ball ball;
	double timer;
	int life;
	bool decreLife;
	int ballDelay;
	std::array<std::array<int, breakoutConstants::blocksWidth>, breakoutConstants::blocksHeight> blocks;
	double currentGameTime{0};
	time_t start;
	void generateBlocks();
	

public:
	bool isTimeInit{ false };

	void Init();
	void reduceTimer();
	int& lifesCount();
	size_t& getScore();
	double& getTimerValue();
	Paddle& getGamePaddle();
	Ball& getGameBall();

	bool& getDecreLife();
	void getUserInput();

	int& getBallDelay();
	bool isGameWin();
	std::array<std::array<int, breakoutConstants::blocksWidth>, breakoutConstants::blocksHeight>& getBlocksMatrix();

	time_t& getTimeStart();

	void refreshCurentGameTime();
	double& getCurrentGameTime();

};