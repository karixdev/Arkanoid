#include "GameManager.h"

GameManager::GameManager() :
	ball(Ball()),
	paddle(Paddle())
{
}

void GameManager::draw(sf::RenderWindow& window)
{
	panel.draw(window);

	ball.draw(window);
	paddle.draw(window);
}

void GameManager::update(float dt)
{
	ball.update(dt);
	paddle.update(dt);
}

void GameManager::updatePoints(int lives)
{
	points += lives * 10;
	panel.setPoints(points);
}

int GameManager::getPoints() const
{
	return points;
}

void GameManager::setActiveLevel(std::string levelName)
{
	activeLevelName = levelName;
}

std::string GameManager::getActiveLevel() const
{
	return activeLevelName;
}

void GameManager::reset(bool resetLvlName)
{
	points = 0;
	panel.setPoints(0);

	ball.reset();
	paddle.reset();

	if (resetLvlName)
	{
		activeLevelName = "";
	}
}

Ball& GameManager::getBall()
{
	return ball;
}

Paddle& GameManager::getPaddle()
{
	return paddle;
}
