#pragma once
#include <SFML/Graphics.hpp>
#include "Label.h"

class Brick
{
public:
	Brick(sf::Vector2f position, sf::Vector2f size, int lives);

	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape shape;

	const float OUTLINE_THICKNESS = 2.f;

	Label label;
};

