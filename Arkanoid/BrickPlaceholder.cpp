#include "BrickPlaceholder.h"

BrickPlaceholder::BrickPlaceholder(
	const sf::Vector2f& position, 
	const sf::Vector2f& size
)
{
	shape.setPosition(position);
	shape.setSize(size);

	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineThickness(OUTLINE_THICKNESS);
	shape.setOutlineColor(OUTLINE_COLOR);
}

void BrickPlaceholder::handleEvent(sf::Event& event)
{
	if (isButtonPressed(event, sf::Mouse::Button::Left))
	{
		shape.setFillColor(sf::Color::Yellow);
	}

	if (isButtonPressed(event, sf::Mouse::Button::Right))
	{
		shape.setFillColor(sf::Color::Transparent);
	}
}

void BrickPlaceholder::draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

bool BrickPlaceholder::isButtonPressed(sf::Event& event, sf::Mouse::Button button)
{
	if (event.type != sf::Event::MouseButtonReleased) return false;
	if (event.mouseButton.button != button) return false;

	sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

	return shape.getGlobalBounds().contains(mousePos);
}

bool BrickPlaceholder::isFilled()
{
	return shape.getFillColor() == sf::Color::Yellow;
}
