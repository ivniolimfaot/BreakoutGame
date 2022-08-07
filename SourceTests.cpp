#include <gtest/gtest.h>
#include "Ball.h"
#include "Game.h"
#include "Engine.h"


//Ball logic testing

TEST(BallTest, BounceLogic) 
{
	Ball ball;
	ball.x = 0;
	ball.y = 0;
	ball.setDirection(0); 
	ball.bounce(1, 1);

	EXPECT_EQ(ball.getDirection(), 0);
	
	ball.x = 2;
	ball.bounce(1, 1);

	EXPECT_EQ(ball.getDirection(), 1);

	ball.x = 0;
	ball.y = 2;
	ball.setDirection(0);
	ball.bounce(1, 1);

	EXPECT_EQ(ball.getDirection(), 2);

	ball.x = 2;
	ball.y = 2;
	ball.setDirection(1);
	ball.bounce(1, 3);

	EXPECT_EQ(ball.getDirection(), 1);

	ball.x = 2;
	ball.y = 2;
	ball.setDirection(1);
	ball.bounce(3, 3);

	EXPECT_EQ(ball.getDirection(), 0);

	ball.x = 2;
	ball.y = 2;
	ball.setDirection(2);
	ball.bounce(3, 1);

	EXPECT_EQ(ball.getDirection(), 2);

	ball.x = 2;
	ball.y = 2;
	ball.setDirection(2);
	ball.bounce(1, 1);

	EXPECT_EQ(ball.getDirection(), 3);

	ball.x = 2;
	ball.y = 2;
	ball.setDirection(2);
	ball.bounce(3, 3);

	EXPECT_EQ(ball.getDirection(), 0);

	ball.x = 2;
	ball.y = 2;
	ball.setDirection(3);
	ball.bounce(1, 1);

	EXPECT_EQ(ball.getDirection(), 3);

	ball.x = 2;
	ball.y = 2;
	ball.setDirection(3);
	ball.bounce(3, 1);

	EXPECT_EQ(ball.getDirection(), 2);

	ball.x = 2;
	ball.y = 2;
	ball.setDirection(3);
	ball.bounce(1, 3);

	EXPECT_EQ(ball.getDirection(), 1);

}

template<typename T>
void printArr(T& arr)
{
	for(int i =0; i < arr.size(); i++)
	{
		for(int j= 0; j < arr[i].size(); j++)
		{
			std::cout << arr[i][j] << ", ";
		}
		std::cout << "\n";
	}
}

TEST(BallTest, CollisionLogic)
{
	Engine eng;
	eng.initGame();
	
	eng.game.getBlocksMatrix() = { { {10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12}} };
	eng.graphicEngine()->layout();

	eng.game.getGameBall().collision(eng.visibleMatrix, eng.game.getBlocksMatrix(), eng.game.getDecreLife(), eng.game.lifesCount(), 
		eng.game.getScore(), 6, 2) ;
	eng.graphicEngine()->layout();
	EXPECT_EQ(eng.visibleMatrix[2][6], 0);

	eng.game.getGameBall().y = 2;
	eng.game.getGameBall().collision(eng.visibleMatrix, eng.game.getBlocksMatrix(), eng.game.getDecreLife(), eng.game.lifesCount(),
		eng.game.getScore(), 7, 1);
	eng.graphicEngine()->layout();
	EXPECT_EQ(eng.visibleMatrix[2][7], 0);

	eng.game.getGameBall().y = 1;
	eng.game.getGameBall().x = 8;
	eng.game.getGameBall().collision(eng.visibleMatrix, eng.game.getBlocksMatrix(), eng.game.getDecreLife(), eng.game.lifesCount(),
		eng.game.getScore(), 6, 2);
	eng.graphicEngine()->layout();
	EXPECT_EQ(eng.visibleMatrix[2][8], 0);

	eng.game.getGameBall().x = breakoutConstants::screenWidth / 2;
	eng.game.getGameBall().y = breakoutConstants::screenHeight - breakoutConstants::screenHeight / 4 - 3;
	eng.game.getGameBall().collision(eng.visibleMatrix, eng.game.getBlocksMatrix(), eng.game.getDecreLife(), eng.game.lifesCount(),
		eng.game.getScore(), 12, 2);
	eng.graphicEngine()->layout();
	EXPECT_EQ(eng.visibleMatrix[2][12], 10);

	eng.game.getGameBall().y = 2;
	eng.game.getGameBall().collision(eng.visibleMatrix, eng.game.getBlocksMatrix(), eng.game.getDecreLife(), eng.game.lifesCount(),
		eng.game.getScore(), 13, 1);
	eng.graphicEngine()->layout();
	EXPECT_EQ(eng.visibleMatrix[2][13], 10);

	eng.game.getGameBall().y = 1;
	eng.game.getGameBall().x = 14;
	eng.game.getGameBall().collision(eng.visibleMatrix, eng.game.getBlocksMatrix(), eng.game.getDecreLife(), eng.game.lifesCount(),
		eng.game.getScore(), 13, 2);
	eng.graphicEngine()->layout();
	EXPECT_EQ(eng.visibleMatrix[2][14], 10);

	eng.game.getGameBall().x = breakoutConstants::screenWidth / 2;
	eng.game.getGameBall().y = breakoutConstants::screenHeight - breakoutConstants::screenHeight / 4 - 3;
	eng.game.getGameBall().collision(eng.visibleMatrix, eng.game.getBlocksMatrix(), eng.game.getDecreLife(), eng.game.lifesCount(),
		eng.game.getScore(), 18, 2);
	eng.graphicEngine()->layout();
	EXPECT_EQ(eng.visibleMatrix[2][18], 11);

	eng.game.getGameBall().y = 2;
	eng.game.getGameBall().collision(eng.visibleMatrix, eng.game.getBlocksMatrix(), eng.game.getDecreLife(), eng.game.lifesCount(),
		eng.game.getScore(), 19, 1);
	eng.graphicEngine()->layout();
	EXPECT_EQ(eng.visibleMatrix[2][19], 11);

	eng.game.getGameBall().y = 1;
	eng.game.getGameBall().x = 20;
	eng.game.getGameBall().collision(eng.visibleMatrix, eng.game.getBlocksMatrix(), eng.game.getDecreLife(), eng.game.lifesCount(),
		eng.game.getScore(), 19, 2);
	eng.graphicEngine()->layout();
	EXPECT_EQ(eng.visibleMatrix[2][20], 11);
	
}

