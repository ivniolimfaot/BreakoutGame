#include "Engine.h"

void Engine::initGame()
{
	this->game.Init();
}

bool Engine::isGameStarted() const { return gameStared; };

bool Engine::isGameExit()    const { return gameEnded; };

void Engine::endGame() { this->gameStared = false; };

Engine::Engine() : gameEnded(false), gameStared(false), visibleMatrix({ 0 })
{
	this->m_graphicEngine = std::make_shared<GraphicEngine>(visibleMatrix, game.getBlocksMatrix(), game);
};

std::shared_ptr<GraphicEngine>& Engine::graphicEngine() { return this->m_graphicEngine; };

void Engine::getUserMenuInput()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case '1':
			gameStared = true;
			this->game.lifesCount() = 3;
			this->game.getTimerValue() = 3;
			this->game.getScore() = 0;
			this->game.getDecreLife() = false;
			this->game.getGamePaddle().setDirection('S');
			this->game.isTimeInit = false;
			this->game.getCurrentGameTime() = 0;
			break;
		case '2':
			gameEnded = true;
			break;
		}
	}
}