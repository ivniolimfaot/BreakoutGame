#pragma once
#include <windows.h>
#include "Game.h"

class GraphicEngine
{
	std::array<std::array<int, breakoutConstants::screenWidth>, breakoutConstants::screenHeight>& visibleMatrix;
	std::array<std::array<int, breakoutConstants::blocksWidth>, breakoutConstants::blocksHeight>& blocks;
	Game& game;
	void moveCursorTo(int x, int y);

	void drawWall();
	void drawMatrix(double timerValue);
	void refreshMatrix();
	void brick();
public:

	void layout();
	void mainMenu();
	void gameFiled();
	void endgameMenu();
	void hideCursor();
	void gameWinMenu();

	GraphicEngine(std::array<std::array<int, breakoutConstants::screenWidth>, breakoutConstants::screenHeight>& visibleMatrixRef,
		std::array<std::array<int, breakoutConstants::blocksWidth>, breakoutConstants::blocksHeight>& blocksRef,
		Game& gamePtr);


};