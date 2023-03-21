#pragma once
#include <SFML/Graphics.hpp>

class Paddle
{
public:
	Paddle(float x, float y);

	void update(float deltaTime, const sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape shape;

	bool canMoveLeft();
	bool canMoveRight(const sf::RenderWindow& window);

	const float SPEED = .5f;

	const float WIDTH = 75.f;
	const float HEIGHT = 15.f;

	const sf::Color COLOR = sf::Color::Green;

	const float OUTLINE_THICKNESS = 2.f;
	const sf::Color OUTLINE_COLOR = sf::Color::Black;

	const float WINDOW_BOUNDARY_MARGIN = 10.f;
};

