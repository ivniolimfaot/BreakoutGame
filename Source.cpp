#include <iostream>
#include <windows.h>
#include <array>
#include <iomanip>
#include <conio.h>
#include <time.h>
#include "Engine.h"


int main(){
	Engine engine;
	engine.graphicEngine()->hideCursor();
	engine.graphicEngine()->mainMenu();
	while (true)
	{
		while (true)
		{
			engine.getUserMenuInput();
			if (engine.isGameStarted())
			{
				engine.initGame();
				while (engine.game.lifesCount() > 0 && engine.game.isGameWin() == false) 
				{
					engine.graphicEngine()->gameFiled();
				}
				engine.endGame();
				break;
			}
			else if (engine.isGameExit())
				return 0;

		}
		system("cls");
		if (engine.game.isGameWin())
			engine.graphicEngine()->gameWinMenu();
		else
			engine.graphicEngine()->endgameMenu();
	}

}