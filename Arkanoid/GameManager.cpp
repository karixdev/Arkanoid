#include "GameManager.h"

GameManager::GameManager(std::vector<Brick>& bricks, Ball& ball, Paddle& paddle) :
	bricks(bricks), paddle(paddle), ball(ball)
{
}

void GameManager::draw(sf::RenderWindow& window)
{
	panel.draw(window);
}

void GameManager::update(float dt)
{
	// check for ball - brick collision and then update points
	for (Brick& brick : bricks)
	{
		if (!ball.handleCollision(brick)) continue;

		points += brick.getLives() * 10;
		panel.setPoints(points);

		brick.descreaseLives();
	}

	// check for paddle ball collisions
	ball.handleCollision(paddle);
}
