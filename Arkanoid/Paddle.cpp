#include "Paddle.h"

Paddle::Paddle(float x, float y)
{
	shape.setPosition(x - WIDTH / 2, y - HEIGHT / 2);
	shape.setSize({ WIDTH, HEIGHT });
	shape.setFillColor(COLOR);

	shape.setOutlineThickness(OUTLINE_THICKNESS);
	shape.setOutlineColor(OUTLINE_COLOR);
}

void Paddle::update(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && canMoveLeft()) {
		shape.move(-SPEED * deltaTime, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && canMoveRight()) {
		shape.move(SPEED * deltaTime, 0);
	}
}

void Paddle::draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

bool Paddle::canMoveLeft()
{
	return shape.getPosition().x > WINDOW_BOUNDARY_MARGIN;
}

bool Paddle::canMoveRight()
{
	// left edge position + paddle width < window width
	return shape.getPosition().x + shape.getSize().x < 600 - WINDOW_BOUNDARY_MARGIN;
}
