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
