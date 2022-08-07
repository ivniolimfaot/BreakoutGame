#pragma once
#include <array>
#include <memory>
#include <conio.h>
#include "GraphicEngine.h"

class Engine
{
	
	bool gameEnded;
	bool gameStared;
	std::shared_ptr<GraphicEngine> m_graphicEngine;

public:
	std::array<std::array<int, breakoutConstants::screenWidth>, breakoutConstants::screenHeight> visibleMatrix;
	Game game;
	void initGame();
	bool isGameStarted() const;
	bool isGameExit()    const;
	void endGame();
	Engine();
	std::shared_ptr<GraphicEngine>& graphicEngine();

	void getUserMenuInput();
};