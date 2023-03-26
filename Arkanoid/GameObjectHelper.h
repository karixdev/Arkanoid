#pragma once
#include <SFML/Graphics.hpp>

class GameObjectHelper
{
public:
	bool canMoveLeft(sf::Vector2f position, float offset);
	bool canMoveRight(sf::Vector2f position, float offset);
};

