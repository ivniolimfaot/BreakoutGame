#pragma once
#include <windows.h>


namespace breakoutConstants
{
	constexpr int screenHeight{ 20 };
	constexpr int screenWidth{ 30 };
	constexpr int blocksHeight{ 8 };
	constexpr int blocksWidth{ 18 };
	constexpr double timerStart{ 3 };
	constexpr COORD timerPos{ 15, 15 };
	constexpr int timerWidth{ 4 };
	constexpr int standardBallDelay{ 3};
};