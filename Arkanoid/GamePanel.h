#pragma once
#include <SFML/Graphics.hpp>
#include "Label.h"

class GamePanel
{
public:
	GamePanel();

	void draw(sf::RenderWindow& window);

	void setPoints(int points);

private:
	Label pointsLabel;
	sf::RectangleShape stripe;
};

