#include "Brick.h"

Brick::Brick(sf::Vector2f position, int numberOfLives)
{
	shape.setPosition(position.x - WIDTH / 2, position.y - HEIGHT / 2);
	shape.setSize({ WIDTH, HEIGHT });
	shape.setFillColor(sf::Color::Blue);

	shape.setOutlineThickness(2);
	shape.setOutlineColor(sf::Color::Black);

	this->numberOfLives = numberOfLives;
}

void Brick::draw(sf::RenderWindow window)
{
	window.draw(shape);
}

void Brick::hit()
{
}
