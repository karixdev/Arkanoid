#include "BrickPlaceholder.h"

BrickPlaceholder::BrickPlaceholder(
	const sf::Vector2f& position, 
	const sf::Vector2f& size
) : Brick(position, size, 0)
{
	shape.setFillColor(sf::Color::Transparent);
	label.setText("");
}

void BrickPlaceholder::handleEvent(sf::Event& event)
{
	if (isButtonPressed(event, sf::Mouse::Button::Left))
	{
		int lives = getLives();
		if (lives <= 1)
		{
			setLives(lives + 1);
		}
		else
		{
			setLives(1);
		}

		shape.setFillColor(sf::Color::Yellow);
	}

	if (isButtonPressed(event, sf::Mouse::Button::Right))
	{
		setLives(0);
		label.setText("");
		shape.setFillColor(sf::Color::Transparent);
	}
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
