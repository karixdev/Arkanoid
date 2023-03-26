#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Brick.h"
#include "WindowConfig.h"

class Ball
{
public:
	Ball();

	void draw(sf::RenderWindow& window);
	void update(float dt);

	void handleCollision(const Paddle& paddle);
	bool handleCollision(Brick& brick);

	sf::FloatRect getGlobalBounds() const;

	float getRadius() const;
	sf::Vector2f getPosition() const;

private:
	void horizontalWallCollision();
	void verticalWallCollision();

	void beforeStartMovement(float dt);
	void afterStartMovement(float dt);

	bool canMoveLeft();
	bool canMoveRight();

private:
	sf::CircleShape shape;

	sf::Vector2f velocity = { .4f, -.4f };

	const float RADIUS = 10.f;
	const sf::Color COLOR = sf::Color::Red;

	const float OUTLINE_THICKNESS = -2.f;
	const sf::Color OUTLINE_COLOR = sf::Color::Black;

	bool hasStarted = false;
	const float BEFORE_START_SPEED = .5f;

	const sf::Vector2f INIT_POSITION = sf::Vector2f(
		WindowConfig::WINDOW_WIDTH / 2.f - RADIUS,
		720.f
	);

	const float WINDOW_BOUNDARY_MARGIN = 10.f;

	const float LEFT_SIDE_BOUNDARY = 50.f;
	const float RIGHT_SIDE_BOUNDARY = 530.f;
};

