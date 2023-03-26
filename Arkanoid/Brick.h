#pragma once
#include <SFML/Graphics.hpp>
#include "Label.h"

class Brick
{
public:
	Brick(sf::Vector2f position, sf::Vector2f size, int lives);

	void draw(sf::RenderWindow& window);

	sf::FloatRect getGlobalBounds() const;
	sf::Vector2f getPosition() const;
	sf::Vector2f getSize() const;

	bool getIsDestroyed() const;

	void descreaseLives();

private:
	sf::RectangleShape shape;

	const float OUTLINE_THICKNESS = 2.f;

	bool isDestroyed = false;

	int lives;

	Label label;

	const sf::Color OUTLINE_COLOR = sf::Color::Black;
	const int OUTLINE_THICKNESS = -1.f;
};