TEST(BallTest, MoveLogic)
{
	Engine eng;
	eng.initGame();

	eng.game.getBlocksMatrix() = { { {10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12}} };
	eng.graphicEngine()->layout();

	eng.game.getGameBall().setDirection(0);
	eng.game.getGameBall().move(eng.visibleMatrix, eng.game.getBlocksMatrix(), eng.game.getDecreLife(),
		eng.game.lifesCount(), eng.game.getScore());
	
	EXPECT_EQ(eng.game.getGameBall().x, 14);
	EXPECT_EQ(eng.game.getGameBall().y, 11);

	eng.game.getGameBall().setDirection(1);
	eng.game.getGameBall().move(eng.visibleMatrix, eng.game.getBlocksMatrix(), eng.game.getDecreLife(),
		eng.game.lifesCount(), eng.game.getScore());

	EXPECT_EQ(eng.game.getGameBall().x, 15);
	EXPECT_EQ(eng.game.getGameBall().y, 10);

	eng.game.getGameBall().setDirection(2);
	eng.game.getGameBall().move(eng.visibleMatrix, eng.game.getBlocksMatrix(), eng.game.getDecreLife(),
		eng.game.lifesCount(), eng.game.getScore());

	EXPECT_EQ(eng.game.getGameBall().x, 14);
	EXPECT_EQ(eng.game.getGameBall().y, 11);


	eng.game.getGameBall().x = 15;
	eng.game.getGameBall().y = 10;
	eng.game.getGameBall().setDirection(3);
	eng.game.getGameBall().move(eng.visibleMatrix, eng.game.getBlocksMatrix(), eng.game.getDecreLife(),
		eng.game.lifesCount(), eng.game.getScore());

	EXPECT_EQ(eng.game.getGameBall().x, 16);
	EXPECT_EQ(eng.game.getGameBall().y, 11);
}

TEST(PaddleTest, MoveLogic)
{
	Engine eng;
	eng.initGame();

	eng.game.getBlocksMatrix() = { { {10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12}} };
	eng.graphicEngine()->layout();

	eng.game.getGamePaddle().setDirection('L');
	eng.game.getGamePaddle().move(eng.game.getDecreLife());

	EXPECT_EQ(eng.game.getGamePaddle().x, 9);

	eng.game.getGamePaddle().setDirection('R');
	eng.game.getGamePaddle().move(eng.game.getDecreLife());

	EXPECT_EQ(eng.game.getGamePaddle().x, 10);
}

TEST(GraphicEngineTest, BrickLogic)
{
	Engine eng;
	eng.initGame();

	eng.game.getBlocksMatrix() = { { {10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12}} };
	eng.graphicEngine()->layout();

	for(int i = 6; i < eng.game.getBlocksMatrix()[0].size() + 6 -1; i++)
	{
		EXPECT_EQ(eng.visibleMatrix[2][i], eng.game.getBlocksMatrix()[0][i-6]);
	}
}