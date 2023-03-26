#include "GameManager.h"

GameManager::GameManager()
{
}

void GameManager::draw(sf::RenderWindow& window)
{
	panel.draw(window);
}

void GameManager::update(float dt)
{
}

void GameManager::updatePoints(int lives)
{
	points += lives * 10;
	panel.setPoints(points);
}

void GameManager::setActiveLevel(std::string levelName)
{
	activeLevelName = levelName;
}

std::string GameManager::getActiveLevel() const
{
	return activeLevelName;
}

void GameManager::reset()
{
	points = 0;
	panel.setPoints(0);
	//activeLevelName = "";
}
