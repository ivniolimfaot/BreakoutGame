#include "GraphicEngine.h"
#include "BreakoutConstants.h"
#include <iostream>
#include <iomanip>

void GraphicEngine::moveCursorTo(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void GraphicEngine::drawWall()
{
	for (int i = 0; i < breakoutConstants::screenHeight; i++)
	{
		for (int j = 0; j < breakoutConstants::screenWidth; j++)
		{
			if (j == 0 || j == breakoutConstants::screenWidth - 1)
				visibleMatrix[i][j] = 9;
			else if (i == 0)
				visibleMatrix[i][j] = 7;
			else if (i == breakoutConstants::screenHeight - 1)
				visibleMatrix[i][j] = 8;
			else
				visibleMatrix[i][j] = 0;
		}
	}
}

void GraphicEngine::drawMatrix(double timerValue)
{
	if (timerValue > 0)
	{
		moveCursorTo(15, 15); std::cout << std::setprecision(3) << timerValue;
	}

	for (int i = 0; i < breakoutConstants::screenHeight; i++)
	{
		for (int j = 0; j < breakoutConstants::screenWidth; j++)
		{
			moveCursorTo(j + 2, i + 3);
			if (visibleMatrix[i][j] == 9) std::cout << char(219);
			if (visibleMatrix[i][j] == 1) std::cout << char(219);
			if (visibleMatrix[i][j] == 2) std::cout << char(233);
			if (visibleMatrix[i][j] == 7) std::cout << char(219);
			if (visibleMatrix[i][j] == 8) std::cout << char(219);
			if (visibleMatrix[i][j] == 5) std::cout << char(254);
			if (visibleMatrix[i][j] == 0) std::cout << char(32);
			if (visibleMatrix[i][j] == 3)  continue;
			if (visibleMatrix[i][j] == 10) std::cout << '#';
			if (visibleMatrix[i][j] == 11) std::cout << '*';
			if (visibleMatrix[i][j] == 12) std::cout << '@';
		}
	}
}

void GraphicEngine::brick()
{
	for (int i = 0; i < breakoutConstants::blocksHeight-1; i++) 
	{
		for (int j = 0; j < breakoutConstants::blocksWidth - 1; j++) 
		{
			if (blocks[i][j] == 10) visibleMatrix[i + 2][j + 6] = 10;
			if (blocks[i][j] == 11) visibleMatrix[i + 2][j + 6] = 11;
			if (blocks[i][j] == 12) visibleMatrix[i + 2][j + 6] = 12;
		}
	}
	if (this->game.getTimerValue() > 0)
	{
		for (int i = breakoutConstants::timerPos.Y; i < breakoutConstants::timerPos.Y + breakoutConstants::timerWidth; i++)
		{
			visibleMatrix[breakoutConstants::timerPos.X - 3][i - 2] = 3;
		}
	}

}

void GraphicEngine::layout()
{
	drawWall();
	this->game.getGamePaddle().draw(this->visibleMatrix);
	this->game.getGameBall().draw(this->visibleMatrix);
	brick();
}

void GraphicEngine::refreshMatrix()
{
	this->game.getGamePaddle().move(this->game.getDecreLife());
	if (this->game.getTimerValue() < 0)
	{
		if (this->game.getBallDelay() == 0)
		{
			this->game.getGameBall().move(this->visibleMatrix, this->game.getBlocksMatrix(), this->game.getDecreLife(), this->game.lifesCount(),
				this->game.getScore());
			this->game.getBallDelay() = breakoutConstants::standardBallDelay;
		}
		else
			this->game.getBallDelay()-=1;
	}
		
}

void GraphicEngine::mainMenu()
{
	drawWall();
	drawMatrix(false);
	moveCursorTo(11, 10); std::cout << "1. NEW GAME ";
	moveCursorTo(11, 12); std::cout << "2. EXIT ";
}

void GraphicEngine::gameFiled()
{
	moveCursorTo(2, 1);  std::cout << "LIFE: " << this->game.lifesCount();
	if (this->game.isTimeInit)
		this->game.refreshCurentGameTime();
	moveCursorTo(2, 2);  std::cout << "TIME: " << std::setprecision(3) << this->game.getCurrentGameTime() << " seconds";
	moveCursorTo(20, 1); std::cout << "SCORE: " << this->game.getScore();
	drawMatrix(this->game.getTimerValue());
	layout();

	if (this->game.getTimerValue() > 0)
		this->game.reduceTimer();
	if(this->game.getTimerValue() <=0 && this->game.isTimeInit == false)
	{
		time(&this->game.getTimeStart());
		this->game.isTimeInit = true;
	}
	this->game.getUserInput();
	refreshMatrix();

}

void GraphicEngine::endgameMenu()
{
	drawWall();
	drawMatrix(false);
	moveCursorTo(11, 10); std::cout << "GAME OVER";
	moveCursorTo(11, 12); std::cout << "TOTAL SCORE: " << this->game.getScore();
	moveCursorTo(11, 14); std::cout << "1. NEW GAME ";
	moveCursorTo(11, 16); std::cout << "2. EXIT ";
}
void GraphicEngine::gameWinMenu()
{
	drawWall();
	drawMatrix(false);
	moveCursorTo(11, 10); std::cout << "YOU WIN!";
	moveCursorTo(11, 12); std::cout << "TOTAL SCORE: " << this->game.getScore();
	moveCursorTo(11, 14); std::cout << "1. NEW GAME ";
	moveCursorTo(11, 16); std::cout << "2. EXIT ";
}


void GraphicEngine::hideCursor()
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.dwSize = 100;
	cursor.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

GraphicEngine::GraphicEngine(std::array<std::array<int, breakoutConstants::screenWidth>, breakoutConstants::screenHeight>& visibleMatrixRef,
	std::array<std::array<int, breakoutConstants::blocksWidth>, breakoutConstants::blocksHeight>& blocksRef,
	Game& gamePtr) :
	visibleMatrix(visibleMatrixRef), blocks(blocksRef), game(gamePtr)
{
};
