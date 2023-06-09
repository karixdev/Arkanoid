#include "Brick.h"

Brick::Brick(sf::Vector2f position, sf::Vector2f size, int lives) :
	label(Label(20.f, std::to_string(lives))), lives(lives), initLives(lives)
{
	shape.setPosition(position);
	shape.setSize(size);
	shape.setFillColor(sf::Color::Yellow);

	shape.setOutlineThickness(OUTLINE_THICKNESS);
	shape.setOutlineColor(OUTLINE_COLOR);

	label.centerRelativily(shape);
}

void Brick::draw(sf::RenderWindow& window)
{
	if (isDestroyed) return;

	window.draw(shape);
	label.draw(window);
}

sf::FloatRect Brick::getGlobalBounds() const
{
	return shape.getGlobalBounds();
}

sf::Vector2f Brick::getPosition() const
{
	return shape.getPosition();
}

sf::Vector2f Brick::getSize() const
{
	return sf::Vector2f(getGlobalBounds().width, getGlobalBounds().height);
}

bool Brick::getIsDestroyed() const
{
	return isDestroyed;
}

void Brick::descreaseLives()
{
	if (--lives == 0)
	{
		isDestroyed = true;
	}

	label.setText(std::to_string(lives));
}

int Brick::getLives() const
{
	return lives;
}

void Brick::reset()
{
	lives = initLives;
	label.setText(std::to_string(initLives));
	isDestroyed = false;
}

void Brick::setLives(int lives)
{
	this->lives = lives;
	label.setText(std::to_string(lives));
}
