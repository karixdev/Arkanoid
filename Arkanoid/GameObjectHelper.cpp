#include "GameObjectHelper.h"
#include "WindowConfig.h"

bool GameObjectHelper::canMoveLeft(sf::Vector2f position, float offset)
{
	return position.x > offset;
}

bool GameObjectHelper::canMoveRight(sf::Vector2f position, float offset)
{
	return position.x < WindowConfig::WINDOW_WIDTH - offset;
}
