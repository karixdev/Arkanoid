#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Brick.h"

class Ball
{
public:
	Ball();

	void draw(sf::RenderWindow& window);
	void update(float dt);

	void handleCollision(const Paddle& paddle);
	void handleCollision(Brick& brick);

	sf::FloatRect getGlobalBounds() const;

private:
	sf::CircleShape shape;

	sf::Vector2f velocity = { .4f, -.4f };

	void horizontalWallCollision();
	void verticalWallCollision();

	const float RADIUS = 10.f;
	const sf::Color COLOR = sf::Color::Red;
};

