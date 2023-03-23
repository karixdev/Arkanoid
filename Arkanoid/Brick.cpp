#include "Brick.h"

Brick::Brick(sf::Vector2f position, sf::Vector2f size, int lives) :
	label(Label(30, std::to_string(lives)))
{
	shape.setPosition(position);
	shape.setSize(size);
	shape.setFillColor(sf::Color::Yellow);

	shape.setOutlineThickness(2);
	shape.setOutlineColor(sf::Color::Black);

	label.centerRelativily(shape);
}

void Brick::draw(sf::RenderWindow& window)
{
	window.draw(shape);
	label.draw(window);
}
