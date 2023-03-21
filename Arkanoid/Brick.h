#pragma once
#include <SFML/Graphics.hpp>

enum BrickType
{
	ONE_HIT,
	TWO_HIT,
	THREE_HIT
};

class Brick
{
public:
	Brick(sf::Vector2f position, int numberOfLives);

	void draw(sf::RenderWindow window);
	void hit();
private:
	sf::RectangleShape shape;

	int numberOfLives;

	const float WIDTH = 100.f;
	const float HEIGHT = 100.f;
};

