#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"

class Ball
{
public:
	Ball();

	void draw(sf::RenderWindow& window);
	void update(float dt, const Paddle& paddle);

private:
	sf::CircleShape shape;

	sf::Vector2f velocity = { .35f, -.35f };

	void horizontalWallCollision();
	void verticalWallCollision();

	void paddleCollision(const Paddle& paddle);

	const float RADIUS = 10.f;
	const sf::Color COLOR = sf::Color::Red;
};

