#include "Paddle.h"

Paddle::Paddle()
{
	shape.setPosition(WindowConfig::WINDOW_WIDTH / 2.f - WIDTH / 2.f, Y_POISITION - HEIGHT / 2.f);
	shape.setSize({ WIDTH, HEIGHT });
	shape.setFillColor(COLOR);

	shape.setOutlineThickness(OUTLINE_THICKNESS);
	shape.setOutlineColor(OUTLINE_COLOR);
}

void Paddle::update(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && canMoveLeft()) 
	{
		shape.move(-SPEED * deltaTime, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && canMoveRight()) 
	{
		shape.move(SPEED * deltaTime, 0);
	}
}

void Paddle::draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

sf::RectangleShape Paddle::getShape() const
{
	return shape;
}

sf::Vector2f Paddle::getPosition() const
{
	return shape.getPosition();
}

sf::FloatRect Paddle::getGlobalBounds() const
{
	return shape.getGlobalBounds();
}

sf::Vector2f Paddle::getSize() const
{
	return sf::Vector2f(getGlobalBounds().width, getGlobalBounds().height);
}

void Paddle::reset()
{
	shape.setPosition(INIT_POSITION);
}

bool Paddle::canMoveLeft()
{
	return shape.getPosition().x > WINDOW_BOUNDARY_MARGIN;
}

bool Paddle::canMoveRight()
{
	return shape.getPosition().x + shape.getSize().x < WindowConfig::WINDOW_WIDTH - WINDOW_BOUNDARY_MARGIN;
}
